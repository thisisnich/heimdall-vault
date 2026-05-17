---
id: "a66a7fcd-10b8-4567-8a24-42e1144c1047"
title: "The Value Will Be Between"
type: vault_note
vault: wiki
created: 2026-05-17
updated: 2026-05-17
checksum: "sha256:bfa1daec7a848a91"
source: heimdall/auto
---

# The Value Will Be Between

- the value will be between 0 and
1023.
There are several pins on the ESP32 that can act as analog pins- these are called
as  ADC  pins:
the
ADC  pins.  All
0,2,4,12,13,14,15,25,26,27,32,33,34,35,36 and 39.
following  GPIOs
can
act
Figure 1 below shows thet pin configuration of the ESP32-WROOM-32 board with
the
Figure 1
EGE322 Lab 3 – Interacting with the ESP32 GPIOs
Effective Date: 2026 S1
Page 2 of 14
Official (Open)
- 3.2
Programming the ESP32 Board
- 3.2.1  Reading an Analog Data to the ESP32
- a)
Connect the potentiometer shown in Figure 2 below to the ESP32 board using
the GPIO13.
- b)
- c)
- d)
Figure 2
You can connect VCC to ESP32 board on 3V3 pin (VCC +3.3V) Vout to ESP32
board Analog input on GPIO36 (ADC1_0). In addition, GND to ESP32 board

# GND.

Create a new python file adcdemo.py
File > New > untitled
File > Save
Click ‘OK’ and save the file as adcdemo.py
Enter the following codes and save the file as adcdemo.py
# Read ADC
from machine import Pin, ADC
from time import sleep
pot=ADC(Pin(34))
pot.atten(ADC.ATTN_11DB) #Full Range
while True:
pot_value=pot.read( )
print(pot_value)
sleep(0.1)
e)
Click to run the upload file to the ESP32 board.
EGE322 Lab 3 – Interacting with the ESP32 GPIOs
Effective Date: 2026 S1
Page 3 of 14
Official (Open)
f)
Press the ‘Stop’ button to stop the scrip that is running on your ESP32 board.
- 3.2.2  Reading the LDR Sensor
Circuit Connection:
EGE322 Lab 3 – Interacting with the ESP32 GPIOs
Effective Date: 2026 S1
Page 4 of 14
Figure 3 <!-- id:a66a7fcd-10b8-4567-8a24-42e1144c1047 ts:2026-05-17 07:49 -->
- the value will be between 0 and
1023.
There are several pins on the ESP32 that can act as analog pins- these are called
as  ADC  pins:
the
ADC  pins.  All
0,2,4,12,13,14,15,25,26,27,32,33,34,35,36 and 39.
following  GPIOs
can
act
Figure 1 below shows thet pin configuration of the ESP32-WROOM-32 board with
the
Figure 1
EGE322 Lab 3 – Interacting with the ESP32 GPIOs
Effective Date: 2026 S1
Page 2 of 14
Official (Open)
- 3.2
Programming the ESP32 Board
- 3.2.1  Reading an Analog Data to the ESP32
- a)
Connect the potentiometer shown in Figure 2 below to the ESP32 board using
the GPIO13.
- b)
- c)
- d)
Figure 2
You can connect VCC to ESP32 board on 3V3 pin (VCC +3.3V) Vout to ESP32
board Analog input on GPIO36 (ADC1_0). In addition, GND to ESP32 board

# GND.

Create a new python file adcdemo.py
File > New > untitled
File > Save
Click ‘OK’ and save the file as adcdemo.py
Enter the following codes and save the file as adcdemo.py
# Read ADC
from machine import Pin, ADC
from time import sleep
pot=ADC(Pin(34))
pot.atten(ADC.ATTN_11DB) #Full Range
while True:
pot_value=pot.read( )
print(pot_value)
sleep(0.1)
e)
Click to run the upload file to the ESP32 board.
EGE322 Lab 3 – Interacting with the ESP32 GPIOs
Effective Date: 2026 S1
Page 3 of 14
Official (Open)
f)
Press the ‘Stop’ button to stop the scrip that is running on your ESP32 board.
- 3.2.2  Reading the LDR Sensor
Circuit Connection:
EGE322 Lab 3 – Interacting with the ESP32 GPIOs
Effective Date: 2026 S1
Page 4 of 14
Figure 3 <!-- id:a66a7fcd-10b8-4567-8a24-42e1144c1047 ts:2026-05-17 07:49 -->
