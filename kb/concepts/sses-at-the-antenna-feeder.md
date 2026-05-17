---
id: "0025ab07-01b0-480d-988a-8fc28cf85475"
title: "Sses At The Antenna Feeder"
type: vault_note
vault: wiki
created: 2026-05-17
updated: 2026-05-17
checksum: "sha256:2eeb1397aecdff93"
source: heimdall/auto
---

# Sses At The Antenna Feeder

- sses at the antenna feeder loss, filter and circulator loss, propagation path loss, fade margin, etc
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
Assuming all other losses are negligible except path loss and Rayleigh fading. <!-- id:0025ab07-01b0-480d-988a-8fc28cf85475 ts:2026-05-17 07:49 -->
