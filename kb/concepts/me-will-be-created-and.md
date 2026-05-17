---
id: "3061dab3-3f14-49fe-9452-e7664f08d578"
title: "Me Will Be Created And"
type: vault_note
vault: wiki
created: 2026-05-17
updated: 2026-05-17
checksum: "sha256:230b7ae174f01a6e"
source: heimdall/auto
---

# Me Will Be Created And

- me will be created and returned if this is empty
---
string name
```

The information above the --- line tells us the arguments needed to call /spawn. x, y and theta determine the location of the spawned turtle, and name is clearly optional. The information below the line isn't something you need to know in this case, but it can help you understand the data type of the response you get from the call.

After knowing what a service type is, how to find a serviceâ€™s type, and how to find the structure of that typeâ€™s arguments, you can call a service using:

```bash
ros2 service call <service_name> <service_type> <arguments>
```

Now letâ€™s spawn a new turtle by calling /spawn and inputting arguments. Input <arguments> in a service call from the command-line need to be in YAML syntax.

```bash
$ ros2 service call /spawn turtlesim/srv/Spawn "{x: 2, y: 2, theta: 0.2, name: ''}"
```

Output:
```
requester: making request: turtlesim.srv.Spawn_Request(x=2.0, y=2.0, theta=0.2, name='')

response:
turtlesim.srv.Spawn_Response(name='turtle2')
```

To kill / delete turtle1, use the following command:

```bash
$ ros2 service call /kill turtlesim/srv/Kill "{name: 'turtle1'}"
```

**Q2)** Modify the command to spawn at least another 9 turtlesim in different location and orientation as shown. <!-- id:3061dab3-3f14-49fe-9452-e7664f08d578 ts:2026-05-17 07:49 -->
- me will be created and returned if this is empty
---
string name
```

The information above the --- line tells us the arguments needed to call /spawn. x, y and theta determine the location of the spawned turtle, and name is clearly optional. The information below the line isn't something you need to know in this case, but it can help you understand the data type of the response you get from the call.

After knowing what a service type is, how to find a serviceâ€™s type, and how to find the structure of that typeâ€™s arguments, you can call a service using:

```bash
ros2 service call <service_name> <service_type> <arguments>
```

Now letâ€™s spawn a new turtle by calling /spawn and inputting arguments. Input <arguments> in a service call from the command-line need to be in YAML syntax.

```bash
$ ros2 service call /spawn turtlesim/srv/Spawn "{x: 2, y: 2, theta: 0.2, name: ''}"
```

Output:
```
requester: making request: turtlesim.srv.Spawn_Request(x=2.0, y=2.0, theta=0.2, name='')

response:
turtlesim.srv.Spawn_Response(name='turtle2')
```

To kill / delete turtle1, use the following command:

```bash
$ ros2 service call /kill turtlesim/srv/Kill "{name: 'turtle1'}"
```

**Q2)** Modify the command to spawn at least another 9 turtlesim in different location and orientation as shown. <!-- id:3061dab3-3f14-49fe-9452-e7664f08d578 ts:2026-05-17 07:49 -->
