/*
 * rgbled.c
 *
 *  Created on: Jan 11, 2017
 *      Author: cheechein
 */

#include <stdint.h>
#include <stdbool.h>
#include "sysctl.h"
#include "gpio.h"
#include "pwm.h"
#include "rgbled.h"

void RGBLEDPinInit(void)
{
	SysCtlPeripheralEnable(SYSCTL_PERIPH_PWM0);
	SysCtlPeripheralEnable(RED_LED_PERIPH);
	SysCtlPeripheralEnable(GREEN_LED_PERIPH);
	SysCtlPeripheralEnable(BLUE_LED_PERIPH);

	while(!SysCtlPeripheralReady(SYSCTL_PERIPH_PWM0));
	while(!SysCtlPeripheralReady(RED_LED_PERIPH));
	while(!SysCtlPeripheralReady(GREEN_LED_PERIPH));
	while(!SysCtlPeripheralReady(BLUE_LED_PERIPH));

	GPIOPinConfigure(GPIO_PF0_M0PWM0);
	GPIOPinConfigure(GPIO_PF1_M0PWM1);
	GPIOPinConfigure(GPIO_PF2_M0PWM2);

	GPIOPinTypePWM(RED_LED_PORT, RED_LED_PIN);
	GPIOPinTypePWM(GREEN_LED_PORT, GREEN_LED_PIN);
	GPIOPinTypePWM(BLUE_LED_PORT, BLUE_LED_PIN);

	PWMClockSet(PWM0_BASE, PWM_SYSCLK_DIV_4);
	PWMGenConfigure(PWM0_BASE, PWM_GEN_0, PWM_GEN_MODE_UP_DOWN | PWM_GEN_MODE_NO_SYNC);
	PWMGenConfigure(PWM0_BASE, PWM_GEN_1, PWM_GEN_MODE_UP_DOWN | PWM_GEN_MODE_NO_SYNC);
	PWMGenPeriodSet(PWM0_BASE, PWM_GEN_0, 30000);
	PWMGenPeriodSet(PWM0_BASE, PWM_GEN_1, 30000);
	PWMPulseWidthSet(PWM0_BASE, PWM_OUT_0, 29999);
	PWMPulseWidthSet(PWM0_BASE, PWM_OUT_1, 29999);
	PWMPulseWidthSet(PWM0_BASE, PWM_OUT_2, 29999);
	PWMGenEnable(PWM0_BASE, PWM_GEN_0);
	PWMGenEnable(PWM0_BASE, PWM_GEN_1);
	PWMOutputState(PWM0_BASE, PWM_OUT_0_BIT, true);
	PWMOutputState(PWM0_BASE, PWM_OUT_1_BIT, true);
	PWMOutputState(PWM0_BASE, PWM_OUT_2_BIT, true);
}

void RGBLEDOn(bool bRed, bool bGreen, bool bBlue)
{
	if(bRed == true)
	{
		PWMPulseWidthSet(PWM0_BASE, PWM_OUT_2, 5);
	}
	if(bGreen == true)
	{
		PWMPulseWidthSet(PWM0_BASE, PWM_OUT_1, 5);
	}
	if(bBlue == true)
	{
		PWMPulseWidthSet(PWM0_BASE, PWM_OUT_0, 5);
	}
}

void RGBLEDOff(bool bRed, bool bGreen, bool bBlue)
{
	if(bRed == true)
	{
		PWMPulseWidthSet(PWM0_BASE, PWM_OUT_2, 29999);
	}
	if(bGreen == true)
	{
		PWMPulseWidthSet(PWM0_BASE, PWM_OUT_1, 29999);
	}
	if(bBlue == true)
	{
		PWMPulseWidthSet(PWM0_BASE, PWM_OUT_0, 29999);
	}
}

void RGBLEDOnOff(bool bRed, bool bGreen, bool bBlue)
{
	if(bRed == true)
	{
		PWMPulseWidthSet(PWM0_BASE, PWM_OUT_2, 5);
	}
	else
	{
		PWMPulseWidthSet(PWM0_BASE, PWM_OUT_2, 29999);
	}
	if(bGreen == true)
	{
		PWMPulseWidthSet(PWM0_BASE, PWM_OUT_1, 5);
	}
	else
	{
		PWMPulseWidthSet(PWM0_BASE, PWM_OUT_1, 29999);
	}
	if(bBlue == true)
	{
		PWMPulseWidthSet(PWM0_BASE, PWM_OUT_0, 5);
	}
	else
	{
		PWMPulseWidthSet(PWM0_BASE, PWM_OUT_0, 29999);
	}
}

void RGBLEDToggle(bool bRed, bool bGreen, bool bBlue)
{
	if(bRed == true)
	{
		if (GPIOPinRead(RED_LED_PORT, RED_LED_PIN) == RED_LED_PIN)
		{
			PWMPulseWidthSet(PWM0_BASE, PWM_OUT_2, 5);
		}
		else
		{
			PWMPulseWidthSet(PWM0_BASE, PWM_OUT_2, 29999);
		}
	}
	if(bGreen == true)
	{
		if (GPIOPinRead(GREEN_LED_PORT, GREEN_LED_PIN) == GREEN_LED_PIN)
		{
			PWMPulseWidthSet(PWM0_BASE, PWM_OUT_1, 5);
		}
		else
		{
			PWMPulseWidthSet(PWM0_BASE, PWM_OUT_1, 29999);
		}
	}
	if(bBlue == true)
	{
		if (GPIOPinRead(BLUE_LED_PORT, BLUE_LED_PIN) == BLUE_LED_PIN)
		{
			PWMPulseWidthSet(PWM0_BASE, PWM_OUT_0, 5);
		}
		else
		{
			PWMPulseWidthSet(PWM0_BASE, PWM_OUT_0, 29999);
		}
	}
}

void RGBLEDColorSet(uint32_t ui32ColorCode)
{
	uint8_t ui8Red = (ui32ColorCode >> 16) & 0xFF;
	uint8_t ui8Green = (ui32ColorCode >> 8) & 0xFF;
	uint8_t ui8Blue = ui32ColorCode & 0xFF;
	PWMPulseWidthSet(PWM0_BASE, PWM_OUT_2, 29999 - (ui8Red*115));
	PWMPulseWidthSet(PWM0_BASE, PWM_OUT_1, 29999 - (ui8Green*115));
	PWMPulseWidthSet(PWM0_BASE, PWM_OUT_0, 29999 - (ui8Blue*115));
}
