---
id: "1f558c5c-6f78-40d3-99cf-ce62176a6c19"
title: "Terminal Windows To Start Turtlesim"
type: vault_note
vault: wiki
created: 2026-05-17
updated: 2026-05-17
checksum: "sha256:db131197d52956be"
source: heimdall/auto
---

# Terminal Windows To Start Turtlesim

- terminal windows.

To start turtlesim, enter the following command in your 1st terminal:

```bash
$ ros2 run turtlesim turtlesim_node
```

Open a 2nd terminal and run the following:

```bash
$ ros2 run turtlesim turtle_teleop_key
```

Open the 3rd terminal and run the following command to view the service caller:

```bash
$ rqt
```

The service caller can help to set the pen width and the colour of the pen.

Set the turtle1/set_pen parameter to g = 255 and width = 5. Click Call button to send the service to turtlesim. Return to turtle_teleop_key terminal and control the turtlesim to draw any shape. Observe the pen width and colour.

Change the pen width to 10 and pen colour to purple.

Using ros topic pub, publish the cmd_vel to control the turtlesim to draw 2 circles as shown. <!-- id:1f558c5c-6f78-40d3-99cf-ce62176a6c19 ts:2026-05-17 07:49 -->
- terminal windows.

To start turtlesim, enter the following command in your 1st terminal:

```bash
$ ros2 run turtlesim turtlesim_node
```

Open a 2nd terminal and run the following:

```bash
$ ros2 run turtlesim turtle_teleop_key
```

Open the 3rd terminal and run the following command to view the service caller:

```bash
$ rqt
```

The service caller can help to set the pen width and the colour of the pen.

Set the turtle1/set_pen parameter to g = 255 and width = 5. Click Call button to send the service to turtlesim. Return to turtle_teleop_key terminal and control the turtlesim to draw any shape. Observe the pen width and colour.

Change the pen width to 10 and pen colour to purple.

Using ros topic pub, publish the cmd_vel to control the turtlesim to draw 2 circles as shown. <!-- id:1f558c5c-6f78-40d3-99cf-ce62176a6c19 ts:2026-05-17 07:49 -->
