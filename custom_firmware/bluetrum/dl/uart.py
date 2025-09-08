from bluetrum.crc import ab_crc16
import time

class UARTDownload:
    # special tokens
    SYNC_TOKEN  = b'\xA5\x96\x87\x5A'   # Sync token
    SYNC_RESP   = b'\x5A\x69\x78\xA5'   # Sync response
    RESET_TOKEN = b'\xF5\xA0'           # Communication Reset token (sending sync token next to it resets the chip instead)

    # response tokens
    RESP_ACK     = 0x1E   # Data packet has been accepted
    RESP_NAK     = 0x2D   # No data available (receive); No space for data (send)
    RESP_NYET    = 0x3C   # Data packet accepted but there is no more space for another one. (not processed yet)

    # request tokens
    DATA_TOKEN   = 0x4B   # Data token. ACK: all right, NYET: previous one hasn't been received yet, NAK: could not receive
    DATA_REQUEST = 0xB4   # Request for data. DATA: there it is, NAK: not available
    PING_TOKEN   = 0xC3   # Can we send more data? ACK: yes, NAK: no

    #------------------------------------------

    def __init__(self, port):
        self.port = port
        self.comms_reset()

    def port_read(self, size):
        data = self.port.read(size)
        if len(data) < size:
            raise TimeoutError(f'Not enough data has been received from the port (had only {len(data)} bytes)')
        return data

    def port_write(self, data):
        self.port.write(data)
        # consume the echo back
        echo = self.port.read(len(data))
        #if len(echo) < len(data):
        #    raise TimeoutError('Did not receive the echo back')
        #if echo != data:
        #    raise ValueError('The echo has been corrupted')

    def comms_reset(self):
        self.counter = 0
        self.ping_before_send = False

    def send_reset(self, hard=False):
        if not hard:
            # communication soft-reset
            self.port_write(UARTDownload.RESET_TOKEN)
        else:
            # chip hard-reset
            self.port_write(UARTDownload.RESET_TOKEN + UARTDownload.SYNC_TOKEN)

        # this makes sense
        self.comms_reset()

    def _make_token_packet(self, token):
        # increase the counter
        self.counter = (self.counter + 1) & 0xff
        # make the token packet
        return bytes([token, self.counter])

    def _recv_token_packet(self):
        # receive the token packet
        recv = self.port_read(2)
        # check the counter value
        if recv[1] != self.counter:
            return ValueError(f'Mismatch in the counter value of a received token ({recv[1]}) from expected ({self.counter})')
        # return the received token value
        return recv[0]

    def _make_data_payload(self, data):
        return len(data).to_bytes(2, 'little') + data + ab_crc16(data).to_bytes(2, 'little')

    def _recv_data_payload(self):
        # receive data length
        size = int.from_bytes(self.port_read(2), 'little')
        # receive data payload
        data = self.port_read(size)
        # receive data CRC
        crc = int.from_bytes(self.port_read(2), 'little')

        # check the received data CRC
        if ab_crc16(data) != crc:
            raise ValueError('Received data packet CRC mismatch')

        # return the data payload
        return data

    def send_packet(self, data):
        data = self._make_data_payload(data)

        do_ping = self.ping_before_send

        # TODO: time out, maybe?
        while True:
            if do_ping:
                # send a PING token
                packet = self._make_token_packet(UARTDownload.PING_TOKEN)
            else:
                # send a DATA packet
                packet = self._make_token_packet(UARTDownload.DATA_TOKEN) + data

            tries = 0
            while True:
                self.port_write(packet)

                try:
                    resp = self._recv_token_packet()
                except TimeoutError:
                    # maybe a reception failure or a CRC error.
                    if tries > 10:
                        raise TimeoutError("Could not send a data packet.")
                    tries += 1
                else:
                    break

            if do_ping:
                if resp == UARTDownload.RESP_ACK:
                    # Now we can send data.
                    do_ping = False
                elif resp == UARTDownload.RESP_NAK:
                    # Not yet.
                    pass
                else:
                    raise RuntimeError(f'Ping: Unexpected response token {resp:02X}')
            else:
                if resp == UARTDownload.RESP_ACK:
                    # All fine
                    self.ping_before_send = False
                    return
                elif resp == UARTDownload.RESP_NYET:
                    # Received fine, but the previous data block hasn't been processed yet.
                    self.ping_before_send = True  # better to ping it next time.
                    return
                elif resp == UARTDownload.RESP_NAK:
                    # Failed, perhaps the chip is busy.
                    do_ping = True  # start pinging.
                else:
                    raise RuntimeError(f'Tx: Unexpected response token {resp:02X}')

    def recv_packet(self):
        # the request packet needs to be sent with the same counter value
        #  in case we need to re-request data in case of a CRC failure etc.
        #  otherwise the chip assumes the data was received ok
        request = self._make_token_packet(UARTDownload.DATA_REQUEST)

        tries = 0

        # TODO: a timeout?
        while True:
            self.port_write(request)

            try:
                resp = self._recv_token_packet()
            except TimeoutError:
                # maybe chip didn't receive the request
                if tries > 10:
                    raise TimeoutError("Could not request a data packet.")
                tries += 1
                continue
            else:
                tries = 0

            if resp == UARTDownload.DATA_TOKEN:
                # Here's the data
                try:
                    # receive the data packet
                    data = self._recv_data_payload()
                except:
                    # something failed, ask for data again.
                    pass
                else:
                    # successful reception
                    return data
            elif resp == UARTDownload.RESP_NAK:
                # Failed, chip does not have any data block yet.
                continue
            else:
                raise RuntimeError(f'Rx: Unexpected response token {resp:02X}')

            tries += 1
