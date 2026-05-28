---
type: lab
course: EGE322
module: EGE322-IOT-System-Project
status: draft
source: pdf
created: 2026-05-28
tags: [EGE322, lab, ESP32, MQTT, Adafruit-IO, DHT22]
---

> **Related:** [[ege322-labs-6-8-walkthrough-guide|Labs 6–8 Walkthrough Guide]] | [[07-DASHBOARDS/NYPY3 - Main Index|NYPY3 Index]] | [[05-KB/concepts/MQTT|MQTT concept]] | [[iot-data-collection-mqtt-rest-api-cloud-services-slides|MQTT & REST Lecture]] | [[ege322-lab-7-esp32-thingspeak-slides|Lab 7 ThingSpeak]]

# EGE322 Lab 8 — MQTT with Adafruit IO

> [!ingest] source: EGE322 Lab 8 - IoT Dashboard using MQTT with Adafruit IO v2026.pdf | date: 2026-05-28 | tool: markitdown
> Auto-converted. Edit summary below; re-run ingest to replace block above.

## Summary

Build an **Adafruit IO** dashboard and connect **ESP32** via **MQTT** (`umqtt.robust`). **Uplink:** publish DHT22 temp/humidity to feeds every 10 s. **Downlink:** subscribe to a `light` feed; callback toggles GPIO LED from dashboard switch. Uses `credential.py` for WiFi and Adafruit IO key.

**PDF:** `99-ATTACHMENTS/EGE322/EGE322 Lab 8 - IoT Dashboard using MQTT with Adafruit IO v2026.pdf`

---

## Introduction

Adafruit IO is a cloud IoT platform supporting **MQTT** and **REST API**. Free tier has limits on dashboards, feeds, and data rates.

| Direction | Flow |
|-----------|------|
| Uplink | ESP32 → Cloud (publish sensor data) |
| Downlink | Cloud → ESP32 (subscribe, e.g. LED control) |

---

## Adafruit IO setup

1. Sign in at [io.adafruit.com](https://io.adafruit.com)
2. **+ Dashboard** → create dashboard
3. **Create New Block** → add **Gauge** widgets for `temp` and `hum` feeds
4. Add **Switch** block for `light` feed (values 1/0 = ON/OFF)
5. Save layout

![[99-ATTACHMENTS/EGE322/ege322-lab-8-mqtt-adafruit-io/ege322-lab-8-mqtt-adafruit-io-p04.png|Dashboard with temp, hum, light switch]]

---

## credential.py

```python
ssid = 'Your Wifi Router SSID'
password = 'Your Wifi Router Password'
adafruit_username = b'Your Adafruit UserID'
adafruit_IO_key = b'Your Adafruit IO Key'  # from MY KEY on io.adafruit.com
```

---

## MicroPython script (key parts)

**Hardware:** DHT22 on GPIO 16, LED on GPIO 4

**MQTT subscribe callback:**

```python
def cb(topic, msg):
    message = msg.decode('utf-8').strip().lower()
    if message in ['1', 'on', 'true']:
        led.value(1)
    else:
        led.value(0)
```

**Feed names** (must match dashboard):

```python
temp_feed = bytes('{:s}/feeds/{:s}'.format(ADAFRUIT_USERNAME, b'temp'), 'utf-8')
hum_feed  = bytes('{:s}/feeds/{:s}'.format(ADAFRUIT_USERNAME, b'hum'),  'utf-8')
mqtt_feed = bytes('{:s}/feeds/{:s}'.format(ADAFRUIT_USERNAME, b'light'), 'utf-8')

client.set_callback(cb)
client.subscribe(mqtt_feed)
```

**Main loop:**
- Every **10 s**: `sensor.measure()` → publish temp/hum
- Every **0.5 s**: `client.check_msg()` for downlink commands

---

## Reflection questions

1. Which code sections handle MQTT publish vs subscribe?
2. Purpose of `cb(topic, msg)`?
3. How does the incoming message control the LED?
4. Why must feed names match the dashboard?
5. Why use `credential.py`?
6. Why publish every 10 s instead of continuously?
7. Why must `client.check_msg()` run in the main loop?

---

## Figures

![[99-ATTACHMENTS/EGE322/ege322-lab-8-mqtt-adafruit-io/ege322-lab-8-mqtt-adafruit-io-p01.png|Lab 8 cover]]
![[99-ATTACHMENTS/EGE322/ege322-lab-8-mqtt-adafruit-io/ege322-lab-8-mqtt-adafruit-io-p02.png|Adafruit account]]
![[99-ATTACHMENTS/EGE322/ege322-lab-8-mqtt-adafruit-io/ege322-lab-8-mqtt-adafruit-io-p03.png|Create gauge block]]
![[99-ATTACHMENTS/EGE322/ege322-lab-8-mqtt-adafruit-io/ege322-lab-8-mqtt-adafruit-io-p05.png|Switch widget]]
![[99-ATTACHMENTS/EGE322/ege322-lab-8-mqtt-adafruit-io/ege322-lab-8-mqtt-adafruit-io-p09.png|MY KEY location]]
![[99-ATTACHMENTS/EGE322/ege322-lab-8-mqtt-adafruit-io/ege322-lab-8-mqtt-adafruit-io-p10.png|Thonny + dashboard result]]
