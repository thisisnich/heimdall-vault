---
tags:
  - EGE353
  - lab
  - ROS2
  - nodes
  - topics
course: EGE353 Autonomous Robotics
topic: Lab 2 - ROS2 Nodes and Topics
source: Lab2 Ros nodes and Topics.pdf
converted: 2026-04-28
---

> **Related:** [[EGE353 Lab 1 Notes|Lab 1]] | [[EGE353 Lab 3 - ROS Services|Lab 3]] | [[EGE353 Lab 4 - ROS Bag Files and Gazebo|Lab 4]]

# Lab 2: ROS2 Nodes and Topics

Chan Kit Wai
Tel: 65500559
Chan_kit_wai@nyp.edu.sg

Synopsis

This  module  aims  to  equip  learners  with  the  knowledge  of  service  robots  and  their  applications.  Learners  will  also
study the concepts of path planning, navigation, obstacle avoidance, simultaneous localisation and mapping. They will
be able to implement mobile robotics system to carry out tasks autonomously.

Module Learning Outcomes

At the end of the module, learners are able to:

∙Explain the features of different sensors and actuators used in autonomous mobile robotics.

∙Perform the analysis of laser and vision sensor data using visualization tools.

∙Implement mobile robotics system using methods such as mapping, localization, path planning, obstacle avoidance
and motion control.

Nodes in ROS2

Start a new terminal and make a new directory call lab1b_ws.

user:~$ mkdir lab1b_ws
user:~$ ls
ai_ws      lab1b_ws     ros2_ws        webpage_ws
catkin_ws  notebook_ws  simulation_ws
user:~$ cd lab1b_ws
user:~/lab1b_ws$ mkdir src
user:~/lab1b_ws$ cd src
user:~/lab1b_ws/src$ git clone https://github.com/1at7/teleop_cpp_ros2.git
Cloning into 'teleop_cpp_ros2'...
remote: Enumerating objects: 18, done.
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

**A:** `git clone` creates a copy of a remote repository (from GitHub or other git hosting service) to your local machine. It downloads all the files, version history, and repository metadata, allowing you to work with the code locally.

Q2) Explain what is the operation of colcon build --packages-select teleop_cpp_ros2

**A:** `colcon build` is the ROS2 build tool (similar to catkin in ROS1). The `--packages-select teleop_cpp_ros2` flag tells colcon to **only build the specified package** rather than all packages in the workspace. This saves time when you only need to compile one package.

Q3) What is the frequency of the published topic /cmd_vel ?

**A:** The `/cmd_vel` topic in this teleop package is published **event-based** (not at a fixed frequency). A message is published **only when a key is pressed**. The frequency depends on how fast you press keys — it could be anywhere from 0 Hz (no keys pressed) to potentially 10-20 Hz if keys are pressed rapidly.

Q4) Explain what is the function for the command ros2 topic list

**A:** `ros2 topic list` displays **all active topics** currently being published or subscribed to in the ROS2 system. It shows the topic names that are part of the current ROS graph.

Q5) Explain what is the function for the command ros2 topic echo /turtle1/cmd_vel

**A:** `ros2 topic echo /turtle1/cmd_vel` displays **all messages being published** to the `/turtle1/cmd_vel` topic in real-time. It shows the message content (typically linear and angular velocity values) as they are published, useful for debugging and understanding what data is being sent.

Q6) Write down the line of code in teleop_cpp_ros2.cpp that publish the topic /turtle1/cmd_vel

**A:** The publisher is typically created with:
```cpp
publisher_ = this->create_publisher<geometry_msgs::msg::Twist>("cmd_vel", 10);
```

And the publish call would be:
```cpp
publisher_->publish(msg);
```

*Note: The exact line depends on the specific version of the teleop_cpp_ros2 package. The topic name may need to be changed to `/turtle1/cmd_vel` in the code or remapped at runtime.*

Q7) Where is the x, y and z direction of the on the turtlebot ?

**A:** In ROS2 turtlebot/turtlesim coordinate system:
- **X-axis**: Forward/backward motion (linear velocity in x direction)
- **Y-axis**: Left/right strafing motion (linear velocity in y direction) — only for holonomic robots
- **Z-axis**: Rotation/yaw (angular velocity around z-axis)

For non-holonomic robots like the standard turtlebot:
- **linear.x** controls forward/backward speed
- **angular.z** controls rotation (turning left/right)
- **linear.y** is typically unused (set to 0)

End of briefing for Lab session

---

## Command List (Copy-Paste Ready)

```bash
# ===== SETUP WORKSPACE =====
mkdir lab1b_ws                      # Create workspace directory for this lab
ls                                  # List current directory contents to verify
cd lab1b_ws                         # Change into the workspace directory
mkdir src                           # Create source folder for ROS packages
cd src                              # Change into source folder
git clone https://github.com/1at7/teleop_cpp_ros2.git   # Clone teleop package from GitHub
ls                                  # List cloned package to verify
cd ..                               # Go back to workspace root
colcon build --packages-select teleop_cpp_ros2           # Build only the teleop package
ls                                  # List workspace contents (build/, install/, log/, src/)
source install/setup.bash             # Source the setup script to add package to ROS environment

# ===== RUN TELEOP (Terminal 1) =====
ros2 run teleop_cpp_ros2 teleop      # Launch keyboard teleop node to control robot

# ===== NEW TERMINALS (Shell 2) - Open 4 separate terminals =====
# Terminal 1:
ros2 run turtlesim turtlesim_node    # Launch turtlesim simulator node

# Terminal 2:
ros2 topic list                      # List all active topics in the ROS graph

# Terminal 3:
ros2 topic echo /cmd_vel             # Display all messages published to /cmd_vel topic

# Terminal 4:
rqt_graph                            # Open visual tool to see node/topic connections

# ===== REMAPPED TELEOP (After Ctrl+C to kill first teleop) =====
source install/setup.bash             # Re-source environment in new terminal
ros2 run teleop_cpp_ros2 teleop --ros args --remap /cmd_vel:=/turtle1/cmd_vel   # Launch teleop with topic remapping so it publishes to /turtle1/cmd_vel instead of /cmd_vel
```
