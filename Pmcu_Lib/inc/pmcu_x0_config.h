/**
 * @file
 * @brief		系统内核配置
 * @author		admin
 * @date		2023.07.27
 * @version	    v1.0
 * @par Copyright(c): All rights reserved.
*/

#ifndef __DRIVER_CONFIG_H_
#define __DRIVER_CONFIG_H_

#include <compiler_defs.h>

#define SYS_CLK			(16000000UL)					/*!< 系统时钟 */

/** GPIO电平 */
typedef enum {
    PLIB_LOW = 0, 					/*!< 低电平 */
    PLIB_HIGH = !PLIB_LOW			/*!< 高点平 */
} IO_LEVEL_E;

/** 使能标志 */
typedef enum {
    PLIB_DISABLE = 0, 				/*!< 不使能 */
    PLIB_ENABLE = !PLIB_DISABLE		/*!< 使能 */
} FUNC_EN_E;

#endif /* end of __DRIVER_CONFIG_H_ */
