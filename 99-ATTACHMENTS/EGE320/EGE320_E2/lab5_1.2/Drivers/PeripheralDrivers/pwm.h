//*****************************************************************************
// pwm.h - API function protoypes for Pulse Width Modulation (PWM) ports
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

#ifndef _PWM_H_
#define _PWM_H_

//*****************************************************************************
// The following are defines for the base address of the PWM peripherals
//*****************************************************************************
#define PWM0_BASE               				0x40028000  // Pulse Width Modulator (PWM)

//*****************************************************************************
// The following are defines for the PWM register offsets.
//*****************************************************************************
#define PWM_O_CTL               				0x00000000  // PWM Master Control
#define PWM_O_SYNC              				0x00000004  // PWM Time Base Sync
#define PWM_O_ENABLE            				0x00000008  // PWM Output Enable
#define PWM_O_INVERT            				0x0000000C  // PWM Output Inversion
#define PWM_O_FAULT             				0x00000010  // PWM Output Fault
#define PWM_O_INTEN             				0x00000014  // PWM Interrupt Enable
#define PWM_O_RIS               				0x00000018  // PWM Raw Interrupt Status
#define PWM_O_ISC               				0x0000001C  // PWM Interrupt Status and Clear
#define PWM_O_STATUS            				0x00000020  // PWM Status
#define PWM_O_FAULTVAL          				0x00000024  // PWM Fault Condition Value
#define PWM_O_ENUPD             				0x00000028  // PWM Enable Update
#define PWM_O_0_CTL             				0x00000040  // PWM0 Control
#define PWM_O_0_INTEN           				0x00000044  // PWM0 Interrupt and Trigger Enable
#define PWM_O_0_RIS             				0x00000048  // PWM0 Raw Interrupt Status
#define PWM_O_0_ISC             				0x0000004C  // PWM0 Interrupt Status and Clear
#define PWM_O_0_LOAD            				0x00000050  // PWM0 Load
#define PWM_O_0_COUNT           				0x00000054  // PWM0 Counter
#define PWM_O_0_CMPA            				0x00000058  // PWM0 Compare A
#define PWM_O_0_CMPB            				0x0000005C  // PWM0 Compare B
#define PWM_O_0_GENA            				0x00000060  // PWM0 Generator A Control
#define PWM_O_0_GENB            				0x00000064  // PWM0 Generator B Control
#define PWM_O_0_DBCTL           				0x00000068  // PWM0 Dead-Band Control
#define PWM_O_0_DBRISE          				0x0000006C  // PWM0 Dead-Band Rising-Edge Delay
#define PWM_O_0_DBFALL          				0x00000070  // PWM0 Dead-Band Falling-Edge-Delay
#define PWM_O_0_FLTSRC0         				0x00000074  // PWM0 Fault Source 0
#define PWM_O_0_FLTSRC1         				0x00000078  // PWM0 Fault Source 1
#define PWM_O_0_MINFLTPER       				0x0000007C  // PWM0 Minimum Fault Period
#define PWM_O_1_CTL             				0x00000080  // PWM1 Control
#define PWM_O_1_INTEN           				0x00000084  // PWM1 Interrupt and Trigger Enable
#define PWM_O_1_RIS             				0x00000088  // PWM1 Raw Interrupt Status
#define PWM_O_1_ISC             				0x0000008C  // PWM1 Interrupt Status and Clear
#define PWM_O_1_LOAD            				0x00000090  // PWM1 Load
#define PWM_O_1_COUNT           				0x00000094  // PWM1 Counter
#define PWM_O_1_CMPA            				0x00000098  // PWM1 Compare A
#define PWM_O_1_CMPB            				0x0000009C  // PWM1 Compare B
#define PWM_O_1_GENA            				0x000000A0  // PWM1 Generator A Control
#define PWM_O_1_GENB            				0x000000A4  // PWM1 Generator B Control
#define PWM_O_1_DBCTL           				0x000000A8  // PWM1 Dead-Band Control
#define PWM_O_1_DBRISE          				0x000000AC  // PWM1 Dead-Band Rising-Edge Delay
#define PWM_O_1_DBFALL          				0x000000B0  // PWM1 Dead-Band Falling-Edge-Delay
#define PWM_O_1_FLTSRC0         				0x000000B4  // PWM1 Fault Source 0
#define PWM_O_1_FLTSRC1        					0x000000B8  // PWM1 Fault Source 1
#define PWM_O_1_MINFLTPER       				0x000000BC  // PWM1 Minimum Fault Period
#define PWM_O_2_CTL             				0x000000C0  // PWM2 Control
#define PWM_O_2_INTEN           				0x000000C4  // PWM2 Interrupt and Trigger Enable
#define PWM_O_2_RIS             				0x000000C8  // PWM2 Raw Interrupt Status
#define PWM_O_2_ISC             				0x000000CC  // PWM2 Interrupt Status and Clear
#define PWM_O_2_LOAD            				0x000000D0  // PWM2 Load
#define PWM_O_2_COUNT          					0x000000D4  // PWM2 Counter
#define PWM_O_2_CMPA            				0x000000D8  // PWM2 Compare A
#define PWM_O_2_CMPB            				0x000000DC  // PWM2 Compare B
#define PWM_O_2_GENA            				0x000000E0  // PWM2 Generator A Control
#define PWM_O_2_GENB            				0x000000E4  // PWM2 Generator B Control
#define PWM_O_2_DBCTL           				0x000000E8  // PWM2 Dead-Band Control
#define PWM_O_2_DBRISE          				0x000000EC  // PWM2 Dead-Band Rising-Edge Delay
#define PWM_O_2_DBFALL          				0x000000F0  // PWM2 Dead-Band Falling-Edge-Delay
#define PWM_O_2_FLTSRC0         				0x000000F4  // PWM2 Fault Source 0
#define PWM_O_2_FLTSRC1         				0x000000F8  // PWM2 Fault Source 1
#define PWM_O_2_MINFLTPER       				0x000000FC  // PWM2 Minimum Fault Period
#define PWM_O_3_CTL             				0x00000100  // PWM3 Control
#define PWM_O_3_INTEN           				0x00000104  // PWM3 Interrupt and Trigger Enable
#define PWM_O_3_RIS             				0x00000108  // PWM3 Raw Interrupt Status
#define PWM_O_3_ISC             				0x0000010C  // PWM3 Interrupt Status and Clear
#define PWM_O_3_LOAD            				0x00000110  // PWM3 Load
#define PWM_O_3_COUNT           				0x00000114  // PWM3 Counter
#define PWM_O_3_CMPA            				0x00000118  // PWM3 Compare A
#define PWM_O_3_CMPB            				0x0000011C  // PWM3 Compare B
#define PWM_O_3_GENA            				0x00000120  // PWM3 Generator A Control
#define PWM_O_3_GENB            				0x00000124  // PWM3 Generator B Control
#define PWM_O_3_DBCTL           				0x00000128  // PWM3 Dead-Band Control
#define PWM_O_3_DBRISE          				0x0000012C  // PWM3 Dead-Band Rising-Edge Delay
#define PWM_O_3_DBFALL          				0x00000130  // PWM3 Dead-Band Falling-Edge-Delay
#define PWM_O_3_FLTSRC0         				0x00000134  // PWM3 Fault Source 0
#define PWM_O_3_FLTSRC1         				0x00000138  // PWM3 Fault Source 1
#define PWM_O_3_MINFLTPER       				0x0000013C  // PWM3 Minimum Fault Period
#define PWM_O_0_FLTSEN          				0x00000800  // PWM0 Fault Pin Logic Sense
#define PWM_O_0_FLTSTAT0        				0x00000804  // PWM0 Fault Status 0
#define PWM_O_0_FLTSTAT1        				0x00000808  // PWM0 Fault Status 1
#define PWM_O_1_FLTSEN          				0x00000880  // PWM1 Fault Pin Logic Sense
#define PWM_O_1_FLTSTAT0        				0x00000884  // PWM1 Fault Status 0
#define PWM_O_1_FLTSTAT1        				0x00000888  // PWM1 Fault Status 1
#define PWM_O_2_FLTSEN          				0x00000900  // PWM2 Fault Pin Logic Sense
#define PWM_O_2_FLTSTAT0        				0x00000904  // PWM2 Fault Status 0
#define PWM_O_2_FLTSTAT1        				0x00000908  // PWM2 Fault Status 1
#define PWM_O_3_FLTSEN          				0x00000980  // PWM3 Fault Pin Logic Sense
#define PWM_O_3_FLTSTAT0        				0x00000984  // PWM3 Fault Status 0
#define PWM_O_3_FLTSTAT1        				0x00000988  // PWM3 Fault Status 1
#define PWM_O_PP                				0x00000FC0  // PWM Peripheral Properties
#define PWM_O_CC                				0x00000FC8  // PWM Clock Configuration

//*****************************************************************************
// The following are defines for the PWM Generator standard offsets.
//*****************************************************************************
#define PWM_O_X_CTL             				0x00000000  // Gen Control Reg
#define PWM_O_X_INTEN           				0x00000004  // Gen Int/Trig Enable Reg
#define PWM_O_X_RIS             				0x00000008  // Gen Raw Int Status Reg
#define PWM_O_X_ISC             				0x0000000C  // Gen Int Status Reg
#define PWM_O_X_LOAD            				0x00000010  // Gen Load Reg
#define PWM_O_X_COUNT           				0x00000014  // Gen Counter Reg
#define PWM_O_X_CMPA            				0x00000018  // Gen Compare A Reg
#define PWM_O_X_CMPB            				0x0000001C  // Gen Compare B Reg
#define PWM_O_X_GENA            				0x00000020  // Gen Generator A Ctrl Reg
#define PWM_O_X_GENB            				0x00000024  // Gen Generator B Ctrl Reg
#define PWM_O_X_DBCTL           				0x00000028  // Gen Dead Band Ctrl Reg
#define PWM_O_X_DBRISE          				0x0000002C  // Gen DB Rising Edge Delay Reg
#define PWM_O_X_DBFALL          				0x00000030  // Gen DB Falling Edge Delay Reg
#define PWM_O_X_FLTSRC0         				0x00000034  // Fault pin, comparator condition
#define PWM_O_X_FLTSRC1         				0x00000038  // Digital comparator condition
#define PWM_O_X_MINFLTPER       				0x0000003C  // Fault minimum period extension
#define PWM_O_X_FLTSEN          				0x00000000  // Fault logic sense
#define PWM_O_X_FLTSTAT0        				0x00000004  // Pin and comparator status
#define PWM_O_X_FLTSTAT1        				0x00000008  // Digital comparator status
#define PWM_GEN_0_OFFSET        				0x00000040  // PWM0 base
#define PWM_GEN_1_OFFSET        				0x00000080  // PWM1 base
#define PWM_GEN_2_OFFSET        				0x000000C0  // PWM2 base
#define PWM_GEN_3_OFFSET        				0x00000100  // PWM3 base
#define PWM_EXT_0_OFFSET        				0x00000800  // PWM0 extended base
#define PWM_EXT_1_OFFSET        				0x00000880  // PWM1 extended base
#define PWM_EXT_2_OFFSET        				0x00000900  // PWM2 extended base
#define PWM_EXT_3_OFFSET        				0x00000980  // PWM3 extended base

//*****************************************************************************
// The following are defines for the bit fields in the PWM_O_CTL register.
//*****************************************************************************
#define PWM_CTL_GLOBALSYNC3     				0x00000008  // Update PWM Generator 3
#define PWM_CTL_GLOBALSYNC2     				0x00000004  // Update PWM Generator 2
#define PWM_CTL_GLOBALSYNC1     				0x00000002  // Update PWM Generator 1
#define PWM_CTL_GLOBALSYNC0     				0x00000001  // Update PWM Generator 0

//*****************************************************************************
// The following are defines for the bit fields in the PWM_O_SYNC register.
//*****************************************************************************
#define PWM_SYNC_SYNC3          				0x00000008  // Reset Generator 3 Counter
#define PWM_SYNC_SYNC2         					0x00000004  // Reset Generator 2 Counter
#define PWM_SYNC_SYNC1          				0x00000002  // Reset Generator 1 Counter
#define PWM_SYNC_SYNC0          				0x00000001  // Reset Generator 0 Counter

//*****************************************************************************
// The following are defines for the bit fields in the PWM_O_ENABLE register.
//*****************************************************************************
#define PWM_ENABLE_PWM7EN       				0x00000080  // MnPWM7 Output Enable
#define PWM_ENABLE_PWM6EN       				0x00000040  // MnPWM6 Output Enable
#define PWM_ENABLE_PWM5EN       				0x00000020  // MnPWM5 Output Enable
#define PWM_ENABLE_PWM4EN       				0x00000010  // MnPWM4 Output Enable
#define PWM_ENABLE_PWM3EN       				0x00000008  // MnPWM3 Output Enable
#define PWM_ENABLE_PWM2EN      					0x00000004  // MnPWM2 Output Enable
#define PWM_ENABLE_PWM1EN       				0x00000002  // MnPWM1 Output Enable
#define PWM_ENABLE_PWM0EN       				0x00000001  // MnPWM0 Output Enable

//*****************************************************************************
// The following are defines for the bit fields in the PWM_O_INVERT register.
//*****************************************************************************
#define PWM_INVERT_PWM7INV      				0x00000080  // Invert MnPWM7 Signal
#define PWM_INVERT_PWM6INV      				0x00000040  // Invert MnPWM6 Signal
#define PWM_INVERT_PWM5INV      				0x00000020  // Invert MnPWM5 Signal
#define PWM_INVERT_PWM4INV      				0x00000010  // Invert MnPWM4 Signal
#define PWM_INVERT_PWM3INV      				0x00000008  // Invert MnPWM3 Signal
#define PWM_INVERT_PWM2INV      				0x00000004  // Invert MnPWM2 Signal
#define PWM_INVERT_PWM1INV      				0x00000002  // Invert MnPWM1 Signal
#define PWM_INVERT_PWM0INV      				0x00000001  // Invert MnPWM0 Signal

//*****************************************************************************
// The following are defines for the bit fields in the PWM_O_FAULT register.
//*****************************************************************************
#define PWM_FAULT_FAULT7        				0x00000080  // MnPWM7 Fault
#define PWM_FAULT_FAULT6        				0x00000040  // MnPWM6 Fault
#define PWM_FAULT_FAULT5        				0x00000020  // MnPWM5 Fault
#define PWM_FAULT_FAULT4        				0x00000010  // MnPWM4 Fault
#define PWM_FAULT_FAULT3        				0x00000008  // MnPWM3 Fault
#define PWM_FAULT_FAULT2        				0x00000004  // MnPWM2 Fault
#define PWM_FAULT_FAULT1        				0x00000002  // MnPWM1 Fault
#define PWM_FAULT_FAULT0        				0x00000001  // MnPWM0 Fault

//*****************************************************************************
// The following are defines for the bit fields in the PWM_O_INTEN register.
//*****************************************************************************
#define PWM_INTEN_INTFAULT3     				0x00080000  // Interrupt Fault 3
#define PWM_INTEN_INTFAULT2     				0x00040000  // Interrupt Fault 2
#define PWM_INTEN_INTFAULT1     				0x00020000  // Interrupt Fault 1
#define PWM_INTEN_INTFAULT0    					0x00010000  // Interrupt Fault 0
#define PWM_INTEN_INTPWM3       				0x00000008  // PWM3 Interrupt Enable
#define PWM_INTEN_INTPWM2       				0x00000004  // PWM2 Interrupt Enable
#define PWM_INTEN_INTPWM1       				0x00000002  // PWM1 Interrupt Enable
#define PWM_INTEN_INTPWM0       				0x00000001  // PWM0 Interrupt Enable

//*****************************************************************************
// The following are defines for the bit fields in the PWM_O_RIS register.
//*****************************************************************************
#define PWM_RIS_INTFAULT3      	 				0x00080000  // Interrupt Fault PWM 3
#define PWM_RIS_INTFAULT2       				0x00040000  // Interrupt Fault PWM 2
#define PWM_RIS_INTFAULT1       				0x00020000  // Interrupt Fault PWM 1
#define PWM_RIS_INTFAULT0       				0x00010000  // Interrupt Fault PWM 0
#define PWM_RIS_INTPWM3         				0x00000008  // PWM3 Interrupt Asserted
#define PWM_RIS_INTPWM2         				0x00000004  // PWM2 Interrupt Asserted
#define PWM_RIS_INTPWM1         				0x00000002  // PWM1 Interrupt Asserted
#define PWM_RIS_INTPWM0         				0x00000001  // PWM0 Interrupt Asserted

//*****************************************************************************
// The following are defines for the bit fields in the PWM_O_ISC register.
//*****************************************************************************
#define PWM_ISC_INTFAULT3       				0x00080000  // FAULT3 Interrupt Asserted
#define PWM_ISC_INTFAULT2       				0x00040000  // FAULT2 Interrupt Asserted
#define PWM_ISC_INTFAULT1       				0x00020000  // FAULT1 Interrupt Asserted
#define PWM_ISC_INTFAULT0       				0x00010000  // FAULT0 Interrupt Asserted
#define PWM_ISC_INTPWM3         				0x00000008  // PWM3 Interrupt Status
#define PWM_ISC_INTPWM2         				0x00000004  // PWM2 Interrupt Status
#define PWM_ISC_INTPWM1         				0x00000002  // PWM1 Interrupt Status
#define PWM_ISC_INTPWM0         				0x00000001  // PWM0 Interrupt Status

//*****************************************************************************
// The following are defines for the bit fields in the PWM_O_STATUS register.
//*****************************************************************************
#define PWM_STATUS_FAULT3       				0x00000008  // Generator 3 Fault Status
#define PWM_STATUS_FAULT2      					0x00000004  // Generator 2 Fault Status
#define PWM_STATUS_FAULT1       				0x00000002  // Generator 1 Fault Status
#define PWM_STATUS_FAULT0       				0x00000001  // Generator 0 Fault Status

//*****************************************************************************
// The following are defines for the bit fields in the PWM_O_FAULTVAL register.
//*****************************************************************************
#define PWM_FAULTVAL_PWM7       				0x00000080  // MnPWM7 Fault Value
#define PWM_FAULTVAL_PWM6       				0x00000040  // MnPWM6 Fault Value
#define PWM_FAULTVAL_PWM5       				0x00000020  // MnPWM5 Fault Value
#define PWM_FAULTVAL_PWM4       				0x00000010  // MnPWM4 Fault Value
#define PWM_FAULTVAL_PWM3       				0x00000008  // MnPWM3 Fault Value
#define PWM_FAULTVAL_PWM2       				0x00000004  // MnPWM2 Fault Value
#define PWM_FAULTVAL_PWM1       				0x00000002  // MnPWM1 Fault Value
#define PWM_FAULTVAL_PWM0       				0x00000001  // MnPWM0 Fault Value

//*****************************************************************************
// The following are defines for the bit fields in the PWM_O_ENUPD register.
//*****************************************************************************
#define PWM_ENUPD_ENUPD7_M      				0x0000C000  // MnPWM7 Enable Update Mode
#define PWM_ENUPD_ENUPD7_IMM    				0x00000000  // Immediate
#define PWM_ENUPD_ENUPD7_LSYNC  				0x00008000  // Locally Synchronized
#define PWM_ENUPD_ENUPD7_GSYNC  				0x0000C000  // Globally Synchronized
#define PWM_ENUPD_ENUPD6_M      				0x00003000  // MnPWM6 Enable Update Mode
#define PWM_ENUPD_ENUPD6_IMM    				0x00000000  // Immediate
#define PWM_ENUPD_ENUPD6_LSYNC  				0x00002000  // Locally Synchronized
#define PWM_ENUPD_ENUPD6_GSYNC  				0x00003000  // Globally Synchronized
#define PWM_ENUPD_ENUPD5_M      				0x00000C00  // MnPWM5 Enable Update Mode
#define PWM_ENUPD_ENUPD5_IMM    				0x00000000  // Immediate
#define PWM_ENUPD_ENUPD5_LSYNC  				0x00000800  // Locally Synchronized
#define PWM_ENUPD_ENUPD5_GSYNC  				0x00000C00  // Globally Synchronized
#define PWM_ENUPD_ENUPD4_M      				0x00000300  // MnPWM4 Enable Update Mode
#define PWM_ENUPD_ENUPD4_IMM    				0x00000000  // Immediate
#define PWM_ENUPD_ENUPD4_LSYNC  				0x00000200  // Locally Synchronized
#define PWM_ENUPD_ENUPD4_GSYNC  				0x00000300  // Globally Synchronized
#define PWM_ENUPD_ENUPD3_M      				0x000000C0  // MnPWM3 Enable Update Mode
#define PWM_ENUPD_ENUPD3_IMM    				0x00000000  // Immediate
#define PWM_ENUPD_ENUPD3_LSYNC  				0x00000080  // Locally Synchronized
#define PWM_ENUPD_ENUPD3_GSYNC  				0x000000C0  // Globally Synchronized
#define PWM_ENUPD_ENUPD2_M      				0x00000030  // MnPWM2 Enable Update Mode
#define PWM_ENUPD_ENUPD2_IMM    				0x00000000  // Immediate
#define PWM_ENUPD_ENUPD2_LSYNC  				0x00000020  // Locally Synchronized
#define PWM_ENUPD_ENUPD2_GSYNC  				0x00000030  // Globally Synchronized
#define PWM_ENUPD_ENUPD1_M      				0x0000000C  // MnPWM1 Enable Update Mode
#define PWM_ENUPD_ENUPD1_IMM    				0x00000000  // Immediate
#define PWM_ENUPD_ENUPD1_LSYNC  				0x00000008  // Locally Synchronized
#define PWM_ENUPD_ENUPD1_GSYNC  				0x0000000C  // Globally Synchronized
#define PWM_ENUPD_ENUPD0_M      				0x00000003  // MnPWM0 Enable Update Mode
#define PWM_ENUPD_ENUPD0_IMM    				0x00000000  // Immediate
#define PWM_ENUPD_ENUPD0_LSYNC  				0x00000002  // Locally Synchronized
#define PWM_ENUPD_ENUPD0_GSYNC  				0x00000003  // Globally Synchronized

//*****************************************************************************
// The following are defines for the bit fields in the PWM_O_X_CTL register.
//*****************************************************************************
#define PWM_X_CTL_LATCH         				0x00040000  // Latch Fault Input
#define PWM_X_CTL_MINFLTPER     				0x00020000  // Minimum Fault Period
#define PWM_X_CTL_FLTSRC        				0x00010000  // Fault Condition Source
#define PWM_X_CTL_DBFALLUPD_M   				0x0000C000  // PWMnDBFALL Update Mode
#define PWM_X_CTL_DBFALLUPD_I   				0x00000000  // Immediate
#define PWM_X_CTL_DBFALLUPD_LS  				0x00008000  // Locally Synchronized
#define PWM_X_CTL_DBFALLUPD_GS  				0x0000C000  // Globally Synchronized
#define PWM_X_CTL_DBRISEUPD_M   				0x00003000  // PWMnDBRISE Update Mode
#define PWM_X_CTL_DBRISEUPD_I   				0x00000000  // Immediate
#define PWM_X_CTL_DBRISEUPD_LS  				0x00002000  // Locally Synchronized
#define PWM_X_CTL_DBRISEUPD_GS  				0x00003000  // Globally Synchronized
#define PWM_X_CTL_DBCTLUPD_M   					0x00000C00  // PWMnDBCTL Update Mode
#define PWM_X_CTL_DBCTLUPD_I    				0x00000000  // Immediate
#define PWM_X_CTL_DBCTLUPD_LS   				0x00000800  // Locally Synchronized
#define PWM_X_CTL_DBCTLUPD_GS   				0x00000C00  // Globally Synchronized
#define PWM_X_CTL_GENBUPD_M    					0x00000300  // PWMnGENB Update Mode
#define PWM_X_CTL_GENBUPD_I     				0x00000000  // Immediate
#define PWM_X_CTL_GENBUPD_LS    				0x00000200  // Locally Synchronized
#define PWM_X_CTL_GENBUPD_GS    				0x00000300  // Globally Synchronized
#define PWM_X_CTL_GENAUPD_M     				0x000000C0  // PWMnGENA Update Mode
#define PWM_X_CTL_GENAUPD_I     				0x00000000  // Immediate
#define PWM_X_CTL_GENAUPD_LS    				0x00000080  // Locally Synchronized
#define PWM_X_CTL_GENAUPD_GS    				0x000000C0  // Globally Synchronized
#define PWM_X_CTL_CMPBUPD       				0x00000020  // Comparator B Update Mode
#define PWM_X_CTL_CMPAUPD       				0x00000010  // Comparator A Update Mode
#define PWM_X_CTL_LOADUPD       				0x00000008  // Load Register Update Mode
#define PWM_X_CTL_DEBUG         				0x00000004  // Debug Mode
#define PWM_X_CTL_MODE          				0x00000002  // Counter Mode
#define PWM_X_CTL_ENABLE        				0x00000001  // PWM Block Enable

//*****************************************************************************
// The following are defines for the bit fields in the PWM_O_X_INTEN register.
//*****************************************************************************
#define PWM_X_INTEN_TRCMPBD     				0x00002000  // Trigger for Counter=PWMnCMPB Down
#define PWM_X_INTEN_TRCMPBU     				0x00001000  // Trigger for Counter=PWMnCMPB Up
#define PWM_X_INTEN_TRCMPAD     				0x00000800  // Trigger for Counter=PWMnCMPA Down
#define PWM_X_INTEN_TRCMPAU     				0x00000400  // Trigger for Counter=PWMnCMPA Up
#define PWM_X_INTEN_TRCNTLOAD   				0x00000200  // Trigger for Counter=PWMnLOAD
#define PWM_X_INTEN_TRCNTZERO   				0x00000100  // Trigger for Counter=0
#define PWM_X_INTEN_INTCMPBD    				0x00000020  // Interrupt for Counter=PWMnCMPB Down
#define PWM_X_INTEN_INTCMPBU    				0x00000010  // Interrupt for Counter=PWMnCMPB Up
#define PWM_X_INTEN_INTCMPAD    				0x00000008  // Interrupt for Counter=PWMnCMPA Down
#define PWM_X_INTEN_INTCMPAU    				0x00000004  // Interrupt for Counter=PWMnCMPA Up
#define PWM_X_INTEN_INTCNTLOAD  				0x00000002  // Interrupt for Counter=PWMnLOAD
#define PWM_X_INTEN_INTCNTZERO  				0x00000001  // Interrupt for Counter=0

//*****************************************************************************
// The following are defines for the bit fields in the PWM_O_X_RIS register.
//*****************************************************************************
#define PWM_X_RIS_INTCMPBD      				0x00000020  // Comparator B Down Interrupt Status
#define PWM_X_RIS_INTCMPBU      				0x00000010  // Comparator B Up Interrupt Status
#define PWM_X_RIS_INTCMPAD      				0x00000008  // Comparator A Down Interrupt Status
#define PWM_X_RIS_INTCMPAU      				0x00000004  // Comparator A Up Interrupt Status
#define PWM_X_RIS_INTCNTLOAD    				0x00000002  // Counter=Load Interrupt Status
#define PWM_X_RIS_INTCNTZERO    				0x00000001  // Counter=0 Interrupt Status

//*****************************************************************************
// The following are defines for the bit fields in the PWM_O_X_ISC register.
//*****************************************************************************
#define PWM_X_ISC_INTCMPBD      				0x00000020  // Comparator B Down Interrupt
#define PWM_X_ISC_INTCMPBU      				0x00000010  // Comparator B Up Interrupt
#define PWM_X_ISC_INTCMPAD      				0x00000008  // Comparator A Down Interrupt
#define PWM_X_ISC_INTCMPAU     					0x00000004  // Comparator A Up Interrupt
#define PWM_X_ISC_INTCNTLOAD    				0x00000002  // Counter=Load Interrupt
#define PWM_X_ISC_INTCNTZERO    				0x00000001  // Counter=0 Interrupt

//*****************************************************************************
// The following are defines for the bit fields in the PWM_O_X_LOAD register.
//*****************************************************************************
#define PWM_X_LOAD_M            				0x0000FFFF  // Counter Load Value
#define PWM_X_LOAD_S            				0

//*****************************************************************************
// The following are defines for the bit fields in the PWM_O_X_COUNT register.
//*****************************************************************************
#define PWM_X_COUNT_M           				0x0000FFFF  // Counter Value
#define PWM_X_COUNT_S           				0

//*****************************************************************************
// The following are defines for the bit fields in the PWM_O_X_CMPA register.
//*****************************************************************************
#define PWM_X_CMPA_M            				0x0000FFFF  // Comparator A Value
#define PWM_X_CMPA_S            				0

//*****************************************************************************
// The following are defines for the bit fields in the PWM_O_X_CMPB register.
//*****************************************************************************
#define PWM_X_CMPB_M            				0x0000FFFF  // Comparator B Value
#define PWM_X_CMPB_S            				0

//*****************************************************************************
// The following are defines for the bit fields in the PWM_O_X_GENA register.
//*****************************************************************************
#define PWM_X_GENA_ACTCMPBD_M   				0x00000C00  // Action for Comparator B Down
#define PWM_X_GENA_ACTCMPBD_NONE                0x00000000  // Do nothing
#define PWM_X_GENA_ACTCMPBD_INV 				0x00000400  // Invert pwmA
#define PWM_X_GENA_ACTCMPBD_ZERO                0x00000800  // Drive pwmA Low
#define PWM_X_GENA_ACTCMPBD_ONE 				0x00000C00  // Drive pwmA High
#define PWM_X_GENA_ACTCMPBU_M   				0x00000300  // Action for Comparator B Up
#define PWM_X_GENA_ACTCMPBU_NONE                0x00000000  // Do nothing
#define PWM_X_GENA_ACTCMPBU_INV 				0x00000100  // Invert pwmA
#define PWM_X_GENA_ACTCMPBU_ZERO                0x00000200  // Drive pwmA Low
#define PWM_X_GENA_ACTCMPBU_ONE 				0x00000300  // Drive pwmA High
#define PWM_X_GENA_ACTCMPAD_M   				0x000000C0  // Action for Comparator A Down
#define PWM_X_GENA_ACTCMPAD_NONE        		0x00000000  // Do nothing
#define PWM_X_GENA_ACTCMPAD_INV 				0x00000040  // Invert pwmA
#define PWM_X_GENA_ACTCMPAD_ZERO         		0x00000080  // Drive pwmA Low
#define PWM_X_GENA_ACTCMPAD_ONE 				0x000000C0  // Drive pwmA High
#define PWM_X_GENA_ACTCMPAU_M   				0x00000030  // Action for Comparator A Up
#define PWM_X_GENA_ACTCMPAU_NONE    			0x00000000  // Do nothing
#define PWM_X_GENA_ACTCMPAU_INV 				0x00000010  // Invert pwmA
#define PWM_X_GENA_ACTCMPAU_ZERO        		0x00000020  // Drive pwmA Low
#define PWM_X_GENA_ACTCMPAU_ONE 				0x00000030  // Drive pwmA High
#define PWM_X_GENA_ACTLOAD_M    				0x0000000C  // Action for Counter=LOAD
#define PWM_X_GENA_ACTLOAD_NONE 				0x00000000  // Do nothing
#define PWM_X_GENA_ACTLOAD_INV  				0x00000004  // Invert pwmA
#define PWM_X_GENA_ACTLOAD_ZERO 				0x00000008  // Drive pwmA Low
#define PWM_X_GENA_ACTLOAD_ONE  				0x0000000C  // Drive pwmA High
#define PWM_X_GENA_ACTZERO_M    				0x00000003  // Action for Counter=0
#define PWM_X_GENA_ACTZERO_NONE 				0x00000000  // Do nothing
#define PWM_X_GENA_ACTZERO_INV  				0x00000001  // Invert pwmA
#define PWM_X_GENA_ACTZERO_ZERO 				0x00000002  // Drive pwmA Low
#define PWM_X_GENA_ACTZERO_ONE  				0x00000003  // Drive pwmA High

//*****************************************************************************
// The following are defines for the bit fields in the PWM_O_X_GENB register.
//*****************************************************************************
#define PWM_X_GENB_ACTCMPBD_M   				0x00000C00  // Action for Comparator B Down
#define PWM_X_GENB_ACTCMPBD_NONE                0x00000000  // Do nothing
#define PWM_X_GENB_ACTCMPBD_INV 				0x00000400  // Invert pwmB
#define PWM_X_GENB_ACTCMPBD_ZERO          		0x00000800  // Drive pwmB Low
#define PWM_X_GENB_ACTCMPBD_ONE 				0x00000C00  // Drive pwmB High
#define PWM_X_GENB_ACTCMPBU_M   				0x00000300  // Action for Comparator B Up
#define PWM_X_GENB_ACTCMPBU_NONE   				0x00000000  // Do nothing
#define PWM_X_GENB_ACTCMPBU_INV 				0x00000100  // Invert pwmB
#define PWM_X_GENB_ACTCMPBU_ZERO    			0x00000200  // Drive pwmB Low
#define PWM_X_GENB_ACTCMPBU_ONE 				0x00000300  // Drive pwmB High
#define PWM_X_GENB_ACTCMPAD_M   				0x000000C0  // Action for Comparator A Down
#define PWM_X_GENB_ACTCMPAD_NONE          		0x00000000  // Do nothing
#define PWM_X_GENB_ACTCMPAD_INV 				0x00000040  // Invert pwmB
#define PWM_X_GENB_ACTCMPAD_ZERO          		0x00000080  // Drive pwmB Low
#define PWM_X_GENB_ACTCMPAD_ONE 				0x000000C0  // Drive pwmB High
#define PWM_X_GENB_ACTCMPAU_M   				0x00000030  // Action for Comparator A Up
#define PWM_X_GENB_ACTCMPAU_NONE    			0x00000000  // Do nothing
#define PWM_X_GENB_ACTCMPAU_INV					0x00000010  // Invert pwmB
#define PWM_X_GENB_ACTCMPAU_ZERO  				0x00000020  // Drive pwmB Low
#define PWM_X_GENB_ACTCMPAU_ONE 				0x00000030  // Drive pwmB High
#define PWM_X_GENB_ACTLOAD_M    				0x0000000C  // Action for Counter=LOAD
#define PWM_X_GENB_ACTLOAD_NONE 				0x00000000  // Do nothing
#define PWM_X_GENB_ACTLOAD_INV  				0x00000004  // Invert pwmB
#define PWM_X_GENB_ACTLOAD_ZERO 				0x00000008  // Drive pwmB Low
#define PWM_X_GENB_ACTLOAD_ONE  				0x0000000C  // Drive pwmB High
#define PWM_X_GENB_ACTZERO_M    				0x00000003  // Action for Counter=0
#define PWM_X_GENB_ACTZERO_NONE 				0x00000000  // Do nothing
#define PWM_X_GENB_ACTZERO_INV  				0x00000001  // Invert pwmB
#define PWM_X_GENB_ACTZERO_ZERO 				0x00000002  // Drive pwmB Low
#define PWM_X_GENB_ACTZERO_ONE  				0x00000003  // Drive pwmB High

//*****************************************************************************
// The following are defines for the bit fields in the PWM_O_X_DBCTL register.
//*****************************************************************************
#define PWM_X_DBCTL_ENABLE      				0x00000001  // Dead-Band Generator Enable

//*****************************************************************************
// The following are defines for the bit fields in the PWM_O_X_DBRISE register.
//*****************************************************************************
#define PWM_X_DBRISE_DELAY_M    				0x00000FFF  // Dead-Band Rise Delay
#define PWM_X_DBRISE_DELAY_S    				0

//*****************************************************************************
// The following are defines for the bit fields in the PWM_O_X_DBFALL register.
//*****************************************************************************
#define PWM_X_DBFALL_DELAY_M    				0x00000FFF  // Dead-Band Fall Delay
#define PWM_X_DBFALL_DELAY_S    				0

//*****************************************************************************
// The following are defines for the bit fields in the PWM_O_X_FLTSRC0 register.
//*****************************************************************************
#define PWM_X_FLTSRC0_FAULT3    				0x00000008  // Fault3 Input
#define PWM_X_FLTSRC0_FAULT2    				0x00000004  // Fault2 Input
#define PWM_X_FLTSRC0_FAULT1    				0x00000002  // Fault1 Input
#define PWM_X_FLTSRC0_FAULT0    				0x00000001  // Fault0 Input

//*****************************************************************************
// The following are defines for the bit fields in the PWM_O_X_FLTSRC1 register.
//*****************************************************************************
#define PWM_X_FLTSRC1_DCMP7     				0x00000080  // Digital Comparator 7
#define PWM_X_FLTSRC1_DCMP6     				0x00000040  // Digital Comparator 6
#define PWM_X_FLTSRC1_DCMP5     				0x00000020  // Digital Comparator 5
#define PWM_X_FLTSRC1_DCMP4     				0x00000010  // Digital Comparator 4
#define PWM_X_FLTSRC1_DCMP3     				0x00000008  // Digital Comparator 3
#define PWM_X_FLTSRC1_DCMP2     				0x00000004  // Digital Comparator 2
#define PWM_X_FLTSRC1_DCMP1     				0x00000002  // Digital Comparator 1
#define PWM_X_FLTSRC1_DCMP0     				0x00000001  // Digital Comparator 0

//*****************************************************************************
// The following are defines for the bit fields in the PWM_O_X_MINFLTPER register.
//*****************************************************************************
#define PWM_X_MINFLTPER_M       				0x0000FFFF  // Minimum Fault Period
#define PWM_X_MINFLTPER_S       				0

//*****************************************************************************
// The following are defines for the bit fields in the PWM_O_X_FLTSEN register.
//*****************************************************************************
#define PWM_X_FLTSEN_FAULT3     				0x00000008  // Fault3 Sense
#define PWM_X_FLTSEN_FAULT2    					0x00000004  // Fault2 Sense
#define PWM_X_FLTSEN_FAULT1     				0x00000002  // Fault1 Sense
#define PWM_X_FLTSEN_FAULT0     				0x00000001  // Fault0 Sense

//*****************************************************************************
// The following are defines for the bit fields in the PWM_O_X_FLTSTAT0 register.
//*****************************************************************************
#define PWM_X_FLTSTAT0_FAULT3   				0x00000008  // Fault Input 3
#define PWM_X_FLTSTAT0_FAULT2   				0x00000004  // Fault Input 2
#define PWM_X_FLTSTAT0_FAULT1  					0x00000002  // Fault Input 1
#define PWM_X_FLTSTAT0_FAULT0   				0x00000001  // Fault Input 0

//*****************************************************************************
// The following are defines for the bit fields in the PWM_O_X_FLTSTAT1 register.
//*****************************************************************************
#define PWM_X_FLTSTAT1_DCMP7    				0x00000080  // Digital Comparator 7 Trigger
#define PWM_X_FLTSTAT1_DCMP6    				0x00000040  // Digital Comparator 6 Trigger
#define PWM_X_FLTSTAT1_DCMP5    				0x00000020  // Digital Comparator 5 Trigger
#define PWM_X_FLTSTAT1_DCMP4    				0x00000010  // Digital Comparator 4 Trigger
#define PWM_X_FLTSTAT1_DCMP3    				0x00000008  // Digital Comparator 3 Trigger
#define PWM_X_FLTSTAT1_DCMP2    				0x00000004  // Digital Comparator 2 Trigger
#define PWM_X_FLTSTAT1_DCMP1    				0x00000002  // Digital Comparator 1 Trigger
#define PWM_X_FLTSTAT1_DCMP0    				0x00000001  // Digital Comparator 0 Trigger

//*****************************************************************************
// The following are defines for the bit fields in the PWM_O_CC register.
//*****************************************************************************
#define PWM_CC_USEPWM           				0x00000100  // Use PWM Clock Divisor
#define PWM_CC_PWMDIV_M         				0x00000007  // PWM Clock Divider
#define PWM_CC_PWMDIV_2         				0x00000000  // /2
#define PWM_CC_PWMDIV_4         				0x00000001  // /4
#define PWM_CC_PWMDIV_8         				0x00000002  // /8
#define PWM_CC_PWMDIV_16        				0x00000003  // /16
#define PWM_CC_PWMDIV_32        				0x00000004  // /32
#define PWM_CC_PWMDIV_64        				0x00000005  // /64





//*****************************************************************************
// Defines that can be passed to the PWMClockSet() API as the ui32Config
// parameter, and can be returned by the PWMClockGet() API.
//*****************************************************************************
#define PWM_SYSCLK_DIV_1        				0x00000000  // PWM clock is system clock
#define PWM_SYSCLK_DIV_2        				0x00000100  // PWM clock is system clock /2
#define PWM_SYSCLK_DIV_4        				0x00000101  // PWM clock is system clock /4
#define PWM_SYSCLK_DIV_8        				0x00000102  // PWM clock is system clock /8
#define PWM_SYSCLK_DIV_16      					0x00000103  // PWM clock is system clock /16
#define PWM_SYSCLK_DIV_32       				0x00000104  // PWM clock is system clock /32
#define PWM_SYSCLK_DIV_64       				0x00000105  // PWM clock is system clock /64

//*****************************************************************************
// Defines to identify the generators within a module.
//*****************************************************************************
#define PWM_GEN_0               				0x00000040  // Offset address of Gen0
#define PWM_GEN_1               				0x00000080  // Offset address of Gen1
#define PWM_GEN_2               				0x000000C0  // Offset address of Gen2
#define PWM_GEN_3               				0x00000100  // Offset address of Gen3
#define PWM_GEN_0_BIT           				0x00000001  // Bit-wise ID for Gen0
#define PWM_GEN_1_BIT           				0x00000002  // Bit-wise ID for Gen1
#define PWM_GEN_2_BIT           				0x00000004  // Bit-wise ID for Gen2
#define PWM_GEN_3_BIT           				0x00000008  // Bit-wise ID for Gen3
#define PWM_GEN_EXT_0           				0x00000800  // Offset of Gen0 ext address range
#define PWM_GEN_EXT_1           				0x00000880  // Offset of Gen1 ext address range
#define PWM_GEN_EXT_2          					0x00000900  // Offset of Gen2 ext address range
#define PWM_GEN_EXT_3           				0x00000980  // Offset of Gen3 ext address range

//*****************************************************************************
// Defines for enabling, disabling, and clearing PWM interrupts.
//*****************************************************************************
#define PWM_INT_GEN_0           				0x00000001  // Generator 0 interrupt
#define PWM_INT_GEN_1           				0x00000002  // Generator 1 interrupt
#define PWM_INT_GEN_2           				0x00000004  // Generator 2 interrupt
#define PWM_INT_GEN_3          					0x00000008  // Generator 3 interrupt
#define PWM_INT_FAULT0          				0x00010000  // Fault0 interrupt
#define PWM_INT_FAULT1          				0x00020000  // Fault1 interrupt
#define PWM_INT_FAULT2          				0x00040000  // Fault2 interrupt
#define PWM_INT_FAULT3          				0x00080000  // Fault3 interrupt
#define PWM_INT_FAULT_M         				0x000F0000  // Fault interrupt source mask

//*****************************************************************************
// The following defines are passed to PWMGenConfigure() as the ui32Config
// parameter and specify the configuration of the PWM generator.
//*****************************************************************************
#define PWM_GEN_MODE_DOWN       				0x00000000  // Down count mode
#define PWM_GEN_MODE_UP_DOWN    				0x00000002  // Up/Down count mode
#define PWM_GEN_MODE_SYNC       				0x00000038  // Synchronous updates
#define PWM_GEN_MODE_NO_SYNC    				0x00000000  // Immediate updates
#define PWM_GEN_MODE_DBG_RUN    				0x00000004  // Continue running in debug mode
#define PWM_GEN_MODE_DBG_STOP   				0x00000000  // Stop running in debug mode
#define PWM_GEN_MODE_FAULT_LATCHED				0x00040000  // Fault is latched
#define PWM_GEN_MODE_FAULT_UNLATCHED			0x00000000  // Fault is not latched
#define PWM_GEN_MODE_FAULT_MINPER				0x00020000  // Enable min fault period
#define PWM_GEN_MODE_FAULT_NO_MINPER			0x00000000  // Disable min fault period
#define PWM_GEN_MODE_FAULT_EXT  				0x00010000  // Enable extended fault support
#define PWM_GEN_MODE_FAULT_LEGACY 				0x00000000  // Disable extended fault support
#define PWM_GEN_MODE_DB_NO_SYNC					0x00000000  // Deadband updates occur immediately
#define PWM_GEN_MODE_DB_SYNC_LOCAL 				0x0000A800  // Deadband updates locally synchronized
#define PWM_GEN_MODE_DB_SYNC_GLOBAL 			0x0000FC00  // Deadband updates globally synchronized
#define PWM_GEN_MODE_GEN_NO_SYNC 				0x00000000  // Generator mode updates occur immediately
#define PWM_GEN_MODE_GEN_SYNC_LOCAL 			0x00000280  // Generator mode updates locally synchronized
#define PWM_GEN_MODE_GEN_SYNC_GLOBAL 			0x000003C0  // Generator mode updates globally synchronized

//*****************************************************************************
// Defines to identify the sense of each of the external FAULTn signals
//*****************************************************************************
#define PWM_FAULT0_SENSE_HIGH   				0x00000000
#define PWM_FAULT0_SENSE_LOW    				0x00000001
#define PWM_FAULT1_SENSE_HIGH   				0x00000000
#define PWM_FAULT1_SENSE_LOW    				0x00000002
#define PWM_FAULT2_SENSE_HIGH   				0x00000000
#define PWM_FAULT2_SENSE_LOW    				0x00000004
#define PWM_FAULT3_SENSE_HIGH   				0x00000000
#define PWM_FAULT3_SENSE_LOW    				0x00000008

//*****************************************************************************
// Defines to identify each of the possible fault trigger conditions in
// PWM_FAULT_GROUP_0.
//*****************************************************************************
#define PWM_FAULT_GROUP_0       				0
#define PWM_FAULT_FAULT0        				0x00000001
#define PWM_FAULT_FAULT1        				0x00000002
#define PWM_FAULT_FAULT2        				0x00000004
#define PWM_FAULT_FAULT3        				0x00000008

//*****************************************************************************
// Defines to identify each of the possible fault trigger conditions in
// PWM_FAULT_GROUP_1.
//*****************************************************************************
#define PWM_FAULT_GROUP_1       				1
#define PWM_FAULT_DCMP0         				0x00000001
#define PWM_FAULT_DCMP1         				0x00000002
#define PWM_FAULT_DCMP2         				0x00000004
#define PWM_FAULT_DCMP3         				0x00000008
#define PWM_FAULT_DCMP4         				0x00000010
#define PWM_FAULT_DCMP5         				0x00000020
#define PWM_FAULT_DCMP6         				0x00000040
#define PWM_FAULT_DCMP7         				0x00000080

//*****************************************************************************
// Defines for enabling, disabling, and clearing PWM generator interrupts and
// triggers.
//*****************************************************************************
#define PWM_INT_CNT_ZERO        				0x00000001  // Int if COUNT = 0
#define PWM_INT_CNT_LOAD       				 	0x00000002  // Int if COUNT = LOAD
#define PWM_INT_CNT_AU          				0x00000004  // Int if COUNT = CMPA U
#define PWM_INT_CNT_AD          				0x00000008  // Int if COUNT = CMPA D
#define PWM_INT_CNT_BU          				0x00000010  // Int if COUNT = CMPA U
#define PWM_INT_CNT_BD          				0x00000020  // Int if COUNT = CMPA D
#define PWM_TR_CNT_ZERO         				0x00000100  // Trig if COUNT = 0
#define PWM_TR_CNT_LOAD         				0x00000200  // Trig if COUNT = LOAD
#define PWM_TR_CNT_AU           				0x00000400  // Trig if COUNT = CMPA U
#define PWM_TR_CNT_AD           				0x00000800  // Trig if COUNT = CMPA D
#define PWM_TR_CNT_BU           				0x00001000  // Trig if COUNT = CMPA U
#define PWM_TR_CNT_BD           				0x00002000  // Trig if COUNT = CMPA D

//*****************************************************************************
// Defines to identify the outputs within a module.
//*****************************************************************************
#define PWM_OUT_0               				0x00000040  // Encoded offset address of PWM0
#define PWM_OUT_1               				0x00000041  // Encoded offset address of PWM1
#define PWM_OUT_2               				0x00000082  // Encoded offset address of PWM2
#define PWM_OUT_3               				0x00000083  // Encoded offset address of PWM3
#define PWM_OUT_4               				0x000000C4  // Encoded offset address of PWM4
#define PWM_OUT_5               				0x000000C5  // Encoded offset address of PWM5
#define PWM_OUT_6               				0x00000106  // Encoded offset address of PWM6
#define PWM_OUT_7               				0x00000107  // Encoded offset address of PWM7
#define PWM_OUT_0_BIT           				0x00000001  // Bit-wise ID for PWM0
#define PWM_OUT_1_BIT           				0x00000002  // Bit-wise ID for PWM1
#define PWM_OUT_2_BIT           				0x00000004  // Bit-wise ID for PWM2
#define PWM_OUT_3_BIT           				0x00000008  // Bit-wise ID for PWM3
#define PWM_OUT_4_BIT           				0x00000010  // Bit-wise ID for PWM4
#define PWM_OUT_5_BIT           				0x00000020  // Bit-wise ID for PWM5
#define PWM_OUT_6_BIT           				0x00000040  // Bit-wise ID for PWM6
#define PWM_OUT_7_BIT          	 				0x00000080  // Bit-wise ID for PWM7

//*****************************************************************************
// Defines passed to PWMOutputUpdateMode() to identify the synchronization mode
// to use when enabling or disabling outputs using PWMOutputState().
//*****************************************************************************
#define PWM_OUTPUT_MODE_NO_SYNC 				0x00000000 // Updates to occur immediately
#define PWM_OUTPUT_MODE_SYNC_LOCAL 				0x00000002 // Updates are locally synchronized
#define PWM_OUTPUT_MODE_SYNC_GLOBAL 			0x00000003 // Updates are globally synchronized





//*****************************************************************************
// API Function prototypes
//*****************************************************************************
extern uint32_t PWMClockGet(uint32_t ui32Base);
extern void PWMClockSet(uint32_t ui32Base, uint32_t ui32Config);
extern void PWMDeadBandDisable(uint32_t ui32Base, uint32_t ui32Gen);
extern void PWMDeadBandEnable(uint32_t ui32Base, uint32_t ui32Gen, uint16_t ui16Rise, uint16_t ui16Fall);
extern void PWMFaultIntClear(uint32_t ui32Base);
extern void PWMFaultIntClearExt(uint32_t ui32Base, uint32_t ui32FaultInts);
extern void PWMFaultIntRegister(uint32_t ui32Base, void (*pfnIntHandler)(void));
extern void PWMFaultIntUnregister(uint32_t ui32Base);
extern void PWMGenConfigure(uint32_t ui32Base, uint32_t ui32Gen, uint32_t ui32Config);
extern void PWMGenDisable(uint32_t ui32Base, uint32_t ui32Gen);
extern void PWMGenEnable(uint32_t ui32Base, uint32_t ui32Gen);
extern void PWMGenFaultClear(uint32_t ui32Base, uint32_t ui32Gen, uint32_t ui32Group, uint32_t ui32FaultTriggers);
extern void PWMGenFaultConfigure(uint32_t ui32Base, uint32_t ui32Gen, uint32_t ui32MinFaultPeriod, uint32_t ui32FaultSenses);
extern uint32_t PWMGenFaultStatus(uint32_t ui32Base, uint32_t ui32Gen, uint32_t ui32Group);
extern uint32_t PWMGenFaultTriggerGet(uint32_t ui32Base, uint32_t ui32Gen, uint32_t ui32Group);
extern void PWMGenFaultTriggerSet(uint32_t ui32Base, uint32_t ui32Gen, uint32_t ui32Group, uint32_t ui32FaultTriggers);
extern void PWMGenIntClear(uint32_t ui32Base, uint32_t ui32Gen, uint32_t ui32Ints);
extern void PWMGenIntRegister(uint32_t ui32Base, uint32_t ui32Gen, void (*pfnIntHandler)(void));
extern uint32_t PWMGenIntStatus(uint32_t ui32Base, uint32_t ui32Gen, bool bMasked);
extern void PWMGenIntTrigDisable(uint32_t ui32Base, uint32_t ui32Gen, uint32_t ui32IntTrig);
extern void PWMGenIntTrigEnable(uint32_t ui32Base, uint32_t ui32Gen, uint32_t ui32IntTrig);
extern void PWMGenIntUnregister(uint32_t ui32Base, uint32_t ui32Gen);
extern uint32_t PWMGenPeriodGet(uint32_t ui32Base, uint32_t ui32Gen);
extern void PWMGenPeriodSet(uint32_t ui32Base, uint32_t ui32Gen, uint32_t ui32Period);
extern void PWMIntDisable(uint32_t ui32Base, uint32_t ui32GenFault);
extern void PWMIntEnable(uint32_t ui32Base, uint32_t ui32GenFault);
extern uint32_t PWMIntStatus(uint32_t ui32Base, bool bMasked);
extern void PWMOutputFault(uint32_t ui32Base, uint32_t ui32PWMOutBits, bool bFaultSuppress);
extern void PWMOutputFaultLevel(uint32_t ui32Base, uint32_t ui32PWMOutBits, bool bDriveHigh);
extern void PWMOutputInvert(uint32_t ui32Base, uint32_t ui32PWMOutBits, bool bInvert);
extern void PWMOutputState(uint32_t ui32Base, uint32_t ui32PWMOutBits, bool bEnable);
extern void PWMOutputUpdateMode(uint32_t ui32Base, uint32_t ui32PWMOutBits, uint32_t ui32Mode);
extern uint32_t PWMPulseWidthGet(uint32_t ui32Base, uint32_t ui32PWMOut);
extern void PWMPulseWidthSet(uint32_t ui32Base, uint32_t ui32PWMOut, uint32_t ui32Width);
extern void PWMSyncTimeBase(uint32_t ui32Base, uint32_t ui32GenBits);
extern void PWMSyncUpdate(uint32_t ui32Base, uint32_t ui32GenBits);

#endif // _PWM_H_
