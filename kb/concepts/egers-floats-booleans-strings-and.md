---
id: "11924e3a-fb00-4765-a6dc-3f84b6213d32"
title: "Egers Floats Booleans Strings And"
type: vault_note
vault: wiki
created: 2026-05-17
updated: 2026-05-17
checksum: "sha256:567ab7ff43cdf1b5"
source: heimdall/auto
---

# Egers Floats Booleans Strings And

- egers, floats, booleans, strings, and lists. In ROS 2, each node maintains its own parameters. Parameters in ROS are associated with individual nodes. Parameters are used to configure nodes at startup (and during runtime), without changing the code. The lifetime of a parameter is tied to the lifetime of the node (though the node could implement some sort of persistence to reload values after restart).

Parameters are addressed by node name, node namespace, parameter name, and parameter namespace. Providing a parameter namespace is optional.

Each parameter consists of a key, a value, and a descriptor. The key is a string and the value is one of the following types: bool, int64, float64, string, byte[], bool[], int64[], float64[] or string[]. By default all descriptors are empty, but can contain parameter descriptions, value ranges, type information, and additional constraints.

### rqt_reconfigure for Parameters Settings

*(Note: The following screenshots are for illustration only, you will not be able to view these settings from your rqt as the node is not available to you.)*


**rqt_reconfigure for rgb_camera parameters** - [Screenshot placeholder]


### Change Parameters Settings for Turtlesim

Available turtlesim parameters:
```
/turtlesim:
  background_b
  background_g
  background_r
  use_sim_time
```

ROS parameter server allows you to store and manipulate data. The Parameter Server can store integers, floats, boolean, dictionaries, and lists. <!-- id:11924e3a-fb00-4765-a6dc-3f84b6213d32 ts:2026-05-17 07:49 -->
- egers, floats, booleans, strings, and lists. In ROS 2, each node maintains its own parameters. Parameters in ROS are associated with individual nodes. Parameters are used to configure nodes at startup (and during runtime), without changing the code. The lifetime of a parameter is tied to the lifetime of the node (though the node could implement some sort of persistence to reload values after restart).

Parameters are addressed by node name, node namespace, parameter name, and parameter namespace. Providing a parameter namespace is optional.

Each parameter consists of a key, a value, and a descriptor. The key is a string and the value is one of the following types: bool, int64, float64, string, byte[], bool[], int64[], float64[] or string[]. By default all descriptors are empty, but can contain parameter descriptions, value ranges, type information, and additional constraints.

### rqt_reconfigure for Parameters Settings

*(Note: The following screenshots are for illustration only, you will not be able to view these settings from your rqt as the node is not available to you.)*


**rqt_reconfigure for rgb_camera parameters** - [Screenshot placeholder]


### Change Parameters Settings for Turtlesim

Available turtlesim parameters:
```
/turtlesim:
  background_b
  background_g
  background_r
  use_sim_time
```

ROS parameter server allows you to store and manipulate data. The Parameter Server can store integers, floats, boolean, dictionaries, and lists. <!-- id:11924e3a-fb00-4765-a6dc-3f84b6213d32 ts:2026-05-17 07:49 -->
