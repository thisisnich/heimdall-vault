---
tags:
  - EGE351
  - lab
  - PLC
  - automation
  - FPWIN
course: EGE351 Automation Systems & Control
topic: Lab Procedures - PLC I/O Address Assignment and Timer Reference
---

> 📚 **Related:** [[EGE351 Automation Systems & Control - MOC|EGE351 MOC]] | [[EGE351 Automatino Systems & Control/EGE351_Lab_1_PLC_Programming|Lab 1 PLC Programming]] | [[ladder|Ladder Logic Reference Guide]]

# EGE351 Lab Procedures

## Lab PC Login

| Field | Value |
|-------|-------|
| Username | `.\student` |
| Password | `free` |
| Software | `FPWIN GR7` |

> ⚠️ Only the `.\student` account has access to the PLC software.

---

## I/O Address Assignment Table

> Grey ribbon cable carries data to and from the PLC.

### Inputs

| Label | Address | Type | Notes |
|-------|---------|------|-------|
| PB1 | `X103` | Push Button | Red, Normal Open (NO) |
| PB2 | `X102` | Push Button | Red, Normal Open (NO) |
| PB3 | `X101` | Push Button | Red, Normal Open (NO) |
| PB4 | `X100` | Push Button | Red, Normal Closed (NC) — inverted |
| SW1 | `X107` | Switch | |
| SW2 | `X106` | Switch | |
| SW3 | `X105` | Switch | |
| SW4 | `X104` | Switch | |
| E-STOP | `X110` | Emergency Stop | Push to activate, turn clockwise to release |
| Sensor 1 | `X111` | Photoelectric (diffuse) | |
| Sensor 2 | `X112` | Photoelectric (diffuse) | |
| Sensor 3 | `X113` | Photoelectric (diffuse) | |
| Sensor 4 | `X114` | Photoelectric (diffuse) | |

### Outputs

| Label | Address | Type | Notes |
|-------|---------|------|-------|
| LED1 | `Y123` | LED | Blue |
| LED2 | `Y122` | LED | Green |
| LED3 | `Y121` | LED | Amber |
| LED4 | `Y120` | LED | Red |
| RELAY-1 | `Y124` | Relay | Left gantry up |
| RELAY-2 | `Y125` | Relay | Left gantry down |
| RELAY-3 | `Y126` | Relay | Right gantry up |
| RELAY-4 | `Y127` | Relay | Right gantry down |

> ⚠️ **NOTE: Each output address can only be used ONCE across all rungs.**

---

## Timers

### Panasonic FP Timer Types

| Instruction | Resolution | Max Time | Use Case |
|-------------|------------|----------|----------|
| **TMR** | 10ms | 327.67s | General purpose |
| **TMX** | 100ms | 3276.7s | Slower, long delays |
| **TMY** | 1ms | 32.767s | Fast/precise timing |
| **TML** | 1min | 327670min | Very long delays |

For LED blinking, **TMR (10ms)** is the sweet spot.

---

## Timer Block Layout

```
TMR  T0
─────────
U:  [contact]     ← Enable input (starts timer when ON)
SV: 50            ← Set Value (50 × 10ms = 500ms)
```
- **T0** = timer number (T0, T1, T2...)
- **U** = Up input — timer counts while this is ON
- **SV** = Set Value (the preset count, not time directly)
- When elapsed count reaches SV, the **T0 contact closes**

---

## SV Value Calculation

```
SV = Desired Time ÷ Timer Resolution

Example (TMR, 500ms):
SV = 500ms ÷ 10ms = 50
```

| Timer | 0.25s | 0.5s | 1s |
|-------|-------|------|----|
| TMR (10ms) | 25 | 50 | 100 |
| TMX (100ms) | — | 5 | 10 |
| TMY (1ms) | 250 | 500 | 1000 |

---

## Counters

### Panasonic FP Counter Notation

Counters count pulses or events and trigger an action when a preset value is reached.

**Counter Block Layout:**
```
CT  C1
─────────
U:  [contact]     ← Increment input (counts up on each pulse)
SV: 10            ← Set Value (count target)
```

**Counter Inputs:**
- **Top input (CT)**: Increment - each pulse on this input increments the counter
- **Bottom input (U)**: Reset - when ON, resets counter to 0

**Counter Behavior:**
- When the counter reaches the SV (set value), the **C1 contact closes**
- The counter contact **latches ON** until the counter is reset
- Counter contacts are referenced as **C0, C1, C2...** (similar to timers)

**Example:**
```
CT  C1
─────────
U:  [X111]     ← Increment on sensor pulse
SV: 10         ← Count to 10
```
After 10 pulses on X111, contact C1 closes and stays closed until reset.

---

## Special Relays (Clock Pulses)

Panasonic FP PLCs have special relays that provide clock pulses for timing and flashing applications.

| Special Relay | Pulse Interval | Use Case |
|---------------|----------------|----------|
| **SR1A** | 1ms | High-speed timing |
| **SR1B** | 10ms | Fast flashing |
| **SR1C** | 1s | Standard flashing (LEDs) |

**Usage Example:**
```
|--[C1]--[SR1C]--------(Y122)--
```
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
SR1C - > 1s