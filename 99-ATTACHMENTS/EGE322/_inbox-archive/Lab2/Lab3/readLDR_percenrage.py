from machine import Pin, ADC
import time

class LDR:
    def __init__(self, pin):
        self.ldr_pin = ADC(Pin(pin))
        self.ldr_pin.atten(ADC.ATTN_11DB)

    def get_raw_value(self):
        return self.ldr_pin.read_u16()

    def get_light_percentage(self):
        return round(self.get_raw_value() / 65535 * 100, 2)

ldr = LDR(36)

while True:
    print(ldr.get_light_percentage())
    time.sleep(1)