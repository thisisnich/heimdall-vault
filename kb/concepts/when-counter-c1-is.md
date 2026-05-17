---
id: "e3f7b596-4daf-4afd-b6b9-9ba00c0659cb"
title: "When Counter C1 Is"
type: vault_note
vault: wiki
created: 2026-05-17
updated: 2026-05-17
checksum: "sha256:d6b038f6c93c6d55"
source: heimdall/auto
---

# When Counter C1 Is

- ```
When counter C1 is complete, the LED Y122 flashes at 1-second intervals (1s ON, 1s OFF) because SR1C toggles every second.

---

## Quick Tips for FPWIN GR7

- Timer contacts are referenced just by number: **T0, T1** etc.
- Counter contacts are referenced just by number: **C0, C1** etc.
- Special relays SR1A/SR1B/SR1C provide clock pulses for flashing effects
- SV can also be set using a **data register**: `SV: DT0` if you want adjustable speed at runtime
- Make sure timer/counter numbers don't overlap with other rungs
- Counters latch ON when complete - always provide a reset condition

> ⚠️ **NOTE: Each output address can only be used ONCE across all rungs.**


Blinknig LED and timers explanation

TM -> timer -> need a "1" signal for U counts of duration set by TM
TMY -> 1s
TMX -> 0.1s
TMR ->0.01s
TML -> 1ms
TMS -> 0.1ms

> formal is \[TM??]\[U?]
> TM?_ -> the ? determines timer duration/clock/speed
> TM_? -> selects which timer -> eg TMY1 is controling T1 -> at 1 second intervals
> U? -> the ? determines how many counts of that it takes before signal goes through 

Timer bit -> 

blink on and off
SR1A - > 1ms
SR1B - > 10ms
SR1C - > 1s <!-- id:e3f7b596-4daf-4afd-b6b9-9ba00c0659cb ts:2026-05-17 07:49 -->
- ```
When counter C1 is complete, the LED Y122 flashes at 1-second intervals (1s ON, 1s OFF) because SR1C toggles every second.

---

## Quick Tips for FPWIN GR7

- Timer contacts are referenced just by number: **T0, T1** etc.
- Counter contacts are referenced just by number: **C0, C1** etc.
- Special relays SR1A/SR1B/SR1C provide clock pulses for flashing effects
- SV can also be set using a **data register**: `SV: DT0` if you want adjustable speed at runtime
- Make sure timer/counter numbers don't overlap with other rungs
- Counters latch ON when complete - always provide a reset condition

> ⚠️ **NOTE: Each output address can only be used ONCE across all rungs.**


Blinknig LED and timers explanation

TM -> timer -> need a "1" signal for U counts of duration set by TM
TMY -> 1s
TMX -> 0.1s
TMR ->0.01s
TML -> 1ms
TMS -> 0.1ms

> formal is \[TM??]\[U?]
> TM?_ -> the ? determines timer duration/clock/speed
> TM_? -> selects which timer -> eg TMY1 is controling T1 -> at 1 second intervals
> U? -> the ? determines how many counts of that it takes before signal goes through 

Timer bit -> 

blink on and off
SR1A - > 1ms
SR1B - > 10ms
SR1C - > 1s <!-- id:e3f7b596-4daf-4afd-b6b9-9ba00c0659cb ts:2026-05-17 07:49 -->
