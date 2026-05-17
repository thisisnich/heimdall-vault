---
id: "82c9de46-9715-402b-b81f-f5419a0f5d2f"
title: "While Ucnum1 5"
type: vault_note
vault: wiki
created: 2026-05-17
updated: 2026-05-17
checksum: "sha256:cc91a82422a50bcc"
source: heimdall/auto
---

# While Ucnum1 5

- while (ucNum1 != 5)
{
    ucNum1++;
}
// Result: ucNum1 = 5
```

---

### Functions

A **function** is a block of code that performs a specific task. Every C program has at least one function: `main()`.

**Purpose:** Divide large code into smaller modules to improve **reusability** and **readability**.

**Two types:**
- **Standard C library functions** (e.g., from `stdlib.h`, `stdio.h`, `stdint.h`, `float.h`, `string.h`, `time.h`, `math.h`)
- **User-defined functions**

#### Function Structure

```c
// Function Declaration / Prototype
unsigned int square(unsigned int ucNum1);

// Function Definition
unsigned int square(unsigned int ucNum1)
{
    ...;
    return uiResult;
}

// Main Function with Function Call
int main(void)
{
    unsigned int uiAnswer = 0;
    uiAnswer = square(2);
    return 0;
}
```

#### Function Formats

- With arguments and with return value
- With arguments and without return value
- Without arguments and with return value
- Without arguments and without return value

---

#### Passing Arguments

**Pass by Value**
- A **copy of the data** is made and processed in the function.
- Changes do **not affect** the original data.

```c
unsigned int cube(unsigned int uiData)
{
    uiData = uiData * uiData * uiData;
    return uiData;
}
// uiNum remains 5; uiAnswer becomes 125
```

**Pass by Reference**
- The **address of the data** is passed to the function.
- Changes **do affect** the original data.

```c
void cube(unsigned int* ptrData)
{
    *ptrData = (*pt <!-- id:82c9de46-9715-402b-b81f-f5419a0f5d2f ts:2026-05-17 07:49 -->
- while (ucNum1 != 5)
{
    ucNum1++;
}
// Result: ucNum1 = 5
```

---

### Functions

A **function** is a block of code that performs a specific task. Every C program has at least one function: `main()`.

**Purpose:** Divide large code into smaller modules to improve **reusability** and **readability**.

**Two types:**
- **Standard C library functions** (e.g., from `stdlib.h`, `stdio.h`, `stdint.h`, `float.h`, `string.h`, `time.h`, `math.h`)
- **User-defined functions**

#### Function Structure

```c
// Function Declaration / Prototype
unsigned int square(unsigned int ucNum1);

// Function Definition
unsigned int square(unsigned int ucNum1)
{
    ...;
    return uiResult;
}

// Main Function with Function Call
int main(void)
{
    unsigned int uiAnswer = 0;
    uiAnswer = square(2);
    return 0;
}
```

#### Function Formats

- With arguments and with return value
- With arguments and without return value
- Without arguments and with return value
- Without arguments and without return value

---

#### Passing Arguments

**Pass by Value**
- A **copy of the data** is made and processed in the function.
- Changes do **not affect** the original data.

```c
unsigned int cube(unsigned int uiData)
{
    uiData = uiData * uiData * uiData;
    return uiData;
}
// uiNum remains 5; uiAnswer becomes 125
```

**Pass by Reference**
- The **address of the data** is passed to the function.
- Changes **do affect** the original data.

```c
void cube(unsigned int* ptrData)
{
    *ptrData = (*pt <!-- id:82c9de46-9715-402b-b81f-f5419a0f5d2f ts:2026-05-17 07:49 -->
