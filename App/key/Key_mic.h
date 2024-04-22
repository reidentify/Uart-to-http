#ifndef __KEY_MIC_H__
#define __KEY_MIC_H__

#include "application.h"

#define _PIN_KEY	(plib_gpio_get_value(CFG_PIN_KEY_PORT, CFG_PIN_KEY_PINNUM))
#define _PIN_MIC	(plib_gpio_get_value(CFG_PIN_MIC_PORT, CFG_PIN_MIC_PINNUM))

#define KEY_TICK_MAX   		(2)//����
#define KEY_TICK_MIN   		(0)

#define KEY_TIM_DOWN_MAX    (5000)
#define KEY_TIM_DOWN_MIN    (0)

#define KEY_TIM_UP_MAX      (3000)
#define KEY_TIM_UP_ACT      (40)	//���������ʱ��n*10ms�����ΰ�������ڴ�ʱ���ڣ���Ϊ��������
#define KEY_TIM_UP_MIN      (0)

//����ʱ��
#define _KEY_DOWN_2S            (200)

//��ͷ�ָ���ֵ
#define _MIC_RECOVER_THD         (20)

typedef enum{
    KEY_EVENT_NONE = 0,	
    KEY_EVENT_PRESS,
    KEY_EVENT_RELEASE,        	
    KEY_EVENT_PRESS_X1,    
    KEY_EVENT_PRESS_X2, 	
    KEY_EVENT_PRESS_X3,	
    KEY_EVENT_PRESS_X4,   
    KEY_EVENT_PRESS_X5, 
    KEY_EVENT_PRESS_LONG,
}KEY_EVENT_E;

struct key_det_s {
    u8 tick;			//��������
    u8 cnt;				//��������
  u8 is_down  : 1;  //ȷ�ϰ��±�־λ
  u8 is_up    : 1;  //ȷ���ͷű�־λ
  u8 reserve  : 6;  //Ԥ��
	u16 tim_down;		//����ʱ��
	u16 tim_up;			//�ͷ�ʱ��
  u16 tim_multi_countdown; //����������⵹��ʱ
};
extern idata struct key_det_s g_key_s;

typedef struct
{
	u8  start : 1;      	//����״̬��1Ϊ������0Ϊ�ͷ�
	u8  hardware_ot : 1;  	//Ӳ����ʱ���³�ֵ
	u8  blow : 1;      		//����״̬��1Ϊ������0Ϊ�ͷ�
	u8  blow_ot : 1;  		//������ʱ���³�ֵ
	u8  unuse :4;
	
	u16 blow_ini;			//����ǰ�ĳ�ֵ
}REV_MIC_STATUS_T;
extern REV_MIC_STATUS_T g_rev_mic;    //����mic״̬

extern bit g_mic_fire_en;  //MIC����������Ч
extern bit g_key_fire_en;  //��������������Ч
extern bit g_key_power_on;

// ����2�δ���Ԥ��
extern xdata u8 g_prefire_on;

void mic_scan(void);
void key_scan(void);
void rev_mic_det_init(void);

#endif
