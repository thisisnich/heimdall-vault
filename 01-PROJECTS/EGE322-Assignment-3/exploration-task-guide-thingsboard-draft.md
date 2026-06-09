---
type: assignment
course: EGE322
module: EGE322-IOT-System-Project
status: draft
source: manual
created: 2026-06-04
due: 2026-06-08
tags: [EGE322, assignment-3, ThingsBoard, exploration, tutorial-draft]
---

> **Use:** Copy sections into Microsoft Word (Heading 1/2/3). Insert screenshots at each *[Figure N]*.  
> **Submit as:** Exploration Task Guide — ThingsBoard MQTT  
> **Screenshots:** [[partner-guide-screenshot-map]]  
> **Code on disk:** `99-ATTACHMENTS/EGE322/assignment-3/main.py` (copy to ESP32) · optional DHT: `main_thingsboard.py`

---

# COPY BELOW INTO WORD

---

## Title page

**Republic Polytechnic — School of Engineering**

**Module:** EGE322 IoT System Project  
**Assignment:** 3 — MQTT Cloud Dashboard (Jigsaw Learning)

**Document title:** Exploration Task Guide — ThingsBoard MQTT Telemetry Dashboard

**Author:** Nicholas Dubs  
**Date:** [DD Mon 2026]  
**Jigsaw role:** Student B (partner: [Student A name])

**Note to marker:** This submission uses **ThingsBoard** from the lecturer’s exploration platform list. Basic Task B (Adafruit IO) was covered in Lab 8; this guide documents independent exploration of a professional IoT dashboard with ESP32 MQTT uplink.

---

## 1. Introduction

### 1.1 Purpose

This guide teaches my jigsaw partner how to connect an **ESP32** to **ThingsBoard Cloud** using **MQTT**, publish **JSON telemetry**, and build a **live dashboard** (gauge + time-series chart). A reader with Thonny, an ESP32, and campus WiFi should complete the task without extra help.

### 1.2 Scope

| Included | Not included |
|----------|----------------|
| ThingsBoard account, device, access token | ThingSpeak (Student A basic task) |
| Dashboard widgets | Adafruit IO (Lab 8 — separate) |
| ESP32 `main.py` + WiFi in `boot.py` | Downlink / device control |
| PC-only MQTT test scripts | Custom sensors beyond assignment minimum |

The assignment allows **internally generated sample data** (no extra hardware). This guide uses a **counter** (0→100, step 10, every 2 s) plus **simulated** `temperature` and `humidity` in the same JSON payload for the chart widgets. If a DHT22 is already wired from Lab 7, see Appendix A.

### 1.3 Architecture

```
ESP32 (MicroPython)  --MQTT publish-->
  Broker: mqtt.thingsboard.cloud:1883
  Topic:  v1/devices/me/telemetry
  Auth:   username = device access token, password = empty
        --> ThingsBoard device telemetry
        --> Dashboard widgets (counter, temperature, humidity)
```

*[Figure 01 — ThingsBoard home with sidebar visible]*

---

## 2. ThingsBoard account and device

### 2.1 Create a cloud account

1. Open [https://thingsboard.cloud](https://thingsboard.cloud) and sign up (free tier).
2. Log in to the tenant dashboard.

### 2.2 Create a device

1. Go to **Entities → Devices**.
2. Click **+** (Add device).
3. Name: `ESP32-Counter` → **Add**.

*[Figure 02 — Devices list]*  
*[Figure 03 — Add device dialog with name filled]*

### 2.3 Copy the access token

1. Open the device `ESP32-Counter`.
2. Click **Copy access token**.
3. Store it locally — you will paste it into `main.py` as `ACCESS_TOKEN`.  
   **Do not share this token publicly** (treat it like a password).

*[Figure 04 — Access token on device page — REDACT token in this document]*

### 2.4 MQTT connection settings

| Setting | Value |
|---------|--------|
| Broker host | `mqtt.thingsboard.cloud` |
| Port | `1883` |
| Client ID | Any unique string (e.g. `esp32_thingsboard`) |
| Username | **Device access token** (from §2.3) |
| Password | *(leave empty)* |
| Publish topic | `v1/devices/me/telemetry` |
| Payload format | **JSON object** with double-quoted keys |

**Example payload:**

```json
{"counter": 10, "temperature": 24.5, "humidity": 55.0}
```

**Invalid example (will fail parsing):** `{temperature:24}` — keys must be quoted.

*[Figure 05 — Optional: device “Check connectivity” or this table as screenshot]*

---

## 3. Build the dashboard

### 3.1 Create a dashboard

1. **Dashboards → +** (Add dashboard).
2. Name: `EGE322 Assignment 3` → **Add**.

*[Figure 06 — New dashboard dialog]*

### 3.2 Add an analog gauge (counter)

1. Open the dashboard → **Edit**.
2. **Add widget** → **Analog gauge** (or similar gauge).
3. Data source: your device `ESP32-Counter`.
4. Telemetry key: **`counter`** (must match JSON field name exactly).
5. Save widget.

*[Figure 07 — Gauge configuration with data key `counter` highlighted]*

### 3.3 Add a time-series chart

1. **Add widget** → **Time series chart**.
2. Add series for keys: **`counter`**, **`temperature`**, **`humidity`**.
3. Set a short real-time window (e.g. last 5 minutes).
4. Save widget.

*[Figure 08 — Chart configuration showing all three keys]*

### 3.4 Layout and appearance

1. Arrange widgets on the grid.
2. Optional: **Settings → Theme** → dark theme for clearer screenshots.
3. **Save** dashboard.

*[Figure 09 — Finished dashboard layout]*

> **Important:** Widget telemetry keys must **exactly match** the field names in the JSON published by the ESP32. A typo (e.g. `counters` vs `counter`) produces an empty widget.

---

## 4. ESP32 setup and MicroPython code

### 4.1 Prerequisites

| Item | Notes |
|------|--------|
| Thonny | Connected to ESP32 |
| `boot.py` | WiFi SSID and password only — **do not duplicate WiFi in `main.py`** |
| Library | `umqtt.robust` on the board |
| Reboot | After editing files use **Ctrl+D** (soft reboot) so `boot.py` runs before `main.py` |

### 4.2 Install code on the ESP32

1. Open Thonny → ESP32 files.
2. Confirm **`boot.py`** connects WiFi on boot.
3. Copy **`99-ATTACHMENTS/EGE322/assignment-3/main.py`** to the ESP32 as **`main.py`** (or paste from §4.4).
4. Replace `PASTE_DEVICE_ACCESS_TOKEN_HERE` with your token (keep the `b"..."` bytes form).
5. **Save to ESP32** → soft reboot **Ctrl+D**.

*[Figure 10 — Thonny showing main.py with token REDACTED]*

### 4.3 Run and verify

Expected shell output:

```
WiFi OK: 192.168.x.x
ThingsBoard MQTT connected
Published: {"counter": 0, "temperature": 24.0, "humidity": 50.0}
...
```

*[Figure 11 — Thonny shell with connected + Published lines]*

On ThingsBoard:

1. **Entities → Devices → ESP32-Counter → Latest telemetry**  
2. Confirm keys `counter`, `temperature`, `humidity` update.

*[Figure 12 — Latest telemetry tab]*

### 4.4 Full MicroPython listing (assignment — internal sample data)

No external sensor required. Counter matches Basic Task A pattern; temperature and humidity are **simulated** for chart widgets.

```python
# EGE322 Assignment 3 — ESP32 → ThingsBoard MQTT (Exploration)
# Save as main.py on ESP32. WiFi only in boot.py.
# Reboot with Ctrl+D after save (do not rely on F5 Run alone).

import json
import time
import network
from umqtt.robust import MQTTClient

# --- ThingsBoard: paste your device access token ---
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

    # Simulated extras for chart widgets (no DHT22 required)
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
```

**Code notes for troubleshooting:**

| Line / idea | Why it matters |
|-------------|----------------|
| `user=ACCESS_TOKEN` | ThingsBoard uses the token as MQTT username |
| `password=b""` | Password must be empty for device token auth |
| `json.dumps(...)` | Builds valid JSON; required for multi-key telemetry |
| `qos=1` | At-least-once delivery; reliable telemetry |
| `wait_for_wifi()` | Avoids MQTT connect before `boot.py` finishes |
| Counter 0→100 step 10 | Same pattern as ThingSpeak assignment sample |

---

## 5. Results

With `main.py` running, the dashboard should show:

- **Gauge:** `counter` stepping 0, 10, 20, … 100, then resetting.
- **Chart:** three series updating every ~2 seconds.

*[Figure 13 — LIVE dashboard — HERO SCREENSHOT for submission]*

**Figure 13 caption:** ThingsBoard dashboard `EGE322 Assignment 3` receiving live MQTT telemetry from ESP32 device `ESP32-Counter`.

---

## 6. Troubleshooting

| Problem | Likely cause | Fix |
|---------|--------------|-----|
| Dashboard widgets empty | Wrong telemetry key | Set widget key to `counter` exactly |
| `MQTT connect failed` | Bad or expired token | Re-copy from device page |
| `WiFi not connected` | `boot.py` wrong / not run | Fix SSID/password; **Ctrl+D** reboot |
| `OSError -202` after Run (F5) | `boot.py` skipped | Use **Ctrl+D** not F5 on `main.py` only |
| Chart flat, gauge works | Chart keys mismatch | Add `temperature`, `humidity` to JSON |
| Invalid JSON error | Manual string concat | Use `json.dumps()` |

*[Figure 14 — Optional: widget with wrong key (empty) vs correct key]*

---

## 7. Limitations

1. **ThingsBoard free tier** — limits on devices, messages, and retention; fine for coursework but not high-frequency production.
2. **Network** — ESP32 needs **2.4 GHz** WiFi; guest networks may block MQTT port 1883.
3. **Security** — Access token grants full device access; redact in screenshots and do not commit to public Git.
4. **Latency** — Cloud round-trip typically 1–5 s; not hard real-time control.
5. **Scope** — This guide covers **uplink telemetry** only, not ThingsBoard rule chains or alarms.
6. **Platform choice** — Adafruit IO (Lab 8) uses per-feed topics; ThingsBoard uses one JSON telemetry topic — different mental model.

---

## 8. What I learned

ThingsBoard treats each ESP32 as a **device** with an **access token** used as the MQTT username. Telemetry is one **JSON object** per publish on `v1/devices/me/telemetry`, and dashboard widgets bind to **keys** inside that object. Compared to ThingSpeak MQTT (`field1=value` strings) and Adafruit IO (`username/feeds/name` per value), ThingsBoard feels closer to industry IoT platforms. Teaching this flow reinforced that **documentation and screenshots** matter as much as working code for peer learning.

---

## Appendix A — Optional: real DHT22 (Lab 7 wiring)

If you already wired **DHT22 DATA → GPIO 15** from Lab 7, use `main_thingsboard.py` on the ESP32 instead of `main.py`. It publishes real `temperature` and `humidity` with the same `counter` pattern. Widget setup in §3 is unchanged.

---

## Appendix B — Screenshot checklist (14 figures — no PC test)

| Fig | Filename | Section |
|-----|----------|---------|
| 01 | `01-thingsboard-home.png` | §1 |
| 02 | `02-devices-list.png` | §2 |
| 03 | `03-device-create.png` | §2 |
| 04 | `04-access-token.png` | §2 |
| 05 | `05-mqtt-settings-table.png` | §2 (optional) |
| 06 | `06-dashboard-new.png` | §3 |
| 07 | `07-widget-gauge-config.png` | §3 |
| 08 | `08-widget-chart-config.png` | §3 |
| 09 | `09-dashboard-layout.png` | §3 |
| 10 | `10-thonny-main-py.png` | §4 |
| 11 | `11-thonny-shell-connected.png` | §4 |
| 12 | `12-latest-telemetry.png` | §4 |
| 13 | `13-dashboard-live.png` | §5 **required** |
| 14 | `14-troubleshooting.png` | §6 (optional) |

**Capture order:** ThingsBoard setup (01–09) → flash ESP32 (10–12) → open dashboard for live shot (13).

---

## Submission reminder

- [ ] Word `.docx` uploaded to Brightspace  
- [ ] Title states **Exploration Task Guide — ThingsBoard**  
- [ ] Peer evaluation form completed  
- [ ] All tokens redacted in figures  

---

# END OF WORD DRAFT
