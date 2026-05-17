---
id: "50a99e82-e444-4049-bfd1-29422d6d8266"
title: "Mit Power Of 25W And"
type: vault_note
vault: wiki
created: 2026-05-17
updated: 2026-05-17
checksum: "sha256:bcd8158a49e0a059"
source: heimdall/auto
---

# Mit Power Of 25W And

- mit power of 25W and has an effective range of 2000 m. The transmitting and receiving antenna gains are 25dB and 3 dB respectively.

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
An aircraft is approaching landing at a height of 1000m and is transmitting 5W to a control tower 10km away. The height of the control tower is 90m. Assume that there is a ground reflected signal to the control tower. <!-- id:50a99e82-e444-4049-bfd1-29422d6d8266 ts:2026-05-17 07:49 -->
- mit power of 25W and has an effective range of 2000 m. The transmitting and receiving antenna gains are 25dB and 3 dB respectively.

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
An aircraft is approaching landing at a height of 1000m and is transmitting 5W to a control tower 10km away. The height of the control tower is 90m. Assume that there is a ground reflected signal to the control tower. <!-- id:50a99e82-e444-4049-bfd1-29422d6d8266 ts:2026-05-17 07:49 -->
