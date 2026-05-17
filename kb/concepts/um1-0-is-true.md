---
id: "be8bc454-2187-4f22-860d-2b79e74834d6"
title: "Um1 0 Is True"
type: vault_note
vault: wiki
created: 2026-05-17
updated: 2026-05-17
checksum: "sha256:3c76366dc89d79a9"
source: heimdall/auto
---

# Um1 0 Is True

- um1 != 0` is true, so `ucNum2--` is executed. This decrements `ucNum2` from 0 to 255 (0xFF).

EGE320 Tut 2
Page 2 of 3
Effective Date: 1 Apr 2022
- 9.  Refer  to  the  program  below,  under  what  condition  the  statement  inside  the  if  {  }  will  NOT  be
executed?
int main(void)
{
unsigned int condition1, condition2, result;
if (condition1 || condition2)
{
result = 1 + 2;
}
}
A.  when condition1 = 0 and condition2 = 0.
B.  when condition1 = 0 and condition2 = 1.
C.  when condition1 = 1 and condition2 = 0.
D.  when condition1 = 1 and condition2 = 1.

Ans: A
Explanation: The `||` (logical OR) operator returns true if at least one condition is true. The statement inside the if block will NOT be executed only when both conditions are false (0).

10. What is the value of ucNum2 after executing the following program?
int main(void)
{
unsigned char ucNum1, ucNum2;
ucNum1 = 10 - 2;
ucNum2 = 0x0F;
switch(ucNum1)
{
case 6: ucNum2 >>= 2; break;
case 7: ucNum2 &= 0xF0; break;
case 8: ucNum2 ^= 0xF0;
default: ucNum2 <<= 4;
}
}
A.  0x00
B.  0xFF
C.  0xF0
D.  0x0F

Ans: C
Explanation: `ucNum1 = 10 - 2 = 8`. The `switch` statement matches `case 8`, so `ucNum2 ^= 0xF0` is executed. `0x0F ^ 0xF0 = 0xF0`. Then `default: ucNum2 <<= 4` is executed, which shifts `0xFF` left by 4 bits, resulting in `0xFF0`. Since `ucNum2` is an 8-bit unsigned char, the result is truncated to `0xF0`.

EGE320 Tut 2
Page 3 of 3
Effective Date: 1 Apr 2022

--- <!-- id:be8bc454-2187-4f22-860d-2b79e74834d6 ts:2026-05-17 07:49 -->
- um1 != 0` is true, so `ucNum2--` is executed. This decrements `ucNum2` from 0 to 255 (0xFF).

EGE320 Tut 2
Page 2 of 3
Effective Date: 1 Apr 2022
- 9.  Refer  to  the  program  below,  under  what  condition  the  statement  inside  the  if  {  }  will  NOT  be
executed?
int main(void)
{
unsigned int condition1, condition2, result;
if (condition1 || condition2)
{
result = 1 + 2;
}
}
A.  when condition1 = 0 and condition2 = 0.
B.  when condition1 = 0 and condition2 = 1.
C.  when condition1 = 1 and condition2 = 0.
D.  when condition1 = 1 and condition2 = 1.

Ans: A
Explanation: The `||` (logical OR) operator returns true if at least one condition is true. The statement inside the if block will NOT be executed only when both conditions are false (0).

10. What is the value of ucNum2 after executing the following program?
int main(void)
{
unsigned char ucNum1, ucNum2;
ucNum1 = 10 - 2;
ucNum2 = 0x0F;
switch(ucNum1)
{
case 6: ucNum2 >>= 2; break;
case 7: ucNum2 &= 0xF0; break;
case 8: ucNum2 ^= 0xF0;
default: ucNum2 <<= 4;
}
}
A.  0x00
B.  0xFF
C.  0xF0
D.  0x0F

Ans: C
Explanation: `ucNum1 = 10 - 2 = 8`. The `switch` statement matches `case 8`, so `ucNum2 ^= 0xF0` is executed. `0x0F ^ 0xF0 = 0xF0`. Then `default: ucNum2 <<= 4` is executed, which shifts `0xFF` left by 4 bits, resulting in `0xFF0`. Since `ucNum2` is an 8-bit unsigned char, the result is truncated to `0xF0`.

EGE320 Tut 2
Page 3 of 3
Effective Date: 1 Apr 2022

--- <!-- id:be8bc454-2187-4f22-860d-2b79e74834d6 ts:2026-05-17 07:49 -->
