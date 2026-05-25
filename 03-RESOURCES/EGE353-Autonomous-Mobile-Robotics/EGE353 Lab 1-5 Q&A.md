---
type: lab
course: EGE353
module: EGE353-Autonomous-Mobile-Robotics
status: draft
source: manual
created: 2026-05-22
tags: [EGE353, lab, ros2, qna, flashcards, exam-prep]
---
	
> **Related:** [[07-DASHBOARDS/NYPY3 - Main Index|NYPY3 Index]] | [[EGE353 Lab 1 Notes|Lab 1]] | [[EGE353 Lab 2 - ROS Nodes and Topics|Lab 2]] | [[EGE353 Lab 3 - ROS Services|Lab 3]] | [[EGE353 Lab 4 - ROS Bag Files and Gazebo|Lab 4]] | [[EGE353 Lab 5 Notes|Lab 5]] | [[EGE353 Lab 5 Package Guide|Package Guide]] | [[07-DASHBOARDS/Schedule & Assessments Dashboard|Assessments]]

# EGE353 Lab 1–5 Q&A & Command Reference

Study sheet for Practical 1 demo questions, Proctored Quiz-1 (Labs 1–6 scope), and oral checks. Content sourced from vault lab notes only.

---

## Command cheat sheet (all labs)

| Command | What it does |
|---------|----------------|
| `source /opt/ros/humble/setup.bash` | Load system ROS 2 (Humble) in current terminal |
| `source ~/dev_ws/install/setup.bash` | Load workspace overlay (underlay + your packages) |
| `source ~/dev_ws/install/local_setup.bash` | Load overlay only (underlay must already be sourced) |
| `ros2 run <pkg> <exe>` | Run a compiled node executable |
| `ros2 node list` | List running node names |
| `ros2 topic list` | List active topics |
| `ros2 topic echo /topic` | Print messages on a topic in real time |
| `ros2 topic hz /topic` | Show average publish frequency (Hz) |
| `ros2 topic pub --once ...` | Publish one message from CLI |
| `ros2 topic pub --rate N ...` | Publish repeatedly at N Hz |
| `ros2 service list` | List available services |
| `ros2 service list -t` | List services with types |
| `ros2 service type /name` | Show type of one service |
| `ros2 service find <type>` | Find services matching a type |
| `ros2 interface show <type>` | Show fields of a message/service type |
| `ros2 service call <name> <type> "{...}"` | Send one service request |
| `ros2 param list` | List parameters for nodes |
| `ros2 param get /node param` | Read a parameter value |
| `ros2 param set /node param value` | Change a parameter at runtime |
| `ros2 param dump /node` | Save node params to YAML |
| `rqt_graph` | Open GUI graph of nodes and topics (Lab 1–4) |
| `ros2 run rqt_graph rqt_graph` | Same tool via ros2 run (Lab 5 demo) |
| `rqt` | General ROS GUI toolbox (e.g. Service Caller) |
| `ros2 bag record -o name /topic ...` | Record topic(s) to a bag folder |
| `ros2 bag play -l name` | Replay bag in a loop |
| `ros2 bag info name` | Show duration and message counts |
| `git clone <url> -b humble` | Copy remote repo into workspace `src/` |
| `rosdep install -i --from-path src --rosdistro humble -y` | Install package dependencies |
| `colcon build` | Build all packages in workspace |
| `colcon build --packages-select <pkg>` | Build one package only |
| `ros2 pkg create --build-type ament_cmake ...` | Create new C++ package |
| `ros2 pkg executables <pkg>` | List runnable executables in a package |
| `--ros-args --remap old:=new` | Remap topic name at runtime |

---

## Lab 1 — Topics & TurtleSim

**Q1: What does `source /opt/ros/humble/setup.bash` do?**  
A: Loads the system ROS 2 environment so `ros2` commands and system packages work in that terminal.

**Q2: What does `ros2 run turtlesim turtlesim_node` do?**  
A: Starts the turtlesim simulation node.

**Q3: What does `ros2 run turtlesim turtle_teleop_key` do?**  
A: Starts keyboard teleop — publishes velocity commands to `/turtle1/cmd_vel`.

**Q4: Is `turtle_teleop_key` a publisher or subscriber?**  
A: **Publisher** — it publishes to `/turtle1/cmd_vel`; it does not subscribe.

**Q5: What topic does turtlesim subscribe to for movement?**  
A: `/turtle1/cmd_vel`

**Q6: What does `ros2 node list` do?**  
A: Lists all currently running ROS 2 nodes.

**Q7: What does `ros2 topic list` do?**  
A: Lists all active topics in the graph.

**Q8: What does `ros2 service list` / `ros2 action list` do?**  
A: Lists available services / actions.

**Q9: What does `ros2 topic echo /turtle1/cmd_vel` do?**  
A: Displays messages published on that topic (linear.x, angular.z, etc.).

**Q10: What does `ros2 topic pub <topic> <msg_type> '<args>'` do?**  
A: Publishes a message of the given type to the topic from the command line.

**Q11: What does `--rate 1` on `ros2 topic pub` mean?**  
A: Publish repeatedly at **1 Hz**.

**Q12: What does `ros2 topic hz /turtle1/cmd_vel` do?**  
A: Reports the average publishing frequency of that topic.

**Q13: What does `rqt_graph` do?**  
A: Opens a GUI showing nodes, topics, and pub/sub connections. Select active nodes/topics and click **Refresh** after changes.

**Q14: What is the Lab 5 equivalent command?**  
A: `ros2 run rqt_graph rqt_graph` — same tool, invoked via `ros2 run`.

**Q15: Linear vs angular velocity?**  
A: Linear = straight-line motion (m/s); angular = rotation about an axis (rad/s), usually `angular.z` for yaw on the turtle.

**Q16: What is theta?**  
A: Orientation angle in radians; positive = counterclockwise, negative = clockwise.

---

## Lab 2 — Nodes, workspace, remap

**Q1: What does `git clone` do?**  
A: Creates a local copy of a remote Git repository (files + version history).

**Q2: What does `colcon build --packages-select teleop_cpp_ros2` do?**  
A: Builds only the named package (faster than building the whole workspace).

**Q3: What does `source install/setup.bash` do?**  
A: Makes your built workspace packages available to `ros2 run` in that terminal.

**Q4: Why don't teleop and turtlesim connect at first?**  
A: Topic names differ — teleop publishes `/cmd_vel`, turtlesim listens on `/turtle1/cmd_vel`.

**Q5: Remap teleop to turtlesim?**  
```bash
ros2 run teleop_cpp_ros2 teleop --ros-args --remap /cmd_vel:=/turtle1/cmd_vel
```  
A: Redirects teleop output to the topic turtlesim actually subscribes to.

**Q6: Frequency of `/cmd_vel` from keyboard teleop?**  
A: **Event-based** — publishes when a key is pressed, not at a fixed rate.

**Q7: Twist axes on the turtle (x, y, z)?**  
A: **X** forward/back (`linear.x`); **Y** left/right strafe on holonomic robots (`linear.y`); **Z** rotation/yaw (`angular.z`).

**Q8: What does `ros2 topic echo /cmd_vel` do?**  
A: Prints velocity messages from the teleop publisher in real time.

---

## Lab 3 — Services & parameters

**Q1: Topic vs service?**  
A: **Topic** = continuous publisher/subscriber stream. **Service** = synchronous request/response (one-shot action).

**Q2: `ros2 service list` vs `ros2 service list -t`?**  
A: List service names / list with **service types** included.

**Q3: `ros2 service type /clear`?**  
A: Shows the service type (e.g. `std_srvs/srv/Empty`).

**Q4: `ros2 interface show turtlesim/srv/Spawn`?**  
A: Shows request and response fields for the Spawn service.

**Q5: Spawn a turtle?**  
```bash
ros2 service call /spawn turtlesim/srv/Spawn "{x: 2, y: 2, theta: 0.2, name: ''}"
```

**Q6: Kill a turtle?**  
```bash
ros2 service call /kill turtlesim/srv/Kill "{name: 'turtle1'}"
```

**Q7: Control turtle2 with teleop?**  
```bash
ros2 run turtlesim turtle_teleop_key --ros-args --remap turtle1/cmd_vel:=turtle2/cmd_vel
```

**Q8: `ros2 param list` / `get` / `set` / `dump`?**  
A: List all params on nodes; read one value; change one at runtime; save node params to a YAML file.

**Q9: Load saved parameters at node startup?**  
```bash
ros2 run turtlesim turtlesim_node --ros-args --params-file ./turtlesim.yaml
```

**Q10: What is `rqt` Service Caller used for in Lab 3?**  
A: GUI to call services (e.g. `/turtle1/set_pen`) without typing `ros2 service call`.

---

## Lab 4 — Rosbag & Gazebo

**Q1: Three main rosbag commands?**  
A: `record`, `play`, `info`.

**Q2: Record multiple topics?**  
```bash
ros2 bag record -o bagfile1 /turtle1/cmd_vel /turtle1/pose
```  
A: Saves published data on those topics to folder `bagfile1`.

**Q3: Replay in a loop?**  
```bash
ros2 bag play -l bagfile1
```  
A: Replays recorded messages; `-l` loops forever.

**Q4: `ros2 bag info bagfile1`?**  
A: Shows duration, total messages, and count per topic.

**Q5: Which node/topic moves the turtle in Lab 4 setup?**  
A: Node `turtle_teleop_key`; topic `/turtle1/cmd_vel`.

**Q6: Why remap teleop for Gazebo?**  
A: Teleop publishes `/turtle1/cmd_vel`; Gazebo diff-drive demo listens on `/demo/cmd_demo`.

**Q7: Gazebo remap example?**  
```bash
ros2 run turtlesim turtle_teleop_key --ros-args --remap /turtle1/cmd_vel:=/demo/cmd_demo
```

**Q8: Start Gazebo demo world?**  
```bash
gazebo --verbose /opt/ros/humble/share/gazebo_plugins/worlds/gazebo_ros_diff_drive_demo.world
```

**Q9: When demoing bag playback, what does `rqt_graph` show?**  
A: e.g. rosbag player → `/turtle1/cmd_vel` → `/turtlesim` (active pub/sub chain).

---

## Lab 5 — Packages, pub/sub, rosbag (Practical 1)

**Q1: Overlay vs underlay?**  
A: **Underlay** = base ROS install (`/opt/ros/humble`). **Overlay** = your `dev_ws` built with `colcon`. Overlay packages **override** same-named underlay packages.

**Q2: Terminal 1 vs Terminal 2 turtlesim in Task 1?**  
A: T1 sources overlay → custom compiled turtlesim (your window title). T2 sources only underlay → system turtlesim (default title).

**Q3: When do you run `colcon build`?**  
A: After any change to source code, `CMakeLists.txt`, or `package.xml`.

**Q4: `rosdep install -i --from-path src --rosdistro humble -y`?**  
A: Installs missing system dependencies for packages in `src/`.

**Q5: Create a C++ package with a node?**  
```bash
ros2 pkg create --build-type ament_cmake --node-name my_node my_package
```

**Q6: Talker topic, node names, message type, frequency?**  
A: Topic `/topic`; nodes `minimal_publisher` and `minimal_subscriber`; type `std_msgs/msg/String`; ~**2 Hz** (500 ms timer).

**Q7: Command to check talker frequency?**  
```bash
ros2 topic hz /topic
```

**Q8: Task 4 — record then demo?**  
Record: `ros2 bag record -o bagtalker /topic` while `ros2 run cpp_pubsub talker` runs.  
Demo: `ros2 bag play -l bagtalker` + `ros2 run cpp_pubsub listener` + `ros2 run rqt_graph rqt_graph` (no talker).

**Q9: Task 5 — what is different from Task 4?**  
A: One bag with **two topics** (`/upcounter` ~2 Hz, `/downcounter` ~1 Hz) and **two listeners** (`Countup_Listener`, `Countdown_Listener`). Demo: bag play + both listeners + rqt_graph.

**Q10: Why must every `.cpp` node appear in `CMakeLists.txt`?**  
A: `add_executable` creates the build target; `install(TARGETS ...)` makes it available to `ros2 run`.

**Q11: Other talker/listener examples in robotics?**  
A: Camera driver (publisher/talker), image display or detector node (subscriber/listener).

**Q12: What files define a ROS 2 package?**  
A: `package.xml` (metadata and dependencies) and `CMakeLists.txt` (build and install rules).

---

## Flashcards

Q::: What command opens the ROS node/topic graph GUI?
A::: `rqt_graph` or `ros2 run rqt_graph rqt_graph`

Q::: What does `ros2 topic hz /topic` show?
A::: Average publish frequency (Hz) of that topic

Q::: Is `turtle_teleop_key` a publisher or subscriber?
A::: Publisher (publishes to `/turtle1/cmd_vel`)

Q::: Topic vs service — main difference?
A::: Topic = continuous stream (pub/sub); service = one request, one response

Q::: What does `git clone` do?
A::: Copies a remote Git repository to your local machine

Q::: When must you run `colcon build`?
A::: After changing source code, CMakeLists.txt, or package.xml

Q::: Overlay vs underlay?
A::: Underlay = base ROS install; overlay = your workspace; overlay overrides underlay

Q::: Talker topic name and message type (Lab 5 Task 3)?
A::: Topic `/topic`; type `std_msgs/msg/String`

Q::: Publisher and subscriber node names (Task 3)?
A::: `minimal_publisher` and `minimal_subscriber`

Q::: Talker publish rate (Task 3)?
A::: ~2 Hz (500 ms wall timer)

Q::: Record a bag from talker topic?
A::: `ros2 bag record -o bagtalker /topic` (while talker is running)

Q::: Task 4 demo — which nodes run?
A::: Bag player + listener + rqt_graph (no live talker)

Q::: Task 5 topics and rates?
A::: `/upcounter` ~2 Hz; `/downcounter` ~1 Hz

Q::: `ros2 bag play -l bagname` — what does `-l` do?
A::: Loop playback forever

Q::: Remap teleop to Gazebo robot cmd topic?
A::: `--ros-args --remap /turtle1/cmd_vel:=/demo/cmd_demo`

Q::: Spawn a turtle via service?
A::: `ros2 service call /spawn turtlesim/srv/Spawn "{x: 2, y: 2, theta: 0.2, name: ''}"`

Q::: What does `source install/setup.bash` do in dev_ws?
A::: Loads underlay + overlay so your packages are available

Q::: What does `ros2 pkg executables cpp_pubsub` show?
A::: List of runnable executables installed for that package

Q::: Keyboard teleop `/cmd_vel` frequency?
A::: Event-based (on key press), not fixed Hz

Q::: Linear vs angular velocity?
A::: Linear = m/s straight motion; angular = rad/s rotation (yaw = angular.z)
