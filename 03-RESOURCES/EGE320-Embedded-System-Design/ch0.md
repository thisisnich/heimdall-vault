---
tags:
  - EGE320
  - embedded-systems
  - IoT
  - microcontroller
  - C-programming
  - chapter-0
  - module-introduction
course: EGE320 Embedded System Design and Technology
chapter: 0
topic: Module Introduction
source: NYPY3 Import
created: 2026-05-17
type: Chapter
status: Completed
---

> 📚 **Related:** [[NYPY3 - Main Index|NYPY3 Index]] | [[03-RESOURCES/EGE320-Embedded-System-Design/lab1.md|Lab 1]] | [[📅 Schedule & Assessments Dashboard|Assessment Dashboard]]

# EGE320 Embedded System Design and Technology
### Module Introduction

---

## Unit Leader

**Name:** Alex Oh Jun Yong
**Email:** Alex_oh@nyp.edu.sg
**Tel:** 6550 0550
**Room:** S.506

---

## Embedded System in Internet of Things (IoT)

This module is part of the IoT cluster:

- **EGE320** — Embedded System Design and Technology *(this module)*
- **EGE321** — Wireless Communications and Network → See [[Lesson1c|Wireless Fundamentals]]
- **EGE322** — IoT System Project

The IoT ecosystem spans from embedded applications at the device level, through connectivity (Wi-Fi, 3G/4G, Ethernet, ZigBee, RFID), to cloud platforms (Microsoft Azure, Amazon Web Services) and user interface devices.

---

## Embedded System in IoT Industry

- The global embedded system market is witnessing considerable growth due to increasing demand for smart devices, estimated to reach **USD 138.45 billion by 2028**.
- Growth is driven by advances in artificial intelligence, virtual reality, machine learning, and **Internet of Things (IoT)**.
- Rising urbanisation in India and China, along with **rising industrialisation and Industry 4.0**, is further driving demand in the **Asia Pacific region**.
- Embedded systems are becoming more complex, yet there is a **lack of skilled professionals** with in-depth knowledge in this field.

*Source: https://www.thebrainyinsights.com/report/embedded-system-market-12555*

### Key Market Players

Intel, Renesas, STMicroelectronics, NXP Semiconductors, Texas Instruments, Microchip, Cypress Semiconductors, Qualcomm, Analog Devices, and Infineon Technologies.

---

## Module Linkages

This module builds on prior knowledge from:

- **EGE151** — Programming
- **EGE180** — Digital Electronics

And feeds into:

- **EGE254** — Microcontroller Applications

---

## Embedded System Components (Example: Smartwatch)

A typical embedded system contains:

- Touch Screen
- LCD Screen
- Push Button
- Buzzer
- Temperature Sensor → Similar sensors used in [[Lesson1Introduction#Sensors|Robotics]]
- Light Sensor
- Microcontroller → See [[Lecture_1_PLC#PLC vs Other Control Systems|vs PLC Comparison]]
- LEDs

---

## Tools

| Category | Tool |
|----------|------|
| **Hardware** | Embedded development board with LCD & smartwatch display |
| **Software** | Code Composer Studio™ (Integrated Development Environment) |

---

## Module Learning Outcomes

At the end of this module, students will be able to:

- **Set up** an embedded system development environment using industry standard embedded platforms and tools.
- **Develop** embedded application software to acquire, process, display, send and receive data in C.
- **Debug** software errors by identifying and rectifying them using the development tools.

---

## Topics

**1. Overview of Embedded System Design and Technology**
- 1.1 Introduction to Embedded System
- 1.2 Embedded System Development Tools and Setup
- 1.3 Embedded System Programming

**2. Embedded System Hardware**
- 2.1 LCD Screen and Touch Panel
- 2.2 Digital Output and Input
- 2.3 Analog Output and Input
- 2.4 Clock and Timers
- 2.5 Serial Communications Interfaces

**3. Embedded System Software**
- 3.1 Real Time Operating System

---

## Module Delivery Plan

| Week | Lab f2f Session (S433B) | Tutorial (S306/S308) |
|------|------------------------|----------------------|
| **Week 1** 20/04 | Chapter 0 & Chapter 1.1 & 1.2 (60 mins)<br>Lab 1 – Embedded System Development Environment (120 mins) | Tutorial 1 |
| **Week 2** 27/04 | Chapter 1.3 (60 mins)<br>Lab 2 – Embedded System Programming I (120 mins) | Tutorial 2 |
| **Week 3** 04/05 | Chapter 1.3 (60 mins)<br>Lab 3 – Embedded System Programming II (120 mins) | Tutorial 3 (HBL) |
| **Week 4** 11/05 *(HBL Week / Graduation Day)* | Chapter 2.1 (60 mins)<br>Lab 4 – Graphic LCD User Interface Design (120 mins) | Tutorial 4 |
| **Week 5** 18/05 | Chapter 2.1 (60 mins)<br>Lab 5 – Touchscreen Interaction (120 mins) | Tutorial 5 |
| **Week 6** 25/05 *(27 May Wed – Hari Raya Haji, Group E1 make-up lesson)* | Chapter 2.2 (60 mins)<br>Lab 6 – Digital Output (120 mins) | Tutorial 6 |
| **Week 7** 01/06 | Chapter 2.2 (60 mins)<br>Lab 7 – Digital Input (120 mins) | 🔴 **Assessment: eQuiz 1 – 15%**<br>40 MCQ, 60 minutes<br>Scope: Lab 1–6, Chapter 1 & 2 (till Digital Output)<br>One A4 cheat sheet allowed |
| **Week 8** 08/06 | 🔴 **Assessment: Lab Test 1 – 25%**<br>Part 1a and 1b, 50 minutes<br>Scope: Lab 1–7<br>BrightSpace notes/codes allowed; Google/search engines NOT allowed | Tutorial 7 |
| **Week 9 & 10** | **Term Break** | |
| **Week 11** 29/06 | Chapter 2.3 (60 mins)<br>Lab 8 – Analog Output (120 mins)<br>Commencement of Assignment | Tutorial 8 |
| **Week 12** 06/07 | Chapter 2.3 (60 mins)<br>Lab 9 – Analog Input (120 mins) | Tutorial 9 |
| **Week 13** 13/07 | Chapter 2.4 (60 mins)<br>Lab 10 – Timer and Real Time Clock (120 mins) | Tutorial 10 |
| **Week 14** 20/07 | Chapter 2.5 (60 mins)<br>Lab 11 – UART Communications (120 mins) | Tutorial 11 |
| **Week 15** 27/07 | Chapter 3.1 (60 mins)<br>Lab 12 – Real Time Operating System (120 mins)<br>🔴 **Assessment submission – 20%** | Tutorial 12 |
| **Week 16** 03/08 | 🔴 **Assessment: eQuiz 2 – 15%**<br>40 MCQ, 60 minutes<br>Scope: Lab 1–12, Chapter 1–3<br>One A4 cheat sheet allowed | |
| **Week 17** 10/08 | 🔴 **Assessment: Lab Test 2 – 25%**<br>1 Question, 50 minutes<br>Scope: Lab 1–11 (Focus: Lab 8–11)<br>BrightSpace notes/codes allowed; Google/search engines NOT allowed | |

---

## Assessment Plan

| Type | Assessment | Percentage | Week |
|------|-----------|------------|------|
| **Test** | eQuiz 1 | 15% | Week 7 |
| | eQuiz 2 | 15% | Week 16 |
| **Practical** | Lab Test 1 | 25% | Week 8 |
| | Lab Test 2 | 25% | Week 17 |
| **Assignment** | Assignment | 20% | Week 15 |
| | **Total** | **100%** | |

---

*End of Chapter 0*


---

## Notes: Pointers in Embedded C

**What are pointers?**
- Pointers are variables that store memory addresses
- they are used to directly manipulate memory locations
- they are used to access hardware registers directly
- they are used to pass arguments to functions by reference
- they are used to create dynamic data structures
- they are used to implement linked lists, trees, and other data structures


---

## Key Definition

**Embedded System:** A processor-based electronic system comprised of both hardware and software designed to perform some specific tasks with limited resources.

> 🔗 **Applications:** Used in [[Lesson1Introduction#Computing Devices|Robotics]], [[Lecture_1_PLC|Industrial Automation]], and [[Lesson1c|Wireless IoT Devices]]

---
