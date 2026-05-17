---
id: "b58e0d9a-b444-4e49-9075-d01198e5f156"
title: "Y120 Which Is An Led"
type: vault_note
vault: wiki
created: 2026-05-17
updated: 2026-05-17
checksum: "sha256:31d16723153d3c08"
source: heimdall/auto
---

# Y120 Which Is An Led

- *Y120** which is an LED. At the same time a small indicator lights up on the output module which allows you to know the address of that output device. **"Y" represents output.**

**AFP7Y32T / Y32T**

> Address range on module: Y120 (top-left) → Y127 (top-right) → Y130 (bottom-left) → Y13F (bottom-right)

**Task:** Find the address of all the output devices and record in the table below.

---

## Input/Output Address Listing

Inputs and outputs connected to the PLC.

| INPUT Device | PLC Address | OUTPUT Device | PLC Address |
|---|---|---|---|
| PB1 | | LED1 | |
| PB2 | | LED2 | |
| PB3 | | LED3 | |
| PB4 | X100 | LED4 | Y120 |
| SW1 | | Relay1 | |
| SW2 | | Relay2 | |
| SW3 | | Relay3 | |
| SW4 | | Relay4 | |
| Sensor1 | | | |
| Sensor2 | | | |
| Sensor3 | | | |
| Sensor4 | | | |
| E-Stop PB | | | |

**Task:** Find out which input devices are normally-open type and which are normally-closed type.

**Task:** Find out what activating each relay does to the left and right gantry.

---

## Programming the PLC

1. Find out the addresses of the inputs (pushbuttons, toggle switches & sensors)

use the display table/showing at the PLC -> the displa -> shows buttons pressed etc


2. Activate the output addresses to identify all the outputs (LEDs, relays)
yes
3. Write a PLC program to **ON the green LED** when Sensor 1 is activated. <!-- id:b58e0d9a-b444-4e49-9075-d01198e5f156 ts:2026-05-17 07:49 -->
- *Y120** which is an LED. At the same time a small indicator lights up on the output module which allows you to know the address of that output device. **"Y" represents output.**

**AFP7Y32T / Y32T**

> Address range on module: Y120 (top-left) → Y127 (top-right) → Y130 (bottom-left) → Y13F (bottom-right)

**Task:** Find the address of all the output devices and record in the table below.

---

## Input/Output Address Listing

Inputs and outputs connected to the PLC.

| INPUT Device | PLC Address | OUTPUT Device | PLC Address |
|---|---|---|---|
| PB1 | | LED1 | |
| PB2 | | LED2 | |
| PB3 | | LED3 | |
| PB4 | X100 | LED4 | Y120 |
| SW1 | | Relay1 | |
| SW2 | | Relay2 | |
| SW3 | | Relay3 | |
| SW4 | | Relay4 | |
| Sensor1 | | | |
| Sensor2 | | | |
| Sensor3 | | | |
| Sensor4 | | | |
| E-Stop PB | | | |

**Task:** Find out which input devices are normally-open type and which are normally-closed type.

**Task:** Find out what activating each relay does to the left and right gantry.

---

## Programming the PLC

1. Find out the addresses of the inputs (pushbuttons, toggle switches & sensors)

use the display table/showing at the PLC -> the displa -> shows buttons pressed etc


2. Activate the output addresses to identify all the outputs (LEDs, relays)
yes
3. Write a PLC program to **ON the green LED** when Sensor 1 is activated. <!-- id:b58e0d9a-b444-4e49-9075-d01198e5f156 ts:2026-05-17 07:49 -->
