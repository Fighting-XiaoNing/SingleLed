/**
 * @file      FmlSingleLed.c
 * @author    XiaoNing
 * @post      Embedded Software Engineer
 * @brief     ��LED
 * @version   1.0.0
 * @date      2023-04-26
 * @copyright Copyright (c) 2023
 */
#include "FmlSingleLed.h"
#include "HdlSingleLed.h"

static volatile bool gLedStatus = false;
static volatile uint8_t gLedCompare = 0;                                        // �Ƚ�ֵ

static void FML_SingleLed_Init(void);
static void FML_SingleLed_Open(void);
static void FML_SingleLed_Close(void);
static void FML_SingleLed_Toggle(void);
static void FML_SingleLed_SetBrightness(uint8_t level);
static void FML_SingleLed_SoftPWM(void);

const FmlSingleLed_TypeDef fmlSingleLed = {
    FML_SingleLed_Init,
    FML_SingleLed_Open,
    FML_SingleLed_Close,
    FML_SingleLed_Toggle,
    FML_SingleLed_SetBrightness,
    FML_SingleLed_SoftPWM
};

/**
 * @brief  LED��ʼ��
 * @param  None
 * @retval None
 */
static void FML_SingleLed_Init(void)
{
    hdlSingleLed.Init();                                                        // ��ʼ��LED
}

/**
 * @brief  ����LED
 * @param  None
 * @retval None
 */
static void FML_SingleLed_Open(void)
{
    gLedStatus = true;
}

/**
 * @brief  �ر�LED
 * @param  None
 * @retval None
 */
static void FML_SingleLed_Close(void)
{
    gLedStatus = false;                                                         // ��ֹ��PWM��������д��ǰ�棬�ɱ��ⷢ�������ж������г���bug��
    hdlSingleLed.Off();                                                         // Ϩ��
}

/**
 * @brief  �л�LED״̬
 * @param  None
 * @retval None
 */
static void FML_SingleLed_Toggle(void)
{
    gLedStatus = !gLedStatus;                                                   // ʹ��/��ֹ��PWM��������д��ǰ�棬�ɱ��ⷢ�������ж������г���bug��
    if (gLedStatus == false)
    {
        hdlSingleLed.Off();                                                     // Ϩ��
    }
}

/**
 * @brief  LED�������ȵȼ�
 * @param  level [0, 100]
 * @retval None
 */
static void FML_SingleLed_SetBrightness(uint8_t level)
{
    gLedCompare = level;                                                        // д��Ƚ�ֵ
}

/**
 * @brief  LED��PWM������
 * @param  None
 * @retval None
 * @note   �����ڵ��ã��������ھ���Ƶ��
 * @note   ��40us����һ�Σ���f = (1/40us)/100 = 250Hz
 * @note   �൱�ڽ�����100��Ƶ
 */
static void FML_SingleLed_SoftPWM(void)
{
    static uint8_t sLedCompareCache = 0;                                        // �Ƚ�ֵ����
    static uint8_t sPeriod = 0;                                                 // ���ڱ���

    if (gLedStatus == false)
    {
        return;
    }

    if (sPeriod == 0)
    {
        sLedCompareCache = gLedCompare;                                         // Ԥװ�ع��ܣ����ڸ���ʱ�ٸı䣩
    }
    if (sPeriod < sLedCompareCache)                                             // ���ڱ���<�Ƚ�ֵ
        hdlSingleLed.On();                                                      // ����
    else
        hdlSingleLed.Off();                                                     // Ϩ��
    sPeriod = (sPeriod + 1) % 100;                                              // �Լӣ��������ڣ�����Ƶ�ʣ�[0, 99]
}
