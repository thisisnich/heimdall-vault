---
id: "c473b778-edfb-47d9-9b78-86bfd369cc82"
title: "Reading From Keyboard"
type: vault_note
vault: wiki
created: 2026-05-17
updated: 2026-05-17
checksum: "sha256:dd9dd50b2e79d826"
source: heimdall/auto
---

# Reading From Keyboard

- ```
Reading from keyboard
---------------------------
Use arrow keys to move the turtle.
Use G|B|V|C|D|E|R|T keys to rotate to absolute orientations. 'F' to cancel a rotation.
'Q' to quit.
```

### Node Architecture

```
teleop_turtle          Topic:              turtlesim
(Publisher Node)  →  /turtle1/cmd_vel  →  (Subscriber Node)
```

- **Node 1 (Subscriber):** `turtlesim_node` — started with `ros2 run turtlesim turtlesim_node`
- **Node 2 (Publisher):** `turtle_teleop_key` — started with `ros2 run turtlesim turtle_teleop_key`

---

## Visualising with rqt_graph

In **Terminal 4**, run:

```bash
rqt_graph
```

`rqt_graph` visualises the active nodes, topics, and connections between them. Click the **refresh** button to update the graph.

The graph shows:
- `/teleop_turtle` publishes keystrokes to `/turtle1/cmd_vel`
- `/turtlesim` subscribes to `/turtle1/cmd_vel` to receive movement data

---

## ROS 2 Commands Reference

Open a new terminal for each command and observe the output:

```bash
ros2 node list
ros2 topic list
ros2 service list
ros2 action list
```

---

## ros2 topic echo

In **Terminal 5**, run:

```bash
ros2 topic echo /turtle1/cmd_vel
```

Move the turtle using `turtle_teleop_key` and observe the output:

```
linear:
  x: 2.0
  y: 0.0
  z: 0.0
angular:
  x: 0.0
  y: 0.0
  z: 0.0
```

---

## ros2 topic pub

Close all existing terminals with `Ctrl+C`, then open new ones.

**Terminal 1:**
```bash
ros2 run turtlesim turtlesim_node
```

**Terminal 2:**
```bash
ros <!-- id:c473b778-edfb-47d9-9b78-86bfd369cc82 ts:2026-05-17 07:49 -->
- ```
Reading from keyboard
---------------------------
Use arrow keys to move the turtle.
Use G|B|V|C|D|E|R|T keys to rotate to absolute orientations. 'F' to cancel a rotation.
'Q' to quit.
```

### Node Architecture

```
teleop_turtle          Topic:              turtlesim
(Publisher Node)  →  /turtle1/cmd_vel  →  (Subscriber Node)
```

- **Node 1 (Subscriber):** `turtlesim_node` — started with `ros2 run turtlesim turtlesim_node`
- **Node 2 (Publisher):** `turtle_teleop_key` — started with `ros2 run turtlesim turtle_teleop_key`

---

## Visualising with rqt_graph

In **Terminal 4**, run:

```bash
rqt_graph
```

`rqt_graph` visualises the active nodes, topics, and connections between them. Click the **refresh** button to update the graph.

The graph shows:
- `/teleop_turtle` publishes keystrokes to `/turtle1/cmd_vel`
- `/turtlesim` subscribes to `/turtle1/cmd_vel` to receive movement data

---

## ROS 2 Commands Reference

Open a new terminal for each command and observe the output:

```bash
ros2 node list
ros2 topic list
ros2 service list
ros2 action list
```

---

## ros2 topic echo

In **Terminal 5**, run:

```bash
ros2 topic echo /turtle1/cmd_vel
```

Move the turtle using `turtle_teleop_key` and observe the output:

```
linear:
  x: 2.0
  y: 0.0
  z: 0.0
angular:
  x: 0.0
  y: 0.0
  z: 0.0
```

---

## ros2 topic pub

Close all existing terminals with `Ctrl+C`, then open new ones.

**Terminal 1:**
```bash
ros2 run turtlesim turtlesim_node
```

**Terminal 2:**
```bash
ros <!-- id:c473b778-edfb-47d9-9b78-86bfd369cc82 ts:2026-05-17 07:49 -->
