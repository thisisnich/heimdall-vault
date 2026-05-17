---
id: "771dd645-8761-4d7d-8420-d81bcdb08160"
title: "Official Open School Of Engineering"
type: vault_note
vault: wiki
created: 2026-05-17
updated: 2026-05-17
checksum: "sha256:0cd5f071703dcbdc"
source: heimdall/auto
---

# Official Open School Of Engineering

- Official (Open)
School of Engineering
Course:  Diploma in Electronic and Computer Engineering
Module:  EGE351 Automation Systems & Control
Name:
Team Members:
Module Group:
Date Submitted:

# EXPERIMENT NO.:


# EGE351 / LAB 2

EXPERIMENT TITLE:  Automation – PLC Programming 2

## OBJECTIVES:

- a)  Understand and apply a latching PLC program
- b)  Understand and apply a PLC Timer

## EQUIPMENT:

Programmable Logic Controller PLC FP7

## COMPONENTS:

Input/Output devices
Automation Systems & Control
Page 1 of 2
Effective Date: 16 Oct 2023
Official (Open)
Write and test the following PLC programs;
- 1)  Write  a  PLC  program  to  turn  on  an  LED  (Y120)  when  a  normally-open  pushbutton  (PB1)  is
pressed. The LED turns off when another normally-open pushbutton (PB2) is pressed.
- 2)  Write a PLC program to blink an LED (Y121) at 1Hz when a  normally-open pushbutton (PB3) is
pressed. The LED turns off when another normally-closed pushbutton (PB4) is pressed.
- 3)  Write a PLC program to turn an LED (Y122) after 5 seconds, when a normally-open pushbutton
(PB5) is pressed. <!-- id:771dd645-8761-4d7d-8420-d81bcdb08160 ts:2026-05-17 07:49 -->
- Official (Open)
School of Engineering
Course:  Diploma in Electronic and Computer Engineering
Module:  EGE351 Automation Systems & Control
Name:
Team Members:
Module Group:
Date Submitted:

# EXPERIMENT NO.:


# EGE351 / LAB 2

EXPERIMENT TITLE:  Automation – PLC Programming 2

## OBJECTIVES:

- a)  Understand and apply a latching PLC program
- b)  Understand and apply a PLC Timer

## EQUIPMENT:

Programmable Logic Controller PLC FP7

## COMPONENTS:

Input/Output devices
Automation Systems & Control
Page 1 of 2
Effective Date: 16 Oct 2023
Official (Open)
Write and test the following PLC programs;
- 1)  Write  a  PLC  program  to  turn  on  an  LED  (Y120)  when  a  normally-open  pushbutton  (PB1)  is
pressed. The LED turns off when another normally-open pushbutton (PB2) is pressed.
- 2)  Write a PLC program to blink an LED (Y121) at 1Hz when a  normally-open pushbutton (PB3) is
pressed. The LED turns off when another normally-closed pushbutton (PB4) is pressed.
- 3)  Write a PLC program to turn an LED (Y122) after 5 seconds, when a normally-open pushbutton
(PB5) is pressed. <!-- id:771dd645-8761-4d7d-8420-d81bcdb08160 ts:2026-05-17 07:49 -->
- Official (Open)
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
ADC  pins. <!-- id:d6bdee54-2774-4a7e-b805-7d9ebde232ff ts:2026-05-17 07:49 -->
- Official (Open)
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
ADC  pins. <!-- id:d6bdee54-2774-4a7e-b805-7d9ebde232ff ts:2026-05-17 07:49 -->
