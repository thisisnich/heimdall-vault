---
type: lecture
course: EGE320
module: EGE320-Embedded-System-Design
status: draft
source: pdf
created: 2026-05-21
tags: []
---

# EGE320 Lab 5 Touchscreen Interaction
> [!ingest] source: EGE320 - Lab5 Touchscreen Interaction.pdf | date: 2026-05-21 | tool: markitdown
> Auto-converted. Edit summary below; re-run ingest to replace block above.

## Summary

Lab 5 — **Touchscreen Interaction** on MSP432/IT7258: touch controller interface, interrupt-based touch detection (`IT7258IntRegister`), reading touch points, designing touch-enabled app icons, unlock button UI. Uses CCS IDE.

**PDF:** [[99-ATTACHMENTS/EGE320/EGE320 - Lab5 Touchscreen Interaction.pdf]]
## Raw

Course

: Diploma in Electronic Systems (EGDF18)
: Diploma in Electronic & Computer Engineering (EGDF20)

Module

: Embedded System Design & Technology (EGE320)

Laboratory No.

: Lab 5

Laboratory Title

: Touchscreen Interaction

Objective

Contents

: To demonstrate the use of touchscreen by writing code to display information.

1.  Touch Controller Interface Circuit
1.1.  Getting the Touch Points
1.2.  Designing Touch Enabled App Icon
1.3.  Enabling Touch for Unlock Button

EGE320 Lab 5

Page 1 of 11

  Effective Date: 1 Apr 2022

1

Touch Controller Interface Circuit

Figure 1a: Touch Controller Interface Circuit

Figure 1b: Touch Point Resolution

EGE320 Lab 5

Page 2 of 11

  Effective Date: 1 Apr 2022

1.1  Getting the Touch Points

1.  Setup the CCS IDE development environment learned in Lab1.

2.  To use an interrupt in the microcontroller to detect the touch action instead of polling, the following

function is needed.

Pointer to the interrupt
handling function

void IT7258IntRegister(void (*pfnIntHandler)(void))

void IT7258IntClear(void)

3.  To get the touch point coordinates from the touch controller, the following function is needed.

Pointer to X coordinate
of the touch point.

uint8_t IT7258GetTouchPointData(uint16_t* ui16XPosition,

                                          uint16_t* ui16YPosition,
                                          uint8_t* ui8Pressure)

Pointer to pressure of the
touch point.

Pointer to Y coordinate
of the touch point.

EGE320 Lab 5

Page 3 of 11

  Effective Date: 1 Apr 2022

4.  Complete the code below while entering it into CCS IDE. Build to ensure no errors in the code.

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
    IT7258IntRegister(____________________);                //Register Touch Panel Interrupt

    GrContextFontSet(&sContext, g_psFontCmss48);            //Set font type and size
    GrContextBackgroundSet(&sContext, ClrWhite);            //Set background color to ClrWhite
    GrContextForegroundSet(&sContext, ClrBlack);            //Set background color to ClrBlack

    GrStringDraw(&sContext, "  x  ,  y  ", 11, 15, 60, 0);

    while(1)
    {
        if(bTouchStatus == 1)
        {
            //Read Touch Point
            IT7258GetTouchPointData(__________, __________, ui8Pressure);

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

EGE320 Lab 5

Page 4 of 11

  Effective Date: 1 Apr 2022

5.  Set the project C system stack size from 512 to 1024 under the project properties.

Figure 1.1a: Set C system stack size

6.  Debug and run the code using F8 key.

7.  Touch on different location of the touchscreen. Ensure that the X and Y coordinates displayed on the

LCD screen are close to the coordinates as shown below.

x     ,     y
120   ,   220

x     ,     y
120   ,   050

x     ,     y
220   ,   120

x     ,     y
020   ,   120

Figure 1.1b: Touchscreen

EGE320 Lab 5

Page 5 of 11

  Effective Date: 1 Apr 2022

1.2  Designing Touch Enabled App Icon

1.  The final user interface design is shown in Figure below.

Figure 1.2a: Touch Enabled App Icon

2.  Setup the CCS IDE development environment learned in Lab1.

3.  Download  the  four

images  c  file  namely  MusicIcon.c,  SettingsIcon.c,  TorchLightIcon.c  and

WeatherIcon.c from blackboard. Copy and paste the file in the project as shown in Figure below.

Figure 1.2b: Location of files

EGE320 Lab 5

Page 6 of 11

  Effective Date: 1 Apr 2022

4.  Complete the code below while entering it into CCS IDE. Build to ensure no errors in the code.

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
    GrImageDraw(&sContext, _______________, 35, 115);       //Printing Music Icon picture
    GrImageDraw(&sContext, g_pui8WeatherIcon, ___, ___);    //Printing Weather Icon picture

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

EGE320 Lab 5

Page 7 of 11

  Effective Date: 1 Apr 2022

                if(((125 < ui16XPosition[0]) && (ui16XPosition[0] < 205)) &&
                   ((25 < ui16YPosition[0]) && (ui16YPosition[0] < 105)))
                {
                    GrCircleFill(&sContext, 120, 120, 121);
                }
                if(((__ < ui16XPosition[0]) && (ui16XPosition[0] < ___)) &&
                   ((__ < ui16YPosition[0]) && (ui16YPosition[0] < ___)))
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

5.  Debug and run the code using F8 key.

6.  Ensure that the Four App Icon are displayed on the LCD screen as shown in Figure 1.2a. Touch on

every single icon and a white screen will be shown to indicate the access to the icon.

EGE320 Lab 5

Page 8 of 11

  Effective Date: 1 Apr 2022

1.3  Enabling Touch for Unlock Button

1.  The flow of the user interface design transition after the unlock button is touched is shown in Figure

below.

Figure 1.3a: User Interface Design Transition on Touch

2.  Setup the CCS IDE development environment by importing the working project from Lab4_1.4.

3.  Complete  the code below by referring to the  code in Section  1.2. Build to  ensure no errors in the

code.

#include <stdbool.h>
#include <stdint.h>
#include "clock.h"
#include "grlib.h"
#include "st7789_spi.h"                                     //Include the display driver file
#include "it7258_i2c.h"                                     //Include the touch driver file

extern const uint8_t g_pui8NypLogo[];
extern const uint8_t g_pui8SettingsIcon[];
extern const uint8_t g_pui8TorchLightIcon[];
extern const uint8_t g_pui8MusicIcon[];
extern const uint8_t g_pui8WeatherIcon[];

tContext sContext = {};
tRectangle sRect = {};
uint32_t uiDelay;
uint16_t ui16XPosition[3] = {};
uint16_t ui16YPosition[3] = {};
uint8_t ui8Pressure[3] = {};
bool bTouchStatus = 0;
int8_t i8PageCounter = 0;
bool bPagePrinted = 0;

//Insert code to use Touch Panel Interrupt Handler

EGE320 Lab 5

Page 9 of 11

  Effective Date: 1 Apr 2022

int main(void)
{
    ClockFrequencySet(120000000);                       //Set processor clock to 120MHz
    ST7789PinInit(120000000);                           //Initialize LCD Controller pin
    IT7258PinInit(120000000);                           //Initialize Touch Controller pin
    GrContextInit(&sContext, &g_sST7789);               //Initialize glib Context

    //Insert code to register Touch Panel Interrupt Handler

    //To display NYP Logo
    GrImageDraw(&sContext, g_pui8NypLogo, 20, 90);

    //Create a 1 second delay
    for(uiDelay=0; uiDelay<7000000; uiDelay++);

    //Clear the screen by drawing a filled circle
    GrContextForegroundSet(&sContext, ClrWhite);
    GrCircleFill(&sContext, 120, 120, 121);
    GrContextForegroundSet(&sContext, ClrBlack);

    //Display clock and date
    GrContextFontSet(&sContext, g_psFontCmss48);
    GrContextBackgroundSet(&sContext, ClrWhite);
    GrContextForegroundSet(&sContext, ClrBlack);
    GrStringDraw(&sContext, "09:55:34", 8, 50, 60, 0);
    GrContextFontSet(&sContext, g_psFontCmss28);
    GrStringDraw(&sContext, "01:04:18", 8, 80, 110, 0);

    //Print UNLOCK button
    sRect.i16XMin = 60;
    sRect.i16YMin = 150;
    sRect.i16XMax = 180;
    sRect.i16YMax = 190;
    GrRectFill(&sContext, &sRect);

    GrLineDraw(&sContext, 58, 148, 182, 148);
    GrLineDraw(&sContext, 58, 148, 58, 192);
    GrLineDraw(&sContext, 58, 192, 182, 192);
    GrLineDraw(&sContext, 182, 148, 182, 192);

    //Print text on UNLOCK button
    GrContextForegroundSet(&sContext, ClrWhite);
    GrContextFontSet(&sContext, g_psFontCmss14);
    GrStringDraw(&sContext, "PRESS TO UNLOCK", 15, 65, 165, 0);

    while(1)
    {
        if(i8PageCounter == 0)
        {
            if(bTouchStatus == 1)
            {
                //Insert code to enable touch for UNLOCK button by following the step below
                //1. Read Touch Point
                //2. Check if the Touch Points is not zero
                {
                    //3. Check if the touch points is within the UNLOCK button compound
                    {
                        //4. Set the i8PageCounter to 1
                    }
                }
                //5. Wait for touch to be released
                //6. Reset bTouchStatus
            }
        }

EGE320 Lab 5

Page 10 of 11

  Effective Date: 1 Apr 2022

        if(i8PageCounter == 1)
        {
            if(bPagePrinted == 0)
            {
                GrContextForegroundSet(&sContext, ClrBlack);
                GrCircleFill(&sContext, 120, 120, 121);

                //Insert code from (Exercise 1.2) to display the 4 App Icons

                bPagePrinted = 1;
            }

            if(bTouchStatus == 1)
            {
                //Insert code from (Exercise 1.2) to detect the
                //touch points for the 4 App Icons and clear bTouchStatus to 0
            }
        }
    }
}

4.  Debug and run the code using F8 key.

5.  Touch on the Unlock button displayed on the LCD screen to access to the user interface with four
App Icons as shown in Figure 1.3a. Continue to touch on every single icon and a white screen will be
shown to indicate the access to the icon.

EGE320 Lab 5

Page 11 of 11

  Effective Date: 1 Apr 2022
