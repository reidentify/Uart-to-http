#ifndef __USERDATAS_H__
#define __USERDATAS_H__

#include "application.h"

#define RST_POR_RAM		0x55AA5AA5	// Power-on reset
#define RST_LVR_RAM		0x00000000	// Low voltage (short circuit) reset

typedef enum
{
  RST_TYPE_NORMAL = 0,
  RST_TYPE_LVR,
}RST_TYPE_E;

typedef struct  
{
  //��λ״̬���֣� �벻Ҫ�Ķ��˱���
    u32 rst_status; 
  
  //�����������
    u32 time;      	// Total oil volume
    u32 work_time; 	// Amount of oil used
  
  //�����������
    u8 show_level;					// ��ʾ�ٷֱ�
    u8 real_level;    			// ��ʵ�ٷֱ�	
   
  //ģʽ�������
    u8  output_mode;        //��˫�����ģʽ
  
	//��λ�������
		u8 out_level;
  
  //�������Ҫ���籣��Ĳ�������������λ����ӣ�����ע��ռ�ռ�ô�С
  
}USER_DATA_T;

extern xdata USER_DATA_T g_userdata_t;



extern bit g_lvr_rst_release_flag;
extern bit g_lvr_flg;

void reset_src_set(void);
void reset_src_clear(void);
u8 reset_src_get(void);
void smoke_info_init(void);
u8 get_oil_percentage(void);
void oil_value_update(void);

#endif

