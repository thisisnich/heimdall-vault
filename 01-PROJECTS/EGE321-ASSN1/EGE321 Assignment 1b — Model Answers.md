---
type: assignment
course: EGE321
module: EGE321-Wireless-Communication
status: draft
source: manual
created: 2026-05-24
due: 2026-05-31
tags:
  - EGE321
  - assignment
  - model-answers
---

> **Source:** [[03-RESOURCES/EGE321-Wireless-Communication/assignment-1b-slides|Assignment brief (ingested)]] · PDF/DOCX: [[99-ATTACHMENTS/EGE321/EGE321-26S1-Assignment-1b.docx]]
> **Vault refs:** Lessons 1c–5c · Tutorials 1b, 2b · **Solutions:** [[tutorial-1b-solution-slides|Tut 1b Sol]] · [[tutorial-2-solution-slides|Tut 2 Sol]] · [[tutorial-3b-solution-slides|Tut 3b Sol]] · [[tutorial-4-solution-slides|Tut 4 Sol]] · [[tutorial-5c-solution-slides|Tut 5c Sol]]

Model answers from vault notes + ingested tutorial solutions. **Copy into your submission DOCX**; add diagrams by hand/software.

---

## Section A (40 marks)

### Question 1 — Transmission modes (10 marks)

| Mode | Diagram (sketch) | How it works | Example |
|------|------------------|--------------|---------|
| **Simplex** | `TX ──────────────► RX` (one arrow only) | One-way only; cannot transmit back on same link | FM radio broadcast, TV broadcast, pager |
| **Half-duplex** | `TX ◄──────────────► RX` (one direction at a time) | Both directions, **not simultaneous**; same channel/time shared | Walkie-talkie, wireless keyboard/mouse |
| **Full-duplex** | `TX ⇄ RX` (both arrows at once) | Simultaneous transmit and receive; often **two frequencies** (TX and RX) | Mobile phone (3G/4G/LTE), cordless phone |

*Sources: [[Lesson1c#Types of Radio In Wireless Communications]], [[Tutorial_1b#Tutorial 1: RF Fundamentals]]*

---

### Question 2

#### (a) Data rate (3 marks)

\[
\text{Data rate} = \text{symbol rate} \times \text{bits per symbol}
= 50{,}000 \times 6 = 300{,}000\ \text{bps} = \mathbf{300\ kbps}
\]

*Ref: [[Lesson3c#Example (1)]]*

#### (b) Bandwidth efficiency (3 marks)

\[
\eta_B = \frac{\text{data rate}}{\text{bandwidth}}
= \frac{300{,}000}{100{,}000} = \mathbf{3\ bps/Hz}
\]

*Ref: [[Lesson3c#Example (1)]]*

#### (c) Three QoS parameters (3 marks)

| Parameter | Meaning | Poor value → effect on streaming / gaming |
|-----------|---------|-------------------------------------------|
| **Latency** | Delay for packets to travel (propagation, queuing, protocol) | High latency → lag, desync, stutter in video; unplayable reaction time in games |
| **Reliability** | Network delivers data correctly and completely | Packet loss / drops → buffering, frozen video, disconnects |
| **Security** | Protection from eavesdropping / unauthorized access | Weak security → risk of interception; may force extra overhead that hurts performance |

*Ref: [[Lesson2c#Quality of Service (QoS)]], [[Tutorial 2b#Question 9]]*

#### (d) FDMA / FDMA+TDMA diagrams (6 marks)

**i) 3 users — FDMA**

- Draw **frequency (f)** on vertical axis, **time (t)** on horizontal axis.
- Three **horizontal bands** \(f_1, f_2, f_3\) spanning full time.
- Each user transmits **continuously** on its own frequency.

**ii) 9 users — 3 frequencies × 3 time slots**

- Three frequency bands \(f_1, f_2, f_3\).
- Each band split into **3 time slots** → \(3 \times 3 = 9\) users.
- Users separated by **frequency (FDMA)** and **time (TDMA)** within each band.

*Ref: [[Tutorial 2b#Question 4]], [[Lesson2c#Combination of TDMA and FDMA]]*

---

### Question 3 — EIRP & propagation (15 marks)

**Chain (from brief):** \(P_T \rightarrow\) cable loss \(L_f=2\) dB \(\rightarrow\) PA gain \(G=10\) dB \(\rightarrow\) antenna \(G_T=6\) dB.

#### (a) Where is EIRP? (2 marks)

Mark EIRP at the **antenna reference / feed point** — i.e. **after** cable loss and PA, **immediately before** radiation (equivalent isotropic power that would produce the same field). On the figure: place label **EIRP** at the output of the TX chain going into the antenna.

*Ref: [[Lesson5c#EIRP Fundamentals]]*

#### (b) Transmit power for EIRP = 50 dBm (4 marks)

\[
\text{EIRP (dBm)} = P_T\text{ (dBm)} - L_f + G_{\text{PA}} + G_T
\]

\[
50 = P_T - 2 + 10 + 6 \Rightarrow P_T = 50 - 14 = \mathbf{36\ dBm}
\]

\[
P_T = 10^{(36-30)/10} = 10^{0.6} \approx \mathbf{3.98\ W} \approx 4\ W
\]

*Ref: [[Lesson5c#EIRP Fundamentals]] (example uses \( \text{EIRP} = P_T - L_f + G_T \); include PA gain in chain)*

#### (c) Wi-Fi observations (9 marks)

| Observation | Phenomenon | Brief explanation |
|-------------|------------|-------------------|
| **A** — usable signal through closed door, no LOS to AP | **Diffraction** | Signal bends around/obstacle edges; energy reaches **shadow region** behind door/walls so link still works at low level |
| **B** — signal varies over a few steps in cafeteria (metal, glass) | **Multipath fading** (reflection/scattering) | Many reflected paths add constructively/destructively; small movement changes phase → **rapid RSSI changes** |
| **C** — outdoor hotspot poor in heavy rain | **Scattering** | Raindrops are comparable to λ; energy scattered in many directions (weaker at receiver). Used in weather radar; extra loss in heavy rain degrades outdoor link |

*A: [[tutorial-4-solution-slides#Tutorial 4 Solution]] (diffraction). B: reflection → fading ([[tutorial-4-solution-slides]]); multipath ([[tutorial-3b-solution-slides]]). C: [[tutorial-4-solution-slides]] Q2(c) — raindrops → scattering.*

---

## Section B (60 marks)

### Question 4 — Free-space path loss

Formula (from brief): \(L_P = 32.4 + 20\log f_{\text{MHz}} + 20\log d_{\text{km}}\), \(d = 3\) km.

Constant term: \(32.4 + 20\log 3 = 32.4 + 9.54 = 41.94\) dB.

#### (a) Table (10 marks)

| Distance (km) | Frequency (MHz) | \(L_P\) (dB) |
|---------------|-----------------|--------------|
| 3 | 200 | **87.96** |
| 3 | 400 | **93.98** |
| 3 | 600 | **97.51** |
| 3 | 800 | **100.00** |
| 3 | 1000 | **101.94** |
| 3 | 1200 | **103.53** |
| 3 | 1400 | **104.86** |
| 3 | 1600 | **106.02** |
| 3 | 1800 | **107.05** |
| 3 | 2000 | **107.96** |

*Ref: [[Lesson4c#Free Space Path Loss Formula (in dB)]] (vault uses 32.44; assignment uses 32.4 — use **32.4** here).*

#### (b) Graph (14 marks)

- **X-axis:** Frequency (MHz), 200–2000
- **Y-axis:** Path loss \(L_P\) (dB), ~88–108
- Plot points from table; connect with smooth curve (approximately **linear** in log‑\(f\)).

#### (c) Relationship (6 marks)

- **Trend:** Path loss **increases** as frequency increases (at fixed distance).
- **Why:** \(L_P \propto 20\log f\); higher frequency → shorter wavelength → greater free-space spreading loss for the same distance.

---

### Question 5 — Cellular link budget (Okumura–Hata + Rayleigh)

Given: \(f=950\) MHz, \(P_r=-118\) dBm, \(G_t=4\) dB, \(G_r=3\) dB, \(h_{te}=60\) m, \(h_{re}=2\) m, \(d=4\) km, negligible feeder loss.

#### (a) Diagram (4 marks)

Sketch: **Base station** (antenna \(G_t\), height \(h_{te}\)) —— **4 km** —— **Mobile** (antenna \(G_r\), height \(h_{re}\)). Label \(P_T\), path loss \(L_P\), fade margin FM, received power \(P_r\).

#### (b) System equation (4 marks)

With \(L_f = 0\):

\[
P_t + G_t - L_p - FM + G_r = P_r
\]

*Ref: [[Lesson5c#Radio Link Budget Equation]]*

#### (c) Path loss — Okumura–Hata (8 marks)

\[
A(h_{re}) = 3.2[\log(11.75\, h_{re})]^2 - 4.97
= 3.2[\log(23.5)]^2 - 4.97 \approx \mathbf{1.05\ dB}
\]

\[
\begin{aligned}
L_p &= 69.55 + 26.16\log f - 13.82\log h_{te} - A(h_{re}) \\
&\quad + [44.9 - 6.55\log h_{te}]\log d \\
&= 69.55 + 26.16\log(950) - 13.82\log(60) - 1.05 \\
&\quad + [44.9 - 6.55\log(60)]\log(4) \\
&\approx \mathbf{141.85\ dB}
\end{aligned}
\]

*Ref: [[Lesson5c#Okumura's Hata Model]]*

#### (d) Required \(P_T\) @ 99.8% reliability (8 marks)

**Fade margin @ 99.8%:** **\(FM = 25\) dB** (Rayleigh chart on assignment). *Tutorial 5c solution uses 18 dB @ 99% only — not this question.*

\[
P_t = P_r - G_t + L_p + FM - G_r
= -118 - 4 + 141.85 + 25 - 3
\approx \mathbf{41.85\ dBm}
\]

*Link equation: [[tutorial-5c-solution-slides]] · Hata steps match lesson/tut examples.*

#### (e) Is 40 dBm enough? (6 marks)

\[
P_{r,\text{actual}} = P_t + G_t - L_p - FM + G_r
= 40 + 4 - 141.85 - 25 + 3
\approx \mathbf{-119.85\ dBm}
\]

Compare: \(-119.85 < -118\) dBm → **No**, the link **does not** meet receiver sensitivity (about **1.85 dB short**), even with 99.8% fade margin included.

---

## Submission checklist

- [ ] Paste answers into official DOCX/PDF; keep workings
- [ ] Draw Q1 mode diagrams, Q2 FDMA/TDMA grids, Q3 EIRP on figure, Q4 graph, Q5 link diagram
- [ ] Add name/student ID per cover sheet
