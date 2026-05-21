from machine import Pin
from time import sleep
import dht

sensor = dht.DHT22(Pin(5))

while True:
    try:
        sensor.measure()
        print("Temperature = %.2f" % sensor.temperature())
        print("Humidity = %.2f" % sensor.humidity())
        sleep(3)

    except OSError:
        print("Failed to read sensor")
        sleep(3)