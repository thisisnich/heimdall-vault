---
type: tutorial
course: EGE321
module: EGE321-Wireless-Communication
status: reviewed
source: pdf
created: 2026-05-24
tags:
  - EGE321
  - tutorial
  - solution
  - digital-modulation
---

# Tutorial 3b Solution — Digital Modulation

> [!ingest] source: Tutorial 3b Solution.pdf | date: 2026-05-24 | tool: markitdown
> Auto-converted. Edit summary below; re-run ingest to replace block above.

## Summary

ADC/bit rate/symbol rate; M-ary example; Shannon capacity; transceiver blocks; **burst errors from multipath fading**; modulation for bandwidth efficiency. PDF: [[99-ATTACHMENTS/EGE321/Tutorial 3b Solution.pdf]].

---

## Full solutions

SCHOOL OF ENGINEERING

Diploma in Electronics & Computer Engineering (EGDF20)

Wireless Communication & Networking (EGE321)

Tutorial 3:

Communication System Architecture

1)  Name two types of error that commonly occur in digital communication systems and

state the underlying causes of the errors.

Ans:
The two types of error are:
Random Error – due to thermal noise.
Burst Error – due to multipath fading.

2)  Give two reasons why baseband filtering is required in digital communications.

Ans:
To constraint signal bandwidth to improve bandwidth efficiency
To filter off unwanted sidelobes to prevent interference to adjacent channels.

3)  What is the function of encryption?

Ans:
Encryption is the process of translating plain text data (plaintext) into something that
appears to be random and meaningless (ciphertext).

privacy : to prevent unauthorized persons from extracting information from the
channel (eavesdropping)
authentication : to prevent unauthorized persons from injecting information into the
channel (spoofing)

4)

The  transmitter  system  of  digital  communication  system  can  support  a  data  rate  of
16kbps within a bandwidth of 20 kHz by encoding 2 bits in each symbol.

(i)  What is the bandwidth efficiency of the radio link?

       BW efficiency = data rate / bandwidth =16k/20k = 0.8 bps/Hz

(ii)  What is the symbol rate?

        Symbol rate = Data rate/ log2M = 16k/2 = 8ksym/s

Tut 3                                                             Page 1 of 2                                           Effective Date: 17 Apr 2023

5)

State Nyquist sampling theorem.

Ans:
Nyquist Sampling Theorem: The sampling frequency need to be > 2 times the
maximum analogue signal at the input of the ADC to avoid aliasing.

6)  What is the function of the channel encoder in a digital transmitter?

Ans:
Channel encoder: to combat channel impairments by adding redundancy bits for error
detection and correction.

7)  A  mobile  radio  can  support  a  data  rate  of  16kbps  within  a  bandwidth  of  25  kHz  by
encoding  2  bits in  each  symbol.  What  is  the  bandwidth  efficiency  of  the  radio  link?
What is the symbol rate?

BW efficiency = data rate / bandwidth =16k/25k = 0.64 bps/Hz
Symbol rate = Data rate/ log2M = 16k/2 = 8ksym/s

8)

If a 16-symbol state wireless modem is designed to transfer data at a rate of 64kbps,
what is the minimum radio bandwidth required?

BWmin = Symbol rate at RF

= Data rate/log2M = 64k/log216 = 16kHz

Tut 3                                                             Page 2 of 2                                           Effective Date: 17 Apr 2023
