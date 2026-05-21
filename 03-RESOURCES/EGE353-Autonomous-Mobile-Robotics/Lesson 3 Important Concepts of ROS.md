---
type: lecture
course: EGE353
module: EGE353-Autonomous-Mobile-Robotics
week: 2
status: reviewed
source: pdf
created: 2026-05-07
tags: [EGE353, lesson-3, ROS, concepts]
---

> **Related:** [[07-DASHBOARDS/NYPY3 - Main Index|NYPY3 Index]] | [[Lesson 2 Robot Operating System ROS|Lesson 2]] | [[EGE353 Lab 2 - ROS Nodes and Topics|Lab 2]] | [[07-DASHBOARDS/Schedule & Assessments Dashboard|Assessments]]

# Lesson 3: Important Concepts of ROS

**Instructor:** Chan Kit Wai · Tel: 65500559 · Chan_kit_wai@nyp.edu.sg

## Synopsis

This module equips learners with knowledge of service robots and their applications, including path planning, navigation, obstacle avoidance, and SLAM.

## Module Learning Outcomes

- Explain features of different sensors and actuators used in autonomous mobile robotics
- Perform analysis of laser and vision sensor data using visualization tools
- Implement mobile robotics systems using mapping, localization, path planning, obstacle avoidance, and motion control

---

## ROS Messages

Nodes communicate by publishing **messages** to **topics**. A message is a typed data structure (primitives, arrays). Example: `String` message on topic `/example`.

---

## ROS Nodes

A **node** is the smallest executable unit in ROS — one program per purpose for reusability.

Mobile robot example — specialized nodes for:
- Sensor drive
- Sensor data conversion
- Obstacle recognition
- Motor drive
- Encoder input
- Navigation

ROS 2 breaks complex systems into modular nodes connected via the topic bus.

---

## ROS Topics

**Publisher-subscriber**, unidirectional, continuous connection.

- Same message type required for publisher and subscriber
- Subscriber connects to publisher via topic name
- Suitable for periodic sensor data
- Multiple publishers ↔ multiple subscribers supported

Example flow:
1. IR sensor → publishes distance (m)
2. Compute unit → processes data
3. Motor control → subscribes to commands

### Publisher
Transmits messages on a topic. Registers with master; can declare multiple publishers per node.

### Subscriber
Receives messages on a topic. Registers with master, connects to matching publisher. Can declare multiple subscribers per node.

---

## ROS Services

**Bidirectional synchronous** communication — request/response pattern.

| | Topics | Services |
|---|--------|----------|
| Pattern | Async pub/sub | Sync request/response |
| Connection | Continuous | One-time, then disconnects |
| Use case | Periodic data | Specific actions/commands |

Components:
- **Service server** — responds to requests
- **Service client** — sends requests, receives responses

Example: client requests current time → server responds → connection terminates.

---

## ROS Actions

For **long-running goals** with progress feedback.

| Service | Action |
|---------|--------|
| Request / Response | Goal / Result + **Feedback** |
| Synchronous | Asynchronous (like a new thread) |
| Short tasks | Complex tasks (e.g. home cleaning with progress updates) |

Actions support **cancellation** mid-operation — services do not.

**Rule of thumb:**
- **Service** — program waits for result before continuing
- **Action** — program continues while action runs in background

---

## ROS Parameters

Configuration values associated with individual nodes. Set at startup or runtime without code changes.

- Addressed by: node name, namespace, parameter name
- Types: bool, int64, float64, string, byte[], and arrays
- Similar to `.ini` config files in Windows
- Can be modified in real-time externally (USB port, camera correction, speed limits)

Parameters are not strictly message communication but use messages internally.

---

## ROS Packages

Software organized in packages — the atomic unit of build and release.

A package contains:
- ROS nodes, libraries, datasets, config files, third-party software
- Must have `package.xml`; built with colcon/ament

### Typical Package Structure

```
my_package/
├── CMakeLists.txt
├── package.xml
├── include/package_name/    # C++ headers
├── msg/                     # Message types
├── srv/                     # Service types
├── src/                     # Source files
└── scripts/                 # Executable scripts
```

- ~2,500 official packages (ROS Indigo era); thousands more from community
- Packages can depend on other packages; workspace holds multiple packages

---

## Communication Summary

| Method | Pattern | Best for |
|--------|---------|----------|
| **Topic** | Async pub/sub | Continuous sensor streams |
| **Service** | Sync request/response | One-off commands |
| **Action** | Async goal/feedback/result | Long tasks with progress |
| **Parameter** | Key-value config | Runtime node settings |

---

*End of Lesson 3*
