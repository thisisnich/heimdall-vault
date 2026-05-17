---
tags:
  - EGE353
  - lesson2
  - ROS
  - robot-operating-system
course: EGE353 Autonomous Mobile Robotics
topic: Lesson 2 - Robot Operating System (ROS)
source: Lesson 2 Robot Operating System ROS.pdf
converted: 2026-05-07
---


# EGE353

Autonomous Mobile Robotics
Service mobile robots, concepts of path planning, navigation,
obstacle avoidance, simultaneous localisation and mapping.
Lesson 2:  Robot Operating System
Chan Kit Wai
Tel: 65500559
Chan_kit_wai@nyp.edu.sg
Synopsis
This  module  aims  to  equip  learners  with  the  knowledge  of  service  robots  and  their  applications.  Learners  will  also
study the concepts of path planning, navigation, obstacle avoidance, simultaneous localisation and mapping. They will
be able to implement mobile robotics system to carry out tasks autonomously.
Module Learning Outcomes
At the end of the module, learners are able to:
•Explain the features of different sensors and actuators used in autonomous mobile robotics.
•Perform the analysis of laser and vision sensor data using visualization tools.
•Implement mobile robotics system using methods such as mapping, localization, path planning, obstacle avoidance
and motion control.
Introduction to ROS
ROS is an open-source, meta-operating system for your
robot. It provides the services you would expect from an
operating system, including hardware abstraction,
low-level device control, implementation of
commonly-used functionality, message-passing between
processes, and package management. It also provides
tools and libraries for obtaining, building, writing, and
running code across multiple computers.
Source: https://www.ros.org
Introduction to ROS
ROS is an open-source, meta-operating system for
your robot. It provides the services you would
expect from an operating system, including
hardware abstraction, low-level device control,
implementation of commonly-used functionality,
message-passing between processes, and
package management.
It also provides tools and libraries for obtaining,
building, writing, and running code across multiple
computers.
Source: https://www.ros.org
Introduction to ROS
Operating System
General purpose computer
Windows(Windows XP, 7, 8 ...)
Linux(Ubuntu, Redhat, Fedora, Mint, Gentoo ...)
MAC(OS X ...) etc
Smart phone
Android, iOS, Windows Phone, Symbian,
ROS= Robot Operating System
ROS is Meta-Operating System
What is a Meta-OS ?
Introduction to ROS
Source: https://www.ros.org
Introduction to ROS
Source: https://www.wiki,ubuntu.com/Releases
Source: https://www.ros.org
Meta-Operating System
• Meta-Operating System (Meta-Operating System): It is not a precisely defined
term but it can be regarded as a system that performs scheduling, loading, monitoring,
error handling and utilizing distributed computing resources as a virtualization layer
between applications and distributed computing resources.
It is not a traditional operating system like Windows, Linux, and Android. Rather,
•
ROS uses the traditional operating system (Linux, Windows, OS-X, and Android).
It uses the existing operating system's process management system, file system,
•
user interface, program utilities (compiler, thread model, etc.). In addition, it provides
essential functions for developing robot application software such as data transmission
/ reception, scheduling and error handling among many different types of hardware in a
library form.
In addition, it develops, manages and provides various application programs based
•
on the robot software framework, and has an ecosystem that distributes packages
developed by users.
Meta-Operating System
Communication between devices
ROS-enabled Operating System
• Ubuntu, OS X, Windows, Fedora, Gentoo, OpenSUSE, Debian, Raspbian, Arch, and
QNX Realtime OS. (There can be functional limitations in some OS)
• Partially available for Android and iOS, smartphone operating systems
•
In case of microcontroller unit (MCU) which can not be equipped with OS, it provides
a library to communicate via serial communication, Bluetooth, and LAN
• Basically it is recommended to run on Ubuntu
ROS Configuration
ROS Configuration
Android, webpage, desktop app
Communication infrastructure

# ROS

Master
node
node

# IR

sensor
Decision
node
Control
Motor
Publish
Subscribe
Publish
Subscribe
Topic name
Ultrasensor
sensor data
Topic name
Left and right
motor speed
Communication infrastructure
Message parsing function
• Provides communication system frequently used in robot development
• Message transfer interface between nodes facilitating encapsulation and code reuse
Message Record and Play
• Messages that are transmitted/received between nodes can be stored and reused as needed
•
It is possible to repeat an experiment based on stored messages, and it is easy to develop algorithm
Use of various programming languages due to the use of messages
• Since data exchange between nodes use messages, each node can be written in different languages
• Client libraries: roscpp, rospy, roslisp, rosjava, roslua, roscs, roseus, PhaROS, rosR
Distributed parameter system
• Variables used in the system are created as global key values so they can be shared, modified and
applied in real-time
ROS functions
Define a standard message for a robot
• Modularization by defining standard message such as camera, IMU, laser sensor / odometry, navigation
data such as route and map, inducing collaborative work, and improving efficiency
Robot geometry library
• Provides TF to calculate the relative coordinates of robot, sensor, etc.
Robot description language
• XML document describing physical characteristics of the robot
ROS functions
•
Exploring ROS using a 2 Wheeled Robot #1: Basics of Robot Modeling using URDF
https://www.theconstructsim.com/exploring-ros-2-wheeled-robot-part-01/
ROS functions
Sensing / recognition
• Sensor drivers, libraries for sensing / recognition
ROS functions
Navigation
• Estimation of poses (position / posture)
of robots commonly used in robots,
provision of self position estimation in
the map
• SLAM required for map creation, and
Navigation library for navigating to
destinations within the created map
ROS Development tools
RViz
• Provide powerful 3D visualization tool
• Visualize sensor data such as laser, camera, etc.
• Represent robot outline and planned motion
https://www.youtube.com/watch?v=7iM2ynZEuf0
ROS Development tools
Mapping using RViz
https://www.youtube.com/watch?v=7iM2ynZEuf0
ROS Development tools
Gazebo
• 3D simulator with physics engine. Supports robot,
sensor, environmental models
• Highly Compatible with ROS
ROS Development tools
Gazebo
ROS Development tools
Gazebo
https://www.youtube.com/watch?v=dtm5X6VUbQc
ROS Development tools

# RQT

• Provides Qt-based framework for developing graphic
interface
• Displays connection information among nodes (rqt_graph)
• Values such as encoder, voltage, numbers that change
over time (rqt_plot)
• Records and plays data in the form of message (rqt_bag)
ROS Development tools
RQT_graph
ROS Development tools
RQT_plot
ROS Development tools
RQT_plot
End of Lesson

---

