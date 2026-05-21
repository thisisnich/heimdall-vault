#include <stdbool.h>
#include <stdint.h>
#include "sysctl.h"
#include "gpio.h"
#include "ssi.h"
#include "grlib/grlib.h"
#include "st7789_spi.h"

//*****************************************************************************
// The following are declarations for global variable
//*****************************************************************************



//*****************************************************************************
//! The display structure that describes the driver for the 1.2inch Round
//! TFT Display with an ST7789 controller.
//*****************************************************************************
const tDisplay g_sST7789 =
{
    sizeof(tDisplay),
    0,
    240,
	240,
	ST7789PixelDraw,
	ST7789PixelDrawMultiple,
	ST7789LineDrawH,
	ST7789LineDrawV,
	ST7789RectFill,
	ST7789ColorTranslate,
	ST7789Flush
};


//******************************************************************************
// Prototypes definitions for the APIs.
//*****************************************************************************
void _ST7789GPIODataPut(uint8_t commandData)
{
	SSIDataPut(SSI3_BASE, commandData);
	while(SSIBusy(SSI3_BASE));
}

void _ST7789WriteCommand(uint8_t command)
{
	GPIOPinWrite(GPIO_PORTQ_AHB_BASE, GPIO_PIN_3, 0);
    _ST7789GPIODataPut(command);				    // Send command bytes to the display
}

void _ST7789WriteData(uint8_t data)
{
	GPIOPinWrite(GPIO_PORTQ_AHB_BASE, GPIO_PIN_3, GPIO_PIN_3);
	_ST7789GPIODataPut(data);						// Send data bytes to the display
}

void ST7789PinInitSPITest(int32_t ui32SysClock)
{
	SysCtlPeripheralEnable(SYSCTL_PERIPH_SSI3);
	SysCtlPeripheralEnable(ST7789_SPI_PERIPH);
	SysCtlPeripheralEnable(ST7789_RESET_PERIPH);
	SysCtlPeripheralEnable(ST7789_BACKLIGHT_PERIPH);

	while(!SysCtlPeripheralReady(SYSCTL_PERIPH_SSI3));
	while(!SysCtlPeripheralReady(ST7789_SPI_PERIPH));
	while(!SysCtlPeripheralReady(ST7789_RESET_PERIPH));
	while(!SysCtlPeripheralReady(ST7789_BACKLIGHT_PERIPH));

	GPIOPinTypeGPIOOutput(ST7789_BACKLIGHT_PORT, ST7789_BACKLIGHT_PIN);
	GPIOPinTypeGPIOOutput(ST7789_RESET_PORT, ST7789_RESET_PIN);

	GPIOPinWrite(ST7789_SPI_PORT, ST7789_SPI_RS_PIN, ST7789_SPI_RS_PIN);
	GPIOPinWrite(ST7789_BACKLIGHT_PORT, ST7789_BACKLIGHT_PIN, ST7789_BACKLIGHT_PIN);
	GPIOPinWrite(ST7789_RESET_PORT, ST7789_RESET_PIN, ST7789_RESET_PIN);

	GPIOPinConfigure(GPIO_PQ0_SSI3CLK);
	GPIOPinConfigure(GPIO_PQ1_SSI3FSS);
	GPIOPinConfigure(GPIO_PQ2_SSI3XDAT0);
	GPIOPinTypeGPIOOutput(ST7789_SPI_PORT, ST7789_SPI_RS_PIN);
	GPIOPinTypeSSI(ST7789_SPI_PORT, ST7789_SPI_SCLK_PIN | ST7789_SPI_CS_PIN | ST7789_SPI_SDI_PIN);

	SSIConfigSetExpClk(SSI3_BASE, ui32SysClock, SSI_FRF_MOTO_MODE_0, SSI_MODE_MASTER, 6000000, 8);
	SSIEnable(SSI3_BASE);

	SSIDataPut(SSI3_BASE, 0x55);
	while(SSIBusy(SSI3_BASE));
}

void ST7789PinInit(int32_t ui32SysClock)
{
	tRectangle sRectangle;

	SysCtlPeripheralEnable(SYSCTL_PERIPH_SSI3);
	SysCtlPeripheralEnable(ST7789_SPI_PERIPH);
	SysCtlPeripheralEnable(ST7789_RESET_PERIPH);
	SysCtlPeripheralEnable(ST7789_BACKLIGHT_PERIPH);

	while(!SysCtlPeripheralReady(SYSCTL_PERIPH_SSI3));
	while(!SysCtlPeripheralReady(ST7789_SPI_PERIPH));
	while(!SysCtlPeripheralReady(ST7789_RESET_PERIPH));
	while(!SysCtlPeripheralReady(ST7789_BACKLIGHT_PERIPH));

	GPIOPinTypeGPIOOutput(ST7789_BACKLIGHT_PORT, ST7789_BACKLIGHT_PIN);
	GPIOPinTypeGPIOOutput(ST7789_RESET_PORT, ST7789_RESET_PIN);

	GPIOPinWrite(ST7789_SPI_PORT, ST7789_SPI_RS_PIN, ST7789_SPI_RS_PIN);
	GPIOPinWrite(ST7789_BACKLIGHT_PORT, ST7789_BACKLIGHT_PIN, ST7789_BACKLIGHT_PIN);
	GPIOPinWrite(ST7789_RESET_PORT, ST7789_RESET_PIN, ST7789_RESET_PIN);

	GPIOPinConfigure(GPIO_PQ0_SSI3CLK);
	GPIOPinConfigure(GPIO_PQ1_SSI3FSS);
	GPIOPinConfigure(GPIO_PQ2_SSI3XDAT0);
	GPIOPinTypeGPIOOutput(ST7789_SPI_PORT, ST7789_SPI_RS_PIN);
	GPIOPinTypeSSI(ST7789_SPI_PORT, ST7789_SPI_SCLK_PIN | ST7789_SPI_CS_PIN | ST7789_SPI_SDI_PIN);

	SSIConfigSetExpClk(SSI3_BASE, ui32SysClock, SSI_FRF_MOTO_MODE_0, SSI_MODE_MASTER, 6000000, 8);
	SSIEnable(SSI3_BASE);

	_ST7789WriteCommand(0x11);						    // Sleep Out

	_ST7789WriteCommand(0x36);
	_ST7789WriteData(0x00);

	_ST7789WriteCommand(0x3A);
	_ST7789WriteData(0x05);

	_ST7789WriteCommand(0xB2);
	_ST7789WriteData(0x0C);
	_ST7789WriteData(0x0C);
	_ST7789WriteData(0x00);
	_ST7789WriteData(0x33);
	_ST7789WriteData(0x33);

    _ST7789WriteCommand(0xB7);
    _ST7789WriteData(0x35);

	_ST7789WriteCommand(0xBB);
	_ST7789WriteData(0x1A);

    _ST7789WriteCommand(0xC0);
    _ST7789WriteData(0x2C);

	_ST7789WriteCommand(0xC2);
	_ST7789WriteData(0x01);

	_ST7789WriteCommand(0xC3);
	_ST7789WriteData(0x0B);

	_ST7789WriteCommand(0xC4);
	_ST7789WriteData(0x20);

	_ST7789WriteCommand(0xC6);
	_ST7789WriteData(0x0F);

	_ST7789WriteCommand(0xD0);
	_ST7789WriteData(0xA4);
	_ST7789WriteData(0xA1);

	_ST7789WriteCommand(0x21);						// Inv On

    _ST7789WriteCommand(0xE0);
    _ST7789WriteData(0x00);
    _ST7789WriteData(0x19);
    _ST7789WriteData(0x1E);
    _ST7789WriteData(0x0A);
    _ST7789WriteData(0x09);
    _ST7789WriteData(0x15);
    _ST7789WriteData(0x3D);
    _ST7789WriteData(0x44);
    _ST7789WriteData(0x51);
    _ST7789WriteData(0x12);
    _ST7789WriteData(0x03);
    _ST7789WriteData(0x00);
    _ST7789WriteData(0x3F);
    _ST7789WriteData(0x3F);

	_ST7789WriteCommand(0xE1);
	_ST7789WriteData(0x00);
	_ST7789WriteData(0x18);
	_ST7789WriteData(0x1E);
	_ST7789WriteData(0x0A);
	_ST7789WriteData(0x09);
	_ST7789WriteData(0x25);
	_ST7789WriteData(0x3F);
	_ST7789WriteData(0x43);
	_ST7789WriteData(0x52);
	_ST7789WriteData(0x33);
	_ST7789WriteData(0x03);
	_ST7789WriteData(0x00);
	_ST7789WriteData(0x3F);
	_ST7789WriteData(0x3F);

	sRectangle.i16XMin = 0;
    sRectangle.i16YMin = 0;
    sRectangle.i16XMax = 240;
    sRectangle.i16YMax = 240;
    ST7789RectFill(0, &sRectangle, 0xFFFF);

    _ST7789WriteCommand(0x29);
}

void ST7789PixelDraw(void *pvDisplayData, int32_t i32X, int32_t i32Y, uint32_t ui32Value)
{
	_ST7789WriteCommand(0x2A);						// Load column command, start and end column
	_ST7789WriteData((uint8_t)(i32X >> 8));
	_ST7789WriteData((uint8_t)(i32X & 0xFF));
	_ST7789WriteData((uint8_t)(i32X >> 8));
	_ST7789WriteData((uint8_t)(i32X & 0xFF));

	_ST7789WriteCommand(0x2B);						// Load row command, start and end row
	_ST7789WriteData((uint8_t)(i32Y >> 8));
	_ST7789WriteData((uint8_t)(i32Y & 0xFF));
	_ST7789WriteData((uint8_t)(i32Y >> 8));
	_ST7789WriteData((uint8_t)(i32Y & 0xFF));

    _ST7789WriteCommand(0x2C);						// Send the data value representing the pixel to the display
    _ST7789WriteData((uint8_t)(ui32Value >> 8));
    _ST7789WriteData((uint8_t)(ui32Value & 0xFF));
}

void ST7789PixelDrawMultiple(void *pvDisplayData, int32_t i32X, int32_t i32Y, int32_t i32X0, int32_t i32Count,
							int32_t i32BPP, const uint8_t *pui8Data, const uint8_t *pui8Palette)
{
    uint32_t ui32Byte;

    _ST7789WriteCommand(0x2A);						// Load column command, start and end column
    _ST7789WriteData((uint8_t)(i32X >> 8));
    _ST7789WriteData((uint8_t)(i32X & 0xFF));
    _ST7789WriteData((uint8_t)((i32X+i32Count) >> 8));
    _ST7789WriteData((uint8_t)((i32X+i32Count) & 0xFF));

	_ST7789WriteCommand(0x2B);						// Load row command, start and end row
	_ST7789WriteData((uint8_t)(i32Y >> 8));
	_ST7789WriteData((uint8_t)(i32Y & 0xFF));
	_ST7789WriteData((uint8_t)(i32Y >> 8));
	_ST7789WriteData((uint8_t)(i32Y & 0xFF));

	_ST7789WriteCommand(0x2C);						// Send the data value representing the pixel to the display

    // Determine how to interpret the pixel data based on the number of bits per pixel.
    switch(i32BPP & ~GRLIB_DRIVER_FLAG_NEW_IMAGE)
    {
        // The pixel data is in 1 bit per pixel format.
        case 1:
        {
            // Loop while there are more pixels to draw.
            while(i32Count)
            {
                // Get the next byte of image data.
                ui32Byte = *pui8Data++;

                // Loop through the pixels in this byte of image data.
                for(; (i32X0 < 8) && i32Count; i32X0++, i32Count--)
                {
                	ui32Byte = ((uint32_t *)pui8Palette)[(ui32Byte >> (7 - i32X0)) & 1];
                	ui32Byte = ST7789ColorTranslate(0, ui32Byte);

                    // Draw this pixel in the appropriate color.
                	_ST7789WriteData((uint8_t)((ui32Byte >> 8) & 0xFF));
                	_ST7789WriteData((uint8_t)(ui32Byte & 0xFF));
                }
                // Start at the beginning of the next byte of image data.
                i32X0 = 0;
            }
            // The image data has been drawn.
            break;
        }

        // The pixel data is in 4 bit per pixel format.
        case 4:
        {
            // Loop while there are more pixels to draw.  "Duff's device" is
            // used to jump into the middle of the loop if the first nibble of
            // the pixel data should not be used.  Duff's device makes use of
            // the fact that a case statement is legal anywhere within a
            // sub-block of a switch statement.  See
            // http://en.wikipedia.org/wiki/Duff's_device for detailed
            // information about Duff's device.
            switch(i32X0 & 1)
            {
                case 0:
                    while(i32Count)
                    {
                        // Get the upper nibble of the next byte of pixel data
                        // and extract the corresponding entry from the palette.
                        ui32Byte = (*pui8Data >> 4) * 3;
                        ui32Byte = (*(uint32_t *)(pui8Palette + ui32Byte) & 0x00ffffff);
                        ui32Byte = ST7789ColorTranslate(0, ui32Byte);

                        // Translate this palette entry and write it to the screen.
                        _ST7789WriteData((uint8_t)((ui32Byte >> 8) & 0xFF));
                        _ST7789WriteData((uint8_t)(ui32Byte & 0xFF));

                        // Decrement the count of pixels to draw.
                        i32Count--;

                        // See if there is another pixel to draw.
                        if(i32Count)
                        {
                case 1:
                            // Get the lower nibble of the next byte of pixel
                            // data and extract the corresponding entry from the palette.
                            ui32Byte = (*pui8Data++ & 15) * 3;
                            ui32Byte = (*(uint32_t *)(pui8Palette + ui32Byte) & 0x00ffffff);
                            ui32Byte = ST7789ColorTranslate(0, ui32Byte);

                            // Translate this palette entry and write it to the screen.
                            _ST7789WriteData((uint8_t)((ui32Byte >> 8) & 0xFF));
                            _ST7789WriteData((uint8_t)(ui32Byte & 0xFF));

                            // Decrement the count of pixels to draw.
                            i32Count--;
                        }
                    }
            }
            // The image data has been drawn.
            break;
        }
        // The pixel data is in 8 bit per pixel format.
        case 8:
        {
            // Loop while there are more pixels to draw.
            while(i32Count--)
            {
            	// Get the next byte of pixel data and extract the
                // corresponding entry from the palette.
                ui32Byte = *pui8Data++ * 3;
                ui32Byte = *(uint32_t *)(pui8Palette + ui32Byte) & 0x00ffffff;
                ui32Byte = ST7789ColorTranslate(0, ui32Byte);
                // Translate this palette entry and write it to the screen.
                _ST7789WriteData((uint8_t)((ui32Byte >> 8) & 0xFF));
                _ST7789WriteData((uint8_t)(ui32Byte & 0xFF));
            }
            // The image data has been drawn.
            break;
        }
    }
}

void ST7789LineDrawH(void *pvDisplayData, int32_t i32X1, int32_t i32X2, int32_t i32Y, uint32_t ui32Value)
{
    unsigned int uIdx;

    _ST7789WriteCommand(0x2A);						// Load column command, start and end column
    _ST7789WriteData((uint8_t)(i32X1 >> 8));
    _ST7789WriteData((uint8_t)(i32X1 & 0xFF));
    _ST7789WriteData((uint8_t)(i32X2 >> 8));
    _ST7789WriteData((uint8_t)(i32X2 & 0xFF));

    _ST7789WriteCommand(0x2B);						// Load row command, start and end row
    _ST7789WriteData((uint8_t)(i32Y >> 8));
    _ST7789WriteData((uint8_t)(i32Y & 0xFF));
    _ST7789WriteData((uint8_t)(i32Y >> 8));
    _ST7789WriteData((uint8_t)(i32Y & 0xFF));

    uIdx = (i32X1 < i32X2) ? (i32X2 - i32X1) : (i32X1 - i32X2);
    uIdx += 1;

    _ST7789WriteCommand(0x2C);						// Send the data value representing the pixel to the display
    while(uIdx)
    {
    	_ST7789WriteData((uint8_t)(ui32Value >> 8));
    	_ST7789WriteData((uint8_t)(ui32Value & 0xFF));
        uIdx -= 1;
    }
}

void ST7789LineDrawV(void *pvDisplayData, int32_t i32X, int32_t i32Y1, int32_t i32Y2, uint32_t ui32Value)
{
    unsigned int uIdx;

    _ST7789WriteCommand(0x2A);						// Load column command, start and end column
    _ST7789WriteData((uint8_t)(i32X >> 8));
    _ST7789WriteData((uint8_t)(i32X & 0xFF));
    _ST7789WriteData((uint8_t)(i32X >> 8));
    _ST7789WriteData((uint8_t)(i32X & 0xFF));

    _ST7789WriteCommand(0x2B);						// Load row command, start and end row
    _ST7789WriteData((uint8_t)(i32Y1 >> 8));
    _ST7789WriteData((uint8_t)(i32Y1 & 0xFF));
    _ST7789WriteData((uint8_t)(i32Y2 >> 8));
    _ST7789WriteData((uint8_t)(i32Y2 & 0xFF));

    uIdx = (i32Y1 < i32Y2) ? (i32Y2 - i32Y1) : (i32Y1 - i32Y2);
    uIdx += 1;

    _ST7789WriteCommand(0x2C);						// Send the data value representing the pixel to the display

    while(uIdx)
    {
    	_ST7789WriteData((uint8_t)(ui32Value >> 8));
    	_ST7789WriteData((uint8_t)(ui32Value & 0xFF));
        uIdx -= 1;
    }
}

void ST7789RectFill(void *pvDisplayData, const tRectangle *psRect, uint32_t ui32Value)
{
	unsigned int uIdx,  uIyMin;

	_ST7789WriteCommand(0x2A);						// Load column command, start and end column
	_ST7789WriteData((uint8_t)(psRect->i16XMin >> 8));
	_ST7789WriteData((uint8_t)(psRect->i16XMin & 0xFF));
	_ST7789WriteData((uint8_t)(psRect->i16XMax >> 8));
	_ST7789WriteData((uint8_t)(psRect->i16XMax & 0xFF));

	uIyMin = psRect->i16YMin;
	while(uIyMin != ((psRect->i16YMax)+1))
	{
		uIdx = (psRect->i16XMin < psRect->i16XMax) ? (psRect->i16XMax - psRect->i16XMin) : (psRect->i16XMin - psRect->i16XMax);
		uIdx += 1;

		_ST7789WriteCommand(0x2B);						// Load row command, start and end row
		_ST7789WriteData((uint8_t)(uIyMin >> 8));
		_ST7789WriteData((uint8_t)(uIyMin & 0xFF));
		_ST7789WriteData((uint8_t)(uIyMin >> 8));
		_ST7789WriteData((uint8_t)(uIyMin & 0xFF));

		_ST7789WriteCommand(0x2C);						// Send the data value representing the pixel to the display
		while(uIdx)
		{
			_ST7789WriteData((uint8_t)(ui32Value >> 8));
			_ST7789WriteData((uint8_t)(ui32Value & 0xFF));
			uIdx -= 1;
		}
		uIyMin++;
	}
}

uint32_t ST7789ColorTranslate(void *pvDisplayData, uint32_t ui32Value)
{
    // Translate from a 24-bit RGB color to a 5-6-5 RGB color.
	return (((ui32Value & 0x00f80000) >> 8) | ((ui32Value & 0x0000fc00) >> 5) | ((ui32Value & 0x000000f8) >> 3));
}

void ST7789Flush(void *pvDisplayData)
{
    //
    // There is nothing to be done.
    //
}
