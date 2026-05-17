---
tags:
  - EGE320
  - lab
  - C-programming
  - embedded-systems
course: EGE320 Embedded System Design & Technology
topic: Lab 3 - Embedded System Programming II
source: EGE320 - Lab3 Embedded System Programming II.pdf
converted: 2026-05-07
---

# Lab 3 - Embedded System Programming II

## Course Information

| Field | Details |
|-------|---------|
| **Course** | Diploma in Electronic Systems (EGDF18), Diploma in Electronic & Computer Engineering (EGDF20) |
| **Module** | Embedded System Design & Technology (EGE320) |
| **Lab No.** | Lab 3 |
| **Lab Title** | Embedded System Programming II |

## Objectives

- Recognize different types of data types for variable, array and pointer in C
- Demonstrate the use of arithmetic, comparison, logical, bitwise and assignment operators in C
- Apply conditional and loops statements and functions in C

## Lab Contents

- 1.1 Largest Number of an Array
- 1.2 Digits Counting of an Integer
- 1.3 Binary to Decimal Conversion

---

## 1.1 Largest Number of an Array

### Task 1
The following flow chart shows the flow of the program to find the largest number of an array.

### Task 2
Complete the code below while entering it into CCS IDE. Build to ensure no errors in the code.

```c
int main(void)
{
    unsigned int uiArray[5] = {5, 20, 15, 40, 30};
    unsigned int uiCounter;
    for (uiCounter = 1; uiCounter < 5; uiCounter++)                      //Loop through the array
    {
        if(uiArray[0] < uiArray[uiCounter])             //Check which element is larger
        {
            uiArray[0] = uiArray[uiCounter];            //Store larger number to uiArray[0]
        }
    }
    return 0;
}
```

### Task 3
Debug and single step through the code until return 0 by using F6 key.

### Task 4
Ensure that the observed value from the variable window matches the expected values.

---

## 1.2 Digits Counting of an Integer

### Task 1
The following flow chart shows the flow of the program to count the number of digits of an integer.

### Task 2
Complete the code below while entering it into CCS IDE. Build to ensure no errors in the code.

```c
int main(void)
{
    unsigned int uiNumber, uiDigitCount;
    uiNumber = 2136516;
    uiDigitCount = 0;
    while (uiNumber != 0)            //Loop while uiNumber is not 0
    {
        uiNumber /= 10;             //uiNumber = uiNumber/10
        uiDigitCount++;        //Increase uiDigitCount by 1
    }
    return 0;
}
```

### Task 3
Debug and single step through the code until return 0 by using F6 key.

### Task 4
Ensure that the observed value from the variable window matches the expected values.

---

## 1.3 Binary to Decimal Conversion

### Task 1
The following flow chart shows the flow of the program to convert a binary number to decimal number.

### Task 2
Complete the code below while entering it into CCS IDE. Build to ensure no errors in the code.

```c
#include <math.h>

//Function Declaration
unsigned int convertBinaryToDecimal(unsigned int uiBinNumber);

int main(void)
{
    unsigned int uiBinaryNumber, uiDecimalNumber;
    uiBinaryNumber = 10001001;
    //Passing by value to function
    uiDecimalNumber = convertBinaryToDecimal(uiBinaryNumber);
    return 0;
}
```

### Task 3
Complete the function below:

```c
unsigned int convertBinaryToDecimal(unsigned int uiBinNumber)
{
    unsigned int uiDecNumber, uiRemainder, uiIndex;
    uiDecNumber = 0;
    uiRemainder = 0;
    uiIndex = 0;
    while (uiBinNumber != 0)
    {
        //Divide uiBinNumber by 10 to get the remainder
        uiRemainder = uiBinNumber % 10;
        //Divide uiBinNumber by 10 to get the quotient
        uiBinNumber /= 10;
        //Multiply remainder with 2^uiIndex
        uiDecNumber += uiRemainder*pow(2,uiIndex);
        //Increment uiIndex by 1 for next digit
        uiIndex++;
    }
    return uiDecNumber;
}
```

### Task 4
Debug and single step through the code until return 0 by using F5 and F6 key.

### Task 5
Ensure that the observed value from the variable window matches the expected values.

---
```c
#include <math.h>

//Function Declaration
unsigned int convertBinaryToDecimal(unsigned int uiBinNumber);

int main(void)
{
    unsigned int uiBinaryNumber, uiDecimalNumber;
    uiBinaryNumber = 10001001;
    //Passing by value to function
    uiDecimalNumber = convertBinaryToDecimal(uiBinaryNumber);
    return 0;
}

unsigned int convertBinaryToDecimal(unsigned int uiBinNumber)
{
    unsigned int uiDecNumber, uiRemainder, uiIndex;
    uiDecNumber = 0;
    uiRemainder = 0;
    uiIndex = 0;
    while (uiBinNumber != 0)
    {
        //Divide uiBinNumber by 10 to get the remainder
        uiRemainder = uiBinNumber % 10;
        //Divide uiBinNumber by 10 to get the quotient
        uiBinNumber /= 10;
        //Multiply remainder with 2^uiIndex
        uiDecNumber += uiRemainder*pow(2,uiIndex);
        //Increment uiIndex by 1 for next digit
        uiIndex++;
    }
    return uiDecNumber;
}
```