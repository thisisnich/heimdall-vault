---
id: "156655c3-87be-4955-9bdb-8dc2c3750eb1"
title: "Program Execution   Executes The"
type: vault_note
vault: wiki
created: 2026-05-17
updated: 2026-05-17
checksum: "sha256:496a62591ae60539"
source: heimdall/auto
---

# Program Execution   Executes The

- Program Execution
- Executes the user program.
- Updates the result into **output memory**.
- Example: `X1 AND X2 = Y3` (Sw_1 AND Sw_2 = Lamp)

### 3. Output Scan
- Transfers the status of the output memory to the **output module**.
- Physical outputs (e.g. lamps, motors) are activated accordingly.

This cycle repeats **over and over again** while the PLC is in RUN mode.

---

## PLC Internal Scan Cycle

```
       ┌─────────────────────────────────┐
       │                                 │
  [Input Scan] → [User-program] → [Output Scan]
  (First instr.)   Execution    (Last instr.)
       │                                 │
       └─────────────────────────────────┘
              (Repeating cycle)
```

> The CPU executes the user-program over and over again when in **RUN mode**.

---

## Central Processing Unit (CPU)

- The CPU **controls and supervises** all operations within the PLC.
- Carries out programmed instructions stored in memory.
- An internal **bus system** carries information to and from the CPU, memory, and I/O units.

---

## Categories of PLC

| PLC Size | Max I/O Points | User Memory Size (No. of Instructions) |
|---|---|---|
| Small | 40 / 40 | 1K |
| Medium | 128 / 128 | 4K |
| Large | > 128 / > 128 | > 4K |

---

## Considerations in Choosing a Suitable PLC

- Necessary input/output capacity
- Types of I/O required
- Size of memory required
- Speed and power required of the CPU and instruction set
- Manufacturer's support and backup <!-- id:156655c3-87be-4955-9bdb-8dc2c3750eb1 ts:2026-05-17 07:49 -->
- Program Execution
- Executes the user program.
- Updates the result into **output memory**.
- Example: `X1 AND X2 = Y3` (Sw_1 AND Sw_2 = Lamp)

### 3. Output Scan
- Transfers the status of the output memory to the **output module**.
- Physical outputs (e.g. lamps, motors) are activated accordingly.

This cycle repeats **over and over again** while the PLC is in RUN mode.

---

## PLC Internal Scan Cycle

```
       ┌─────────────────────────────────┐
       │                                 │
  [Input Scan] → [User-program] → [Output Scan]
  (First instr.)   Execution    (Last instr.)
       │                                 │
       └─────────────────────────────────┘
              (Repeating cycle)
```

> The CPU executes the user-program over and over again when in **RUN mode**.

---

## Central Processing Unit (CPU)

- The CPU **controls and supervises** all operations within the PLC.
- Carries out programmed instructions stored in memory.
- An internal **bus system** carries information to and from the CPU, memory, and I/O units.

---

## Categories of PLC

| PLC Size | Max I/O Points | User Memory Size (No. of Instructions) |
|---|---|---|
| Small | 40 / 40 | 1K |
| Medium | 128 / 128 | 4K |
| Large | > 128 / > 128 | > 4K |

---

## Considerations in Choosing a Suitable PLC

- Necessary input/output capacity
- Types of I/O required
- Size of memory required
- Speed and power required of the CPU and instruction set
- Manufacturer's support and backup <!-- id:156655c3-87be-4955-9bdb-8dc2c3750eb1 ts:2026-05-17 07:49 -->
