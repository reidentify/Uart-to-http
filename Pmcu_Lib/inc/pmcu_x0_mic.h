/**
 * @file
 * @brief		MIC����
 * @author		admin
 * @date		2023.07.27
 * @version	    v1.1
 * @par 		Copyright(c): All rights reserved.
 * @par 		�޸ļ�¼
 * @par 		1.admin��2023-08-21���������װ��ʽ�����ٴ���ռ� 
*/

#ifndef __PMCU_MIC_H_
#define __PMCU_MIC_H_

#include "pmcu_x0_config.h"

#define MIC_ALL_ON						((U8)0xFF)      /*!< MIC�����¼� */
#define MIC_ABNORMAL 					((U8)0x80)		/*!< MIC�쳣�¼� */
#define MIC_SAMPLE 						((U8)0x40)		/*!< MIC�����¼� */
#define MIC_BLOW						((U8)0x20)      /*!< MIC�����¼� */
#define MIC_INHALE_TIMEOUT 				((U8)0x10)      /*!< MIC���̳�ʱ�¼� */
#define MIC_INHALE_RELEASE 				((U8)0x08)      /*!< MIC�����ͷ��¼� */
#define MIC_INHALE 						((U8)0x04)      /*!< MIC�����¼� */
#define MIC_REFLESH_VALUE 				((U8)0x02)      /*!< MIC���³�ֵ�¼� */
#define MIC_BLOW_RELEASE				((U8)0x01)      /*!< MIC�����ͷ��¼� */
#define MIC_ALL_OFF						((U8)0x00)      /*!< MIC�����¼��ر� */

#define MIC_CURR_160NA 					((U8)0x00)		/*!< ��ͷ��������160nA */
#define MIC_CURR_320NA 					((U8)0x08)		/*!< ��ͷ��������320nA */

#define MIC_SAMPLE_TIME_45MS 			((U8)0x00)		/*!< ��ͷ����ʱ�䣺45���� */
#define MIC_SAMPLE_TIME_35MS 			((U8)0x20)		/*!< ��ͷ����ʱ�䣺35���� */
#define MIC_SAMPLE_TIME_23MS 			((U8)0x40)		/*!< ��ͷ����ʱ�䣺23���� */
#define MIC_SAMPLE_TIME_57MS 			((U8)0x60)		/*!< ��ͷ����ʱ�䣺57���� */

/** ��ͷ���̳�ʱʱ�� */
typedef enum {
    MIC_TIMEOUT_2_5 = 0,	/*!< 2.5�� */
    MIC_TIMEOUT_5   = 1,	/*!< 5�� */
    MIC_TIMEOUT_10  = 2,	/*!< 10�� */
    MIC_TIMEOUT_20  = 3,	/*!< 20�� */
} MIC_TIMEOUT_E;

/**
* @brief  MIC��ʼ������
* @param  Event MIC�¼��������ж�ʹ�ܣ�ѡ�����²����� \n
* @ref MIC_ALL_ON \n
* @ref MIC_ABNORMAL \n
* @ref MIC_SAMPLE \n
* @ref MIC_BLOW \n
* @ref MIC_INHALE_TIMEOUT \n
* @ref MIC_INHALE_RELEASE \n
* @ref MIC_INHALE \n
* @ref MIC_REFLESH_VALUE \n
* @ref MIC_BLOW_RELEASE \n
* @ref MIC_ALL_OFF	    \n
* @param  Mic_Curr ��ͷ��������ѡ�� \n
* @ref MIC_CURR_160NA \n
* @ref MIC_CURR_320NA \n
* @param  Sample_Time ��ͷ����ʱ�䣬ѡ�� \n
* @ref MIC_SAMPLE_TIME_45MS \n
* @ref MIC_SAMPLE_TIME_35MS \n
* @ref MIC_SAMPLE_TIME_23MS \n
* @ref MIC_SAMPLE_TIME_57MS \n
* @param  Timeout ��ͷ������ʱʱ�䣬ѡ�� \n
* @ref MIC_TIMEOUT_2_5 \n
* @ref MIC_TIMEOUT_5 \n
* @ref MIC_TIMEOUT_10 \n
* @ref MIC_TIMEOUT_20 \n
* @retval ��
* @par    ˵��
* -# �޸�MIC����ʱ����Ҫ�ȹر�MICʹ��
* -# ��ʹ��˯�߻��ѵ�MIC�¼����ѣ�MIC_IntEn���ж�ʹ�ܣ�ͬʱ��Ϊ˯�߻����¼�
* -# ����MIC_BLOW�ʹ����ͷ�MIC_BLOW_RELEASE����һ���ж�ʹ�ܿ���
*/
void plib_mic_init(U8 Event, U8 Mic_Curr, U8 Sample_Time, MIC_TIMEOUT_E Timeout);

/**
* @brief  MIC��ʼ������
* @param  Trig1 MIC��һ��ֵ�����÷�Χ0~31�����̱���Ϊ������ֵ/1024
* @param  Trig2 MIC�ڶ���ֵ�����÷�Χ0~255�����̱���Ϊ������ֵ/1024
* @retval ��
* @par    ˵��
* ��
*/
void plib_mic_set_trig(U8 Trig1, U8 Trig2);

/**
* @brief  ʹ����ͷ����
* @param  ifEn �Ƿ�ʹ�� \n
* @ref PLIB_ENABLE ʹ�� \n
* @ref PLIB_DISABLE ��ʹ�� \n
* @retval ��
* @par    ˵��
* -# �޸�MIC����ʱ����Ҫ�ȹر�MICʹ��
* -# MICʹ�ܺ���Ҫ��ʱ300ms���ȴ�MIC�����ȶ�
*/
void plib_mic_en(FUNC_EN_E ifEn);

/**
* @brief  MIC�ж�����
* @param  Event MIC�¼��������ж�ʹ�ܣ�ѡ�����²����� \n
* @ref MIC_ALL_ON \n
* @ref MIC_ABNORMAL \n
* @ref MIC_SAMPLE \n
* @ref MIC_BLOW \n
* @ref MIC_INHALE_TIMEOUT \n
* @ref MIC_INHALE_RELEASE \n
* @ref MIC_INHALE \n
* @ref MIC_REFLESH_VALUE \n
* @ref MIC_BLOW_RELEASE \n
* @ref MIC_ALL_OFF	    \n
* @param  ifEn �Ƿ�ʹ�� \n
* @ref PLIB_ENABLE ʹ�� \n
* @ref PLIB_DISABLE ��ʹ�� \n
* @retval ��
* @par    ˵��
* -# ��ʹ��˯�߻��ѵ�MIC�¼����ѣ�MIC_IntEn���ж�ʹ�ܣ�ͬʱ��Ϊ˯�߻����¼�
* -# ����MIC_BLOW�ʹ����ͷ�MIC_BLOW_RELEASE����һ���ж�ʹ�ܿ���
*/
void plib_mic_it_cfg(U8 Event, FUNC_EN_E ifEn);

/**
* @brief  MIC�ж��Ƿ�ʹ��
* @param  Event MIC�¼��������ж�ʹ�ܣ�ѡ�����²����� \n
* @ref MIC_ALL_ON \n
* @ref MIC_ABNORMAL \n
* @ref MIC_SAMPLE \n
* @ref MIC_BLOW \n
* @ref MIC_INHALE_TIMEOUT \n
* @ref MIC_INHALE_RELEASE \n
* @ref MIC_INHALE \n
* @ref MIC_REFLESH_VALUE \n
* @ref MIC_BLOW_RELEASE \n
* @ref MIC_ALL_OFF	    \n
* @retval  �¼��ж�ʹ��״̬
* - 0 δʹ��
* - ��0 ��ʹ��
* @par ˵��
* ��
*/
U8 plib_mic_it_ifen(U8 Event);

/**
* @brief  MIC���ж�ʹ��
* @param  ifEn �Ƿ�ʹ�� \n
* @ref PLIB_ENABLE ʹ�� \n
* @ref PLIB_DISABLE ��ʹ�� \n
* @retval ��
* @par   ˵��
* ��
*/
void plib_mic_it_en(FUNC_EN_E ifEn);

/**
* @brief  ������ͷ��һ��ֵ
* @param  TrigValue MIC��һ��ֵ�����÷�Χ0~31�����̱���Ϊ������ֵ/1024
* @retval ��
* @par    ˵��
* -# �ýӿڽ���MICʹ��300ms�󣬵�����Ч
*/
void plib_mic_set_trig1(U8 TrigValue);

/**
* @brief  ��ȡ��ͷ��һ��ֵ
* @param  ��
* @retval ��ǰ���õ�MIC��һ��ֵ
* @par   ˵��
* ��
*/
U8 plib_mic_get_trig1(void);

/**
* @brief  ������ͷ�ڶ���ֵ
* @param  TrigValue MIC�ڶ���ֵ�����÷�Χ0~255�����̱���Ϊ������ֵ/1024
* @retval ��
* @par    ˵��
* -# �ýӿڽ���MICʹ��300ms�󣬵�����Ч
*/
void plib_mic_set_trig2(U8 TrigValue);

/**
* @brief  ��ȡ��ͷ�ڶ���ֵ
* @param  ��
* @retval ��ǰ���õ�MIC�ڶ���ֵ
* @par   ˵��
* ��
*/
U8 plib_mic_get_trig2(void);

/**
* @brief  ��ȡ��ͷ��ֵ
* @param  ��
* @retval ��ǰ��ͷ�ĳ�ֵ
* @par   ˵��
* ��
*/
U16 plib_mic_get_init_value(void);

/**
* @brief  ��ȡ��ͷʵʱ����ֵ
* @param  ��
* @retval ��ǰ��ͷ��ʵʱ����ֵ
* @par   ˵��
* ��
*/
U16 plib_mic_get_cur_value(void);

/**
* @brief  ��ȡMIC�¼�״̬
* @param  Event MIC�¼���ѡ�����²����� \n
* @ref MIC_ALL_ON \n
* @ref MIC_ABNORMAL \n
* @ref MIC_SAMPLE \n
* @ref MIC_BLOW \n
* @ref MIC_INHALE_TIMEOUT \n
* @ref MIC_INHALE_RELEASE \n
* @ref MIC_INHALE \n
* @ref MIC_REFLESH_VALUE \n
* @ref MIC_BLOW_RELEASE \n
* @ref MIC_ALL_OFF	    \n
* @retval  �¼�����״̬
* - 0 δ�������¼�
* - ��0 �Ѵ������¼�
* @par   ˵��
* ��
*/
U8 plib_mic_get_flg(U8 Event);

/**
* @brief  ���MIC�¼�״̬
* @param  Event MIC�¼���ѡ�����²����� \n
* @ref MIC_ALL_ON \n
* @ref MIC_ABNORMAL \n
* @ref MIC_SAMPLE \n
* @ref MIC_BLOW \n
* @ref MIC_INHALE_TIMEOUT \n
* @ref MIC_INHALE_RELEASE \n
* @ref MIC_INHALE \n
* @ref MIC_REFLESH_VALUE \n
* @ref MIC_BLOW_RELEASE \n
* @ref MIC_ALL_OFF	    \n
* @retval ��
* @par   ˵��
* ��
*/
void plib_mic_clr_flg(U8 Event);

/**
* @brief  ��������������̳�ֵ
* @param  ��
* @retval ��
* @par    ˵��
* -# �ýڿڿ���������ʱ�̣���������һ����ͷ���̳�ֵ
*/
void plib_mic_reflesh_ini_value();

#endif /* end of __PMCU_MIC_H_ */

