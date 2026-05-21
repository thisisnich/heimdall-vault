/*
 * clock.c
 *
 *  Created on: Jan 11, 2017
 *      Author: cheechein
 */

#include <stdint.h>
#include <stdbool.h>
#include <time.h>
#include "sysctl.h"
#include "systick.h"
#include "hibernate.h"
#include "clock.h"

void SysTickInterruptHandler(void)
{
	SysTickInterruptFlag = true;
}

uint32_t ClockFrequencySet(uint32_t ui32SysClock)
{
	return (SysCtlClockFreqSet((SYSCTL_XTAL_25MHZ | SYSCTL_OSC_MOSC | SYSCTL_USE_PLL | SYSCTL_CFG_VCO_480), ui32SysClock));
}

void ClockTimerSet(uint32_t ui32milliSeconds)
{
	uint16_t ui16overflowCounter = 0;

	SysTickPeriodSet(120000);
	SysTickEnable();

    SysTickIntRegister(SysTickInterruptHandler);
    SysTickIntEnable();

	SysTickInterruptFlag = false;

	while(ui16overflowCounter < ui32milliSeconds)
	{
		if(SysTickInterruptFlag == true)
		{
			SysTickInterruptFlag = false;
			ui16overflowCounter++;
		}
	}
}

void ClockRTCInit(uint32_t ui32SysClock)
{
	SysCtlPeripheralEnable(SYSCTL_PERIPH_HIBERNATE);
	HibernateEnableExpClk(ui32SysClock);
	HibernateClockConfig(HIBERNATE_OSC_LOWDRIVE);
	HibernateCounterMode(HIBERNATE_COUNTER_12HR);
}

void ClockRTCIntRegister(void (*pfnIntHandler)(void))
{
	HibernateIntRegister(*pfnIntHandler);
	HibernateIntEnable(HIBERNATE_INT_RTC_MATCH_0);
}

void ClockRTCIntClear(void)
{
	HibernateIntClear(HIBERNATE_INT_RTC_MATCH_0);
}

void ClockRTCDateTimeSet(struct tm *psTime)
{
	HibernateCalendarSet(psTime);
	HibernateRTCEnable();
}

void ClockRTCDateTimeGet(struct tm *psTime)
{
	HibernateCalendarGet(psTime);
}

void ClockRTCAlarmTimeSet(struct tm *psTime)
{
	HibernateCalendarMatchSet(0, psTime);
}
