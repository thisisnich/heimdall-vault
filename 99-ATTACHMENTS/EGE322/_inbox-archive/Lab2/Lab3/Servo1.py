from machine import Pin, PWM
import time

servo = PWM(Pin(23), freq=50)

servo.duty(20)   # about 0 degree
time.sleep_ms(1000)

servo.duty(70)   # about 90 degree
time.sleep_ms(1000)

servo.duty(120)  # about 180 degree
time.sleep_ms(1000)	