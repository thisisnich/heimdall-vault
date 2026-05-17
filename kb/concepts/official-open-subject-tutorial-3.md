---
id: "61ab6fcc-5531-45fb-b665-f51008d5b6ca"
title: "Official Open Subject Tutorial 3"
type: vault_note
vault: wiki
created: 2026-05-17
updated: 2026-05-17
checksum: "sha256:e749a45cf5407f7a"
source: heimdall/auto
---

# Official Open Subject Tutorial 3

- Official (Open)
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
A PLC is used to control the motor drive Y8 for a car window. <!-- id:61ab6fcc-5531-45fb-b665-f51008d5b6ca ts:2026-05-17 07:49 -->
- Official (Open)
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
A PLC is used to control the motor drive Y8 for a car window. <!-- id:61ab6fcc-5531-45fb-b665-f51008d5b6ca ts:2026-05-17 07:49 -->
