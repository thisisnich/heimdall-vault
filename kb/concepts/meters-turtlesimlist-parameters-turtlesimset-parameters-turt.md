---
id: "ccb5d711-5254-42d8-a680-d6b28e5ba1dc"
title: "Meters Turtlesimlist Parameters Turtlesimset Parameters Turt"
type: vault_note
vault: wiki
created: 2026-05-17
updated: 2026-05-17
checksum: "sha256:186821f2276d1828"
source: heimdall/auto
---

# Meters Turtlesimlist Parameters Turtlesimset Parameters Turt

- meters
/turtlesim/list_parameters
/turtlesim/set_parameters
/turtlesim/set_parameters_atomically
```

Let's take a look at turtlesim's /clear service. In the 2nd terminal, enter the command:

```bash
$ ros2 service type /clear
```

Output: `std_srvs/srv/Empty`

Empty type means the service call sends no data when making a request and receives no data when receiving a response.

To see the types of all the active services at the same time, you can append the --show-types option, abbreviated as -t, to the list command:

```bash
$ ros2 service list -t
```

Output:
```
/clear [std_srvs/srv/Empty]
/kill [turtlesim/srv/Kill]
/reset [std_srvs/srv/Empty]
/spawn [turtlesim/srv/Spawn]
...
/turtle1/set_pen [turtlesim/srv/SetPen]
/turtle1/teleport_absolute [turtlesim/srv/TeleportAbsolute]
/turtle1/teleport_relative [turtlesim/srv/TeleportRelative]
...
```

You can find all the Empty typed services like this. In the 2nd terminal, enter the command:

```bash
$ ros2 service find std_srvs/srv/Empty
```

Output:
```
/clear
/reset
```

You can call services from the command line, but first you need to know the structure of the input arguments. To run this command, in the 2nd terminal, enter:

```bash
$ ros2 interface show turtlesim/srv/Spawn
```

Output:
```
float32 x
float32 y
float32 theta
string name # Optional.  A unique name will be created and returned if this is empty
---
string name
```

The information above the --- line tells us the arguments needed to call /spawn. <!-- id:ccb5d711-5254-42d8-a680-d6b28e5ba1dc ts:2026-05-17 07:49 -->
- meters
/turtlesim/list_parameters
/turtlesim/set_parameters
/turtlesim/set_parameters_atomically
```

Let's take a look at turtlesim's /clear service. In the 2nd terminal, enter the command:

```bash
$ ros2 service type /clear
```

Output: `std_srvs/srv/Empty`

Empty type means the service call sends no data when making a request and receives no data when receiving a response.

To see the types of all the active services at the same time, you can append the --show-types option, abbreviated as -t, to the list command:

```bash
$ ros2 service list -t
```

Output:
```
/clear [std_srvs/srv/Empty]
/kill [turtlesim/srv/Kill]
/reset [std_srvs/srv/Empty]
/spawn [turtlesim/srv/Spawn]
...
/turtle1/set_pen [turtlesim/srv/SetPen]
/turtle1/teleport_absolute [turtlesim/srv/TeleportAbsolute]
/turtle1/teleport_relative [turtlesim/srv/TeleportRelative]
...
```

You can find all the Empty typed services like this. In the 2nd terminal, enter the command:

```bash
$ ros2 service find std_srvs/srv/Empty
```

Output:
```
/clear
/reset
```

You can call services from the command line, but first you need to know the structure of the input arguments. To run this command, in the 2nd terminal, enter:

```bash
$ ros2 interface show turtlesim/srv/Spawn
```

Output:
```
float32 x
float32 y
float32 theta
string name # Optional.  A unique name will be created and returned if this is empty
---
string name
```

The information above the --- line tells us the arguments needed to call /spawn. <!-- id:ccb5d711-5254-42d8-a680-d6b28e5ba1dc ts:2026-05-17 07:49 -->
