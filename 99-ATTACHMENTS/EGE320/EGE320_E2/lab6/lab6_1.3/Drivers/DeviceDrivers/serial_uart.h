/*
 * serial_uart.h
 *
 *  Created on: Feb 15, 2017
 *      Author: cheechein
 */

#ifndef SERIAL_UART_H_
#define SERIAL_UART_H_

#define	SERIAL_UART_PERIPH		SYSCTL_PERIPH_GPIOC

#define	SERIAL_UART_PORT		GPIO_PORTC_AHB_BASE

#define	SERIAL_UART_TX_PIN		GPIO_PIN_5
#define	SERIAL_UART_RX_PIN		GPIO_PIN_4

//*****************************************************************************
// Prototypes for the APIs.
//*****************************************************************************
void SerialPinInit(uint32_t ui32SysClock);
void SerialIntRegister(void (*pfnIntHandler)(void));
bool SerialTxIntStatus(void);
bool SerialRxIntStatus(void);
void SerialIntClear(void);
void SerialDataTx(uint8_t ui8DataTx);
char SerialDataRx(void);

#endif /* SERIAL_UART_H_ */
