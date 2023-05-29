/**
 * @file      FmlSingleLed.c
 * @author    XiaoNing
 * @post      Embedded Software Engineer
 * @brief     ��LED
 * @version   1.0.0
 * @date      2023-05-29
 * @copyright Copyright (c) 2023
 */
#include "FmlSingleLed.h"
#include "HdlSingleLed.h"

static volatile bool gLedStatus = false;
static volatile uint8_t gLedCompare = 0;                                        // �Ƚ�ֵ

/**
 * @brief  LED��ʼ��
 * @param  None
 * @retval None
 */
void FML_SingleLed_Init(void)
{
    HDL_SingleLed_Init();                                                       // ��ʼ��LED
}

/**
 * @brief  ����LED
 * @param  None
 * @retval None
 */
void FML_SingleLed_Open(void)
{
    gLedStatus = true;
}

/**
 * @brief  �ر�LED
 * @param  None
 * @retval None
 */
void FML_SingleLed_Close(void)
{
    gLedStatus = false;                                                         // ��ֹ��PWM��������д��ǰ�棬�ɱ��ⷢ�������ж������г���bug��
    HDL_SingleLed_Off();                                                        // Ϩ��
}

/**
 * @brief  �л�LED״̬
 * @param  None
 * @retval None
 */
void FML_SingleLed_Toggle(void)
{
    gLedStatus = !gLedStatus;                                                   // ʹ��/��ֹ��PWM��������д��ǰ�棬�ɱ��ⷢ�������ж������г���bug��
    if (gLedStatus == false)
    {
        HDL_SingleLed_Off();                                                    // Ϩ��
    }
}

/**
 * @brief  LED�������ȵȼ�
 * @param  level [0, 100]
 * @retval None
 */
void FML_SingleLed_SetBrightness(uint8_t level)
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
void FML_SingleLed_SoftPWM(void)
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
        HDL_SingleLed_On();                                                     // ����
    else
        HDL_SingleLed_Off();                                                    // Ϩ��
    sPeriod = (sPeriod + 1) % 100;                                              // �Լӣ��������ڣ�����Ƶ�ʣ�[0, 99]
}
