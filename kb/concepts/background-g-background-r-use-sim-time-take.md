---
id: "19f40baa-31db-418b-9199-4df13d320071"
title: "Background G Background R Use Sim Time Take"
type: vault_note
vault: wiki
created: 2026-05-17
updated: 2026-05-17
checksum: "sha256:d387f230f7fa0ab5"
source: heimdall/auto
---

# Background G Background R Use Sim Time Take

- background_g
  background_r
  use_sim_time
```

Take note of the node namespaces, /teleop_turtle and /turtlesim, followed by each node's parameters. Let's find out the current value of /turtlesim's parameter background_g:

```bash
$ ros2 param get /turtlesim background_g
```

Output: `Integer value is: 86`

Set the background red value:

```bash
$ ros2 param set /turtlesim background_r 150
```

Dump all parameters to a file:

```bash
$ ros2 param dump /turtlesim
```

Output: `Saving to: ./turtlesim.yaml`

View the saved file:

```bash
$ cat turtlesim.yaml
```

Output:
```yaml
/turtlesim:
  ros__parameters:
    background_b: 255
    background_g: 86
    background_r: 150
    use_sim_time: false
```

**Q4)** Modify the command to change the turtlesim's background color r=150, b=255, and g=86 to get a purple background. Using parameter get to show the rgb values on the terminal and parameter set to change the turtlesim's background to purple. Screenshot both terminal and simulation as shown.

### Load Parameters

Now, Ctrl+C to stop all processes in each terminal and close all terminals. Start new terminals and load in the parameters using ./turtlesim.yaml file saved earlier.

```bash
ros2 run <package_name> <executable_name> --ros-args --params-file <file_name>

$ ros2 run turtlesim turtlesim_node --ros-args --params-file ./turtlesim.yaml
```

Open a 2nd terminal turtlesim and rerun without loading the parameters. <!-- id:19f40baa-31db-418b-9199-4df13d320071 ts:2026-05-17 07:49 -->
- background_g
  background_r
  use_sim_time
```

Take note of the node namespaces, /teleop_turtle and /turtlesim, followed by each node's parameters. Let's find out the current value of /turtlesim's parameter background_g:

```bash
$ ros2 param get /turtlesim background_g
```

Output: `Integer value is: 86`

Set the background red value:

```bash
$ ros2 param set /turtlesim background_r 150
```

Dump all parameters to a file:

```bash
$ ros2 param dump /turtlesim
```

Output: `Saving to: ./turtlesim.yaml`

View the saved file:

```bash
$ cat turtlesim.yaml
```

Output:
```yaml
/turtlesim:
  ros__parameters:
    background_b: 255
    background_g: 86
    background_r: 150
    use_sim_time: false
```

**Q4)** Modify the command to change the turtlesim's background color r=150, b=255, and g=86 to get a purple background. Using parameter get to show the rgb values on the terminal and parameter set to change the turtlesim's background to purple. Screenshot both terminal and simulation as shown.

### Load Parameters

Now, Ctrl+C to stop all processes in each terminal and close all terminals. Start new terminals and load in the parameters using ./turtlesim.yaml file saved earlier.

```bash
ros2 run <package_name> <executable_name> --ros-args --params-file <file_name>

$ ros2 run turtlesim turtlesim_node --ros-args --params-file ./turtlesim.yaml
```

Open a 2nd terminal turtlesim and rerun without loading the parameters. <!-- id:19f40baa-31db-418b-9199-4df13d320071 ts:2026-05-17 07:49 -->
