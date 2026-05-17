---
id: "9c680e0b-56e9-445a-acfc-4379f57388fc"
title: "Return Iresult Int"
type: vault_note
vault: wiki
created: 2026-05-17
updated: 2026-05-17
checksum: "sha256:abb33244fc4563fe"
source: heimdall/auto
---

# Return Iresult Int

- ……;
    return iResult;
}

int main(void)
{
    ……;
    char iRes = Demo(1.234, 43);
    ……;
}
```

**Options:**
- A. char
- B. float
- C. int
- D. double

**Answer:** A (char - the function signature shows it returns a char)

---

### Question 10
What is the value of `i1stNumber` and `i2ndNumber` after executing the following program?

```c
void Swap(int *iNumber1, int *iNumber2)
{
    int iTempNumber;
    iTempNumber = *iNumber1;
    *iNumber1 = *iNumber2;
    *iNumber2 = iTempNumber;
}

int main(void)
{
    int i1stNumber, i2ndNumber;
    i1stNumber = 24;
    i2ndNumber = 42;
    Swap(&i1stNumber, &i2ndNumber);
}
```

**Options:**
- A. i1stNumber = 24 and i2ndNumber = 42
- B. i1stNumber = 42 and i2ndNumber = 24
- C. i1stNumber = 22 and i2ndNumber = 44
- D. i1stNumber = 44 and i2ndNumber = 22

**Answer:** B (i1stNumber = 42 and i2ndNumber = 24 - the values are swapped using pointers) <!-- id:9c680e0b-56e9-445a-acfc-4379f57388fc ts:2026-05-17 07:49 -->
- ……;
    return iResult;
}

int main(void)
{
    ……;
    char iRes = Demo(1.234, 43);
    ……;
}
```

**Options:**
- A. char
- B. float
- C. int
- D. double

**Answer:** A (char - the function signature shows it returns a char)

---

### Question 10
What is the value of `i1stNumber` and `i2ndNumber` after executing the following program?

```c
void Swap(int *iNumber1, int *iNumber2)
{
    int iTempNumber;
    iTempNumber = *iNumber1;
    *iNumber1 = *iNumber2;
    *iNumber2 = iTempNumber;
}

int main(void)
{
    int i1stNumber, i2ndNumber;
    i1stNumber = 24;
    i2ndNumber = 42;
    Swap(&i1stNumber, &i2ndNumber);
}
```

**Options:**
- A. i1stNumber = 24 and i2ndNumber = 42
- B. i1stNumber = 42 and i2ndNumber = 24
- C. i1stNumber = 22 and i2ndNumber = 44
- D. i1stNumber = 44 and i2ndNumber = 22

**Answer:** B (i1stNumber = 42 and i2ndNumber = 24 - the values are swapped using pointers) <!-- id:9c680e0b-56e9-445a-acfc-4379f57388fc ts:2026-05-17 07:49 -->
