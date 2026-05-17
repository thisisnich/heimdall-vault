---
tags:
  - EGE353
  - lab
  - ros2
  - rosbag
  - gazebo
  - simulation
course: EGE353 Autonomous Robotics
topic: Lab 4 - ROS Bag Files and Gazebo
source: Lab4 Ros bag files.pdf
converted: 2026-05-08
---

> **Related:** [[EGE353 Lab 1 Notes|Lab 1]] | [[EGE353 Lab 2 - ROS Nodes and Topics|Lab 2]] | [[EGE353 Lab 3 - ROS Services|Lab 3]]

# Lab 4: ROS Bag Files and Gazebo

## Course Information

| Field | Details |
|-------|---------|
| **Course** | EGE353 Autonomous Mobile Robotics |
| **Module** | Service mobile robots, concepts of path planning, navigation, obstacle avoidance, simultaneous localisation and mapping |
| **Lecturer** | Chan Kit Wai |
| **Contact** | Tel: 65500559, Email: Chan_kit_wai@nyp.edu.sg |

## Module Synopsis

This module aims to equip learners with the knowledge of service robots and their applications. Learners will also study the concepts of path planning, navigation, obstacle avoidance, simultaneous localisation and mapping. They will be able to implement mobile robotics system to carry out tasks autonomously.

## Module Learning Outcomes

At the end of the module, learners are able to:
- Explain the features of different sensors and actuators used in autonomous mobile robotics
- Perform the analysis of laser and vision sensor data using visualization tools
- Implement mobile robotics system using methods such as mapping, localization, path planning, obstacle avoidance and motion control

## Lab Session Learning Outcomes

At the end of the sessions, learners are able to:
- Record data published on topics
- Playback recorded topics
- Run gazebo simulator and use keyboard to control a simulated robot

---

## ROS Bag Overview

### What is ROS Bag?

ROS2 bag is a command line tool for recording data published on topics in your system. It accumulates the data passed on any number of topics and saves it in a database. You can then replay the data to reproduce the results of your tests and experiments.

**Use Cases:**
- Recording topics is a great way to share your work and allow others to recreate it
- Recording data during live experiment or recording data on test site (e.g. warehouse, outdoor, non-lab environment)
- The recorded bag file can be replayed in lab environment for further analysis, project development or simulation purpose

### ROS Bag Commands

ROS bag provides three main commands:
1. **record** - Record data from topics
2. **play** - Playback recorded topics
3. **info** - Get information about a bag file

### Video Reference
[ROS Bag Tutorial](https://www.youtube.com/watch?v=pwlbArh_neU)

---

## ROS Bag with Turtlesim

### Starting Turtlesim

To start turtlesim, enter the following command in your terminal:
```bash
$ ros2 run turtlesim turtlesim_node
```

Open a 2nd terminal and run the following to enable keyboard control:
```bash
$ ros2 run turtlesim turtle_teleop_key
```

Open a 3rd terminal and run the following to make a new directory for bag files:
```bash
$ mkdir youradmin_bag_files
$ cd youradmin_bag_files
```

### Viewing Topics

rosbag can only record data from topics that are published on. To see a list of your system's topics, open a new terminal and run the command:
```bash
~/youradmin_bag_files$ ros2 topic list
```

**Expected Output:**
```
/parameter_events
/rosout
/turtle1/cmd_vel
/turtle1/color_sensor
/turtle1/pose
```

### Question 1
Can you identify which node and topic is responsible to make the turtle move in turtlesim?

**Node:** turtle_teleop_key
**Topic:** /turtle1/cmd_vel

### Viewing Topic Data

To see the data that `/turtle1/cmd_vel` is publishing, run the command:
```bash
~/youradmin_bag_files$ ros2 topic echo /turtle1/cmd_vel
```

Nothing will show up at first because no data is being published by the teleop. Return to the terminal where you ran the teleop and select it so it's active. Use the arrow keys to move the turtle around, and you will see data being published on the terminal running `ros2 topic echo`.

**Sample Output:**
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

Observe the changes in the x and z values as you move the turtle using the arrow keys.

---

## Recording ROS Bag Files

### Recording Topics

To record data from topics, use the `ros2 bag record` command:

```bash
# Record specific topics
ros2 bag record -o bagfile1 /turtle1/cmd_vel /turtle1/pose
```

### Recording Example

While the turtlesim is running and you're controlling it with the keyboard, record the data:

```bash
~/youradmin_bag_files$ ros2 bag record -o bagfile1 /turtle1/cmd_vel /turtle1/pose
```

You will see messages indicating the database opened and topics subscribed. Return to the teleop terminal and control the robot to draw a square. After drawing, press `Ctrl+C` to stop recording.

**Expected Output:**
```
[INFO] [rosbag2_storage]: Opened database 'rosbag2_2022_02_23-23_43_43/rosbag2_2022_02_23-23_43_43_0.db3' for READ_WRITE.
[INFO] [rosbag2_transport]: Listening for topics...
[INFO] [rosbag2_transport]: Subscribed to topic '/turtle1/cmd_vel'
[INFO] [rosbag2_transport]: All requested topics are subscribed. Stopping discovery...
```

Use `ls` to list the files in the directory. You should see `bagfile1.bag` created.

---

## Playing Back ROS Bag Files

### Playback Commands

To replay recorded bag files:

```bash
# Play a bag file in a loop
ros2 bag play -l bagfile1
```

### Playback Example

Stop the turtlesim and teleop nodes. Then play back the recorded data:

```bash
~/youradmin_bag_files$ ros2 bag play -l bagfile1
```

You should see the turtle move exactly as it did during recording, drawing the previous square without using the keyboard.

---

## Getting Bag File Information

### Info Command

To get information about a bag file:

```bash
ros2 bag info bagfile1
```

**Expected Output:**
```
sqlite3
Duration: 16.943s
Files: bagfile1_0.db3
Bag size: 117.3 KiB
Start: Feb 24 2022 00:12:13.583 (1645690333.583)
End: Feb 24 2022 00:12:30.527 (1645690350.527)
Messages: 1069

Topic information:
Topic: /turtle1/pose | Type: turtlesim/msg/Pose | Count: 1060 | Serialization Format: cdr
Topic: /turtle1/cmd_vel | Type: geometry_msgs/msg/Twist | Count: 9 | Serialization Format: cdr
```

**Note:** The `/turtle1/cmd_vel` topic's Count is only 9 (how many times arrow keys were pressed), while `/turtle1/pose` has a Count of over 1060 (data published continuously during recording).

---

## Question 2

**Task:**
Close all terminals. Modify the command such that it only records the cmd_vel and save it to bagfile2.

**Steps:**
1. Using the turtle_teleop_key to draw a square in turtlesim
2. Terminate the turtle_teleop_key process
3. Close the turtlesim and replay the bagfile2 in a loop
4. Observe if the turtlesim can draw back the same square you previously drawn
5. Run `rqt_graph`, ensure you refresh the nodes/topics (active) to view the graph showing rosbag -> /turtle1/cmd_vel -> /turtlesim
6. Echo the topic `/turtle1/pose` (i.e., `ros2 topic echo /turtle1/pose`)
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
```