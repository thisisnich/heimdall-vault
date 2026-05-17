---
id: "9c9226e0-a609-435b-bbc2-bffa46b91d46"
title: "Ver Will Have The Probability"
type: vault_note
vault: wiki
created: 2026-05-17
updated: 2026-05-17
checksum: "sha256:2ba1f13519a02463"
source: heimdall/auto
---

# Ver Will Have The Probability

- ver will have the probability of 99.8% of receiving the signal.

### Link Budget Example Table

| Parameters | Values (dB) |
|------------|-------------|
| Tx power(dBm) | 45 |
| Antenna cable loss | 3 |
| Tx Antenna Gain (dBi) | 13 |
| EIRP(dBm) (= 45 – 3 + 13) | 55 |
| Path Loss | 150 |
| Fade Margin(dB) | 0 |
| Other margin components(dB) such as building penetration loss | 0 |
| Received isotropic power(dBm) (= 55 – 150 – 0 - 0) | -95 |
| Rx Antenna Gain (dBi) | 4 |
| Mobile antenna cable loss (dB) | 1 |
| Rx signal power (dBm) (= -95 + 4 – 1) | -92 |
| Rx noise power kTB (dBm) | -126 |
| Rx CNR(dB) (= -92 – (-126)) | 34 |
| Target Rx CNR(dB) | 13 |
| Margin(dB) (= 34 – 13) | 21 |

### Video Reference
[How to Calculate the Required Link Budget to Establish a Communication Link with a Case Study](https://youtu.be/meb4a5oeTDA)

---

## Useful Formulas Summary

| Model | Formula |
|-------|---------|
| Free Space Propagation Model | LP (dB) = 32.44 + 20 log d (km) + 20 log f (MHz) |
| Okumura's Hata Model | A(hre) = 3.2[log(11.75 hre)]² - 4.97 (dB)<br>LP = 69.55 + 26.16 log f(MHz) – 13.82 log hte – A(hre) + [44.9 – 6.55 log hte][log d (km)] |
| Plane Earth Model | L (dB) = 120 + 40 log dkm - 20 log[hr(m) ht(m)] |
| Link Budget | Pt – Lf + Gt – Lp - FM + GR – Lf = PR |

---

## Homework

### Problem Statement

A RF engineer is tasked to set up a base station within a cell radius d = 2 km in a new town. <!-- id:9c9226e0-a609-435b-bbc2-bffa46b91d46 ts:2026-05-17 07:49 -->
- ver will have the probability of 99.8% of receiving the signal.

### Link Budget Example Table

| Parameters | Values (dB) |
|------------|-------------|
| Tx power(dBm) | 45 |
| Antenna cable loss | 3 |
| Tx Antenna Gain (dBi) | 13 |
| EIRP(dBm) (= 45 – 3 + 13) | 55 |
| Path Loss | 150 |
| Fade Margin(dB) | 0 |
| Other margin components(dB) such as building penetration loss | 0 |
| Received isotropic power(dBm) (= 55 – 150 – 0 - 0) | -95 |
| Rx Antenna Gain (dBi) | 4 |
| Mobile antenna cable loss (dB) | 1 |
| Rx signal power (dBm) (= -95 + 4 – 1) | -92 |
| Rx noise power kTB (dBm) | -126 |
| Rx CNR(dB) (= -92 – (-126)) | 34 |
| Target Rx CNR(dB) | 13 |
| Margin(dB) (= 34 – 13) | 21 |

### Video Reference
[How to Calculate the Required Link Budget to Establish a Communication Link with a Case Study](https://youtu.be/meb4a5oeTDA)

---

## Useful Formulas Summary

| Model | Formula |
|-------|---------|
| Free Space Propagation Model | LP (dB) = 32.44 + 20 log d (km) + 20 log f (MHz) |
| Okumura's Hata Model | A(hre) = 3.2[log(11.75 hre)]² - 4.97 (dB)<br>LP = 69.55 + 26.16 log f(MHz) – 13.82 log hte – A(hre) + [44.9 – 6.55 log hte][log d (km)] |
| Plane Earth Model | L (dB) = 120 + 40 log dkm - 20 log[hr(m) ht(m)] |
| Link Budget | Pt – Lf + Gt – Lp - FM + GR – Lf = PR |

---

## Homework

### Problem Statement

A RF engineer is tasked to set up a base station within a cell radius d = 2 km in a new town. <!-- id:9c9226e0-a609-435b-bbc2-bffa46b91d46 ts:2026-05-17 07:49 -->
