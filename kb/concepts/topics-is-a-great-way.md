---
id: "15169103-a1be-49a1-99e1-f55150bb13f7"
title: "Topics Is A Great Way"
type: vault_note
vault: wiki
created: 2026-05-17
updated: 2026-05-17
checksum: "sha256:fc2c472c2772853e"
source: heimdall/auto
---

# Topics Is A Great Way

- topics is a great way to share your work and allow others to recreate it
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

rosbag can only record data from topics that are published on. <!-- id:15169103-a1be-49a1-99e1-f55150bb13f7 ts:2026-05-17 07:49 -->
