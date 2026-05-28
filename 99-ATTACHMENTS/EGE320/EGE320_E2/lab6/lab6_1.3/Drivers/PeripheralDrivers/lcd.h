//*****************************************************************************
// lcd.h - Defines and Macros for the LCD Controller module.
//
// Copyright (c) 2012-2015 Texas Instruments Incorporated.  All rights reserved.
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

#ifndef _LCD_H_
#define _LCD_H_

//*****************************************************************************
// The following are defines for the base address of the memories and peripherals.
//*****************************************************************************

#define LCD0_BASE               				0x44050000  // LCD Controller

//*****************************************************************************
// The following are defines for the LCD register offsets.
//*****************************************************************************
#define LCD_O_PID               				0x00000000  // LCD PID Register Format
#define LCD_O_CTL               				0x00000004  // LCD Control
#define LCD_O_LIDDCTL           				0x0000000C  // LCD LIDD Control
#define LCD_O_LIDDCS0CFG       					0x00000010  // LCD LIDD CS0 Configuration
#define LCD_O_LIDDCS0ADDR       				0x00000014  // LIDD CS0 Read/Write Address
#define LCD_O_LIDDCS0DATA       				0x00000018  // LIDD CS0 Data Read/Write Initiation
#define LCD_O_LIDDCS1CFG        				0x0000001C  // LIDD CS1 Configuration
#define LCD_O_LIDDCS1ADDR       				0x00000020  // LIDD CS1 Address Read/Write Initiation
#define LCD_O_LIDDCS1DATA       				0x00000024  // LIDD CS1 Data Read/Write Initiation
#define LCD_O_RASTRCTL          				0x00000028  // LCD Raster Control
#define LCD_O_RASTRTIM0        					0x0000002C  // LCD Raster Timing 0
#define LCD_O_RASTRTIM1         				0x00000030  // LCD Raster Timing 1
#define LCD_O_RASTRTIM2         				0x00000034  // LCD Raster Timing 2
#define LCD_O_RASTRSUBP1        				0x00000038  // LCD Raster Subpanel Display 1
#define LCD_O_RASTRSUBP2        				0x0000003C  // LCD Raster Subpanel Display 2
#define LCD_O_DMACTL            				0x00000040  // LCD DMA Control
#define LCD_O_DMABAFB0          				0x00000044  // LCD DMA Frame Buffer 0 Base Address
#define LCD_O_DMACAFB0          				0x00000048  // LCD DMA Frame Buffer 0 Ceiling Address
#define LCD_O_DMABAFB1          				0x0000004C  // LCD DMA Frame Buffer 1 Base Address
#define LCD_O_DMACAFB1          				0x00000050  // LCD DMA Frame Buffer 1 Ceiling Address
#define LCD_O_SYSCFG            				0x00000054  // LCD System Configuration Register
#define LCD_O_RISSET            				0x00000058  // LCD Interrupt Raw Status and Set Register
#define LCD_O_MISCLR            				0x0000005C  // LCD Interrupt Status and Clear
#define LCD_O_IM                				0x00000060  // LCD Interrupt Mask
#define LCD_O_IENC              				0x00000064  // LCD Interrupt Enable Clear
#define LCD_O_CLKEN             				0x0000006C  // LCD Clock Enable
#define LCD_O_CLKRESET          				0x00000070  // LCD Clock Resets

//*****************************************************************************
// The following are defines for the bit fields in the LCD_O_PID register.
//*****************************************************************************
#define LCD_PID_MAJOR_M         				0x00000700  // Major Release Number
#define LCD_PID_MINOR_M         				0x0000003F  // Minor Release Number

//*****************************************************************************
// The following are defines for the bit fields in the LCD_O_CTL register.
//*****************************************************************************
#define LCD_CTL_CLKDIV_M        				0x0000FF00  // Clock Divisor
#define LCD_CTL_UFLOWRST        				0x00000002  // Underflow Restart
#define LCD_CTL_LCDMODE         				0x00000001  // LCD Mode Select
#define LCD_CTL_CLKDIV_S        				8			// Shift 8 Bits

//*****************************************************************************
// The following are defines for the bit fields in the LCD_O_LIDDCTL register.
//*****************************************************************************
#define LCD_LIDDCTL_DMACS       				0x00000200  // CS0/CS1 Select for LIDD DMA Writes
#define LCD_LIDDCTL_DMAEN       				0x00000100  // LIDD DMA Enable
#define LCD_LIDDCTL_CS1E1       				0x00000080  // Chip Select 1 (CS1)/Enable 1 (E1) Polarity Control
#define LCD_LIDDCTL_CS0E0       				0x00000040  // Chip Select 0 (CS0)/Enable 0 (E0) Polarity Control
#define LCD_LIDDCTL_WRDIRINV    				0x00000020  // Write Strobe (WR) /Direction (DIR) Polarity Control
#define LCD_LIDDCTL_RDEN        				0x00000010  // Read Strobe (RD) /Direct Enable (EN) Polarity Control
#define LCD_LIDDCTL_ALE         				0x00000008  // Address Latch Enable (ALE) Polarity Control
#define LCD_LIDDCTL_MODE_M      				0x00000007  // LIDD Mode Select
#define LCD_LIDDCTL_MODE_SYNCM68                0x00000000  // Synchronous Motorola 6800 Mode
#define LCD_LIDDCTL_MODE_ASYNCM68				0x00000001  // Asynchronous Motorola 6800 Mode
#define LCD_LIDDCTL_MODE_SYNCM80                0x00000002  // Synchronous Intel 8080 mode
#define LCD_LIDDCTL_MODE_ASYNCM80 			    0x00000003  // Asynchronous Intel 8080 mode
#define LCD_LIDDCTL_MODE_ASYNCHIT               0x00000004  // Asynchronous Hitachi mode

//*****************************************************************************
// The following are defines for the bit fields in the LCD_O_LIDDCS0CFG register.
//*****************************************************************************
#define LCD_LIDDCS0CFG_WRSU_M   				0xF8000000  // Write Strobe (WR) Set-Up Cycles
#define LCD_LIDDCS0CFG_WRDUR_M  				0x07E00000  // Write Strobe (WR) Duration Cycles
#define LCD_LIDDCS0CFG_WRHOLD_M 				0x001E0000  // Write Strobe (WR) Hold cycles
#define LCD_LIDDCS0CFG_RDSU_M   				0x0001F000  // Read Strobe (RD) Set-Up cycles
#define LCD_LIDDCS0CFG_RDDUR_M  				0x00000FC0  // Read Strobe (RD) Duration cycles
#define LCD_LIDDCS0CFG_RDHOLD_M 				0x0000003C  // Read Strobe (RD) Hold cycles
#define LCD_LIDDCS0CFG_GAP_M    				0x00000003  // Field value defines the number of LCDMCLK cycles (GAP +1)
                                            				// between the end of one CS0 (LCDAC) device access and the
															// start of another CS0 (LCDAC) device access unless the two
                                            				// accesses are both reads
#define LCD_LIDDCS0CFG_WRSU_S   27
#define LCD_LIDDCS0CFG_WRDUR_S  21
#define LCD_LIDDCS0CFG_WRHOLD_S 17
#define LCD_LIDDCS0CFG_RDSU_S   12
#define LCD_LIDDCS0CFG_RDDUR_S  6
#define LCD_LIDDCS0CFG_RDHOLD_S 2
#define LCD_LIDDCS0CFG_GAP_S    0

//*****************************************************************************
// The following are defines for the bit fields in the LCD_O_LIDDCS0ADDR register.
//*****************************************************************************
#define LCD_LIDDCS0ADDR_CS0ADDR_M               0x0000FFFF  // LCD Address

//*****************************************************************************
// The following are defines for the bit fields in the LCD_O_LIDDCS0DATA register.
//*****************************************************************************
#define LCD_LIDDCS0DATA_CS0DATA_M               0x0000FFFF  // LCD Data Read/Write

//*****************************************************************************
// The following are defines for the bit fields in the LCD_O_LIDDCS1CFG register.
//*****************************************************************************
#define LCD_LIDDCS1CFG_WRSU_M   				0xF8000000  // Write Strobe (WR) Set-Up Cycles
#define LCD_LIDDCS1CFG_WRDUR_M  				0x07E00000  // Write Strobe (WR) Duration Cycles
#define LCD_LIDDCS1CFG_WRHOLD_M 				0x001E0000  // Write Strobe (WR) Hold cycles
#define LCD_LIDDCS1CFG_RDSU_M   				0x0001F000  // Read Strobe (RD) Set-Up cycles
#define LCD_LIDDCS1CFG_RDDUR_M  				0x00000FC0  // Read Strobe (RD) Duration cycles
#define LCD_LIDDCS1CFG_RDHOLD_M 				0x0000003C  // Read Strobe (RD) Hold cycles
#define LCD_LIDDCS1CFG_GAP_M    				0x00000003  // Field value defines the number of LCDMCLK cycles (GAP + 1)
															// between the end of one CS1 (LCDAC) device access and the
															// start of another CS0 (LCDAC) device access unless the two
															// accesses are both reads
#define LCD_LIDDCS1CFG_WRSU_S   27
#define LCD_LIDDCS1CFG_WRDUR_S  21
#define LCD_LIDDCS1CFG_WRHOLD_S 17
#define LCD_LIDDCS1CFG_RDSU_S   12
#define LCD_LIDDCS1CFG_RDDUR_S  6
#define LCD_LIDDCS1CFG_RDHOLD_S 2
#define LCD_LIDDCS1CFG_GAP_S    0

//*****************************************************************************
// The following are defines for the bit fields in the LCD_O_LIDDCS1ADDR register.
//*****************************************************************************
#define LCD_LIDDCS1ADDR_CS1ADDR_M				0x0000FFFF  // LCD Address Bus

//*****************************************************************************
// The following are defines for the bit fields in the LCD_O_LIDDCS1DATA register.
//*****************************************************************************
#define LCD_LIDDCS1DATA_CS0DATA_M				0x0000FFFF  // LCD Data Read/Write Initiation

//*****************************************************************************
// The following are defines for the bit fields in the LCD_O_RASTRCTL register.
//*****************************************************************************
#define LCD_RASTRCTL_TFT24UPCK  				0x04000000  // 24-bit TFT Mode Packing
#define LCD_RASTRCTL_TFT24      				0x02000000  // 24-Bit TFT Mode
#define LCD_RASTRCTL_FRMBUFSZ   				0x01000000  // Frame Buffer Select
#define LCD_RASTRCTL_TFTMAP     				0x00800000  // TFT Mode Alternate Signal Mapping for Palettized Framebuffer
#define LCD_RASTRCTL_NIBMODE    				0x00400000  // Nibble Mode
#define LCD_RASTRCTL_PALMODE_M  				0x00300000  // Pallette Loading Mode
#define LCD_RASTRCTL_PALMODE_PALDAT             0x00000000  // Palette and data loading, reset value
#define LCD_RASTRCTL_PALMODE_PAL				0x00100000  // Palette loading only
#define LCD_RASTRCTL_PALMODE_DAT 				0x00200000  // Data loading only
#define LCD_RASTRCTL_REQDLY_M   				0x000FF000  // Palette Loading Delay
#define LCD_RASTRCTL_MONO8B     				0x00000200  // Mono 8-Bit
#define LCD_RASTRCTL_RDORDER    				0x00000100  // Raster Data Order Select
#define LCD_RASTRCTL_LCDTFT     				0x00000080  // LCD TFT
#define LCD_RASTRCTL_LCDBW      				0x00000002  // LCD Monochrome
#define LCD_RASTRCTL_LCDEN      				0x00000001  // LCD Controller Enable for Raster Operations
#define LCD_RASTRCTL_REQDLY_S   				12

//*****************************************************************************
// The following are defines for the bit fields in the LCD_O_RASTRTIM0 register.
//*****************************************************************************
#define LCD_RASTRTIM0_HBP_M     				0xFF000000  // Horizontal Back Porch Lowbits
#define LCD_RASTRTIM0_HFP_M     				0x00FF0000  // Horizontal Front Porch Lowbits
#define LCD_RASTRTIM0_HSW_M     				0x0000FC00  // Horizontal Sync Pulse Width Lowbits
#define LCD_RASTRTIM0_PPL_M     				0x000003F0  // Pixels-per-line LSB[9:4]
#define LCD_RASTRTIM0_MSBPPL    				0x00000008  // Pixels-per-line MSB[10]
#define LCD_RASTRTIM0_HBP_S     				24
#define LCD_RASTRTIM0_HFP_S     				16
#define LCD_RASTRTIM0_HSW_S     				10
#define LCD_RASTRTIM0_PPL_S     				4
#define LCD_RASTRTIM0_MSBPPL_S  				3

//*****************************************************************************
// The following are defines for the bit fields in the LCD_O_RASTRTIM1 register.
//*****************************************************************************
#define LCD_RASTRTIM1_VBP_M     				0xFF000000  // Vertical Back Porch
#define LCD_RASTRTIM1_VFP_M     				0x00FF0000  // Vertical Front Porch
#define LCD_RASTRTIM1_VSW_M     				0x0000FC00  // Vertical Sync Width Pulse
#define LCD_RASTRTIM1_LPP_M     				0x000003FF  // Lines Per Panel
#define LCD_RASTRTIM1_VBP_S     				24
#define LCD_RASTRTIM1_VFP_S     				16
#define LCD_RASTRTIM1_VSW_S     				10
#define LCD_RASTRTIM1_LPP_S     				0

//*****************************************************************************
// The following are defines for the bit fields in the LCD_O_RASTRTIM2 register.
//*****************************************************************************
#define LCD_RASTRTIM2_HSW_M     				0x78000000  // Bits 9:6 of the horizontal sync width field
#define LCD_RASTRTIM2_MSBLPP    				0x04000000  // MSB of Lines Per Panel
#define LCD_RASTRTIM2_PXLCLKCTL 				0x02000000  // Hsync/Vsync Pixel Clock Control On/Off
#define LCD_RASTRTIM2_PSYNCRF   				0x01000000  // Program HSYNC/VSYNC Rise or Fall
#define LCD_RASTRTIM2_INVOE     				0x00800000  // Invert Output Enable
#define LCD_RASTRTIM2_INVPXLCLK 				0x00400000  // Invert Pixel Clock
#define LCD_RASTRTIM2_IHS       				0x00200000  // Invert Hysync
#define LCD_RASTRTIM2_IVS       				0x00100000  // Invert Vsync
#define LCD_RASTRTIM2_ACBI_M    				0x000F0000  // AC Bias Pins Transitions per Interrupt
#define LCD_RASTRTIM2_ACBF_M    				0x0000FF00  // AC Bias Pin Frequency
#define LCD_RASTRTIM2_MSBHBP_M  				0x00000030  // Bits 9:8 of the horizontal back porch field
#define LCD_RASTRTIM2_MSBHFP_M  				0x00000003  // Bits 9:8 of the horizontal front porch field
#define LCD_RASTRTIM2_HSW_S     				27
#define LCD_RASTRTIM2_MSBLPP_S  				26
#define LCD_RASTRTIM2_ACBI_S    				16
#define LCD_RASTRTIM2_ACBF_S    				8
#define LCD_RASTRTIM2_MSBHBP_S  				4
#define LCD_RASTRTIM2_MSBHFP_S  				0

//*****************************************************************************
// The following are defines for the bit fields in the LCD_O_RASTRSUBP1 register.
//*****************************************************************************
#define LCD_RASTRSUBP1_SPEN     				0x80000000  // Sub Panel Enable
#define LCD_RASTRSUBP1_HOLS     				0x20000000  // High or Low Signal
#define LCD_RASTRSUBP1_LPPT_M   				0x03FF0000  // Line Per Panel Threshold
#define LCD_RASTRSUBP1_DPDLSB_M 				0x0000FFFF  // Default Pixel Data LSB[15:0]
#define LCD_RASTRSUBP1_LPPT_S   				16
#define LCD_RASTRSUBP1_DPDLSB_S 				0

//*****************************************************************************
// The following are defines for the bit fields in the LCD_O_RASTRSUBP2 register.
//*****************************************************************************
#define LCD_RASTRSUBP2_LPPTMSB  				0x00000100  // Lines Per Panel Threshold Bit 10
#define LCD_RASTRSUBP2_DPDMSB_M 				0x000000FF  // Default Pixel Data MSB [23:16]

//*****************************************************************************
// The following are defines for the bit fields in the LCD_O_DMACTL register.
//*****************************************************************************
#define LCD_DMACTL_FIFORDY_M    				0x00000700  // DMA FIFO threshold
#define LCD_DMACTL_FIFORDY_8    				0x00000000  // 8 words
#define LCD_DMACTL_FIFORDY_16  	 				0x00000100  // 16 words
#define LCD_DMACTL_FIFORDY_32   				0x00000200  // 32 words
#define LCD_DMACTL_FIFORDY_64   				0x00000300  // 64 words
#define LCD_DMACTL_FIFORDY_128  				0x00000400  // 128 words
#define LCD_DMACTL_FIFORDY_256  				0x00000500  // 256 words
#define LCD_DMACTL_FIFORDY_512  				0x00000600  // 512 words
#define LCD_DMACTL_BURSTSZ_M    				0x00000070  // Burst Size setting for DMA transfers (all DMA transfers are 32 bits wide):
#define LCD_DMACTL_BURSTSZ_4    				0x00000020  // burst size of 4
#define LCD_DMACTL_BURSTSZ_8    				0x00000030  // burst size of 8
#define LCD_DMACTL_BURSTSZ_16   				0x00000040  // burst size of 16
#define LCD_DMACTL_BYTESWAP     				0x00000008  // This bit controls the bytelane ordering of the data on the output of the DMA module
#define LCD_DMACTL_BIGDEND      				0x00000002  // Big Endian Enable
#define LCD_DMACTL_FMODE        				0x00000001  // Frame Mode

//*****************************************************************************
// The following are defines for the bit fields in the LCD_O_DMABAFB0 register.
//*****************************************************************************
#define LCD_DMABAFB0_FB0BA_M    				0xFFFFFFFC  // Frame Buffer 0 Base Address

//*****************************************************************************
// The following are defines for the bit fields in the LCD_O_DMACAFB0 register.
//*****************************************************************************
#define LCD_DMACAFB0_FB0CA_M    				0xFFFFFFFC  // Frame Buffer 0 Ceiling Address

//*****************************************************************************
// The following are defines for the bit fields in the LCD_O_DMABAFB1 register.
//*****************************************************************************
#define LCD_DMABAFB1_FB1BA_M    				0xFFFFFFFC  // Frame Buffer 1 Base Address pointer

//*****************************************************************************
// The following are defines for the bit fields in the LCD_O_DMACAFB1 register.
//*****************************************************************************
#define LCD_DMACAFB1_FB1CA_M    				0xFFFFFFFC  // Frame Buffer 1 Ceiling Address pointer

//*****************************************************************************
// The following are defines for the bit fields in the LCD_O_SYSCFG register.
//*****************************************************************************
#define LCD_SYSCFG_STDBY_M      				0x00000030  // Standby Mode
#define LCD_SYSCFG_STDBY_FORCE  				0x00000000  // Force-standby mode:
#define LCD_SYSCFG_STDBY_NONE   				0x00000010  // No-standby mode:
#define LCD_SYSCFG_STDBY_SMART  				0x00000020  // Smart-standby mode:
#define LCD_SYSCFG_IDLEMODE_M   				0x0000000C  // Idle Mode
#define LCD_SYSCFG_IDLEMODE_FORCE 				0x00000000  // Force-idle mode:
#define LCD_SYSCFG_IDLEMODE_NONE 				0x00000004  // No-idle mode:
#define LCD_SYSCFG_IDLEMODE_SMART				0x00000008  // Smart-idle mode:

//*****************************************************************************
// The following are defines for the bit fields in the LCD_O_RISSET register.
//*****************************************************************************
#define LCD_RISSET_EOF1         				0x00000200  // DMA End-of-Frame 1 Raw Interrupt Status and Set
#define LCD_RISSET_EOF0         				0x00000100  // DMA End-of-Frame 0 Raw Interrupt Status and Set
#define LCD_RISSET_PALLOAD      				0x00000040  // DMA Palette Loaded Raw Interrupt Status and Set
#define LCD_RISSET_FIFOU        				0x00000020  // DMA FIFO Underflow Raw Interrupt Status and Set
#define LCD_RISSET_ACBS         				0x00000008  // AC Bias Count Raw Interrupt Status and Set
#define LCD_RISSET_SYNCS        				0x00000004  // Frame Synchronization Lost Raw Interrupt Status and Set
#define LCD_RISSET_RRASTRDONE   				0x00000002  // Raster Mode Frame Done interrupt
#define LCD_RISSET_DONE         				0x00000001  // Raster or LIDD Frame Done (shared, depends on whetherRaster or LIDD mode enabled) RawInterrupt Status and Set

//*****************************************************************************
// The following are defines for the bit fields in the LCD_O_MISCLR register.
//*****************************************************************************
#define LCD_MISCLR_EOF1         				0x00000200  // DMA End-of-Frame 1 Enabled Interrupt and Clear
#define LCD_MISCLR_EOF0        	 				0x00000100  // DMA End-of-Frame 0 Raw Interrupt and Clear
#define LCD_MISCLR_PALLOAD      				0x00000040  // DMA Palette Loaded Enabled Interrupt and Clear
#define LCD_MISCLR_FIFOU        				0x00000020  // DMA FIFO Underflow Enabled Interrupt and Clear
#define LCD_MISCLR_ACBS        					0x00000008  // AC Bias Count Enabled Interrupt and Clear
#define LCD_MISCLR_SYNCS        				0x00000004  // Frame Synchronization Lost Enabled Interrupt and Clear
#define LCD_MISCLR_RRASTRDONE   				0x00000002  // Raster Mode Frame Done interrupt
#define LCD_MISCLR_DONE         				0x00000001  // Raster or LIDD Frame Done (shared, depends on whether Raster or LIDD mode enabled) Enabled Interrupt and Clear

//*****************************************************************************
// The following are defines for the bit fields in the LCD_O_IM register.
//*****************************************************************************
#define LCD_IM_EOF1             				0x00000200  // DMA End-of-Frame 1 Interrupt Enable Set
#define LCD_IM_EOF0             				0x00000100  // DMA End-of-Frame 0 Interrupt Enable Set
#define LCD_IM_PALLOAD          				0x00000040  // DMA Palette Loaded Interrupt Enable Set
#define LCD_IM_FIFOU            				0x00000020  // DMA FIFO Underflow Interrupt Enable Set
#define LCD_IM_ACBS             				0x00000008  // AC Bias Count Interrupt Enable Set
#define LCD_IM_SYNCS            				0x00000004  // Frame Synchronization Lost Interrupt Enable Set
#define LCD_IM_RRASTRDONE       				0x00000002  // Raster Mode Frame Done Interrupt Enable Set
#define LCD_IM_DONE             				0x00000001  // Raster or LIDD Frame Done (shared, depends on whether Raster or LIDD mode enabled) Interrupt Enable Set

//*****************************************************************************
// The following are defines for the bit fields in the LCD_O_IENC register.
//*****************************************************************************
#define LCD_IENC_EOF1           				0x00000200  // DMA End-of-Frame 1 Interrupt Enable Clear
#define LCD_IENC_EOF0           				0x00000100  // DMA End-of-Frame 0 Interrupt Enable Clear
#define LCD_IENC_PALLOAD        				0x00000040  // DMA Palette Loaded Interrupt Enable Clear
#define LCD_IENC_FIFOU          				0x00000020  // DMA FIFO Underflow Interrupt Enable Clear
#define LCD_IENC_ACBS           				0x00000008  // AC Bias Count Interrupt Enable Clear
#define LCD_IENC_SYNCS         				    0x00000004  // Frame Synchronization Lost Interrupt Enable Clear
#define LCD_IENC_RRASTRDONE     				0x00000002  // Raster Mode Frame Done Interrupt Enable Clear
#define LCD_IENC_DONE           				0x00000001  // Raster or LIDD Frame Done (shared, depends on whether Raster or LIDD mode enabled) Interrupt Enable Clear

//*****************************************************************************
// The following are defines for the bit fields in the LCD_O_CLKEN register.
//*****************************************************************************
#define LCD_CLKEN_DMA           				0x00000004  // DMA Clock Enable
#define LCD_CLKEN_LIDD          				0x00000002  // LIDD Submodule Clock Enable
#define LCD_CLKEN_CORE          				0x00000001  // LCD Core Clock Enable

//*****************************************************************************
// The following are defines for the bit fields in the LCD_O_CLKRESET register.
//*****************************************************************************
#define LCD_CLKRESET_MAIN      					0x00000008  // Software Reset for the entire LCD module
#define LCD_CLKRESET_DMA        				0x00000004  // Software Reset for the DMA submodule
#define LCD_CLKRESET_LIDD       				0x00000002  // Software Reset for the LIDD submodule (character displays)
#define LCD_CLKRESET_CORE       				0x00000001  // Software Reset for the Core, which encompasses the Raster Active Matrix and Passive Matrix logic





//*****************************************************************************
// Flags used in the ui32Clocks parameter to LCDClockReset().
//*****************************************************************************
#define LCD_CLOCK_MAIN          				0x00000008
#define LCD_CLOCK_DMA          				    0x00000004
#define LCD_CLOCK_LIDD          				0x00000002
#define LCD_CLOCK_CORE          				0x00000001

//*****************************************************************************
// Configuration values used with LCDDMAConfigSet().
//*****************************************************************************
#define LCD_DMA_FIFORDY_8_WORDS 				0x00000000
#define LCD_DMA_FIFORDY_16_WORDS  				0x00000100
#define LCD_DMA_FIFORDY_32_WORDS				0x00000200
#define LCD_DMA_FIFORDY_64_WORDS				0x00000300
#define LCD_DMA_FIFORDY_128_WORDS				0x00000400
#define LCD_DMA_FIFORDY_256_WORDS				0x00000500
#define LCD_DMA_FIFORDY_512_WORDS				0x00000600
#define LCD_DMA_BURST_4         				0x00000020
#define LCD_DMA_BURST_8         				0x00000030
#define LCD_DMA_BURST_16        				0x00000040
#define LCD_DMA_BYTE_ORDER_0123 				0x00000000
#define LCD_DMA_BYTE_ORDER_1023 				0x00000008
#define LCD_DMA_BYTE_ORDER_3210 				0x00000002
#define LCD_DMA_BYTE_ORDER_2301 				0x0000000A
#define LCD_DMA_FMODE       					0x00000001

//*****************************************************************************
// Possible values for the ui8Mode parameter to LCDModeSet().  The label
// LCD_MODE_AUTO_UFLOW_RESTART may be ORed with either of the other two.
//*****************************************************************************
#define LCD_MODE_LIDD           				((uint8_t)0x00)
#define LCD_MODE_RASTER         				((uint8_t)0x01)
#define LCD_MODE_AUTO_UFLOW_RESTART				((uint8_t)0x02)

//*****************************************************************************
// Values used to construct the ui32Config parameter to LCDIDDConfigSet().
//*****************************************************************************
#define LIDD_CONFIG_SYNC_MPU68  				0x00000000
#define LIDD_CONFIG_ASYNC_MPU68 				0x00000001
#define LIDD_CONFIG_SYNC_MPU80  				0x00000002
#define LIDD_CONFIG_ASYNC_MPU80 				0x00000003
#define LIDD_CONFIG_ASYNC_HITACHI              	0x00000004
#define LIDD_CONFIG_INVERT_ALE  				0x00000008
#define LIDD_CONFIG_INVERT_RS_EN                0x00000010
#define LIDD_CONFIG_INVERT_WS_DIR               0x00000020
#define LIDD_CONFIG_INVERT_CS0  				0x00000040
#define LIDD_CONFIG_INVERT_CS1  				0x00000080
#define LIDD_CONFIG_DMAEN  						0x00000100
#define LIDD_CONFIG_DMACS		  				0x00000200

//*****************************************************************************
// Interrupt sources for the LCD controller.  These may be ORed together and
// passed to LCDIntEnable(), LCDIntDisable() and LCDIntClear().  They are also
// returned by LCDIntStatus().
//*****************************************************************************
#define LCD_INT_DMA_DONE        				0x00000001
#define LCD_INT_RASTER_FRAME_DONE				0x00000002
#define LCD_INT_SYNC_LOST       				0x00000004
#define LCD_INT_AC_BIAS_CNT     				0x00000008
#define LCD_INT_UNDERFLOW       				0x00000020
#define LCD_INT_PAL_LOAD        				0x00000040
#define LCD_INT_EOF0            				0x00000100
#define LCD_INT_EOF1           					0x00000200





//*****************************************************************************
// Values used to construct the ui32Config parameter to
// LCDRasterConfigSet().  Valid parameters contain one of the RASTER_FMT_xxx
// labels optionally ORed with the other flags.  Only one of
// RASTER_LOAD_DATA_ONLY and RASTER_LOAD_PALETTE_ONLY may be specified (if
// neither is specified, the controller will load both palette and data when
// scanning out the frame buffer).
//*****************************************************************************
#define RASTER_FMT_ACTIVE_24BPP_PACKED			0x02000080
#define RASTER_FMT_ACTIVE_24BPP_UNPACKED 		0x06000080
#define RASTER_FMT_ACTIVE_PALETTIZED_12BIT		0x00000080
#define RASTER_FMT_ACTIVE_PALETTIZED_16BIT     	0x00800080
#define RASTER_FMT_PASSIVE_MONO_4PIX   			0x00000002
#define RASTER_FMT_PASSIVE_MONO_8PIX   			0x00000202
#define RASTER_FMT_PASSIVE_PALETTIZED    		0x00000000
#define RASTER_FMT_PASSIVE_COLOR_12BIT   	 	0x00000000
#define RASTER_FMT_PASSIVE_COLOR_16BIT    	 	0x01000000
#define RASTER_NIBBLE_MODE_ENABLED     			0x00400000
#define RASTER_LOAD_DATA_ONLY   				0x00200000
#define RASTER_LOAD_PALETTE_ONLY 				0x00100000
#define RASTER_READ_ORDER_REVERSED  			0x00000100

//*****************************************************************************
// Type values used with LCDRasterPaletteSet().
//*****************************************************************************
#define LCD_PALETTE_TYPE_1BPP   				0x00000000
#define LCD_PALETTE_TYPE_2BPP   				0x00001000
#define LCD_PALETTE_TYPE_4BPP  					0x00002000
#define LCD_PALETTE_TYPE_8BPP   				0x00003000
#define LCD_PALETTE_TYPE_DIRECT 				0x00004000
#define LCD_PALETTE_SRC_24BIT   				0x80000000

//*****************************************************************************
// Flags used in with LCDSubPanelConfigSet().
//*****************************************************************************
#define LCD_SUBPANEL_AT_TOP     				0x20000000
#define LCD_SUBPANEL_AT_BOTTOM  				0x00000000

// Values which can be ORed together within the ui32Flags field of the
// tLCDRasterTiming structure.
//
#define RASTER_TIMING_SYNCS_OPPOSITE_PIXCLK     0x00000000
#define RASTER_TIMING_SYNCS_ON_RISING_PIXCLK    0x02000000
#define RASTER_TIMING_SYNCS_ON_FALLING_PIXCLK   0x03000000
#define RASTER_TIMING_ACTIVE_HIGH_OE            0x00000000
#define RASTER_TIMING_ACTIVE_LOW_OE             0x00800000
#define RASTER_TIMING_ACTIVE_HIGH_PIXCLK        0x00000000
#define RASTER_TIMING_ACTIVE_LOW_PIXCLK         0x00400000
#define RASTER_TIMING_ACTIVE_HIGH_HSYNC         0x00000000
#define RASTER_TIMING_ACTIVE_LOW_HSYNC          0x00200000
#define RASTER_TIMING_ACTIVE_HIGH_VSYNC         0x00000000
#define RASTER_TIMING_ACTIVE_LOW_VSYNC          0x00100000





//*****************************************************************************
//! A structure containing timing parameters for the LIDD (LCD Interface
//! Display Driver) interface.  This is used with the LCDIDDTimingSet function.
//*****************************************************************************
typedef struct
{
    //! Write Strobe Set-Up cycles.  When performing a write access, this
    //! field defines the number of MCLK cycles that Data Bus/Pad Output
    //! Enable, ALE, the Direction bit, and Chip Select have to be ready before
    //! the Write Strobe is asserted.  Valid values are from 0 to 31.
    //
    uint8_t ui8WSSetup;

    //! Write Strobe Duration cycles.  Field value defines the number of MCLK
    //! cycles for which the Write Strobe is held active when performing a
    //! write access.  Valid values are from 1 to 63.
    //
    uint8_t ui8WSDuration;

    //! Write Strobe Hold cycles.  Field value defines the number of MCLK
    //! cycles for which Data Bus/Pad Output Enable, ALE, the Direction bit,
    //! and Chip Select are held after the Write Strobe is deasserted when
    //! performing a write access.  Valid values are from 1 to 15.
    //
    uint8_t ui8WSHold;

    //! Read Strobe Set-Up cycles.  When performing a read access, this field
    //! defines the number of MCLK cycles that Data Bus/Pad Output Enable, ALE,
    //! the Direction bit, and Chip Select have to be ready before the Read
    //! Strobe is asserted.  Valid values are from 0 to 31.
    //
    uint8_t ui8RSSetup;

    //! Read Strobe Duration cycles.  Field value defines the number of MCLK
    //! cycles for which the Read Strobe is held active when performing a read
    //! access.  Valid values are from 1 to 63.
    //
    uint8_t ui8RSDuration;

    //! Read Strobe Hold cycles.  Field value defines the number of MCLK cycles
    //! for which Data Bus/Pad Output Enable, ALE, the Direction bit, and Chip
    //! Select are held after the Read Strobe is deasserted when performing a
    //! read access.  Valid values are from 1 to 15.
    //
    uint8_t ui8RSHold;

    //! Field value defines the number of MCLK cycles between the end of one
    //! device access and the start of another device access using the same
    //! Chip Select unless the two accesses are both Reads.  In this case,
    //! this delay is not incurred.  Valid vales are from 1 to 4.
    //
    uint8_t ui8DelayCycles;
}
tLCDIDDTiming;

//! A structure containing timing parameters for the raster interface.  This is
//! used with the LCDRasterTimingSet function.
//
typedef struct
{
    //! Flags configuring the polarity and active edges of the various signals
    //! in the raster interface.  This field is comprised of a logical OR of
    //! the labels with prefix  ``RASTER_TIMING_''.
    //
    uint32_t ui32Flags;

    //! The number of pixels contained within each line on the LCD display.
    //! Valid values are multiple of 16 less than or equal to 2048.
    //
    uint16_t ui16PanelWidth;

    //! The number of lines on the LCD display.  Valid values are from 1 to
    //! 2048.
    //
    uint16_t ui16PanelHeight;

    //! A value from 1 to 1024 that specifies the number of pixel clock periods
    //! to add to the end of each line after active video has ended.
    //
    uint16_t ui16HFrontPorch;

    //! A value from 1 to 1024 that specifies the number of pixel clock periods
    //! to add to the beginning of a line before active video is asserted.
    //
    uint16_t ui16HBackPorch;

    //! A value from 1 to 1024 that specifies the number of pixel clock periods
    //! to pulse the line clock at the end of each line.
    //
    uint16_t ui16HSyncWidth;

    //! A value from 0 to 255 that specifies the number of line clock periods
    //! to add to the end of each frame after the last active line.
    //
    uint8_t ui8VFrontPorch;

    //! A value from 0 to 255 that specifies the number of line clock periods
    //! to add to the beginning of a frame before the first active line is
    //! output to the display.
    //
    uint8_t ui8VBackPorch;

    //! In active mode, a value from 1 to 64 that specifies the number of
    //! line clock periods to set the lcd_fp pin active at the end of each
    //! frame after the vertical front porch period elapses.  The number of
    //! The frame clock is used as the VSYNC signal in active mode.
    //!
    //! In passive mode, a value from 1 to 64 that specifies the number of
    //! extra line clock periods to insert after the vertical front porch
    //! period has elapsed.  Note that the width of lcd_fp is not affected by
    //! this value in passive mode.
    //
    uint8_t ui8VSyncWidth;

    //! A value from 0 to 255 that specifies the number of line clocks to
    //! count before transitioning the AC Bias pin.  This pin is used to
    //! periodically invert the polarity of the power supply to prevent DC
    //! charge build-up within the display.
    //
    uint8_t ui8ACBiasLineCount;
}
tLCDRasterTiming;





//*****************************************************************************
// Function Prototypes.
//*****************************************************************************
extern void LCDClockReset(uint32_t ui32Base, uint32_t ui32Clocks);																										// Tested
extern void LCDDMAConfigSet(uint32_t ui32Base, uint32_t ui32Config);																									// Tested
extern void LCDIDDCommandWrite(uint32_t ui32Base, uint32_t ui32CS, uint16_t ui16Cmd);
extern void LCDIDDConfigSet(uint32_t ui32Base, uint32_t ui32Config);
extern uint16_t LCDIDDDataRead(uint32_t ui32Base, uint32_t ui32CS);
extern void LCDIDDDataWrite(uint32_t ui32Base, uint32_t ui32CS, uint16_t ui16Data);
extern void LCDIDDDMADisable(uint32_t ui32Base);
extern void LCDIDDDMAWrite(uint32_t ui32Base, uint32_t ui32CS, const uint32_t *pui32Data, uint32_t ui32Count);
extern uint16_t LCDIDDIndexedRead(uint32_t ui32Base, uint32_t ui32CS, uint16_t ui16Addr);
extern void LCDIDDIndexedWrite(uint32_t ui32Base, uint32_t ui32CS, uint16_t ui16Addr, uint16_t ui16Data);
extern uint16_t LCDIDDStatusRead(uint32_t ui32Base, uint32_t ui32CS);
extern void LCDIDDTimingSet(uint32_t ui32Base, uint32_t ui32CS, const tLCDIDDTiming *pTiming);
extern void LCDIntClear(uint32_t ui32Base, uint32_t ui32IntFlags);																										// Tested
extern void LCDIntDisable(uint32_t ui32Base, uint32_t ui32IntFlags);																									// Tested
extern void LCDIntEnable(uint32_t ui32Base, uint32_t ui32IntFlags);																										// Tested
extern void LCDIntRegister(uint32_t ui32Base, void (*pfnHandler)(void));																								// Tested
extern uint32_t LCDIntStatus(uint32_t ui32Base, bool bMasked);																											// Tested
extern void LCDIntUnregister(uint32_t ui32Base);																														// Tested
extern uint32_t LCDModeSet(uint32_t ui32Base, uint8_t ui8Mode, uint32_t ui32PixClk, uint32_t ui32SysClk);																// Tested
extern void LCDRasterACBiasIntCountSet(uint32_t ui32Base, uint8_t ui8Count);																							// Tested
extern void LCDRasterConfigSet(uint32_t ui32Base, uint32_t ui32Config, uint8_t ui8PalLoadDelay);																		// Tested
extern void LCDRasterDisable(uint32_t ui32Base);																														// Tested
extern void LCDRasterEnable(uint32_t ui32Base);																															// Tested
extern bool LCDRasterEnabled(uint32_t ui32Base);																														// Tested
extern void LCDRasterFrameBufferSet(uint32_t ui32Base, uint8_t ui8Buffer, uint32_t *pui32Addr, uint32_t ui32NumBytes);													// Tested
extern void LCDRasterPaletteSet(uint32_t ui32Base, uint32_t ui32Type, uint32_t *pui32PalAddr, const uint32_t *pui32SrcColors, uint32_t ui32Start, uint32_t ui32Count);
extern void LCDRasterSubPanelConfigSet(uint32_t ui32Base, uint32_t ui32Flags, uint32_t ui32BottomLines, uint32_t ui32DefaultPixel);
extern void LCDRasterSubPanelDisable(uint32_t ui32Base);																												// Tested
extern void LCDRasterSubPanelEnable(uint32_t ui32Base);																													// Tested
extern void LCDRasterTimingSet(uint32_t ui32Base, const tLCDRasterTiming *pTiming);

#endif // _LCD_H_
