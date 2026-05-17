---
id: "c5aa2022-235e-4d79-833c-0fae683955ee"
title: "Dress Of The Data Is"
type: vault_note
vault: wiki
created: 2026-05-17
updated: 2026-05-17
checksum: "sha256:247facc65dea0564"
source: heimdall/auto
---

# Dress Of The Data Is

- dress of the data** is passed to the function.
- Changes **do affect** the original data.

```c
void cube(unsigned int* ptrData)
{
    *ptrData = (*ptrData) * (*ptrData) * (*ptrData);
}
// uiNum becomes 125
```

---

### Checkpoint Questions (Section 1.3 Part II)

**Q1.** Values after `do { ucNum1--; ucNum2 -= 1; } while(ucNum1 && ucNum2);` starting from 5:
- A. ucNum1 = -1, ucNum2 = -1
- **B. ucNum1 = 0, ucNum2 = 0** ✓
- C. ucNum1 = 1, ucNum2 = 1

**Q2.** Value of `ucNum2` after shifting left 7 times from `0x01`:
- A. `ucNum2 = 0x40`
- **B. `ucNum2 = 0x80`** ✓
- C. `ucNum2 = 0x01`

**Q3.** Which argument passing method affects the original data?
- A. Pass by value
- **B. Pass by reference** ✓

**Q4.** Variable in `cube()` that stores data passed from `uiNum`:
- A. cube
- **B. uiData** ✓
- C. uiAnswer

**Q5.** What is passed to `square(&uiNum)`?
- A. Data of uiNum
- **B. Memory address of uiNum** ✓

---

*End of Chapter 1* <!-- id:c5aa2022-235e-4d79-833c-0fae683955ee ts:2026-05-17 07:49 -->
