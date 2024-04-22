#include "key_mic.h"

//连续按键时，如果只允许按下事件响应一次，此宏设置为1，
#define MULTI_KEY_ONLY_HANDLE_FIRST_PRESS_DOWN  1

/* Global key status */
struct piple_state g_mic_piple;
idata struct key_det_s g_mic_s, g_key_s;

#define MIC_SENSITIVITY_PERCENT   (1)   //灵敏度百分比
#define REV_MIC_RELEASE_FILTER    (3)
REV_MIC_STATUS_T g_rev_mic;         //反向mic状态

bit g_mic_fire_en;  //MIC触发
bit g_key_fire_en;  //按键触发
bit g_key_power_on;  //用于保存上电时，按键状态，以确保按着按键上电，不会触发吸烟
xdata u8 g_prefire_on;

/**
* @brief  判断反向咪是否处于释放状态
* @retval None
* @par   Explanation
*/
static u8 rev_mic_is_release(void)
{
    u16 init, cur;
    u8 ret;
    static u8 cnt;

    init = plib_mic_get_init_value();
    cur = plib_mic_get_cur_value();

    if(cur < init)
    {
        if( (init - cur) > ((u32)init / 100 * MIC_SENSITIVITY_PERCENT) )
        {
            if(++cnt == REV_MIC_RELEASE_FILTER)
            {
                ret = 1;
                cnt = 0;
            }
        }
    }
    else
    {
        cnt = 0;
    }

    return ret;
}

/**
* @brief  咪头检测初始化
* @retval None
* @par   Explanation
*/
void rev_mic_det_init(void)
{
    g_rev_mic.start = 0;
    g_rev_mic.hardware_ot = 0;
}

/**
* @brief  Scans the key input and updates the key status accordingly.
* @retval None
* @par   Explanation
* This function is placed in a 10ms timer to poll
*/
u8 key_det(struct key_det_s * pkey, u8 state)
{
    u8 key_event = KEY_EVENT_NONE;

    if(state)
    {
        if(pkey->tick < KEY_TICK_MAX) //按键初次按下，触发防抖计数
        {
            pkey->tick++;
            pkey->tim_up = KEY_TIM_UP_MIN;
        }
        else if (pkey->tick == KEY_TICK_MAX)  //按键确认被按下
        {
#if MULTI_KEY_ONLY_HANDLE_FIRST_PRESS_DOWN

            //连续按键时，仅允许第一次按下响应“按下事件”
            if(!pkey->cnt)
#endif
            {
                key_event = KEY_EVENT_PRESS;
            }

            pkey->tick++;
            pkey->cnt++;
            pkey->tim_multi_countdown = KEY_TIM_UP_ACT;   //按键按下后，设置倒计时
            pkey->is_down = 1;
            pkey->is_up = 0;
        }
        else //key_tick > KEY_TICK_MAX -->长按计时
        {
            if(pkey->tim_down < KEY_TIM_DOWN_MAX)
            {
                pkey->tim_down++;    //长按计时

            }
        }
    }
    else    //按键未按下或按下后释放
    {
        if(pkey->tick)//按键释放倒计时
        {
            pkey->tick = pkey->tick / 2; //key_tick递减

            if(pkey->tim_up == 0) //只在0的时候执行一次
            {
                pkey->tim_up++;
                key_event = KEY_EVENT_RELEASE;
                pkey->tim_down = 0; //释放清零
            }
        }
        else    //确认释放
        {
            pkey->tim_down = KEY_TIM_DOWN_MIN;    //长按清零
            pkey->is_down = 0;
            pkey->is_up = 1;

            if(pkey->tim_up < KEY_TIM_UP_MAX)     //按键弹起计时
            {
                pkey->tim_up++;
            }

            if(pkey->cnt == 0)    //连击大于等于5次后，立即响应，不再等待按键弹起
            {
                pkey->tim_up = 1;    //tim_up 设置为很小，不能为0，会与按键松开事件冲突
            }
        }
    }

    if(pkey->tim_multi_countdown)
    {
        pkey->tim_multi_countdown--;
    }

    //1.倒计时结束，且按键已经释放
    //2.按键次数大于等于5次，立即执行
    if( ((0 == pkey->tim_multi_countdown) && (pkey->is_up))   || \
            (pkey->cnt >= 5) )
    {
        switch(pkey->cnt) //按键次数处理
        {
        case 1:
            key_event = KEY_EVENT_PRESS_X1;
            AM_DBG_PRINTF("x1+++\r\n");
            break;

        case 2:
            key_event = KEY_EVENT_PRESS_X2;
            AM_DBG_PRINTF("x2\r\n");
            break;

        case 3:
            key_event = KEY_EVENT_PRESS_X3;
            AM_DBG_PRINTF("x3\r\n");
            break;

        case 4:
            key_event = KEY_EVENT_PRESS_X4;
            AM_DBG_PRINTF("x4\r\n");
            break;

        case 5:
            key_event = KEY_EVENT_PRESS_X5;
            AM_DBG_PRINTF("x5\r\n");
            break;

        default:
            break;
        }

        pkey->cnt = 0;    //清除按键次数
    }

    //长按计时
    switch(pkey->tim_down)
    {
    case _KEY_DOWN_2S:
        key_event = KEY_EVENT_PRESS_LONG;
        pkey->cnt = 0;    //清除按键次数
        break;

    default:
        break;
    }

    return key_event;
}

/**
* @brief  Scans the key input and updates the key status accordingly.
* @retval None
* @par   Explanation
* This function is placed in a 10ms timer to poll
*/
void mic_scan(void)
{
#if CFG_MIC_TYPE == 0   //正向咪头检测
	
    if(plib_mic_get_flg(MIC_INHALE))
    {
		//反吹超时10秒后，初值更新，释放反吹时，导致的吸烟触发，直接更新初值
		if(g_rev_mic.blow_ot)	
		{
			AM_DBG_PRINTF("blow_inhale\r\n");
			
			//等待咪头恢复才更新初值
			if((g_rev_mic.blow_ini + _MIC_RECOVER_THD) >= plib_mic_get_cur_value())
			{
				AM_DBG_PRINTF("blow_ref\r\n");
				plib_mic_reflesh_ini_value();
				g_rev_mic.blow_ot = 0;		
			}
			else
			{
				//咪头未完全恢复，退出
				return;
			}
		}
		else //正常吸烟
		{
			g_mic_fire_en = 1;	
			g_rev_mic.start	= 1;		
		}

		plib_mic_clr_flg(MIC_INHALE);
        AM_DBG_PRINTF("Inhale\r\n");
    }
    else if(plib_mic_get_flg(MIC_INHALE_RELEASE))
    {
        plib_mic_clr_flg(MIC_INHALE_RELEASE);
		
        g_mic_fire_en = 0;
        AM_DBG_PRINTF("Inhale release\r\n");
    }
    else if(plib_mic_get_flg(MIC_INHALE_TIMEOUT))
    {
        plib_mic_clr_flg(MIC_INHALE_TIMEOUT);

        //由于吸烟一直不释放，导致的硬件超时保护后
        if(g_rev_mic.start)
        {
			g_rev_mic.start = 0;
            g_rev_mic.hardware_ot = 1;
        }

        g_mic_fire_en = 0;
		
        tiny_printf("Inhale timeout\r\n");
    }	
    else if(plib_mic_get_flg(MIC_BLOW))
    {
        plib_mic_clr_flg(MIC_BLOW);
        AM_DBG_PRINTF("Blow\r\n");

		//吸烟后，一直不释放，触发了硬件超时，且经过了10秒的初值更新；吸烟释放后，等同于触发了反吹，更新一次初值，以避开反吹更新初值的10S
        if(g_rev_mic.hardware_ot)
        {
            tiny_printf("ot rel\r\n");
            plib_mic_reflesh_ini_value();
            
            g_rev_mic.hardware_ot = 0;
        }		
        //MIC吸烟导致短路复位，复位后，MIC未释放（等同于吸烟上电）时，更新一次初值，以避开反吹更新初值的10S
        else if(g_lvr_flg && !g_lvr_rst_release_flag)
        {
            g_lvr_rst_release_flag = 1;
            plib_mic_reflesh_ini_value();
            AM_DBG_PRINTF("lvr rel\r\n");
        }		
		//正常触发反吹时，记录标志位，做反吹保护
		else
		{			
			//获取反吹时的初值
			g_rev_mic.blow_ini = plib_mic_get_init_value();
			g_rev_mic.blow = 1;
		}
    }
    else if(plib_mic_get_flg(MIC_REFLESH_VALUE))
    {
        plib_mic_clr_flg(MIC_REFLESH_VALUE);

		//由于反吹10秒，导致超时，记录超时标志
        if(g_rev_mic.blow)
        {		
            g_rev_mic.blow_ot = 1;
			g_rev_mic.blow = 0;
			AM_DBG_PRINTF("blow ot\r\n");
        }
    }	
    else if(plib_mic_get_flg(MIC_BLOW_RELEASE))
    {
        plib_mic_clr_flg(MIC_BLOW_RELEASE);
		
		g_rev_mic.blow = 0;		
        AM_DBG_PRINTF("blow release\r\n");
    }	

#elif CFG_MIC_TYPE == 1   //反向咪头检测

    if(plib_mic_get_flg(MIC_BLOW))
    {
        plib_mic_clr_flg(MIC_BLOW);
        g_mic_fire_en = 1;
        g_rev_mic.start = 1;
        AM_DBG_PRINTF("Blow\r\n");
    }
    else if(plib_mic_get_flg(MIC_BLOW_RELEASE))
    {
        plib_mic_clr_flg(MIC_BLOW_RELEASE);
        g_mic_fire_en = 0;
        //g_rev_mic.start = 0;
        AM_DBG_PRINTF("Blow release\r\n");
    }
    else if(plib_mic_get_flg(MIC_REFLESH_VALUE))
    {
        plib_mic_clr_flg(MIC_REFLESH_VALUE);

        if(g_rev_mic.start)
        {
            g_rev_mic.hardware_ot = 1;
        }

        AM_DBG_PRINTF("hwot\r\n");
    }
    else if(plib_mic_get_flg(MIC_INHALE))
    {
        plib_mic_clr_flg(MIC_INHALE);

        if(g_rev_mic.hardware_ot)       //反向咪超时释放，更新初值
        {
            AM_DBG_PRINTF("rel\r\n");
            plib_mic_reflesh_ini_value();
            g_rev_mic.start = 0;
            g_rev_mic.hardware_ot = 0;
        }

        //MIC吸烟导致短路复位，复位后，MIC未释放（等同于吹气上电）时，更新一次初值，以避开正吸更新初值的超时时间
        if(g_lvr_flg && !g_lvr_rst_release_flag)
        {
            g_lvr_rst_release_flag = 1;
            plib_mic_reflesh_ini_value();
        }
        else //正常工作情况的正吹
        {

        }
    }

#else //三线开关咪头检测
    g_mic_fire_en = _PIN_MIC;

#endif   /* end of #if CFG_MIC_TYPE == 0 */

    switch(key_det(&g_mic_s, g_mic_fire_en))
    {
    case KEY_EVENT_PRESS:

        //按着按键上电，不触发吸烟
        if(g_key_power_on)
        {
            break;
        }

        util_queue_push(EVENT_MIC_START);
        AM_DBG_PRINTF("mic_start\r\n");
        break;

    case KEY_EVENT_RELEASE:
        g_key_power_on = 0;
        util_queue_push(EVENT_MIC_STOP);
        AM_DBG_PRINTF("mic stop\r\n");
        break;

    case KEY_EVENT_PRESS_X3:
#if CFG_MIC_LOCK_CNT != 0
        util_queue_push(EVENT_LOCK_CHILD);
#endif

    default:
        break;
    }
}

/**
* @brief  Scans the key input and updates the key status accordingly.
* @retval None
* @par   Explanation
* This function is placed in a 10ms timer to poll
*/
void key_scan(void)
{
    //读取按键触发状态
#if (CFG_PIN_KEY_VALUE_TYPE == 0)
    g_key_fire_en = !_PIN_KEY;
#elif (CFG_PIN_KEY_VALUE_TYPE == 1)
    g_key_fire_en = _PIN_KEY;
#endif

    switch(key_det(&g_key_s, g_key_fire_en))
    {
    case KEY_EVENT_PRESS:
        AM_DBG_PRINTF("down\r\n");
        util_queue_push(EVENT_KEY_PRESS);
        break;

    case KEY_EVENT_RELEASE:
        AM_DBG_PRINTF("up---\r\n");
        util_queue_push(EVENT_KEY_RELEASE);
        g_key_power_on = 0;
        break;

    case KEY_EVENT_PRESS_X1:
        util_queue_push(EVENT_PRESS_x1);
        break;

    case KEY_EVENT_PRESS_X2:
#if CFG_KEY_PREFIRE_CNT != 0
        util_queue_push(EVENT_PREFIRE_START);
#endif				
        break;

    case KEY_EVENT_PRESS_X3:
#if CFG_KEY_MODE_SW_CNT != 0
				if(g_sys.lock_child == 0)
				{
					util_queue_push(EVENT_MODE_SW);
				}
#endif				
        break;

    case KEY_EVENT_PRESS_X4:
        break;

    case KEY_EVENT_PRESS_X5:
#if CFG_KEY_LOCK_CNT != 0
        util_queue_push(EVENT_LOCK_CHILD);
#endif
        break;

    case KEY_EVENT_PRESS_LONG:
        break;

    default:
        break;
    }
}
