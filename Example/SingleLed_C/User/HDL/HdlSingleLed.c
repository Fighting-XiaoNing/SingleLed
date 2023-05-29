/**
 * @file      HdlSingleLed.c
 * @author    XiaoNing
 * @post      Embedded Software Engineer
 * @brief     ��LED
 * @version   1.0.0
 * @date      2023-05-29
 * @copyright Copyright (c) 2023
 */
#include "HdlSingleLed.h"
#include <reg52.h>

sbit LED1 = P1^0;

/**
 * @brief  LED��ʼ��
 * @param  None
 * @retval None
 */
void HDL_SingleLed_Init(void)
{
    LED1 = 0;
}

/**
 * @brief  ����LED
 * @param  None
 * @retval None
 */
void HDL_SingleLed_On(void)
{
    LED1 = 1;
}

/**
 * @brief  Ϩ��LED
 * @param  None
 * @retval None
 */
void HDL_SingleLed_Off(void)
{
    LED1 = 0;
}
