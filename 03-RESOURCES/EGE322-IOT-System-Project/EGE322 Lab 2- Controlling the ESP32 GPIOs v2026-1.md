---
tags:
  - EGE322
  - lab2
  - ESP32
  - GPIO
  - IoT
  - microcontroller
course: EGE322 IoT System Project
topic: Lab 2 - Controlling the ESP32 GPIOs
source: EGE322 Lab 2- Controlling the ESP32 GPIOs v2026-1.pdf
converted: 2026-05-07
type: Lab
status: Completed
---

> 📚 **Related:** [[NYPY3 - Main Index|NYPY3 Index]] | [[03-RESOURCES/EGE322-IOT-System-Project/EGE322 Lab 1- MicroPython Programming v2026b.md|Lab 1]] | [[📅 Schedule & Assessments Dashboard|Assessment Dashboard]]

> 📚 **Related:** [[NYPY3 - Main Index|NYPY3 Index]] | [[03-RESOURCES/EGE322-IOT-System-Project/EGE322 Lab 1- MicroPython Programming v2026b.md|Lab 1]] | [[📅 Schedule & Assessments Dashboard|Assessment Dashboard]]

Official (Open)
School of Engineering
Diploma in Electronic & Computer Engineering (EGDF20)
EGE322 –IoT System Project
Course
Module
:
:
Laboratory 2:  Controlling the ESP32 GPIOs
- 1.
Objectives
In  this  session,  you  will  learn  how  to  program  the  GPIO  ports  of  the    ESP32
microcontroller in micropython.
At the end of this laboratory session, you will be able to write a micropython script
to:


turn on and off leds,
on and off the leds using a momentary switch.
- 2.
Material
Window 10 x64 computer with USB port and Internet connectivity x1
ESP32 NodeMCU microcontroller board x 1
USB 2.0 data cable with mini-USB connectivity. x 1
Green and Red leds x 2
Momentary Switch  x 1
EGE322 Lab 2 – Controlling the ESP32 GPIOs
Effective Date: 2026 S1
Page 1 of 8
Official (Open)
- 3.
The ESP32 Microcontroller Board
- 3.1
Introduction to the ESP32 Board
Throughout this course, we’ll be using the ESP32 DEVKIT board with the ESP32-
WROOM-32 chip. There are many others ESP32 boards like the ESP32 Thing and
the HUZZAH32 ESP32 board.
Figure 1: The Adafruits Huzzah32 ESP32 and the Sparkfun ESP32 Thing
You can use any of the other boards but the pin configuration may be different
from board to board for connection to external devices.
The Figure  2 below  shows the  ESP32  DEVKIT  board  with  the ESP-WROOM-32
module.
Figure 2
The board can be powered by the USB port or from the 5V supply pin. There is an
on-board 3.3V regulator to drop the voltage down to power the ESP-WROOM-
32 module.
There is an on-board BOOT button to soft-reboot the ESP-WROOM-32 module.
EGE322 Lab 2 – Controlling the ESP32 GPIOs
Effective Date: 2026 S1
Page 2 of 8
Official (Open)
Figure 3 below shows thet pin configuration of the ESP32-WROOM-32 board.
Figure 3
- 3.2.
Programming the ESP32 Board
- 3.2.1  Blinking an LED
- a)
Open ThonnyIDE.  Create a new file name it as main.py
File > New > untitled
File > Save
Click ‘OK’ and save the file as main.py
- b)
Enter the following codes and save the file as main.py
# Blinking an LED from machine
import Pin from time import sleep
led = Pin(2, Pin.OUT) # The onboard blue LED is connected to GPIO 2.
while True:
led.value(not led.value( ))
sleep(0.5)
EGE322 Lab 2 – Controlling the ESP32 GPIOs
Effective Date: 2026 S1
Page 3 of 8
Official (Open)
- c)
Click on the “Run” button to run the file
- d)
e)
You will see the onboard ‘red’ led blinking.
Press the ‘Stop’ button to stop the scrip that is running on your ESP32 board.
EGE322 Lab 2 – Controlling the ESP32 GPIOs
Effective Date: 2026 S1
Page 4 of 8
Official (Open)
- 3.2.2  Blinking 2 LED
Connect LED 1 to GPIO pin 2 and LED 2 to GPIO pin 5.
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

---

