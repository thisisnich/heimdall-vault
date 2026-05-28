/*
 * vibrator.h
 *
 *  Created on: 30 Aug 2017
 *      Author: CheeChein
 */

#ifndef VIBRATOR_H_
#define VIBRATOR_H_

#define VIBRATOR_PERIPH   SYSCTL_PERIPH_GPIOG

#define VIBRATOR_PORT     GPIO_PORTG_AHB_BASE

#define VIBRATOR_PIN      GPIO_PIN_0

//*****************************************************************************
// Prototypes for the APIs.
//*****************************************************************************
void VibratorPinInit(void);
void VibratorFrequencySet(uint16_t ui32Frequency);

#endif /* DRIVERS_DEVICEDRIVERS_VIBRATOR_H_ */
