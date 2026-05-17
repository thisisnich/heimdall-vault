---
tags:
  - EGE321
  - lesson3c
  - wireless-systems
  - digital-modulation
  - chapter-2
  - communications-system
course: EGE321 Wireless Communication & Networking
topic: Lesson 3c - Wireless Communications System (Chapter 2)
source: Lesson3c.pptx
converted: 2026-05-07
type: Lesson
status: Completed
---

> 📚 **Related:** [[NYPY3 - Main Index|NYPY3 Index]] | [[03-RESOURCES/EGE321-Wireless-Communication/Lesson2c.md|Lesson 2c]] | [[📅 Schedule & Assessments Dashboard|Assessment Dashboard]]

> 📚 **Related:** [[NYPY3 - Main Index|NYPY3 Index]] | [[03-RESOURCES/EGE321-Wireless-Communication/Lesson2c.md|Lesson 2c]] | [[📅 Schedule & Assessments Dashboard|Assessment Dashboard]]

> 📚 **Related:** [[NYPY3 - Main Index|NYPY3 Index]] | [[03-RESOURCES/EGE321-Wireless-Communication/Lesson2c.md|Chapter 2]] | [[📅 Schedule & Assessments Dashboard|Assessment Dashboard]]

# Lesson 3c - Wireless Communications System (Chapter 2)

## Contents

- 2. Wireless Communications System
- 2.1 Communication System Architecture
- 2.2 Radio Propagation and Link Budget Analysis
- 2.3 Digital Modulation Technique

---

## Analog vs Digital Signals

### Analog Signals
An analogue signal is defined as a physical time-varying quantity and is usually smooth and continuous.

### Digital Signals
A digital signal, on the other hand, is made up of discrete symbols selected from a finite set.

---

## Digital Transceiver Architecture

### Input Signal
The source of information can be analog or digital:
- Analog: audio or video signal
- Digital: teletype signal

In digital communication, the signal produced by this source is converted into digital signal consisting of 1's & 0's.

---

## Analog to Digital Converter (ADC)

### Process of Converting Analog to Digital Format

**ADC Components:**
- Sampling Function Generator
- Encoder
- Sampling pulses
- Analog Input Signal

**Key Parameters:**
- TS = sampling interval (s)
- fS = 1/TS = sampling frequency (Hz)
- PCM Codes: 011 110 100 010...

---

## Digital Transceiver Building Block – ADC

### Information Transfer Rate (Bit Rate)

**What is bit rate?**
Bit rate is the number of bits that are conveyed or processed per unit of time.

**Information transfer rate or Bit rate:**
The speed at which binary information (bits) can be transferred from source to destination.

**Example:**
If 10 bits of information are sent every second:
- Information transfer rate = 10 bits / 1s = 10 bps (in 1 sec, 10 bits can tx)

**Unit:** bits / second or bps

---

## Symbol Rate

### What is symbol rate?
Symbol rate (baud rate or modulation rate) is the number of symbol changes, waveform changes, or signalling events across the transmission medium per time unit using a digitally modulated signal or a line code.

**Examples:**
- If 1 bit = 1 symbol, then the symbol rate would be the same as the bit rate
- If 2 bits = 1 symbol, then the symbol rate would be half of the bit rate

**Formula:**
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
Introduce some redundancy in the binary information sequence that can be used at the receiver to overcome the effects of noise and interference encountered in transmission.

### Digital Modulator
**Function:**
Convert the binary sequence into electric signals so that it can transmit on channel
- Maps binary sequences into signal waveforms
- Example: represent 1 by sin x and 0 by cos x

### Communication Channel
The physical medium used for transmitting signals from transmitter to receiver:
- Wireless: atmosphere
- Traditional telephony: wired
- Optical channels
- Under water acoustic channels

### Digital Demodulator
**Function:**
Processes the channel corrupted transmitted waveform and reduces the waveform to the sequence of numbers that represents estimates of the transmitted data symbols.

### Channel Decoder
**Function:**
Attempts to reconstruct the original information sequence from the knowledge of the code used by the channel encoder and the redundancy contained in the received data.

### Source Decoder
**Function:**
If an analog signal is desired, tries to decode the sequence from the knowledge of the encoding algorithm, resulting in the approximate replica of the input at the transmitter end.

### Output Transducer
Finally, we get the desired signal in desired format (analog or digital).

---

## Video References

### Source Encoder, Channel Encoder & Encryption
[The Roles of Source Encoder, Channel Encoder & Encryption of a Transmitter of Digital Transceiver](https://youtu.be/ymF3ZMlp4f8)

### Modulator Roles (ASK, FSK & PSK)
[Digital Transceiver: Roles of Modulator (ASK, FSK & PSK). Draw the Time Diagram of ASK, FSK & PSK](https://youtu.be/EzkrhXHouNg)

---

## Examples

### Example 1
**Question:** What is function of the source coding in a digital transmitter?

**Answer:**
The function of the source coding is to perform data compression of the input source to achieve a minimal representation of the input waveform.

### Example 2
**Question:** What is the function of the channel encoder in a digital transmitter?

**Answer:**
Channel encoder is to combat channel impairments by adding redundancy bits for error detection and correction.

---

## Basic Elements of Digital Communication System

| Component | Function |
|-----------|----------|
| Information source and input transducer | e.g. speech source & A-to-D conversion of speech |
| Source encoder | removes redundancy, e.g. speech compression |
| Channel encoder | adds redundancy (e.g. linear block codes, cyclic codes & convolutional codes) to combat channel impairment |
| Digital modulator & Upconverter | baseband filtering, data formatting based on modulation scheme (BPSK, QPSK), upconversion, power amplification, etc |
| Communication Channel | propagation loss, shadowing, multipath, etc |
| Digital demodulator & Downconverter | signal processing |
| Channel decoder | error correction |
| Source decoder | signal reconstruction |
| Output Transducer | output conversion |
| Encryption | security of information |
| Decryption | restore original data |

---

## Encryption & Decryption

**Encryption:**
The process of translating plain text data (plaintext) into something that appears to be random and meaningless (ciphertext).

**Decryption:**
The process of converting ciphertext back to plaintext. To encrypt more than a small amount of data, symmetric encryption is used.

---

## Channel Coding - Types of Errors

### 1. Random Errors
- Occur randomly in the received sequence
- Mainly due to thermal noise, also called Gaussian noise
- Codes designed to correct random errors are called random-error-correcting codes
- Examples: Block Codes & Convolutional Codes

### 2. Burst Errors
- Occur in clusters of message in the received sequence
- Mainly caused by multipath fading
- Can be corrected using a combination of random-error correcting codes & time interleaving

### 3. Diffuse Errors
- Combination of burst & random errors
- Can be corrected using concatenated codes
- Example: random-error-correcting codes + Reed-Solomon Codes

---
