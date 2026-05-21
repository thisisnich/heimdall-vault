---
type: assignment
course: EGE322
module: EGE322-IOT-System-Project
status: draft
source: pdf
created: 2026-05-20
due: 2026-05-25
tags: [EGE322, assignment, BME280, web-server, ESP32]
---

> **Related:** [[NYPY3 - Main Index|NYPY3 Index]] | [[iot-assignment-2-2026b-slides|Ingested PDF]] | [[EGE322 Lab Code Reference|Lab Code]] | [[Schedule & Assessments Dashboard|Assessments]]

# EGE322 Assignment 2 — BME280 Web Server

**Source:** [[99-ATTACHMENTS/EGE322/IOT Assignment 2 2026b.pdf|PDF]] · Ingest: [[iot-assignment-2-2026b-slides]]

## Brief

Set up ESP32 with **BME280** (I2C) and build a **MicroPython web server** that:

1. Displays temperature, humidity, and pressure readings
2. Shows readings in an HTML table (Part 2)
3. Controls **two LEDs** via ON/OFF buttons on the web page (Part 3)
4. Combines sensor display + LED control on one page (Part 4)

Reference scripts provided for BME280 web server and LED web buttons.

**Reference files:** `99-ATTACHMENTS/EGE322/assignment-2/`
- [[99-ATTACHMENTS/EGE322/assignment-2/bme280_WebServer_1.py|bme280_WebServer_1.py]] — Part 2 base (sensor web page)
- [[99-ATTACHMENTS/EGE322/assignment-2/web_server_led_on-off.py|web_server_led_on-off.py]] — Part 3 base (LED ON/OFF buttons)

## Parts

| Part | Task | Files |
|------|------|-------|
| **1** | BME280 sensor readings to serial | `main.py`, `BME280.py` |
| **2** | Web server — sensor readings in HTML table | `main.py`, `boot.py` |
| **3** | Two LED pairs — ON/OFF via web buttons | `main.py`, `boot.py` |
| **4** | Combine Part 2 + Part 3 on one page | `main.py`, `boot.py` |

### Part 1 Wiring (BME280 I2C)

| BME280 | ESP32 |
|--------|-------|
| Vin | 3.3V |
| GND | GND |
| SCL | GPIO 22 |
| SDA | GPIO 21 |

Upload `BME280.py` library to ESP32 (not included in MicroPython by default).

### Part 2–4 Notes

- WiFi credentials in `boot.py` (`ssid`, `password`)
- Web server on port 80; auto-refresh every 5s for sensor page
- LED control via URL query: `/?led=on` and `/?led=off` (extend for second LED in Part 3)
- Improve CSS/layout optional for Part 4

## Submission

1. Folder structure:
   - `Part 1/` — main + library
   - `Part 2/` — main + boot
   - `Part 3/` — main + boot
   - `Part 4/` — main + boot
2. Word doc with:
   - Part 2 screenshot + highlighted changes in `main.py`
   - Part 3 screenshot + highlighted changes in `main.py`
   - Part 4 final combined page screenshot
3. Zip as `Assignment_2/` → submit to **Brightspace**

## Tasks

- [ ] Part 1 — BME280 serial readings working
- [ ] Part 2 — web table for sensor data
- [ ] Part 3 — two independent LED ON/OFF button pairs
- [ ] Part 4 — combined page
- [ ] Word doc with screenshots and highlighted code
- [ ] Zip and submit to Brightspace

## Links

- [[EGE322 Lab 2- Controlling the ESP32 GPIOs v2026-1|Lab 2 — GPIO]]
- [[EGE322 Lab 3- Interacting with the ESP32 GPIOs v2026-1|Lab 3 — ADC/LDR]]
- [[ESP32_Programming_Guide|ESP32 Programming Guide]]
