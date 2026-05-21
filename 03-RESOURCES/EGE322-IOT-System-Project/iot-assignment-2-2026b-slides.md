---
type: assignment
course: EGE322
module: EGE322-IOT-System-Project
status: draft
source: pdf
created: 2026-05-20
tags: [EGE322, assignment, BME280, web-server, ESP32]
---

> **Project note:** [[01-PROJECTS/EGE322-Assignment-2/EGE322 Assignment 2 - BME280 Web Server|Assignment 2 — working note + checklist]]
> **PDF:** [[99-ATTACHMENTS/EGE322/IOT Assignment 2 2026b.pdf]]
> **Reference scripts:** [[99-ATTACHMENTS/EGE322/assignment-2/bme280_WebServer_1.py|Part 2]] · [[99-ATTACHMENTS/EGE322/assignment-2/web_server_led_on-off.py|Part 3]]

# EGE322 Assignment 2 — BME280 Web Server

> [!ingest] source: IOT Assignment 2 2026b.pdf | date: 2026-05-20 | tool: markitdown
> Auto-converted. Edit summary below; re-run ingest to replace block above.

## Summary

ESP32 + **BME280** environmental sensor over **I2C**. Build a **MicroPython web server** (HTML/CSS/JS) showing temperature, humidity, and pressure; add **two independent LED ON/OFF button pairs** on the web page; combine into one page (Part 4). Submit zipped folders + Word doc to Brightspace.

---

## Parts Overview

| Part | Task | Key files |
|------|------|-----------|
| **1** | BME280 serial readings | `main.py`, `BME280.py` |
| **2** | Web server — sensor in HTML **table** | `main.py`, `boot.py` |
| **3** | Two LED pairs — ON/OFF web buttons | `main.py`, `boot.py` |
| **4** | Combine Part 2 + 3; improve UI optional | `main.py`, `boot.py` |

---

## Part 1 — BME280 Wiring (I2C)

| BME280 | ESP32 |
|--------|-------|
| Vin | 3.3 V |
| GND | GND |
| SCL | GPIO 22 |
| SDA | GPIO 21 |

Upload `BME280.py` to ESP32 (not bundled with MicroPython).

```python
from machine import Pin, I2C
from time import sleep
import BME280

i2c = I2C(scl=Pin(22), sda=Pin(21), freq=10000)

while True:
    bme = BME280.BME280(i2c=i2c)
    print('Temperature: ', bme.temperature())
    print('Humidity: ', bme.humidity())
    print('Pressure: ', bme.pressure())
    sleep(5)
```

---

## Part 2 — Sensor Web Server

Base reference: `bme280_WebServer_1.py` + `boot_1.py`

- Modify `web_page()` to show readings in an **HTML table** (not plain `<p>` tags)
- Server on port 80; meta refresh ~5 s for live updates
- WiFi credentials in `boot.py`

---

## Part 3 — LED Web Control

Base reference: `web_server_led_on-off.py` + `boot_2.py`

- URL query control: `/?led=on` and `/?led=off`
- **Extend to two LEDs** on separate GPIO pins
- Each LED: own ON/OFF button pair on the page

---

## Part 4 — Combined Page

Merge sensor table (Part 2) + dual LED controls (Part 3) on one web page. CSS/layout improvements optional.

---

## Submission

1. Folders: `Part 1/` … `Part 4/` (main + boot/library as specified)
2. Word doc: Part 2 & 3 screenshots + **highlighted code changes**; Part 4 final screenshot
3. Zip as `Assignment_2/` → **Brightspace**

See [[01-PROJECTS/EGE322-Assignment-2/EGE322 Assignment 2 - BME280 Web Server|project note]] for task checklist.
