---
id: "7681b0e1-992a-43b2-9b46-5c9124cbd987"
title: "And Set To 50Mhz"
type: vault_note
vault: wiki
created: 2026-05-17
updated: 2026-05-17
checksum: "sha256:7b00e2fcd2af55c3"
source: heimdall/auto
---

# And Set To 50Mhz

- and set to 50MHz:
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

Calculate the amplitude level in dBmV for R = 50Ω using the above measured Power Level. <!-- id:7681b0e1-992a-43b2-9b46-5c9124cbd987 ts:2026-05-17 07:49 -->
