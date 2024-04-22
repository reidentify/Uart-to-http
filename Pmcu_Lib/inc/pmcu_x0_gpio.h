/**
 * @file
 * @brief		GPIO����
 * @author		admin
 * @date		2023.07.27
 * @version	    v1.1
 * @par 		Copyright(c): All rights reserved.
 * @par 		1.admin��2023-08-21������plib_gpio_init()�ӿڣ�GPIOC0/GPIOC1�ڲ�����/���������෴���� 
 * @par 		2.admin��2023-09-07�����ӽӿ�plib_gpio_mode() 
*/

#ifndef __PMCU_GPIO_H_
#define __PMCU_GPIO_H_

#include "pmcu_x0_config.h"

#define	GPIO_GroupA  	((U8)0x01)		/*!< GPIOA�� */
#define	GPIO_GroupB  	((U8)0x02)		/*!< GPIOB�� */
#define	GPIO_GroupC  	((U8)0x04)		/*!< GPIOC�� */

#define	GPIO_Pin_0  		((U8)0x01)		/*!< GPIO PIN0 */
#define	GPIO_Pin_1  		((U8)0x02)      /*!< GPIO PIN1 */
#define	GPIO_Pin_2  		((U8)0x04)      /*!< GPIO PIN2 */
#define	GPIO_Pin_3  		((U8)0x08)      /*!< GPIO PIN3 */
#define	GPIO_Pin_All  		((U8)0x0F)      /*!< GPIO ����PIN */

#define	GPIO_LED_0  		((U8)0x01)		/*!< LED PIN0 */
#define	GPIO_LED_1  		((U8)0x02)		/*!< LED PIN1 */
#define	GPIO_LED_2  		((U8)0x04)		/*!< LED PIN2 */
#define	GPIO_LED_All  		((U8)0x07)		/*!< LED ����PIN */

#define	GPIO_LED_4MA  		((U8)0x00) 		/*!< LED ��������4mA */
#define	GPIO_LED_8MA  		((U8)0x08)		/*!< LED ��������8mA */
#define	GPIO_LED_21MA  		((U8)0x10)		/*!< LED ��������21mA */
#define	GPIO_LED_29MA  		((U8)0x18)		/*!< LED ��������29mA */

/** GPIO�������ģʽ */
typedef enum {
    GPIO_IOMode_FLOATING = 0,			/*!< ���գ��������ʹ�ܾ��ر� */
    GPIO_IOMode_IN_FLOATING = 1,		/*!< �������� */
    GPIO_IOMode_Out_PP = 2,				/*!< PP��� */
    GPIO_IOMode_Out_OD = 3,				/*!< OD��� */
} GPIO_IOMode_E;

/** GPIO�ڲ�������ģʽ */
typedef enum {
    GPIO_PUPDMode_None = 0,				/*!< �������� */
    GPIO_PUPDMode_PD = 1,				/*!< �ڲ������� */
    GPIO_PUPDMode_PU = 2,				/*!< �ڲ������� */
} GPIO_PDPUMode_E;

/** GPIO PP����������� */
typedef enum {
    GPIO_Driver_Weak = 0,				/*!< ���� */
    GPIO_Driver_Strength = 1,			/*!< ǿ�� */
} GPIO_DRIVER_E;

/** GPIO�������� */
typedef enum {
    GPIO_PinMux_IO = 0,					/*!< IO */
    GPIO_PinMux_PWM0_0,                 /*!< PWM0��0ͨ�� */
    GPIO_PinMux_PWM0_1,                 /*!< PWM0��1ͨ�� */
    GPIO_PinMux_PWM0_2,                 /*!< PWM0��2ͨ�� */
    GPIO_PinMux_PWM1_0,	                /*!< PWM1��0ͨ�� */
    GPIO_PinMux_PWM1_1,	                /*!< PWM1��1ͨ�� */
    GPIO_PinMux_PWM1_2,		            /*!< PWM1��2ͨ�� */
    GPIO_PinMux_ADC,                    /*!< ADC���� */
    GPIO_PinMux_UART,                   /*!< UARTͨѶ�ӿ� */
    GPIO_PinMux_LED,	                /*!< LED������� */
} GPIO_PINMUX_E;

/**
* @brief  GPIO��ʼ������
* @param  Gpiox GPIO��ţ�ѡ�� \n
* @ref GPIO_GroupA \n
* @ref GPIO_GroupB \n
* @ref GPIO_GroupC \n
* @param  Pinx GPIO���źţ�ѡ�� \n
* @ref GPIO_Pin_0 \n
* @ref GPIO_Pin_1 \n
* @ref GPIO_Pin_2 \n
* @ref GPIO_Pin_3 \n
* @ref GPIO_Pin_All \n
* @param  PinmuxMode GPIO����ģʽ��ѡ�� \n
* @ref GPIO_PinMux_IO \n
* @ref GPIO_PinMux_PWM0_0 \n
* @ref GPIO_PinMux_PWM0_1 \n
* @ref GPIO_PinMux_PWM0_2 \n
* @ref GPIO_PinMux_PWM1_0 \n
* @ref GPIO_PinMux_PWM1_1 \n
* @ref GPIO_PinMux_PWM1_2 \n
* @ref GPIO_PinMux_ADC    \n
* @ref GPIO_PinMux_UART   \n
* @ref GPIO_PinMux_LED    \n
* @param  IOMode GPIO�������ģʽ��ѡ�� \n
* @ref GPIO_IOMode_FLOATING    \n
* @ref GPIO_IOMode_IN_FLOATING   \n
* @ref GPIO_IOMode_Out_PP    \n
* @ref GPIO_IOMode_Out_OD    \n
* @param  PUPDMode GPIO�ڲ�������ģʽ��ѡ�� \n
* @ref GPIO_PUPDMode_None \n
* @ref GPIO_PUPDMode_PD \n
* @ref GPIO_PUPDMode_PU \n
* @param  PPDriver PP���ʱ��GPIO����������ѡ�� \n
* @ref GPIO_Driver_Weak \n
* @ref GPIO_Driver_Strength \n
* @retval ��
* @par   ˵��
* ��
* @par �޸ļ�¼
* -# admin��2023-08-21������GPIOC0/GPIOC1�ڲ�����/���������෴����
*/
void plib_gpio_init(U8 Gpiox, U8 Pinx, GPIO_PINMUX_E PinmuxMode, GPIO_IOMode_E IOMode, GPIO_PDPUMode_E PUPDMode, GPIO_DRIVER_E PPDriver);

/**
* @brief  GPIO���ģʽ���ú���
* @param  Gpiox GPIO��ţ�ѡ�� \n
* @ref GPIO_GroupA \n
* @ref GPIO_GroupB \n
* @ref GPIO_GroupC \n
* @param  Pinx GPIO���źţ�ѡ�� \n
* @ref GPIO_Pin_0 \n
* @ref GPIO_Pin_1 \n
* @ref GPIO_Pin_2 \n
* @ref GPIO_Pin_3 \n
* @ref GPIO_Pin_All \n
* @param  IOMode GPIO�������ģʽ��ѡ�� \n
* @ref GPIO_IOMode_FLOATING    \n
* @ref GPIO_IOMode_IN_FLOATING   \n
* @ref GPIO_IOMode_Out_PP    \n
* @ref GPIO_IOMode_Out_OD    \n
* @retval ��
* @par   ˵��
* ��
* @par �޸ļ�¼
* -# admin��2023-09-07������
*/
void plib_gpio_mode(U8 Gpiox, U8 Pinx, GPIO_IOMode_E IOMode); 
	
/**
* @brief  GPIO���ʹ��
* @param  Gpiox GPIO��ţ�ѡ�� \n
* @ref GPIO_GroupA \n
* @ref GPIO_GroupB \n
* @ref GPIO_GroupC \n
* @param  Pinx GPIO���źţ�ѡ�� \n
* @ref GPIO_Pin_0 \n
* @ref GPIO_Pin_1 \n
* @ref GPIO_Pin_2 \n
* @ref GPIO_Pin_3 \n
* @ref GPIO_Pin_All \n
* @param  ifEn �Ƿ�ʹ�� \n
* @ref PLIB_ENABLE ʹ�� \n
* @ref PLIB_DISABLE ��ʹ�� \n
* @retval ��
* @par   ˵��
* ��
*/
void plib_gpio_output_en(U8 Gpiox, U8 Pinx, FUNC_EN_E ifEn);

/**
* @brief  GPIO����ʹ��
* @param  Gpiox GPIO��ţ�ѡ�� \n
* @ref GPIO_GroupA \n
* @ref GPIO_GroupB \n
* @ref GPIO_GroupC \n
* @param  Pinx GPIO���źţ�ѡ�� \n
* @ref GPIO_Pin_0 \n
* @ref GPIO_Pin_1 \n
* @ref GPIO_Pin_2 \n
* @ref GPIO_Pin_3 \n
* @ref GPIO_Pin_All \n
* @param  ifEn �Ƿ�ʹ�� \n
* @ref PLIB_ENABLE ʹ�� \n
* @ref PLIB_DISABLE ��ʹ�� \n
* @retval ��
* @par   ˵��
* ��
*/
void plib_gpio_input_en(U8 Gpiox, U8 Pinx, FUNC_EN_E ifEn);

/**
* @brief  GPIO����ߵ�ƽ
* @param  Gpiox GPIO��ţ�ѡ�� \n
* @ref GPIO_GroupA \n
* @ref GPIO_GroupB \n
* @ref GPIO_GroupC \n
* @param  Pinx GPIO���źţ�ѡ�� \n
* @ref GPIO_Pin_0 \n
* @ref GPIO_Pin_1 \n
* @ref GPIO_Pin_2 \n
* @ref GPIO_Pin_3 \n
* @ref GPIO_Pin_All \n
* @param  level �����ƽ \n
* @ref PLIB_HIGH �ߵ�ƽ \n
* @ref PLIB_LOW �͵�ƽ \n
* @retval ��
* @par   ˵��
* ��
*/
void plib_gpio_set_value(U8 GPIOx, U8 Pinx, IO_LEVEL_E level);

/**
  * @brief  GPIO��ȡ�����ƽ
* @param  Gpiox GPIO��ţ�ѡ�� \n
* @ref GPIO_GroupA \n
* @ref GPIO_GroupB \n
* @ref GPIO_GroupC \n
* @param  Pinx GPIO���źţ�ѡ�� \n
* @ref GPIO_Pin_0 \n
* @ref GPIO_Pin_1 \n
* @ref GPIO_Pin_2 \n
* @ref GPIO_Pin_3 \n
* @ref GPIO_Pin_All \n
* @retval  �¼�����״̬
* - PLIB_LOW �͵�ƽ
* - PLIB_HIGH �ߵ�ƽ
* @par   ˵��
* ��
*/
U8 plib_gpio_get_value(U8 GPIOx, U8 Pinx);

/**
* @brief  GPIO �����ж�
* @param  Gpiox GPIO��ţ�ѡ�� \n
* @ref GPIO_GroupA \n
* @ref GPIO_GroupB \n
* @ref GPIO_GroupC \n
* @param  Pinx GPIO���źţ�ѡ�� \n
* @ref GPIO_Pin_0 \n
* @ref GPIO_Pin_1 \n
* @ref GPIO_Pin_2 \n
* @ref GPIO_Pin_3 \n
* @ref GPIO_Pin_All \n
* @param  ifEn �Ƿ�ʹ�� \n
* @ref PLIB_ENABLE ʹ�� \n
* @ref PLIB_DISABLE ��ʹ�� \n
* @retval ��
* @par    ˵��
* -# ��ʹ��˯�߻��ѵ�GPIO�¼����ѣ����ж�ʹ�����ã�ͬʱ��Ϊ˯�߻����¼�
*/
void plib_gpio_it_cfg(U8 Gpiox, U8 Pinx, FUNC_EN_E ifEn);

/**
* @brief  GPIO ���ж�ʹ��
* @param  ifEn �Ƿ�ʹ�� \n
* @ref PLIB_ENABLE ʹ�� \n
* @ref PLIB_DISABLE ��ʹ�� \n
* @retval ��
* @par   ˵��
* ��
*/
void plib_gpio_it_en(FUNC_EN_E ifEn);

/**
* @brief  GPIOA1/GPIOA2/GPIOA3 ����LEDʱ�ģ�������������
* @param  LEDCurr LED����������λ��ѡ�� \n
* @ref GPIO_LED_4MA \n
* @ref GPIO_LED_8MA \n
* @ref GPIO_LED_21MA \n
* @ref GPIO_LED_29MA \n
* @retval ��
* @par   ˵��
* ��
*/
void plib_gpio_set_led_curr(U8 LEDCurr);

/**
* @brief  LED���ʹ��
* @param  LED_Numbe LED�� \n
* @ref GPIO_LED_0 \n
* @ref GPIO_LED_1 \n
* @ref GPIO_LED_2 \n
* @ref GPIO_LED_All \n
* @param  ifEn �Ƿ�ʹ�� \n
* @ref PLIB_ENABLE ʹ�� \n
* @ref PLIB_DISABLE ��ʹ�� \n
* @retval ��
* @par   ˵��
* ��
*/
void plib_gpio_led_output_en(U8 LED_Number, FUNC_EN_E ifEn);

#endif /* end of __PMCU_GPIO_H_ */

