#ifndef __CHARGER_USB_H__
#define __CHARGER_USB_H__

#include "application.h"

#define USB_IN_CNT_MAX 		30  		//300ms���������Ϊȷ��OVP��־��⣬ʱ�䲻��̫��
#define USB_OVP_CNT_MAX 	10  	//100msOVP��������

#define USB_IS_IN_CHARGING (g_chg_s.chg_state == USB_STATE_USB_CHRGING)

typedef enum {
    USB_STATE_USB_IDLE = 0,
	USB_STATE_USB_IN,
	USB_STATE_USB_OUT,
    USB_STATE_USB_CHRGING,
    USB_STATE_USB_FULL,
    USB_STATE_USB_RECHG,
    USB_STATE_USB_OVP,	
    USB_STATE_USB_UVP,		
} USB_STATE_E;

typedef struct
{
	u8	ovp_cnt;
	u8	in_cnt;
	u8	chg_state;
	u32	full_timeout_cnt;
	
	union
	{
		u8 flg;
		struct
		{
			u8 in : 1;    	//USB����
			u8 out : 1;  	//USB�γ�
			u8 ovp : 1;  	//USB��ѹ
			u8 uvp : 1;  	//USBǷѹ
			u8 hw_full :1;	//Ӳ������
			u8 sf_full :1;	//�����������
			u8 full_timeout :1;	//99%��ǿ�������־
		}bits;
	}CHG_U;			
} CHG_T;

extern idata CHG_T g_chg_s;
#define _ChgBit  (g_chg_s.CHG_U.bits)

void usb_charger_process(void);

#endif
