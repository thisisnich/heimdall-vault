---
type: lab
course: EGE353
module: EGE353-Autonomous-Mobile-Robotics
status: reviewed
source: pdf
created: 2026-05-17
tags: [EGE353, lab, ros2, topics, lab1]
---

> **Related:** [[07-DASHBOARDS/NYPY3 - Main Index|NYPY3 Index]] | [[Lab 1 - ROS Nodes and TurtleSim|Lab 1 Slides]] | [[EGE353 Lab 2 - ROS Nodes and Topics|Lab 2]] | [[07-DASHBOARDS/Schedule & Assessments Dashboard|Assessments]]

> **Lab Materials:** [[Lab 1 - ROS Nodes and TurtleSim.pdf|PDF]] · [[Lab 1 - ROS Nodes and TurtleSim|Markdown]]

# Lab 1: ROS2 Topics & TurtleSim

**Instructor:** Chan Kit Wai · Tel: 65500559 · Chan_kit_wai@nyp.edu.sg

## Setup

Login to your Construct account: https://app.theconstruct.ai/

## Understanding ROS2 Topics

Reference: [Understanding ROS2 Topics (Humble)](https://docs.ros.org/en/humble/Tutorials/Beginner-CLI-Tools/Understanding-ROS2-Topics/Understanding-ROS2-Topics.html)

## Terminal Basics

- A blinking cursor in an active terminal means a process is running
- Use `Ctrl+C` to stop a running process

## Theta (Orientation)

Theta represents the orientation/rotation angle in ROS2 coordinate systems.

- Measured in **radians**
- Positive theta = counterclockwise rotation
- Negative theta = clockwise rotation

## Nodes in ROS2

### Start Turtlesim

```bash
source /opt/ros/humble/setup.bash
ros2 run turtlesim turtlesim_node
```

### List Nodes & Topics

```bash
ros2 node list
ros2 topic list
ros2 service list
ros2 action list
```

### Keyboard Teleop

```bash
ros2 run turtlesim turtle_teleop_key
```

Click the teleop terminal before pressing arrow keys.

### Visualize with rqt_graph

```bash
rqt_graph
```

The `/teleop_turtle` node publishes to `/turtle1/cmd_vel`; `/turtlesim` subscribes to it.

### Topic Echo

```bash
ros2 topic echo /turtle1/cmd_vel
```

### Publish from CLI

```bash
ros2 topic pub --once /turtle1/cmd_vel geometry_msgs/msg/Twist "{linear: {x: 2.0, y: 0.0, z: 0.0}, angular: {x: 0.0, y: 0.0, z: 1.8}}"
```

- **Linear speed** = distance / time (m/s)
- **Angular speed** = rad/s

### Topic Rate

```bash
ros2 topic pub --rate 1 /turtle1/cmd_vel geometry_msgs/msg/Twist "{linear: {x: 2.0, y: 0.0, z: 0.0}, angular: {x: 0.0, y: 0.0, z: 1.8}}"
ros2 topic hz /turtle1/cmd_vel
```

**Task:** Modify the command so average rate is 2.0 Hz.

## Demo Questions

| # | Question | Answer |
|---|----------|--------|
| Q1 | Is `turtle_teleop_key` a subscriber or publisher? | **Publisher** — it publishes to `/turtle1/cmd_vel` |
| Q2 | What topic does turtlesim subscribe to? | `/turtle1/cmd_vel` |
| Q3 | What does `ros2 topic pub <topic> <msg_type> '<args>'` do? | Publishes a message of the given type to the topic |
| Q4 | Difference between linear and angular velocity? | Linear = straight-line motion (m/s); angular = rotation about an axis (rad/s) |

## Command List

```bash
source /opt/ros/humble/setup.bash
ros2 run turtlesim turtlesim_node
ros2 run turtlesim turtle_teleop_key
rqt_graph
ros2 topic echo /turtle1/cmd_vel
ros2 topic pub --once /turtle1/cmd_vel geometry_msgs/msg/Twist "{linear: {x: 2.0, y: 0.0, z: 0.0}, angular: {x: 0.0, y: 0.0, z: 1.8}}"
ros2 topic pub --rate 1 /turtle1/cmd_vel geometry_msgs/msg/Twist "{linear: {x: 2.0, y: 0.0, z: 0.0}, angular: {x: 0.0, y: 0.0, z: 1.8}}"
ros2 topic hz /turtle1/cmd_vel
```
