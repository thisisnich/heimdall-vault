//*****************************************************************************
// interrupt.h - Prototypes for the NVIC Interrupt Controller Driver.
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

#ifndef _INTERRUPT_H_
#define _INTERRUPT_H_

//*****************************************************************************
// The following are defines for interrupts
//*****************************************************************************
#define NUM_INTERRUPTS							130
#define NUM_PRIORITY            				8

//*****************************************************************************
// The following are defines for the NVIC register addresses.
//*****************************************************************************
#define NVIC_EN0                				0xE000E100  // Interrupt 0-31 Set Enable
#define NVIC_EN1                				0xE000E104  // Interrupt 32-63 Set Enable
#define NVIC_EN2                				0xE000E108  // Interrupt 64-95 Set Enable
#define NVIC_EN3                				0xE000E10C  // Interrupt 96-113 Set Enable
#define NVIC_DIS0               				0xE000E180  // Interrupt 0-31 Clear Enable
#define NVIC_DIS1               				0xE000E184  // Interrupt 32-63 Clear Enable
#define NVIC_DIS2               				0xE000E188  // Interrupt 64-95 Clear Enable
#define NVIC_DIS3               				0xE000E18C  // Interrupt 96-113 Clear Enable
#define NVIC_PEND0              				0xE000E200  // Interrupt 0-31 Set Pending
#define NVIC_PEND1              				0xE000E204  // Interrupt 32-63 Set Pending
#define NVIC_PEND2              				0xE000E208  // Interrupt 64-95 Set Pending
#define NVIC_PEND3              				0xE000E20C  // Interrupt 96-113 Set Pending
#define NVIC_UNPEND0            				0xE000E280  // Interrupt 0-31 Clear Pending
#define NVIC_UNPEND1            				0xE000E284  // Interrupt 32-63 Clear Pending
#define NVIC_UNPEND2            				0xE000E288  // Interrupt 64-95 Clear Pending
#define NVIC_UNPEND3            				0xE000E28C  // Interrupt 96-113 Clear Pending
#define NVIC_ACTIVE0            				0xE000E300  // Interrupt 0-31 Active Bit
#define NVIC_ACTIVE1            				0xE000E304  // Interrupt 32-63 Active Bit
#define NVIC_ACTIVE2            				0xE000E308  // Interrupt 64-95 Active Bit
#define NVIC_ACTIVE3            				0xE000E30C  // Interrupt 96-113 Active Bit
#define NVIC_PRI0               				0xE000E400  // Interrupt 0-3 Priority
#define NVIC_PRI1               				0xE000E404  // Interrupt 4-7 Priority
#define NVIC_PRI2               				0xE000E408  // Interrupt 8-11 Priority
#define NVIC_PRI3               				0xE000E40C  // Interrupt 12-15 Priority
#define NVIC_PRI4               				0xE000E410  // Interrupt 16-19 Priority
#define NVIC_PRI5               				0xE000E414  // Interrupt 20-23 Priority
#define NVIC_PRI6               				0xE000E418  // Interrupt 24-27 Priority
#define NVIC_PRI7               				0xE000E41C  // Interrupt 28-31 Priority
#define NVIC_PRI8               				0xE000E420  // Interrupt 32-35 Priority
#define NVIC_PRI9               				0xE000E424  // Interrupt 36-39 Priority
#define NVIC_PRI10              				0xE000E428  // Interrupt 40-43 Priority
#define NVIC_PRI11              				0xE000E42C  // Interrupt 44-47 Priority
#define NVIC_PRI12              				0xE000E430  // Interrupt 48-51 Priority
#define NVIC_PRI13              				0xE000E434  // Interrupt 52-55 Priority
#define NVIC_PRI14              				0xE000E438  // Interrupt 56-59 Priority
#define NVIC_PRI15              				0xE000E43C  // Interrupt 60-63 Priority
#define NVIC_PRI16              				0xE000E440  // Interrupt 64-67 Priority
#define NVIC_PRI17              				0xE000E444  // Interrupt 68-71 Priority
#define NVIC_PRI18              				0xE000E448  // Interrupt 72-75 Priority
#define NVIC_PRI19              				0xE000E44C  // Interrupt 76-79 Priority
#define NVIC_PRI20              				0xE000E450  // Interrupt 80-83 Priority
#define NVIC_PRI21              				0xE000E454  // Interrupt 84-87 Priority
#define NVIC_PRI22              				0xE000E458  // Interrupt 88-91 Priority
#define NVIC_PRI23              				0xE000E45C  // Interrupt 92-95 Priority
#define NVIC_PRI24              				0xE000E460  // Interrupt 96-99 Priority
#define NVIC_PRI25              				0xE000E464  // Interrupt 100-103 Priority
#define NVIC_PRI26              				0xE000E468  // Interrupt 104-107 Priority
#define NVIC_PRI27              				0xE000E46C  // Interrupt 108-111 Priority
#define NVIC_PRI28              				0xE000E470  // Interrupt 112-113 Priority
#define NVIC_SW_TRIG            				0xE000EF00  // Software Trigger Interrupt

#define NVIC_ACTLR              				0xE000E008  // Auxiliary Control
#define NVIC_CPUID              				0xE000ED00  // CPU ID Base
#define NVIC_INT_CTRL           				0xE000ED04  // Interrupt Control and State
#define NVIC_VTABLE             				0xE000ED08  // Vector Table Offset
#define NVIC_APINT              				0xE000ED0C  // Application Interrupt and Reset Control
#define NVIC_SYS_CTRL           				0xE000ED10  // System Control
#define NVIC_CFG_CTRL           				0xE000ED14  // Configuration and Control
#define NVIC_SYS_PRI1          				 	0xE000ED18  // System Handler Priority 1
#define NVIC_SYS_PRI2           				0xE000ED1C  // System Handler Priority 2
#define NVIC_SYS_PRI3           				0xE000ED20  // System Handler Priority 3
#define NVIC_SYS_HND_CTRL       				0xE000ED24  // System Handler Control and State
#define NVIC_FAULT_STAT         				0xE000ED28  // Configurable Fault Status
#define NVIC_HFAULT_STAT        				0xE000ED2C  // Hard Fault Status
#define NVIC_MM_ADDR            				0xE000ED34  // Memory Management Fault Address
#define NVIC_FAULT_ADDR         				0xE000ED38  // Bus Fault Address

#define NVIC_MPU_TYPE           				0xE000ED90  // MPU Type
#define NVIC_MPU_CTRL          					0xE000ED94  // MPU Control
#define NVIC_MPU_NUMBER         				0xE000ED98  // MPU Region Number
#define NVIC_MPU_BASE           				0xE000ED9C  // MPU Region Base Address
#define NVIC_MPU_ATTR           				0xE000EDA0  // MPU Region Attribute and Size
#define NVIC_MPU_BASE1          				0xE000EDA4  // MPU Region Base Address Alias 1
#define NVIC_MPU_ATTR1          				0xE000EDA8  // MPU Region Attribute and Size Alias 1
#define NVIC_MPU_BASE2          				0xE000EDAC  // MPU Region Base Address Alias 2
#define NVIC_MPU_ATTR2          				0xE000EDB0  // MPU Region Attribute and Size Alias 2
#define NVIC_MPU_BASE3          				0xE000EDB4  // MPU Region Base Address Alias 3
#define NVIC_MPU_ATTR3          				0xE000EDB8  // MPU Region Attribute and Size Alias 3

#define NVIC_CPAC               				0xE000ED88  // Coprocessor Access Control
#define NVIC_FPCC               				0xE000EF34  // Floating-Point Context Control
#define NVIC_FPCA               				0xE000EF38  // Floating-Point Context Address
#define NVIC_FPDSC              				0xE000EF3C  // Floating-Point Default Status Control

//*****************************************************************************
// The following are defines for the fault assignments.
//*****************************************************************************
#define FAULT_NMI               				2           // NMI fault
#define FAULT_HARD              				3           // Hard fault
#define FAULT_MPU               				4           // MPU fault
#define FAULT_BUS               				5           // Bus fault
#define FAULT_USAGE             				6           // Usage fault
#define FAULT_SVCALL            				11          // SVCall
#define FAULT_DEBUG             				12          // Debug monitor
#define FAULT_PENDSV            				14          // PendSV
#define FAULT_SYSTICK           				15          // System Tick
#define INT_GPIOA_TM4C129       				16          // GPIO Port A
#define INT_GPIOB_TM4C129       				17          // GPIO Port B
#define INT_GPIOC_TM4C129       				18          // GPIO Port C
#define INT_GPIOD_TM4C129      					19          // GPIO Port D
#define INT_GPIOE_TM4C129       				20          // GPIO Port E
#define INT_UART0_TM4C129       				21          // UART0
#define INT_UART1_TM4C129       				22          // UART1
#define INT_SSI0_TM4C129        				23          // SSI0
#define INT_I2C0_TM4C129        				24          // I2C0
#define INT_PWM0_FAULT_TM4C129  				25          // PWM Fault
#define INT_PWM0_0_TM4C129      				26          // PWM Generator 0
#define INT_PWM0_1_TM4C129      				27          // PWM Generator 1
#define INT_PWM0_2_TM4C129      				28          // PWM Generator 2
#define INT_QEI0_TM4C129        				29          // QEI0
#define INT_ADC0SS0_TM4C129     				30          // ADC0 Sequence 0
#define INT_ADC0SS1_TM4C129     				31          // ADC0 Sequence 1
#define INT_ADC0SS2_TM4C129     				32          // ADC0 Sequence 2
#define INT_ADC0SS3_TM4C129     				33          // ADC0 Sequence 3
#define INT_WATCHDOG_TM4C129    				34          // Watchdog Timers 0 and 1
#define INT_TIMER0A_TM4C129     				35          // 16/32-Bit Timer 0A
#define INT_TIMER0B_TM4C129     				36          // 16/32-Bit Timer 0B
#define INT_TIMER1A_TM4C129     				37          // 16/32-Bit Timer 1A
#define INT_TIMER1B_TM4C129     				38          // 16/32-Bit Timer 1B
#define INT_TIMER2A_TM4C129     				39          // 16/32-Bit Timer 2A
#define INT_TIMER2B_TM4C129     				40          // 16/32-Bit Timer 2B
#define INT_COMP0_TM4C129       				41          // Analog Comparator 0
#define INT_COMP1_TM4C129       				42          // Analog Comparator 1
#define INT_COMP2_TM4C129       				43          // Analog Comparator 2
#define INT_SYSCTL_TM4C129      				44          // System Control
#define INT_FLASH_TM4C129       				45          // Flash Memory Control
#define INT_GPIOF_TM4C129       				46          // GPIO Port F
#define INT_GPIOG_TM4C129       				47          // GPIO Port G
#define INT_GPIOH_TM4C129       				48          // GPIO Port H
#define INT_UART2_TM4C129       				49          // UART2
#define INT_SSI1_TM4C129        				50          // SSI1
#define INT_TIMER3A_TM4C129     				51          // 16/32-Bit Timer 3A
#define INT_TIMER3B_TM4C129     				52          // 16/32-Bit Timer 3B
#define INT_I2C1_TM4C129        				53          // I2C1
#define INT_CAN0_TM4C129        				54          // CAN 0
#define INT_CAN1_TM4C129        				55          // CAN1
#define INT_EMAC0_TM4C129       				56          // Ethernet MAC
#define INT_HIBERNATE_TM4C129   				57          // HIB
#define INT_USB0_TM4C129        				58          // USB MAC
#define INT_PWM0_3_TM4C129      				59          // PWM Generator 3
#define INT_UDMA_TM4C129        				60          // uDMA 0 Software
#define INT_UDMAERR_TM4C129     				61          // uDMA 0 Error
#define INT_ADC1SS0_TM4C129     				62          // ADC1 Sequence 0
#define INT_ADC1SS1_TM4C129     				63          // ADC1 Sequence 1
#define INT_ADC1SS2_TM4C129     				64          // ADC1 Sequence 2
#define INT_ADC1SS3_TM4C129     				65          // ADC1 Sequence 3
#define INT_EPI0_TM4C129        				66          // EPI 0
#define INT_GPIOJ_TM4C129       				67          // GPIO Port J
#define INT_GPIOK_TM4C129       				68          // GPIO Port K
#define INT_GPIOL_TM4C129       				69          // GPIO Port L
#define INT_SSI2_TM4C129        				70          // SSI 2
#define INT_SSI3_TM4C129        				71          // SSI 3
#define INT_UART3_TM4C129       				72          // UART 3
#define INT_UART4_TM4C129       				73          // UART 4
#define INT_UART5_TM4C129       				74          // UART 5
#define INT_UART6_TM4C129       				75          // UART 6
#define INT_UART7_TM4C129       				76          // UART 7
#define INT_I2C2_TM4C129        				77          // I2C 2
#define INT_I2C3_TM4C129        				78          // I2C 3
#define INT_TIMER4A_TM4C129     				79          // Timer 4A
#define INT_TIMER4B_TM4C129     				80          // Timer 4B
#define INT_TIMER5A_TM4C129     				81          // Timer 5A
#define INT_TIMER5B_TM4C129     				82          // Timer 5B
#define INT_SYSEXC_TM4C129      				83          // Floating-Point Exception (imprecise)
#define INT_I2C4_TM4C129        				86          // I2C 4
#define INT_I2C5_TM4C129        				87          // I2C 5
#define INT_GPIOM_TM4C129       				88          // GPIO Port M
#define INT_GPION_TM4C129       				89          // GPIO Port N
#define INT_TAMPER0_TM4C129     				91          // Tamper
#define INT_GPIOP0_TM4C129      				92          // GPIO Port P (Summary or P0)
#define INT_GPIOP1_TM4C129      				93          // GPIO Port P1
#define INT_GPIOP2_TM4C129      				94          // GPIO Port P2
#define INT_GPIOP3_TM4C129      				95          // GPIO Port P3
#define INT_GPIOP4_TM4C129      				96          // GPIO Port P4
#define INT_GPIOP5_TM4C129      				97          // GPIO Port P5
#define INT_GPIOP6_TM4C129      				98          // GPIO Port P6
#define INT_GPIOP7_TM4C129      				99          // GPIO Port P7
#define INT_GPIOQ0_TM4C129      				100         // GPIO Port Q (Summary or Q0)
#define INT_GPIOQ1_TM4C129      				101         // GPIO Port Q1
#define INT_GPIOQ2_TM4C129      				102         // GPIO Port Q2
#define INT_GPIOQ3_TM4C129      				103         // GPIO Port Q3
#define INT_GPIOQ4_TM4C129      				104         // GPIO Port Q4
#define INT_GPIOQ5_TM4C129      				105         // GPIO Port Q5
#define INT_GPIOQ6_TM4C129      				106         // GPIO Port Q6
#define INT_GPIOQ7_TM4C129      				107         // GPIO Port Q7
#define INT_GPIOR_TM4C129       				108         // GPIO Port R
#define INT_GPIOS_TM4C129       				109         // GPIO Port S
#define INT_SHA0_TM4C129        				110         // SHA/MD5
#define INT_AES0_TM4C129        				111         // AES
#define INT_DES0_TM4C129        				112         // DES
#define INT_LCD0_TM4C129        				113         // LCD
#define INT_TIMER6A_TM4C129     				114         // 16/32-Bit Timer 6A
#define INT_TIMER6B_TM4C129     				115         // 16/32-Bit Timer 6B
#define INT_TIMER7A_TM4C129     				116         // 16/32-Bit Timer 7A
#define INT_TIMER7B_TM4C129     				117         // 16/32-Bit Timer 7B
#define INT_I2C6_TM4C129        				118         // I2C 6
#define INT_I2C7_TM4C129        				119         // I2C 7
#define INT_ONEWIRE0_TM4C129    				121         // 1-Wire
#define INT_I2C8_TM4C129        				125         // I2C 8
#define INT_I2C9_TM4C129        				126         // I2C 9
#define INT_GPIOT_TM4C129       				127         // GPIO T


//*****************************************************************************
// The following are defines for the bit fields in the NVIC_ACTLR register.
//*****************************************************************************
#define NVIC_ACTLR_DISOOFP      				0x00000200  // Disable Out-Of-Order Floating Point
#define NVIC_ACTLR_DISFPCA      				0x00000100  // Disable CONTROL
#define NVIC_ACTLR_DISFOLD      				0x00000004  // Disable IT Folding
#define NVIC_ACTLR_DISWBUF     				    0x00000002  // Disable Write Buffer
#define NVIC_ACTLR_DISMCYC      				0x00000001  // Disable Interrupts of Multiple Cycle Instructions

//*****************************************************************************
// The following are defines for the bit fields in the NVIC_CPUID register.
//*****************************************************************************
#define NVIC_CPUID_IMP_M        				0xFF000000  // Implementer Code
#define NVIC_CPUID_IMP_ARM      				0x41000000  // ARM
#define NVIC_CPUID_VAR_M        				0x00F00000  // Variant Number
#define NVIC_CPUID_CON_M        				0x000F0000  // Constant
#define NVIC_CPUID_PARTNO_M     				0x0000FFF0  // Part Number
#define NVIC_CPUID_PARTNO_CM4   				0x0000C240  // Cortex-M4 processor
#define NVIC_CPUID_REV_M        				0x0000000F  // Revision Number

//*****************************************************************************
// The following are defines for the bit fields in the NVIC_INT_CTRL register.
//*****************************************************************************
#define NVIC_INT_CTRL_NMI_SET   				0x80000000  // NMI Set Pending
#define NVIC_INT_CTRL_PEND_SV   				0x10000000  // PendSV Set Pending
#define NVIC_INT_CTRL_UNPEND_SV 				0x08000000  // PendSV Clear Pending
#define NVIC_INT_CTRL_PENDSTSET 				0x04000000  // SysTick Set Pending
#define NVIC_INT_CTRL_PENDSTCLR 				0x02000000  // SysTick Clear Pending
#define NVIC_INT_CTRL_ISR_PRE   				0x00800000  // Debug Interrupt Handling
#define NVIC_INT_CTRL_ISR_PEND  				0x00400000  // Interrupt Pending
#define NVIC_INT_CTRL_VEC_PEN_M 				0x000FF000  // Interrupt Pending Vector Number
#define NVIC_INT_CTRL_VEC_PEN_NMI				0x00002000  // NMI
#define NVIC_INT_CTRL_VEC_PEN_HARD				0x00003000  // Hard fault
#define NVIC_INT_CTRL_VEC_PEN_MEM				0x00004000  // Memory management fault
#define NVIC_INT_CTRL_VEC_PEN_BUS				0x00005000  // Bus fault
#define NVIC_INT_CTRL_VEC_PEN_USG				0x00006000  // Usage fault
#define NVIC_INT_CTRL_VEC_PEN_SVC				0x0000B000  // SVCall
#define NVIC_INT_CTRL_VEC_PEN_PNDSV				0x0000E000  // PendSV
#define NVIC_INT_CTRL_VEC_PEN_TICK 				0x0000F000  // SysTick
#define NVIC_INT_CTRL_RET_BASE  				0x00000800  // Return to Base
#define NVIC_INT_CTRL_VEC_ACT_M 				0x000000FF  // Interrupt Pending Vector Number

//*****************************************************************************
// The following are defines for the bit fields in the NVIC_VTABLE register.
//*****************************************************************************
#define NVIC_VTABLE_OFFSET_M    				0xFFFFFC00  // Vector Table Offset

//*****************************************************************************
// The following are defines for the bit fields in the NVIC_APINT register.
//*****************************************************************************
#define NVIC_APINT_VECTKEY_M    				0xFFFF0000  // Register Key
#define NVIC_APINT_VECTKEY      				0x05FA0000  // Vector key
#define NVIC_APINT_ENDIANESS    				0x00008000  // Data Endianess
#define NVIC_APINT_PRIGROUP_M   				0x00000700  // Interrupt Priority Grouping
#define NVIC_APINT_PRIGROUP_7_1 				0x00000000  // Priority group 7.1 split
#define NVIC_APINT_PRIGROUP_6_2 				0x00000100  // Priority group 6.2 split
#define NVIC_APINT_PRIGROUP_5_3 				0x00000200  // Priority group 5.3 split
#define NVIC_APINT_PRIGROUP_4_4 				0x00000300  // Priority group 4.4 split
#define NVIC_APINT_PRIGROUP_3_5 				0x00000400  // Priority group 3.5 split
#define NVIC_APINT_PRIGROUP_2_6 				0x00000500  // Priority group 2.6 split
#define NVIC_APINT_PRIGROUP_1_7 				0x00000600  // Priority group 1.7 split
#define NVIC_APINT_PRIGROUP_0_8 				0x00000700  // Priority group 0.8 split
#define NVIC_APINT_SYSRESETREQ  				0x00000004  // System Reset Request
#define NVIC_APINT_VECT_CLR_ACT 				0x00000002  // Clear Active NMI / Fault
#define NVIC_APINT_VECT_RESET   				0x00000001  // System Reset

//*****************************************************************************
// The following are defines for the bit fields in the NVIC_SYS_CTRL register.
//*****************************************************************************
#define NVIC_SYS_CTRL_SEVONPEND 				0x00000010  // Wake Up on Pending
#define NVIC_SYS_CTRL_SLEEPDEEP 				0x00000004  // Deep Sleep Enable
#define NVIC_SYS_CTRL_SLEEPEXIT 				0x00000002  // Sleep on ISR Exit

//*****************************************************************************
// The following are defines for the bit fields in the NVIC_CFG_CTRL register.
//*****************************************************************************
#define NVIC_CFG_CTRL_STKALIGN  				0x00000200  // Stack Alignment on Exception Entry
#define NVIC_CFG_CTRL_BFHFNMIGN 				0x00000100  // Ignore Bus Fault in NMI and Fault
#define NVIC_CFG_CTRL_DIV0      				0x00000010  // Trap on Divide by 0
#define NVIC_CFG_CTRL_UNALIGNED					0x00000008  // Trap on Unaligned Access
#define NVIC_CFG_CTRL_MAIN_PEND 				0x00000002  // Allow Main Interrupt Trigger
#define NVIC_CFG_CTRL_BASE_THR  				0x00000001  // Thread State Control

//*****************************************************************************
// The following are defines for the bit fields in the NVIC_SYS_PRI1 register.
//*****************************************************************************
#define NVIC_SYS_PRI1_USAGE_M   				0x00E00000  // Usage Fault Priority
#define NVIC_SYS_PRI1_BUS_M     				0x0000E000  // Bus Fault Priority
#define NVIC_SYS_PRI1_MEM_M     				0x000000E0  // Memory Management Fault Priority

//*****************************************************************************
// The following are defines for the bit fields in the NVIC_SYS_PRI2 register.
//*****************************************************************************
#define NVIC_SYS_PRI2_SVC_M     				0xE0000000  // SVCall Priority

//*****************************************************************************
// The following are defines for the bit fields in the NVIC_SYS_PRI3 register.
//*****************************************************************************
#define NVIC_SYS_PRI3_TICK_M    				0xE0000000  // SysTick Exception Priority
#define NVIC_SYS_PRI3_PENDSV_M  				0x00E00000  // PendSV Priority
#define NVIC_SYS_PRI3_DEBUG_M   				0x000000E0  // Debug Priority

//*****************************************************************************
// The following are defines for the bit fields in the NVIC_SYS_HND_CTRL register.
//*****************************************************************************
#define NVIC_SYS_HND_CTRL_USAGE 				0x00040000  // Usage Fault Enable
#define NVIC_SYS_HND_CTRL_BUS   				0x00020000  // Bus Fault Enable
#define NVIC_SYS_HND_CTRL_MEM   				0x00010000  // Memory Management Fault Enable
#define NVIC_SYS_HND_CTRL_SVC   				0x00008000  // SVC Call Pending
#define NVIC_SYS_HND_CTRL_BUSP  				0x00004000  // Bus Fault Pending
#define NVIC_SYS_HND_CTRL_MEMP  				0x00002000  // Memory Management Fault Pending
#define NVIC_SYS_HND_CTRL_USAGEP				0x00001000  // Usage Fault Pending
#define NVIC_SYS_HND_CTRL_TICK  				0x00000800  // SysTick Exception Active
#define NVIC_SYS_HND_CTRL_PNDSV 				0x00000400  // PendSV Exception Active
#define NVIC_SYS_HND_CTRL_MON   				0x00000100  // Debug Monitor Active
#define NVIC_SYS_HND_CTRL_SVCA  				0x00000080  // SVC Call Active
#define NVIC_SYS_HND_CTRL_USGA  				0x00000008  // Usage Fault Active
#define NVIC_SYS_HND_CTRL_BUSA  				0x00000002  // Bus Fault Active
#define NVIC_SYS_HND_CTRL_MEMA  				0x00000001  // Memory Management Fault Active

//*****************************************************************************
// The following are defines for the bit fields in the NVIC_FAULT_STAT register.
//*****************************************************************************
#define NVIC_FAULT_STAT_DIV0    				0x02000000  // Divide-by-Zero Usage Fault
#define NVIC_FAULT_STAT_UNALIGN 				0x01000000  // Unaligned Access Usage Fault
#define NVIC_FAULT_STAT_NOCP    				0x00080000  // No Coprocessor Usage Fault
#define NVIC_FAULT_STAT_INVPC   				0x00040000  // Invalid PC Load Usage Fault
#define NVIC_FAULT_STAT_INVSTAT 				0x00020000  // Invalid State Usage Fault
#define NVIC_FAULT_STAT_UNDEF   				0x00010000  // Undefined Instruction Usage Fault
#define NVIC_FAULT_STAT_BFARV   				0x00008000  // Bus Fault Address Register Valid
#define NVIC_FAULT_STAT_BLSPERR 				0x00002000  // Bus Fault on Floating-Point Lazy State Preservation
#define NVIC_FAULT_STAT_BSTKE   				0x00001000  // Stack Bus Fault
#define NVIC_FAULT_STAT_BUSTKE 					0x00000800  // Unstack Bus Fault
#define NVIC_FAULT_STAT_IMPRE   				0x00000400  // Imprecise Data Bus Error
#define NVIC_FAULT_STAT_PRECISE 				0x00000200  // Precise Data Bus Error
#define NVIC_FAULT_STAT_IBUS    				0x00000100  // Instruction Bus Error
#define NVIC_FAULT_STAT_MMARV   				0x00000080  // Memory Management Fault Address Register Valid
#define NVIC_FAULT_STAT_MLSPERR 				0x00000020  // Memory Management Fault of Floating-Point Lazy State Preservation
#define NVIC_FAULT_STAT_MSTKE   				0x00000010  // Stack Access Violation
#define NVIC_FAULT_STAT_MUSTKE  				0x00000008  // Unstack Access Violation
#define NVIC_FAULT_STAT_DERR    				0x00000002  // Data Access Violation
#define NVIC_FAULT_STAT_IERR    				0x00000001  // Instruction Access Violation

//*****************************************************************************
// The following are defines for the bit fields in the NVIC_HFAULT_STATregister.
//*****************************************************************************
#define NVIC_HFAULT_STAT_DBG    				0x80000000  // Debug Event
#define NVIC_HFAULT_STAT_FORCED 				0x40000000  // Forced Hard Fault
#define NVIC_HFAULT_STAT_VECT  					0x00000002  // Vector Table Read Fault

//*****************************************************************************
// The following are defines for the bit fields in the NVIC_MM_ADDR register.
//*****************************************************************************
#define NVIC_MM_ADDR_M          				0xFFFFFFFF  // Fault Address

//*****************************************************************************
// The following are defines for the bit fields in the NVIC_FAULT_ADDR register.
//*****************************************************************************
#define NVIC_FAULT_ADDR_M       				0xFFFFFFFF  // Fault Address

//*****************************************************************************
// The following are defines for the bit fields in the NVIC_MPU_TYPE register.
//*****************************************************************************
#define NVIC_MPU_TYPE_IREGION_M 				0x00FF0000  // Number of I Regions
#define NVIC_MPU_TYPE_DREGION_M 				0x0000FF00  // Number of D Regions
#define NVIC_MPU_TYPE_SEPARATE  				0x00000001  // Separate or Unified MPU

//*****************************************************************************
// The following are defines for the bit fields in the NVIC_MPU_CTRL register.
//*****************************************************************************
#define NVIC_MPU_CTRL_PRIVDEFEN 				0x00000004  // MPU Default Region
#define NVIC_MPU_CTRL_HFNMIENA  				0x00000002  // MPU Enabled During Faults
#define NVIC_MPU_CTRL_ENABLE    				0x00000001  // MPU Enable

//*****************************************************************************
// The following are defines for the bit fields in the NVIC_MPU_NUMBER register.
//*****************************************************************************
#define NVIC_MPU_NUMBER_M       				0x00000007  // MPU Region to Access

//*****************************************************************************
// The following are defines for the bit fields in the NVIC_MPU_BASE register.
//*****************************************************************************
#define NVIC_MPU_BASE_ADDR_M    				0xFFFFFFE0  // Base Address Mask
#define NVIC_MPU_BASE_VALID     				0x00000010  // Region Number Valid
#define NVIC_MPU_BASE_REGION_M  				0x00000007  // Region Number

//*****************************************************************************
// The following are defines for the bit fields in the NVIC_MPU_ATTR register.
//*****************************************************************************
#define NVIC_MPU_ATTR_XN        				0x10000000  // Instruction Access Disable
#define NVIC_MPU_ATTR_AP_M      				0x07000000  // Access Privilege
#define NVIC_MPU_ATTR_AP_NO_NO  				0x00000000  // prv: no access, usr: no access
#define NVIC_MPU_ATTR_AP_RW_NO  				0x01000000  // prv: rw, usr: none
#define NVIC_MPU_ATTR_AP_RW_RO  				0x02000000  // prv: rw, usr: read-only
#define NVIC_MPU_ATTR_AP_RW_RW  				0x03000000  // prv: rw, usr: rw
#define NVIC_MPU_ATTR_AP_RO_NO  				0x05000000  // prv: ro, usr: none
#define NVIC_MPU_ATTR_AP_RO_RO  				0x06000000  // prv: ro, usr: ro
#define NVIC_MPU_ATTR_TEX_M     				0x00380000  // Type Extension Mask
#define NVIC_MPU_ATTR_SHAREABLE 				0x00040000  // Shareable
#define NVIC_MPU_ATTR_CACHEABLE 				0x00020000  // Cacheable
#define NVIC_MPU_ATTR_BUFFRABLE 				0x00010000  // Bufferable
#define NVIC_MPU_ATTR_SRD_M     				0x0000FF00  // Subregion Disable Bits
#define NVIC_MPU_ATTR_SRD_0     				0x00000100  // Sub-region 0 disable
#define NVIC_MPU_ATTR_SRD_1     				0x00000200  // Sub-region 1 disable
#define NVIC_MPU_ATTR_SRD_2     				0x00000400  // Sub-region 2 disable
#define NVIC_MPU_ATTR_SRD_3     				0x00000800  // Sub-region 3 disable
#define NVIC_MPU_ATTR_SRD_4     				0x00001000  // Sub-region 4 disable
#define NVIC_MPU_ATTR_SRD_5     				0x00002000  // Sub-region 5 disable
#define NVIC_MPU_ATTR_SRD_6     				0x00004000  // Sub-region 6 disable
#define NVIC_MPU_ATTR_SRD_7     				0x00008000  // Sub-region 7 disable
#define NVIC_MPU_ATTR_SIZE_M    				0x0000003E  // Region Size Mask
#define NVIC_MPU_ATTR_SIZE_32B  				0x00000008  // Region size 32 bytes
#define NVIC_MPU_ATTR_SIZE_64B  				0x0000000A  // Region size 64 bytes
#define NVIC_MPU_ATTR_SIZE_128B 				0x0000000C  // Region size 128 bytes
#define NVIC_MPU_ATTR_SIZE_256B 				0x0000000E  // Region size 256 bytes
#define NVIC_MPU_ATTR_SIZE_512B 				0x00000010  // Region size 512 bytes
#define NVIC_MPU_ATTR_SIZE_1K   				0x00000012  // Region size 1 Kbytes
#define NVIC_MPU_ATTR_SIZE_2K   				0x00000014  // Region size 2 Kbytes
#define NVIC_MPU_ATTR_SIZE_4K   				0x00000016  // Region size 4 Kbytes
#define NVIC_MPU_ATTR_SIZE_8K   				0x00000018  // Region size 8 Kbytes
#define NVIC_MPU_ATTR_SIZE_16K  				0x0000001A  // Region size 16 Kbytes
#define NVIC_MPU_ATTR_SIZE_32K  				0x0000001C  // Region size 32 Kbytes
#define NVIC_MPU_ATTR_SIZE_64K  				0x0000001E  // Region size 64 Kbytes
#define NVIC_MPU_ATTR_SIZE_128K 				0x00000020  // Region size 128 Kbytes
#define NVIC_MPU_ATTR_SIZE_256K 				0x00000022  // Region size 256 Kbytes
#define NVIC_MPU_ATTR_SIZE_512K 				0x00000024  // Region size 512 Kbytes
#define NVIC_MPU_ATTR_SIZE_1M   				0x00000026  // Region size 1 Mbytes
#define NVIC_MPU_ATTR_SIZE_2M   				0x00000028  // Region size 2 Mbytes
#define NVIC_MPU_ATTR_SIZE_4M   				0x0000002A  // Region size 4 Mbytes
#define NVIC_MPU_ATTR_SIZE_8M   				0x0000002C  // Region size 8 Mbytes
#define NVIC_MPU_ATTR_SIZE_16M  				0x0000002E  // Region size 16 Mbytes
#define NVIC_MPU_ATTR_SIZE_32M  				0x00000030  // Region size 32 Mbytes
#define NVIC_MPU_ATTR_SIZE_64M  				0x00000032  // Region size 64 Mbytes
#define NVIC_MPU_ATTR_SIZE_128M 				0x00000034  // Region size 128 Mbytes
#define NVIC_MPU_ATTR_SIZE_256M 				0x00000036  // Region size 256 Mbytes
#define NVIC_MPU_ATTR_SIZE_512M				    0x00000038  // Region size 512 Mbytes
#define NVIC_MPU_ATTR_SIZE_1G   				0x0000003A  // Region size 1 Gbytes
#define NVIC_MPU_ATTR_SIZE_2G   				0x0000003C  // Region size 2 Gbytes
#define NVIC_MPU_ATTR_SIZE_4G   				0x0000003E  // Region size 4 Gbytes
#define NVIC_MPU_ATTR_ENABLE    				0x00000001  // Region Enable

//*****************************************************************************
// The following are defines for the bit fields in the NVIC_MPU_BASE1 register.
//*****************************************************************************
#define NVIC_MPU_BASE1_ADDR_M   				0xFFFFFFE0  // Base Address Mask
#define NVIC_MPU_BASE1_VALID    				0x00000010  // Region Number Valid
#define NVIC_MPU_BASE1_REGION_M 				0x00000007  // Region Number

//*****************************************************************************
// The following are defines for the bit fields in the NVIC_MPU_ATTR1 register.
//*****************************************************************************
#define NVIC_MPU_ATTR1_XN       				0x10000000  // Instruction Access Disable
#define NVIC_MPU_ATTR1_AP_M     				0x07000000  // Access Privilege
#define NVIC_MPU_ATTR1_TEX_M    				0x00380000  // Type Extension Mask
#define NVIC_MPU_ATTR1_SHAREABLE				0x00040000  // Shareable
#define NVIC_MPU_ATTR1_CACHEABLE				0x00020000  // Cacheable
#define NVIC_MPU_ATTR1_BUFFRABLE				0x00010000  // Bufferable
#define NVIC_MPU_ATTR1_SRD_M    				0x0000FF00  // Subregion Disable Bits
#define NVIC_MPU_ATTR1_SIZE_M   				0x0000003E  // Region Size Mask
#define NVIC_MPU_ATTR1_ENABLE   				0x00000001  // Region Enable

//*****************************************************************************
// The following are defines for the bit fields in the NVIC_MPU_BASE2 register.
//*****************************************************************************
#define NVIC_MPU_BASE2_ADDR_M   				0xFFFFFFE0  // Base Address Mask
#define NVIC_MPU_BASE2_VALID    				0x00000010  // Region Number Valid
#define NVIC_MPU_BASE2_REGION_M 				0x00000007  // Region Number

//*****************************************************************************
// The following are defines for the bit fields in the NVIC_MPU_ATTR2 register.
//*****************************************************************************
#define NVIC_MPU_ATTR2_XN       				0x10000000  // Instruction Access Disable
#define NVIC_MPU_ATTR2_AP_M     				0x07000000  // Access Privilege
#define NVIC_MPU_ATTR2_TEX_M    				0x00380000  // Type Extension Mask
#define NVIC_MPU_ATTR2_SHAREABLE				0x00040000  // Shareable
#define NVIC_MPU_ATTR2_CACHEABLE				0x00020000  // Cacheable
#define NVIC_MPU_ATTR2_BUFFRABLE				0x00010000  // Bufferable
#define NVIC_MPU_ATTR2_SRD_M    				0x0000FF00  // Subregion Disable Bits
#define NVIC_MPU_ATTR2_SIZE_M   				0x0000003E  // Region Size Mask
#define NVIC_MPU_ATTR2_ENABLE   				0x00000001  // Region Enable

//*****************************************************************************
// The following are defines for the bit fields in the NVIC_MPU_BASE3 register.
//*****************************************************************************
#define NVIC_MPU_BASE3_ADDR_M   				0xFFFFFFE0  // Base Address Mask
#define NVIC_MPU_BASE3_VALID    				0x00000010  // Region Number Valid
#define NVIC_MPU_BASE3_REGION_M 				0x00000007  // Region Number

//*****************************************************************************
// The following are defines for the bit fields in the NVIC_MPU_ATTR3 register.
//*****************************************************************************
#define NVIC_MPU_ATTR3_XN       				0x10000000  // Instruction Access Disable
#define NVIC_MPU_ATTR3_AP_M     				0x07000000  // Access Privilege
#define NVIC_MPU_ATTR3_TEX_M    				0x00380000  // Type Extension Mask
#define NVIC_MPU_ATTR3_SHAREABLE				0x00040000  // Shareable
#define NVIC_MPU_ATTR3_CACHEABLE				0x00020000  // Cacheable
#define NVIC_MPU_ATTR3_BUFFRABLE				0x00010000  // Bufferable
#define NVIC_MPU_ATTR3_SRD_M    				0x0000FF00  // Subregion Disable Bits
#define NVIC_MPU_ATTR3_SIZE_M   				0x0000003E  // Region Size Mask
#define NVIC_MPU_ATTR3_ENABLE   				0x00000001  // Region Enable

//*****************************************************************************
// The following are defines for the bit fields in the NVIC_CPAC register.
//*****************************************************************************
#define NVIC_CPAC_CP11_M        				0x00C00000  // CP11 Coprocessor Access Privilege
#define NVIC_CPAC_CP11_DIS      				0x00000000  // Access Denied
#define NVIC_CPAC_CP11_PRIV     				0x00400000  // Privileged Access Only
#define NVIC_CPAC_CP11_FULL    					0x00C00000  // Full Access
#define NVIC_CPAC_CP10_M        				0x00300000  // CP10 Coprocessor Access Privilege
#define NVIC_CPAC_CP10_DIS      				0x00000000  // Access Denied
#define NVIC_CPAC_CP10_PRIV    				 	0x00100000  // Privileged Access Only
#define NVIC_CPAC_CP10_FULL    					0x00300000  // Full Access

//*****************************************************************************
// The following are defines for the bit fields in the NVIC_FPCC register.
//*****************************************************************************
#define NVIC_FPCC_ASPEN         				0x80000000  // Automatic State Preservation Enable
#define NVIC_FPCC_LSPEN         				0x40000000  // Lazy State Preservation Enable
#define NVIC_FPCC_MONRDY        				0x00000100  // Monitor Ready
#define NVIC_FPCC_BFRDY         				0x00000040  // Bus Fault Ready
#define NVIC_FPCC_MMRDY         				0x00000020  // Memory Management Fault Ready
#define NVIC_FPCC_HFRDY         				0x00000010  // Hard Fault Ready
#define NVIC_FPCC_THREAD        				0x00000008  // Thread Mode
#define NVIC_FPCC_USER          				0x00000002  // User Privilege Level
#define NVIC_FPCC_LSPACT        				0x00000001  // Lazy State Preservation Active

//*****************************************************************************
// The following are defines for the bit fields in the NVIC_FPCA register.
//*****************************************************************************
#define NVIC_FPCA_ADDRESS_M     				0xFFFFFFF8  // Address

//*****************************************************************************
// The following are defines for the bit fields in the NVIC_FPDSC register.
//*****************************************************************************
#define NVIC_FPDSC_AHP         					0x04000000  // AHP Bit Default
#define NVIC_FPDSC_DN           				0x02000000  // DN Bit Default
#define NVIC_FPDSC_FZ           				0x01000000  // FZ Bit Default
#define NVIC_FPDSC_RMODE_M      				0x00C00000  // RMODE Bit Default
#define NVIC_FPDSC_RMODE_RN     				0x00000000  // Round to Nearest (RN) mode
#define NVIC_FPDSC_RMODE_RP     				0x00400000  // Round towards Plus Infinity (RP) mode
#define NVIC_FPDSC_RMODE_RM     				0x00800000  // Round towards Minus Infinity (RM) mode
#define NVIC_FPDSC_RMODE_RZ     				0x00C00000  // Round towards Zero (RZ) mode

//*****************************************************************************
// Prototypes for the APIs.
//*****************************************************************************
extern void IntDisable(uint32_t ui32Interrupt);								// Tested
extern void IntEnable(uint32_t ui32Interrupt);								// Tested
extern uint32_t IntIsEnabled(uint32_t ui32Interrupt);						// Tested
extern bool IntMasterDisable(void);											// Tested
extern bool IntMasterEnable(void);											// Tested
extern void IntPendClear(uint32_t ui32Interrupt);							// Tested
extern void IntPendSet(uint32_t ui32Interrupt);								// Tested
extern int32_t IntPriorityGet(uint32_t ui32Interrupt);						// Tested
extern uint32_t IntPriorityGroupingGet(void);								// Tested
extern void IntPriorityGroupingSet(uint32_t ui32Bits);						// Tested
extern uint32_t IntPriorityMaskGet(void);									// Tested
extern void IntPriorityMaskSet(uint32_t ui32PriorityMask);					// Tested
extern void IntPrioritySet(uint32_t ui32Interrupt, uint8_t ui8Priority);	// Tested
extern void IntRegister(uint32_t ui32Interrupt, void (*pfnHandler)(void));	// Tested
extern void IntTrigger(uint32_t ui32Interrupt);								// Tested
extern void IntUnregister(uint32_t ui32Interrupt);							// Tested

#endif // _INTERRUPT_H_
