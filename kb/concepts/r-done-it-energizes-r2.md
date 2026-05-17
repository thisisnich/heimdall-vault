---
id: "156d29f5-f3ba-4c63-95a3-ff59a2663528"
title: "R Done It Energizes R2"
type: vault_note
vault: wiki
created: 2026-05-17
updated: 2026-05-17
checksum: "sha256:e4891c27e03b978b"
source: heimdall/auto
---

# R Done It Energizes R2

- r done), it energizes R2. R2 latches through its own contact AND the NOT T2 contact (amber timer not complete) AND the NOT X100 contact (STOP button). This cascades from red to amber.
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
When PB1 is pressed five times, a green LED flashes. When PB1 is pressed eight times, an amber LED flashes. <!-- id:156d29f5-f3ba-4c63-95a3-ff59a2663528 ts:2026-05-17 07:49 -->
- r done), it energizes R2. R2 latches through its own contact AND the NOT T2 contact (amber timer not complete) AND the NOT X100 contact (STOP button). This cascades from red to amber.
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
When PB1 is pressed five times, a green LED flashes. When PB1 is pressed eight times, an amber LED flashes. <!-- id:156d29f5-f3ba-4c63-95a3-ff59a2663528 ts:2026-05-17 07:49 -->
