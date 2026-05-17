---
tags:
  - EGE322
  - lab1
  - MicroPython
  - IDE
  - ESP32
  - IoT
  - programming
course: EGE322 IoT System Project
topic: Lab 1 - MicroPython IDE Setup
source: EGE322 Lab 1- MicroPython Programming v2026b.pdf
converted: 2026-05-07
type: Lab
status: Completed
---

> 📚 **Related:** [[NYPY3 - Main Index|NYPY3 Index]] | [[📅 Schedule & Assessments Dashboard|Assessment Dashboard]] | [[03-RESOURCES/EGE322-IOT-System-Project/ESP32_Programming_Guide.md|ESP32 Programming Guide]]

Official (Open)
School of Engineering
Diploma in Electronic & Computer Engineering (EGDF20)
EGE322 – IoT System Project
Course
Module
:
:
Laboratory 1:  MicroPython IDE Setup
- 1.
Objectives
- 1.1
In  this  session,  you  will  learn  how  to  setup  and  program  the  ESP32  WROOM
microcontroller in micropython.
At the end of this laboratory session, you will be able to:



Erase and update the micropython firmware of the ESP32 microcontroller.
Integrated
Execute  MicroPython
the  MicroPython
script  using
Development Environment (IDE).
Program the ESP32 using the MicroPython IDE.
- 2.
Material
Window 10 x64 computer with USB port and Internet connectivity x1
ESP32 WROOM microcontroller board x 1
USB 2.0 data cable with mini-USB connectivity.
EGE322 Lab 1 –MicroPython IDE Setup                                                                      Effective Date: 2026 S1
Page 1 of 9
Official (Open)
- 3.
Procedures
- 3.1
Installation of the MicroPython IDE
Thonny IDE is one of the simplest IDE available for MicroPython. You can create
code, manage code, debug and will be able to flash MicroPython using Thonny

# IDE.

Step : Installation
- a)  Download Thonny IDE from https://thonny.org/
- b)  Double click on
to install or right click on the ‘thonny-3.2.7.exe’
file and click on ‘Run as an administrator’
EGE322 Lab 1 –MicroPython IDE Setup                                                                      Effective Date: 2026 S1
Page 2 of 9
Official (Open)
- c)  Click to accept the agreement on the next screen.
- d)  Select the folder you want to install the Thonny IDE and click on ‘Next’.
e)  Click to Create a desktop icon.
f)  Click Install.
g)  Click on ‘Finish’ once the installation is successfully completed.
h)  Open Thonny IDE from the desktop or start menu.
EGE322 Lab 1 –MicroPython IDE Setup                                                                      Effective Date: 2026 S1
Page 3 of 9
Official (Open)
i)  Short-cut:
a.  F5: Save & Run the current script
b.  Ctrl+N: New File
c.  Ctrl+S: Save the file
d.  Ctrl+D: Soft reboot
e.  Ctrl+C: Keyword interrupt
- 3.2  Download the ESP32 MicroPython Firmware Bin File
- a)  Next you will have to connect the ESP32 microcontroller to the PC desktop using
the USB cable.
- b)  Go to the Device Manager, you can see that the ESP32 board is connected to the
Serial Port COM6 (in this case)
- c)  Download and install the CP210X VCP USB Driver if your computer cannot detect
the ESP32 Wroom Microcontroller board.
- d)  The MicroPython may not be flashed onto the ESP32 microcontroller by default.
You will need to go to the MicroPython download page to download the latest
binary file to flash your Python microcontroller.
e)  Open the Thonny IDE.
EGE322 Lab 1 –MicroPython IDE Setup                                                                      Effective Date: 2026 S1
Page 4 of 9
Official (Open)
f)  Click on Run -> Configure Interpreter
g)  Select the correct device in your interpreter and the correct USB port as shown:
Click ‘Install or update MicroPython (esptool)’
EGE322 Lab 1 –MicroPython IDE Setup                                                                      Effective Date: 2026 S1
Page 5 of 9
Official (Open)
h)  5.Scroll down to select the USB port, the device and version of the micropython
software. If you need to download older version of the firmware, you have to click
on the link
‘https://micropythonorg/download/ESP32_GENERIC
Note: An older version of the firmware has also been uploaded to Brightspace for
your reference.
i)
If you click on the link http://micropython.org/download#esp32,  it will bring you
to the MicroPython download page. Scroll down to the ESP32 section
and select the version of the esp32 binary file you want to download.
EGE322 Lab 1 –MicroPython IDE Setup                                                                      Effective Date: 2026 S1
Page 6 of 9
Official (Open)
j)  Alternatively, if you have already downloaded a local MicroPython firmware image
file, you can flash the firmware directly by clicking the button shown below.
k)  Click ‘close’ to exit
EGE322 Lab 1 –MicroPython IDE Setup                                                                      Effective Date: 2026 S1
Page 7 of 9
Official (Open)
l)  After installation, you will see:
m) The ‘>>>’ in the python REPL tells you that the micropython has been successfully
installed in the ESP32 microcontroller.
n)  Tips: If flashing the ESP32 fails, try pressing and holding the BOOT button before
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
f)  Save the file as blink.py in your working directory. Press ‘RUN’ to run the blink.py
file.
g)  Now you can see that there are two ways of running the python script; one way
is to use the REPL and the other is run as a python script.
- 4.
Conclusion
In this laboratory exercise, we have:
Learn how to setup the micropython firmware for the ESP32 WROOM.
Learn how to program the ESP32 WROOM using the microPython IDE.
Learn  how  to  run  the  micropython  codes  in  the  IDE  in  REPL  and  as  a
python script.

# -  THE END -

EGE322 Lab 1 –MicroPython IDE Setup                                                                      Effective Date: 2026 S1
Page 9 of 9

---

