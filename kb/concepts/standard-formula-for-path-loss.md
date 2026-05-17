---
id: "5e34fb2f-50ca-43bc-9826-a4fecf31b632"
title: "Standard Formula For Path Loss"
type: vault_note
vault: wiki
created: 2026-05-17
updated: 2026-05-17
checksum: "sha256:98d54daae52806f3"
source: heimdall/auto
---

# Standard Formula For Path Loss

- **Standard Formula for Path Loss in Urban Areas:**

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
= 141 <!-- id:5e34fb2f-50ca-43bc-9826-a4fecf31b632 ts:2026-05-17 07:49 -->
