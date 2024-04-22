#ifndef __SCREEN_CTRL_MODE_H__
#define __SCREEN_CTRL_MODE_H__

#include "battery.h"
#include "screen_xx.h"
typedef enum
{
    SCREEN_MODE_UNDEFINE = 0,
    SCREEN_MODE_OFF,        	//Always off
    SCREEN_MODE_ON,         	//Always on
    SCREEN_MODE_FLASH,      	//Blink
    SCREEN_MODE_HOLD,			//Holding Status
	SCREEN_MODE_MARQUEE,		//Marquee	
  SCREEN_MODE_BREATH,

} SCREEN_MODE_E;

typedef struct
{
    u8 mode;         //ģʽ
    u8 cnt;          //��Ҫ���ƵĴ���
    u16 run;          //�����������������е�ʱ��
    u16 period;       //���ο��Ƶ�����
    u8 is_on;         //��ǰ�Ƿ������������ڸ�����˸״̬	
    u8 onoff_after_flash;  //��˸����״̬
    u8 delay;
    u32 ctrl_mask;      //��������
    u32 ctrl_bak;       //����ǰ�ı���
    u32 ctrl_mask2;      //��������
    u32 ctrl_bak2;       //����ǰ�ı���
} SCREEN_CTRL_T;


typedef struct
{
  u8 period ;        //����
  u8 duty   ;        //ռ�ձ�  
  u8 run   ;         //��ǰֵ 
}SCR_PWM_T;


#define SCR_PWM_PERIOD  (16)
#define SCR_PWM_MUTY_MAX  (SCR_PWM_PERIOD - 1)

#define SCR_CAL_DUTY_BREATH_UP()	((u32)screen_ctrl_t.run * SCR_PWM_MUTY_MAX / screen_ctrl_t.period)
#define SCR_CAL_DUTY_BREATH_DN()	(SCR_PWM_MUTY_MAX - SCR_CAL_DUTY_BREATH_UP())


extern SCREEN_CTRL_T xdata screen_ctrl_t;

void screen_set_ctrl_info(SCREEN_MODE_E mode, u16 Period_Onff, u8 Loop_Times, u32 ch_Mark, u32 ch_Mark2, u8 flash_on);
void screen_set_bright(u32 mask, u32 mask2);
void screen_ctrl_handler(void);
void screen_soft_pwm_process(void);
#endif




