---
id: "83cb73ee-5f52-4c01-9311-f232c9ff59a2"
title: "Pen Etc   Killing Turtles"
type: vault_note
vault: wiki
created: 2026-05-17
updated: 2026-05-17
checksum: "sha256:f37a40d253b2e968"
source: heimdall/auto
---

# Pen Etc   Killing Turtles

- pen`, etc.)
- **Killing Turtles**: Use `/kill` service to remove specific turtles by name

### ROS Service Call
- **Call-and-Response Model**: Services provide request/response communication vs. topics' one-way streams
- **Service Discovery**: `ros2 service list` shows all available services; `-t` flag shows types
- **Service Types**: `ros2 service type <service_name>` displays the service type (e.g., `std_srvs/srv/Empty`)
- **Finding Services by Type**: `ros2 service find <type>` finds all services of a specific type
- **Interface Inspection**: `ros2 interface show <service_type>` shows request/response structure
- **Calling Services**: `ros2 service call <service_name> <service_type> <arguments>` with YAML syntax for arguments
- **Common Services**:
  - `/spawn` - Create new turtles
  - `/kill` - Delete turtles
  - `/clear` - Clear drawing (Empty type)
  - `/reset` - Reset simulation (Empty type)
  - `/turtleX/set_pen` - Change pen color/width
  - `/turtleX/teleport_absolute` - Teleport to absolute position
  - `/turtleX/teleport_relative` - Teleport relative to current position

### ROS Parameters
- **Node Configuration**: Parameters are node settings stored as integers, floats, booleans, strings, or lists
- **Parameter Namespaces**: Each node maintains its own parameters (e.g., `/turtlesim/background_r`, `/teleop_turtle/scale_linear`)
- **Listing Parameters**: `ros2 param list` shows all parameters across nodes
- **Getting Parameters**: `ros2 param get <node_name> <parame <!-- id:83cb73ee-5f52-4c01-9311-f232c9ff59a2 ts:2026-05-17 07:49 -->
- pen`, etc.)
- **Killing Turtles**: Use `/kill` service to remove specific turtles by name

### ROS Service Call
- **Call-and-Response Model**: Services provide request/response communication vs. topics' one-way streams
- **Service Discovery**: `ros2 service list` shows all available services; `-t` flag shows types
- **Service Types**: `ros2 service type <service_name>` displays the service type (e.g., `std_srvs/srv/Empty`)
- **Finding Services by Type**: `ros2 service find <type>` finds all services of a specific type
- **Interface Inspection**: `ros2 interface show <service_type>` shows request/response structure
- **Calling Services**: `ros2 service call <service_name> <service_type> <arguments>` with YAML syntax for arguments
- **Common Services**:
  - `/spawn` - Create new turtles
  - `/kill` - Delete turtles
  - `/clear` - Clear drawing (Empty type)
  - `/reset` - Reset simulation (Empty type)
  - `/turtleX/set_pen` - Change pen color/width
  - `/turtleX/teleport_absolute` - Teleport to absolute position
  - `/turtleX/teleport_relative` - Teleport relative to current position

### ROS Parameters
- **Node Configuration**: Parameters are node settings stored as integers, floats, booleans, strings, or lists
- **Parameter Namespaces**: Each node maintains its own parameters (e.g., `/turtlesim/background_r`, `/teleop_turtle/scale_linear`)
- **Listing Parameters**: `ros2 param list` shows all parameters across nodes
- **Getting Parameters**: `ros2 param get <node_name> <parame <!-- id:83cb73ee-5f52-4c01-9311-f232c9ff59a2 ts:2026-05-17 07:49 -->
