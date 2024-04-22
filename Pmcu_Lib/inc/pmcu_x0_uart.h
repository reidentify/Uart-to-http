/**
 * @file
 * @brief		��������
 * @author		admin
 * @date		2023.07.27
 * @version	    v1.0
 * @par 		Copyright(c): All rights reserved.
*/

#ifndef __PMCU_UART_H_
#define __PMCU_UART_H_

#include "pmcu_x0_config.h"

#define UART_S1RI 							((U8)0x01)	/*!< ���ڽ��ձ�־λ */
#define UART_S1TI 							((U8)0x02)	/*!< ���ڷ��ͱ�־λ */

//�������ݳ���
#define UART_WordLength_8b                  ((U8)0x80)	/*!< ����8bit����ģʽ */
#define UART_WordLength_9b                  ((U8)0x00)	/*!< ����9bit����ģʽ */

//�����շ�ģʽ
#define UART_Mode_FullDuplex                ((U8)0x00)	/*!< ����ȫ˫��ģʽ��TX������GPIOC0��RX������GPIOC1 */
#define UART_Mode_HalfDuplex                ((U8)0x40)	/*!< ���ڰ�˫��ģʽ��ʹ��GPIOC0�ܽ� */

//���ڽ���ʹ��
#define UART_RxEnable                		((U8)0x10)	/*!< ���ڽ���ʹ�� */
#define UART_RxDisable                		((U8)0x00)	/*!< ���ڽ��ղ�ʹ�� */

/**
* @brief  ���ڳ�ʼ������
* @param  WordLength ��������λ��ѡ�� \n
* @ref UART_WordLength_8b \n
* @ref UART_WordLength_9b \n
* @param  BaudRate ���ڲ����ʣ���Χ��2400~115200
* @param  Mode ���ڹ���ģʽ��ѡ�� \n
* @ref UART_Mode_FullDuplex \n
* @ref UART_Mode_HalfDuplex \n
* @param  RxEn ���ڽ���ʹ�� \n
* @ref PLIB_ENABLE ʹ�� \n
* @ref PLIB_DISABLE ��ʹ�� \n
* @param  ITEn �����ж�ʹ�� \n
* @ref PLIB_ENABLE ʹ�� \n
* @ref PLIB_DISABLE ��ʹ�� \n
* @retval ��
* @par   ˵��
* ��
*/
void plib_uart_init(U8 WordLength, U32 BaudRate, U8 Mode, FUNC_EN_E RxEn, FUNC_EN_E ITEn);

/**
* @brief  UART����ʹ��
* @param  newstate �Ƿ�ʹ�� \n
* @ref PLIB_ENABLE ʹ�� \n
* @ref PLIB_DISABLE ��ʹ�� \n
* @retval ��
* @par    ˵��
* -# UART�����ڰ�˫��ʱ����Ҫʹ�ô˽ӿ��л����ڵ��շ�״̬
*/
void plib_uart_rx_en(FUNC_EN_E ifEn);

/**
* @brief  UART�ж�ʹ��
* @param  newstate �Ƿ�ʹ�� \n
* @ref PLIB_ENABLE ʹ�� \n
* @ref PLIB_DISABLE ��ʹ�� \n
* @retval ��
* @par    ˵��
* ��
*/
void plib_uart_it_en(FUNC_EN_E ifEn);

/**
* @brief  ��ȡ����״̬
* @param  ���ڽṹ�������ַ
* @param  Flg ���ڱ�־λ��ѡ�� \n
* @ref UART_S1RI \n
* @ref UART_S1TI \n
* @retval  ����״̬
* - 0 �޶�Ӧ״̬����
* - ��0 ��Ӧ״̬������
* @par   ˵��
* ��
*/
U8 plib_uart_get_flg(U8 Flg);

/**
* @brief  �������״̬
* @param  Flg ���ڱ�־λ��ѡ�� \n
* @ref UART_S1RI \n
* @ref UART_S1TI \n
* @retval ��
* @par   ˵��
* ��
*/
void plib_uart_clr_flg(U8 Flg);

/**
* @brief  ���͵��ֽ�����
* @param  value Ҫ���͵��ֽ�
* @retval ��
* @par   ˵��
* ��
*/
void plib_uart_send_byte(U8 value);

/**
* @brief  ��ȡ���ֽ�����
* @param  ��
* @retval ��ȡ�����ֽ�����
* @par   ˵��
* ��
*/
U8 plib_uart_get_byte();

/**
* @brief  ��ȡ�����Ƿ�æ״̬
* @param  ��
* @retval  ���ڹ���״̬
* - 0 ���ڿ���
* - ��0 ����æ
* @par   ˵��
* ��
*/
U8 plib_uart_is_busy();


#endif /* end of __PMCU_UART_H_ */
