/*
 * it7258_i2c.h
 *
 *  Created on: Nov 12, 2016
 *      Author: cheechein
 */

#ifndef IT7258_I2C_H_
#define IT7258_I2C_H_

#define	IT7258_I2C_PERIPH		SYSCTL_PERIPH_GPIOL

#define	IT7258_I2C_PORT			GPIO_PORTL_AHB_BASE

#define	IT7258_I2C_SCL_PIN		GPIO_PIN_1
#define	IT7258_I2C_SDA_PIN		GPIO_PIN_0
#define	IT7258_I2C_RESET_PIN	GPIO_PIN_4
#define	IT7258_I2C_EINT_PIN		GPIO_PIN_5



#define SLAVE_ADDRESS 							0x46

#define COMMAND_BUFFER_INDEX 					0x20
#define SYSTEM_COMMAND_BUFFER_INDEX 			0x40
#define QUERY_BUFFER_INDEX 						0x80
#define COMMAND_RESPONSE_BUFFER_INDEX 			0xA0
#define SYSTEM_COMMAND_RESPONSE_BUFFER_INDEX 	0xC0
#define POINT_INFO_BUFFER_INDEX 				0xE0

#define QUERY_SUCCESS 							0x00
#define QUERY_BUSY 								0x01
#define QUERY_ERROR 							0x02
#define QUERY_POINT 							0x80

#define FIRMWARE_INFORMATION					0x00
#define	TWOD_RESOLUTIONS						0x02
#define FLASH_SIZE								0x03
#define	INTERRUPT_NOTIFICATION_STATUS			0x04
#define GESTURE_INFORMATION						0x05
#define CONFIGURATION_VERSION					0x06

#define INTERRUPT_DISABLE						0x00
#define INTERRUPT_ENABLE						0x01
#define INTERRUPT_LOW_LEVEL_TRIGGER				0x00
#define INTERRUPT_HIGH_LEVEL_TRIGGER			0x01
#define INTERRUPT_FALLING_EDGE_TRIGGER		    0x10
#define INTERRUPT_RISING_EDGE_TRIGGER			0x11

#define POWER_SLEEP_MODE						0x01
#define POWER_OFF_MODE							0x02

bool _IT7258DataWrite(uint8_t ui8DeviceAddress, uint8_t ui8BufferIndex,  uint8_t* pui8Data, uint8_t ui8DataLength);
bool _IT7258DataRead(uint8_t ui8DeviceAddress, uint8_t ui8BufferIndex,  uint8_t* pui8Data, uint8_t ui8DataLength);
bool _IT7258WriteCommandBuffer(uint8_t* puiBufferData, uint8_t ui8DataLength);
bool _IT7258ReadCommandResponseBuffer(uint8_t* puiBufferData, uint8_t ui8DataLength);
bool _IT7258ReadQueryBuffer(uint8_t* puiBufferData);
bool _IT7258ReadPointInfoBuffer(uint8_t* puiBufferData);
void IT7258PinInit(uint32_t ui32SysClock);
void IT7258PinInitI2CTest(uint32_t ui32SysClock);
void IT7258IntRegister(void (*pfnIntHandler)(void));
void IT7258IntClear(void);
bool IT7258IdentifyCapSensor();																							//Tested
bool IT7258InquiryCapSensorInformation(uint8_t ui8SubCommand, uint8_t* pui8CommandResponse);							//Tested
bool IT7258SetCapSensorInformation(uint8_t ui8SubCommand, uint8_t ui8Parameter, uint8_t ui8Type);						//Tested
bool IT7258SetPowerMode(uint8_t ui8SubCommand, uint8_t ui8Parameter);
bool IT7258ReinitializeFirmware();
uint8_t IT7258GetTouchPointData(uint16_t* ui16XPosition, uint16_t* ui16YPosition, uint8_t* ui8Pressure);				//Tested
uint8_t IT7258GetGesture(uint16_t* ui16XPosition, uint16_t* ui16YPosition, uint8_t* ui8StartDirection, uint8_t* ui8StopDirection);

#endif /* IT7258_I2C_H_ */
