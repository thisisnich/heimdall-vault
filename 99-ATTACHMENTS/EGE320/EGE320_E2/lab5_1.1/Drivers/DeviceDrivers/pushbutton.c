/*
 * pushbutton.c
 *
 *  Created on: Jan 20, 2017
 *      Author: cheechein
 */

#include <stdint.h>
#include <stdbool.h>
#include "sysctl.h"
#include "gpio.h"
#include "pushbutton.h"

void PushButtonPinInit(void)
{
	SysCtlPeripheralEnable(PUSH_BUTTON_PERIPH);
	while(!SysCtlPeripheralReady(PUSH_BUTTON_PERIPH));
	GPIOPinTypeGPIOInput(PUSH_BUTTON_PORT, PUSH_BUTTON_PIN);
}

void PushButtonIntRegister(void (*pfnIntHandler)(void))
{
	GPIOIntRegister(PUSH_BUTTON_PORT, *pfnIntHandler);
	GPIOIntTypeSet(PUSH_BUTTON_PORT, PUSH_BUTTON_PIN, GPIO_BOTH_EDGES);
	GPIOIntEnable(PUSH_BUTTON_PORT, PUSH_BUTTON_PIN);
}

void PushButtonIntClear(void)
{
	GPIOIntClear(PUSH_BUTTON_PORT, PUSH_BUTTON_PIN);
}

bool PushButtonPinRead(void)
{
	uint8_t ui8PBRead = 0;
	ui8PBRead = GPIOPinRead(PUSH_BUTTON_PORT, PUSH_BUTTON_PIN);
	if(ui8PBRead == 0)
		return true;
	else
		return false;
}
