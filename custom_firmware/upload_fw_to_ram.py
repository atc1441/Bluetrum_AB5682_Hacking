from bluetrum.cipher import ab_calckey
from bluetrum.utils import *

import time
import struct
import argparse
import os
from tqdm import tqdm

try:
    from serial import Serial
    from bluetrum.dl.uart import UARTDownload
except ImportError:
    print('pyserial is not installed. Please install it with: pip install pyserial by https://github.com/kagaimiq/bluetrum-tools edited by ATC1441')
    exit(1)

ap = argparse.ArgumentParser(description='Tool to upload a loader blob to Bluetrum chips via UART.')

ap.add_argument('--port', required=True,
                help='Serial port to use for UART bootloader (e.g., COM3 or /dev/ttyUSB0)')
ap.add_argument('--baud', type=int, default=115200,
                help='Baudrate für die Datenübertragung nach der Initialisierung (Standard: %(default)d).')
ap.add_argument('--loader', required=True,
                help='Path to the .bin file to be used as the download blob (dl_blob)')

args = ap.parse_args()

if not os.path.exists(args.loader):
    print(f"Error: Loader file not found at '{args.loader}'")
    exit(1)

try:
    with open(args.loader, 'rb') as f:
        dl_blob = f.read()
    print(f"Successfully loaded {len(dl_blob)} bytes from '{args.loader}' as dl_blob.")
except Exception as e:
    print(f"Error: Could not read the loader file '{args.loader}': {e}")
    exit(1)

class BlCmd:
    IFACE_PARAM         = 0x50
    MEM_READ            = 0x52
    AUTHORIZE           = 0x55
    MEM_WRITE           = 0x57
    SET_CMD_HANDLER     = 0x58
    GET_INFO            = 0x5A
    REBOOT              = 0x5E

def make_cb(cmd, arg1=0, arg2=0, arg3=0):
    return struct.pack('>BIBH', cmd, arg1, arg2, arg3)

def do_the_stuff(execcmd, blocksize, iface, port):
    try:
        resp = execcmd(make_cb(BlCmd.GET_INFO, arg1=0x5259414E, arg3=0x67ca), recv=24)
        chipid, loadaddr, commskey, _ = struct.unpack('>12sIII', resp)
        print(f' Chip ID:       {chipid.hex().upper()}')
        print(f' Load address:  ${loadaddr:08X}')
        print(f' Init. commkey: ${commskey:08X}')

        resp = execcmd(make_cb(BlCmd.AUTHORIZE, arg1=ab_calckey(commskey)), recv=4)
        commskey, = struct.unpack('>I', resp)
        print(f' New commkey:   ${commskey:08X}')

        print("Uploading loader blob...")
        data = bytearray(dl_blob) + b'\x00' * align_by(len(dl_blob), blocksize)
        execcmd(make_cb(BlCmd.MEM_WRITE, arg1=loadaddr, arg3=(len(data) // blocksize)),send=data)
        execcmd(make_cb(BlCmd.SET_CMD_HANDLER, arg1=loadaddr))
        print("Loader blob uploaded and executed.")        
        udl.port.write(udl._make_token_packet(UARTDownload.DATA_TOKEN) + udl._make_data_payload(make_cb(0x00, arg1=0x00003b00)))

        print("\nListening for UART output... Press Ctrl+C to exit.")
        try:
            while True:
                if port.in_waiting > 0:
                    received_bytes = port.read(port.in_waiting)
                    output_str = ""
                    for byte in received_bytes:
                        if 32 <= byte <= 126 or byte in [10, 13]:
                            output_str += chr(byte)
                        else:
                            output_str += f'\\x{byte:02x}'
                    print(output_str, end='', flush=True)
                time.sleep(0.01)
        except KeyboardInterrupt:
            print("\nStopping UART listener.")

    except Exception as e:
        print(f'\nAn error occurred: {e}')

    except KeyboardInterrupt:
        print('\nOperation interrupted by user.')

with Serial(args.port, args.baud) as port:
    udl = UARTDownload(port)

    print(f'Attempting to synchronize on {args.port}...', end='', flush=True)


    port.reset_input_buffer()
    port.reset_output_buffer()
    time.sleep(0.1)
    port.baudrate = args.baud
    time.sleep(0.1)

    port.timeout = .01
    try:
        done = False
        num = 0
        while not done:
            if num < 10:
                udl.port.reset_input_buffer()
                udl.port.write(UARTDownload.SYNC_TOKEN)
                while not done:
                    recv = port.read(4)
                    if recv == b'': break
                    if recv == UARTDownload.SYNC_RESP: done = True
                num += 1
            else:
                print('.', end='', flush=True)
                udl.send_reset(True)
                num = 0
        if not done:
            print(" Neusynchronisierung fehlgeschlagen.")
            exit()
    except Exception as e:
        print(f" Neusynchronisierung fehlgeschlagen: {e}")
        exit()
    

    print("")
    port.timeout = .1

    def execcmd(cb, send=None, recv=None, max_io=512, switch_baud=None):
        udl.send_packet(cb)
        
        if switch_baud is not None:
            port.baudrate = switch_baud
        
        if send is not None:
            sent = 0
            with tqdm(total=len(send), unit='B', unit_scale=True, desc='Uploading') as pbar:
                while sent < len(send):
                    chunk_size = min(len(send) - sent, max_io)
                    udl.send_packet(send[sent : sent+chunk_size])
                    sent += chunk_size
                    pbar.update(chunk_size)
        
        elif recv is not None:
            data = b''
            while len(data) < recv:
                block = udl.recv_packet()
                if not block:
                    break
                data += block
            return data
            
    do_the_stuff(execcmd, 512, 'uart', port)

print("\nOperation finished.")