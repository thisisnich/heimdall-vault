---
type: lab
course: EGE320
module: EGE320-Embedded-System-Design
status: draft
source: pdf
created: 2026-05-21
tags: [EGE320, lab, touchscreen, IT7258, CCS]
---

> **Related:** [[07-DASHBOARDS/NYPY3 - Main Index|NYPY3 Index]] | [[EGE320 - Touch Screen Technology|Touch Screen Lesson]] | [[ege320-tutorial-5-slides|Tutorial 5]] | [[07-DASHBOARDS/Schedule & Assessments Dashboard|Assessments]]

> **Code:** `99-ATTACHMENTS/EGE320/EGE320_E2/` · [[99-ATTACHMENTS/EGE320/EGE320_E2/README|EGE320_E2 workflow]]

# EGE320 Lab 5 — Touchscreen Interaction

> [!ingest] source: EGE320 - Lab5 Touchscreen Interaction.pdf | date: 2026-05-21 | tool: markitdown
> Auto-converted. Edit summary below; re-run ingest to replace block above.

## Summary

Demonstrate touchscreen use on MSP432 with **IT7258** I2C touch controller and **ST7789** LCD. Three exercises: read/display touch coordinates via interrupt, touch-enabled app icons with hit regions, unlock-button flow transitioning to icon screen. Uses **CCS IDE**, GrLib, stack size 1024.

---

## Contents

1. Touch Controller Interface Circuit
2. **1.1** Getting the Touch Points
3. **1.2** Designing Touch Enabled App Icon
4. **1.3** Enabling Touch for Unlock Button

---

## IT7258 API

| Function | Purpose |
|----------|---------|
| `IT7258IntRegister(void (*pfnIntHandler)(void))` | Register touch interrupt handler |
| `IT7258IntClear(void)` | Clear touch interrupt |
| `IT7258GetTouchPointData(uint16_t* x, uint16_t* y, uint8_t* pressure)` | Read X, Y, pressure |

**Includes:** `st7789_spi.h` (display), `it7258_i2c.h` (touch), `grlib.h`

---

## 1.1 Getting the Touch Points

### Setup

1. CCS IDE (from Lab 1)
2. Register ISR: `IT7258IntRegister(TouchPanelIntHandler)`
3. Set **C system stack size** 512 → **1024** (project properties)
4. Debug/run (F8)

### Expected coordinates (approx.)

| Location | x | y |
|----------|---|---|
| Bottom | 120 | 220 |
| Top | 120 | 050 |
| Right | 220 | 120 |
| Left | 020 | 120 |

### Key code pattern

```c
void TouchPanelIntHandler(void) {
    IT7258IntClear();
    bTouchStatus = 1;
}

// In main loop when bTouchStatus == 1:
IT7258GetTouchPointData(ui16XPosition, ui16YPosition, ui8Pressure);
sprintf(uc8TempCoordinate, " %.3d , %.3d ", ui16XPosition[0], ui16YPosition[0]);
GrStringDraw(&sContext, uc8TempCoordinate, 11, 15, 120, 1);

// Wait for release
while ((ui16XPosition[0] != 0) && (ui16YPosition[0] != 0))
    IT7258GetTouchPointData(ui16XPosition, ui16YPosition, ui8Pressure);
bTouchStatus = 0;
```

**Blanks to fill:** `IT7258IntRegister(___)`, `IT7258GetTouchPointData(___)`.

---

## 1.2 Touch Enabled App Icons

Download from Blackboard: `MusicIcon.c`, `SettingsIcon.c`, `TorchLightIcon.c`, `WeatherIcon.c`

Four icons in quadrants; touch within region → white screen feedback.

### Hit region example (one icon)

```c
if (((125 < ui16XPosition[0]) && (ui16XPosition[0] < 205)) &&
    ((115 < ui16YPosition[0]) && (ui16YPosition[0] < 195))) {
    GrContextForegroundSet(&sContext, ClrWhite);
    GrCircleFill(&sContext, 120, 120, 121);
}
```

Draw icons with `GrImageDraw(&sContext, g_pui8MusicIcon, x, y)`.

---

## 1.3 Unlock Button Flow

1. Import working project from **Lab4_1.4**
2. Splash: NYP logo → 1 s delay → clock/date + **PRESS TO UNLOCK** button
3. Touch unlock (region ~60–180 x, 150–190 y) → `i8PageCounter = 1` → show 4 app icons (reuse 1.2 logic)
4. Touch icons → white screen

**State machine:** `i8PageCounter` (0 = lock screen, 1 = icons), `bPagePrinted`, `bTouchStatus`

---

## Tasks

- [x] Complete 1.1 coordinate display
- [x] Complete 1.2 four-icon touch regions
- [x] Complete 1.3 unlock → icons transition
- [ ] Demo all touch regions to instructor
