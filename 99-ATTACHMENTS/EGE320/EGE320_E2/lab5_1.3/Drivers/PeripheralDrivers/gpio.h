//*****************************************************************************
// gpio.h - Defines and Macros for GPIO API.
//
// Copyright (c) 2005-2015 Texas Instruments Incorporated.  All rights reserved.
// Software License Agreement
//
//   Redistribution and use in source and binary forms, with or without
//   modification, are permitted provided that the following conditions
//   are met:
//
//   Redistributions of source code must retain the above copyright
//   notice, this list of conditions and the following disclaimer.
//
//   Redistributions in binary form must reproduce the above copyright
//   notice, this list of conditions and the following disclaimer in the
//   documentation and/or other materials provided with the
//   distribution.
//
//   Neither the name of Texas Instruments Incorporated nor the names of
//   its contributors may be used to endorse or promote products derived
//   from this software without specific prior written permission.
//
// THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS
// "AS IS" AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT
// LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR
// A PARTICULAR PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT
// OWNER OR CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL,
// SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT
// LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE,
// DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY
// THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT
// (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE
// OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
//
// This is part of revision 2.1.2.111 of the Tiva Peripheral Driver Library.
//*****************************************************************************
#ifndef _GPIO_H_
#define _GPIO_H_

//*****************************************************************************
// The following are defines for the base address of the GPIO peripherals
//*****************************************************************************
#define GPIO_PORTA_AHB_BASE     				0x40058000  // GPIO Port A (high speed)
#define GPIO_PORTB_AHB_BASE     				0x40059000  // GPIO Port B (high speed)
#define GPIO_PORTC_AHB_BASE    					0x4005A000  // GPIO Port C (high speed)
#define GPIO_PORTD_AHB_BASE     				0x4005B000  // GPIO Port D (high speed)
#define GPIO_PORTE_AHB_BASE     				0x4005C000  // GPIO Port E (high speed)
#define GPIO_PORTF_AHB_BASE     				0x4005D000  // GPIO Port F (high speed)
#define GPIO_PORTG_AHB_BASE     				0x4005E000  // GPIO Port G (high speed)
#define GPIO_PORTH_AHB_BASE     				0x4005F000  // GPIO Port H (high speed)
#define GPIO_PORTJ_AHB_BASE     				0x40060000  // GPIO Port J (high speed)
#define GPIO_PORTK_AHB_BASE     				0x40061000  // GPIO Port K (high speed)
#define GPIO_PORTL_AHB_BASE     				0x40062000  // GPIO Port L (high speed)
#define GPIO_PORTM_AHB_BASE     				0x40063000  // GPIO Port M (high speed)
#define GPIO_PORTN_AHB_BASE     				0x40064000  // GPIO Port N (high speed)
#define GPIO_PORTP_AHB_BASE     				0x40065000  // GPIO Port P (high speed)
#define GPIO_PORTQ_AHB_BASE     				0x40066000  // GPIO Port Q (high speed)
#define GPIO_PORTR_AHB_BASE     				0x40067000  // GPIO Port R (high speed)
#define GPIO_PORTS_AHB_BASE     				0x40068000  // GPIO Port S (high speed)
#define GPIO_PORTT_AHB_BASE     				0x40069000  // GPIO Port T (high speed)

//*****************************************************************************
// The following are defines for the GPIO register offsets.
//*****************************************************************************
#define GPIO_O_DATA             				0x00000000  // GPIO Data
#define GPIO_O_DIR              				0x00000400  // GPIO Direction
#define GPIO_O_IS               				0x00000404  // GPIO Interrupt Sense
#define GPIO_O_IBE              				0x00000408  // GPIO Interrupt Both Edges
#define GPIO_O_IEV              				0x0000040C  // GPIO Interrupt Event
#define GPIO_O_IM               				0x00000410  // GPIO Interrupt Mask
#define GPIO_O_RIS              				0x00000414  // GPIO Raw Interrupt Status
#define GPIO_O_MIS              				0x00000418  // GPIO Masked Interrupt Status
#define GPIO_O_ICR              				0x0000041C  // GPIO Interrupt Clear
#define GPIO_O_AFSEL            				0x00000420  // GPIO Alternate Function Select
#define GPIO_O_DR2R             				0x00000500  // GPIO 2-mA Drive Select
#define GPIO_O_DR4R             				0x00000504  // GPIO 4-mA Drive Select
#define GPIO_O_DR8R             				0x00000508  // GPIO 8-mA Drive Select
#define GPIO_O_ODR              				0x0000050C  // GPIO Open Drain Select
#define GPIO_O_PUR              				0x00000510  // GPIO Pull-Up Select
#define GPIO_O_PDR              				0x00000514  // GPIO Pull-Down Select
#define GPIO_O_SLR              				0x00000518  // GPIO Slew Rate Control Select
#define GPIO_O_DEN              				0x0000051C  // GPIO Digital Enable
#define GPIO_O_LOCK             				0x00000520  // GPIO Lock
#define GPIO_O_CR               				0x00000524  // GPIO Commit
#define GPIO_O_AMSEL            				0x00000528  // GPIO Analog Mode Select
#define GPIO_O_PCTL             				0x0000052C  // GPIO Port Control
#define GPIO_O_ADCCTL           				0x00000530  // GPIO ADC Control
#define GPIO_O_DMACTL           				0x00000534  // GPIO DMA Control
#define GPIO_O_SI               				0x00000538  // GPIO Select Interrupt
#define GPIO_O_DR12R            				0x0000053C  // GPIO 12-mA Drive Select
#define GPIO_O_WAKEPEN          				0x00000540  // GPIO Wake Pin Enable
#define GPIO_O_WAKELVL          				0x00000544  // GPIO Wake Level
#define GPIO_O_WAKESTAT         				0x00000548  // GPIO Wake Status
#define GPIO_O_PP               				0x00000FC0  // GPIO Peripheral Property
#define GPIO_O_PC               				0x00000FC4  // GPIO Peripheral Configuration
#define GPIO_O_PERIPHLID4       				0x00000FD0  // GPIO Peripheral Identification 4
#define GPIO_O_PERIPHLID5       				0x00000FD4  // GPIO Peripheral Identification 5
#define GPIO_O_PERIPHLID6       				0x00000FD8  // GPIO Peripheral Identification 6
#define GPIO_O_PERIPHLID7       				0x00000FDC  // GPIO Peripheral Identification 7
#define GPIO_O_PERIPHLID0       				0x00000FE0  // GPIO Peripheral Identification 0
#define GPIO_O_PERIPHLID1       				0x00000FE4  // GPIO Peripheral Identification 1
#define GPIO_O_PERIPHLID2       				0x00000FE8  // GPIO Peripheral Identification 2
#define GPIO_O_PERIPHLID3       				0x00000FEC  // GPIO Peripheral Identification 3
#define GPIO_O_PCELLID0  	    				0x00000FF0  // GPIO PrimeCell Identification 0
#define GPIO_O_PCELLID1  	    				0x00000FF4  // GPIO PrimeCell Identification 1
#define GPIO_O_PCELLID2  	   					0x00000FF8  // GPIO PrimeCell Identification 2
#define GPIO_O_PCELLID3  	    				0x00000FFC  // GPIO PrimeCell Identification 3

//*****************************************************************************
// The following are defines for the bit fields in the GPIO_O_IM register.
//*****************************************************************************
#define GPIO_IM_DMAIME          				0x00000100  // GPIO uDMA Done Interrupt Mask Enable
#define GPIO_IM_GPIO_M          				0x000000FF  // GPIO Interrupt Mask Enable

//*****************************************************************************
// The following are defines for the bit fields in the GPIO_O_RIS register.
//*****************************************************************************
#define GPIO_RIS_DMARIS         				0x00000100  // GPIO uDMA Done Interrupt Raw Status
#define GPIO_RIS_GPIO_M         				0x000000FF  // GPIO Interrupt Raw Status

//*****************************************************************************
// The following are defines for the bit fields in the GPIO_O_MIS register.
//*****************************************************************************
#define GPIO_MIS_DMAMIS         				0x00000100  // GPIO uDMA Done Masked Interrupt Status
#define GPIO_MIS_GPIO_M         				0x000000FF  // GPIO Masked Interrupt Status

//*****************************************************************************
// The following are defines for the bit fields in the GPIO_O_ICR register.
//*****************************************************************************
#define GPIO_ICR_DMAIC          				0x00000100  // GPIO uDMA Interrupt Clear
#define GPIO_ICR_GPIO_M         				0x000000FF  // GPIO Interrupt Clear

//*****************************************************************************
// The following are defines for the bit fields in the GPIO_O_LOCK register.
//*****************************************************************************
#define GPIO_LOCK_M             				0xFFFFFFFF  // GPIO Lock
#define GPIO_LOCK_UNLOCKED      				0x00000000  // The GPIOCR register is unlocked and may be modified
#define GPIO_LOCK_LOCKED        				0x00000001  // The GPIOCR register is locked and may not be modified
#define GPIO_LOCK_KEY           				0x4C4F434B  // Unlocks the GPIO_CR register

//*****************************************************************************
// The following are defines for the bit fields in the GPIO_O_SI register.
//*****************************************************************************
#define GPIO_SI_SUM             				0x00000001  // Summary Interrupt

//*****************************************************************************
// The following are defines for the bit fields in the GPIO_O_DR12R register.
//*****************************************************************************
#define GPIO_DR12R_DRV12_M      				0x000000FF  // Output Pad 12-mA Drive Enable
#define GPIO_DR12R_DRV12_12MA   				0x00000001  // The corresponding GPIO pin has 12-mA drive.

//*****************************************************************************
// The following are defines for the bit fields in the GPIO_O_WAKEPEN register.
//*****************************************************************************
#define GPIO_WAKEPEN_WAKEP4     				0x00000010  // P[4] Wake Enable
#define GPIO_WAKEPEN_WAKEP5     				0x00000020  // P[5] Wake Enable
#define GPIO_WAKEPEN_WAKEP6     				0x00000040  // P[6] Wake Enable
#define GPIO_WAKEPEN_WAKEP7     				0x00000080  // P[7] Wake Enable

//*****************************************************************************
// The following are defines for the bit fields in the GPIO_O_WAKELVL register.
//*****************************************************************************
#define GPIO_WAKELVL_WAKELVL4   				0x00000010  // P[4] Wake Level
#define GPIO_WAKELVL_WAKELVL5   				0x00000020  // P[5] Wake Level
#define GPIO_WAKELVL_WAKELVL6   				0x00000040  // P[6] Wake Level
#define GPIO_WAKELVL_WAKELVL7   				0x00000080  // P[7] Wake Level

//*****************************************************************************
// The following are defines for the bit fields in the GPIO_O_WAKESTAT register.
//*****************************************************************************
#define GPIO_WAKESTAT_STAT4     				0x00000010  // P[4] Wake Status
#define GPIO_WAKESTAT_STAT5     				0x00000020  // P[5] Wake Status
#define GPIO_WAKESTAT_STAT6     				0x00000040  // P[6] Wake Status
#define GPIO_WAKESTAT_STAT7     				0x00000080  // P[7] Wake Status

//*****************************************************************************
// The following are defines for the bit fields in the GPIO_O_PP register.
//*****************************************************************************
#define GPIO_PP_EDE             				0x00000001  // Extended Drive Enable

//*****************************************************************************
// The following are defines for the bit fields in the GPIO_O_PC register.
//*****************************************************************************
#define GPIO_PC_EDM7_M          				0x0000C000  // Extended Drive Mode Bit 7
#define GPIO_PC_EDM6_M          				0x00003000  // Extended Drive Mode Bit 6
#define GPIO_PC_EDM5_M          				0x00000C00  // Extended Drive Mode Bit 5
#define GPIO_PC_EDM4_M         	 				0x00000300  // Extended Drive Mode Bit 4
#define GPIO_PC_EDM3_M          				0x000000C0  // Extended Drive Mode Bit 3
#define GPIO_PC_EDM2_M          				0x00000030  // Extended Drive Mode Bit 2
#define GPIO_PC_EDM1_M          				0x0000000C  // Extended Drive Mode Bit 1
#define GPIO_PC_EDM0_M          				0x00000003  // Extended Drive Mode Bit 0
#define GPIO_PC_EDM0_DISABLE    				0x00000000  // Drive values of 2, 4 and 8 mA are maintained.
#define GPIO_PC_EDM0_6MA        				0x00000001  // An additional 6 mA option is provided
#define GPIO_PC_EDM0_PLUS2MA    				0x00000003  // A 2 mA driver is always enabled;
#define GPIO_PC_EDM7_S          				14
#define GPIO_PC_EDM6_S          				12
#define GPIO_PC_EDM5_S          				10
#define GPIO_PC_EDM4_S          				8
#define GPIO_PC_EDM3_S          				6
#define GPIO_PC_EDM2_S          				4
#define GPIO_PC_EDM1_S          				2





//*****************************************************************************
// The following values define the bit field for the ui8Pins argument to several of the APIs.
//*****************************************************************************
#define GPIO_PIN_0              				0x00000001  // GPIO pin 0
#define GPIO_PIN_1              				0x00000002  // GPIO pin 1
#define GPIO_PIN_2             				 	0x00000004  // GPIO pin 2
#define GPIO_PIN_3             					0x00000008  // GPIO pin 3
#define GPIO_PIN_4              				0x00000010  // GPIO pin 4
#define GPIO_PIN_5             					0x00000020  // GPIO pin 5
#define GPIO_PIN_6             					0x00000040  // GPIO pin 6
#define GPIO_PIN_7              				0x00000080  // GPIO pin 7

//*****************************************************************************
// Values that can be passed to GPIODirModeSet as the ui32PinIO parameter, and
// returned from GPIODirModeGet.
//*****************************************************************************
#define GPIO_DIR_MODE_IN        				0x00000000  // Pin is a GPIO input
#define GPIO_DIR_MODE_OUT       				0x00000001  // Pin is a GPIO output
#define GPIO_DIR_MODE_HW        				0x00000002  // Pin is a peripheral function

//*****************************************************************************
// Values that can be passed to GPIOIntEnable() and GPIOIntDisable() functions
// in the ui32IntFlags parameter.
//*****************************************************************************
#define GPIO_INT_PIN_0          				0x00000001
#define GPIO_INT_PIN_1          				0x00000002
#define GPIO_INT_PIN_2          				0x00000004
#define GPIO_INT_PIN_3          				0x00000008
#define GPIO_INT_PIN_4          				0x00000010
#define GPIO_INT_PIN_5          				0x00000020
#define GPIO_INT_PIN_6          				0x00000040
#define GPIO_INT_PIN_7          				0x00000080
#define GPIO_INT_DMA            				0x00000100

//*****************************************************************************
// Values that can be passed to GPIOIntTypeSet as the ui32IntType parameter,
// and returned from GPIOIntTypeGet.
//*****************************************************************************
#define GPIO_FALLING_EDGE       				0x00000000  // Interrupt on falling edge
#define GPIO_RISING_EDGE        				0x00000004  // Interrupt on rising edge
#define GPIO_BOTH_EDGES         				0x00000001  // Interrupt on both edges
#define GPIO_LOW_LEVEL          				0x00000002  // Interrupt on low level
#define GPIO_HIGH_LEVEL         				0x00000006  // Interrupt on high level
#define GPIO_DISCRETE_INT       				0x00010000  // Interrupt for individual pins

//*****************************************************************************
// Values that can be passed to GPIOPadConfigSet as the ui32Strength parameter,
// and returned by GPIOPadConfigGet in the *pui32Strength parameter.
//*****************************************************************************
#define GPIO_STRENGTH_2MA       				0x00000001  // 2mA drive strength
#define GPIO_STRENGTH_4MA       				0x00000002  // 4mA drive strength
#define GPIO_STRENGTH_6MA       				0x00000065  // 6mA drive strength
#define GPIO_STRENGTH_8MA       				0x00000067  // 8mA drive strength
#define GPIO_STRENGTH_8MA_SC    				0x0000006F  // 8mA drive with slew rate control
#define GPIO_STRENGTH_10MA      				0x00000075  // 10mA drive strength
#define GPIO_STRENGTH_12MA      				0x00000077  // 12mA drive strength

//*****************************************************************************
// Values that can be passed to GPIOPadConfigSet as the ui32PadType parameter,
// and returned by GPIOPadConfigGet in the *pui32PadType parameter.
//*****************************************************************************
#define GPIO_PIN_TYPE_STD       				0x00000008  // Push-pull
#define GPIO_PIN_TYPE_STD_WPU   				0x0000000A  // Push-pull with weak pull-up
#define GPIO_PIN_TYPE_STD_WPD   				0x0000000C  // Push-pull with weak pull-down
#define GPIO_PIN_TYPE_OD        				0x00000009  // Open-drain
#define GPIO_PIN_TYPE_ANALOG    				0x00000000  // Analog comparator
#define GPIO_PIN_TYPE_WAKE_HIGH 				0x00000208  // Hibernate wake, high
#define GPIO_PIN_TYPE_WAKE_LOW  				0x00000108  // Hibernate wake, low

//*****************************************************************************
// Values that can be passed to GPIOPinConfigure()
//*****************************************************************************
#define GPIO_PA0_U0RX           				0x00000001
#define GPIO_PA0_I2C9SCL        				0x00000002
#define GPIO_PA0_T0CCP0         				0x00000003
#define GPIO_PA0_CAN0RX         				0x00000007

#define GPIO_PA1_U0TX           				0x00000401
#define GPIO_PA1_I2C9SDA        				0x00000402
#define GPIO_PA1_T0CCP1         				0x00000403
#define GPIO_PA1_CAN0TX         				0x00000407

#define GPIO_PA2_U4RX           				0x00000801
#define GPIO_PA2_I2C8SCL        				0x00000802
#define GPIO_PA2_T1CCP0         				0x00000803
#define GPIO_PA2_SSI0CLK        				0x0000080F

#define GPIO_PA3_U4TX           				0x00000C01
#define GPIO_PA3_I2C8SDA        				0x00000C02
#define GPIO_PA3_T1CCP1         				0x00000C03
#define GPIO_PA3_SSI0FSS        				0x00000C0F

#define GPIO_PA4_U3RX          					0x00001001
#define GPIO_PA4_T2CCP0        					0x00001003
#define GPIO_PA4_I2C7SCL        				0x00001002
#define GPIO_PA4_SSI0XDAT0      				0x0000100F

#define GPIO_PA5_U3TX           				0x00001401
#define GPIO_PA5_T2CCP1         				0x00001403
#define GPIO_PA5_I2C7SDA        				0x00001402
#define GPIO_PA5_SSI0XDAT1      				0x0000140F

#define GPIO_PA6_U2RX           				0x00001801
#define GPIO_PA6_I2C6SCL        				0x00001802
#define GPIO_PA6_T3CCP0         				0x00001803
#define GPIO_PA6_USB0EPEN       				0x00001805
#define GPIO_PA6_SSI0XDAT2      				0x0000180D
#define GPIO_PA6_EN0RXCK        				0x0000180E
#define GPIO_PA6_EPI0S8         				0x0000180F

#define GPIO_PA7_U2TX           				0x00001C01
#define GPIO_PA7_I2C6SDA        				0x00001C02
#define GPIO_PA7_T3CCP1         				0x00001C03
#define GPIO_PA7_USB0PFLT       				0x00001C05
#define GPIO_PA7_USB0EPEN       				0x00001C0B
#define GPIO_PA7_SSI0XDAT3      				0x00001C0D
#define GPIO_PA7_EPI0S9         				0x00001C0F

#define GPIO_PB0_U1RX           				0x00010001
#define GPIO_PB0_I2C5SCL        				0x00010002
#define GPIO_PB0_CAN1RX         				0x00010007
#define GPIO_PB0_T4CCP0         				0x00010003

#define GPIO_PB1_U1TX           				0x00010401
#define GPIO_PB1_I2C5SDA        				0x00010402
#define GPIO_PB1_CAN1TX         				0x00010407
#define GPIO_PB1_T4CCP1         				0x00010403

#define GPIO_PB2_T5CCP0         				0x00010803
#define GPIO_PB2_I2C0SCL        				0x00010802
#define GPIO_PB2_EN0MDC         				0x00010805
#define GPIO_PB2_USB0STP        				0x0001080E
#define GPIO_PB2_EPI0S27        				0x0001080F

#define GPIO_PB3_I2C0SDA        				0x00010C02
#define GPIO_PB3_T5CCP1         				0x00010C03
#define GPIO_PB3_EN0MDIO        				0x00010C05
#define GPIO_PB3_USB0CLK        				0x00010C0E
#define GPIO_PB3_EPI0S28        				0x00010C0F

#define GPIO_PB4_U0CTS          				0x00011001
#define GPIO_PB4_I2C5SCL        				0x00011002
#define GPIO_PB4_SSI1FSS        				0x0001100F

#define GPIO_PB5_U0RTS         	 				0x00011401
#define GPIO_PB5_I2C5SDA        				0x00011402
#define GPIO_PB5_SSI1CLK        				0x0001140F

#define GPIO_PB6_I2C6SCL        				0x00011802
#define GPIO_PB6_T6CCP0         				0x00011803

#define GPIO_PB7_I2C6SDA        				0x00011C02
#define GPIO_PB7_T6CCP1         				0x00011C03

#define GPIO_PC0_TCK            				0x00020001
#define GPIO_PC0_SWCLK          				0x00020001

#define GPIO_PC1_TMS            				0x00020401
#define GPIO_PC1_SWDIO          				0x00020401

#define GPIO_PC2_TDI            				0x00020801

#define GPIO_PC3_SWO            				0x00020C01
#define GPIO_PC3_TDO            				0x00020C01

#define GPIO_PC4_U7RX           				0x00021001
#define GPIO_PC4_T7CCP0         				0x00021003
#define GPIO_PC4_EPI0S7         				0x0002100F

#define GPIO_PC5_U7TX           				0x00021401
#define GPIO_PC5_T7CCP1         				0x00021403
#define GPIO_PC5_RTCCLK         				0x00021407
#define GPIO_PC5_EPI0S6         				0x0002140F

#define GPIO_PC6_U5RX           				0x00021801
#define GPIO_PC6_EPI0S5         				0x0002180F

#define GPIO_PC7_U5TX           				0x00021C01
#define GPIO_PC7_EPI0S4         				0x00021C0F

#define GPIO_PD0_I2C7SCL        				0x00030002
#define GPIO_PD0_T0CCP0         				0x00030003
#define GPIO_PD0_C0O            				0x00030005
#define GPIO_PD0_SSI2XDAT1      				0x0003000F

#define GPIO_PD1_I2C7SDA        				0x00030402
#define GPIO_PD1_T0CCP1         				0x00030403
#define GPIO_PD1_C1O            				0x00030405
#define GPIO_PD1_SSI2XDAT0      				0x0003040F

#define GPIO_PD2_I2C8SCL        				0x00030802
#define GPIO_PD2_T1CCP0         				0x00030803
#define GPIO_PD2_C2O            				0x00030805
#define GPIO_PD2_SSI2FSS        				0x0003080F

#define GPIO_PD3_I2C8SDA        				0x00030C02
#define GPIO_PD3_T1CCP1         				0x00030C03
#define GPIO_PD3_SSI2CLK        				0x00030C0F

#define GPIO_PD4_U2RX           				0x00031001
#define GPIO_PD4_T3CCP0         				0x00031003
#define GPIO_PD4_SSI1XDAT2      				0x0003100F

#define GPIO_PD5_U2TX           				0x00031401
#define GPIO_PD5_T3CCP1         				0x00031403
#define GPIO_PD5_SSI1XDAT3      				0x0003140F

#define GPIO_PD6_U2RTS          				0x00031801
#define GPIO_PD6_T4CCP0         				0x00031803
#define GPIO_PD6_USB0EPEN       				0x00031805
#define GPIO_PD6_SSI2XDAT3      				0x0003180F

#define GPIO_PD7_U2CTS          				0x00031C01
#define GPIO_PD7_T4CCP1         				0x00031C03
#define GPIO_PD7_USB0PFLT       				0x00031C05
#define GPIO_PD7_NMI            				0x00031C08
#define GPIO_PD7_SSI2XDAT2     	 				0x00031C0F

#define GPIO_PE0_U1RTS          				0x00040001

#define GPIO_PE1_U1DSR          				0x00040401

#define GPIO_PE2_U1DCD          				0x00040801

#define GPIO_PE3_U1DTR          				0x00040C01
#define GPIO_PE3_OWIRE          				0x00040C05

#define GPIO_PE4_U1RI           				0x00041001
#define GPIO_PE4_SSI1XDAT0      				0x0004100F

#define GPIO_PE5_SSI1XDAT1      				0x0004140F

#define GPIO_PE6_U0CTS          				0x00041801
#define GPIO_PE6_I2C9SCL        				0x00041802

#define GPIO_PE7_U0RTS          				0x00041C01
#define GPIO_PE7_I2C9SDA        				0x00041C02
#define GPIO_PE7_NMI            				0x00041C08

#define GPIO_PF0_EN0LED0        				0x00050005
#define GPIO_PF0_M0PWM0         				0x00050006
#define GPIO_PF0_SSI3XDAT1      				0x0005000E
#define GPIO_PF0_TRD2           				0x0005000F

#define GPIO_PF1_EN0LED2        				0x00050405
#define GPIO_PF1_M0PWM1         				0x00050406
#define GPIO_PF1_SSI3XDAT0      				0x0005040E
#define GPIO_PF1_TRD1           				0x0005040F

#define GPIO_PF2_EN0MDC         				0x00050805
#define GPIO_PF2_M0PWM2         				0x00050806
#define GPIO_PF2_SSI3FSS        				0x0005080E
#define GPIO_PF2_TRD0           				0x0005080F

#define GPIO_PF3_EN0MDIO        				0x00050C05
#define GPIO_PF3_M0PWM3         				0x00050C06
#define GPIO_PF3_SSI3CLK        				0x00050C0E
#define GPIO_PF3_TRCLK          				0x00050C0F

#define GPIO_PF4_EN0LED1        				0x00051005
#define GPIO_PF4_M0FAULT0       				0x00051006
#define GPIO_PF4_SSI3XDAT2      				0x0005100E
#define GPIO_PF4_TRD3           				0x0005100F

#define GPIO_PF5_SSI3XDAT3      				0x0005140E

#define GPIO_PF6_LCDMCLK        				0x0005180F

#define GPIO_PF7_LCDDATA02      				0x00051C0F

#define GPIO_PG0_I2C1SCL        				0x00060002
#define GPIO_PG0_EN0PPS         				0x00060005
#define GPIO_PG0_M0PWM4         				0x00060006
#define GPIO_PG0_EPI0S11        				0x0006000F

#define GPIO_PG1_I2C1SDA        				0x00060402
#define GPIO_PG1_M0PWM5         				0x00060406
#define GPIO_PG1_EPI0S10        				0x0006040F

#define GPIO_PG2_I2C2SCL       					0x00060802
#define GPIO_PG2_EN0TXCK        				0x0006080E
#define GPIO_PG2_SSI2XDAT3      				0x0006080F

#define GPIO_PG3_I2C2SDA        				0x00060C02
#define GPIO_PG3_EN0TXEN        				0x00060C0E
#define GPIO_PG3_SSI2XDAT2      				0x00060C0F

#define GPIO_PG4_U0CTS          				0x00061001
#define GPIO_PG4_I2C3SCL        				0x00061002
#define GPIO_PG4_OWIRE          				0x00061005
#define GPIO_PG4_EN0TXD0        				0x0006100E
#define GPIO_PG4_SSI2XDAT1      				0x0006100F

#define GPIO_PG5_U0RTS          				0x00061401
#define GPIO_PG5_I2C3SDA        				0x00061402
#define GPIO_PG5_OWALT          				0x00061405
#define GPIO_PG5_EN0TXD1        				0x0006140E
#define GPIO_PG5_SSI2XDAT0      				0x0006140F

#define GPIO_PG6_I2C4SCL        				0x00061802
#define GPIO_PG6_OWIRE          				0x00061805
#define GPIO_PG6_EN0RXER        				0x0006180E
#define GPIO_PG6_SSI2FSS        				0x0006180F

#define GPIO_PG7_I2C4SDA        				0x00061C02
#define GPIO_PG7_OWIRE          				0x00061C05
#define GPIO_PG7_EN0RXDV        				0x00061C0E
#define GPIO_PG7_SSI2CLK        				0x00061C0F

#define GPIO_PH0_U0RTS          				0x00070001
#define GPIO_PH0_EPI0S0         				0x0007000F

#define GPIO_PH1_U0CTS          				0x00070401
#define GPIO_PH1_EPI0S1         				0x0007040F

#define GPIO_PH2_U0DCD          				0x00070801
#define GPIO_PH2_EPI0S2         				0x0007080F

#define GPIO_PH3_U0DSR          				0x00070C01
#define GPIO_PH3_EPI0S3         				0x00070C0F

#define GPIO_PH4_U0DTR          				0x00071001

#define GPIO_PH5_U0RI           				0x00071401
#define GPIO_PH5_EN0PPS         				0x00071405

#define GPIO_PH6_U5RX           				0x00071801
#define GPIO_PH6_U7RX           				0x00071802

#define GPIO_PH7_U5TX           				0x00071C01
#define GPIO_PH7_U7TX           				0x00071C02

#define GPIO_PJ0_U3RX           				0x00080001
#define GPIO_PJ0_EN0PPS         				0x00080005

#define GPIO_PJ1_U3TX           				0x00080401

#define GPIO_PJ2_U2RTS          				0x00080801
#define GPIO_PJ2_LCDDATA14      				0x0008080F

#define GPIO_PJ3_U2CTS          				0x00080C01
#define GPIO_PJ3_LCDDATA15      				0x00080C0F

#define GPIO_PJ4_U3RTS          				0x00081001
#define GPIO_PJ4_LCDDATA16      				0x0008100F

#define GPIO_PJ5_U3CTS          				0x00081401
#define GPIO_PJ5_LCDDATA17      				0x0008140F

#define GPIO_PJ6_U4RTS          				0x00081801
#define GPIO_PJ6_LCDAC          				0x0008180F

#define GPIO_PJ7_U4CTS          				0x00081C01

#define GPIO_PK0_U4RX           				0x00090001
#define GPIO_PK0_EPI0S0         				0x0009000F

#define GPIO_PK1_U4TX           				0x00090401
#define GPIO_PK1_EPI0S1         				0x0009040F

#define GPIO_PK2_U4RTS          				0x00090801
#define GPIO_PK2_EPI0S2         				0x0009080F

#define GPIO_PK3_U4CTS          				0x00090C01
#define GPIO_PK3_EPI0S3         				0x00090C0F

#define GPIO_PK4_I2C3SCL        				0x00091002
#define GPIO_PK4_EN0LED0        				0x00091005
#define GPIO_PK4_M0PWM6         				0x00091006
#define GPIO_PK4_EN0INTRN       				0x00091007
#define GPIO_PK4_EN0RXD3        				0x0009100E
#define GPIO_PK4_EPI0S32        				0x0009100F

#define GPIO_PK5_I2C3SDA        				0x00091402
#define GPIO_PK5_EN0LED2        				0x00091405
#define GPIO_PK5_M0PWM7         				0x00091406
#define GPIO_PK5_EN0RXD2        				0x0009140E
#define GPIO_PK5_EPI0S31       					0x0009140F

#define GPIO_PK6_I2C4SCL        				0x00091802
#define GPIO_PK6_EN0LED1        				0x00091805
#define GPIO_PK6_M0FAULT1       				0x00091806
#define GPIO_PK6_EN0TXD2        				0x0009180E
#define GPIO_PK6_EPI0S25        				0x0009180F

#define GPIO_PK7_U0RI           				0x00091C01
#define GPIO_PK7_I2C4SDA        				0x00091C02
#define GPIO_PK7_RTCCLK         				0x00091C05
#define GPIO_PK7_M0FAULT2       				0x00091C06
#define GPIO_PK7_EN0TXD3        				0x00091C0E
#define GPIO_PK7_EPI0S24        				0x00091C0F

#define GPIO_PL0_I2C2SDA        				0x000A0002
#define GPIO_PL0_M0FAULT3       				0x000A0006
#define GPIO_PL0_USB0D0         				0x000A000E
#define GPIO_PL0_EPI0S16        				0x000A000F

#define GPIO_PL1_I2C2SCL        				0x000A0402
#define GPIO_PL1_PHA0           				0x000A0406
#define GPIO_PL1_USB0D1         				0x000A040E
#define GPIO_PL1_EPI0S17        				0x000A040F

#define GPIO_PL2_C0O            				0x000A0805
#define GPIO_PL2_PHB0           				0x000A0806
#define GPIO_PL2_USB0D2         				0x000A080E
#define GPIO_PL2_EPI0S18        				0x000A080F

#define GPIO_PL3_C1O            				0x000A0C05
#define GPIO_PL3_IDX0           				0x000A0C06
#define GPIO_PL3_USB0D3         				0x000A0C0E
#define GPIO_PL3_EPI0S19        				0x000A0C0F

#define GPIO_PL4_T0CCP0         				0x000A1003
#define GPIO_PL4_USB0D4         				0x000A100E
#define GPIO_PL4_EPI0S26        				0x000A100F

#define GPIO_PL5_T0CCP1         				0x000A1403
#define GPIO_PL5_EPI0S33        				0x000A140F
#define GPIO_PL5_USB0D5         				0x000A140E

#define GPIO_PL6_T1CCP0         				0x000A1803

#define GPIO_PL7_T1CCP1         				0x000A1C03

#define GPIO_PM0_T2CCP0         				0x000B0003
#define GPIO_PM0_EPI0S15        				0x000B000F

#define GPIO_PM1_T2CCP1         				0x000B0403
#define GPIO_PM1_EPI0S14        				0x000B040F

#define GPIO_PM2_T3CCP0         				0x000B0803
#define GPIO_PM2_EPI0S13        				0x000B080F

#define GPIO_PM3_T3CCP1         				0x000B0C03
#define GPIO_PM3_EPI0S12        				0x000B0C0F

#define GPIO_PM4_U0CTS          				0x000B1001
#define GPIO_PM4_T4CCP0         				0x000B1003
#define GPIO_PM4_EN0RREF_CLK    				0x000B100E

#define GPIO_PM5_U0DCD          				0x000B1401
#define GPIO_PM5_T4CCP1         				0x000B1403

#define GPIO_PM6_U0DSR          				0x000B1801
#define GPIO_PM6_T5CCP0         				0x000B1803
#define GPIO_PM6_EN0CRS         				0x000B180E

#define GPIO_PM7_U0RI           				0x000B1C01
#define GPIO_PM7_T5CCP1         				0x000B1C03
#define GPIO_PM7_EN0COL         				0x000B1C0E

#define GPIO_PN0_U1RTS          				0x000C0001

#define GPIO_PN1_U1CTS         					0x000C0401

#define GPIO_PN2_U1DCD          				0x000C0801
#define GPIO_PN2_U2RTS          				0x000C0802
#define GPIO_PN2_EPI0S29        				0x000C080F

#define GPIO_PN3_U1DSR          				0x000C0C01
#define GPIO_PN3_U2CTS          				0x000C0C02
#define GPIO_PN3_EPI0S30        				0x000C0C0F

#define GPIO_PN4_U1DTR          				0x000C1001
#define GPIO_PN4_U3RTS          				0x000C1002
#define GPIO_PN4_I2C2SDA        				0x000C1003
#define GPIO_PN4_EPI0S34        				0x000C100F

#define GPIO_PN5_U1RI           				0x000C1401
#define GPIO_PN5_U3CTS          				0x000C1402
#define GPIO_PN5_I2C2SCL        				0x000C1403
#define GPIO_PN5_EPI0S35        				0x000C140F

#define GPIO_PN6_U4RTS          				0x000C1802
#define GPIO_PN6_EN0TXER        				0x000C180E
#define GPIO_PN6_LCDDATA13      				0x000C180F

#define GPIO_PN7_U1RTS          				0x000C1C01
#define GPIO_PN7_U4CTS          				0x000C1C02
#define GPIO_PN7_LCDDATA12      				0x000C1C0F

#define GPIO_PP0_U6RX           				0x000D0001
#define GPIO_PP0_T6CCP0         				0x000D0005
#define GPIO_PP0_EN0INTRN       				0x000D0007
#define GPIO_PP0_SSI3XDAT2      				0x000D000F

#define GPIO_PP1_U6TX           				0x000D0401
#define GPIO_PP1_T6CCP1         				0x000D0405
#define GPIO_PP1_SSI3XDAT3      				0x000D040F

#define GPIO_PP2_U0DTR          				0x000D0801
#define GPIO_PP2_USB0NXT        				0x000D080E
#define GPIO_PP2_EPI0S29        				0x000D080F

#define GPIO_PP3_U1CTS          				0x000D0C01
#define GPIO_PP3_U0DCD          				0x000D0C02
#define GPIO_PP3_RTCCLK         				0x000D0C07
#define GPIO_PP3_USB0DIR       					0x000D0C0E
#define GPIO_PP3_EPI0S30        				0x000D0C0F

#define GPIO_PP4_U3RTS          				0x000D1001
#define GPIO_PP4_U0DSR          				0x000D1002
#define GPIO_PP4_OWIRE          				0x000D1004
#define GPIO_PP4_USB0D7        				 	0x000D100E

#define GPIO_PP5_U3CTS          				0x000D1401
#define GPIO_PP5_I2C2SCL        				0x000D1402
#define GPIO_PP5_OWALT          				0x000D1404
#define GPIO_PP5_USB0D6        				 	0x000D140E

#define GPIO_PP6_U1DCD          				0x000D1801
#define GPIO_PP6_I2C2SDA        				0x000D1802

#define GPIO_PP7_OWIRE          				0x000D1C05

#define GPIO_PQ0_T6CCP0         				0x000E0003
#define GPIO_PQ0_SSI3CLK        				0x000E000E
#define GPIO_PQ0_EPI0S20        				0x000E000F

#define GPIO_PQ1_T6CCP1         				0x000E0403
#define GPIO_PQ1_SSI3FSS        				0x000E040E
#define GPIO_PQ1_EPI0S21        				0x000E040F

#define GPIO_PQ2_T7CCP0         				0x000E0803
#define GPIO_PQ2_SSI3XDAT0      				0x000E080E
#define GPIO_PQ2_EPI0S22        				0x000E080F

#define GPIO_PQ3_T7CCP1         				0x000E0C03
#define GPIO_PQ3_SSI3XDAT1      				0x000E0C0E
#define GPIO_PQ3_EPI0S23        				0x000E0C0F

#define GPIO_PQ4_U1RX           				0x000E1001
#define GPIO_PQ4_DIVSCLK        				0x000E1007

#define GPIO_PQ5_U1TX           				0x000E1401
#define GPIO_PQ5_EN0RXD0        				0x000E140E

#define GPIO_PQ6_U1DTR          				0x000E1801
#define GPIO_PQ6_EN0RXD1        				0x000E180E

#define GPIO_PQ7_U1RI           				0x000E1C01

#define GPIO_PR0_U4TX           				0x000F0001
#define GPIO_PR0_I2C1SCL        				0x000F0002
#define GPIO_PR0_M0PWM0         				0x000F0006
#define GPIO_PR0_LCDCP          				0x000F000F

#define GPIO_PR1_U4RX           				0x000F0401
#define GPIO_PR1_I2C1SDA        				0x000F0402
#define GPIO_PR1_M0PWM1         				0x000F0406
#define GPIO_PR1_LCDFP          				0x000F040F

#define GPIO_PR2_I2C2SCL        				0x000F0802
#define GPIO_PR2_M0PWM2         				0x000F0806
#define GPIO_PR2_LCDLP          				0x000F080F

#define GPIO_PR3_I2C2SDA        				0x000F0C02
#define GPIO_PR3_M0PWM3         				0x000F0C06
#define GPIO_PR3_LCDDATA03      				0x000F0C0F

#define GPIO_PR4_I2C3SCL        				0x000F1002
#define GPIO_PR4_T0CCP0         				0x000F1003
#define GPIO_PR4_M0PWM4         				0x000F1006
#define GPIO_PR4_LCDDATA00      				0x000F100F

#define GPIO_PR5_U1RX           				0x000F1401
#define GPIO_PR5_I2C3SDA        				0x000F1402
#define GPIO_PR5_T0CCP1         				0x000F1403
#define GPIO_PR5_M0PWM5         				0x000F1406
#define GPIO_PR5_LCDDATA01      				0x000F140F

#define GPIO_PR6_U1TX           				0x000F1801
#define GPIO_PR6_I2C4SCL        				0x000F1802
#define GPIO_PR6_T1CCP0         				0x000F1803
#define GPIO_PR6_M0PWM6         				0x000F1806
#define GPIO_PR6_LCDDATA04      				0x000F180F

#define GPIO_PR7_I2C4SDA        				0x000F1C02
#define GPIO_PR7_T1CCP1         				0x000F1C03
#define GPIO_PR7_M0PWM7         				0x000F1C06
#define GPIO_PR7_EN0TXEN        				0x000F1C0E
#define GPIO_PR7_LCDDATA05      				0x000F1C0F

#define GPIO_PS0_T2CCP0         				0x00100003
#define GPIO_PS0_M0FAULT0       				0x00100006
#define GPIO_PS0_LCDDATA20      				0x0010000F

#define GPIO_PS1_T2CCP1         				0x00100403
#define GPIO_PS1_M0FAULT1       				0x00100406
#define GPIO_PS1_LCDDATA21      				0x0010040F

#define GPIO_PS2_U1DSR          				0x00100801
#define GPIO_PS2_T3CCP0         				0x00100803
#define GPIO_PS2_M0FAULT2       				0x00100806
#define GPIO_PS2_LCDDATA22      				0x0010080F

#define GPIO_PS3_T3CCP1         				0x00100C03
#define GPIO_PS3_M0FAULT3       				0x00100C06
#define GPIO_PS3_LCDDATA23      				0x00100C0F

#define GPIO_PS4_T4CCP0         				0x00101003
#define GPIO_PS4_PHA0           				0x00101006
#define GPIO_PS4_EN0TXD0        				0x0010100E
#define GPIO_PS4_LCDDATA06      				0x0010100F

#define GPIO_PS5_T4CCP1         				0x00101403
#define GPIO_PS5_PHB0           				0x00101406
#define GPIO_PS5_EN0TXD1        				0x0010140E
#define GPIO_PS5_LCDDATA07      				0x0010140F

#define GPIO_PS6_T5CCP0         				0x00101803
#define GPIO_PS6_IDX0          			 		0x00101806
#define GPIO_PS6_EN0RXER        				0x0010180E
#define GPIO_PS6_LCDDATA08      				0x0010180F

#define GPIO_PS7_T5CCP1         				0x00101C03
#define GPIO_PS7_EN0RXDV        				0x00101C0E
#define GPIO_PS7_LCDDATA09      				0x00101C0F

#define GPIO_PT0_T6CCP0         				0x00110003
#define GPIO_PT0_CAN0RX         				0x00110007
#define GPIO_PT0_EN0RXD0        				0x0011000E
#define GPIO_PT0_LCDDATA10      				0x0011000F

#define GPIO_PT1_T6CCP1         				0x00110403
#define GPIO_PT1_CAN0TX         				0x00110407
#define GPIO_PT1_EN0RXD1        				0x0011040E
#define GPIO_PT1_LCDDATA11      				0x0011040F

#define GPIO_PT2_T7CCP0         				0x00110803
#define GPIO_PT2_CAN1RX         				0x00110807
#define GPIO_PT2_LCDDATA18      				0x0011080F

#define GPIO_PT3_T7CCP1         				0x00110C03
#define GPIO_PT3_CAN1TX         				0x00110C07
#define GPIO_PT3_LCDDATA19      				0x00110C0F





//*****************************************************************************
// Prototypes for the APIs.
//*****************************************************************************
extern void GPIOADCTriggerDisable(uint32_t ui32Port, uint8_t ui8Pins);													//Tested
extern void GPIOADCTriggerEnable(uint32_t ui32Port, uint8_t ui8Pins);													//Tested
extern uint32_t GPIODirModeGet(uint32_t ui32Port, uint8_t ui8Pin);														//Tested
extern void GPIODirModeSet(uint32_t ui32Port, uint8_t ui8Pins, uint32_t ui32PinIO);										//Tested
extern void GPIODMATriggerDisable(uint32_t ui32Port, uint8_t ui8Pins);													//Tested
extern void GPIODMATriggerEnable(uint32_t ui32Port, uint8_t ui8Pins);													//Tested
extern void GPIOIntClear(uint32_t ui32Port, uint32_t ui32IntFlags);														//Tested
extern void GPIOIntDisable(uint32_t ui32Port, uint32_t ui32IntFlags);													//Tested
extern void GPIOIntEnable(uint32_t ui32Port, uint32_t ui32IntFlags);													//Tested
extern void GPIOIntRegister(uint32_t ui32Port, void (*pfnIntHandler)(void));											//Tested
extern uint32_t GPIOIntStatus(uint32_t ui32Port, bool bMasked);															//Tested
extern uint32_t GPIOIntTypeGet(uint32_t ui32Port, uint8_t ui8Pin);														//Tested
extern void GPIOIntTypeSet(uint32_t ui32Port, uint8_t ui8Pins, uint32_t ui32IntType);									//Tested
extern void GPIOIntUnregister(uint32_t ui32Port);																		//Tested
extern void GPIOPadConfigGet(uint32_t ui32Port, uint8_t ui8Pin, uint32_t *pui32Strength, uint32_t *pui32PadType);		//Tested
extern void GPIOPadConfigSet(uint32_t ui32Port, uint8_t ui8Pins, uint32_t ui32Strength, uint32_t ui32PadType);			//Tested
extern void GPIOPinConfigure(uint32_t ui32PinConfig);																	//Tested
extern int32_t GPIOPinRead(uint32_t ui32Port, uint8_t ui8Pins);															//Tested
extern void GPIOPinTypeADC(uint32_t ui32Port, uint8_t ui8Pins);
extern void GPIOPinTypeCAN(uint32_t ui32Port, uint8_t ui8Pins);
extern void GPIOPinTypeCIR (uint32_t ui32Port, uint8_t ui8Pins);
extern void GPIOPinTypeComparator(uint32_t ui32Port, uint8_t ui8Pins);
extern void GPIOPinTypeComparatorOutput(uint32_t ui32Port, uint8_t ui8Pins);
extern void GPIOPinTypeEPI(uint32_t ui32Port, uint8_t ui8Pins);
extern void GPIOPinTypeEthernetLED(uint32_t ui32Port, uint8_t ui8Pins);
extern void GPIOPinTypeEthernetMII(uint32_t ui32Port, uint8_t ui8Pins);
extern void GPIOPinTypeGPIOInput(uint32_t ui32Port, uint8_t ui8Pins);
extern void GPIOPinTypeGPIOOutput(uint32_t ui32Port, uint8_t ui8Pins);
extern void GPIOPinTypeGPIOOutputOD(uint32_t ui32Port, uint8_t ui8Pins);
extern void GPIOPinTypeI2C(uint32_t ui32Port, uint8_t ui8Pins);															//Tested
extern void GPIOPinTypeI2CSCL(uint32_t ui32Port, uint8_t ui8Pins);														//Tested
extern void GPIOPinTypeKBColumn (uint32_t ui32Port, uint8_t ui8Pins);
extern void GPIOPinTypeKBRow (uint32_t ui32Port, uint8_t ui8Pins);
extern void GPIOPinTypeLCD(uint32_t ui32Port, uint8_t ui8Pins);
extern void GPIOPinTypeLEDSeq (uint32_t ui32Port, uint8_t ui8Pins);
extern void GPIOPinTypeLPC (uint32_t ui32Port, uint8_t ui8Pins);
extern void GPIOPinTypePECIRx (uint32_t ui32Port, uint8_t ui8Pins);
extern void GPIOPinTypePECITx (uint32_t ui32Port, uint8_t ui8Pins);
extern void GPIOPinTypePWM(uint32_t ui32Port, uint8_t ui8Pins);
extern void GPIOPinTypeQEI(uint32_t ui32Port, uint8_t ui8Pins);
extern void GPIOPinTypeSSI(uint32_t ui32Port, uint8_t ui8Pins);
extern void GPIOPinTypeTimer(uint32_t ui32Port, uint8_t ui8Pins);
extern void GPIOPinTypeUART(uint32_t ui32Port, uint8_t ui8Pins);
extern void GPIOPinTypeUSBAnalog(uint32_t ui32Port, uint8_t ui8Pins);
extern void GPIOPinTypeUSBDigital(uint32_t ui32Port, uint8_t ui8Pins);
extern void GPIOPinTypeWakeHigh(uint32_t ui32Port, uint8_t ui8Pins);
extern void GPIOPinTypeWakeLow(uint32_t ui32Port, uint8_t ui8Pins);
extern uint32_t GPIOPinWakeStatus(uint32_t ui32Port);
extern void GPIOPinWrite(uint32_t ui32Port, uint8_t ui8Pins, uint8_t ui8Val);											//Tested

#endif // _GPIO_H_
