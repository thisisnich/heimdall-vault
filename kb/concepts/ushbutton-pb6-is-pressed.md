---
id: "5ae20a0b-00ff-4950-a6c0-3d548950127c"
title: "Ushbutton Pb6 Is Pressed"
type: vault_note
vault: wiki
created: 2026-05-17
updated: 2026-05-17
checksum: "sha256:d700f2875c702df8"
source: heimdall/auto
---

# Ushbutton Pb6 Is Pressed

- ushbutton (PB6) is pressed.

### Task 4: Delayed Turn-Off

Write a PLC program to turn an LED (Y122) when a normally-open pushbutton (PB5) is pressed. The LED turns off after 3 seconds, when another normally-open pushbutton (PB6) is pressed.

---

## Understandings

### Question 1

Write and explain a latching PLC program.

### Question 2

Describe the operation of a PLC Timer.

### Question 3

A PB1 (NO) is connected to Timer1. What is the value of T1 if PB1 is released after preset value of the timer.

---

## My Solutions

### Task 1: Latching Circuit (Rung 0)

**I/O Mapping:**
- PB1 → X103 (Normally Open)
- PB2 → X102 (Normally Closed in circuit)
- LED → Y120

<details>
<summary>Ladder Diagram (Mermaid - Click to expand)</summary>

```mermaid
flowchart LR
    A[X103<br/>PB1<br/>NO] --> B{Parallel}
    B --> C[Y120<br/>Latch<br/>NO]
    B --> D[/X102<br/>PB2<br/>NC]
    C --> E[(Y120<br/>LED)]
    D --> E
    style A fill:#90EE90,stroke:#333
    style C fill:#87CEEB,stroke:#333
    style D fill:#FFB6C1,stroke:#333
    style E fill:#FFD700,stroke:#333
```

</details>

**Ladder Diagram (ASCII):**
```
     X103     Y120     Y120
|----[ ]----+----[ ]----( )----|
|           |
|     /X102 |
|----[ ]----+
```

**Operation:** Press PB1 (X103) to turn on Y120. Y120 latches itself on through the parallel branch. <!-- id:5ae20a0b-00ff-4950-a6c0-3d548950127c ts:2026-05-17 07:49 -->
- ushbutton (PB6) is pressed.

### Task 4: Delayed Turn-Off

Write a PLC program to turn an LED (Y122) when a normally-open pushbutton (PB5) is pressed. The LED turns off after 3 seconds, when another normally-open pushbutton (PB6) is pressed.

---

## Understandings

### Question 1

Write and explain a latching PLC program.

### Question 2

Describe the operation of a PLC Timer.

### Question 3

A PB1 (NO) is connected to Timer1. What is the value of T1 if PB1 is released after preset value of the timer.

---

## My Solutions

### Task 1: Latching Circuit (Rung 0)

**I/O Mapping:**
- PB1 → X103 (Normally Open)
- PB2 → X102 (Normally Closed in circuit)
- LED → Y120

<details>
<summary>Ladder Diagram (Mermaid - Click to expand)</summary>

```mermaid
flowchart LR
    A[X103<br/>PB1<br/>NO] --> B{Parallel}
    B --> C[Y120<br/>Latch<br/>NO]
    B --> D[/X102<br/>PB2<br/>NC]
    C --> E[(Y120<br/>LED)]
    D --> E
    style A fill:#90EE90,stroke:#333
    style C fill:#87CEEB,stroke:#333
    style D fill:#FFB6C1,stroke:#333
    style E fill:#FFD700,stroke:#333
```

</details>

**Ladder Diagram (ASCII):**
```
     X103     Y120     Y120
|----[ ]----+----[ ]----( )----|
|           |
|     /X102 |
|----[ ]----+
```

**Operation:** Press PB1 (X103) to turn on Y120. Y120 latches itself on through the parallel branch. <!-- id:5ae20a0b-00ff-4950-a6c0-3d548950127c ts:2026-05-17 07:49 -->
