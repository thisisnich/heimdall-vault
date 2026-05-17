---
id: "44dcf2c0-9d14-4066-b644-f7acbfb579e2"
title: "The Latch Window Closing Rungs"
type: vault_note
vault: wiki
created: 2026-05-17
updated: 2026-05-17
checksum: "sha256:fbc11f2f1954531c"
source: heimdall/auto
---

# The Latch Window Closing Rungs

- the latch).

**Window Closing (Rungs 6-10):**
- **Rung 6 (Close latch):** Mirrors Rung 1 but for closing. When PB2 (X102) is pressed, it energizes R4. R4 latches through its own contact AND the NOT R2 contact (ensuring open circuit isn't active) AND the NOT T4 contact.

- **Rung 7 (Close output):** R4 directly controls the window close motor Y121.

- **Rung 8 (Momentary press timer):** Mirrors Rung 3. When R4 is energized, timer TMY3 starts with 1-second preset.

- **Rung 9 (Auto-extend enable):** Mirrors Rung 4. When T3 completes (PB2 held for >1 second), it energizes R1, enabling auto-extend for closing.

- **Rung 10 (Auto-extend timer):** Mirrors Rung 5. When R1 is energized, timer TMY4 starts with 10-second preset for auto-close.
### Question 3
A PLC is used to control a conveyor system. A sensor X5 with a normally open contact sees items passing on the conveyor. <!-- id:44dcf2c0-9d14-4066-b644-f7acbfb579e2 ts:2026-05-17 07:49 -->
- the latch).

**Window Closing (Rungs 6-10):**
- **Rung 6 (Close latch):** Mirrors Rung 1 but for closing. When PB2 (X102) is pressed, it energizes R4. R4 latches through its own contact AND the NOT R2 contact (ensuring open circuit isn't active) AND the NOT T4 contact.

- **Rung 7 (Close output):** R4 directly controls the window close motor Y121.

- **Rung 8 (Momentary press timer):** Mirrors Rung 3. When R4 is energized, timer TMY3 starts with 1-second preset.

- **Rung 9 (Auto-extend enable):** Mirrors Rung 4. When T3 completes (PB2 held for >1 second), it energizes R1, enabling auto-extend for closing.

- **Rung 10 (Auto-extend timer):** Mirrors Rung 5. When R1 is energized, timer TMY4 starts with 10-second preset for auto-close.
### Question 3
A PLC is used to control a conveyor system. A sensor X5 with a normally open contact sees items passing on the conveyor. <!-- id:44dcf2c0-9d14-4066-b644-f7acbfb579e2 ts:2026-05-17 07:49 -->
