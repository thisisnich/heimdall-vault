---
tags:
  - EGE351
  - lab
  - PLC
  - combination-logic
  - lab5
  - sequential-logic
course: EGE351 Automation Systems & Control
topic: Lab 5 - Combination Logic 3
source: 23S2 EGE351 Lab 5 - Automation_v1 .pdf
converted: 2026-05-19
type: Lab
status: Completed
---

> 📚 **Related:** [[NYPY3 - Main Index|NYPY3 Index]] | [[03-RESOURCES/EGE351-Automation-Systems-Control/23S2 EGE351 Lab 4 - Automation .md|Lab 4]] | [[📅 Schedule & Assessments Dashboard|Assessment Dashboard]]

> **Lab Materials:**
> - 📄 [[Lab 5 - Automation.pdf|PDF Document]]

---

Official (Open)

School of Engineering

Course: Diploma in Electronic and Computer Engineering

Module: EGE351 Automation Systems & Control

**Name:**

**Team Members:**

**Module Group:**

**Date Submitted:**

---

# EGE351 / LAB 5

**EXPERIMENT TITLE:** Combination Logic 3

## Objectives

- a) Understand and apply PLC combination logic program
- b) Understand and apply a PLC Counter

## Equipment

Programmable Logic Controller PLC FP7

## Components

Input/Output devices

---

## Write and test the following PLC programs

### Question 1

A PLC is used to control a pusher system. The pusher pushes objects into a container. When an object arrives, sensor 1 detects the object. A pusher cylinder extends to push the object into the container. After 3 seconds the pusher cylinder retracts to its home position. After 8 objects are pushed into the container, a red LED lights up to alert operator to collect the objects in the container. Use limit switches, SW1 and SW2 to detect fully extended and retracted positions of the pusher cylinder respectively. A RESET PB (NC) is also used to reset the counter.

```
Pusher Cylinders
     ↓
Container to collect objects
```

**Solution:**

```
Rung 1:
|--[X111]--[ ]--------------------------------------(R1)--|
|                                                        |
+--[R1]--[/T1]------------------------------------- |

Rung 2:
|--[R1]--------------------------------------------(Y124)--|

Rung 3:
|--[R1]--[X107]--------------------------[TMY1 | U3]--|

Rung 4:
|--[/R1]------------------------------------------(Y125)--|

Rung 5:
|--[R2]--[X106]-------------------------------------[CT1]--|
|--[/X100]--------------------------------------------[U8 ]--|

Rung 6:
|--[C1]--------------------------------------------(Y120)--|

Rung 7:
|--[T1]-------------------+-------------------------------(R2)--|
                                               |
|--[R2]--[/X106]--------|
```

### Question 2

A PLC is used to control a display light system. Write a program to simulate the display lights. When a START (NO) pushbutton is pressed, the LEDs below cycle through the steps:

1. a red LED blinks for 5 seconds, then
2. a green LED blinks for 3 seconds, then
3. a blue LED blinks for 5 seconds, followed by
4. an amber LED blinks for 3 seconds

The above cycle continues until a STOP (NC) pushbutton is pressed, and all the above LEDs are turned off.

**Solution:**

```
Rung 1:
|--[X103]--[/R2]--[/R3]--[/R4]--+----------------(R1)--|
                                 |
|--[R1]--[/T1]--[X100]----------+
                                 |
|--[T4]--------------------------+

Rung 2:
|--[R1]-----------------------------[TMY1 | U5]--|

Rung 3:
|--[R1]--[SR1B]----------------------------------(Y120)--|

Rung 4:
|--[T1]--------------------------+-------------(R2)--|
                                 |
|--[R2]--[/T2]--[X100]----------+

Rung 5:
|--[R2]-----------------------------[TMY2 | U3]--|

Rung 6:
|--[R2]--[SR1B]----------------------------------(Y122)--|

Rung 7:
|--[T2]--------------------------+-------------(R3)--|
                                 |
|--[R3]--[/T3]--[X100]----------+

Rung 8:
|--[R3]-----------------------------[TMY3 | U4]--|

Rung 9:
|--[R3]--[SR1B]----------------------------------(Y123)--|

Rung 10:
|--[T3]--------------------------+-------------(R4)--|
                                 |
|--[R4]--[/T4]--[X100]----------+

Rung 11:
|--[R4]-----------------------------[TMY4 | U3]--|

Rung 12:
|--[R4]--[SR1B]----------------------------------(Y121)--|
```

### Question 3

When PB1 is pressed 3 times, a green LED turns on. When PB1 is pressed 5 times, an amber LED turns on. When PB1 is pressed 7 times, a red LED turns on. After this, a right gantry is raised. 3 seconds later, the gantry is lowered and all LEDs are turned off.

---

*Effective Date: 16 Oct 2023*

