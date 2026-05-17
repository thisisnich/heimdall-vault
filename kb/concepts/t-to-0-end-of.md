---
id: "cb341421-42b5-4cbb-a524-061e8844c09f"
title: "T To 0 End Of"
type: vault_note
vault: wiki
created: 2026-05-17
updated: 2026-05-17
checksum: "sha256:e676d8e85e99f529"
source: heimdall/auto
---

# T To 0 End Of

- t to 0)

End of briefing for Lab session

---

## Command List (Copy-Paste Ready)

```bash
# ===== SETUP WORKSPACE =====
mkdir lab1b_ws                      # Create workspace directory for this lab
ls                                  # List current directory contents to verify
cd lab1b_ws                         # Change into the workspace directory
mkdir src                           # Create source folder for ROS packages
cd src                              # Change into source folder
git clone https://github.com/1at7/teleop_cpp_ros2.git   # Clone teleop package from GitHub
ls                                  # List cloned package to verify
cd ..                               # Go back to workspace root
colcon build --packages-select teleop_cpp_ros2           # Build only the teleop package
ls                                  # List workspace contents (build/, install/, log/, src/)
source install/setup.bash             # Source the setup script to add package to ROS environment

# ===== RUN TELEOP (Terminal 1) =====
ros2 run teleop_cpp_ros2 teleop      # Launch keyboard teleop node to control robot

# ===== NEW TERMINALS (Shell 2) - Open 4 separate terminals =====
# Terminal 1:
ros2 run turtlesim turtlesim_node    # Launch turtlesim simulator node

# Terminal 2:
ros2 topic list                      # List all active topics in the ROS graph

# Terminal 3:
ros2 topic echo /cmd_vel             # Display all messages published to /cmd_vel topic

# Terminal 4:
rqt_graph <!-- id:cb341421-42b5-4cbb-a524-061e8844c09f ts:2026-05-17 07:49 -->
- t to 0)

End of briefing for Lab session

---

## Command List (Copy-Paste Ready)

```bash
# ===== SETUP WORKSPACE =====
mkdir lab1b_ws                      # Create workspace directory for this lab
ls                                  # List current directory contents to verify
cd lab1b_ws                         # Change into the workspace directory
mkdir src                           # Create source folder for ROS packages
cd src                              # Change into source folder
git clone https://github.com/1at7/teleop_cpp_ros2.git   # Clone teleop package from GitHub
ls                                  # List cloned package to verify
cd ..                               # Go back to workspace root
colcon build --packages-select teleop_cpp_ros2           # Build only the teleop package
ls                                  # List workspace contents (build/, install/, log/, src/)
source install/setup.bash             # Source the setup script to add package to ROS environment

# ===== RUN TELEOP (Terminal 1) =====
ros2 run teleop_cpp_ros2 teleop      # Launch keyboard teleop node to control robot

# ===== NEW TERMINALS (Shell 2) - Open 4 separate terminals =====
# Terminal 1:
ros2 run turtlesim turtlesim_node    # Launch turtlesim simulator node

# Terminal 2:
ros2 topic list                      # List all active topics in the ROS graph

# Terminal 3:
ros2 topic echo /cmd_vel             # Display all messages published to /cmd_vel topic

# Terminal 4:
rqt_graph <!-- id:cb341421-42b5-4cbb-a524-061e8844c09f ts:2026-05-17 07:49 -->
