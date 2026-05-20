---
type: lab
course: EGE353
module: EGE353-Autonomous-Mobile-Robotics
status: reviewed
source: pdf
created: 2026-05-08
tags: [EGE353, lab, ros2, rosbag, gazebo, lab4]
---

> **Related:** [[NYPY3 - Main Index|NYPY3 Index]] | [[EGE353 Lab 3 - ROS Services|Lab 3]] | [[EGE353 Lab 5 Notes|Lab 5]] | [[Schedule & Assessments Dashboard|Assessments]]

# Lab 4: ROS Bag Files and Gazebo

**Instructor:** Chan Kit Wai · Tel: 65500559 · Chan_kit_wai@nyp.edu.sg

## Module Learning Outcomes

- Explain features of different sensors and actuators used in autonomous mobile robotics
- Perform analysis of laser and vision sensor data using visualization tools
- Implement mobile robotics systems using mapping, localization, path planning, obstacle avoidance, and motion control

## Lab Session Learning Outcomes

- Record data published on topics
- Playback recorded topics
- Run Gazebo simulator and control a simulated robot with keyboard

---

## ROS Bag Overview

ROS2 bag records data published on topics and saves it to a database for later replay.

**Use cases:**
- Share work and allow others to recreate experiments
- Record data during live experiments (warehouse, outdoor)
- Replay in lab for analysis, development, or simulation

**Three main commands:** `record` · `play` · `info`

**Video:** [ROS Bag Tutorial](https://www.youtube.com/watch?v=pwlbArh_neU)

---

## ROS Bag with Turtlesim

### Setup (3 terminals)

```bash
# Terminal 1
ros2 run turtlesim turtlesim_node

# Terminal 2
ros2 run turtlesim turtle_teleop_key

# Terminal 3
mkdir youradmin_bag_files && cd youradmin_bag_files
ros2 topic list
```

**Expected topics:**
```
/parameter_events
/rosout
/turtle1/cmd_vel
/turtle1/color_sensor
/turtle1/pose
```

### Q1 — Which node/topic moves the turtle?

| | |
|---|---|
| **Node** | `turtle_teleop_key` |
| **Topic** | `/turtle1/cmd_vel` |

### Echo Topic Data

```bash
ros2 topic echo /turtle1/cmd_vel
```

Move turtle with arrow keys — observe linear.x and angular.z changes.

---

## Recording & Playback

### Record

```bash
ros2 bag record -o bagfile1 /turtle1/cmd_vel /turtle1/pose
```

Draw a square with teleop, then `Ctrl+C` to stop. Verify with `ls` — `bagfile1` folder created.

### Play

Stop turtlesim and teleop, then:

```bash
ros2 bag play -l bagfile1
```

Turtle replays the square without keyboard input.

### Info

```bash
ros2 bag info bagfile1
```

Example output:
```
Duration: 16.943s
Messages: 1069
Topic: /turtle1/pose | Count: 1060
Topic: /turtle1/cmd_vel | Count: 9
```

`/cmd_vel` count is low (key presses only); `/pose` is continuous.

---

## Q2 — Record cmd_vel Only

1. Draw a square with `turtle_teleop_key`
2. Stop teleop; close turtlesim
3. Record only cmd_vel → `bagfile2`
4. Replay in loop — does turtlesim redraw the square?
5. Run `rqt_graph` (refresh active nodes) — rosbag → `/turtle1/cmd_vel` → `/turtlesim`
6. Echo `/turtle1/pose`; use `ros2 topic hz /turtle1/cmd_vel`
7. Demo to instructor with screenshots

```bash
ros2 bag record -o bagfile2 /turtle1/cmd_vel
ros2 bag play -l bagfile2
rqt_graph
ros2 topic echo /turtle1/pose
ros2 topic hz /turtle1/cmd_vel
```

---

## Gazebo Simulator

Close all programs. Run teleop + Gazebo.

### Load Gazebo

```bash
# Terminal 1
gazebo --verbose /opt/ros/humble/share/gazebo_plugins/worlds/gazebo_ros_diff_drive_demo.world

# Terminal 2
ros2 topic list
```

**Expected topics:** `/clock`, `/demo/cmd_demo`, `/demo/odom_demo`, `/parameter_events`, `/rosout`, `/tf`

### Q — Does turtle_teleop_key work without remap?

**No.** Teleop publishes to `/turtle1/cmd_vel`; Gazebo robot listens on `/demo/cmd_demo`.

### Topic Remapping

```bash
# Terminal 2 (after Ctrl+C on default teleop)
ros2 run turtlesim turtle_teleop_key --ros-args --remap /turtle1/cmd_vel:=/demo/cmd_demo

# Terminal 3
rqt_graph
```

### View World File

```bash
vi /opt/ros/humble/share/gazebo_plugins/worlds/gazebo_ros_diff_drive_demo.world
```

---

## Command List

```bash
# ===== ROS Bag =====
ros2 run turtlesim turtlesim_node
ros2 run turtlesim turtle_teleop_key
mkdir youradmin_bag_files && cd youradmin_bag_files
ros2 topic list
ros2 topic echo /turtle1/cmd_vel
ros2 bag record -o bagfile1 /turtle1/cmd_vel /turtle1/pose
ros2 bag play -l bagfile1
ros2 bag info bagfile1
ros2 bag record -o bagfile2 /turtle1/cmd_vel

# ===== Gazebo =====
gazebo --verbose /opt/ros/humble/share/gazebo_plugins/worlds/gazebo_ros_diff_drive_demo.world
ros2 topic list
ros2 run turtlesim turtle_teleop_key --ros-args --remap /turtle1/cmd_vel:=/demo/cmd_demo
rqt_graph
```
