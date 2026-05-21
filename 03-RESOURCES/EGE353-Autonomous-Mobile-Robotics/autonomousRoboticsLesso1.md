---
type: lecture
course: EGE353
module: EGE353-Autonomous-Mobile-Robotics
week: 1
status: reviewed
source: manual
created: 2026-05-17
tags: [EGE353, lesson-1, module-overview, SLAM, ROS]
---

> **Related:** [[07-DASHBOARDS/NYPY3 - Main Index|NYPY3 Index]] | [[Lesson1Introduction|Lesson 1 Slides]] | [[Lesson 1-Introduction|Lesson 1 PDF]] | [[EGE353 Assessment Breakdown|Assessments]]

# EGE353 — Lesson 1 Class Notes

---

## Assessment Schedule

> See [[EGE353 Assessment Breakdown|Assessment Breakdown]] and [[EGE353 Weekly Lesson Plan - E2|Weekly Lesson Plan]] for current dates.

| Week | Assessment | Weight |
|------|------------|--------|
| 4–5 | Practical 1: ROS bags and packages | 20% |
| 6 | Test 1: Proctored Quiz-1 | 10% |
| 11–13 | Practical 2: Dockers | 20% |
| 14 | Test 2: Proctored Quiz-2 | 15% |
| 15–17 | Project Part A + B (design + SLAM) | 35% |

### Weekly Timetable (E2)

| WK | Mon Date | E2: Tue 11am–1pm | E2: Fri 8am–10am | Remarks |
|----|----------|------------------|------------------|---------|
| 1 | 20 Apr 26 | Module intro · Lesson 1 | Lab 1: ROS nodes & TurtleSim | |
| 2 | 27 Apr 26 | Project Part A Briefing · Lesson 2 & 3 (SDL) | | **1 May — Labour Day** |
| 3 | 4 May 26 | Lab 2 · Lab 4 briefing · Quiz-1 briefing | | |
| 4 | 11 May 26 | Project Part A (Investigate) · Lesson 4 & 5 (SDL) | | **HBL 11–15 May** |
| 5 | 18 May 26 | **Practical 1 (20%)** · Lab 5 briefing/practical | **Practical 1 (20%)** · Lab 5 | |
| 6 | 25 May 26 | **Practical 1 (20%)** · Lab 5 demo · Lab 6 briefing | | **27 May — Hari Raya Haji** |
| 7 | 1 Jun 26 | **Quiz-1 (10%)** · Practical 1 deadline · Lab 6 | | **1 Jun — Vesak Day** |
| 8 | 8 Jun 26 | Project Part A review · mid-term feedback | | |
| 9–10 | 15–26 Jun | **Term Break** | | |

---

## ROS Basics

**ROS → Robot Operating System**

- Windows is an OS on a PC; on a robot it's ROS
- TurtleBot from Lab 5 onwards; ConstructSim for early labs

### SLAM (Simultaneous Localisation and Mapping)

| Concept | Meaning |
|---------|---------|
| **Localization** | Knowing where you are (position in environment) |
| **Mapping** | Knowing what the environment looks like |
| **SLAM** | Maps and localises **at the same time** |

Mapping and localization are separate functions that can happen independently.

**Technologies:** GPS, LiDAR — see [[Lesson1Introduction#Sensors|Sensors]]

> Self-study before each lab: identify what you'll learn, which components matter, and pre-read accordingly.

---

## Certification

Certificate of competency from **NYP and Robotis** — certified to work on ROS to a certain level.

---

## Asimov's Laws of Robotics

1. **First Law** — May not injure a human or allow harm through inaction
2. **Second Law** — Must obey human orders unless they conflict with the First Law
3. **Third Law** — Must protect own existence unless it conflicts with First or Second Law
4. **Zeroth Law** — Must not harm humanity or allow humanity to come to harm

> Full details: [[Lesson1Introduction#Asimov's Three Laws of Robotics|Lesson 1 Slides]]

---

## Applications

- **Taobao/Alibaba robotic warehouse** — [[Lesson1Introduction#Warehouse Automation|Warehouse Automation]]
- Security robots, driverless cars, hospital UV disinfecting robots
