# Blinking 2 LEDs
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