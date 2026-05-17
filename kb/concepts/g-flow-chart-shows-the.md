---
id: "9b2e50cc-4978-4ad6-b155-4d6aa3a0d5ee"
title: "G Flow Chart Shows The"
type: vault_note
vault: wiki
created: 2026-05-17
updated: 2026-05-17
checksum: "sha256:45bf7ec9f4c639b2"
source: heimdall/auto
---

# G Flow Chart Shows The

- g flow chart shows the flow of the program to find the largest number of an array.

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
Complete the code below while entering it into CCS IDE. <!-- id:9b2e50cc-4978-4ad6-b155-4d6aa3a0d5ee ts:2026-05-17 07:49 -->
