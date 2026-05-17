---
tags:
  - EGE321
  - wireless
  - lab
  - spectrum-analyser
  - dB
  - dBm
course: EGE321 Wireless Communications & Networking
topic: Lab 1 — Loopback Test within Spectrum Analyser
source: EGE321 Lab1 Loopback Test within SPA.pdf
converted: 2026-04-24
---

> 📚 **Related:** [[EGE321 Wireless Communication & Networking - MOC|EGE321 MOC]] | [[EGE321 Wireless Communication & Networking/Lesson1c|Chapter 1 Notes]] | [[EGE321 Wireless Communication & Networking/Tutorial_1b|Tutorial 1]]

# EGE321 / LAB 1 — Loopback Test within Spectrum Analyser

**School of Engineering**
**Course:** Diploma in Electronic & Computer Engineering (EGDF20)
**Module:** EGE321 - Wireless Communications & Networking

| | |
|---|---|
| **Name:** | **Date:** |
| **Group:** | |

---

## 1. Objectives

1.1 To familiarise with the use of a Signal Analyser for frequency and amplitude/power measurements

---

## 2. Equipment

2.1 Signal/Spectrum Analyser **R&S FPC1500**

---

## Introduction

**Oscilloscopes** are commonly used to observe the exact wave shape of an electrical signal. In addition to the amplitude of the signal, an oscilloscope can show distortion, the time between two events (such as pulse width, period, or rise time) and relating timing of two related signals.

A **Signal Analyser** is an instrument that is used to analyse a signal in the frequency domain by displaying the spectrum of the signal. It can display raw, unprocessed signal information such as voltage, power, frequency, sidebands and harmonic content.

**Spectrum Analysers** measure the amplitude level, power level and frequency of signals in the frequency domain.

---

## Front Panel — R&S FPC1500

| Control | Function |
|---------|----------|
| **Spectrum Mode Selected** | Activates spectrum analysis mode |
| **Selection Buttons** | Mode/function selection |
| **Preset** | Resets all parameters to default |
| **Dial** | Adjust values |
| **Step-keys** | Increment/decrement values |
| **Power On/Off** | Power button |
| **RF Input** | Signal input (50Ω) |
| **RF Output** | Signal generator output (50Ω) |

---

## Procedure

**1.** Switch on R&S FPC1500 Signal Analyser by pressing Power button. In this experiment, you will be changing the parameters of the analyser (span, centre frequency, etc.) to observe their effects on the display. If you are lost, all the parameters can be reset to their default values by pressing the `<PRESET>` button.

**2.** Turn on the signal generator function of the FPC1500 with CW carrier and set to 50MHz:
```
<MEAS>  [SOURCE]  [CW]  (50)  (MHz)
```

**3.** Set the output power to 0dBm:
```
[LEVEL]  (0)  (dBm)
```

**4.** Connect "Gen. Output 50Ω" to the "RF INPUT 50Ω" of the R&S FPC1500 connector using a 50Ω N-Type cable.

**5.** Set the FPC1500 to spectrum mode:
```
<MEAS>  [Measurement Mode]  [Spectrum]
```

**6.** Set the centre frequency to 50MHz:
```
<FREQ>  [Center Frequency]  (50)  (MHz)
```

**7.** Set the span to 5MHz:
```
<SPAN>  [Manual Span]  (5)  (MHz)
```

**8.** By default, the power reference level has been set to -20dBm. Set the amplitude to see the entire signal:
```
<AMPTD>  [Reference Level]  (5)  (dBm)
```

**9.** You should be able to see a single frequency of 50MHz (without modulation) displayed on the FPC1500.

Press `<Mkr►>` → `<Set to Peak>` to place a marker at the peak of the signal and read out the frequency and power level. To read the amplitude level, press `<AMPTD>` → `[Unit]` → `[dBmV]`.

| Measurement     | Value      |
| --------------- | ---------- |
| Frequency       | 50MHz      |
| Power Level     | -0.4 dBm   |
| Amplitude Level | 46.55 dBmV |

Calculate the amplitude level in dBmV for R = 50Ω using the above measured Power Level. Show your workings here.

$$
\begin{align*}
P &= 10^{\frac{\text{Power Level}}{10}} \\
&= 10^{\frac{-0.4}{10}} \\
&= 10^{-0.04} \\
&= 0.000912 \text{ mW} \\
\\
\text{Amplitude Level} &= 20 \times \log_{10}\left(\frac{V_{rms}}{1mV}\right) \\
&= 20 \times \log_{10}\left(\frac{\sqrt{P \times R}}{0.001}\right) \\
&= 20 \times \log_{10}\left(\frac{\sqrt{0.000912 \times 50}}{0.001}\right) \\
&= 20 \times \log_{10}\left(\frac{\sqrt{0.0456}}{0.001}\right) \\
&= 20 \times \log_{10}\left(\frac{0.2136}{0.001}\right) \\
&= 20 \times \log_{10}(213.6) \\
&= 20 \times 2.329 \\
&= 46.58 \text{ dBmV}
\end{align*}
$$

> Does the measured and calculated amplitude level tally? _______________

**10.** Press the `<Marker>` button to place a marker on the screen. The readout on the top of the screen shows the frequency and amplitude position of the marker. Use the dial to move the marker across the screen.

What is the frequency on the left edge, the middle, and the right edge of the screen?

| Position   | Frequency |
| ---------- | --------- |
| Left Edge  | 47.5      |
| Middle     | 50        |
| Right Edge | 52.5      |
marker can show delta to another marker, or actual freq

> Do these readings tally with the span and centre frequency setting of the analyser?
> Ans: kinda -> the span is correct 

**11.** You can shift the display left or right by changing the centre frequency (using the dial, step keys, or numeric keypad).

Press `<FREQ>` → select Centre Frequency → move the dial to change to **49.5 MHz**. What do you observe?

| Measurement | Value     |
| ----------- | --------- |
| Frequency   | 50 MHz    |
| Amplitude   | 46.3 dBmV |

**12.** The display can be shifted up or down by changing the amplitude reference level (the value of the top-most horizontal line on the screen).

Press `<AMPT>` → select Reference Level → change to **30 dBmV** using the numeric keypad. What do you observe? Try using the dial and step keys to change the reference level.

-> when the ampt is too low, the top is cut off/distorted -> we cant see the peak which is what we're interested in

Set the Reference Level back to **50 dBmV**.

**13.** Try changing the span by using the dial (press `<SPAN>` first). Notice the **Sweep Time (SWT)**, **Video Bandwidth (VBW)**, and **Resolution Bandwidth (RBW)** values at the top of the screen change when the span is altered.

Record values in the table below:

| Span   | Sweep Time (SWT) | Video Bandwidth (VBW) | Resolution Bandwidth (RBW) |
| ------ | ---------------- | --------------------- | -------------------------- |
| 1 MHz  | 20ms             | 30kHz                 | 30kHz                      |
| 5 MHz  | 20ms             | 10kHz                 | 100kHz                     |
| 50 MHz | 20ms             | 1MHz                  | 1MHz                       |

Set the span to **5 MHz**. Change the Resolution Bandwidth to **30 kHz** manually:
```
<BW>  [RBW manual]  (30)  (kHz)
```

Record the values:

| Span  | Sweep Time (SWT) | Video Bandwidth (VBW) | Resolution Bandwidth (RBW) |
| ----- | ---------------- | --------------------- | -------------------------- |
| 5 MHz | 28ms             | 30kHz                 | 30 kHz                     |

> Smaller RBWs provide finer frequency resolution and the ability to differentiate signals that have frequencies that are closer together. A smaller RBW also results in a smaller amount of noise in the measurement. However, lowering the RBW will increase the sweep time. Sweep time directly affects how long it takes to complete a measurement.

Reset the Signal Analyser to default setting by pressing `<PRESET>`.

---

## Appendix — Introduction to dB, dBm and dBmV

- Signals in communication have extremely wide ranges in magnitudes which make graphical representation and relative comparison between signals very difficult.
- The **decibel scale** is used to solve these problems. It is a relative power measurement.
- The decibel is defined as ten times the logarithm of the ratio of two power values.
- The ratio of 2 power values can be defined as **Power Gain** or **Loss**.

**Power Gain/Loss (ratio):**

`G(ratio) = Po(W) / Pi(W)`

**Power Gain/Loss (dB):**

`G(dB) = 10 × log₁₀ [ Po(W) / Pi(W) ]`

where Po = output power & Pi = input power

- A **positive dB** value indicates that the output value is greater than the input value
- A **negative dB** value indicates that the output value is smaller than the input value

**dBm** — absolute power level referenced to 1mW:

`P(dBm) = 10 × log₁₀ [ Power(W) / 1mW ]`

**dBW** — absolute power level referenced to 1W:

`P(dBW) = 10 × log₁₀ [ Power(W) / 1W ]`

**dBmV** — absolute voltage level referenced to 1mV:

`V(dBmV) = 20 × log₁₀ [ V(volts) / 1mV ]`
