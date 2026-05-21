//*****************************************************************************
// systick.h - Prototypes for the SysTick driver.
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

#ifndef _SYSTICK_H_
#define _SYSTICK_H_

//*****************************************************************************
// The following are defines for the System Timer (SysTick) register addresses.
//*****************************************************************************

#define ST_CTRL           						0xE000E010  // SysTick Control and Status Register
#define ST_RELOAD          						0xE000E014  // SysTick Reload Value Register
#define ST_CURRENT         						0xE000E018  // SysTick Current Value Register

//*****************************************************************************
// The following are defines for the bit fields in the ST_CTRL register.
//*****************************************************************************
#define ST_CTRL_COUNT      						0x00010000  // Count Flag
#define ST_CTRL_CLK_SRC    						0x00000004  // Clock Source
#define ST_CTRL_INTEN      						0x00000002  // Interrupt Enable
#define ST_CTRL_ENABLE     						0x00000001  // Enable

//*****************************************************************************
// Prototypes for the APIs.
//*****************************************************************************
extern void SysTickDisable(void);							//Tested
extern void SysTickEnable(void);							//Tested
extern void SysTickIntDisable(void);						//Tested
extern void SysTickIntEnable(void);							//Tested
extern void SysTickIntRegister(void (*pfnHandler)(void));	//Tested
extern void SysTickIntUnregister(void);						//Tested
extern uint32_t SysTickPeriodGet(void);						//Tested
extern void SysTickPeriodSet(uint32_t ui32Period);			//Tested
extern uint32_t SysTickValueGet(void);						//Tested

#endif // _SYSTICK_H_
