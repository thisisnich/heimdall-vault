---
id: "e37077db-8be2-46ba-894d-9afa749dd09a"
title: "Eech Source A To D Conversion"
type: vault_note
vault: wiki
created: 2026-05-17
updated: 2026-05-17
checksum: "sha256:e1855477186634ca"
source: heimdall/auto
---

# Eech Source A To D Conversion

- eech source & A-to-D conversion of speech |
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

### 2. <!-- id:e37077db-8be2-46ba-894d-9afa749dd09a ts:2026-05-17 07:49 -->
- eech source & A-to-D conversion of speech |
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

### 2. <!-- id:e37077db-8be2-46ba-894d-9afa749dd09a ts:2026-05-17 07:49 -->
