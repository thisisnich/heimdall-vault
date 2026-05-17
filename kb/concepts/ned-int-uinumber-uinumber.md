---
id: "9200c01f-62a2-4359-ac26-946b857c0d1b"
title: "Ned Int Uinumber Uinumber"
type: vault_note
vault: wiki
created: 2026-05-17
updated: 2026-05-17
checksum: "sha256:2cd08466b3ddae48"
source: heimdall/auto
---

# Ned Int Uinumber Uinumber

- ned int uiNumber;
    uiNumber = 10;
    do
    {
        uiNumber /= 3;
    }
    while(uiNumber != 0);
}
```

**Options:**
- A. 0
- B. 1
- C. 3
- D. 10

**Answer:** A (0)

---

### Question 4
Refer to the program below, all the numbers have been assigned to the variable `uiNumber` in the do-while loop EXCEPT:

```c
int main(void)
{
    unsigned int uiNumber;
    uiNumber = 10;
    do
    {
        uiNumber += 2;
    }
    while(uiNumber < 20);
}
```

**Options:**
- A. 12
- B. 16
- C. 20
- D. 24

**Answer:** D (24 - the loop stops when uiNumber reaches 20, so 24 is never assigned)

---

### Question 5
What is the value of `ucNum2` after executing the following program?

```c
int main(void)
{
    unsigned char ucNum1, ucNum2;
    ucNum2 = 0x80;
    for (ucNum1=7; ucNum1>0; ucNum1--)
    {
        ucNum2 >>= 1;
    }
}
```

**Options:**
- A. 0x01
- B. 0x02
- C. 0x04
- D. 0x08

**Answer:** A (0x01 - right shift 7 times: 0x80 → 0x40 → 0x20 → 0x10 → 0x08 → 0x04 → 0x02 → 0x01)

---

### Question 6
What is the value of `uiFactorial` after executing the following program?

```c
int main(void)
{
    unsigned int uiNumber, i, uiFactorial;
    uiNumber = 5;
    uiFactorial = 1;
    for(i=1; i<=uiNumber; i++)
    {
        uiFactorial *= i;
    }
}
```

**Options:**
- A. 2
- B. 6
- C. 24
- D. <!-- id:9200c01f-62a2-4359-ac26-946b857c0d1b ts:2026-05-17 07:49 -->
- ned int uiNumber;
    uiNumber = 10;
    do
    {
        uiNumber /= 3;
    }
    while(uiNumber != 0);
}
```

**Options:**
- A. 0
- B. 1
- C. 3
- D. 10

**Answer:** A (0)

---

### Question 4
Refer to the program below, all the numbers have been assigned to the variable `uiNumber` in the do-while loop EXCEPT:

```c
int main(void)
{
    unsigned int uiNumber;
    uiNumber = 10;
    do
    {
        uiNumber += 2;
    }
    while(uiNumber < 20);
}
```

**Options:**
- A. 12
- B. 16
- C. 20
- D. 24

**Answer:** D (24 - the loop stops when uiNumber reaches 20, so 24 is never assigned)

---

### Question 5
What is the value of `ucNum2` after executing the following program?

```c
int main(void)
{
    unsigned char ucNum1, ucNum2;
    ucNum2 = 0x80;
    for (ucNum1=7; ucNum1>0; ucNum1--)
    {
        ucNum2 >>= 1;
    }
}
```

**Options:**
- A. 0x01
- B. 0x02
- C. 0x04
- D. 0x08

**Answer:** A (0x01 - right shift 7 times: 0x80 → 0x40 → 0x20 → 0x10 → 0x08 → 0x04 → 0x02 → 0x01)

---

### Question 6
What is the value of `uiFactorial` after executing the following program?

```c
int main(void)
{
    unsigned int uiNumber, i, uiFactorial;
    uiNumber = 5;
    uiFactorial = 1;
    for(i=1; i<=uiNumber; i++)
    {
        uiFactorial *= i;
    }
}
```

**Options:**
- A. 2
- B. 6
- C. 24
- D. <!-- id:9200c01f-62a2-4359-ac26-946b857c0d1b ts:2026-05-17 07:49 -->
