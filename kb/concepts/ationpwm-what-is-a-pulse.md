---
id: "1711f3f2-1c8a-4c3c-a551-12a1003f4b09"
title: "Ationpwm What Is A Pulse"
type: vault_note
vault: wiki
created: 2026-05-17
updated: 2026-05-17
checksum: "sha256:64844c3243250b36"
source: heimdall/auto
---

# Ationpwm What Is A Pulse

- ation(PWM)
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
duty cycle and freq to set the frequency. <!-- id:1711f3f2-1c8a-4c3c-a551-12a1003f4b09 ts:2026-05-17 07:49 -->
- ation(PWM)
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
duty cycle and freq to set the frequency. <!-- id:1711f3f2-1c8a-4c3c-a551-12a1003f4b09 ts:2026-05-17 07:49 -->
