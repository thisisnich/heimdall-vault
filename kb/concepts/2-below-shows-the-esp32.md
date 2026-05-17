- 2 below  shows the  ESP32  DEVKIT  board  with  the ESP-WROOM-32
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
led1 <!-- id:dd59bdbb-e693-47db-a16f-705bc9ef4143 ts:2026-05-17 07:49 -->
