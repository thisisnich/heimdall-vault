/*
 * buzzer.h
 *
 *  Created on: Jan 19, 2017
 *      Author: cheechein
 */

#ifndef BUZZER_H_
#define BUZZER_H_

#define	BUZZER_PERIPH	SYSCTL_PERIPH_GPIOG

#define	BUZZER_PORT		GPIO_PORTG_AHB_BASE

#define	BUZZER_PIN		GPIO_PIN_1

//*****************************************************************************
// Prototypes for the APIs.
//*****************************************************************************
void BuzzerPinInit(void);
void BuzzerFrequencySet(uint16_t ui32Frequency);


#endif /* BUZZER_H_ */
