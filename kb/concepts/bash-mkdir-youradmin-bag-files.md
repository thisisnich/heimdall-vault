---
id: "73375744-e235-4e72-98ec-ab8d4b9dbdeb"
title: "Bash Mkdir Youradmin Bag Files"
type: vault_note
vault: wiki
created: 2026-05-17
updated: 2026-05-17
checksum: "sha256:def76f48147a770c"
source: heimdall/auto
---

# Bash Mkdir Youradmin Bag Files

- :
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

Nothing will show up at first because no data is being published by the teleop. Return to the terminal where you ran the teleop and select it so it's active. <!-- id:73375744-e235-4e72-98ec-ab8d4b9dbdeb ts:2026-05-17 07:49 -->
