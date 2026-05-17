---
id: "3bd276aa-48b4-4275-9474-50e906a895bd"
title: "A Gpio   B Adc"
type: vault_note
vault: wiki
created: 2026-05-17
updated: 2026-05-17
checksum: "sha256:f3f25fd2e6e65592"
source: heimdall/auto
---

# A Gpio   B Adc

- A. GPIO
- **B. ADC** ✓ *(Answer)*
- C. PWM

**Q3.** Which of the following is NOT the hardware tool needed to set up the development environment?
- A. Host PC
- B. Development Board
- C. Debug Probe
- **D. Debugger** ✓ *(Answer — Debugger is a software tool)*

---

## 1.3 Embedded System Programming

### Subtopics
- **Programming I:** C for Embedded System, C Program Structure and Sections, Basic Data Type and Modifier, Variable / Array / Pointer, Operators, Conditional Statements
- **Programming II:** Loop Statements, Functions

---

## Embedded System Programming I

### C for Embedded System

- C is perhaps the **most popular** programming language in embedded systems.
- Advantages: **portability**, **better code efficiency with reduced overhead**, **shorter development time**.
- Offers **low-level hardware control** and is more readable than assembly language.
- Many C compilers are available for a wide variety of development platforms.

---

### C Program Structure and Sections

```c
// This is a simple program          ← Documentation Section

#include <stdint.h>                  ← Link Section

#define PI 3.14                      ← Definition Section

uint8_t ui8Counter;                  ← Global Declaration Section
uint32_t Function1 (uint8_t x);

int main (void)                      ← Main Function Section
{
    while(1);
    return 0;
}

uint32_t Function1 (uint8_t x)       ← Sub Program Section
{
    return result;
}
```

| Section | Purpose |
|---------|---------| <!-- id:3bd276aa-48b4-4275-9474-50e906a895bd ts:2026-05-17 07:49 -->
