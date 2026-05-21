---
type: lecture
course: EGE353
module: EGE353-Autonomous-Mobile-Robotics
week: 2
status: reviewed
source: pdf
created: 2026-05-07
tags: [EGE353, lesson-2, ROS, robot-operating-system]
---

> **Related:** [[07-DASHBOARDS/NYPY3 - Main Index|NYPY3 Index]] | [[Lesson 1-Introduction|Lesson 1]] | [[Lesson 3 Important Concepts of ROS|Lesson 3]] | [[07-DASHBOARDS/Schedule & Assessments Dashboard|Assessments]]

# Lesson 2: Robot Operating System (ROS)

**Instructor:** Chan Kit Wai · Tel: 65500559 · Chan_kit_wai@nyp.edu.sg

## Synopsis

This module equips learners with knowledge of service robots and their applications, including path planning, navigation, obstacle avoidance, and SLAM.

## Module Learning Outcomes

- Explain features of different sensors and actuators used in autonomous mobile robotics
- Perform analysis of laser and vision sensor data using visualization tools
- Implement mobile robotics systems using mapping, localization, path planning, obstacle avoidance, and motion control

---

## Introduction to ROS

ROS is an **open-source meta-operating system** for robots. It provides:

- Hardware abstraction and low-level device control
- Commonly-used functionality and message-passing between processes
- Package management, tools, and libraries for building and running code across multiple computers

*Source: [ros.org](https://www.ros.org)*

### ROS vs Traditional OS

| Traditional OS | Examples |
|----------------|----------|
| General purpose | Windows, Linux (Ubuntu, Fedora), macOS |
| Smartphones | Android, iOS |
| **Robot** | **ROS = Robot Operating System** |

ROS is **not** a traditional OS — it runs **on top of** Linux, Windows, macOS, or Android.

---

## Meta-Operating System

A meta-OS performs scheduling, loading, monitoring, error handling, and utilizes distributed computing resources as a virtualization layer between applications and hardware.

ROS uses the host OS's process management, file system, and utilities, then adds:

- Data transmission/reception libraries for heterogeneous hardware
- Robot application framework with package ecosystem

### ROS-Enabled Platforms

- Ubuntu, macOS, Windows, Fedora, Gentoo, OpenSUSE, Debian, Raspbian, Arch, QNX
- Partial support: Android, iOS
- MCU (no OS): serial, Bluetooth, LAN libraries
- **Recommended:** Ubuntu

---

## ROS Communication Infrastructure

```
Master → node ↔ node
IR sensor → [Publish/Subscribe] → Decision node → [Publish/Subscribe] → Motor control
```

| Feature | Description |
|---------|-------------|
| **Message parsing** | Standard communication interfaces between nodes |
| **Record & Play** | Store/replay messages (rosbag) for repeatable experiments |
| **Multi-language** | Nodes in different languages via messages (roscpp, rospy, rosjava, etc.) |
| **Parameters** | Global key-value variables, shared and modified in real-time |

---

## ROS Functions

### Standard Messages & Libraries
- Standard message types for camera, IMU, laser, odometry, navigation
- **TF** — robot geometry library for relative coordinates
- **URDF** — XML robot description language

### Sensing / Recognition
- Sensor drivers and recognition libraries

### Navigation
- Pose estimation and self-localization on a map
- **SLAM** for map creation
- Navigation library for path planning to destinations

---

## ROS Development Tools

### RViz
- 3D visualization of sensor data (laser, camera)
- Robot outline and planned motion
- [RViz demo](https://www.youtube.com/watch?v=7iM2ynZEuf0)

### Gazebo
- 3D simulator with physics engine
- Robot, sensor, and environment models
- Highly compatible with ROS
- [Gazebo demo](https://www.youtube.com/watch?v=dtm5X6VUbQc)

### RQT (Qt-based GUI framework)

| Tool | Purpose |
|------|---------|
| `rqt_graph` | Node/topic connection diagram |
| `rqt_plot` | Time-series plots (encoder, voltage, etc.) |
| `rqt_bag` | Record and play back messages |

---

*End of Lesson 2*
