---
id: "d034d061-f083-4482-b5b5-2c3df9283c44"
title: "Ro Choose Ros 2"
type: vault_note
vault: wiki
created: 2026-05-17
updated: 2026-05-17
checksum: "sha256:fce9691976bbf785"
source: heimdall/auto
---

# Ro Choose Ros 2

- ro** → Choose **ROS 2 Humble**
3. Select **Simulation** → Choose **Create from scratch**
4. Enter a project name (e.g. `EGE353`) → Click **CREATE**
5. Click **Run** to launch the rosject

### Interface Overview

| Element | Description |
|---------|-------------|
| Shell / Terminal icon | Opens a new terminal window |
| Code editor icon | Opens the VS Code-style editor |
| Terminal tabs (`#564`, `#570`, etc.) | Multiple shell sessions |

---

## Nodes in ROS2

### Starting TurtleSim

In **Terminal 1**, run:

```bash
source /opt/ros/humble/setup.bash
ros2 run turtlesim turtlesim_node
```

Expected output:
```
[INFO] [turtlesim]: Starting turtlesim with node name /turtlesim
[INFO] [turtlesim]: Spawning turtle [turtle1] at x=[5.544445], y=[5.544445], theta=[0.000000]
```

### Listing Nodes

In **Terminal 2**, run:

```bash
source /opt/ros/humble/setup.bash
ros2 node list
```

Expected output:
```
/turtlesim
```

### Controlling the Turtle (Teleop)

In **Terminal 3**, run:

```bash
ros2 run turtlesim turtle_teleop_key
```

> ⚠️ Make sure you click on Terminal 3 before pressing the arrow keys.

Expected output:
```
Reading from keyboard
---------------------------
Use arrow keys to move the turtle.
Use G|B|V|C|D|E|R|T keys to rotate to absolute orientations. <!-- id:d034d061-f083-4482-b5b5-2c3df9283c44 ts:2026-05-17 07:49 -->
- ro** → Choose **ROS 2 Humble**
3. Select **Simulation** → Choose **Create from scratch**
4. Enter a project name (e.g. `EGE353`) → Click **CREATE**
5. Click **Run** to launch the rosject

### Interface Overview

| Element | Description |
|---------|-------------|
| Shell / Terminal icon | Opens a new terminal window |
| Code editor icon | Opens the VS Code-style editor |
| Terminal tabs (`#564`, `#570`, etc.) | Multiple shell sessions |

---

## Nodes in ROS2

### Starting TurtleSim

In **Terminal 1**, run:

```bash
source /opt/ros/humble/setup.bash
ros2 run turtlesim turtlesim_node
```

Expected output:
```
[INFO] [turtlesim]: Starting turtlesim with node name /turtlesim
[INFO] [turtlesim]: Spawning turtle [turtle1] at x=[5.544445], y=[5.544445], theta=[0.000000]
```

### Listing Nodes

In **Terminal 2**, run:

```bash
source /opt/ros/humble/setup.bash
ros2 node list
```

Expected output:
```
/turtlesim
```

### Controlling the Turtle (Teleop)

In **Terminal 3**, run:

```bash
ros2 run turtlesim turtle_teleop_key
```

> ⚠️ Make sure you click on Terminal 3 before pressing the arrow keys.

Expected output:
```
Reading from keyboard
---------------------------
Use arrow keys to move the turtle.
Use G|B|V|C|D|E|R|T keys to rotate to absolute orientations. <!-- id:d034d061-f083-4482-b5b5-2c3df9283c44 ts:2026-05-17 07:49 -->
