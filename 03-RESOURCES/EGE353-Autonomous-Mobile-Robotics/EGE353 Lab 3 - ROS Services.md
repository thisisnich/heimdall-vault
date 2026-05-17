---
tags:
  - EGE353
  - lab
  - ROS2
  - services
  - parameters
course: EGE353 Autonomous Robotics
topic: Lab 3 - ROS2 Services and Parameters
source: Lab 3 Ros services.pdf
converted: 2026-04-28
---

> **Related:** [[EGE353 Lab 1 Notes|Lab 1]] | [[EGE353 Lab 2 - ROS Nodes and Topics|Lab 2]] | [[EGE353 Lab 4 - ROS Bag Files and Gazebo|Lab 4]]

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

Services are another method of communication for nodes in the ROS graph. Services are based on a call-and-response model, versus topics' publisher-subscriber model. While topics allow nodes to subscribe to data streams and get continual updates, services only provide data when they are specifically called by a client. Nodes can communicate using services in ROS 2. Unlike a topic - a one way communication pattern where a node publishes information that can be consumed by one or more subscribers - a service is a request/response pattern where a client makes a request to a node providing the service and the service processes the request and generates a response.

You generally don't want to use a service for continuous calls; topics or even actions would be better suited.

### TASK 1 - Service Call

To start turtlesim, enter the following command in your new terminal:

```bash
$ ros2 run turtlesim turtlesim_node
```

Open a 2nd terminal and run the following:

```bash
$ ros2 service list
```

Open a 3rd terminal and run the following:

```bash
$ ros2 run turtlesim turtle_teleop_key
```

**Q1)** Rerun the service list again on 2nd terminal. Note the difference between the results before and after the turtle_telop_key is run:

```bash
$ ros2 service list
```

Output:
```
/reset
/spawn
/teleop_turtle/describe_parameters
/teleop_turtle/get_parameter_types
/teleop_turtle/get_parameters
/teleop_turtle/list_parameters
/teleop_turtle/set_parameters
/teleop_turtle/set_parameters_atomically
/turtle1/set_pen
/turtle1/teleport_absolute
/turtle1/teleport_relative
/turtlesim/describe_parameters
/turtlesim/get_parameter_types
/turtlesim/get_parameters
/turtlesim/list_parameters
/turtlesim/set_parameters
/turtlesim/set_parameters_atomically
```

Let's take a look at turtlesim's /clear service. In the 2nd terminal, enter the command:

```bash
$ ros2 service type /clear
```

Output: `std_srvs/srv/Empty`

Empty type means the service call sends no data when making a request and receives no data when receiving a response.

To see the types of all the active services at the same time, you can append the --show-types option, abbreviated as -t, to the list command:

```bash
$ ros2 service list -t
```

Output:
```
/clear [std_srvs/srv/Empty]
/kill [turtlesim/srv/Kill]
/reset [std_srvs/srv/Empty]
/spawn [turtlesim/srv/Spawn]
...
/turtle1/set_pen [turtlesim/srv/SetPen]
/turtle1/teleport_absolute [turtlesim/srv/TeleportAbsolute]
/turtle1/teleport_relative [turtlesim/srv/TeleportRelative]
...
```

You can find all the Empty typed services like this. In the 2nd terminal, enter the command:

```bash
$ ros2 service find std_srvs/srv/Empty
```

Output:
```
/clear
/reset
```

You can call services from the command line, but first you need to know the structure of the input arguments. To run this command, in the 2nd terminal, enter:

```bash
$ ros2 interface show turtlesim/srv/Spawn
```

Output:
```
float32 x
float32 y
float32 theta
string name # Optional.  A unique name will be created and returned if this is empty
---
string name
```

The information above the --- line tells us the arguments needed to call /spawn. x, y and theta determine the location of the spawned turtle, and name is clearly optional. The information below the line isn't something you need to know in this case, but it can help you understand the data type of the response you get from the call.

After knowing what a service type is, how to find a serviceâ€™s type, and how to find the structure of that typeâ€™s arguments, you can call a service using:

```bash
ros2 service call <service_name> <service_type> <arguments>
```

Now letâ€™s spawn a new turtle by calling /spawn and inputting arguments. Input <arguments> in a service call from the command-line need to be in YAML syntax.

```bash
$ ros2 service call /spawn turtlesim/srv/Spawn "{x: 2, y: 2, theta: 0.2, name: ''}"
```

Output:
```
requester: making request: turtlesim.srv.Spawn_Request(x=2.0, y=2.0, theta=0.2, name='')

response:
turtlesim.srv.Spawn_Response(name='turtle2')
```

To kill / delete turtle1, use the following command:

```bash
$ ros2 service call /kill turtlesim/srv/Kill "{name: 'turtle1'}"
```

**Q2)** Modify the command to spawn at least another 9 turtlesim in different location and orientation as shown. Screenshot your terminal command, Turtlesim display results and fill in the table below.


| Turtle | x | y | theta |
|--------|---|---|-------|
| 3 | 10 | 10 | 3.14/4 |
| 4 | 6 | 1 | 3 |
| 5 | 2 | 7 | 8 |
| 6 | 9 | 13 | 9 |

**Spawn 9 turtles in a circle (45° apart, radius 3.5, pointing outward from center):**
```bash
ros2 service call /spawn turtlesim/srv/Spawn "{x: 9.0, y: 5.5, theta: 0, name: ''}"
ros2 service call /spawn turtlesim/srv/Spawn "{x: 7.97, y: 7.97, theta: 0.785, name: ''}"
ros2 service call /spawn turtlesim/srv/Spawn "{x: 5.5, y: 9.0, theta: 1.571, name: ''}"
ros2 service call /spawn turtlesim/srv/Spawn "{x: 3.03, y: 7.97, theta: 2.356, name: ''}"
ros2 service call /spawn turtlesim/srv/Spawn "{x: 2.0, y: 5.5, theta: 3.142, name: ''}"
ros2 service call /spawn turtlesim/srv/Spawn "{x: 3.03, y: 3.03, theta: 3.927, name: ''}"
ros2 service call /spawn turtlesim/srv/Spawn "{x: 5.5, y: 2.0, theta: 4.712, name: ''}"
ros2 service call /spawn turtlesim/srv/Spawn "{x: 7.97, y: 3.03, theta: 5.498, name: ''}"
ros2 service call /spawn turtlesim/srv/Spawn "{x: 8.5, y: 5.5, theta: 6.283, name: ''}"
```

### TASK 2 - Using RQT to Set Pen

Close all previous terminals and open new terminal windows.

To start turtlesim, enter the following command in your 1st terminal:

```bash
$ ros2 run turtlesim turtlesim_node
```

Open a 2nd terminal and run the following:

```bash
$ ros2 run turtlesim turtle_teleop_key
```

Open the 3rd terminal and run the following command to view the service caller:

```bash
$ rqt
```

The service caller can help to set the pen width and the colour of the pen.

Set the turtle1/set_pen parameter to g = 255 and width = 5. Click Call button to send the service to turtlesim. Return to turtle_teleop_key terminal and control the turtlesim to draw any shape. Observe the pen width and colour.

Change the pen width to 10 and pen colour to purple.

Using ros topic pub, publish the cmd_vel to control the turtlesim to draw 2 circles as shown. The size of circle can be random.

Open a 4th terminal and run the following:

```bash
$ ros2 topic pub --once /turtle1/cmd_vel geometry_msgs/msg/Twist "{linear: {x: 2.0, y: 0.0, z: 0.0}, angular: {x: 0.0, y: 0.0, z: 1.8}}"
```

#### Spawn Turtle2

Return to 2nd terminal and Ctrl+C to terminate the turtle_teleop_key.

```bash
$ ros2 service call /spawn turtlesim/srv/Spawn "{x: 2, y: 2, theta: 0.2, name: ''}"
```

Open a new terminal and run a new teleop_key, remap the topic turtle1/cmd_vel to turtle2/cmd_vel so that you are able to control the new turtle2:

```bash
$ ros2 run turtlesim turtle_teleop_key --ros-args --remap turtle1/cmd_vel:=turtle2/cmd_vel
```

Open a new terminal:

```bash
$ ros2 topic list
```

Observe the output, how many cmd_vel did you see? Control the turtle2 to draw a white line as shown.

#### Spawn 3 Turtles

**Q3)** Modify the pen colour to your choice of colour and draw different circles or line with the 3 or more turtles. Screenshot your results.

## ROS Parameters

A parameter is a configuration value of a node. You can think of parameters as node settings. A node can store parameters as integers, floats, booleans, strings, and lists. In ROS 2, each node maintains its own parameters. Parameters in ROS are associated with individual nodes. Parameters are used to configure nodes at startup (and during runtime), without changing the code. The lifetime of a parameter is tied to the lifetime of the node (though the node could implement some sort of persistence to reload values after restart).

Parameters are addressed by node name, node namespace, parameter name, and parameter namespace. Providing a parameter namespace is optional.

Each parameter consists of a key, a value, and a descriptor. The key is a string and the value is one of the following types: bool, int64, float64, string, byte[], bool[], int64[], float64[] or string[]. By default all descriptors are empty, but can contain parameter descriptions, value ranges, type information, and additional constraints.

### rqt_reconfigure for Parameters Settings

*(Note: The following screenshots are for illustration only, you will not be able to view these settings from your rqt as the node is not available to you.)*


**rqt_reconfigure for rgb_camera parameters** - [Screenshot placeholder]


### Change Parameters Settings for Turtlesim

Available turtlesim parameters:
```
/turtlesim:
  background_b
  background_g
  background_r
  use_sim_time
```

ROS parameter server allows you to store and manipulate data. The Parameter Server can store integers, floats, boolean, dictionaries, and lists. ROS parameters use the YAML markup language for syntax. In simple cases, YAML looks very natural: 1 is an integer, 1.0 is a float, one is a string, true is a boolean, [1, 2, 3] is a list of integers, and {a: b, c: d} is a dictionary. ROS has many commands that can be used on parameters, as shown below.

### TASK 3 - ROS Parameters (Optional)

Close all terminals and start a new terminal. Start up the two turtlesim nodes, /turtlesim and /teleop_turtle.

```bash
$ ros2 run turtlesim turtlesim_node
```

Open a 2nd terminal and run the following:

```bash
$ ros2 run turtlesim turtle_teleop_key
```

Open a 3rd terminal and run the following:

```bash
$ ros2 param list
```

Output:
```
/teleop_turtle:
  scale_angular
  scale_linear
  use_sim_time
/turtlesim:
  background_b
  background_g
  background_r
  use_sim_time
```

Take note of the node namespaces, /teleop_turtle and /turtlesim, followed by each node's parameters. Let's find out the current value of /turtlesim's parameter background_g:

```bash
$ ros2 param get /turtlesim background_g
```

Output: `Integer value is: 86`

Set the background red value:

```bash
$ ros2 param set /turtlesim background_r 150
```

Dump all parameters to a file:

```bash
$ ros2 param dump /turtlesim
```

Output: `Saving to: ./turtlesim.yaml`

View the saved file:

```bash
$ cat turtlesim.yaml
```

Output:
```yaml
/turtlesim:
  ros__parameters:
    background_b: 255
    background_g: 86
    background_r: 150
    use_sim_time: false
```

**Q4)** Modify the command to change the turtlesim's background color r=150, b=255, and g=86 to get a purple background. Using parameter get to show the rgb values on the terminal and parameter set to change the turtlesim's background to purple. Screenshot both terminal and simulation as shown.

### Load Parameters

Now, Ctrl+C to stop all processes in each terminal and close all terminals. Start new terminals and load in the parameters using ./turtlesim.yaml file saved earlier.

```bash
ros2 run <package_name> <executable_name> --ros-args --params-file <file_name>

$ ros2 run turtlesim turtlesim_node --ros-args --params-file ./turtlesim.yaml
```

Open a 2nd terminal turtlesim and rerun without loading the parameters. Note what is the difference:

```bash
$ ros2 run turtlesim turtlesim_node
```

Nodes have parameters to define their default configuration values. You can get and set parameter values from the command line. You can also save the parameter settings to a file to reload them in a future session.

---

## Teaching Points Summary

### Topics
- **Publisher-Subscriber Model**: Topics enable continuous data streams where nodes publish information consumed by one or more subscribers
- **Topic Remapping**: Use `--ros-args --remap old_topic:=new_topic` to redirect topic communications (e.g., controlling turtle2 instead of turtle1)
- **Topic Publishing**: Use `ros2 topic pub` to send messages to topics (e.g., `/turtle1/cmd_vel` for velocity control)
- **Topic Listing**: `ros2 topic list` shows all active topics in the ROS graph

### Multiple Turtles
- **Spawning Turtles**: Use `/spawn` service with x, y, theta, and optional name parameters to create new turtles
- **Turtle Names**: Auto-generated (turtle2, turtle3, etc.) if name field is empty
- **Individual Control**: Each turtle has its own topics (`/turtle1/cmd_vel`, `/turtle2/cmd_vel`, etc.) and services (`/turtle1/set_pen`, `/turtle2/set_pen`, etc.)
- **Killing Turtles**: Use `/kill` service to remove specific turtles by name

### ROS Service Call
- **Call-and-Response Model**: Services provide request/response communication vs. topics' one-way streams
- **Service Discovery**: `ros2 service list` shows all available services; `-t` flag shows types
- **Service Types**: `ros2 service type <service_name>` displays the service type (e.g., `std_srvs/srv/Empty`)
- **Finding Services by Type**: `ros2 service find <type>` finds all services of a specific type
- **Interface Inspection**: `ros2 interface show <service_type>` shows request/response structure
- **Calling Services**: `ros2 service call <service_name> <service_type> <arguments>` with YAML syntax for arguments
- **Common Services**:
  - `/spawn` - Create new turtles
  - `/kill` - Delete turtles
  - `/clear` - Clear drawing (Empty type)
  - `/reset` - Reset simulation (Empty type)
  - `/turtleX/set_pen` - Change pen color/width
  - `/turtleX/teleport_absolute` - Teleport to absolute position
  - `/turtleX/teleport_relative` - Teleport relative to current position

### ROS Parameters
- **Node Configuration**: Parameters are node settings stored as integers, floats, booleans, strings, or lists
- **Parameter Namespaces**: Each node maintains its own parameters (e.g., `/turtlesim/background_r`, `/teleop_turtle/scale_linear`)
- **Listing Parameters**: `ros2 param list` shows all parameters across nodes
- **Getting Parameters**: `ros2 param get <node_name> <parameter_name>` reads current value
- **Setting Parameters**: `ros2 param set <node_name> <parameter_name> <value>` changes value at runtime
- **Dumping Parameters**: `ros2 param dump <node_name>` exports all parameters to YAML file
- **Loading Parameters**: `ros2 run <package> <executable> --ros-args --params-file <file.yaml>` loads parameters at startup
- **Persistence**: Parameters last only while the node is running unless saved to file

---

## End of Lab Briefing

---

## Command List (Copy-Paste Ready)

```bash
# ===== TASK 1 - Service Call (Open 3 terminals) =====
# Terminal 1 - Start simulator:
ros2 run turtlesim turtlesim_node    # Launch turtlesim node (provides services)

# Terminal 2 - List services:
ros2 service list                    # Show all available services before teleop

# Terminal 3 - Start teleop:
ros2 run turtlesim turtle_teleop_key # Launch keyboard control node

# Back in Terminal 2 - Check new services:
ros2 service list                    # Show services again (now includes teleop_turtle services)

# Terminal 2 - Inspect /clear service:
ros2 service type /clear             # Display the service type (std_srvs/srv/Empty)

# Terminal 2 - List with types:
ros2 service list -t                 # Show all services with their types

# Terminal 2 - Find services by type:
ros2 service find std_srvs/srv/Empty # Find all services that use Empty type

# Terminal 2 - Inspect Spawn service structure:
ros2 interface show turtlesim/srv/Spawn   # Show request/response format for Spawn service

# Terminal 2 - Spawn a new turtle:
ros2 service call /spawn turtlesim/srv/Spawn "{x: 2, y: 2, theta: 0.2, name: ''}"   # Call service to create turtle2 at position (2,2) with 0.2 rad rotation

# Terminal 2 - Kill a turtle:
ros2 service call /kill turtlesim/srv/Kill "{name: 'turtle1'}"   # Remove turtle1 from simulation

# ===== TASK 2 - RQT SetPen (Close all previous, open 4 new terminals) =====
# Terminal 1:
ros2 run turtlesim turtlesim_node    # Launch fresh turtlesim instance

# Terminal 2:
ros2 run turtlesim turtle_teleop_key # Launch keyboard control

# Terminal 3:
rqt                                  # Open RQT GUI for visual service calling

# Terminal 4 - Draw circle with cmd_vel:
ros2 topic pub --once /turtle1/cmd_vel geometry_msgs/msg/Twist "{linear: {x: 2.0, y: 0.0, z: 0.0}, angular: {x: 0.0, y: 0.0, z: 1.8}}"   # Publish single Twist message (linear x=2 m/s, angular z=1.8 rad/s) to make turtle move in arc

# Terminal 4 - Spawn turtle2:
ros2 service call /spawn turtlesim/srv/Spawn "{x: 2, y: 2, theta: 0.2, name: ''}"   # Create second turtle

# Terminal 2 (Ctrl+C first) - Remap teleop to turtle2:
ros2 run turtlesim turtle_teleop_key --ros-args --remap turtle1/cmd_vel:=turtle2/cmd_vel   # Launch teleop remapped to control turtle2 instead of turtle1

# Terminal 4 - Check topics:
ros2 topic list                      # List topics to see both /turtle1/cmd_vel and /turtle2/cmd_vel

# ===== TASK 3 - ROS Parameters (Optional) (Close all, open 3 terminals) =====
# Terminal 1:
ros2 run turtlesim turtlesim_node    # Launch turtlesim

# Terminal 2:
ros2 run turtlesim turtle_teleop_key # Launch teleop

# Terminal 3 - List all parameters:
ros2 param list                      # Show parameters for all nodes (background colors, scale factors, etc.)

# Terminal 3 - Get specific parameter:
ros2 param get /turtlesim background_g   # Read current green background value (default: 86)

# Terminal 3 - Set parameter value:
ros2 param set /turtlesim background_r 150   # Change red background component to 150

# Terminal 3 - Save all parameters to file:
ros2 param dump /turtlesim           # Export /turtlesim parameters to YAML file (./turtlesim.yaml)

# Terminal 3 - View saved file:
cat turtlesim.yaml                   # Display contents of saved parameter file

# Terminal 1 (Ctrl+C first) - Load parameters from file:
ros2 run turtlesim turtlesim_node --ros-args --params-file ./turtlesim.yaml   # Launch turtlesim with saved parameters (purple background)

# Compare with default (Terminal 1 - new window):
ros2 run turtlesim turtlesim_node    # Launch turtlesim with default parameters (blue background)
```
