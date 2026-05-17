---
id: "d2b1eda6-4a01-4091-801e-cee92e5cf702"
title: "Io Pin 23 Ledpwmpin23 Once"
type: vault_note
vault: wiki
created: 2026-05-17
updated: 2026-05-17
checksum: "sha256:48390380cb9e37e8"
source: heimdall/auto
---

# Io Pin 23 Ledpwmpin23 Once

- IO Pin 23
>>led=PWM(Pin(23))
Once the led object is created you can use the methods like the duty to set the
duty cycle and freq to set the frequency. The duty cycle can varies from 0 to
1023.
>>led.duty(512)
>>led.freq(1)
You can also create the PWM object in a single code:
>>led=PWM(Pin(15),freq=1,duty=256)
To stop the PWM use the method deinit( )
>>led.deinit( )
- a)
- b)
- c)
- d)
e)
EGE322 Lab 3 – Interacting with the ESP32 GPIOs
Effective Date: 2026 S1
Page 8 of 14
Official (Open)
f)
Let’s write a python script to fade the LED using PWM.
fadeLED.py
def ledpwm( ):
from machine import Pin, PWM
import time
led=PWM(Pin(23))
led.freq(1000)
duty_cycle=0
while True:
for duty_cycle in range (0,1024):
led.duty(duty_cycle)
time.sleep_ms(2)
ledpwm( )
EGE322 Lab 3 – Interacting with the ESP32 GPIOs
Effective Date: 2026 S1
Page 9 of 14
Official (Open)
++++++
Fade2.py
from machine import Pin, PWM
import time
led2 = PWM(Pin(2))
led2.freq(1000)
while True:
for i in range(0, 1024):
led2.duty(i)
time.sleep_ms(1)
for i in range(1023, -1, -1):
led2.duty(i)
time.sleep_ms(1)
EGE322 Lab 3 – Interacting with the ESP32 GPIOs
Effective Date: 2026 S1
Page 10 of 14
Official (Open)
g)
The PWM method can be used to position the SERVO motor from 0 to 180
degree.
A typical Servo motor expects to be updated every 20ms with a pulse between
1ms to 2ms, or between 5 and 10% duty cycle of a 50Hz waveform.
The PWM and Angle Relationship
With a 1.5ms pulse, the servo motor will be at 90 degree from -90 to 0 <!-- id:d2b1eda6-4a01-4091-801e-cee92e5cf702 ts:2026-05-17 07:49 -->
- IO Pin 23
>>led=PWM(Pin(23))
Once the led object is created you can use the methods like the duty to set the
duty cycle and freq to set the frequency. The duty cycle can varies from 0 to
1023.
>>led.duty(512)
>>led.freq(1)
You can also create the PWM object in a single code:
>>led=PWM(Pin(15),freq=1,duty=256)
To stop the PWM use the method deinit( )
>>led.deinit( )
- a)
- b)
- c)
- d)
e)
EGE322 Lab 3 – Interacting with the ESP32 GPIOs
Effective Date: 2026 S1
Page 8 of 14
Official (Open)
f)
Let’s write a python script to fade the LED using PWM.
fadeLED.py
def ledpwm( ):
from machine import Pin, PWM
import time
led=PWM(Pin(23))
led.freq(1000)
duty_cycle=0
while True:
for duty_cycle in range (0,1024):
led.duty(duty_cycle)
time.sleep_ms(2)
ledpwm( )
EGE322 Lab 3 – Interacting with the ESP32 GPIOs
Effective Date: 2026 S1
Page 9 of 14
Official (Open)
++++++
Fade2.py
from machine import Pin, PWM
import time
led2 = PWM(Pin(2))
led2.freq(1000)
while True:
for i in range(0, 1024):
led2.duty(i)
time.sleep_ms(1)
for i in range(1023, -1, -1):
led2.duty(i)
time.sleep_ms(1)
EGE322 Lab 3 – Interacting with the ESP32 GPIOs
Effective Date: 2026 S1
Page 10 of 14
Official (Open)
g)
The PWM method can be used to position the SERVO motor from 0 to 180
degree.
A typical Servo motor expects to be updated every 20ms with a pulse between
1ms to 2ms, or between 5 and 10% duty cycle of a 50Hz waveform.
The PWM and Angle Relationship
With a 1.5ms pulse, the servo motor will be at 90 degree from -90 to 0 <!-- id:d2b1eda6-4a01-4091-801e-cee92e5cf702 ts:2026-05-17 07:49 -->
