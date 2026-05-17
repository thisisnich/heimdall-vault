---
tags:
  - EGE321
  - lab
  - appendix
  - theory
  - fourier-series
  - bandwidth
  - lab3-appendix
  - signal-theory
course: EGE321 Wireless Communication & Networking
topic: Lab 3 Appendix - Bandwidth of Digital Signal
source: EGE321 Lab3 Time and Frequency Domain Analysis of a digital signal- Appendix.pdf
converted: 2026-05-08
type: Appendix
---

> 📚 **Related:** [[NYPY3 - Main Index|NYPY3 Index]] | [[03-RESOURCES/EGE321-Wireless-Communication/EGE321 Lab3 Time and Frequency Domain Analysis of a Digital Signal.md|Lab 3]] | [[📅 Schedule & Assessments Dashboard|Assessment Dashboard]]
status: Completed
---

> 📚 **Related:** [[NYPY3 - Main Index|NYPY3 Index]] | [[03-RESOURCES/EGE321-Wireless-Communication/EGE321 Lab3 Time and Frequency Domain Analysis of a Digital Signal.md|Lab 3]] | [[📅 Schedule & Assessments Dashboard|Assessment Dashboard]]

# Lab 3 Appendix: Bandwidth of a Digital Signal - Theory

## Fourier Series of Rectangular Waveform

Given that the general expression for a rectangular waveform in terms of Fourier series is as follows:

```
x(t) = Σ [a_n cos(nω₀t) + b_n sin(nω₀t)]
```

where f₀ = 1/T

From the figure, for a periodic signal with a bit pattern 1 0 1 0 10…, the bit rate = 1/τ where τ is the bit duration.

The mainlobe bandwidth of the baseband signal is given by 1/τ.

## 50% Duty Cycle Square Wave

Given τ = 1µs and T = 2µs, let τ = T/2, then:

- f₀ = 1/T = 1/(2µs) = 0.5 MHz
- Duty Cycle = 50%

Using Fourier Series expansion, the time domain signal of the 50% duty cycle square wave can be written in terms of the corresponding frequency components as:

```
x(t) = (2A/π)cos(ω₀t) + (2A/3π)cos(3ω₀t) + (2A/5π)cos(5ω₀t) + ...
```

## Frequency Spectrum of Square Wave

The spectrum of the square wave can be plotted as:

**Amplitude vs Frequency:**

| Frequency (MHz) | Amplitude |
|-----------------|-----------|
| 0.0 | 2A/π |
| 0.5 | 2A/3π |
| 1.0 | 2A/5π |
| 1.5 | 2A/7π |
| 2.0 | 2A/9π |
| 2.5 | ... |
| 3.0 | ... |
| 3.5 | ... |
| 4.0 | ... |
| 4.5 | ... |

**Key Observations:**
- Square wave contains only odd harmonics (1st, 3rd, 5th, 7th, 9th, ...)
- Envelope of the spectrum is a sinc function
- 1st null occurs at (1/τ)
- 2nd null occurs at (2/τ)
- And so on...

## Fourier Coefficients

For a 50% duty cycle square wave:

```
a_n = 0 (for all n)
b_n = (2A/nπ) × sin(nπ/2)
```

This gives:
- b₁ = 2A/π
- b₃ = 2A/3π
- b₅ = 2A/5π
- etc.

## Comparison of Signals in Time and Frequency Domains

### Effect of Duty Cycle on Square Wave and its Frequency Spectrum

The duty cycle of a square wave affects:
- The amplitude of the harmonic components
- The frequency spacing between spectral lines
- The location of nulls in the frequency spectrum

A 50% duty cycle square wave has:
- Maximum odd harmonic content
- No even harmonics
- First null at f = 1/τ (the fundamental frequency)