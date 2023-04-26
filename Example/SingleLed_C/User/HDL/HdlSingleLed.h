/**
 * @file      HdlSingleLed.h
 * @author    XiaoNing
 * @post      Embedded Software Engineer
 * @brief     µ¥LED
 * @version   1.0.0
 * @date      2023-04-26
 * @copyright Copyright (c) 2023
 */
#ifndef __HDL_SINGLE_LED_H
#define __HDL_SINGLE_LED_H

typedef struct HdlSingleLed
{
    void (*Init)(void);
    void (*On)(void);
    void (*Off)(void);
    void (*Toggle)(void);
} HdlSingleLed_TypeDef;

extern const HdlSingleLed_TypeDef hdlSingleLed;

#endif /* __HDL_SINGLE_LED_H */
