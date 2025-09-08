#ifndef __ASSEMBLER__
#define SFR_RO *(volatile unsigned long const *)
#define SFR_WO *(volatile unsigned long*)
#define SFR_RW *(volatile unsigned long*)
#define LPSFR_RO *(volatile unsigned long const *)
#define LPSFR_WO *(volatile unsigned long*)
#define LPSFR_RW *(volatile unsigned long*)
#define SWINT()      asm(".long 0xb0030057")
#define EEBREAKINT() asm(".long 0xb0040057")
#else
#define SFR_RO
#define SFR_WO
#define SFR_RW
#define LPSFR_RO
#define LPSFR_WO
#define LPSFR_RW
#define SWINT      .long 0xb0030057
#define EEBREAKINT .long 0xb0040057
#endif


#ifndef _EAGER_SFR_
#define _EAGER_SFR_

#define SFR_BASE   0x00000100    // address 0~255 is reserved
#define SFR0_BASE  (SFR_BASE + 0x000)
#define SFR1_BASE  (SFR_BASE + 0x100)
#define SFR2_BASE  (SFR_BASE + 0x200)
#define SFR3_BASE  (SFR_BASE + 0x300)
#define SFR4_BASE  (SFR_BASE + 0x400)
#define SFR5_BASE  (SFR_BASE + 0x500)
#define SFR6_BASE  (SFR_BASE + 0x600)
#define SFR7_BASE  (SFR_BASE + 0x700)
#define SFR8_BASE  (SFR_BASE + 0x800)
#define SFR9_BASE  (SFR_BASE + 0x900)
#define SFR10_BASE (SFR_BASE + 0xa00)
#define SFR11_BASE (SFR_BASE + 0xb00)
#define SFR12_BASE (SFR_BASE + 0xc00)
#define SFR13_BASE (SFR_BASE + 0xd00)
#define SFR14_BASE (SFR_BASE + 0xe00)
#define SFR15_BASE (SFR_BASE + 0xf00)

//------------------------- SFR Group0 ---------------------------------------//
#define TICK0CON          SFR_RW (SFR0_BASE + 0x01*4)
#define TICK0CPND         SFR_RW (SFR0_BASE + 0x02*4)
#define TICK0CNT          SFR_RW (SFR0_BASE + 0x03*4)
#define TICK0PR           SFR_RW (SFR0_BASE + 0x04*4)
#define TICK1CON          SFR_RW (SFR0_BASE + 0x05*4)
#define TICK1CPND         SFR_RW (SFR0_BASE + 0x06*4)
//#define FUNCMCON0         SFR_RW (SFR0_BASE + 0x07*4)
//#define FUNCMCON1         SFR_RW (SFR0_BASE + 0x08*4)
//#define FUNCMCON2         SFR_RW (SFR0_BASE + 0x09*4)
#define TICK1CNT          SFR_RW (SFR0_BASE + 0x0a*4)
#define TICK1PR           SFR_RW (SFR0_BASE + 0x0b*4)
#define CPDATA            SFR_RW (SFR0_BASE + 0x0c*4)
#define SPMODE            SFR_RW (SFR0_BASE + 0x0d*4)
#define DEVICEID          SFR_RW (SFR0_BASE + 0x0e*4)
#define VERSIONID         SFR_RW (SFR0_BASE + 0x0f*4)

#define UART0CON          SFR_RW (SFR0_BASE + 0x10*4)
#define UART0CPND         SFR_WO (SFR0_BASE + 0x11*4)
#define UART0BAUD         SFR_RW (SFR0_BASE + 0x12*4)
#define UART0DATA         SFR_RW (SFR0_BASE + 0x13*4)
#define TMR0CON           SFR_RW (SFR0_BASE + 0x14*4)
#define TMR0CPND          SFR_RW (SFR0_BASE + 0x15*4)
#define TMR0CNT           SFR_RW (SFR0_BASE + 0x16*4)
#define TMR0PR            SFR_RW (SFR0_BASE + 0x17*4)
#define CRSTPND           SFR_RW (SFR0_BASE + 0x18*4)
#define CLKCON0           SFR_RW (SFR0_BASE + 0x19*4)
#define WDTCON            SFR_RW (SFR0_BASE + 0x1a*4)
#define RTCCON            SFR_RW (SFR0_BASE + 0x1b*4)
#define VBRSTCON          SFR_RW (SFR0_BASE + 0x1c*4)
#define CLKCON1           SFR_RW (SFR0_BASE + 0x1d*4)
#define RTCCPND           SFR_WO (SFR0_BASE + 0x1e*4)
//#define U0KEYCON          SFR_RW (SFR0_BASE + 0x1f*4)

#define SD0CON            SFR_RW (SFR0_BASE + 0x20*4)
#define SD0CPND           SFR_WO (SFR0_BASE + 0x21*4)
#define SD0BAUD           SFR_RW (SFR0_BASE + 0x22*4)
#define SD0CMD            SFR_RW (SFR0_BASE + 0x23*4)
#define SD0ARG3           SFR_RW (SFR0_BASE + 0x24*4)
#define SD0ARG2           SFR_RW (SFR0_BASE + 0x25*4)
#define SD0ARG1           SFR_RW (SFR0_BASE + 0x26*4)
#define SD0ARG0           SFR_RW (SFR0_BASE + 0x27*4)
#define SD0DMAADR         SFR_RW (SFR0_BASE + 0x28*4)
#define SD0DMACNT         SFR_RW (SFR0_BASE + 0x29*4)
#define SPI0CON           SFR_RW (SFR0_BASE + 0x2a*4)
#define SPI0BUF           SFR_RW (SFR0_BASE + 0x2b*4)
#define SPI0BAUD          SFR_RW (SFR0_BASE + 0x2c*4)
#define SPI0CPND          SFR_RW (SFR0_BASE + 0x2d*4)
#define SPI0DMACNT        SFR_RW (SFR0_BASE + 0x2e*4)
#define SPI0DMAADR        SFR_RW (SFR0_BASE + 0x2f*4)

#define UART1CON          SFR_RW (SFR0_BASE + 0x30*4)
#define UART1CPND         SFR_WO (SFR0_BASE + 0x31*4)
#define UART1BAUD         SFR_RW (SFR0_BASE + 0x32*4)
#define UART1DATA         SFR_RW (SFR0_BASE + 0x33*4)
//#define U1KEYCON          SFR_RW (SFR0_BASE + 0x34*4)
#define TMR1CON           SFR_RW (SFR0_BASE + 0x35*4)
#define TMR1CPND          SFR_RW (SFR0_BASE + 0x36*4)
#define TMR1CNT           SFR_RW (SFR0_BASE + 0x37*4)
#define TMR1PR            SFR_RW (SFR0_BASE + 0x38*4)
#define TMR2CON           SFR_RW (SFR0_BASE + 0x3a*4)
#define TMR2CPND          SFR_RW (SFR0_BASE + 0x3b*4)
#define TMR2CNT           SFR_RW (SFR0_BASE + 0x3c*4)
#define TMR2PR            SFR_RW (SFR0_BASE + 0x3d*4)
#define CLKGAT2           SFR_RW (SFR0_BASE + 0x3e*4)

//------------------------- SFR Group1 ---------------------------------------//
#define AUBUFDATA       SFR_RW (SFR1_BASE + 0x01*4)
#define AUBUFCON        SFR_RW (SFR1_BASE + 0x02*4)
#define AUBUFSTARTADDR  SFR_RW (SFR1_BASE + 0x03*4)
#define AUBUFSIZE       SFR_RW (SFR1_BASE + 0x04*4)
#define AUBUFFIFOCNT    SFR_RW (SFR1_BASE + 0x05*4)
#define AUBUF1DATA      SFR_RW (SFR1_BASE + 0x06*4)
#define AUBUF1CON       SFR_RW (SFR1_BASE + 0x07*4)
#define AUBUF1STARTADDR SFR_RW (SFR1_BASE + 0x08*4)
#define AUBUF1SIZE      SFR_RW (SFR1_BASE + 0x09*4)
#define AUBUF1FIFOCNT   SFR_RW (SFR1_BASE + 0x0a*4)
#define AUBUFPEAKLEFT   SFR_RW (SFR1_BASE + 0x0b*4)
#define AUBUFPEAKRIGHT  SFR_RW (SFR1_BASE + 0x0c*4)
#define AUBUFPTR        SFR_RW (SFR1_BASE + 0x0d*4)
#define AUBUFBACKUP     SFR_RW (SFR1_BASE + 0x0e*4)

#define DACDIGCON0      SFR_RW (SFR1_BASE + 0x0f*4)
#define DACDIGCON2      SFR_RW (SFR1_BASE + 0x10*4)
#define DACDIGCON3      SFR_RW (SFR1_BASE + 0x11*4)
#define PHASECOMP       SFR_RW (SFR1_BASE + 0x12*4)
#define DACVOLCON       SFR_RW (SFR1_BASE + 0x13*4)
#define SRC0VOLCON      SFR_RW (SFR1_BASE + 0x14*4)
#define SRC1VOLCON      SFR_RW (SFR1_BASE + 0x15*4)
#define MIXWEIGHT       SFR_RW (SFR1_BASE + 0x16*4)
#define DACRMDCCON      SFR_RW (SFR1_BASE + 0x17*4)
#define DACLDCEXP       SFR_RW (SFR1_BASE + 0x18*4)
#define DACBQ0CON       SFR_RW (SFR1_BASE + 0x19*4)
#define DACBQPEND       SFR_RW (SFR1_BASE + 0x1a*4)
#define DACBQCOEF       SFR_RW (SFR1_BASE + 0x1b*4)
#define DACRAMTADDR     SFR_RW (SFR1_BASE + 0x1c*4)
#define DACRAMTDATA     SFR_RW (SFR1_BASE + 0x1d*4)

#define ADCRAMTADDR     SFR_RW (SFR1_BASE + 0x1e*4)
#define ADCRAMTDATA     SFR_RW (SFR1_BASE + 0x1f*4)

#define AUCON0          SFR_RW (SFR1_BASE + 0x20*4)
#define AUCON1          SFR_RW (SFR1_BASE + 0x21*4)
#define AUCON2          SFR_RW (SFR1_BASE + 0x22*4)
#define AUCON3          SFR_RW (SFR1_BASE + 0x23*4)
#define AUCON4          SFR_RW (SFR1_BASE + 0x24*4)
#define AUDMAADR        SFR_RW (SFR1_BASE + 0x25*4)

#define SBCECCON0       SFR_RW (SFR1_BASE + 0x26*4)
#define SBCECCON1       SFR_RW (SFR1_BASE + 0x27*4)
#define SBCECDMAINADR   SFR_RW (SFR1_BASE + 0x28*4)
#define SBCECDMAOUTADR  SFR_RW (SFR1_BASE + 0x29*4)
#define SBCECDMACNT     SFR_RW (SFR1_BASE + 0x2a*4)

#define SDADCDMACON     SFR_RW (SFR1_BASE + 0x2b*4)
#define SDADCDMACLR     SFR_RW (SFR1_BASE + 0x2c*4)
#define SDADCDMAFLAG    SFR_RW (SFR1_BASE + 0x2d*4)
#define SDADCDMAADDR    SFR_RW (SFR1_BASE + 0x2e*4)
#define SDADCDMASIZE    SFR_RW (SFR1_BASE + 0x2f*4)
#define SDADCDIGCON     SFR_RW (SFR1_BASE + 0x30*4)
#define SDADCGAINCON    SFR_RW (SFR1_BASE + 0x31*4)
#define SDADCGETDCCON   SFR_RW (SFR1_BASE + 0x32*4)

#define AUBUF0DMACON    SFR_RW (SFR1_BASE + 0x33*4)
#define AUBUF0DMAADR    SFR_RW (SFR1_BASE + 0x34*4)
#define AUBUF0DMAKICK   SFR_RW (SFR1_BASE + 0x35*4)
#define AUBUF1DMACON    SFR_RW (SFR1_BASE + 0x36*4)
#define AUBUF1DMAADR    SFR_RW (SFR1_BASE + 0x37*4)
#define AUBUF1DMAKICK   SFR_RW (SFR1_BASE + 0x38*4)

#define AUANGCON0       SFR_RW (SFR1_BASE + 0x39*4)
#define AUANGCON1       SFR_RW (SFR1_BASE + 0x3a*4)
#define AUANGCON2       SFR_RW (SFR1_BASE + 0x3b*4)
#define AUANGCON3       SFR_RW (SFR1_BASE + 0x3c*4)
#define AUANGCON4       SFR_RW (SFR1_BASE + 0x3d*4)
#define AUANGCON5       SFR_RW (SFR1_BASE + 0x3e*4)
#define AUANGCON6       SFR_RW (SFR1_BASE + 0x3f*4)

//------------------------- SFR Group2 ---------------------------------------//
#define UFADDR          SFR_RW (SFR2_BASE + 0x00*4)
#define UPOWER          SFR_RW (SFR2_BASE + 0x01*4)
#define UINTRTX1        SFR_RW (SFR2_BASE + 0x02*4)
#define UINTRTX2        SFR_RW (SFR2_BASE + 0x03*4)
#define UINTRRX1        SFR_RW (SFR2_BASE + 0x04*4)
#define UINTRRX2        SFR_RW (SFR2_BASE + 0x05*4)
#define UINTRUSB        SFR_RW (SFR2_BASE + 0x06*4)
#define UINTRTX1E       SFR_RW (SFR2_BASE + 0x07*4)
#define UINTRTX2E       SFR_RW (SFR2_BASE + 0x08*4)
#define UINTRRX1E       SFR_RW (SFR2_BASE + 0x09*4)
#define UINTRRX2E       SFR_RW (SFR2_BASE + 0x0a*4)
#define UINTRUSBE       SFR_RW (SFR2_BASE + 0x0b*4)
#define UFRAME1         SFR_RW (SFR2_BASE + 0x0c*4)
#define UFRAME2         SFR_RW (SFR2_BASE + 0x0d*4)
#define UINDEX          SFR_RW (SFR2_BASE + 0x0e*4)
#define UDEVCTL         SFR_RW (SFR2_BASE + 0x0f*4)

#define UTXMAXP         SFR_RW (SFR2_BASE + 0x10*4)
#define UCSR0           SFR_RW (SFR2_BASE + 0x11*4)
#define UTXCSR1         SFR_RW (SFR2_BASE + 0x11*4)
#define UTXCSR2         SFR_RW (SFR2_BASE + 0x12*4)
#define URXMAXP         SFR_RW (SFR2_BASE + 0x13*4)
#define URXCSR1         SFR_RW (SFR2_BASE + 0x14*4)
#define URXCSR2         SFR_RW (SFR2_BASE + 0x15*4)
#define UCOUNT0         SFR_RW (SFR2_BASE + 0x16*4)
#define URXCOUNT1       SFR_RW (SFR2_BASE + 0x16*4)
#define URXCOUNT2       SFR_RW (SFR2_BASE + 0x17*4)
#define UTXTYPE         SFR_RW (SFR2_BASE + 0x18*4)
#define UTXINTERVAL     SFR_RW (SFR2_BASE + 0x19*4)
#define URXTYPE         SFR_RW (SFR2_BASE + 0x1a*4)
#define URXINTERVAL     SFR_RW (SFR2_BASE + 0x1b*4)

#define UFIFO0          SFR_RW (SFR2_BASE + 0x20*4)
#define UFIFO1          SFR_RW (SFR2_BASE + 0x21*4)
#define UFIFO2          SFR_RW (SFR2_BASE + 0x22*4)
#define UFIFO3          SFR_RW (SFR2_BASE + 0x23*4)
#define UFIFO4          SFR_RW (SFR2_BASE + 0x24*4)
#define UFIFO5          SFR_RW (SFR2_BASE + 0x25*4)
#define UFIFO6          SFR_RW (SFR2_BASE + 0x26*4)
#define UFIFO7          SFR_RW (SFR2_BASE + 0x27*4)
#define UFIFO8          SFR_RW (SFR2_BASE + 0x28*4)
#define UFIFO9          SFR_RW (SFR2_BASE + 0x29*4)
#define UFIFO10         SFR_RW (SFR2_BASE + 0x2a*4)
#define UFIFO11         SFR_RW (SFR2_BASE + 0x2b*4)
#define UFIFO12         SFR_RW (SFR2_BASE + 0x2c*4)
#define UFIFO13         SFR_RW (SFR2_BASE + 0x2d*4)
#define UFIFO14         SFR_RW (SFR2_BASE + 0x2e*4)
#define UFIFO15         SFR_RW (SFR2_BASE + 0x2f*4)

//------------------------- SFR Group3 ---------------------------------------//
#define USBCON0         SFR_RW (SFR3_BASE + 0x00*4)
#define USBCON1         SFR_RW (SFR3_BASE + 0x01*4)
#define USBCON2         SFR_RW (SFR3_BASE + 0x02*4)
#define USBCON3         SFR_RW (SFR3_BASE + 0x03*4)
#define USBCON4         SFR_RW (SFR3_BASE + 0x04*4)
#define USBEP0ADR       SFR_RW (SFR3_BASE + 0x05*4)
#define USBEP1RXADR     SFR_RW (SFR3_BASE + 0x06*4)
#define USBEP1TXADR     SFR_RW (SFR3_BASE + 0x07*4)
#define USBEP2RXADR     SFR_RW (SFR3_BASE + 0x08*4)
#define USBEP2TXADR     SFR_RW (SFR3_BASE + 0x09*4)
#define USBEP3RXADR     SFR_RW (SFR3_BASE + 0x0a*4)
#define USBEP3TXADR     SFR_RW (SFR3_BASE + 0x0b*4)
#define BTPHYTSCON      SFR_RW (SFR3_BASE + 0x0c*4)
#define PLL2CON1        SFR_RW (SFR3_BASE + 0x0d*4)
#define DBGCON1         SFR_RW (SFR3_BASE + 0x0e*4)
#define DBGCON          SFR_RW (SFR3_BASE + 0x0f*4)

#define CRCDAT          SFR_RW (SFR3_BASE + 0x10*4)
#define CRCRES          SFR_RW (SFR3_BASE + 0x11*4)
#define LFSRRES         SFR_RW (SFR3_BASE + 0x12*4)
#define TESTDATA                LFSRRES
#define LFCRCCON        SFR_RW (SFR3_BASE + 0x13*4)
#define BTDMAADR        SFR_RW (SFR3_BASE + 0x14*4)
#define PLL0CON1        SFR_RW (SFR3_BASE + 0x15*4)
#define PRCLKDIVCON0    SFR_RW (SFR3_BASE + 0x16*4)
#define PRCLKDIVCON1    SFR_RW (SFR3_BASE + 0x17*4)
#define BTRFDMACON      SFR_RW (SFR3_BASE + 0x18*4)
#define BTADDMACNT      SFR_RW (SFR3_BASE + 0x19*4)
#define BTADDMAADR      SFR_RW (SFR3_BASE + 0x1a*4)
#define BTDADMACNT      SFR_RW (SFR3_BASE + 0x1b*4)
#define BTDADMAADR      SFR_RW (SFR3_BASE + 0x1c*4)
#define PWRCON0         SFR_RW (SFR3_BASE + 0x1d*4)
#define LVDCON          SFR_RW (SFR3_BASE + 0x1e*4)
#define PWRCON1         SFR_RW (SFR3_BASE + 0x1f*4)

#define CRC1DAT         SFR_RW (SFR3_BASE + 0x20*4)
#define CRC1RES         SFR_RW (SFR3_BASE + 0x21*4)
#define PLL1CON1        SFR_RW (SFR3_BASE + 0x22*4)
//#define LPBUCKCON       SFR_RW (SFR3_BASE + 0x22*4)
#define PLL0DIV         SFR_RW (SFR3_BASE + 0x23*4)
#define PLL1DIV         SFR_RW (SFR3_BASE + 0x24*4)
#define PLL2DIV         SFR_RW (SFR3_BASE + 0x25*4)
#define PLL0CON         SFR_RW (SFR3_BASE + 0x26*4)
#define PWRCON3         SFR_RW (SFR3_BASE + 0x27*4)
#define CLKDIVCON2      SFR_RW (SFR3_BASE + 0x28*4)
#define XO26MCON        SFR_RW (SFR3_BASE + 0x29*4)
#define CLKDIVCON0      SFR_RW (SFR3_BASE + 0x2a*4)
#define RSTCON0         SFR_RW (SFR3_BASE + 0x2b*4)
#define CLKGAT0         SFR_RW (SFR3_BASE + 0x2c*4)
#define LPMCON          SFR_RW (SFR3_BASE + 0x2d*4)
#define MEMCON          SFR_RW (SFR3_BASE + 0x2e*4)
#define CLKDIVCON1      SFR_RW (SFR3_BASE + 0x2f*4)

#define HSUT0CON        SFR_RW (SFR3_BASE + 0x30*4)
#define HSUT0CPND       SFR_RW (SFR3_BASE + 0x31*4)
#define HSUT0BAUD       SFR_RW (SFR3_BASE + 0x32*4)
#define HSUT0DATA       SFR_RW (SFR3_BASE + 0x33*4)
#define HSUT0TXCNT      SFR_RW (SFR3_BASE + 0x34*4)
#define HSUT0TXADR      SFR_RW (SFR3_BASE + 0x35*4)
#define HSUT0RXCNT      SFR_RW (SFR3_BASE + 0x36*4)
#define HSUT0RXADR      SFR_RW (SFR3_BASE + 0x37*4)
#define HSUT0FIFOCNT    SFR_RW (SFR3_BASE + 0x38*4)
#define HSUT0FIFO       SFR_RW (SFR3_BASE + 0x39*4)
#define HSUT0FIFOADR    SFR_RW (SFR3_BASE + 0x3a*4)
#define HSUT0TMRCNT     SFR_RW (SFR3_BASE + 0x3b*4)
#define HSUT0FCCON      SFR_RW (SFR3_BASE + 0x3c*4)
#define BTCON4          SFR_RW (SFR3_BASE + 0x3d*4)
#define PWRCON2         SFR_RW (SFR3_BASE + 0x3e*4)
#define CLKGAT1         SFR_RW (SFR3_BASE + 0x3f*4)

//------------------------- SFR Group4 ---------------------------------------//
//0x00~0x3f reserve for CPU
#define EXCEPTPND       SFR_RO (SFR4_BASE + 0x00*4)
#define EXCEPTCPND      SFR_WO (SFR4_BASE + 0x01*4)
#define NMICON          SFR_RW (SFR4_BASE + 0x02*4)
#define BP0ADR          SFR_RW (SFR4_BASE + 0x03*4)
#define BP1ADR          SFR_RW (SFR4_BASE + 0x04*4)
#define BP2ADR          SFR_RW (SFR4_BASE + 0x05*4)
#define BP3ADR          SFR_RW (SFR4_BASE + 0x06*4)
#define BP4ADR          SFR_RW (SFR4_BASE + 0x07*4)
#define BP5ADR          SFR_RW (SFR4_BASE + 0x08*4)
#define BP6ADR          SFR_RW (SFR4_BASE + 0x09*4)
#define ICLOCK1         SFR_RW (SFR4_BASE + 0x0a*4)
#define ICVAL1          SFR_RW (SFR4_BASE + 0x0b*4)
#define PICCONCLR       SFR_WO (SFR4_BASE + 0x0c*4)
#define PICCONSET       SFR_WO (SFR4_BASE + 0x0d*4)
#define PICENCLR        SFR_WO (SFR4_BASE + 0x0e*4)
#define PICENSET        SFR_WO (SFR4_BASE + 0x0f*4)

#define PICCON          SFR_RW (SFR4_BASE + 0x10*4)
#define PICEN           SFR_RW (SFR4_BASE + 0x11*4)
#define PICPR           SFR_RW (SFR4_BASE + 0x12*4)
#define PICADR          SFR_RW (SFR4_BASE + 0x13*4)
#define PICPND          SFR_RW (SFR4_BASE + 0x14*4)
#define CACHCON0        SFR_RW (SFR4_BASE + 0x15*4)
#define CACHCON1        SFR_RW (SFR4_BASE + 0x16*4)
#define ICTAG           SFR_RW (SFR4_BASE + 0x17*4)
#define ICINDEX         SFR_RW (SFR4_BASE + 0x18*4)
#define ICADRMS         SFR_RW (SFR4_BASE + 0x19*4)
#define ICLOCK          SFR_RW (SFR4_BASE + 0x1a*4)
#define ICVAL           SFR_RW (SFR4_BASE + 0x1b*4)
//#define DCADRMS         SFR_RW (SFR4_BASE + 0x1c*4)
#define SWBK            SFR_RW (SFR4_BASE + 0x1d*4)
#define EPICCON         SFR_RW (SFR4_BASE + 0x1e*4)
#define EPC             SFR_RW (SFR4_BASE + 0x1f*4)

#define BP7ADR          SFR_RW (SFR4_BASE + 0x20*4)
#define BP8ADR          SFR_RW (SFR4_BASE + 0x21*4)
#define BP9ADR          SFR_RW (SFR4_BASE + 0x22*4)
#define BP10ADR         SFR_RW (SFR4_BASE + 0x23*4)
#define BP11ADR         SFR_RW (SFR4_BASE + 0x24*4)
#define BP12ADR         SFR_RW (SFR4_BASE + 0x25*4)
#define BP13ADR         SFR_RW (SFR4_BASE + 0x26*4)
#define BP14ADR         SFR_RW (SFR4_BASE + 0x27*4)
#define BP15ADR         SFR_RW (SFR4_BASE + 0x28*4)
#define PICPR1          SFR_RW (SFR4_BASE + 0x29*4)

#define PCERR           SFR_RW (SFR4_BASE + 0x2e*4)
#define PCST            SFR_RW (SFR4_BASE + 0x2f*4)

//------------------------- SFR Group5 ---------------------------------------//
#define PARCON0         SFR_RW (SFR5_BASE + 0x00*4)
#define PARCON1         SFR_RW (SFR5_BASE + 0x01*4)
#define PARCON2         SFR_RW (SFR5_BASE + 0x02*4)
#define PARCON3         SFR_RW (SFR5_BASE + 0x03*4)
#define PARCON4         SFR_RW (SFR5_BASE + 0x04*4)
#define PARCON5         SFR_RW (SFR5_BASE + 0x05*4)
#define PARCON6         SFR_RW (SFR5_BASE + 0x06*4)

#define FUNCINCON       SFR_RW (SFR5_BASE + 0x07*4)
#define FUNCOUTCON      SFR_RW (SFR5_BASE + 0x08*4)
#define FUNCOUTMCON     SFR_RW (SFR5_BASE + 0x09*4)
#define FUNCMCON0       SFR_RW (SFR5_BASE + 0x0a*4)
#define FUNCMCON1       SFR_RW (SFR5_BASE + 0x0b*4)
#define FUNCMCON2       SFR_RW (SFR5_BASE + 0x0c*4)

#define GPDMACON        SFR_RW (SFR5_BASE + 0x10*4)
#define GPDMAADDRST0    SFR_RW (SFR5_BASE + 0x11*4)
#define GPDMAADDRST1    SFR_RW (SFR5_BASE + 0x12*4)
#define GPDMAKICK       SFR_RW (SFR5_BASE + 0x13*4)

#define SADCDAT0        SFR_RO (SFR5_BASE + 0x20*4)
#define SADCDAT1        SFR_RO (SFR5_BASE + 0x21*4)
#define SADCDAT2        SFR_RO (SFR5_BASE + 0x22*4)
#define SADCDAT3        SFR_RO (SFR5_BASE + 0x23*4)
#define SADCDAT4        SFR_RO (SFR5_BASE + 0x24*4)
#define SADCDAT5        SFR_RO (SFR5_BASE + 0x25*4)
#define SADCDAT6        SFR_RO (SFR5_BASE + 0x26*4)
#define SADCDAT7        SFR_RO (SFR5_BASE + 0x27*4)
#define SADCDAT8        SFR_RO (SFR5_BASE + 0x28*4)
#define SADCDAT9        SFR_RO (SFR5_BASE + 0x29*4)
#define SADCDAT10       SFR_RO (SFR5_BASE + 0x2a*4)
#define SADCDAT11       SFR_RO (SFR5_BASE + 0x2b*4)
#define SADCDAT12       SFR_RO (SFR5_BASE + 0x2c*4)
#define SADCDAT13       SFR_RO (SFR5_BASE + 0x2d*4)
#define SADCDAT14       SFR_RO (SFR5_BASE + 0x2e*4)
#define SADCDAT15       SFR_RO (SFR5_BASE + 0x2f*4)

#define SADCCON         SFR_RW (SFR5_BASE + 0x30*4)
#define SADCCH          SFR_RW (SFR5_BASE + 0x31*4)
#define SADCST          SFR_WO (SFR5_BASE + 0x32*4)
#define SADCBAUD        SFR_WO (SFR5_BASE + 0x33*4)
#define MBISTCON        SFR_WO (SFR5_BASE + 0x34*4)
#define MBISTEADR       SFR_WO (SFR5_BASE + 0x35*4)
#define MBISTBADR       SFR_WO (SFR5_BASE + 0x36*4)
#define MBISTCRC        SFR_WO (SFR5_BASE + 0x37*4)
#define MBISTERR        SFR_WO (SFR5_BASE + 0x38*4)
#define EFCON0          SFR_RW (SFR5_BASE + 0x3d*4)
#define EFCON1          SFR_WO (SFR5_BASE + 0x3e*4)
#define EFDAT           SFR_RW (SFR5_BASE + 0x3f*4)

//------------------------- SFR Group6 ---------------------------------------//
#define GPIOASET        LPSFR_WO (SFR6_BASE + 0x00*4)
#define GPIOACLR        LPSFR_WO (SFR6_BASE + 0x01*4)
#define GPIOA           LPSFR_RW (SFR6_BASE + 0x02*4)
#define GPIOADIR        LPSFR_RW (SFR6_BASE + 0x03*4)
#define GPIOADE         LPSFR_RW (SFR6_BASE + 0x04*4)
#define GPIOAFEN        LPSFR_RW (SFR6_BASE + 0x05*4)
#define GPIOADRV        LPSFR_RW (SFR6_BASE + 0x06*4)
#define GPIOAPU         LPSFR_RW (SFR6_BASE + 0x07*4)
#define GPIOAPD         LPSFR_RW (SFR6_BASE + 0x08*4)
#define GPIOAPU200K     LPSFR_RW (SFR6_BASE + 0x09*4)
#define GPIOAPD200K     LPSFR_RW (SFR6_BASE + 0x0a*4)
#define GPIOAPU300      LPSFR_RW (SFR6_BASE + 0x0b*4)
#define GPIOAPD300      LPSFR_RW (SFR6_BASE + 0x0c*4)

#define GPIOBSET        LPSFR_WO (SFR6_BASE + 0x10*4)
#define GPIOBCLR        LPSFR_WO (SFR6_BASE + 0x11*4)
#define GPIOB           LPSFR_RW (SFR6_BASE + 0x12*4)
#define GPIOBDIR        LPSFR_RW (SFR6_BASE + 0x13*4)
#define GPIOBDE         LPSFR_RW (SFR6_BASE + 0x14*4)
#define GPIOBFEN        LPSFR_RW (SFR6_BASE + 0x15*4)
#define GPIOBDRV        LPSFR_RW (SFR6_BASE + 0x16*4)
#define GPIOBPU         LPSFR_RW (SFR6_BASE + 0x17*4)
#define GPIOBPD         LPSFR_RW (SFR6_BASE + 0x18*4)
#define GPIOBPU200K     LPSFR_RW (SFR6_BASE + 0x19*4)
#define GPIOBPD200K     LPSFR_RW (SFR6_BASE + 0x1a*4)
#define GPIOBPU300      LPSFR_RW (SFR6_BASE + 0x1b*4)
#define GPIOBPD300      LPSFR_RW (SFR6_BASE + 0x1c*4)

#define GPIOESET        LPSFR_WO (SFR6_BASE + 0x20*4)
#define GPIOECLR        LPSFR_WO (SFR6_BASE + 0x21*4)
#define GPIOE           LPSFR_RW (SFR6_BASE + 0x22*4)
#define GPIOEDIR        LPSFR_RW (SFR6_BASE + 0x23*4)
#define GPIOEDE         LPSFR_RW (SFR6_BASE + 0x24*4)
#define GPIOEFEN        LPSFR_RW (SFR6_BASE + 0x25*4)
#define GPIOEDRV        LPSFR_RW (SFR6_BASE + 0x26*4)
#define GPIOEPU         LPSFR_RW (SFR6_BASE + 0x27*4)
#define GPIOEPD         LPSFR_RW (SFR6_BASE + 0x28*4)
#define GPIOEPU200K     LPSFR_RW (SFR6_BASE + 0x29*4)
#define GPIOEPD200K     LPSFR_RW (SFR6_BASE + 0x2a*4)
#define GPIOEPU300      LPSFR_RW (SFR6_BASE + 0x2b*4)
#define GPIOEPD300      LPSFR_RW (SFR6_BASE + 0x2c*4)

#define GPIOFSET        LPSFR_WO (SFR6_BASE + 0x30*4)
#define GPIOFCLR        LPSFR_WO (SFR6_BASE + 0x31*4)
#define GPIOF           LPSFR_RW (SFR6_BASE + 0x32*4)
#define GPIOFDIR        LPSFR_RW (SFR6_BASE + 0x33*4)
#define GPIOFDE         LPSFR_RW (SFR6_BASE + 0x34*4)
#define GPIOFFEN        LPSFR_RW (SFR6_BASE + 0x35*4)
#define GPIOFDRV        LPSFR_RW (SFR6_BASE + 0x36*4)
#define GPIOFPU         LPSFR_RW (SFR6_BASE + 0x37*4)
#define GPIOFPD         LPSFR_RW (SFR6_BASE + 0x38*4)
#define GPIOFPU200K     LPSFR_RW (SFR6_BASE + 0x39*4)
#define GPIOFPD200K     LPSFR_RW (SFR6_BASE + 0x3a*4)
#define GPIOFPU300      LPSFR_RW (SFR6_BASE + 0x3b*4)
#define GPIOFPD300      LPSFR_RW (SFR6_BASE + 0x3c*4)

//------------------------- SFR Group7 ---------------------------------------//
#define GPIOGSET        LPSFR_WO (SFR7_BASE + 0x00*4)
#define GPIOGCLR        LPSFR_WO (SFR7_BASE + 0x01*4)
#define GPIOG           LPSFR_RW (SFR7_BASE + 0x02*4)
#define GPIOGDIR        LPSFR_RW (SFR7_BASE + 0x03*4)
#define GPIOGDE         LPSFR_RW (SFR7_BASE + 0x04*4)
#define GPIOGFEN        LPSFR_RW (SFR7_BASE + 0x05*4)
#define GPIOGDRV        LPSFR_RW (SFR7_BASE + 0x06*4)
#define GPIOGPU         LPSFR_RW (SFR7_BASE + 0x07*4)
#define GPIOGPD         LPSFR_RW (SFR7_BASE + 0x08*4)
#define GPIOGPU200K     LPSFR_RW (SFR7_BASE + 0x09*4)
#define GPIOGPD200K     LPSFR_RW (SFR7_BASE + 0x0a*4)
#define GPIOGPU300      LPSFR_RW (SFR7_BASE + 0x0b*4)
#define GPIOGPD300      LPSFR_RW (SFR7_BASE + 0x0c*4)

#define WKUPCON         LPSFR_RW (SFR7_BASE + 0x10*4)
#define WKUPEDG         LPSFR_RW (SFR7_BASE + 0x11*4)
#define WKUPCPND        LPSFR_WO (SFR7_BASE + 0x12*4)
#define PORTINTEDG      LPSFR_RW (SFR7_BASE + 0x13*4)
#define PORTINTEN       LPSFR_RW (SFR7_BASE + 0x14*4)
#define WKPINMAP        LPSFR_RW (SFR7_BASE + 0x15*4)
#define SENSCON         LPSFR_RW (SFR7_BASE + 0x16*4)
#define SENSCPND        LPSFR_WO (SFR7_BASE + 0x17*4)
#define SENSCNT         LPSFR_RW (SFR7_BASE + 0x18*4)
#define SENSCON1        LPSFR_RW (SFR7_BASE + 0x19*4)
#define BTCON2          LPSFR_RW (SFR7_BASE + 0x1a*4)

#define WKRSRC          LPSFR_RO (SFR7_BASE + 0x20*4)
#define WKFSRC          LPSFR_RO (SFR7_BASE + 0x21*4)
#define BTSNFCNT        LPSFR_RO (SFR7_BASE + 0x22*4)
#define BTSNCLKN        LPSFR_RO (SFR7_BASE + 0x23*4)

//------------------------- SFR Group8 ---------------------------------------//
#define IIC0CON0        SFR_RW (SFR8_BASE + 0x00*4)
#define IIC0CON1        SFR_RW (SFR8_BASE + 0x01*4)
#define IIC0CMDA        SFR_RW (SFR8_BASE + 0x02*4)
#define IIC0DATA        SFR_RW (SFR8_BASE + 0x03*4)
#define IIC0DMAADR      SFR_RW (SFR8_BASE + 0x04*4)
#define IIC0DMACNT      SFR_RW (SFR8_BASE + 0x05*4)
#define IIC0SSTS        SFR_RW (SFR8_BASE + 0x06*4)
#define IIC1CON0        SFR_RW (SFR8_BASE + 0x07*4)
#define IIC1CON1        SFR_RW (SFR8_BASE + 0x08*4)
#define IIC1CMDA        SFR_RW (SFR8_BASE + 0x09*4)
#define IIC1DATA        SFR_RW (SFR8_BASE + 0x0a*4)
#define IIC1DMAADR      SFR_RW (SFR8_BASE + 0x0b*4)
#define IIC1DMACNT      SFR_RW (SFR8_BASE + 0x0c*4)
#define IIC1SSTS        SFR_RW (SFR8_BASE + 0x0d*4)

#define AECFFTRST       SFR_RW (SFR8_BASE + 0x10*4)
#define AECFFTCON       SFR_RW (SFR8_BASE + 0x11*4)
#define AECFFTKICK      SFR_RW (SFR8_BASE + 0x12*4)
#define FFTDINADDR      SFR_RW (SFR8_BASE + 0x13*4)
#define FFTBUFADDR      SFR_RW (SFR8_BASE + 0x14*4)
#define AECCON1         SFR_RW (SFR8_BASE + 0x15*4)
#define AECCON2         SFR_RW (SFR8_BASE + 0x16*4)
#define AECCON3         SFR_RW (SFR8_BASE + 0x17*4)
#define AECCON4         SFR_RW (SFR8_BASE + 0x18*4)
#define AECCON5         SFR_RW (SFR8_BASE + 0x19*4)
#define AECFLAG         SFR_RW (SFR8_BASE + 0x1a*4)
#define IRRXCON         SFR_RW (SFR8_BASE + 0x1b*4)
#define IRRXDAT         SFR_RW (SFR8_BASE + 0x1c*4)
#define IRRXCPND        SFR_WO (SFR8_BASE + 0x1d*4)
#define IRRXERR0        SFR_WO (SFR8_BASE + 0x1e*4)
#define IRRXERR1        SFR_WO (SFR8_BASE + 0x1f*4)
#define IRRXPR0         SFR_WO (SFR8_BASE + 0x20*4)
#define IRRXPR1         SFR_WO (SFR8_BASE + 0x21*4)

#define PROTCON0        SFR_RW (SFR8_BASE + 0x22*4)
#define PROTCON1        SFR_RW (SFR8_BASE + 0x23*4)
#define CVSDCON0        SFR_RW (SFR8_BASE + 0x24*4)
#define CVSDCPND        SFR_WO (SFR8_BASE + 0x25*4)
#define CVSDDMACNT      SFR_WO (SFR8_BASE + 0x26*4)
#define CVSDDMAERADR    SFR_WO (SFR8_BASE + 0x27*4)
#define CVSDDMAEWADR    SFR_WO (SFR8_BASE + 0x28*4)
#define CVSDDMADRADR    SFR_WO (SFR8_BASE + 0x29*4)
#define CVSDDMADWADR    SFR_WO (SFR8_BASE + 0x2a*4)
#define CVSDPRED        SFR_RW (SFR8_BASE + 0x2c*4)
#define CVSDPREACC      SFR_RW (SFR8_BASE + 0x2d*4)
#define AECCON6         SFR_RW (SFR8_BASE + 0x2f*4)
#define AECCON7         SFR_RW (SFR8_BASE + 0x30*4)


#define QDECCON         SFR_RW (SFR8_BASE + 0x31*4)
#define QDECCPND        SFR_RW (SFR8_BASE + 0x32*4)

#define SQRT64L         SFR_RW (SFR8_BASE + 0x33*4)
#define SQRT64H         SFR_RW (SFR8_BASE + 0x34*4)
#define PLCCON0         SFR_RW (SFR8_BASE + 0x35*4)
#define PLCCON1         SFR_RW (SFR8_BASE + 0x36*4)
#define PLCCON2         SFR_RW (SFR8_BASE + 0x37*4)
#define MINPOWER        SFR_RW (SFR8_BASE + 0x38*4)
#define PLCKICK         SFR_RW (SFR8_BASE + 0x39*4)
#define PLCLOOPBASE     SFR_RW (SFR8_BASE + 0x3a*4)
#define PLCLOOPSIZE     SFR_RW (SFR8_BASE + 0x3b*4)
#define PLCSPTR         SFR_RW (SFR8_BASE + 0x3c*4)
#define PLCOPTR         SFR_RW (SFR8_BASE + 0x3d*4)
#define PLCFADDR        SFR_RW (SFR8_BASE + 0x3e*4)

//------------------------- SFR Group9 ---------------------------------------//
#define TMR3CON         SFR_RW (SFR9_BASE + 0x00*4)
#define TMR3CPND        SFR_WO (SFR9_BASE + 0x01*4)
#define TMR3CNT         SFR_RW (SFR9_BASE + 0x02*4)
#define TMR3PR          SFR_RW (SFR9_BASE + 0x03*4)
#define TMR3CPT         SFR_RO (SFR9_BASE + 0x04*4)
//#define TMR3DUTY0       SFR_WO (SFR9_BASE + 0x05*4)
//#define TMR3DUTY1       SFR_WO (SFR9_BASE + 0x06*4)
//#define TMR3DUTY2       SFR_WO (SFR9_BASE + 0x07*4)
#define TMR4CON         SFR_RW (SFR9_BASE + 0x08*4)
#define TMR4CPND        SFR_WO (SFR9_BASE + 0x09*4)
#define TMR4CNT         SFR_RW (SFR9_BASE + 0x0a*4)
#define TMR4PR          SFR_RW (SFR9_BASE + 0x0b*4)
#define TMR4CPT         SFR_RO (SFR9_BASE + 0x0c*4)
//#define TMR4DUTY0       SFR_WO (SFR9_BASE + 0x0d*4)
//#define TMR4DUTY1       SFR_WO (SFR9_BASE + 0x0e*4)
//#define TMR4DUTY2       SFR_WO (SFR9_BASE + 0x0f*4)

#define TMR5CON         SFR_RW (SFR9_BASE + 0x10*4)
#define TMR5CPND        SFR_WO (SFR9_BASE + 0x11*4)
#define TMR5CNT         SFR_RW (SFR9_BASE + 0x12*4)
#define TMR5PR          SFR_RW (SFR9_BASE + 0x13*4)
#define TMR5CPT         SFR_RO (SFR9_BASE + 0x14*4)
#define TMR5DUTY0       SFR_RW (SFR9_BASE + 0x15*4)
#define TMR5DUTY1       SFR_RW (SFR9_BASE + 0x16*4)
#define TMR5DUTY2       SFR_RW (SFR9_BASE + 0x17*4)
#define TMR5DUTY3       SFR_RW (SFR9_BASE + 0x18*4)
#define TMR5DUTY4       SFR_RW (SFR9_BASE + 0x19*4)
#define TMR5DUTY5       SFR_RW (SFR9_BASE + 0x1a*4)

#define SPI1CON         SFR_RW (SFR9_BASE + 0x20*4)
#define SPI1BUF         SFR_RW (SFR9_BASE + 0x21*4)
#define SPI1BAUD        SFR_RW (SFR9_BASE + 0x22*4)
#define SPI1CPND        SFR_RW (SFR9_BASE + 0x23*4)
#define SPI1DMACNT      SFR_RW (SFR9_BASE + 0x24*4)
#define SPI1DMAADR      SFR_RW (SFR9_BASE + 0x25*4)

#define FREQDETCON      SFR_RW (SFR9_BASE + 0x28*4)
#define FREQDETCPND     SFR_RW (SFR9_BASE + 0x29*4)
#define FREQDETCNT      SFR_RW (SFR9_BASE + 0x2a*4)
#define FREQDETTGT      SFR_RW (SFR9_BASE + 0x2b*4)

#define RTCRAMADR       SFR_RW (SFR9_BASE + 0x2c*4)
#define RTCRAMDAT       SFR_RW (SFR9_BASE + 0x2d*4)
#define RTCALM          SFR_RW (SFR9_BASE + 0x2e*4)
#define RTCCNT          SFR_RW (SFR9_BASE + 0x2f*4)

#define RTCCON0         SFR_RW (SFR9_BASE + 0x30*4)
#define RTCCON1         SFR_RW (SFR9_BASE + 0x31*4)
#define RTCCON2         SFR_RW (SFR9_BASE + 0x32*4)
#define RTCCON3         SFR_RW (SFR9_BASE + 0x33*4)
#define RTCCON4         SFR_RW (SFR9_BASE + 0x34*4)
#define RTCCON5         SFR_RW (SFR9_BASE + 0x35*4)
#define RTCCON6         SFR_RW (SFR9_BASE + 0x36*4)
#define RTCCON7         SFR_RW (SFR9_BASE + 0x37*4)
#define RTCCON8         SFR_RW (SFR9_BASE + 0x38*4)
#define RTCCON9         SFR_RW (SFR9_BASE + 0x39*4)
#define RTCCON10        SFR_RW (SFR9_BASE + 0x3a*4)
#define RTCCON11        SFR_RW (SFR9_BASE + 0x3b*4)
#define RTCCON12        SFR_RW (SFR9_BASE + 0x3c*4)
#define RTCCON13        SFR_RW (SFR9_BASE + 0x3d*4)
#define RTCCON14        SFR_RW (SFR9_BASE + 0x3e*4)
#define RTCCON15        SFR_RW (SFR9_BASE + 0x3f*4)

//------------------------- SFR Group10 --------------------------------------//

#define PBQCON          SFR_RW (SFR10_BASE + 0x00*4)
#define PBQ0CON         SFR_RW (SFR10_BASE + 0x01*4)
//#define PBQ1CON         SFR_RW (SFR10_BASE + 0x02*4)
#define PBQPEND         SFR_RW (SFR10_BASE + 0x03*4)
#define PBQCOEF         SFR_RW (SFR10_BASE + 0x04*4)
#define PBQGAIN         SFR_RW (SFR10_BASE + 0x05*4)
#define PBQDMARADR      SFR_RW (SFR10_BASE + 0x06*4)
#define PBQDMAWADR      SFR_RW (SFR10_BASE + 0x07*4)
#define PBQDMASIZE      SFR_RW (SFR10_BASE + 0x08*4)
#define PIANOCON        SFR_RW (SFR10_BASE + 0x09*4)
#define PIANOBUF        SFR_WO (SFR10_BASE + 0x0a*4)
#define TONEDLY         SFR_RW (SFR10_BASE + 0x0b*4)
#define TONEDLY1        SFR_RW (SFR10_BASE + 0x0c*4)
#define AU0DMAOCON      SFR_RW (SFR10_BASE + 0x0d*4)
#define AU0DMAOADR      SFR_RW (SFR10_BASE + 0x0e*4)
#define AU0DMAOSIZE     SFR_RW (SFR10_BASE + 0x0f*4)

#define DECON           SFR_RW (SFR10_BASE + 0x10*4)
#define DEPEND          SFR_RW (SFR10_BASE + 0x11*4)
#define DEPAR0          SFR_RW (SFR10_BASE + 0x12*4)
#define DEPAR1          SFR_RW (SFR10_BASE + 0x13*4)
#define DEPAR2          SFR_RW (SFR10_BASE + 0x14*4)
#define DEPAR3          SFR_RW (SFR10_BASE + 0x15*4)
#define DEPAR4          SFR_RW (SFR10_BASE + 0x16*4)
#define DEPAR5          SFR_RW (SFR10_BASE + 0x17*4)
#define DEPAR6          SFR_RW (SFR10_BASE + 0x18*4)
#define DEPAR7          SFR_RW (SFR10_BASE + 0x19*4)
#define DEPAR8          SFR_RW (SFR10_BASE + 0x1a*4)
#define DEPAR9          SFR_RW (SFR10_BASE + 0x1b*4)
#define DEPAR10         SFR_RW (SFR10_BASE + 0x1c*4)
#define DEPAR11         SFR_RW (SFR10_BASE + 0x1d*4)
#define DESPICON        SFR_RW (SFR10_BASE + 0x1e*4)
#define DESPIBUF        SFR_RW (SFR10_BASE + 0x1f*4)

#define DESPIBAUD       SFR_RW (SFR10_BASE + 0x20*4)
#define DESPICPND       SFR_RW (SFR10_BASE + 0x21*4)
#define DESPIDMACNT     SFR_RW (SFR10_BASE + 0x22*4)
#define DESPIDMAADR     SFR_RW (SFR10_BASE + 0x23*4)
#define FACON           SFR_RW (SFR10_BASE + 0x24*4)
#define FAPEND          SFR_RW (SFR10_BASE + 0x25*4)
#define FAPAR0          SFR_RW (SFR10_BASE + 0x26*4)
#define FAPAR1          SFR_RW (SFR10_BASE + 0x27*4)
#define FAPAR2          SFR_RW (SFR10_BASE + 0x28*4)
#define FAPAR3          SFR_RW (SFR10_BASE + 0x29*4)
#define FAPAR4          SFR_RW (SFR10_BASE + 0x2a*4)
#define WPTCON          SFR_RW (SFR10_BASE + 0x2b*4)
#define WPTPND          SFR_RW (SFR10_BASE + 0x2c*4)
#define WPTADR          SFR_RW (SFR10_BASE + 0x2d*4)
#define WPTDAT          SFR_RW (SFR10_BASE + 0x2e*4)
#define MEMCON1         SFR_RW (SFR10_BASE + 0x2f*4)

#define MEMCON2         SFR_RW (SFR10_BASE + 0x30*4)
#define SWSINPHASE      SFR_RW (SFR10_BASE + 0x31*4)
#define SWSINWAVE       SFR_RW (SFR10_BASE + 0x32*4)

#ifndef __ASSEMBLER__
enum funo_select_tbl {
    FO_T5PWM0              = 0,
    FO_T5PWM1,
    FO_T5PWM2,
    FO_T5PWM3,
    FO_UR0TX,
    FO_HURTX,
    FO_UR1TX,
    FO_I2C0SCL,
    FO_I2C0SDA,
    FO_CLKOUT,
    FO_SPI1D0,
    FO_SPI1D1,
    FO_SPI1CLK,
    FO_I2C1SCL,
    FO_I2C1SDA,
};

enum funo_io_tbl {
    FO_PA0              = 1,
    FO_PA1,
    FO_PA2,
    FO_PA3,
    FO_PA4,
    FO_PA5,
    FO_PA6,
    FO_PA7,
    FO_PB0              = 9,
    FO_PB1,
    FO_PB2,
    FO_PB3,
    FO_PB4,
    FO_PB5,
    FO_PB6,
    FO_PB7,
    FO_PE0              = 17,
    FO_PE1,
    FO_PE2,
    FO_PE3,
    FO_PE4,
    FO_PE5,
    FO_PE6,
    FO_PE7,
    FO_PF0              = 25,
    FO_PF1,
    FO_PF2,
    FO_PF3,
    FO_PF4,
    FO_PF5,
};

enum funi_io_tbl {
    FI_PA0              = 0,
    FI_PA1,
    FI_PA2,
    FI_PA3,
    FI_PA4,
    FI_PA5,
    FI_PA6,
    FI_PA7,
    FI_PB0              = 8,
    FI_PB1,
    FI_PB2,
    FI_PB3,
    FI_PB4,
    FI_PB5,
    FI_PB6,
    FI_PB7,
    FI_PE0              = 16,
    FI_PE1,
    FI_PE2,
    FI_PE3,
    FI_PE4,
    FI_PE5,
    FI_PE6,
    FI_PE7,
    FI_PF0              = 24,
    FI_PF1,
    FI_PF2,
    FI_PF3,
    FI_PF4,
    FI_PF5,
    FI_PG0              = 30,
    FI_PG1,
    FI_PG2,
    FI_PG3,
    FI_PG4,
    FI_PG5,
};
#endif

//channel output function select
#define CH0_FUNO_SEL(ch0_funo_sel) FUNCOUTCON = (ch0_funo_sel << 0)
#define CH1_FUNO_SEL(ch1_funo_sel) FUNCOUTCON = (ch1_funo_sel << 8)
#define CH2_FUNO_SEL(ch2_funo_sel) FUNCOUTCON = (ch2_funo_sel <<16)
#define CH3_FUNO_SEL(ch3_funo_sel) FUNCOUTCON = (ch3_funo_sel <<24)

//channel 0 output mapping
#define CH0_FUNO_PA0MAP            FUNCOUTMCON = ( 1 << 0)
#define CH0_FUNO_PA1MAP            FUNCOUTMCON = ( 2 << 0)
#define CH0_FUNO_PA2MAP            FUNCOUTMCON = ( 3 << 0)
#define CH0_FUNO_PA3MAP            FUNCOUTMCON = ( 4 << 0)
#define CH0_FUNO_PA4MAP            FUNCOUTMCON = ( 5 << 0)
#define CH0_FUNO_PA5MAP            FUNCOUTMCON = ( 6 << 0)
#define CH0_FUNO_PA6MAP            FUNCOUTMCON = ( 7 << 0)
#define CH0_FUNO_PA7MAP            FUNCOUTMCON = ( 8 << 0)

#define CH0_FUNO_PB0MAP            FUNCOUTMCON = ( 9 << 0)
#define CH0_FUNO_PB1MAP            FUNCOUTMCON = (10 << 0)
#define CH0_FUNO_PB2MAP            FUNCOUTMCON = (11 << 0)
#define CH0_FUNO_PB3MAP            FUNCOUTMCON = (12 << 0)
#define CH0_FUNO_PB4MAP            FUNCOUTMCON = (13 << 0)
#define CH0_FUNO_PB5MAP            FUNCOUTMCON = (14 << 0)
#define CH0_FUNO_PB6MAP            FUNCOUTMCON = (15 << 0)
#define CH0_FUNO_PB7MAP            FUNCOUTMCON = (16 << 0)

#define CH0_FUNO_PE0MAP            FUNCOUTMCON = (17 << 0)
#define CH0_FUNO_PE1MAP            FUNCOUTMCON = (18 << 0)
#define CH0_FUNO_PE2MAP            FUNCOUTMCON = (19 << 0)
#define CH0_FUNO_PE3MAP            FUNCOUTMCON = (20 << 0)
#define CH0_FUNO_PE4MAP            FUNCOUTMCON = (21 << 0)
#define CH0_FUNO_PE5MAP            FUNCOUTMCON = (22 << 0)
#define CH0_FUNO_PE6MAP            FUNCOUTMCON = (23 << 0)
#define CH0_FUNO_PE7MAP            FUNCOUTMCON = (24 << 0)

#define CH0_FUNO_PF0MAP            FUNCOUTMCON = (25 << 0)
#define CH0_FUNO_PF1MAP            FUNCOUTMCON = (26 << 0)
#define CH0_FUNO_PF2MAP            FUNCOUTMCON = (27 << 0)
#define CH0_FUNO_PF3MAP            FUNCOUTMCON = (28 << 0)
#define CH0_FUNO_PF4MAP            FUNCOUTMCON = (29 << 0)
#define CH0_FUNO_PF5MAP            FUNCOUTMCON = (30 << 0)

//channel 1 output mapping
#define CH1_FUNO_PA0MAP            FUNCOUTMCON = ( 1 << 8)
#define CH1_FUNO_PA1MAP            FUNCOUTMCON = ( 2 << 8)
#define CH1_FUNO_PA2MAP            FUNCOUTMCON = ( 3 << 8)
#define CH1_FUNO_PA3MAP            FUNCOUTMCON = ( 4 << 8)
#define CH1_FUNO_PA4MAP            FUNCOUTMCON = ( 5 << 8)
#define CH1_FUNO_PA5MAP            FUNCOUTMCON = ( 6 << 8)
#define CH1_FUNO_PA6MAP            FUNCOUTMCON = ( 7 << 8)
#define CH1_FUNO_PA7MAP            FUNCOUTMCON = ( 8 << 8)

#define CH1_FUNO_PB0MAP            FUNCOUTMCON = ( 9 << 8)
#define CH1_FUNO_PB1MAP            FUNCOUTMCON = (10 << 8)
#define CH1_FUNO_PB2MAP            FUNCOUTMCON = (11 << 8)
#define CH1_FUNO_PB3MAP            FUNCOUTMCON = (12 << 8)
#define CH1_FUNO_PB4MAP            FUNCOUTMCON = (13 << 8)
#define CH1_FUNO_PB5MAP            FUNCOUTMCON = (14 << 8)
#define CH1_FUNO_PB6MAP            FUNCOUTMCON = (15 << 8)
#define CH1_FUNO_PB7MAP            FUNCOUTMCON = (16 << 8)

#define CH1_FUNO_PE0MAP            FUNCOUTMCON = (17 << 8)
#define CH1_FUNO_PE1MAP            FUNCOUTMCON = (18 << 8)
#define CH1_FUNO_PE2MAP            FUNCOUTMCON = (19 << 8)
#define CH1_FUNO_PE3MAP            FUNCOUTMCON = (20 << 8)
#define CH1_FUNO_PE4MAP            FUNCOUTMCON = (21 << 8)
#define CH1_FUNO_PE5MAP            FUNCOUTMCON = (22 << 8)
#define CH1_FUNO_PE6MAP            FUNCOUTMCON = (23 << 8)
#define CH1_FUNO_PE7MAP            FUNCOUTMCON = (24 << 8)

#define CH1_FUNO_PF0MAP            FUNCOUTMCON = (25 << 8)
#define CH1_FUNO_PF1MAP            FUNCOUTMCON = (26 << 8)
#define CH1_FUNO_PF2MAP            FUNCOUTMCON = (27 << 8)
#define CH1_FUNO_PF3MAP            FUNCOUTMCON = (28 << 8)
#define CH1_FUNO_PF4MAP            FUNCOUTMCON = (29 << 8)
#define CH1_FUNO_PF5MAP            FUNCOUTMCON = (30 << 8)

//channel 2 output mapping
#define CH2_FUNO_PA0MAP            FUNCOUTMCON = ( 1 <<16)
#define CH2_FUNO_PA1MAP            FUNCOUTMCON = ( 2 <<16)
#define CH2_FUNO_PA2MAP            FUNCOUTMCON = ( 3 <<16)
#define CH2_FUNO_PA3MAP            FUNCOUTMCON = ( 4 <<16)
#define CH2_FUNO_PA4MAP            FUNCOUTMCON = ( 5 <<16)
#define CH2_FUNO_PA5MAP            FUNCOUTMCON = ( 6 <<16)
#define CH2_FUNO_PA6MAP            FUNCOUTMCON = ( 7 <<16)
#define CH2_FUNO_PA7MAP            FUNCOUTMCON = ( 8 <<16)

#define CH2_FUNO_PB0MAP            FUNCOUTMCON = ( 9 <<16)
#define CH2_FUNO_PB1MAP            FUNCOUTMCON = (10 <<16)
#define CH2_FUNO_PB2MAP            FUNCOUTMCON = (11 <<16)
#define CH2_FUNO_PB3MAP            FUNCOUTMCON = (12 <<16)
#define CH2_FUNO_PB4MAP            FUNCOUTMCON = (13 <<16)
#define CH2_FUNO_PB5MAP            FUNCOUTMCON = (14 <<16)
#define CH2_FUNO_PB6MAP            FUNCOUTMCON = (15 <<16)
#define CH2_FUNO_PB7MAP            FUNCOUTMCON = (16 <<16)

#define CH2_FUNO_PE0MAP            FUNCOUTMCON = (17 <<16)
#define CH2_FUNO_PE1MAP            FUNCOUTMCON = (18 <<16)
#define CH2_FUNO_PE2MAP            FUNCOUTMCON = (19 <<16)
#define CH2_FUNO_PE3MAP            FUNCOUTMCON = (20 <<16)
#define CH2_FUNO_PE4MAP            FUNCOUTMCON = (21 <<16)
#define CH2_FUNO_PE5MAP            FUNCOUTMCON = (22 <<16)
#define CH2_FUNO_PE6MAP            FUNCOUTMCON = (23 <<16)
#define CH2_FUNO_PE7MAP            FUNCOUTMCON = (24 <<16)

#define CH2_FUNO_PF0MAP            FUNCOUTMCON = (25 <<16)
#define CH2_FUNO_PF1MAP            FUNCOUTMCON = (26 <<16)
#define CH2_FUNO_PF2MAP            FUNCOUTMCON = (27 <<16)
#define CH2_FUNO_PF3MAP            FUNCOUTMCON = (28 <<16)
#define CH2_FUNO_PF4MAP            FUNCOUTMCON = (29 <<16)
#define CH2_FUNO_PF5MAP            FUNCOUTMCON = (30 <<16)

//channel 3 output mapping
#define CH3_FUNO_PA0MAP            FUNCOUTMCON = ( 1 <<24)
#define CH3_FUNO_PA1MAP            FUNCOUTMCON = ( 2 <<24)
#define CH3_FUNO_PA2MAP            FUNCOUTMCON = ( 3 <<24)
#define CH3_FUNO_PA3MAP            FUNCOUTMCON = ( 4 <<24)
#define CH3_FUNO_PA4MAP            FUNCOUTMCON = ( 5 <<24)
#define CH3_FUNO_PA5MAP            FUNCOUTMCON = ( 6 <<24)
#define CH3_FUNO_PA6MAP            FUNCOUTMCON = ( 7 <<24)
#define CH3_FUNO_PA7MAP            FUNCOUTMCON = ( 8 <<24)

#define CH3_FUNO_PB0MAP            FUNCOUTMCON = ( 9 <<24)
#define CH3_FUNO_PB1MAP            FUNCOUTMCON = (10 <<24)
#define CH3_FUNO_PB2MAP            FUNCOUTMCON = (11 <<24)
#define CH3_FUNO_PB3MAP            FUNCOUTMCON = (12 <<24)
#define CH3_FUNO_PB4MAP            FUNCOUTMCON = (13 <<24)
#define CH3_FUNO_PB5MAP            FUNCOUTMCON = (14 <<24)
#define CH3_FUNO_PB6MAP            FUNCOUTMCON = (15 <<24)
#define CH3_FUNO_PB7MAP            FUNCOUTMCON = (16 <<24)

#define CH3_FUNO_PE0MAP            FUNCOUTMCON = (17 <<24)
#define CH3_FUNO_PE1MAP            FUNCOUTMCON = (18 <<24)
#define CH3_FUNO_PE2MAP            FUNCOUTMCON = (19 <<24)
#define CH3_FUNO_PE3MAP            FUNCOUTMCON = (20 <<24)
#define CH3_FUNO_PE4MAP            FUNCOUTMCON = (21 <<24)
#define CH3_FUNO_PE5MAP            FUNCOUTMCON = (22 <<24)
#define CH3_FUNO_PE6MAP            FUNCOUTMCON = (23 <<24)
#define CH3_FUNO_PE7MAP            FUNCOUTMCON = (24 <<24)

#define CH3_FUNO_PF0MAP            FUNCOUTMCON = (25 <<24)
#define CH3_FUNO_PF1MAP            FUNCOUTMCON = (26 <<24)
#define CH3_FUNO_PF2MAP            FUNCOUTMCON = (27 <<24)
#define CH3_FUNO_PF3MAP            FUNCOUTMCON = (28 <<24)
#define CH3_FUNO_PF4MAP            FUNCOUTMCON = (29 <<24)
#define CH3_FUNO_PF5MAP            FUNCOUTMCON = (30 <<24)

//channel input function select
#define CH0_FUNI_SEL(ch0_funi_sel) FUNCINCON  = (ch0_funi_sel << 0)
#define CH1_FUNI_SEL(ch1_funi_sel) FUNCINCON  = (ch1_funi_sel << 8)
#define CH2_FUNI_SEL(ch2_funi_sel) FUNCINCON  = (ch2_funi_sel <<16)
#define CH3_FUNI_SEL(ch3_funi_sel) FUNCINCON  = (ch3_funi_sel <<24)

#endif
