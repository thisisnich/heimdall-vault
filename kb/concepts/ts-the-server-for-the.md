---
id: "c63f4cde-4b02-41a0-bc4f-a987dbcdc198"
title: "Ts The Server For The"
type: vault_note
vault: wiki
created: 2026-05-17
updated: 2026-05-17
checksum: "sha256:098a7ba39d37b6f0"
source: heimdall/auto
---

# Ts The Server For The

- ts the server for the current time as shown in the Figure, the server will
check the time and respond to the client, and the connection is terminated. The service is synchronous bidirectional
communication between the service client that requests a service regarding a particular task and the service server that
is responsible for responding to requests.
ROS Service
ROS Service
ROS Actions
ROS Actions
Communication on action is used when a requested goal takes a long time to be completed, therefore
progress feedback is necessary. This is very similar to the service where ‘goals’ and ‘results’ correspond
to ‘requests’ and ‘responses’ respectively. In addition, the ‘feedback’ is added to report feedbacks to the
client periodically when intermediate values are needed.
The message transmission method is the same as the asynchronous topic. The feedback transmits an
asynchronous bidirectional message between the action client which sets the goal of the action and an
action server that performs the action and sends the feedback to the action client. For example, as shown
in Figure, if the client sets home-cleaning tasks as a goal to the server, the server informs the user of the
progress of the dishwashing, laundry, cleaning, etc. in the form of feedback, and finally sends the final
message to the client as a result. <!-- id:c63f4cde-4b02-41a0-bc4f-a987dbcdc198 ts:2026-05-17 07:49 -->
- ts the server for the current time as shown in the Figure, the server will
check the time and respond to the client, and the connection is terminated. The service is synchronous bidirectional
communication between the service client that requests a service regarding a particular task and the service server that
is responsible for responding to requests.
ROS Service
ROS Service
ROS Actions
ROS Actions
Communication on action is used when a requested goal takes a long time to be completed, therefore
progress feedback is necessary. This is very similar to the service where ‘goals’ and ‘results’ correspond
to ‘requests’ and ‘responses’ respectively. In addition, the ‘feedback’ is added to report feedbacks to the
client periodically when intermediate values are needed.
The message transmission method is the same as the asynchronous topic. The feedback transmits an
asynchronous bidirectional message between the action client which sets the goal of the action and an
action server that performs the action and sends the feedback to the action client. For example, as shown
in Figure, if the client sets home-cleaning tasks as a goal to the server, the server informs the user of the
progress of the dishwashing, laundry, cleaning, etc. in the form of feedback, and finally sends the final
message to the client as a result. <!-- id:c63f4cde-4b02-41a0-bc4f-a987dbcdc198 ts:2026-05-17 07:49 -->
