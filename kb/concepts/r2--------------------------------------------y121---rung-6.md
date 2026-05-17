---
id: "9d1488f4-b644-40be-8bc1-81ab63a62eff"
title: "R2                                            Y121   Rung 6"
type: vault_note
vault: wiki
created: 2026-05-17
updated: 2026-05-17
checksum: "sha256:834691eaa8752c3c"
source: heimdall/auto
---

# R2                                            Y121   Rung 6

- [R2]--------------------------------------------(Y121)--|

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
- **Rung 4 (Amber latch):** When T1 completes (red timer done), it energizes R2. R2 latches through its own contact AND the NOT T2 contact (amber timer not complete) AND the NOT X100 contact (STOP button). <!-- id:9d1488f4-b644-40be-8bc1-81ab63a62eff ts:2026-05-17 07:49 -->
- [R2]--------------------------------------------(Y121)--|

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
- **Rung 4 (Amber latch):** When T1 completes (red timer done), it energizes R2. R2 latches through its own contact AND the NOT T2 contact (amber timer not complete) AND the NOT X100 contact (STOP button). <!-- id:9d1488f4-b644-40be-8bc1-81ab63a62eff ts:2026-05-17 07:49 -->
