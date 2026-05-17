---
id: "92a960aa-5dfe-4efe-8c27-23714ca2d098"
title: "Ts 18 Done Remote Counting"
type: vault_note
vault: wiki
created: 2026-05-17
updated: 2026-05-17
checksum: "sha256:508b5eb9ed304604"
source: heimdall/auto
---

# Ts 18 Done Remote Counting

- ts: 18, done.
remote: Counting objects: 100% (18/18), done.
remote: Compressing objects: 100% (15/15), done.
remote: Total 18 (delta 4), reused 9 (delta 1), pack-reused 0
Unpacking objects: 100% (18/18), 18.33 KiB | 3.67 MiB/s, done.

Nodes in ROS2

Start a new terminal and make a new directory call lab1b_ws.

user:~/lab1b_ws/src$ ls
teleop_cpp_ros2
user:~/lab1b_ws/src$ cd ..
user:~/lab1b_ws$ colcon build --packages-select teleop_cpp_ros2
Starting >>> teleop_cpp_ros2
Finished <<< teleop_cpp_ros2 [6.05s]

Summary: 1 package finished [6.17s]
user:~/lab1b_ws$ ls
build  install  log  src
user:~/lab1b_ws$ source install/setup.bash

Nodes in ROS2

user:~/lab1b_ws$ ros2 run teleop_cpp_ros2 teleop

Reading from the keyboard and Publishing to Twist!
---------------------------
Moving around:
   u    i    o
   j    k    l
   m    ,    .
For Holonomic mode (strafing), hold down the shift key:
---------------------------
   U    I    O
   J    K    L
   M    <    >
---------------------------

Now top Speed is 0.500000 and turn is 1.000000 | Last command:

Nodes in ROS2

Open a new shell window

Shell 2 - Terminal 1

Shell 2 - Terminal 5

Shell 1 - Terminal 1(teleop)

Nodes in ROS2

On shell 2 open a 1st terminal window and run turtlesim

$ ros2 run turtlesim turtlesim_node

On shell 2 open a 2nd terminal window and run topic list

$ ros2 topic list

Observe the that there are two cmd_vel topics
On shell 2 open a 3rd terminal and run topic echo

$ ros2 topic echo /cmd_vel

On shell 2 <!-- id:92a960aa-5dfe-4efe-8c27-23714ca2d098 ts:2026-05-17 07:49 -->
- ts: 18, done.
remote: Counting objects: 100% (18/18), done.
remote: Compressing objects: 100% (15/15), done.
remote: Total 18 (delta 4), reused 9 (delta 1), pack-reused 0
Unpacking objects: 100% (18/18), 18.33 KiB | 3.67 MiB/s, done.

Nodes in ROS2

Start a new terminal and make a new directory call lab1b_ws.

user:~/lab1b_ws/src$ ls
teleop_cpp_ros2
user:~/lab1b_ws/src$ cd ..
user:~/lab1b_ws$ colcon build --packages-select teleop_cpp_ros2
Starting >>> teleop_cpp_ros2
Finished <<< teleop_cpp_ros2 [6.05s]

Summary: 1 package finished [6.17s]
user:~/lab1b_ws$ ls
build  install  log  src
user:~/lab1b_ws$ source install/setup.bash

Nodes in ROS2

user:~/lab1b_ws$ ros2 run teleop_cpp_ros2 teleop

Reading from the keyboard and Publishing to Twist!
---------------------------
Moving around:
   u    i    o
   j    k    l
   m    ,    .
For Holonomic mode (strafing), hold down the shift key:
---------------------------
   U    I    O
   J    K    L
   M    <    >
---------------------------

Now top Speed is 0.500000 and turn is 1.000000 | Last command:

Nodes in ROS2

Open a new shell window

Shell 2 - Terminal 1

Shell 2 - Terminal 5

Shell 1 - Terminal 1(teleop)

Nodes in ROS2

On shell 2 open a 1st terminal window and run turtlesim

$ ros2 run turtlesim turtlesim_node

On shell 2 open a 2nd terminal window and run topic list

$ ros2 topic list

Observe the that there are two cmd_vel topics
On shell 2 open a 3rd terminal and run topic echo

$ ros2 topic echo /cmd_vel

On shell 2 <!-- id:92a960aa-5dfe-4efe-8c27-23714ca2d098 ts:2026-05-17 07:49 -->
