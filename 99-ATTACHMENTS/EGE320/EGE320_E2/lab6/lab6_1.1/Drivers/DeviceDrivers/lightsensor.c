/*
 * lightsensor.c
 *
 *  Created on: Jan 25, 2017
 *      Author: cheechein
 */

#include <stdint.h>
#include <stdbool.h>
#include "sysctl.h"
#include "gpio.h"
#include "comp.h"
#include "lightsensor.h"

void LightSensorPinInit(void)
{
	SysCtlPeripheralEnable(SYSCTL_PERIPH_COMP0);
	SysCtlPeripheralEnable(LIGHT_SENSOR_INPUT_PERIPH);
	SysCtlPeripheralEnable(LIGHT_SENSOR_OUTPUT_PERIPH);

	while(!SysCtlPeripheralReady(SYSCTL_PERIPH_COMP0));
	while(!SysCtlPeripheralReady(LIGHT_SENSOR_INPUT_PERIPH));
	while(!SysCtlPeripheralReady(LIGHT_SENSOR_OUTPUT_PERIPH));

	GPIOPinConfigure(GPIO_PP0_T6CCP0);
	GPIOPinConfigure(GPIO_PP1_T6CCP1);
	GPIOPinConfigure(GPIO_PD2_C2O);

	GPIOPinTypeComparator(LIGHT_SENSOR_INPUT_PORT, LIGHT_SENSOR_INPUT_POS_PIN);
	GPIOPinTypeComparator(LIGHT_SENSOR_INPUT_PORT, LIGHT_SENSOR_INPUT_NEG_PIN);
	GPIOPinTypeComparatorOutput(LIGHT_SENSOR_OUTPUT_PORT, LIGHT_SENSOR_OUTPUT_PIN);

	ComparatorConfigure(COMP_BASE, 2, COMP_ASRCP_REF | COMP_OUTPUT_NORMAL);
	ComparatorRefSet(COMP_BASE, COMP_REF_1_546875V);
}

bool LightSensorPinRead(void)
{
	bool bLightSensorRead = 0;
	bLightSensorRead = ComparatorValueGet(COMP_BASE, 2);
	if(bLightSensorRead == 0)
		return false;
	else
		return true;
}
