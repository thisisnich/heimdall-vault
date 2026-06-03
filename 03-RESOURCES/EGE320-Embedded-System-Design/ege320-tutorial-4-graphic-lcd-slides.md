---
type: tutorial
course: EGE320
module: EGE320-Embedded-System-Design
status: reviewed
source: pdf
created: 2026-06-03
tags: [EGE320, tutorial, LCD, graphic, MCQ]
---

> **Related:** [[07-DASHBOARDS/NYPY3 - Main Index|NYPY3 Index]] | [[ege320-tutorial-5-slides|Tutorial 5]] | [[07-DASHBOARDS/Schedule & Assessments Dashboard|Assessments]]

> **PDF:** [[99-ATTACHMENTS/EGE320/EGE320 - Tutorial4.pdf|EGE320 - Tutorial4.pdf]]

# EGE320 Tutorial 4 — LCD Screen

> [!ingest] source: EGE320 - Tutorial4.pdf | date: 2026-06-03 | tool: markitdown
> Auto-converted. Edit summary below; re-run ingest to replace block above.

## Summary

MCQs on **display** hardware: LCD as visual feedback, backlight, LCD types (graphic = true colour), RGB pixels, bit depth (24-bit true colour, 16-bit high colour, RGB565), diagonal size in inches, graphics system blocks (glass, controller, frame buffer — not touch controller), and frame-buffer size calculation.

---

## Answer key

| Q | Answer | One-line why |
|---|--------|----------------|
| 1 | **A** | **LCD** gives visual output; touch/button/keypad are input. |
| 2 | **A** | LCD images need a **backlight** (not frontlight/sun). |
| 3 | **C** | **Graphic LCD** supports full colour images. |
| 4 | **D** | Pixel RGB — **not white** (white is mixed from RGB). |
| 5 | **C** | 16M colours = 24 bpp total → **8 bits per channel** (24÷3). |
| 6 | **D** | **High colour** = 16 bpp per pixel. |
| 7 | **B** | 16-bit pixel → **5-6-5** RGB split. |
| 8 | **D** | Screen size quoted in **inches** (diagonal). |
| 9 | **A** | **Touch controller** is touch subsystem, not display graphics chain. |
| 10 | **D** | 240×240×24 bpp = 240×240×3 B = **172800 bytes**. |

---

## Questions

### Q1 — Visual feedback to users?

> ✅ **A — LCD Screen**

### Q2 — How LCD produces images?

> ✅ **A — Using backlight**

### Q3 — True colour LCD type?

> ✅ **C — Graphic LCD**

### Q4 — Three basic pixel colours EXCEPT?

> ✅ **D — White** (RGB are primaries)

### Q5 — 16 million colours, equal bits per R/G/B?

> ✅ **C — 8-bits** each (24 bpp ÷ 3)

### Q6 — Bits for High Color?

> ✅ **D — 16-bits** per pixel

### Q7 — Valid 16-bit colour scheme?

> ✅ **B — 5-6-5** (RGB565)

### Q8 — Diagonal LCD measurement unit?

> ✅ **D — inch**

### Q9 — NOT a graphics system hardware component?

> ✅ **A — Touch Controller** (belongs to touch path; graphics = glass + display controller + frame buffer)

### Q10 — Frame buffer: 240×240, 24 BPP?

\[
240 \times 240 \times (24/8) = 172\,800\ \text{bytes}
\]

> ✅ **D — 172800 bytes**

---

## Cheat-sheet lines

```
Visual out=LCD | backlight | true color=Graphic LCD
RGB not white | 16M=8b/ch | High color=16bpp | 16b=5-6-5
Size=inch | NOT touch ctrl in graphics chain
FB bytes = W×H×(bpp/8)
```
