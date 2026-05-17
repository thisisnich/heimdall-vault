---
id: "3a09a9b7-7051-4437-80ef-dd4c08fddefb"
title: "E Embedded Systems Some Common"
type: vault_note
vault: wiki
created: 2026-05-17
updated: 2026-05-17
checksum: "sha256:357fd6316f21ccb2"
source: heimdall/auto
---

# E Embedded Systems Some Common

- e embedded
systems. Some common examples include task, semaphores and message queues.
• Services are operations that the kernel performs on an object. Some common examples include
timing interrupt handling and resource management.
Effective Date: 1/4/2022
6
Official (Open)
Introduction
RTOS Kernel
Effective Date: 1/4/2022
7
Official (Open)
Scheduler
• Round Robin Scheduling
•
In a round robin scheduler, all the tasks are given equal share of the CPU execution time. With time
slicing, each task executes for a defined interval in an ongoing cycle.
• A run-time counter tracks the time slice for each task. When one task’s time slice completes, the counter
is clear and the task is place at the end of the cycle.
• Newly added tasks are placed at the end of the cycle.
Effective Date: 1/4/2022
8
Official (Open)
Scheduler
• Round Robin Scheduling
Effective Date: 1/4/2022
9
Official (Open)
Scheduler
• Priority Scheduling
•
In a priority scheduler, each task has a priority and the highest priority task run first.
• Priority scheduling can be either of the following:
• Pre-emptive: The scheduler may pre-empt the central processing unit (CPU) in the case the priority of the freshly
arrived process being greater than those of the existing processes.
• Non-pre-emptive: The scheduler simply places the new process at the top of the ready queue.
Effective Date: 1/4/2022
10
Official (Open)
Scheduler
• Priority Scheduling (Pre-emptive)
• Task 1 is pre-empted by higher priority task 2, which is t <!-- id:3a09a9b7-7051-4437-80ef-dd4c08fddefb ts:2026-05-17 07:49 -->
