/**
 * @file
 * @brief		��ʱ������
 * @author		admin
 * @date		2023.07.27
 * @version	    v1.1
 * @par 		Copyright(c): All rights reserved.
 * @par 		�޸ļ�¼
 * @par 		1.admin��2023-08-21���������װ��ʽ�����ٴ���ռ� 
*/

#ifndef __PMCU_TIMER_H_
#define __PMCU_TIMER_H_

#include "pmcu_x0_config.h"

/** ��ʱ������ģʽ���� */
typedef enum {
    TIM_MODE_0 = 0,					/*!< ��ʱ������ģʽ0��13bit�������أ����ʱ6ms */
    TIM_MODE_1,                 	/*!< ��ʱ������ģʽ1��16bit�������أ����ʱ49ms */
    TIM_MODE_2,                 	/*!< ��ʱ������ģʽ2��16bit�����أ����ʱ49ms */
} TIM_Mode_E;

/**
* @brief  ��ʱ��0��ʼ������
* @param  TIM_Mode ��ʱ���Ĺ���ģʽ��ѡ�� \n
* @ref TIM_MODE_0 \n
* @ref TIM_MODE_1 \n
* @ref TIM_MODE_2 \n
* @param  TIM_Period ��ʱ���Ķ�ʱʱ�䣬��λus��TIM_MODE_0���ʱʱ��Ϊ6ms��TIM_MODE_1��TIM_MODE_2���ʱʱ��Ϊ49ms
* @param  TIM_En ��ʱ��������ʹ�� \n
* @ref PLIB_ENABLE ʹ�� \n
* @ref PLIB_DISABLE ��ʹ�� \n
* @param  TIM_IntEn ��ʱ�����ж�ʹ�� \n
* @ref PLIB_ENABLE ʹ�� \n
* @ref PLIB_DISABLE ��ʹ�� \n
* @retval ��
* @par   ˵��
* ��
*/
void plib_tim0_init(TIM_Mode_E TIM_Mode, U16 TIM_Times, FUNC_EN_E TIM_En, FUNC_EN_E TIM_IntEn);

/**
* @brief  ��ʱ��0��װ��ֵ
* @param  TIM_Mode ��ʱ���Ĺ���ģʽ��ѡ�� \n
* @ref TIM_MODE_0 \n
* @ref TIM_MODE_1 \n
* @param  TIM_Times ��ʱ���Ķ�ʱʱ�䣬��λus��TIM_MODE_0���ʱʱ��Ϊ6ms��TIM_MODE_1���ʱʱ��Ϊ49ms
* @retval ��
* @par   ˵��
* -# ����TIM_MODE_0��TIM_MODE_1����ģʽ��ʹ��
*/
void plib_tim0_reload(TIM_Mode_E TIM_Mode, U16 TIM_Times);

/**
* @brief  Timer0�Ƿ�������ʱ
* @param  newstate �Ƿ�ʹ�� \n
* @ref PLIB_ENABLE ʹ�� \n
* @ref PLIB_DISABLE ��ʹ�� \n
* @retval ��
* @par   ˵��
* ��
*/
void plib_tim0_en(FUNC_EN_E ifEn);

/**
* @brief  Timer0�ж�ʹ��
* @param  ifEn �Ƿ�ʹ�� \n
* @ref PLIB_ENABLE ʹ�� \n
* @ref PLIB_DISABLE ��ʹ�� \n
* @retval ��
* @par    ˵��
* ��
*/
void plib_tim0_it_en(FUNC_EN_E ifEn);

/**
* @brief  ��ʱ��1��ʼ������
* @param  TIM_Mode ��ʱ���Ĺ���ģʽ��ѡ�� \n
* @ref TIM_MODE_0 \n
* @ref TIM_MODE_1 \n
* @ref TIM_MODE_2 \n
* @param  TIM_Period ��ʱ���Ķ�ʱʱ�䣬��λus��TIM_MODE_0���ʱʱ��Ϊ6ms��TIM_MODE_1��TIM_MODE_2���ʱʱ��Ϊ49ms
* @param  TIM_En ��ʱ��������ʹ�� \n
* @ref PLIB_ENABLE ʹ�� \n
* @ref PLIB_DISABLE ��ʹ�� \n
* @param  TIM_IntEn ��ʱ�����ж�ʹ�� \n
* @ref PLIB_ENABLE ʹ�� \n
* @ref PLIB_DISABLE ��ʹ�� \n
* @retval ��
* @par   ˵��
* ��
*/
void plib_tim1_init(TIM_Mode_E TIM_Mode, U16 TIM_Times, FUNC_EN_E TIM_En, FUNC_EN_E TIM_IntEn);

/**
* @brief  ��ʱ��1��װ��ֵ
* @param  TIM_Mode ��ʱ���Ĺ���ģʽ��ѡ�� \n
* @ref TIM_MODE_0 \n
* @ref TIM_MODE_1 \n
* @param  TIM_Times ��ʱ���Ķ�ʱʱ�䣬��λus��TIM_MODE_0���ʱʱ��Ϊ6ms��TIM_MODE_1���ʱʱ��Ϊ49ms
* @retval ��
* @par   ˵��
* -# ����TIM_MODE_0��TIM_MODE_1����ģʽ��ʹ��
*/
void plib_tim1_reload(TIM_Mode_E TIM_Mode, U16 TIM_Times);

/**
* @brief  Timer1�Ƿ�������ʱ
* @param  newstate �Ƿ�ʹ�� \n
* @ref PLIB_ENABLE ʹ�� \n
* @ref PLIB_DISABLE ��ʹ�� \n
* @retval ��
* @par   ˵��
* ��
*/
void plib_tim1_en(FUNC_EN_E ifEn);

/**
* @brief  Timer1�ж�ʹ��
* @param  ifEn �Ƿ�ʹ�� \n
* @ref PLIB_ENABLE ʹ�� \n
* @ref PLIB_DISABLE ��ʹ�� \n
* @retval ��
* @par    ˵��
* ��
*/
void plib_tim1_it_en(FUNC_EN_E ifEn);

#endif /* end of __PMCU_TIMER_H_ */

