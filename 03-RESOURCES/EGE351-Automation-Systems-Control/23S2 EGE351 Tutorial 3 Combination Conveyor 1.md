---
tags:
  - EGE351
  - tutorial
  - PLC
  - combination-logic
  - tutorial-3
  - conveyor-system
course: EGE351 Automation Systems & Control
topic: Tutorial 3 - Combination Conveyor 1
source: 23S2 EGE351 Tutorial 3 Combination Conveyor 1.pdf
converted: 2026-05-05
type: Tutorial
status: Completed
---

> 📚 **Related:** [[NYPY3 - Main Index|NYPY3 Index]] | [[03-RESOURCES/EGE351-Automation-Systems-Control/23S2 EGE351 Lab 3 - Automation - Combination Logic 1.md|Lab 3]] | [[📅 Schedule & Assessments Dashboard|Assessment Dashboard]]

> 📚 **Related:** [[NYPY3 - Main Index|NYPY3 Index]] | [[03-RESOURCES/EGE351-Automation-Systems-Control/23S2 EGE351 Lab 3 - Automation - Combination Logic 1.md|Lab 3]] | [[📅 Schedule & Assessments Dashboard|Assessment Dashboard]]

> 📚 **Related:** [[NYPY3 - Main Index|NYPY3 Index]] | [[03-RESOURCES/EGE351-Automation-Systems-Control/23S2 EGE351 Lab 3 - Automation - Combination Logic 1.md|Lab 3]] | [[📅 Schedule & Assessments Dashboard|Assessment Dashboard]]

Official (Open)
Subject
Tutorial 3
Automation Systems & Control (EGE351)
Automation Control 1
For the following applications, draw the PLC ladder logic to operate the system as designed.
### Question 1
A PLC is used to control a flood light Y6. When a normally-open motion sensor X2 detects any movement, the flood light switches on for 10 seconds and then switches off.
flood light
motion
sensor

**Solution:**
```
Rung 0:
|--[X111]--------+-------------------(R1)--|
| --[R1]--[/T1]--+

Rung 6:
|--[R1]----------------------------------------------------(Y120)--|

Rung 8:
|--[R1]-----------------------------------------------[TMY1, U10]--|
```

**How the ladder diagram works:**

- **Rung 0 (Latching with timer reset):** When motion sensor X111 detects movement, it energizes relay R1. R1 latches itself through its own contact (R1) AND the NOT timer contact [/T1], keeping R1 energized until timer T1 completes (after 10 seconds). This is a standard latching circuit with timer-based reset.

- **Rung 6 (Output control):** When R1 is energized, it directly controls the flood light output Y120. The flood light stays ON as long as R1 is energized.

- **Rung 8 (Timer setup):** When R1 is energized, it starts timer TMY1 with a 10-second preset (U10 = 10 seconds). After 10 seconds, TMY1 completes, causing the [/T1] contact in Rung 0 to open, breaking the latch and de-energizing R1, which turns off the flood light.

## Question 2
A PLC is used to control the motor drive Y8 for a car window. When a normally-open pushbutton PB1 is pressed momentarily the window starts to open. If the pushbutton is pressed for more than 1 second, the window continues opening automatically until fully open.
A second similar pushbutton PB2 does the same thing to close the window. Limit switches SW1 and SW2 are provided to detect if the car window is fully open or fully closed respectively.
car window

**Solution:**
```
Rung 1:
|--[X103]--------------+-----------------------------------(R2)--|
|                      |
+--[R3]--[/R4]--[/T2]--+

Rung 2:
|--[R2]----------------------------------------------------(Y120)--|

Rung 3:
|--[R2]------------------------------------------[TMY1, U1]--|

Rung 4:
|--[T1]----------------------------------------------------(R3)--|

Rung 5:
|--[R3]------------------------------------------[TMY2, U10]--|

Rung 6:
|--[X102]--------------+------------------------------------(R4)--|
|                      |
+--[R1]--[/R2]--[/T4]--+

Rung 7:
|--[R4]----------------------------------------------------(Y121)--|

Rung 8:
|--[R4]---------------------------------------[TMY3, U1]--|

Rung 9:
|--[T3]----------------------------------------------------(R1)--|

Rung 10:
|--[R1]------------------------------------------[TMY4, U10]--|
```

**How the ladder diagram works:**

This is a bi-directional motor control with auto-extend feature for both directions.

**Window Opening (Rungs 1-5):**
- **Rung 1 (Open latch):** When PB1 (X103) is pressed momentarily, it energizes R2. R2 latches through its own contact AND the NOT R4 contact (ensuring close circuit isn't active) AND the NOT T2 contact (auto-extend timer not complete). This allows momentary press to start opening.

- **Rung 2 (Open output):** R2 directly controls the window open motor Y120.

- **Rung 3 (Momentary press timer):** When R2 is energized, timer TMY1 starts with 1-second preset. If PB1 is released before 1 second, T1 never completes, preventing auto-extend.

- **Rung 4 (Auto-extend enable):** When T1 completes (PB1 held for >1 second), it energizes R3, enabling the auto-extend mode.

- **Rung 5 (Auto-extend timer):** When R3 is energized, timer TMY2 starts with 10-second preset. This keeps the window opening automatically until it hits the limit switch (not shown in this diagram, but typically would be in series with the latch).

**Window Closing (Rungs 6-10):**
- **Rung 6 (Close latch):** Mirrors Rung 1 but for closing. When PB2 (X102) is pressed, it energizes R4. R4 latches through its own contact AND the NOT R2 contact (ensuring open circuit isn't active) AND the NOT T4 contact.

- **Rung 7 (Close output):** R4 directly controls the window close motor Y121.

- **Rung 8 (Momentary press timer):** Mirrors Rung 3. When R4 is energized, timer TMY3 starts with 1-second preset.

- **Rung 9 (Auto-extend enable):** Mirrors Rung 4. When T3 completes (PB2 held for >1 second), it energizes R1, enabling auto-extend for closing.

- **Rung 10 (Auto-extend timer):** Mirrors Rung 5. When R1 is energized, timer TMY4 starts with 10-second preset for auto-close.
### Question 3
A PLC is used to control a conveyor system. A sensor X5 with a normally open contact sees items passing on the conveyor. When 10 items have passed, the conveyor motor Y3 stops, a cylinder Y1 extends and retracts after 2 seconds, and the conveyor runs again until another 10 items have passed.
conveyor belt
cylinder
Automation Systems & Control
Page 1 of 1
Effective date: 16 Oct 2023

**Solution:**
```
Rung 1:
|--[X111]-------------------------------------------[CT1]--|
|                                                   [   ]
|--[T1]---------------------------------------------[U10]--|

Rung 2:
|--[/C1]-------------------------------------------(Y122)--|

Rung 3:
|--[C1]--------------------------------------------(Y125)--|

Rung 4:
|--[C1]-----------------------------[TMY1 | U2]--|

Rung 5:
|--[/C1]--[ ]--------------------------------------(Y124)--|
```

**How the ladder diagram works:**

This is a conveyor counting system with automatic stop and cylinder actuation.

- **Rung 1 (Counter setup):** When sensor X111 detects an item (pulse), it increments counter CT1. The bottom input (T1) is the reset - when T1 is ON, it resets the counter to 0. The preset U10 means the counter will complete after 10 items.

- **Rung 2 (Conveyor motor control):** When counter C1 is NOT complete ([/C1] is closed), the conveyor motor Y122 runs. Once 10 items pass and C1 completes, [/C1] opens and stops the conveyor.

- **Rung 3 (Cylinder extend):** When counter C1 completes (after 10 items), the cylinder Y125 extends.

- **Rung 4 (Cylinder retract timer):** When C1 completes, timer TMY1 starts with 2-second preset (U2 = 2 seconds). This times how long the cylinder stays extended.

- **Rung 5 (Cylinder retract + counter reset):** When timer T1 completes (after 2 seconds), it energizes Y124 (cylinder retract) AND resets the counter through the empty contact (the reset input to CT1). This restarts the conveyor and begins counting again.

---

