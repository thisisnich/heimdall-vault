---
type: lab
course: EGE353
module: EGE353-Autonomous-Mobile-Robotics
status: draft
source: pdf
created: 2026-05-22
tags: [EGE353, lab, ros2, rosbag, lab5, task5]
---

# Lab 5 — ROS Package (Task5 update)

> [!ingest] source: Lab 5 ROS package_Task5.pdf | date: 2026-05-22 | tool: markitdown
> Auto-converted. Edit summary below; re-run ingest to replace block above.

## Summary

Updated Lab 5 briefing: same Tasks 1–4 as [[Lab 5 - ROS Package|original slides]], plus **Task 5** (dual-topic rosbag + two listeners). **Practical 1 demo tasks changed** to Task 4 + Task 5 only (Task 1 and 3 no longer listed for live demo). Hands-on steps: [[EGE353 Lab 5 Notes#Task 5 — Rosbag with 2 topics and 2 subscribers (new)|Lab 5 Notes — Task 5]].

**Attachment:** [[99-ATTACHMENTS/EGE353/Lab 5 ROS package_Task5.pdf|PDF]]

## What changed vs original Lab 5

| Item | Original | Task5 PDF |
|------|----------|-----------|
| Demo tasks | Task 1, 3, 4 | **Task 4, 5** |
| Task 5 | — | Rosbag publishes `/upcounter` (2 Hz) + `/downcounter` (1 Hz); `Countup_Listener` + `Countdown_Listener` |
| Task 5 label | — | “Optional” / advance — still listed for demo |

## Task 5 (diagram from slides)

```
ros bag  ──► /upcounter  (2 Hz) ──► Countup_Listener
         └──► /downcounter (1 Hz) ──► Countdown_Listener
```

Record both topics while live publishers run; demo uses **bag play + two listeners only** (same pattern as Task 4).

## Overlay / underlay (from Task 1 slides)

- **Underlay:** base ROS install (`/opt/ros/humble`) or parent workspace — provides dependencies.
- **Overlay:** your `dev_ws` after `colcon build` — your packages **override** same-named packages in the underlay.
- `source install/setup.bash` in overlay loads **both** underlay + overlay; `local_setup.bash` loads overlay only (needs underlay sourced first).

See [[EGE353 Lab 5 Notes#Task 1 — Create Workspace & Clone turtlesim|Lab 5 Notes — Task 1]] for the turtlesim demo.

## Raw (archive)

Tasks 1–4 identical to [[Lab 5 - ROS Package]]. Full MarkItDown dump omitted; re-run `ingest.py pdf` on the attachment to regenerate.
