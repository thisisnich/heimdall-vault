---
type: tutorial
course: EGE321
module: EGE321-Wireless-Communication
status: reviewed
source: pdf
created: 2026-05-24
tags:
  - EGE321
  - tutorial
  - solution
  - multiple-access
---

# Tutorial 2 Solution — Communication System Architecture

> [!ingest] source: Tutorial 2 Solution - Copy.pdf | date: 2026-05-24 | tool: markitdown
> Auto-converted. Edit summary below; re-run ingest to replace block above.

## Summary

Multiple access (FDMA, TDMA, CDMA, OFDMA, SDMA); F–T diagrams; multiplexing vs multiple access; FM channels; Shannon–Hartley; telephone line capacity; **QoS: latency, reliability, security**. PDF: [[99-ATTACHMENTS/EGE321/Tutorial 2 Solution - Copy.pdf]]. Pairs with [[Tutorial 2b]].

---

## Full solutions

SCHOOL OF ENGINEERING

Diploma in Electronics & Computer Engineering (EGDF20)

Wireless Communication & Networking (EGE321)

Tutorial 2:

Communication System Architecture

1)  Define what is multiple access methods?

•  Allow many users at the same time
•  Share a finite amount of radio spectrum
•  High performance
•  Duplexing generally required

2)  What are the different types of multiple access methods?

There are five basic access or multiplexing methods:

•
frequency division multiple access (FDMA),
•
time division multiple access (TDMA),
•  code division multiple access (CDMA),
•  orthogonal frequency division multiple access (OFDMA), and
•

spatial division multiple access (SDMA).

3)

Sketch the frequency vs time graph of the multiple access system. Explain briefly how the
information is carried and distinguish by the multiple access system.

SDMA

Tut 2                                                             Page 1 of 3

Effective Date: 17 Apr 2023

4)

Explain, with the help of frequency-time diagrams, how the following multiple access
schemes can be implemented :

(i)
(ii)

Four users using FDMA
Six users using a combination of FDMA ( 2 frequencies ) and TDMA

i)

FDMA with four users

Frequency

f4

f3

f2

f1

(ii)

FDMA/TDMA for six users

Frequency

f2

f1

-----

-----

Time

Time

5)  What is the difference between Multiple Access & Multiplexing?

Multiplexing

Multiplexing is the process of transmitting several messages simultaneously on the same circuit
or channel.

Multiple Access

Multiple Access are techniques that allow spectrum and power to be shared efficiently among
multiple users. In multiple access, more than one simple signal can thus be transmitted as part of
a  single  complex  signal  and  separated  out  at  the  receiving  end.  This  is  not  possible  in
multiplexing

6)  What is the frequency spectrum allocated for FM Radio Broadcasting?

Considering each channel occupies 200 kHz, what is the maximum no. of channels
available for broadcasting?

For FM broadcasting: 88 – 108 MHz
Total frequency range available: 108-88 = 20 MHz
Each channel occupies 200 kHz

Max. no. of channels available = 20MHz / 200 kHz = 100

Tut 2                                                             Page 2 of 3

Effective Date: 17 Apr 2023

7)

State  the  Shannon-Hartley  Capacity  Theorem  and  explain  how  the  Shannon-Hartley
Capacity can be increased.

Shannon-Hartley Capacity Theorem: C = B log2(1+S/N) bps

BW and S/N is proportional to C. Hence C can be increase by increasing the BW or S/N.

8)

A Class 1 telephone line has a flat bandwidth of 300Hz to 3400Hz and a minimum signal
to noise ratio of 40dB. It is required to send data over the telephone line, what is the
maximum possible data rate?

C = Blog2(1+S/N) bps

C = (3400-300)log2(1+1040/10) = 41.192kbps

9)

It  is  very  critical  to  maintain  the  Quality  of  Service  (QoS)  in  wireless  communication
system. State the three monitoring factors of QoS.

Latency, Reliability, Security

Tut 2                                                             Page 3 of 3

Effective Date: 17 Apr 2023
