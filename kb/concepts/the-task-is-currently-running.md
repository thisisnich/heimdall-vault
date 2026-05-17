---
id: "8a6236e6-91b8-44ef-be99-14df30fbfae5"
title: "The Task Is Currently Running"
type: vault_note
vault: wiki
created: 2026-05-17
updated: 2026-05-17
checksum: "sha256:ee90a446f8db0a7f"
source: heimdall/auto
---

# The Task Is Currently Running

- the task is currently running.
Effective Date: 1/4/2022
15
Official (Open)
Objects - Task
Effective Date: 1/4/2022
16
Task States
Official (Open)
Objects - Semaphore
• Semaphore is a kernel object that one or more threads of execution can acquire or release for
the purpose of synchronization or mutual exclusion (prevents simultaneous access to a shared
resource).
• A semaphore is like a key that allows a task to carry out some operation or to access a resource. If
the task can acquire the semaphore, it can carry out the intended operation. Once the operation is
done, the task can release the semaphore.
• When a semaphore is first created, the kernel assigns to it a semaphore control bloc (SCB), a
unique ID, a value and a task-waiting list.
• There are three types of semaphore: binary, counting and mutex semaphore.
Effective Date: 1/4/2022
17
Official (Open)
Objects - Semaphore
• Binary Semaphore
• A binary semaphore can have a value of either 0 or 1.
• When a binary semaphore’s value is 0, it is considered unavailable.
• When a binary semaphore’s value is 1, it is considered available.
Effective Date: 1/4/2022
18
Official (Open)
Objects - Semaphore
• Counting Semaphore
• A counting semaphore uses a count to allow it to be acquired or released multiple times.
• When a counting semaphore’s value is 0, it is considered unavailable.
• When a counting semaphore’s value is greater than 0, it is considered available.
Effective Date: 1/4/2022
19
Official (Open)
Objects - Semaphore
• <!-- id:8a6236e6-91b8-44ef-be99-14df30fbfae5 ts:2026-05-17 07:49 -->
