---
id: "ba791a32-a87d-4a24-8667-3e81b909bd34"
title: "Ho Turtle1Cmd Vel A Ros2 Topic"
type: vault_note
vault: wiki
created: 2026-05-17
updated: 2026-05-17
checksum: "sha256:573ac6474b3b8f36"
source: heimdall/auto
---

# Ho Turtle1Cmd Vel A Ros2 Topic

- ho /turtle1/cmd_vel

**A:** `ros2 topic echo /turtle1/cmd_vel` displays **all messages being published** to the `/turtle1/cmd_vel` topic in real-time. It shows the message content (typically linear and angular velocity values) as they are published, useful for debugging and understanding what data is being sent.

Q6) Write down the line of code in teleop_cpp_ros2.cpp that publish the topic /turtle1/cmd_vel

**A:** The publisher is typically created with:
```cpp
publisher_ = this->create_publisher<geometry_msgs::msg::Twist>("cmd_vel", 10);
```

And the publish call would be:
```cpp
publisher_->publish(msg);
```

*Note: The exact line depends on the specific version of the teleop_cpp_ros2 package. The topic name may need to be changed to `/turtle1/cmd_vel` in the code or remapped at runtime.*

Q7) Where is the x, y and z direction of the on the turtlebot ?

**A:** In ROS2 turtlebot/turtlesim coordinate system:
- **X-axis**: Forward/backward motion (linear velocity in x direction)
- **Y-axis**: Left/right strafing motion (linear velocity in y direction) — only for holonomic robots
- **Z-axis**: Rotation/yaw (angular velocity around z-axis)

For non-holonomic robots like the standard turtlebot:
- **linear.x** controls forward/backward speed
- **angular.z** controls rotation (turning left/right)
- **linear.y** is typically unused (set to 0)

End of briefing for Lab session

---

## Command List (Copy-Paste Ready)

```bash
# ===== SETUP WORKSPACE =====
mkdir lab1b_ws <!-- id:ba791a32-a87d-4a24-8667-3e81b909bd34 ts:2026-05-17 07:49 -->
- ho /turtle1/cmd_vel

**A:** `ros2 topic echo /turtle1/cmd_vel` displays **all messages being published** to the `/turtle1/cmd_vel` topic in real-time. It shows the message content (typically linear and angular velocity values) as they are published, useful for debugging and understanding what data is being sent.

Q6) Write down the line of code in teleop_cpp_ros2.cpp that publish the topic /turtle1/cmd_vel

**A:** The publisher is typically created with:
```cpp
publisher_ = this->create_publisher<geometry_msgs::msg::Twist>("cmd_vel", 10);
```

And the publish call would be:
```cpp
publisher_->publish(msg);
```

*Note: The exact line depends on the specific version of the teleop_cpp_ros2 package. The topic name may need to be changed to `/turtle1/cmd_vel` in the code or remapped at runtime.*

Q7) Where is the x, y and z direction of the on the turtlebot ?

**A:** In ROS2 turtlebot/turtlesim coordinate system:
- **X-axis**: Forward/backward motion (linear velocity in x direction)
- **Y-axis**: Left/right strafing motion (linear velocity in y direction) — only for holonomic robots
- **Z-axis**: Rotation/yaw (angular velocity around z-axis)

For non-holonomic robots like the standard turtlebot:
- **linear.x** controls forward/backward speed
- **angular.z** controls rotation (turning left/right)
- **linear.y** is typically unused (set to 0)

End of briefing for Lab session

---

## Command List (Copy-Paste Ready)

```bash
# ===== SETUP WORKSPACE =====
mkdir lab1b_ws <!-- id:ba791a32-a87d-4a24-8667-3e81b909bd34 ts:2026-05-17 07:49 -->
