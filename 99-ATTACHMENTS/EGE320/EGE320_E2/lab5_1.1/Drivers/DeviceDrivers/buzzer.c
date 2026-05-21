/*
 * buzzer.c
 *
 *  Created on: Jan 19, 2017
 *      Author: cheechein
 */

#include <stdint.h>
#include <stdbool.h>
#include "sysctl.h"
#include "gpio.h"
#include "pwm.h"
#include "buzzer.h"

void BuzzerPinInit(void)
{
	SysCtlPeripheralEnable(SYSCTL_PERIPH_PWM0);
	SysCtlPeripheralEnable(BUZZER_PERIPH);
	while(!SysCtlPeripheralReady(BUZZER_PERIPH));
	GPIOPinConfigure(GPIO_PG1_M0PWM5);
	GPIOPinTypePWM(BUZZER_PORT, BUZZER_PIN);

	PWMClockSet(PWM0_BASE, PWM_SYSCLK_DIV_4);
	PWMGenConfigure(PWM0_BASE, PWM_GEN_2, PWM_GEN_MODE_UP_DOWN | PWM_GEN_MODE_NO_SYNC);
	PWMGenPeriodSet(PWM0_BASE, PWM_GEN_2, 30000);
	PWMPulseWidthSet(PWM0_BASE, PWM_OUT_5, 0);
	PWMGenEnable(PWM0_BASE, PWM_GEN_2);
	PWMOutputState(PWM0_BASE, PWM_OUT_5_BIT, true);
}

void BuzzerFrequencySet(uint16_t ui32Frequency)
{
	float fPeriod = 0;
	float fPulseWidth = 0;
	fPeriod = 30000000 / ui32Frequency;
	fPulseWidth = fPeriod / 2;
	PWMGenPeriodSet(PWM0_BASE, PWM_GEN_2, fPeriod);
	PWMPulseWidthSet(PWM0_BASE, PWM_OUT_5, fPulseWidth);
}
