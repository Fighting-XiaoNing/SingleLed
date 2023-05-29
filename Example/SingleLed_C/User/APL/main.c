/**
 * @file      main.c
 * @author    XiaoNing
 * @post      Embedded Software Engineer
 * @brief     主函数
 * @version   1.0.0
 * @date      2023-05-29
 * @copyright Copyright (c) 2023
 */
#include "FmlSingleLed.h"

static void Delay_Ms(uint16_t nms)
{
    uint16_t x = 0, y = 0;
    for (x = nms; x > 0; x--)
        for (y = 112; y > 0; y--);
}

/**
 * @brief  主函数
 * @param  None
 * @retval int
 */
int main(void)
{
    FML_SingleLed_Init();                                                       // LED初始化
    FML_SingleLed_SetBrightness(20);                                            // LED设置亮度等级
    FML_SingleLed_Open();                                                       // 启动LED
    while (1)
    {
        Delay_Ms(1);
        FML_SingleLed_SoftPWM();                                                // LED软PWM发生器
    }
}
