/**
 * @file
 * @brief		ADC����
 * @author		admin
 * @date		2023.07.27
 * @version	    v1.0
 * @par 		Copyright(c): All rights reserved.
*/

#ifndef __PMCU_ADC_H_
#define __PMCU_ADC_H_

#include "pmcu_x0_config.h"

#define ADC_CHN0_PGAOUT				((U8)0x01)  /* ADCͨ��0 PGA_OUT */
#define ADC_CHN1_VBAT				((U8)0x02)  /* ADCͨ��1 VBAT */
#define ADC_CHN2_VDD				((U8)0x04)  /* ADCͨ��2 VDD */
#define ADC_CHN3_GPIOB0				((U8)0x08)  /* ADCͨ��3 PBIT_GPIOB0 */
#define ADC_CHN4_GPIOB1				((U8)0x10)  /* ADCͨ��4 PBIT_GPIOB1 */
#define ADC_CHN5_GPIOB2				((U8)0x20)  /* ADCͨ��5 PBIT_GPIOB2 */
#define ADC_CHN_ALL					((U8)0x3F)  /* ADC����ͨ�� */

/** ADC������ */
typedef enum {
    ADC_SAMPLE_380K = 0,		/*!< 380K */
    ADC_SAMPLE_190K,			/*!< 190K */
    ADC_SAMPLE_95K,				/*!< 95K */
    ADC_SAMPLE_47K,				/*!< 47K */
} ADC_SAMPLE_RATE_E;

/** PGA ���� */
typedef enum {
    ADC_PGA_GAIN_16 = 0,		/*!< 16�� */
    ADC_PGA_GAIN_32,			/*!< 32�� */
} ADC_PGA_GAIN_E;

/** ADC����������ʽ */
typedef enum {
    ADC_MODE_SOFTWARE = 0,		/*!< ���������ÿʹ��һ��ͨ��������һ�β��� */
    ADC_MODE_PWM_TRIG,			/*!< �������������MOS PWM��������ش������� */
} ADC_SAMPLE_MODE_E;

/** ADCͨ��0 �������� */
typedef enum {
    ADC_PGA_SEL_BYPASS = 0,		/*!< PGA BYPASS������VOUT�����ѹʱʹ�� */
    ADC_PGA_SEL_x16,			/*!< PGA����16�������������迹ʹ�� */
    ADC_PGA_SEL_x32,			/*!< PGA����32�������������迹ʹ�� */
} ADC_PGA_SEL_E;

/**
* @brief  ADC��ʼ������
* @param  Sample_Rate ADC�����ʣ�ѡ�� \n
* @ref ADC_SAMPLE_380K \n
* @ref ADC_SAMPLE_190K \n
* @ref ADC_SAMPLE_95K \n
* @ref ADC_SAMPLE_47K \n
* @param  Pga_Gain ADC PGA���棬ѡ�� \n
* @ref ADC_PGA_GAIN_16 \n
* @ref ADC_PGA_GAIN_32 \n
* @param  Sample_Mode ADC����������ʽ��ѡ�� \n
* @ref ADC_MODE_SOFTWARE \n
* @ref ADC_MODE_PWM_TRIG \n
* @param  Pwm_Trig_Delay MOS PWM��������ʱ��MOS PWM�����ز�����ʱ���ã��������255��ʱ��=����ֵ*2/16000000
* @retval ��
* @par   ˵��
* ��
*/
void plib_adc_init(U8 Sample_Rate, ADC_PGA_GAIN_E Pga_Gain, ADC_SAMPLE_MODE_E Sample_Mode, U8 Pwm_Trig_Delay);

/**
* @brief  ADC��ʹ�ܿ���
* @param  newstate �Ƿ�ʹ�� \n
* @ref PLIB_ENABLE ʹ�� \n
* @ref PLIB_DISABLE ��ʹ�� \n
* @retval ��
* @par   ˵��
* ��
*/
void plib_adc_en(FUNC_EN_E ifEn);

/**
* @brief  ADCͨ��ʹ��
* @param  channel ADC����ͨ����ѡ������һ�������� \n
* @ref ADC_CHN0_PGAOUT \n
* @ref ADC_CHN1_VBAT \n
* @ref ADC_CHN2_VDD \n
* @ref ADC_CHN3_GPIOB0 \n
* @ref ADC_CHN4_GPIOB1 \n
* @ref ADC_CHN5_GPIOB2 \n
* @param  newstate �Ƿ�ʹ�� \n
* @ref PLIB_ENABLE ʹ�� \n
* @ref PLIB_DISABLE ��ʹ�� \n
* @retval ��
* @par   ˵��
* -# �����ȿ���ADC��ʹ�ܣ�ͨ��ʹ�ܲ���Ч
* -# ʹ�������������ʱ��ÿ�β���������Ӳ�����Զ����ͨ��ʹ�ܣ������β�����������������Ҫ�ٴο���ͨ��ʹ��
* -# ʹ��MOS PWM��������ʱ������Ҫʹ��һ��ADCͨ��ʹ��
*/
void plib_adc_chn_en(U8 channel, FUNC_EN_E ifEn);

/**
* @brief  ADCͨ���ж�ʹ��
* @param  channel ADC����ͨ����ѡ������һ������: \n
* @ref ADC_CHN0_PGAOUT \n
* @ref ADC_CHN1_VBAT	\n
* @ref ADC_CHN2_VDD	\n
* @ref ADC_CHN3_GPIOB0	\n
* @ref ADC_CHN4_GPIOB1	\n
* @ref ADC_CHN5_GPIOB2	\n
* @param  newstate �Ƿ�ʹ�� \n
* @ref PLIB_ENABLE ʹ�� \n
* @ref PLIB_DISABLE ��ʹ�� \n
* @retval ��
* @par   ˵��
* -# ADC�Ĳ������̶������ȼ�˳��ִ�У�ͨ��0���ȼ���ߣ�ͨ��6��ͣ���������ͨ��ADC����ʱ������н���ȴ����ȼ���͵�ͨ��������ɣ��ٽ������ݴ���
*/
void plib_adc_it_cfg(U8 channel, FUNC_EN_E ifEn);

/**
* @brief  ADC�ж��Ƿ�ʹ��
* @param  channel ADC����ͨ����ѡ������һ�������� \n
* @ref ADC_CHN0_PGAOUT \n
* @ref ADC_CHN1_VBAT	\n
* @ref ADC_CHN2_VDD	\n
* @ref ADC_CHN3_GPIOB0	\n
* @ref ADC_CHN4_GPIOB1	\n
* @ref ADC_CHN5_GPIOB2	\n
* @ref ADC_CHN_ALL	\n
* @retval  �¼��ж�ʹ��״̬
* - 0 δʹ��
* - ��0 ��ʹ��
* @par ˵��
* ��
*/
U8 plib_adc_it_ifen(U8 channel);

/**
* @brief  ADC MOS PWM��������ʹ��
* @param  newstate �Ƿ�ʹ�� \n
* @ref PLIB_ENABLE ʹ�� \n
* @ref PLIB_DISABLE ��ʹ�� \n
* @retval ��
* @par   ˵��
* ��
*/
void plib_adc_pwm_trig_en(FUNC_EN_E ifEn);

/**
* @brief  ADC���ж�ʹ��
* @param  newstate �Ƿ�ʹ�� \n
* @ref PLIB_ENABLE ʹ�� \n
* @ref PLIB_DISABLE ��ʹ�� \n
* @retval ��
* @par   ˵��
* ��
*/
void plib_adc_it_en(FUNC_EN_E ifEn);

/**
* @brief  ��ȡADC����״̬
* @param  channel ADC����ͨ����ѡ��: \n
* @ref ADC_CHN0_PGAOUT \n
* @ref ADC_CHN1_VBAT	\n
* @ref ADC_CHN2_VDD	\n
* @ref ADC_CHN3_GPIOB0	\n
* @ref ADC_CHN4_GPIOB1	\n
* @ref ADC_CHN5_GPIOB2	\n
* @ref ADC_CHN_ALL	\n
* @retval  ADC�������״̬
* - 0 ����δ���
* - ��0 ���������
* @par   ˵��
* -# ADC�Ĳ������̶������ȼ�˳��ִ�У�ͨ��0���ȼ���ߣ�ͨ��6��ͣ���������ͨ��ADC����ʱ������н���ȴ����ȼ���͵�ͨ��������ɣ��ٽ������ݴ���
*/
U8 plib_adc_get_flg(U8 channel);

/**
* @brief  ���ADCͨ����־
* @param  channel ADC����ͨ����ѡ�� \n
* @ref ADC_CHN0_PGAOUT \n
* @ref ADC_CHN1_VBAT	\n
* @ref ADC_CHN2_VDD	\n
* @ref ADC_CHN3_GPIOB0	\n
* @ref ADC_CHN4_GPIOB1	\n
* @ref ADC_CHN5_GPIOB2	\n
* @retval ��
* @par   ˵��
* ��
*/
void plib_adc_clr_flg(U8 channel);

/**
* @brief  ADC��ȡͨ���������
* @param  channel ADC����ͨ����ѡ�� \n
* @ref ADC_CHN0_PGAOUT \n
* @ref ADC_CHN1_VBAT	\n
* @ref ADC_CHN2_VDD	\n
* @ref ADC_CHN3_GPIOB0	\n
* @ref ADC_CHN4_GPIOB1	\n
* @ref ADC_CHN5_GPIOB2	\n
* @retval ʮ�����ƵĲ������
* @par   ˵��
* ��
*/
U16 plib_adc_get_ad_value(U8 channel);

/**
* @brief  ADCͨ��0����������ģʽ����
* @param  pgasel ����ģʽ��ѡ�� \n
* @ref ADC_PGA_SEL_BYPASS PGA BYPASS������VOUT�����ѹʱʹ�� \n
* @ref ADC_PGA_SEL_x16	PGA����16�������������迹ʹ�� \n
* @ref ADC_PGA_SEL_x32	PGA����32�������������迹ʹ�� \n
* @retval ��
* @par   ˵��
* -# ���������迹ʱ��оƬ��VOUT�ܽŷų�50mA����
*/
void plib_adc_pga_sel(ADC_PGA_SEL_E pgasel);

/**
* @brief  ADCͨ���������ת���ɵ�ѹ
* @param  advalue ADC�������ADֵ
* @retval ת����ĵ�ѹ����λmV
* @par   ˵��
* -# ADC_CHN0_PGAOUT�����������迹��/ADC_CHN1_VBAT/ADC_CHN2_VDD/ADC_CHN3_GPIOB0/ADC_CHN4_GPIOB1/ADC_CHN5_GPIOB2��ʹ�ô�ת���ӿ�
*/
U32 plib_adc_get_volt_div2(U16 advalue);

/**
* @brief  ADCͨ���������ת���ɵ�ѹ
* @param  advalue ADC�������ADֵ
* @retval ת����ĵ�ѹ����λmV
* @par   ˵��
* -# ADC_CHN0_PGAOUT������VOUT�����ѹ��ʹ�ô�ת���ӿ�
*/
U32 plib_adc_get_volt_div4(U16 advalue);

#endif /* end of __PMCU_ADC_H_ */
