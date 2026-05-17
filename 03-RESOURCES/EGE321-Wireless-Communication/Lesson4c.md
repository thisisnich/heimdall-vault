---
tags:
  - EGE321
  - lesson4c
  - wireless-systems
  - radio-propagation
  - link-budget
  - chapter-2
course: EGE321 Wireless Communication & Networking
topic: Lesson 4c - Radio Propagation and Link Budget (Chapter 2.2)
source: Lesson4c.pptx
converted: 2026-05-07
type: Lesson
status: Completed
---

> 📚 **Related:** [[NYPY3 - Main Index|NYPY3 Index]] | [[03-RESOURCES/EGE321-Wireless-Communication/Lesson3c.md|Chapter 2]] | [[📅 Schedule & Assessments Dashboard|Assessment Dashboard]]

# Lesson 4c - Radio Propagation and Link Budget (Chapter 2.2)

## Contents

- 2.2 Radio Propagation and Link Budget
- 2.2.1 Electromagnetic Wave Propagation
- 2.2.2 Propagation Path Loss Model
- 2.2.3 Link Performance Analysis

---

## Electromagnetic Wave Propagation

### Electromagnetic (EM) Spectrum

The entire range of frequencies that is occupied by the electromagnetic waves is referred to as electromagnetic spectrum.

**Frequency Allocation:**
- Allocation of frequencies is made by world-wide agreements under the control of the International Telecommunications Union (ITU)
- Representatives from different countries meet at regular ITU conference to decide what services should be allowed to use which frequencies
- These are necessary so as not to cause interference to each other's transmission

### EM Wave Fundamentals

**Signal Conversion:**
Information to be transmitted must be converted into signals that is compatible with the transmitting medium.

**Electromagnetic Wave:**
- The information is converted into an electrical signal which consists of both Electric (E) and Magnetic (M) fields
- This is called an Electromagnetic (EM) wave
- Radio Frequency (RF) wave is part of the EM wave

**Wavelength:**
- The wavelength (λ) of an electromagnetic wave is defined as the distance travelled by the EM wave in the time of one period
- The frequency of the EM wave is inversely proportional to the wavelength

**Propagation:**
EM waves can travel through long distances:
- Guided medium: transmission wires
- Unguided medium: free space or vacuum

### Transverse Electromagnetic Wave (TEM)

**Characteristics:**
- The EM wave shown is a Transverse Electromagnetic Wave (TEM) as the electric field, E and the magnetic field, H are transverse to the direction of propagation

**Polarization:**
Polarization of an EM wave refers to the orientation of the E-field. Two common types of polarization are:
- Vertical Polarization
- Horizontal Polarization

---

## Radio Propagation Mechanisms

Electromagnetic signals, after leaving the transmitting antenna, will experience the following propagation mechanisms:
- Reflection
- Diffraction
- Scattering
- Refraction
- Absorption

### Reflection

**Definition:**
The EM signal impinges on an object whose dimension is very large as compared to the wavelength of the EM signal.

**Conditions:**
- Dimension large compared to wavelength (λ) of EM wave

**Examples:**
- Earth surface
- Buildings and walls

### Diffraction

**Definition:**
Occurs when radio path is blocked by an object that has sharp irregularities.

**Characteristics:**
- Also often termed shadowing because the diffracted field can reach the receiver even when shadowed by an impenetrable obstruction – shadow region

**Examples:**
- Sharp projections (buildings, mountain peaks) produces a maximum diffracted signal

### Scattering

**Definition:**
Occurs when the EM wave strikes small, rough surfaces or other irregularities objects.

**Conditions:**
- Object's dimension small as compared to wavelength (λ) of EM wave

**Examples:**
- Foliage, lampposts and street signs

**Surface Roughness:**
- Surface roughness is tested by Rayleigh criterion which defines a critical height hc of surface protuberances
- A surface is considered smooth if its minimum to maximum protuberance h < hc
- A surface is considered rough if the protuberance h > hc

### Example

**Problem:**
An electromagnetic signal may encounter reflection or scattering when it hits an obstacle. Explain when reflection and scattering occur.

**Answer:**
- When the EM signal hits an object whose dimension is very large compared to its wavelength, it undergoes reflection
- When the EM signal hits a small object whose dimension is small compared to its wavelength, it is redirected in all directions

### Video Reference
[Link Budget Part 1. Reflection, Refraction, Diffraction or Scattering, When EM Wave Hit an Obstacle](https://youtu.be/xPiMMvZ5zTQ)

---

## RF Propagation Modes

### Propagation Types

**Ground waves:**
- Space waves – travels over the earth surface
- Surface waves – travels along the surface of the earth. Signal usually below 2MHz (LF and MF bands)
- Sky waves – radio wave propagated upward from earth, whether reflected by the ionosphere or not

### Frequency Band Classification

| Classification Band | Initials | Frequency Range | Characteristics |
|---------------------|----------|-----------------|----------------|
| Extremely low | ELF | < 300 Hz | Ground wave |
| Infra low | ILF | 300 Hz - 3 kHz | |
| Very low | VLF | 3 kHz - 30 kHz | |
| Low | LF | 30 kHz - 300 kHz | |
| Medium | MF | 300 kHz - 3 MHz | Ground/Sky wave |
| High | HF | 3 MHz - 30 MHz | Sky wave |
| Very high | VHF | 30 MHz - 300 MHz | Space wave |
| Ultra high | UHF | 300 MHz - 3 GHz | |
| Super high | SHF | 3 GHz - 30 GHz | |
| Extremely high | EHF | 30 GHz - 300 GHz | |
| Tremendously high | THF | 300 GHz - 3000 GHz | |

---

## Radio Propagation Models

### Line of Sight (LOS) vs Non Line of Sight (NLOS)

Radiated energy from the antenna propagates through the media (air) to reach the receiving antenna over mainly two possible propagation paths:

**1) Line of Sight (LOS) path:**
- Tx and Rx can "see" each other
- A LOS link requires that most of the first Fresnel zone is free of any obstructions
- Otherwise there will be significant signal reduction

**2) Non Line of Sight (NLOS) paths:**
- The direct path between Tx and Rx are blocked by obstacles and hence "cannot see" each other
- The radio signal is reflected off from some structures to reach the receiver

### Optical Line of Sight

**Definition:**
Optical line of sight is the direct free-space path that exists between two end-points.

**Requirements:**
- To have a clear line of sight there must be no obstructions between Tx and Rx
- "Transmitter and receiver must be able to see each other"

**Obstructions:**
- Curvature of the Earth
- Mountains
- Topographic features
- Buildings
- Other man-made objects

### Radio Line of Sight

**Space Wave Propagation:**
- Propagation restricted by Earth's curvature
- Due to the density of the atmosphere changing (less dense as the height increases), radio signals are refracted (bent) into slightly curved paths
- Communicating antennas can "see" each other even when beyond the visible horizon

**Characteristics:**
- Line of sight (LOS) propagation is one mode of unguided radio wave transmission
- Used mainly for VHF and Microwaves bands because the energy of radio waves at these bands propagate through the atmosphere in more or less a straight line

**Distance Calculation:**
- Optical line of sight distance: dOLOS
- Radio line of sight distance dRLOS is usually 1.33 times further than the optical line of sight dOLOS
- dRLOS = 1.33 dOLOS

**Note:**
Determining the line-of-sight distance does not guarantee range. The transmitter power, receiver sensitivity, transmission line loss, antenna loss or gain, and operating frequency must also be considered when calculating the actual range.

---

## Propagation Path Loss Models

### Free Space Concept

**Definition:**
Free space path is the Line-of-Sight path directly between the transmit and receive antennas (also called the Direct Wave).

**Free Space Loss:**
- Defined as the loss incurred by an EM wave as it propagates in a straight line through a vacuum with no absorption or reflection of energy from nearby objects
- A free space channel characterizes an ideal RF propagation path

### Friis Free Space Equation

The free space propagation model is used to predict signal strength when the transmitter and receiver have a clear, unobstructed line of sight path between them. This is an Ideal Model.

**Formula:**
```
PR = Received Power in Watts
PT = Transmitted Power in Watts
GT = Transmit Antenna Gain
GR = Receive Antenna Gain
λ = Wavelength in meters
d = Tx/Rx Separation in same units as wavelength in meters
L = system loss that is not related to propagation (L ≥ 1)
L = 1 (if there is no system hardware losses)
```

### Path Loss Fundamentals

**Definition:**
The path loss represents the signal attenuation after the signal leaves the transmit antenna and before reaching the receive antenna. It is defined as the difference (in dB) between the transmitted power and the received power with unity antenna gain.

**Friis Formula:**
The Friis formula shows that the received signal power falls off as the square of the transmitter to receiver separation distance (d):
- PR ∝ d⁻²

**Factors Affecting Path Loss:**
Besides frequency and distance between antennas, path loss is also dependent on:
- Antenna heights
- Terrain environment – urban, rural etc
- Weather

**Free Space Path Loss Formula (in dB):**
```
LP (dB) = 32.44 + 20 log d (km) + 20 log f (MHz)
```

### Example

**Problem:**
A radio communication system is operating at 400 MHz and has a transmit power of 25W and has an effective range of 2000 m. The transmitting and receiving antenna gains are 25dB and 3 dB respectively.

**Questions:**
1. State the condition that must be valid to apply the free space path loss model
2. Assuming no other losses, calculate the free space loss

**Solution:**

**1. Condition:**
Transmitter and receiver must have a clear, unobstructed line of sight path between them.

**2. Free Space Path Loss:**
```
LP (dB) = 32.44 + 20 log d (km) + 20 log f (MHz)
= 32.44 + 20 log 2 + 20 log 400
= 90.5 dB
```

---

## Plane Earth Model

### Fundamentals

VHF, UHF and microwave signals normally propagate by space wave. Space wave consists of the direct wave and ground reflected wave. Reflection from the ground will cause energy loss such that its attenuation will be higher than the free space loss.

**Plane Earth Path Loss Model:**
- The plane earth propagation loss is independent of frequency

**Formula:**
```
L (dB) = 120 + 40 log dkm - 20 log[hr(m) ht(m)]
```

**Where:**
- d = distance in km
- ht, hr = antenna heights in m

### Example

**Problem:**
An aircraft is approaching landing at a height of 1000m and is transmitting 5W to a control tower 10km away. The height of the control tower is 90m. Assume that there is a ground reflected signal to the control tower. Determine the path loss.

**Solution:**
Since there is a ground reflected wave, we use the Plane earth model.
```
L (dB) = 120 + 40 log dkm - 20 log[hr(m) ht(m)]
= 120 + 40 log 10 - 20 log(1000 × 90)
= 60.9 dB
```

---

## Video References

### Link Budget Calculations
- [How to Calculate Link Budget Using Free Space Path Loss, Plane Earth & Okumura's Hata Models](https://youtu.be/VpBsqt4DuXs)
- [Link Budget Part 3. How to Apply Free Space Path Loss (FSPL) Equation: Applications & Usage Explain](https://youtu.be/3ba8ytGTcP8)
- [Link Budget Part 5. How to Calculate the Path Loss Using Plane Earth Model (Ground Reflected Wave)](https://youtu.be/ssYxLkdHRyU)

---

## Homework

### Problem 1
A satellite that is 400km above the earth transmits a signal at 12 GHz to an earth station. The transmit power of the satellite is 100W.

**Tasks:**
i) State the condition that must be valid to apply the free space path loss model
ii) Estimate the path loss in dB between the satellite and the earth station

### Problem 2
A microwave transmitting system is transmitting 30W of power to a receiver 10km away. Given that the height of the transmitting antenna is 100m and the height of the receiver antenna is 10m and assume that there is a ground reflected signal to the receiver. Determine the path loss in dB.

---
