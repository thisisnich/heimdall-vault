---
id: "f55c26f0-1125-47b6-843a-dffef6d25316"
title: "Related Ege321 Lab3 Time"
type: vault_note
vault: wiki
created: 2026-05-17
updated: 2026-05-17
checksum: "sha256:3bc783bec5b75a1f"
source: heimdall/auto
---

# Related Ege321 Lab3 Time

- > **Related:** [[EGE321 Lab3 Time and Frequency Domain Analysis of a Digital Signal|Lab 3]]

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
| 4.5 | ... <!-- id:f55c26f0-1125-47b6-843a-dffef6d25316 ts:2026-05-17 07:49 -->
