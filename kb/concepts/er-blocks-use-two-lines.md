---
id: "13a4bdff-1f4e-47c8-aaf8-e8c9baaf8f79"
title: "Er Blocks Use Two Lines"
type: vault_note
vault: wiki
created: 2026-05-17
updated: 2026-05-17
checksum: "sha256:c322ce181a125479"
source: heimdall/auto
---

# Er Blocks Use Two Lines

- er blocks use two lines - align the preset (U) line under the increment (CT) line

### Rung Numbering
In FPWIN GR7S, rungs can have multiple "layers". The numbering system shows:
- **Left number**: Logical rung number (1, 2, 3...)
- **Right number**: Actual physical rung position

Example with 2-layer rungs:
```
1
2  3
3  5
4  7
5  9
```
This means:
- Rung 1 uses position 1
- Rung 2 uses positions 2-3
- Rung 3 uses positions 4-5
- etc.

For markdown documentation, use the logical rung number (left number) for clarity.

## Common Patterns

### 1. Simple Direct Control
```
Rung 0:
|--[X000]--------(Y000)--
```
**Explanation**: When input X000 is ON, output Y000 turns ON.

### 2. Latching Circuit (Seal-in)
```
Rung 0:
|--[X000]--------+-------------------(R1)--|
| --[R1]----------+

Rung 1:
|--[R1]--------(Y000)--
```
**Explanation**: Momentary input X000 latches relay R1, which keeps itself energized even after X000 is released. Used for start/stop circuits.

### 3. Timer-Based Control
```
Rung 0:
|--[X000]--------[TMY1, U5]--

Rung 1:
|--[T1]--------(Y000)--
```
**Explanation**: When X000 is ON, timer TMY1 starts (1-second resolution, 5 counts = 5 seconds). After 5 seconds, T1 completes and turns ON Y000.

### 4. Timer Reset (Self-Resetting)
```
Rung 0:
|--[X000]--------+-------------------(R1)--|
| --[R1]--[/T1]--+

Rung 1:
|--[R1]--------[TMY1, U10]--
```
**Explanation**: X000 starts the latch. R1 starts a 10-second timer (TMY1 = 1s × 10 = 10s). <!-- id:13a4bdff-1f4e-47c8-aaf8-e8c9baaf8f79 ts:2026-05-17 07:49 -->
- er blocks use two lines - align the preset (U) line under the increment (CT) line

### Rung Numbering
In FPWIN GR7S, rungs can have multiple "layers". The numbering system shows:
- **Left number**: Logical rung number (1, 2, 3...)
- **Right number**: Actual physical rung position

Example with 2-layer rungs:
```
1
2  3
3  5
4  7
5  9
```
This means:
- Rung 1 uses position 1
- Rung 2 uses positions 2-3
- Rung 3 uses positions 4-5
- etc.

For markdown documentation, use the logical rung number (left number) for clarity.

## Common Patterns

### 1. Simple Direct Control
```
Rung 0:
|--[X000]--------(Y000)--
```
**Explanation**: When input X000 is ON, output Y000 turns ON.

### 2. Latching Circuit (Seal-in)
```
Rung 0:
|--[X000]--------+-------------------(R1)--|
| --[R1]----------+

Rung 1:
|--[R1]--------(Y000)--
```
**Explanation**: Momentary input X000 latches relay R1, which keeps itself energized even after X000 is released. Used for start/stop circuits.

### 3. Timer-Based Control
```
Rung 0:
|--[X000]--------[TMY1, U5]--

Rung 1:
|--[T1]--------(Y000)--
```
**Explanation**: When X000 is ON, timer TMY1 starts (1-second resolution, 5 counts = 5 seconds). After 5 seconds, T1 completes and turns ON Y000.

### 4. Timer Reset (Self-Resetting)
```
Rung 0:
|--[X000]--------+-------------------(R1)--|
| --[R1]--[/T1]--+

Rung 1:
|--[R1]--------[TMY1, U10]--
```
**Explanation**: X000 starts the latch. R1 starts a 10-second timer (TMY1 = 1s × 10 = 10s). <!-- id:13a4bdff-1f4e-47c8-aaf8-e8c9baaf8f79 ts:2026-05-17 07:49 -->
