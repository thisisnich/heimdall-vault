---
id: "e689aa43-306a-4389-8b2f-d1fbc23cc908"
title: "All Existing Terminals With Ctrlc"
type: vault_note
vault: wiki
created: 2026-05-17
updated: 2026-05-17
checksum: "sha256:52e4c45ba72b7b17"
source: heimdall/auto
---

# All Existing Terminals With Ctrlc

- all existing terminals with `Ctrl+C`, then open new ones.

**Terminal 1:**
```bash
ros2 run turtlesim turtlesim_node
```

**Terminal 2:**
```bash
ros2 run turtlesim turtle_teleop_key
```

**Terminal 3** — publish a single message:
```bash
ros2 topic pub --once /turtle1/cmd_vel geometry_msgs/msg/Twist \
"{linear: {x: 2.0, y: 0.0, z: 0.0}, angular: {x: 0.0, y: 0.0, z: 1.8}}"
```

Expected output:
```
publisher: beginning loop
publishing #1: geometry_msgs.msg.Twist(linear=geometry_msgs.msg.Vector3(x=2.0, y=0.0, z=0.0), angular=geometry_msgs.msg.Vector3(x=0.0, y=0.0, z=1.8))
```

**Syntax:**
```bash
ros2 topic pub <topic_name> <msg_type> '<args>'
```

- **Linear speed** = Distance / Time — unit: m/s
- **Angular speed** — unit: radians/second (rad/s)

### Continuous Publishing

```bash
ros2 topic pub --rate 1 /turtle1/cmd_vel geometry_msgs/msg/Twist \
"{linear: {x: 2.0, y: 0.0, z: 0.0}, angular: {x: 0.0, y: 0.0, z: 1.8}}"
```

> The `--rate 1` flag publishes continuously at 1 message per second (vs `--once` which publishes only once). <!-- id:e689aa43-306a-4389-8b2f-d1fbc23cc908 ts:2026-05-17 07:49 -->
- all existing terminals with `Ctrl+C`, then open new ones.

**Terminal 1:**
```bash
ros2 run turtlesim turtlesim_node
```

**Terminal 2:**
```bash
ros2 run turtlesim turtle_teleop_key
```

**Terminal 3** — publish a single message:
```bash
ros2 topic pub --once /turtle1/cmd_vel geometry_msgs/msg/Twist \
"{linear: {x: 2.0, y: 0.0, z: 0.0}, angular: {x: 0.0, y: 0.0, z: 1.8}}"
```

Expected output:
```
publisher: beginning loop
publishing #1: geometry_msgs.msg.Twist(linear=geometry_msgs.msg.Vector3(x=2.0, y=0.0, z=0.0), angular=geometry_msgs.msg.Vector3(x=0.0, y=0.0, z=1.8))
```

**Syntax:**
```bash
ros2 topic pub <topic_name> <msg_type> '<args>'
```

- **Linear speed** = Distance / Time — unit: m/s
- **Angular speed** — unit: radians/second (rad/s)

### Continuous Publishing

```bash
ros2 topic pub --rate 1 /turtle1/cmd_vel geometry_msgs/msg/Twist \
"{linear: {x: 2.0, y: 0.0, z: 0.0}, angular: {x: 0.0, y: 0.0, z: 1.8}}"
```

> The `--rate 1` flag publishes continuously at 1 message per second (vs `--once` which publishes only once). <!-- id:e689aa43-306a-4389-8b2f-d1fbc23cc908 ts:2026-05-17 07:49 -->
