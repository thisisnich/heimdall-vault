---
tags:
  - EGE321
  - lab
  - oscilloscope
  - spectrum-analyzer
  - time-domain
  - frequency-domain
course: EGE321 Wireless Communication & Networking
topic: Lab 3 - Time and Frequency Domain Analysis of a Digital Signal
source: EGE321 Lab3 Time and Frequency Domain Analysis of a Digital Signal.pdf
converted: 2026-05-08
---

> **Related:** [[EGE321 Lab1 Loopback Test within SPA|Lab 1]] | [[EGE321 Lab3 Time and Frequency Domain Analysis of a digital signal- Appendix|Lab 3 Appendix]]

# Lab 3: Time and Frequency Domain Analysis of a Digital Signal

## Objectives

- To learn how to use an oscilloscope and waveform generator
- To observe digital signals in both the time and frequency domains

## Equipment

- Spectrum Analyser R&S FPC1500
- Function/Arbitrary Waveform Generator Agilent 33500B
- Digital Storage Oscilloscope DSO-X 2022A

## Materials

- Mini-Circuits ZFSC-2-2 Power Splitter (or T-joint)

---

## Part 1 – Review of Digital Storage Oscilloscope and Function Generator

### Digital Storage Oscilloscope

Digital Storage Oscilloscope measures signals in the time domain.

**Key Controls:**
- Time/div knob
- Autoscale
- ON/OFF
- Volts/div knobs
- Cursors button
- Measure button

**Button Functions:**
- Push to Select for measurement in Cursor Mode
- Push to Select for measurement Type (e.g., Freq, Period selection) in Measure Mode

### Function Generator Agilent 33522A/33500B

Function generators generate electrical waveforms. (33500B is newer and has same operation guide as 33522A)

**Key Controls:**
- Waveform Button
- Keypad to enter frequency or amplitude, etc.
- Power On/Off
- Blue buttons under menu (black buttons for 33500B)
- Channel 1 Selector
- Channel 2 Selector

### Setup Procedure

**Step 1:** Turn on the Function Generator Agilent 33522A.

**Step 2:** Set the output termination to High Impedance:
- Press here above the Channel 1 BNC connector
- a. Press Channel Setup button
- b. Press the blue button under Output Load
- c. Press the blue button below 'Set to High Z'
- d. Press the blue button below 'Done'

**Step 3:** Set up the Function Generator to produce:
- Type of waveform: Sine
- Frequency: 0.5MHz
- Amplitude: 1 V peak to peak

**Procedure:**
- a. Press the button to select 'Sine' wave
- b. Press the blue button to select 'Frequency' and enter using the keypad
- c. Enter the frequency as 0.5MHz: Press under 'MHz' using the keypad
- d. Enter the amplitude as 1Vpp: Press under 'Amplitude' and press under 'Vpp'
- e. Press under Channel Setup and under 'Output On' to turn on the function generator

**Step 4:** Connect the output of the function generator to the oscilloscope input using a coaxial cable.

**Step 5:** Observe the waveform using the oscilloscope. Check that the waveform is 1 Vpp and frequency is 0.5 MHz. Sketch and label the signal (amplitude, period and frequency) observed from the oscilloscope.

### Measurement Methods

The peak-to-peak amplitude of the waveform can be measured using either Automatic Measurement or Cursor Measurement.

#### Automatic Measurement

**Procedure:**
- a. Press the [Meas] key to display the Measurement Menu
- b. Press the Source softkey to select the channel or reference waveform to be measured (1 for channel 1, 2 for channel 2)
- c. Press the Type softkey then rotate the Entry knob to select a measurement to be made
- d. Press "Push to Select" for Frequency measurement
- e. Verify and record frequency of the waveform by reading the value display on the right
- f. The Settings softkey will be available to make additional measurement settings on some measurements
- g. Press the Add Measurement softkey or push the Entry knob to display the measurement for peak to peak amplitude
- h. Verify and record the peak to peak amplitude of the waveform
- i. To turn off measurements, press the [Meas] key again. Measurements are erased from the display
- j. To stop making one or more measurements, press the Clear Meas softkey and choose the measurement to clear, or press Clear All

#### Cursor Measurement

Cursors are horizontal and vertical markers that indicate X-axis values and Y-axis values on a selected waveform source. You can use cursors to make custom voltage, time, phase, or ratio measurements on oscilloscope signals.

**Cursor Types:**
- **X cursors:** Vertical dashed lines that adjust horizontally, used to measure time (s) and frequency (1/s)
  - X1 cursor: short-dashed vertical line
  - X2 cursor: long-dashed vertical line
- **Y cursors:** Horizontal dashed lines that adjust vertically, used to measure Volts or Amps
  - Y1 cursor: short-dashed horizontal line
  - Y2 cursor: long-dashed horizontal line

**Procedure:**
- a. Press the [Cursors] key. The Cursors box in the right-side information area appears, indicating that cursors are "on" (Press the [Cursors] key again when you want to turn cursors off)
- b. In the Cursors Menu, press Mode; then, select the desired mode:
  - Manual — ΔX, 1/ΔX, and ΔY values are displayed
  - ΔX is the difference between the X1 and X2 cursors
  - ΔY is the difference between the Y1 and Y2 cursors
- c. Press Source; then, select the input source for cursor values (1 for channel 1, 2 for channel 2)
- d. Select the cursor(s) to be adjusted:
  - Push the "Cursors knob"; then, turn the Cursors knob. To finalize your selection, either push the Cursors knob again or wait about five seconds for the popup menu to disappear
  - Or: Press the Cursors softkey; then, turn the Entry knob
- e. The X1 X2 linked and Y1 Y2 linked selections let you adjust both cursors at the same time, while the delta value remains the same
- f. To change the cursor units, press the Units softkey:
  - In the Cursor Units Menu, press the X Units softkey to select: Seconds (s), Hz (1/s), Phase (°) or Ratio
  - Press the Y Units softkey to select: Base (same units used for the source waveform) or Ratio

**Measurements:**
- Frequency of the waveform: _____________________
- Peak to peak amplitude of the waveform: ________________
- Do these results make using Automatic Measurement and Cursor Measurement tally?
- Ans: ___________________

### Quick Exercise

Determine the peak amplitude, peak to peak amplitude, period and frequency of the sinusoidal signal below. The time/div is 5µs and volt/div is 200mV.

- Peak Amplitude (Vp): ______________
- Peak to Peak Amplitude (Vp-p): ____________
- Period: ______________
- Frequency: ______________

---

## Part 2 – Time and Frequency Domain Analysis of a Digital Signal

### Setup Procedure

**Step 1:** Disconnect the coaxial cable from the oscilloscope and connect it to spectrum analyzer instead.

**Step 2:** Set the functional generator:
- Type of waveform: Sine
- Frequency: 0.5MHz
- Output Load: 50 Ohm
- Amplitude: 1 V peak to peak

**Step 3:** Set generator output termination:
- a. Press Channel Setup button
- b. Press the blue button under Output Load
- c. Press the blue button below 'Set to 50Ω'
- d. Press the blue button below 'Done'
- e. Press above the Channel 1 BNC connector

**Step 4:** Set the Spectrum Analyzer parameters:
- Center Frequency: 0.5MHz
- Span: 500kHz
- Amplitude unit: Volt
- Amplitude reference level: 2V
- RBW: 1 kHz or 10kHz
- Set Marker at 500kHz

**Question:** What do you observe on the Spectrum Analyzer? What is the effect of RBW setting?
___________________________________________________________________________
__________________________________________________________________________

### Square Wave Analysis

**Step 5:** Generate square waves using the function generator and observe the signal in the time and frequency domain using the oscilloscope and spectrum analyzer. Keep the same settings as before but change the waveform type from Sine to Square.

- Type of waveform: Square
- Duty Cycle: 50%
- Frequency: 0.5 MHz
- Output termination: 50 Ohm
- Amplitude: 1 V peak to peak

**Step 6:** Set the oscilloscope:
- Amplitude: 1 V per division
- Time base: 1 µs per division

Use a T-joint to connect the output of the function generator to the oscilloscope input and spectrum analyser input. (The T-joint will be issued by the lecturer.)

**Step 7:** Set the Spectrum Analyser:
- Centre frequency: 2.5 MHz
- Span: 5 MHz
- Ref Lvl: 2V
- RBW: 10kHz

Sketch the display shown on the spectrum analyser. Label the amplitude and frequency of each component clearly (You can use marker function).

**Steps to use marker:**
- a) 1st Marker: Press "Mkr", then "Mkr->", then press "Set to Peak"
- b) 2nd Marker: Press "Mkr". Select "Marker 2", select "Marker Type", then "Mkr->", press "Set to peak", then press "set to Next peak"
- c) 3rd Marker: Press "Mkr", Select "Marker 3", select "Marker Type", press "Mkr->", press "Set to peak", then press "set to Next peak" twice

**Note:** The learner can also examine the harmonics in greater detail by setting the center frequency to 25 MHz and the span to 50 MHz.

### Reflection Questions

**a.** Why is the output termination set to 50 Ohm in this part with Spectrum Analyzer?
___________________________________________________________________________
___________________________________________________________________________
_________________________________________________________________________
__________________________________________________________________________

**b.** What is the frequency spacing between the spectral lines by using square wave with duty cycle 50%?
___________________________________________________________________________
__________________________________________________________________________

**c.** Does your observed result match the theoretical expectation? Explain briefly.
___________________________________________________________________________
__________________________________________________________________________
___________________________________________________________________________
__________________________________________________________________________

---

## Appendix

See [[EGE321 Lab3 Time and Frequency Domain Analysis of a digital signal- Appendix|Lab 3 Appendix]] for theoretical background on bandwidth of digital signals, Fourier series, and square wave harmonics.