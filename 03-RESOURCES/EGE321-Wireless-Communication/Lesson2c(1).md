---
tags:
  - EGE321
  - wireless
  - multiple-access
  - FDMA
  - TDMA
  - CDMA
  - OFDMA
  - SDMA
  - lesson2c-duplicate
  - multiple-access-techniques
course: EGE321 Wireless Communication and Networking
topic: Wireless System Design Considerations - Multiple Access Techniques
source: Lesson2c(1).pptx
converted: 2026-05-07
type: Lesson
status: Completed
---

> 📚 **Related:** [[NYPY3 - Main Index|NYPY3 Index]] | [[03-RESOURCES/EGE321-Wireless-Communication/Lesson1c.md|Lesson 1c]] | [[📅 Schedule & Assessments Dashboard|Assessment Dashboard]]
converted: 2026-04-30
type: Lesson
status: Completed
---

> 📚 **Related:** [[NYPY3 - Main Index|NYPY3 Index]] | [[03-RESOURCES/EGE321-Wireless-Communication/Lesson2c.md|Lesson 2c]] | [[📅 Schedule & Assessments Dashboard|Assessment Dashboard]]
> 📚 **Related:** [[EGE321 Wireless Communication & Networking - MOC|EGE321 MOC]] | [[Lesson2c|Lesson 2c]]
Wireless System Design Considerations
Multiple Access Techniques
There are five common multiple access techniques as following:
- 1) Frequency Division Multiple Access (FDMA),
- 2) Time Division Multiple Access (TDMA),
- 3) Code Division Multiple Access (CDMA),
- 4) Orthogonal Frequency Division Multiple Access (OFDMA), and
- 5) Spatial Division Multiple Access (SDMA).
1 System Design Considerations
5 Most Commonly Used Multiple Access, FDMA, TDMA, CDMA, OFDMA & SDMA to Support Multiple Users.
https://youtu.be/-Nux72R5W24
Pls see this Youtube video to understand more.
Wireless System Design Considerations
Multiple Access Techniques (FDMA)
1 System Design Considerations
Each user is assigned one unique frequency for communication between the transmitter and receiver.
If there are multiple transmitters and one receiver, different transmitter will transmit by different frequency to the receiver.
Frequency Division Multiple Access (FDMA)
Time
Frequency
f2
f3
Wireless System Design Considerations
Multiple Access Techniques (FDMA)
1 System Design Considerations
f1
f2
f3
f2
f3
Frequency Division Multiple Access (FDMA)
Wireless System Design Considerations
Multiple Access Techniques (TDMA)
Each user is assigned unique time but same frequency for communication between the transmitter and receiver.
If there are multiple transmitters and one receiver, different transmitter will transmit at different time to the receiver.
1 System Design Considerations
Time Division Multiple Access (TDMA)
Time
Wireless System Design Considerations
Multiple Access Techniques (TDMA)
1 System Design Considerations
Time
Frequency
Time
f1
Freq.
Timeslot 1
Timeslot 2
Timeslot 3
f1
Time Division Multiple Access (TDMA)
Time-division multiple access (TDMA) allows several users to share the same frequency channel by dividing the signal into different time slots.
Wireless System Design Considerations
Multiple Access Techniques (TDMA)
1 System Design Considerations
Time Division Multiple Access (TDMA)
1 System Design Considerations
Time
Frequency
Wireless System Design Considerations
Combination of TDMA and FDMA
Wireless System Design Considerations
Multiple Access Techniques (CDMA)
1 System Design Considerations
User is assigned one unique code for communication, occupying over a wide bandwidth.
CDMA is where several transmitters can send information simultaneously over a single communication channel. This allows several users to share a band of frequencies (where each transmitter is assigned a unique code).
Code Division Multiple Access (CDMA)
Wireless System Design Considerations
Multiple Access Techniques (CDMA)
1 System Design Considerations
CDMA is a digital technology and transmits over the entire frequency range. It does not assign a specific frequency to each user but assign a unique code to each user on the communications network as illustrate in the diagram.
Code Division Multiple Access (CDMA)
# SDMA
Wireless System Design Considerations
Multiple Access Techniques (SDMA)
Spatial Division Multiple Access (SDMA)
1 System Design Considerations
SDMA - focusing signal beams using advanced antenna technology which is also called phased array techniques.
“Know the direction to transmit” energy efficiency
Use in satellite and cellular communication by reuse the frequency, focusing on different areas.
# OFDMA
Wireless System Design Considerations
Multiple Access Techniques (OFDMA)
Orthogonal Frequency Division Multiple Access (OFDMA)
1 System Design Considerations
Orthogonal frequency division multiplexing (OFDMA) is used in 4G or Long Term Evolution (LTE) cellular systems.
OFDM is a modulation method that divides a channel into multiple narrow orthogonal bands that are spaced so they don’t interfere with one another.
The demand and traffic patterns, user locations, and the network conditions are constantly changing and the wireless communication system must adapt to the user needs.
The main issues facing wireless communication are:
the complexity of communication protocols that support full user mobility,
the power consumption in the mobile or portable terminal, and
the spectrum scarcity.
Challenges in Wireless Communication System
1 System Design Considerations
Multiple Access Vs Multiplexing. Distinguish the Different Between Multiple Access and Multiplexing.
https://youtu.be/8sxlqLX_dBY
Pls see this Youtube video to understand more.
How our Phone Evolve from 1G to 5G with Different Multiple Access (FDMA. TDMA, CDMA, OFDMA & SDMA).
https://youtu.be/Vz7H6J6RmFU
Pls see this Youtube video to understand more.
Challenges in Wireless Communication System
Managing the scarce RF spectrum resources
1 System Design Considerations
# How to put more users in the limited resource like spectrum?To solve the RF bandwidth scarcity problem, more efficient modulation techniques like QAM and OFDM will have to be used to carry more payload.Users will also need to share the frequency bandwidth using multiple access techniques like FDMA, TDMA and CDMA.Frequency will also need to be reused (SDMA) if possible, for example use case in cellular system.
Challenges in Wireless Communication System
Managing the scarce RF spectrum resources
1 System Design Considerations
QoS - Latency, Reliability, Security
Latency –   	1) time for the packets to take between sender and receiver 			2) interaction between the sender & receiver or even various 			parties along the way.
Four key causes of latency are 	1) propagation delay
- 2) serialization
- 3) data protocols and routing
- 4) switching, queuing and buffing
Challenges in Wireless Communication System
Quality of Service (QoS)
1 System Design Considerations
QoS - Latency, Reliability, Security
Definition of Reliability : is the ability of the communication network guarantee that the data is always delivered from the transmitter to the receiver but time taken for communication to take placed is not concerned.
For example, in a communication network, reliability can be improved by:
Improve the reliability of individual components
Increase the number of paths between the source and destination
Decrease the number of intermediate links
Challenges in Wireless Communication System
Quality of Service (QoS)
1 System Design Considerations
QoS - Latency, Reliability, Security
“How secure is your communication?”
How to ensure that only the intended receiver receive your message especially for wireless communication.
Increased risk of eavesdropping with wireless connectivity
With device / user mobility (only wireless can fulfil), there will be security issues related to authentication and privacy.
Security can be enhanced with encryption using combination of public and private keys cryptography.
Challenges in Wireless Communication System
Quality of Service (QoS)
1 System Design Considerations
Other considerations will include:
The physical environment.
Presence of peripheral devices that can impact the wireless system.
Proximity to human or metallic structure.
Availability of stable power source.
Cost.
Manufacturing reliability.
Repeatability of performance.
1 System Design Considerations
Challenges in Wireless Communication System
Other Design Consideration
Frequency Hopping Spread Spectrum, FHSS: How Multiple Users Share Resources Without Interference.
https://youtu.be/xV3fZThMYlI
Pls see this Youtube video to understand more.
How Code Division Multiple Access, CDMA & Direct Sequence Spread Spectrum, DSSS Works.
https://youtu.be/Zahw-f-_KVs
Pls see this Youtube video to understand more.
1 System Design Considerations
Thank you
