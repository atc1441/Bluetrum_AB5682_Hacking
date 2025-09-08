#ifndef _MACRO_H
#define _MACRO_H

#define u32 uint32_t

#define UINT_MAX                0xffffffff
#define INT_MAX                 0x7fffffff
#define INT_MIN                 -0x80000000

#define BIT(n)                  (1ul << (n))

#define AT(x)                   __attribute__((section(#x)))
#define ALIGNED(n)              __attribute__((aligned(n)))
#define DMA_ADR(x)              ((u32)x)
#define ALWAYS_INLINE           __attribute__((always_inline)) inline
#define NO_INLINE               __attribute__((noinline))
#define WEAK                    __attribute__((weak))
#define PACKED                  __attribute__((packed))
#define FIQ                     __attribute__((fiq("machine")))

#define WDT_CLR()               wdt_clr()
#define WDT_EN()                WDTCON = 0x110
#define WDT_DIS()               WDTCON = 0xaa0
#define WDT_RST()               WDTCON = 0xa000110; while (1)
#define WDT_RST_DELAY()         WDTCON = 0xa100110; while (1)

#define BYTE0(n)                ((unsigned char)(n))
#define BYTE1(n)                ((unsigned char)((n)>>8))
#define BYTE2(n)                ((unsigned char)((n)>>16))
#define BYTE3(n)                ((unsigned char)((n)>>24))

#define GET_LE16(ptr)           (u16)(*(u16*)(u8*)(ptr))
#define GET_LE32(ptr)           (u32)(*(u32*)(u8*)(ptr))
#define PUT_LE16(ptr, val)      *(u16*)(u8*)(ptr) = (u16)(val)
#define PUT_LE32(ptr, val)      *(u32*)(u8*)(ptr) = (u32)(val)

#define GET_BE16(ptr)           get_be16(ptr)
#define GET_BE32(ptr)           get_be32(ptr)
#define PUT_BE16(ptr, val)      put_be16(ptr, val)
#define PUT_BE32(ptr, val)      put_be32(ptr, val)

#define ABS(x)                  ((x) < 0 ? (-(x)) : (x))
#define MIN(a,b)                ((a) < (b) ? (a) : (b))
#define MAX(a,b)                ((a) > (b) ? (a) : (b))

void wdt_clr(void);

#endif // _MACRO_H
