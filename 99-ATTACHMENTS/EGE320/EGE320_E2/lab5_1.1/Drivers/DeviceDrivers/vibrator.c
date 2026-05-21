/*
 * vibrator.c
 *
 *  Created on: 30 Aug 2017
 *      Author: CheeChein
 */

#include <stdint.h>
#include <stdbool.h>
#include "sysctl.h"
#include "gpio.h"
#include "pwm.h"
#include "vibrator.h"

void VibratorPinInit(void)
{
    SysCtlPeripheralEnable(SYSCTL_PERIPH_PWM0);
    SysCtlPeripheralEnable(VIBRATOR_PERIPH);
    while(!SysCtlPeripheralReady(VIBRATOR_PERIPH));
    GPIOPinConfigure(GPIO_PG0_M0PWM4);
    GPIOPinTypePWM(VIBRATOR_PORT, VIBRATOR_PIN);

    PWMClockSet(PWM0_BASE, PWM_SYSCLK_DIV_4);
    PWMGenConfigure(PWM0_BASE, PWM_GEN_2, PWM_GEN_MODE_UP_DOWN | PWM_GEN_MODE_NO_SYNC);
    PWMGenPeriodSet(PWM0_BASE, PWM_GEN_2, 30000);
    PWMPulseWidthSet(PWM0_BASE, PWM_OUT_4, 0);
    PWMGenEnable(PWM0_BASE, PWM_GEN_2);
    PWMOutputState(PWM0_BASE, PWM_OUT_4_BIT, true);
}

void VibratorFrequencySet(uint16_t ui32Frequency)
{
    float fPeriod = 0;
    float fPulseWidth = 0;
    fPeriod = 30000000 / ui32Frequency;
    fPulseWidth = fPeriod / 2;
    PWMGenPeriodSet(PWM0_BASE, PWM_GEN_2, fPeriod);
    PWMPulseWidthSet(PWM0_BASE, PWM_OUT_4, fPulseWidth);
}
