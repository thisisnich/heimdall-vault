---
tags:
  - EGE351
  - tutorial
  - PLC
  - combination-logic
  - tutorial-4
  - traffic-light
course: EGE351 Automation Systems & Control
topic: Tutorial 4 - Combination Traffic Light
source: 23S2 EGE351 Tutorial 4 Combination Traffic Light.pdf
converted: 2026-05-05
type: Tutorial
status: Completed
source: NYPY3 Import
---

> 📚 **Related:** [[NYPY3 - Main Index|NYPY3 Index]] | [[03-RESOURCES/EGE351-Automation-Systems-Control/23S2 EGE351 Lab 3 - Automation - Combination Logic 1.md|Lab 3]] | [[📅 Schedule & Assessments Dashboard|Assessment Dashboard]]

> 📚 **Related:** [[NYPY3 - Main Index|NYPY3 Index]] | [[03-RESOURCES/EGE351-Automation-Systems-Control/23S2 EGE351 Lab 3 - Automation - Combination Logic 1.md|Lab 3]] | [[📅 Schedule & Assessments Dashboard|Assessment Dashboard]]

> 📚 **Related:** [[NYPY3 - Main Index|NYPY3 Index]] | [[03-RESOURCES/EGE351-Automation-Systems-Control/23S2 EGE351 Lab 3 - Automation - Combination Logic 1.md|Lab 3]] | [[📅 Schedule & Assessments Dashboard|Assessment Dashboard]]

> 📚 **Related:** [[NYPY3 - Main Index|NYPY3 Index]] | [[03-RESOURCES/EGE351-Automation-Systems-Control/23S2 EGE351 Lab 3 - Automation - Combination Logic 1.md|Lab 3]] | [[📅 Schedule & Assessments Dashboard|Assessment Dashboard]]

Official (Open)
Subject
Tutorial 4
Automation Systems & Control (EGE351)
Automation Control
For the following applications, prepare an input-output (I/O) table and write a PLC ladder
program to implement them.
### Question 1
A PLC is used to control a conveyor system. Sensor 1 detects objects coming down the conveyor. The motion of the conveyor is indicated by a red LED. When five objects are detected, the conveyor stops and turns on a green LED.

**Solution:**
```
Rung 1:
|--[X111]-------------------------------------------[CT1]--|
|                                                   [   ]
|--[T1]---------------------------------------------[U10]--|

Rung 2:
|--[/C1]------------------------------------------(Y122)--|

Rung 3:
|--[C1]-------------------------------------------(Y125)--|
```

**How the ladder diagram works:**

This is a conveyor counting system that stops after 5 objects and changes LED status.

- **Rung 1 (Counter setup):** When sensor X111 detects an object (pulse), it increments counter CT1. The bottom input (T1) is the reset - when T1 is ON, it resets the counter to 0. The preset U10 means the counter will complete after 10 counts (note: the question says 5 objects, but the diagram shows U10 - this may need adjustment to U5 for 5 objects).

- **Rung 2 (Conveyor motor/red LED control):** When counter C1 is NOT complete ([/C1] is closed), the conveyor motor/red LED Y122 runs. Once the target count is reached and C1 completes, [/C1] opens and stops the conveyor/turns off the red LED.

- **Rung 3 (Green LED):** When counter C1 completes (after reaching the target count), the green LED Y125 turns on, indicating the conveyor has stopped.

> ⚠️ **Note:** The diagram shows U10 (10 counts) but the question specifies 5 objects. Change U10 to U5 to match the requirement.
### Question 2
A PLC is used to control a traffic light system. Write a program to simulate the traffic lights.
When a START (NO) pushbutton is pressed, the following steps are executed:
- 1) a red LED turns on for 5 seconds, then
- 2) an amber LED turns on for 3 seconds, followed by
- 3) a green LED turns on for 8 seconds.
All LEDs are off when a STOP (NC) pushbutton is pressed.

**Solution:**
```
Rung 1:
|--[X102]----------------------+------------------(R1)--|
|                               |
+--[R1]--[/T1]--[X100]------+

Rung 2:
|--[R1]--------------------------------------------(Y120)--|

Rung 3:
|--[R1]-----------------------------[TMY1 | U5]--|

Rung 4:
|--[T1]------------------------- +-----------------(R2)--|
|                               |
+--[R2]--[/T2]--[X100]-----+

Rung 5:
|--[R2]--------------------------------------------(Y121)--|

Rung 6:
|--[R2]-----------------------------[TMY2 | U3]--|

Rung 7:
|--[T2]-------------------------+-----------------(R3)--|
|                               |
+--[R3]--[/T3]--[X100]-----+

Rung 8:
|--[R3]--------------------------------------------(Y122)--|

Rung 9:
|--[R3]-----------------------------[TMY3 | U8]--|
```

**How the ladder diagram works:**

This is a sequential traffic light controller with three stages (red → amber → green). The system uses a cascading latch design where each stage's timer completion triggers the next stage.

**Stage 1 - Red Light (Rungs 1-3):**
- **Rung 1 (Red latch):** When START button X102 is pressed, it energizes R1. R1 latches through its own contact AND the NOT T1 contact (red timer not complete) AND the NOT X100 contact (STOP button not pressed - NC, so normally closed contact opens when pressed).
- **Rung 2 (Red output):** R1 directly controls the red LED Y120.
- **Rung 3 (Red timer):** When R1 is energized, timer TMY1 starts with 5-second preset (U5 = 5 seconds). After 5 seconds, T1 completes.

**Stage 2 - Amber Light (Rungs 4-6):**
- **Rung 4 (Amber latch):** When T1 completes (red timer done), it energizes R2. R2 latches through its own contact AND the NOT T2 contact (amber timer not complete) AND the NOT X100 contact (STOP button). This cascades from red to amber.
- **Rung 5 (Amber output):** R2 directly controls the amber LED Y121.
- **Rung 6 (Amber timer):** When R2 is energized, timer TMY2 starts with 3-second preset (U3 = 3 seconds). After 3 seconds, T2 completes.

**Stage 3 - Green Light (Rungs 7-9):**
- **Rung 7 (Green latch):** When T2 completes (amber timer done), it energizes R3. R3 latches through its own contact AND the NOT T3 contact (green timer not complete) AND the NOT X100 contact (STOP button). This cascades from amber to green.
- **Rung 8 (Green output):** R3 directly controls the green LED Y122.
- **Rung 9 (Green timer):** When R3 is energized, timer TMY3 starts with 8-second preset (U8 = 8 seconds). After 8 seconds, T3 completes.

**STOP Functionality:**
- The STOP button X100 is normally closed (NC). When pressed, it opens, causing all the NOT X100 contacts ([/X100]) in Rungs 1, 4, and 7 to open. This breaks all latches simultaneously, turning off all LEDs.

**Sequence Summary:**
1. Press START → Red ON for 5s
2. After 5s → Red OFF, Amber ON for 3s
3. After 3s → Amber OFF, Green ON for 8s
4. After 8s → Green OFF (cycle ends)
5. Press STOP at any time → All LEDs OFF
### Question 3
When PB1 is pressed five times, a green LED flashes. When PB1 is pressed eight times, an amber LED flashes. When PB1 is pressed twelve times, a red LED flashes. After this, a left gantry is raised. Two seconds later, the gantry is lowered and all LEDs are turned off.

**Solution:**
```
Rung 1:
|--[X103]-------------------------------------------[CT1]--|
|                                                   [   ]
|--[T1]---------------------------------------------[U5]--|

Rung 2:
|--[C1]--[SR1C]--------------------------------------(Y122)--|

Rung 3:
|--[C1]--[X103]-------------------------------------[CT2]--|
|                                                   [   ]
|--[T1]---------------------------------------------[U8]--|

Rung 4:
|--[C2]--[SR1C]--------------------------------------(Y121)--|

Rung 5:
|--[C2]--[X103]-------------------------------------[CT3]--|
|                                                   [   ]
|--[T1]---------------------------------------------[U12]--|

Rung 6:
|--[C3]--[SR1C]--------------------------------------(Y120)--|

Rung 7:
|--[C3]-----------------------------[TMY1 | U2]--|

Rung 8:
|--[C3]----------------------------------------------(Y124)--|

Rung 9:
|--[/C3]--------------------------------------------- (Y125)--|
```

**How the ladder diagram works:**

This is a multi-stage counter system that triggers different LEDs based on button press counts, then controls a gantry with automatic reset.

**Stage 1 - Green LED at 5 presses (Rungs 1-2):**
- **Rung 1 (Counter 1):** When PB1 (X103) is pressed, it increments counter CT1. The bottom input (T1) resets the counter. The preset U5 means the counter completes after 5 button presses.
- **Rung 2 (Green LED flash):** When counter C1 completes (after 5 presses), AND the SR1C special relay (1-second clock pulse) is ON, the green LED Y122 flashes. SR1C provides the flashing effect at 1-second intervals.

**Stage 2 - Amber LED at 8 presses (Rungs 3-4):**
- **Rung 3 (Counter 2):** When counter C1 is complete AND PB1 (X103) is pressed, it increments counter CT2. This means counter 2 only starts counting after counter 1 has reached 5 presses. The preset U8 means it completes after 8 additional presses (total 13 presses from start, or 8 presses after stage 1).
- **Rung 4 (Amber LED flash):** When counter C2 completes, AND SR1C is ON, the amber LED Y121 flashes.

**Stage 3 - Red LED at 12 presses (Rungs 5-6):**
- **Rung 5 (Counter 3):** When counter C2 is complete AND PB1 (X103) is pressed, it increments counter CT3. This means counter 3 only starts counting after counter 2 has reached its target. The preset U12 means it completes after 12 additional presses.
- **Rung 6 (Red LED flash):** When counter C3 completes, AND SR1C is ON, the red LED Y120 flashes.

**Gantry Control (Rungs 7-9):**
- **Rung 7 (Gantry raise timer):** When counter C3 completes, timer TMY1 starts with 2-second preset (U2 = 2 seconds). This times how long the gantry stays raised.
- **Rung 8 (Gantry raise):** When counter C3 completes, the left gantry raise output Y124 is energized (gantry goes up).
- **Rung 9 (Gantry lower):** When counter C3 is NOT complete ([/C3] is closed), the left gantry lower output Y125 is energized. This means the gantry is normally lowered, and only raises when C3 completes. After the timer in Rung 7 completes (and presumably resets the counters), the gantry lowers again.

**Counter Reset:**
- The T1 contact in Rungs 1, 3, and 5 is the reset input for all three counters. When T1 is ON, all counters reset to 0. This would typically be triggered after the gantry operation completes to restart the sequence.

**Sequence Summary:**
1. Press PB1 5 times → Green LED flashes
2. Continue pressing PB1 (8 more times) → Amber LED flashes
3. Continue pressing PB1 (12 more times) → Red LED flashes
4. After stage 3 complete → Gantry raises (Y124 ON)
5. After 2 seconds → Gantry lowers (Y125 ON), counters reset, sequence restarts
Automation Systems & Control
Page 1 of 1
Effective date: 16 Oct 2023

---

