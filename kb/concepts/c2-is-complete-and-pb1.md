---
id: "d5f7c8ab-4a2e-453d-85a6-07eb9a4defd0"
title: "C2 Is Complete And Pb1"
type: vault_note
vault: wiki
created: 2026-05-17
updated: 2026-05-17
checksum: "sha256:5c59936c7854ecd7"
source: heimdall/auto
---

# C2 Is Complete And Pb1

- C2 is complete AND PB1 (X103) is pressed, it increments counter CT3. This means counter 3 only starts counting after counter 2 has reached its target. The preset U12 means it completes after 12 additional presses.
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
5. <!-- id:d5f7c8ab-4a2e-453d-85a6-07eb9a4defd0 ts:2026-05-17 07:49 -->
- C2 is complete AND PB1 (X103) is pressed, it increments counter CT3. This means counter 3 only starts counting after counter 2 has reached its target. The preset U12 means it completes after 12 additional presses.
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
5. <!-- id:d5f7c8ab-4a2e-453d-85a6-07eb9a4defd0 ts:2026-05-17 07:49 -->
