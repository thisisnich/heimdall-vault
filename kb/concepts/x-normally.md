---
id: "dea6ab16-e7dd-4a6c-a6bb-ed9ee1afcede"
title: "X Normally"
type: vault_note
vault: wiki
created: 2026-05-17
updated: 2026-05-17
checksum: "sha256:c13b4d829244aaed"
source: heimdall/auto
---

# X Normally

- -----------|
| `[X###]` | Normally Open Contact | Closes when input is ON |
| `[/X###]` | Normally Closed Contact | Opens when input is ON |

### Output Coils
| Symbol | Meaning | Description |
|--------|---------|-------------|
| `(Y###)` | Output Coil | Energizes when logic path is complete |
| `(R###)` | Internal Relay | Internal memory bit for logic |

### Timers (Panasonic FP)
| Symbol | Meaning | Description |
|--------|---------|-------------|
| `[TMxz, Uy]` | Timer instruction | TM = timer, x = resolution type, z = timer number, Uy = count value |
| `[Tz]` | Timer contact (NO) | Normally open when timer Tz is complete |
| `[/Tz]` | Timer contact (NC) | Normally closed when timer Tz is complete |

**Timer Resolution Types:**
| Type | Resolution | Max Time | Use Case |
|------|------------|----------|----------|
| TMR | 10ms | 327.67s | General purpose |
| TMX | 100ms | 3276.7s | Slower, long delays |
| TMY | 1s | 32767s | Standard timing |
| TML | 1min | 327670min | Very long delays |

**Timer Notation:** `[TMxz, Uy]`
- **x** = Resolution type (R, X, Y, L)
- **z** = Timer number (0, 1, 2...)
- **y** = Number of counts (not time directly)
- When the timer completes, contact **Tz** becomes ON

**Example:** `[TMY1, U10]` = Timer T1, 1-second resolution, 10 counts = 10 seconds total

### Counters (Panasonic FP)
| Symbol | Meaning | Description |
|--------|---------|-------------|
| `[CTx]` | Counter increment | Top input increments counter Cx |
| `[Uy]` | Counter preset | <!-- id:dea6ab16-e7dd-4a6c-a6bb-ed9ee1afcede ts:2026-05-17 07:49 -->
- -----------|
| `[X###]` | Normally Open Contact | Closes when input is ON |
| `[/X###]` | Normally Closed Contact | Opens when input is ON |

### Output Coils
| Symbol | Meaning | Description |
|--------|---------|-------------|
| `(Y###)` | Output Coil | Energizes when logic path is complete |
| `(R###)` | Internal Relay | Internal memory bit for logic |

### Timers (Panasonic FP)
| Symbol | Meaning | Description |
|--------|---------|-------------|
| `[TMxz, Uy]` | Timer instruction | TM = timer, x = resolution type, z = timer number, Uy = count value |
| `[Tz]` | Timer contact (NO) | Normally open when timer Tz is complete |
| `[/Tz]` | Timer contact (NC) | Normally closed when timer Tz is complete |

**Timer Resolution Types:**
| Type | Resolution | Max Time | Use Case |
|------|------------|----------|----------|
| TMR | 10ms | 327.67s | General purpose |
| TMX | 100ms | 3276.7s | Slower, long delays |
| TMY | 1s | 32767s | Standard timing |
| TML | 1min | 327670min | Very long delays |

**Timer Notation:** `[TMxz, Uy]`
- **x** = Resolution type (R, X, Y, L)
- **z** = Timer number (0, 1, 2...)
- **y** = Number of counts (not time directly)
- When the timer completes, contact **Tz** becomes ON

**Example:** `[TMY1, U10]` = Timer T1, 1-second resolution, 10 counts = 10 seconds total

### Counters (Panasonic FP)
| Symbol | Meaning | Description |
|--------|---------|-------------|
| `[CTx]` | Counter increment | Top input increments counter Cx |
| `[Uy]` | Counter preset | <!-- id:dea6ab16-e7dd-4a6c-a6bb-ed9ee1afcede ts:2026-05-17 07:49 -->
