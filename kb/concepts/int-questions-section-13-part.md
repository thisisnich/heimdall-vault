---
id: "b69c4c86-de0a-4a23-8602-a3313d2137d3"
title: "Int Questions Section 13 Part"
type: vault_note
vault: wiki
created: 2026-05-17
updated: 2026-05-17
checksum: "sha256:a5906dc7723b7dba"
source: heimdall/auto
---

# Int Questions Section 13 Part

- int Questions (Section 1.3 Part I)

**Q1.** Best data type for value `-129`:
- **A. signed short** ✓ *(range: -32768 to 32767)*
- B. unsigned int
- C. float

**Q2.** Correct pointer declaration for a `float` variable named `ptrHeight`:
- A. `int ptrHeight;`
- **B. `float * ptrHeight;`** ✓
- C. `char * ptrHeight;`

**Q3.** Value of `ucNum1` after `ucNum1 = 0x01; ucNum1 <<= 7;`:
- A. `ucNum1 = 0x40`
- **B. `ucNum1 = 0x80`** ✓ *(0x01 shifted left 7 = 0x80)*
- C. `ucNum1 = 0x01`

**Q4.** Value of `ucNum1` after `ucNum1 = 10 + 3; if (ucNum1 > 12) { ucNum2 |= 0x03; } else { ucNum1++; }`:
- A. `ucNum1 = 12`
- **B. `ucNum1 = 13`** ✓ *(13 > 12, so if-branch executes; ucNum1 unchanged)*
- C. `ucNum1 = 14`

**Q5.** Value of `ucNum2` after `ucNum1 = 10 - 3; ucNum2 = 0x0F; switch(ucNum1) { case 7: ucNum2 &= 0xF0; ... }`:
- A. `ucNum2 = 0x0F`
- **B. `ucNum2 = 0xF0`** ✓ *(0x0F & 0xF0 = 0x00... wait — 0x0F AND 0xF0 = 0x00)*

> **Correction:** `0x0F & 0xF0 = 0x00`. <!-- id:b69c4c86-de0a-4a23-8602-a3313d2137d3 ts:2026-05-17 07:49 -->
- int Questions (Section 1.3 Part I)

**Q1.** Best data type for value `-129`:
- **A. signed short** ✓ *(range: -32768 to 32767)*
- B. unsigned int
- C. float

**Q2.** Correct pointer declaration for a `float` variable named `ptrHeight`:
- A. `int ptrHeight;`
- **B. `float * ptrHeight;`** ✓
- C. `char * ptrHeight;`

**Q3.** Value of `ucNum1` after `ucNum1 = 0x01; ucNum1 <<= 7;`:
- A. `ucNum1 = 0x40`
- **B. `ucNum1 = 0x80`** ✓ *(0x01 shifted left 7 = 0x80)*
- C. `ucNum1 = 0x01`

**Q4.** Value of `ucNum1` after `ucNum1 = 10 + 3; if (ucNum1 > 12) { ucNum2 |= 0x03; } else { ucNum1++; }`:
- A. `ucNum1 = 12`
- **B. `ucNum1 = 13`** ✓ *(13 > 12, so if-branch executes; ucNum1 unchanged)*
- C. `ucNum1 = 14`

**Q5.** Value of `ucNum2` after `ucNum1 = 10 - 3; ucNum2 = 0x0F; switch(ucNum1) { case 7: ucNum2 &= 0xF0; ... }`:
- A. `ucNum2 = 0x0F`
- **B. `ucNum2 = 0xF0`** ✓ *(0x0F & 0xF0 = 0x00... wait — 0x0F AND 0xF0 = 0x00)*

> **Correction:** `0x0F & 0xF0 = 0x00`. <!-- id:b69c4c86-de0a-4a23-8602-a3313d2137d3 ts:2026-05-17 07:49 -->
