---
type: lab
course: EGE353
module: EGE353-Autonomous-Mobile-Robotics
status: draft
source: manual
created: 2026-05-22
tags: [EGE353, lab, ros2, package, lab5, guide, practical1]
---

> **Related:** [[EGE353 Lab 5 Notes|Lab 5 Notes]] | [[EGE353 Lab 1-5 Q&A|Q&A]] | [[EGE353 Lab 4 - ROS Bag Files and Gazebo|Lab 4 (rosbag)]] | [[lab-5-ros-package_task5-slides|Task5 PDF notes]] | [[99-ATTACHMENTS/EGE353/Lab 5 ROS package_Task5.pdf|PDF]]

# Lab 5 Package Guide — Step-by-step

Hands-on walkthrough: **what to run**, **what code to paste**, **where it goes**, and **what to show the instructor**.

**Practical 1 (20%)** — Live demo: **Task 4 + Task 5**. Oral questions may still cover Tasks 1–3. Screenshot everything into your Google Doc.

---

## Before you start

Every new terminal:

```bash
source /opt/ros/humble/setup.bash
source ~/dev_ws/install/setup.bash
```

**Concepts from earlier labs you reuse:**

| From | Used in Lab 5 |
|------|----------------|
| [[EGE353 Lab 2 - ROS Nodes and Topics\|Lab 2]] | `git clone`, `colcon build`, `source install/setup.bash`, remap idea |
| [[EGE353 Lab 4 - ROS Bag Files and Gazebo\|Lab 4]] | `ros2 bag record/play/info`, `-l` loop, `rqt_graph` during playback |
| Lab 1 | `ros2 topic hz`, `rqt_graph`, pub/sub mental model |

---

## Final folder layout (after all tasks)

```
~/dev_ws/
├── src/
│   ├── ros_tutorials/          # Task 1 — cloned
│   ├── my_package/             # Task 2
│   └── cpp_pubsub/             # Task 3–5
│       ├── CMakeLists.txt      # ← register every executable here
│       ├── package.xml
│       └── src/
│           ├── publisher_member_function.cpp   # talker
│           ├── subscriber_member_function.cpp  # listener
│           ├── updown_publisher.cpp            # Task 5 record
│           ├── countup_listener.cpp
│           └── countdown_listener.cpp
├── build/  install/  log/
~/bag_files/
├── bagtalker/      # Task 4
└── bagcounters/    # Task 5
```

**Rule:** New `.cpp` file → `add_executable` + `ament_target_dependencies` + name in `install(TARGETS ...)` → `colcon build` → `source install/setup.bash`.

Verify executables:

```bash
ros2 pkg executables cpp_pubsub
```

---

## Task 1 — Workspace + overlay demo

> **Show teacher?** Oral only (overlay vs underlay) — not on live demo list in Task5 PDF, but expect questions.

### Steps

```bash
source /opt/ros/humble/setup.bash
mkdir -p ~/dev_ws/src
cd ~/dev_ws/src
git clone https://github.com/ros/ros_tutorials.git -b humble
cd ~/dev_ws
rosdep install -i --from-path src --rosdistro humble -y
colcon build
source install/local_setup.bash
```

### Code edit — custom turtlesim title

**File:** `~/dev_ws/src/ros_tutorials/turtlesim/src/turtle_frame.cpp`  
**Line ~52:** change to your name:

```cpp
setWindowTitle("Nicholas TurtleSim");
```

### Rebuild and compare two terminals

```bash
# Terminal 1 — overlay (custom title)
cd ~/dev_ws
colcon build
source install/local_setup.bash
ros2 run turtlesim turtlesim_node

# Terminal 2 — underlay only (default title)
source /opt/ros/humble/setup.bash
ros2 run turtlesim turtlesim_node
```

**Explain to teacher:** T1 = your compiled overlay; T2 = system install. Overlay overrides underlay.

---

## Task 2 — Create `my_package`

> **Show teacher?** Oral only (`git clone`, package structure).

```bash
cd ~/dev_ws
source install/local_setup.bash
cd src
ros2 pkg create --build-type ament_cmake --node-name my_node my_package
cd ~/dev_ws
colcon build --packages-select my_package
source install/setup.bash
ros2 run my_package my_node
```

Expected: `hello world my_package package`

**File:** `~/dev_ws/src/my_package/package.xml` — line 6:

```xml
<description>Nicholas Dubs first ros package</description>
```

---

## Task 3 — `cpp_pubsub` talker + listener

> **Show teacher?** Oral (topic name, node names, message type, `ros2 topic hz`) — not live demo in Task5 PDF.

### 3a — Create package and download sources

```bash
cd ~/dev_ws/src
ros2 pkg create --build-type ament_cmake cpp_pubsub
cd cpp_pubsub/src
wget -O publisher_member_function.cpp https://raw.githubusercontent.com/ros2/examples/humble/rclcpp/topics/minimal_publisher/member_function.cpp
wget -O subscriber_member_function.cpp https://raw.githubusercontent.com/ros2/examples/humble/rclcpp/topics/minimal_subscriber/member_function.cpp
```

### 3b — Edit subscriber (add your name)

**File:** `~/dev_ws/src/cpp_pubsub/src/subscriber_member_function.cpp`

In `topic_callback`:

```cpp
RCLCPP_INFO(this->get_logger(), "My name is Nicholas, I heard: '%s'", msg->data.c_str());
```

Key talker facts (for oral):

- Node: `minimal_publisher` / `minimal_subscriber`
- Topic: `/topic`
- Type: `std_msgs/msg/String`
- Rate: **2 Hz** (500 ms timer)

### 3c — `package.xml`

**File:** `~/dev_ws/src/cpp_pubsub/package.xml`

Add dependencies (package level — works reliably):

```xml
  <buildtool_depend>ament_cmake</buildtool_depend>

  <depend>rclcpp</depend>
  <depend>std_msgs</depend>

  <test_depend>ament_lint_auto</test_depend>
  <test_depend>ament_lint_common</test_depend>

  <export>
    <build_type>ament_cmake</build_type>
  </export>
```

Set description to something meaningful (not TODO).

### 3d — `CMakeLists.txt` (talker + listener only at this stage)

**File:** `~/dev_ws/src/cpp_pubsub/CMakeLists.txt`

Paste/replace the executable section with:

```cmake
find_package(rclcpp REQUIRED)
find_package(std_msgs REQUIRED)

add_executable(talker src/publisher_member_function.cpp)
ament_target_dependencies(talker rclcpp std_msgs)

add_executable(listener src/subscriber_member_function.cpp)
ament_target_dependencies(listener rclcpp std_msgs)

install(TARGETS
  talker
  listener
  DESTINATION lib/${PROJECT_NAME})
```

Keep the rest of the file (`cmake_minimum_required`, `project`, standards, `ament_package()`, etc.).

### 3e — Build and test

```bash
cd ~/dev_ws
colcon build --packages-select cpp_pubsub
source install/setup.bash

# Terminal 1
ros2 run cpp_pubsub talker

# Terminal 2
ros2 run cpp_pubsub listener

# Terminal 3 — oral demo
ros2 topic hz /topic
```

---

## Task 4 — Rosbag + listener

> **SHOW TEACHER — required live demo**

Pattern from [[EGE353 Lab 4 - ROS Bag Files and Gazebo#Recording & Playback|Lab 4 record/play]], but topic is `/topic` from your talker.

### Phase A — Record (not shown live; do beforehand)

```bash
mkdir -p ~/bag_files
cd ~/bag_files
source ~/dev_ws/install/setup.bash

# Terminal A
ros2 bag record -o bagtalker /topic

# Terminal B — run ~15 s then Ctrl+C both
ros2 run cpp_pubsub talker
```

Check:

```bash
ros2 bag info bagtalker
```

### Phase B — Live demo (close all terminals first)

| Terminal | Command |
|----------|---------|
| **1** | `cd ~/bag_files` → `ros2 bag play -l bagtalker` |
| **2** | `ros2 run cpp_pubsub listener` |
| **3** | `ros2 run rqt_graph rqt_graph` |

**In rqt_graph:** Nodes/Topics **(active)** → click **Refresh**.

### Screenshot checklist — Task 4

- [ ] Terminal 2: listener printing `Hello, world! 0`, `1`, …
- [ ] `rqt_graph`: bag → `/topic` → listener
- [ ] Optional: `ros2 topic hz /topic` showing ~2 Hz during playback

**Say to teacher:** Bag replaces talker as publisher; listener still subscribes to `/topic`.

---

## Task 5 — Dual-topic bag + two listeners

> **SHOW TEACHER — required live demo**

One publisher node publishes both topics (record phase). Demo uses **bag only** + two listeners — same idea as Task 4 extended.

### 5a — Create `updown_publisher.cpp`

**File:** `~/dev_ws/src/cpp_pubsub/src/updown_publisher.cpp`

```cpp
#include <chrono>
#include <memory>
#include <string>
#include "rclcpp/rclcpp.hpp"
#include "std_msgs/msg/string.hpp"

using namespace std::chrono_literals;

class UpDownPublisher : public rclcpp::Node
{
public:
  UpDownPublisher()
  : Node("updown_publisher"), up_count_(0), down_count_(10)
  {
    up_publisher_ = this->create_publisher<std_msgs::msg::String>("upcounter", 10);
    down_publisher_ = this->create_publisher<std_msgs::msg::String>("downcounter", 10);

    up_timer_ = this->create_wall_timer(
      500ms, std::bind(&UpDownPublisher::up_callback, this));
    down_timer_ = this->create_wall_timer(
      1000ms, std::bind(&UpDownPublisher::down_callback, this));
  }

private:
  void up_callback()
  {
    auto message = std_msgs::msg::String();
    message.data = std::to_string(up_count_++);
    RCLCPP_INFO(this->get_logger(), "Publishing to upcounter: '%s'", message.data.c_str());
    up_publisher_->publish(message);
  }

  void down_callback()
  {
    auto message = std_msgs::msg::String();
    message.data = std::to_string(down_count_--);
    RCLCPP_INFO(this->get_logger(), "Publishing to downcounter: '%s'", message.data.c_str());
    down_publisher_->publish(message);
  }

  rclcpp::Publisher<std_msgs::msg::String>::SharedPtr up_publisher_;
  rclcpp::Publisher<std_msgs::msg::String>::SharedPtr down_publisher_;
  rclcpp::TimerBase::SharedPtr up_timer_;
  rclcpp::TimerBase::SharedPtr down_timer_;
  size_t up_count_;
  int down_count_;
};

int main(int argc, char * argv[])
{
  rclcpp::init(argc, argv);
  rclcpp::spin(std::make_shared<UpDownPublisher>());
  rclcpp::shutdown();
  return 0;
}
```

### 5b — Create `countup_listener.cpp`

**File:** `~/dev_ws/src/cpp_pubsub/src/countup_listener.cpp`

```cpp
#include <memory>
#include "rclcpp/rclcpp.hpp"
#include "std_msgs/msg/string.hpp"

using std::placeholders::_1;

class CountupListener : public rclcpp::Node
{
public:
  CountupListener() : Node("Countup_Listener")
  {
    subscription_ = this->create_subscription<std_msgs::msg::String>(
      "upcounter", 10, std::bind(&CountupListener::topic_callback, this, _1));
  }

private:
  void topic_callback(const std_msgs::msg::String::SharedPtr msg) const
  {
    RCLCPP_INFO(this->get_logger(), "Upcount: '%s'", msg->data.c_str());
  }
  rclcpp::Subscription<std_msgs::msg::String>::SharedPtr subscription_;
};

int main(int argc, char * argv[])
{
  rclcpp::init(argc, argv);
  rclcpp::spin(std::make_shared<CountupListener>());
  rclcpp::shutdown();
  return 0;
}
```

### 5c — Create `countdown_listener.cpp`

**File:** `~/dev_ws/src/cpp_pubsub/src/countdown_listener.cpp`

Same as countup but:

- Node name: `"Countdown_Listener"`
- Topic: `"downcounter"`
- Log: `"Downcount: '%s'"`

### 5d — Update `CMakeLists.txt` (full executable block)

**File:** `~/dev_ws/src/cpp_pubsub/CMakeLists.txt`

```cmake
find_package(rclcpp REQUIRED)
find_package(std_msgs REQUIRED)

add_executable(talker src/publisher_member_function.cpp)
ament_target_dependencies(talker rclcpp std_msgs)

add_executable(listener src/subscriber_member_function.cpp)
ament_target_dependencies(listener rclcpp std_msgs)

add_executable(updown_publisher src/updown_publisher.cpp)
ament_target_dependencies(updown_publisher rclcpp std_msgs)

add_executable(countup_listener src/countup_listener.cpp)
ament_target_dependencies(countup_listener rclcpp std_msgs)

add_executable(countdown_listener src/countdown_listener.cpp)
ament_target_dependencies(countdown_listener rclcpp std_msgs)

install(TARGETS
  talker
  listener
  updown_publisher
  countup_listener
  countdown_listener
  DESTINATION lib/${PROJECT_NAME})
```

```bash
cd ~/dev_ws
colcon build --packages-select cpp_pubsub
source install/setup.bash
ros2 pkg executables cpp_pubsub
```

Must list all five executables before continuing.

### 5e — Record bag (before demo)

```bash
mkdir -p ~/bag_files && cd ~/bag_files
source ~/dev_ws/install/setup.bash

# Terminal A
ros2 bag record -o bagcounters /upcounter /downcounter

# Terminal B — ~15–20 s, then Ctrl+C both
ros2 run cpp_pubsub updown_publisher
```

```bash
ros2 bag info bagcounters
```

Both topics must appear.

### 5f — Live demo (close all terminals; no publisher)

| Terminal | Command |
|----------|---------|
| **1** | `cd ~/bag_files` → `ros2 bag play -l bagcounters` |
| **2** | `ros2 run cpp_pubsub countup_listener` |
| **3** | `ros2 run cpp_pubsub countdown_listener` |
| **4** | `ros2 run rqt_graph rqt_graph` → active → Refresh |

Optional proof terminals:

```bash
ros2 topic hz /upcounter    # ~2 Hz
ros2 topic hz /downcounter  # ~1 Hz
```

### Screenshot checklist — Task 5

- [ ] T2: upcount messages (`0`, `1`, `2`…)
- [ ] T3: downcount messages (`10`, `9`, `8`…)
- [ ] `rqt_graph`: bag → both topics → both listeners
- [ ] `ros2 bag info bagcounters` showing both topics
- [ ] Optional: both `ros2 topic hz` outputs

---

## What to show vs what to explain

### Live demo (must run for instructor)

| Task | Show |
|------|------|
| **Task 4** | `bag play -l bagtalker` + `listener` + `rqt_graph` |
| **Task 5** | `bag play -l bagcounters` + both listeners + `rqt_graph` |

### Oral / screenshots (Google Doc)

| Topic | Prepare to explain |
|-------|-------------------|
| Overlay vs underlay | Task 1 two turtlesim terminals |
| `git clone` | Task 1 / Lab 2 |
| When `colcon build` | After any code/CMake change |
| Talker topic / nodes / type / Hz | `/topic`, `minimal_publisher`, `minimal_subscriber`, `std_msgs/msg/String`, ~2 Hz |
| `ros2 topic hz` | Command + expected rate |
| Talker/listener in real robots | Camera = publisher, display = subscriber |
| Task 5 diagram | Bag publishes 2 topics; each listener only hears its topic |

Full Q&A: [[EGE353 Lab 1-5 Q&A]].

---

## Troubleshooting

| Problem | Fix |
|---------|-----|
| `No executable found` | Missing `add_executable` or not in `install(TARGETS)` → rebuild → source |
| `install TARGETS given target "X" which does not exist` | Listed in `install` but no matching `add_executable` |
| `ros2 pkg executables` missing node | Fix CMakeLists → `colcon build` → `source install/setup.bash` |
| Listener silent during bag demo | Topic name mismatch; forgot `source`; bag recorded empty |
| Build fails after paste | Check filename paths in `add_executable` match `src/` exactly |

---

## One-page demo script (read before instructor)

1. “Task 4: I recorded `/topic` while talker ran. Now only the bag publishes and listener receives.”
2. Start T1 bag play, T2 listener, T3 rqt_graph — refresh — screenshot.
3. “Task 5: Same pattern with two topics at different rates and two listeners.”
4. Start T1 bag play, T2 countup listener, T3 countdown listener, T4 rqt_graph — refresh — screenshot.
5. If asked: overlay = my workspace; underlay = `/opt/ros/humble`; `colcon build` after every code change.
