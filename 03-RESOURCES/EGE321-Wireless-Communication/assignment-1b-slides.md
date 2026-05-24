---
type: assignment
course: EGE321
module: EGE321-Wireless-Communication
status: draft
source: pdf
created: 2026-05-24
tags:
  - EGE321
  - assignment
  - assn1
---

# EGE321 Assignment 1b (May 2026)

> [!ingest] source: EGE321 26S1 Assignment 1b(1).docx | date: 2026-05-24 | tool: markitdown
> Auto-converted. Edit summary below; re-run ingest to replace block above.

## Summary

ASSN1 brief (Ch 1 + partial Ch 2): **Section A** — duplex modes, symbol/bit rate & QoS, FDMA/TDMA, EIRP link, propagation scenarios; **Section B** — free-space path loss table/graph (3 km), Okumura–Hata + Rayleigh link budget (950 MHz, 4 km). **Model answers:** [[01-PROJECTS/EGE321-ASSN1/EGE321 Assignment 1b — Model Answers]]. Original: [[99-ATTACHMENTS/EGE321/EGE321-26S1-Assignment-1b.docx]].

---

## Instructions

- Section A: 3 questions (40 marks) · Section B: 2 questions (60 marks)
- Answer all; show workings, labelled diagrams, units
- Diagrams: software or neat hand-drawn

---

## Section A (40 marks)

### Question 1 (10 marks)

With diagrams: name, draw, and explain the **three radio transmission modes** (simplex, half-duplex, full-duplex) with an example each.

### Question 2

1. Symbol rate **50 ksymbols/s**, bandwidth **100 kHz**, **6 bits/symbol** — find **data rate** (3) and **bandwidth efficiency** (3).
2. **Three QoS parameters** and effect on video/gaming when poor (3).
3. Frequency–time diagrams: **(i)** 3 users FDMA; **(ii)** 9 users = 3 FDMA × 3 TDMA (6).

### Question 3

RF chain: cable **2 dB** loss, PA **10 dB**, antenna **6 dB** gain; target **EIRP = 50 dBm**.

1. Mark where **EIRP** is on the figure (2).
2. Calculate required **transmit power** \(P_T\) (4).
3. Wi-Fi observations A (door closed), B (cafeteria metal/glass), C (heavy rain) — one propagation phenomenon each (9).

---

## Section B (60 marks)

### Question 4

Free space: \(L_P = 32.4 + 20\log f_{\text{MHz}} + 20\log d_{\text{km}}\), **d = 3 km**.

| Task | Marks |
|------|-------|
| (a) Table: \(L_P\) for f = 200…2000 MHz | 10 |
| (b) Plot \(L_P\) vs f | 14 |
| (c) Describe f vs \(L_P\) trend and why | 6 |

### Question 5

Cellular link: **950 MHz**, \(P_r = -118\) dBm, \(G_t = 4\) dB, \(G_r = 3\) dB, \(h_{te} = 60\) m, \(h_{re} = 2\) m, **d = 4 km**; Okumura–Hata path loss + Rayleigh **fade margin** (99.8%).

| Task | Marks |
|------|-------|
| (a) Labelled BS–mobile diagram | 4 |
| (b) System equation | 4 |
| (c) Path loss \(L_p\) | 8 |
| (d) Required \(P_T\) | 8 |
| (e) If \(P_T = 40\) dBm only — sufficient? | 6 |

*(Rayleigh chart embedded in original DOCX — not reproduced here.)*

---

## Raw (archive)

See [[99-ATTACHMENTS/EGE321/EGE321-26S1-Assignment-1b.docx]] for figures (RF block diagram, Rayleigh chart).
