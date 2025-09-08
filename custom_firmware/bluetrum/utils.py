
__all__ = [
    'hexdump',
    'align_by',
    'align_to',
    'anyint',
]

try:
    from hexdump import hexdump
except ImportError:
    def hexdump(data):
        print(f'** there should be a hex dump of {len(data)} bytes **')
        for off in range(0, len(data), 16):
            print(f'{off:08X}: {data[off:off+16].hex(" ")}')

def align_by(value, alignment):
    """ Get a value to pad/align the value to a specified alignment """
    n = value % alignment
    if n > 0: n = alignment - n
    return n

def align_to(value, alignment):
    """ Align/pad a value to a specified alignment """
    return value + align_by(value, alignment)

def anyint(s):
    return int(s, 0)
