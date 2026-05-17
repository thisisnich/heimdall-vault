---
id: "cf967f21-6208-43d0-ae26-0b0e3093ef11"
title: "Simsrvkill Name Turtle1 Q2"
type: vault_note
vault: wiki
created: 2026-05-17
updated: 2026-05-17
checksum: "sha256:83e01999cc6c1391"
source: heimdall/auto
---

# Simsrvkill Name Turtle1 Q2

- sim/srv/Kill "{name: 'turtle1'}"
```

**Q2)** Modify the command to spawn at least another 9 turtlesim in different location and orientation as shown. Screenshot your terminal command, Turtlesim display results and fill in the table below.


| Turtle | x | y | theta |
|--------|---|---|-------|
| 3 | 10 | 10 | 3.14/4 |
| 4 | 6 | 1 | 3 |
| 5 | 2 | 7 | 8 |
| 6 | 9 | 13 | 9 |

**Spawn 9 turtles in a circle (45° apart, radius 3.5, pointing outward from center):**
```bash
ros2 service call /spawn turtlesim/srv/Spawn "{x: 9.0, y: 5.5, theta: 0, name: ''}"
ros2 service call /spawn turtlesim/srv/Spawn "{x: 7.97, y: 7.97, theta: 0.785, name: ''}"
ros2 service call /spawn turtlesim/srv/Spawn "{x: 5.5, y: 9.0, theta: 1.571, name: ''}"
ros2 service call /spawn turtlesim/srv/Spawn "{x: 3.03, y: 7.97, theta: 2.356, name: ''}"
ros2 service call /spawn turtlesim/srv/Spawn "{x: 2.0, y: 5.5, theta: 3.142, name: ''}"
ros2 service call /spawn turtlesim/srv/Spawn "{x: 3.03, y: 3.03, theta: 3.927, name: ''}"
ros2 service call /spawn turtlesim/srv/Spawn "{x: 5.5, y: 2.0, theta: 4.712, name: ''}"
ros2 service call /spawn turtlesim/srv/Spawn "{x: 7.97, y: 3.03, theta: 5.498, name: ''}"
ros2 service call /spawn turtlesim/srv/Spawn "{x: 8.5, y: 5.5, theta: 6.283, name: ''}"
```

### TASK 2 - Using RQT to Set Pen

Close all previous terminals and open new terminal windows.

To start turtlesim, enter the following command in your 1st terminal:

```bash
$ ros2 run turtlesim turtlesim_node
```

Open a 2nd <!-- id:cf967f21-6208-43d0-ae26-0b0e3093ef11 ts:2026-05-17 07:49 -->
- sim/srv/Kill "{name: 'turtle1'}"
```

**Q2)** Modify the command to spawn at least another 9 turtlesim in different location and orientation as shown. Screenshot your terminal command, Turtlesim display results and fill in the table below.


| Turtle | x | y | theta |
|--------|---|---|-------|
| 3 | 10 | 10 | 3.14/4 |
| 4 | 6 | 1 | 3 |
| 5 | 2 | 7 | 8 |
| 6 | 9 | 13 | 9 |

**Spawn 9 turtles in a circle (45° apart, radius 3.5, pointing outward from center):**
```bash
ros2 service call /spawn turtlesim/srv/Spawn "{x: 9.0, y: 5.5, theta: 0, name: ''}"
ros2 service call /spawn turtlesim/srv/Spawn "{x: 7.97, y: 7.97, theta: 0.785, name: ''}"
ros2 service call /spawn turtlesim/srv/Spawn "{x: 5.5, y: 9.0, theta: 1.571, name: ''}"
ros2 service call /spawn turtlesim/srv/Spawn "{x: 3.03, y: 7.97, theta: 2.356, name: ''}"
ros2 service call /spawn turtlesim/srv/Spawn "{x: 2.0, y: 5.5, theta: 3.142, name: ''}"
ros2 service call /spawn turtlesim/srv/Spawn "{x: 3.03, y: 3.03, theta: 3.927, name: ''}"
ros2 service call /spawn turtlesim/srv/Spawn "{x: 5.5, y: 2.0, theta: 4.712, name: ''}"
ros2 service call /spawn turtlesim/srv/Spawn "{x: 7.97, y: 3.03, theta: 5.498, name: ''}"
ros2 service call /spawn turtlesim/srv/Spawn "{x: 8.5, y: 5.5, theta: 6.283, name: ''}"
```

### TASK 2 - Using RQT to Set Pen

Close all previous terminals and open new terminal windows.

To start turtlesim, enter the following command in your 1st terminal:

```bash
$ ros2 run turtlesim turtlesim_node
```

Open a 2nd <!-- id:cf967f21-6208-43d0-ae26-0b0e3093ef11 ts:2026-05-17 07:49 -->
