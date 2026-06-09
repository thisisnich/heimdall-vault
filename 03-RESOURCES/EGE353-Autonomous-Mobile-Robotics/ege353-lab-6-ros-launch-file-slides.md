---
type: lab
course: EGE353
module: EGE353-Autonomous-Mobile-Robotics
status: draft
source: pdf
created: 2026-06-09
tags: [EGE353, lab, ros2, launch-file, remap, gazebo, dolly]
---

> **Related:** [[EGE353 Lab 2 - ROS Nodes and Topics|Lab 2 — remap (slide 10)]] | [[EGE353 Lab 6 Simple|Lab 6 — setup only (no run)]] | [[EGE353 Lab 3 - ROS Services|Lab 3]] | [[EGE353 Lab 1-5 Q&A|Lab Q&A]] | [[05-KB/concepts/ROS|ROS concept]] | [[07-DASHBOARDS/NYPY3 - Main Index|NYPY3 Index]]

# EGE353 Lab 6 — ROS Launch Files

> [!ingest] source: Lab 6 ROS launch file.pdf | date: 2026-06-09 | tool: markitdown
> Auto-converted. Edit summary below; re-run ingest to replace block above.

**PDF:** `99-ATTACHMENTS/EGE353/Lab 6 ROS launch file.pdf`  
**Instructor:** Chan Kit Wai · Tel: 65500559 · Chan_kit_wai@nyp.edu.sg

## Summary

Lab 6 introduces **ROS 2 launch files** to start multiple nodes (and their configs) with one command instead of many terminals. **Task 1** builds `talk_listen.launch.py` for `cpp_pubsub` talker + listener. **Task 2** launches **Gazebo + RViz** with the **dolly** package, remaps **teleop** to `/dolly/cmd_vel`, then adds a **follow-me** node with remapping inside the launch file. **CLI remap** syntax is from [[EGE353 Lab 2 - ROS Nodes and Topics#Step 4 — Topic Remapping|Lab 2 slide 10]]; this lab adds **remap inside launch files** via `remappings=[...]`.

---

## Why launch files?

| Without launch | With launch |
|----------------|-------------|
| New terminal per node | `ros2 launch <pkg> <file>.launch.py` starts all nodes |
| Re-type `source` + args each time | Args, namespaces, remaps declared once |
| Hard to reproduce system | Share one Python/XML/YAML file |

A launch file is a Python script that returns a `LaunchDescription` listing what to run. Framework: `launch` + `launch_ros`.

**Key function (required):**

```python
def generate_launch_description():
    return LaunchDescription([...])
```

Ref: [ROS 2 Launch system (Foxy)](https://docs.ros.org/en/foxy/Tutorials/Launch/Launch-system.html)

---

## Remapping — two ways

### 1. Command line (Lab 2, slide 10)

When teleop publishes `/cmd_vel` but the robot listens on another topic:

```bash
source install/setup.bash
ros2 run teleop_cpp_ros2 teleop --ros-args --remap /cmd_vel:=/turtle1/cmd_vel
```

**Lab 6 Task 2 answer (Dolly in Gazebo):**

```bash
ros2 run teleop_cpp_ros2 teleop --ros-args --remap /cmd_vel:=/dolly/cmd_vel
```

Use `ros2 topic list` to find the **old** (publisher) and **new** (subscriber) topic names before remapping.

### 2. Inside a launch file (Lab 6, slides ~11–12)

Add `remappings` to a `Node` — tuple is `(current_name, new_name)`:

```python
from launch_ros.actions import Node

talker_node = Node(
    package='demo_nodes_cpp',
    executable='talker',
    name='my_talker',
    remappings=[('talk_topic', 'my_chatter')],
)

listener_node = Node(
    package='demo_nodes_py',
    executable='listener',
    name='my_listener',
    remappings=[('listen_topic', 'my_chatter')],
)
```

Both nodes now share **`my_chatter`** without editing source code.

**Q: Why remap?** So two nodes can communicate on the **same topic name** (answer **1** in slide Q&A). Option 4 (“old topic gets a new name”) is partly true but the **purpose** is inter-node communication.

**Follow-me node in `demo.launch.py`:**

```python
follow = Node(
    package='dolly_follow',
    executable='dolly_follow',
    output='screen',
    remappings=[
        ('cmd_vel', '/dolly/cmd_vel'),
        ('laser_scan', '/dolly/laser_scan'),
    ],
)
```

---

## Task 1 — Simple launch file (`talk_listen.launch.py`)

### Setup workspace

```bash
mkdir -p ~/launch_ws/src
cd ~/launch_ws/src
git clone https://github.com/Adlink-ROS/ros2_simple_example.git
cd ~/launch_ws
colcon build
source install/setup.bash
```

### Before launch file (two terminals)

| Terminal | Command |
|----------|---------|
| 1 | `ros2 run cpp_pubsub talker` |
| 2 | `source install/setup.bash` → `ros2 run cpp_pubsub listener` |

### Create launch file

```bash
cd ~/launch_ws/src/ros2_simple_example/cpp_pubsub
mkdir launch && cd launch
touch talk_listen.launch.py
```

**`talk_listen.launch.py`:**

```python
from launch import LaunchDescription
import launch_ros.actions

def generate_launch_description():
    return LaunchDescription([
        launch_ros.actions.Node(
            package='cpp_pubsub', executable='talker', output='screen'),
        launch_ros.actions.Node(
            package='cpp_pubsub', executable='listener', output='screen'),
    ])
```

> Note: slides use `demo_nodes_cpp`; this lab clones `ros2_simple_example` — package name is **`cpp_pubsub`**.

### Register launch file in `CMakeLists.txt`

Add at bottom of `cpp_pubsub/CMakeLists.txt`:

```cmake
install(DIRECTORY launch
  DESTINATION share/${PROJECT_NAME})
```

### Run launch file

```bash
cd ~/launch_ws
colcon build
source install/setup.bash
ros2 launch cpp_pubsub talk_listen.launch.py
```

Both talker and listener start from one command.

![[99-ATTACHMENTS/EGE353/ege353-lab-6-ros-launch-file/ege353-lab-6-ros-launch-file-p16.png|talk_listen.launch.py structure]]
![[99-ATTACHMENTS/EGE353/ege353-lab-6-ros-launch-file/ege353-lab-6-ros-launch-file-p18.png|ros2 launch output — both nodes running]]

---

## Task 2 — Follow-me robot (Gazebo + Dolly)

### Clone extra packages

```bash
cd ~/launch_ws/src
git clone https://github.com/1at7/teleop_cpp_ros2.git
git clone https://github.com/chapulina/dolly -b foxy
	cd ~/launch_ws
colcon build
source install/setup.bash
```

### Create `demo.launch.py`

```bash
cd ~/launch_ws/src/dolly/dolly_gazebo/launch
touch demo.launch.py
```

Copy full `demo.launch.py` from **Politemall** (Gazebo include, RViz, world arg). Launch:

```bash
cd ~/launch_ws
colcon build
source install/setup.bash
ros2 launch dolly_gazebo demo.launch.py world:=dolly_empty.world
```

Opens **Gazebo** (physics sim) and **RViz** (sensor visualization). Add objects; watch **laser scan** reflections.

### Teleop with remap (Terminal 2)

```bash
source install/setup.bash
ros2 run teleop_cpp_ros2 teleop --ros-args --remap /cmd_vel:=/dolly/cmd_vel
```

### Add follow node to launch file

Edit `demo.launch.py` — add `follow` node with `remappings` (see above), include in `LaunchDescription` after `gazebo`. Rebuild and relaunch; stop teleop — robot follows object via laser scan → `/dolly/cmd_vel`.

![[99-ATTACHMENTS/EGE353/ege353-lab-6-ros-launch-file/ege353-lab-6-ros-launch-file-p27.png|follow node remappings in demo.launch.py]]
![[99-ATTACHMENTS/EGE353/ege353-lab-6-ros-launch-file/ege353-lab-6-ros-launch-file-p28.png|follow-me demo in Gazebo + RViz]]

---

## Lab Q&A (know for quiz)

| Q | Answer |
|---|--------|
| Can you run a ROS node without a launch file? | **Yes** — `ros2 run <pkg> <executable>` |
| Purpose of a launch file? | Start/configure **multiple nodes** (and args, remaps) **at once** |
| Gazebo vs RViz? | **Gazebo** = physics simulation world · **RViz** = visualize sensor data (e.g. laser scan) |
| Function of `dolly_empty.world`? | SDF **world file** — defines Gazebo environment (see [Gazebo virtual worlds](https://nlamprian.me/blog/software/ros/2019/10/06/gazebo-virtual-worlds/)) |
| Demo follow-me to instructor | Robot tracks object using laser + `dolly_follow` |

---

## Command cheat sheet

```bash
# Build & source (every new terminal)
cd ~/launch_ws && colcon build && source install/setup.bash

# Launch file
ros2 launch cpp_pubsub talk_listen.launch.py
ros2 launch dolly_gazebo demo.launch.py world:=dolly_empty.world

# CLI remap (Lab 2) — Dolly variant (Lab 6)
ros2 run teleop_cpp_ros2 teleop --ros-args --remap /cmd_vel:=/dolly/cmd_vel

# Debug topics
ros2 topic list
ros2 topic echo /dolly/cmd_vel
```

---

## Figures (slide reference)

![[99-ATTACHMENTS/EGE353/ege353-lab-6-ros-launch-file/ege353-lab-6-ros-launch-file-p03.png|Intro — why launch files]]
![[99-ATTACHMENTS/EGE353/ege353-lab-6-ros-launch-file/ege353-lab-6-ros-launch-file-p10.png|Remap in launch file — syntax]]
![[99-ATTACHMENTS/EGE353/ege353-lab-6-ros-launch-file/ege353-lab-6-ros-launch-file-p11.png|talker/listener remap example]]
![[99-ATTACHMENTS/EGE353/ege353-lab-6-ros-launch-file/ege353-lab-6-ros-launch-file-p20.png|Task 2 — follow me robot]]
![[99-ATTACHMENTS/EGE353/ege353-lab-6-ros-launch-file/ege353-lab-6-ros-launch-file-p29.png|Demo and Q&A]]

---

## Flashcards

**Q:** Launch a ROS 2 launch file?  
**A:** `ros2 launch <package_name> <file>.launch.py` (optional args e.g. `world:=dolly_empty.world`)

**Q:** Remap topic on CLI?  
**A:** `--ros-args --remap old:=new` — see [[EGE353 Lab 2 - ROS Nodes and Topics|Lab 2]]

**Q:** Remap inside launch file?  
**A:** `remappings=[('old_topic', 'new_topic')]` inside `Node(...)`

**Q:** Teleop → Dolly Gazebo cmd topic?  
**A:** `--remap /cmd_vel:=/dolly/cmd_vel`

---

## Copy-paste runbook (terminal)

Run on your ROS 2 VM (Foxy). **New terminal?** Always `cd ~/launch_ws && source install/setup.bash` first.

---

### Task 1 — talker + listener launch file

**Step 1 — Create workspace and clone (Terminal 1)**

```bash
mkdir -p ~/launch_ws/src
cd ~/launch_ws/src
git clone https://github.com/Adlink-ROS/ros2_simple_example.git
cd ~/launch_ws
colcon build
source install/setup.bash
```

**Step 2 — Optional: run nodes separately first (2 terminals)**

Terminal 1:

```bash
cd ~/launch_ws
source install/setup.bash
ros2 run cpp_pubsub talker
```

Terminal 2:

```bash
cd ~/launch_ws
source install/setup.bash
ros2 run cpp_pubsub listener
```

Stop both with **Ctrl+C** before continuing.

**Step 3 — Create launch folder and file**

```bash
cd ~/launch_ws/src/ros2_simple_example/cpp_pubsub
mkdir -p launch
nano launch/talk_listen.launch.py
```

Paste this, save (**Ctrl+O**, Enter, **Ctrl+X**):

```python
from launch import LaunchDescription
import launch_ros.actions

def generate_launch_description():
    return LaunchDescription([
        launch_ros.actions.Node(
            package='cpp_pubsub', executable='talker', output='screen'),
        launch_ros.actions.Node(
            package='cpp_pubsub', executable='listener', output='screen'),
    ])
```

**Step 4 — Register launch in CMakeLists.txt**

```bash
nano ~/launch_ws/src/ros2_simple_example/cpp_pubsub/CMakeLists.txt
```

Add at the **bottom**:

```cmake
install(DIRECTORY launch
  DESTINATION share/${PROJECT_NAME})
```

**Step 5 — Build and launch**

```bash
cd ~/launch_ws
colcon build
source install/setup.bash
ros2 launch cpp_pubsub talk_listen.launch.py
```

Stop with **Ctrl+C**. You should see both talker and listener output in one terminal.

---

### Task 2 — Dolly Gazebo + teleop remap + follow-me

**Step 1 — Clone teleop + dolly (if not already in workspace)**

```bash
cd ~/launch_ws/src
git clone https://github.com/1at7/teleop_cpp_ros2.git
git clone https://github.com/chapulina/dolly -b foxy
cd ~/launch_ws
colcon build
source install/setup.bash
```

**Step 2 — Create demo launch file**

```bash
mkdir -p ~/launch_ws/src/dolly/dolly_gazebo/launch
touch ~/launch_ws/src/dolly/dolly_gazebo/launch/demo.launch.py
```

Open in editor — copy full `demo.launch.py` from **Politemall**, or build from lab slides. Then **add** the follow node (Step 4) before first full launch if doing follow-me in one go.

**Step 3 — Launch Gazebo + RViz (Terminal 1)**

```bash
cd ~/launch_ws
colcon build
source install/setup.bash
ros2 launch dolly_gazebo demo.launch.py world:=dolly_empty.world
```

Leave running. In Gazebo: add objects, observe laser scan in RViz.

**Step 4 — Teleop with remap (Terminal 2)**

Find topics (optional, Terminal 3):

```bash
cd ~/launch_ws
source install/setup.bash
ros2 topic list
```

Drive robot with keyboard:

```bash
cd ~/launch_ws
source install/setup.bash
ros2 run teleop_cpp_ros2 teleop --ros-args --remap /cmd_vel:=/dolly/cmd_vel
```

Stop teleop with **Ctrl+C** when switching to follow-me mode.

**Step 5 — Add follow node to `demo.launch.py`**

Edit `~/launch_ws/src/dolly/dolly_gazebo/launch/demo.launch.py` — inside `generate_launch_description()`, add:

```python
from launch_ros.actions import Node

    follow = Node(
        package='dolly_follow',
        executable='dolly_follow',
        output='screen',
        remappings=[
            ('cmd_vel', '/dolly/cmd_vel'),
            ('laser_scan', '/dolly/laser_scan'),
        ],
    )
```

Include `follow` in the `return LaunchDescription([...])` list (with `gazebo`, `rviz`, etc.).

**Step 6 — Relaunch with follow-me (Terminal 1)**

```bash
# Ctrl+C to stop old launch first
cd ~/launch_ws
colcon build
source install/setup.bash
ros2 launch dolly_gazebo demo.launch.py world:=dolly_empty.world
```

Move an object in Gazebo — robot should follow via laser scan.

---

### Quick reference — all commands

```bash
# === EVERY NEW TERMINAL ===
cd ~/launch_ws
source install/setup.bash

# === BUILD (after code/launch edits) ===
cd ~/launch_ws
colcon build
source install/setup.bash

# === TASK 1 ===
ros2 run cpp_pubsub talker
ros2 run cpp_pubsub listener
ros2 launch cpp_pubsub talk_listen.launch.py

# === TASK 2 ===
ros2 launch dolly_gazebo demo.launch.py world:=dolly_empty.world
ros2 run teleop_cpp_ros2 teleop --ros-args --remap /cmd_vel:=/dolly/cmd_vel

# === LAB 2 REMAP (turtlesim — slide 10) ===
ros2 run teleop_cpp_ros2 teleop --ros-args --remap /cmd_vel:=/turtle1/cmd_vel

# === DEBUG ===
ros2 topic list
ros2 topic echo /cmd_vel
ros2 topic echo /dolly/cmd_vel
ros2 topic echo /dolly/laser_scan
rqt_graph
```

---

## Troubleshooting

### `Could not find ament_cmake` on `colcon build`

**Cause:** ROS 2 underlay not sourced — CMake cannot find `ament_cmake`.

**Fix — run before every `colcon build`:**

```bash
# Use the distro on YOUR VM (check with: ls /opt/ros/)
source /opt/ros/foxy/setup.bash    # Lab 6 dolly branch is foxy
# OR
source /opt/ros/humble/setup.bash  # if your NYP VM is Humble

cd ~/launch_ws
colcon build
source install/setup.bash
```

**One-liner habit:**

```bash
source /opt/ros/foxy/setup.bash && cd ~/launch_ws && colcon build && source install/setup.bash
```

If only `dolly_follow` fails and other packages were skipped, ensure full clones exist in `~/launch_ws/src/`:

```bash
ls ~/launch_ws/src
# expect: ros2_simple_example  teleop_cpp_ros2  dolly  (and their deps)
```

Rebuild everything the first time:

```bash
source /opt/ros/foxy/setup.bash
cd ~/launch_ws
colcon build
```

---

## Troubleshooting

### `Could not find ament_cmake` on `colcon build`

**Cause:** ROS 2 underlay not sourced — CMake cannot find `ament_cmake`.

**Fix — run before every `colcon build`:**

```bash
# Use the distro on YOUR VM (check with: ls /opt/ros/)
source /opt/ros/foxy/setup.bash    # Lab 6 dolly branch is foxy
# OR
source /opt/ros/humble/setup.bash  # if your NYP VM is Humble

cd ~/launch_ws
colcon build
source install/setup.bash
```

**One-liner habit:**

```bash
source /opt/ros/foxy/setup.bash && cd ~/launch_ws && colcon build && source install/setup.bash
```

If only `dolly_follow` fails and other packages were skipped, ensure full clones exist in `~/launch_ws/src/`:

```bash
ls ~/launch_ws/src
# expect: ros2_simple_example  teleop_cpp_ros2  dolly  (and their deps)
```

Rebuild everything (not just one package) the first time:

```bash
source /opt/ros/foxy/setup.bash
cd ~/launch_ws
colcon build
```
