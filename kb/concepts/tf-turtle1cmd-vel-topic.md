---
id: "20910d08-15b7-418f-ad42-4e44b493e72c"
title: "Tf Turtle1Cmd Vel Topic"
type: vault_note
vault: wiki
created: 2026-05-17
updated: 2026-05-17
checksum: "sha256:e096f59617b0857f"
source: heimdall/auto
---

# Tf Turtle1Cmd Vel Topic

- tf
/turtle1/cmd_vel
```

### Topic Remapping

The turtle_teleop_key publishes to `/turtle1/cmd_vel`, but the Gazebo robot listens to `/demo/cmd_demo`. We need to remap the topic.

**Terminal 2 - Stop teleop_key with Ctrl+C, then remap:**
```bash
ros2 run turtlesim turtle_teleop_key --ros-args --remap /turtle1/cmd_vel:=/demo/cmd_demo
```

**Terminal 4 - Verify only one cmd_vel topic:**
```bash
ros2 topic list
```

**Expected Output:**
```
/clock
/demo/cmd_demo
/parameter_events
/rosout
/tf
```

**Terminal 4 - Visualize the node graph:**
```bash
rqt_graph
```

### Viewing Gazebo World File

**Terminal 5 - View the Gazebo world configuration:**
```bash
vi /opt/ros/foxy/share/gazebo_plugins/worlds/gazebo_ros_diff_drive_demo.world
```

Use `:q` + `Enter` to exit the vi editor. <!-- id:20910d08-15b7-418f-ad42-4e44b493e72c ts:2026-05-17 07:49 -->
s:2026-05-17 07:49 -->
- tf
/turtle1/cmd_vel
```

### Topic Remapping

The turtle_teleop_key publishes to `/turtle1/cmd_vel`, but the Gazebo robot listens to `/demo/cmd_demo`. We need to remap the topic.

**Terminal 2 - Stop teleop_key with Ctrl+C, then remap:**
```bash
ros2 run turtlesim turtle_teleop_key --ros-args --remap /turtle1/cmd_vel:=/demo/cmd_demo
```

**Terminal 4 - Verify only one cmd_vel topic:**
```bash
ros2 topic list
```

**Expected Output:**
```
/clock
/demo/cmd_demo
/parameter_events
/rosout
/tf
```

**Terminal 4 - Visualize the node graph:**
```bash
rqt_graph
```

### Viewing Gazebo World File

**Terminal 5 - View the Gazebo world configuration:**
```bash
vi /opt/ros/foxy/share/gazebo_plugins/worlds/gazebo_ros_diff_drive_demo.world
```

Use `:q` + `Enter` to exit the vi editor. <!-- id:20910d08-15b7-418f-ad42-4e44b493e72c ts:2026-05-17 07:49 -->
