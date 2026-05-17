---
id: "d6a389f8-4053-4bb4-914b-c37a30b1e743"
title: "Ggle Led Using Button Switch"
type: vault_note
vault: wiki
created: 2026-05-17
updated: 2026-05-17
checksum: "sha256:3e6add7c049480c0"
source: heimdall/auto
---

# Ggle Led Using Button Switch

- ggle LED using Button Switch (GPIO INPUT)
A digital input is a board pin which can read if it sees a high(ON) or low(OFF)
logic level connected to it. For example, if you connect a button to a digital input
you can detect when the button is pressed and released.
We will connect a momentary push button to one of the digital inputs of the
ESP32 and try to read the status of the push button.
- a)
- b)
Connect the LED to GPIO 5 and Push Button Switch to GPIO 15
Enter the button.py program as shown below:
from machine import Pin
button = Pin(15, Pin.IN, Pin.PULL_UP)
while True:
if not button.value( ):
print(‘Button pressed!)
The execution is continuous and can only be stopped by pressing STOP or ctrl-C
to terminate the program.
- c)
Next, we will modify the program to detect only one key press.
from machine import Pin
from time import sleep
button = Pin(19,Pin.IN,Pin.PULL_UP)
while True:
first=button.value()
sleep(0.01)
second=button.value()
if first and not second:
print('Button pressed!')
EGE322 Lab 2 – Controlling the ESP32 GPIOs
Effective Date: 2026 S1
Page 6 of 8
Official (Open)
elif not first and second:
print('Button released!')
- d)  Next we will modify the program to light up the LED with the button is pressed.
from machine import Pin
from time import sleep
button = Pin(15,Pin.IN,Pin.PULL_UP)
led=Pin(5,Pin.OUT)
while True:
first=button.value()
sleep(0.01)
second=button.value()
#led.value(1)
if first and not second:
# Turn on LED
led.value(1)
#print('LED turned ON')
elif n <!-- id:d6a389f8-4053-4bb4-914b-c37a30b1e743 ts:2026-05-17 07:49 -->
- ggle LED using Button Switch (GPIO INPUT)
A digital input is a board pin which can read if it sees a high(ON) or low(OFF)
logic level connected to it. For example, if you connect a button to a digital input
you can detect when the button is pressed and released.
We will connect a momentary push button to one of the digital inputs of the
ESP32 and try to read the status of the push button.
- a)
- b)
Connect the LED to GPIO 5 and Push Button Switch to GPIO 15
Enter the button.py program as shown below:
from machine import Pin
button = Pin(15, Pin.IN, Pin.PULL_UP)
while True:
if not button.value( ):
print(‘Button pressed!)
The execution is continuous and can only be stopped by pressing STOP or ctrl-C
to terminate the program.
- c)
Next, we will modify the program to detect only one key press.
from machine import Pin
from time import sleep
button = Pin(19,Pin.IN,Pin.PULL_UP)
while True:
first=button.value()
sleep(0.01)
second=button.value()
if first and not second:
print('Button pressed!')
EGE322 Lab 2 – Controlling the ESP32 GPIOs
Effective Date: 2026 S1
Page 6 of 8
Official (Open)
elif not first and second:
print('Button released!')
- d)  Next we will modify the program to light up the LED with the button is pressed.
from machine import Pin
from time import sleep
button = Pin(15,Pin.IN,Pin.PULL_UP)
led=Pin(5,Pin.OUT)
while True:
first=button.value()
sleep(0.01)
second=button.value()
#led.value(1)
if first and not second:
# Turn on LED
led.value(1)
#print('LED turned ON')
elif n <!-- id:d6a389f8-4053-4bb4-914b-c37a30b1e743 ts:2026-05-17 07:49 -->
