---
id: "052bfbdb-f568-46d6-ad01-95feddce4e43"
title: "Ign Remainder C"
type: vault_note
vault: wiki
created: 2026-05-17
updated: 2026-05-17
checksum: "sha256:c12d3797bc9d10da"
source: heimdall/auto
---

# Ign Remainder C

- ign remainder | `c %= a` |
| `<<=` | Left shift and assign | `c <<= 5` |
| `>>=` | Right shift and assign | `c >>= 5` |
| `&=` | Bitwise AND and assign | `c &= 5` |
| `\|=` | Bitwise OR and assign | `c \|= 5` |
| `^=` | Bitwise XOR and assign | `c ^= 5` |

**Example:**
```c
unsigned char ucNum1, ucNum2;
ucNum1 = 10 / 3;   // ucNum1 = 3
ucNum2 = 10 % 3;   // ucNum2 = 1
```

---

### Conditional Statements

Used to **decide the action of execution** of statements **based on certain conditions**.

Three types: `if`, `if-else`, `switch`

#### if Statement

```c
if (condition)
{
    Statement1;
}
Statement2;
```

If `condition` is true → execute `Statement1`, then `Statement2`. Otherwise, skip to `Statement2`.

#### if-else Statement

```c
if (condition)
{
    Statement1;
}
else
{
    Statement2;
}
Statement3;
```

Shorthand (ternary): `condition ? Statement1 : Statement2;`

#### switch Statement

```c
switch (variable)
{
    case value:
        Statement1;
        break;
    case value:
        Statement2;
        break;
    default:
        Statement3;
}
```

**Example:**
```c
unsigned char ucNum1, ucNum2;
ucNum1 = 10 * 3;          // ucNum1 = 30
if (ucNum1 == 30)
{
    ucNum2 = 10 - 3;      // ucNum2 = 7
}
ucNum1++;                 // ucNum1 = 31
// Result: ucNum1 = 31, ucNum2 = 7
```

---

### Checkpoint Questions (Section 1.3 Part I)

**Q1.** Best data type for value `-129`:
- **A. signed short** ✓ *(range: -32768 to 32767)*
- B. unsigned int
- C. <!-- id:052bfbdb-f568-46d6-ad01-95feddce4e43 ts:2026-05-17 07:49 -->
