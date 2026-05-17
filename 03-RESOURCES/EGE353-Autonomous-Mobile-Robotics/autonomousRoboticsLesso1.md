---
tags:
  - EGE353
  - robotics
  - ROS
  - SLAM
  - assessment-schedule
course: EGE353 Autonomous Mobile Robotics
lesson: 1
topic: Module Overview and ROS Basics
---

# EGE353 Autonomous Mobile Robotics — Lesson 1 Notes

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
| 2 | 27 Apr 26 | Project Part A Briefing (Engage)<br>- Lesson 2: Robot Operating System *(ELearning-SDL)*<br>- Lesson 3: Important Concepts in ROS *(ELearning-SDL)* | | This project applies Challenge‑Based Learning to autonomous mobile robotics through a real‑world service context. Students begin with a Big Idea such as Health, Sustainability, or Community, exploring how robots can create meaningful impact. From this, an Essential Question is formed to connect personal relevance with community needs. These reflections lead to a concrete Challenge Statement, calling students to design an autonomous mobile robot that safely and effectively addresses a real operational problem. The resulting system design provides the evidence‑based foundation for implementation in Project Part C (ACT). |
| | | | | **1 May 2026 (Fri) – Labour Day** |
| 3 | 4 May 26 | - Lab 2: ROS nodes and TurtleSim (Practical session)<br>- Lab 4: ROS bags (Briefing)<br>- Briefing of Proctored Quiz-1 | | |
| 4 | 11 May 26 | Project Part A Briefing (Investigate)<br>- Lesson 4: Understanding the various components of mobile robot *(ELearning-SDL)*<br>- Lesson 5: Computing hardware *(ELearning-SDL)* | | Investigate: The lesson supports the INVESTIGATE phase by equipping students with system‑level knowledge of sensing, computing, actuation, and power components. Technologies such as LiDAR, vision, UWB, IMU, computing platforms, and power systems are introduced to enable evidence‑based investigation and component justification for the challenge.<br><br>**HBL Week (SEG Graduation Week) 11–15 May 2026** |
| 5 | 18 May 26 | **Practical 1 (20%)**<br>- Lab 5: ROS packages (Briefing)<br>- Lab 5: ROS packages (Practical session) | **Practical 1 (20%)**<br>- Lab 5: ROS packages (Practical session) | |
| 6 | 25 May 26 | **Practical 1 (20%)**<br>- Lab 5: ROS packages (Practical session)<br>- Demo of Practical 1 to instructor<br>- Lab 6: Creating and editing ROS launch files (Briefing) | | **27 May 2026 (Wed) – Hari Raya Haji** |
| 7 | 1 Jun 26 | **Proctored Quiz-1 (10%)**<br>Class E2 Quiz: 2 Jun 2026, Tue, 9–10am<br>- Deadline for Practical 1 (20%) to instructor<br>- Lab 6: Creating and editing ROS launch files (Practical session) | | **1 Jun 2026 (Mon) – Vesak Day** |
| 8 | 8 Jun 26 | Project Part A Discussion (Engage, Investigate) review<br>Project Part A *(ELearning)*<br>Mid term feedback | | |
| 9 | 15 Jun 26 | **Term Break** | | **15 Jun 2026 – 26 Jun 2026 (2 Weeks)** |
| 10 | 22 Jun 26 | **Term Break** | | |

---

## ROS Basics

**ROS → Robot Operating System**
- Windows is an OS on a PC; on a robot it's called ROS
- Will use TurtleBot from lab 5 onwards
- First we will use ConstructSim (web-based simulator)

### SLAM (Simultaneous Localisation and Mapping)

**What is the difference between localisation and mapping?**
- **Localization:** Knowing where you are (robot finding its position in the environment)
- **Mapping:** Knowing what the environment looks like (robot creating a map)
- **SLAM:** Maps and localises at the same time — making a map of environment while tracking position
- Mapping and localisation are two separate functions that can happen independently

**Technologies used:**
- GPS, LiDAR for localization
- Reference: [[Lesson1Introduction#Sensors|Sensor Types]]

We need to self study before a lab -> decide and find out what are we learning during a lab -> what are the components we need to know -> self learn before

lacalisation -> knowing where you are in reference to map, gps, lidar
SLAM -> maps and localises at the same time -> making a map of envoronment 
mapping and localisation are two seperate functions -> can happen independently from each other


---

## Lesson 1 Learning Outcomes

> See [[Lesson1Introduction#Module Learning Outcomes|Official Learning Outcomes]]


---

## Certification

We will finish with a **certificate of competency from NYP and Robotis**: certified to work on ROS to a certain level.

---

## Asimov's Laws of Robotics

Discussed 3(4) rules of robots:

1. **First Law:** A robot may not injure a human being or, through inaction, allow a human being to come to harm.
2. **Second Law:** A robot must obey orders given to it by human beings, except where such orders would conflict with the First Law.
3. **Third Law:** A robot must protect its own existence as long as such protection does not conflict with the First or Second Law.
4. **Fourth Law (Zeroth Law):** A robot must not harm humanity, or, by inaction, allow humanity to come to harm.

> 📖 Full details: [[Lesson1Introduction#Asimov's Three Laws of Robotics|Asimov's Three Laws]]

---

## Applications

- **Taobao robotic warehouse** — See [[Lesson1Introduction#Warehouse Automation|Warehouse Automation]]

