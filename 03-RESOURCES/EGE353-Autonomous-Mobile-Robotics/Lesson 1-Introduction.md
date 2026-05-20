---
type: lecture
course: EGE353
module: EGE353-Autonomous-Mobile-Robotics
week: 1
status: reviewed
source: pdf
created: 2026-05-08
tags: [EGE353, lesson-1, introduction, robotics]
---

> **Related:** [[NYPY3 - Main Index|NYPY3 Index]] | [[Lesson1Introduction|Lesson 1 Study Notes]] | [[autonomousRoboticsLesso1|Class Notes]] | [[Schedule & Assessments Dashboard|Assessments]]

# Lesson 1: Introduction to Autonomous Robotics

**Instructor:** Chan Kit Wai · Tel: 65500559 · Chan_kit_wai@nyp.edu.sg

## Synopsis

This module equips learners with knowledge of service robots and their applications, including path planning, navigation, obstacle avoidance, and SLAM.

## Module Learning Outcomes

- Explain features of different sensors and actuators used in autonomous mobile robotics
- Perform analysis of laser and vision sensor data using visualization tools
- Implement mobile robotics systems using mapping, localization, path planning, obstacle avoidance, and motion control

---

## Introduction to Robotics

### Definition of a Robot

1. A machine that resembles a human and does mechanical, routine tasks on command
2. A person who acts and responds in a mechanical, routine manner (automaton)
3. Any machine or mechanical device that operates automatically with humanlike skill

*Source: [dictionary.com/browse/robot](https://www.dictionary.com/browse/robot)*

### Asimov's Three Laws of Robotics

Introduced in "Runaround" (1942), from the *Handbook of Robotics, 56th Edition, 2058 A.D.*:

1. **First Law** — A robot may not injure a human being or, through inaction, allow a human being to come to harm
2. **Second Law** — A robot must obey orders given by human beings except where such orders would conflict with the First Law
3. **Third Law** — A robot must protect its own existence as long as such protection does not conflict with the First or Second Law

*Source: [Wikipedia — Three Laws of Robotics](https://en.wikipedia.org/wiki/Three_Laws_of_Robotics)*

---

## Robot Structure

**Control loop:** Sensor data → Compute decision → Control actuators

| Component | Description |
|-----------|-------------|
| **Mechanical body** | Rigid structure holding sensors, motors, and wheels |
| **Sensors** | Camera, wheel encoders, IMU, LiDAR, ultrasonic, IR — perceive environment |
| **Actuators** | Motors controlling arm/body position, angular and linear movement |
| **Computing devices** | Microcontroller (Arduino), SBC (Raspberry Pi), GPU, Industrial PC |

### Computing Devices

- **SBC (Raspberry Pi)** — All components (RAM, GPU, CPU) on one board, credit-card sized
- **Industrial PC** — Rugged enclosures for dust, dirt, oil, grease, water, explosive atmospheres

*Sources: [robotis.com](http://en.robotis.com/) · [advantech.com](https://www.advantech.com)*

---

## Applications

### Warehouse Automation
- Alibaba Cainiao Smart Warehouse
- Autonomous mobile robots (AMR) for picking, packing, transport
- 6 types of warehouse robots

### Healthcare
- Tan Tock Seng Hospital — UV disinfecting mobile robot
- Autonomous delivery and telepresence robots

### NYP Industrial Projects
- **Security robot** — AgileX SCOUT UGV
- **Driverless car**
- **Forklift & warehouse simulation**

### Robotics Competition
Underground cave racing (Universe Today reference)

---

## Development Tools

| Tool | Purpose |
|------|---------|
| Ubuntu | Linux OS (recommended for ROS) |
| ROS | Robot middleware / meta-OS |
| Python | Programming language |
| RViz | 3D visualization |
| TurtleBot3 Burger | Mobile robot platform |
| Gazebo | Physics-based simulation |

---

*End of Lesson 1*
