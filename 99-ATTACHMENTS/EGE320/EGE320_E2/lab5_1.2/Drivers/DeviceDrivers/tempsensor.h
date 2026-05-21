/*
 * tempsensor.h
 *
 *  Created on: Feb 2, 2017
 *      Author: cheechein
 */

#ifndef TEMPSENSOR_H_
#define TEMPSENSOR_H_

#define	TEMP_SENSOR_PERIPH		SYSCTL_PERIPH_GPIOD

#define	TEMP_SENSOR_PORT		GPIO_PORTD_AHB_BASE

#define	TEMP_SENSOR_PIN			GPIO_PIN_4

//*****************************************************************************
// Prototypes for the APIs.
//*****************************************************************************
void TempSensorPinInit(void);
float TempSensorPinRead(void);

#endif /* TEMPSENSOR_H_ */
