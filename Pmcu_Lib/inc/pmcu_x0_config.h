/**
 * @file
 * @brief		ϵͳ�ں�����
 * @author		admin
 * @date		2023.07.27
 * @version	    v1.0
 * @par Copyright(c): All rights reserved.
*/

#ifndef __DRIVER_CONFIG_H_
#define __DRIVER_CONFIG_H_

#include <compiler_defs.h>

#define SYS_CLK			(16000000UL)					/*!< ϵͳʱ�� */

/** GPIO��ƽ */
typedef enum {
    PLIB_LOW = 0, 					/*!< �͵�ƽ */
    PLIB_HIGH = !PLIB_LOW			/*!< �ߵ�ƽ */
} IO_LEVEL_E;

/** ʹ�ܱ�־ */
typedef enum {
    PLIB_DISABLE = 0, 				/*!< ��ʹ�� */
    PLIB_ENABLE = !PLIB_DISABLE		/*!< ʹ�� */
} FUNC_EN_E;

#endif /* end of __DRIVER_CONFIG_H_ */
