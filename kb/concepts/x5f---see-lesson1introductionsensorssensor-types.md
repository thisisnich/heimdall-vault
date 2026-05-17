---
id: "22c2a747-e3f7-4840-9b0f-0b84d4d56bd9"
title: "X5F   See Lesson1Introductionsensorssensor Types"
type: vault_note
vault: wiki
created: 2026-05-17
updated: 2026-05-17
checksum: "sha256:1a712179575fd186"
source: heimdall/auto
---

# X5F   See Lesson1Introductionsensorssensor Types

- X5F)
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
     | <!-- id:22c2a747-e3f7-4840-9b0f-0b84d4d56bd9 ts:2026-05-17 07:49 -->
- X5F)
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
     | <!-- id:22c2a747-e3f7-4840-9b0f-0b84d4d56bd9 ts:2026-05-17 07:49 -->
