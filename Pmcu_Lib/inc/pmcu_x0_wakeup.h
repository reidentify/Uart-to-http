/**
 * @file
 * @brief		˯�߻�������
 * @author		admin
 * @date		2023.07.27
 * @version	    v1.0
 * @par 		Copyright(c): All rights reserved.
*/

#ifndef __PMCU_WAKEUP_H_
#define __PMCU_WAKEUP_H_

#include "pmcu_x0_config.h"

#define	WK_SRC_GPIO  		((U8)0x01)		/*!< GPIO���ػ���Դ */
#define	WK_SRC_PLUG  		((U8)0x02)		/*!< ���ذβ廽��Դ */
#define	WK_SRC_USB  		((U8)0x04)      /*!< USB�β廽��Դ */
#define	WK_SRC_CHG_FULL  	((U8)0x08)      /*!< ������份��Դ */
#define	WK_SRC_MIC  		((U8)0x10)      /*!< MIC�¼�����Դ */
#define	WK_SRC_TIMER  		((U8)0x80)      /*!< ��ʱ����Դ */

/**
* @brief  ϵͳ����˯��ģʽ
* @param  ��
* @retval ��
* @par    ˵��
* @par    ˵��
* -# Ϊ����˯��©�磬˯��ǰ��Ҫ������IO���ó��ڲ�����ģʽ��оƬ�ⲿ������ǰ���£�
*/
void plib_wk_sleep(void);

/**
* @brief  ����Դ����
* @param  Src ����Դʹ�ܣ�ѡ������һ�������� \n
* @ref WK_SRC_GPIO \n
* @ref WK_SRC_PLUG \n
* @ref WK_SRC_USB \n
* @ref WK_SRC_CHG_FULL \n
* @ref WK_SRC_MIC \n
* @ref WK_SRC_TIMER \n
* @param  Timer_cfg ʹ�ܶ�ʱ����ʱ�����ö�ʱʱ�����������ֵΪ127��ʱ��=����ֵ*7.76ms����ʹ��ʱ����Ϊ0
* @retval ��
* @par   ˵��
* -# ��ʹ��WK_SRC_TIMER����Դ����Ҫ����Timer_cfg����ʱ��
* -# ��ʹ��WK_SRC_MIC����Դ����Ҫ����plib_mic_it_cfg()���þ����MIC�����¼�
* -# ��ʹ��WK_SRC_GPIO����Դ����Ҫ����plib_gpio_it_cfg()���þ����ĸ�IO���ѣ�����Ҫ����plib_gpio_init()����IOΪ����ģʽ
*/
void plib_wk_init(U8 Src, U8 Timer_cfg);

#endif /* end of __PMCU_WAKEUP_H_ */

