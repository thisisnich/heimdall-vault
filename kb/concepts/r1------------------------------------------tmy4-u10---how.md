---
id: "d8c0de16-ee6c-4b0f-beda-9d373df32c10"
title: "R1                                          Tmy4 U10   How"
type: vault_note
vault: wiki
created: 2026-05-17
updated: 2026-05-17
checksum: "sha256:0cde48c055426ca6"
source: heimdall/auto
---

# R1                                          Tmy4 U10   How

- |--[R1]------------------------------------------[TMY4, U10]--|
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
- **Rung 6 (Close latch):** Mirrors Rung 1 but for closing. When PB2 (X102) is pressed, it energizes R4. <!-- id:d8c0de16-ee6c-4b0f-beda-9d373df32c10 ts:2026-05-17 07:49 -->
- |--[R1]------------------------------------------[TMY4, U10]--|
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
- **Rung 6 (Close latch):** Mirrors Rung 1 but for closing. When PB2 (X102) is pressed, it energizes R4. <!-- id:d8c0de16-ee6c-4b0f-beda-9d373df32c10 ts:2026-05-17 07:49 -->
