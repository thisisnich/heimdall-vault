---
id: "405a2c7b-7970-4011-9019-d48bff06120b"
title: "Chart Shows The Flow Of"
type: vault_note
vault: wiki
created: 2026-05-17
updated: 2026-05-17
checksum: "sha256:90c97f2e829a1abe"
source: heimdall/auto
---

# Chart Shows The Flow Of

- chart shows the flow of the program to convert a binary number to decimal number.

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
    unsigned int uiBinaryNumbe <!-- id:405a2c7b-7970-4011-9019-d48bff06120b ts:2026-05-17 07:49 -->
- chart shows the flow of the program to convert a binary number to decimal number.

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
    unsigned int uiBinaryNumbe <!-- id:405a2c7b-7970-4011-9019-d48bff06120b ts:2026-05-17 07:49 -->
