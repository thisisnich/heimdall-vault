---
type: lab
course: EGE353
module: EGE353-Autonomous-Mobile-Robotics
status: reviewed
source: pdf
created: 2026-05-19
tags: [EGE353, lab, ros2, package, publisher, subscriber, lab5]
---

> **Related:** [[07-DASHBOARDS/NYPY3 - Main Index|NYPY3 Index]] | [[EGE353 Lab 4 - ROS Bag Files and Gazebo|Lab 4]] | [[EGE353 Lab 5 Demo Study Guide|Demo Study Guide (simple)]] | [[EGE353 Lab 5 Package Guide|Package Guide]] | [[Lab 5 - ROS Package|Lab 5 Slides]] | [[EGE353 Lab 1-5 Q&A|Lab 1–5 Q&A]] | [[07-DASHBOARDS/Schedule & Assessments Dashboard|Assessments]]

> **Lab Materials:** [[Lab 5 - ROS Package.pdf|PDF (original)]] · [[Lab 5 - ROS Package|Markdown]] · [[lab-5-ros-package_task5-slides|Task5 update]] · [[99-ATTACHMENTS/EGE353/Lab 5 ROS package_Task5.pdf|PDF (Task5)]]

# Lab 5: ROS Package Creation

**Instructor:** Chan Kit Wai · Tel: 65500559 · Chan_kit_wai@nyp.edu.sg

**Practical 1 (20%)** — Individual work; live demo to instructor is compulsory (**Tasks 4 and 5** in the Task5 PDF). Late demo subject to penalty. Tasks 1–3 are still lab practice and demo *questions* may cover them.

---

## Overview

- Create ROS2 packages with `ros2 pkg create`
- Understand `package.xml` and `CMakeLists.txt`
- Implement publisher and subscriber nodes in C++
- Build with `colcon`
- Record/replay topics with rosbag

---

## Task 1 — Create Workspace & Clone turtlesim

```bash
source /opt/ros/humble/setup.bash
mkdir -p ~/dev_ws/src
cd ~/dev_ws/src
git clone https://github.com/ros/ros_tutorials.git -b humble
cd ..
rosdep install -i --from-path src --rosdistro humble -y
colcon build
source install/local_setup.bash
```

Modify `turtle_frame.cpp` line 52: `setWindowTitle("Your Name TurtleSim");`

```bash
colcon build
source install/local_setup.bash
ros2 run turtlesim turtlesim_node    # local overlay — custom title
```

Open a **2nd terminal** (only core ROS sourced):

```bash
source /opt/ros/humble/setup.bash
ros2 run turtlesim turtlesim_node    # system turtlesim — default title
```

**Key difference:** Terminal 1 uses your compiled overlay; Terminal 2 uses the system install.

---

## Task 2 — Create a ROS2 Package

```bash
cd ~/dev_ws
source install/local_setup.bash
cd src
ros2 pkg create --build-type ament_cmake --node-name my_node my_package
cd ..
colcon build --packages-select my_package
source install/setup.bash
ros2 run my_package my_node
# Output: hello world my_package package
```

Edit `package.xml` — set `<description>Your full name first ros package</description>`.

**Package structure:**
```
my_package/
├── CMakeLists.txt
├── package.xml
├── include/my_package/
└── src/my_node.cpp
```

---

## Task 3 — Publisher & Subscriber (talker/listener)

### Create package & download source

```bash
cd ~/dev_ws/src
ros2 pkg create --build-type ament_cmake cpp_pubsub
cd cpp_pubsub/src
wget -O publisher_member_function.cpp https://raw.githubusercontent.com/ros2/examples/humble/rclcpp/topics/minimal_publisher/member_function.cpp
wget -O subscriber_member_function.cpp https://raw.githubusercontent.com/ros2/examples/humble/rclcpp/topics/minimal_subscriber/member_function.cpp
```

### Key publisher code

```cpp
publisher_ = this->create_publisher<std_msgs::msg::String>("topic", 10);
timer_ = this->create_wall_timer(500ms, std::bind(&MinimalPublisher::timer_callback, this));
```

- Node name: `minimal_publisher`
- Topic: `topic`
- Message type: `std_msgs/msg/String`
- Publishes every 500 ms

### package.xml dependencies

Add inside `<export>`:
```xml
<depend>rclcpp</depend>
<depend>std_msgs</depend>
```

### CMakeLists.txt

```cmake
find_package(rclcpp REQUIRED)
find_package(std_msgs REQUIRED)
add_executable(talker src/publisher_member_function.cpp)
ament_target_dependencies(talker rclcpp std_msgs)
add_executable(listener src/subscriber_member_function.cpp)
ament_target_dependencies(listener rclcpp std_msgs)
install(TARGETS talker listener DESTINATION lib/${PROJECT_NAME})
```

Edit subscriber callback — add your name in `topic_callback`.

### Build & Run

```bash
cd ~/dev_ws
colcon build --packages-select cpp_pubsub
source install/setup.bash

# Terminal 1
ros2 run cpp_pubsub talker

# Terminal 2
ros2 run cpp_pubsub listener
```

---

## Task 4 — Rosbag with talker/listener

Record the talker topic, then replay with only listener running:

```bash
cd ~/bag_files    # or your bag directory
ros2 bag record -o bagtalker /topic
# Run talker briefly, Ctrl+C to stop recording

# Demo setup:
# Terminal 1: ros2 bag play -l bagtalker
# Terminal 2: ros2 run cpp_pubsub listener
# Terminal 3: ros2 run rqt_graph rqt_graph → refresh active nodes
```

---

## Task 5 — Rosbag with 2 topics and 2 subscribers (new)

Marked *optional* on the slide (“independent/advance learners”), but **required for Practical 1 demo** in the Task5 PDF.

**Goal:** One bag file replays **two topics** at different rates; **two listener nodes** each subscribe to a different topic.

| Topic | Rate | Subscriber node |
|-------|------|-----------------|
| `/upcounter` | 2 Hz | `Countup_Listener` |
| `/downcounter` | 1 Hz | `Countdown_Listener` |

### Step 1 — Add two publishers (record phase only)

In `cpp_pubsub` (or a new package), add nodes that publish `std_msgs/msg/String`:

- **Countup publisher** → topic `/upcounter`, timer **500 ms** (2 Hz), message counts up: `0, 1, 2, …`
- **Countdown publisher** → topic `/downcounter`, timer **1000 ms** (1 Hz), message counts down: `10, 9, 8, …` (pick any start value)

Pattern (same as Task 3 talker — change topic name and timer):

```cpp
publisher_ = this->create_publisher<std_msgs::msg::String>("upcounter", 10);
timer_ = this->create_wall_timer(500ms, std::bind(&CountupPublisher::timer_callback, this));
```

Register both executables in `CMakeLists.txt` and rebuild:

```bash
cd ~/dev_ws
colcon build --packages-select cpp_pubsub
source install/setup.bash
```

### Step 2 — Add two listeners

Clone `subscriber_member_function.cpp` twice:

- `countup_listener.cpp` — subscribe to `"upcounter"`, log e.g. `Countup_Listener heard: …`
- `countdown_listener.cpp` — subscribe to `"downcounter"`, log e.g. `Countdown_Listener heard: …`

Add both to `CMakeLists.txt` `install(TARGETS …)` and rebuild.

### Step 3 — Record both topics into one bag

```bash
mkdir -p ~/bag_files && cd ~/bag_files
source ~/dev_ws/install/setup.bash

# Terminal A — record
ros2 bag record -o bagcounters /upcounter /downcounter

# Terminal B — run both publishers ~15–20 s, then Ctrl+C each
ros2 run cpp_pubsub countup
ros2 run cpp_pubsub countdown   # second terminal

# Stop recording (Ctrl+C on Terminal A)
ros2 bag info bagcounters       # should list both topics
```

### Step 4 — Demo (bag replaces live publishers)

Close all previous terminals. **Do not run the publishers** — only the bag and listeners:

```bash
source ~/dev_ws/install/setup.bash

# Terminal 1
cd ~/bag_files
ros2 bag play -l bagcounters

# Terminal 2
ros2 run cpp_pubsub countup_listener

# Terminal 3
ros2 run cpp_pubsub countdown_listener

# Terminal 4
ros2 run rqt_graph rqt_graph
# → Nodes/Topics (active) → Refresh
```

You should see the bag publishing both topics; each listener prints only its topic. Verify rates with `ros2 topic hz /upcounter` (~2 Hz) and `ros2 topic hz /downcounter` (~1 Hz) in extra terminals during playback.

---

## Practical 1 Demo Questions

Be prepared to answer:

| Question | Hint |
|----------|------|
| Difference running turtlesim from terminal 1 vs 2? | Overlay vs system install |
| What is `git clone`? | Copies remote repo locally |
| When to run `colcon build`? | After any source code change |
| Topic name talker publishes? | `topic` |
| Publisher and subscriber node names? | `minimal_publisher`, `minimal_subscriber` |
| Command to view topic frequency? | `ros2 topic hz /topic` (~2 Hz) |
| Message type? | `std_msgs/msg/String` |
| Other talker/listener examples? | Camera sensor (talker), display node (listener) |

---

## Command List

```bash
source /opt/ros/humble/setup.bash
mkdir -p ~/dev_ws/src && cd ~/dev_ws/src
git clone https://github.com/ros/ros_tutorials.git -b humble
cd .. && rosdep install -i --from-path src --rosdistro humble -y
colcon build && source install/local_setup.bash

ros2 pkg create --build-type ament_cmake --node-name my_node my_package
colcon build --packages-select my_package
source install/setup.bash
ros2 run my_package my_node

ros2 pkg create --build-type ament_cmake cpp_pubsub
colcon build --packages-select cpp_pubsub
source install/setup.bash
ros2 run cpp_pubsub talker
ros2 run cpp_pubsub listener
ros2 topic hz /topic
ros2 bag record -o bagtalker /topic
ros2 bag play -l bagtalker
```
