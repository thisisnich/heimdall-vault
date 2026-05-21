---
type: lecture
course: EGE353
module: EGE353-Autonomous-Mobile-Robotics
week: 1
status: reviewed
source: manual
created: 2026-05-17
tags: [EGE353, lesson-1, introduction, robotics]
---

> **Related:** [[07-DASHBOARDS/NYPY3 - Main Index|NYPY3 Index]] | [[Lesson 1-Introduction|Lesson 1 PDF]] | [[autonomousRoboticsLesso1|Class Notes]] | [[07-DASHBOARDS/Schedule & Assessments Dashboard|Assessments]]

# Lesson 1: Introduction to Autonomous Mobile Robotics

**Instructor:** Chan Kit Wai · Tel: 65500559 · Chan_kit_wai@nyp.edu.sg

## Synopsis

This module aims to equip learners with the knowledge of service robots and their applications. Learners will also study the concepts of path planning, navigation, obstacle avoidance, simultaneous localisation and mapping. They will be able to implement mobile robotics system to carry out tasks autonomously.

## Module Learning Outcomes

- Explain the features of different sensors and actuators used in autonomous mobile robotics
- Perform the analysis of laser and vision sensor data using visualization tools
- Implement mobile robotics system using methods such as mapping, localization, path planning, obstacle avoidance and motion control

---

## Introduction to Robotics

### Definition of a Robot

1. A machine that resembles a human and does mechanical, routine tasks on command
2. A person who acts and responds in a mechanical, routine manner, usually subject to another's will; automaton
3. Any machine or mechanical device that operates automatically with humanlike skill

*Source: [dictionary.com/browse/robot](https://www.dictionary.com/browse/robot)*

### Asimov's Three Laws of Robotics

The Three Laws were devised by Isaac Asimov, first introduced in "Runaround" (1942, *I, Robot*).

1. **First Law** — A robot may not injure a human being or, through inaction, allow a human being to come to harm
2. **Second Law** — A robot must obey the orders given it by human beings except where such orders would conflict with the First Law
3. **Third Law** — A robot must protect its own existence as long as such protection does not conflict with the First or Second Law

*Source: [Wikipedia — Three Laws of Robotics](https://en.wikipedia.org/wiki/Three_Laws_of_Robotics)*

---

## Robot Structure

**Control loop:** Sensor data → Compute decision → Control actuators

| Component | Description |
|-----------|-------------|
| **Mechanical body** | Holds sensors, motors, and wheels; usually rigid |
| **Sensors** | Camera, encoders, IMU, LiDAR, ultrasonic, IR |
| **Actuators** | Motors for position, angular, and linear movement |
| **Computing devices** | Arduino (MCU), Raspberry Pi (SBC), GPU, Industrial PC |

### Computing Devices

- **Microcontroller (Arduino)** — see EGE320 embedded systems
- **SBC (Raspberry Pi)** — RAM, GPU, CPU on one board, credit-card sized
- **Industrial PC** — Rugged for dust, dirt, oil, grease, water

*Source: [advantech.com](https://www.advantech.com)* · [robotis.com](http://en.robotis.com/)

---

## Applications of Mobile Robotics

### Warehouse Automation
Picking, packing, and autonomous transport in smart warehouses.

### Healthcare
- Autonomous delivery in hospital corridors
- Telepresence for remote consultation
- UV disinfecting robots (e.g. Tan Tock Seng Hospital)

### NYP Industrial Projects
- **Security robot** — AgileX SCOUT UGV
- **Driverless car** — autonomous vehicle with obstacle avoidance
- **Forklift & warehouse simulation** — Gazebo-based

---

## Development Tools

| Tool | Description |
|------|-------------|
| Ubuntu | Linux operating system |
| ROS | Middleware for robot software → [[autonomousRoboticsLesso1#ROS Basics\|ROS Basics]] |
| Python | Programming language |
| RViz | 3D visualization for ROS |
| TurtleBot3 Burger | Mobile robot platform |
| Gazebo | Robot simulation environment |

---

*End of Lesson 1*
