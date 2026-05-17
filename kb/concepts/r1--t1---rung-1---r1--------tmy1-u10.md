---
id: "a439ce45-5056-44d5-bba3-76adcd1b23ce"
title: "R1  T1   Rung 1   R1        Tmy1 U10"
type: vault_note
vault: wiki
created: 2026-05-17
updated: 2026-05-17
checksum: "sha256:08cfbb8fbf27b12e"
source: heimdall/auto
---

# R1  T1   Rung 1   R1        Tmy1 U10

- --[R1]--[/T1]--+

Rung 1:
|--[R1]--------[TMY1, U10]--
```
**Explanation**: X000 starts the latch. R1 starts a 10-second timer (TMY1 = 1s × 10 = 10s). When timer completes, [/T1] opens and breaks the latch, turning OFF R1. Used for one-shot timing.

### 5. Interlock (Mutual Exclusion)
```
Rung 0:
|--[X000]--[/R2]--------(R1)--

Rung 1:
|--[X001]--[/R1]--------(R2)--
```
**Explanation**: R1 and R2 cannot be ON simultaneously. Each rung includes the NOT of the other relay, ensuring only one can be active at a time. Used for forward/reverse motor control.

### 6. Counter Application
```
Rung 0:
|--[X005]---------------------------[CT1]--|
|                                       [   ]
|--[T1]---------------------------------[U10]--|

Rung 1:
|--[C1]--------(Y000)--
```
**Explanation**: Each pulse on X005 increments counter CT1. The bottom input (T1) resets the counter. After 10 counts, C1 completes and turns ON Y000. C1 stays ON until the counter is reset.

## Creating New Diagrams

### Step-by-Step Process

1. **Identify Inputs and Outputs**
   - List all sensors, switches, buttons (X addresses)
   - List all motors, lights, actuators (Y addresses)
   - Determine if internal relays (R) are needed for intermediate logic
   - Check [[EGE351 Automatino Systems & Control/Lab procedures|Lab Procedures]] for standard I/O assignments

2. <!-- id:a439ce45-5056-44d5-bba3-76adcd1b23ce ts:2026-05-17 07:49 -->
- --[R1]--[/T1]--+

Rung 1:
|--[R1]--------[TMY1, U10]--
```
**Explanation**: X000 starts the latch. R1 starts a 10-second timer (TMY1 = 1s × 10 = 10s). When timer completes, [/T1] opens and breaks the latch, turning OFF R1. Used for one-shot timing.

### 5. Interlock (Mutual Exclusion)
```
Rung 0:
|--[X000]--[/R2]--------(R1)--

Rung 1:
|--[X001]--[/R1]--------(R2)--
```
**Explanation**: R1 and R2 cannot be ON simultaneously. Each rung includes the NOT of the other relay, ensuring only one can be active at a time. Used for forward/reverse motor control.

### 6. Counter Application
```
Rung 0:
|--[X005]---------------------------[CT1]--|
|                                       [   ]
|--[T1]---------------------------------[U10]--|

Rung 1:
|--[C1]--------(Y000)--
```
**Explanation**: Each pulse on X005 increments counter CT1. The bottom input (T1) resets the counter. After 10 counts, C1 completes and turns ON Y000. C1 stays ON until the counter is reset.

## Creating New Diagrams

### Step-by-Step Process

1. **Identify Inputs and Outputs**
   - List all sensors, switches, buttons (X addresses)
   - List all motors, lights, actuators (Y addresses)
   - Determine if internal relays (R) are needed for intermediate logic
   - Check [[EGE351 Automatino Systems & Control/Lab procedures|Lab Procedures]] for standard I/O assignments

2. <!-- id:a439ce45-5056-44d5-bba3-76adcd1b23ce ts:2026-05-17 07:49 -->
