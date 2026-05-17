---
id: "6021604d-37d1-450d-a0f1-c95b303b590b"
title: "Service List  T Show"
type: vault_note
vault: wiki
created: 2026-05-17
updated: 2026-05-17
checksum: "sha256:49910864858d5840"
source: heimdall/auto
---

# Service List  T Show

- service list -t                 # Show all services with their types

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
ros2 run turtlesim turtle_teleop_key --ros-args <!-- id:6021604d-37d1-450d-a0f1-c95b303b590b ts:2026-05-17 07:49 -->
- service list -t                 # Show all services with their types

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
ros2 run turtlesim turtle_teleop_key --ros-args <!-- id:6021604d-37d1-450d-a0f1-c95b303b590b ts:2026-05-17 07:49 -->
