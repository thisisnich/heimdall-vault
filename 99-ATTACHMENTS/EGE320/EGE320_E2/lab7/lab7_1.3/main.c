/**
 * EGE320 Lab 7 — Exercise 1.3 (Home push button)
 * Import Lab6_1.3 CCS project, replace main.c with this file.
 * Requires: Drivers, Libraries, nyplogo.c, icon/image sources from Utility.zip
 */
#include <stdbool.h>
#include <stdint.h>
#include "clock.h"
#include "grlib.h"
#include "st7789_spi.h"
#include "it7258_i2c.h"
#include "rgbled.h"
#include "pushbutton.h"

extern const uint8_t g_pui8NypLogo[];
extern const uint8_t g_pui8SettingsIcon[];
extern const uint8_t g_pui8TorchLightIcon[];
extern const uint8_t g_pui8MusicIcon[];
extern const uint8_t g_pui8WeatherIcon[];
extern const uint8_t g_pui8On[];
extern const uint8_t g_pui8Off[];

tContext sContext = {};
tRectangle sRect = {};
uint32_t uiDelay;
uint16_t ui16XPosition[3] = {};
uint16_t ui16YPosition[3] = {};
uint8_t ui8Pressure[3] = {};
bool bTouchStatus = 0;
int8_t i8PageCounter = 0;
bool bPagePrinted = 0;
uint8_t ui8PressStatus = 0;
bool bHomePagePrinted = 0;

/* Time + unlock UI (no logo) — used on Home return */
static void DrawTimeUnlockUI(void)
{
    GrContextForegroundSet(&sContext, ClrWhite);
    GrCircleFill(&sContext, 120, 120, 121);
    GrContextForegroundSet(&sContext, ClrBlack);
    GrContextFontSet(&sContext, g_psFontCmss48);
    GrContextBackgroundSet(&sContext, ClrWhite);
    GrContextForegroundSet(&sContext, ClrBlack);
    GrStringDraw(&sContext, "09:55:34", 8, 50, 60, 0);
    GrContextFontSet(&sContext, g_psFontCmss28);
    GrStringDraw(&sContext, "01:04:18", 8, 80, 110, 0);
    sRect.i16XMin = 60;
    sRect.i16YMin = 150;
    sRect.i16XMax = 180;
    sRect.i16YMax = 190;
    GrRectFill(&sContext, &sRect);
    GrLineDraw(&sContext, 58, 148, 182, 148);
    GrLineDraw(&sContext, 58, 148, 58, 192);
    GrLineDraw(&sContext, 58, 192, 182, 192);
    GrLineDraw(&sContext, 182, 148, 182, 192);
    GrContextForegroundSet(&sContext, ClrWhite);
    GrContextFontSet(&sContext, g_psFontCmss14);
    GrStringDraw(&sContext, "PRESS TO UNLOCK", 15, 65, 165, 0);
}

/* Lab 7 §1.2 — exit torch when push button pressed */
void TorchLightApp(void)
{
    bool bLEDStatus = 0;

    GrImageDraw(&sContext, g_pui8Off, 80, 80);

    while (ui8PressStatus == 0)
    {
        if (bTouchStatus == 1)
        {
            IT7258GetTouchPointData(ui16XPosition, ui16YPosition, ui8Pressure);

            if ((ui16XPosition[0] != 0) && (ui16YPosition[0] != 0))
            {
                if (((100 < ui16XPosition[0]) && (ui16XPosition[0] < 140)) &&
                    ((100 < ui16YPosition[0]) && (ui16YPosition[0] < 140)))
                {
                    if (bLEDStatus == 0)
                    {
                        RGBLEDOnOff(1, 1, 1);
                        GrImageDraw(&sContext, g_pui8On, 80, 80);
                        bLEDStatus = 1;
                    }
                    else
                    {
                        RGBLEDOnOff(0, 0, 0);
                        GrImageDraw(&sContext, g_pui8Off, 80, 80);
                        bLEDStatus = 0;
                    }
                }
            }

            while ((ui16XPosition[0] != 0) && (ui16YPosition[0] != 0))
            {
                IT7258GetTouchPointData(ui16XPosition, ui16YPosition, ui8Pressure);
            }
            bTouchStatus = 0;
        }
    }

    bPagePrinted = 0;
    RGBLEDOnOff(0, 0, 0);
    while (ui8PressStatus == 1)
        ;
}

void TouchPanelIntHandler(void)
{
    IT7258IntClear();
    bTouchStatus = 1;
}

void PushButtonIntHandler(void)
{
    PushButtonIntClear();
    if (ui8PressStatus == 0)
        ui8PressStatus = 1;
    else
        ui8PressStatus = 0;
}

int main(void)
{
    ClockFrequencySet(120000000);
    ST7789PinInit(120000000);
    IT7258PinInit(120000000);
    RGBLEDPinInit();
    PushButtonPinInit();
    GrContextInit(&sContext, &g_sST7789);

    IT7258IntRegister(TouchPanelIntHandler);
    PushButtonIntRegister(PushButtonIntHandler);

    /* First boot: logo splash then time/unlock */
    GrImageDraw(&sContext, g_pui8NypLogo, 20, 90);
    for (uiDelay = 0; uiDelay < 7000000; uiDelay++)
        ;
    DrawTimeUnlockUI();
    bHomePagePrinted = 1;

    while (1)
    {
        if (i8PageCounter == 0)
        {
            if (bHomePagePrinted == 0)
            {
                DrawTimeUnlockUI();
                bHomePagePrinted = 1;
            }

            if (bTouchStatus == 1)
            {
                IT7258GetTouchPointData(ui16XPosition, ui16YPosition, ui8Pressure);
                if ((ui16XPosition[0] != 0) && (ui16YPosition[0] != 0))
                {
                    if (((60 < ui16XPosition[0]) && (ui16XPosition[0] < 180)) &&
                        ((50 < ui16YPosition[0]) && (ui16YPosition[0] < 90)))
                    {
                        i8PageCounter = 1;
                    }
                }
                while ((ui16XPosition[0] != 0) && (ui16YPosition[0] != 0))
                {
                    IT7258GetTouchPointData(ui16XPosition, ui16YPosition, ui8Pressure);
                }
                bTouchStatus = 0;
            }
        }

        if (i8PageCounter == 1)
        {
            if (bPagePrinted == 0)
            {
                GrContextForegroundSet(&sContext, ClrBlack);
                GrCircleFill(&sContext, 120, 120, 121);
                GrImageDraw(&sContext, g_pui8SettingsIcon, 35, 25);
                GrImageDraw(&sContext, g_pui8TorchLightIcon, 125, 25);
                GrImageDraw(&sContext, g_pui8MusicIcon, 35, 115);
                GrImageDraw(&sContext, g_pui8WeatherIcon, 125, 115);
                bPagePrinted = 1;
            }

            if (bTouchStatus == 1)
            {
                GrContextForegroundSet(&sContext, ClrWhite);
                IT7258GetTouchPointData(ui16XPosition, ui16YPosition, ui8Pressure);

                if ((ui16XPosition[0] != 0) && (ui16YPosition[0] != 0))
                {
                    if (((125 < ui16XPosition[0]) && (ui16XPosition[0] < 205)) &&
                        ((115 < ui16YPosition[0]) && (ui16YPosition[0] < 195)))
                    {
                        GrCircleFill(&sContext, 120, 120, 121);
                    }
                    if (((35 < ui16XPosition[0]) && (ui16XPosition[0] < 115)) &&
                        ((115 < ui16YPosition[0]) && (ui16YPosition[0] < 195)))
                    {
                        GrCircleFill(&sContext, 120, 120, 121);
                        TorchLightApp();
                    }
                    if (((125 < ui16XPosition[0]) && (ui16XPosition[0] < 205)) &&
                        ((25 < ui16YPosition[0]) && (ui16YPosition[0] < 105)))
                    {
                        GrCircleFill(&sContext, 120, 120, 121);
                    }
                    if (((35 < ui16XPosition[0]) && (ui16XPosition[0] < 115)) &&
                        ((25 < ui16YPosition[0]) && (ui16YPosition[0] < 105)))
                    {
                        GrCircleFill(&sContext, 120, 120, 121);
                    }
                }

                while ((ui16XPosition[0] != 0) && (ui16YPosition[0] != 0))
                {
                    IT7258GetTouchPointData(ui16XPosition, ui16YPosition, ui8Pressure);
                }
                bTouchStatus = 0;
            }

            /* Lab 7 §1.3 — Home: push button returns to time UI */
            if (ui8PressStatus == 1)
            {
                i8PageCounter = 0;
                bHomePagePrinted = 0;
                bPagePrinted = 0;
                while (ui8PressStatus == 1)
                    ;
            }
        }
    }
}
