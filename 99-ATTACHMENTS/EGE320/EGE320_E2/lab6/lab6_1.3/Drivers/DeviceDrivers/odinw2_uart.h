/*
 * odinw2_uart.h
 *
 *  Created on: Feb 15, 2017
 *      Author: cheechein
 */

#ifndef ODINW2_UART_H_
#define ODINW2_UART_H_

#define	ODINW2_UART_TX_PERIPH		SYSCTL_PERIPH_GPIOB
#define	ODINW2_UART_RX_PERIPH		SYSCTL_PERIPH_GPIOQ
#define	ODINW2_UART_DSR_PERIPH		SYSCTL_PERIPH_GPIOE
#define	ODINW2_UART_DTR_PERIPH		SYSCTL_PERIPH_GPIOE
#define	ODINW2_UART_RTS_PERIPH		SYSCTL_PERIPH_GPION
#define	ODINW2_UART_CTS_PERIPH		SYSCTL_PERIPH_GPIOP
#define	ODINW2_UART_RST_PERIPH		SYSCTL_PERIPH_GPIOM
#define	ODINW2_UART_SW0_PERIPH		SYSCTL_PERIPH_GPIOM
#define	ODINW2_UART_SW1_PERIPH		SYSCTL_PERIPH_GPIOM

#define	ODINW2_UART_TX_PORT			GPIO_PORTB_AHB_BASE
#define	ODINW2_UART_RX_PORT			GPIO_PORTQ_AHB_BASE
#define	ODINW2_UART_DSR_PORT		GPIO_PORTE_AHB_BASE
#define	ODINW2_UART_DTR_PORT		GPIO_PORTE_AHB_BASE
#define	ODINW2_UART_RTS_PORT		GPIO_PORTN_AHB_BASE
#define	ODINW2_UART_CTS_PORT		GPIO_PORTP_AHB_BASE
#define	ODINW2_UART_RST_PORT		GPIO_PORTM_AHB_BASE
#define	ODINW2_UART_SW0_PORT		GPIO_PORTM_AHB_BASE
#define	ODINW2_UART_SW1_PORT		GPIO_PORTM_AHB_BASE

#define	ODINW2_UART_TX_PIN		GPIO_PIN_1
#define	ODINW2_UART_RX_PIN		GPIO_PIN_4
#define	ODINW2_UART_DSR_PIN		GPIO_PIN_1
#define	ODINW2_UART_DTR_PIN		GPIO_PIN_3
#define	ODINW2_UART_RTS_PIN		GPIO_PIN_0
#define	ODINW2_UART_CTS_PIN		GPIO_PIN_3
#define	ODINW2_UART_RST_PIN		GPIO_PIN_2
#define	ODINW2_UART_SW0_PIN		GPIO_PIN_3
#define	ODINW2_UART_SW1_PIN		GPIO_PIN_4

#define ACTIVATE						"3"
#define DEACTIVATE						"4"

#define WIFISTATUS						"0"
#define INACTIVE						"0"
#define ACTIVE							"1"

#define SSID							"2"

#define AUTHENTICATION					"5"
#define OPEN							"1"
#define WPA_WPA2_PSK					"2"
#define LEAP							"3"
#define PEAP							"4"

#define PASSPHASE						"8"

#define IPV4_MODE						"100"
#define STATIC							"1"
#define DHCP							"2"

//*****************************************************************************
// Prototypes for the APIs.
//*****************************************************************************

void ODINW2PinInit(uint32_t ui32SysClock);
void ODINW2BTLocalAddress(char* pui8LocalAddress);
int8_t ODINW2ConnectPeer(char* pui8ProfileName, char* pui8RemoteAddress);
uint8_t ODINW2ListenPeer(uint8_t* ui8ProfileName, uint8_t* ui8ConnectionType, char* pui8RemoteAddress);
bool ODINW2DataMode(char* ui8mode);
void ODINW2DataTx(uint8_t ui8DataTx);
char ODINW2DataRx(void);
bool ODINW2WiFiStationConfig(uint32_t ui32Base, char* pui8ConfigID, char* pui8ParameterTag, char* pui8ParameterValue);
bool ODINW2WiFiStationConfigAction(uint32_t ui32Base, char* pui8ConfigID, char* pui8Action);


#endif /* DRIVERS_DEVICEDRIVERS_ODINW2_UART_H_ */
