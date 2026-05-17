---
id: "a3b3e42c-ad0b-4030-82c0-7495e56e1db9"
title: "Tle1Cmd Vel Info Rosbag2 Transport All Requested"
type: vault_note
vault: wiki
created: 2026-05-17
updated: 2026-05-17
checksum: "sha256:422c4accacfc3bad"
source: heimdall/auto
---

# Tle1Cmd Vel Info Rosbag2 Transport All Requested

- tle1/cmd_vel'
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
Close all terminals. <!-- id:a3b3e42c-ad0b-4030-82c0-7495e56e1db9 ts:2026-05-17 07:49 -->
