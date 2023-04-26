/**
 * @file      FmlSingleLed.h
 * @author    XiaoNing
 * @post      Embedded Software Engineer
 * @brief     µ¥LED
 * @version   1.0.0
 * @date      2023-04-26
 * @copyright Copyright (c) 2023
 */
#ifndef __FML_SINGLE_LED_H
#define __FML_SINGLE_LED_H

#include <stdbool.h>
#include <stdint.h>

typedef struct FmlSingleLed
{
    void (*Init)(void);
    void (*Open)(void);
    void (*Close)(void);
    void (*Toggle)(void);
    void (*SetBrightness)(uint8_t level);
    void (*SoftPWM)(void);
} FmlSingleLed_TypeDef;

extern const FmlSingleLed_TypeDef fmlSingleLed;

#endif /* __FML_SINGLE_LED_H */
