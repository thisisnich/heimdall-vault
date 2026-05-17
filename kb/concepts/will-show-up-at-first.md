---
id: "ca4f71f8-1470-4525-9d86-59cadc0599a3"
title: "Will Show Up At First"
type: vault_note
vault: wiki
created: 2026-05-17
updated: 2026-05-17
checksum: "sha256:f6d4ca1442fe423a"
source: heimdall/auto
---

# Will Show Up At First

- will show up at first because no data is being published by the teleop. Return to the terminal where you ran the teleop and select it so it's active. Use the arrow keys to move the turtle around, and you will see data being published on the terminal running `ros2 topic echo`.

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

Use `ls` to list the files in the directory. <!-- id:ca4f71f8-1470-4525-9d86-59cadc0599a3 ts:2026-05-17 07:49 -->
