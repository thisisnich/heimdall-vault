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
  - link-budget
---

# Tutorial 5c Solution — Link Performance Analysis

> [!ingest] source: Tutorial 5c Solution.pdf | date: 2026-05-24 | tool: markitdown
> Auto-converted. Edit summary below; re-run ingest to replace block above.

## Summary

FSPL factors (distance, frequency); practical path-loss factors; Orchard Rd link budget: **FM = 18 dB @ 99%**, \(L_p = 134\) dB, \(P_T = 28\) dBm (with 2 dB feeder); mobile complaint case \(L_p \approx 141.94\) dB, \(P_R \approx -103.93\) dBm (insufficient vs −100 dBm). PDF: [[99-ATTACHMENTS/EGE321/Tutorial 5c Solution.pdf]]. **ASSN1 Q5 @ 99.8%:** use assignment Rayleigh chart → **25 dB** (confirmed).

## Key formulas

- System: \(P_T - L_f + G_T - L_P - FM + G_r - L_f = P_r\)
- Hata: \(L_P = 69.55 + 26.16\log f - 13.82\log h_{te} - A(h_{re}) + [44.9 - 6.55\log h_{te}]\log d\)
- \(A(h_{re}) = 3.2[\log(11.75\,h_{re})]^2 - 4.97\) dB
- **99% reliability → FM = 18 dB**

---

## Full solutions

SCHOOL OF ENGINEERING

Diploma in Electronics & Computer Engineering (EGDF20)

Wireless Communication & Networking (EGE321)

Tutorial 5:

Link Performance Analysis

1)  What are the 2 factors that determine the path loss in Free Space propagation model?

Distance and frequency

2)

In practical scenarios, name other factors that also have an impact on path loss.

•  Antenna heights
•  Terrain environment (urban or rural, etc)
•  Weather

3)

As a RF engineer of one of the cellular operator in Singapore, you are in charge of the
setting up of some base station in Singapore Orchard Road.  Consider the following
given parameters:

•  Frequency of operation = 900 MHz
•  Base station transmitter power output PT = unknown
•  Base Station feeder loss, LF = 2 dB
•  Mobile station sensitivity, PR = -113 dBm
•  Base station transmitting antenna gain, GT = 10 dB
•  Mobile station receiving antenna gain, GR = 3 dB
•  Height of Base station, hT = 40 m
•  Height of Mobile station, hR = 2 m

Assume that there are no other losses except for the path loss and fading.  The Base
station  must  provide  reliable  communication  within  a  cell  radius  d  =  2  km  with  a
reliability of 99 %.  Using the Okumura-Hata Model, calculate the following:

a)
The required fade margin for 99% reliability [Answer = 18 dB]
b)  Write down the system equation in terms of the given parameters
c)
d)

The path loss, L [Answer = 134 dB]
The required Base station transmitter power PT [Answer = 26 dB]

Tut 5                                                             Page 1 of 3

Effective Date: 17 Oct 2022

(a) For the required fade margin of 99% reliability, an extra 18 dB is required.

Note: Fade Margin is like buying insurance for your luggage when you go traveling.
The more you treasure your belongings, the more you demanded that the luggage should
reach your destination intact and therefore the more you should pay for the insurance
premium.

(b) PT – Lf + GT – LP – FM + GR – Lf  = PR

(c)  Lp for the Okumura Hata model in an urban setting is given by

LP = 69.55 + 26.16 log f (MHz) – 13.82 log hte – A(hre) + [44.9 – 6.55 log hte ][log d
(km)]

A (hre) = 3.2[log(11.75hre)]2 – 4.97 (db)

= 3.2 [log (11.75*2)]2 – 4.97 dB = 1.045 dB

LP = 69.55 + 26.16 log 900 – 13.82 log 40 – 1.045 + [44.9-6.55 log 40][log 2]
= 134 dB

(d) PT – 2 + 10 – 134 – 18 +3 – 0 = -113
PT = 2-10+134+18-3-113 = 28 dBm

4)

A  mobile  subscriber  that  is  living  at  a  distance,  d  =  3.5  km  from  a  base  station
complained to the cellular operator that his mobile phone reception is not very good.
You  are  asked  to  investigate  to  find  out  the  problems  and  make  the  necessary
recommendations.  Details are as follows:

Frequency of operation, f
Base Station transmitted output power, PT
Base Station transmitter antenna gain, GT
Base Station transmitter antenna height, hte
Mobile Station receiver sensitivity

: 935.2 MHz
: 20 W
: 10 dB
: 50 metre
: -100 dBm

Tut 5                                                             Page 2 of 3

Effective Date: 17 Oct 2022

Mobile Station receiver antenna gain, GR
Mobile Station receiver antenna height, hre

: 3 dB
: 1.6 metre

 Assume  that  all  other  losses  are  negligible  except  for  the  path  loss  and  Rayleigh
fading.

Using the Okumura-Hata propagation model, determine the following:

(i)

  The system equation in terms of the given parameters.

PT + GT – LP – FM + GR = PR

(ii)    The path loss, LP (dB).

A (hre) = 3.2 [log (11.75hre)]2 - 4.97 (dB)
= 3.2 [log(11.75 x 1.6)]2 - 4.97
= 0.2251

LP = 69.55 + 26.16 log f(MHz)  – 13.82 log hte – A(hre) + [44.9 – 6.55 log
hte][log d (km)]
     = 69.55 + 26.16 log(935.2)  -  13.82 log(50) -  0.2251 + [44.9 - 6.55 log
50]log3.5 = 141.94 dB

(iii)    The  received  signal,  PR  (dBm)  at  the  mobile  receiver,  assuming  the  base

station must provide communication with 99 % reliability.

For 99% reliability, FM = 18 dB
PT + GT – LP – FM + GR = PR
PR = 10 log (20/0.001) + 10 – 141.94 – 18 + 3 = -103.93 dBm

(iv)    Based  on  your  result  from  (iii),  is  the  signal  strength  received  at

subscriber’s mobile phone sufficient? Explain your answer.

Insufficient as the signal strength is weaker than the minimum of -100 dBm
required.

Okumura Hata Propagation model:

LP = 69.55 + 26.16 log f(MHz) –13.82 log hte – A(hre)

+ [44.9 – 6.55 log hte] [log d (km)]

A (hre) = 3.2 [log (11.75hre)]2 - 4.97 (dB)

Tut 5                                                             Page 3 of 3

Effective Date: 17 Oct 2022
