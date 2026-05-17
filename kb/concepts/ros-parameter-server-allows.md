---
id: "27530774-5bb1-4a53-8b3c-5370a1f442cc"
title: "Ros Parameter Server Allows"
type: vault_note
vault: wiki
created: 2026-05-17
updated: 2026-05-17
checksum: "sha256:ba313d6f313f5a78"
source: heimdall/auto
---

# Ros Parameter Server Allows

- ```

ROS parameter server allows you to store and manipulate data. The Parameter Server can store integers, floats, boolean, dictionaries, and lists. ROS parameters use the YAML markup language for syntax. In simple cases, YAML looks very natural: 1 is an integer, 1.0 is a float, one is a string, true is a boolean, [1, 2, 3] is a list of integers, and {a: b, c: d} is a dictionary. ROS has many commands that can be used on parameters, as shown below.

### TASK 3 - ROS Parameters (Optional)

Close all terminals and start a new terminal. Start up the two turtlesim nodes, /turtlesim and /teleop_turtle.

```bash
$ ros2 run turtlesim turtlesim_node
```

Open a 2nd terminal and run the following:

```bash
$ ros2 run turtlesim turtle_teleop_key
```

Open a 3rd terminal and run the following:

```bash
$ ros2 param list
```

Output:
```
/teleop_turtle:
  scale_angular
  scale_linear
  use_sim_time
/turtlesim:
  background_b
  background_g
  background_r
  use_sim_time
```

Take note of the node namespaces, /teleop_turtle and /turtlesim, followed by each node's parameters. <!-- id:27530774-5bb1-4a53-8b3c-5370a1f442cc ts:2026-05-17 07:49 -->
- ```

ROS parameter server allows you to store and manipulate data. The Parameter Server can store integers, floats, boolean, dictionaries, and lists. ROS parameters use the YAML markup language for syntax. In simple cases, YAML looks very natural: 1 is an integer, 1.0 is a float, one is a string, true is a boolean, [1, 2, 3] is a list of integers, and {a: b, c: d} is a dictionary. ROS has many commands that can be used on parameters, as shown below.

### TASK 3 - ROS Parameters (Optional)

Close all terminals and start a new terminal. Start up the two turtlesim nodes, /turtlesim and /teleop_turtle.

```bash
$ ros2 run turtlesim turtlesim_node
```

Open a 2nd terminal and run the following:

```bash
$ ros2 run turtlesim turtle_teleop_key
```

Open a 3rd terminal and run the following:

```bash
$ ros2 param list
```

Output:
```
/teleop_turtle:
  scale_angular
  scale_linear
  use_sim_time
/turtlesim:
  background_b
  background_g
  background_r
  use_sim_time
```

Take note of the node namespaces, /teleop_turtle and /turtlesim, followed by each node's parameters. <!-- id:27530774-5bb1-4a53-8b3c-5370a1f442cc ts:2026-05-17 07:49 -->
