---
id: "5f9b6b41-02ab-4181-b603-448c272b9bbc"
title: "Ege353 Autonomous Mobile Robotics"
type: vault_note
vault: wiki
created: 2026-05-17
updated: 2026-05-17
checksum: "sha256:ed4c6497095add81"
source: heimdall/auto
---

# Ege353 Autonomous Mobile Robotics

- # EGE353 Autonomous Mobile Robotics
### Lab 1: Understanding ROS Nodes and TurtleSim
**Lecturer:** Chan Kit Wai
**Tel:** 65500559
**Email:** Chan_kit_wai@nyp.edu.sg

> 📚 **Related:** [[Lesson1Introduction|Lesson 1]] | [[autonomousRoboticsLesso1|Lesson 1 Notes]]

---

## Module Learning Outcomes

At the end of the module, learners are able to:

- Explain the features of different sensors and actuators used in autonomous mobile robotics.
- Perform the analysis of laser and vision sensor data using visualization tools.
- Implement mobile robotics system using methods such as mapping, localization, path planning, obstacle avoidance and motion control.

---

## Web-Based Simulator Setup

**Platform:** [The Construct](https://www.theconstruct.ai/)
**Sign up:** https://app.theconstruct.ai/signup/

> ⚠️ Make sure you record your email and password somewhere.

### Creating a New ROSject

1. Go to **Develop → My Rosjects → Create new rosject**
2. Select **ROS Distro** → Choose **ROS 2 Humble**
3. Select **Simulation** → Choose **Create from scratch**
4. Enter a project name (e.g. `EGE353`) → Click **CREATE**
5. <!-- id:5f9b6b41-02ab-4181-b603-448c272b9bbc ts:2026-05-17 07:49 -->
- # EGE353 Autonomous Mobile Robotics
### Lab 1: Understanding ROS Nodes and TurtleSim
**Lecturer:** Chan Kit Wai
**Tel:** 65500559
**Email:** Chan_kit_wai@nyp.edu.sg

> 📚 **Related:** [[Lesson1Introduction|Lesson 1]] | [[autonomousRoboticsLesso1|Lesson 1 Notes]]

---

## Module Learning Outcomes

At the end of the module, learners are able to:

- Explain the features of different sensors and actuators used in autonomous mobile robotics.
- Perform the analysis of laser and vision sensor data using visualization tools.
- Implement mobile robotics system using methods such as mapping, localization, path planning, obstacle avoidance and motion control.

---

## Web-Based Simulator Setup

**Platform:** [The Construct](https://www.theconstruct.ai/)
**Sign up:** https://app.theconstruct.ai/signup/

> ⚠️ Make sure you record your email and password somewhere.

### Creating a New ROSject

1. Go to **Develop → My Rosjects → Create new rosject**
2. Select **ROS Distro** → Choose **ROS 2 Humble**
3. Select **Simulation** → Choose **Create from scratch**
4. Enter a project name (e.g. `EGE353`) → Click **CREATE**
5. <!-- id:5f9b6b41-02ab-4181-b603-448c272b9bbc ts:2026-05-17 07:49 -->
- # EGE353 Autonomous Mobile Robotics — Lesson 1 Notes

> 📚 **Related:** [[Lesson1Introduction|Lesson 1 Slides]] | [[EGE353 Autonomous Robotics/lab1|Lab 1: ROS Nodes]]

---

## Assessment Schedule

| Week | Assessment Type | Weightage |
|------|----------------|-----------|
| 4-5 | Practical 1: Usages of ROS bags and packages | 20 |
| 6 | Test 1: Proctored Quiz-1 | 10 |
| 11-13 | Practical 2: Dockers | 20 |
| 14 | Test 2: Proctored Quiz-2 | 15 |
| 15-17 | Project (Part A): Robot design project | 35 |
| | Project (Part B): To implement Simultaneous Localisation and Mapping (SLAM) for path planning and navigation and obstacles avoidance using real mobile robots | 35 |
| | **Total** | **100** |
^^
this is outdates, the time schedule (weeks) and project A and B are diff


| WK | Mon Date | E2: Tue 11am–1pm | E2: Fri 8am–10am | Remarks |
|----|----------|------------------|------------------|---------|
| 1 | 20 Apr 26 | - Introduction of Module structure<br>- Lesson 1: Introduction to Autonomous Mobile Robotics | Lab 1: ROS nodes and TurtleSim (Practical session) | |
| 2 | 27 Apr 26 | Project Part A Briefing (Engage)<br>- Lesson 2: Robot Operating System *(ELearning-SDL)*<br>- Lesson 3: Important Concepts in ROS *(ELearning-SDL)* | | This project applies Challenge‑Based Learning to autonomous mobile robotics through a real‑world service context. Students begin with a Big Idea such as Health, Sustainability, or Community, exploring how robots can create meaningful impact. <!-- id:1bfb4efc-a160-4eab-a5c7-1e429a664b38 ts:2026-05-17 07:49 -->
- # EGE353 Autonomous Mobile Robotics — Lesson 1 Notes

> 📚 **Related:** [[Lesson1Introduction|Lesson 1 Slides]] | [[EGE353 Autonomous Robotics/lab1|Lab 1: ROS Nodes]]

---

## Assessment Schedule

| Week | Assessment Type | Weightage |
|------|----------------|-----------|
| 4-5 | Practical 1: Usages of ROS bags and packages | 20 |
| 6 | Test 1: Proctored Quiz-1 | 10 |
| 11-13 | Practical 2: Dockers | 20 |
| 14 | Test 2: Proctored Quiz-2 | 15 |
| 15-17 | Project (Part A): Robot design project | 35 |
| | Project (Part B): To implement Simultaneous Localisation and Mapping (SLAM) for path planning and navigation and obstacles avoidance using real mobile robots | 35 |
| | **Total** | **100** |
^^
this is outdates, the time schedule (weeks) and project A and B are diff


| WK | Mon Date | E2: Tue 11am–1pm | E2: Fri 8am–10am | Remarks |
|----|----------|------------------|------------------|---------|
| 1 | 20 Apr 26 | - Introduction of Module structure<br>- Lesson 1: Introduction to Autonomous Mobile Robotics | Lab 1: ROS nodes and TurtleSim (Practical session) | |
| 2 | 27 Apr 26 | Project Part A Briefing (Engage)<br>- Lesson 2: Robot Operating System *(ELearning-SDL)*<br>- Lesson 3: Important Concepts in ROS *(ELearning-SDL)* | | This project applies Challenge‑Based Learning to autonomous mobile robotics through a real‑world service context. Students begin with a Big Idea such as Health, Sustainability, or Community, exploring how robots can create meaningful impact. <!-- id:1bfb4efc-a160-4eab-a5c7-1e429a664b38 ts:2026-05-17 07:49 -->
- # EGE353

Autonomous Mobile
Robotics
Service mobile robots, concepts of path planning, navigation,
obstacle avoidance, simultaneous localisation and mapping.
Lesson 3:  Important Concepts of ROS
Chan Kit Wai
Tel: 65500559
Chan_kit_wai@nyp.edu.sg
Synopsis
This  module  aims  to  equip  learners  with  the  knowledge  of  service  robots  and  their  applications.  Learners  will  also
study the concepts of path planning, navigation, obstacle avoidance, simultaneous localisation and mapping. They will
be able to implement mobile robotics system to carry out tasks autonomously.
Module Learning Outcomes
At the end of the module, learners are able to:
•Explain the features of different sensors and actuators used in autonomous mobile robotics.
•Perform the analysis of laser and vision sensor data using visualization tools.
•Implement mobile robotics system using methods such as mapping, localization, path planning, obstacle avoidance
and motion control.
ROS Message
Nodes  communicate  with  each  other  by  publishing  messages  to  topics.  A  message  is  a  simple  data  structure,
comprising  typed  fields.  Standard  primitive  types  (integer,  floating  point,  boolean,  etc.)  are  supported,  as  are
arrays of primitive types. Basically, a message is data through a channel called topic. In the following figure, the
message is String type and the topic is called /example.
ROS nodes
A node refers to the smallest unit of processor running in
ROS. <!-- id:8cf6592d-ef0e-49e7-b8c3-35fe8775626a ts:2026-05-17 07:49 -->
- # EGE353

Autonomous Mobile
Robotics
Service mobile robots, concepts of path planning, navigation,
obstacle avoidance, simultaneous localisation and mapping.
Lesson 3:  Important Concepts of ROS
Chan Kit Wai
Tel: 65500559
Chan_kit_wai@nyp.edu.sg
Synopsis
This  module  aims  to  equip  learners  with  the  knowledge  of  service  robots  and  their  applications.  Learners  will  also
study the concepts of path planning, navigation, obstacle avoidance, simultaneous localisation and mapping. They will
be able to implement mobile robotics system to carry out tasks autonomously.
Module Learning Outcomes
At the end of the module, learners are able to:
•Explain the features of different sensors and actuators used in autonomous mobile robotics.
•Perform the analysis of laser and vision sensor data using visualization tools.
•Implement mobile robotics system using methods such as mapping, localization, path planning, obstacle avoidance
and motion control.
ROS Message
Nodes  communicate  with  each  other  by  publishing  messages  to  topics.  A  message  is  a  simple  data  structure,
comprising  typed  fields.  Standard  primitive  types  (integer,  floating  point,  boolean,  etc.)  are  supported,  as  are
arrays of primitive types. Basically, a message is data through a channel called topic. In the following figure, the
message is String type and the topic is called /example.
ROS nodes
A node refers to the smallest unit of processor running in
ROS. <!-- id:8cf6592d-ef0e-49e7-b8c3-35fe8775626a ts:2026-05-17 07:49 -->
- # EGE353

Autonomous Mobile Robotics
Service mobile robots, concepts of path planning, navigation,
obstacle avoidance, simultaneous localisation and mapping.
Lesson 2:  Robot Operating System
Chan Kit Wai
Tel: 65500559
Chan_kit_wai@nyp.edu.sg
Synopsis
This  module  aims  to  equip  learners  with  the  knowledge  of  service  robots  and  their  applications.  Learners  will  also
study the concepts of path planning, navigation, obstacle avoidance, simultaneous localisation and mapping. They will
be able to implement mobile robotics system to carry out tasks autonomously.
Module Learning Outcomes
At the end of the module, learners are able to:
•Explain the features of different sensors and actuators used in autonomous mobile robotics.
•Perform the analysis of laser and vision sensor data using visualization tools.
•Implement mobile robotics system using methods such as mapping, localization, path planning, obstacle avoidance
and motion control.
Introduction to ROS
ROS is an open-source, meta-operating system for your
robot. It provides the services you would expect from an
operating system, including hardware abstraction,
low-level device control, implementation of
commonly-used functionality, message-passing between
processes, and package management. It also provides
tools and libraries for obtaining, building, writing, and
running code across multiple computers.
Source: https://www.ros.org
Introduction to ROS
ROS is an open-source, meta-operating system for
your robot. <!-- id:83d32cfa-2d54-4d6a-96d5-8f3d9deb20e5 ts:2026-05-17 07:49 -->
- # EGE353

Autonomous Mobile Robotics
Service mobile robots, concepts of path planning, navigation,
obstacle avoidance, simultaneous localisation and mapping.
Lesson 2:  Robot Operating System
Chan Kit Wai
Tel: 65500559
Chan_kit_wai@nyp.edu.sg
Synopsis
This  module  aims  to  equip  learners  with  the  knowledge  of  service  robots  and  their  applications.  Learners  will  also
study the concepts of path planning, navigation, obstacle avoidance, simultaneous localisation and mapping. They will
be able to implement mobile robotics system to carry out tasks autonomously.
Module Learning Outcomes
At the end of the module, learners are able to:
•Explain the features of different sensors and actuators used in autonomous mobile robotics.
•Perform the analysis of laser and vision sensor data using visualization tools.
•Implement mobile robotics system using methods such as mapping, localization, path planning, obstacle avoidance
and motion control.
Introduction to ROS
ROS is an open-source, meta-operating system for your
robot. It provides the services you would expect from an
operating system, including hardware abstraction,
low-level device control, implementation of
commonly-used functionality, message-passing between
processes, and package management. It also provides
tools and libraries for obtaining, building, writing, and
running code across multiple computers.
Source: https://www.ros.org
Introduction to ROS
ROS is an open-source, meta-operating system for
your robot. <!-- id:83d32cfa-2d54-4d6a-96d5-8f3d9deb20e5 ts:2026-05-17 07:49 -->
- # EGE353 Autonomous Mobile Robotics — Map of Content

> 🤖 **Course Overview:** This module covers autonomous mobile robotics, ROS (Robot Operating System), SLAM, path planning, and navigation.

> � **Note:** Do not use images or assets for EGE353 lab files. All lab content should be text-based only.

---

## 📋 Course Information

**Lecturer:** Chan Kit Wai  
**Email:** Chan_kit_wai@nyp.edu.sg  
**Tel:** 65500559

**Certification:** NYP and Robotis certificate of competency in ROS  
📜 [[EGE353 Robotis Co-Certification|Co-Certification Details]]

**Schedule:**  
📅 [[EGE353 Weekly Lesson Plan - E2|Weekly Lesson Plan (E2 Class)]]

---

## 📚 Lessons & Lectures

- [[Lesson1Introduction|Lesson 1: Robot Structure & Sensors]]
  - Robot structure: base, actuators, sensors, controllers
  - Sensors: encoders, IMU, laser, vision
  - Actuators: motors, servos
  - Asimov's Three Laws of Robotics

- [[autonomousRoboticsLesso1|Lesson 1: ROS Basics]]
  - ROS introduction and installation
  - ROS2 vs ROS1 differences
  - Assessment schedule and week plan

- [[Lesson 2 Robot Operating System ROS|Lesson 2: Robot Operating System (ROS)]]
  - ROS as meta-operating system
  - Hardware abstraction
  - Message-passing between processes
  - Package management

- [[Lesson 3 Important Concepts of ROS|Lesson 3: Important ROS Concepts]]
  - ROS nodes and topics
  - ROS services and parameters
  - ROS publishers and subscribers
  - Project structure
  - Asimov's Laws expanded

---

## 🔬 Labs & Practicals

- <!-- id:3aafefa6-a9ed-480e-a945-6d1445bdf987 ts:2026-05-17 07:49 -->
- # EGE353 Autonomous Mobile Robotics — Map of Content

> 🤖 **Course Overview:** This module covers autonomous mobile robotics, ROS (Robot Operating System), SLAM, path planning, and navigation.

> � **Note:** Do not use images or assets for EGE353 lab files. All lab content should be text-based only.

---

## 📋 Course Information

**Lecturer:** Chan Kit Wai  
**Email:** Chan_kit_wai@nyp.edu.sg  
**Tel:** 65500559

**Certification:** NYP and Robotis certificate of competency in ROS  
📜 [[EGE353 Robotis Co-Certification|Co-Certification Details]]

**Schedule:**  
📅 [[EGE353 Weekly Lesson Plan - E2|Weekly Lesson Plan (E2 Class)]]

---

## 📚 Lessons & Lectures

- [[Lesson1Introduction|Lesson 1: Robot Structure & Sensors]]
  - Robot structure: base, actuators, sensors, controllers
  - Sensors: encoders, IMU, laser, vision
  - Actuators: motors, servos
  - Asimov's Three Laws of Robotics

- [[autonomousRoboticsLesso1|Lesson 1: ROS Basics]]
  - ROS introduction and installation
  - ROS2 vs ROS1 differences
  - Assessment schedule and week plan

- [[Lesson 2 Robot Operating System ROS|Lesson 2: Robot Operating System (ROS)]]
  - ROS as meta-operating system
  - Hardware abstraction
  - Message-passing between processes
  - Package management

- [[Lesson 3 Important Concepts of ROS|Lesson 3: Important ROS Concepts]]
  - ROS nodes and topics
  - ROS services and parameters
  - ROS publishers and subscribers
  - Project structure
  - Asimov's Laws expanded

---

## 🔬 Labs & Practicals

- <!-- id:3aafefa6-a9ed-480e-a945-6d1445bdf987 ts:2026-05-17 07:49 -->
- # EGE353 Autonomous Mobile Robotics
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
3. <!-- id:49386e64-a647-4e57-8eb7-c3219ad031e3 ts:2026-05-17 07:49 -->
