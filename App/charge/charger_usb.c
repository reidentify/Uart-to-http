#include "charger_usb.h"

#define FALLING_CURRENT_STEP  (5) //�������ֵ�
#define S_FULL_VOLTAGE_CNT_PER  (CFG_CHG_FULL_TIMER/FALLING_CURRENT_STEP)

/* Global usb struct */
idata CHG_T g_chg_s;

static void usb_in_ovp(void)
{
		if(!_ChgBit.in)   //δ���룬������ѹ
    {
        return;
    }
		
    if(plib_chg_get_status(CHG_S_USBOVP))   //USB OVP
    {
        _ChgBit.ovp = 1;
    }
    else
    {
        _ChgBit.ovp = 0;
    }
}

/**
 * @brief Detect usb access
 */
static void usb_in_det(void)
{
    if(plib_chg_get_status(CHG_S_USB_IN))   //USB ����
    {
        _ChgBit.in = 1;
    }
    else
    {
        _ChgBit.in = 0;
    }
}

/**
 * @brief Detect usb chg full
 */
static void usb_full_det(void)
{
    if(!_ChgBit.in)   //δ���룬�������
    {
        return;
    }

    if(!plib_chg_ifen())    //����ֹ���������
    {
        return;
    }

    if(plib_chg_get_status(CHG_S_FULL))
    {
        _ChgBit.hw_full = 1;
    }
    else
    {
        _ChgBit.hw_full = 0;
    }
}

/**
 * @brief USB charging control function.
 *        Controls the charging process based on the current USB state.
 */
void usb_charger_process(void)
{
    static u16 s_full_voltage_cnt;
    static u16 s_sub_curr_voltage_cnt;
    s8  falling_step, charg_iset, iset_max;
    //USB�����������
    usb_in_det();
    usb_full_det();
	
		//USB��ѹ���
		usb_in_ovp();

    switch (g_chg_s.chg_state)
    {
    case USB_STATE_USB_IDLE:
        if(_ChgBit.in)
        {
            _ChgBit.hw_full = 0;
            _ChgBit.sf_full = 0;

            plib_chg_en(PLIB_DISABLE);

            //�����У�����ת�����״̬
            if(SYSTEM_FIRE_RUNNING == g_sys.status_sys)
            {
                break;
            }

            //USB����������
#if CFG_SYS_UNLOCK_MODE==1
            util_queue_push(EVENT_LOCK_SYS);
#endif
						
						batlow_unlock();
						
						if(_ChgBit.ovp)
						{
							util_queue_push(EVENT_USB_OVP);
							g_chg_s.chg_state = USB_STATE_USB_OVP;
						}

            //���������USB��/Ƿѹ���룬�ȼ�⵽USB���룬���⵽USB ��/Ƿѹ������
            if(++g_chg_s.in_cnt >= USB_IN_CNT_MAX)
            {
                g_chg_s.in_cnt = 0;

#if CFG_CHG_SUB_CUR_EN
                plib_chg_set_cc_current(CFG_CHG_ISET);
#endif

//              //����Ҫ�󣺵�ص�ѹ����4.05Vʱ������USB�ſ������
//                if(g_battery.volt.idle >= CFG_CHG_RECHG_VBAT_THD)
//                {
//                  AM_DBG_PRINTF("Bat>4050\r\n");
//                  //util_queue_push(EVENT_USB_FULL);
//                  //g_chg_s.chg_state = USB_STATE_USB_FULL;
//                    //�رճ�磬�ȴ��´ν���USB���¿���
//                    plib_chg_en(PLIB_DISABLE);
//                  break;
//                }

                util_queue_push(EVENT_USB_INPUT);
                g_chg_s.chg_state = USB_STATE_USB_CHRGING;
                plib_chg_en(PLIB_ENABLE);
            }
        }

        break;

    case USB_STATE_USB_CHRGING:
        if(_ChgBit.in)
        {
						if(_ChgBit.ovp)
						{
							util_queue_push(EVENT_USB_OVP);
							g_chg_s.chg_state = USB_STATE_USB_OVP;
						}
						
            if(_ChgBit.hw_full) //Ӳ������
            {
							s_full_voltage_cnt = 0;
							util_queue_push(EVENT_USB_FULL);
							g_chg_s.chg_state = USB_STATE_USB_FULL; 
            }

#if CFG_CHG_SUB_CUR_EN

            if(g_battery.volt.idle >= CFG_CHG_SUB_CUR_VBAT_THD)
            {
                if(++s_sub_curr_voltage_cnt >= CFG_CHG_SUB_CUR_TIMER)
                {
                    s_sub_curr_voltage_cnt = 0;
                    plib_chg_set_cc_current(CFG_CHG_SUB_CUR_ISET);
                }
            }

#endif

#if CFG_CHG_FULL_BY_SOFT_EN

            if(g_battery.volt.idle >= CFG_CHG_FULL_VBAT_THD)
            {
                s_full_voltage_cnt++;

                //AM_DBG_PRINTF("full cnt:%d\r\n", (u16)s_full_voltage_cnt);
                if(s_full_voltage_cnt >= CFG_CHG_FULL_TIMER)
                {
                    _ChgBit.sf_full = 1;

										s_full_voltage_cnt = 0;
										util_queue_push(EVENT_USB_FULL);
										g_chg_s.chg_state = USB_STATE_USB_FULL;

										plib_chg_en(PLIB_DISABLE);
                  
                    //����Ҫ������󣬳����ƣ�����ж����䣬�رճ�磬�ȴ��´ν���USB���¿���

                }

                falling_step = s_full_voltage_cnt / S_FULL_VOLTAGE_CNT_PER;

                if( 0 == (s_full_voltage_cnt % S_FULL_VOLTAGE_CNT_PER) )
                {
                    iset_max = (CFG_CHG_ISET > CHG_ISET_500MA) ? CHG_ISET_500MA : CFG_CHG_ISET;
                    charg_iset = iset_max - falling_step;

                    if( charg_iset < 0)
                    {
                        charg_iset = 0;
                    }

                    plib_chg_set_cc_current(charg_iset);
                }

            }

#endif
        }
        else
        {
            g_chg_s.chg_state = USB_STATE_USB_IDLE;
            util_queue_push(EVENT_USB_REMOVE);
        }

        break;

    case USB_STATE_USB_FULL:
        if(_ChgBit.in)
        {
#if CFG_CHG_FULL_BY_SOFT_EN

            //������Ƴ��ʱ������󣬵�ѹ���������ѹʱ��������磬������ʾ����
            if(g_battery.volt.idle < CFG_CHG_RECHG_VBAT_THD)
            {
                util_queue_push(EVENT_USB_CHRGING);        //����Ч
                g_chg_s.chg_state = USB_STATE_USB_RECHG;      //���븴��
                plib_chg_set_cc_current(CHG_ISET_500MA);
                plib_chg_en(PLIB_ENABLE);
//              util_queue_push(EVENT_USB_CHRGING);
//              g_chg_s.chg_state = USB_STATE_USB_CHRGING;
            }
            else if(g_battery.volt.idle >= CFG_CHG_RECHG_VBAT_THD)
            {
                //util_queue_push(EVENT_USB_FULL);
                //g_chg_s.chg_state = USB_STATE_USB_FULL;
                //����Ҫ������󣬳����ƣ�����ж����䣬�رճ�磬�ȴ��´ν���USB���¿���
                plib_chg_en(PLIB_DISABLE);
            }

#endif
        }
        else
        {
            g_chg_s.chg_state = USB_STATE_USB_IDLE;
            util_queue_push(EVENT_USB_REMOVE);
        }

        break;

    case USB_STATE_USB_RECHG:
        if(_ChgBit.in)
        {
#if CFG_CHG_FULL_BY_SOFT_EN

            if(g_battery.volt.idle >= CFG_CHG_FULL_VBAT_THD)
            {
                s_full_voltage_cnt++;

                //AM_DBG_PRINTF("re full cnt:%d\r\n", (u16)s_full_voltage_cnt);
                if(s_full_voltage_cnt >= CFG_CHG_FULL_TIMER)
                {
                    s_full_voltage_cnt = 0;
                    util_queue_push(EVENT_USB_FULL);
                    g_chg_s.chg_state = USB_STATE_USB_FULL;

                    //����Ҫ������󣬹رճ��
                    plib_chg_en(PLIB_DISABLE);
                }
            }

#endif

            if(_ChgBit.hw_full)
            {
                s_full_voltage_cnt = 0;
                util_queue_push(EVENT_USB_FULL);
                g_chg_s.chg_state = USB_STATE_USB_FULL;
            }
        }
        else
        {
            g_chg_s.chg_state = USB_STATE_USB_IDLE;
            util_queue_push(EVENT_USB_REMOVE);
        }

        break;
				
    case USB_STATE_USB_OVP:
        if(_ChgBit.in)
        {
						if(_ChgBit.ovp == 0)
						{
							if(g_battery.volt.idle >= CFG_CHG_FULL_VBAT_THD)
							{
									util_queue_push(EVENT_USB_FULL);
									g_chg_s.chg_state = USB_STATE_USB_FULL;
								
									plib_chg_en(PLIB_DISABLE);
							}
							else
							{
									if(++g_chg_s.ovp_cnt >= USB_OVP_CNT_MAX)
									{
										g_chg_s.ovp_cnt = 0;
										util_queue_push(EVENT_USB_CHRGING);
										g_chg_s.chg_state = USB_STATE_USB_CHRGING;
										plib_chg_set_cc_current(CHG_ISET_500MA);
										plib_chg_en(PLIB_ENABLE);
									}
									
							}
						}
        }
        else
        {
						_ChgBit.ovp = 0;
						g_chg_s.ovp_cnt = 0;
            g_chg_s.chg_state = USB_STATE_USB_IDLE;
            util_queue_push(EVENT_USB_REMOVE);
        }

        break;

    default:
        g_chg_s.chg_state = USB_STATE_USB_IDLE;
        break;
    }
}
