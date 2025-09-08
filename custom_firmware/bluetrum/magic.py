""" Magic numbers """

# keys
MAGICKEY_dll    = 0x48502018   # used by the "dll" files
MAGICKEY_XFIL   = 0x4C494658   # used by header.bin, etc.
MAGICKEY_LVMG   = 0x474D564C   # used for the firmware header & boot code
MAGICKEY_XAPP   = 0x50504158   # used for the XCOD area & region table
MAGICKEY_UBIN   = 0xCEC9C2D5   # 
MAGICKEY_segk   = 0x6B676573   # 

# signatures
MAGICSIGN_ENTR  = b'\xC5\xCE\xD4\xD2'  # res.bin file list header
MAGICSIGN_DOWN  = b'\xC4\xCF\xD7\xCE'  # "DOWN" section
MAGICSIGN_XCOD  = b'\xD8\xC3\xCF\xC4'  # code area sign
MAGICSIGN_XRES  = b'\xD8\xD2\xC5\xD3'  # resource area sign
