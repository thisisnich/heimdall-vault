---
tags:
  - EGE322
  - lab3
  - ESP32
  - GPIO
  - IoT
  - microcontroller
  - sensor-interaction
course: EGE322 IoT System Project
topic: Lab 3 - Interacting with the ESP32 GPIOs
source: EGE322 Lab 3- Interacting with the ESP32 GPIOs v2026-1.pdf
converted: 2026-05-07
type: Lab
status: Completed
---

> 📚 **Related:** [[NYPY3 - Main Index|NYPY3 Index]] | [[03-RESOURCES/EGE322-IOT-System-Project/EGE322 Lab 2- Controlling the ESP32 GPIOs v2026-1.md|Lab 2]] | [[📅 Schedule & Assessments Dashboard|Assessment Dashboard]]

Official (Open)
School of Engineering
Diploma in Electronic & Computer Engineering (EGDF20)
EGE322 – IoT System Project
Course
Module
:
:
Laboratory 3:  Interacting with the ESP32 GPIOs
- 1.
Objectives
In  this  session,  you  will  learn  how  to  program  the  GPIO  ports  of  the    ESP32
microcontroller in micropython.
At the end of this laboratory session, you will be able to write a micropython script
to:



read the potentiometer reading using the ADC
use PWM to control colour of LEDs,
use PWM to control the position of the servo motor
- 2.
Material
Window 10 x64 computer with USB port and Internet connectivity x1
ESP32 NodeMCU microcontroller board x 1
USB 2.0 data cable with mini-USB connectivity. x 1
Green and Red leds x 2
Momentary Switch  x 1
24 x 24mm OLED display x 1
EGE322 Lab 3 – Interacting with the ESP32 GPIOs
Effective Date: 2026 S1
Page 1 of 14
Official (Open)
- 3.
The ESP32 Microcontroller Board
- 3.1
Introduction to the ESP32 Board
The ESP32 ADC pins have 12-bit resolution. These pins read voltages between 0
and 3.3V  and  returns  a  digital  value  between  0  and  4095.  Using  a  10-bit  ADC
resolution that can be programmed in software, the value will be between 0 and
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
signal using a digital source. A PWM signal consists of two main components
that define its behaviour: a duty cycle and a frequency. The duty cycle describes
the amount of time the signal is in a high (on) state as a percentage of the total
time of it takes to complete one cycle. The frequency determines how fast the
PWM completes a cycle (i.e. 1000 Hz would be 1000 cycles per second), and
therefore how fast it switches between high and low states. By cycling a digital
signal off and on at a fast enough rate, and with a certain duty cycle, the output
will appear to behave like a constant voltage analog signal when providing
power to devices.
The PWM can be used to position the SERVO motor from 0 to 180 degrees.
EGE322 Lab 3 – Interacting with the ESP32 GPIOs
Effective Date: 2026 S1
Page 7 of 14
Official (Open)
Hardware Connection
All servo motors have 3 wires: Red to 5V Supply, Black or Brown to Ground and
Yellow to PWM Signal.
Software Setup
First import from machine module the Pin and PWM class
>>from machine import Pin, PWM
Then create a PWM object called led and pass on to the GPIO Pin 23
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
Wire up the ESP32 and write a MicroPython script to control a Servo motor
using a potentiometer.
  When the potentiometer is at its minimum position, the Servo motor should
rotate to 0°.
  When the potentiometer is adjusted to its maximum position, the Servo
motor should rotate to 180°.
- 4.2
Exercise 2
Write an ESP32 MicroPython script to control an LED and a Servo motor using an
LDR sensor.
  When the LDR illumination value is below 700, the LED should turn ON and
the Servo motor should rotate to 90°.
  When the LDR illumination value is above 700, the LED should turn OFF and
the Servo motor should rotate back to 0°.
5
Conclusion
In this laboratory exercise, we have learnt how to read the GPIO analog port and
control the GPIO port using PWM.

# -THE END -

EGE322 Lab 3 – Interacting with the ESP32 GPIOs
Effective Date: 2026 S1
Page 14 of 14

---

