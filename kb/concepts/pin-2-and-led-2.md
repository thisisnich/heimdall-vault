---
id: "f5eb582b-f838-423d-8777-7c965736dfec"
title: "Pin 2 And Led 2"
type: vault_note
vault: wiki
created: 2026-05-17
updated: 2026-05-17
checksum: "sha256:6764879e3521c59f"
source: heimdall/auto
---

# Pin 2 And Led 2

- pin 2 and LED 2 to GPIO pin 5.
- a)
- b)  Modify the main.py program as follows
# Blinking 2 LEDs
from machine import Pin
from time import sleep
led1 = Pin(2, Pin.OUT)
led2 = Pin(5, Pin.OUT)
led1.value(1)
led2.value(0)
sleep(1)
led1.value(0)
led2.value(1)
sleep(1)
- c)
Click on ‘Save’ and ‘Download and Run’ button.
What did you notice?
_______________________________________________________________________________
- d)  Modify the code above to keep the LED1 and LED2 blinking continuously using
the while loop.
from machine import Pin
from time import sleep
led1 = Pin(2, Pin.OUT)
led2 = Pin(5, Pin.OUT)
while True:
led1.value(1)
led2.value(0)
sleep(1)
led1.value(0)
led2.value(1)
sleep(1)
EGE322 Lab 2 – Controlling the ESP32 GPIOs
Effective Date: 2026 S1
Page 5 of 8
Official (Open)
- 3.2.3  Toggle LED using Button Switch (GPIO INPUT)
A digital input is a board pin which can read if it sees a high(ON) or low(OFF)
logic level connected to it. <!-- id:f5eb582b-f838-423d-8777-7c965736dfec ts:2026-05-17 07:49 -->
- pin 2 and LED 2 to GPIO pin 5.
- a)
- b)  Modify the main.py program as follows
# Blinking 2 LEDs
from machine import Pin
from time import sleep
led1 = Pin(2, Pin.OUT)
led2 = Pin(5, Pin.OUT)
led1.value(1)
led2.value(0)
sleep(1)
led1.value(0)
led2.value(1)
sleep(1)
- c)
Click on ‘Save’ and ‘Download and Run’ button.
What did you notice?
_______________________________________________________________________________
- d)  Modify the code above to keep the LED1 and LED2 blinking continuously using
the while loop.
from machine import Pin
from time import sleep
led1 = Pin(2, Pin.OUT)
led2 = Pin(5, Pin.OUT)
while True:
led1.value(1)
led2.value(0)
sleep(1)
led1.value(0)
led2.value(1)
sleep(1)
EGE322 Lab 2 – Controlling the ESP32 GPIOs
Effective Date: 2026 S1
Page 5 of 8
Official (Open)
- 3.2.3  Toggle LED using Button Switch (GPIO INPUT)
A digital input is a board pin which can read if it sees a high(ON) or low(OFF)
logic level connected to it. <!-- id:f5eb582b-f838-423d-8777-7c965736dfec ts:2026-05-17 07:49 -->
