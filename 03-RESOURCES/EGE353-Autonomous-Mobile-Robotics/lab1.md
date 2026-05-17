---
tags:
  - EGE353
  - robotics
  - ROS
  - lab
  - turtlesim
  - practical
  - lab1
course: EGE353 Autonomous Mobile Robotics
lab: 1
topic: Understanding ROS Nodes and TurtleSim
source: NYPY3 Import
created: 2026-05-17
type: Lab
status: Completed
---

> 📚 **Related:** [[NYPY3 - Main Index|NYPY3 Index]] | [[📅 Schedule & Assessments Dashboard|Assessment Dashboard]] | [[03-RESOURCES/EGE353-Autonomous-Mobile-Robotics/Lesson 1-Introduction.md|Lesson 1: Introduction]]

# EGE353 Autonomous Mobile Robotics
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
5. Click **Run** to launch the rosject

### Interface Overview

| Element | Description |
|---------|-------------|
| Shell / Terminal icon | Opens a new terminal window |
| Code editor icon | Opens the VS Code-style editor |
| Terminal tabs (`#564`, `#570`, etc.) | Multiple shell sessions |

---

## Nodes in ROS2

### Starting TurtleSim

In **Terminal 1**, run:

```bash
source /opt/ros/humble/setup.bash
ros2 run turtlesim turtlesim_node
```

Expected output:
```
[INFO] [turtlesim]: Starting turtlesim with node name /turtlesim
[INFO] [turtlesim]: Spawning turtle [turtle1] at x=[5.544445], y=[5.544445], theta=[0.000000]
```

### Listing Nodes

In **Terminal 2**, run:

```bash
source /opt/ros/humble/setup.bash
ros2 node list
```

Expected output:
```
/turtlesim
```

### Controlling the Turtle (Teleop)

In **Terminal 3**, run:

```bash
ros2 run turtlesim turtle_teleop_key
```

> ⚠️ Make sure you click on Terminal 3 before pressing the arrow keys.

Expected output:
```
Reading from keyboard
---------------------------
Use arrow keys to move the turtle.
Use G|B|V|C|D|E|R|T keys to rotate to absolute orientations. 'F' to cancel a rotation.
'Q' to quit.
```

### Node Architecture

```
teleop_turtle          Topic:              turtlesim
(Publisher Node)  →  /turtle1/cmd_vel  →  (Subscriber Node)
```

- **Node 1 (Subscriber):** `turtlesim_node` — started with `ros2 run turtlesim turtlesim_node`
- **Node 2 (Publisher):** `turtle_teleop_key` — started with `ros2 run turtlesim turtle_teleop_key`

---

## Visualising with rqt_graph

In **Terminal 4**, run:

```bash
rqt_graph
```

`rqt_graph` visualises the active nodes, topics, and connections between them. Click the **refresh** button to update the graph.

The graph shows:
- `/teleop_turtle` publishes keystrokes to `/turtle1/cmd_vel`
- `/turtlesim` subscribes to `/turtle1/cmd_vel` to receive movement data

---

## ROS 2 Commands Reference

Open a new terminal for each command and observe the output:

```bash
ros2 node list
ros2 topic list
ros2 service list
ros2 action list
```

---

## ros2 topic echo

In **Terminal 5**, run:

```bash
ros2 topic echo /turtle1/cmd_vel
```

Move the turtle using `turtle_teleop_key` and observe the output:

```
linear:
  x: 2.0
  y: 0.0
  z: 0.0
angular:
  x: 0.0
  y: 0.0
  z: 0.0
```

---

## ros2 topic pub

Close all existing terminals with `Ctrl+C`, then open new ones.

**Terminal 1:**
```bash
ros2 run turtlesim turtlesim_node
```

**Terminal 2:**
```bash
ros2 run turtlesim turtle_teleop_key
```

**Terminal 3** — publish a single message:
```bash
ros2 topic pub --once /turtle1/cmd_vel geometry_msgs/msg/Twist \
"{linear: {x: 2.0, y: 0.0, z: 0.0}, angular: {x: 0.0, y: 0.0, z: 1.8}}"
```

Expected output:
```
publisher: beginning loop
publishing #1: geometry_msgs.msg.Twist(linear=geometry_msgs.msg.Vector3(x=2.0, y=0.0, z=0.0), angular=geometry_msgs.msg.Vector3(x=0.0, y=0.0, z=1.8))
```

**Syntax:**
```bash
ros2 topic pub <topic_name> <msg_type> '<args>'
```

- **Linear speed** = Distance / Time — unit: m/s
- **Angular speed** — unit: radians/second (rad/s)

### Continuous Publishing

```bash
ros2 topic pub --rate 1 /turtle1/cmd_vel geometry_msgs/msg/Twist \
"{linear: {x: 2.0, y: 0.0, z: 0.0}, angular: {x: 0.0, y: 0.0, z: 1.8}}"
```

> The `--rate 1` flag publishes continuously at 1 message per second (vs `--once` which publishes only once). The turtle will move in a circle continuously.

---

## ros2 topic echo — Pose

```bash
ros2 topic echo /turtle1/pose
```

Run alongside the publisher above and observe `linear_velocity` and `angular_velocity`.

**Exercises:**
- Change linear x to `4.0` and angular z to `5.8` — observe the changes
- Change linear x to `1.0` and angular z to `0.8` — observe the changes

---

## ros2 topic hz

Publish command velocity in one terminal:
```bash
ros2 topic pub --rate 1 /turtle1/cmd_vel geometry_msgs/msg/Twist \
"{linear: {x: 2.0, y: 0.0, z: 0.0}, angular: {x: 0.0, y: 0.0, z: 1.8}}"
```

In a new terminal, check the publish rate:
```bash
ros2 topic hz /turtle1/cmd_vel
```

Expected output:
```
average rate: 1.000
    min: 0.998s max: 1.001s std dev: 0.00065s window: 22
```

**Exercise:** Modify the command so the average rate is `2.0` (2 times per second).

Press `Ctrl+C` to stop each process when done.

---

## Demo Questions

> Be prepared to answer these questions during the demo.

**Q1) Is `turtle_teleop_key` a subscriber or publisher? Explain.**

A1) It is a **Publisher**. From the `rqt_graph`, it publishes to a topic and does not subscribe to any topic.

**Q2) What is the topic that the turtlesim node subscribes to?**

A2) `/turtle1/cmd_vel`

**Q3) Explain the function of `ros2 topic pub <topic_name> <msg_type> '<args>'`**

A3) It publishes a message to a specified topic with a given message type and arguments. For example, `--rate 1` publishes the message once per second continuously.

**Q4) Explain the difference between linear and angular velocity.**

A4) Linear and angular are two different types of motion:
- **Linear motion** is motion in a straight line. Linear speed = Distance / Time (unit: m/s).
- **Angular motion** is the motion of a body about a fixed point or axis, moving along a curved path (unit: rad/s).

The key difference is the path the object follows — straight for linear, curved for angular.

---

## Quick Command Reference

### Setup
```bash
source /opt/ros/humble/setup.bash
```

### Start TurtleSim
```bash
ros2 run turtlesim turtlesim_node
```

### Start Teleop Control
```bash
ros2 run turtlesim turtle_teleop_key
```

### List Commands
```bash
ros2 node list
ros2 topic list
ros2 service list
ros2 action list
```

### Visualize Graph
```bash
rqt_graph
```

### Echo Topic (Monitor Messages)
```bash
ros2 topic echo /turtle1/cmd_vel
ros2 topic echo /turtle1/pose
```

### Publish Once
```bash
ros2 topic pub --once /turtle1/cmd_vel geometry_msgs/msg/Twist "{linear: {x: 2.0, y: 0.0, z: 0.0}, angular: {x: 0.0, y: 0.0, z: 1.8}}"
```

### Publish Continuously (1 Hz)
```bash
	ros2 topic pub --rate 1 /turtle1/cmd_vel geometry_msgs/msg/Twist "{linear: {x: 2.0, y: 0.0, z: 0.0}, angular: {x: 0.0, y: 0.0, z: 1.8}}"
```

### Check Topic Frequency
```bash
ros2 topic hz /turtle1/cmd_vel
```

---

*End of Lab 1*