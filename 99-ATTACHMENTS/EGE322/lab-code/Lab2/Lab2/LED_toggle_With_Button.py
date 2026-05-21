from machine import Pin
from time import sleep

button = Pin(15, Pin.IN, Pin.PULL_UP)
led = Pin(5, Pin.OUT)

while True:
    first = button.value()
    sleep(0.01)
    second = button.value()

    if first and not second:
        # Toggle the LED
        led.value(not led.value())