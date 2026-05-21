/*
 * pushbutton.h
 *
 *  Created on: Jan 20, 2017
 *      Author: cheechein
 */

#ifndef PUSHBUTTON_H_
#define PUSHBUTTON_H_

#define	PUSH_BUTTON_PERIPH	SYSCTL_PERIPH_GPIOB

#define	PUSH_BUTTON_PORT	GPIO_PORTB_AHB_BASE

#define	PUSH_BUTTON_PIN		GPIO_PIN_2

//*****************************************************************************
// Prototypes for the APIs.
//*****************************************************************************
void PushButtonPinInit(void);
void PushButtonIntRegister(void (*pfnIntHandler)(void));
void PushButtonIntClear(void);
bool PushButtonPinRead(void);

#endif /* PUSHBUTTON_H_ */
