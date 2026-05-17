---
tags:
  - EGE320
  - tutorial
  - C-programming
  - embedded-systems
course: EGE320 Embedded System Design & Technology
topic: Tutorial 3 - Embedded System Programming II
---

# Tutorial 3: Embedded System Programming II

**Course:** Diploma in Electronic Systems (EGDF18) / Diploma in Electronic & Computer Engineering (EGDF20)  
**Module:** Embedded System Design & Technology (EGE320)

## Learning Objectives

- Describe C program structure
- Recognize different types of data types for variable, array and pointer in C
- Apply arithmetic, comparison, logical, bitwise and assignment operators in C
- Apply conditional and loops statements and functions in C

---

## Questions

### Question 1
What is the value of variable `count` after executing the following program?

```c
int main(void)
{
    unsigned int i, count;
    i = 1;
    count = 0;
    while(i < 5)
    {
        count += 2;
        i++;
    }
}
```

**Options:**
- A. count = 2
- B. count = 4
- C. count = 6
- D. count = 8

**Answer:** D (count = 8)

---

### Question 2
How many times the code `i--;` is executed in the following program?

```c
int main(void)
{
    unsigned int i = 10;
    while(i > 0)
    {
        i--;
        if(i == 4)
            break;
    }
}
```

**Options:**
- A. 4 times
- B. 5 times
- C. 6 times
- D. 7 times

**Answer:** C (6 times)

---

### Question 3
What is the value of variable `uiNumber` after executing the following program?

```c
int main(void)
{
    unsigned int uiNumber;
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
- D. 120

**Answer:** D (120 - factorial of 5: 1×2×3×4×5 = 120)

---

### Question 7
Identify the name of the user-defined function in the following program?

```c
int main(void)
{
    unsigned char ucNum1, ucNum2, ucMax;
    ucNum1 = 0xC2;
    ucNum2 = 0xA3;
    ucMax = findMax(ucNum1, ucNum2);
}
```

**Options:**
- A. ucNum1
- B. ucNum2
- C. ucMax
- D. findMax

**Answer:** D (findMax)

---

### Question 8
What is the value of variable `iResult` after executing the following program?

```c
int Add(int iNum1, int iNum2)
{
    return (iNum1 + iNum2);
}

int main(void)
{
    int iVar1, iVar2, iResult;
    iVar1 = 41;
    iVar2 = 43;
    iResult = Add(iVar1, iVar2);
}
```

**Options:**
- A. 41
- B. 43
- C. 84
- D. 48

**Answer:** C (84 - 41 + 43 = 84)

---

### Question 9
Refer to the program below, what is the return data type of the function `Demo()`?

```c
char Demo(float fNum1, int iNum1)
{
    char iResult;
    ……;
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

**Answer:** B (i1stNumber = 42 and i2ndNumber = 24 - the values are swapped using pointers)
