#ifndef __RL_DET_H__
#define __RL_DET_H__

#include "application.h"

#define RL_DET_TICK_MAX   		(50)//����

#define EXT_RL_DIV_VALUE 		(5100)	//����MOS��������ؼ���ѹ����

#if CFG_PIN_EXTMOS_RL_DET_GPIO	//GPIO����
#define EXT_RLOAD_DET_EN_Output(ifen)       \
{                                   \
    if(ifen == ENABLE)              \
        plib_gpio_set_value(CFG_PIN_EXTMOS_RL_PORT, CFG_PIN_EXTMOS_RL_PINNUM, PLIB_LOW);      \
    else                            \
        plib_gpio_set_value(CFG_PIN_EXTMOS_RL_PORT, CFG_PIN_EXTMOS_RL_PINNUM, PLIB_HIGH);     \
}
#endif /* end of #if CFG_PIN_EXTMOS_RL_DET_GPIO */

#if CFG_PIN_EXTMOS_RL_DET_MOTOR	//�ܽŲ�����ʹ��MOTOR�ܽ�����ߵ͵�ƽ
#define EXT_RLOAD_DET_EN_Output(ifen)			\
{												\
	if(ifen == ENABLE)							\			
	{											\				
		plib_motor_set_duty(MOTOR_DUTY_100);	\	
		plib_motor_en(ENABLE);					\			
	}											\				
	else										\			
	{											\				
		plib_motor_set_duty(MOTOR_DUTY_0);		\				
		plib_motor_en(ENABLE);					\								
	}											\			
}
#endif /* end of #if CFG_PIN_EXTMOS_RL_DET_MOTOR */

typedef enum {
    RL_OPEN = 0, // bit4 used to determine if open circuit
    RL_NORMAL = 1,
    RL_LOW = 2,
    RL_SHORT = 3,
    RL_DRY = 4,	
} RL_STATUS_E;

struct rl_det_data {
	u8 rl_plug;
    u8 plug_delay;		
    u8 status;
    u16 ohm;
};
extern idata struct rl_det_data g_rl_det[2];

void rload_det(void);
void rload_get_inmos_ohm(u8 gain_sel);
void rload_get_exmos_ohm(void);
u8 rload_det_firing(void);

#endif
