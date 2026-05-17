---
id: "d30b3cfa-1538-4396-9692-676b675e6f40"
title: "Efficiency Of The Radio Link"
type: vault_note
vault: wiki
created: 2026-05-17
updated: 2026-05-17
checksum: "sha256:7219ab67018b7897"
source: heimdall/auto
---

# Efficiency Of The Radio Link

- efficiency of the radio link

**Solution:**

**1. Data/Bit rate:**
```
Data/Bit rate = Symbol rate × k (Given, k is 2)
= 2 × 8kbps = 16kbps
```

**2. Bandwidth efficiency:**
```
BW efficiency = data rate / bandwidth
= 16k / 20k = 0.8 bps/Hz
```

---

## Shannon Capacity Theorem

### Fundamentals
The Shannon-Hartley capacity limit for error-free communication is given by:

**Channel Capacity:**
```
C = BW × log₂(1 + S/N) bps
```

The Shannon-Hartley theorem tells the maximum rate at which information can be transmitted over a communications channel of a specified bandwidth in the presence of noise.

### Example
**Problem:**
A telephone line has a bandwidth of 0 to 4 kHz, and the maximum signal to noise ratio (S/N) on the line is 20 dB. What is the channel capacity for error-free transmission?

**Solution:**
```
BW = Highest freq – lowest freq = 4kHz
C = BW × log₂(1 + S/N)
Therefore C = (4000 - 0) × log₂(1 + 1020/10)
= 4000 × log₂(101)
= 26.63 kbps
```

---

## Digital Transceiver Building Blocks

### Source Encoder
**Function:**
Convert signal from source into digital signal
- Use as few binary digits as possible to represent the signal
- Efficient representation results in little or no redundancy
- This sequence of binary digits is called information sequence

**Source Encoding or Data Compression:**
The process of efficiently converting the output of either analog or digital source into a sequence of binary digits.

### Channel Encoder
**Function:**
Introduce some redundanc <!-- id:d30b3cfa-1538-4396-9692-676b675e6f40 ts:2026-05-17 07:49 -->
- efficiency of the radio link

**Solution:**

**1. Data/Bit rate:**
```
Data/Bit rate = Symbol rate × k (Given, k is 2)
= 2 × 8kbps = 16kbps
```

**2. Bandwidth efficiency:**
```
BW efficiency = data rate / bandwidth
= 16k / 20k = 0.8 bps/Hz
```

---

## Shannon Capacity Theorem

### Fundamentals
The Shannon-Hartley capacity limit for error-free communication is given by:

**Channel Capacity:**
```
C = BW × log₂(1 + S/N) bps
```

The Shannon-Hartley theorem tells the maximum rate at which information can be transmitted over a communications channel of a specified bandwidth in the presence of noise.

### Example
**Problem:**
A telephone line has a bandwidth of 0 to 4 kHz, and the maximum signal to noise ratio (S/N) on the line is 20 dB. What is the channel capacity for error-free transmission?

**Solution:**
```
BW = Highest freq – lowest freq = 4kHz
C = BW × log₂(1 + S/N)
Therefore C = (4000 - 0) × log₂(1 + 1020/10)
= 4000 × log₂(101)
= 26.63 kbps
```

---

## Digital Transceiver Building Blocks

### Source Encoder
**Function:**
Convert signal from source into digital signal
- Use as few binary digits as possible to represent the signal
- Efficient representation results in little or no redundancy
- This sequence of binary digits is called information sequence

**Source Encoding or Data Compression:**
The process of efficiently converting the output of either analog or digital source into a sequence of binary digits.

### Channel Encoder
**Function:**
Introduce some redundanc <!-- id:d30b3cfa-1538-4396-9692-676b675e6f40 ts:2026-05-17 07:49 -->
