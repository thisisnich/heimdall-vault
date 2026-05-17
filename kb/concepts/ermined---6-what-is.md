---
id: "7ca8d807-1e70-4b4a-ae5c-d4d75f680184"
title: "Ermined   6 What Is"
type: vault_note
vault: wiki
created: 2026-05-17
updated: 2026-05-17
checksum: "sha256:f5177e030cd3755c"
source: heimdall/auto
---

# Ermined   6 What Is

- ermined.

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
3. <!-- id:7ca8d807-1e70-4b4a-ae5c-d4d75f680184 ts:2026-05-17 07:49 -->
