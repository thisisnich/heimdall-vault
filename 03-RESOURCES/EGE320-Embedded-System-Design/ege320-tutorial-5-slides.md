---
type: tutorial
course: EGE320
module: EGE320-Embedded-System-Design
status: draft
source: pdf
created: 2026-05-21
tags: [EGE320, tutorial, touchscreen, MCQ]
---

> **Related:** [[07-DASHBOARDS/NYPY3 - Main Index|NYPY3 Index]] | [[EGE320 - Touch Screen Technology|Touch Screen Lesson]] | [[ege320-lab-5-touchscreen-interaction-slides|Lab 5]] | [[07-DASHBOARDS/Schedule & Assessments Dashboard|Assessments]]

> **PDF:** [[99-ATTACHMENTS/EGE320/EGE320 - Tutorial5.pdf]]

# EGE320 Tutorial 5 — Touchscreen Panel

> [!ingest] source: EGE320 - Tutorial5.pdf | date: 2026-05-21 | tool: markitdown
> Auto-converted. Edit summary below; re-run ingest to replace block above.

## Summary

MCQ tutorial on touchscreen hardware: panel layering on LCD, sensing technologies (resistive, capacitive, infrared), spacer dots in resistive panels, voltage measurement at touch points, projected capacitive environments, and touch controller role between sensor and MCU.

**Objective:** Describe touch system hardware components and the purpose of each.

---

## Questions

### Q1 — How is a touchscreen layered with an LCD?

- A. Layered **on top** of the LCD screen
- B. Layered at the bottom of the LCD screen
- C. Layered in between the LCD screen
- D. Layered both top and bottom of the LCD screen

### Q2 — Which is NOT a touchscreen sensing technology?

- A. Resistive
- B. Capacitive
- C. Inductive
- D. Infrared

### Q3 — What is the spacer dot used for in resistive touch (ITO sheets)?

- A. Prevent top/bottom sheets contacting **when pressed**
- B. Prevent top/bottom sheets contacting **when not pressed**
- C. Perform resistive sensing by measuring voltages
- D. Fill the gap between sheets

### Q4 — Touch point voltage measured with X1 (0 V) and X2 (5 V) on top sheet?

- A. Through electrode X1
- B. Through electrode X2
- C. Through spacer dot
- D. Through electrode Y

### Q5 — Touch point nearer to X2 — expected voltage? (X1=0 V, X2=5 V)

- A. 1 V · B. 2 V · C. 3 V · D. 4 V

### Q6 — Projected capacitive sensing best suited for?

- A. Wet or underwater
- B. High-vibration industrial
- C. Dusty environments
- D. **Clean, dry environments with bare-finger touch**

### Q7 — Center of resistive panel touched (max 5 V on electrodes)?

- A. 1.5 V · B. **2.5 V** · C. 3.5 V · D. 4.5 V

### Q8 — X and Y electrodes in projected capacitive structure?

- A. Parallel · B. Series · C. **Intersecting in matrix** · D. Series X / parallel Y

### Q9 — How does a finger affect projected capacitive sensing?

- A. **Introduces additional capacitance**
- B. Introduces additional resistance
- C. Introduces additional inductance
- D. Introduces additional pressure

### Q10 — Role of touch controller (between sensor and MCU)?

- A. Captures voltage/signal change on panel
- B. Lets driver code interpret touch events
- C. **Translates sensor info into data the MCU understands**
- D. Fetches/decodes frame buffer data for MCU

---

## Study links

- [[EGE320 - Touch Screen Technology#Resistive Touch Screen|Resistive vs capacitive]]
- [[ege320-lab-5-touchscreen-interaction-slides#IT7258 API|Lab 5 — IT7258 driver]]
