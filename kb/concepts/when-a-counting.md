---
id: "a7d282ca-ceb4-4ae7-a256-c3323cf7ba0e"
title: "When A Counting"
type: vault_note
vault: wiki
created: 2026-05-17
updated: 2026-05-17
checksum: "sha256:ac90bb33815fd873"
source: heimdall/auto
---

# When A Counting

- .
• When a counting semaphore’s value is greater than 0, it is considered available.
Effective Date: 1/4/2022
19
Official (Open)
Objects - Semaphore
• Counting Semaphore
Effective Date: 1/4/2022
20
Official (Open)
Objects - Semaphore
• Mutex Semaphore
• A mutual exclusion (mutex) semaphore is a special binary semaphore.
•
It allows a task to acquire or lock the mutex to own it. No other task can release or unlock the mutex.
The mutex can only be released or unlocked by the owner that acquire or locked it.
• When a mutex semaphore’s value is 0, it is considered locked.
• When a mutex semaphore’s value is greater than 0, it is considered unlocked.
Effective Date: 1/4/2022
21
Official (Open)
Objects - Semaphore
• Mutex Semaphore
Initial
(lock count = 1)
Acquire
(lock count = 0)
Release
(lock count = 1)
Acquire (recursive)
(lock count = lock count - 1)
Release (recursive)
(lock count = lock count + 1)
Effective Date: 1/4/2022
22
Official (Open)
Objects – Message Queue
• Message Queues are buffer-like kernel object through which tasks and Interrupt service routines
(ISR) send and receive messages to communicate and synchronize with data.
• When a message queues is first created, it is assigned an associated queue control block (QCB), a
message queue name, a unique ID, memory buffers, a queue length, a maximum message length
and one or more task-waiting list.
• A message queue can fall into either one of the three states, empty, not empty and full.
• When a message queue is first c <!-- id:a7d282ca-ceb4-4ae7-a256-c3323cf7ba0e ts:2026-05-17 07:49 -->
- .
• When a counting semaphore’s value is greater than 0, it is considered available.
Effective Date: 1/4/2022
19
Official (Open)
Objects - Semaphore
• Counting Semaphore
Effective Date: 1/4/2022
20
Official (Open)
Objects - Semaphore
• Mutex Semaphore
• A mutual exclusion (mutex) semaphore is a special binary semaphore.
•
It allows a task to acquire or lock the mutex to own it. No other task can release or unlock the mutex.
The mutex can only be released or unlocked by the owner that acquire or locked it.
• When a mutex semaphore’s value is 0, it is considered locked.
• When a mutex semaphore’s value is greater than 0, it is considered unlocked.
Effective Date: 1/4/2022
21
Official (Open)
Objects - Semaphore
• Mutex Semaphore
Initial
(lock count = 1)
Acquire
(lock count = 0)
Release
(lock count = 1)
Acquire (recursive)
(lock count = lock count - 1)
Release (recursive)
(lock count = lock count + 1)
Effective Date: 1/4/2022
22
Official (Open)
Objects – Message Queue
• Message Queues are buffer-like kernel object through which tasks and Interrupt service routines
(ISR) send and receive messages to communicate and synchronize with data.
• When a message queues is first created, it is assigned an associated queue control block (QCB), a
message queue name, a unique ID, memory buffers, a queue length, a maximum message length
and one or more task-waiting list.
• A message queue can fall into either one of the three states, empty, not empty and full.
• When a message queue is first c <!-- id:a7d282ca-ceb4-4ae7-a256-c3323cf7ba0e ts:2026-05-17 07:49 -->
