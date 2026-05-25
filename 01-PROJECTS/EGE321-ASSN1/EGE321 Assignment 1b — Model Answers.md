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

#### (c) Three QoS parameters — effect on video streaming & online gaming (3 marks)

QoS ensures the wireless network meets user expectations for time-sensitive applications. Three critical parameters (from [[Lesson2c#Quality of Service (QoS)]], [[Tutorial 2b]]):

**1. Latency** — time delay for a packet to travel from sender to receiver (propagation, serialization, routing, queuing/buffering).

- **Video streaming:** High latency means the player buffer runs ahead of what the network can deliver → **startup delay**, **audio–video lip-sync errors**, and live streams (sports, calls) feeling **out of step** with reality. Short spikes cause **stutter** even if average bitrate is fine.
- **Online gaming:** Games need **fast feedback** (button press → server → screen). High latency (**lag/ping**) makes aiming and movement feel delayed; in FPS or fighting games you see enemies **after** they have already moved (**desync**), which is often **unplayable** in ranked play.

**2. Reliability** — the network **delivers data completely and correctly** to the receiver (low packet loss, few retransmissions).

- **Video streaming:** Lost video packets force **retransmits** or **frame drops** → **buffering** (spinning wheel), **pixelation/blocking**, or resolution **downgrades** (720p → 480p) when the app cannot sustain throughput.
- **Online gaming:** Lost control or state packets cause **rubber-banding** (character snaps back), **hit registration** failures, or sudden **disconnects**/kicks. UDP-based games suffer immediately; TCP-based traffic adds delay while recovering lost data.

**3. Security** — protection against **eavesdropping**, tampering, and **unauthorized access** (authentication, privacy on a shared wireless medium).

- **Video streaming:** Weak security risks **account hijack** or **content interception** on public Wi-Fi; fixing this with **encryption (e.g. WPA3, HTTPS)** adds processing and overhead that can slightly **reduce throughput** or add **latency** on weak links.
- **Online gaming:** Poor security enables **cheating tools**, **DDoS** on your IP, or **session theft**; encryption is required for fair play but on congested Wi-Fi extra handshakes can contribute to **join-time delay** or brief **lag spikes** if the link is already marginal.

*Real-time apps need **low latency + high reliability** first; security must be strong without starving the link of usable capacity.*

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

**Observation A — Diffraction**

Wi-Fi signals do not always travel in a straight line; they propagate as EM waves. When the path to the access point is blocked by a door frame or the edge of a wall, **diffraction** occurs — the waves **bend around** the sharp obstacle into the **shadow region** behind it. Not all of the transmitted energy reaches the receiver (so the signal is **weaker**), but similar to sound being muffled yet still audible through a closed door, enough diffracted energy still reaches the classroom for a usable, though weak, link.

**Observation B — Reflection** *(multipath fading in explanation)*

Large **metal surfaces** and **glass walls** **reflect** Wi-Fi signals (objects large compared to the wavelength). The receiver then gets **multiple copies** of the same signal along different paths (direct + reflected). These copies can add **constructively** (stronger RSSI) or **destructively** (weaker RSSI) depending on phase — this is **multipath fading**. Moving only a few steps shifts the receiver between constructive and destructive “zones”, so the observed signal strength **fluctuates**. *(Diagram: show direct + reflected ray; constructive = waves in phase; destructive = waves out of phase / cancel.)*

**Observation C — Scattering**

In heavy rain, **water droplets** interact with the outdoor Wi-Fi signal. Raindrops are comparable in size to the wavelength, so **scattering** occurs — EM energy is redirected in many directions rather than staying on the direct path. Water also **absorbs** some RF energy. Together, scattering and absorption **increase path loss** between the hotspot and the receiver; heavier rain compounds the effect until the link is practically unusable.

*Refs: [[tutorial-4-solution-slides]] (diffraction, reflection, scattering/raindrops); [[Lesson4c#Radio Propagation Mechanisms]]; multipath fading — [[Lesson3c]], [[Lesson5c#Fade Margin]].*

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
