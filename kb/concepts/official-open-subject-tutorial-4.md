---
id: "b4fd4e47-56a1-4dd5-99bf-a350509ce04c"
title: "Official Open Subject Tutorial 4"
type: vault_note
vault: wiki
created: 2026-05-17
updated: 2026-05-17
checksum: "sha256:9ab9151d543bca28"
source: heimdall/auto
---

# Official Open Subject Tutorial 4

- Official (Open)
Subject
Tutorial 4
Automation Systems & Control (EGE351)
Automation Control
For the following applications, prepare an input-output (I/O) table and write a PLC ladder
program to implement them.
### Question 1
A PLC is used to control a conveyor system. Sensor 1 detects objects coming down the conveyor. The motion of the conveyor is indicated by a red LED. When five objects are detected, the conveyor stops and turns on a green LED.

**Solution:**
```
Rung 1:
|--[X111]-------------------------------------------[CT1]--|
|                                                   [   ]
|--[T1]---------------------------------------------[U10]--|

Rung 2:
|--[/C1]------------------------------------------(Y122)--|

Rung 3:
|--[C1]-------------------------------------------(Y125)--|
```

**How the ladder diagram works:**

This is a conveyor counting system that stops after 5 objects and changes LED status.

- **Rung 1 (Counter setup):** When sensor X111 detects an object (pulse), it increments counter CT1. The bottom input (T1) is the reset - when T1 is ON, it resets the counter to 0. The preset U10 means the counter will complete after 10 counts (note: the question says 5 objects, but the diagram shows U10 - this may need adjustment to U5 for 5 objects).

- **Rung 2 (Conveyor motor/red LED control):** When counter C1 is NOT complete ([/C1] is closed), the conveyor motor/red LED Y122 runs. <!-- id:b4fd4e47-56a1-4dd5-99bf-a350509ce04c ts:2026-05-17 07:49 -->
- Official (Open)
Subject
Tutorial 4
Automation Systems & Control (EGE351)
Automation Control
For the following applications, prepare an input-output (I/O) table and write a PLC ladder
program to implement them.
### Question 1
A PLC is used to control a conveyor system. Sensor 1 detects objects coming down the conveyor. The motion of the conveyor is indicated by a red LED. When five objects are detected, the conveyor stops and turns on a green LED.

**Solution:**
```
Rung 1:
|--[X111]-------------------------------------------[CT1]--|
|                                                   [   ]
|--[T1]---------------------------------------------[U10]--|

Rung 2:
|--[/C1]------------------------------------------(Y122)--|

Rung 3:
|--[C1]-------------------------------------------(Y125)--|
```

**How the ladder diagram works:**

This is a conveyor counting system that stops after 5 objects and changes LED status.

- **Rung 1 (Counter setup):** When sensor X111 detects an object (pulse), it increments counter CT1. The bottom input (T1) is the reset - when T1 is ON, it resets the counter to 0. The preset U10 means the counter will complete after 10 counts (note: the question says 5 objects, but the diagram shows U10 - this may need adjustment to U5 for 5 objects).

- **Rung 2 (Conveyor motor/red LED control):** When counter C1 is NOT complete ([/C1] is closed), the conveyor motor/red LED Y122 runs. <!-- id:b4fd4e47-56a1-4dd5-99bf-a350509ce04c ts:2026-05-17 07:49 -->
