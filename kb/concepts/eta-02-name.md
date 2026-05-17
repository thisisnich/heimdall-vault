---
id: "7d7620f6-da6f-44b5-9bc2-a97cde435a49"
title: "Eta 02 Name"
type: vault_note
vault: wiki
created: 2026-05-17
updated: 2026-05-17
checksum: "sha256:968cfcba622d5a77"
source: heimdall/auto
---

# Eta 02 Name

- eta: 0.2, name: ''}"   # Create second turtle

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

# Compare with default (Terminal 1 - <!-- id:7d7620f6-da6f-44b5-9bc2-a97cde435a49 ts:2026-05-17 07:49 -->
- eta: 0.2, name: ''}"   # Create second turtle

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

# Compare with default (Terminal 1 - <!-- id:7d7620f6-da6f-44b5-9bc2-a97cde435a49 ts:2026-05-17 07:49 -->
