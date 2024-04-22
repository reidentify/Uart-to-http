/**
 * @file
 * @brief		PWM����
 * @author		admin
 * @date		2023.07.27
 * @version	    v1.1
 * @par 		Copyright(c): All rights reserved.
 * @par 		�޸ļ�¼
 * @par 		1.admin��2023-09-05������PWM�����غ��½����ж��Ƿ�ʹ�ܽӿ�  
*/

#ifndef __PMCU_PWM_H_
#define __PMCU_PWM_H_

#include "pmcu_x0_config.h"

#define PWM_TRIG_RISING 	((U8)0x01)	/* PWM�������¼� */
#define PWM_TRIG_FALLING	((U8)0x02)	/* PWM�½����¼� */

/** PWM��ѡ�� */
typedef enum {
    PWM_SEL0 = 0,			/*!< PWM0 */
    PWM_SEL1,				/*!< PWM1 */
} PWM_SEL_E;

/** PWMͨ��ѡ�� */
typedef enum {
    PWM_CH0 = 0,			/*!< ͨ��0 */
    PWM_CH1,				/*!< ͨ��1 */
    PWM_CH2,				/*!< ͨ��2 */
} PWM_CHN_E;

/** PWM���ʱ�ӷ�Ƶϵ�� */
typedef enum {
    PWM_FCLK1 = 0,		/*!< 1��Ƶ����С���Ƶ�ʣ�62745Hz */
    PWM_FCLK2,			/*!< 2��Ƶ����С���Ƶ�ʣ�31373Hz */
    PWM_FCLK4,          /*!< 4��Ƶ����С���Ƶ�ʣ�15686Hz */
    PWM_FCLK8,          /*!< 8��Ƶ����С���Ƶ�ʣ�7843Hz */
    PWM_FCLK16,         /*!< 16��Ƶ����С���Ƶ�ʣ�3922Hz */
    PWM_FCLK32,         /*!< 32��Ƶ����С���Ƶ�ʣ�1960Hz */
    PWM_FCLK64,         /*!< 64��Ƶ����С���Ƶ�ʣ�980Hz */
    PWM_FCLK128,        /*!< 128��Ƶ����С���Ƶ�ʣ�490Hz */
} PWM_FCLK_E;

/**
* @brief  PWM��ʼ������
* @param  pwmsel PWM��ѡ�� \n
* @ref PWM_SEL0  \n
* @ref PWM_SEL1  \n
* @param  Fclk_div ��Ƶϵ����ѡ�� \n
* @ref PWM_FCLK1  \n
* @ref PWM_FCLK2  \n
* @ref PWM_FCLK4  \n
* @ref PWM_FCLK8  \n
* @ref PWM_FCLK16 \n
* @ref PWM_FCLK32 \n
* @ref PWM_FCLK64 \n
* @ref PWM_FCLK128 \n
* @param  Period �������ã�����ֵ=16000000/ʱ�ӷ�Ƶϵ��/���Ƶ��
* @param  CH0_Duty ͨ��0ռ�ձ����ã�����ֵ=����*���ռ�ձ�
* @param  CH1_Duty ͨ��1ռ�ձ����ã�����ֵ=����*���ռ�ձ�
* @param  CH2_Duty ͨ��2ռ�ձ����ã�����ֵ=����*���ռ�ձ�
* @param  ifNegate �Ƿ�ʹ�ܼ��Է�ת \n
* @ref PLIB_ENABLE ʹ�� \n
* @ref PLIB_DISABLE ��ʹ�� \n
* @retval ��
* @par   ˵��
* ��
*/
void plib_pwm_init(PWM_SEL_E pwmsel, PWM_FCLK_E Fclk_div, U8 Period, U8 CH0_Duty, U8 CH1_Duty, U8 CH2_Duty, U8 ifNegate);

/**
* @brief  PWM���ʹ��
* @param  pwmsel PWM��ѡ�� \n
* @ref PWM_SEL0  \n
* @ref PWM_SEL1  \n
* @param  newstate �Ƿ�ʹ�� \n
* @ref PLIB_ENABLE ʹ�� \n
* @ref PLIB_DISABLE ��ʹ�� \n
* @retval ��
* @par   ˵��
* ��
*/
void plib_pwm_en(PWM_SEL_E pwmsel, FUNC_EN_E ifEn);

/**
* @brief  PWM������Է�תʹ��
* @param  pwmsel PWM��ѡ�� \n
* @ref PWM_SEL0  \n
* @ref PWM_SEL1  \n
* @param  newstate �Ƿ�ʹ�� \n
* @ref PLIB_ENABLE ʹ�� \n
* @ref PLIB_DISABLE ��ʹ�� \n
* @retval ��
* @par   ˵��
* ��
*/
void plib_pwm_negate_en(PWM_SEL_E pwmsel, FUNC_EN_E ifEn);

/**
* @brief  ͬʱ���ã�PWM���ռ�ձ�����
* @param  pwmsel PWM��ѡ�� \n
* @ref PWM_SEL0  \n
* @ref PWM_SEL1  \n
* @param  duty0 ͨ��0ռ�ձ����ã�����ֵ=����*���ռ�ձ�
* @param  duty1 ͨ��1ռ�ձ����ã�����ֵ=����*���ռ�ձ�
* @param  duty2 ͨ��2ռ�ձ����ã�����ֵ=����*���ռ�ձ�
* @retval ��
* @par   ˵��
* -# ��ʹ�õ�ͨ��������Ϊ0����
*/
void plib_pwm_set_chn_duty(PWM_SEL_E pwmsel, U8 duty0, U8 duty1, U8 duty2);

/**
* @brief  PWM�ж�ʹ��
* @param  pwmsel PWM��ѡ�� \n
* @ref PWM_SEL0  \n
* @ref PWM_SEL1  \n
* @param  event PWM�ж��¼��� \n
* @ref PWM_TRIG_RISING  \n
* @ref PWM_TRIG_FALLING  \n
* @param  newstate �Ƿ�ʹ�� \n
* @ref PLIB_ENABLE ʹ�� \n
* @ref PLIB_DISABLE ��ʹ�� \n
* @retval ��
* @par   ˵��
* -# ��ͨ��0�ᴥ�������غ��½����жϣ���100%ռ�ձ�ʱ�����ᴥ���ж�
*/
void plib_pwm_it_cfg(PWM_SEL_E pwmsel, U8 event, FUNC_EN_E ifEn);

/**
* @brief  PWM�ж��Ƿ�ʹ��
* @param  pwmsel PWM��ѡ�� \n
* @ref PWM_SEL0  \n
* @ref PWM_SEL1  \n
* @param  event PWM�ж��¼��� \n
* @ref PWM_TRIG_RISING  \n
* @ref PWM_TRIG_FALLING  \n
* @retval  �¼��ж�ʹ��״̬
* - 0 δʹ��
* - ��0 ��ʹ��
* @par ˵��
* ��
*/
U8 plib_pwm_it_ifen(PWM_SEL_E pwmsel, U8 event);

/**
* @brief  PWM���ж�ʹ��
* @param  newstate �Ƿ�ʹ�� \n
* @ref PLIB_ENABLE ʹ�� \n
* @ref PLIB_DISABLE ��ʹ�� \n
* @retval ��
* @par   ˵��
* -# ��MOS PWM����һ���ж�ʹ��
*/
void plib_pwm_it_en(FUNC_EN_E ifEn);

/**
* @brief  PWM�¼�״̬
* @param  pwmsel PWM��ѡ�� \n
* @ref PWM_SEL0  \n
* @ref PWM_SEL1  \n
* @param  event PWM�ж��¼��� \n
* @ref PWM_TRIG_RISING  \n
* @ref PWM_TRIG_FALLING  \n
* @retval  �¼�����״̬
* - 0 δ������Ӧ״̬
* - ��0 �����˶�Ӧ״̬
* @par   ˵��
* -# ��ͨ��0�ᴥ�������غ��½���״̬
*/
U8 plib_pwm_get_flg(PWM_SEL_E pwmsel, U8 event);

/**
* @brief  ���PWM�¼�״̬
* @param  pwmsel PWM��ѡ�� \n
* @ref PWM_SEL0  \n
* @ref PWM_SEL1  \n
* @param  event PWM�ж��¼��� \n
* @ref PWM_TRIG_RISING  \n
* @ref PWM_TRIG_FALLING  \n
* @retval ��
* @par   ˵��
* ��
*/
void plib_pwm_clr_flg(PWM_SEL_E pwmsel, U8 event);

#endif /* end of __PMCU_PWM_H_ */

