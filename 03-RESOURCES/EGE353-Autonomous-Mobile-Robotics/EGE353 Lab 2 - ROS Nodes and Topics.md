---
type: lab
course: EGE353
module: EGE353-Autonomous-Mobile-Robotics
status: reviewed
source: pdf
created: 2026-04-28
tags: [EGE353, lab, ros2, nodes, topics, lab2]
---

> **Related:** [[07-DASHBOARDS/NYPY3 - Main Index|NYPY3 Index]] | [[EGE353 Lab 1 Notes|Lab 1]] | [[EGE353 Lab 3 - ROS Services|Lab 3]] | [[07-DASHBOARDS/Schedule & Assessments Dashboard|Assessments]]

# Lab 2: ROS2 Nodes and Topics

**Instructor:** Chan Kit Wai · Tel: 65500559 · Chan_kit_wai@nyp.edu.sg

## Synopsis

This module equips learners with knowledge of service robots and their applications, including path planning, navigation, obstacle avoidance, and SLAM.

## Module Learning Outcomes

- Explain features of different sensors and actuators used in autonomous mobile robotics
- Perform analysis of laser and vision sensor data using visualization tools
- Implement mobile robotics systems using mapping, localization, path planning, obstacle avoidance, and motion control

---

## Task: Nodes in ROS2

### Step 1 — Create Workspace & Clone Package

```bash
mkdir lab1b_ws
cd lab1b_ws
mkdir src
cd src
git clone https://github.com/1at7/teleop_cpp_ros2.git
cd ..
colcon build --packages-select teleop_cpp_ros2
source install/setup.bash
```

### Step 2 — Run Teleop Node

```bash
ros2 run teleop_cpp_ros2 teleop
```

Keyboard layout for holonomic control:

```
Moving around:        Holonomic (hold Shift):
   u    i    o            U    I    O
   j    k    l            J    K    L
   m    ,    .            M    <    >
```

### Step 3 — Turtlesim & Topic Inspection

Open **Shell 2** with 4 terminals:

| Terminal | Command |
|----------|---------|
| 1 | `ros2 run turtlesim turtlesim_node` |
| 2 | `ros2 topic list` |
| 3 | `ros2 topic echo /cmd_vel` |
| 4 | `rqt_graph` |

Observe two `/cmd_vel` topics — teleop and turtlesim are **not linked** yet.

### Step 4 — Topic Remapping

Stop teleop (`Ctrl+C`), then remap:

```bash
source install/setup.bash
ros2 run teleop_cpp_ros2 teleop --ros-args --remap /cmd_vel:=/turtle1/cmd_vel
```

Use arrow keys to control the turtle. Alternatively, change the topic name in `teleop_cpp_ros2.cpp` source code.

### Coordinate System (Twist)

| Axis | Non-holonomic turtle | Holonomic robot |
|------|---------------------|-----------------|
| **linear.x** | Forward/backward | Forward/backward |
| **linear.y** | Unused (0) | Left/right strafe |
| **angular.z** | Rotation (yaw) | Rotation (yaw) |

---

## Lab Questions & Answers

**Q1) Explain the operation of `git clone`.**

**A:** `git clone` creates a local copy of a remote repository, downloading all files, version history, and metadata.

**Q2) Explain `colcon build --packages-select teleop_cpp_ros2`.**

**A:** `colcon build` is the ROS2 build tool. `--packages-select` builds **only** the named package, saving time.

**Q3) What is the frequency of the published topic `/cmd_vel`?**

**A:** Event-based — a message is published **only when a key is pressed**, not at a fixed rate.

**Q4) What does `ros2 topic list` do?**

**A:** Lists all active topics in the current ROS graph.

**Q5) What does `ros2 topic echo /turtle1/cmd_vel` do?**

**A:** Displays messages published to `/turtle1/cmd_vel` in real time (linear and angular velocity values).

**Q6) Write the line of code that publishes `/turtle1/cmd_vel`.**

**A:**
```cpp
publisher_ = this->create_publisher<geometry_msgs::msg::Twist>("cmd_vel", 10);
publisher_->publish(msg);
```
Topic can be remapped at runtime or changed in source.

**Q7) Where are the x, y, and z directions on the turtlebot?**

**A:**
- **X** — forward/backward (linear.x)
- **Y** — left/right strafe (linear.y, holonomic only)
- **Z** — rotation/yaw (angular.z)

---

## Command List (Copy-Paste Ready)

```bash
# ===== SETUP WORKSPACE =====
mkdir lab1b_ws
cd lab1b_ws
mkdir src && cd src
git clone https://github.com/1at7/teleop_cpp_ros2.git
cd ..
colcon build --packages-select teleop_cpp_ros2
source install/setup.bash

# ===== RUN TELEOP (Terminal 1) =====
ros2 run teleop_cpp_ros2 teleop

# ===== SHELL 2 — 4 TERMINALS =====
ros2 run turtlesim turtlesim_node
ros2 topic list
ros2 topic echo /cmd_vel
rqt_graph

# ===== REMAPPED TELEOP =====
source install/setup.bash
ros2 run teleop_cpp_ros2 teleop --ros-args --remap /cmd_vel:=/turtle1/cmd_vel
```
