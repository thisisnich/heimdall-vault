---
id: "a8b4d903-9c8e-4bd7-a63e-da810aaa1799"
title: "10 Log Signal Power"
type: vault_note
vault: wiki
created: 2026-05-17
updated: 2026-05-17
checksum: "sha256:69758dc77876d46f"
source: heimdall/auto
---

# 10 Log Signal Power

- = 10 log (signal power / noise power)
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
- PR = Rx sensitivity for a specified SNR or BER. <!-- id:a8b4d903-9c8e-4bd7-a63e-da810aaa1799 ts:2026-05-17 07:49 -->
