try:
    import usocket as socket
except:
    import socket

from machine import Pin, I2C
import network
import esp
import gc
import time

esp.osdebug(None)
gc.collect()

ssid = 'NickPhone'
password = 'DimHPpw!123'

# Reset WiFi radio cleanly
station = network.WLAN(network.STA_IF)
station.active(False)
time.sleep(1)
station.active(True)
time.sleep(1)

# Connect
station.connect(ssid, password)
print('Connecting to WiFi...')

timeout = 15
while not station.isconnected() and timeout > 0:
    time.sleep(1)
    timeout -= 1
    print('Waiting... (' + str(timeout) + 's left)')

if station.isconnected():
    print('Connection successful!')
    print('IP:', station.ifconfig()[0])
else:
    print('Failed to connect. Rebooting...')
    time.sleep(2)
    import machine
    machine.reset()

i2c = I2C(scl=Pin(22), sda=Pin(21), freq=10000)