---
id: "ee50f41d-100a-4d16-b9e8-9447439dee2e"
title: "Ctivate The Output Addresses To"
type: vault_note
vault: wiki
created: 2026-05-17
updated: 2026-05-17
checksum: "sha256:6a0ea41d77598c65"
source: heimdall/auto
---

# Ctivate The Output Addresses To

- ctivate the output addresses to identify all the outputs (LEDs, relays)
yes
3. Write a PLC program to **ON the green LED** when Sensor 1 is activated. Reset the LED by pressing PB1.

internal relay
R (ro)
R1
r2
r3

Can be used as "inputs" nad set as "outputs"

latching circuite : DRAW DIAGRAM HERE

button (x???) ------------------------ ( R3 )
| R3 | --button(inverse) (X???)---^ (R3 is input parallele to button, so latching)

| R3 | -------------------------------- (Y???)


4. Write a PLC program to **blink the red LED** when Sensor 4 is activated. Reset the blinking LED by pressing PB4.
   MAKE TABLE \\/
Use timers -> SR13 (abt 10 Hz) -> first cycle bit
flash/blink bit = SR1A frequency = 10Hz
flash/blink bit = SR1B frequency = 5Hz
flash/blink bit = SR1C frequency = 1Hz
flash/blink bit = SR1D frequency = 0.5Hz (USE TIMER LIKE INPUTS)

x


---

## Understanding

**Briefly explain the difference between using PB1 and PB4 to reset the LED.**

_Answer:_ _______________________________________________

_______________________________________________

**Activate Relays 1 to 4 and note what it does to the gantries:**

_Answer:_ _______________________________________________

_______________________________________________ <!-- id:ee50f41d-100a-4d16-b9e8-9447439dee2e ts:2026-05-17 07:49 -->
- ctivate the output addresses to identify all the outputs (LEDs, relays)
yes
3. Write a PLC program to **ON the green LED** when Sensor 1 is activated. Reset the LED by pressing PB1.

internal relay
R (ro)
R1
r2
r3

Can be used as "inputs" nad set as "outputs"

latching circuite : DRAW DIAGRAM HERE

button (x???) ------------------------ ( R3 )
| R3 | --button(inverse) (X???)---^ (R3 is input parallele to button, so latching)

| R3 | -------------------------------- (Y???)


4. Write a PLC program to **blink the red LED** when Sensor 4 is activated. Reset the blinking LED by pressing PB4.
   MAKE TABLE \\/
Use timers -> SR13 (abt 10 Hz) -> first cycle bit
flash/blink bit = SR1A frequency = 10Hz
flash/blink bit = SR1B frequency = 5Hz
flash/blink bit = SR1C frequency = 1Hz
flash/blink bit = SR1D frequency = 0.5Hz (USE TIMER LIKE INPUTS)

x


---

## Understanding

**Briefly explain the difference between using PB1 and PB4 to reset the LED.**

_Answer:_ _______________________________________________

_______________________________________________

**Activate Relays 1 to 4 and note what it does to the gantries:**

_Answer:_ _______________________________________________

_______________________________________________ <!-- id:ee50f41d-100a-4d16-b9e8-9447439dee2e ts:2026-05-17 07:49 -->
