---
tags:
  - EGE321
  - wireless
  - communication
  - RF
  - system-design
course: EGE321 Wireless Communication & Networking
chapter: 1
topic: System Design Considerations
---
# EGE321 – Wireless Communication & Networking
## Chapter 1: System Design Considerations
> 📚 **Related:** [[Lesson2c|Chapter 2: Multiple Access]] | [[Tutorial_1b|Tutorial 1]]
---
## Contents
1. System Design Considerations
   - 1.1 Wireless Technology Overview
   - 1.2 Wireless System Design Considerations
   - 1.3 Challenges in Wireless Communication System
---
## 1.1 Wireless Technology Overview
**Q: What is communication?**
Ans: Communication means transfer of information from source to recipient.
**Q: What is wireless communication?**
Ans: Any transfer of information between points that do not have a physical connection, like wire or cable connection, would be **Wireless Communication**.
---
### Advantages and Disadvantages of Wireless Communication
| Advantages | Disadvantages |
|---|---|
| Flexibility | Security vulnerabilities |
| Easy Installation | Planning |
| Accessible | Interference |
| Mobility | |
---
### Radio System Fundamentals
- Transmitting or receiving voice and data using electromagnetic waves in open space.
- The information from the sender to receiver is carried over a well defined channel.
- Each channel has a fixed frequency bandwidth and capacity.
- Different channels can be used to transmit information in parallel and independently.
**Further Reading / Videos:**
- [How Electronic Communication Works (Transmitter, Channel & Receiver)](https://www.youtube.com/results?search_query=How+Electronic+Communication+Works)
	- Communication system -> transfer of information between to or more points
		- sender (transmitter)
		- recipient(receiver)
	- How is communication carried out?
		- f2f
		- smoke, fires, drums, coloured flags, pigeons (olden days)
	- Elements of an Electronic Communication System
		- Transmitter: convert original source information (baseband) to a from suitable for transmission
		- Channel/Medium: The medium by which the electronic signal is send or propagated from one place to another.
		- Receiver: Accepts transmitted signals and convers them back to the original form, which is understandable by humans
	- Channel/Medium
		- Transmission line → cable or wire that carries information in the form of an electrical current
		- Optical fiber → a fine piece of glass that carries information as light
		- Wireless → medium is the air, e.g. radio, TV, cell networks
> 🔗 **IoT Context:** Wireless is key for [[ch0#Embedded System in Internet of Things (IoT)|IoT Systems]]
- [Why Modulation is CRUCIAL in Wireless Communication? (Analog vs Digital Modulation Explained!)](https://www.youtube.com/results?search_query=Why+Modulation+is+CRUCIAL+in+Wireless+Communication)
---
## 1.2 Wireless System Design Considerations
### Types of Radio In Wireless Communications
**Classification of mobile radio transmission systems:**
| Type | Description |
|---|---|
| **Simplex** | Communication in one direction only and cannot be reversed. |
| **Half-Duplex** | Communication can be in both directions but transmission does not occur at the same time. |
| **Full-Duplex** | Allows simultaneous exchange in both directions at the same time. |
---
### Simplex Radio System
- A radio technology that allows only **one-way communication** from a transmitter to a receiver.
- **Examples:** FM radio, Pagers, TV.
---
### Half Duplex Radio System
- Two direction communication using the **same frequency**.
- Each station can either transmit or receive but **not at the same time** (not simultaneously).
- **Examples:** Walkie-talkie, wireless keyboard & mouse.
---
### Full Duplex Radio System
- Radio systems in which each end can **transmit and receive simultaneously**.
- Typically **two frequencies** are used to set up the communication channel; one for transmit and the other for receive.
- **Examples:** CT2 Cordless Phone, Cellular Phone (3G, 4G, LTE, etc.)
**Further Reading / Video:**
- [What is Simplex, Half Duplex & Full Duplex – Different Types of Telecommunication Transmission Modes](https://youtu.be/07pFHyOrN_k)
---
*EGE321 – Wireless Communication & Networking | Chapter 1: System Design Considerations*
