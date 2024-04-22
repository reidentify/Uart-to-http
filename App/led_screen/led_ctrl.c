#include "led_ctrl.h"

xdata struct led_ctrl g_led_s;

void led_turn_flash()
{
		led_all_on(g_led_s.led_mask);
		
		if(g_led_s.run < g_led_s.onoff) 
    {
        g_led_s.run++;
    }
    else    
    {
        g_led_s.run = 0;
			
				g_led_s.led_mask <<= 1;
				
        if(g_led_s.cnt > 0)
        {
            g_led_s.cnt--;

            if(g_led_s.cnt == 0)
            {
               g_led_s.mode = LED_MODE_OFF;
            }
        }
    }
}

/**
 * @brief Process LED periods for flashing LED.
 * @param index The index of the LED.
 * @param num The number of the LED.
 */
void led_period_process(void)
{
    if(g_led_s.run < g_led_s.onoff) //LED����ʾ��ʱ����С������ʱ������������
    {
        g_led_s.run++;
    }
    else    //��ǰLED��ʾʱ���Ѵﵽ����ֵ
    {
        g_led_s.run = 0;

        if(g_led_s.cnt > 0)
        {
            g_led_s.cnt--;

            if(g_led_s.cnt == 0)    //���������
            {
								if(g_led_show_type == LED_SHOW_TYPE_USB_IN_FIRST)
								{
										g_led_s.mode = LED_MODE_ON;
								}
                else if(g_led_s.mode == LED_MODE_BREATH) //����ʱ��g_led_s.cnt����0���Գ�������
                {
                    g_led_s.cnt = 2;
                }
                else
                {
                    g_led_s.mode = LED_MODE_OFF;
                }
            }
        }
    }
}

/**
 * @brief Set LED status and control parameters for a specific group of LEDs.
 */
void led_set_ctrl_info(LED_MODE_E mode, u8 Period_Onff, u8 Loop_Times, u8 ch_Mark)
{
    u16 xdata run_new;

    //��ǰΪ��˸��Ч�����ϴε�Чδ�������������ڳ���������˸����+1.��ΪҪ��������
    if(mode == LED_MODE_FLASH && g_led_s.mode != LED_MODE_OFF && g_led_s.mode != LED_MODE_UNDEFINE)
    {
        g_led_s.cnt = Loop_Times * 2 + 1;
    }
    else
    {
        g_led_s.cnt = Loop_Times * 2;
    }

    run_new = (u32)(g_led_s.run * Period_Onff) / g_led_s.onoff;
    g_led_s.mode = mode;            //��ǰ��Чģʽ
    g_led_s.onoff = Period_Onff;    //��������ʱ��
    g_led_s.led_mask = ch_Mark;     //��ЩLED����

    //��ǰ����������ģʽ���ҽ�������ЧΪ���������������𡢺����������򣩵�Ч��ʱ����ӵ�ǰ��Ч��ʼ��ʾ
    if(g_led_s.run &&
            (g_led_s.mode == LED_MODE_BREATH ||
             g_led_s.mode == LED_MODE_BREATH_OFF))
    {
        g_led_s.run = g_led_s.onoff - run_new;
    }
    else
    {
        g_led_s.run = 0;
    }
		
		if(g_led_s.mode == LED_MODE_TURN_FLASH)
		{
				g_led_s.cnt/=2;
		}
		
		if((g_led_show_type == LED_SHOW_TYPE_RL_SHORT) || (g_led_show_type == LED_SHOW_TYPE_RL_LOW))
		{
				g_led_s.cnt/=2;
		}
}

/**
 * @brief Set LED bright.
 */
void led_set_bright(u8 color_msk, u8 duty)
{
    u8 xdata chn0_duty, chn1_duty, chn2_duty, chn3_duty, chn4_duty, chn5_duty;

    chn0_duty = (color_msk & LED0_MASK) ? duty : 0;
    chn1_duty = (color_msk & LED1_MASK) ? duty : 0;
    chn2_duty = (color_msk & LED2_MASK) ? duty : 0;
    chn3_duty = (color_msk & LED3_MASK) ? duty : 0;
    chn4_duty = (color_msk & LED4_MASK) ? duty : 0;
    chn5_duty = (color_msk & LED5_MASK) ? duty : 0;
    plib_pwm_set_chn_duty(PWM_SEL0, chn0_duty, chn1_duty, chn2_duty);
    plib_pwm_set_chn_duty(PWM_SEL1, chn3_duty, chn4_duty, chn5_duty);
}

/**
 * @brief Process the LED status every 10 milliseconds.
 */
void led_ctrl_handler(void)
{
    u8 xdata tmp;

    switch (g_led_s.mode)
    {
    case LED_MODE_UNDEFINE:
        break;

    case LED_MODE_OFF:
        if(USB_IS_IN_CHARGING)
        {
            util_queue_push(EVENT_USB_CHRGING);
        }
        else
        {
            g_led_show_type = LED_SHOW_TYPE_OFF;
            led_all_off(g_led_s.led_mask);
            g_led_s.is_on = 0;
        }

        break;

    case LED_MODE_ON:
        led_all_on(g_led_s.led_mask);
		
				if((g_led_show_type == LED_SHOW_TYPE_RL_SHORT) || (g_led_show_type == LED_SHOW_TYPE_RL_LOW))
				{
					 led_period_process();
				}
				
        g_led_s.is_on = 1;
        break;

    case LED_MODE_FLASH:
        if(g_led_s.cnt & 1)
        {
            led_all_off(g_led_s.led_mask);
            g_led_s.is_on = 0;
        }
        else
        {
            led_all_on(g_led_s.led_mask);
            g_led_s.is_on = 1;
        }

        led_period_process();
        break;

    case LED_MODE_BREATH:
        if(g_led_s.cnt & 1)
        {
            tmp = led_cal_duty_breath_dn();
            g_led_s.is_on = 0;
        }
        else
        {
            tmp = led_cal_duty_breath_up();
            g_led_s.is_on = 1;
        }

        led_set_bright(g_led_s.led_mask, tmp);
        led_period_process();
        break;

    case LED_MODE_BREATH_ON:
        if(g_led_s.run < g_led_s.onoff)
        {
            g_led_s.run++;
            tmp = led_cal_duty_breath_up();
            led_set_bright(g_led_s.led_mask, tmp);
        }

        g_led_s.is_on = 1;
        break;

    case LED_MODE_BREATH_OFF:
        if(g_led_s.run < g_led_s.onoff)
        {
            g_led_s.run++;
            tmp = led_cal_duty_breath_dn();
            led_set_bright(g_led_s.led_mask, tmp);
        }
        else
        {
            g_led_s.mode = LED_MODE_OFF;
        }

        g_led_s.is_on = 0;
        break;
				
    case LED_MODE_TURN_FLASH:
				led_turn_flash();
        break;

    default:
        break;
    }
}
