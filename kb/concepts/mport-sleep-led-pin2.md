---
id: "63246aeb-844b-422d-98d5-84a6712a478b"
title: "Mport Sleep Led Pin2"
type: vault_note
vault: wiki
created: 2026-05-17
updated: 2026-05-17
checksum: "sha256:6ec55e679dd3297c"
source: heimdall/auto
---

# Mport Sleep Led Pin2

- mport sleep
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

--- <!-- id:63246aeb-844b-422d-98d5-84a6712a478b ts:2026-05-17 07:49 -->
