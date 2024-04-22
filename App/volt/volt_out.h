#ifndef _OUTPUT_CTRL_H_
#define	_OUTPUT_CTRL_H_

#include "application.h"

#define CFG_MOS_PWM_PERIOD_MAX	((u32)CFG_MOS_PWM_PERIOD * 99 / 100)	//��ռ�ձ���99%�����ȷ���ܴ���PWM���ز���
#define CFG_MOS_PWM_PERIOD_MIN	((u32)CFG_MOS_PWM_PERIOD * 20 / 100)	//��Сռ�ձ��������20%���

#define CFG_EXTMOS_PWM_PERIOD_MAX	((u32)CFG_EXTMOS_PWM_PERIOD * 99 / 100)	//��ռ�ձ���99%�����ȷ���ܴ���PWM���ز���
#define CFG_EXTMOS_PWM_PERIOD_MIN	((u32)CFG_EXTMOS_PWM_PERIOD * 20 / 100)	//��Сռ�ձ��������20%���

#define ExtMOS_Output(ifen)       	\
{                                   \
    if(ifen == ENABLE)              \
        plib_gpio_set_value(CFG_PIN_EXTMOS_VOUT_PORT, CFG_PIN_EXTMOS_VOUT_PINNUM, PLIB_LOW);      \
    else                            \
        plib_gpio_set_value(CFG_PIN_EXTMOS_VOUT_PORT, CFG_PIN_EXTMOS_VOUT_PINNUM, PLIB_HIGH);       \
}

typedef enum {
	OUTPUT_MODE_MOS_NONE = 0,		//�����	
	OUTPUT_MODE_INMOS_ONLY,			//���ڲ�MOS���
	OUTPUT_MODE_EXMOS_ONLY,			//���ⲿMOS���
	OUTPUT_MODE_MOS_BOTH,			//˫MOSͬʱ���
} OUTPUT_MODE_E;

struct output_data {
	u8 pwm_open_dly;		//MOS PWM��ͨ����ʱ����ADC��ʱ�����ڣ���100us��ʱ������ʵ����ʱ=N*100us
	u8 pwm_open_flg;		//�ܿ�MOS PWM�����ز���ADC�ı�־
	u8 pwm_ris_flg;			//PWM�����ر�־
	u16 pwm_duty;			//�������ռ�ձ�	
	u16 v_mos_out;			//���ʵʱ��ѹ
	u16 v_user_set;			//������õ�Ŀ���ѹ
	u16 v_user_set_temp;			//���õ�Ŀ���ѹ
	u8 fire_on;				//���̱�־��1=�������
	u8 ouput_mode;			//���ģʽ���ڲ�MOS������ⲿMOS�����˫��ͬʱ���	
};

struct output_ctrl {
	struct output_data chn[2];		//���������·MOS���
	u8 ouput_mode;			//���ģʽ���ڲ�MOS������ⲿMOS�����˫��ͬʱ���	
	u8 ouput_level;
};

#define POWER_OUTPUT_RED  	(0x01)
#define POWER_OUTPUT_BLUE  	(0x02)
#define POWER_OUTPUT_WHILTE	(0x07)  

extern idata struct output_ctrl g_out_s;

void out_fire_start(void);
void out_fire_stop(void);
void out_ctrl_cv(void);
void out_ctrl_cw(void);
void output_mos_change(void);

#endif

