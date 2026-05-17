---
id: "5f69e990-a789-4941-9202-cdda7b0c321b"
title: "W Chart Shows The Flow"
type: vault_note
vault: wiki
created: 2026-05-17
updated: 2026-05-17
checksum: "sha256:1e8eca180e0a8b7a"
source: heimdall/auto
---

# W Chart Shows The Flow

- w chart shows the flow of the program to count the number of digits of an integer.

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
Complete the code below while entering it into CCS IDE. <!-- id:5f69e990-a789-4941-9202-cdda7b0c321b ts:2026-05-17 07:49 -->
