//*****************************************************************************
// uart.h - Defines and Macros for the UART.
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

#ifndef _UART_H_
#define _UART_H_

//*****************************************************************************
// The following are defines for the base address of the UART peripherals
//*****************************************************************************
#define UART0_BASE              				0x4000C000  // UART0
#define UART1_BASE              				0x4000D000  // UART1
#define UART2_BASE              				0x4000E000  // UART2
#define UART3_BASE              				0x4000F000  // UART3
#define UART4_BASE              				0x40010000  // UART4
#define UART5_BASE              				0x40011000  // UART5
#define UART6_BASE              				0x40012000  // UART6
#define UART7_BASE              				0x40013000  // UART7

//*****************************************************************************
// The following are defines for the UART register offsets.
//*****************************************************************************
#define UART_O_DR               				0x00000000  // UART Data
#define UART_O_RSR              				0x00000004  // UART Receive Status/Error Clear
#define UART_O_ECR              				0x00000004  // UART Receive Status/Error Clear
#define UART_O_FR               				0x00000018  // UART Flag
#define UART_O_ILPR             				0x00000020  // UART IrDA Low-Power Register
#define UART_O_IBRD             				0x00000024  // UART Integer Baud-Rate Divisor
#define UART_O_FBRD             				0x00000028  // UART Fractional Baud-Rate Divisor
#define UART_O_LCRH             				0x0000002C  // UART Line Control
#define UART_O_CTL              				0x00000030  // UART Control
#define UART_O_IFLS            					0x00000034  // UART Interrupt FIFO Level Select
#define UART_O_IM               				0x00000038  // UART Interrupt Mask
#define UART_O_RIS              				0x0000003C  // UART Raw Interrupt Status
#define UART_O_MIS              				0x00000040  // UART Masked Interrupt Status
#define UART_O_ICR              				0x00000044  // UART Interrupt Clear
#define UART_O_DMACTL           				0x00000048  // UART DMA Control
#define UART_O_9BITADDR         				0x000000A4  // UART 9-Bit Self Address
#define UART_O_9BITAMASK        				0x000000A8  // UART 9-Bit Self Address Mask
#define UART_O_PP               				0x00000FC0  // UART Peripheral Properties
#define UART_O_CC               				0x00000FC8  // UART Clock Configuration

//*****************************************************************************
// The following are defines for the bit fields in the UART_O_DR register.
//*****************************************************************************
#define UART_DR_OE              				0x00000800  // UART Overrun Error
#define UART_DR_BE              				0x00000400  // UART Break Error
#define UART_DR_PE              				0x00000200  // UART Parity Error
#define UART_DR_FE              				0x00000100  // UART Framing Error
#define UART_DR_DATA_M          				0x000000FF  // Data Transmitted or Received
#define UART_DR_DATA_S          				0

//*****************************************************************************
// The following are defines for the bit fields in the UART_O_RSR register.
//*****************************************************************************
#define UART_RSR_OE             				0x00000008  // UART Overrun Error
#define UART_RSR_BE             				0x00000004  // UART Break Error
#define UART_RSR_PE             				0x00000002  // UART Parity Error
#define UART_RSR_FE             				0x00000001  // UART Framing Error

//*****************************************************************************
// The following are defines for the bit fields in the UART_O_ECR register.
//*****************************************************************************
#define UART_ECR_DATA_M         				0x000000FF  // Error Clear
#define UART_ECR_DATA_S         				0

//*****************************************************************************
// The following are defines for the bit fields in the UART_O_FR register.
//*****************************************************************************
#define UART_FR_RI              				0x00000100  // Ring Indicator
#define UART_FR_TXFE            				0x00000080  // UART Transmit FIFO Empty
#define UART_FR_RXFF            				0x00000040  // UART Receive FIFO Full
#define UART_FR_TXFF            				0x00000020  // UART Transmit FIFO Full
#define UART_FR_RXFE            				0x00000010  // UART Receive FIFO Empty
#define UART_FR_BUSY            				0x00000008  // UART Busy
#define UART_FR_DCD             				0x00000004  // Data Carrier Detect
#define UART_FR_DSR             				0x00000002  // Data Set Ready
#define UART_FR_CTS             				0x00000001  // Clear To Send

//*****************************************************************************
// The following are defines for the bit fields in the UART_O_ILPR register.
//*****************************************************************************
#define UART_ILPR_ILPDVSR_M     				0x000000FF  // IrDA Low-Power Divisor
#define UART_ILPR_ILPDVSR_S     				0

//*****************************************************************************
// The following are defines for the bit fields in the UART_O_IBRD register.
//*****************************************************************************
#define UART_IBRD_DIVINT_M      				0x0000FFFF  // Integer Baud-Rate Divisor
#define UART_IBRD_DIVINT_S      				0

//*****************************************************************************
// The following are defines for the bit fields in the UART_O_FBRD register.
//*****************************************************************************
#define UART_FBRD_DIVFRAC_M     				0x0000003F  // Fractional Baud-Rate Divisor
#define UART_FBRD_DIVFRAC_S     				0

//*****************************************************************************
// The following are defines for the bit fields in the UART_O_LCRH register.
//*****************************************************************************
#define UART_LCRH_SPS           				0x00000080  // UART Stick Parity Select
#define UART_LCRH_WLEN_M        				0x00000060  // UART Word Length
#define UART_LCRH_WLEN_5        				0x00000000  // 5 bits (default)
#define UART_LCRH_WLEN_6        				0x00000020  // 6 bits
#define UART_LCRH_WLEN_7        				0x00000040  // 7 bits
#define UART_LCRH_WLEN_8        				0x00000060  // 8 bits
#define UART_LCRH_FEN           				0x00000010  // UART Enable FIFOs
#define UART_LCRH_STP2          				0x00000008  // UART Two Stop Bits Select
#define UART_LCRH_EPS           				0x00000004  // UART Even Parity Select
#define UART_LCRH_PEN           				0x00000002  // UART Parity Enable
#define UART_LCRH_BRK           				0x00000001  // UART Send Break

//*****************************************************************************
// The following are defines for the bit fields in the UART_O_CTL register.
//*****************************************************************************
#define UART_CTL_CTSEN         				 	0x00008000  // Enable Clear To Send
#define UART_CTL_RTSEN          				0x00004000  // Enable Request to Send
#define UART_CTL_RTS            				0x00000800  // Request to Send
#define UART_CTL_DTR            				0x00000400  // Data Terminal Ready
#define UART_CTL_RXE            				0x00000200  // UART Receive Enable
#define UART_CTL_TXE            				0x00000100  // UART Transmit Enable
#define UART_CTL_LBE            				0x00000080  // UART Loop Back Enable
#define UART_CTL_HSE            				0x00000020  // High-Speed Enable
#define UART_CTL_EOT           				 	0x00000010  // End of Transmission
#define UART_CTL_SMART          				0x00000008  // ISO 7816 Smart Card Support
#define UART_CTL_SIRLP          				0x00000004  // UART SIR Low-Power Mode
#define UART_CTL_SIREN          				0x00000002  // UART SIR Enable
#define UART_CTL_UARTEN         				0x00000001  // UART Enable

//*****************************************************************************
// The following are defines for the bit fields in the UART_O_IFLS register.
//*****************************************************************************
#define UART_IFLS_RX_M          				0x00000038  // UART Receive Interrupt FIFO Level Select
#define UART_IFLS_RX1_8         				0x00000000  // RX FIFO >= 1/8 full
#define UART_IFLS_RX2_8         				0x00000008  // RX FIFO >= 1/4 full
#define UART_IFLS_RX4_8         				0x00000010  // RX FIFO >= 1/2 full (default)
#define UART_IFLS_RX6_8         				0x00000018  // RX FIFO >= 3/4 full
#define UART_IFLS_RX7_8         				0x00000020  // RX FIFO >= 7/8 full
#define UART_IFLS_TX_M          				0x00000007  // UART Transmit Interrupt FIFO  Level Select
#define UART_IFLS_TX1_8         				0x00000000  // TX FIFO <= 1/8 full
#define UART_IFLS_TX2_8         				0x00000001  // TX FIFO <= 1/4 full
#define UART_IFLS_TX4_8         				0x00000002  // TX FIFO <= 1/2 full (default)
#define UART_IFLS_TX6_8         				0x00000003  // TX FIFO <= 3/4 full
#define UART_IFLS_TX7_8         				0x00000004  // TX FIFO <= 7/8 full

//*****************************************************************************
// The following are defines for the bit fields in the UART_O_IM register.
//*****************************************************************************
#define UART_IM_DMATXIM         				0x00020000  // Transmit DMA Interrupt Mask
#define UART_IM_DMARXIM         				0x00010000  // Receive DMA Interrupt Mask
#define UART_IM_9BITIM          				0x00001000  // 9-Bit Mode Interrupt Mask
#define UART_IM_EOTIM           				0x00000800  // End of Transmission Interrupt Mask
#define UART_IM_OEIM            				0x00000400  // UART Overrun Error Interrupt Mask
#define UART_IM_BEIM            				0x00000200  // UART Break Error Interrupt Mask
#define UART_IM_PEIM            				0x00000100  // UART Parity Error Interrupt Mask
#define UART_IM_FEIM            				0x00000080  // UART Framing Error Interrupt Mask
#define UART_IM_RTIM            				0x00000040  // UART Receive Time-Out Interrupt Mask
#define UART_IM_TXIM            				0x00000020  // UART Transmit Interrupt Mask
#define UART_IM_RXIM            				0x00000010  // UART Receive Interrupt Mask
#define UART_IM_DSRMIM          				0x00000008  // UART Data Set Ready Modem Interrupt Mask
#define UART_IM_DCDMIM          				0x00000004  // UART Data Carrier Detect Modem Interrupt Mask
#define UART_IM_CTSMIM          				0x00000002  // UART Clear to Send Modem Interrupt Mask
#define UART_IM_RIMIM           				0x00000001  // UART Ring Indicator Modem Interrupt Mask

//*****************************************************************************
// The following are defines for the bit fields in the UART_O_RIS register.
//*****************************************************************************
#define UART_RIS_DMATXRIS       				0x00020000  // Transmit DMA Raw Interrupt Status
#define UART_RIS_DMARXRIS       				0x00010000  // Receive DMA Raw Interrupt Status
#define UART_RIS_9BITRIS        				0x00001000  // 9-Bit Mode Raw Interrupt Status
#define UART_RIS_EOTRIS         				0x00000800  // End of Transmission Raw Interrupt Status
#define UART_RIS_OERIS          				0x00000400  // UART Overrun Error Raw Interrupt Status
#define UART_RIS_BERIS         					0x00000200  // UART Break Error Raw Interrupt Status
#define UART_RIS_PERIS          				0x00000100  // UART Parity Error Raw Interrupt Status
#define UART_RIS_FERIS          				0x00000080  // UART Framing Error Raw Interrupt Status
#define UART_RIS_RTRIS          				0x00000040  // UART Receive Time-Out Raw Interrupt Status
#define UART_RIS_TXRIS          				0x00000020  // UART Transmit Raw Interrupt Status
#define UART_RIS_RXRIS          				0x00000010  // UART Receive Raw Interrupt Status
#define UART_RIS_DSRRIS         				0x00000008  // UART Data Set Ready Modem Raw Interrupt Status
#define UART_RIS_DCDRIS         				0x00000004  // UART Data Carrier Detect Modem Raw Interrupt Status
#define UART_RIS_CTSRIS         				0x00000002  // UART Clear to Send Modem Raw Interrupt Status
#define UART_RIS_RIRIS          				0x00000001  // UART Ring Indicator Modem Raw Interrupt Status

//*****************************************************************************
// The following are defines for the bit fields in the UART_O_MIS register.
//*****************************************************************************
#define UART_MIS_DMATXMIS       				0x00020000  // Transmit DMA Masked Interrupt Status
#define UART_MIS_DMARXMIS       				0x00010000  // Receive DMA Masked Interrupt Status
#define UART_MIS_9BITMIS        				0x00001000  // 9-Bit Mode Masked Interrupt Status
#define UART_MIS_EOTMIS         				0x00000800  // End of Transmission Masked Interrupt Status
#define UART_MIS_OEMIS          				0x00000400  // UART Overrun Error Masked Interrupt Status
#define UART_MIS_BEMIS          				0x00000200  // UART Break Error Masked Interrupt Status
#define UART_MIS_PEMIS          				0x00000100  // UART Parity Error Masked Interrupt Status
#define UART_MIS_FEMIS         					0x00000080  // UART Framing Error Masked Interrupt Status
#define UART_MIS_RTMIS          				0x00000040  // UART Receive Time-Out Masked Interrupt Status
#define UART_MIS_TXMIS          				0x00000020  // UART Transmit Masked Interrupt Status
#define UART_MIS_RXMIS          				0x00000010  // UART Receive Masked Interrupt Status
#define UART_MIS_DSRMIS         				0x00000008  // UART Data Set Ready Modem Masked Interrupt Status
#define UART_MIS_DCDMIS         				0x00000004  // UART Data Carrier Detect Modem Masked Interrupt Status
#define UART_MIS_CTSMIS         				0x00000002  // UART Clear to Send Modem Masked Interrupt Status
#define UART_MIS_RIMIS          				0x00000001  // UART Ring Indicator Modem Masked Interrupt Status

//*****************************************************************************
// The following are defines for the bit fields in the UART_O_ICR register.
//*****************************************************************************
#define UART_ICR_DMATXIC        				0x00020000  // Transmit DMA Interrupt Clear
#define UART_ICR_DMARXIC        				0x00010000  // Receive DMA Interrupt Clear
#define UART_ICR_9BITIC         				0x00001000  // 9-Bit Mode Interrupt Clear
#define UART_ICR_EOTIC          				0x00000800  // End of Transmission Interrupt Clear
#define UART_ICR_OEIC           				0x00000400  // Overrun Error Interrupt Clear
#define UART_ICR_BEIC           				0x00000200  // Break Error Interrupt Clear
#define UART_ICR_PEIC           				0x00000100  // Parity Error Interrupt Clear
#define UART_ICR_FEIC           				0x00000080  // Framing Error Interrupt Clear
#define UART_ICR_RTIC           				0x00000040  // Receive Time-Out Interrupt Clear
#define UART_ICR_TXIC           				0x00000020  // Transmit Interrupt Clear
#define UART_ICR_RXIC           				0x00000010  // Receive Interrupt Clear
#define UART_ICR_DSRMIC         				0x00000008  // UART Data Set Ready Modem Interrupt Clear
#define UART_ICR_DCDMIC         				0x00000004  // UART Data Carrier Detect Modem Interrupt Clear
#define UART_ICR_CTSMIC         				0x00000002  // UART Clear to Send Modem Interrupt Clear
#define UART_ICR_RIMIC          				0x00000001  // UART Ring Indicator Modem Interrupt Clear

//*****************************************************************************
// The following are defines for the bit fields in the UART_O_DMACTL register.
//*****************************************************************************
#define UART_DMACTL_DMAERR      				0x00000004  // DMA on Error
#define UART_DMACTL_TXDMAE      				0x00000002  // Transmit DMA Enable
#define UART_DMACTL_RXDMAE      				0x00000001  // Receive DMA Enable

//*****************************************************************************
// The following are defines for the bit fields in the UART_O_9BITADDR register.
//*****************************************************************************
#define UART_9BITADDR_9BITEN    				0x00008000  // Enable 9-Bit Mode
#define UART_9BITADDR_ADDR_M    				0x000000FF  // Self Address for 9-Bit Mode
#define UART_9BITADDR_ADDR_S    				0

//*****************************************************************************
// The following are defines for the bit fields in the UART_O_9BITAMASK register.
//*****************************************************************************
#define UART_9BITAMASK_MASK_M   				0x000000FF  // Self Address Mask for 9-Bit Mode
#define UART_9BITAMASK_MASK_S   				0

//*****************************************************************************
// The following are defines for the bit fields in the UART_O_PP register.
//*****************************************************************************
#define UART_PP_MSE             				0x00000008  // Modem Support Extended
#define UART_PP_MS             					0x00000004  // Modem Support
#define UART_PP_NB              				0x00000002  // 9-Bit Support
#define UART_PP_SC              				0x00000001  // Smart Card Support

//*****************************************************************************
// The following are defines for the bit fields in the UART_O_CC register.
//*****************************************************************************
#define UART_CC_CS_M            				0x0000000F  // UART Baud Clock Source
#define UART_CC_CS_SYSCLK       				0x00000000  // System clock (based on clock source and divisor factor)
#define UART_CC_CS_PIOSC        				0x00000005  // PIOSC





//*****************************************************************************
// Values that can be passed to UARTClockSourceSet() or returned from
// UARTClockSourceGet().
//*****************************************************************************
#define UART_CLOCK_SYSTEM       				0x00000000
#define UART_CLOCK_PIOSC       					0x00000005

//*****************************************************************************
// Values that can be passed to UARTConfigSetExpClk as the ui32Config parameter
// and returned by UARTConfigGetExpClk in the pui32Config parameter.
// Additionally, the UART_CONFIG_PAR_* subset can be passed to
// UARTParityModeSet as the ui32Parity parameter, and are returned by
// UARTParityModeGet.
//*****************************************************************************
#define UART_CONFIG_WLEN_MASK   				0x00000060  // Mask for extracting word length
#define UART_CONFIG_WLEN_8      				0x00000060  // 8 bit data
#define UART_CONFIG_WLEN_7      				0x00000040  // 7 bit data
#define UART_CONFIG_WLEN_6      				0x00000020  // 6 bit data
#define UART_CONFIG_WLEN_5      				0x00000000  // 5 bit data
#define UART_CONFIG_STOP_MASK   				0x00000008  // Mask for extracting stop bits
#define UART_CONFIG_STOP_ONE    				0x00000000  // One stop bit
#define UART_CONFIG_STOP_TWO    				0x00000008  // Two stop bits
#define UART_CONFIG_PAR_MASK    				0x00000086  // Mask for extracting parity
#define UART_CONFIG_PAR_NONE    				0x00000000  // No parity
#define UART_CONFIG_PAR_EVEN    				0x00000006  // Even parity
#define UART_CONFIG_PAR_ODD     				0x00000002  // Odd parity
#define UART_CONFIG_PAR_ONE     				0x00000082  // Parity bit is one
#define UART_CONFIG_PAR_ZERO    				0x00000086  // Parity bit is zero

//*****************************************************************************
// Values that can be passed to UARTDMAEnable() and UARTDMADisable().
//*****************************************************************************
#define UART_DMA_ERR_RXSTOP     				0x00000004  // Stop DMA receive if UART error
#define UART_DMA_TX             				0x00000002  // Enable DMA for transmit
#define UART_DMA_RX             				0x00000001  // Enable DMA for receive

//*****************************************************************************
// Values that can be passed to UARTFIFOLevelSet as the ui32TxLevel parameter
// and returned by UARTFIFOLevelGet in the pui32TxLevel.
//*****************************************************************************
#define UART_FIFO_TX1_8         				0x00000000  // Transmit interrupt at 1/8 Full
#define UART_FIFO_TX2_8         				0x00000001  // Transmit interrupt at 1/4 Full
#define UART_FIFO_TX4_8         				0x00000002  // Transmit interrupt at 1/2 Full
#define UART_FIFO_TX6_8         				0x00000003  // Transmit interrupt at 3/4 Full
#define UART_FIFO_TX7_8        					0x00000004  // Transmit interrupt at 7/8 Full

//*****************************************************************************
// Values that can be passed to UARTFIFOLevelSet as the ui32RxLevel parameter
// and returned by UARTFIFOLevelGet in the pui32RxLevel.
//*****************************************************************************
#define UART_FIFO_RX1_8         				0x00000000  // Receive interrupt at 1/8 Full
#define UART_FIFO_RX2_8         				0x00000008  // Receive interrupt at 1/4 Full
#define UART_FIFO_RX4_8         				0x00000010  // Receive interrupt at 1/2 Full
#define UART_FIFO_RX6_8         				0x00000018  // Receive interrupt at 3/4 Full
#define UART_FIFO_RX7_8         				0x00000020  // Receive interrupt at 7/8 Full

//*****************************************************************************
// Values that can be passed to UARTFlowControl() or returned from
// UARTFlowControlGet().
//*****************************************************************************
#define UART_FLOWCONTROL_TX     				0x00008000
#define UART_FLOWCONTROL_RX     				0x00004000
#define UART_FLOWCONTROL_NONE   				0x00000000

//*****************************************************************************
// Values that can be passed to UARTIntEnable, UARTIntDisable, and UARTIntClear
// as the ui32IntFlags parameter, and returned from UARTIntStatus.
//*****************************************************************************
#define UART_INT_DMATX          				0x20000     // DMA TX interrupt
#define UART_INT_DMARX          				0x10000     // DMA RX interrupt
#define UART_INT_9BIT           				0x1000      // 9-bit address match interrupt
#define UART_INT_OE             				0x400       // Overrun Error Interrupt Mask
#define UART_INT_BE             				0x200       // Break Error Interrupt Mask
#define UART_INT_PE             				0x100       // Parity Error Interrupt Mask
#define UART_INT_FE             				0x080       // Framing Error Interrupt Mask
#define UART_INT_RT             				0x040       // Receive Timeout Interrupt Mask
#define UART_INT_TX             				0x020       // Transmit Interrupt Mask
#define UART_INT_RX             				0x010       // Receive Interrupt Mask
#define UART_INT_DSR            				0x008       // DSR Modem Interrupt Mask
#define UART_INT_DCD           				 	0x004       // DCD Modem Interrupt Mask
#define UART_INT_CTS            				0x002       // CTS Modem Interrupt Mask
#define UART_INT_RI             				0x001       // RI Modem Interrupt Mask

//*****************************************************************************
// Values that can be passed to UARTModemControlSet().
//*****************************************************************************
#define UART_OUTPUT_RTS         				0x00000800
#define UART_OUTPUT_DTR         				0x00000400

//*****************************************************************************
// Values that can be returned from UARTModemStatusGet().
//*****************************************************************************
#define UART_INPUT_RI           				0x00000100
#define UART_INPUT_DCD          				0x00000004
#define UART_INPUT_DSR          				0x00000002
#define UART_INPUT_CTS          				0x00000001

//*****************************************************************************
// Values returned from UARTRxErrorGet().
//*****************************************************************************
#define UART_RXERROR_OVERRUN    				0x00000008
#define UART_RXERROR_BREAK      				0x00000004
#define UART_RXERROR_PARITY     				0x00000002
#define UART_RXERROR_FRAMING    				0x00000001

//*****************************************************************************
// Values that can be passed to UARTTxIntModeSet() or returned from
// UARTTxIntModeGet().
//*****************************************************************************
#define UART_TXINT_MODE_FIFO    				0x00000000
#define UART_TXINT_MODE_EOT     				0x00000010





//*****************************************************************************
// API Function prototypes
//*****************************************************************************
extern void UART9BitAddrSend(uint32_t ui32Base, uint8_t ui8Addr);
extern void UART9BitAddrSet(uint32_t ui32Base, uint8_t ui8Addr, uint8_t ui8Mask);
extern void UART9BitDisable(uint32_t ui32Base);
extern void UART9BitEnable(uint32_t ui32Base);
extern void UARTBreakCtl(uint32_t ui32Base, bool bBreakState);
extern bool UARTBusy(uint32_t ui32Base);
extern int32_t UARTCharGet(uint32_t ui32Base);
extern int32_t UARTCharGetNonBlocking(uint32_t ui32Base);
extern void UARTCharPut(uint32_t ui32Base, unsigned char ucData);
extern bool UARTCharPutNonBlocking(uint32_t ui32Base, unsigned char ucData);
extern bool UARTCharsAvail(uint32_t ui32Base);
extern uint32_t UARTClockSourceGet(uint32_t ui32Base);
extern void UARTClockSourceSet(uint32_t ui32Base, uint32_t ui32Source);
extern void UARTConfigGetExpClk(uint32_t ui32Base, uint32_t ui32UARTClk, uint32_t *pui32Baud, uint32_t *pui32Config);
extern void UARTConfigSetExpClk(uint32_t ui32Base, uint32_t ui32UARTClk, uint32_t ui32Baud, uint32_t ui32Config);
extern void UARTDisable(uint32_t ui32Base);
extern void UARTDisableSIR(uint32_t ui32Base);
extern void UARTDMADisable(uint32_t ui32Base, uint32_t ui32DMAFlags);
extern void UARTDMAEnable(uint32_t ui32Base, uint32_t ui32DMAFlags);
extern void UARTEnable(uint32_t ui32Base);
extern void UARTEnableSIR(uint32_t ui32Base, bool bLowPower);
extern void UARTFIFODisable(uint32_t ui32Base);
extern void UARTFIFOEnable(uint32_t ui32Base);
extern void UARTFIFOLevelGet(uint32_t ui32Base, uint32_t *pui32TxLevel, uint32_t *pui32RxLevel);
extern void UARTFIFOLevelSet(uint32_t ui32Base, uint32_t ui32TxLevel, uint32_t ui32RxLevel);
extern uint32_t UARTFlowControlGet(uint32_t ui32Base);
extern void UARTFlowControlSet(uint32_t ui32Base, uint32_t ui32Mode);
extern void UARTIntClear(uint32_t ui32Base, uint32_t ui32IntFlags);
extern void UARTIntDisable(uint32_t ui32Base, uint32_t ui32IntFlags);
extern void UARTIntEnable(uint32_t ui32Base, uint32_t ui32IntFlags);
extern void UARTIntRegister(uint32_t ui32Base, void (*pfnHandler)(void));
extern uint32_t UARTIntStatus(uint32_t ui32Base, bool bMasked);
extern void UARTIntUnregister(uint32_t ui32Base);
extern void UARTModemControlClear(uint32_t ui32Base, uint32_t ui32Control);
extern uint32_t UARTModemControlGet(uint32_t ui32Base);
extern void UARTModemControlSet(uint32_t ui32Base, uint32_t ui32Control);
extern uint32_t UARTModemStatusGet(uint32_t ui32Base);
extern uint32_t UARTParityModeGet(uint32_t ui32Base);
extern void UARTParityModeSet(uint32_t ui32Base, uint32_t ui32Parity);
extern void UARTRxErrorClear(uint32_t ui32Base);
extern uint32_t UARTRxErrorGet(uint32_t ui32Base);
extern void UARTSmartCardDisable(uint32_t ui32Base);
extern void UARTSmartCardEnable(uint32_t ui32Base);
extern bool UARTSpaceAvail(uint32_t ui32Base);
extern uint32_t UARTTxIntModeGet(uint32_t ui32Base);
extern void UARTTxIntModeSet(uint32_t ui32Base, uint32_t ui32Mode);
extern void UARTLoopbackEnable(uint32_t ui32Base);

#endif // _UART_H_
