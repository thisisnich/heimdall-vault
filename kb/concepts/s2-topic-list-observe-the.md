---
id: "9f310e4f-f4aa-47ed-9654-1fc132af3f06"
title: "S2 Topic List Observe The"
type: vault_note
vault: wiki
created: 2026-05-17
updated: 2026-05-17
checksum: "sha256:c409a3b05a03f321"
source: heimdall/auto
---

# S2 Topic List Observe The

- s2 topic list

Observe the that there are two cmd_vel topics
On shell 2 open a 3rd terminal and run topic echo

$ ros2 topic echo /cmd_vel

On shell 2 open a 4th terminal and run  rqt_graph to observe that the nodes are not linked
together by a topic.

$ rqt_graph

Nodes in ROS2

/turtle1/cmd_vel

/teleop

/turtlesim

/cmd_vel

Nodes in ROS2

/turtle1/cmd_vel

/teleop

/turtlesim

/cmd_vel

Nodes in ROS2

Terminate the previous teleop program by Ctr+C and rerun it with –remap options as –remap from_OldTopic:=to_NewTopic
Rerun topic list again to observe
Using the arrow keys, try to control the turtlebot

user:~/lab1b_ws$ source install/setup.bash
user:~/lab1b_ws$ ros2 run teleop_cpp_ros2 teleop –ros args –remap /cmd_vel:=/turtle1/cmd_vel

Nodes in ROS2

Explore all commands to control the turtlesim.

Nodes in ROS2

Constant linear and angular velocity

Constant linear and angular velocity for holonomic robots

z

x

y

Nodes in ROS2

Constant linear and angular velocity for holonomic robots

Nodes in ROS2

For explanation only. Not necessary to test it.

Instead of remapping the topic, you can change the topic name in the code editor as shown. This can be helpful
in your future lab sessions.

Nodes in ROS2

Try to answer the following questions.

Q1) Explain what is the operation of git clone.

**A:** `git clone` creates a copy of a remote repository (from GitHub or other git hosting service) to your local machine. <!-- id:9f310e4f-f4aa-47ed-9654-1fc132af3f06 ts:2026-05-17 07:49 -->
- s2 topic list

Observe the that there are two cmd_vel topics
On shell 2 open a 3rd terminal and run topic echo

$ ros2 topic echo /cmd_vel

On shell 2 open a 4th terminal and run  rqt_graph to observe that the nodes are not linked
together by a topic.

$ rqt_graph

Nodes in ROS2

/turtle1/cmd_vel

/teleop

/turtlesim

/cmd_vel

Nodes in ROS2

/turtle1/cmd_vel

/teleop

/turtlesim

/cmd_vel

Nodes in ROS2

Terminate the previous teleop program by Ctr+C and rerun it with –remap options as –remap from_OldTopic:=to_NewTopic
Rerun topic list again to observe
Using the arrow keys, try to control the turtlebot

user:~/lab1b_ws$ source install/setup.bash
user:~/lab1b_ws$ ros2 run teleop_cpp_ros2 teleop –ros args –remap /cmd_vel:=/turtle1/cmd_vel

Nodes in ROS2

Explore all commands to control the turtlesim.

Nodes in ROS2

Constant linear and angular velocity

Constant linear and angular velocity for holonomic robots

z

x

y

Nodes in ROS2

Constant linear and angular velocity for holonomic robots

Nodes in ROS2

For explanation only. Not necessary to test it.

Instead of remapping the topic, you can change the topic name in the code editor as shown. This can be helpful
in your future lab sessions.

Nodes in ROS2

Try to answer the following questions.

Q1) Explain what is the operation of git clone.

**A:** `git clone` creates a copy of a remote repository (from GitHub or other git hosting service) to your local machine. <!-- id:9f310e4f-f4aa-47ed-9654-1fc132af3f06 ts:2026-05-17 07:49 -->
