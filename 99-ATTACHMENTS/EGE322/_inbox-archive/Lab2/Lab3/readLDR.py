from machine import Pin, ADC
from time import sleep

pot = ADC(Pin(36))
pot.atten(ADC.ATTN_11DB)  # Full range

while True:
    pot_value = pot.read()
    lumvalue = (pot_value - 40) * (10 / 86)
    print(lumvalue)
    sleep(0.1)