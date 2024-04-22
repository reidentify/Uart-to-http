/**
 * @file
 * @brief		ϵͳ����
 * @author		admin
 * @date		2023.07.27
 * @version	    v1.0
 * @par 		Copyright(c): All rights reserved.
*/

#ifndef __PMCU_SYS_H_
#define __PMCU_SYS_H_

#include "pmcu_x0_config.h"

/** JTAG�ӿ�ѡ�� */
typedef enum {
    JTAG_SEL_DISABLE = 0,	/*!< ��ʹ�� */
    JTAG_SEL_GPIOA,			/*!< GPIOA����ΪJTAG���Կ� */
    JTAG_SEL_GPIOB,			/*!< GPIOB����ΪJTAG���Կ� */
} JTAG_SEL_E;


/**
* @brief  ϵͳʱ��ʹ��
* @param  ��
* @retval ��
* @par   ˵��
* -# оƬ����������ʹ��ϵͳʱ��
*/
void plib_sys_clk_en(void);
	
/**
* @brief  ϵͳ��λ
* @param  ��
* @retval ��
* @par   ˵��
* -# ���ú�ϵͳ��λ
*/
void plib_sys_reset(void);

/**
* @brief  ϵͳ���ж�ʹ��
* @param  ifEn �Ƿ�ʹ�� \n
* @ref PLIB_ENABLE ʹ�� \n
* @ref PLIB_DISABLE ��ʹ�� \n
* @retval ��
* @par   ˵��
* -# ʹ�ܺ�����ģ����жϲ��ܴ���
*/
void plib_sys_it_en(FUNC_EN_E ifEn);

/**
* @brief  JTAG���Խӿ�ѡ��
* @param  sel JTAG���Ժ��ܣ�ѡ�� \n
* @ref JTAG_SEL_DISABLE \n
* @ref JTAG_SEL_GPIOA	\n
* @ref JTAG_SEL_GPIOB	\n
* @retval ��
* @par   ˵��
* -# ʹ�ܺ�����ģ����жϲ��ܴ���
*/
void plib_sys_jtag_sel(JTAG_SEL_E sel);

#endif /* end of __PMCU_SYS_H_ */

