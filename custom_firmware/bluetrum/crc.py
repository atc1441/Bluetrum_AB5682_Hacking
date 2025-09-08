
__all__ = ['ab_crc16', 'ab_crc32']

import crcmod

ab_crc16 = crcmod.mkCrcFun(0x11021, xorOut=0, rev=False)
ab_crc32 = crcmod.mkCrcFun(0x104C11DB7, xorOut=0, rev=True)
