---
id: "8409e6cb-5df2-4ba5-abf5-52ff1370780e"
title: "Irstbuttonvalue Sleep001 Secondbuttonvalue Ledvalue1 If"
type: vault_note
vault: wiki
created: 2026-05-17
updated: 2026-05-17
checksum: "sha256:40472864baedb19b"
source: heimdall/auto
---

# Irstbuttonvalue Sleep001 Secondbuttonvalue Ledvalue1 If

- irst=button.value()
sleep(0.01)
second=button.value()
#led.value(1)
if first and not second:
# Turn on LED
led.value(1)
#print('LED turned ON')
elif not first and second:
led.value(0)
#print('LED turned OFF')
e)
Next, we will modify the program to toggle the LED ‘ON’ and ‘OFF’ with the
press of the button.
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
# Toggle the  LED
led.value(not led.value( ))
EGE322 Lab 2 – Controlling the ESP32 GPIOs
Effective Date: 2026 S1
Page 7 of 8
Official (Open)
- 3.3
Exercise
Wire up the ESP32 board with 2 push-button and write a micropython program
to turn on LED1 with push-button 1 and turn on LED2 with push-button2 and to
turn off
- 4.
Conclusion
In this laboratory exercise, we have:
Learn how to program the ESP32 using the GPIO ports.
Next, we will learn how to read analog signal and program the ESP32 using PWM.

# -  THE END -

EGE322 Lab 2 – Controlling the ESP32 GPIOs
Effective Date: 2026 S1
Page 8 of 8

--- <!-- id:8409e6cb-5df2-4ba5-abf5-52ff1370780e ts:2026-05-17 07:49 -->
- irst=button.value()
sleep(0.01)
second=button.value()
#led.value(1)
if first and not second:
# Turn on LED
led.value(1)
#print('LED turned ON')
elif not first and second:
led.value(0)
#print('LED turned OFF')
e)
Next, we will modify the program to toggle the LED ‘ON’ and ‘OFF’ with the
press of the button.
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
# Toggle the  LED
led.value(not led.value( ))
EGE322 Lab 2 – Controlling the ESP32 GPIOs
Effective Date: 2026 S1
Page 7 of 8
Official (Open)
- 3.3
Exercise
Wire up the ESP32 board with 2 push-button and write a micropython program
to turn on LED1 with push-button 1 and turn on LED2 with push-button2 and to
turn off
- 4.
Conclusion
In this laboratory exercise, we have:
Learn how to program the ESP32 using the GPIO ports.
Next, we will learn how to read analog signal and program the ESP32 using PWM.

# -  THE END -

EGE322 Lab 2 – Controlling the ESP32 GPIOs
Effective Date: 2026 S1
Page 8 of 8

--- <!-- id:8409e6cb-5df2-4ba5-abf5-52ff1370780e ts:2026-05-17 07:49 -->
