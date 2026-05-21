from machine import Pin
from time import sleep

button = Pin(15, Pin.IN, Pin.PULL_UP)
led = Pin(5, Pin.OUT)

while True:
    first = button.value()
    sleep(0.01)
    second = button.value()

    if first and not second:
        # Button just pressed
        led.value(1)
        print('LED turned ON') 

    elif not first and second:
        # Button just released
        led.value(0)
        print('LED turned OFF')