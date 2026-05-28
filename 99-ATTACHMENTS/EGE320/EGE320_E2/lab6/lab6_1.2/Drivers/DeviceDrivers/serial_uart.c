/*
 * serial_uart.c
 *
 *  Created on: Feb 15, 2017
 *      Author: cheechein
 */

#include <stdint.h>
#include <stdbool.h>
#include "sysctl.h"
#include "gpio.h"
#include "uart.h"
#include "serial_uart.h"

void SerialPinInit(uint32_t ui32SysClock)
{
	SysCtlPeripheralEnable(SYSCTL_PERIPH_UART7);
	SysCtlPeripheralEnable(SERIAL_UART_PERIPH);

	while(!SysCtlPeripheralReady(SYSCTL_PERIPH_UART7));
	while(!SysCtlPeripheralReady(SERIAL_UART_PERIPH));

	GPIOPinConfigure(GPIO_PC5_U7TX);
	GPIOPinConfigure(GPIO_PC4_U7RX);
	GPIOPinTypeUART(SERIAL_UART_PORT, SERIAL_UART_TX_PIN);
	GPIOPinTypeUART(SERIAL_UART_PORT, SERIAL_UART_RX_PIN);

	UARTConfigSetExpClk(UART7_BASE, ui32SysClock, 115200, (UART_CONFIG_WLEN_8 | UART_CONFIG_STOP_ONE | UART_CONFIG_PAR_NONE));
}

void SerialIntRegister(void (*pfnIntHandler)(void))
{
	UARTFIFODisable(UART7_BASE);
	UARTIntRegister(UART7_BASE, *pfnIntHandler);
	UARTIntEnable(UART7_BASE, UART_INT_TX | UART_INT_RX);
}

bool SerialTxIntStatus(void)
{
	if(UARTIntStatus(UART7_BASE, true) & UART_INT_TX)
	{
		return true;
	}
	else
	{
		return false;
	}
}

bool SerialRxIntStatus(void)
{
	if(UARTIntStatus(UART7_BASE, true) & UART_INT_RX)
	{
		return true;
	}
	else
	{
		return false;
	}
}

void SerialIntClear(void)
{
	UARTIntClear(UART7_BASE, UART_INT_TX | UART_INT_RX);
}

void SerialDataTx(uint8_t ui8DataTx)
{
	UARTCharPut(UART7_BASE, ui8DataTx);
	while(UARTBusy(UART7_BASE));
}

char SerialDataRx(void)
{
	return UARTCharGet(UART7_BASE);
}
