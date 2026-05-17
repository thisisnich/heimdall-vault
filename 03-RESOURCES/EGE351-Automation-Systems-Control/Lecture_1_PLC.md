---
tags:
  - EGE351
  - automation
  - PLC
  - ladder-diagram
  - control-systems
  - lecture-1
course: EGE351 Automation Systems & Control
lecture: 1
topic: Programmable Logic Controller (PLC)
source: NYPY3 Import
created: 2026-05-17
type: Lecture
status: Completed
---

> 📚 **Related:** [[NYPY3 - Main Index|NYPY3 Index]] | [[03-RESOURCES/EGE351-Automation-Systems-Control/lab1.md|Lab 1]] | [[📅 Schedule & Assessments Dashboard|Assessment Dashboard]]

# Programmable Logic Controller (PLC)
### PLC Flowchart to Ladder Diagram

> 📚 **Related:** [[lesson1|Module Overview]] | [[EGE351 Automatino Systems & Control/lab1|Lab 1 Notes]]

---

## FP2 PLC System

A typical PLC consists of the following components:

| Component                 | Description                              |
| ------------------------- | ---------------------------------------- |
| **Power Supply**          | Provides power to the PLC system         |
| **CPU**                   | Central processing unit (e.g. FP2-C1)    |
| **Network Module**        | Handles communication between devices    |
| **Input / Output Module** | Connects to field devices (e.g. XY64D2T) |

**Video Reference:** [Introduction to PLC](https://www.youtube.com/watch?v=iw2t4rCXSiE)

---

## PLC Inputs and Outputs

- **INPUTS** – switches, sensors, pushbuttons, etc.
  - Addressed as **X** (e.g. X40, X52, X5F)
  - See [[Lesson1Introduction#Sensors|Sensor Types in Robotics]]
- **OUTPUTS** – lamp, buzzer, motor, conveyor, etc.
  - Addressed as **Y** (e.g. Y68, Y6A, Y7D)
  - See [[Lesson1Introduction#Actuators|Actuators in Robotics]]
- Programs are downloaded to the PLC via a **download cable** from a PC.

---

## PLC Block Diagram

```
[Programming Terminal]
         |
[Power Supply] → [CPU Memory] → [Input Module] ← [Input Devices]
                      |
                 [Output Module] → [Output Devices]
                      |
                  [PROCESS]
```

---

## Features of PLC

- Rugged, noise immune equipment.
- Modular plug-in construction, allowing easy replacement or addition of units (e.g. input/output).
- Standard input/output connections and signal levels.
- Easily understood programming language.
- Ease of programming and reprogramming.
- Capable of communicating with other PLCs, computers and intelligent devices.
- Competitive in both cost and space with relay and solid-state logic systems.

---

## Distributed Control Structure

PLCs can be integrated into a larger networked control hierarchy:

> 🔗 **IoT Integration:** See [[ch0#Embedded System in Internet of Things (IoT)|IoT Ecosystem]] and [[Lesson2c#Quality of Service (QoS)|Network QoS]]

```
Plant Manager's PC / Supervisor PCs
           |
     [Plant Computer]
           |
    [Local Area Network]  ← High-level communication link
     /              \
[Area Controller]  [Area Controller]
     |                    |
MicroComputer, CNC,   Robot, PLC, PLC
Machine
```

---

## PLC vs Other Control Systems

| Characteristic | Relay Systems | Digital/Analog Logic | Computers | PLC |
|---|---|---|---|---|
| Price per function | Fairly low | Low | High | Low |
| Physical size | Bulky | Very compact | Fairly compact | Very compact |
| Operating speed | Slow | Very fast | Fairly fast | Fast |
| Electrical noise immunity | Excellent | Good | Quite good | Good |
| Installation | Time consuming | Design & test fine tuning time consuming | Programming extremely time-consuming | Simple to program & install |
| Complicated operation | No | Yes | Yes | Yes |
| Ease of changing function | Very difficult | Difficult | Quite simple | Very simple |
| Ease of maintenance | Poor (large no. of contacts) | Poor if ICs soldered | Poor (several custom boards) | Good (few standard cards) |

---

## PLC Memory Map

| Memory Type | Storage |
|---|---|
| Executive Memory | ROM |
| System Memory | RAM |
| I/O Status Memory | RAM |
| Data Memory | RAM |
| User Memory | RAM / EPROM / EEPROM |

---

## I/O Address Assignment Table

| Input | | Output | |
|---|---|---|---|
| **Address** | **Label** | **Address** | **Label** |
| X0 | PB A | Y0 | Extend Cylinder A |
| X1 | PB B | Y1 | Retract Cylinder A |
| X3 | Sensor 1 | Y2 | Extend Cylinder B |
| X4 | Sensor 2 | Y3 | Blue Lamp |

---

## Data Memory

- Data memory is required by timers, counters, mathematics and process parameters.
- An area of memory is set aside for data storage.
- Some manufacturers subdivide the data memory area into two sub-memories — one for **fixed data** and one for **variable data**.

---

## How a PLC Works

The PLC operates on a continuous **scan cycle** with three main phases:

### 1. Input Scan
- Checks the status of all input devices.
- Updates the status into **input memory** (e.g. X1 = Sw_1, X2 = Sw_2).

### 2. Program Execution
- Executes the user program.
- Updates the result into **output memory**.
- Example: `X1 AND X2 = Y3` (Sw_1 AND Sw_2 = Lamp)

### 3. Output Scan
- Transfers the status of the output memory to the **output module**.
- Physical outputs (e.g. lamps, motors) are activated accordingly.

This cycle repeats **over and over again** while the PLC is in RUN mode.

---

## PLC Internal Scan Cycle

```
       ┌─────────────────────────────────┐
       │                                 │
  [Input Scan] → [User-program] → [Output Scan]
  (First instr.)   Execution    (Last instr.)
       │                                 │
       └─────────────────────────────────┘
              (Repeating cycle)
```

> The CPU executes the user-program over and over again when in **RUN mode**.

---

## Central Processing Unit (CPU)

- The CPU **controls and supervises** all operations within the PLC.
- Carries out programmed instructions stored in memory.
- An internal **bus system** carries information to and from the CPU, memory, and I/O units.

---

## Categories of PLC

| PLC Size | Max I/O Points | User Memory Size (No. of Instructions) |
|---|---|---|
| Small | 40 / 40 | 1K |
| Medium | 128 / 128 | 4K |
| Large | > 128 / > 128 | > 4K |

---

## Considerations in Choosing a Suitable PLC

- Necessary input/output capacity
- Types of I/O required
- Size of memory required
- Speed and power required of the CPU and instruction set
- Manufacturer's support and backup
