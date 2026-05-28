---
type: assignment
course: EGE322
module: EGE322-IOT-System-Project
status: draft
source: pdf
created: 2026-05-26
tags: [EGE322, assignment, BME280, web-server, ESP32]
---

> **Project note:** [[01-PROJECTS/EGE322-Assignment-2/EGE322 Assignment 2 - BME280 Web Server|Assignment 2 — checklist + status]]
> **PDF:** [[99-ATTACHMENTS/EGE322/IOT Assignment 2 2026b-1.pdf|IOT Assignment 2 2026b-1.pdf]] · earlier copy: [[99-ATTACHMENTS/EGE322/IOT Assignment 2 2026b.pdf]]
> **Prior ingest:** [[iot-assignment-2-2026b-slides]] (same spec; kept for history)

# EGE322 Assignment 2 — BME280 Web Server (2026b-1)

> [!ingest] source: IOT Assignment 2 2026b-1.pdf | date: 2026-05-26 | tool: markitdown
> Auto-converted. Edit summary below; re-run ingest to replace block above.

## Summary

Same brief as [[iot-assignment-2-2026b-slides|2026b release]]: ESP32 + **BME280** (I2C) → MicroPython web server with live **temperature / humidity / pressure**, then **two independent LED ON/OFF button pairs**, then **one combined page**. Submit four part folders + **Word doc** (screenshots + highlighted code diffs) in zip `Assignment_2/` to Brightspace.

**Your code (vault):** Parts 2–4 in `99-ATTACHMENTS/EGE322/assignment-2/Task2|Task3|Task4/`. Part 1 folder + `BME280.py` not filed yet.

---

## Parts

| Part | Requirement | Submit |
|------|-------------|--------|
| **1** | Serial print temp/hum/pressure every 5 s | `main.py`, `BME280.py` |
| **2** | Web server; sensor in **HTML table** (not `<p>`) | `main.py`, `boot.py` |
| **3** | Two LEDs, each with ON/OFF buttons (`/?led…` URLs) | `main.py`, `boot.py` |
| **4** | Combine Part 2 + 3; UI polish optional | `main.py`, `boot.py` |

### Part 1 wiring (I2C)

| BME280 | ESP32 |
|--------|-------|
| Vin | 3.3 V |
| GND | GND |
| SCL | GPIO 22 |
| SDA | GPIO 21 |

Starter loop uses `import BME280` — library must be uploaded to the board as `BME280.py`.

### Part 2 change vs reference

Reference: [[99-ATTACHMENTS/EGE322/assignment-2/bme280_WebServer_1.py|bme280_WebServer_1.py]] + `boot.py` — replace `<p>` readings with an **HTML `<table>`**; keep 5 s meta refresh.

### Part 3 change vs reference

Reference: [[99-ATTACHMENTS/EGE322/assignment-2/web_server_led_on-off.py|web_server_led_on-off.py]] — extend single LED (`/?led=on|off`) to **two LEDs** on separate GPIO pins with separate button pairs.

---

## Submission (Brightspace)

1. **Folders:** `Part 1/` … `Part 4/` (files as above)
2. **Word doc:**
   - Part 2 screenshot + **highlighted** changes in `main.py` vs provided code
   - Part 3 screenshot + **highlighted** changes in `main.py` vs provided code
   - Part 4 final combined page screenshot
3. Zip everything as **`Assignment_2/`** → Brightspace

---

## Raw (archive)

<!-- gap: MarkItDown PDF dump collapsed — see PDF attachment for figures (Part 2 table mockup, Part 3 dual-LED layout) -->

Spec text matches [[iot-assignment-2-2026b-slides]]; no scope change detected in 2026b-1 PDF.
