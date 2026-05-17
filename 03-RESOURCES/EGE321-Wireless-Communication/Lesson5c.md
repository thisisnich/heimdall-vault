---
tags:
  - EGE321
  - lesson5c
  - wireless-systems
  - digital-modulation
  - chapter-2
  - modulation-techniques
course: EGE321 Wireless Communication & Networking
topic: Lesson 5c - Digital Modulation Technique (Chapter 2.3)
source: Lesson5c.pptx
converted: 2026-05-07
type: Lesson
status: Completed
---

> 📚 **Related:** [[NYPY3 - Main Index|NYPY3 Index]] | [[03-RESOURCES/EGE321-Wireless-Communication/Lesson4c.md|Lesson 4c]] | [[📅 Schedule & Assessments Dashboard|Assessment Dashboard]]

> 📚 **Related:** [[NYPY3 - Main Index|NYPY3 Index]] | [[03-RESOURCES/EGE321-Wireless-Communication/Lesson4c.md|Lesson 4c]] | [[📅 Schedule & Assessments Dashboard|Assessment Dashboard]]

> 📚 **Related:** [[NYPY3 - Main Index|NYPY3 Index]] | [[03-RESOURCES/EGE321-Wireless-Communication/Lesson4c.md|Chapter 2]] | [[📅 Schedule & Assessments Dashboard|Assessment Dashboard]]

# Lesson 5c - Digital Modulation Technique (Chapter 2.3)

## Contents

- 2.2 Radio Propagation and Link Budget
- 2.2.1 Electromagnetic Wave Propagation
- 2.2.2 Propagation Path Loss Model
- 2.2.3 Link Performance Analysis

---

## Radio Propagation Model – EIRP

### EIRP Fundamentals

**Definition:**
Effective, or Equivalent, Isotropically Radiated Power (EIRP) is the maximum amount of power that could be radiated from an antenna, given its antenna gain and the transmitter power of the RF system. EIRP is most commonly given in dB or dBm.

**Equations:**
```
EIRP = PT × GT (watts)
EIRP (dBm) = PT (dBm) + GT (dB)
```

**Where:**
- PT = Transmitted Power
- GT = Transmit Antenna Gain

### Example

**Problem:**
Calculate the EIRP of a microwave transmitting installation where the transmitter output power is 1 W, the total feeder cable loss is 1 dB, and the transmitting antenna gain is 30dB.

**Solution:**
```
EIRP (dBm) = PT (dBm) – Lf (dB) + GT (dB)
= 10 log (1W/0.001W) – 1 dB + 30 dB
= 30 dBm – 1 dB + 30 dB
= 59 dBm
```

### Video Reference
[What is Link Budget & How to Calculate the Link Budget to Estimate the Quality of Comm Link](https://youtu.be/y35j8wb0eBU)

---

## Okumura's Hata Model

### Fundamentals

Hata published an empirical formula based on Okumura's results to predict path loss, and is valid from 150 MHz to 1500 MHz.

**Standard Formula for Path Loss in Urban Areas:**

**Parameters:**
- f: Frequency between 150-1500 MHz
- hte: Effective height of transmitter between 30-200 m
- hre: Effective height of receiver between 1-10 m
- d: Distance between transmitter and receiver in km
- A(hre): Correction factor for mobile antenna height

**For a large city:**
```
A(hre) = 3.2[log(11.75 hre)]² - 4.97 (dB) for f ≥ 300 MHz
```

### Example

**Problem:**
A mobile subscriber is living at a distance, d = 3500 m from a base station and complained to the cellular operator that his mobile phone reception is not very good. You are asked to investigate to find out the problems and make the necessary recommendations.

**Parameters:**
- Frequency of operation, f: 935.2 MHz
- Base Station transmitted output power, PT: 20 W
- Base Station transmitter antenna gain, GT: 10 dB
- Base Station transmitter antenna height, hte: 50 metre
- Mobile Station receiver sensitivity, PR: -100 dBm
- Mobile Station receiver antenna gain, GR: 3 dB
- Mobile Station receiver antenna height, hre: 1.6 metre

**Task:**
Assuming all other losses are negligible except for the path loss, using Okumura-Hata propagation model, determine the path loss, LP (dB).

**Solution:**
```
A(hre) = 3.2[log(11.75 hre)]² - 4.97 (dB)
= 3.2[log(11.75 × 1.6)]² - 4.97
= 0.2251

LP = 69.55 + 26.16 log f(MHz) – 13.82 log hte – A(hre) + [44.9 – 6.55 log hte][log d (km)]
= 69.55 + 26.16 log(935.2) - 13.82 log(50) - 0.2251 + [44.9 - 6.55 log 50] log 3.5
= 141.94 dB
```

---

## Link Performance Analysis

### Fundamentals

**Communication Link:**
Communication link includes the entire communication path from the information source, through the transmitter, RF channel and receiver up to the information sink.

**Link Budget Analysis:**
- By examining the link budget, we can determine whether communication system meets the requirements comfortably or marginally or fails to meet the specifications
- A link analysis consists of calculating the useful signal power and the interfering noise power available at the receiver
- The output of the link analysis is a link budget which shows the gains and losses
- Some link budget parameters are statistical such as allowances for fading
- Therefore, the link budget is an estimation technique for evaluating the communication system performance

### Performance Criteria

**Bit Error Rate (BER):**
- Used in digital system to measure the quality of the demodulator output in terms of the number of bits wrongly decoded
- BER = total bits received in error / total bits transmitted

**Signal to Noise Ratio (SNR):**
- The SNR is a measure of performance at the various points of a communication link
- SNR (dB) = 10 log (signal power / noise power)
- The SNR can be degraded (lowered) through:
  - The decrease of the desired signal power
  - The increase of noise power (noise) or interfering signals (interferences)

### Radio Link Design

Link budget accounts for the total losses and gains in a transmission link from transmitter output to the receiver SNR at the input to the demodulator.

**Radio link design of a mobile communication system generally involves the tradeoff among the following 3 parameters (factors):**
- Transmit power (PT)
- Propagation path loss (LP)
- Receive Power (PR) or Rx sensitivity

### Radio Link Budget Equation

**To guarantee detection at the Receiver, we must have:**
```
PT(dBm) + (Gains)dB – (Losses)dB ≥ PR (dBm)
```

**Where:**
- PT = transmit power
- Gain = transmit and receive antenna gain
- Losses = total losses at the antenna feeder loss, filter and circulator loss, propagation path loss, fade margin, etc
- PR = Rx sensitivity for a specified SNR or BER. This is the minimum signal strength that must be received at the receiver antenna in order to guarantee a certain level of performance at the receiver output

**Performance Standards:**
- For analog link SNR is normally 12 dB SINAD
- For mobile digital link, the BER could be 1×10⁻⁶

**Fade Margin:**
Refers to the margin in dB that has to be added to the path loss to account for multipath fading

---

## Radio Link Example

### Problem Statement

Consider a particular base station in a cellular system operating in a large city with the following parameters:

**Parameters:**
- Frequency of operation: 915 MHz
- Base transmitter output power, Pt: PT (to be determined)
- Mobile receiver sensitivity, Pr: -113 dBm
- Base transmitter antenna gain, Gt: 6 dB
- Mobile receiver antenna gain, Gr: 3 dB
- Height of base transmitter, hte: 50 m
- Height of mobile receiver, hre: 2 m

**Assumption:**
Assuming all other losses are negligible except path loss and Rayleigh fading. Provision for fade margin for 99.8% reliability may be calculated with the help of the Rayleigh distribution chart provided (Treat the Fade Margin as additional loss along the path)

**Requirements:**
i) Write down the system equation
ii) Given that a cell radius of 3 km is required, calculate the path loss
iii) Determine the required power of the transmitter, PT with 99.8% of communication link

### Solution

**i) System Equation:**
```
Pt – Lf + Gt – Lp - FM + GR – Lf = PR
```
Given that feeder losses are negligible, Lf = 0:
```
Pt + Gt – Lp - FM + GR = PR
```

**ii) Path Loss Calculation:**
```
A(hre) = 3.2[log(11.75 hre)]² - 4.97
= 3.2[log(11.75 × 2)]² - 4.97
= 1.045 dB

PL = 69.55 + 26.16 log f - 13.82 log hte - A(hre) + (44.9 - 6.55 log hte)(log d)
= 69.55 + 26.16 log(915) – 13.82 log(50) – 1.045 + (44.9 – 6.55 log(50)) log(3)
= 138.14 dB
```

**iii) Required Transmitter Power:**
From the Rayleigh distribution chart (99.8% reliability): Fade Margin = 25 dB

```
Pt – Lf + Gt – Lp - FM + GR – Lf = PR
Transmit power required Pt = PR + Lf - Gt + Lp + FM - GR + Lf
= -113 + 0 – 6 + 138.14 + 25 - 3 + 0
= 41.14 dBm
```

With transmit power of 41.14 dBm, we can be sure that the receiver will have the probability of 99.8% of receiving the signal.

### Link Budget Example Table

| Parameters | Values (dB) |
|------------|-------------|
| Tx power(dBm) | 45 |
| Antenna cable loss | 3 |
| Tx Antenna Gain (dBi) | 13 |
| EIRP(dBm) (= 45 – 3 + 13) | 55 |
| Path Loss | 150 |
| Fade Margin(dB) | 0 |
| Other margin components(dB) such as building penetration loss | 0 |
| Received isotropic power(dBm) (= 55 – 150 – 0 - 0) | -95 |
| Rx Antenna Gain (dBi) | 4 |
| Mobile antenna cable loss (dB) | 1 |
| Rx signal power (dBm) (= -95 + 4 – 1) | -92 |
| Rx noise power kTB (dBm) | -126 |
| Rx CNR(dB) (= -92 – (-126)) | 34 |
| Target Rx CNR(dB) | 13 |
| Margin(dB) (= 34 – 13) | 21 |

### Video Reference
[How to Calculate the Required Link Budget to Establish a Communication Link with a Case Study](https://youtu.be/meb4a5oeTDA)

---

## Useful Formulas Summary

| Model | Formula |
|-------|---------|
| Free Space Propagation Model | LP (dB) = 32.44 + 20 log d (km) + 20 log f (MHz) |
| Okumura's Hata Model | A(hre) = 3.2[log(11.75 hre)]² - 4.97 (dB)<br>LP = 69.55 + 26.16 log f(MHz) – 13.82 log hte – A(hre) + [44.9 – 6.55 log hte][log d (km)] |
| Plane Earth Model | L (dB) = 120 + 40 log dkm - 20 log[hr(m) ht(m)] |
| Link Budget | Pt – Lf + Gt – Lp - FM + GR – Lf = PR |

---

## Homework

### Problem Statement

A RF engineer is tasked to set up a base station within a cell radius d = 2 km in a new town. The operator team has provided the following parameters:

**Parameters:**
- Frequency of operation = 920 MHz
- Base Station feeder loss, LF = 2 dB
- Base station transmitting antenna gain, GT = 10 dB
- Height of Base station, hT = 40 m
- Mobile station sensitivity, PR = -113 dBm
- Mobile station receiving antenna gain, GR = 3 dB
- Height of Mobile station, hR = 2 m

**Tasks:**
1. The required fade margin for 99% reliability
2. Write down the system equation in terms of the given parameters
3. The path loss, Lp, using Okumura Hata Model
4. The required Base station transmitter power PT

---
