# Lab 1: Understanding ROS nodes and TurtleSim

**Author:** Chan Kit Wai  
**Tel:** 65500559  
**Email:** Chan_kit_wai@nyp.edu.sg

## Synopsis

This module aims to equip learners with the knowledge of service robots and their applications. Learners will also study the concepts of path planning, navigation, obstacle avoidance, simultaneous localisation and mapping. They will be able to implement mobile robotics system to carry out tasks autonomously.

## Module Learning Outcomes

At the end of the module, learners are able to:

- Explain the features of different sensors and actuators used in autonomous mobile robotics.
- Perform the analysis of laser and vision sensor data using visualization tools.
- Implement mobile robotics system using methods such as mapping, localization, path planning, obstacle avoidance and motion control.

## Web-based Simulator

**URL:** https://www.theconstruct.ai/  
**Signup:** https://app.theconstruct.ai/signup/

> Make sure you record your email and password somewhere

### Simulator Interface

- Click to open a new shell/terminal window
- Click to open code editor
- Multiple terminal windows available (shell 1, shell 5, etc.)

## Nodes in ROS2

### Starting Turtlesim

To start turtlesim, enter the following command in your terminal:

```bash
source /opt/ros/humble/setup.bash
ros2 run turtlesim turtlesim_node
```

The simulator window should appear, with a random turtle in the center. In the terminal under the command, you will see messages from the node. You can use Ctrl + mouse scroll to adjust the web browser zoom to 100%.

**Output:**
```
[INFO] [turtlesim]: Starting turtlesim with node name /turtlesim
[INFO] [turtlesim]: Spawning turtle [turtle1] at x=[5.544445], y=[5.544445], theta=[0.000000]
```

### Listing Nodes

Open a 2nd terminal while turtlesim is still running in the 1st terminal, and enter:

```bash
source /opt/ros/humble/setup.bash
ros2 node list
```

The terminal will return the node name `/turtlesim` as there is only one node running.

### Turtle Teleoperation

Open a 3rd terminal while turtlesim is still running in the 1st terminal:

```bash
ros2 run turtlesim turtle_teleop_key
```

**Important:** Please ensure that you click on the 3rd terminal before pressing the arrow key.

**Output:**
```
Reading from keyboard
---------------------------
Use arrow keys to move the turtle.
Use G|B|V|C|D|E|R|T keys to rotate to absolute orientations. 'F' to cancel a rotation.
'Q' to quit.
```

### Node Names

- **Node 1:** `turtlesim_node` (from `ros2 run turtlesim turtlesim_node`)
- **Node 2:** `turtle_teleop_key` (from `ros2 run turtlesim turtle_teleop_key`)

## Visualizing Nodes with rqt_graph

Open a 4th terminal and enter:

```bash
rqt_graph
```

`rqt_graph` is used to visualize the changing nodes and topics, as well as the connections between them. Make sure to click the refresh button for any changes.

The graph depicts how the `/turtlesim` node and the `/teleop_turtle` node are communicating with each other over a topic. The `/teleop_turtle` node is publishing data (the keystrokes you enter to move the turtle around) to the `/turtle1/cmd_vel` topic, and the `/turtlesim` node is subscribed to that topic to receive the data.

## ROS2 Topic Commands

### Topic Echo

Open a 5th terminal and enter:

```bash
ros2 topic echo /turtle1/cmd_vel
```

Return to the terminal where `turtle_teleop_key` is running and use the arrows to move the turtle around. Watch the terminal where your echo is running at the same time, and you'll see position data being published for every movement you make.

**Output:**
```yaml
linear:
  x: 2.0
  y: 0.0
  z: 0.0
angular:
  x: 0.0
  y: 0.0
  z: 0.0
```

### Basic ROS2 Commands

Open a new shell/terminal for each task below and observe the output:

```bash
ros2 node list
ros2 topic list
ros2 service list
ros2 action list
```

### Topic Publish

Close all existing terminals and shells using (Ctrl + C on each terminal).

Open a new shell as shown:

**Terminal 1:**
```bash
ros2 run turtlesim turtlesim_node
```

**Terminal 2:**
```bash
ros2 run turtlesim turtle_teleop_key
```

**Terminal 3:**
```bash
ros2 topic pub --once /turtle1/cmd_vel geometry_msgs/msg/Twist "{linear: {x: 2.0, y: 0.0, z: 0.0}, angular: {x: 0.0, y: 0.0, z: 1.8}}"
```

Now that you have the message structure, you can publish data onto a topic directly from the command line using:

```bash
ros2 topic pub <topic_name> <msg_type> '<args>'
```

**Velocity Definitions:**
- **Linear Speed** = (Distance / time) = d / t, The unit of linear speed is m/s or ms⁻¹
- **Angular Speed** = radian per second (rad/s)

**Output:**
```
publisher: beginning loop
publishing #1: geometry_msgs.msg.Twist(linear=geometry_msgs.msg.Vector3(x=2.0, y=0.0, z=0.0), angular=geometry_msgs.msg.Vector3(x=0.0, y=0.0, z=1.8))
```

### Topic Publish with Rate

Try the following and note the difference in the command and the output:

```bash
ros2 topic pub --rate 1 /turtle1/cmd_vel geometry_msgs/msg/Twist "{linear: {x: 2.0, y: 0.0, z: 0.0}, angular: {x: 0.0, y: 0.0, z: 1.8}}"
```

You can stop the publisher using Ctrl+C

### Topic Echo for Pose

Try the following and observe the linear velocity and angular velocity:

```bash
ros2 topic pub --rate 1 /turtle1/cmd_vel geometry_msgs/msg/Twist "{linear: {x: 2.0, y: 0.0, z: 0.0}, angular: {x: 0.0, y: 0.0, z: 1.8}}"
```

In another terminal:
```bash
ros2 topic echo /turtle1/pose
```

**Experiments:**
- Change the publisher linear x to 4.0 and angular z to 5.8 and observe the changes
- Change the publisher linear x to 1.0 and angular z to 0.8 and observe the changes

### Topic Hertz (Rate)

Run the following command to publish the command velocity:

```bash
ros2 topic pub --rate 1 /turtle1/cmd_vel geometry_msgs/msg/Twist "{linear: {x: 2.0, y: 0.0, z: 0.0}, angular: {x: 0.0, y: 0.0, z: 1.8}}"
```

Open a new terminal and run the following to view the rate of topic being published:

```bash
ros2 topic hz /turtle1/cmd_vel
```

**Output:**
```
average rate: 1.000
min: 0.998s max: 1.001s std dev: 0.00065s window: 22
```

**Task:** Modify the command such that the average rate is 2.0 (2 times per second)

Press Ctrl+C to stop the process for each terminal. After stopping all the process, you can close the terminal and shut down the PC.

## Demo Questions

Be prepared to answer these questions during demo:

### Q1) Is turtle_teleop_key a subscriber or publisher? Explain.

**Answer:** Publisher, from the rqt_graph, it publishes a topic, it does not subscribe to any topic.

### Q2) What is the topic that turtlesim node subscribe to?

**Answer:** turtle1/cmd_vel

### Q3) Explain the function of this command line "ros2 topic pub <topic_name> <msg_type> '<args>'"

**Answer:** 
```bash
ros2 topic pub --rate 1 /turtle1/cmd_vel geometry_msgs/msg/Twist "{linear: {x: 2.0, y: 0.0, z: 0.0}, angular: {x: 0.0, y: 0.0, z: 1.8}}"
```

It publishes a topic with message type and arguments.

### Q4) Explain the difference between linear and angular velocity

**Answer:** Linear and angular are two different types of motion that objects can undergo.

Linear motion is motion in a straight line. On the other hand, angular motion is defined as the motion of a body about a fixed point or fixed axis.

The key difference between linear and angular motion lies in the path that the moving object follows. In linear motion, the object moves along a straight path, whereas in angular motion, the object moves along a curved path.

---

*End of briefing for Lab session*
