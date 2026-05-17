---
id: "da05b7de-fadd-48e8-a417-b94e0f19a611"
title: "This Is A Multi Stage"
type: vault_note
vault: wiki
created: 2026-05-17
updated: 2026-05-17
checksum: "sha256:67b16bd8d709f4f8"
source: heimdall/auto
---

# This Is A Multi Stage

- :**

This is a multi-stage counter system that triggers different LEDs based on button press counts, then controls a gantry with automatic reset.

**Stage 1 - Green LED at 5 presses (Rungs 1-2):**
- **Rung 1 (Counter 1):** When PB1 (X103) is pressed, it increments counter CT1. The bottom input (T1) resets the counter. The preset U5 means the counter completes after 5 button presses.
- **Rung 2 (Green LED flash):** When counter C1 completes (after 5 presses), AND the SR1C special relay (1-second clock pulse) is ON, the green LED Y122 flashes. SR1C provides the flashing effect at 1-second intervals.

**Stage 2 - Amber LED at 8 presses (Rungs 3-4):**
- **Rung 3 (Counter 2):** When counter C1 is complete AND PB1 (X103) is pressed, it increments counter CT2. This means counter 2 only starts counting after counter 1 has reached 5 presses. The preset U8 means it completes after 8 additional presses (total 13 presses from start, or 8 presses after stage 1).
- **Rung 4 (Amber LED flash):** When counter C2 completes, AND SR1C is ON, the amber LED Y121 flashes.

**Stage 3 - Red LED at 12 presses (Rungs 5-6):**
- **Rung 5 (Counter 3):** When counter C2 is complete AND PB1 (X103) is pressed, it increments counter CT3. This means counter 3 only starts counting after counter 2 has reached its target. <!-- id:da05b7de-fadd-48e8-a417-b94e0f19a611 ts:2026-05-17 07:49 -->
- :**

This is a multi-stage counter system that triggers different LEDs based on button press counts, then controls a gantry with automatic reset.

**Stage 1 - Green LED at 5 presses (Rungs 1-2):**
- **Rung 1 (Counter 1):** When PB1 (X103) is pressed, it increments counter CT1. The bottom input (T1) resets the counter. The preset U5 means the counter completes after 5 button presses.
- **Rung 2 (Green LED flash):** When counter C1 completes (after 5 presses), AND the SR1C special relay (1-second clock pulse) is ON, the green LED Y122 flashes. SR1C provides the flashing effect at 1-second intervals.

**Stage 2 - Amber LED at 8 presses (Rungs 3-4):**
- **Rung 3 (Counter 2):** When counter C1 is complete AND PB1 (X103) is pressed, it increments counter CT2. This means counter 2 only starts counting after counter 1 has reached 5 presses. The preset U8 means it completes after 8 additional presses (total 13 presses from start, or 8 presses after stage 1).
- **Rung 4 (Amber LED flash):** When counter C2 completes, AND SR1C is ON, the amber LED Y121 flashes.

**Stage 3 - Red LED at 12 presses (Rungs 5-6):**
- **Rung 5 (Counter 3):** When counter C2 is complete AND PB1 (X103) is pressed, it increments counter CT3. This means counter 3 only starts counting after counter 2 has reached its target. <!-- id:da05b7de-fadd-48e8-a417-b94e0f19a611 ts:2026-05-17 07:49 -->
