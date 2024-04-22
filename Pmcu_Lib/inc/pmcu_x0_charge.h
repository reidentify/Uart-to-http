/**
 * @file
 * @brief		�������
 * @author		admin
 * @date		2023.07.27
 * @version	    v1.1
 * @par 		Copyright(c): All rights reserved.
 * @par 		�޸ļ�¼
 * @par 		1.admin��2023-09-06������plib_chg_ifen()�ӿڣ�����plib_chg_init()IBCEn��������
*/

#ifndef __PMCU_CHARGE_H_
#define __PMCU_CHARGE_H_

#include "pmcu_x0_config.h"

#define CHG_IEN_CHGST 		((U8)0x10)	/*!< ����жϣ���翪����ֹͣ */
#define CHG_IEN_USB 		((U8)0x08)	/*!< ����жϣ�USB�β� */

#define CHG_CHG_ST_IF 		((U8)0x04)	/*!< ����¼�����翪����ֹͣ */
#define CHG_USB_IN 			((U8)0x02)	/*!< ����¼���USB���� */
#define CHG_USB_OUT 		((U8)0x01)	/*!< ����¼���USB�γ� */

#define CHG_S_RECHARGE 		((U8)0x80)	/*!< ���״̬������ */
#define CHG_S_USBOVP 		((U8)0x40)	/*!< ���״̬��USB��ѹ */
#define CHG_S_USBUVP 		((U8)0x20)  /*!< ���״̬��USBǷѹ */
#define CHG_S_TC 			((U8)0x10)  /*!< ���״̬�������� */
#define CHG_S_CC 			((U8)0x08)  /*!< ���״̬��������� */
#define CHG_S_CV 			((U8)0x04)  /*!< ���״̬����ѹ��� */
#define CHG_S_FULL 			((U8)0x02)  /*!< ���״̬������ */
#define CHG_S_USB_IN 		((U8)0x01)  /*!< ���״̬��USB���� */

/** �������Ƿѹ������ѹ */
typedef enum {
    CHG_UVLS_2_3V = 0,		/*!< 2.3V */
    CHG_UVLS_2_4V,			/*!< 2.4V */
    CHG_UVLS_2_5V,			/*!< 2.5V */
    CHG_UVLS_2_6V,			/*!< 2.6V */
} VCC_UV_E;

/** ���������� */
typedef enum {
    CHG_ISET_250MA = 0,		/*!< 250mA */
    CHG_ISET_300MA,     	/*!< 300mA */
    CHG_ISET_350MA,     	/*!< 350mA */
    CHG_ISET_400MA,     	/*!< 400mA */
    CHG_ISET_450MA,     	/*!< 450mA */
    CHG_ISET_500MA,			/*!< 500mA */
    CHG_ISET_550MA,     	/*!< 550mA */
    CHG_ISET_600MA,     	/*!< 600mA */
    CHG_ISET_650MA,     	/*!< 650mA */
    CHG_ISET_700MA,     	/*!< 700mA */
    CHG_ISET_750MA,    		/*!< 750mA */
} CHG_ISET_E;

/** ����������� */
typedef enum {
    CHG_FULL_ISET_20 = 0,	/*!< ����������20% */
    CHG_FULL_ISET_10,		/*!< ����������10% */
} CHG_FULL_E;

/**
* @brief  ����ʼ������
* @param  IBCEn ��������ǰ���Ƿ��г���������\n
* @ref PLIB_ENABLE ʹ�ܣ��޳����� \n
* @ref PLIB_DISABLE ��ʹ�ܣ��г����� \n
* @param  CCCurrent ������������ѡ�� \n
*@ref CHG_ISET_250MA \n
*@ref CHG_ISET_300MA \n
*@ref CHG_ISET_350MA \n
*@ref CHG_ISET_400MA \n
*@ref CHG_ISET_450MA \n
*@ref CHG_ISET_500MA \n
*@ref CHG_ISET_550MA \n
*@ref CHG_ISET_600MA \n
*@ref CHG_ISET_650MA \n
*@ref CHG_ISET_700MA \n
*@ref CHG_ISET_750MA \n
* @param  FullCurrent ����������� \n
*@ref CHG_FULL_ISET_20 \n
*@ref CHG_FULL_ISET_10 \n
* @param  UVVoltage �������Ƿѹ������ѹ \n
*@ref CHG_UVLS_2_3V \n
*@ref CHG_UVLS_2_4V \n
*@ref CHG_UVLS_2_5V \n
*@ref CHG_UVLS_2_6V \n
* @par   ˵��
* ��
*/
void plib_chg_init(FUNC_EN_E IBCEn, CHG_ISET_E CCCurrent, CHG_FULL_E FullCurrent, VCC_UV_E UVVoltage);

/**
  * @brief  ���ʹ��
* @param  newstate �Ƿ�ʹ�� \n
* @ref PLIB_ENABLE ʹ�� \n
* @ref PLIB_DISABLE ��ʹ�� \n
* @retval ��
* @par   ˵��
* -# ����رճ��������½���USB�������������������¿������
*/
void plib_chg_en(FUNC_EN_E ifEn);

/**
* @brief  ����Ƿ�ʹ��
* @retval  ���ʹ��״̬
* - 0 δʹ��
* - ��0 ��ʹ��
* @par ˵��
* ��
*/
U8 plib_chg_ifen(void);
	
/**
* @brief  ���ú���������
* @param  Current ������������ѡ�� \n
* @ref CHG_ISET_250MA \n
* @ref CHG_ISET_300MA \n
* @ref CHG_ISET_350MA \n
* @ref CHG_ISET_400MA \n
* @ref CHG_ISET_450MA \n
* @ref CHG_ISET_500MA \n
* @ref CHG_ISET_550MA \n
* @ref CHG_ISET_600MA \n
* @ref CHG_ISET_650MA \n
* @ref CHG_ISET_700MA \n
* @ref CHG_ISET_750MA \n
* @par   ˵��
* -# ֧�ֳ��������޸ĳ�����
*/
void plib_chg_set_cc_current(CHG_ISET_E Current);

/**
* @brief  ����ж�ʹ��
* @param  event ����¼���ѡ������һ�������� \n
* @ref CHG_IEN_CHGST \n
* @ref CHG_IEN_USB	\n
* @param  newstate �Ƿ�ʹ�� \n
* @ref PLIB_ENABLE ʹ�� \n
* @ref PLIB_DISABLE ��ʹ�� \n
* @retval ��
* @par   ˵��
* ��
*/
void plib_chg_it_cfg(U8 event, FUNC_EN_E ifEn);

/**
* @brief  ����ж��Ƿ�ʹ��
* @param  event ����¼���ѡ������һ�������� \n
* @ref CHG_IEN_CHGST \n
* @ref CHG_IEN_USB	\n\n
* @retval  �¼��ж�ʹ��״̬
* - 0 δʹ��
* - ��0 ��ʹ��
* @par ˵��
* ��
*/
U8 plib_chg_it_ifen(U8 event);

/**
* @brief  ������ж�ʹ��
* @param  newstate �Ƿ�ʹ�� \n
* @ref PLIB_ENABLE ʹ�� \n
* @ref PLIB_DISABLE ��ʹ�� \n
* @retval ��
* @par   ˵��
* ��
*/
void plib_chg_it_en(FUNC_EN_E ifEn);

/**
* @brief  ��ȡ����¼�״̬
* @param  event ����¼���ѡ�� \n
* @ref CHG_CHG_ST_IF \n
* @ref CHG_USB_IN	\n
* @ref CHG_USB_OUT	\n
* @retval  �¼�����״̬
* - 0 �¼�δ����
* - ��0 �¼��Ѵ���
* @par   ˵��
* ��
*/
U8 plib_chg_get_flg(U8 event);

/**
* @brief  �������¼���־
* @param  event ����¼���ѡ�� \n
* @ref CHG_CHG_ST_IF \n
* @ref CHG_USB_IN	\n
* @ref CHG_USB_OUT	\n
* @retval ��
* @par   ˵��
* ��
*/
void plib_chg_clr_flg(U8 event);

/**
* @brief  ��ȡ��統ǰ״̬
* @param  flg ���״̬��ѡ�� \n
* @ref CHG_S_RECHARGE \n
* @ref CHG_S_USBOVP	\n
* @ref CHG_S_USBUVP	\n
* @ref CHG_S_TC \n
* @ref CHG_S_CC	\n
* @ref CHG_S_CV	\n
* @ref CHG_S_FULL \n
* @ref CHG_S_USB_IN	\n
* @retval ��統ǰ����״̬
* @par   ˵��
* ��
*/
U8 plib_chg_get_status(U8 flg);

#endif /* end of __PMCU_CHARGE_H_ */

