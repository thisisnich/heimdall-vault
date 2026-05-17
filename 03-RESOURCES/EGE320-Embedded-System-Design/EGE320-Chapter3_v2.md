---
tags:
  - EGE320
  - chapter3
  - RTOS
  - embedded-systems
  - chapter-3
  - software-architecture
course: EGE320 Embedded System Design & Technology
topic: Chapter 3 - Embedded System Software (RTOS)
source: EGE320-Chapter3_v2.pdf
converted: 2026-05-07
type: Chapter
status: Completed
---

> 📚 **Related:** [[NYPY3 - Main Index|NYPY3 Index]] | [[03-RESOURCES/EGE320-Embedded-System-Design/ch0.md|Chapter 0]] | [[📅 Schedule & Assessments Dashboard|Assessment Dashboard]]

Official (Open)
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
• Task 1 is pre-empted by higher priority task 2, which is then pre-empted by task 3. When task 3 completes,
task 2 resumes. Likewise, when task 2 completes, task 1 resumes.
Effective Date: 1/4/2022
11
Official (Open)
Objects - Task
• A task is an independent thread of execution that can compete with other concurrent task for
processor execution time.
• A task is schedulable based on a predefined scheduling algorithm.
• Each task object has an associated name, a unique ID, a priority, a task control block (TCB), a
stack and a task routine.
• Example of some system tasks include:
•
Initialization or startup task
•
Idle task
• Logging task
• Exception-handling task
• Debug agent task
Effective Date: 1/4/2022
12
Official (Open)
Objects - Task
• When the kernel first starts, it creates its own set of system task and allocates the appropriate
priority for each of the task from a set of reserved priority levels. After that, the kernel jumps to a
predefined entry point that serves as the beginning of the application tasks.
• Tasks are structured in one of the two ways:
• Run to Completion
• Endless Loop
• Run to completion typically run once and most useful for initialization and startup when the
system first powers on.
• Endless loop tasks typically run many times and do the majority of the work in the application
by handling inputs and outputs when the system is powered on.
Effective Date: 1/4/2022
13
Official (Open)
Objects - Task
RunToCompletionTask()
{
Initialize Application
Create endless loop task
Create kernel Objects
Delete or suspend this task
}
EndlessLoopTask()
{
Initialize Code
Loop Forever
{
Body of the loop
Make one or more blocking calls
}
}
Task Structures
Effective Date: 1/4/2022
14
Official (Open)
Objects - Task
• Generally three main states are used in most typical kernels which include:
• Ready State
• Blocked State
• Running State
• Ready state means a task is ready but unable to run due to higher priority task is executing.
• Blocked state means a task is blocked due to resource requested is not available or has delayed
itself for some duration.
• Running state means the task is currently running.
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
• When a message queue is first created, it is in the empty state.
Effective Date: 1/4/2022
23
Official (Open)
Objects – Message Queue
• When a task sends a message to the message queue and no task are waiting to receive the
message, the message queue’s state become not empty.
• If additional messages continue to arrive at the queue and the number of messages in the queue
is equal to the queue’s length, the message queue’s state becomes full.
• Message queues can be used to send and receive a variety of data which include temperature value
from a sensor, bitmap to draw on a display, text message to print to an LCD, keyboard event and
data packet to send over the network.
Effective Date: 1/4/2022
24
Official (Open)
Objects – Message Queue
Effective Date: 1/4/2022
25
Message Queue
Official (Open)
Services
• Services in the kernel comprises sets of API calls that can be used to perform operations on kernel
objects.
• Below is the list of some services provided by kernel:
• Task Management Services
• Time Management Services
• Memory Management Services
• Device Management Services
•
Interrupt Handling Services
Effective Date: 1/4/2022
26
Official (Open)
It’s                     time!
Effective Date: 1/4/2022
27
Official (Open)
Question 1
Which of the following is NOT the type of scheduling that could be used by the RTOS scheduler?
Answer:
A. Round Robin Scheduling
B. Priority Scheduling
C. First-Come First-Serve Scheduling
Effective Date: 1/4/2022
28
Official (Open)
Question 2
Which of the following is NOT an object in the RTOS kernel?
Answer:
A. Task
B. Semaphore
C. Message Buffer
Effective Date: 1/4/2022
29
Official (Open)
Question 3
Under what situation a task in the running state will go into the blocked state?
Answer:
A. When the task requests for an unavailable resource.
B. When the task no longer has the highest priority.
C. When the task is initialized.
Effective Date: 1/4/2022
30
Official (Open)
End of Chapter 3
Effective Date: 1/4/2022
31

