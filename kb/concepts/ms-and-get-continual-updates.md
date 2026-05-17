---
id: "1aa12fcc-0ba5-4a46-86be-9dd6df9b5031"
title: "Ms And Get Continual Updates"
type: vault_note
vault: wiki
created: 2026-05-17
updated: 2026-05-17
checksum: "sha256:445a4d25441cce75"
source: heimdall/auto
---

# Ms And Get Continual Updates

- ms and get continual updates, services only provide data when they are specifically called by a client. Nodes can communicate using services in ROS 2. Unlike a topic - a one way communication pattern where a node publishes information that can be consumed by one or more subscribers - a service is a request/response pattern where a client makes a request to a node providing the service and the service processes the request and generates a response.

You generally don't want to use a service for continuous calls; topics or even actions would be better suited.

### TASK 1 - Service Call

To start turtlesim, enter the following command in your new terminal:

```bash
$ ros2 run turtlesim turtlesim_node
```

Open a 2nd terminal and run the following:

```bash
$ ros2 service list
```

Open a 3rd terminal and run the following:

```bash
$ ros2 run turtlesim turtle_teleop_key
```

**Q1)** Rerun the service list again on 2nd terminal. <!-- id:1aa12fcc-0ba5-4a46-86be-9dd6df9b5031 ts:2026-05-17 07:49 -->
- ms and get continual updates, services only provide data when they are specifically called by a client. Nodes can communicate using services in ROS 2. Unlike a topic - a one way communication pattern where a node publishes information that can be consumed by one or more subscribers - a service is a request/response pattern where a client makes a request to a node providing the service and the service processes the request and generates a response.

You generally don't want to use a service for continuous calls; topics or even actions would be better suited.

### TASK 1 - Service Call

To start turtlesim, enter the following command in your new terminal:

```bash
$ ros2 run turtlesim turtlesim_node
```

Open a 2nd terminal and run the following:

```bash
$ ros2 service list
```

Open a 3rd terminal and run the following:

```bash
$ ros2 run turtlesim turtle_teleop_key
```

**Q1)** Rerun the service list again on 2nd terminal. <!-- id:1aa12fcc-0ba5-4a46-86be-9dd6df9b5031 ts:2026-05-17 07:49 -->
