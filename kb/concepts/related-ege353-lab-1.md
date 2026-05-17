---
id: "2aaa14aa-f2e8-4d28-8408-62c9ef09877b"
title: "Related Ege353 Lab 1"
type: vault_note
vault: wiki
created: 2026-05-17
updated: 2026-05-17
checksum: "sha256:dcb7045e7c6de047"
source: heimdall/auto
---

# Related Ege353 Lab 1

- > **Related:** [[EGE353 Lab 1 Notes|Lab 1]] | [[EGE353 Lab 2 - ROS Nodes and Topics|Lab 2]] | [[EGE353 Lab 4 - ROS Bag Files and Gazebo|Lab 4]]

# Lab 3: ROS2 Services and Parameters

**Instructor:** Chan Kit Wai  
**Tel:** 65500559  
**Email:** Chan_kit_wai@nyp.edu.sg

### Synopsis

This  module  aims  to  equip  learners  with  the  knowledge  of  service  robots  and  their  applications.  Learners  will  also
study the concepts of path planning, navigation, obstacle avoidance, simultaneous localisation and mapping. They will
be able to implement mobile robotics system to carry out tasks autonomously.

### Module Learning Outcomes

At the end of the module, learners are able to:

- Explain the features of different sensors and actuators used in autonomous mobile robotics.
- Perform the analysis of laser and vision sensor data using visualization tools.
- Implement mobile robotics system using methods such as mapping, localization, path planning, obstacle avoidance and motion control.

## ROS Services

Services are another method of communication for nodes in the ROS graph. Services are based on a call-and-response model, versus topics' publisher-subscriber model. While topics allow nodes to subscribe to data streams and get continual updates, services only provide data when they are specifically called by a client. Nodes can communicate using services in ROS 2. <!-- id:2aaa14aa-f2e8-4d28-8408-62c9ef09877b ts:2026-05-17 07:49 -->
- > **Related:** [[EGE353 Lab 1 Notes|Lab 1]] | [[EGE353 Lab 2 - ROS Nodes and Topics|Lab 2]] | [[EGE353 Lab 4 - ROS Bag Files and Gazebo|Lab 4]]

# Lab 3: ROS2 Services and Parameters

**Instructor:** Chan Kit Wai  
**Tel:** 65500559  
**Email:** Chan_kit_wai@nyp.edu.sg

### Synopsis

This  module  aims  to  equip  learners  with  the  knowledge  of  service  robots  and  their  applications.  Learners  will  also
study the concepts of path planning, navigation, obstacle avoidance, simultaneous localisation and mapping. They will
be able to implement mobile robotics system to carry out tasks autonomously.

### Module Learning Outcomes

At the end of the module, learners are able to:

- Explain the features of different sensors and actuators used in autonomous mobile robotics.
- Perform the analysis of laser and vision sensor data using visualization tools.
- Implement mobile robotics system using methods such as mapping, localization, path planning, obstacle avoidance and motion control.

## ROS Services

Services are another method of communication for nodes in the ROS graph. Services are based on a call-and-response model, versus topics' publisher-subscriber model. While topics allow nodes to subscribe to data streams and get continual updates, services only provide data when they are specifically called by a client. Nodes can communicate using services in ROS 2. <!-- id:2aaa14aa-f2e8-4d28-8408-62c9ef09877b ts:2026-05-17 07:49 -->
- > **Related:** [[EGE353 Lab 1 Notes|Lab 1]] | [[EGE353 Lab 3 - ROS Services|Lab 3]] | [[EGE353 Lab 4 - ROS Bag Files and Gazebo|Lab 4]]

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
remote: Total 18 (delta 4), reused 9 (del <!-- id:8a71c9db-a177-48ee-86d6-976ded69bdeb ts:2026-05-17 07:49 -->
- > **Related:** [[EGE353 Lab 1 Notes|Lab 1]] | [[EGE353 Lab 3 - ROS Services|Lab 3]] | [[EGE353 Lab 4 - ROS Bag Files and Gazebo|Lab 4]]

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
remote: Total 18 (delta 4), reused 9 (del <!-- id:8a71c9db-a177-48ee-86d6-976ded69bdeb ts:2026-05-17 07:49 -->
