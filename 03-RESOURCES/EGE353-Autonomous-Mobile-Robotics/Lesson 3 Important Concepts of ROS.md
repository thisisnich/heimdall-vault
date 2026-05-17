---
tags:
  - EGE353
  - lesson3
  - ROS
  - concepts
  - lesson-3
  - robotics-concepts
course: EGE353 Autonomous Mobile Robotics
topic: Lesson 3 - Important Concepts of ROS
source: Lesson 3 Important Concepts of ROS.pdf
converted: 2026-05-07
type: Lesson
status: Completed
source: NYPY3 Import
---

> 📚 **Related:** [[NYPY3 - Main Index|NYPY3 Index]] | [[03-RESOURCES/EGE353-Autonomous-Mobile-Robotics/Lesson 2 Robot Operating System ROS.md|Lesson 2]] | [[📅 Schedule & Assessments Dashboard|Assessment Dashboard]]

> 📚 **Related:** [[NYPY3 - Main Index|NYPY3 Index]] | [[03-RESOURCES/EGE353-Autonomous-Mobile-Robotics/Lesson 2 Robot Operating System ROS.md|Lesson 2]] | [[📅 Schedule & Assessments Dashboard|Assessment Dashboard]]


# EGE353

Autonomous Mobile
Robotics
Service mobile robots, concepts of path planning, navigation,
obstacle avoidance, simultaneous localisation and mapping.
Lesson 3:  Important Concepts of ROS
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
ROS Message
Nodes  communicate  with  each  other  by  publishing  messages  to  topics.  A  message  is  a  simple  data  structure,
comprising  typed  fields.  Standard  primitive  types  (integer,  floating  point,  boolean,  etc.)  are  supported,  as  are
arrays of primitive types. Basically, a message is data through a channel called topic. In the following figure, the
message is String type and the topic is called /example.
ROS nodes
A node refers to the smallest unit of processor running in
ROS. Think of it as one executable program.
ROS  recommends  creating  one  single  node  for  each
purpose,  and  it  is  recommended  to  develop  for  easy
reusability.  For  example,  in  case  of  mobile  robots,  the
into
program  to  operate  the  robot
specialized functions.
is  broken  down
Specialized  node  is  used  for  each  function  such  as  sensor
drive, sensor data conversion, obstacle recognition, motor
drive, encoder input, and
navigation.
ROS  2  breaks  complex  systems  down  into  many  modular
nodes. Topics are a vital element of the ROS graph that act
as a bus for nodes to exchange messages.
Compute unit
ROS Topic
Communication on topic uses the same type of message for both
publisher and subscriber. The subscriber node receives the
information of publisher node corresponding to the identical topic
name registered in the master. Based on this information, the
subscriber node directly connects to the publisher node to receive
messages.
As topics are unidirectional and remain connected to continuously
send or receive messages.
It is suitable for sensor data that requires publishing messages
periodically. In addition, multiple subscribers can receive message
from a publisher and vice versa. Multiple publishers and subscribers
connections are available as well.
Distance in
meter
ROS Topic
- 3. Motor control
- 1. IR sensor
Compute unit
- 2. Compute unit
ROS Topic
Examples
ROS Publisher
The term ‘publish’ stands for the action of transmitting relative messages corresponding to the
topic. The publisher node registers its own information and topic with the master, and sends a
message to connected subscriber nodes that are interested in the same topic. The publisher is
declared in the node and can be declared multiple times in one node.
ROS Subscriber
The term ‘subscribe’ stands for the action of receiving relative messages corresponding to the topic. The subscriber node
registers its own information and topic with the master, and receives publisher information that publishes relative topic
from the master. Based on received publisher information, the subscriber node directly requests connection to the
publisher node and receives messages from the connected publisher node. A subscriber is declared in the node and
can be declared multiple times in one node.
ROS Service
Communication on service is a bidirectional synchronous communication between the service client requesting a service
and the service server responding to the request as shown. The aforementioned ‘publish’ and ‘subscribe’ of the topic is
an asynchronous method which is advantageous on periodical data transmission. On the other hands, there is a need for
synchronous communication which uses request and response. Accordingly, ROS provides a synchronized message
communication method called ‘service’.
ROS Service
A service consists of a service server that responds only when there is a request and a service client that can send
requests as well as receiving responses. Unlike the topic, the service is one time message communication. Therefore,
when the request and response of the service are completed, the connection between two nodes will be disconnected.
A service is often used to command a robot to perform a specific action or nodes to perform certain events with a
specific condition. Service does not maintain the connection, so it is useful to reduce the load of the network by
replacing topic. For example, if the client requests the server for the current time as shown in the Figure, the server will
check the time and respond to the client, and the connection is terminated. The service is synchronous bidirectional
communication between the service client that requests a service regarding a particular task and the service server that
is responsible for responding to requests.
ROS Service
ROS Service
ROS Actions
ROS Actions
Communication on action is used when a requested goal takes a long time to be completed, therefore
progress feedback is necessary. This is very similar to the service where ‘goals’ and ‘results’ correspond
to ‘requests’ and ‘responses’ respectively. In addition, the ‘feedback’ is added to report feedbacks to the
client periodically when intermediate values are needed.
The message transmission method is the same as the asynchronous topic. The feedback transmits an
asynchronous bidirectional message between the action client which sets the goal of the action and an
action server that performs the action and sends the feedback to the action client. For example, as shown
in Figure, if the client sets home-cleaning tasks as a goal to the server, the server informs the user of the
progress of the dishwashing, laundry, cleaning, etc. in the form of feedback, and finally sends the final
message to the client as a result. Unlike the service, the action is often used to command complex robot
tasks such as cancelling transmitted goal while the operation is in progress
ROS Actions
ROS Service vs Actions
What’s the difference between a Service and an Action?
Services are Synchronous. When your ROS program calls a
service, your program can’t continue until it receives a result
from the service.
Actions are Asynchronous. It’s like launching a new thread.
When your ROS program calls an action, your program can
perform other tasks while the action is being performed in
another thread.
Use services when your program can’t continue until it
receives the result from the service.
ROS Message
ROS topic, service and actions
ROS topic, service and actions
ROS Parameter
Parameters in ROS are associated with individual nodes.
Parameters are used to configure nodes at startup (and during
runtime), without changing the code. The lifetime of a
parameter is tied to the lifetime of the node (though the node
could implement some sort of persistence to reload values
after restart).
Parameters are addressed by node name, node namespace,
parameter name, and parameter namespace. Providing a
parameter namespace is optional.
Each parameter consists of a key, a value, and a descriptor. The
key is a string and the value is one of the following types: bool,
int64, float64, string, byte[], bool[], int64[], float64[] or string[].
By default all descriptors are empty, but can contain parameter
descriptions, value ranges, type information, and additional
constraints.
ROS Parameter
ROS Parameter
Message communication is largely divided into topics, services, and actions. Parameters are global variables
used in nodes and in the larger context, they can also be considered as a message communication. In Windows
programs *.ini file is used to save configurations just as parameters in ROS. The configuration are set with
default values and can be read or written externally if necessary. Especially, the configured values can be
modified in real-time from the outside by using the write function. It is very useful to flexibly cope with
changing environment. Although parameters are not strictly a message communication method, they belong
to the scope of message communication in that they use messages. For example, you can change parameters
to set the USB port to connect to, get the camera color correction value, and configure the maximum and
minimum values of the speed and commands.
ROS Package
Software in ROS is organized in packages. A package might contain ROS nodes, a ROS-independent library, a
dataset, configuration files, a third-party piece of software, or anything else that logically constitutes a useful
module. The goal of these packages it to provide this useful functionality in an easy-to-consume manner so
that software can be easily reused. In general, ROS packages follow a "Goldilocks" principle: enough
functionality to be useful, but not too much that the package is heavyweight and difficult to use from other
software.
Packages are easy to create by hand or with tools like catkin_create_pkg. A ROS package is simply a directory
descended from ROS_PACKAGE_PATH (see ROS Environment Variables) that has a package.xml file in it.
Packages are the most atomic unit of build and the unit of release. This means that a package is the smallest
individual thing you can build in ROS and it is the way software is bundled for release (meaning, for example,
there is one debian package for each ROS package), respectively.
ROS Package
ROS packages tend to follow a common structure. Here are some of the directories and files you may notice.
●
include/package_name: C++ include headers (make sure to export in the CMakeLists.txt)
● msg/: Folder containing Message (msg) types
●
●
●
src/package_name/: Source files, especially Python source that are exported to other packages.
srv/: Folder containing Service (srv) types
scripts/: executable scripts
● CMakeLists.txt: CMake build file (see catkin/CMakeLists.txt)
● package.xml: Package catkin/package.xml
● CHANGELOG.rst: Many packages will define a changelog which can be automatically injected into binary
packaging and into the wiki page for the package
ROS Package
ROS Package
ROS Package
A package is the basic unit of ROS. The ROS application is developed on a package basis, and the
package contains either a configuration file to launch other packages or nodes. The package also
contains all the files necessary for running the package, including ROS dependency libraries for
running various processes, datasets, and configuration file.
The number of official packages is about 2,500 for ROS Indigo as of July 2017
(http://repositories.ros.org/status_page/ ros_indigo_default.html) and about 1,600 packages for ROS Kinetic
(http://repositories.ros.org/status_page/ros_kinetic_default.html). In addition, although there could be some
redundancies, there are about 4,600 packages developed and released by users
(http://rosindex.github.io/stats/).
End of Lesson

---

