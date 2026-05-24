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
  - propagation
---

# Tutorial 4 Solution — Propagation Path-Loss Model

> [!ingest] source: Tutorial 4 Solution - Copy.pdf | date: 2026-05-24 | tool: markitdown
> Auto-converted. Edit summary below; re-run ingest to replace block above.

## Summary

Official solutions: optical vs radio LOS; **reflection, diffraction, scattering** (raindrops → scatter, weather radar); free space; wavelength/frequency; satellite FSPL; **EIRP**; FSPL @ 450 MHz; plane-earth aircraft link. PDF: [[99-ATTACHMENTS/EGE321/Tutorial 4 Solution - Copy.pdf]]. **ASSN1 Q3(c):** A=diffraction, B=reflection/multipath fading, C=**scattering** (rain).

---

## Key answers (ASSN1 / propagation)

| Topic | Answer |
|-------|--------|
| Diffraction | Bend around sharp obstacle; energy in **shadow zone** (weaker) |
| Scattering | Small objects / **raindrops** comparable to λ; energy in many directions |
| EIRP (dBm) | \( \text{EIRP} = P_T - L_f + G_T \) |
| FSPL | \( L_P = 32.4 + 20\log d_{\text{km}} + 20\log f_{\text{MHz}} \) (brief uses 32.4; solution Q5 uses 32.4) |

---

## Full solutions

SCHOOL OF ENGINEERING

Diploma in Electronics & Computer Engineering (EGDF20)

Wireless Communication & Networking (EGE321)

Tutorial 4:

Propagation Path-Loss Model

1)  With the aid of diagram, distinguish the differences between optical line of sight and

radio line of sight.

Optical line of sight is the direct free-space distance that exists between two end-points.
It  is  the  distance  seen  by  a  distant  transmitter  to  the  distant  receiver.    (“face  to
face”) To have a clear line of sight, there must be no obstructions between the two end-
locations.

However  due  to  the  density  of  the  atmosphere  changing  less  dense  as  the  height
increases,  radio  signals  are  refracted  into  slightly  curved  paths,  and  hence
communication antennas can “see” each other even when they are beyond the visible
horizon.   This  is  the  radio  horizon  –  the  distance  that  is  seen  by the  radio  signal.
Radio Horizon is usually taken as 1.33 times longer than the optical distance.

2)  Describe  briefly  the  3  basic  mechanisms  listed  below  that  occur  in  radio  wave

propagation.

a)  Reflection

Radio  waves  may  be  reflected  from  various  substances  or  objects  they  meet  during
propagation if the dimension of the object is very large compared to the wavelength
of the radio wave. The amount of reflection depends on the reflecting material.

Tut 4                                                                          Page 1 of 3                             Effective Date: 17 Oct 2022

Optical HorizonAntennaRadio HorizonRadio line of sight pathEARTH Surface

When radio waves are reflected, a phase shift will normally occur.  Radio waves that
keep their phase relationships (in-phase) after reflection normally produce a stronger
signal at the receiving site. Those that received out of phase produce a weaker signal
-  fading. In the extreme, the signals could just cancel each other.

b)  Diffraction

When radio waves meet a sharp obstacle, they have a natural tendency to bend around
the  tip  of  the  obstacle.  This  is  known  as  diffraction.  This  results  in  a  change  of
direction of part of the wave energy from the normal line-of-sight path. Because of
this  change, it  is  possible  to  receive  energy  around the  edges  of  an  obstacle  or  at
some  distances  below  the  highest  point  of  an  obstruction  in  the  shadow  zone.  This
diffracted radio frequency energy is weaker and may still be detected by a receiver.

c)

Scattering

When the radio waves meet a rough surface or very small objects whose dimensions
are comparable to the radio wave such dust particles, leaves or raindrops, it will tend
to be reflected into many directions (scattered). This scattering effect is employed by
weather  radar  to  detect  the  presence  of  rain  nearby.  The  effect  is  best  observed  at
around 10GHz.

3)  Define the concept of Free Space Propagation.

Free space assumes a channel free of all hindrances or obstacles to RF propagation
such as absorption, reflection, refraction or diffraction.  The energy arriving at the
receiver  is  assumed  to  be  only  a  function  of  the  distance  from  the  transmitter
(following the inverse square law).  A free space channel characterizes an ideal RF
propagation path.

4)

A transmitter transmits a signal with a wavelength of 15m over the air.

Transmitter

Coaxial cable

a)  Determine the frequency of the signal.

b)

If the signal travels through the coaxial cable with a speed of 2x108m/s,
calculate the wavelength of the signal in the coaxial cable.

Tut 4                                                                          Page 2 of 3                             Effective Date: 17 Oct 2022

MHzxcf20151038===mxxfv10102010268===

5)

A  satellite  that  is  500km  above  the  earth  transmits  a  signal  at  1.6GHz  to  an  earth
station. The transmit power of the satellite is 100W. Estimate the received signal in dBm
at the antenna of the earth station. Assume free space path loss.

Free space loss L (dB )  = 32.4 + 20 log d (km) + 20 log f (MHz)

= 32.4+20log500 +20log1600
=150.5dB

PT =100W
PR (dBm)

= 50dBm.
= PT(dBm) – L(dB)
= 50 – 150.5
= -100.5dBm

6)  Calculate  the  EIRP  of  a  microwave  transmitting  installation  where  the  transmitter
output power is 0.5 W, the total feeder cable loss is 5 dB, and the transmitting antenna
gain is 33 dB.

EIRP (dBm) = PT (dBm) –Lf (dB) + GT (dB)

= 10 log (0.5W/0.001W) – 5 dB + 33 dB
= 26.99 dBm – 5 dB + 33 dB
= 55 dBm

7)

A microwave carrier system is operating at 450 MHz and has a range of 25 km.  The
transmitter power is 25 W and the receiving and transmitting antenna gains are 24 dB
each.  Assuming no other losses, calculate the following the free space loss.

Free space path loss LP (dB)   = 32.44 + 20 log d (km) + 20 log f (MHz)

= 32.44 + 20 log 25 + 20 log 450
= 113.46 dB

8)

An aircraft is now approaching landing at a height of 1000m and is transmitting 5W to
a control tower 10km away. The height of the control tower is 90m. Assume that there
is a ground reflected signal to the control tower. Determine the received power in dBm
at the control tower.

Since there is a ground reflected wave, we use the Plane earth model.

L (dB) = 120 + 40 log dkm - 20 log[hr(m) ht(m)]

= 120 + 40log10 – 20log(1000x90)
= 60.9dB

PT = 5W
PR (dBm)

= 37dBm.
= PT(dBm) – L(dB)
= 37 – 60.9
= -23.9dBm

Tut 4                                                                          Page 3 of 3                             Effective Date: 17 Oct 2022
