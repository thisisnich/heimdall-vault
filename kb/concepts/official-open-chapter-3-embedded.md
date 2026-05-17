---
id: "ef828114-3d95-44be-9317-1f737a296edc"
title: "Official Open Chapter 3 Embedded"
type: vault_note
vault: wiki
created: 2026-05-17
updated: 2026-05-17
checksum: "sha256:322db28c6cbf6306"
source: heimdall/auto
---

# Official Open Chapter 3 Embedded

- Official (Open)
Chapter 3
Embedded System Software
Effective Date: 1/4/2022
1
Official (Open)
Topics
- 3.1
Real Time Operating System (RTOS)
Effective Date: 1/4/2022
2
Official (Open)
Topics
- 3.1
Real Time Operating System
 Introduction
 Scheduler
 Objects
 Task
 Semaphore
 Message Queue
 Services
Effective Date: 1/4/2022
3
Official (Open)
Real Time Operating System
Effective Date: 1/4/2022
4
Official (Open)
Introduction
• A real-time operating system (RTOS) is a program that schedules execution in a timely manner,
manages system resources and provides a consistent foundation for developing application
code.
• RTOS can be scaled down to comprises only a kernel or scaled up with a combination of various
modules including the file system, networking protocol stacks and other components  as  shown in
below.
Effective Date: 1/4/2022
5
Official (Open)
Introduction
• Most RTOS kernels contain scheduler, objects and services.
• Scheduler is contained within each kernel and follows a set of algorithm that determines which
and when a task executes. Some common examples include round-robin and priority scheduling.
• Objects are special kernel constructs used for application development for real-time embedded
systems. Some common examples include task, semaphores and message queues.
• Services are operations that the kernel performs on an object. <!-- id:ef828114-3d95-44be-9317-1f737a296edc ts:2026-05-17 07:49 -->
