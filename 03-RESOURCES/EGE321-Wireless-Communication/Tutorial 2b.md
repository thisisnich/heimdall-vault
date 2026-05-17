---
tags:
  - EGE321
  - tutorial
  - multiple-access
  - communication-system
  - tutorial-2b
  - system-architecture
course: EGE321 Wireless Communication and Networking
topic: Tutorial 2b - Communication System Architecture
source: Tutorial 2b.pdf
converted: 2026-04-30
type: Tutorial
status: Completed
source: NYPY3 Import
---

> 📚 **Related:** [[NYPY3 - Main Index|NYPY3 Index]] | [[03-RESOURCES/EGE321-Wireless-Communication/Lesson2c.md|Lesson 2c]] | [[📅 Schedule & Assessments Dashboard|Assessment Dashboard]]

> 📚 **Related:** [[NYPY3 - Main Index|NYPY3 Index]] | [[03-RESOURCES/EGE321-Wireless-Communication/Lesson2c.md|Lesson 2c]] | [[📅 Schedule & Assessments Dashboard|Assessment Dashboard]]

> 📚 **Related:** [[NYPY3 - Main Index|NYPY3 Index]] | [[03-RESOURCES/EGE321-Wireless-Communication/Lesson2c.md|Lesson 2c]] | [[📅 Schedule & Assessments Dashboard|Assessment Dashboard]]


# SCHOOL OF ENGINEERING

Diploma in Electronics & Communications Engineering (EGDF20)
Wireless Communication & Networking (EGE321)
Tutorial 2:
Communication System Architecture
- 1)  Define what is multiple access methods?
Multiple access methods are techniques that allow multiple users to share the same communication channel or bandwidth simultaneously without interference. They enable efficient utilization of limited frequency spectrum by dividing the available resources among multiple users.

- 2)  What are the different types of multiple access methods?
- FDMA (Frequency Division Multiple Access)
- TDMA (Time Division Multiple Access)
- CDMA (Code Division Multiple Access)
- OFDMA (Orthogonal Frequency Division Multiple Access)
- SDMA (Spatial Division Multiple Access)

- 3)
Sketch the frequency vs time graph of the multiple access system. Explain briefly how
the information is carried and distinguish by the multiple access system.
**FDMA Graph:** Frequency on Y-axis, Time on X-axis. Each user assigned a unique frequency band that spans the entire time duration.
**TDMA Graph:** Frequency on Y-axis, Time on X-axis. All users share the same frequency but are assigned different time slots.
**Information is carried:** FDMA separates users by frequency, TDMA separates users by time slots.

- 4)
Explain, with the help of frequency-time diagrams, how the following multiple access
schemes can be implemented :
(i) Four users using FDMA: Four horizontal bands at different frequencies (f1, f2, f3, f4), each spanning the full time axis. Each user transmits continuously on their assigned frequency.
(ii) Six users using a combination of FDMA ( 2 frequencies ) and TDMA: Two frequency bands (f1, f2). Each frequency band is divided into 3 time slots. Total of 6 users (3 users per frequency × 2 frequencies).

- 5)  What is the difference between Multiple Access & Multiplexing?
- **Multiplexing:** Combining multiple signals into one medium for transmission from point-to-point (typically wired). The receiver is known and fixed.
- **Multiple Access:** Allows multiple users to share a common communication channel dynamically. Users can join/leave the network freely. Used in wireless systems where the receiver is not predetermined.

- 6)  What is the frequency spectrum allocated for FM Radio Broadcasting?
Considering each channel occupies 200 kHz, what is the maximum no. of channels
available for broadcasting?
FM Radio spectrum: 88 MHz to 108 MHz (20 MHz total bandwidth)
Maximum channels: 20 MHz / 200 kHz = 100 channels

- 7)
State  the  Shannon-Hartley  Capacity  Theorem  and  explain  how the  Shannon-Hartley
Capacity can be increased.
**Shannon-Hartley Capacity Theorem:** C = B × log₂(1 + S/N)
Where: C = channel capacity (bits/sec), B = bandwidth (Hz), S/N = signal-to-noise ratio

**How to increase capacity:**
1. Increase bandwidth (B)
2. Increase signal power (S) to improve S/N ratio
3. Decrease noise power (N) to improve S/N ratio

- 8)  A Class 1 telephone line has a flat bandwidth of 300Hz to 3400Hz and a minimum
signal to noise ratio of 40dB. It is required to send data over the telephone line, what
is the maximum possible data rate?
Bandwidth (B) = 3400 - 300 = 3100 Hz
S/N (linear) = 10^(40/10) = 10^4 = 10000

C = B × log₂(1 + S/N)
C = 3100 × log₂(1 + 10000)
C = 3100 × log₂(10001)
C = 3100 × 13.29
C ≈ 41,199 bits/sec or 41.2 kbps

- 9)
It is very critical to maintain the Quality of Service (QoS) in wireless communication
system. State the three monitoring factors of QoS.
1. **Latency** - Time delay for packet delivery
2. **Reliability** - Guaranteed data delivery
3. **Security** - Protection against eavesdropping and unauthorized access
Tut 2                                                              Page 1 of 1
Effective Date: 17 Oct 2022

---

