---
type: lab
course: EGE353
module: EGE353-Autonomous-Mobile-Robotics
status: draft
source: manual
created: 2026-05-23
tags: [EGE353, lab, ros2, lab5, practical1, study-guide]
---

> **For:** Practical 1 live demo (20%)  
> **Demo tasks:** Task 4 + Task 5  
> **Also read:** [[EGE353 Lab 5 Package Guide|Full code guide]] · [[EGE353 Lab 1-5 Q&A|Q&A flashcards]]

# Lab 5 — Simple Demo Study Guide

Follow this top to bottom. Check each box as you go.

**Before every new terminal:**

```bash
source /opt/ros/humble/setup.bash
source ~/dev_ws/install/setup.bash
```

---

## Part 0 — Check your package builds

```bash
cd ~/dev_ws
colcon build --packages-select cpp_pubsub
source install/setup.bash
ros2 pkg executables cpp_pubsub
```

You should see (names may vary slightly):

- `talker`
- `listener`
- `updown_publisher` (or your dual-topic publisher)
- `countup_listener`
- `countdown_listener`

If something is missing → see [[EGE353 Lab 5 Package Guide#Troubleshooting]].

---

## Part 1 — Task 4 (one topic + one listener + bag)

### What you're proving

Record messages from the **talker** into a bag file. Later, replay the bag **instead of** the talker. The **listener** still receives messages.

```
RECORD:  talker → /topic  → saved to bagtalker
DEMO:    bag play → /topic → listener
```

### Step A — Record the bag (do once)

Open **Terminal A**:

```bash
mkdir -p ~/bag_files
cd ~/bag_files
ros2 bag record -o bagtalker /topic
```

Open **Terminal B**:

```bash
ros2 run cpp_pubsub talker
```

Wait **15–20 seconds**. Then `Ctrl+C` on talker, then `Ctrl+C` on record.

Check:

```bash
ros2 bag info bagtalker
```

You should see topic `/topic` with messages.

### Step B — Live demo (show teacher)

**Close all terminals first.** Do **not** run talker.

| Terminal | Command |
|----------|---------|
| **1** | `cd ~/bag_files` then `ros2 bag play -l bagtalker` |
| **2** | `ros2 run cpp_pubsub listener` |
| **3** | `ros2 run rqt_graph rqt_graph` |

In rqt_graph: choose **Nodes/Topics (active)** → click **Refresh**.

**What you should see**

- Terminal 2 prints: `I heard: 'Hello, world! 0'`, `1`, `2`…
- Graph shows: bag → `/topic` → listener

**Screenshot for Google Doc:** listener terminal + rqt_graph.

**Say to teacher:** “The bag replaces the talker as the publisher.”

---

## Part 2 — Task 5 (two topics + two listeners + bag)

### What you're proving

Same idea as Task 4, but **two topics** at different speeds and **two listeners**.

| Topic | Speed | Listener |
|-------|-------|----------|
| `/upcounter` | ~2 Hz | `countup_listener` |
| `/downcounter` | ~1 Hz | `countdown_listener` |

```
RECORD:  updown_publisher → /upcounter + /downcounter → bagcounters
DEMO:    bag play → both topics → both listeners (no live publisher)
```

### Step A — Record the bag (do once)

**Terminal A:**

```bash
cd ~/bag_files
ros2 bag record -o bagcounters /upcounter /downcounter
```

**Terminal B:**

```bash
ros2 run cpp_pubsub updown_publisher
```

Wait **15–20 seconds**. `Ctrl+C` publisher, then `Ctrl+C` record.

Check:

```bash
ros2 bag info bagcounters
```

Both `/upcounter` and `/downcounter` must appear.

### Step B — Live demo (show teacher)

**Close all terminals.** Do **not** run the publisher.

| Terminal | Command |
|----------|---------|
| **1** | `cd ~/bag_files` then `ros2 bag play -l bagcounters` |
| **2** | `ros2 run cpp_pubsub countup_listener` |
| **3** | `ros2 run cpp_pubsub countdown_listener` |
| **4** | `ros2 run rqt_graph rqt_graph` → active → Refresh |

**Optional proof (extra terminals):**

```bash
ros2 topic hz /upcounter    # about 2 Hz
ros2 topic hz /downcounter  # about 1 Hz
```

**What you should see**

- Terminal 2: upcount messages (`0`, `1`, `2`…)
- Terminal 3: downcount messages (`10`, `9`, `8`… or your start value)
- Graph: bag → two topics → two listeners

**Screenshot for Google Doc:** both listeners + rqt_graph.

---

## Part 3 — Oral questions (teacher may ask anytime)

You don't demo these live, but you must **explain** them.

### Overlay vs underlay (Task 1)

| Terminal | Source | turtlesim |
|----------|--------|-----------|
| 1 | `source install/local_setup.bash` in dev_ws | **Your** build (custom window title) |
| 2 | only `source /opt/ros/humble/setup.bash` | **System** install (default title) |

**Short answer:** Terminal 1 uses your **overlay** (dev_ws). Terminal 2 uses the **underlay** (system ROS) only.

### Quick answers

| Question | Answer |
|----------|--------|
| What is `git clone`? | Copies a remote Git repo to your computer |
| When do you run `colcon build`? | After changing any source code, CMakeLists.txt, or package.xml |
| Talker topic name? | `/topic` |
| Publisher node name? | `minimal_publisher` |
| Subscriber node name? | `minimal_subscriber` |
| Message type? | `std_msgs/msg/String` |
| Talker publish rate? | ~2 Hz (500 ms timer) |
| Command to check topic frequency? | `ros2 topic hz /topic` |
| Real robot talker/listener example? | Camera publishes images; display node subscribes |

More Q&A: [[EGE353 Lab 1-5 Q&A]]

---

## Part 4 — Command cheat sheet

```bash
# Setup (every new terminal)
source /opt/ros/humble/setup.bash
source ~/dev_ws/install/setup.bash

# Build
cd ~/dev_ws
colcon build --packages-select cpp_pubsub
source install/setup.bash

# Task 3 — talker + listener (practice)
ros2 run cpp_pubsub talker
ros2 run cpp_pubsub listener
ros2 topic hz /topic

# Task 4 — bag
ros2 bag record -o bagtalker /topic
ros2 bag play -l bagtalker
ros2 run cpp_pubsub listener
ros2 run rqt_graph rqt_graph

# Task 5 — bag
ros2 bag record -o bagcounters /upcounter /downcounter
ros2 run cpp_pubsub updown_publisher
ros2 bag play -l bagcounters
ros2 run cpp_pubsub countup_listener
ros2 run cpp_pubsub countdown_listener
ros2 topic hz /upcounter
ros2 topic hz /downcounter
```

---

## Part 5 — Demo day checklist

Print or copy this list.

**Before class**

- [ ] `colcon build` succeeds
- [ ] `bagtalker` exists and has `/topic`
- [ ] `bagcounters` exists and has both topics
- [ ] Ran Task 4 demo once at home
- [ ] Ran Task 5 demo once at home
- [ ] Google Doc screenshots ready (or capture during demo)
- [ ] Read oral answers in Part 3

**During demo — Task 4**

- [ ] Close old terminals
- [ ] T1: bag play (loop)
- [ ] T2: listener
- [ ] T3: rqt_graph + refresh

**During demo — Task 5**

- [ ] Close old terminals
- [ ] T1: bag play (loop)
- [ ] T2: countup listener
- [ ] T3: countdown listener
- [ ] T4: rqt_graph + refresh

---

## Part 6 — When something breaks

| Problem | Fix |
|---------|-----|
| `No executable found` | Add node to CMakeLists.txt → `colcon build` → `source install/setup.bash` |
| Listener silent | Wrong topic name, or forgot to `source install/setup.bash` |
| Empty bag | Didn't run publisher/talker long enough while recording |
| rqt_graph empty | Click **Refresh**; make sure nodes are still running |

Full troubleshooting: [[EGE353 Lab 5 Package Guide#Troubleshooting]]

---

## Part 7 — Self-test (cover answers, then check)

1. Task 4 demo: which 3 terminals, which commands?  
2. Why don't you run talker during the Task 4 demo?  
3. Task 5: topic names and approximate Hz?  
4. Overlay vs underlay in one sentence?  
5. What does `ros2 topic hz /topic` show?

**Answers**

1. T1 `ros2 bag play -l bagtalker`, T2 listener, T3 rqt_graph  
2. The bag replaces the talker as publisher  
3. `/upcounter` ~2 Hz, `/downcounter` ~1 Hz  
4. Overlay = your dev_ws packages; underlay = system ROS; overlay overrides underlay  
5. Average publish frequency in Hz  

---

*Good luck on Practical 1.*
