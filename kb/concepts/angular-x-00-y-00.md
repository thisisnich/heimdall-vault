---
id: "f3273188-e8cd-45d0-9d94-56900919bcbd"
title: "Angular X 00 Y 00"
type: vault_note
vault: wiki
created: 2026-05-17
updated: 2026-05-17
checksum: "sha256:daea67c43a3bd5ea"
source: heimdall/auto
---

# Angular X 00 Y 00

- angular: {x: 0.0, y: 0.0, z: 1.8}}"
```

> The `--rate 1` flag publishes continuously at 1 message per second (vs `--once` which publishes only once). The turtle will move in a circle continuously.

---

## ros2 topic echo — Pose

```bash
ros2 topic echo /turtle1/pose
```

Run alongside the publisher above and observe `linear_velocity` and `angular_velocity`.

**Exercises:**
- Change linear x to `4.0` and angular z to `5.8` — observe the changes
- Change linear x to `1.0` and angular z to `0.8` — observe the changes

---

## ros2 topic hz

Publish command velocity in one terminal:
```bash
ros2 topic pub --rate 1 /turtle1/cmd_vel geometry_msgs/msg/Twist \
"{linear: {x: 2.0, y: 0.0, z: 0.0}, angular: {x: 0.0, y: 0.0, z: 1.8}}"
```

In a new terminal, check the publish rate:
```bash
ros2 topic hz /turtle1/cmd_vel
```

Expected output:
```
average rate: 1.000
    min: 0.998s max: 1.001s std dev: 0.00065s window: 22
```

**Exercise:** Modify the command so the average rate is `2.0` (2 times per second).

Press `Ctrl+C` to stop each process when done.

---

## Demo Questions

> Be prepared to answer these questions during the demo.

**Q1) Is `turtle_teleop_key` a subscriber or publisher? Explain.**

A1) It is a **Publisher**. <!-- id:f3273188-e8cd-45d0-9d94-56900919bcbd ts:2026-05-17 07:49 -->
- angular: {x: 0.0, y: 0.0, z: 1.8}}"
```

> The `--rate 1` flag publishes continuously at 1 message per second (vs `--once` which publishes only once). The turtle will move in a circle continuously.

---

## ros2 topic echo — Pose

```bash
ros2 topic echo /turtle1/pose
```

Run alongside the publisher above and observe `linear_velocity` and `angular_velocity`.

**Exercises:**
- Change linear x to `4.0` and angular z to `5.8` — observe the changes
- Change linear x to `1.0` and angular z to `0.8` — observe the changes

---

## ros2 topic hz

Publish command velocity in one terminal:
```bash
ros2 topic pub --rate 1 /turtle1/cmd_vel geometry_msgs/msg/Twist \
"{linear: {x: 2.0, y: 0.0, z: 0.0}, angular: {x: 0.0, y: 0.0, z: 1.8}}"
```

In a new terminal, check the publish rate:
```bash
ros2 topic hz /turtle1/cmd_vel
```

Expected output:
```
average rate: 1.000
    min: 0.998s max: 1.001s std dev: 0.00065s window: 22
```

**Exercise:** Modify the command so the average rate is `2.0` (2 times per second).

Press `Ctrl+C` to stop each process when done.

---

## Demo Questions

> Be prepared to answer these questions during the demo.

**Q1) Is `turtle_teleop_key` a subscriber or publisher? Explain.**

A1) It is a **Publisher**. <!-- id:f3273188-e8cd-45d0-9d94-56900919bcbd ts:2026-05-17 07:49 -->
