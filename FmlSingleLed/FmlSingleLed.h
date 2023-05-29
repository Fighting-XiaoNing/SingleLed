/**
 * @file      FmlSingleLed.h
 * @author    XiaoNing
 * @post      Embedded Software Engineer
 * @brief     µ¥LED
 * @version   1.0.0
 * @date      2023-05-29
 * @copyright Copyright (c) 2023
 */
#ifndef __FML_SINGLE_LED_H
#define __FML_SINGLE_LED_H

#include <stdbool.h>
#include <stdint.h>

extern void FML_SingleLed_Init(void);
extern void FML_SingleLed_Open(void);
extern void FML_SingleLed_Close(void);
extern void FML_SingleLed_Toggle(void);
extern void FML_SingleLed_SetBrightness(uint8_t level);
extern void FML_SingleLed_SoftPWM(void);

#endif /* __FML_SINGLE_LED_H */
