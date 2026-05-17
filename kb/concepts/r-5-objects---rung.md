---
id: "19d9a37b-9788-4a24-a15a-5ef274e8caaf"
title: "R 5 Objects   Rung"
type: vault_note
vault: wiki
created: 2026-05-17
updated: 2026-05-17
checksum: "sha256:349c12841bf1c07b"
source: heimdall/auto
---

# R 5 Objects   Rung

- r 5 objects).

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
|--[T2]---------------- <!-- id:19d9a37b-9788-4a24-a15a-5ef274e8caaf ts:2026-05-17 07:49 -->
- r 5 objects).

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
|--[T2]---------------- <!-- id:19d9a37b-9788-4a24-a15a-5ef274e8caaf ts:2026-05-17 07:49 -->
