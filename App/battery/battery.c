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
		g_userdata_t.show_level = g_userdata_t.real_level;	//获取上电的默认档位	
}

/*
 * Correct the bat level
 */
u8 get_battery_level()
{
		//充电时，减去充电抬升的电压
    if(USB_IS_IN_CHARGING)
    {
        g_battery.volt.idle -= CFG_BAT_DIFF_CHG;
    }
    else    //不充电或放电时，加上放电拉低的偏差
    {
        //g_battery.idle_volt += CFG_BAT_DIFF_DISCHG;
    }	
		
		//获取当前电压对应的档位
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
		
		//根据充放电状态，获取真实的档位
		if(USB_IS_IN_CHARGING)	    //充电状态
		{
			//仅在充电时，允许电量上升
			if(g_userdata_t.real_level > g_userdata_t.show_level)
			{
				g_userdata_t.show_level = g_userdata_t.real_level;	
				
				//电量档位变化时，更新充电显示灯效
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
