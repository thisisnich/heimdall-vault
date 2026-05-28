---
type: tutorial
course: EGE320
module: EGE320-Embedded-System-Design
status: reviewed
source: pdf
created: 2026-05-28
tags: [EGE320, tutorial, digital-output, GPIO]
---

# EGE320 Tutorial 6 — Digital Output and Input

> [!ingest] source: EGE320 - Tutorial6.pdf | date: 2026-05-28 | tool: markitdown
> Auto-converted. Edit summary below; re-run ingest to replace block above.

**PDF:** [[99-ATTACHMENTS/EGE320/EGE320 - Tutorial6.pdf|EGE320 - Tutorial6.pdf]]

## Summary

Tutorial 6 MCQs on **digital outputs**: valid logic levels (3.3 V VDD), suitable loads (LED, fan, lock vs sensor), LED current/resistor calculations, transistor purpose for motors, output types (open-collector/drain vs push-pull), and advantages of each. Aligns with Lab 6 digital output week.

## Figures

![[99-ATTACHMENTS/EGE320/ege320-tutorial-6/ege320-tutorial-6-p01.png|Page 1 — Q3 LED circuit]]

![[99-ATTACHMENTS/EGE320/ege320-tutorial-6/ege320-tutorial-6-p02.png|Page 2 — Q4–Q5 circuits]]

## Questions

### 1. Valid digital output voltage (VDD = 3.3 V)

| | Option |
|---|--------|
| A | 3.29 V |
| B | 2.80 V |
| C | 1.65 V |
| D | 0.80 V |

> ✅ **Answer: A** — At VDD = 3.3 V, a valid **HIGH** is ≈ VDD (~3.29 V). The others are not proper logic-1 levels (too low or mid-rail).

---

### 2. NOT suitable to control with digital output

| | Option |
|---|--------|
| A | LED light bulb |
| B | Portable fan |
| C | Smart door lock |
| D | Temperature sensor |

> ✅ **Answer: D** — A temperature sensor is an **input** device (MCU reads it). Digital **output** drives actuators/loads (LED, fan, lock).

---

### 3. LED current (Dout = 3.30 V, VLED = 1.20 V)

![[99-ATTACHMENTS/EGE320/ege320-tutorial-6/ege320-tutorial-6-p01.png|LED circuit — page 1]]

| | Option |
|---|--------|
| A | 5.46 mA |
| B | 9.55 mA |
| C | 15 mA |
| D | 20.46 mA |

> ✅ **Answer: B** — From circuit: R = 220 Ω.  
> \(I = \dfrac{V_{Dout} - V_{LED}}{R} = \dfrac{3.30 - 1.20}{220} = 9.55\ \text{mA}\)

---

### 4. R1 for 3 mA LED (Dout = 3.30 V, VLED = 0.8 V)

![[99-ATTACHMENTS/EGE320/ege320-tutorial-6/ege320-tutorial-6-p02.png|LED + transistor circuits — page 2]]

| | Option |
|---|--------|
| A | 266.67 Ω |
| B | 833.33 Ω |
| C | 1.10 kΩ |
| D | 1.37 kΩ |

> ✅ **Answer: B** — \(R_1 = \dfrac{V_{Dout} - V_{LED}}{I} = \dfrac{3.30 - 0.8}{0.003} = 833.33\ \Omega\)

---

### 5. Purpose of transistor in motor drive circuit

| | Option |
|---|--------|
| A | Isolate external circuit from MCU |
| B | Protect MCU from short circuit |
| C | Allow higher current to drive motor |
| D | Increase component count |

> ✅ **Answer: C** — GPIO pins source/sink limited current; the transistor **switches the motor load** so the MCU does not drive motor current directly.

---

### 6. Digital output type

| | Option |
|---|--------|
| A | Open-collector / drain |
| B | Pull-up |
| C | Pull-down |
| D | Floating |

> ✅ **Answer: A** — **Open-collector/drain** and **push-pull** are output topologies. Pull-up/pull-down are resistor configs; floating is a high-Z state.

---

### 7. Can sink and source current

| | Option |
|---|--------|
| A | Open-collector / drain |
| B | Pull-up |
| C | Pull-down |
| D | Push-pull |

> ✅ **Answer: D** — **Push-pull** has two transistors and can drive the line **HIGH (source)** and **LOW (sink)**. Open-drain only pulls low; needs external pull-up for high.

---

### 8. Open-collector/drain when internal transistor is OFF

| | Option |
|---|--------|
| A | Sinks current to internal ground |
| B | Sources current from internal supply |
| C | Open (high impedance) |
| D | Closed, shorted to ground |

> ✅ **Answer: C** — Transistor OFF → line is **not driven** → high impedance (floating until pull-up defines HIGH).

---

### 9. Advantage of open-drain over push-pull

| | Option |
|---|--------|
| A | Multiple devices share line; external pull-up sets voltage |
| B | Fast switching, driven both ways |
| C | No pull-up required |
| D | Several outputs cannot be tied together |

> ✅ **Answer: A** — Wired-OR / shared bus (e.g. I²C): multiple open-drain outputs can tie together safely with one pull-up.

---

### 10. Advantage of push-pull over open-drain

| | Option |
|---|--------|
| A | Pulled up to any system voltage |
| B | Fast switching, driven both ways by transistors |
| C | Pull-up resistor required |
| D | Several device outputs can be tied together |

> ✅ **Answer: B** — Push-pull **actively drives** HIGH and LOW → faster edges, no external pull-up needed for switching speed.

---

## Quick reference

| Topic | Key point |
|-------|-----------|
| LED current | \(I = (V_{Dout} - V_{LED}) / R\) |
| Limit resistor | \(R = (V_{Dout} - V_{LED}) / I_{target}\) |
| Open-drain | Sinks only; HIGH via external pull-up; bus-friendly |
| Push-pull | Sources and sinks; faster; do not tie outputs together |
