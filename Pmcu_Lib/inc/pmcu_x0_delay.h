/**
 * @file
 * @brief		��ʱ��������
 * @author		admin
 * @date		2023.07.27
 * @version	    v1.0
 * @par 		Copyright(c): All rights reserved.
*/

#ifndef __PMCU_DELAY_H_
#define __PMCU_DELAY_H_

#include "pmcu_x0_config.h"

/**
* @brief ��ʱxms����
* @param ms ��ʱnms
* @retval ��
* @par   ˵��
* -# ms��ʱ��������������ֵΪ��ʱ����ms���������65535
*/
void delay_ms(U16 ms);

/**
* @brief ��ʱx10us����
* @param us ��ʱ(n *10) us
* @retval ��
* @par   ˵��
* -# us��ʱ��������������ֵΪ��ʱ���ٸ�10us���������65535
*/
void delay10us(U16 us);

#endif /* end of __PMCU_DELAY_H_ */
