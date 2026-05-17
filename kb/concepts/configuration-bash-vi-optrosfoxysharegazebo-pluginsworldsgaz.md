---
id: "089d5330-6b31-4a12-be83-ddd52b398f20"
title: "Configuration Bash Vi Optrosfoxysharegazebo Pluginsworldsgaz"
type: vault_note
vault: wiki
created: 2026-05-17
updated: 2026-05-17
checksum: "sha256:fb9a1376569f3afa"
source: heimdall/auto
---

# Configuration Bash Vi Optrosfoxysharegazebo Pluginsworldsgaz

- configuration:**
```bash
vi /opt/ros/foxy/share/gazebo_plugins/worlds/gazebo_ros_diff_drive_demo.world
```

Use `:q` + `Enter` to exit the vi editor. You can scroll down to analyze the script.

---

## Summary of Commands

```bash
# ===== ROS Bag with Turtlesim =====

# Start turtlesim
ros2 run turtlesim turtlesim_node

# Start keyboard teleop
ros2 run turtlesim turtle_teleop_key

# Create directory for bag files
mkdir youradmin_bag_files
cd youradmin_bag_files

# List topics
ros2 topic list

# Echo topic data
ros2 topic echo /turtle1/cmd_vel

# Record bag file
ros2 bag record -o bagfile1 /turtle1/cmd_vel /turtle1/pose

# Play bag file in loop
ros2 bag play -l bagfile1

# Get bag info
ros2 bag info bagfile1

# Record only cmd_vel
ros2 bag record -o bagfile2 /turtle1/cmd_vel

# ===== Gazebo Simulator =====

# Load Gazebo with differential drive robot
gazebo --verbose /opt/ros/humble/share/gazebo_plugins/worlds/gazebo_ros_diff_drive_demo.world

# Check Gazebo topics
ros2 topic list

# Start turtle teleop (without remap - won't work with Gazebo)
ros2 run turtlesim turtle_teleop_key

# Start turtle teleop with topic remap (for Gazebo)
ros2 run turtlesim turtle_teleop_key --ros-args --remap /turtle1/cmd_vel:=/demo/cmd_demo

# Visualize node graph
rqt_graph

# View Gazebo world configuration
vi /opt/ros/foxy/share/gazebo_plugins/worlds/gazebo_ros_diff_drive_demo.world
``` <!-- id:089d5330-6b31-4a12-be83-ddd52b398f20 ts:2026-05-17 07:49 -->
