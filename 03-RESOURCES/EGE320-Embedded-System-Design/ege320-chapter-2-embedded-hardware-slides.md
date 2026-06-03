---
type: lecture
course: EGE320
module: EGE320-Embedded-System-Design
status: reviewed
source: pdf
created: 2026-06-03
tags: [EGE320, chapter-2, LCD, touchscreen, digital-output, GPIO]
---

> **Related:** [[ch0|Chapter 0]] | [[EGE320-Chapter1|EGE320-Chapter1]] | [[ege320-tutorial-4-graphic-lcd-slides|Tut 4]] | [[ege320-tutorial-5-slides|Tut 5]] | [[ege320-tutorial-6-slides|Tut 6]] | [[07-DASHBOARDS/Schedule & Assessments Dashboard|Assessments]]

> **PDF:** [[99-ATTACHMENTS/EGE320/EGE320-Chapter2 v2-1.pdf|EGE320-Chapter2 v2-1.pdf]]

# Chapter 2 — Embedded System Hardware

> [!ingest] source: EGE320-Chapter2 v2-1.pdf | date: 2026-06-03 | tool: markitdown
> Auto-converted. Edit summary below; re-run ingest to replace block above.

## Summary

Chapter 2 covers embedded **I/O hardware**: LCD graphics stack (pixels, colour depth, frame buffer), touchscreen technologies (resistive 4-wire, projected capacitive, touch controller), and **digital GPIO** (logic levels, LED/motor drive, push-pull vs open-drain). **eQuiz 1 scope stops at §2.2 Digital Output** — §2.2 digital *input* and §2.3+ are later weeks.

---

## eQuiz 1 scope (Week 7)

| In scope | Out of scope (this quiz) |
|----------|---------------------------|
| §2.1 LCD + touch | §2.2 digital **input**, pull-up/down |
| §2.2 **Digital output** + output types | §2.3 analog, §2.4 clocks, §2.5 UART |

---

## 2.1 LCD screen and touch panel

### LCD basics

- LCD uses **liquid crystals** + **backlight** (or reflector) — crystals do **not** emit light.
- Types: **Segment**, **Dot matrix**, **Graphic** (rich colour images).

### Pixels and colour

| Term | Meaning |
|------|---------|
| **True colour** | 24 bpp → 8 bits per R/G/B → **16M** colours (2²⁴) |
| **High colour** | **16 bpp** → 64K colours (2¹⁶) |
| 16-bit schemes | **5-6-5** (R,G,B) or **T-1-5-5-5** |
| Resolution | e.g. 320×240 = 320 columns × 240 rows |
| Diagonal size | **Inches** |

### Graphics system (4 components)

1. **Display glass** — pixels; no memory; must be refreshed or blank
2. **Display controller** — reads frame buffer, decodes, drives glass
3. **Frame buffer** (RAM) — holds pixel data

\[
\text{Frame buffer (bytes)} = \text{pixels} \times \frac{\text{BPP}}{8}
\]

Example (slides): QVGA 320×240 @ **16 BPP** → 320×240×16/8 = **153600 bytes**

4. **Microcontroller** — application writes frame buffer

**Not** in graphics chain: **touch controller** (touch subsystem).

### Graphics library

- Vendor library; minimum need: **display driver** (set pixel colour). Lab: **GrLib**.

### Touch panel

- Thin panel **layered on top of LCD**
- Technologies: **Resistive**, **Capacitive**, **SAW**, **Infrared**

#### Resistive (4-wire)

- Top + bottom **ITO** sheets; **spacer dots** on bottom → **no contact when not pressed**
- **X electrodes** on top (vertical direction); **Y** on bottom (horizontal)
- Drive **X1=0 V, X2=5 V** on top → centre touch → **2.5 V** read on **Y** electrode
- Then drive Y axis; read on X — gets (x, y)
- **Single-touch**; works with finger/stylus

#### Projected capacitive

- X/Y on two glass layers, **intersecting matrix**
- Finger changes **capacitance** between electrodes
- **Multi-touch**; needs clean/dry conductive touch

#### Touch system (3 components)

| Part | Role |
|------|------|
| Touch **sensor** | Panel; touch changes voltage/signal |
| Touch **controller** | **Translates** sensor → data MCU understands |
| **MCU** | Driver interprets touch events |

Display controller ≠ touch controller.

### Chapter 2.1 checkpoint (slide answers)

| Q | Answer |
|---|--------|
| Rich colour LCD? | **C — Graphic LCD** |
| Pixels 240×320? | **A — 76800** (240×320) |
| Why frame buffer? | **B — Holds data to be shown** |
| Multi-touch? | **B — Capacitive** |
| Uses **fewer** electrodes for position? | **A — Resistive** |
| NOT touch hardware? | **C — Display controller** |

---

## 2.2 Digital output (eQuiz scope)

### Logic levels

| Level | Pin voltage |
|-------|-------------|
| **High (1)** | ≈ **VDD** |
| **Low (0)** | ≈ **0 V** |

- Drive **LED / vibrator** (high-side): **HIGH** ≈ VDD to turn on
- Active-low LED: **LOW** ≈ 0 V to turn on

High-current loads: use **transistor** or relay — GPIO does not supply motor current directly.

### Output types

| | **Push-pull** | **Open-collector / drain** |
|---|---------------|----------------------------|
| Drive | **Sources and sinks** | **Sinks only**; HIGH = **high-Z** |
| Speed | **Faster** (active both ways) | Slower (RC + pull-up) |
| Tie outputs together? | **No** — fight → damage | **Yes** (wired bus) |
| Pull-up | Not required | **Required** for HIGH |

**Open-drain** when: shared bus, different voltage pull-up, multiple devices on one line (e.g. I²C-style).

**Push-pull** when: need fast edges, single driver, no shared line.

### Chapter 2.2 digital output checkpoint (slides)

| Q | Answer |
|---|--------|
| Faster switching? | **A — Push-pull** |
| Two push-pull outputs, opposite levels tied? | **B — Transistors can be damaged** |

---

## Key figures (eQuiz)

![[99-ATTACHMENTS/EGE320/ege320-chapter-2-embedded-hardware/ege320-chapter-2-embedded-hardware-p11.png|Graphics system components]]

![[99-ATTACHMENTS/EGE320/ege320-chapter-2-embedded-hardware/ege320-chapter-2-embedded-hardware-p27.png|Resistive 4-wire sensing]]

![[99-ATTACHMENTS/EGE320/ege320-chapter-2-embedded-hardware/ege320-chapter-2-embedded-hardware-p34.png|Touch system components]]

![[99-ATTACHMENTS/EGE320/ege320-chapter-2-embedded-hardware/ege320-chapter-2-embedded-hardware-p45.png|Push-pull output]]

![[99-ATTACHMENTS/EGE320/ege320-chapter-2-embedded-hardware/ege320-chapter-2-embedded-hardware-p46.png|Open-collector drain]]

![[99-ATTACHMENTS/EGE320/ege320-chapter-2-embedded-hardware/ege320-chapter-2-embedded-hardware-p47.png|Push-pull vs open-drain comparison]]

---

## A4 cheat-sheet block (Ch 2 only)

```
LCD: backlight | Graphic=true color | 24b=8/ch | 16b=high,5-6-5
FB bytes = W×H×(bpp/8) | glass+ctrl+FB+MCU (NOT touch ctrl)
Touch ON LCD | spacer=gap when NOT pressed
4-wire: drive X read Y | centre=2.5V
PCT: matrix | finger=C | multi-touch=cap
Touch IC: sensor→MCU
GPIO HIGH≈VDD LOW≈0 | LED high-side=1
Push-pull: fast, source+sink, NO tie together
Open-drain: sink only, Hi-Z high, pull-up, bus OK
```

---

## Later sections (not eQuiz 1)

§2.2 digital input, §2.3 analog/PWM/DAC, §2.4 clocks/RTC, §2.5 UART — see full PDF. Re-run `ingest.py pdf` to restore full figure list + raw dump if needed.
