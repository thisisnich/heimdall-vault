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
course: EGE321 Wireless Communication & Networking
chapter: 2
topic: Multiple Access Techniques
---
# Wireless System Design Considerations — Multiple Access Techniques
> 📚 **Related:** [[Lesson1c|Chapter 1: System Design]] | [[Tutorial_1b|Tutorial 1]]
---
## Multiple Access Techniques Overview
There are five common multiple access techniques:
1. Frequency Division Multiple Access (FDMA)
2. Time Division Multiple Access (TDMA)
3. Code Division Multiple Access (CDMA)
4. Orthogonal Frequency Division Multiple Access (OFDMA)
5. Spatial Division Multiple Access (SDMA)
📺 **Video:** [5 Most Commonly Used Multiple Access – FDMA, TDMA, CDMA, OFDMA & SDMA](https://youtu.be/-Nux72R5W24)
---
## Frequency Division Multiple Access (FDMA)
Each user is assigned one unique frequency for communication between the transmitter and receiver.
If there are multiple transmitters and one receiver, different transmitters will transmit on different frequencies to the receiver.
> **Diagram concept:** Users 1, 2, and 3 are each assigned a unique frequency (f1, f2, f3) and can transmit simultaneously across the same time span.
---
## Time Division Multiple Access (TDMA)
Each user is assigned a unique time slot but the same frequency for communication between the transmitter and receiver.
If there are multiple transmitters and one receiver, different transmitters will transmit at different times to the receiver.
> **Diagram concept:** Users 1, 2, and 3 each occupy separate time slots (Timeslot 1, 2, 3) on the same frequency (f1).
TDMA allows several users to share the same frequency channel by dividing the signal into different time slots.
### Combination of TDMA and FDMA
By combining both techniques, users can be multiplexed across both time slots and frequency bands simultaneously (e.g., Users 1–9 spread across multiple timeslots and frequencies).
---
## Code Division Multiple Access (CDMA)
Each user is assigned one unique **code** for communication, occupying a wide bandwidth.
CDMA allows several transmitters to send information simultaneously over a single communication channel. This allows several users to share a band of frequencies — each transmitter is assigned a unique code.
CDMA is a digital technology that transmits over the entire frequency range. It does not assign a specific frequency to each user but instead assigns a unique code to each user on the communications network.
📺 **Video:** [How CDMA & Direct Sequence Spread Spectrum (DSSS) Works](https://youtu.be/Zahw-f-_KVs)
📺 **Video:** [Frequency Hopping Spread Spectrum (FHSS): How Multiple Users Share Resources Without Interference](https://youtu.be/xV3fZThMYlI)
---
## Spatial Division Multiple Access (SDMA)
SDMA focuses signal beams using advanced antenna technology — also called **phased array techniques**.
- "Know the direction to transmit" → energy efficiency
- Used in satellite and cellular communication by reusing the frequency, focusing on different areas
---
## Orthogonal Frequency Division Multiple Access (OFDMA)
OFDMA is used in **4G / Long Term Evolution (LTE)** cellular systems.
OFDM is a modulation method that divides a channel into multiple narrow orthogonal bands spaced so they don't interfere with one another.
📺 **Video:** [How our Phone Evolved from 1G to 5G with Different Multiple Access (FDMA, TDMA, CDMA, OFDMA & SDMA)](https://youtu.be/Vz7H6J6RmFU)
📺 **Video:** [Multiple Access vs Multiplexing – Distinguish the Difference](https://youtu.be/8sxlqLX_dBY)
---
## Challenges in Wireless Communication Systems
The demand, traffic patterns, user locations, and network conditions are constantly changing — wireless systems must adapt to user needs.
### Main Issues
1. Complexity of communication protocols that support full user mobility
2. Power consumption in mobile or portable terminals
3. Spectrum scarcity
---
## Managing Scarce RF Spectrum Resources
**How to put more users into limited spectrum?**
- Use more efficient modulation techniques like **QAM** and **OFDM** to carry more payload
- Share frequency bandwidth using multiple access techniques: **FDMA, TDMA, CDMA**
- Reuse frequency (**SDMA**) where possible (e.g., cellular systems)
---
## Quality of Service (QoS)
### Latency
Latency refers to:
1. Time for packets to travel between sender and receiver
2. Interaction time between sender, receiver, and intermediate parties
**Four key causes of latency:**
1. Propagation delay
2. Serialization
3. Data protocols and routing
4. Switching, queuing, and buffering
### Reliability
**Definition:** The ability of the communication network to guarantee data is always delivered from transmitter to receiver, regardless of time taken.
Reliability can be improved by:
- Improving the reliability of individual components
- Increasing the number of paths between source and destination
- Decreasing the number of intermediate links
> 🔗 **Related:** Network reliability concepts apply to [[Lecture_1_PLC#Distributed Control Structure|Distributed Control Systems]]
### Security
*"How secure is your communication?"*
- Wireless communication carries an increased risk of eavesdropping
- Device/user mobility introduces security issues related to **authentication** and **privacy**
- Security can be enhanced with encryption using a combination of **public and private key cryptography**
---
## Other Design Considerations
Other factors to consider in wireless system design:
- The physical environment (open-area, semi-open, closed)
- Presence of peripheral devices that can impact the wireless system
- Proximity to human or metallic structures (body effect, proximity effect)
- Availability of a stable power source
- Cost
- Manufacturing reliability
- Repeatability of performance
**Key design dimensions include:** propagation environment, multipath fading, delay, distance/zone, antenna gain/efficiency/bandwidth/pattern, human interface, human hazard, and land/maritime/aeronautical/satellite considerations.
---
*1 System Design Considerations*
