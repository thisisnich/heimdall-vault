---
id: "3ed15b98-488a-493b-b1f9-4eb082d68d81"
title: "Be Prepared To Answer These"
type: vault_note
vault: wiki
created: 2026-05-17
updated: 2026-05-17
checksum: "sha256:4793783a2f75cc56"
source: heimdall/auto
---

# Be Prepared To Answer These

- Be prepared to answer these questions during the demo.

**Q1) Is `turtle_teleop_key` a subscriber or publisher? Explain.**

A1) It is a **Publisher**. From the `rqt_graph`, it publishes to a topic and does not subscribe to any topic.

**Q2) What is the topic that the turtlesim node subscribes to?**

A2) `/turtle1/cmd_vel`

**Q3) Explain the function of `ros2 topic pub <topic_name> <msg_type> '<args>'`**

A3) It publishes a message to a specified topic with a given message type and arguments. For example, `--rate 1` publishes the message once per second continuously.

**Q4) Explain the difference between linear and angular velocity.**

A4) Linear and angular are two different types of motion:
- **Linear motion** is motion in a straight line. Linear speed = Distance / Time (unit: m/s).
- **Angular motion** is the motion of a body about a fixed point or axis, moving along a curved path (unit: rad/s).

The key difference is the path the object follows — straight for linear, curved for angular.

---

## Quick Command Reference

### Setup
```bash
source /opt/ros/humble/setup.bash
```

### Start TurtleSim
```bash
ros2 run turtlesim turtlesim_node
```

### Start Teleop Control
```bash
ros2 run turtlesim turtle_teleop_key
```

### List Commands
```bash
ros2 node list
ros2 topic list
ros2 service list
ros2 action list
```

### Visualize Graph
```bash
rqt_graph
```

### Echo Topic (Monitor Messages)
```bash
ros2 topic echo /turtle1/cmd_vel
ros2 topic echo /turtle1/pose
```

### Publish <!-- id:3ed15b98-488a-493b-b1f9-4eb082d68d81 ts:2026-05-17 07:49 -->
- Be prepared to answer these questions during the demo.

**Q1) Is `turtle_teleop_key` a subscriber or publisher? Explain.**

A1) It is a **Publisher**. From the `rqt_graph`, it publishes to a topic and does not subscribe to any topic.

**Q2) What is the topic that the turtlesim node subscribes to?**

A2) `/turtle1/cmd_vel`

**Q3) Explain the function of `ros2 topic pub <topic_name> <msg_type> '<args>'`**

A3) It publishes a message to a specified topic with a given message type and arguments. For example, `--rate 1` publishes the message once per second continuously.

**Q4) Explain the difference between linear and angular velocity.**

A4) Linear and angular are two different types of motion:
- **Linear motion** is motion in a straight line. Linear speed = Distance / Time (unit: m/s).
- **Angular motion** is the motion of a body about a fixed point or axis, moving along a curved path (unit: rad/s).

The key difference is the path the object follows — straight for linear, curved for angular.

---

## Quick Command Reference

### Setup
```bash
source /opt/ros/humble/setup.bash
```

### Start TurtleSim
```bash
ros2 run turtlesim turtlesim_node
```

### Start Teleop Control
```bash
ros2 run turtlesim turtle_teleop_key
```

### List Commands
```bash
ros2 node list
ros2 topic list
ros2 service list
ros2 action list
```

### Visualize Graph
```bash
rqt_graph
```

### Echo Topic (Monitor Messages)
```bash
ros2 topic echo /turtle1/cmd_vel
ros2 topic echo /turtle1/pose
```

### Publish <!-- id:3ed15b98-488a-493b-b1f9-4eb082d68d81 ts:2026-05-17 07:49 -->
