---
id: "4811b80a-950f-457e-935f-75ff69a90438"
title: "N The Ros Graph"
type: vault_note
vault: wiki
created: 2026-05-17
updated: 2026-05-17
checksum: "sha256:2e363b064c5c7cbd"
source: heimdall/auto
---

# N The Ros Graph

- n the ROS graph

# Terminal 3:
ros2 topic echo /cmd_vel             # Display all messages published to /cmd_vel topic

# Terminal 4:
rqt_graph                            # Open visual tool to see node/topic connections

# ===== REMAPPED TELEOP (After Ctrl+C to kill first teleop) =====
source install/setup.bash             # Re-source environment in new terminal
ros2 run teleop_cpp_ros2 teleop --ros args --remap /cmd_vel:=/turtle1/cmd_vel   # Launch teleop with topic remapping so it publishes to /turtle1/cmd_vel instead of /cmd_vel
``` <!-- id:4811b80a-950f-457e-935f-75ff69a90438 ts:2026-05-17 07:49 -->
- n the ROS graph

# Terminal 3:
ros2 topic echo /cmd_vel             # Display all messages published to /cmd_vel topic

# Terminal 4:
rqt_graph                            # Open visual tool to see node/topic connections

# ===== REMAPPED TELEOP (After Ctrl+C to kill first teleop) =====
source install/setup.bash             # Re-source environment in new terminal
ros2 run teleop_cpp_ros2 teleop --ros args --remap /cmd_vel:=/turtle1/cmd_vel   # Launch teleop with topic remapping so it publishes to /turtle1/cmd_vel instead of /cmd_vel
``` <!-- id:4811b80a-950f-457e-935f-75ff69a90438 ts:2026-05-17 07:49 -->
