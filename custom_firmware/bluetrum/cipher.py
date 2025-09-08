
__all__ = [
    'ab_lfsr_cipher_in',
    'ab_lfsr_cipher',
    'ab_calckey',
    'ab_calcuserkey'
]

from .crc import ab_crc16

#---------------------------------------
#
# Bluetrum LFSR cipher (x32+x30+x26+x25 polynomial)
#

ab_lfsr_table = [val for val in range(256)]
for i, reg in enumerate(ab_lfsr_table):
    for j in range(8):
        # the 'A3' surely resembles their logo
        reg = (reg >> 1) ^ (0xA3000000 if reg & 1 else 0)
    ab_lfsr_table[i] = reg

def ab_lfsr_cipher_in(buff, off, size, key):
    for i in range(size):
        buff[off + i] ^= key & 0xff
        key = (key >> 8) ^ ab_lfsr_table[key & 0xff]
    return key

def ab_lfsr_cipher(data, key):
    data = bytearray(data)
    ab_lfsr_cipher_in(data, 0, len(data), key)
    return bytes(data)

#---------------------------------------

def ab_calckey(key, init=-1):
    key ^= 0x5555AAAA
    crc1 = ab_crc16(key.to_bytes(4, 'little'), init)
    key ^= 0xFFFFFFFF
    crc2 = ab_crc16(key.to_bytes(4, 'little'), init)
    return (crc1 << 16) | crc2

def ab_calcuserkey(key):
    key = key.to_bytes(4, 'little')
    crc1 = ab_crc16(key, 0x4850)
    crc2 = ab_crc16(key, 0x6870)
    return (crc1 << 16) | crc2
