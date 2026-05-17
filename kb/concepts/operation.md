---
id: "7111c010-e752-4ccf-8239-1a3ce3a958de"
title: "Operation"
type: vault_note
vault: wiki
created: 2026-05-17
updated: 2026-05-17
checksum: "sha256:93038dce6b3666fc"
source: heimdall/auto
---

# Operation

- ]----[ ]------( )----|
```

**Operation:** Press PB3 (X101) to turn on internal relay R1. R1 activates timer SR1C which controls Y121 blinking at 1Hz. Press PB4 (X100) to turn off R1 and stop the blinking.

---

### Task 3: Delayed Turn-On (Rung 0 & 6)

**I/O Mapping:**
- PB5 → X102 (Normally Closed in circuit)
- PB6 → X103 (Normally Open)
- LED → Y120
- Timer → TMY1 (U5 = 5 seconds)

<details>
<summary>Ladder Diagram (Mermaid - Click to expand)</summary>

```mermaid
flowchart LR
    subgraph Rung0["Rung 0"]
        A[X102<br/>PB5<br/>NC] --> B{Parallel}
        B --> C[R1<br/>Latch<br/>NO]
        B --> D[X103<br/>PB6<br/>NO]
        C --> E[(R1<br/>Relay)]
        D --> E
    end

    subgraph Rung6["Rung 6"]
        F[R1<br/>NO] --> G[TMY1<br/>Timer<br/>5s]
    end

    subgraph Rung12["Rung 12"]
        H[T1<br/>NO] --> I{Parallel}
        I --> J[Y120<br/>Latch<br/>NO]
        I --> K[X103<br/>PB6<br/>NO]
        J --> L[(Y120<br/>LED)]
        K --> L
    end

    E -.-> F
    G -.-> H

    style A fill:#FFB6C1,stroke:#333
    style C fill:#87CEEB,stroke:#333
    style E fill:#FFD700,stroke:#333
    style G fill:#FFA500,stroke:#333
    style J fill:#87CEEB,stroke:#333
    style L fill:#FFD700,stroke:#333
```

</details>

**Ladder Diagram (ASCII):**
```
Rung 0:
     X102           R1
|----[ ]--------+---( )----|
|               |
|     R1   X103 |
|----[ ]----[/]-+

Rung 6:
     R1
|----[ ]----[TMY1][U5]--------|

Rung 12:
     T1              Y120
|----[ ]---------+---- <!-- id:7111c010-e752-4ccf-8239-1a3ce3a958de ts:2026-05-17 07:49 -->
- ]----[ ]------( )----|
```

**Operation:** Press PB3 (X101) to turn on internal relay R1. R1 activates timer SR1C which controls Y121 blinking at 1Hz. Press PB4 (X100) to turn off R1 and stop the blinking.

---

### Task 3: Delayed Turn-On (Rung 0 & 6)

**I/O Mapping:**
- PB5 → X102 (Normally Closed in circuit)
- PB6 → X103 (Normally Open)
- LED → Y120
- Timer → TMY1 (U5 = 5 seconds)

<details>
<summary>Ladder Diagram (Mermaid - Click to expand)</summary>

```mermaid
flowchart LR
    subgraph Rung0["Rung 0"]
        A[X102<br/>PB5<br/>NC] --> B{Parallel}
        B --> C[R1<br/>Latch<br/>NO]
        B --> D[X103<br/>PB6<br/>NO]
        C --> E[(R1<br/>Relay)]
        D --> E
    end

    subgraph Rung6["Rung 6"]
        F[R1<br/>NO] --> G[TMY1<br/>Timer<br/>5s]
    end

    subgraph Rung12["Rung 12"]
        H[T1<br/>NO] --> I{Parallel}
        I --> J[Y120<br/>Latch<br/>NO]
        I --> K[X103<br/>PB6<br/>NO]
        J --> L[(Y120<br/>LED)]
        K --> L
    end

    E -.-> F
    G -.-> H

    style A fill:#FFB6C1,stroke:#333
    style C fill:#87CEEB,stroke:#333
    style E fill:#FFD700,stroke:#333
    style G fill:#FFA500,stroke:#333
    style J fill:#87CEEB,stroke:#333
    style L fill:#FFD700,stroke:#333
```

</details>

**Ladder Diagram (ASCII):**
```
Rung 0:
     X102           R1
|----[ ]--------+---( )----|
|               |
|     R1   X103 |
|----[ ]----[/]-+

Rung 6:
     R1
|----[ ]----[TMY1][U5]--------|

Rung 12:
     T1              Y120
|----[ ]---------+---- <!-- id:7111c010-e752-4ccf-8239-1a3ce3a958de ts:2026-05-17 07:49 -->
