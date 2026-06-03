---
type: tutorial
course: EGE320
module: EGE320-Embedded-System-Design
status: reviewed
source: manual
created: 2026-06-03
tags: [EGE320, eQuiz1, cheat-sheet, MCQ]
due: 2026-06-04
---

> **Assessment:** eQuiz 1 — 40 MCQ, 60 min, **one A4 sheet** (print this note at smallest readable font, both sides if allowed).  
> **Scope:** Labs 1–6, Ch 1 & Ch 2 **through Digital Output** (not digital input, analog, timers, UART, Ch 3).  
> **Sources:** [[tutorial1]] · [[EGE320 - Tutorial2]] · [[Tutorial 3 - Embedded System Programming II]] · [[ege320-tutorial-4-graphic-lcd-slides]] · [[ege320-tutorial-5-slides]] · [[ege320-tutorial-6-slides]] · [[EGE320-Chapter1]] · [[ege320-chapter-2-embedded-hardware-slides]]

# EGE320 eQuiz 1 — A4 Cheat Sheet

*Copy sections below onto one sheet. Test trace questions on paper — don’t memorize every hex outcome.*

---

## 1. Embedded system & tools (Tut 1 / Ch 1.1–1.2 / Lab 1)

| Trap question | Answer |
|---------------|--------|
| Embedded system definition | HW+SW, **specific** task, **limited** resources |
| Processor MAIN role | **Processes** data & instructions |
| Processor types | **MPU**, **MCU** (not ADC/SPI/PWM) |
| NOT on-chip peripheral | **Connector** |
| NOT on digital **input** | **LED** (output) |
| NOT serial interface | **ADC** |
| Buzzer tones | **PWM** |
| Accurate clock timing | **RTC** |
| Debug probe | Probe / trace / **control** target |
| IDE does NOT include | **Calculator** |

**Lab 1 / CCS:** Target `Tiva TM4C129ENCPDT` · probe `XDS100v2` · IDE = editor + compiler + assembler + **debugger**

---

## 2. C programming (Tut 2–3 / Ch 1.3 / Labs 2–3)

### Structure & symbols

| Item | Rule |
|------|------|
| **Mandatory** section | `main` |
| `&` | **Address of** |
| `*` | Pointer / dereference |
| Char `'A'` | `unsigned char` |
| Value **128** | `unsigned char` |
| Value **−129** | `signed short` |
| Array 5× `unsigned char` | `unsigned char name[5]` |

### Operators (quick)

| Op | Note |
|----|------|
| `&&` / `\|\|` | If-block **skipped** only when **both** conditions false |
| `uc--` from 0 | **0xFF** (unsigned wrap) |
| `~0x33` | **0xCC** |
| `0x3C &= 0x0F` | **0x0C** |
| `0x01 <<= 7` | **0x80** |
| `10/3`, `10%3` | **3**, **1** |

### Control flow

| Construct | Check |
|-----------|--------|
| `while` | Condition **before** loop |
| `do-while` | Body runs **≥1** time |
| `for` | Watch `i>0` vs `i>=0`; `break` exits |
| `switch` | **`break`** or fall-through; `default` optional |

**Trace templates**

```
while(i<5){ count+=2; i++; }     → count=8
do{ x/=3; }while(x!=0); x=10    → ends at 0
for(i=7;i>0;i--) uc>>=1; 0x80   → 0x01
factorial 5                     → 120
```

### Functions

| Topic | Answer |
|-------|--------|
| User-defined function name in call | Name of function (e.g. `findMax`) |
| Return type of `char Demo(...)` | **char** |
| Pass by **value** | Copy — **original unchanged** |
| Pass by **reference** | `*` + `&` — **original changes** |
| `square(&uiNum)` passes | **Address** of `uiNum` |
| Swap with pointers | Values **exchange** |

### Tut 2 answer key (Q1–10)

| Q | Ans |
|---|-----|
| 1 | D main |
| 2 | A unsigned char |
| 3 | A `unsigned char x[5]` |
| 4 | B address of |
| 5 | C ~0x33=0xCC |
| 6 | C 0x0C |
| 7 | A (0x0908) — verify calc if unsure |
| 8 | C 0xFF |
| 9 | A both 0 |
| 10 | C 0xF0 (case 8, fall-through default) |

### Tut 3 answer key (Q1–10)

| Q | Ans |
|---|-----|
| 1 | D count=8 |
| 2 | C 6× `i--` |
| 3 | A uiNumber=0 |
| 4 | D 24 never assigned |
| 5 | A 0x01 |
| 6 | D 120 |
| 7 | D findMax |
| 8 | C 84 |
| 9 | A char |
| 10 | B swapped 42/24 |

---

## 3. LCD & graphics (Tut 4 / Ch 2.1)

| Q topic | Ans |
|---------|-----|
| Visual feedback | **LCD** |
| How LCD shows image | **Backlight** |
| True / rich colour | **Graphic LCD** |
| Pixel primaries EXCEPT | **White** |
| 16M colours, equal R/G/B bits | **8** each (24÷3) |
| High colour bpp | **16** |
| 16-bit RGB scheme | **5-6-5** |
| Diagonal size unit | **inch** |
| NOT graphics HW component | **Touch controller** |
| FB 240×240 @ 24 bpp | **172800** B |
| FB formula | `W×H×(bpp/8)` |
| QVGA 320×240 @ 16 bpp (Ch2) | **153600** B |

**Graphics chain:** display **glass** → **controller** ← **frame buffer** ← **MCU**  
**GrLib:** display driver sets **pixel colour** · Lab LCD: **ST7789**

---

## 4. Touchscreen (Tut 5 / Ch 2.1 / Lab 5)

| Q | Ans |
|---|-----|
| Layer on LCD | **On top** |
| NOT sensing tech | **Inductive** |
| Spacer dots | Gap when **NOT pressed** |
| X1=0,X2=5V, read position | **Y electrode** |
| Touch near X2 (5V) | **~4 V** |
| Centre touch 0–5V | **2.5 V** |
| PCT best environment | **Clean, dry**, bare finger |
| PCT electrode layout | **Matrix intersect** |
| Finger effect | Adds **capacitance** |
| Touch controller role | **Sensor → MCU data** |
| Multi-touch | **Capacitive** |
| Fewer electrodes | **Resistive** |
| NOT touch HW | **Display controller** |

**Lab 5:** Touch **IT7258** (I2C) · `IT7258IntRegister` · `IT7258GetTouchPointData` · stack **1024**

---

## 5. Digital output (Tut 6 / Ch 2.2 / Lab 6)

| Q | Ans |
|---|-----|
| Valid HIGH @ 3.3V | **~3.29 V** |
| NOT digital output load | **Temp sensor** (input) |
| LED current | `I=(Vout−Vled)/R` → **9.55 mA** (3.3−1.2)/220 |
| R for 3 mA LED | **833 Ω** (3.3−0.8)/0.003 |
| Transistor on motor | **Higher current** for motor |
| Output type name | **Open-collector/drain** |
| Source **and** sink | **Push-pull** |
| Open-drain, transistor OFF | **High-Z** |
| Open-drain advantage | **Shared bus** + pull-up |
| Push-pull advantage | **Fast**, drives both ways |
| Faster switching (Ch2) | **Push-pull** |
| Two push-pull, opposite levels tied | **Damage transistors** |

| Level | Voltage |
|-------|---------|
| HIGH `1` | ≈ **VDD** |
| LOW `0` | ≈ **0 V** |

**Lab 6:** **RGBLED** / GPIO · high-side ON = logic **1** ≈ VDD

---

## 6. Formula & mnemonic strip (edge of sheet)

```
FB = W×H×(bpp/8)     LED: I=(Vout-Vled)/R  R=(Vout-Vled)/I
&=addr  *=ptr  main mandatory  uc--@0→FF  both0→skip if(||)
Touch ON LCD | spacer=not pressed | drive X read Y | centre 2.5V
PCT=clean finger +C | touch IC→MCU | NOT disp ctrl in touch HW
Push-pull: fast, src+sink, NO tie | Open-drain: sink, Hi-Z, pull-up, bus OK
```

---

## 7. Out of scope (skip tonight)

Digital **input**, pull-up/down · Analog / PWM / DAC / ADC · Clocks / RTC · UART · [[EGE320-Chapter3_v2|Ch 3 RTOS]] · Tutorial 7+

---

## Print tips

- Font **7–8 pt**, 3 columns, margins minimal.
- **Side 1:** §1–3 (tools + C). **Side 2:** §4–6 (LCD/touch/GPIO).
- Allowed: one A4 — confirm with invigilator if **both sides** OK.

---

*Good luck — trace any `switch`/`while` question for 30s before picking.*
