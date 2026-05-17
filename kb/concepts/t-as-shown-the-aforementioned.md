---
id: "589e2d50-ba3a-4101-9352-7cd9b53041d1"
title: "T As Shown The Aforementioned"
type: vault_note
vault: wiki
created: 2026-05-17
updated: 2026-05-17
checksum: "sha256:2f45fc8523afd2aa"
source: heimdall/auto
---

# T As Shown The Aforementioned

- t as shown. The aforementioned ‘publish’ and ‘subscribe’ of the topic is
an asynchronous method which is advantageous on periodical data transmission. On the other hands, there is a need for
synchronous communication which uses request and response. Accordingly, ROS provides a synchronized message
communication method called ‘service’.
ROS Service
A service consists of a service server that responds only when there is a request and a service client that can send
requests as well as receiving responses. Unlike the topic, the service is one time message communication. Therefore,
when the request and response of the service are completed, the connection between two nodes will be disconnected.
A service is often used to command a robot to perform a specific action or nodes to perform certain events with a
specific condition. Service does not maintain the connection, so it is useful to reduce the load of the network by
replacing topic. For example, if the client requests the server for the current time as shown in the Figure, the server will
check the time and respond to the client, and the connection is terminated. <!-- id:589e2d50-ba3a-4101-9352-7cd9b53041d1 ts:2026-05-17 07:49 -->
- t as shown. The aforementioned ‘publish’ and ‘subscribe’ of the topic is
an asynchronous method which is advantageous on periodical data transmission. On the other hands, there is a need for
synchronous communication which uses request and response. Accordingly, ROS provides a synchronized message
communication method called ‘service’.
ROS Service
A service consists of a service server that responds only when there is a request and a service client that can send
requests as well as receiving responses. Unlike the topic, the service is one time message communication. Therefore,
when the request and response of the service are completed, the connection between two nodes will be disconnected.
A service is often used to command a robot to perform a specific action or nodes to perform certain events with a
specific condition. Service does not maintain the connection, so it is useful to reduce the load of the network by
replacing topic. For example, if the client requests the server for the current time as shown in the Figure, the server will
check the time and respond to the client, and the connection is terminated. <!-- id:589e2d50-ba3a-4101-9352-7cd9b53041d1 ts:2026-05-17 07:49 -->
