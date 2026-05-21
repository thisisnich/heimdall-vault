/*
 * clock.h
 *
 *  Created on: Jan 11, 2017
 *      Author: cheechein
 */

#ifndef CLOCK_H_
#define CLOCK_H_

bool SysTickInterruptFlag;
extern struct tm *psTime;

//*****************************************************************************
// Prototypes for the APIs.
//*****************************************************************************
uint32_t ClockFrequencySet(uint32_t ui32SysClock);
void ClockTimerSet(uint32_t ui32milliSeconds);
void ClockRTCInit(uint32_t ui32SysClock);
void ClockRTCIntRegister(void (*pfnIntHandler)(void));
void ClockRTCIntClear(void);
void ClockRTCDateTimeSet(struct tm *psTime);
void ClockRTCDateTimeGet(struct tm *psTime);
void ClockRTCAlarmTimeSet(struct tm *psTime);

#endif /* CLOCK_H_ */
