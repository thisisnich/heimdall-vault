# Read ADC
from machine import Pin, ADC
from time import sleep

pot = ADC(Pin(36))
pot.atten(ADC.ATTN_11DB)  # Full range: about 0V to 3.3V

while True:
    pot_value = pot.read()
    print(pot_value)
    sleep(0.1)