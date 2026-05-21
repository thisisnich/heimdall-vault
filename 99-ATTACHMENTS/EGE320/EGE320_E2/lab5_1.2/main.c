

/**
 * main.c
 */
#include <stdbool.h>
#include <stdint.h>
#include <stdio.h>
#include "clock.h"
#include "grlib.h"
#include "st7789_spi.h"                                     //Include the display driver file
#include "it7258_i2c.h"                                     //Include the touch driver file

extern const uint8_t g_pui8SettingsIcon[];
extern const uint8_t g_pui8TorchLightIcon[];
extern const uint8_t g_pui8MusicIcon[];
extern const uint8_t g_pui8WeatherIcon[];

tContext sContext = {};
uint16_t ui16XPosition[3] = {};
uint16_t ui16YPosition[3] = {};
uint8_t ui8Pressure[3] = {};
bool bTouchStatus = 0;

void TouchPanelIntHandler(void)                             //Touch Panel ISR
{
    IT7258IntClear();                                       //Clear Interrupt
    bTouchStatus = 1;                                       //Set bTouchStatus
}

int main(void)
{
    ClockFrequencySet(120000000);                           //Set processor clock to 120MHz
    ST7789PinInit(120000000);                               //Initialize LCD Controller pin
    IT7258PinInit(120000000);                               //Initialize Touch Controller pin

    GrContextInit(&sContext, &g_sST7789);                   //Initialize glib Context
    IT7258IntRegister(TouchPanelIntHandler);                //Register Touch Panel Interrupt

    GrContextForegroundSet(&sContext, ClrBlack);            //Set Foreground color to black
    GrCircleFill(&sContext, 120, 120, 121);                 //Draw a filled circle

    GrImageDraw(&sContext, g_pui8SettingsIcon, 35, 25);     //Printing TorchLight Icon picture
    GrImageDraw(&sContext, g_pui8TorchLightIcon, 125, 25);  //Printing Weather Icon picture
    GrImageDraw(&sContext, g_pui8MusicIcon, 35, 115);        //Printing Music Icon picture
    GrImageDraw(&sContext, g_pui8WeatherIcon, 125, 115);    //Printing Weather Icon picture

    while(1)
    {
        if(bTouchStatus == 1)
        {
            //Set Foreground color to white
            GrContextForegroundSet(&sContext, ClrWhite);

            //Read Touch Point
            IT7258GetTouchPointData(ui16XPosition, ui16YPosition, ui8Pressure);

            if((ui16XPosition[0] != 0) && (ui16YPosition[0] != 0))
            {
                //Check if the touch point is within the range
                if(((125 < ui16XPosition[0]) && (ui16XPosition[0] < 205)) &&
                   ((115 < ui16YPosition[0]) && (ui16YPosition[0] < 195)))
                {
                    //Draw a filled circle
                    GrCircleFill(&sContext, 120, 120, 121);
                }
                if(((35 < ui16XPosition[0]) && (ui16XPosition[0] < 115)) &&
                   ((115 < ui16YPosition[0]) && (ui16YPosition[0] < 195)))
                {
                    GrCircleFill(&sContext, 120, 120, 121);
                }
                if(((125 < ui16XPosition[0]) && (ui16XPosition[0] < 205)) &&
                   ((25 < ui16YPosition[0]) && (ui16YPosition[0] < 105)))
                {
                    GrCircleFill(&sContext, 120, 120, 121);
                }
                if(((35 < ui16XPosition[0]) && (ui16XPosition[0] < 115)) &&
                   ((25 < ui16YPosition[0]) && (ui16YPosition[0] < 105)))
                {
                    GrCircleFill(&sContext, 120, 120, 121);
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
