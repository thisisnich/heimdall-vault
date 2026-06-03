from machine import Pin
import time
import os
import dht
from umqtt.robust import MQTTClient

# --- Adafruit config (WiFi is in boot.py) ---
ADAFRUIT_USERNAME = b'PASTE_ADAFRUIT_USERNAME'
ADAFRUIT_IO_KEY = b'PASTE_ADAFRUIT_IO_KEY'

# --- hardware (Lab 8 pins) ---
sensor = dht.DHT22(Pin(16))
led = Pin(4, Pin.OUT)

PUBLISH_EVERY_S = 10
CHECK_EVERY_S = 0.5


def cb(topic, msg):
    """Downlink — dashboard switch → LED."""
    print('Subscribe:', topic, msg)
    try:
        message = msg.decode('utf-8').strip().lower()
        if message in ('1', 'on', 'true'):
            led.value(1)
        else:
            led.value(0)
    except Exception as e:
        print('Callback error:', e)


def connect_mqtt():
    client_id = b'esp32_' + bytes(str(int.from_bytes(os.urandom(3), 'little')), 'utf-8')
    client = MQTTClient(
        client_id=client_id,
        server=b'io.adafruit.com',
        user=ADAFRUIT_USERNAME,
        password=ADAFRUIT_IO_KEY,
        ssl=False,
    )
    client.connect()
    client.set_callback(cb)

    temp_feed = b'%s/feeds/temp' % ADAFRUIT_USERNAME
    hum_feed = b'%s/feeds/hum' % ADAFRUIT_USERNAME
    light_feed = b'%s/feeds/light' % ADAFRUIT_USERNAME

    client.subscribe(light_feed)  # downlink
    return client, temp_feed, hum_feed


client, temp_feed, hum_feed = connect_mqtt()
accum = 0.0

while True:
    try:
        if accum >= PUBLISH_EVERY_S:
            sensor.measure()
            t = sensor.temperature()
            h = sensor.humidity()
            client.publish(temp_feed, bytes(str(t), 'utf-8'), qos=0)
            client.publish(hum_feed, bytes(str(h), 'utf-8'), qos=0)
            print('Published T=%s H=%s' % (t, h))
            accum = 0.0

        client.check_msg()  # must run often for downlink
        time.sleep(CHECK_EVERY_S)
        accum += CHECK_EVERY_S

    except KeyboardInterrupt:
        client.disconnect()
        break