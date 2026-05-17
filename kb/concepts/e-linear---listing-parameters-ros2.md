---
id: "3bd1d372-40c0-40f7-a7af-b3fea9e73017"
title: "E Linear   Listing Parameters Ros2"
type: vault_note
vault: wiki
created: 2026-05-17
updated: 2026-05-17
checksum: "sha256:44f8648616644ebf"
source: heimdall/auto
---

# E Linear   Listing Parameters Ros2

- e_linear`)
- **Listing Parameters**: `ros2 param list` shows all parameters across nodes
- **Getting Parameters**: `ros2 param get <node_name> <parameter_name>` reads current value
- **Setting Parameters**: `ros2 param set <node_name> <parameter_name> <value>` changes value at runtime
- **Dumping Parameters**: `ros2 param dump <node_name>` exports all parameters to YAML file
- **Loading Parameters**: `ros2 run <package> <executable> --ros-args --params-file <file.yaml>` loads parameters at startup
- **Persistence**: Parameters last only while the node is running unless saved to file

---

## End of Lab Briefing

---

## Command List (Copy-Paste Ready)

```bash
# ===== TASK 1 - Service Call (Open 3 terminals) =====
# Terminal 1 - Start simulator:
ros2 run turtlesim turtlesim_node    # Launch turtlesim node (provides services)

# Terminal 2 - List services:
ros2 service list                    # Show all available services before teleop

# Terminal 3 - Start teleop:
ros2 run turtlesim turtle_teleop_key # Launch keyboard control node

# Back in Terminal 2 - Check new services:
ros2 service list                    # Show services again (now includes teleop_turtle services)

# Terminal 2 - Inspect /clear service:
ros2 service type /clear             # Display the service type (std_srvs/srv/Empty)

# Terminal 2 - List with types:
ros2 service list -t                 # Show all services with their types

# Terminal 2 - Find services by type:
ros2 service find std_srvs/srv/Empty # Fi <!-- id:3bd1d372-40c0-40f7-a7af-b3fea9e73017 ts:2026-05-17 07:49 -->
- e_linear`)
- **Listing Parameters**: `ros2 param list` shows all parameters across nodes
- **Getting Parameters**: `ros2 param get <node_name> <parameter_name>` reads current value
- **Setting Parameters**: `ros2 param set <node_name> <parameter_name> <value>` changes value at runtime
- **Dumping Parameters**: `ros2 param dump <node_name>` exports all parameters to YAML file
- **Loading Parameters**: `ros2 run <package> <executable> --ros-args --params-file <file.yaml>` loads parameters at startup
- **Persistence**: Parameters last only while the node is running unless saved to file

---

## End of Lab Briefing

---

## Command List (Copy-Paste Ready)

```bash
# ===== TASK 1 - Service Call (Open 3 terminals) =====
# Terminal 1 - Start simulator:
ros2 run turtlesim turtlesim_node    # Launch turtlesim node (provides services)

# Terminal 2 - List services:
ros2 service list                    # Show all available services before teleop

# Terminal 3 - Start teleop:
ros2 run turtlesim turtle_teleop_key # Launch keyboard control node

# Back in Terminal 2 - Check new services:
ros2 service list                    # Show services again (now includes teleop_turtle services)

# Terminal 2 - Inspect /clear service:
ros2 service type /clear             # Display the service type (std_srvs/srv/Empty)

# Terminal 2 - List with types:
ros2 service list -t                 # Show all services with their types

# Terminal 2 - Find services by type:
ros2 service find std_srvs/srv/Empty # Fi <!-- id:3bd1d372-40c0-40f7-a7af-b3fea9e73017 ts:2026-05-17 07:49 -->
