from machine import Pin
from time import sleep

button1 = Pin(15, Pin.IN, Pin.PULL_UP)
button2 = Pin(19, Pin.IN, Pin.PULL_UP)

led1 = Pin(5, Pin.OUT)
led2 = Pin(2, Pin.OUT)

while True:
    first1 = button1.value()
    first2 = button2.value()

    sleep(0.01)

    second1 = button1.value()
    second2 = button2.value()

    # Button 1 pressed once → toggle LED1
    if first1 and not second1:
        led1.value(not led1.value())

    # Button 2 pressed once → toggle LED2
    if first2 and not second2:
        led2.value(not led2.value())