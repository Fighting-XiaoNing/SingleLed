/**
 * @file      FmlSingleLed.c
 * @author    XiaoNing
 * @post      Embedded Software Engineer
 * @brief     单LED
 * @version   1.0.0
 * @date      2023-05-29
 * @copyright Copyright (c) 2023
 */
#include "FmlSingleLed.h"
#include "HdlSingleLed.h"

static volatile bool gLedStatus = false;
static volatile uint8_t gLedCompare = 0;                                        // 比较值

/**
 * @brief  LED初始化
 * @param  None
 * @retval None
 */
void FML_SingleLed_Init(void)
{
    HDL_SingleLed_Init();                                                       // 初始化LED
}

/**
 * @brief  启动LED
 * @param  None
 * @retval None
 */
void FML_SingleLed_Open(void)
{
    gLedStatus = true;
}

/**
 * @brief  关闭LED
 * @param  None
 * @retval None
 */
void FML_SingleLed_Close(void)
{
    gLedStatus = false;                                                         // 禁止软PWM发生器（写在前面，可避免发生器在中断里运行出现bug）
    HDL_SingleLed_Off();                                                        // 熄灭
}

/**
 * @brief  切换LED状态
 * @param  None
 * @retval None
 */
void FML_SingleLed_Toggle(void)
{
    gLedStatus = !gLedStatus;                                                   // 使能/禁止软PWM发生器（写在前面，可避免发生器在中断里运行出现bug）
    if (gLedStatus == false)
    {
        HDL_SingleLed_Off();                                                    // 熄灭
    }
}

/**
 * @brief  LED设置亮度等级
 * @param  level [0, 100]
 * @retval None
 */
void FML_SingleLed_SetBrightness(uint8_t level)
{
    gLedCompare = level;                                                        // 写入比较值
}

/**
 * @brief  LED软PWM发生器
 * @param  None
 * @retval None
 * @note   等周期调用，调用周期决定频率
 * @note   若40us调用一次，则f = (1/40us)/100 = 250Hz
 * @note   相当于进行了100分频
 */
void FML_SingleLed_SoftPWM(void)
{
    static uint8_t sLedCompareCache = 0;                                        // 比较值缓存
    static uint8_t sPeriod = 0;                                                 // 周期变量

    if (gLedStatus == false)
    {
        return;
    }

    if (sPeriod == 0)
    {
        sLedCompareCache = gLedCompare;                                         // 预装载功能（周期更新时再改变）
    }
    if (sPeriod < sLedCompareCache)                                             // 周期变量<比较值
        HDL_SingleLed_On();                                                     // 点亮
    else
        HDL_SingleLed_Off();                                                    // 熄灭
    sPeriod = (sPeriod + 1) % 100;                                              // 自加，控制周期（驱动频率）[0, 99]
}
