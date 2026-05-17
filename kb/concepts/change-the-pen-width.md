---
id: "ae1b214e-8196-4450-9e96-92c05ec2e94d"
title: "Change The Pen Width"
type: vault_note
vault: wiki
created: 2026-05-17
updated: 2026-05-17
checksum: "sha256:242b6897e90c1f97"
source: heimdall/auto
---

# Change The Pen Width

- .

Change the pen width to 10 and pen colour to purple.

Using ros topic pub, publish the cmd_vel to control the turtlesim to draw 2 circles as shown. The size of circle can be random.

Open a 4th terminal and run the following:

```bash
$ ros2 topic pub --once /turtle1/cmd_vel geometry_msgs/msg/Twist "{linear: {x: 2.0, y: 0.0, z: 0.0}, angular: {x: 0.0, y: 0.0, z: 1.8}}"
```

#### Spawn Turtle2

Return to 2nd terminal and Ctrl+C to terminate the turtle_teleop_key.

```bash
$ ros2 service call /spawn turtlesim/srv/Spawn "{x: 2, y: 2, theta: 0.2, name: ''}"
```

Open a new terminal and run a new teleop_key, remap the topic turtle1/cmd_vel to turtle2/cmd_vel so that you are able to control the new turtle2:

```bash
$ ros2 run turtlesim turtle_teleop_key --ros-args --remap turtle1/cmd_vel:=turtle2/cmd_vel
```

Open a new terminal:

```bash
$ ros2 topic list
```

Observe the output, how many cmd_vel did you see? Control the turtle2 to draw a white line as shown.

#### Spawn 3 Turtles

**Q3)** Modify the pen colour to your choice of colour and draw different circles or line with the 3 or more turtles. Screenshot your results.

## ROS Parameters

A parameter is a configuration value of a node. You can think of parameters as node settings. A node can store parameters as integers, floats, booleans, strings, and lists. In ROS 2, each node maintains its own parameters. Parameters in ROS are associated with individual nodes. <!-- id:ae1b214e-8196-4450-9e96-92c05ec2e94d ts:2026-05-17 07:49 -->
- .

Change the pen width to 10 and pen colour to purple.

Using ros topic pub, publish the cmd_vel to control the turtlesim to draw 2 circles as shown. The size of circle can be random.

Open a 4th terminal and run the following:

```bash
$ ros2 topic pub --once /turtle1/cmd_vel geometry_msgs/msg/Twist "{linear: {x: 2.0, y: 0.0, z: 0.0}, angular: {x: 0.0, y: 0.0, z: 1.8}}"
```

#### Spawn Turtle2

Return to 2nd terminal and Ctrl+C to terminate the turtle_teleop_key.

```bash
$ ros2 service call /spawn turtlesim/srv/Spawn "{x: 2, y: 2, theta: 0.2, name: ''}"
```

Open a new terminal and run a new teleop_key, remap the topic turtle1/cmd_vel to turtle2/cmd_vel so that you are able to control the new turtle2:

```bash
$ ros2 run turtlesim turtle_teleop_key --ros-args --remap turtle1/cmd_vel:=turtle2/cmd_vel
```

Open a new terminal:

```bash
$ ros2 topic list
```

Observe the output, how many cmd_vel did you see? Control the turtle2 to draw a white line as shown.

#### Spawn 3 Turtles

**Q3)** Modify the pen colour to your choice of colour and draw different circles or line with the 3 or more turtles. Screenshot your results.

## ROS Parameters

A parameter is a configuration value of a node. You can think of parameters as node settings. A node can store parameters as integers, floats, booleans, strings, and lists. In ROS 2, each node maintains its own parameters. Parameters in ROS are associated with individual nodes. <!-- id:ae1b214e-8196-4450-9e96-92c05ec2e94d ts:2026-05-17 07:49 -->
