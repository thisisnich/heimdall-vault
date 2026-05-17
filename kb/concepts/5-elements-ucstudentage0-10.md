---
id: "069d3807-323b-47bc-9c7e-82ba0cd52ce4"
title: "5 Elements Ucstudentage0 10"
type: vault_note
vault: wiki
created: 2026-05-17
updated: 2026-05-17
checksum: "sha256:661f86d9f236e5d0"
source: heimdall/auto
---

# 5 Elements Ucstudentage0 10

- (5 elements)
ucStudentAge[0] = 10;            // Array Assignment
```

#### Pointer

A **variable** that holds a **memory address** rather than data. Used to access data through memory addresses.

```c
unsigned char ucNumber;
unsigned char* ptrNumber;        // Pointer Declaration (using *)
ptrNumber = &ucNumber;           // Pointer Assignment (using &)
```

**Memory layout example:**

| Address | Content | Data Type | Variable | Value |
|---------|---------|-----------|----------|-------|
| 0xFFF0 | 0x41 | `char` | `cName` | `cName = 0x41` |
| 0xFFF1 | 0x10 | `char` | `cAge[3]` | `cAge[0] = 0x10` |
| 0xFFF2 | 0x11 | | | `cAge[1] = 0x11` |
| 0xFFF3 | 0x12 | | | `cAge[2] = 0x12` |
| 0xFFF4 | 0xFF | `char*` | `ptrName` | `ptrName = 0xFFF0` |
| 0xFFF5 | 0xF0 | | | |

**Example:** Declaration of an array of 100 unsigned integers named `uiBicycle`:
```c
unsigned int uiBicycle[100];
```

---

### Operators

#### Arithmetic Operators

| Operator | Description | Example |
|----------|-------------|---------|
| `+` | Adds two operands | `a + b` |
| `-` | Subtracts second from first | `a - b` |
| `*` | Multiplies both operands | `a * b` |
| `/` | Divides and returns quotient | `a / b` |
| `%` | Divides and returns remainder | `a % b` |
| `++` | Increases integer value by one | `a++` |
| `--` | Decreases integer value by one | `b--` |

#### Comparison Operators

| Operator | Description | Example |
|----------|-------------|---------|
| `==` | True if operands are equal | `a == b` |
| <!-- id:069d3807-323b-47bc-9c7e-82ba0cd52ce4 ts:2026-05-17 07:49 -->
