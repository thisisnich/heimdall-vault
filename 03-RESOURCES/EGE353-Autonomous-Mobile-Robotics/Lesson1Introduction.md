---
tags:
  - EGE353
  - robotics
  - autonomous-systems
  - ROS
course: EGE353 Autonomous Mobile Robotics
lesson: 1
topic: Introduction to Autonomous Mobile Robotics
---

# EGE353 Autonomous Mobile Robotics
### Lesson 1: Introduction
**Lecturer:** Chan Kit Wai
**Tel:** 65500559
**Email:** Chan_kit_wai@nyp.edu.sg

> 📚 **Related:** [[autonomousRoboticsLesso1|Lesson 1 Notes]] | [[EGE353 Autonomous Robotics/lab1|Lab 1: ROS Nodes]]

---

## Synopsis

This module aims to equip learners with the knowledge of service robots and their applications. Learners will also study the concepts of path planning, navigation, obstacle avoidance, simultaneous localisation and mapping. They will be able to implement mobile robotics system to carry out tasks autonomously.

---

## Module Learning Outcomes

At the end of the module, learners are able to:

- Explain the features of different sensors and actuators used in autonomous mobile robotics.
- Perform the analysis of laser and vision sensor data using visualization tools.
- Implement mobile robotics system using methods such as mapping, localization, path planning, obstacle avoidance and motion control.

---

## Introduction to Robotics

### Definition of a Robot
1. A machine that resembles a human and does mechanical, routine tasks on command.
2. A person who acts and responds in a mechanical, routine manner, usually subject to another's will; automaton.
3. Any machine or mechanical device that operates automatically with humanlike skill.

*Source: https://www.dictionary.com/browse/robot*

### Asimov's Three Laws of Robotics

The Three Laws of Robotics were devised by science fiction author Isaac Asimov, first introduced in his 1942 short story "Runaround" (included in the 1950 collection *I, Robot*).

**First Law**
A robot may not injure a human being or, through inaction, allow a human being to come to harm.

**Second Law**
A robot must obey the orders given it by human beings except where such orders would conflict with the First Law.

**Third Law**
A robot must protect its own existence as long as such protection does not conflict with the First or Second Law.

*Source: https://en.wikipedia.org/wiki/Three_Laws_of_Robotics*

---

## Robot Structure

### Different Parts of a Robot
- Mechanical body
- Sensors
- Actuators
- Computing devices

The basic control loop: **Sensor data → Compute decision → Control Actuators**

### Mechanical Body
The mechanical body is used to hold all the sensors, motors and wheels together. It is usually a rigid structure.

### Sensors
The sensors comprise of camera sensor, wheel encoders, IMU sensors, lidar sensors, ultrasonic sensors, and infrared sensor to perceive the surrounding environment.

> 🔗 **See also:** Sensor interfacing in [[Lecture_1_PLC#PLC Inputs and Outputs|PLC Systems]] and [[ch0#Embedded System Components (Example: Smartwatch)|Embedded Systems]]

### Actuators
The motors control the movement of the robot's arm and body. It can control the position, angular and linear movements.

*Source: http://en.robotis.com/*

### Computing Devices
- **Microcontroller:** Arduino → See [[ch0#Embedded System Components (Example: Smartwatch)|EGE320 Embedded Systems]]
- **Single Board Computer (SBC):** e.g. Raspberry Pi
- **Graphic Processing Unit (GPU)**
- **Industrial PC**

**Single Board Computer (Raspberry Pi):** A single-board computer is a device with all of its components such as RAM, a GPU, and CPU built-in. Unlike a traditional desktop PC, SBCs are small — roughly the size of a credit card.

**Industrial PC:** Industrial PC enclosures are a more efficient, affordable and reliable alternative to expensive machines. They can withstand harsh environments including dust, dirt, grime, oil, grease and water.

*Source: https://www.advantech.com*

---

## Applications of Mobile Robotics

### Warehouse Automation
Mobile robotics systems carry out tasks autonomously in warehouses, such as picking, packing and transportation.

### Healthcare
- Autonomous delivery robots in hospital corridors
- Telepresence robots for remote consultation
- UV disinfecting mobile robots (e.g. deployed at Tan Tock Seng Hospital)

---

## NYP Industrial Projects
- **Security robot** — AgileX SCOUT UGV
- **Driverless car** — Autonomous vehicle with obstacle avoidance
- **Simulation of Forklift and Warehouse** — Gazebo-based simulation environment

---

## Development Tools

| Tool | Description |
|------|-------------|
| Ubuntu | Linux operating system |
| ROS (Robot Operating System) | Middleware for robot software development → See [[autonomousRoboticsLesso1#ROS basics|ROS Basics]] |
| Python | Programming language |
| RViz | 3D visualization tool for ROS |
| TurtleBot3 Burger | Mobile robot platform |
| Gazebo | Robot simulation environment |

---

*End of Lesson 1*