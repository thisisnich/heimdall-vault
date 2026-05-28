#include <stdbool.h>
#include <stdint.h>
#include <string.h>
#include "sysctl.h"
#include "gpio.h"
#include "uart.h"
#include "odinw2_uart.h"

bool bDataRxStatus = 0;
uint8_t bDataRxCount = 0;

void ODINW2IntHandler(void)
{
	if(UARTIntStatus(UART1_BASE, true) & UART_INT_RX)
	{
		UARTIntClear(UART1_BASE, UART_INT_RX);
	    bDataRxStatus = 1;
	    bDataRxCount++;
	}
}

void ODINW2PinInit(uint32_t ui32SysClock)
{
	bool ui8RunStatus = 1;
	uint8_t ui8RunCount = 0;

	SysCtlPeripheralEnable(SYSCTL_PERIPH_UART1);
	SysCtlPeripheralEnable(ODINW2_UART_RST_PERIPH);
	SysCtlPeripheralEnable(ODINW2_UART_SW0_PERIPH);
	SysCtlPeripheralEnable(ODINW2_UART_SW1_PERIPH);
	SysCtlPeripheralEnable(ODINW2_UART_TX_PERIPH);
	SysCtlPeripheralEnable(ODINW2_UART_RX_PERIPH);
	SysCtlPeripheralEnable(ODINW2_UART_DSR_PERIPH);
	SysCtlPeripheralEnable(ODINW2_UART_DTR_PERIPH);
	SysCtlPeripheralEnable(ODINW2_UART_RTS_PERIPH);
	SysCtlPeripheralEnable(ODINW2_UART_CTS_PERIPH);

	while(!SysCtlPeripheralReady(ODINW2_UART_RST_PERIPH));
	while(!SysCtlPeripheralReady(ODINW2_UART_SW0_PERIPH));
	while(!SysCtlPeripheralReady(ODINW2_UART_SW1_PERIPH));
	while(!SysCtlPeripheralReady(ODINW2_UART_TX_PERIPH));
	while(!SysCtlPeripheralReady(ODINW2_UART_RX_PERIPH));
	while(!SysCtlPeripheralReady(ODINW2_UART_DSR_PERIPH));
	while(!SysCtlPeripheralReady(ODINW2_UART_DTR_PERIPH));
	while(!SysCtlPeripheralReady(ODINW2_UART_RTS_PERIPH));
	while(!SysCtlPeripheralReady(ODINW2_UART_CTS_PERIPH));

	GPIOPinTypeGPIOOutput(ODINW2_UART_RST_PORT, ODINW2_UART_RST_PIN);
	GPIOPinTypeGPIOOutput(ODINW2_UART_SW0_PORT, ODINW2_UART_SW0_PIN);
	GPIOPinTypeGPIOOutput(ODINW2_UART_SW1_PORT, ODINW2_UART_SW1_PIN);

	GPIOPinTypeUART(ODINW2_UART_TX_PORT, ODINW2_UART_TX_PIN);
	GPIOPinTypeUART(ODINW2_UART_RX_PORT, ODINW2_UART_RX_PIN);
	GPIOPinTypeUART(ODINW2_UART_DSR_PORT, ODINW2_UART_DSR_PIN);
	GPIOPinTypeUART(ODINW2_UART_DTR_PORT, ODINW2_UART_DTR_PIN);
	GPIOPinTypeUART(ODINW2_UART_RTS_PORT, ODINW2_UART_RTS_PIN);
	GPIOPinTypeUART(ODINW2_UART_CTS_PORT, ODINW2_UART_CTS_PIN);
	GPIOPinConfigure(GPIO_PB1_U1TX);
	GPIOPinConfigure(GPIO_PQ4_U1RX);
	GPIOPinConfigure(GPIO_PE1_U1DSR);
	GPIOPinConfigure(GPIO_PE3_U1DTR);
	GPIOPinConfigure(GPIO_PN0_U1RTS);
	GPIOPinConfigure(GPIO_PP3_U1CTS);

	GPIOPinWrite(ODINW2_UART_RST_PORT, ODINW2_UART_RST_PIN, ODINW2_UART_RST_PIN);
	GPIOPinWrite(ODINW2_UART_SW0_PORT, ODINW2_UART_SW0_PIN, ODINW2_UART_SW0_PIN);
	GPIOPinWrite(ODINW2_UART_SW1_PORT, ODINW2_UART_SW1_PIN, ODINW2_UART_SW1_PIN);

	UARTFlowControlSet(UART1_BASE, UART_FLOWCONTROL_TX | UART_FLOWCONTROL_RX);
	UARTConfigSetExpClk(UART1_BASE, ui32SysClock, 115200,(UART_CONFIG_WLEN_8 | UART_CONFIG_STOP_ONE | UART_CONFIG_PAR_NONE));

	UARTFIFODisable(UART1_BASE);
	UARTIntRegister(UART1_BASE, ODINW2IntHandler);
	UARTIntEnable(UART1_BASE, UART_INT_RX);

	while(ui8RunStatus)
	{
		if(bDataRxStatus == 1)
		{
			UARTCharGet(UART1_BASE);
			if(ui8RunCount == 11)
			{
				bDataRxCount = 0;
				ui8RunStatus = 0;
			}
			else
			{
				ui8RunCount++;
			}
			bDataRxStatus = 0;
		}
	}
}

void ODINW2BTLocalAddress(char* pui8LocalAddress)
{
	char ui8DataTx[11] = {};
	uint8_t ui8DataRx[50] = {};
	uint8_t ui8TxCommandLength = 0;
	uint8_t i = 0, j = 0;
	uint8_t ui8RunStatus = 1;

	strcpy(ui8DataTx, "AT+UMLA=1\r");
	ui8TxCommandLength = sizeof(ui8DataTx);
	while(ui8TxCommandLength)
	{
		UARTCharPut(UART1_BASE, ui8DataTx[j]);
		ui8TxCommandLength--;
		j++;
	}
	while(ui8RunStatus == 1)
	{
		if(bDataRxStatus == 1)
		{
			ui8DataRx[i] = UARTCharGet(UART1_BASE);
			if(ui8DataRx[i-3] == 'O' && ui8DataRx[i-2] == 'K' && ui8DataRx[i-1] == '\r' && ui8DataRx[i] == '\n')
			{
				for(i=18; i<30; i++)
				{
					*pui8LocalAddress = ui8DataRx[i];
					pui8LocalAddress++;
				}
				ui8RunStatus = 0;
			}
			if(ui8DataRx[i-6] == 'E' && ui8DataRx[i-5] == 'R' && ui8DataRx[i-4] == 'R' &&  ui8DataRx[i-3] == 'O' &&
			   ui8DataRx[i-2] == 'R' && ui8DataRx[i-1] == '\r' && ui8DataRx[i] == '\n')
			{
				ui8RunStatus = 0;
			}
			bDataRxStatus = 0;
			i++;
		}
	}
}

int8_t ODINW2ConnectPeer(char* pui8ProfileName, char* pui8RemoteAddress)
{
	char ui8DataTx[50] = {};
	uint8_t ui8DataRx[200] = {};
	uint8_t ui8TxCommandLength = 0;
	uint8_t i = 0, j = 0;
	uint8_t ui8RunStatus = 1;
	bool ui8ErrorStatus = 0;

	strcpy(ui8DataTx, "AT+UDCP=\"");
	strcat(ui8DataTx, pui8ProfileName);
	strcat(ui8DataTx, "://");
	strcat(ui8DataTx, pui8RemoteAddress);
	strcat(ui8DataTx, "\"\r");
	ui8TxCommandLength = sizeof(ui8DataTx);
	while(ui8TxCommandLength)
	{
		UARTCharPut(UART1_BASE, ui8DataTx[j]);
		ui8TxCommandLength--;
		j++;
	}
	while(ui8RunStatus == 1)
	{
		if(bDataRxStatus == 1)
		{
			ui8DataRx[i] = UARTCharGet(UART1_BASE);
			if(ui8DataRx[i-3] == 'O' && ui8DataRx[i-2] == 'K' && ui8DataRx[i-1] == '\r' && ui8DataRx[i] == '\n')
			{
				ui8RunStatus = 0;
				ui8ErrorStatus = 0;
			}
			if(ui8DataRx[i-6] == 'E' && ui8DataRx[i-5] == 'R' && ui8DataRx[i-4] == 'R' &&  ui8DataRx[i-3] == 'O' &&
			   ui8DataRx[i-2] == 'R' && ui8DataRx[i-1] == '\r' && ui8DataRx[i] == '\n')
			{
				ui8RunStatus = 0;
				ui8ErrorStatus = 1;
			}
			bDataRxStatus = 0;
			i++;
		}
	}
	if(ui8ErrorStatus == 0)
	{
		return  ui8DataRx[38];
	}
	else
	{
		return -1;
	}
}

uint8_t ODINW2ListenPeer(uint8_t* ui8ProfileName, uint8_t* ui8ConnectionType, char* pui8RemoteAddress)
{
	uint8_t ui8DataRx[50] = {};
	uint8_t i = 0;
	uint8_t ui8RunStatus = 1;

	while(ui8RunStatus == 1)
	{
		if(bDataRxStatus == 1)
		{
			ui8DataRx[i] = UARTCharGet(UART1_BASE);
			bDataRxStatus = 0;
			if(i == 33)
			{
				*ui8ProfileName = ui8DataRx[12];
				*ui8ConnectionType = ui8DataRx[14];
				for(i=16; i<29; i++)
				{
					*pui8RemoteAddress = ui8DataRx[i];
					pui8RemoteAddress++;
				}
				ui8RunStatus = 0;
			}
			i++;
		}
	}
	return ui8DataRx[10];
}

bool ODINW2DataMode(char* ui8mode)
{
	char ui8DataTx[5] = {};
	uint8_t ui8DataRx[50] = {};
	uint8_t ui8TxCommandLength = 0;
	uint8_t i = 0, j = 0;
	uint8_t ui8RunStatus = 1;
	bool ui8ErrorStatus = 0;

	strcpy(ui8DataTx, "ATO\r");
	strcat(ui8DataTx, ui8mode);
	ui8TxCommandLength = sizeof(ui8DataTx);
	while(ui8TxCommandLength)
	{
		UARTCharPut(UART1_BASE, ui8DataTx[j]);
		ui8TxCommandLength--;
		j++;
	}
	while(ui8RunStatus == 1)
	{
		if(bDataRxStatus == 1)
		{
			ui8DataRx[i] = UARTCharGet(UART1_BASE);
			if(ui8DataRx[i-3] == 'O' && ui8DataRx[i-2] == 'K' && ui8DataRx[i-1] == '\r' && ui8DataRx[i] == '\n')
			{
				ui8RunStatus = 0;
				ui8ErrorStatus = 0;
			}
			if(ui8DataRx[i-6] == 'E' && ui8DataRx[i-5] == 'R' && ui8DataRx[i-4] == 'R' &&  ui8DataRx[i-3] == 'O' &&
			   ui8DataRx[i-2] == 'R' && ui8DataRx[i-1] == '\r' && ui8DataRx[i] == '\n')
			{
				ui8RunStatus = 0;
				ui8ErrorStatus = 1;
			}
			bDataRxStatus = 0;
			i++;
		}
	}
	if(ui8ErrorStatus == 0)
	{
		bDataRxCount = 0;
		return 1;

	}
	else
	{
		return 0;
	}
}

void ODINW2DataTx(uint8_t ui8DataTx)
{
	UARTCharPut(UART1_BASE, ui8DataTx);
	while(UARTBusy(UART1_BASE));
}

char ODINW2DataRx(void)
{
	while(bDataRxStatus == 0);
	bDataRxStatus = 0;
	return UARTCharGet(UART1_BASE);
}

bool ODINW2WiFiStationConfigAction(uint32_t ui32Base, char* pui8ConfigID, char* pui8Action)
{
	const char ui8ATCommand[10] = {'A','T','+','U','W','S','C','A','='};
	char ui8DataTx[50] = {};
	uint8_t ui8DataBuffer[50] = {};
	uint16_t i = 0;
	uint8_t ui8RunFlag = 1;

	strcat(ui8DataTx, ui8ATCommand);
	strcat(ui8DataTx, pui8ConfigID);
	strcat(ui8DataTx, ",");
	strcat(ui8DataTx, pui8Action);
	strcat(ui8DataTx, "\r");

	while(ui8DataTx[i] != '\r')
	{
		UARTCharPut(ui32Base, ui8DataTx[i]);
		i++;
	}
	UARTCharPut(ui32Base, ui8DataTx[i]);
	i = 0;
	while(ui8RunFlag == 1)
	{
		ui8DataBuffer[i] = UARTCharGet(UART1_BASE);
		if(ui8DataBuffer[i-3] == '\n' && ui8DataBuffer[i-2] == 'O' && ui8DataBuffer[i-1] == 'K' && ui8DataBuffer[i] == '\r')
		{
			ui8RunFlag = 0;
			return true;
		}
		if(i == 100)
		{
			ui8RunFlag = 0;
		}
		i++;
	}
	return false;
}

bool ODINW2WiFiStationConfig(uint32_t ui32Base, char* pui8ConfigID, char* pui8ParameterTag, char* pui8ParameterValue)
{
	char ui8ATCommand[9] = {'A','T','+','U','W','S','C','='};
	char ui8DataTx[50] = {};
	uint8_t ui8DataBuffer[50] = {};
	uint8_t i = 0;
	uint8_t ui8RunFlag = 1;

	strcat(ui8DataTx, ui8ATCommand);
	strcat(ui8DataTx, pui8ConfigID);
	strcat(ui8DataTx, ",");
	strcat(ui8DataTx, pui8ParameterTag);
	strcat(ui8DataTx, ",");
	strcat(ui8DataTx, pui8ParameterValue);
	strcat(ui8DataTx, "\r");

	while(ui8DataTx[i] != '\r')
	{
		UARTCharPut(ui32Base, ui8DataTx[i]);
		i++;
	}
	UARTCharPut(ui32Base, ui8DataTx[i]);
	i = 0;
	while(ui8RunFlag == 1)
	{
		ui8DataBuffer[i] = UARTCharGet(UART1_BASE);
		if(ui8DataBuffer[i-3] == '\n' && ui8DataBuffer[i-2] == 'O' && ui8DataBuffer[i-1] == 'K' && ui8DataBuffer[i] == '\r')
		{
			ui8RunFlag = 0;
			return true;
		}
		if(i == 100)
		{
			ui8RunFlag = 0;
		}
		i++;
	}
	return false;
}

