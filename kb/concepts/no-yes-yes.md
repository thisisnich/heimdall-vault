---
id: "80942df8-4880-4b7c-9fbb-1f6327efc8f8"
title: "No Yes Yes"
type: vault_note
vault: wiki
created: 2026-05-17
updated: 2026-05-17
checksum: "sha256:e90f75d56cdf91b6"
source: heimdall/auto
---

# No Yes Yes

- No | Yes | Yes | Yes |
| Ease of changing function | Very difficult | Difficult | Quite simple | Very simple |
| Ease of maintenance | Poor (large no. of contacts) | Poor if ICs soldered | Poor (several custom boards) | Good (few standard cards) |

---

## PLC Memory Map

| Memory Type | Storage |
|---|---|
| Executive Memory | ROM |
| System Memory | RAM |
| I/O Status Memory | RAM |
| Data Memory | RAM |
| User Memory | RAM / EPROM / EEPROM |

---

## I/O Address Assignment Table

| Input | | Output | |
|---|---|---|---|
| **Address** | **Label** | **Address** | **Label** |
| X0 | PB A | Y0 | Extend Cylinder A |
| X1 | PB B | Y1 | Retract Cylinder A |
| X3 | Sensor 1 | Y2 | Extend Cylinder B |
| X4 | Sensor 2 | Y3 | Blue Lamp |

---

## Data Memory

- Data memory is required by timers, counters, mathematics and process parameters.
- An area of memory is set aside for data storage.
- Some manufacturers subdivide the data memory area into two sub-memories — one for **fixed data** and one for **variable data**.

---

## How a PLC Works

The PLC operates on a continuous **scan cycle** with three main phases:

### 1. Input Scan
- Checks the status of all input devices.
- Updates the status into **input memory** (e.g. X1 = Sw_1, X2 = Sw_2).

### 2. Program Execution
- Executes the user program.
- Updates the result into **output memory**.
- Example: `X1 AND X2 = Y3` (Sw_1 AND Sw_2 = Lamp)

### 3. <!-- id:80942df8-4880-4b7c-9fbb-1f6327efc8f8 ts:2026-05-17 07:49 -->
- No | Yes | Yes | Yes |
| Ease of changing function | Very difficult | Difficult | Quite simple | Very simple |
| Ease of maintenance | Poor (large no. of contacts) | Poor if ICs soldered | Poor (several custom boards) | Good (few standard cards) |

---

## PLC Memory Map

| Memory Type | Storage |
|---|---|
| Executive Memory | ROM |
| System Memory | RAM |
| I/O Status Memory | RAM |
| Data Memory | RAM |
| User Memory | RAM / EPROM / EEPROM |

---

## I/O Address Assignment Table

| Input | | Output | |
|---|---|---|---|
| **Address** | **Label** | **Address** | **Label** |
| X0 | PB A | Y0 | Extend Cylinder A |
| X1 | PB B | Y1 | Retract Cylinder A |
| X3 | Sensor 1 | Y2 | Extend Cylinder B |
| X4 | Sensor 2 | Y3 | Blue Lamp |

---

## Data Memory

- Data memory is required by timers, counters, mathematics and process parameters.
- An area of memory is set aside for data storage.
- Some manufacturers subdivide the data memory area into two sub-memories — one for **fixed data** and one for **variable data**.

---

## How a PLC Works

The PLC operates on a continuous **scan cycle** with three main phases:

### 1. Input Scan
- Checks the status of all input devices.
- Updates the status into **input memory** (e.g. X1 = Sw_1, X2 = Sw_2).

### 2. Program Execution
- Executes the user program.
- Updates the result into **output memory**.
- Example: `X1 AND X2 = Y3` (Sw_1 AND Sw_2 = Lamp)

### 3. <!-- id:80942df8-4880-4b7c-9fbb-1f6327efc8f8 ts:2026-05-17 07:49 -->
