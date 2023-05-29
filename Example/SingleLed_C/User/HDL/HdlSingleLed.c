/**
 * @file      HdlSingleLed.c
 * @author    XiaoNing
 * @post      Embedded Software Engineer
 * @brief     单LED
 * @version   1.0.0
 * @date      2023-05-29
 * @copyright Copyright (c) 2023
 */
#include "HdlSingleLed.h"
#include <reg52.h>

sbit LED1 = P1^0;

/**
 * @brief  LED初始化
 * @param  None
 * @retval None
 */
void HDL_SingleLed_Init(void)
{
    LED1 = 0;
}

/**
 * @brief  点亮LED
 * @param  None
 * @retval None
 */
void HDL_SingleLed_On(void)
{
    LED1 = 1;
}

/**
 * @brief  熄灭LED
 * @param  None
 * @retval None
 */
void HDL_SingleLed_Off(void)
{
    LED1 = 0;
}
