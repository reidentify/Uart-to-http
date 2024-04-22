#include "battery.h"

/* Global battery parameters */
idata struct battery_state g_battery;

void batlow_lock(void)
{
		if(g_battery.low_cnt < BAT_LOW_CNT)
		{
				if(++g_battery.low_cnt == BAT_LOW_CNT)
				{
					g_sys.lock_child = 1;
				}
		}
}

void batlow_unlock(void)
{
		if(g_battery.low_cnt == BAT_LOW_CNT)
		{
			g_battery.low_cnt = 0;
			g_sys.lock_child = 0;
		}
}

/*
 * Perform voltage sampling in a loop.
 */
void battery_get_volt(void)
{
    g_battery.advalue = pmcu_adc_sample_1ch_mul(ADC_CHN1_VBAT, 4);
    g_battery.volt.now = plib_adc_get_volt_div2(g_battery.advalue);
    g_battery.volt.idle = g_battery.volt.now;
}

/*
 * Get the BAT init value
 */
void battery_get_volt_init(void)
{
    battery_get_volt();
    get_battery_level();
		g_userdata_t.show_level = g_userdata_t.real_level;	//��ȡ�ϵ��Ĭ�ϵ�λ	
}

/*
 * Correct the bat level
 */
u8 get_battery_level()
{
		//���ʱ����ȥ���̧���ĵ�ѹ
    if(USB_IS_IN_CHARGING)
    {
        g_battery.volt.idle -= CFG_BAT_DIFF_CHG;
    }
    else    //������ŵ�ʱ�����Ϸŵ����͵�ƫ��
    {
        //g_battery.idle_volt += CFG_BAT_DIFF_DISCHG;
    }	
		
		//��ȡ��ǰ��ѹ��Ӧ�ĵ�λ
		if(g_battery.volt.idle >= CFG_BAT_LEVEL2_VOLT)
		{
			g_userdata_t.real_level = BAT_LEVEL_3;
		}
		else if(g_battery.volt.idle >= CFG_BAT_LEVEL1_VOLT)
		{
			g_userdata_t.real_level = BAT_LEVEL_2;
		}
		else
		{
			g_userdata_t.real_level = BAT_LEVEL_1;
		}
		
		//���ݳ�ŵ�״̬����ȡ��ʵ�ĵ�λ
		if(USB_IS_IN_CHARGING)	    //���״̬
		{
			//���ڳ��ʱ�������������
			if(g_userdata_t.real_level > g_userdata_t.show_level)
			{
				g_userdata_t.show_level = g_userdata_t.real_level;	
				
				//������λ�仯ʱ�����³����ʾ��Ч
				//util_queue_push(EVENT_USB_CHRGING);
			}
		}
		else
		{
			if(g_userdata_t.real_level < g_userdata_t.show_level)
			{
				g_userdata_t.show_level = g_userdata_t.real_level;	
			}
		}
	
		return g_userdata_t.show_level;
}
