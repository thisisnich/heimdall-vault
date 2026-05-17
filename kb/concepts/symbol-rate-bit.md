---
id: "c2e82f8c-8ff0-4624-a077-1fee63ffda3e"
title: "Symbol Rate Bit"
type: vault_note
vault: wiki
created: 2026-05-17
updated: 2026-05-17
checksum: "sha256:2cd26e28e009e984"
source: heimdall/auto
---

# Symbol Rate Bit

- *
Symbol rate = bit rate / the number of bits to represent a symbol

**Unit:** Symbol / second or sps

### Video Reference
[Digital Modulation Part 1. How Data Speed Works: Throughput, Bits, Baud & Channel Rate Demystified!](https://youtu.be/LkG0iXV4d2E)

---

## Binary Signaling

### Fundamentals
Every 1 second, 1 bit of data is sent which is 1 bps
- 10 seconds: data "1 1 0 1 1 0 0 1 0 0"
- Bit rate = 1 bps
- 1 Symbol = 1 bit, then the symbol rate is 1 sps

### Binary Signaling Characteristics
- One Symbol is used to represent One bit
- Symbol Rate = Bit Rate
- 2 possible states: "1" or "0"

### ASK, BPSK, FSK
Binary modulation schemes:
- ASK (Amplitude Shift Keying)
- BPSK (Binary Phase Shift Keying)
- FSK (Frequency Shift Keying)

---

## M-ary Signaling

### Fundamentals
- K = number of bits make into a symbol
- M = number of possible state = 2^K

**For Binary Signaling (K=1):**
- M = 2

**For M-ary Signaling:**
- One symbol is represented by more than 1 bit
- Group of k bits represented by One Symbol from 2^K-symbol set
- Symbol Rate = Bit Rate / k = Bit Rate / log₂M

**Example (K=4):**
- M = 2⁴ = 16

---

## Example (1)

**Problem:**
A mobile radio can support a symbol rate of 8kbps within a bandwidth of 20 kHz by encoding 2 bits in each symbol. Compute:
1. The data/bit rate
2. The bandwidth efficiency of the radio link

**Solution:**

**1. Data/Bit rate:**
```
Data/Bit rate = Symbol rate × k (Given, k is 2)
= 2 × 8kbps = 16kbps
```

**2. <!-- id:c2e82f8c-8ff0-4624-a077-1fee63ffda3e ts:2026-05-17 07:49 -->
- *
Symbol rate = bit rate / the number of bits to represent a symbol

**Unit:** Symbol / second or sps

### Video Reference
[Digital Modulation Part 1. How Data Speed Works: Throughput, Bits, Baud & Channel Rate Demystified!](https://youtu.be/LkG0iXV4d2E)

---

## Binary Signaling

### Fundamentals
Every 1 second, 1 bit of data is sent which is 1 bps
- 10 seconds: data "1 1 0 1 1 0 0 1 0 0"
- Bit rate = 1 bps
- 1 Symbol = 1 bit, then the symbol rate is 1 sps

### Binary Signaling Characteristics
- One Symbol is used to represent One bit
- Symbol Rate = Bit Rate
- 2 possible states: "1" or "0"

### ASK, BPSK, FSK
Binary modulation schemes:
- ASK (Amplitude Shift Keying)
- BPSK (Binary Phase Shift Keying)
- FSK (Frequency Shift Keying)

---

## M-ary Signaling

### Fundamentals
- K = number of bits make into a symbol
- M = number of possible state = 2^K

**For Binary Signaling (K=1):**
- M = 2

**For M-ary Signaling:**
- One symbol is represented by more than 1 bit
- Group of k bits represented by One Symbol from 2^K-symbol set
- Symbol Rate = Bit Rate / k = Bit Rate / log₂M

**Example (K=4):**
- M = 2⁴ = 16

---

## Example (1)

**Problem:**
A mobile radio can support a symbol rate of 8kbps within a bandwidth of 20 kHz by encoding 2 bits in each symbol. Compute:
1. The data/bit rate
2. The bandwidth efficiency of the radio link

**Solution:**

**1. Data/Bit rate:**
```
Data/Bit rate = Symbol rate × k (Given, k is 2)
= 2 × 8kbps = 16kbps
```

**2. <!-- id:c2e82f8c-8ff0-4624-a077-1fee63ffda3e ts:2026-05-17 07:49 -->
