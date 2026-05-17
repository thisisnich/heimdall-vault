---
tags:
  - EGE351
  - automation
  - PLC
  - lab
  - ladder-diagram
  - lab1
  - I/O-addressing
course: EGE351 Automation Systems & Control
lab: 1
topic: PLC Programming — I/O Addressing and Ladder Logic
submitted: 2026-04-22
source: NYPY3 Import
created: 2026-05-17
type: Lab
status: Completed
---

> 📚 **Related:** [[NYPY3 - Main Index|NYPY3 Index]] | [[03-RESOURCES/EGE351-Automation-Systems-Control/Lecture_1_PLC.md|Lecture 1: PLC Theory]] | [[📅 Schedule & Assessments Dashboard|Assessment Dashboard]]

# EGE351 / LAB 1 — Automation: PLC Programming

**School of Engineering**
**Course:** Diploma in Electronic and Computer Engineering
**Module:** EGE351 Automation Systems & Control

|                               |                              |
| ----------------------------- | ---------------------------- |
| **Name:** Nicholas Dubs       | **Module Group:** ???        |
| **Team Members:** Doris and e | **Date Submitted:** 22/04/26 |

---

**Experiment No.:** EGE351 / LAB 1
**Experiment Title:** Automation – PLC Programming

**Objectives:**
- a) Know the different modules of the PLC
- b) Understand how to get the address of input/output devices

**Equipment:** Programmable Logic Controller PLC FP7

**Components:** Input/Output devices

---

## a) Know the Different Modules of the PLC

Listen to the lecturer's presentation on the key features of the programmable logic controller (PLC) and the input/output devices. Take note how to start the PLC software.

### PLC

The PLC is made of the following modules:

- Power supply (AC to DC)
- CPU
- Input module
- Output module
- Analog module (not used now)

---

## b) Understand How to Get the Address of Input/Output Devices

### Addressing Scheme of Input Module

Whenever an input device is activated, a small indicator lights up on the input module which allows you to know the address of that input device. **"X" represents input.**

**AFP7X32D2 / X32D2**

> Address range on module: X100 (top-left) → X107 (top-right) → X110 (bottom-left) → X11F (bottom-right)

**Task:** Find the address of all the input devices and record in the table below.

---

### Addressing Scheme of Output Module

Write the program below in the PLC and note what happens.

```
     X103                                                        Y120
|-----||----------------------------------------------------------( )
     Input                                                      Output
```

Whenever the input device **X103** (a normally-open pushbutton) is activated, the ladder program (or PLC program) activates the output **Y120** which is an LED. At the same time a small indicator lights up on the output module which allows you to know the address of that output device. **"Y" represents output.**

**AFP7Y32T / Y32T**

> Address range on module: Y120 (top-left) → Y127 (top-right) → Y130 (bottom-left) → Y13F (bottom-right)

**Task:** Find the address of all the output devices and record in the table below.

---

## Input/Output Address Listing

Inputs and outputs connected to the PLC.

| INPUT Device | PLC Address | OUTPUT Device | PLC Address |
|---|---|---|---|
| PB1 | | LED1 | |
| PB2 | | LED2 | |
| PB3 | | LED3 | |
| PB4 | X100 | LED4 | Y120 |
| SW1 | | Relay1 | |
| SW2 | | Relay2 | |
| SW3 | | Relay3 | |
| SW4 | | Relay4 | |
| Sensor1 | | | |
| Sensor2 | | | |
| Sensor3 | | | |
| Sensor4 | | | |
| E-Stop PB | | | |

**Task:** Find out which input devices are normally-open type and which are normally-closed type.

**Task:** Find out what activating each relay does to the left and right gantry.

---

## Programming the PLC

1. Find out the addresses of the inputs (pushbuttons, toggle switches & sensors)

use the display table/showing at the PLC -> the displa -> shows buttons pressed etc


2. Activate the output addresses to identify all the outputs (LEDs, relays)
yes
3. Write a PLC program to **ON the green LED** when Sensor 1 is activated. Reset the LED by pressing PB1.

internal relay
R (ro)
R1
r2
r3

Can be used as "inputs" nad set as "outputs"

latching circuite : DRAW DIAGRAM HERE

button (x???) ------------------------ ( R3 )
| R3 | --button(inverse) (X???)---^ (R3 is input parallele to button, so latching)

| R3 | -------------------------------- (Y???)


4. Write a PLC program to **blink the red LED** when Sensor 4 is activated. Reset the blinking LED by pressing PB4.
   MAKE TABLE \\/
Use timers -> SR13 (abt 10 Hz) -> first cycle bit
flash/blink bit = SR1A frequency = 10Hz
flash/blink bit = SR1B frequency = 5Hz
flash/blink bit = SR1C frequency = 1Hz
flash/blink bit = SR1D frequency = 0.5Hz (USE TIMER LIKE INPUTS)

x


---

## Understanding

**Briefly explain the difference between using PB1 and PB4 to reset the LED.**

_Answer:_ _______________________________________________

_______________________________________________

**Activate Relays 1 to 4 and note what it does to the gantries:**

_Answer:_ _______________________________________________

_______________________________________________

