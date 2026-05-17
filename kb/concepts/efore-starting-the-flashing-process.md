---
id: "b27621bd-249d-4955-ac2c-6a879eaec22d"
title: "Efore Starting The Flashing Process"
type: vault_note
vault: wiki
created: 2026-05-17
updated: 2026-05-17
checksum: "sha256:86591f371debf5f6"
source: heimdall/auto
---

# Efore Starting The Flashing Process

- efore
starting the flashing process.
If  the  issue  persists,  try  changing  the  COM  port  or  restarting  the  PC  before
attempting again.
In some cases, certain PCs may not be able to flash the firmware properly. If this
happens,  you  may  ask  a  classmate  to  help  flash  the  firmware,  and  you  can
continue with the programming exercises afterward.
EGE322 Lab 1 –MicroPython IDE Setup                                                                      Effective Date: 2026 S1
Page 8 of 9
Official (Open)
- 3.3  Running the microPython in REPL and as a .py script
- a)   Next, we will enter the following python code using the REPL
With  the  serial  port  connected,  you  will  see  the  >>>  cursor  in  the  Window
console
- b)   Enter the following code and press ‘Enter’ line by line in the REPL.
>>from machine import Pin
>>from time import sleep
>>led=Pin(2,Pin.OUT)
>>while True:
led.value(1)
sleep(0.5)
- c)  You do not have to connect an LED to Pin 2 as there is a default onboard LED
connected to GPIO Pin 2 of the ESP32 board.
- d)  In REPL, each python code is run immediately after it is entered as Python is an
interpreter language.
e)  Next, you will open a new .py file and enter the code as above.
from machine import Pin
from time import sleep
led = Pin(2, Pin.OUT)
while True:
led.value(1)
sleep(0.5)
led.value(0)
sleep(0.5)
f)  Save the file as blink.py in your working directory. <!-- id:b27621bd-249d-4955-ac2c-6a879eaec22d ts:2026-05-17 07:49 -->
