---
id: "6c52fe12-ce04-4304-8bcc-6a88c767b789"
title: "Irst Starts It Creates Its"
type: vault_note
vault: wiki
created: 2026-05-17
updated: 2026-05-17
checksum: "sha256:d7a4f458f3efdc66"
source: heimdall/auto
---

# Irst Starts It Creates Its

- irst starts, it creates its own set of system task and allocates the appropriate
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
Obj <!-- id:6c52fe12-ce04-4304-8bcc-6a88c767b789 ts:2026-05-17 07:49 -->
