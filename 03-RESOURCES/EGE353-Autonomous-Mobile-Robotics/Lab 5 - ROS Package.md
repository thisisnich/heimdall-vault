# EGE353 Autonomous Mobile Robotics

Service mobile robots, concepts of path planning, navigation, obstacle avoidance, simultaneous localisation and mapping.

# Lab 5: Create ROS Package

**Practical 1 (20%)**

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

## Create a Workspace

A workspace is a directory containing ROS 2 packages. Before using ROS 2, it's necessary to source your ROS 2 installation workspace in the terminal you plan to work in. This makes ROS 2's packages available for you to use in that terminal.

You also have the option of sourcing an "overlay" – a secondary workspace where you can add new packages without interfering with the existing ROS 2 workspace that you're extending, or "underlay". Your underlay must contain the dependencies of all the packages in your overlay. Packages in your overlay will override packages in the underlay. It's also possible to have several layers of underlays and overlays, with each successive overlay using the packages of its parent underlays.

## Task 1: Create a Workspace and Clone Turtlesim to Local Drive

### Create a Workspace

Start your terminal 1 and source the ros2 environment with the following command in your terminal. You may need to enter this command for each new terminal that you open.

```bash
$ source /opt/ros/humble/setup.bash
```

Create a new directory. For this example, it will be dev_ws. For other workspace it can be for example sensor_ws or robotdog_ws. Ensure you are in the correct directory using the pwd command as shown.

```bash
$ mkdir -p ~/dev_ws/src
$ cd ~/dev_ws/src
$ pwd
/home/user/dev_ws/src
$ ls
```

You will not see any files in the src directory. Ensure you're still in the /home/user/dev_ws/src directory before you clone. For now you will practice putting a workspace together using existing packages to be downloaded from github.com. But in the subsequent labs, you will create your own packages.

```bash
$ git clone https://github.com/ros/ros_tutorials.git -b humble
$ ls
ros_tutorials
```

Now ros_tutorials is cloned in your workspace (/home/mobilerobot/dev_ws/src). The ros_tutorials repository contains the turtlesim package, which we'll use in the rest of this tutorial. The other packages in this repository are not built because they contain a COLCON_IGNORE file. Now you have populated your workspace with a sample package, but it isn't a fully-functional workspace yet. You need to resolve dependencies and build the workspace first.

### Explore and Build

Using code editor/file manager, explore the various files in the ros_tutorial directory.

Before building the workspace, you need to resolve package dependencies. You may have all the dependencies already, but best practice is to check for dependencies every time you clone. You wouldn't want a build to fail after a long wait because of missing dependencies.

```bash
~/dev_ws/src$ cd ..
~/dev_ws$ rosdep install -i --from-path src --rosdistro humble -y
#All required rosdeps installed successfully
```

Using colcon build to generate other new directories. If you encounter errors, repeat colcon build for another 3 to 4 times.

```bash
~/dev_ws$ ls
src
~/dev_ws$ colcon build
…
This may be promoted to an error in a future release of colcon-core.
Starting >>> turtlesim
[Processing: turtlesim]
Finished <<< turtlesim [37.3s]

Summary: 1 package finished [37.4s]
~/dev_ws$ ls
build  install  log  src
```

Using the file manager/code editor, open and explore the file in install/local_setup.bash. Do not edit or save the file. Sourcing the local_setup of the overlay will only add the packages available in the overlay to your environment. Setup sources the overlay as well as the underlay it was created in, allowing you to utilize both workspaces.

So, sourcing your main ROS 2 installation's setup and then the dev_ws overlay's local_setup, like you just did, is the same as just sourcing dev_ws's setup, because that includes the environment of the underlay it was created in.

> **Note:** Do not edit or save the local_setup.bash. Just browse through the content.

### Modify Turtlesim Code

Modify the turtlesim code. Open the file turtle_frame.cpp.

**Modify line 52:** `setWindowTitle("Mr Chan TurtleSim");`

Save the file turtle_frame.cpp. Go back to the 1st terminal and rebuild the files. You need to rebuild each time you modify the source code.

- `source /opt/ros/humble/setup.bash`: Activates the core ROS installation
- `source install/local_setup.bash`: Activates your custom workspace's packages, overlaying them on the core ROS installation

```bash
~/dev_ws$ colcon build
~/dev_ws$ source install/local_setup.bash
~/dev_ws$ ros2 run turtlesim turtlesim_node
```

**Comparison:**
- System turtlesim (install with ros)
- Local turtlesim (source code compiled in dev_ws)

Enlarge and take note that the title is changed to your name i.e Mr Chan's Turtlesim.

### Test System vs Local

Open a 2nd terminal:

```bash
$ source /opt/ros/humble/setup.bash
$ ros2 run turtlesim turtlesim_node
```

Press Ctrl+C on each terminal to stop each process.

## Task 2: Create a ROS2 Package

A package can be considered a container for your ROS 2 code. If you want to be able to install your code or share it with others, then you'll need it organized in a package. With packages, you can release your ROS 2 work and allow others to build and use it easily.

Package creation in ROS 2 uses ament as its build system and colcon as its build tool. You can create a package using either CMake or Python, which are officially supported, though other build types do exist.

**Key files:**
- `package.xml` file containing meta information about the package
- `CMakeLists.txt` file that describes how to build the code within the package

The simplest possible package may have a file structure that looks like:

```
my_package/
     CMakeLists.txt
     package.xml
```

A single workspace can contain as many packages as you want, each in their own folder. You can also have packages of different build types in one workspace (CMake, Python, etc.). You cannot have nested packages.

Best practice is to have a src folder within your workspace, and to create your packages in there. This keeps the top level of the workspace "clean".

### Create a Package

Click on terminal 1 and source your workspace:

```bash
~/dev_ws$ source install/local_setup.bash
```

Make sure you are in the src folder before running the package creation command. You will now have a new folder within your workspace's src directory called my_package.

To create a package use the template: `ros2 pkg create --build-type ament_cmake <package_name>`

```bash
~/dev_ws$ cd src
~/dev_ws/src$ ls
ros_tutorials
~/dev_ws/src$ ros2 pkg create --build-type ament_cmake --node-name my_node my_package
creating folder ./my_package
creating ./my_package/package.xml
creating source and include folder
creating folder ./my_package/src
creating folder ./my_package/include/my_package
creating ./my_package/CMakeLists.txt
creating ./my_package/src/my_node.cpp
~/dev_ws/src$ ls
my_package  ros_tutorials
~/dev_ws/src$ cd ..
~/dev_ws$ colcon build
~/dev_ws$ ls \build
COLCON_IGNORE  my_package  turtlesim
```

If you want to build any particular package only, use `colcon build --packages-select my_package` command.

To use your new package and executable, source your main ROS 2 installation:

```bash
~/dev_ws$ source install/setup.bash
~/dev_ws$ ros2 run my_package my_node
hello world my_package package
```

```bash
~/dev_ws$ ls src/my_package/
CMakeLists.txt  include  package.xml  src
~/dev_ws$ ls src/my_package/src
my_node.cpp
```

`my_node.cpp` is inside the src directory. This is where all your custom C++ nodes will go in the future.

### Customize package.xml

You may have noticed in the return message after creating your package that the fields description and license contain TODO notes. That's because the package description and license declaration are not automatically set, but are required if you ever want to release your package. The maintainer field may also need to be filled in.

From dev_ws/src/my_package, open package.xml using file manager/code editor:

**Modify line 6 and save:** `<description>Nicholas Dubs first ros package</description>`

## Task 3: Create a Publisher and Subscriber Package

```
/topic
talker → Listener
```

### Simple Publisher and Subscriber

#### Write the Publisher Node

Nodes are executable processes that communicate over the ROS graph. In this tutorial, the nodes will pass information in the form of string messages to each other over a topic. The example used here is a simple "talker" and "listener" system; one node publishes data and the other subscribes to the topic so it can receive that data.

You will download publisher_member_function.cpp to src folder.

```bash
~/dev_ws$ cd src
~/dev_ws/src$ ros2 pkg create --build-type ament_cmake cpp_pubsub
…..
creating ./cpp_pubsub/CMakeLists.txt
~/dev_ws/src$ ls
cpp_pubsub  my_package  ros_tutorials
~/dev_ws/src$ cd cpp_pubsub/src
~/dev_ws/src/cpp_pubsub/src$ ls
~/dev_ws/src/cpp_pubsub/src$
~/src$ wget -O publisher_member_function.cpp https://raw.githubusercontent.com/ros2/examples/humble/rclcpp/topics/minimal_publisher/member_function.cpp

…
~/dev_ws/src/cpp_pubsub/src$ ls
publisher_member_function.cpp
```

Open the file publisher_member_function.cpp in IDE.

#### Publisher Code

```cpp
#include <chrono>
#include <memory>
#include "rclcpp/rclcpp.hpp"
#include "std_msgs/msg/string.hpp"

using namespace std::chrono_literals;

class MinimalPublisher : public rclcpp::Node
{
public:
  MinimalPublisher()
  : Node("minimal_publisher"), count_(0)
  {
    publisher_ = this->create_publisher<std_msgs::msg::String>("topic", 10);
    timer_ = this->create_wall_timer(
      500ms, std::bind(&MinimalPublisher::timer_callback, this));
  }
private:
  void timer_callback()
  {
    auto message = std_msgs::msg::String();
    message.data = "Hello, world! " + std::to_string(count_++);
    RCLCPP_INFO(this->get_logger(), "Publishing: '%s'", message.data.c_str());
    publisher_->publish(message);
  }
  rclcpp::TimerBase::SharedPtr timer_;
  rclcpp::Publisher<std_msgs::msg::String>::SharedPtr publisher_;
  size_t count_;
};

int main(int argc, char * argv[])
{
  rclcpp::init(argc, argv);
  rclcpp::spin(std::make_shared<MinimalPublisher>());
  rclcpp::shutdown();
  return 0;
}
```

**Code Explanation:**

The top of the code includes the standard C++ headers you will be using. After the standard C++ headers is the rclcpp/rclcpp.hpp include which allows you to use the most common pieces of the ROS 2 system. Last is std_msgs/msg/string.hpp, which includes the built-in message type you will use to publish data.

These lines represent the node's dependencies. Recall that dependencies have to be added to package.xml and CMakeLists.txt, which you'll do in the next section.

The public constructor names the node minimal_publisher and initializes count_ to 0. Inside the constructor, the publisher is initialized with the String message type, the topic name topic, and the required queue size to limit messages in the event of a backup. Next, timer_ is initialized, which causes the timer_callback function to be executed twice a second.

The timer_callback function is where the message data is set and the messages are actually published. The RCLCPP_INFO macro ensures every published message is printed to the console.

Following the MinimalPublisher class is main, where the node actually executes. rclcpp::init initializes ROS 2, and rclcpp::spin starts processing data from the node, including callbacks from the timer.

#### Update package.xml

Open the file ~/dev_ws/src/cpp_pubsub/package.xml in code editor and add in the dependencies.
Save the file.

```xml
<?xml version="1.0"?>
<?xml-model href="http://download.ros.org/schema/package_format3.xsd" schematypens="http://www.w3.org/2001/XMLSchema"?>
<package format="3">
  <name>cpp_pubsub</name>
  <version>0.0.0</version>
  <description>My first publisher and subscriber</description>
  <maintainer email="mobilerobot@todo.todo">mobilerobot</maintainer>
  <license>TODO: License declaration</license>

  <buildtool_depend>ament_cmake</buildtool_depend>

  <test_depend>ament_lint_auto</test_depend>
  <test_depend>ament_lint_common</test_depend>

  <export>
    <build_type>ament_cmake</build_type>
    <depend>rclcpp</depend>
    <depend>std_msgs</depend>
  </export>
</package>
```

#### Update CMakeLists.txt

Open CMakeLists.txt and add in the required dependency, packages and source files. The file CMakeLists.txt is the input to the CMake build system for building software packages.

```bash
~/dev_ws/src/cpp_pubsub/src$ cd ..
```

Open the file `~/dev_ws/src/cpp_pubsub/CMakeLists.txt` in IDE/code editor, edit and save it.

```cmake
cmake_minimum_required(VERSION 3.5)
project(cpp_pubsub)

# Default to C99
if(NOT CMAKE_C_STANDARD)
  set(CMAKE_C_STANDARD 99)
endif()

# Default to C++14
if(NOT CMAKE_CXX_STANDARD)
  set(CMAKE_CXX_STANDARD 14)
endif()

if(CMAKE_COMPILER_IS_GNUCXX OR CMAKE_CXX_COMPILER_ID MATCHES "Clang")
  add_compile_options(-Wall -Wextra -Wpedantic)
endif()

# find dependencies
find_package(ament_cmake REQUIRED)
find_package(rclcpp REQUIRED)
find_package(std_msgs REQUIRED)

add_executable(talker src/publisher_member_function.cpp)
ament_target_dependencies(talker rclcpp std_msgs)

install(TARGETS
  talker
  DESTINATION lib/${PROJECT_NAME})

if(BUILD_TESTING)
  find_package(ament_lint_auto REQUIRED)
  ament_lint_auto_find_test_dependencies()
endif()

ament_package()
```

#### Write the Subscriber Node

```bash
~/dev_ws/src/cpp_pubsub$ cd src
~/dev_ws/src/cpp_pubsub/src$ ls
publisher_member_function.cpp
~/src$ wget -O subscriber_member_function.cpp https://raw.githubusercontent.com/ros2/examples/humble/rclcpp/topics/minimal_subscriber/member_function.cpp

--2022-02-28 03:59:55--  https://raw.githubusercontent.com/ros2/examples/foxy/rclcpp/topics/minimal_subscriber/member_function.cpp
Resolving raw.githubusercontent.com (raw.githubusercontent.com)... failed: Temporary failure in name resolution.
wget: unable to resolve host address 'raw.githubusercontent.com'
~/dev_ws/src/cpp_pubsub/src$ ls
publisher_member_function.cpp  subscriber_member_function.cpp
~/dev_ws/src/cpp_pubsub/src$ cd ~/dev_ws
```

The subscriber node's code is nearly identical to the publisher's. Now the node is named minimal_subscriber, and the constructor uses the node's create_subscription class to execute the callback.

There is no timer because the subscriber simply responds whenever data is published to the topic.

View the subscriber node, add in your name in the `topic_callback` function and save the file.

```cpp
#include <memory>
#include "rclcpp/rclcpp.hpp"
#include "std_msgs/msg/string.hpp"
using std::placeholders::_1;

class MinimalSubscriber : public rclcpp::Node
{
public:
  MinimalSubscriber()
  : Node("minimal_subscriber")
  {
    subscription_ = this->create_subscription<std_msgs::msg::String>(
      "topic", 10, std::bind(&MinimalSubscriber::topic_callback, this, _1));
  }

private:
  void topic_callback(const std_msgs::msg::String::SharedPtr msg) const
  {
    RCLCPP_INFO(this->get_logger(), "My name is ???, I heard: '%s'", msg->data.c_str());
  }
  rclcpp::Subscription<std_msgs::msg::String>::SharedPtr subscription_;
};

int main(int argc, char * argv[])
{
  rclcpp::init(argc, argv);
  rclcpp::spin(std::make_shared<MinimalSubscriber>());
  rclcpp::shutdown();
  return 0;
}
```

Recall that the topic name and message type used by the publisher and subscriber must match to allow them to communicate.

The topic_callback function receives the string message data published over the topic, and simply writes it to the console using the RCLCPP_INFO macro.

The only field declaration in this class is the subscription.

The main function is exactly the same, except now it spins the MinimalSubscriber node. For the publisher node, spinning meant starting the timer, but for the subscriber it simply means preparing to receive messages whenever they come.

Since this node has the same dependencies as the publisher node, there's nothing new to add to package.xml.

#### Update CMakeLists.txt for Subscriber

Edit CMakeLists.txt to add the listener executable:

```cmake
cmake_minimum_required(VERSION 3.5)
project(cpp_pubsub)

# Default to C99
if(NOT CMAKE_C_STANDARD)
  set(CMAKE_C_STANDARD 99)
endif()

# Default to C++14
if(NOT CMAKE_CXX_STANDARD)
  set(CMAKE_CXX_STANDARD 14)
endif()

if(CMAKE_COMPILER_IS_GNUCXX OR CMAKE_CXX_COMPILER_ID MATCHES "Clang")
  add_compile_options(-Wall -Wextra -Wpedantic)
endif()

# find dependencies
find_package(ament_cmake REQUIRED)
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

#### Build and Run

Use the first terminal to run the talker node which is the publisher.

```bash
~/dev_ws$ colcon build --packages-select cpp_pubsub
Starting >>> cpp_pubsub
Finished <<< cpp_pubsub [0.21s]
Summary: 1 package finished [0.30s]

~/dev_ws$ source install/setup.bash
~/dev_ws$ ros2 run cpp_pubsub talker
[INFO] [1646051316.464444988] [minimal_publisher]: Publishing: 'Hello, world! 0'
[INFO] [1646051316.964443538] [minimal_publisher]: Publishing: 'Hello, world! 1'
```

Open a 2nd terminal for the listener which is the subscriber.

```bash
~/dev_ws$ source install/setup.bash
~/dev_ws$ ros2 run cpp_pubsub listener

[INFO] [1646051746.535122648] [minimal_subscriber]: I heard: 'Hello, world! 0'
[INFO] [1646051747.034727298] [minimal_subscriber]: I heard: 'Hello, world! 1'
```

## Task 4: Create a Rosbag Publisher and Subscriber Package

```
/topic
ros bag → Listener
```

### Practical 1 (20%)

### Rosbag Setup Instructions

**Step 1: Record the topic to a bag file**

First, ensure the talker node is running (from Task 3). Then in a new terminal:

```bash
# Create a directory for bag files
mkdir -p ~/bag_files
cd ~/bag_files

# Record the /topic to a bag file
ros2 bag record -o bagtalker /topic
```

Let it record for about 10-15 seconds, then press Ctrl+C to stop recording.

**Step 2: Verify the bag file**

```bash
# List the contents of the bag file
ros2 bag info bagtalker_0.db3
```

**Step 3: Play back the bag file**

Stop the talker node (Ctrl+C). Then play back the recorded bag:

```bash
# Play the bag file in a loop
ros2 bag play bagtalker_0.db3 --loop
```

**Step 4: Run the listener node**

In a separate terminal, run the listener node to receive the data from the bag playback:

```bash
~/dev_ws$ source install/setup.bash
~/dev_ws$ ros2 run cpp_pubsub listener
```

**Step 5: Visualize with rqt_graph**

In a third terminal:

```bash
ros2 run rqt_graph rqt_graph
```

- Click "node/topic (active)" to see active nodes and topics
- Click the refresh button to update the graph

**Demo the following:**
- Close all previous terminals
- Terminal 1 → run bag file: `ros2 bag play bagtalker_0.db3 --loop`
- Terminal 2 → run listener: `ros2 run cpp_pubsub listener`
- Terminal 3 → `ros2 run rqt_graph rqt_graph` → click node/topic (active) → click refresh button

**Individual work.**

Live demo to instructor is compulsory, questions will be asked during the assessment.

**Demo the following task upon completion:**
- Task 1
- Task 3
- Task 4

Late demo will be subjected to penalty mentioned in the Politemall → module overview

### Practical 1 DEMO Questions (20%)

Be prepared to answer the following:

- Note the difference between running turtlesim from terminal 1 and terminal 2. Explain what is the difference and the reason behind it.
- Explain what is git clone?
- When do you need to run colcon build command?
- What is the name of the topic that the talker is publishing?
- What is the name of the publisher and subscriber node?
- What is the command to view the frequency of the topic, what is the freq?
- What is the message type of the topic?
- Give some other examples of listener and talker node used in robotic system. (i.e. camera sensor is talker node)
- What is the purpose of a rosbag file and how is it used in ROS2?
- What command is used to record a topic to a rosbag file?
- What command is used to play back a rosbag file?
- What is the difference between `source install/local_setup.bash` and `source install/setup.bash`?
- What is the purpose of the package.xml file in a ROS2 package?
- What is the purpose of the CMakeLists.txt file in a ROS2 package?
- What is the difference between a publisher and a subscriber in ROS2?
- What is the role of the `ament_cmake` build system in ROS2?

**Demo to instructor is compulsory.**

Prepare to answer and screenshot your results to a google doc file for lab demo. Questions asked may not be limited to the above questions.

### Sample Answers

1. **Note the difference between running turtlesim from terminal 1 and terminal 2. Explain what is the difference and the reason behind it.**

   Terminal 1 sources the local workspace overlay (`source install/local_setup.bash`) which activates the custom-built turtlesim from dev_ws. Terminal 2 sources only the underlay (`source /opt/ros/humble/setup.bash`) which activates the system-installed turtlesim. The overlay packages override underlay packages when both are sourced, allowing you to test modified code without affecting the system installation.

2. **Explain what is git clone?**

   Git clone is a command that copies a repository from a remote server (like GitHub) to your local machine. It creates a complete copy of the repository including all files, history, and branches, allowing you to work with the code locally.

3. **When do you need to run colcon build command?**

   You need to run `colcon build` when you:
   - Create a new package
   - Modify source code (C++ or Python files)
   - Add new dependencies to package.xml or CMakeLists.txt
   - Make changes to the build configuration

4. **What is the name of the topic that the talker is publishing?**

   The talker publishes to the topic named `/topic`.

5. **What is the name of the publisher and subscriber node?**

   Publisher node: `minimal_publisher`
   Subscriber node: `minimal_subscriber`

6. **What is the command to view the frequency of the topic, what is the freq?**

   Command: `ros2 topic hz /topic`

   The frequency is approximately 2 Hz (publishes every 500ms as set by the timer). The `hz` command measures the rate at which messages are being published on the topic by calculating the average time between consecutive messages. It displays statistics including average rate, standard deviation, min/max rates, and window size.

7. **What is the message type of the topic?**

   The message type is `std_msgs/msg/String`. This is a standard ROS2 message type that contains a single string field called `data`. You can verify this using `ros2 topic info /topic` or `ros2 topic echo /topic` to see the message structure. The String message is defined in the `std_msgs` package, which provides basic primitive message types for ROS2.

8. **Give some other examples of listener and talker node used in robotic system.**

   - Camera sensor (talker) → Image processing node (subscriber)
   - Lidar sensor (talker) → Obstacle avoidance node (subscriber)
   - IMU sensor (talker) → Navigation node (subscriber)
   - Path planner (talker) → Motor controller (subscriber)
   - GPS sensor (talker) → Localization node (subscriber)

9. **What is the purpose of a rosbag file and how is it used in ROS2?**

   A rosbag file records and stores the **messages** published to topics (not the topic itself). Your teacher saying "rosbag records the topic" is a common shorthand - technically, rosbag records the message data flowing through topics. It captures the timestamp, message content, and metadata for each message, allowing you to replay the exact sequence of messages later for testing, debugging, or analysis without needing the original sensors or nodes running.

   **What the teacher means:** When they say "record the topic," they mean "record the messages being published on that topic." It's a convenient way of saying it, but technically you're recording the message stream, not the topic structure itself.

   **Which is right:** Technically, you're right - rosbag records the messages IN the topic. The topic is just a channel/name; the messages are the actual data being recorded. But your teacher's phrasing is commonly used shorthand in the ROS community.

10. **What command is used to record a topic to a rosbag file?**

    `ros2 bag record -o bagname /topic_name`

    **The `-o` flag:** The `-o` (output) flag specifies the prefix/name for the bag file. Without it, rosbag uses a timestamp-based name. With `-o bagtalker`, it creates files like `bagtalker_0.db3`, `bagtalker_0.yaml`, etc. This makes it easier to identify and manage your bag files with meaningful names.

11. **What command is used to play back a rosbag file?**

    `ros2 bag play bagname_0.db3 --loop`

    The `--loop` flag causes the bag to replay continuously until you stop it with Ctrl+C. Without it, the bag plays once and stops when all messages are published.

12. **What is the difference between `source install/local_setup.bash` and `source install/setup.bash`?**

    `source install/setup.bash` sources both the overlay workspace AND the underlay (system ROS2 installation), while `source install/local_setup.bash` sources ONLY the overlay workspace.

    **Files and info difference:**
    - **Using only overlay (local_setup.bash):** Only packages built in your workspace are available. Environment variables point only to your overlay's bin, lib, and share directories. You won't have access to system ROS2 packages unless they're explicitly in your overlay.
    - **Using both overlay and underlay (setup.bash):** Both your workspace packages AND system ROS2 packages are available. Environment variables include paths to both layers. The overlay packages take precedence over underlay packages when there are conflicts.

    **When to use each:** Use `setup.bash` for normal development to ensure all dependencies are available. Use `local_setup.bash` only if you need to test exclusively with your overlay packages without interference from system packages.

13. **What is the purpose of the package.xml file in a ROS2 package?**

    The package.xml file is NOT just for version info - it critically affects functionality. It contains:
    - **Metadata:** Name, version, description, maintainer, license
    - **Dependencies:** Build dependencies (`<build_depend>`, `<buildtool_depend>`), runtime dependencies (`<depend>`, `<exec_depend>`), and test dependencies (`<test_depend>`)
    - **Export information:** Build type and package exports

    **How it affects functionality:**
    - The build system (colcon) reads package.xml to determine what other packages need to be built first
    - It tells CMake which libraries and packages to link against
    - It's used by rosdep to install system dependencies
    - Missing dependencies in package.xml will cause build failures or runtime errors
    - Incorrect dependency declarations can lead to packages not being found during build or execution

14. **What is the purpose of the CMakeLists.txt file in a ROS2 package?**

    The CMakeLists.txt file is the build configuration that defines how to compile and install your package. It contains:

    - **CMake version and project setup:** Minimum CMake version required and project name
    - **C/C++ standards:** Sets C99 and C++14 (or newer) standards
    - **Compiler flags:** Warning flags like `-Wall -Wextra -Wpedantic`
    - **Dependency finding:** `find_package(ament_cmake REQUIRED)`, `find_package(rclcpp REQUIRED)`, etc.
    - **Executable definitions:** `add_executable(talker src/publisher_member_function.cpp)` creates executables from source files
    - **Target dependencies:** `ament_target_dependencies(talker rclcpp std_msgs)` links ROS2 libraries to your executables
    - **Installation rules:** `install(TARGETS ...)` specifies where to install executables
    - **Testing configuration:** Ament lint auto and test dependencies
    - **Package export:** `ament_package()` generates package configuration files

    **Why it matters:** Without proper CMakeLists.txt configuration, your code won't compile, won't link to required libraries, won't be installed correctly, and won't be usable by other packages.

15. **What is the difference between a publisher and a subscriber in ROS2?**

    A publisher sends messages to a topic, while a subscriber receives messages from a topic. Publishers are data producers (sensors, algorithms), and subscribers are data consumers (processing nodes, actuators). They communicate asynchronously through topics.

16. **What is the role of the `ament_cmake` build system in ROS2?**

    ament_cmake is the build system for CMake-based ROS2 packages. It extends CMake with ROS2-specific functionality for finding dependencies, handling Python executables, generating package configuration, and managing the build process in a ROS2 workspace.

---

*End of briefing for Lab session*
