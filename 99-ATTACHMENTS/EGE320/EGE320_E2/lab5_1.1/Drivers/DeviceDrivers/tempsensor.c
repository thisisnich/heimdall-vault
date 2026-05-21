/*
 * tempsensor.c
 *
 *  Created on: Feb 2, 2017
 *      Author: cheechein
 */

#include <stdint.h>
#include <stdbool.h>
#include "sysctl.h"
#include "gpio.h"
#include "adc.h"
#include "tempsensor.h"

void TempSensorPinInit(void)
{
	SysCtlPeripheralEnable(SYSCTL_PERIPH_ADC0);
	SysCtlPeripheralEnable(TEMP_SENSOR_PERIPH);

	while(!SysCtlPeripheralReady(SYSCTL_PERIPH_ADC0));
	while(!SysCtlPeripheralReady(TEMP_SENSOR_PERIPH));

	GPIOPinTypeADC(TEMP_SENSOR_PORT, TEMP_SENSOR_PIN);

    ADCSequenceConfigure(ADC0_BASE, 3, ADC_TRIGGER_PROCESSOR, 0);
    ADCSequenceStepConfigure(ADC0_BASE, 3, 0, ADC_CTL_CH7 | ADC_CTL_IE | ADC_CTL_END);
    ADCSequenceEnable(ADC0_BASE, 3);
    ADCIntClear(ADC0_BASE, 3);
}

float TempSensorPinRead(void)
{
	uint32_t ui32TempSensorValue = 0;
	uint32_t ui32TempSensorArray[50] = {};
	uint32_t ui32TempSensorSum = 0;
	uint32_t ui32TempSensorAve = 0;
	uint16_t ui16Count = 0;
	float fTempVoltageValue = 0;
	float fTempValue = 0;

	for(ui16Count = 0; ui16Count < 50; ui16Count++)
	{
		ADCProcessorTrigger(ADC0_BASE, 3);
		while(!ADCIntStatus(ADC0_BASE, 3, false));
		ADCIntClear(ADC0_BASE, 3);
		ADCSequenceDataGet(ADC0_BASE, 3, &ui32TempSensorValue);
		ui32TempSensorArray[ui16Count] = ui32TempSensorValue;
	}

	for(ui16Count = 0; ui16Count < 50; ui16Count++)
	{
		ui32TempSensorSum = ui32TempSensorSum + ui32TempSensorArray[ui16Count];
	}

	ui32TempSensorAve = ui32TempSensorSum / 50;

    fTempVoltageValue = (ui32TempSensorAve / 4095.0) * 3.3;
    fTempValue = -0.193 * (fTempVoltageValue * 1000) + 212.009;

    return fTempValue;
}
