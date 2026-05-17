---
id: "82a5afc2-9eec-40b8-96a2-325d5dfda632"
title: "Os2 Topic Echo Turtle1Pose 7"
type: vault_note
vault: wiki
created: 2026-05-17
updated: 2026-05-17
checksum: "sha256:504526947cab4be4"
source: heimdall/auto
---

# Os2 Topic Echo Turtle1Pose 7

- os2 topic echo /turtle1/pose`)
7. Using ros topic hz to display the publishing rate for `/turtle1/cmd_vel` (i.e., `ros2 topic hz /turtle1/cmd_vel`)
8. Must demo to the instructor and remember to screenshot all commands and results

---

## Gazebo Simulator

### Task Overview

**Task:** To run 2 nodes - teleop key node and Gazebo simulator

Close all programs (`Ctrl+C`) and close all terminals.

### Loading Gazebo with Robot

**Terminal 1 - Load Gazebo with differential drive robot:**
```bash
gazebo --verbose /opt/ros/foxy/share/gazebo_plugins/worlds/gazebo_ros_diff_drive_demo.world
```

**Terminal 2 - Check topics:**
```bash
ros2 topic list
```

**Expected Output:**
```
/clock
/demo/cmd_demo
/demo/odom_demo
/parameter_events
/rosout
/tf
```

**Terminal 2 - Try turtle_teleop_key:**
```bash
ros2 run turtlesim turtle_teleop_key
```

**Question:** Attempt to control the robot using the turtle_teleop_key. Does it work? Why not?

**Terminal 3 - Check turtlesim topics:**
```bash
ros2 topic list
```

**Expected Output:**
```
/clock
/demo/cmd_demo
/demo/odom_demo
/parameter_events
/rosout
/tf
/turtle1/cmd_vel
```

### Topic Remapping

The turtle_teleop_key publishes to `/turtle1/cmd_vel`, but the Gazebo robot listens to `/demo/cmd_demo`. <!-- id:82a5afc2-9eec-40b8-96a2-325d5dfda632 ts:2026-05-17 07:49 -->
