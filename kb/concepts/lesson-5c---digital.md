---
id: "f26a17e7-e1c0-421d-b9e4-67ef382fc279"
title: "Lesson 5C   Digital"
type: vault_note
vault: wiki
created: 2026-05-17
updated: 2026-05-17
checksum: "sha256:0be1017895a096e1"
source: heimdall/auto
---

# Lesson 5C   Digital

- # Lesson 5c - Digital Modulation Technique (Chapter 2.3)

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
- hte: Effective height of transmitter betwe <!-- id:f26a17e7-e1c0-421d-b9e4-67ef382fc279 ts:2026-05-17 07:49 -->
- # Lesson 5c - Digital Modulation Technique (Chapter 2.3)

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
- hte: Effective height of transmitter betwe <!-- id:f26a17e7-e1c0-421d-b9e4-67ef382fc279 ts:2026-05-17 07:49 -->
