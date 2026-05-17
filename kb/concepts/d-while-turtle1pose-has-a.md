---
id: "e7eaa7a8-227a-4abc-adbc-7bb59ea8cf1f"
title: "D While Turtle1Pose Has A"
type: vault_note
vault: wiki
created: 2026-05-17
updated: 2026-05-17
checksum: "sha256:09442393fee121a5"
source: heimdall/auto
---

# D While Turtle1Pose Has A

- d), while `/turtle1/pose` has a Count of over 1060 (data published continuously during recording).

---

## Question 2

**Task:**
Close all terminals. Modify the command such that it only records the cmd_vel and save it to bagfile2.

**Steps:**
1. Using the turtle_teleop_key to draw a square in turtlesim
2. Terminate the turtle_teleop_key process
3. Close the turtlesim and replay the bagfile2 in a loop
4. Observe if the turtlesim can draw back the same square you previously drawn
5. Run `rqt_graph`, ensure you refresh the nodes/topics (active) to view the graph showing rosbag -> /turtle1/cmd_vel -> /turtlesim
6. Echo the topic `/turtle1/pose` (i.e., `ros2 topic echo /turtle1/pose`)
7. Using ros topic hz to display the publishing rate for `/turtle1/cmd_vel` (i.e., `ros2 topic hz /turtle1/cmd_vel`)
8. <!-- id:e7eaa7a8-227a-4abc-adbc-7bb59ea8cf1f ts:2026-05-17 07:49 -->
