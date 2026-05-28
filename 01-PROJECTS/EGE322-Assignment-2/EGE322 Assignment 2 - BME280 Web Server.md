---
type: assignment
course: EGE322
module: EGE322-IOT-System-Project
status: draft
source: pdf
created: 2026-05-20
updated: 2026-05-26
due: 2026-05-25
tags: [EGE322, assignment, BME280, web-server, ESP32]
---

> **Related:** [[07-DASHBOARDS/NYPY3 - Main Index|NYPY3 Index]] | [[iot-assignment-2-2026b-1-slides|Ingested brief (2026b-1)]] | [[iot-assignment-2-2026b-slides|Prior ingest]] | [[EGE322 Lab Code Reference|Lab Code]] | [[07-DASHBOARDS/Schedule & Assessments Dashboard|Assessments]]

# EGE322 Assignment 2 — BME280 Web Server

**Due:** 25 May 2026 (Practical Lab Assignment 2 · 20% combined with Labs 4–5)  
**PDF:** [[99-ATTACHMENTS/EGE322/IOT Assignment 2 2026b-1.pdf|2026b-1]] · [[99-ATTACHMENTS/EGE322/IOT Assignment 2 2026b.pdf|2026b]]

---

## Status snapshot (26 May 2026)

| Part | Code in vault | Meets spec? | Submit-ready? |
|------|---------------|-------------|---------------|
| **1** | ⚠️ Library in vault; no `Part 1/` yet | — | ❌ Need `Part 1/main.py` + `BME280.py` (from [[99-ATTACHMENTS/EGE322/assignment-2/bme280 - Copy(1).py\|portal library]]) |
| **2** | ✅ `assignment-2/Task2/` | ✅ HTML table + 5 s refresh | ⚠️ Rename folder; screenshot + Word diff |
| **3** | ✅ `assignment-2/Task3/` | ✅ Two LEDs (GPIO 2 & 4), `led1`/`led2` URLs | ⚠️ Rename folder; screenshot + Word diff |
| **4** | ✅ `assignment-2/Task4/` | ✅ Combined sensor + dual LED UI | ⚠️ Rename folder; final screenshot |
| **Word doc** | 🟡 Draft started | — | ⚠️ Add screenshots; see [[01-PROJECTS/EGE322-Assignment-2/Assignment_2.docx\|Assignment_2.docx]] |
| **Zip** | ❌ Not started | — | ❌ `Assignment_2/` layout |

**Code paths**

| Part | Your work (submit from here) | Files |
|------|------------------------------|-------|
| 2 | `99-ATTACHMENTS/EGE322/assignment-2/Task2/` | `main.py`, `boot.py` |
| 3 | `99-ATTACHMENTS/EGE322/assignment-2/Task3/` | `main.py`, `boot.py` |
| 4 | `99-ATTACHMENTS/EGE322/assignment-2/Task4/` | `main.py`, `boot.py` |

### Folder layout — `99-ATTACHMENTS/EGE322/assignment-2/`

**Student portal downloads (reference only — do not submit as-is)**

| File | Role |
|------|------|
| [[99-ATTACHMENTS/EGE322/assignment-2/bme280_WebServer_1.py\|bme280_WebServer_1.py]] | Part 2 starter (`web_page()` with `<p>` tags) |
| [[99-ATTACHMENTS/EGE322/assignment-2/web_server_led_on-off.py\|web_server_led_on-off.py]] | Part 3 starter (single LED) |
| [[99-ATTACHMENTS/EGE322/assignment-2/boot_1.py\|boot_1.py]] | WiFi + I2C setup for Part 2 |
| [[99-ATTACHMENTS/EGE322/assignment-2/boot_2.py\|boot_2.py]] | WiFi + LED pin for Part 3 |
| [[99-ATTACHMENTS/EGE322/assignment-2/bme280 - Copy(1).py\|bme280 - Copy(1).py]] | **BME280 library** → rename to `BME280.py` for Part 1 submit |

Duplicates `*(1).py` are extra portal copies (Windows); safe to ignore — use the non-`(1)` files for diffs in Word.

**Your completed work (Task folders)**

| Folder | Based on portal file | What you changed |
|--------|---------------------|------------------|
| `Task2/` | `bme280_WebServer_1.py` + `boot_1.py` | HTML **table** + CSS |
| `Task3/` | `web_server_led_on-off.py` + `boot_2.py` | **Two** LEDs (GPIO 2 & 4) |
| `Task4/` | Task2 + Task3 merged | Combined dashboard UI |

References for Word doc diffs: compare **Task*** `main.py` **against** portal starters above, not against each other.


---

## What you still need to do

### A. Code / files (before zip)

- [ ] **Part 1 folder** — `Part 1/main.py` (serial loop from brief) + `Part 1/BME280.py` (copy/rename from portal [[99-ATTACHMENTS/EGE322/assignment-2/bme280 - Copy(1).py|bme280 library]])
- [ ] **Sanitize `boot.py`** for submission — replace real SSIDs/passwords with placeholders (`Your_SSID`) in the **zip copies** only; keep working creds locally if needed
- [ ] **Rename for marking** — grader expects `Part 1` … `Part 4`, not `Task2`/`Task3`/`Task4`
- [ ] **Quick re-test on board** — flash each part folder once; capture IP for screenshots

### B. Documentation (Word doc)

- [ ] **Part 2 screenshot** — browser showing sensor **table** (your Task2 page)
- [ ] **Part 2 highlighted code** — diff `Task2/main.py` vs portal [[99-ATTACHMENTS/EGE322/assignment-2/bme280_WebServer_1.py|bme280_WebServer_1.py]]
- [ ] **Part 3 screenshot** — both LED states visible; show ON/OFF working
- [ ] **Part 3 highlighted code** — diff `Task3/main.py` vs portal [[99-ATTACHMENTS/EGE322/assignment-2/web_server_led_on-off.py|web_server_led_on-off.py]]
- [ ] **Part 4 screenshot** — full combined dashboard (`Task4/main.py`)

### C. Packaging

- [ ] Folder layout:
  ```
  Assignment_2/
    Part 1/   main.py, BME280.py
    Part 2/   main.py, boot.py
    Part 3/   main.py, boot.py
    Part 4/   main.py, boot.py
    Assignment_2.docx   (or name per Brightspace)
  ```
- [ ] Zip → upload **Brightspace**

---

## Brief (from ingest)

1. BME280 I2C readings (Part 1 serial)
2. Web server — readings in HTML **table** (Part 2)
3. **Two** LED pairs — ON/OFF via web (Part 3)
4. Combined page (Part 4)

Wiring: BME280 Vin→3.3V, GND→GND, SCL→22, SDA→21. LEDs: any digital GPIO (you used **GPIO 2** and **GPIO 4**).

---

## Implementation notes (your code)

**Part 2** — `web_page()` uses styled `<table>` with temp/pressure/humidity; meta refresh 5 s; `BME280` properties as `.temperature` / `.pressure` / `.humidity`.

**Part 3** — `led1=Pin(2)`, `led2=Pin(4)`; URLs `/?led1=on|off`, `/?led2=on|off`; separate state display per LED.

**Part 4** — Merged sensor grid + LED controls; auto-refresh 5 s; improved CSS card layout.

<!-- gap: Part 1 main.py not saved in vault — portal library present as bme280 - Copy(1).py -->

---

## Tasks

- [ ] Part 1 — file `main.py` + `BME280.py` into `Part 1/`
- [x] Part 2 — web table for sensor data (`Task2/`)
- [x] Part 3 — two independent LED ON/OFF pairs (`Task3/`)
- [x] Part 4 — combined page (`Task4/`)
- [ ] Word doc with screenshots and highlighted code → [[01-PROJECTS/EGE322-Assignment-2/Assignment_2.docx|Assignment_2.docx]] (draft; paste screenshots)
- [ ] Zip `Assignment_2/` and submit to Brightspace

---

## Links

- [[EGE322 Lab 2- Controlling the ESP32 GPIOs v2026-1|Lab 2 — GPIO]]
- [[EGE322 Lab 3- Interacting with the ESP32 GPIOs v2026-1|Lab 3 — ADC/LDR]]
- [[ESP32_Programming_Guide|ESP32 Programming Guide]]
