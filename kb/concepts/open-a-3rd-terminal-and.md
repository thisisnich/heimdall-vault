---
id: "689e8370-7ac7-40b5-afdd-aea3d9d69fd8"
title: "Open A 3Rd Terminal And"
type: vault_note
vault: wiki
created: 2026-05-17
updated: 2026-05-17
checksum: "sha256:7d8de688bf4fcd0c"
source: heimdall/auto
---

# Open A 3Rd Terminal And

- Open a 3rd terminal and run the following:

```bash
$ ros2 run turtlesim turtle_teleop_key
```

**Q1)** Rerun the service list again on 2nd terminal. Note the difference between the results before and after the turtle_telop_key is run:

```bash
$ ros2 service list
```

Output:
```
/reset
/spawn
/teleop_turtle/describe_parameters
/teleop_turtle/get_parameter_types
/teleop_turtle/get_parameters
/teleop_turtle/list_parameters
/teleop_turtle/set_parameters
/teleop_turtle/set_parameters_atomically
/turtle1/set_pen
/turtle1/teleport_absolute
/turtle1/teleport_relative
/turtlesim/describe_parameters
/turtlesim/get_parameter_types
/turtlesim/get_parameters
/turtlesim/list_parameters
/turtlesim/set_parameters
/turtlesim/set_parameters_atomically
```

Let's take a look at turtlesim's /clear service. <!-- id:689e8370-7ac7-40b5-afdd-aea3d9d69fd8 ts:2026-05-17 07:49 -->
- Open a 3rd terminal and run the following:

```bash
$ ros2 run turtlesim turtle_teleop_key
```

**Q1)** Rerun the service list again on 2nd terminal. Note the difference between the results before and after the turtle_telop_key is run:

```bash
$ ros2 service list
```

Output:
```
/reset
/spawn
/teleop_turtle/describe_parameters
/teleop_turtle/get_parameter_types
/teleop_turtle/get_parameters
/teleop_turtle/list_parameters
/teleop_turtle/set_parameters
/teleop_turtle/set_parameters_atomically
/turtle1/set_pen
/turtle1/teleport_absolute
/turtle1/teleport_relative
/turtlesim/describe_parameters
/turtlesim/get_parameter_types
/turtlesim/get_parameters
/turtlesim/list_parameters
/turtlesim/set_parameters
/turtlesim/set_parameters_atomically
```

Let's take a look at turtlesim's /clear service. <!-- id:689e8370-7ac7-40b5-afdd-aea3d9d69fd8 ts:2026-05-17 07:49 -->
