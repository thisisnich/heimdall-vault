- itter, hte: 50 m
- Height of mobile receiver, hre: 2 m

**Assumption:**
Assuming all other losses are negligible except path loss and Rayleigh fading. Provision for fade margin for 99.8% reliability may be calculated with the help of the Rayleigh distribution chart provided (Treat the Fade Margin as additional loss along the path)

**Requirements:**
i) Write down the system equation
ii) Given that a cell radius of 3 km is required, calculate the path loss
iii) Determine the required power of the transmitter, PT with 99.8% of communication link

### Solution

**i) System Equation:**
```
Pt – Lf + Gt – Lp - FM + GR – Lf = PR
```
Given that feeder losses are negligible, Lf = 0:
```
Pt + Gt – Lp - FM + GR = PR
```

**ii) Path Loss Calculation:**
```
A(hre) = 3.2[log(11.75 hre)]² - 4.97
= 3.2[log(11.75 × 2)]² - 4.97
= 1.045 dB

PL = 69.55 + 26.16 log f - 13.82 log hte - A(hre) + (44.9 - 6.55 log hte)(log d)
= 69.55 + 26.16 log(915) – 13.82 log(50) – 1.045 + (44.9 – 6.55 log(50)) log(3)
= 138.14 dB
```

**iii) Required Transmitter Power:**
From the Rayleigh distribution chart (99.8% reliability): Fade Margin = 25 dB

```
Pt – Lf + Gt – Lp - FM + GR – Lf = PR
Transmit power required Pt = PR + Lf - Gt + Lp + FM - GR + Lf
= -113 + 0 – 6 + 138.14 + 25 - 3 + 0
= 41.14 dBm
```

With transmit power of 41.14 dBm, we can be sure that the receiver will have the probability of 99.8% of receiving the signal.

### Link Budget Example Table

| Parameters | Values (dB) |
|------------|----------- <!-- id:a1e0321e-77bf-4f34-8dca-4128a3b8297e ts:2026-05-17 07:49 -->
