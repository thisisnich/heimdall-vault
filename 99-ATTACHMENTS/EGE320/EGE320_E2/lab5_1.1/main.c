

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

tContext sContext = {};
uint16_t ui16XPosition[3] = {};
uint16_t ui16YPosition[3] = {};
uint8_t ui8Pressure[3] = {};
bool bTouchStatus = 0;
char uc8TempCoordinate[10] = {};

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

    GrContextFontSet(&sContext, g_psFontCmss48);            //Set font type and size
    GrContextBackgroundSet(&sContext, ClrWhite);            //Set background color to ClrWhite
    GrContextForegroundSet(&sContext, ClrBlack);            //Set background color to ClrBlack

    GrStringDraw(&sContext, "  x  ,  y  ", 11, 15, 60, 0);

    while(1)
    {
        if(bTouchStatus == 1)
        {
            //Read Touch Point
            IT7258GetTouchPointData(ui16XPosition, ui16YPosition, ui8Pressure);

            if((ui16XPosition[0] != 0) && (ui16YPosition[0] != 0))
            {
                //Display Touch Point
                sprintf(uc8TempCoordinate," %.3d , %.3d ", ui16XPosition[0], ui16YPosition[0]);
                GrStringDraw(&sContext, uc8TempCoordinate, 11, 15, 120, 1);
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
