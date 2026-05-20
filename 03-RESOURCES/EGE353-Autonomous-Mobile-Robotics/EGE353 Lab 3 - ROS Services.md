---
type: lab
course: EGE353
module: EGE353-Autonomous-Mobile-Robotics
status: reviewed
source: pdf
created: 2026-04-28
tags: [EGE353, lab, ros2, services, parameters, lab3]
---

> **Related:** [[NYPY3 - Main Index|NYPY3 Index]] | [[EGE353 Lab 2 - ROS Nodes and Topics|Lab 2]] | [[EGE353 Lab 4 - ROS Bag Files and Gazebo|Lab 4]] | [[Schedule & Assessments Dashboard|Assessments]]

# Lab 3: ROS2 Services and Parameters

**Instructor:** Chan Kit Wai · Tel: 65500559 · Chan_kit_wai@nyp.edu.sg

## Synopsis

This module equips learners with knowledge of service robots and their applications, including path planning, navigation, obstacle avoidance, and SLAM.

## Module Learning Outcomes

- Explain features of different sensors and actuators used in autonomous mobile robotics
- Perform analysis of laser and vision sensor data using visualization tools
- Implement mobile robotics systems using mapping, localization, path planning, obstacle avoidance, and motion control

---

## ROS Services

Services use a **call-and-response** model (vs topics' publisher-subscriber). A client sends a request; the server processes it and returns a response. Use services for one-off actions, not continuous data streams.

### TASK 1 — Service Call

**Terminal 1:**
```bash
ros2 run turtlesim turtlesim_node
```

**Terminal 2:**
```bash
ros2 service list
```

**Terminal 3:**
```bash
ros2 run turtlesim turtle_teleop_key
```

**Q1)** Rerun `ros2 service list` on Terminal 2 — note new services after teleop starts:

```
/reset
/spawn
/teleop_turtle/describe_parameters
/teleop_turtle/get_parameter_types
/teleop_turtle/get_parameters
/teleop_turtle/list_parameters
/teleop_turtle/set_parameters
/teleop_turtle/set_parameters_atomically
/turtle1/set_pen
/turtle1/teleport_absolute
/turtle1/teleport_relative
/turtlesim/describe_parameters
/turtlesim/get_parameter_types
/turtlesim/get_parameters
/turtlesim/list_parameters
/turtlesim/set_parameters
/turtlesim/set_parameters_atomically
```

Inspect service types:

```bash
ros2 service type /clear                    # std_srvs/srv/Empty
ros2 service list -t                        # all services with types
ros2 service find std_srvs/srv/Empty        # /clear, /reset
ros2 interface show turtlesim/srv/Spawn       # request/response structure
```

Spawn and kill turtles:

```bash
ros2 service call /spawn turtlesim/srv/Spawn "{x: 2, y: 2, theta: 0.2, name: ''}"
ros2 service call /kill turtlesim/srv/Kill "{name: 'turtle1'}"
```

Service call syntax: `ros2 service call <service_name> <service_type> <arguments>` (YAML syntax for arguments).

**Q2)** Spawn turtles at these locations:

| Turtle | x | y | theta |
|--------|---|---|-------|
| 3 | 10 | 10 | 3.14/4 |
| 4 | 6 | 1 | 3 |
| 5 | 2 | 7 | 8 |
| 6 | 9 | 13 | 9 |

**Spawn 9 turtles in a circle (45° apart, radius 3.5, pointing outward):**

```bash
ros2 service call /spawn turtlesim/srv/Spawn "{x: 9.0, y: 5.5, theta: 0, name: ''}"
ros2 service call /spawn turtlesim/srv/Spawn "{x: 7.97, y: 7.97, theta: 0.785, name: ''}"
ros2 service call /spawn turtlesim/srv/Spawn "{x: 5.5, y: 9.0, theta: 1.571, name: ''}"
ros2 service call /spawn turtlesim/srv/Spawn "{x: 3.03, y: 7.97, theta: 2.356, name: ''}"
ros2 service call /spawn turtlesim/srv/Spawn "{x: 2.0, y: 5.5, theta: 3.142, name: ''}"
ros2 service call /spawn turtlesim/srv/Spawn "{x: 3.03, y: 3.03, theta: 3.927, name: ''}"
ros2 service call /spawn turtlesim/srv/Spawn "{x: 5.5, y: 2.0, theta: 4.712, name: ''}"
ros2 service call /spawn turtlesim/srv/Spawn "{x: 7.97, y: 3.03, theta: 5.498, name: ''}"
ros2 service call /spawn turtlesim/srv/Spawn "{x: 8.5, y: 5.5, theta: 6.283, name: ''}"
```

### TASK 2 — Using RQT to Set Pen

Close all terminals. Open 4 new terminals:

| Terminal | Command |
|----------|---------|
| 1 | `ros2 run turtlesim turtlesim_node` |
| 2 | `ros2 run turtlesim turtle_teleop_key` |
| 3 | `rqt` → Service Caller → `/turtle1/set_pen` |
| 4 | `ros2 topic pub --once /turtle1/cmd_vel geometry_msgs/msg/Twist "{linear: {x: 2.0, y: 0.0, z: 0.0}, angular: {x: 0.0, y: 0.0, z: 1.8}}"` |

Set pen g=255, width=5 → draw a shape. Change to purple, width=10. Draw 2 circles with `ros2 topic pub`.

**Spawn Turtle2** — Ctrl+C teleop, then:

```bash
ros2 service call /spawn turtlesim/srv/Spawn "{x: 2, y: 2, theta: 0.2, name: ''}"
ros2 run turtlesim turtle_teleop_key --ros-args --remap turtle1/cmd_vel:=turtle2/cmd_vel
ros2 topic list    # observe multiple cmd_vel topics
```

**Q3)** Modify pen colour and draw different circles/lines with 3+ turtles. Screenshot results.

---

## ROS Parameters

Parameters are **node configuration values** (int, float, bool, string, lists). Each node maintains its own parameters; they can be read/written at runtime.

### TASK 3 — ROS Parameters (Optional)

| Terminal | Command |
|----------|---------|
| 1 | `ros2 run turtlesim turtlesim_node` |
| 2 | `ros2 run turtlesim turtle_teleop_key` |
| 3 | `ros2 param list` |

```bash
ros2 param get /turtlesim background_g       # default: 86
ros2 param set /turtlesim background_r 150
ros2 param dump /turtlesim                   # saves turtlesim.yaml
cat turtlesim.yaml
```

**Q4)** Set background to purple (r=150, g=86, b=255). Screenshot terminal and simulation.

Load saved parameters:

```bash
ros2 run turtlesim turtlesim_node --ros-args --params-file ./turtlesim.yaml
```

Compare with default (no params file) — background colour differs.

---

## Teaching Points Summary

### Topics
- Publisher-subscriber model for continuous data streams
- Remap: `--ros-args --remap old_topic:=new_topic`
- Publish: `ros2 topic pub`; list: `ros2 topic list`

### Multiple Turtles
- Spawn: `/spawn` service; kill: `/kill` service
- Each turtle gets own topics (`/turtleN/cmd_vel`) and services (`/turtleN/set_pen`)

### Services
- Call-and-response (synchronous, one-time)
- Discovery: `ros2 service list`, `-t` for types
- Inspect: `ros2 interface show <type>`
- Call: `ros2 service call <name> <type> <args>`

### Parameters
- Per-node config; get/set/dump/load via CLI
- Persist with `--params-file` at startup

---

## Command List (Copy-Paste Ready)

```bash
# ===== TASK 1 =====
ros2 run turtlesim turtlesim_node
ros2 service list
ros2 run turtlesim turtle_teleop_key
ros2 service list
ros2 service type /clear
ros2 service list -t
ros2 service find std_srvs/srv/Empty
ros2 interface show turtlesim/srv/Spawn
ros2 service call /spawn turtlesim/srv/Spawn "{x: 2, y: 2, theta: 0.2, name: ''}"
ros2 service call /kill turtlesim/srv/Kill "{name: 'turtle1'}"

# ===== TASK 2 =====
ros2 run turtlesim turtlesim_node
ros2 run turtlesim turtle_teleop_key
rqt
ros2 topic pub --once /turtle1/cmd_vel geometry_msgs/msg/Twist "{linear: {x: 2.0, y: 0.0, z: 0.0}, angular: {x: 0.0, y: 0.0, z: 1.8}}"
ros2 service call /spawn turtlesim/srv/Spawn "{x: 2, y: 2, theta: 0.2, name: ''}"
ros2 run turtlesim turtle_teleop_key --ros-args --remap turtle1/cmd_vel:=turtle2/cmd_vel
ros2 topic list

# ===== TASK 3 =====
ros2 run turtlesim turtlesim_node
ros2 run turtlesim turtle_teleop_key
ros2 param list
ros2 param get /turtlesim background_g
ros2 param set /turtlesim background_r 150
ros2 param dump /turtlesim
cat turtlesim.yaml
ros2 run turtlesim turtlesim_node --ros-args --params-file ./turtlesim.yaml
```
