---
type: lab
course: EGE353
module: EGE353-Autonomous-Mobile-Robotics
status: draft
source: manual
created: 2026-06-09
tags: [EGE353, lab6, setup, launch-file, dolly]
---

> **Related:** [[ege353-lab-6-ros-launch-file-slides|Lab 6 full notes + run commands]] | [[EGE353 Lab 2 - ROS Nodes and Topics|Lab 2 remap]]

# EGE353 Lab 6 — Simple setup (no run)

Setup only: workspace, clones, build, files, code. **No** `ros2 run` / `ros2 launch` here — use the full lab note when ready to run Task 2.

---

## Before every build

```bash
# Check distro: ls /opt/ros/
source /opt/ros/foxy/setup.bash
# OR: source /opt/ros/humble/setup.bash
```

---

## Task 1 — Workspace + `ros2_simple_example`

### 1. Create workspace and clone

```bash
mkdir -p ~/launch_ws/src
cd ~/launch_ws/src
git clone https://github.com/Adlink-ROS/ros2_simple_example.git
```

### 2. First build

```bash
source /opt/ros/foxy/setup.bash
cd ~/launch_ws
colcon build
source install/setup.bash
```

### 3. Create launch folder + `talk_listen.launch.py`

```bash
cd ~/launch_ws/src/ros2_simple_example/cpp_pubsub
mkdir -p launch
nano launch/talk_listen.launch.py
```

Paste:

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

Save and exit.

### 4. Edit `CMakeLists.txt`

```bash
nano ~/launch_ws/src/ros2_simple_example/cpp_pubsub/CMakeLists.txt
```

Add at the **bottom**:

```cmake
install(DIRECTORY launch
  DESTINATION share/${PROJECT_NAME})
```

### 5. Rebuild Task 1 package

```bash
source /opt/ros/foxy/setup.bash
cd ~/launch_ws
colcon build
source install/setup.bash
```

Task 1 setup done. (Skip running `talk_listen.launch.py` until you want to test.)

---

## Task 2 — Dolly + teleop + `demo.launch.py`

Uses the same `~/launch_ws`.

### 1. Clone packages

```bash
cd ~/launch_ws/src
git clone https://github.com/1at7/teleop_cpp_ros2.git
git clone https://github.com/chapulina/dolly -b foxy
```

Check:

```bash
ls ~/launch_ws/src
# ros2_simple_example  teleop_cpp_ros2  dolly
```

### 2. Build all packages

```bash
source /opt/ros/foxy/setup.bash
cd ~/launch_ws
colcon build
source install/setup.bash
```

If `dolly_follow` fails with `ament_cmake` not found → you forgot `source /opt/ros/...` before `colcon build`.

### 3. Create launch file path

```bash
mkdir -p ~/launch_ws/src/dolly/dolly_gazebo/launch
nano ~/launch_ws/src/dolly/dolly_gazebo/launch/demo.launch.py
```

### 4. Paste full `demo.launch.py`

```python
import os
from ament_index_python.packages import get_package_share_directory
from launch import LaunchDescription
from launch.actions import DeclareLaunchArgument
from launch.actions import IncludeLaunchDescription
from launch.conditions import IfCondition
from launch.launch_description_sources import PythonLaunchDescriptionSource
from launch.substitutions import LaunchConfiguration
from launch_ros.actions import Node


def generate_launch_description():
    pkg_gazebo_ros = get_package_share_directory('gazebo_ros')
    pkg_dolly_gazebo = get_package_share_directory('dolly_gazebo')
    # Gazebo launch
    gazebo = IncludeLaunchDescription(
        PythonLaunchDescriptionSource(
            os.path.join(pkg_gazebo_ros, 'launch', 'gazebo.launch.py'),
        )
    )
    # RViz
    rviz = Node(
        package='rviz2',
        executable='rviz2',
        arguments=[
            '-d', os.path.join(pkg_dolly_gazebo, 'rviz', 'dolly_gazebo.rviz')],
        condition=IfCondition(LaunchConfiguration('rviz'))
    )
    follow = Node(
        package='dolly_follow',
        executable='dolly_follow',
        output='screen',
        remappings=[
            ('cmd_vel', '/dolly/cmd_vel'),
            ('laser_scan', '/dolly/laser_scan'),
        ],
    )
    return LaunchDescription([
        DeclareLaunchArgument(
            'world',
            default_value=[os.path.join(
                pkg_dolly_gazebo, 'worlds', 'dolly_empty.world'), ''],
            description='SDF world file'),
        DeclareLaunchArgument('rviz', default_value='true',
                              description='Open RViz.'),
        gazebo,
        follow,
        rviz,
    ])
```

Save and exit.

### 5. Rebuild after launch file change

```bash
source /opt/ros/foxy/setup.bash
cd ~/launch_ws
colcon build
source install/setup.bash
```

Task 2 setup done.

---

## Final run — follow-me demo

Your `demo.launch.py` already includes **`dolly_follow`** with remaps. One terminal is enough for the demo.

### Terminal 1 — launch Gazebo + RViz + follow node

```bash
source /opt/ros/foxy/setup.bash
cd ~/launch_ws
source install/setup.bash
ros2 launch dolly_gazebo demo.launch.py world:=dolly_empty.world
```

Wait for Gazebo and RViz to open.

### Demo to instructor

1. In **Gazebo**, insert/move an object (box) in front of the robot.
2. Watch **laser scan** in RViz and the robot **following** the object.
3. **Do not** run teleop at the same time — follow node publishes `/dolly/cmd_vel`.

Stop launch with **Ctrl+C**.

---

### Optional — test keyboard drive first (Terminal 2)

Only if you want to verify teleop **before** using follow-me. **Ctrl+C** teleop before relying on follow node.

```bash
source /opt/ros/foxy/setup.bash
cd ~/launch_ws
source install/setup.bash
ros2 run teleop_cpp_ros2 teleop --ros-args --remap /cmd_vel:=/dolly/cmd_vel
```

---

## Setup checklist

- [ ] `source /opt/ros/foxy/setup.bash` before each `colcon build`
- [ ] Task 1: `ros2_simple_example` cloned + `talk_listen.launch.py` + CMake install
- [ ] Task 2: `teleop_cpp_ros2` + `dolly` (foxy branch) cloned
- [ ] `demo.launch.py` saved with follow node + remappings
- [ ] Final `colcon build` succeeds
- [ ] `source install/setup.bash` before any run (separate doc)
