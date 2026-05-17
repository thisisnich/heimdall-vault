---
id: "3e2c12e7-15a5-4352-afa7-272b87b3d2bc"
title: "S2 Run Turtlesim Turtlesim Node   Ros Args"
type: vault_note
vault: wiki
created: 2026-05-17
updated: 2026-05-17
checksum: "sha256:78112026402c61ef"
source: heimdall/auto
---

# S2 Run Turtlesim Turtlesim Node   Ros Args

- s2 run turtlesim turtlesim_node --ros-args --params-file ./turtlesim.yaml
```

Open a 2nd terminal turtlesim and rerun without loading the parameters. Note what is the difference:

```bash
$ ros2 run turtlesim turtlesim_node
```

Nodes have parameters to define their default configuration values. You can get and set parameter values from the command line. You can also save the parameter settings to a file to reload them in a future session.

---

## Teaching Points Summary

### Topics
- **Publisher-Subscriber Model**: Topics enable continuous data streams where nodes publish information consumed by one or more subscribers
- **Topic Remapping**: Use `--ros-args --remap old_topic:=new_topic` to redirect topic communications (e.g., controlling turtle2 instead of turtle1)
- **Topic Publishing**: Use `ros2 topic pub` to send messages to topics (e.g., `/turtle1/cmd_vel` for velocity control)
- **Topic Listing**: `ros2 topic list` shows all active topics in the ROS graph

### Multiple Turtles
- **Spawning Turtles**: Use `/spawn` service with x, y, theta, and optional name parameters to create new turtles
- **Turtle Names**: Auto-generated (turtle2, turtle3, etc.) if name field is empty
- **Individual Control**: Each turtle has its own topics (`/turtle1/cmd_vel`, `/turtle2/cmd_vel`, etc.) and services (`/turtle1/set_pen`, `/turtle2/set_pen`, etc.)
- **Killing Turtles**: Use `/kill` service to remove specific turtles by name

### ROS Service Call
- **Call-and-Response Model**: Service <!-- id:3e2c12e7-15a5-4352-afa7-272b87b3d2bc ts:2026-05-17 07:49 -->
- s2 run turtlesim turtlesim_node --ros-args --params-file ./turtlesim.yaml
```

Open a 2nd terminal turtlesim and rerun without loading the parameters. Note what is the difference:

```bash
$ ros2 run turtlesim turtlesim_node
```

Nodes have parameters to define their default configuration values. You can get and set parameter values from the command line. You can also save the parameter settings to a file to reload them in a future session.

---

## Teaching Points Summary

### Topics
- **Publisher-Subscriber Model**: Topics enable continuous data streams where nodes publish information consumed by one or more subscribers
- **Topic Remapping**: Use `--ros-args --remap old_topic:=new_topic` to redirect topic communications (e.g., controlling turtle2 instead of turtle1)
- **Topic Publishing**: Use `ros2 topic pub` to send messages to topics (e.g., `/turtle1/cmd_vel` for velocity control)
- **Topic Listing**: `ros2 topic list` shows all active topics in the ROS graph

### Multiple Turtles
- **Spawning Turtles**: Use `/spawn` service with x, y, theta, and optional name parameters to create new turtles
- **Turtle Names**: Auto-generated (turtle2, turtle3, etc.) if name field is empty
- **Individual Control**: Each turtle has its own topics (`/turtle1/cmd_vel`, `/turtle2/cmd_vel`, etc.) and services (`/turtle1/set_pen`, `/turtle2/set_pen`, etc.)
- **Killing Turtles**: Use `/kill` service to remove specific turtles by name

### ROS Service Call
- **Call-and-Response Model**: Service <!-- id:3e2c12e7-15a5-4352-afa7-272b87b3d2bc ts:2026-05-17 07:49 -->
