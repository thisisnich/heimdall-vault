

/**
 * main.c
 */
#include <stdbool.h>
#include <stdint.h>
#include "clock.h"
#include "grlib.h"
#include "st7789_spi.h"                         //Include the display driver file
#include "it7258_i2c.h"                         //Include the touch driver file
#include "rgbled.h"                             //Include the rgbled driver file

extern const uint8_t g_pui8On[];
extern const uint8_t g_pui8Off[];

tContext sContext = {};
uint16_t ui16XPosition[3] = {};
uint16_t ui16YPosition[3] = {};
uint8_t ui8Pressure[3] = {};
bool bTouchStatus = 0;

void TorchLightApp(void)
{
    bool bLEDStatus = 0;

    //Print Off image
    GrImageDraw(&sContext, g_pui8Off, 80, 80);

    while(1)
    {
        if(bTouchStatus == 1)
        {
            //Read Touch Point
            IT7258GetTouchPointData(ui16XPosition, ui16YPosition, ui8Pressure);

            if((ui16XPosition[0] != 0) && (ui16YPosition[0] != 0))
            {
                if(((100 < ui16XPosition[0]) && (ui16XPosition[0] < 140)) &&
                   ((100 < ui16YPosition[0]) && (ui16YPosition[0] < 140)))
                {
                    //Check if LED is On or Off
                    if (bLEDStatus == 0)
                    {
                        //Turn ON all LEDs
                        RGBLEDOn(1, 1, 1);

                        //Print On image
                        GrImageDraw(&sContext, g_pui8On, 80, 80);

                        //Set bLEDStatus to 1
                        bLEDStatus = 1;
                    }
                    else
                    {
                        //Turn OFF all LEDs
                        RGBLEDOnOff(0, 0, 0);

                        //Print Off image
                        GrImageDraw(&sContext, g_pui8Off, 80, 80);

                        //Clear bLEDStatus to 0
                        bLEDStatus = 0;
                    }
                }
            }

            //Wait for touch to be released
            while((ui16XPosition[0] != 0) && (ui16YPosition[0] != 0))
            {
                IT7258GetTouchPointData(ui16XPosition, ui16YPosition, ui8Pressure);
            }

            //Reset bTouchStatus
            bTouchStatus = 0;
        }
    }
}

void TouchPanelIntHandler(void)                 //Touch Panel ISR
{
    IT7258IntClear();                           //Clear Interrupt
    bTouchStatus = 1;                           //Set bTouchStatus
}

int main(void)
{
    ClockFrequencySet(120000000);               //Set processor clock to 120MHz
    ST7789PinInit(120000000);                   //Initialize LCD Controller pin
    IT7258PinInit(120000000);                   //Initialize Touch Controller pin
    RGBLEDPinInit();                            //Initialize RGBLED pin

    GrContextInit(&sContext, &g_sST7789);       //Initialize glib Context
    IT7258IntRegister(TouchPanelIntHandler);    //Register Touch Panel Interrupt

    TorchLightApp();                            //TorchLightApp Function Call
}
