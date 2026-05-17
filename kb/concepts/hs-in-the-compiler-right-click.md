---
id: "105cdcd7-db9f-471e-846e-baa82e20d341"
title: "Hs In The Compiler Right Click"
type: vault_note
vault: wiki
created: 2026-05-17
updated: 2026-05-17
checksum: "sha256:fb41c68fa18b5f58"
source: heimdall/auto
---

# Hs In The Compiler Right Click

- hs in the compiler, right-click on `lab1` → **Properties**. In the Properties window, add the six paths in **Include Options** under **ARM Compiler**. Click **Apply and Close**.


11. Double click on `main.c` in project `lab1`, delete all existing code, enter the program below, and save.

```c
#include <stdbool.h>
#include <stdint.h>
#include <stdio.h>
#include "clock.h"
#include "rgbled.h"
#include "grlib.h"
#include "st7789_spi.h"
#include "it7258_i2c.h"

bool bTouchStatus = 0;

void TouchPanelIntHandler(void)                             //Touch Panel ISR
{
    IT7258IntClear();                                       //Clear Interrupt
    bTouchStatus = 1;                                       //Set bTouchStatus
}

int main(void)
{
    tContext sContext = {};
    uint16_t ui16XPosition[3] = {};
    uint16_t ui16YPosition[3] = {};
    uint8_t ui8Pressure[3] = {};

    ClockFrequencySet(120000000);                           //Set processor clock to 120MHz
    RGBLEDPinInit();                                        //Initialize RGBLED pin
    IT7258PinInit(120000000);                               //Initialize Touch Controller pin
    ST7789PinInit(120000000);                               //Initialize LCD Controller pin
    GrContextInit(&sContext, &g_sST7789);                   //Initialize glib Context
    IT7258IntRegister(TouchPanelIntHandler);                //Register Touch Panel Interrupt

    GrContextForegroundSet(&sContext, ClrRed);
    GrCircleFill(&sContext, 120, 6 <!-- id:105cdcd7-db9f-471e-846e-baa82e20d341 ts:2026-05-17 07:49 -->
