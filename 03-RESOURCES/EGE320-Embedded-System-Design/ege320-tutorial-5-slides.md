---
type: tutorial
course: EGE320
module: EGE320-Embedded-System-Design
status: reviewed
source: pdf
created: 2026-05-21
tags: [EGE320, tutorial, touchscreen, MCQ]
---

> **Related:** [[07-DASHBOARDS/NYPY3 - Main Index|NYPY3 Index]] | [[EGE320 - Touch Screen Technology|Touch Screen Lesson]] | [[ege320-lab-5-touchscreen-interaction-slides|Lab 5]] | [[ege320-tutorial-4-graphic-lcd-slides|Tutorial 4]] | [[07-DASHBOARDS/Schedule & Assessments Dashboard|Assessments]]

> **PDF:** [[99-ATTACHMENTS/EGE320/EGE320 - Tutorial5.pdf|EGE320 - Tutorial5.pdf]]

# EGE320 Tutorial 5 — Touchscreen Panel

> [!ingest] source: EGE320 - Tutorial5.pdf | date: 2026-06-03 | tool: markitdown
> Auto-converted. Edit summary below; re-run ingest to replace block above.

## Summary

Ten MCQs on touchscreen **hardware**: panel placement on LCD, sensing types (resistive / capacitive / infrared), resistive spacer dots and voltage-divider position sensing, projected-capacitive environment and matrix layout, finger capacitance, and the touch controller’s role vs the display path. Answers below match standard EGE320 lecture/lab wording (not an official published key).

**Objective:** Describe touch system hardware components and the purpose of each.

---

## Answer key

| Q | Answer | One-line why |
|---|--------|----------------|
| 1 | **A** | Touch panel sits **on top** of the LCD (user faces touch layer first). |
| 2 | **C** | Resistive, capacitive, infrared are real types; **inductive** is not used here. |
| 3 | **B** | Spacer dots keep layers **apart when not pressed**; press brings sheets together. |
| 4 | **D** | Drive X on top sheet; read position voltage via **Y electrode** (other layer). |
| 5 | **D** | Nearer X2 (5 V) → measured voltage **closer to 5 V** (~4 V). |
| 6 | **D** | Projected cap needs **clean, dry** surface and conductive finger. |
| 7 | **B** | Centre of 0–5 V divider → **2.5 V** on both axes at centre. |
| 8 | **C** | PCT uses **intersecting X/Y matrix** (multi-touch grid). |
| 9 | **A** | Finger adds **capacitance** to the electrostatic field. |
| 10 | **C** | Touch IC **translates sensor data** into form the MCU can use. |

---

## Questions (with explanations)

### Q1 — How is a touchscreen layered with an LCD?

- A. Layered **on top** of the LCD screen
- B. Layered at the bottom of the LCD screen
- C. Layered in between the LCD screen
- D. Layered both top and bottom of the LCD screen

> ✅ **Answer: A** — The touch layer is the outer interface; the LCD stack is underneath for display.

---

### Q2 — Which is NOT a touchscreen sensing technology?

- A. Resistive
- B. Capacitive
- C. Inductive
- D. Infrared

> ✅ **Answer: C** — Course covers resistive, capacitive (surface + projected), SAW/infrared-style sensing; not inductive coupling.

---

### Q3 — Spacer dots between ITO sheets (resistive)?

- A. Prevent contact **when pressed**
- B. Prevent contact **when not pressed**
- C. Perform resistive sensing by measuring voltages
- D. Fill the gap between sheets

> ✅ **Answer: B** — Dots maintain a small gap so layers stay open until the user presses; then sheets touch at the press point.

---

### Q4 — Touch voltage with X1 = 0 V, X2 = 5 V on top sheet?

- A. Through electrode X1
- B. Through electrode X2
- C. Through spacer dot
- D. Through electrode Y

> ✅ **Answer: D** — **4-wire resistive** method: impose voltage on one axis (here X on top sheet), read the divider voltage at the touch point through the **other layer’s electrode** (Y) while the sheets are in contact.

---

### Q5 — Touch point nearer to X2 (X1 = 0 V, X2 = 5 V)?

- A. 1 V · B. 2 V · C. 3 V · D. 4 V

> ✅ **Answer: D** — Voltage along the sheet follows a linear divider between X1 and X2; closer to the **5 V** end → **higher** reading (~4 V, not 1–2 V).

---

### Q6 — Projected capacitive best suited for?

- A. Wet or underwater
- B. High-vibration industrial
- C. Dusty environments
- D. Clean, dry environments with bare-finger touch

> ✅ **Answer: D** — Needs stable electrostatic field and conductive touch (finger); water/dust/gloves degrade or false-trigger sensing.

---

### Q7 — Centre of resistive panel touched (max 5 V on electrodes)?

- A. 1.5 V · B. 2.5 V · C. 3.5 V · D. 4.5 V

> ✅ **Answer: B** — Geometric centre = midpoint of the divider → **2.5 V** (same idea on X and Y when each axis is driven to 5 V max).

---

### Q8 — X and Y electrodes in projected capacitive structure?

- A. Parallel · B. Series · C. Intersecting in matrix · D. Series X / parallel Y

> ✅ **Answer: C** — PCT uses a **grid/matrix** of rows and columns; intersection locates touch (multi-touch).

---

### Q9 — How does a finger affect projected capacitive sensing?

- A. Introduces additional **capacitance**
- B. Introduces additional resistance
- C. Introduces additional inductance
- D. Introduces additional pressure

> ✅ **Answer: A** — Body capacitance couples to the grid and **changes** the local capacitance the controller detects (not pressure-based).

---

### Q10 — Role of touch controller (between sensor and MCU)?

- A. Captures voltage/signal change on panel
- B. Lets driver code interpret touch events
- C. **Takes info from touch sensor and translates it for the MCU**
- D. Fetches/decodes frame buffer for MCU

> ✅ **Answer: C** — Hardware controller (e.g. **IT7258** in Lab 5) processes raw sensor signals and outputs coordinates/status the MCU reads. (A is panel-level physics; B is software driver job; D is **display** controller / frame buffer path.)

---

## Study links

- [[EGE320 - Touch Screen Technology#Resistive Touch Screen|Resistive vs capacitive]]
- [[ege320-lab-5-touchscreen-interaction-slides#IT7258 API|Lab 5 — IT7258 driver]]

## Cheat-sheet lines (copy to A4)

```
Touch on TOP of LCD | NOT inductive
Spacer: gap when NOT pressed
Resistive: drive X, read Y | centre=2.5V, near 5V end≈4V
PCT: clean/dry finger | matrix X∩Y | finger adds C
Touch IC: sensor → MCU data (not framebuffer)
```
