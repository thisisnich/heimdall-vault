import urequests
import dht
import time
from machine import Pin, I2C
from ssd1306 import SSD1306_I2C

# --- config (lab-specific — safe to edit here) ---
THINGSPEAK_WRITE_API_KEY = '2EIDLLVI722CKFIE'
UPDATE_MS = 5000

# --- hardware ---
led = Pin(2, Pin.OUT)
sensor = dht.DHT22(Pin(15))
i2c = I2C(scl=Pin(22), sda=Pin(21))
oled = SSD1306_I2C(128, 64, i2c, 0x3c)


def dht22():
    """Lab 7 exercise 2 — wrap sensor read."""
    sensor.measure()
    return sensor.temperature(), sensor.humidity()


def show_oled(t, h):
    oled.fill(0)
    oled.text('ThingSpeak', 0, 0)
    oled.text('T: %.1f C' % t, 0, 18)
    oled.text('H: %.1f %%' % h, 0, 34)
    oled.show()


last = time.ticks_ms()
headers = {'Content-Type': 'application/json'}

while True:
    if time.ticks_ms() - last >= UPDATE_MS:
        try:
            t, h = dht22()
            show_oled(t, h)
            payload = {'field1': t, 'field2': h}
            url = 'http://api.thingspeak.com/update?api_key=' + THINGSPEAK_WRITE_API_KEY
            r = urequests.post(url, json=payload, headers=headers)
            r.close()
            print('Uploaded:', payload)
            led.value(not led.value())
        except OSError:
            print('Sensor error')
        last = time.ticks_ms()
    time.sleep(0.1)
