/*
 * rgbled.h
 *
 *  Created on: Jan 11, 2017
 *      Author: cheechein
 */

#ifndef RGBLED_H_
#define RGBLED_H_

#define	RED_LED_PERIPH		SYSCTL_PERIPH_GPIOF
#define	GREEN_LED_PERIPH	SYSCTL_PERIPH_GPIOF
#define	BLUE_LED_PERIPH		SYSCTL_PERIPH_GPIOF

#define	RED_LED_PORT		GPIO_PORTF_AHB_BASE
#define	GREEN_LED_PORT		GPIO_PORTF_AHB_BASE
#define	BLUE_LED_PORT		GPIO_PORTF_AHB_BASE

#define	RED_LED_PIN			GPIO_PIN_2
#define	GREEN_LED_PIN		GPIO_PIN_1
#define	BLUE_LED_PIN		GPIO_PIN_0

//*****************************************************************************
// Prototypes for the APIs.
//*****************************************************************************
void RGBLEDPinInit(void);
void RGBLEDOn(bool bRed, bool bGreen, bool bBlue);
void RGBLEDOff(bool bRed, bool bGreen, bool bBlue);
void RGBLEDOnOff(bool bRed, bool bGreen, bool bBlue);
void RGBLEDToggle(bool bRed, bool bGreen, bool bBlue);
void RGBLEDColorSet(uint32_t ui32ColorCode);

#endif /* RGBLED_H_ */
