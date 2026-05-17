---
id: "d5270829-652a-4cf0-9f7f-f4e80ab8b420"
title: "Raph Bash Rqt Graph"
type: vault_note
vault: wiki
created: 2026-05-17
updated: 2026-05-17
checksum: "sha256:ca4dac0bd02ee074"
source: heimdall/auto
---

# Raph Bash Rqt Graph

- raph
```bash
rqt_graph
```

### Echo Topic (Monitor Messages)
```bash
ros2 topic echo /turtle1/cmd_vel
ros2 topic echo /turtle1/pose
```

### Publish Once
```bash
ros2 topic pub --once /turtle1/cmd_vel geometry_msgs/msg/Twist "{linear: {x: 2.0, y: 0.0, z: 0.0}, angular: {x: 0.0, y: 0.0, z: 1.8}}"
```

### Publish Continuously (1 Hz)
```bash
	ros2 topic pub --rate 1 /turtle1/cmd_vel geometry_msgs/msg/Twist "{linear: {x: 2.0, y: 0.0, z: 0.0}, angular: {x: 0.0, y: 0.0, z: 1.8}}"
```

### Check Topic Frequency
```bash
ros2 topic hz /turtle1/cmd_vel
```

---

*End of Lab 1* <!-- id:d5270829-652a-4cf0-9f7f-f4e80ab8b420 ts:2026-05-17 07:49 -->
- raph
```bash
rqt_graph
```

### Echo Topic (Monitor Messages)
```bash
ros2 topic echo /turtle1/cmd_vel
ros2 topic echo /turtle1/pose
```

### Publish Once
```bash
ros2 topic pub --once /turtle1/cmd_vel geometry_msgs/msg/Twist "{linear: {x: 2.0, y: 0.0, z: 0.0}, angular: {x: 0.0, y: 0.0, z: 1.8}}"
```

### Publish Continuously (1 Hz)
```bash
	ros2 topic pub --rate 1 /turtle1/cmd_vel geometry_msgs/msg/Twist "{linear: {x: 2.0, y: 0.0, z: 0.0}, angular: {x: 0.0, y: 0.0, z: 1.8}}"
```

### Check Topic Frequency
```bash
ros2 topic hz /turtle1/cmd_vel
```

---

*End of Lab 1* <!-- id:d5270829-652a-4cf0-9f7f-f4e80ab8b420 ts:2026-05-17 07:49 -->
