#ifndef ST7789_SPI_H_
#define ST7789_SPI_H_

//*****************************************************************************
//! This flag is passed to display driver's PixelDrawMultiple calls in the
//! i32BPP parameter to indicate that a given span of pixels represents the
//! first line of a new image.  Drivers may use this to recalculate any color
//! mapping table required to draw the image rather than doing this on every
//! line of pixels.
//*****************************************************************************
#define GRLIB_DRIVER_FLAG_NEW_IMAGE     	0x40000000

#define	ST7789_SPI_PERIPH			SYSCTL_PERIPH_GPIOQ
#define	ST7789_BACKLIGHT_PERIPH		SYSCTL_PERIPH_GPIOF
#define	ST7789_RESET_PERIPH			SYSCTL_PERIPH_GPIOM

#define	ST7789_SPI_PORT				GPIO_PORTQ_AHB_BASE
#define	ST7789_BACKLIGHT_PORT		GPIO_PORTF_AHB_BASE
#define	ST7789_RESET_PORT			GPIO_PORTM_AHB_BASE

#define	ST7789_SPI_SCLK_PIN			GPIO_PIN_0
#define	ST7789_SPI_SDI_PIN			GPIO_PIN_2
#define	ST7789_SPI_RS_PIN			GPIO_PIN_3
#define	ST7789_SPI_CS_PIN			GPIO_PIN_1
#define	ST7789_BACKLIGHT_PIN		GPIO_PIN_3
#define	ST7789_RESET_PIN			GPIO_PIN_5

//*****************************************************************************
// Prototypes for the globals exported by this driver.
//*****************************************************************************
extern const tDisplay g_sST7789;

//*****************************************************************************
// Prototypes for the APIs.
//*****************************************************************************
void ST7789PinInitSPITest(int32_t ui32SysClock);
void ST7789PinInit(int32_t ui32SysClock);
void ST7789PixelDraw(void *pvDisplayData, int32_t i32X, int32_t i32Y, uint32_t ui32Value);
void ST7789PixelDrawMultiple(void *pvDisplayData, int32_t i32X, int32_t i32Y, int32_t i32X0, int32_t i32Count,
							int32_t i32BPP, const uint8_t *pui8Data, const uint8_t *pui8Palette);
void ST7789LineDrawH(void *pvDisplayData, int32_t i32X1, int32_t i32X2, int32_t i32Y, uint32_t ui32Value);
void ST7789LineDrawV(void *pvDisplayData, int32_t i32X, int32_t i32Y1, int32_t i32Y2, uint32_t ui32Value);
void ST7789RectFill(void *pvDisplayData, const tRectangle *psRect, uint32_t ui32Value);
uint32_t ST7789ColorTranslate(void *pvDisplayData, uint32_t ui32Value);
void ST7789Flush(void *pvDisplayData);

#endif /* ST7789_SPI_H_ */

