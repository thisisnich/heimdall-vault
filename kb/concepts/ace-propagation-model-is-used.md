---
id: "5cd0e706-d955-474c-9aaf-372bdb910dd5"
title: "Ace Propagation Model Is Used"
type: vault_note
vault: wiki
created: 2026-05-17
updated: 2026-05-17
checksum: "sha256:afd2cac4fc3a160d"
source: heimdall/auto
---

# Ace Propagation Model Is Used

- ace propagation model is used to predict signal strength when the transmitter and receiver have a clear, unobstructed line of sight path between them. This is an Ideal Model.

**Formula:**
```
PR = Received Power in Watts
PT = Transmitted Power in Watts
GT = Transmit Antenna Gain
GR = Receive Antenna Gain
λ = Wavelength in meters
d = Tx/Rx Separation in same units as wavelength in meters
L = system loss that is not related to propagation (L ≥ 1)
L = 1 (if there is no system hardware losses)
```

### Path Loss Fundamentals

**Definition:**
The path loss represents the signal attenuation after the signal leaves the transmit antenna and before reaching the receive antenna. It is defined as the difference (in dB) between the transmitted power and the received power with unity antenna gain.

**Friis Formula:**
The Friis formula shows that the received signal power falls off as the square of the transmitter to receiver separation distance (d):
- PR ∝ d⁻²

**Factors Affecting Path Loss:**
Besides frequency and distance between antennas, path loss is also dependent on:
- Antenna heights
- Terrain environment – urban, rural etc
- Weather

**Free Space Path Loss Formula (in dB):**
```
LP (dB) = 32.44 + 20 log d (km) + 20 log f (MHz)
```

### Example

**Problem:**
A radio communication system is operating at 400 MHz and has a transmit power of 25W and has an effective range of 2000 m. The transmitting and receiving antenna gains are 25dB and 3 dB respectively.

**Questions:**
1. <!-- id:5cd0e706-d955-474c-9aaf-372bdb910dd5 ts:2026-05-17 07:49 -->
- ace propagation model is used to predict signal strength when the transmitter and receiver have a clear, unobstructed line of sight path between them. This is an Ideal Model.

**Formula:**
```
PR = Received Power in Watts
PT = Transmitted Power in Watts
GT = Transmit Antenna Gain
GR = Receive Antenna Gain
λ = Wavelength in meters
d = Tx/Rx Separation in same units as wavelength in meters
L = system loss that is not related to propagation (L ≥ 1)
L = 1 (if there is no system hardware losses)
```

### Path Loss Fundamentals

**Definition:**
The path loss represents the signal attenuation after the signal leaves the transmit antenna and before reaching the receive antenna. It is defined as the difference (in dB) between the transmitted power and the received power with unity antenna gain.

**Friis Formula:**
The Friis formula shows that the received signal power falls off as the square of the transmitter to receiver separation distance (d):
- PR ∝ d⁻²

**Factors Affecting Path Loss:**
Besides frequency and distance between antennas, path loss is also dependent on:
- Antenna heights
- Terrain environment – urban, rural etc
- Weather

**Free Space Path Loss Formula (in dB):**
```
LP (dB) = 32.44 + 20 log d (km) + 20 log f (MHz)
```

### Example

**Problem:**
A radio communication system is operating at 400 MHz and has a transmit power of 25W and has an effective range of 2000 m. The transmitting and receiving antenna gains are 25dB and 3 dB respectively.

**Questions:**
1. <!-- id:5cd0e706-d955-474c-9aaf-372bdb910dd5 ts:2026-05-17 07:49 -->
