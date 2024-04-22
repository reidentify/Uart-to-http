#ifndef __BATTERY_H__
#define __BATTERY_H__

#include "application.h"

struct capacity {
	int per;
	int min;
	int max;	
};

// Battery related data structure
struct battery_state {
    struct {
        u16 now;				// Real-time voltage value obtained
        u16 idle;				// Voltage in idle (undischarged) state
        u16 fire;				// Voltage in firing state
    } volt;		
	
	u8 init_level;    			// 第一次上电时的，电量百分比，用来控制第一次上电满电时，特殊处理
	u16 advalue;                // ADC result
  u8 sample_delay;			// Delayed sampling of battery voltage
	u8 low_cnt;    			// 低电次数
	u16 fire_time;				// battery fire timer
	u16 chg_time;				// 充电时间
};
extern idata struct battery_state g_battery;

#define CFG_BAT_LEVEL1_VOLT (3700)
#define CFG_BAT_LEVEL2_VOLT (3870)
#define BAT_LEVEL_1  (0x01)
#define BAT_LEVEL_2  (0x02)
#define BAT_LEVEL_3  (0x04)

#define BAT_LOW_CNT		(3)

void battery_get_volt_init(void);
void battery_get_volt(void);
u8 get_battery_level(void);
void batlow_lock(void);
void batlow_unlock(void);

#endif

