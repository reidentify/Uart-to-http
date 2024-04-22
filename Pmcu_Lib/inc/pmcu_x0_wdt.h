/**
 * @file
 * @brief		���Ź�����
 * @author		admin
 * @date		2023.07.27
 * @version	    v1.0
 * @par 		Copyright(c): All rights reserved.
*/

#ifndef __PMCU_WDT_H_
#define __PMCU_WDT_H_

#include "pmcu_x0_config.h"

/**
* @brief  ���Ź����ʱ������
* @param  Tim_ms ���Ź����ʱ�䣬��λms�����ֵ����1500
* @retval ��
* @par   ˵��
* ��
*/
void plib_wdt_set_time(U16 Tim_ms);

/**
* @brief  ���Ź�����
* @param  ��
* @retval ��
* @par   ˵��
* ��
*/
void plib_wdt_open(void);

/**
* @brief  ���Ź��Ƿ���
* @param  ��
* @retval  ���Ź�״̬
* - 0 ���Ź�δ����
* - ��0 ���Ź��ѿ���
* @par   ˵��
* ��
*/
U8 plib_wdt_if_open(void);

/**
* @brief  ���Ź��ر�
* @param  ��
* @retval ��
* @par   ˵��
* ��
*/
void plib_wdt_close(void);

/**
* @brief  ���Ź�ι��
* @param  ��
* @retval ��
* @par   ˵��
* ��
*/
void plib_wdt_reflesh(void);

#endif /* end of __PMCU_WDT_H_ */

