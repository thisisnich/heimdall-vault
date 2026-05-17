---
id: "e441b6fa-4bb1-452c-b51e-e35be6d79c21"
title: "Or Auto Close Question 3"
type: vault_note
vault: wiki
created: 2026-05-17
updated: 2026-05-17
checksum: "sha256:600062401b867b2f"
source: heimdall/auto
---

# Or Auto Close Question 3

- or auto-close.
### Question 3
A PLC is used to control a conveyor system. A sensor X5 with a normally open contact sees items passing on the conveyor. When 10 items have passed, the conveyor motor Y3 stops, a cylinder Y1 extends and retracts after 2 seconds, and the conveyor runs again until another 10 items have passed.
conveyor belt
cylinder
Automation Systems & Control
Page 1 of 1
Effective date: 16 Oct 2023

**Solution:**
```
Rung 1:
|--[X111]-------------------------------------------[CT1]--|
|                                                   [   ]
|--[T1]---------------------------------------------[U10]--|

Rung 2:
|--[/C1]-------------------------------------------(Y122)--|

Rung 3:
|--[C1]--------------------------------------------(Y125)--|

Rung 4:
|--[C1]-----------------------------[TMY1 | U2]--|

Rung 5:
|--[/C1]--[ ]--------------------------------------(Y124)--|
```

**How the ladder diagram works:**

This is a conveyor counting system with automatic stop and cylinder actuation.

- **Rung 1 (Counter setup):** When sensor X111 detects an item (pulse), it increments counter CT1. The bottom input (T1) is the reset - when T1 is ON, it resets the counter to 0. The preset U10 means the counter will complete after 10 items.

- **Rung 2 (Conveyor motor control):** When counter C1 is NOT complete ([/C1] is closed), the conveyor motor Y122 runs. <!-- id:e441b6fa-4bb1-452c-b51e-e35be6d79c21 ts:2026-05-17 07:49 -->
- or auto-close.
### Question 3
A PLC is used to control a conveyor system. A sensor X5 with a normally open contact sees items passing on the conveyor. When 10 items have passed, the conveyor motor Y3 stops, a cylinder Y1 extends and retracts after 2 seconds, and the conveyor runs again until another 10 items have passed.
conveyor belt
cylinder
Automation Systems & Control
Page 1 of 1
Effective date: 16 Oct 2023

**Solution:**
```
Rung 1:
|--[X111]-------------------------------------------[CT1]--|
|                                                   [   ]
|--[T1]---------------------------------------------[U10]--|

Rung 2:
|--[/C1]-------------------------------------------(Y122)--|

Rung 3:
|--[C1]--------------------------------------------(Y125)--|

Rung 4:
|--[C1]-----------------------------[TMY1 | U2]--|

Rung 5:
|--[/C1]--[ ]--------------------------------------(Y124)--|
```

**How the ladder diagram works:**

This is a conveyor counting system with automatic stop and cylinder actuation.

- **Rung 1 (Counter setup):** When sensor X111 detects an item (pulse), it increments counter CT1. The bottom input (T1) is the reset - when T1 is ON, it resets the counter to 0. The preset U10 means the counter will complete after 10 items.

- **Rung 2 (Conveyor motor control):** When counter C1 is NOT complete ([/C1] is closed), the conveyor motor Y122 runs. <!-- id:e441b6fa-4bb1-452c-b51e-e35be6d79c21 ts:2026-05-17 07:49 -->
