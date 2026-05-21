# Blinking an LED
from machine import Pin
from time import sleep
# The onboard blue LED is connected to GPIO 2.
led = Pin(2, Pin.OUT)
while True:
    led.value(not led.value( ))
    sleep(0.5) 