#include "pmu.h"

/**
 * @brief Enters sleep mode.
 */
void pm_sleep_enter(void)
{
    plib_sys_it_en(PLIB_DISABLE);
    plib_chg_en(PLIB_DISABLE);
    plib_motor_en(PLIB_DISABLE);
    /********************����MIC***************************/
#if CFG_MIC_TYPE == 2
    plib_gpio_init(CFG_PIN_MIC_PORT, CFG_PIN_MIC_PINNUM, GPIO_PinMux_IO, GPIO_IOMode_IN_FLOATING, GPIO_PUPDMode_PD, GPIO_Driver_Weak);
#endif /* end of #if CFG_KEY_EN */

    /********************KEY***************************/
#if CFG_KEY_EN
#if CFG_PIN_KEY_VALUE_TYPE==0
    plib_gpio_init(CFG_PIN_KEY_PORT, CFG_PIN_KEY_PINNUM, GPIO_PinMux_IO, GPIO_IOMode_IN_FLOATING, GPIO_PUPDMode_PU, GPIO_Driver_Weak);
#elif   CFG_PIN_KEY_VALUE_TYPE==1
    plib_gpio_init(CFG_PIN_KEY_PORT, CFG_PIN_KEY_PINNUM, GPIO_PinMux_IO, GPIO_IOMode_IN_FLOATING, GPIO_PUPDMode_PD, GPIO_Driver_Weak);
#endif
#endif /* end of CFG_PIN_KEY_VALUE_TYPE==0 */

    /********************LED***************************/
#if CFG_UI_LED_EN

    plib_gpio_led_output_en(GPIO_LED_All, PLIB_DISABLE);

#if CFG_UI_LED0_EN
    plib_gpio_init(CFG_PIN_LED0_PORT, CFG_PIN_LED0_PINNUM, GPIO_PinMux_IO, GPIO_IOMode_IN_FLOATING, GPIO_PUPDMode_PU, GPIO_Driver_Weak);
#endif /* end of #if CFG_UI_LED0_EN */

#if CFG_UI_LED1_EN
    plib_gpio_init(CFG_PIN_LED1_PORT, CFG_PIN_LED1_PINNUM, GPIO_PinMux_IO, GPIO_IOMode_IN_FLOATING, GPIO_PUPDMode_PU, GPIO_Driver_Weak);
#endif /* end of #if CFG_UI_LED1_EN */

#if CFG_UI_LED2_EN
    plib_gpio_init(CFG_PIN_LED2_PORT, CFG_PIN_LED2_PINNUM, GPIO_PinMux_IO, GPIO_IOMode_IN_FLOATING, GPIO_PUPDMode_PU, GPIO_Driver_Weak);
#endif /* end of #if CFG_UI_LED2_EN */

#if CFG_UI_LED3_EN
    plib_gpio_init(CFG_PIN_LED3_PORT, CFG_PIN_LED3_PINNUM, GPIO_PinMux_IO, GPIO_IOMode_IN_FLOATING, GPIO_PUPDMode_PU, GPIO_Driver_Weak);
#endif /* end of #if CFG_UI_LED3_EN */

#if CFG_UI_LED4_EN
    plib_gpio_init(CFG_PIN_LED4_PORT, CFG_PIN_LED4_PINNUM, GPIO_PinMux_IO, GPIO_IOMode_IN_FLOATING, GPIO_PUPDMode_PU, GPIO_Driver_Weak);
#endif /* end of #if CFG_UI_LED4_EN */

#if CFG_UI_LED5_EN
    plib_gpio_init(CFG_PIN_LED5_PORT, CFG_PIN_LED5_PINNUM, GPIO_PinMux_IO, GPIO_IOMode_IN_FLOATING, GPIO_PUPDMode_PU, GPIO_Driver_Weak);
#endif /* end of #if CFG_UI_LED4_EN */

#endif /* end of #if CFG_UI_LED_EN */

    /********************SCREEN***************************/
#if CFG_UI_SCREEN_EN

#if CFG_UI_COM1_EN
    plib_gpio_init(CFG_PIN_COM1_PORT, CFG_PIN_COM1_PINNUM, GPIO_PinMux_IO, GPIO_IOMode_IN_FLOATING, GPIO_PUPDMode_PD, GPIO_Driver_Weak);
#endif /* end of #if CFG_UI_COM1_EN */
#if CFG_UI_COM2_EN
    plib_gpio_init(CFG_PIN_COM2_PORT, CFG_PIN_COM2_PINNUM, GPIO_PinMux_IO, GPIO_IOMode_IN_FLOATING, GPIO_PUPDMode_PD, GPIO_Driver_Weak);
#endif /* end of #if CFG_UI_COM2_EN */
#if CFG_UI_COM3_EN
    plib_gpio_init(CFG_PIN_COM3_PORT, CFG_PIN_COM3_PINNUM, GPIO_PinMux_IO, GPIO_IOMode_IN_FLOATING, GPIO_PUPDMode_PD, GPIO_Driver_Weak);
#endif /* end of #if CFG_UI_COM3_EN */
#if CFG_UI_COM4_EN
    plib_gpio_init(CFG_PIN_COM4_PORT, CFG_PIN_COM4_PINNUM, GPIO_PinMux_IO, GPIO_IOMode_IN_FLOATING, GPIO_PUPDMode_PD, GPIO_Driver_Weak);
#endif /* end of #if CFG_UI_COM4_EN */
#if CFG_UI_COM5_EN
    plib_gpio_init(CFG_PIN_COM5_PORT, CFG_PIN_COM5_PINNUM, GPIO_PinMux_IO, GPIO_IOMode_IN_FLOATING, GPIO_PUPDMode_PD, GPIO_Driver_Weak);
#endif /* end of #if CFG_UI_COM5_EN */
#if CFG_UI_COM6_EN
    plib_gpio_init(CFG_PIN_COM6_PORT, CFG_PIN_COM6_PINNUM, GPIO_PinMux_IO, GPIO_IOMode_IN_FLOATING, GPIO_PUPDMode_PD, GPIO_Driver_Weak);
#endif /* end of #if CFG_UI_COM6_EN */
#if CFG_UI_COM7_EN
    plib_gpio_init(CFG_PIN_COM7_PORT, CFG_PIN_COM7_PINNUM, GPIO_PinMux_IO, GPIO_IOMode_IN_FLOATING, GPIO_PUPDMode_PD, GPIO_Driver_Weak);
#endif /* end of #if CFG_UI_COM7_EN */
#if CFG_UI_COM8_EN
    plib_gpio_init(CFG_PIN_COM8_PORT, CFG_PIN_COM8_PINNUM, GPIO_PinMux_IO, GPIO_IOMode_IN_FLOATING, GPIO_PUPDMode_PD, GPIO_Driver_Weak);
#endif /* end of #if CFG_UI_COM8_EN */
#if CFG_UI_COM9_EN
    plib_gpio_init(CFG_PIN_COM9_PORT, CFG_PIN_COM9_PINNUM, GPIO_PinMux_IO, GPIO_IOMode_IN_FLOATING, GPIO_PUPDMode_PD, GPIO_Driver_Weak);
#endif /* end of #if CFG_UI_COM9_EN */

#endif /* end of #if CFG_UI_SCREEN_EN */

    /********************�òʵ�***************************/
#if CFG_UI_MAGIC_LED_EN

#if CFG_UI_MAGIC_LED_PWR_EN
    plib_gpio_init(CFG_PIN_MAGIC_LED_PWR_PORT, CFG_PIN_MAGIC_LED_PWR_PINNUM, GPIO_PinMux_IO, GPIO_IOMode_Out_PP, GPIO_PUPDMode_None, GPIO_Driver_Strength);
    plib_gpio_set_value(CFG_PIN_MAGIC_LED_PWR_PORT, CFG_PIN_MAGIC_LED_PWR_PINNUM, PLIB_HIGH);
#endif /* end of #if CFG_UI_MAGIC_LED_PWR_EN */

#endif /* end of #if CFG_UI_MAGIC_LED_EN */

    // GPIOC0/C1
    plib_gpio_init(GPIO_GroupC, GPIO_Pin_0, GPIO_PinMux_IO, GPIO_IOMode_IN_FLOATING, GPIO_PUPDMode_None, GPIO_Driver_Weak);
    plib_gpio_init(GPIO_GroupC, GPIO_Pin_1, GPIO_PinMux_IO, GPIO_IOMode_IN_FLOATING, GPIO_PUPDMode_None, GPIO_Driver_Weak);

    /* Wakeup source configuration */
    pmcu_wakeup_init();

    /* Enter sleep */
    plib_wk_sleep();
}

/**
 * @brief Exits sleep mode.
 */
void pm_sleep_exit(void)
{
    bsy_sys_init(); // System peripheral initialization
}

/**
 * @brief Scans whether to allow sleep.
 * @param timesleep The time interval for scanning.
 */
void pm_sleep_process(u16 timesleep)
{
    /* Scan every timesleep ms whether to allow sleep */
    if (util_time_passing(g_sys.time.timesleep) >= timesleep)
    {
        //�������»�MIC���£�δ�ͷţ���ֹ����˯��
        if(g_mic_fire_en || g_key_fire_en)
        {
            goto INIT_SLEEP;
        }

        //��ͷ���̳�ʱ�󣬵��³�ֵ���£������̶���δ�ͷţ�����������
        if(g_rev_mic.hardware_ot || g_rev_mic.blow || g_rev_mic.blow_ot)
        {
            goto INIT_SLEEP;
        }

        //��⵽USB���룬��ֹ����˯��
        if(_ChgBit.in)
        {
            goto INIT_SLEEP;
        }

        //LED״̬����ʱ���������˯��
        if (g_led_show_type == LED_SHOW_TYPE_OFF || g_led_show_type == LED_SHOW_TYPE_NONE)
        {
            AM_DBG_PRINTF("Sleep\r\n");
            pm_sleep_enter();
            pm_sleep_exit();
            AM_DBG_PRINTF("Wakeup\r\n");
        }

INIT_SLEEP:
        util_timepass_init(g_sys.time.timesleep);
    }
}
