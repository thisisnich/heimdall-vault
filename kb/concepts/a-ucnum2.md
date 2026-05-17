---
id: "62d3b2d7-42fd-4a2d-99d4-88c5c9f98640"
title: "A Ucnum2"
type: vault_note
vault: wiki
created: 2026-05-17
updated: 2026-05-17
checksum: "sha256:26c9c93adb943e9d"
source: heimdall/auto
---

# A Ucnum2

- ... }`:
- A. `ucNum2 = 0x0F`
- **B. `ucNum2 = 0xF0`** ✓ *(0x0F & 0xF0 = 0x00... wait — 0x0F AND 0xF0 = 0x00)*

> **Correction:** `0x0F & 0xF0 = 0x00`. The slide answer is `ucNum2 = 0xF0`; review with your instructor.

---

## Embedded System Programming II

### Loop Statements

A loop allows **one or more statements to be executed multiple times**, reducing code length and saving memory.

Three types: `while`, `do-while`, `for`

#### while Loop

```c
while (condition)
{
    Statement1;
}
```

Condition is checked **before** each iteration.

#### do-while Loop

```c
do
{
    Statement1;
}
while (condition);
```

Statement executes **at least once**; condition is checked **after** each iteration.

#### for Loop

```c
for (init; condition; increment/decrement)
{
    Statement1;
}
```

**Example:**
```c
unsigned char ucNum1 = 0;
while (ucNum1 != 5)
{
    ucNum1++;
}
// Result: ucNum1 = 5
```

---

### Functions

A **function** is a block of code that performs a specific task. <!-- id:62d3b2d7-42fd-4a2d-99d4-88c5c9f98640 ts:2026-05-17 07:49 -->
