#include "key_mic.h"

//��������ʱ�����ֻ�������¼���Ӧһ�Σ��˺�����Ϊ1��
#define MULTI_KEY_ONLY_HANDLE_FIRST_PRESS_DOWN  1

/* Global key status */
struct piple_state g_mic_piple;
idata struct key_det_s g_mic_s, g_key_s;

#define MIC_SENSITIVITY_PERCENT   (1)   //�����Ȱٷֱ�
#define REV_MIC_RELEASE_FILTER    (3)
REV_MIC_STATUS_T g_rev_mic;         //����mic״̬

bit g_mic_fire_en;  //MIC����
bit g_key_fire_en;  //��������
bit g_key_power_on;  //���ڱ����ϵ�ʱ������״̬����ȷ�����Ű����ϵ磬���ᴥ������
xdata u8 g_prefire_on;

/**
* @brief  �жϷ������Ƿ����ͷ�״̬
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
* @brief  ��ͷ����ʼ��
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
        if(pkey->tick < KEY_TICK_MAX) //�������ΰ��£�������������
        {
            pkey->tick++;
            pkey->tim_up = KEY_TIM_UP_MIN;
        }
        else if (pkey->tick == KEY_TICK_MAX)  //����ȷ�ϱ�����
        {
#if MULTI_KEY_ONLY_HANDLE_FIRST_PRESS_DOWN

            //��������ʱ���������һ�ΰ�����Ӧ�������¼���
            if(!pkey->cnt)
#endif
            {
                key_event = KEY_EVENT_PRESS;
            }

            pkey->tick++;
            pkey->cnt++;
            pkey->tim_multi_countdown = KEY_TIM_UP_ACT;   //�������º����õ���ʱ
            pkey->is_down = 1;
            pkey->is_up = 0;
        }
        else //key_tick > KEY_TICK_MAX -->������ʱ
        {
            if(pkey->tim_down < KEY_TIM_DOWN_MAX)
            {
                pkey->tim_down++;    //������ʱ

            }
        }
    }
    else    //����δ���»��º��ͷ�
    {
        if(pkey->tick)//�����ͷŵ���ʱ
        {
            pkey->tick = pkey->tick / 2; //key_tick�ݼ�

            if(pkey->tim_up == 0) //ֻ��0��ʱ��ִ��һ��
            {
                pkey->tim_up++;
                key_event = KEY_EVENT_RELEASE;
                pkey->tim_down = 0; //�ͷ�����
            }
        }
        else    //ȷ���ͷ�
        {
            pkey->tim_down = KEY_TIM_DOWN_MIN;    //��������
            pkey->is_down = 0;
            pkey->is_up = 1;

            if(pkey->tim_up < KEY_TIM_UP_MAX)     //���������ʱ
            {
                pkey->tim_up++;
            }

            if(pkey->cnt == 0)    //�������ڵ���5�κ�������Ӧ�����ٵȴ���������
            {
                pkey->tim_up = 1;    //tim_up ����Ϊ��С������Ϊ0�����밴���ɿ��¼���ͻ
            }
        }
    }

    if(pkey->tim_multi_countdown)
    {
        pkey->tim_multi_countdown--;
    }

    //1.����ʱ�������Ұ����Ѿ��ͷ�
    //2.�����������ڵ���5�Σ�����ִ��
    if( ((0 == pkey->tim_multi_countdown) && (pkey->is_up))   || \
            (pkey->cnt >= 5) )
    {
        switch(pkey->cnt) //������������
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

        pkey->cnt = 0;    //�����������
    }

    //������ʱ
    switch(pkey->tim_down)
    {
    case _KEY_DOWN_2S:
        key_event = KEY_EVENT_PRESS_LONG;
        pkey->cnt = 0;    //�����������
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
#if CFG_MIC_TYPE == 0   //������ͷ���
	
    if(plib_mic_get_flg(MIC_INHALE))
    {
		//������ʱ10��󣬳�ֵ���£��ͷŷ���ʱ�����µ����̴�����ֱ�Ӹ��³�ֵ
		if(g_rev_mic.blow_ot)	
		{
			AM_DBG_PRINTF("blow_inhale\r\n");
			
			//�ȴ���ͷ�ָ��Ÿ��³�ֵ
			if((g_rev_mic.blow_ini + _MIC_RECOVER_THD) >= plib_mic_get_cur_value())
			{
				AM_DBG_PRINTF("blow_ref\r\n");
				plib_mic_reflesh_ini_value();
				g_rev_mic.blow_ot = 0;		
			}
			else
			{
				//��ͷδ��ȫ�ָ����˳�
				return;
			}
		}
		else //��������
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

        //��������һֱ���ͷţ����µ�Ӳ����ʱ������
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

		//���̺�һֱ���ͷţ�������Ӳ����ʱ���Ҿ�����10��ĳ�ֵ���£������ͷź󣬵�ͬ�ڴ����˷���������һ�γ�ֵ���Աܿ��������³�ֵ��10S
        if(g_rev_mic.hardware_ot)
        {
            tiny_printf("ot rel\r\n");
            plib_mic_reflesh_ini_value();
            
            g_rev_mic.hardware_ot = 0;
        }		
        //MIC���̵��¶�·��λ����λ��MICδ�ͷţ���ͬ�������ϵ磩ʱ������һ�γ�ֵ���Աܿ��������³�ֵ��10S
        else if(g_lvr_flg && !g_lvr_rst_release_flag)
        {
            g_lvr_rst_release_flag = 1;
            plib_mic_reflesh_ini_value();
            AM_DBG_PRINTF("lvr rel\r\n");
        }		
		//������������ʱ����¼��־λ������������
		else
		{			
			//��ȡ����ʱ�ĳ�ֵ
			g_rev_mic.blow_ini = plib_mic_get_init_value();
			g_rev_mic.blow = 1;
		}
    }
    else if(plib_mic_get_flg(MIC_REFLESH_VALUE))
    {
        plib_mic_clr_flg(MIC_REFLESH_VALUE);

		//���ڷ���10�룬���³�ʱ����¼��ʱ��־
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

#elif CFG_MIC_TYPE == 1   //������ͷ���

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

        if(g_rev_mic.hardware_ot)       //�����䳬ʱ�ͷţ����³�ֵ
        {
            AM_DBG_PRINTF("rel\r\n");
            plib_mic_reflesh_ini_value();
            g_rev_mic.start = 0;
            g_rev_mic.hardware_ot = 0;
        }

        //MIC���̵��¶�·��λ����λ��MICδ�ͷţ���ͬ�ڴ����ϵ磩ʱ������һ�γ�ֵ���Աܿ��������³�ֵ�ĳ�ʱʱ��
        if(g_lvr_flg && !g_lvr_rst_release_flag)
        {
            g_lvr_rst_release_flag = 1;
            plib_mic_reflesh_ini_value();
        }
        else //�����������������
        {

        }
    }

#else //���߿�����ͷ���
    g_mic_fire_en = _PIN_MIC;

#endif   /* end of #if CFG_MIC_TYPE == 0 */

    switch(key_det(&g_mic_s, g_mic_fire_en))
    {
    case KEY_EVENT_PRESS:

        //���Ű����ϵ磬����������
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
    //��ȡ��������״̬
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
