---
type: lab
course: EGE322
module: EGE322-IOT-System-Project
status: draft
source: pdf
created: 2026-05-28
tags: [EGE322, lab, ESP32, ThingSpeak, DHT22, REST-API, urequests]
---

> **Related:** [[ege322-labs-6-8-walkthrough-guide|Labs 6–8 Walkthrough Guide]] | [[07-DASHBOARDS/NYPY3 - Main Index|NYPY3 Index]] | [[ege322-lab-6-introduction-to-thingspeak-slides|Lab 6 ThingSpeak Intro]] | [[ege322-lab-8-mqtt-adafruit-io-slides|Lab 8 Adafruit MQTT]] | [[ESP32_Programming_Guide|ESP32 Guide]]

# EGE322 Lab 7 — ESP32 ThingSpeak (REST API)

> [!ingest] source: EGE322 Lab 7 - Connecting the ESP32 to the Internet Using ThingSpeak v2026b.pdf | date: 2026-05-28 | tool: markitdown
> Auto-converted. Edit summary below; re-run ingest to replace block above.

## Summary

Connect **ESP32** to **ThingSpeak** using **REST API** (`urequests.post`). Read DHT22 temperature/humidity, display on OLED, and publish to ThingSpeak fields every 5 s. Covers WiFi setup via `wifi_credentials.py`, channel/API key configuration, and reflection questions on `sensor.measure()`, JSON headers, and field mapping.

**PDF:** `99-ATTACHMENTS/EGE322/EGE322 Lab 7 - Connecting the ESP32 to the Internet Using ThingSpeak v2026b.pdf`

---

## Objectives

- Set up IoT platform (ThingSpeak)
- Connect ESP32 to OLED and DHT22
- Send sensor data to cloud via REST API

---

## Material

| Item | Qty |
|------|-----|
| Windows 10 PC + USB + Internet | 1 |
| ESP32 NodeMCU | 1 |
| USB 2.0 mini-USB cable | 1 |
| DHT22 sensor | 1 |
| 0.96" OLED (24×24 mm) | 1 |

---

## Wiring

| DHT22 | ESP32 | OLED | ESP32 |
|-------|-------|------|-------|
| Pin 1 (VDD) | 3.3V | GND | GND |
| Pin 2 (DATA) | GPIO 15 | VDD | 3.3V |
| Pin 3 (NC) | — | SCK | GPIO 22 |
| Pin 4 (GND) | GND | SDA | GPIO 21 |

---

## ThingSpeak setup

1. Register/login at [thingspeak.com](https://thingspeak.com/)
2. **New Channel** → name fields (e.g. Field 1 = Temperature, Field 2 = Humidity)
3. **Save Channel** → note **Channel ID** and **Write API Key** (keep secret)
4. Data can be published via REST API or MQTT (`mqtt.thingspeak.com`)

---

## WiFi credentials

`wifi_credentials.py`:

```python
SSID = 'Your WiFi Network SSID'
Password = 'Your WiFi Network Password'
```

---

## DHT22 + OLED (baseline)

```python
from machine import Pin, I2C
from ssd1306 import SSD1306_I2C
from time import sleep
import dht

sensor = dht.DHT22(Pin(15))
i2c = I2C(scl=Pin(22), sda=Pin(21))
oled = SSD1306_I2C(128, 64, i2c, 0x3c)

while True:
    try:
        sensor.measure()
        oled.fill(0)
        oled.text('Temp: %.2f' % sensor.temperature(), 0, 0)
        oled.text('Humid: %.2f' % sensor.humidity(), 0, 10)
        oled.show()
        sleep(3)
    except OSError:
        print('Failed to read sensor!')
```

---

## ThingSpeak POST (core loop)

```python
import network, wifi_credentials, urequests, dht, time
from machine import Pin

led = Pin(2, Pin.OUT)
sensor = dht.DHT22(Pin(15))

sta = network.WLAN(network.STA_IF)
sta.active(True)
sta.connect(wifi_credentials.SSID, wifi_credentials.Password)
while not sta.isconnected():
    pass

HTTP_HEADERS = {'Content-Type': 'application/json'}
THINGSPEAK_WRITE_API_KEY = 'YOUR_KEY_HERE'
UPDATE_TIME_INTERVAL = 5000  # ms
last_update = time.ticks_ms()

while True:
    if time.ticks_ms() - last_update >= UPDATE_TIME_INTERVAL:
        sensor.measure()
        t = sensor.temperature()
        h = sensor.humidity()
        dht_readings = {'field1': t, 'field2': h}
        request = urequests.post(
            'http://api.thingspeak.com/update?api_key=' + THINGSPEAK_WRITE_API_KEY,
            json=dht_readings, headers=HTTP_HEADERS)
        request.close()
        print(dht_readings)
        led.toggle()
        last_update = time.ticks_ms()
```

---

## Exercises

1. Add OLED display to the ThingSpeak REST API script
2. Wrap DHT22 reading in a `dht22()` function
3. Fix any OLED display errors observed during runtime

---

## Reflection questions

1. Why must `sensor.measure()` be called before `temperature()` / `humidity()`?
2. Why is `Content-Type: application/json` required in the POST header?
3. How does ThingSpeak know field1 = temp and field2 = humidity?
4. What does `urequests.post()` do?
5. Why call `request.close()`?

---

## Figures

![[99-ATTACHMENTS/EGE322/ege322-lab-7-esp32-thingspeak/ege322-lab-7-esp32-thingspeak-p01.png|Lab 7 cover]]
![[99-ATTACHMENTS/EGE322/ege322-lab-7-esp32-thingspeak/ege322-lab-7-esp32-thingspeak-p02.png|What is ThingSpeak]]
![[99-ATTACHMENTS/EGE322/ege322-lab-7-esp32-thingspeak/ege322-lab-7-esp32-thingspeak-p03.png|Registration]]
![[99-ATTACHMENTS/EGE322/ege322-lab-7-esp32-thingspeak/ege322-lab-7-esp32-thingspeak-p04.png|New channel]]
![[99-ATTACHMENTS/EGE322/ege322-lab-7-esp32-thingspeak/ege322-lab-7-esp32-thingspeak-p05.png|Channel tabs]]
![[99-ATTACHMENTS/EGE322/ege322-lab-7-esp32-thingspeak/ege322-lab-7-esp32-thingspeak-p06.png|API keys]]
