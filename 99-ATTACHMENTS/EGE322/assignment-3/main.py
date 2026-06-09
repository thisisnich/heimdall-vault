# EGE322 Assignment 3 — ESP32 → ThingsBoard MQTT (Exploration)
# Copy this file to the ESP32 as main.py. WiFi only in boot.py.
# Soft reboot with Ctrl+D after save (do not rely on F5 Run alone).
#
# Simulated counter + temperature + humidity (no external sensor).
# DHT22 version: see main_thingsboard.py

import json
import time
import network
from umqtt.robust import MQTTClient

# Paste from ThingsBoard → Device → Copy access token
ACCESS_TOKEN = b"PASTE_DEVICE_ACCESS_TOKEN_HERE"

BROKER = "mqtt.thingsboard.cloud"
PORT = 1883
TOPIC = b"v1/devices/me/telemetry"
PUBLISH_EVERY_S = 2

counter = 0


def wait_for_wifi(timeout_s=20):
    """boot.py should connect WiFi; wait if main.py starts early."""
    wlan = network.WLAN(network.STA_IF)
    if not wlan.active():
        wlan.active(True)
    if wlan.isconnected():
        return
    while timeout_s > 0 and not wlan.isconnected():
        time.sleep(1)
        timeout_s -= 1
    if not wlan.isconnected():
        raise OSError("WiFi not connected — fix boot.py, then Ctrl+D")


def connect_mqtt():
    client = MQTTClient(
        client_id=b"esp32_thingsboard",
        server=BROKER,
        port=PORT,
        user=ACCESS_TOKEN,
        password=b"",
        keepalive=60,
        ssl=False,
    )
    client.connect()
    print("ThingsBoard MQTT connected")
    return client


wait_for_wifi()
client = connect_mqtt()

while True:
    if counter > 100:
        counter = 0

    # Simulated values for chart widgets (no DHT22 required)
    temperature = 20.0 + (counter % 50) * 0.2
    humidity = 40.0 + (counter % 30)

    payload = json.dumps({
        "counter": counter,
        "temperature": round(temperature, 1),
        "humidity": round(humidity, 1),
    })
    client.publish(TOPIC, payload, qos=1)
    print("Published:", payload)

    counter += 10
    time.sleep(PUBLISH_EVERY_S)
