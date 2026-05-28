/*
 * lightsensor.h
 *
 *  Created on: Jan 25, 2017
 *      Author: cheechein
 */

#ifndef LIGHTSENSOR_H_
#define LIGHTSENSOR_H_

#define	LIGHT_SENSOR_INPUT_PERIPH		SYSCTL_PERIPH_GPIOP
#define	LIGHT_SENSOR_OUTPUT_PERIPH		SYSCTL_PERIPH_GPIOD

#define	LIGHT_SENSOR_INPUT_PORT			GPIO_PORTP_AHB_BASE
#define	LIGHT_SENSOR_OUTPUT_PORT		GPIO_PORTD_AHB_BASE

#define	LIGHT_SENSOR_INPUT_POS_PIN		GPIO_PIN_0
#define	LIGHT_SENSOR_INPUT_NEG_PIN		GPIO_PIN_1
#define	LIGHT_SENSOR_OUTPUT_PIN			GPIO_PIN_2

//*****************************************************************************
// Prototypes for the APIs.
//*****************************************************************************
void LightSensorPinInit(void);
bool LightSensorPinRead(void);

#endif /* LIGHTSENSOR_H_ */
