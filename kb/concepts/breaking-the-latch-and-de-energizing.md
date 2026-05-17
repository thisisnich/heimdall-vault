---
id: "2c49dae6-da5b-4ec9-8a9a-694337f641bc"
title: "Breaking The Latch And De Energizing"
type: vault_note
vault: wiki
created: 2026-05-17
updated: 2026-05-17
checksum: "sha256:6be482719073a6fc"
source: heimdall/auto
---

# Breaking The Latch And De Energizing

- breaking the latch and de-energizing R1, which turns off the flood light.

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

This is a bi-directional motor control with au <!-- id:2c49dae6-da5b-4ec9-8a9a-694337f641bc ts:2026-05-17 07:49 -->
- breaking the latch and de-energizing R1, which turns off the flood light.

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

This is a bi-directional motor control with au <!-- id:2c49dae6-da5b-4ec9-8a9a-694337f641bc ts:2026-05-17 07:49 -->
