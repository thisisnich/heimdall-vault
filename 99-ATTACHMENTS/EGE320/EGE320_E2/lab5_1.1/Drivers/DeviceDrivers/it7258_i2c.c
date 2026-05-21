#include <stdbool.h>
#include <stdint.h>
#include "sysctl.h"
#include "gpio.h"
#include "i2c.h"
#include "it7258_i2c.h"

bool _IT7258DataWrite(uint8_t ui8DeviceAddress, uint8_t ui8BufferIndex,  uint8_t* pui8Data, uint8_t ui8DataLength)
{
	uint16_t i = 0,j = 0;

	for(j = 0; j < 10000; j++);
	I2CMasterSlaveAddrSet(I2C2_BASE, ui8DeviceAddress, false);
	I2CMasterDataPut(I2C2_BASE, ui8BufferIndex);
	I2CMasterControl(I2C2_BASE, I2C_MASTER_CMD_BURST_SEND_START);
	while(I2CMasterBusy(I2C2_BASE));
	for(j = 0; j < 2000; j++);

	for(i = 0; i < (ui8DataLength-1); i++)
	{
		I2CMasterDataPut(I2C2_BASE, *pui8Data);
		I2CMasterControl(I2C2_BASE, I2C_MASTER_CMD_BURST_SEND_CONT);
		while(I2CMasterBusy(I2C2_BASE));
		for(j = 0; j < 2000; j++);
		pui8Data++;
	}
	I2CMasterDataPut(I2C2_BASE, *pui8Data);
	I2CMasterControl(I2C2_BASE, I2C_MASTER_CMD_BURST_SEND_FINISH);
	while(I2CMasterBusy(I2C2_BASE));
	for(j = 0; j < 2000; j++);
	return true;
}

bool _IT7258DataRead(uint8_t ui8DeviceAddress, uint8_t ui8BufferIndex,  uint8_t* pui8Data, uint8_t ui8DataLength)
{
	uint16_t i = 0,j = 0;

	for(j = 0; j < 10000; j++);
	I2CMasterSlaveAddrSet(I2C2_BASE, ui8DeviceAddress, false);
	I2CMasterDataPut(I2C2_BASE, ui8BufferIndex);
	I2CMasterControl(I2C2_BASE, I2C_MASTER_CMD_BURST_SEND_START);
	while(I2CMasterBusy(I2C2_BASE));
	if(ui8DataLength > 1)
	{
		I2CMasterSlaveAddrSet(I2C2_BASE, ui8DeviceAddress, true);
		I2CMasterControl(I2C2_BASE, I2C_MASTER_CMD_BURST_RECEIVE_START);
		while(I2CMasterBusy(I2C2_BASE));
		for(i=0; i<(ui8DataLength-1); i++)
		{
			for(j = 0; j < 2000; j++);
			*pui8Data = I2CMasterDataGet(I2C2_BASE);
			I2CMasterControl(I2C2_BASE, I2C_MASTER_CMD_BURST_RECEIVE_CONT);
			while(I2CMasterBusy(I2C2_BASE));
			pui8Data++;
		}
		for(j = 0; j < 2000; j++);
		*pui8Data = I2CMasterDataGet(I2C2_BASE);
		I2CMasterControl(I2C2_BASE, I2C_MASTER_CMD_BURST_RECEIVE_FINISH);
		while(I2CMasterBusy(I2C2_BASE));
	}
	else
	{
		I2CMasterSlaveAddrSet(I2C2_BASE, ui8DeviceAddress, true);
		I2CMasterControl(I2C2_BASE, I2C_MASTER_CMD_SINGLE_RECEIVE);
		while(I2CMasterBusy(I2C2_BASE));
		for(j = 0; j < 2000; j++);
		*pui8Data = I2CMasterDataGet(I2C2_BASE);
	}
	return true;
}

bool _IT7258WriteCommandBuffer(uint8_t* puiBufferData, uint8_t ui8DataLength)
{
	return _IT7258DataWrite(SLAVE_ADDRESS, COMMAND_BUFFER_INDEX, puiBufferData, ui8DataLength);
}

bool _IT7258ReadCommandResponseBuffer(uint8_t* puiBufferData, uint8_t ui8DataLength)
{
	return _IT7258DataRead(SLAVE_ADDRESS, COMMAND_RESPONSE_BUFFER_INDEX, puiBufferData, ui8DataLength);
}

bool _IT7258ReadQueryBuffer(uint8_t* puiBufferData)
{
	return _IT7258DataRead(SLAVE_ADDRESS, QUERY_BUFFER_INDEX, puiBufferData, 1);
}

bool _IT7258ReadPointInfoBuffer(uint8_t* puiBufferData)
{
	return _IT7258DataRead(SLAVE_ADDRESS, POINT_INFO_BUFFER_INDEX, puiBufferData, 14);
}

void IT7258PinInitI2CTest(uint32_t ui32SysClock)
{
	SysCtlPeripheralEnable(SYSCTL_PERIPH_I2C2);
	SysCtlPeripheralEnable(IT7258_I2C_PERIPH);

	while(!SysCtlPeripheralReady(SYSCTL_PERIPH_I2C2));
	while(!SysCtlPeripheralReady(IT7258_I2C_PERIPH));

	GPIOPinTypeGPIOOutput(IT7258_I2C_PORT, IT7258_I2C_RESET_PIN);
	GPIOPinTypeGPIOInput(IT7258_I2C_PORT, IT7258_I2C_EINT_PIN);

	GPIOPinConfigure(GPIO_PL1_I2C2SCL);
	GPIOPinConfigure(GPIO_PL0_I2C2SDA);
	GPIOPinTypeI2CSCL(IT7258_I2C_PORT, IT7258_I2C_SCL_PIN);
	GPIOPinTypeI2C(IT7258_I2C_PORT, IT7258_I2C_SDA_PIN);

	GPIOPinWrite(IT7258_I2C_PORT, IT7258_I2C_RESET_PIN, 0);

	I2CMasterInitExpClk(I2C2_BASE, ui32SysClock, true);

	I2CMasterSlaveAddrSet(I2C2_BASE, SLAVE_ADDRESS, false);
	I2CMasterDataPut(I2C2_BASE, 0x55);
	I2CMasterControl(I2C2_BASE, I2C_MASTER_CMD_SINGLE_SEND);
}

void IT7258PinInit(uint32_t ui32SysClock)
{
	SysCtlPeripheralEnable(SYSCTL_PERIPH_I2C2);
	SysCtlPeripheralEnable(IT7258_I2C_PERIPH);

	while(!SysCtlPeripheralReady(SYSCTL_PERIPH_I2C2));
	while(!SysCtlPeripheralReady(IT7258_I2C_PERIPH));

	GPIOPinTypeGPIOOutput(IT7258_I2C_PORT, IT7258_I2C_RESET_PIN);
	GPIOPinTypeGPIOInput(IT7258_I2C_PORT, IT7258_I2C_EINT_PIN);

	GPIOPinConfigure(GPIO_PL1_I2C2SCL);
	GPIOPinConfigure(GPIO_PL0_I2C2SDA);
	GPIOPinTypeI2CSCL(IT7258_I2C_PORT, IT7258_I2C_SCL_PIN);
	GPIOPinTypeI2C(IT7258_I2C_PORT, IT7258_I2C_SDA_PIN);

	GPIOPinWrite(IT7258_I2C_PORT, IT7258_I2C_RESET_PIN, 0);

	I2CMasterInitExpClk(I2C2_BASE, ui32SysClock, true);
}

void IT7258IntRegister(void (*pfnIntHandler)(void))
{
	GPIOIntRegister(IT7258_I2C_PORT, *pfnIntHandler);
	GPIOIntTypeSet(IT7258_I2C_PORT, IT7258_I2C_EINT_PIN, GPIO_FALLING_EDGE);
	GPIOIntEnable(IT7258_I2C_PORT, IT7258_I2C_EINT_PIN);
}

void IT7258IntClear(void)
{
	GPIOIntClear(IT7258_I2C_PORT, IT7258_I2C_EINT_PIN);
}

bool IT7258IdentifyCapSensor()
{
	uint8_t ucWriteLength = 0, ucReadLength = 0;
	uint8_t pui8Command = 0, pui8CommandResponse[10] = {};
	uint8_t ui8QueryResponse = 0;

	ucWriteLength = 1;
	ucReadLength = 0x0A;
	pui8Command = 0x00;

	do
	{
		_IT7258ReadQueryBuffer(&ui8QueryResponse);
	}while(ui8QueryResponse & QUERY_BUSY);

	if(!_IT7258WriteCommandBuffer(&pui8Command, ucWriteLength))
	{
		return false;
	}

	do
	{
		_IT7258ReadQueryBuffer(&ui8QueryResponse);
	}while(ui8QueryResponse & QUERY_BUSY);

	if(!_IT7258ReadCommandResponseBuffer(pui8CommandResponse, ucReadLength))
	{
		return false;
	}

	if(pui8CommandResponse[1] != 'I' || pui8CommandResponse[2] != 'T' || pui8CommandResponse[3] != 'E' ||
	   pui8CommandResponse[4] != '7' || pui8CommandResponse[5] != '2' || pui8CommandResponse[6] != '6' || pui8CommandResponse[7] != '0')
	{
		return false;
	}
	return true;
}

bool IT7258InquiryCapSensorInformation(uint8_t ui8SubCommand, uint8_t* pui8CommandResponse)
{
	uint8_t ucWriteLength = 0, ucReadLength = 0;
	uint8_t pui8Command[3] = {};
	uint8_t ui8QueryResponse = 0;

	ucWriteLength = 2;
	ucReadLength = 0x0E;
	pui8Command[0] = 0x01;
	pui8Command[1] = ui8SubCommand;

	if((ui8SubCommand == TWOD_RESOLUTIONS) || (ui8SubCommand == GESTURE_INFORMATION))
	{
		ucWriteLength = 3;
		pui8Command[2] = 0x00;
	}

	do
	{
		_IT7258ReadQueryBuffer(&ui8QueryResponse);
	}while(ui8QueryResponse & QUERY_BUSY);

	if(!_IT7258WriteCommandBuffer(pui8Command, ucWriteLength))
	{
		return false;
	}

	do
	{
		_IT7258ReadQueryBuffer(&ui8QueryResponse);
	}while(ui8QueryResponse & QUERY_BUSY);

	if(!_IT7258ReadCommandResponseBuffer(pui8CommandResponse, ucReadLength))
	{
		return false;
	}
	return true;
}

bool IT7258SetCapSensorInformation(uint8_t ui8SubCommand, uint8_t ui8Parameter, uint8_t ui8Type)
{
	uint8_t ucWriteLength = 0, ucReadLength = 0;
	uint8_t pui8Command[4] = {}, pui8CommandResponse[6] = {};
	uint8_t ui8QueryResponse = 0;

	ucWriteLength = 4;
	ucReadLength = 2;
	pui8Command[0] = 0x02;
	pui8Command[1] = ui8SubCommand;
	pui8Command[2] = ui8Parameter;
	pui8Command[3] = ui8Type;

	do
	{
		_IT7258ReadQueryBuffer(&ui8QueryResponse);
	}while(ui8QueryResponse & QUERY_BUSY);

	if(!_IT7258WriteCommandBuffer(pui8Command, ucWriteLength))
	{
		return false;
	}

	do
	{
		_IT7258ReadQueryBuffer(&ui8QueryResponse);
	}while(ui8QueryResponse & QUERY_BUSY);

	if(!_IT7258ReadCommandResponseBuffer(pui8CommandResponse, ucReadLength))
	{
		return false;
	}
	return true;
}

bool IT7258SetPowerMode(uint8_t ui8SubCommand, uint8_t ui8Parameter)
{
	uint8_t ucWriteLength = 0;
	uint8_t pui8Command[3] = {};
	uint8_t ui8QueryResponse = 0;

	ucWriteLength = 3;
	pui8Command[0] = 0x04;
	pui8Command[1] = ui8SubCommand;
	pui8Command[2] = ui8Parameter;

	do
	{
		_IT7258ReadQueryBuffer(&ui8QueryResponse);
	}while(ui8QueryResponse & QUERY_BUSY);

	if(!_IT7258WriteCommandBuffer(pui8Command, ucWriteLength))
	{
		return false;
	}
	return true;
}

bool IT7258ReinitializeFirmware()
{
	uint8_t ucWriteLength = 0, ucReadLength = 0;
	uint8_t pui8Command = 0, pui8CommandResponse[3] = {};
	uint8_t ui8QueryResponse = 0;
	uint32_t i = 0;

	ucWriteLength = 1;
	ucReadLength = 2;
	pui8Command = 0x6F;

	do
	{
		_IT7258ReadQueryBuffer(&ui8QueryResponse);
	}while(ui8QueryResponse & QUERY_BUSY);

	if(!_IT7258WriteCommandBuffer(&pui8Command, ucWriteLength))
	{
		return false;
	}

	for(i = 0; i < 200000; i++);

	do
	{
		_IT7258ReadQueryBuffer(&ui8QueryResponse);
	}while(ui8QueryResponse & QUERY_BUSY);

	if(!_IT7258ReadCommandResponseBuffer(pui8CommandResponse, ucReadLength))
	{
		return false;
	}

	if(pui8CommandResponse[0] != 0x00 || pui8CommandResponse[1] != 0x00 )
	{
		return false;
	}
	return true;
}

uint8_t IT7258GetTouchPointData(uint16_t* ui16XPosition, uint16_t* ui16YPosition, uint8_t* ui8Pressure)
{
	uint8_t ui8QueryResponse = 0;
	uint8_t ui8NumberOfPoint = 0;
	uint8_t ui8PointInfoBufferResponse[14] = {};
	uint8_t i = 0;

	while(!_IT7258ReadQueryBuffer(&ui8QueryResponse));

	if(ui8QueryResponse & QUERY_POINT)
	{
		if(!_IT7258ReadPointInfoBuffer(ui8PointInfoBufferResponse))
		{
			return false;
		}

		if((ui8PointInfoBufferResponse[0] & 0xF0) == 0)
		{
			for(i = 0; i < 3; i++)
			{
				if(ui8PointInfoBufferResponse[0] & (1<<i))
				{
					*ui16XPosition = ((ui8PointInfoBufferResponse[i*4+3] & 0x0F) << 8) +
										ui8PointInfoBufferResponse[i*4+2];
					*ui16YPosition = ((ui8PointInfoBufferResponse[i*4+3] & 0xF0) << 4) +
										ui8PointInfoBufferResponse[i*4+4];
					*ui8Pressure = ui8PointInfoBufferResponse[i*4+5] & 0x0F;
					ui8NumberOfPoint++;
				}
				else
				{
					*ui16XPosition = 0;
					*ui16YPosition = 0;
					*ui8Pressure = 0;
				}
				ui16XPosition++;
				ui16YPosition++;
				ui8Pressure++;
			}
		}
	}
	return ui8NumberOfPoint;
}

uint8_t IT7258GetGesture(uint16_t* ui16XPosition, uint16_t* ui16YPosition, uint8_t* ui8StartDirection, uint8_t* ui8StopDirection)
{
	uint8_t ui8QueryResponse = 0;
	uint8_t ui8GestureID = 0;
	uint8_t ui8PointInfoBufferResponse[14] = {};
	uint8_t i = 0;

	while(!_IT7258ReadQueryBuffer(&ui8QueryResponse));

	if(ui8QueryResponse & QUERY_POINT)
	{
		if(!_IT7258ReadPointInfoBuffer(ui8PointInfoBufferResponse))
		{
			return false;
		}

		if((ui8PointInfoBufferResponse[0] & 0xF0) == 0x80)
		{
			ui8GestureID = ui8PointInfoBufferResponse[1];
			if(ui8GestureID < 0x26)
			{
				ui16XPosition[0] = ((ui8PointInfoBufferResponse[3] & 0x0F) << 8) +
									ui8PointInfoBufferResponse[2];
				ui16YPosition[0] = ((ui8PointInfoBufferResponse[3] & 0xF0) << 4) +
									ui8PointInfoBufferResponse[+4];
			}
			if((ui8GestureID == 0x26) || (ui8GestureID == 0x27))
			{
				*ui8StartDirection = ui8PointInfoBufferResponse[2] & 0x07;
				*ui8StopDirection = (ui8PointInfoBufferResponse[2] & 0x70) >> 4;
			}
			if((ui8GestureID == 0x40) || (ui8GestureID == 0x41))
			{
				for(i = 0; i < 1; i++)
				{
					ui16XPosition[i] = ((ui8PointInfoBufferResponse[i*4+3] & 0x0F) << 8) +
										ui8PointInfoBufferResponse[i*4+2];
					ui16YPosition[i] = ((ui8PointInfoBufferResponse[i*4+3] & 0xF0) << 4) +
										ui8PointInfoBufferResponse[i*4+4];
				}
			}
		}
	}
	return ui8GestureID;
}
