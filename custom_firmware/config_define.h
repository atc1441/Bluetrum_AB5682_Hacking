/*****************************************************************************
 * Module    : Configs
 * File      : config_define.h
 * Function  : 定义用户参数常量
 *****************************************************************************/
#ifndef CONFIG_DEFINE_H
#define CONFIG_DEFINE_H

/*****************************************************************************
 * Module    : 系统定义
 *****************************************************************************/
#define XOSC_CLK_HZ                     26000000
#define CHIP_QNF32B                    1
#define CHIP_QNF32C                    2

/*****************************************************************************
 * Module    : 显示相关配置选择列表
 *****************************************************************************/
//显示驱动屏选择
#define DISPLAY_NO                      0                                       //无显示模块
#define DISPLAY_LCD                     0x100                                   //选用LCD点阵屏做为显示驱动
#define DISPLAY_LCDSEG                  0x200                                   //选用断码屏做为显示驱动
#define DISPLAY_LEDSEG                  0x400                                   //选用数码管做为显示驱动
#define DISPLAY_TFT                     0x800                                   //选用彩屏做为显示驱动

#define GUI_NO                          DISPLAY_NO                              //无主题，无显示
#define GUI_TFT_320_ST77916             (DISPLAY_TFT | 0x01)                    //彩屏 320 * 385
#define GUI_TFT_360_GC9C01              (DISPLAY_TFT | 0x02)                    //彩屏 360 * 360
#define GUI_OLED_466_ICNA3310B          (DISPLAY_TFT | 0x03)                    //OLED彩屏 466 * 466
#define GUI_TFT_JD9853                  (DISPLAY_TFT | 0x04)                    //JD9853  240*296 DSPI 屏
#define GUI_TFT_240_ST7789              (DISPLAY_TFT | 0x05)                    //ST7789  240*296 SPI 屏

#define CTP_NO                          0
#define CTP_CST8X                       1
#define CTP_CHSC6X                      2
#define CTP_AXS5106                     3



/*****************************************************************************
 * Module    : FLASH大小定义
 *****************************************************************************/
#define FSIZE_8M                        0x800000
#define FSIZE_4M                        0x400000
#define FSIZE_2M                        0x200000
#define FSIZE_1M                        0x100000
#define FSIZE_512K                      0x80000


/*****************************************************************************
 * Module    : 提示音语言配置选择列表
 *****************************************************************************/
#define LANG_EN         0               //英文提示音
#define LANG_ZH         1               //中文提示音
#define LANG_EN_ZH      2               //英文、中文双语提示音

/*****************************************************************************
 * Module    : ADC通路选择列表
 *****************************************************************************/
#define ADCCH_PA0       0               //SARADC channel 0
#define ADCCH_PA1       1               //SARADC channel 1
#define ADCCH_PB0       2               //SARADC channel 2
#define ADCCH_PB1       3               //SARADC channel 3
#define ADCCH_PB2       4               //SARADC channel 4
#define ADCCH_PB3       5               //SARADC channel 5
#define ADCCH_PB4       6               //SARADC channel 6
#define ADCCH_PB7       7               //SARADC channel 7
#define ADCCH_PF1       8               //SARADC channel 8
#define ADCCH_PF2       9               //SARADC channel 9
#define ADCCH_PF3       10              //SARADC channel 10
#define ADCCH_PE6       11              //SARADC channel 11
#define ADCCH_PE7       12              //SARADC channel 12
#define ADCCH_WKO       13              //SARADC channel 13
#define ADCCH_VBAT      14              //SARADC channel 14
#define ADCCH_VRTC      15              //SARADC channel 15
#define ADCCH_BGOP      15              //SARADC channel 15
#define ADCCH_VUSB      15              //SARADC channel 15
#define ADCCH_VTS       15              //SARADC channel 15

/*****************************************************************************
 * Module    : Timer3 Capture Mapping选择列表
 *          FUNCMCON2[7:4], 例如FUNCMCON2 = TMR3MAP_PA5;
 *****************************************************************************/
#define TMR3MAP_PA5     (1 << 4)        //G1  capture mapping: PA5
#define TMR3MAP_PA6     (2 << 4)        //G2  capture mapping: PA6
#define TMR3MAP_PB0     (3 << 4)        //G3  capture mapping: PB0
#define TMR3MAP_PB1     (4 << 4)        //G4  capture mapping: PB1
#define TMR3MAP_PE0     (5 << 4)        //G5  capture mapping: PE0
#define TMR3MAP_PE3     (6 << 4)        //G6  capture mapping: PE3
#define TMR3MAP_PE4     (7 << 4)        //G7  capture mapping: PE4
#define TMR3MAP_PE5     (8 << 4)        //G8  capture mapping: PE5
#define TMR3MAP_PF2     (9 << 4)        //G9  capture mapping: PF2

/*****************************************************************************
 * Module    : IRRX Mapping选择列表
 *          FUNCMCON2[23:20], 例如FUNCMCON2 = IRMAP_PA5;
 *****************************************************************************/
#define IRMAP_PA5       (1 << 20)       //G1  capture mapping: PA5
#define IRMAP_PA6       (2 << 20)       //G2  capture mapping: PA6
#define IRMAP_PB0       (3 << 20)       //G3  capture mapping: PB0
#define IRMAP_PB1       (4 << 20)       //G4  capture mapping: PB1
#define IRMAP_PE0       (5 << 20)       //G5  capture mapping: PE0
#define IRMAP_PE3       (6 << 20)       //G6  capture mapping: PE3
#define IRMAP_PE4       (7 << 20)       //G7  capture mapping: PE4
#define IRMAP_PE5       (8 << 20)       //G8  capture mapping: PE5
#define IRMAP_PF2       (9 << 20)       //G9  capture mapping: PF2


/*****************************************************************************
 * Module    : Timer5 PWM Mapping选择列表
 * PWM0 = FUNCMCON1[11:8],  PWM1 = FUNCMCON1[15:12], PWM2 = FUNCMCON1[19:16]
 * PWM3 = FUNCMCON1[23:20], PWM4 = FUNCMCON1[27:24], PWM5 = FUNCMCON1[31:28]
 * 示例：FUNCMCON1 = PWM0MAP_PA0;
 *****************************************************************************/
#define PWM0MAP_PA0    (1 << 8)        //G1 PWM0 mapping: PA0
#define PWM1MAP_PA1    (1 << 12)       //G1 PWM1 mapping: PA1
#define PWM2MAP_PA2    (1 << 16)       //G1 PWM2 mapping: PA2
#define PWM3MAP_PA3    (1 << 20)       //G1 PWM3 mapping: PA3
#define PWM4MAP_PA4    (1 << 24)       //G1 PWM3 mapping: PA4
#define PWM5MAP_PA5    (1 << 28)       //G1 PWM3 mapping: PA5

#define PWM0MAP_PA6    (2 << 8)        //G2 PWM0 mapping: PA6
#define PWM1MAP_PA7    (2 << 12)       //G2 PWM1 mapping: PA7
#define PWM2MAP_PB0    (2 << 16)       //G2 PWM2 mapping: PB0
#define PWM3MAP_PB1    (2 << 20)       //G2 PWM3 mapping: PB1
#define PWM4MAP_PB2    (2 << 24)       //G2 PWM3 mapping: PB2
#define PWM5MAP_PB3    (2 << 28)       //G2 PWM3 mapping: PB3

#define PWM0MAP_PB4    (3 << 8)        //G3 PWM0 mapping: PB4
#define PWM1MAP_PB5    (3 << 12)       //G3 PWM1 mapping: PB5
#define PWM2MAP_PB6    (3 << 16)       //G3 PWM2 mapping: PB6
#define PWM3MAP_PB7    (3 << 20)       //G3 PWM3 mapping: PB7
#define PWM4MAP_PE6    (3 << 24)       //G3 PWM3 mapping: PE6
#define PWM5MAP_PE7    (3 << 28)       //G3 PWM3 mapping: PE7

#define PWM0MAP_PE0    (4 << 8)        //G4 PWM0 mapping: PE0
#define PWM1MAP_PE1    (4 << 12)       //G4 PWM1 mapping: PE1
#define PWM2MAP_PE2    (4 << 16)       //G4 PWM2 mapping: PE2
#define PWM3MAP_PE3    (4 << 20)       //G4 PWM3 mapping: PE3
#define PWM4MAP_PE4    (4 << 24)       //G4 PWM3 mapping: PE4
#define PWM5MAP_PE5    (4 << 28)       //G4 PWM3 mapping: PE5

#define PWM0MAP_PF0    (5 << 8)        //G5 PWM0 mapping: PF0
#define PWM1MAP_PF1    (5 << 12)       //G5 PWM1 mapping: PF1
#define PWM2MAP_PF2    (5 << 16)       //G5 PWM2 mapping: PF2
#define PWM3MAP_PF3    (5 << 20)       //G5 PWM3 mapping: PF3
#define PWM4MAP_PF4    (5 << 24)       //G5 PWM3 mapping: PF4
#define PWM5MAP_PF5    (5 << 28)       //G5 PWM3 mapping: PF5


/*****************************************************************************
 * Module    : Clock output Mapping选择列表
 *          FUNCMCON1[3:0], 例如FUNCMCON1 = CLKOMAP_PB3;
 *****************************************************************************/
#define CLKOMAP_PB3     (1 << 0)        //G1 Clock output mapping: PB3
#define CLKOMAP_PB4     (2 << 0)        //G2 Clock output mapping: PB4
#define CLKOMAP_PE0     (3 << 0)        //G3 Clock output mapping: PE0
#define CLKOMAP_PF0     (4 << 0)        //G4 Clock output mapping: PF0
#define CLKOMAP_PF4     (5 << 0)        //G5 Clock output mapping: PF4
#define CLKOMAP_PE7     (6 << 0)        //G6 Clock output mapping: PE7
#define CLKOMAP_PA7     (7 << 0)        //G7 Clock output mapping: PA7


/*****************************************************************************
 * Module    : sd0 Mapping选择列表
 *          FUNCMCON0[3:0], 例如FUNCMCON0 = SD0MAP_G1;
 *****************************************************************************/
#define SD0MAP_G1       (1 << 0)       //G1  SDCLK(PB0), SDCMD(PB1), SDDAT0(PB2)
#define SD0MAP_G2       (2 << 0)       //G2  SDCLK(PB7), SDCMD(PB6), SDDAT0(PB5)
#define SD0MAP_G3       (3 << 0)       //G3  SDCLK(PE3), SDCMD(PE2), SDDAT0(PE1)


/*****************************************************************************
 * Module    : spi1 Mapping选择列表
  *          FUNCMCON1[7:4], 例如FUNCMCON1 = SPI1MAP_G1;
 *****************************************************************************/
#define SPI1MAP_G1     (1 << 4)         //G1 SPI1CLK(PA1), SPI1DI(PA3), SPI1DO(PA0)
#define SPI1MAP_G2     (2 << 4)         //G2 SPI1CLK(PB1), SPI1DI(PB0), SPI1DO(PB2)
#define SPI1MAP_G3     (3 << 4)         //G3 SPI1CLK(PB7), SPI1DI(PB6), SPI1DO(PB5)
#define SPI1MAP_G4     (4 << 4)         //G4 SPI1CLK(PE6), SPI1DI(PE5), SPI1DO(PE4)
#define SPI1MAP_G5     (5 << 4)         //G5 SPI1CLK(PF3), SPI1DI(PF2), SPI1DO(PF1), SPI1DIOD2(PE1), SPI1DIOD3(PE2)
#define SPI1MAP_G6     (6 << 4)         //G6 SPI1CLK(PA4), SPI1DI(PA3), SPI1DO(PA2), SPI1DIOD2(PA1), SPI1DIOD3(PA0)


/*****************************************************************************
 * Module    : uart0 Mapping选择列表
 *****************************************************************************/
#define UTX0MAP_PB3     (1 << 8)        //G1 uart0 tx: PB3
#define UTX0MAP_PA1     (2 << 8)        //G2 uart0 tx: PA1
#define UTX0MAP_PA3     (3 << 8)        //G3 uart0 tx: PA3
#define UTX0MAP_PE3     (4 << 8)        //G4 uart0 tx: PE3
#define UTX0MAP_PE5     (5 << 8)        //G5 uart0 tx: PE5
#define UTX0MAP_PE7     (6 << 8)        //G6 uart0 tx: PE7
#define UTX0MAP_PF5     (7 << 8)        //G7 uart0 tx: PF5
#define URX0MAP_VUSB    (8 << 12)       //G6 uart0 rx: VUSB

#define URX0MAP_PB4     (1 << 12)       //G1 uart0 rx: PB4
#define URX0MAP_PA0     (2 << 12)       //G2 uart0 rx: PA0
#define URX0MAP_PA2     (3 << 12)       //G3 uart0 rx: PA2
#define URX0MAP_PE2     (4 << 12)       //G4 uart0 rx: PE2
#define URX0MAP_PE4     (5 << 12)       //G5 uart0 rx: PE4
#define URX0MAP_PE6     (6 << 12)       //G6 uart0 rx: PE6
#define URX0MAP_TX      (7 << 12)       //uart0 map to TX pin by UT0TXMAP select(1线模式)


/*****************************************************************************
 * Module    : Quadrate Decode Mapping选择列表
 *          FUNCMCON2[19:16], 例如FUNCMCON2 = QDEC_MAP_G1;
 *****************************************************************************/
#define QDEC_MAP_G1     (1 << 16)       //G1 QDEC_A: PB0, QDEC_B: PB1
#define QDEC_MAP_G2     (2 << 16)       //G2 QDEC_A: PE1, QDEC_B: PE2
#define QDEC_MAP_G3     (3 << 16)       //G3 QDEC_A: PE6, QDEC_B: PE7


/*****************************************************************************
 * Module    : 录音文件类型列表
 *****************************************************************************/
#define REC_NO          0
#define REC_WAV         1              //PCM WAV
#define REC_ADPCM       2              //ADPCM WAV
#define REC_MP3         3
#define REC_SBC         4

/*****************************************************************************
* Module    : DAC SELECT
*****************************************************************************/
#define DAC_DIFF_MONO       0           //DAC差分单声道输出
#define DAC_SINGLE_MONO     1           //DAC单端单声道输出

/*****************************************************************************
* Module    : DAC OUT Sample Rate
*****************************************************************************/
#define DAC_OUT_44K1    0               //dac out sample rate 44.1K
#define DAC_OUT_48K     1               //dac out sample rate 48K

/*****************************************************************************
* Module    : DAC LDOH Select
*****************************************************************************/
#define AU_LDOH_2V4     0               //VDDAUD LDO voltage 2.4V
#define AU_LDOH_2V5     1               //VDDAUD LDO voltage 2.5V
#define AU_LDOH_2V7     2               //VDDAUD LDO voltage 2.7V
#define AU_LDOH_2V9     3               //VDDAUD LDO voltage 2.9V
#define AU_LDOH_3V1     4               //VDDAUD LDO voltage 3.1V
#define AU_LDOH_3V2     5               //VDDAUD LDO voltage 3.2V

/*****************************************************************************
* Module    : AUX or MIC Left&Right channel list
* AUX: 可以任意左与右搭配，或只选择左，或只选择右
*****************************************************************************/
#define CH_MIC_PF0          0x0c    //MIC(PF0)   -> left mic  -> sdadc left channel


/*****************************************************************************
* Module    : 电池低电电压列表
*****************************************************************************/
#define VBAT_2V8            0       //2.8v
#define VBAT_2V9            1       //2.9v
#define VBAT_3V0            2       //3.0v
#define VBAT_3V1            3       //3.1v
#define VBAT_3V2            4       //3.2v
#define VBAT_3V3            5       //3.3v
#define VBAT_3V4            6       //3.4v
#define VBAT_3V5            7       //3.5v
#define VBAT_3V6            8       //3.6v
#define VBAT_3V7            9       //3.7v
#define VBAT_3V8            10      //3.8v

/*****************************************************************************
* Module    : uart0 printf IO列表
*****************************************************************************/
#define PRINTF_NONE         0           //关闭UART0打印信息
#define PRINTF_PB3          1
#define PRINTF_PA1          2
#define PRINTF_PA3          3
#define PRINTF_PE3          4
#define PRINTF_PE5          5
#define PRINTF_PE7          6
#define PRINTF_PF5          7

/*****************************************************************************
* Module    : GPIO list
*****************************************************************************/
#define IO_NONE             0
#define IO_PA0              1
#define IO_PA1              2
#define IO_PA2              3
#define IO_PA3              4
#define IO_PA4              5
#define IO_PA5              6
#define IO_PA6              7
#define IO_PA7              8
#define IO_PB0              9
#define IO_PB1              10
#define IO_PB2              11
#define IO_PB3              12
#define IO_PB4              13
#define IO_PB5              14
#define IO_PB6              15
#define IO_PB7              16
#define IO_PE0              17
#define IO_PE1              18
#define IO_PE2              19
#define IO_PE3              20
#define IO_PE4              21
#define IO_PE5              22
#define IO_PE6              23
#define IO_PE7              24
#define IO_PF0              25
#define IO_PF1              26
#define IO_PF2              27
#define IO_PF3              28
#define IO_PF4              29
#define IO_PF5              30
#define IO_MAX_NUM          30

#define IO_MUX_SDCLK        31
#define IO_MUX_SDCMD        32

#define IO_EDGE_FALL        0xfe
#define IO_EDGE_RISE        0xff



/*****************************************************************************
* Module    : APP protocol
*****************************************************************************/
#define USE_NULL_APP                    0
#define USE_AB_APP                      1   //bluefit app

#endif //CONFIG_DEFINE_H
