---
type: lab
course: EGE353
module: EGE353-Autonomous-Mobile-Robotics
status: draft
source: manual
created: 2026-05-22
updated: 2026-05-26
tags: [EGE353, lab, ros2, qna, flashcards, exam-prep, quiz-1]
---

> **Related:** [[07-DASHBOARDS/NYPY3 - Main Index|NYPY3 Index]] | [[EGE353 Lab 1 Notes|Lab 1]] | [[EGE353 Lab 2 - ROS Nodes and Topics|Lab 2]] | [[EGE353 Lab 3 - ROS Services|Lab 3]] | [[EGE353 Lab 4 - ROS Bag Files and Gazebo|Lab 4]] | [[EGE353 Lab 5 Notes|Lab 5]] | [[EGE353 Lab 5 Package Guide|Package Guide]] | [[EGE353 Lab 5 Demo Study Guide|Practical 1 demo]] | [[07-DASHBOARDS/Schedule & Assessments Dashboard|Assessments]]
> **Sources merged:** vault lab notes + [[99-ATTACHMENTS/EGE353/ROS2_Revision_Notes.docx]]

# EGE353 Lab 1–5 Q&A & Command Reference

Study sheet for Practical 1 demo, **Proctored Quiz-1** (Labs 1–6), and oral checks.

---

## Core concepts

| Concept | Definition | Example |
|---------|------------|---------|
| **Node** | Smallest running program in ROS 2 | `turtlesim_node`, `turtle_teleop_key` |
| **Topic** | Named one-way communication channel | `/turtle1/cmd_vel`, `/turtle1/pose` |
| **Publisher** | Node that **sends** data to a topic | `turtle_teleop_key` → `/turtle1/cmd_vel` |
| **Subscriber** | Node that **receives** data from a topic | `turtlesim_node` on `/turtle1/cmd_vel` |
| **Service** | One-shot request/response (synchronous) | `/spawn`, `/kill` — **one server**, many clients |
| **Action** | Long-running task with goal + feedback (async) | Tasks that take a long time to complete |
| **Parameter** | Config variables on a node | `/turtlesim` → `background_r`, `background_g`, `background_b` |

### Topic vs service vs action

| | Topic | Service | Action |
|---|-------|---------|--------|
| Pattern | Continuous stream | One request → one response | Long task + feedback |
| Sync/async | Async | **Synchronous** | Async |
| Servers | Many publishers OK* | **One server** | One action server |
| Clients | Many subscribers OK | Many clients OK | Many clients OK |
| Use when | Ongoing data (pose, velocity) | One-time action (spawn/kill) | Long-running task |

\* **Multi-publisher warning:** Multiple publishers on the **same topic** can conflict — subscribers only see the topic name, not which node sent the message. Usually **one publisher per topic**.

---

## Command cheat sheet (all labs)

| Command | What it does |
|---------|--------------|
| `source /opt/ros/humble/setup.bash` | Load system ROS 2 (Humble) in current terminal |
| `source ~/dev_ws/install/setup.bash` | Load workspace overlay (underlay + your packages) |
| `source ~/dev_ws/install/local_setup.bash` | Load overlay only (underlay must already be sourced) |
| `ros2 run <pkg> <exe>` | Run a compiled node executable |
| `ros2 run turtlesim turtlesim_node` | Start turtlesim (subscriber) |
| `ros2 run turtlesim turtle_teleop_key` | Keyboard teleop (publisher) |
| `ros2 node list` | List running node names |
| `ros2 topic list` | List active topics |
| `ros2 topic echo /topic` | Print messages on a topic in real time |
| `ros2 topic echo /turtle1/pose` | Show turtle position & orientation live |
| `ros2 topic hz /topic` | Show average publish frequency (Hz) |
| `ros2 topic pub --once ...` | Publish one message from CLI |
| `ros2 topic pub --rate N ...` | Publish repeatedly at N Hz |
| `ros2 service list` / `ros2 action list` | List services / actions |
| `ros2 service list -t` | List services with types |
| `ros2 service type /name` | Show type of one service |
| `ros2 service find <type>` | Find services matching a type |
| `ros2 interface show <type>` | Show fields of a message/service type |
| `ros2 service call <name> <type> "{...}"` | Send one service request |
| `ros2 param list` / `get` / `set` / `dump` | List, read, change, or save node params |
| `ros2 param set /turtlesim background_r 150` | Change turtlesim background colour |
| `rqt_graph` / `ros2 run rqt_graph rqt_graph` | GUI graph of nodes and topics |
| `rqt` | General ROS GUI (e.g. Service Caller) |
| `ros2 bag record -o name /topic ...` | Record topic(s) to a bag folder (`.db3`) |
| `ros2 bag play -l name` | Replay bag in a loop |
| `ros2 bag info name` | Show duration and message counts |
| `git clone <url> -b humble` | Copy repo into workspace **`src/`** |
| `rosdep install -i --from-path src --rosdistro humble -y` | Install package dependencies |
| `colcon build` | Build all packages in workspace |
| `colcon build --packages-select <pkg>` | Build one package only |
| `ros2 pkg create --build-type ament_cmake ...` | Create new C++ package |
| `ros2 pkg executables <pkg>` | List runnable executables in a package |
| `--ros-args --remap old:=new` | Remap topic name at runtime |

---

## Lab 1 — Topics & TurtleSim

**System flow:**
```
Keyboard → turtle_teleop_key (publisher) → /turtle1/cmd_vel (topic) → turtlesim_node (subscriber) → turtle moves
```

**Q1: What does `source /opt/ros/humble/setup.bash` do?**  
A: Loads the system ROS 2 environment so `ros2` commands and system packages work in that terminal.

**Q2: What does `ros2 run turtlesim turtlesim_node` do?**  
A: Starts the turtlesim simulation node (**subscriber**).

**Q3: What does `ros2 run turtlesim turtle_teleop_key` do?**  
A: Starts keyboard teleop — **publisher** of velocity commands to `/turtle1/cmd_vel`.

**Q4: Is `turtle_teleop_key` a publisher or subscriber?**  
A: **Publisher** — publishes to `/turtle1/cmd_vel`; does not subscribe.

**Q5: What topic does turtlesim subscribe to for movement?**  
A: `/turtle1/cmd_vel` (cmd = command, vel = velocity).

**Q6: What does `ros2 node list` / `ros2 topic list` do?**  
A: Lists all running nodes / all active topics.

**Q7: What does `ros2 service list` / `ros2 action list` do?**  
A: Lists available services / actions.

**Q8: What does `ros2 topic echo /turtle1/cmd_vel` do?**  
A: Displays live messages on that topic (`linear.x`, `angular.z`, etc.).

**Q9: What does `ros2 topic echo /turtle1/pose` do?**  
A: Shows turtle position and orientation in real time.

**Q10: What does `ros2 topic pub` do? What does `--rate 1` mean?**  
A: Publishes messages from CLI. `--once` = single message; `--rate 1` = **1 Hz** (1 message per second).

```bash
ros2 topic pub --once /turtle1/cmd_vel geometry_msgs/msg/Twist \
  "{linear: {x: 2.0, y: 0.0, z: 0.0}, angular: {x: 0.0, y: 0.0, z: 1.8}}"

ros2 topic pub --rate 1 /turtle1/cmd_vel geometry_msgs/msg/Twist \
  "{linear: {x: 2.0, y: 0.0, z: 0.0}, angular: {x: 0.0, y: 0.0, z: 1.8}}"
```

**Q11: What does `ros2 topic hz /turtle1/cmd_vel` do?**  
A: Reports average publishing frequency of that topic.

**Q12: Frequency of `/cmd_vel` from keyboard teleop?**  
A: **Event-based** — publishes when a key is pressed, not at a fixed rate. (Course sheet may also cite **10 Hz** in other contexts — confirm with lab.)

**Q13: What does `rqt_graph` do?**  
A: Opens GUI showing nodes, topics, and pub/sub connections. Refresh after changes. Open in new terminal; Ctrl+C to stop. Lab 5 equivalent: `ros2 run rqt_graph rqt_graph`.

**Q14: `/turtle1/cmd_vel` field meanings?**

| Field | Effect |
|-------|--------|
| `linear.x > 0` | Forward |
| `linear.x < 0` | Backward |
| `angular.z > 0` | Turn left (anti-clockwise) |
| `angular.z < 0` | Turn right (clockwise) |

**Q15: Linear vs angular velocity?**  
A: Linear = straight-line motion (m/s); angular = rotation (rad/s), usually `angular.z` for yaw.

**Q16: What is theta? Coordinate system?**

| Axis / value | Meaning |
|--------------|---------|
| X | Increases right (0 → 13 in window) |
| Y | Increases upward (0 → 13) |
| Theta = 0 | Facing **East** (3 o'clock) |
| Theta = π (3.14 rad) | Facing **West** |
| Theta **+** | Anti-clockwise |
| Theta **−** | Clockwise |

**Q17: Teleop key bindings**

| Key(s) | Action |
|--------|--------|
| `i` / `,` | Forward / backward |
| `j` / `l` | Rotate left / right (in place) |
| `u`, `m` | Anti-clockwise diagonal |
| `o`, `.` | Clockwise diagonal |
| **Capital** letters | Translation relative to robot front |

---

## Lab 2 — Nodes, workspace, remap

**Underlay vs overlay**

| Underlay | Overlay |
|----------|---------|
| Base ROS at `/opt/ros/humble` | Your `~/dev_ws` built with `colcon` |
| System packages & libraries | Custom/edited packages on top |
| Like original game files | Like mods — **overrides** same-named underlay packages |

**Q1: What does `git clone` do? Where do you run it?**  
A: Copies a remote Git repository locally. Run from workspace **`src/`** folder.

**Q2: What does `colcon build --packages-select teleop_cpp_ros2` do?**  
A: Builds only that package (reads source → compiles C++ → executable).

**Q3: What does `source install/setup.bash` do?**  
A: Loads underlay + overlay so your packages are available to `ros2 run`.

**Q4: Why don't teleop and turtlesim connect at first?**  
A: Topic names differ — teleop publishes `/cmd_vel`, turtlesim listens on `/turtle1/cmd_vel`.

**Q5: Remap teleop to turtlesim?**  
```bash
ros2 run teleop_cpp_ros2 teleop --ros-args --remap /cmd_vel:=/turtle1/cmd_vel
```

**Q6: Twist axes (x, y, z)?**  
A: **X** forward/back (`linear.x`); **Y** strafe on holonomic robots (`linear.y`); **Z** yaw (`angular.z`).

**Q7: Holonomic vs non-holonomic robots?**  
A: **Holonomic** — move sideways and rotate simultaneously. **Omni wheel** (3×, 90° to travel); **Mecanum wheel** (4×, 45°). Control via **angle** and **amplitude** (speed).

**Q8: When must you run `colcon build`?**  
A: After any change to source code, `CMakeLists.txt`, or `package.xml`.

---

## Lab 3 — Services & parameters

**Q1: Topic vs service vs action — when use service?**  
A: **Topic** = continuous pub/sub stream. **Service** = one-time synchronous request/response (spawn/kill) — **one server only**. **Action** = long async task with feedback.

**Q2: `ros2 service list` vs `ros2 service list -t`?**  
A: List service names / list with **types** included.

**Q3: `ros2 service type /clear`?**  
A: Shows service type (e.g. `std_srvs/srv/Empty`).

**Q4: `ros2 interface show turtlesim/srv/Spawn`?**  
A: Shows request and response fields before calling.

**Q5: Spawn / kill a turtle?**  
```bash
ros2 service call /spawn turtlesim/srv/Spawn "{x: 2, y: 2, theta: 0.2, name: ''}"
ros2 service call /kill turtlesim/srv/Kill "{name: 'turtle1'}"
```

**Q6: Control turtle2 with teleop?**  
```bash
ros2 run turtlesim turtle_teleop_key --ros-args --remap turtle1/cmd_vel:=turtle2/cmd_vel
```

**Q7: Parameters — list / get / set / dump?**  
A: List all params on nodes; read one; change at runtime; save to YAML.

**Q8: Load saved parameters at startup?**  
```bash
ros2 run turtlesim turtlesim_node --ros-args --params-file ./turtlesim.yaml
```

**Q9: What is `rqt` Service Caller used for?**  
A: GUI to call services (e.g. `/turtle1/set_pen`) without typing `ros2 service call`.

---

## Lab 4 — Rosbag & Gazebo

**Rosbag concept:** Records topic traffic to `.db3` files — **live topics** = conversation now; **bag** = recording to replay later.

**Q1: Three main rosbag commands?**  
A: `record`, `play`, `info`.

**Q2: Record multiple topics?**  
```bash
ros2 bag record -o bagfile1 /turtle1/cmd_vel /turtle1/pose
```

**Q3: Replay in a loop?**  
```bash
ros2 bag play -l bagfile1
```
A: `-l` loops forever; robot redraws same path automatically.

**Q4: `ros2 bag info bagfile1`?**  
A: Duration, total messages, count per topic.

**Q5: Why does `/turtle1/pose` have far more messages than `/cmd_vel` in a bag?**  
A: `cmd_vel` only when keys pressed (event-based); `pose` publishes **continuously** at fixed rate even if turtle is still → pose count ≫ cmd_vel count.

**Q6: Which node moves the turtle?**  
A: `turtle_teleop_key` (pub) → `/turtle1/cmd_vel` → `turtlesim_node` (sub).

**Q7: Why remap teleop for Gazebo?**  
A: Teleop publishes `/turtle1/cmd_vel`; Gazebo diff-drive demo listens on `/demo/cmd_demo`.

```
Before remap:  teleop → /turtle1/cmd_vel     Gazebo listens → /demo/cmd_demo  (no link)
After remap:   Keyboard → teleop → /demo/cmd_demo → Gazebo robot → moves
```

**Q8: Gazebo remap + start world?**  
```bash
ros2 run turtlesim turtle_teleop_key --ros-args --remap /turtle1/cmd_vel:=/demo/cmd_demo

gazebo --verbose /opt/ros/humble/share/gazebo_plugins/worlds/gazebo_ros_diff_drive_demo.world
```

**Q9: When demoing bag playback, what does `rqt_graph` show?**  
A: e.g. rosbag player → `/turtle1/cmd_vel` → `/turtlesim` (active pub/sub chain).

---

## Lab 5 — Packages, pub/sub, rosbag (Practical 1)

**Q1: Overlay vs underlay (Lab 5 Task 1)?**  
A: T1 sources overlay → custom compiled turtlesim. T2 sources only underlay → system turtlesim.

**Q2: `rosdep install -i --from-path src --rosdistro humble -y`?**  
A: Installs missing system dependencies for packages in `src/`.

**Q3: Create a C++ package with a node?**  
```bash
ros2 pkg create --build-type ament_cmake --node-name my_node my_package
```

**Q4: Talker topic, nodes, type, frequency?**  
A: Topic `/topic`; nodes `minimal_publisher` / `minimal_subscriber`; type `std_msgs/msg/String`; ~**2 Hz** (500 ms timer).

**Q5: Task 4 — record then demo?**  
Record: `ros2 bag record -o bagtalker /topic` while talker runs.  
Demo: `ros2 bag play -l bagtalker` + listener + `ros2 run rqt_graph rqt_graph` (**no live talker**).

**Q6: Task 5 vs Task 4?**  
A: One bag, **two topics** (`/upcounter` ~2 Hz, `/downcounter` ~1 Hz), **two listeners** (`Countup_Listener`, `Countdown_Listener`).

**Q7: Why must every `.cpp` node appear in `CMakeLists.txt`?**  
A: `add_executable` = build target; `install(TARGETS ...)` = available to `ros2 run`.

**Q8: What files define a ROS 2 package?**  
A: `package.xml` (metadata, dependencies) and `CMakeLists.txt` (build/install rules).

**Q9: Other talker/listener examples in robotics?**  
A: Camera driver (publisher), image display or detector (subscriber).

**Q10: `ros2 pkg executables cpp_pubsub`?**  
A: Lists runnable executables installed for that package.

---

## Exam quick reference

| Question | Answer |
|----------|--------|
| Which node moves the turtle? | `turtle_teleop_key` → `/turtle1/cmd_vel` → `turtlesim_node` |
| What does `ros2 topic echo` do? | Print live messages on a topic |
| What does `ros2 bag record` / `play` do? | Save topic data (`.db3`) / replay recorded data |
| What does `ros2 topic list` do? | List all active topics |
| Why one publisher per topic? | Subscribers can't tell which node sent the message |
| Topic vs service — when service? | One-time action (spawn/kill); no ongoing stream |
| How many servers per service? | **One** server (many clients OK) |
| What is `rqt_graph`? | Visual node–topic graph |
| Clockwise in theta? | **Negative**; anti-clockwise = **positive** |
| Why Gazebo needed remap? | teleop → `/turtle1/cmd_vel` but robot → `/demo/cmd_demo` |
| Keyboard teleop frequency? | Event-based (on key press) |

---

## Flashcards

Q::: What command opens the ROS node/topic graph GUI?
A::: `rqt_graph` or `ros2 run rqt_graph rqt_graph`

Q::: What does `ros2 topic hz /topic` show?
A::: Average publish frequency (Hz) of that topic

Q::: Is `turtle_teleop_key` a publisher or subscriber?
A::: Publisher (publishes to `/turtle1/cmd_vel`)

Q::: Topic vs service — main difference?
A::: Topic = continuous stream (pub/sub); service = one request, one response (one server)

Q::: What is an Action (vs topic/service)?
A::: Long-running async task with goal and feedback

Q::: Why avoid multiple publishers on one topic?
A::: Subscriber can't tell which node sent the message — conflicts possible

Q::: What does `git clone` do? Where to run it?
A::: Copy remote repo locally; run from workspace `src/`

Q::: When must you run `colcon build`?
A::: After changing source code, CMakeLists.txt, or package.xml

Q::: Overlay vs underlay?
A::: Underlay = base ROS install; overlay = your workspace; overlay overrides underlay

Q::: Why does pose have more bag messages than cmd_vel?
A::: pose publishes continuously; cmd_vel only when keys pressed

Q::: Talker topic, type, rate (Lab 5 Task 3)?
A::: `/topic`; `std_msgs/msg/String`; ~2 Hz

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

Q::: Theta = 0 means facing which direction?
A::: East (3 o'clock); π rad = West; + = anti-clockwise

Q::: Holonomic robot?
A::: Can move sideways and rotate simultaneously (omni/mecanum wheels)

Q::: Linear vs angular velocity?
A::: Linear = m/s straight motion; angular = rad/s rotation (yaw = angular.z)

---

## Last-minute summary

**Node** = ROS program · **Topic** = channel · **Publisher** = sends · **Subscriber** = receives · **Service** = one-shot · **Action** = long task

**`/cmd_vel`** = movement command · **teleop** publishes · **turtlesim** subscribes

**`ros2 topic echo`** = view messages · **`ros2 bag record`** = save · **`ros2 bag play`** = replay · **Gazebo** needs topic remap · **`git clone`** in **`src/`** · **`colcon build`** after code changes
