---
id: "3e427134-0117-4efc-ac3a-a05c47a7a414"
title: "Ning Description"
type: vault_note
vault: wiki
created: 2026-05-17
updated: 2026-05-17
checksum: "sha256:2f238543b0ca7409"
source: heimdall/auto
---

# Ning Description

- ning | Description |
|--------|---------|-------------|
| `[CTx]` | Counter increment | Top input increments counter Cx |
| `[Uy]` | Counter preset | Bottom input sets count target to y |
| `[Cx]` | Counter contact (NO) | Normally open when counter Cx reaches target |
| `[/Cx]` | Counter contact (NC) | Normally closed when counter Cx reaches target |

**Counter Notation:**
- **CTx** = Counter number x
- **Uy** = Preset value y (how many counts to increment)
- Top input = Increment (counts up on each pulse)
- Bottom input = Reset (resets counter to 0)
- When counter reaches preset, **Cx** latches ON until reset

### Addressing Conventions (Panasonic FP)
- **X###**: Input addresses (sensors, switches, buttons) - X100-X119 typical
- **Y###**: Output addresses (motors, lights, valves) - Y120-Y127 typical
- **R###**: Internal relays (auxiliary contacts)
- **T###**: Timer addresses (T0, T1, T2...)
- **C###**: Counter addresses (C0, C1, C2...)

> ⚠️ **IMPORTANT:** Each output address (Y###) can only be used ONCE across all rungs.

## Markdown Ladder Diagram Format

### Basic Structure
```
Rung 0:
|--[X000]--------(Y000)--
```

### With Branches
```
Rung 0:
|--[X000]--------+-------------------(R1)--|
| --[R1]--[/T1]--+
```

### With Counter
```
Rung 0:
|--[X111]---------------------------[CT1]--|
|                                       [   ]
|--[T1]---------------------------------[U10]--
```

### Key Formatting Rules
1. <!-- id:3e427134-0117-4efc-ac3a-a05c47a7a414 ts:2026-05-17 07:49 -->
- ning | Description |
|--------|---------|-------------|
| `[CTx]` | Counter increment | Top input increments counter Cx |
| `[Uy]` | Counter preset | Bottom input sets count target to y |
| `[Cx]` | Counter contact (NO) | Normally open when counter Cx reaches target |
| `[/Cx]` | Counter contact (NC) | Normally closed when counter Cx reaches target |

**Counter Notation:**
- **CTx** = Counter number x
- **Uy** = Preset value y (how many counts to increment)
- Top input = Increment (counts up on each pulse)
- Bottom input = Reset (resets counter to 0)
- When counter reaches preset, **Cx** latches ON until reset

### Addressing Conventions (Panasonic FP)
- **X###**: Input addresses (sensors, switches, buttons) - X100-X119 typical
- **Y###**: Output addresses (motors, lights, valves) - Y120-Y127 typical
- **R###**: Internal relays (auxiliary contacts)
- **T###**: Timer addresses (T0, T1, T2...)
- **C###**: Counter addresses (C0, C1, C2...)

> ⚠️ **IMPORTANT:** Each output address (Y###) can only be used ONCE across all rungs.

## Markdown Ladder Diagram Format

### Basic Structure
```
Rung 0:
|--[X000]--------(Y000)--
```

### With Branches
```
Rung 0:
|--[X000]--------+-------------------(R1)--|
| --[R1]--[/T1]--+
```

### With Counter
```
Rung 0:
|--[X111]---------------------------[CT1]--|
|                                       [   ]
|--[T1]---------------------------------[U10]--
```

### Key Formatting Rules
1. <!-- id:3e427134-0117-4efc-ac3a-a05c47a7a414 ts:2026-05-17 07:49 -->
