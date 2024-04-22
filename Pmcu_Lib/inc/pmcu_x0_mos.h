/**
 * @file
 * @brief		MOS PWM����
 * @author		admin
 * @date		2023.07.27
 * @version	    v1.1
 * @par 		Copyright(c): All rights reserved.
 * @par 		�޸ļ�¼
 * @par 		1.admin��2023-09-05������MOS�����غ��½����ж��Ƿ�ʹ�ܽӿ�
*/

#ifndef __PMCU_MOS_H_
#define __PMCU_MOS_H_

#include "pmcu_x0_config.h"

#define MOS_TRIG_RISING 				((U8)0x01)	/* MOS PWM�������¼� */
#define MOS_TRIG_FALLING				((U8)0x02)	/* MOS PWM�½����¼� */
#define MOS_OTP							((U8)0x20)	/* MOS PWM OTP�¼� */
#define MOS_OCP 						((U8)0x40)	/* MOS PWM OCP�¼� */

/** ��/��MOS���ʹ�����/�½�б�� */
typedef enum {
    MOS_SPEED4 = 0,			/*!< ��/��MOS����б�ʵ�λ4 */
    MOS_SPEED3,				/*!< ��/��MOS����б�ʵ�λ3 */
    MOS_SPEED2,				/*!< ��/��MOS����б�ʵ�λ2 */
    MOS_SPEED1,				/*!< ��/��MOS����б�ʵ�λ1 */
} MOS_SPEED_E;

/** ���������·������ֵ */
typedef enum {
    MOS_OCP_4A = 0,			/*!< 4A */
    MOS_OCP_5A,				/*!< 5A */
    MOS_OCP_6A,				/*!< 6A */
    MOS_OCP_7A,				/*!< 7A */
} MOS_OCP_THD_E;

/** �������ʱ�ӷ�Ƶϵ�� */
typedef enum {
    MOS_Fclk = 0,				/*!< 1��Ƶ����С���Ƶ�ʣ�245Hz */
    MOS_Fclk2,					/*!< 2��Ƶ����С���Ƶ�ʣ�123Hz */
    MOS_Fclk4,					/*!< 4��Ƶ����С���Ƶ�ʣ�62Hz */
    MOS_Fclk8,					/*!< 8��Ƶ����С���Ƶ�ʣ�31Hz */
    MOS_Fclk16,					/*!< 16��Ƶ����С���Ƶ�ʣ�16Hz */
} MOS_FCLK_E;

/**
* @brief  MOS PWM��ʼ������
* @param  Fclk_div ��Ƶϵ����ѡ�� \n
* @ref MOS_Fclk  \n
* @ref MOS_Fclk2  \n
* @ref MOS_Fclk4  \n
* @ref MOS_Fclk8  \n
* @ref MOS_Fclk16 \n
* @param  Period �������ã�����ֵ=16000000/ʱ�ӷ�Ƶϵ��/���Ƶ��
* @param  Duty ռ�ձ����ã�����ֵ=����*���ռ�ձ�
* @param  Ocp_Thd �����������������ֵ��ѡ�� \n
* @ref MOS_OCP_4A  \n
* @ref MOS_OCP_5A  \n
* @ref MOS_OCP_6A  \n
* @ref MOS_OCP_7A  \n
* @param  OcpEn ���������������ʹ�� \n
* @ref PLIB_ENABLE ʹ�� \n
* @ref PLIB_DISABLE ��ʹ�� \n
* @param  OtpEn ����������±���ʹ�� \n
* @ref PLIB_ENABLE ʹ�� \n
* @ref PLIB_DISABLE ��ʹ�� \n
* @retval ��
* @par   ˵��
* ��
*/
void plib_mos_init(MOS_FCLK_E Fclk_div, U16 Period, U16 Duty, MOS_OCP_THD_E Ocp_Thd, FUNC_EN_E OcpEn, FUNC_EN_E OtpEn);

/**
* @brief  ����MOS������ʼ������
* @param  Exmos1 ��/��MOS����ͬ��ʹ��λ��ʹ���ⲿNMOSʱ����PLIB_ENABLE����ȷ���ⲿNMOS���ڲ�NMOS�ȵ�ͨ \n
* @ref PLIB_ENABLE ʹ�� \n
* @ref PLIB_DISABLE ��ʹ�� \n
* @param  Exmos2 ��/��MOS����ͬ������ʹ��λ����Exmos1=PLIB_ENABLEʱ��������Ч \n
* @ref PLIB_ENABLE ʹ�� \n
* @ref PLIB_DISABLE, ��ʹ�� \n
* @param  Speed1 ��/��MOS���ʹ�����/�½�б��1����Exmos1=PLIB_ENABLEʱ��������Ч \n
* @ref MOS_SPEED4 \n
* @ref MOS_SPEED3 \n
* @ref MOS_SPEED2 \n
* @ref MOS_SPEED1 \n
* @param  Speed2 ��/��MOS���ʹ�����/�½�б��2����Exmos1=PLIB_ENABLEʱ��������Ч \n
* @ref MOS_SPEED4 \n
* @ref MOS_SPEED3 \n
* @retval ��
* @par   ˵��
* -# ����˵������MOS��ָʹ��MOS_EXT�ܽ�����
*/
void plib_exmos_init(FUNC_EN_E Exmos1, FUNC_EN_E Exmos2, MOS_SPEED_E Speed1, MOS_SPEED_E Speed2);

/**
* @brief  MOS PWM���ʹ��
* @param  newstate �Ƿ�ʹ�� \n
* @ref PLIB_ENABLE ʹ�� \n
* @ref PLIB_DISABLE ��ʹ�� \n
* @retval ��
* @par   ˵��
* ��
*/
void plib_mos_en(FUNC_EN_E ifEn);

/**
* @brief  MOS PWMռ�ձ�����
* @param  duty ռ�ձ����ã�����ֵ=����*���ռ�ձ�
* @retval ��
* @par   ˵��
* ��
*/
void plib_mos_set_duty(U16 duty);

/**
* @brief  ��ȡMOS�¼�״̬
* @param  event MOS�ж��¼��� \n
* @ref MOS_TRIG_RISING  \n
* @ref MOS_TRIG_FALLING  \n
* @retval  �¼�����״̬
* - 0 δ������Ӧ״̬
* - ��0 �����˶�Ӧ״̬
* @par   ˵��
* ��
*/
U8 plib_mos_get_flg(U8 event);

/**
* @brief  ���MOS�¼�״̬
* @param  event MOS�ж��¼��� \n
* @ref MOS_TRIG_RISING  \n
* @ref MOS_TRIG_FALLING  \n
* @retval ��
* @par   ˵��
* ��
*/
void plib_mos_clr_flg(U8 event);

/**
* @brief  MOS�ж�ʹ��
* @param  event MOS�ж��¼��� \n
* @ref MOS_TRIG_RISING  \n
* @ref MOS_TRIG_FALLING  \n
* @param  newstate �Ƿ�ʹ�� \n
* @ref PLIB_ENABLE ʹ�� \n
* @ref PLIB_DISABLE ��ʹ�� \n
* @par   ˵��
* ��
*/
void plib_mos_it_cfg(U8 event, FUNC_EN_E ifEn);

/**
* @brief  MOS�ж��Ƿ�ʹ��
* @param  event MOS�ж��¼��� \n
* @ref MOS_TRIG_RISING  \n
* @ref MOS_TRIG_FALLING  \n
* @retval  �¼��ж�ʹ��״̬
* - 0 δʹ��
* - ��0 ��ʹ��
* @par ˵��
* ��
*/
U8 plib_mos_it_ifen(U8 event);

/**
* @brief  MOS���ж�ʹ��
* @param  newstate �Ƿ�ʹ�� \n
* @ref PLIB_ENABLE ʹ�� \n
* @ref PLIB_DISABLE ��ʹ�� \n
* @retval ��
* @par   ˵��
* -# MOS PWM����/�½��غ�PWM0/1����һ���ж�ʹ��
*/
void plib_mos_it_en(FUNC_EN_E ifEn);

/**
* @brief  ��ȡMOS�쳣�¼�״̬
* @param  event �쳣�ж��¼��� \n
* @ref MOS_OCP  \n
* @ref MOS_OTP  \n
* @retval  �¼�����״̬
* - 0 δ������Ӧ״̬
* - ��0 �����˶�Ӧ״̬
* @par   ˵��
* ��
*/
U8 plib_mos_get_abn_flg(U8 event);

/**
* @brief  ���MOS�쳣�¼�״̬
* @param  event �쳣�ж��¼��� \n
* @ref MOS_OCP  \n
* @ref MOS_OTP  \n
* @retval ��
* @par   ˵��
* ��
*/
void plib_mos_clr_abn_flg(U8 event);

/**
* @brief  MOS�쳣�ж�ʹ��
* @param  event �쳣�ж��¼��� \n
* @ref MOS_OCP  \n
* @ref MOS_OTP  \n
* @param  newstate �Ƿ�ʹ�� \n
* @ref PLIB_ENABLE ʹ�� \n
* @ref PLIB_DISABLE ��ʹ�� \n
* @par   ˵��
* ��
*/
void plib_mos_abn_it_cfg(U8 event, FUNC_EN_E ifEn);

/**
* @brief  MOS�쳣���ж�ʹ��
* @param  newstate �Ƿ�ʹ�� \n
* @ref PLIB_ENABLE ʹ�� \n
* @ref PLIB_DISABLE ��ʹ�� \n
* @retval ��
* @par   ˵��
* ��
*/
void plib_mos_abn_it_en(FUNC_EN_E ifEn);

/**
* @brief  ��⸺�ز��״̬
* @param  ��
* @retval ����״̬
* - 0 ����δ����
* - ��0 �����ѽ���
* @par   ˵��
* ��
*/
U8 plib_mos_get_plug_flg(void);

/**
* @brief  ��ȡOCP������MOS���״̬
* @param  ��
* @retval MOS����״̬
* - 0 δ����
* - ��0 ����OCP��������
* @par   ˵��
* -# ��MOS PWM����ҳ���OCP�쳣ʱ���ڲ�Ӳ���Զ����棬�ر�MOS PWM�����
* -# ���ٵȴ�1ms�󣬿�ͨ��plib_mos_ocp_unlock()������
* -# OCP�쳣�ѽ����MOS PWM��������������������λ��λ
*/
U8 plib_mos_get_ocp_lock(void);

/**
* @brief  OCP�쳣���������MOS���
* @param  ��
* @retval ��
* @par   ˵��
* -# OCP�쳣�ѽ����MOS PWM����������������������MOS
*/
void plib_mos_ocp_unlock(void);


#endif /* end of __PMCU_MOS_H_ */

