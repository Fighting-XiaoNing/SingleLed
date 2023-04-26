/**
 * @file      HdlSingleLed.c
 * @author    XiaoNing
 * @post      Embedded Software Engineer
 * @brief     µ¥LED
 * @version   1.0.0
 * @date      2023-04-26
 * @copyright Copyright (c) 2023
 */
#include "HdlSingleLed.h"
#include <reg52.h>

sbit LED1 = P1^0;

static void HDL_SingleLed_Init(void);
static void HDL_SingleLed_On(void);
static void HDL_SingleLed_Off(void);
static void HDL_SingleLed_Toggle(void);

const HdlSingleLed_TypeDef hdlSingleLed = {
    HDL_SingleLed_Init,
    HDL_SingleLed_On,
    HDL_SingleLed_Off,
    HDL_SingleLed_Toggle,
};

/**
 * @brief  LED³õÊ¼»¯
 * @param  None
 * @retval None
 */
static void HDL_SingleLed_Init(void)
{
    LED1 = 0;
}

/**
 * @brief  µãÁÁLED
 * @param  None
 * @retval None
 */
static void HDL_SingleLed_On(void)
{
    LED1 = 1;
}

/**
 * @brief  Ï¨ÃðLED
 * @param  None
 * @retval None
 */
static void HDL_SingleLed_Off(void)
{
    LED1 = 0;
}

/**
 * @brief  ÇÐ»»LED×´Ì¬
 * @param  None
 * @retval None
 */
static void HDL_SingleLed_Toggle(void)
{
    LED1 = LED1 ^ 0x01;
}
