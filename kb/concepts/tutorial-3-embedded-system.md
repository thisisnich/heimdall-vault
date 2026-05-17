---
id: "05f3828e-a047-48a8-98c6-3c9208edfb65"
title: "Tutorial 3 Embedded System"
type: vault_note
vault: wiki
created: 2026-05-17
updated: 2026-05-17
checksum: "sha256:a4fca08ebaf3edc6"
source: heimdall/auto
---

# Tutorial 3 Embedded System

- # Tutorial 3: Embedded System Programming II

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
- D. <!-- id:05f3828e-a047-48a8-98c6-3c9208edfb65 ts:2026-05-17 07:49 -->
- # Tutorial 3: Embedded System Programming II

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
- D. <!-- id:05f3828e-a047-48a8-98c6-3c9208edfb65 ts:2026-05-17 07:49 -->
