---
id: "528cf9a7-cf3b-4cbe-8a0e-8be9e4379c20"
title: "Rd   322 Reading The"
type: vault_note
vault: wiki
created: 2026-05-17
updated: 2026-05-17
checksum: "sha256:223a4298768ce263"
source: heimdall/auto
---

# Rd   322 Reading The

- rd.
- 3.2.2  Reading the LDR Sensor
Circuit Connection:
EGE322 Lab 3 – Interacting with the ESP32 GPIOs
Effective Date: 2026 S1
Page 4 of 14
Figure 3
Official (Open)
In this exercise, we will connect a photoresistor to the ESP32 Micropython board
to read the amount of light present.
- a)
Create a New python script and enter the following codes:
from machine import Pin, ADC
from time import sleep
pot=ADC(Pin(36))
pot.atten(ADC.ATTN_11DB) #Full Range
while True:
pot_value=pot.read( )
lumvalue=(pot_value-40)*(10/86)
print(lumvalue)
sleep(0.1)
- b)
Save the file and Run the script.
- c)
Press the ‘Stop’ button to stop the scrip that is running on your ESP32 board.
EGE322 Lab 3 – Interacting with the ESP32 GPIOs
Effective Date: 2026 S1
Page 5 of 14
Official (Open)
Using Class
To make the python code modular, the above code can also be written using
class.
LDR_class.py
from machine import Pin
import time
class LDR:
def __init__(self, pin):
self.ldr_pin = machine.ADC(Pin(pin))
def get_raw_value(self):
return self.ldr_pin.read_u16()
def get_light_percentage(self):
return round(self.get_raw_value()/65535*100,2)
ldr = LDR(36)
while True:
print(ldr.get_light_percentage())
time.sleep(1)
EGE322 Lab 3 – Interacting with the ESP32 GPIOs
Effective Date: 2026 S1
Page 6 of 14
Official (Open)
- 3.2.3  Controlling Port using Pulse-Width Modulation(PWM)
What is a Pulse Width Modulation?
A Pulse Width Modulation (PWM) Signal is a method for generating an analog
signal using a digital source. <!-- id:528cf9a7-cf3b-4cbe-8a0e-8be9e4379c20 ts:2026-05-17 07:49 -->
- rd.
- 3.2.2  Reading the LDR Sensor
Circuit Connection:
EGE322 Lab 3 – Interacting with the ESP32 GPIOs
Effective Date: 2026 S1
Page 4 of 14
Figure 3
Official (Open)
In this exercise, we will connect a photoresistor to the ESP32 Micropython board
to read the amount of light present.
- a)
Create a New python script and enter the following codes:
from machine import Pin, ADC
from time import sleep
pot=ADC(Pin(36))
pot.atten(ADC.ATTN_11DB) #Full Range
while True:
pot_value=pot.read( )
lumvalue=(pot_value-40)*(10/86)
print(lumvalue)
sleep(0.1)
- b)
Save the file and Run the script.
- c)
Press the ‘Stop’ button to stop the scrip that is running on your ESP32 board.
EGE322 Lab 3 – Interacting with the ESP32 GPIOs
Effective Date: 2026 S1
Page 5 of 14
Official (Open)
Using Class
To make the python code modular, the above code can also be written using
class.
LDR_class.py
from machine import Pin
import time
class LDR:
def __init__(self, pin):
self.ldr_pin = machine.ADC(Pin(pin))
def get_raw_value(self):
return self.ldr_pin.read_u16()
def get_light_percentage(self):
return round(self.get_raw_value()/65535*100,2)
ldr = LDR(36)
while True:
print(ldr.get_light_percentage())
time.sleep(1)
EGE322 Lab 3 – Interacting with the ESP32 GPIOs
Effective Date: 2026 S1
Page 6 of 14
Official (Open)
- 3.2.3  Controlling Port using Pulse-Width Modulation(PWM)
What is a Pulse Width Modulation?
A Pulse Width Modulation (PWM) Signal is a method for generating an analog
signal using a digital source. <!-- id:528cf9a7-cf3b-4cbe-8a0e-8be9e4379c20 ts:2026-05-17 07:49 -->
