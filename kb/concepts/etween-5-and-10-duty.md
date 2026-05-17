---
id: "43cb7f26-7503-4a6e-873b-f3f21002e44c"
title: "Etween 5 And 10 Duty"
type: vault_note
vault: wiki
created: 2026-05-17
updated: 2026-05-17
checksum: "sha256:013b21f82d4cb964"
source: heimdall/auto
---

# Etween 5 And 10 Duty

- etween 5 and 10% duty cycle of a 50Hz waveform.
The PWM and Angle Relationship
With a 1.5ms pulse, the servo motor will be at 90 degree from -90 to 0 degree.
With a 2.5ms pulse, the servo will be at 180 degree from -90 to +90 degree.
Servo_1.py
from machine import Pin, PWM import time
servo=PWM(Pin(23), freq=50)
servo.duty(20)  # to position servo at 9 degree
time.sleep_ms(1000)
servo.duty(70) # to position servo at 90 degree
time.sleep_ms(1000)
servo.duty(120) # to position servo at 180 degree
time.sleep_ms(1000)
EGE322 Lab 3 – Interacting with the ESP32 GPIOs
Effective Date: 2026 S1
Page 11 of 14
Official (Open)
The Code Flow Chart
Servo_2.py
#import related modules
from machine import Pin, PWM
import time
# Servo1's pin is 23
S1 = PWM(Pin(23), freq=50, duty=0)
EGE322 Lab 3 – Interacting with the ESP32 GPIOs
Effective Date: 2026 S1
Page 12 of 14
Official (Open)
'''
Description: Servo control function
Function: 180 degree steering gear: angle: -90 to 90 represents the
corresponding angle
360 continuous rotation degree servo: angle: -90 to 90 rotation direction
and speed value.
'''
def Servo(servo,angle):
S1.duty(int(((angle+90)*2/180+0.5)/20*1023))
#-90 degrees
Servo(S1,-90)
time.sleep(1)
#-45 degrees
Servo(S1,-45)
time.sleep(1)
#0 degrees
Servo(S1,0)
time.sleep(1)
#45 degrees
Servo(S1,45)
time.sleep(1)
#90 degrees
Servo(S1,90)
time.sleep(1)
EGE322 Lab 3 – Interacting with the ESP32 GPIOs
Effective Date: 2026 S1
Page 13 of 14
Official (Open)
- 4.1
Exercise 1
Wire up the ESP3 <!-- id:43cb7f26-7503-4a6e-873b-f3f21002e44c ts:2026-05-17 07:49 -->
- etween 5 and 10% duty cycle of a 50Hz waveform.
The PWM and Angle Relationship
With a 1.5ms pulse, the servo motor will be at 90 degree from -90 to 0 degree.
With a 2.5ms pulse, the servo will be at 180 degree from -90 to +90 degree.
Servo_1.py
from machine import Pin, PWM import time
servo=PWM(Pin(23), freq=50)
servo.duty(20)  # to position servo at 9 degree
time.sleep_ms(1000)
servo.duty(70) # to position servo at 90 degree
time.sleep_ms(1000)
servo.duty(120) # to position servo at 180 degree
time.sleep_ms(1000)
EGE322 Lab 3 – Interacting with the ESP32 GPIOs
Effective Date: 2026 S1
Page 11 of 14
Official (Open)
The Code Flow Chart
Servo_2.py
#import related modules
from machine import Pin, PWM
import time
# Servo1's pin is 23
S1 = PWM(Pin(23), freq=50, duty=0)
EGE322 Lab 3 – Interacting with the ESP32 GPIOs
Effective Date: 2026 S1
Page 12 of 14
Official (Open)
'''
Description: Servo control function
Function: 180 degree steering gear: angle: -90 to 90 represents the
corresponding angle
360 continuous rotation degree servo: angle: -90 to 90 rotation direction
and speed value.
'''
def Servo(servo,angle):
S1.duty(int(((angle+90)*2/180+0.5)/20*1023))
#-90 degrees
Servo(S1,-90)
time.sleep(1)
#-45 degrees
Servo(S1,-45)
time.sleep(1)
#0 degrees
Servo(S1,0)
time.sleep(1)
#45 degrees
Servo(S1,45)
time.sleep(1)
#90 degrees
Servo(S1,90)
time.sleep(1)
EGE322 Lab 3 – Interacting with the ESP32 GPIOs
Effective Date: 2026 S1
Page 13 of 14
Official (Open)
- 4.1
Exercise 1
Wire up the ESP3 <!-- id:43cb7f26-7503-4a6e-873b-f3f21002e44c ts:2026-05-17 07:49 -->
