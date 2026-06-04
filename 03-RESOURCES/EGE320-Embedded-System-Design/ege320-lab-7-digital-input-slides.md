---
type: lab
course: EGE320
module: EGE320-Embedded-System-Design
status: reviewed
source: pdf
created: 2026-06-04
tags: [EGE320, lab, GPIO, push-button, digital-input, CCS]
---

> **Related:** [[ege320-lab-6-digital-output-slides|Lab 6 Digital Output]] | [[ege320-chapter-2-embedded-hardware-slides|Chapter 2]] | [[ege320-equiz1-cheat-sheet|eQuiz 1 cheat sheet]] | [[07-DASHBOARDS/Schedule & Assessments Dashboard|Assessments]]

> **PDF:** [[99-ATTACHMENTS/EGE320/EGE320 - Lab7 Digital Input.pdf|EGE320 - Lab7 Digital Input.pdf]]

# EGE320 Lab 7 — Digital Input

> [!ingest] source: EGE320 - Lab7 Digital Input.pdf | date: 2026-06-04 | tool: markitdown
> Auto-converted. Edit summary below; re-run ingest to replace block above.

## Summary

Lab 7 adds **digital input** via the board **push button** using **GPIO interrupts** (not polling). Three exercises: detect press/release on LCD, use the button to **exit** the Lab 6 Torch Light app, then implement a **Home** button that returns from the app grid to the lock/time UI. Builds on Lab 5–6 (`IT7258` touch, `RGBLED`, `pushbutton.h`, GrLib, ST7789).

**Note:** Digital input theory is **after eQuiz 1** scope, but this lab is on the **Lab Test 1** path (Labs 1–7).

---

## Objectives

- Illustrate **digital input** (contact closure → logic 0/1)
- Demonstrate **GPIO** with interrupt-driven push button
- Develop C apps combining touch + push button + RGB LED

---

## Contents

1. Push Button Interface Circuit
2. **1.1** Push Button Press Detection
3. **1.2** App Exit Push Button (from Torch Light)
4. **1.3** Home Push Button (back to time UI)

---

## Push button API

| Function | Purpose |
|----------|---------|
| `PushButtonPinInit()` | Configure push-button GPIO |
| `PushButtonIntRegister(void (*pfnIntHandler)(void))` | Register ISR |
| `PushButtonIntClear(void)` | Clear interrupt flag |

**ISR pattern:** toggle `ui8PressStatus` (0 = released, 1 = pressed) after `PushButtonIntClear()`.

**Includes:** `pushbutton.h`, `st7789_spi.h`, `grlib.h`, `clock.h` — plus Lab 6: `it7258_i2c.h`, `rgbled.h`

![[99-ATTACHMENTS/EGE320/ege320-lab-7-digital-input/ege320-lab-7-digital-input-p01.png|Push button interface circuit]]

---

## 1.1 Push button press detection

![[99-ATTACHMENTS/EGE320/ege320-lab-7-digital-input/ege320-lab-7-digital-input-p02.png|Figure 1.1a — PRESSED / RELEASED on LCD]]

### Fill-in answers

| Blank | Answer |
|-------|--------|
| `PushButtonIntRegister(___)` | `PushButtonIntHandler` |
| `if (ui8PressStatus == __)` | `1` (show "PRESSED") |

```c
void PushButtonIntHandler(void)
{
    PushButtonIntClear();
    if (ui8PressStatus == 0)
        ui8PressStatus = 1;
    else
        ui8PressStatus = 0;
}

// main:
PushButtonIntRegister(PushButtonIntHandler);
// loop:
if (ui8PressStatus == 1)
    GrStringDraw(&sContext, "PRESSED  ", 10, 60, 110, 1);
else
    GrStringDraw(&sContext, "RELEASED ", 10, 60, 110, 1);
```

Run with **F8**; press/release updates LCD text.

---

## 1.2 Exit push button (Torch Light app)

Import **Lab6_1.3** project. Push button exits `TorchLightApp()` and returns to icon screen.

![[99-ATTACHMENTS/EGE320/ege320-lab-7-digital-input/ege320-lab-7-digital-input-p04.png|Figure 1.2a — Exit Torch Light via push button]]

### `TorchLightApp()` fill-ins

| Blank | Answer |
|-------|--------|
| `while(___)` — stay in torch while not exiting | `ui8PressStatus == 0` |
| `bPagePrinted = _` | `0` |
| `RGBLEDOnOff(_, _, _)` | `0, 0, 0` |
| `while(___)` — wait until button released | `ui8PressStatus == 1` |

**Torch touch region (on/off image):** x 100–140, y 100–140.

**Music icon (bottom-left) launches torch:** x 35–115, y 115–195.

---

## 1.3 Home push button

From **four app icons**, press push button → return to **lock/time UI** (page 0).

![[99-ATTACHMENTS/EGE320/ege320-lab-7-digital-input/ege320-lab-7-digital-input-p08.png|Figure 1.3a — Home: back to time UI]]

### New flag

- `bool bHomePagePrinted = 0` — avoid redrawing home screen every loop

### In `main` when `i8PageCounter == 0`

- If `bHomePagePrinted == 0`: redraw date/time + unlock button → set `bHomePagePrinted = 1`

### When `i8PageCounter == 1` and push button pressed

```c
if (ui8PressStatus == 1)
{
    i8PageCounter = 0;
    bHomePagePrinted = 0;
    bPagePrinted = 0;
    // optional: wait for release while (ui8PressStatus == 1);
}
```

---

## State machine (Lab 6 + 7)

| `i8PageCounter` | Screen |
|-----------------|--------|
| `0` | Lock / time + unlock |
| `1` | Four app icons |

| Flag | Role |
|------|------|
| `bPagePrinted` | Icons drawn once |
| `bHomePagePrinted` | Home/time UI drawn once |
| `ui8PressStatus` | Push button (ISR toggles) |
| `bTouchStatus` | Touch event pending |

---

## MCQ hooks (digital input — Ch 2.2)

| Topic | Key point |
|-------|-----------|
| Digital input use | Sense open/closed (switch, contact) |
| Closed circuit | Current flows → reads **1** |
| Open circuit | No current → **0** |
| Pull-up input | Pin tied to VDD; switch to **GND** |
| Floating | High-impedance, undefined — avoid without pull-up/down |

See [[ege320-chapter-2-embedded-hardware-slides#Later sections (not eQuiz 1)|Ch 2 §2.2 digital input]] when studying for Lab Test 1.

---

## Full §1.3 source (vault)

Complete `main.c`: `99-ATTACHMENTS/EGE320/EGE320_E2/lab7/lab7_1.3/main.c`  
**CCS:** Import **Lab6_1.3** project → replace `main.c` → Build (F7) → Run (F8).

---

## Checklist

- [ ] 1.1 — `PushButtonIntRegister` + `ui8PressStatus == 1` on LCD
- [ ] 1.2 — exit torch app; LED off; `bPagePrinted = 0`
- [ ] 1.3 — home resets `i8PageCounter`, `bHomePagePrinted`, `bPagePrinted`
- [ ] Demo all three flows to instructor
