#ifndef __CONFIG_EXTRA_H__
#define __CONFIG_EXTRA_H__

/*****************************************************************************
 * Module    : 系统功能配置
 *****************************************************************************/

#ifndef SYS_MODE_BREAKPOINT_EN
#define SYS_MODE_BREAKPOINT_EN      0
#endif


#ifndef SPIFLASH_SPEED_UP_EN
#define SPIFLASH_SPEED_UP_EN         1
#endif


#ifndef WARNING_WAVRES_PLAY
#define WARNING_WAVRES_PLAY              0
#endif

#ifndef MIC_EQ_EN
#define MIC_EQ_EN                        0
#endif


#if (GUI_SELECT == GUI_TFT_320_ST77916)
    #define GUI_SCREEN_WIDTH                320
    #define GUI_SCREEN_HEIGHT               385
    #define GUI_SCREEN_OFS_X                0
    #define GUI_SCREEN_OFS_Y                0
#elif (GUI_SELECT == GUI_TFT_360_GC9C01)
    #define GUI_SCREEN_WIDTH                360
    #define GUI_SCREEN_HEIGHT               360
    #define GUI_SCREEN_OFS_X                0
    #define GUI_SCREEN_OFS_Y                0
#elif (GUI_SELECT == GUI_OLED_466_ICNA3310B)
    #define GUI_SCREEN_WIDTH                466
    #define GUI_SCREEN_HEIGHT               466
    #define GUI_SCREEN_OFS_X                6
    #define GUI_SCREEN_OFS_Y                0
#elif (GUI_SELECT == GUI_TFT_JD9853)
    #define GUI_SCREEN_WIDTH                240
    #define GUI_SCREEN_HEIGHT               296
    #define GUI_SCREEN_OFS_X                0
    #define GUI_SCREEN_OFS_Y                0
#elif (GUI_SELECT == GUI_TFT_240_ST7789)
    #define GUI_SCREEN_WIDTH                240
    #define GUI_SCREEN_HEIGHT               296
    #define GUI_SCREEN_OFS_X                0
    #define GUI_SCREEN_OFS_Y                0
#else
    #define GUI_SCREEN_WIDTH                0
    #define GUI_SCREEN_HEIGHT               0
#endif

#define GUI_SCREEN_CENTER_X                 (GUI_SCREEN_WIDTH / 2)
#define GUI_SCREEN_CENTER_Y                 (GUI_SCREEN_HEIGHT / 2)

#if (TP_SELECT == TP_CST8X)
    #define TP_IIC_ADDR                     0x15
    #define TP_IIC_UPDATE_ADDR              0x6A
#elif (TP_SELECT == TP_CHSC6X)
    #define TP_IIC_ADDR                     0x2E

#endif

/*****************************************************************************
 * Module    : 音乐功能配置
 *****************************************************************************/
#if !CHARGE_EN
#undef  CHARGE_TRICK_EN
#undef  CHARGE_DC_IN
#undef  CHARGE_DC_NOT_PWRON
#define CHARGE_TRICK_EN             0
#define CHARGE_DC_NOT_PWRON         0
#define CHARGE_DC_IN()              0
#endif

#ifndef PWROFF_PRESS_TIME
#define PWROFF_PRESS_TIME           3               //1:大约1秒    3: 1.5s,  6: 2s,  9: 2.5s, 12: 3s
#endif // PWROFF_PRESS_TIME

#ifndef PWRON_PRESS_TIME
#define PWRON_PRESS_TIME            1500           //1.5s
#endif // PWRON_PRESS_TIME

#ifndef USER_MULTI_KEY_TIME
#define USER_MULTI_KEY_TIME             1
#endif // USER_MULTI_KEY_TIME

#ifndef SYS_LIMIT_VOLUME
#define SYS_LIMIT_VOLUME            SYS_INIT_VOLUME
#endif // SYS_LIMIT_VOLUME

#ifndef LINEIN_2_PWRDOWN_TONE_EN
#define LINEIN_2_PWRDOWN_TONE_EN    0   //插入Linein直接关机，是否播放关机提示音。
#endif // LINEIN_2_PWRDOWN_TONE_EN

#ifndef LPWR_WARING_TIMES
#define LPWR_WARING_TIMES           0xff
#endif // LPWR_WARING_TIMES

#if !BUZZER_EN
#undef BUZZER_INIT
#define BUZZER_INIT()
#undef BUZZER_ON
#define BUZZER_ON()
#undef BUZZER_OFF
#define BUZZER_OFF()
#endif

#ifndef PWRON_FRIST_BAT_EN
#define PWRON_FRIST_BAT_EN          1
#endif // PWRON_FRIST_BAT_EN

#if !LOUDSPEAKER_MUTE_EN
#undef LOUDSPEAKER_MUTE_INIT
#define LOUDSPEAKER_MUTE_INIT()
#undef LOUDSPEAKER_MUTE_DIS
#define LOUDSPEAKER_MUTE_DIS()
#undef LOUDSPEAKER_MUTE
#define LOUDSPEAKER_MUTE()
#undef LOUDSPEAKER_UNMUTE
#define LOUDSPEAKER_UNMUTE()
#undef LOUDSPEAKER_UNMUTE_DELAY
#define LOUDSPEAKER_UNMUTE_DELAY        0
#undef LOUDSPEAKER_MUTE_PORT
#define LOUDSPEAKER_MUTE_PORT           IO_NONE
#endif

#if !AMP_CTRL_AB_D_EN
#undef  AMP_CTRL_AB_D_PORT
#undef  AMP_CTRL_AB_D_TYPE
#undef  AMPLIFIER_SEL_INIT
#undef  AMPLIFIER_SEL_D
#undef  AMPLIFIER_SEL_AB

#define AMP_CTRL_AB_D_PORT              IO_NONE
#define AMP_CTRL_AB_D_TYPE              0
#define AMPLIFIER_SEL_INIT()
#define AMPLIFIER_SEL_D()
#define AMPLIFIER_SEL_AB()
#endif

#if !VBAT_DETECT_EN
#undef LPWR_WARNING_VBAT
#undef LPWR_OFF_VBAT
#define LPWR_WARNING_VBAT               0
#define LPWR_OFF_VBAT                   0
#endif

/*****************************************************************************
 * Module    : 蓝牙相关配置
 *****************************************************************************/
#ifndef BT_A2DP_RECON_EN
#define BT_A2DP_RECON_EN            0
#endif

#ifndef BT_BACKSTAGE_EN
#define BT_BACKSTAGE_EN             1   //蓝牙后台管理
#endif

#ifndef BT_BACKSTAGE_MUSIC_EN
#define BT_BACKSTAGE_MUSIC_EN       1   //蓝牙音乐支持后台播放
#endif


#if !LE_EN
    #undef LE_PAIR_EN
    #undef LE_SM_SC_EN
    #undef LE_AB_LINK_APP_EN
    #undef LE_BQB_RF_EN
    #define LE_PAIR_EN              0
    #define LE_SM_SC_EN             0
    #define LE_AB_LINK_APP_EN       0
    #define LE_BQB_RF_EN            0
#endif

#if LE_BQB_RF_EN
    #undef BT_FCC_TEST_EN
    #undef USER_KEY_QDEC_EN
    #define BT_FCC_TEST_EN          1   //LE_BQB和FCC共用huart_init
    #define USER_KEY_QDEC_EN        0
#endif

#if LE_EN
    #define BT_DUAL_MODE_EN         1
#else
    #define BT_DUAL_MODE_EN         0
#endif

#ifndef BT_PAIR_SLEEP_EN
#define BT_PAIR_SLEEP_EN            1
#endif // BT_PAIR_SLEEP_EN

#ifndef BT_HFP_RINGS_BEFORE_NUMBER
#define BT_HFP_RINGS_BEFORE_NUMBER   0
#endif


#if BT_FCC_TEST_EN    //FCC 默认PB3 (USB_DP) 波特率1500000通信, 关闭用到PB3的程序
#if (UART0_PRINTF_SEL == PRINTF_PB3)
#undef UART0_PRINTF_SEL
#define UART0_PRINTF_SEL  PRINTF_NONE
#endif
#endif

#if LE_AB_FOT_EN || LE_DUEROS_FOT_EN
#define LE_FOT_EN                   1
#endif

#if BT_FOT_EN || LE_FOT_EN
#undef FOT_EN
#define FOT_EN                      1   //是否打开FOTA升级功能
#endif

#if BT_FCC_TEST_EN
    #define WORK_MODE           MODE_FCC_TEST
#elif BT_BQB_RF_EN
    #define WORK_MODE           MODE_BQB_RF
#elif BT_BQB_PROFILE_EN
    #define WORK_MODE           MODE_BQB_PROFILE
#elif BT_CBT_TEST_EN
    #define WORK_MODE           MODE_CBT_TEST
#else
    #define WORK_MODE           MODE_NORMAL
#endif

#if !BT_HID_EN
#undef BT_HID_TYPE
#undef BT_HID_MENU_EN
#undef BT_HID_DISCON_DEFAULT_EN
#define BT_HID_TYPE                 0
#define BT_HID_MENU_EN              0
#define BT_HID_DISCON_DEFAULT_EN    0
#endif


/*****************************************************************************
 * Module    : uart0 printf 功能自动配置(自动关闭SD卡，USB)
 *****************************************************************************/
#if (UART0_PRINTF_SEL == PRINTF_NONE)
    //关闭所以打印信息
    #undef printf
    #undef vprintf
    #undef print_r
    #undef print_r16
    #undef print_r32
    #undef printk
    #undef vprintk
    #undef print_kr
    #undef print_kr16
    #undef print_kr32

    #define printf(...)
    #define vprintf(...)
    #define print_r(...)
    #define print_r16(...)
    #define print_r32(...)
    #define printk(...)
    #define vprintk(...)
    #define print_kr(...)
    #define print_kr16(...)
    #define print_kr32(...)
#endif


/*****************************************************************************
 * Module    : 提示音配置
 *****************************************************************************/
#if (!WARNING_TONE_EN)
#undef WARNING_POWER_ON
#undef WARNING_POWER_OFF
#undef WARNING_BT_INCALL
#undef BT_HFP_INBAND_RING_EN

#define WARNING_POWER_ON               0
#define WARNING_POWER_OFF              0
#define WARNING_BT_INCALL              0
#define BT_HFP_INBAND_RING_EN          0

#endif

#ifndef UPD_FILENAME
#define UPD_FILENAME                   "fw5000.upd"
#endif

/*****************************************************************************
* Module    : 有冲突或功能上不能同时打开的宏
*****************************************************************************/


/*****************************************************************************
* Module    : 计算FunctionKey
*****************************************************************************/

/*****************************************************************************
* Module    : 传感器选择
*****************************************************************************/
#define SENSOR_STEP_NULL                         0
#define SENSOR_STEP_EN                           0x100
#define SENSOR_STEP_SC7A20                       (SENSOR_STEP_EN | 0x0)
#define SENSOR_STEP_MSA310                       (SENSOR_STEP_EN | 0x1)

#define SENSOR_HR_NULL                           0
#define SENSOR_HR_EN                             0x200
#define SENSOR_HR_TYHX_HRS3300                   (SENSOR_HR_EN | 0x0)			            //天易合芯HRS3300心率血压传感器
#define SENSOR_HR_TYHX_HX3605                    (SENSOR_HR_EN | 0x1)			            //天易合芯HX3605心率血氧传感器

#define SENSOR_GEO_NULL                           0
#define SENSOR_GEO_EN                             0x300

#endif // __CONFIG_EXTRA_H__

