---
type: lab
course: EGE320
module: EGE320-Embedded-System-Design
status: draft
source: pdf
created: 2026-05-28
tags: [EGE320, lab, GPIO, RGB-LED, touchscreen, CCS]
---

> **Related:** [[07-DASHBOARDS/NYPY3 - Main Index|NYPY3 Index]] | [[ege320-lab-5-touchscreen-interaction-slides|Lab 5 Touchscreen]] | [[ege320-tutorial-6-slides|Tutorial 6]] | [[07-DASHBOARDS/Schedule & Assessments Dashboard|Assessments]]

# EGE320 Lab 6 — Digital Output

> [!ingest] source: EGE320 - Lab6 Digital Output-1.pdf | date: 2026-05-28 | tool: markitdown
> Auto-converted. Edit summary below; re-run ingest to replace block above.

## Summary

Lab 6 covers **digital GPIO output** on the MSP432 via the RGB LED driver. Three exercises: multicolor LED sequencing with `RGBLEDOnOff()`, a standalone Torch Light touch app (On/Off images), and integration into the Lab 5 unlock → app-icon UI. Uses **CCS IDE**, `rgbled.h`, ST7789 display, and IT7258 touch.

**PDF:** `99-ATTACHMENTS/EGE320/EGE320 - Lab6 Digital Output-1.pdf`

---

## Objectives

- Illustrate digital output concepts
- Demonstrate GPIO peripheral use
- Develop C applications using GPIO peripherals

---

## Contents

1. RGB LED Interface Circuit
2. **1.1** Multicolor LED Display
3. **1.2** Torch Light App
4. **1.3** Integrating Torch Light App

---

## RGBLEDOnOff API

| Parameter | Effect |
|-----------|--------|
| `bRed` | 1 = ON, 0 = OFF red LED |
| `bGreen` | 1 = ON, 0 = OFF green LED |
| `bBlue` | 1 = ON, 0 = OFF blue LED |

```c
void RGBLEDOnOff(bool bRed, bool bGreen, bool bBlue);
```

![[99-ATTACHMENTS/EGE320/ege320-lab-6-digital-output/ege320-lab-6-digital-output-p02.png|Figure 1a — RGB LED interface circuit]]

---

## 1.1 Multicolor LED Display

Cycle red → green → blue using busy-wait delays (~0.5 s each):

```c
#include <stdbool.h>
#include <stdint.h>
#include "clock.h"
#include "rgbled.h"

uint32_t ui32Count = 0;

void MultiColorLEDDisplay(void)
{
    RGBLEDOnOff(1, 0, 0);   // Red ON
    for (ui32Count = 0; ui32Count < 3000000; ui32Count++);

    RGBLEDOnOff(0, 0, 0);   // All OFF
    for (ui32Count = 0; ui32Count < 3000000; ui32Count++);

    RGBLEDOnOff(0, 1, 0);   // Green ON — fill in blanks
    // ... repeat pattern for blue
}

int main(void)
{
    ClockFrequencySet(120000000);
    RGBLEDPinInit();
    while (1) {
        MultiColorLEDDisplay();  // fill in call
    }
}
```

**Expected:** RGB LED lights red, green, blue one at a time.

---

## 1.2 Torch Light App

Touch the centre On/Off button to toggle all RGB LEDs. Download `On.c` and `Off.c` from Blackboard.

![[99-ATTACHMENTS/EGE320/ege320-lab-6-digital-output/ege320-lab-6-digital-output-p04.png|Figure 1.2a — Torch Light App UI]]

**Hit region:** x 100–140, y 100–140

Key logic:
- `bLEDStatus == 0` → turn all LEDs on, draw On image, set status 1
- else → `RGBLEDOnOff(0,0,0)`, draw Off image, clear status

**Includes:** `st7789_spi.h`, `it7258_i2c.h`, `rgbled.h`, `grlib.h`

---

## 1.3 Integrating Torch Light App

Import working project from **Lab5_1.3**, add On/Off images, insert `TorchLightApp()` from §1.2.

![[99-ATTACHMENTS/EGE320/ege320-lab-6-digital-output/ege320-lab-6-digital-output-p07.png|Figure 1.3a — UI transition flow]]

**Flow:**
1. **Page 0** — NYP logo, date/time, UNLOCK button (x 60–180, y 50–90) → sets `i8PageCounter = 1`
2. **Page 1** — Four app icons; music icon region triggers `TorchLightApp()`

---

## Figures

![[99-ATTACHMENTS/EGE320/ege320-lab-6-digital-output/ege320-lab-6-digital-output-p01.png|Lab 6 cover]]
![[99-ATTACHMENTS/EGE320/ege320-lab-6-digital-output/ege320-lab-6-digital-output-p03.png|Exercise 1.1 code page]]
![[99-ATTACHMENTS/EGE320/ege320-lab-6-digital-output/ege320-lab-6-digital-output-p05.png|Torch Light code]]
![[99-ATTACHMENTS/EGE320/ege320-lab-6-digital-output/ege320-lab-6-digital-output-p06.png|Torch Light continued]]
![[99-ATTACHMENTS/EGE320/ege320-lab-6-digital-output/ege320-lab-6-digital-output-p08.png|Integration code]]
![[99-ATTACHMENTS/EGE320/ege320-lab-6-digital-output/ege320-lab-6-digital-output-p09.png|Integration continued]]
