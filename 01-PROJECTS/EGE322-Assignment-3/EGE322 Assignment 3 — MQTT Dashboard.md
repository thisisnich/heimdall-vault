---
type: assignment
course: EGE322
module: EGE322-IOT-System-Project
status: draft
source: manual
created: 2026-06-02
due: 2026-06-08
tags: [EGE322, assignment-3, MQTT, dashboard, ThingsBoard, Node-RED]
---

> **Related:** [[03-RESOURCES/EGE322-IOT-System-Project/ege322-assignment-3-iot-dashboard-2026b-slides|Assignment brief]] | [[03-RESOURCES/EGE322-IOT-System-Project/select-an-iot-dashboard-photo|Dashboard chart]] | [[ege322-labs-6-8-walkthrough-guide|Labs 6–8]] | [[07-DASHBOARDS/Schedule & Assessments Dashboard|Due dates]]

# EGE322 Assignment 3 — MQTT Dashboard

**Due:** 8 Jun 2026 · **Weight:** part of 20% (with Practical Lab Assignment 3)

---

## Platform choice — **ThingsBoard** (primary)

**Criteria:** most visually professional + most IoT learning value.

| Platform | Visual polish | Learning depth | Verdict |
|----------|---------------|------------------|---------|
| **ThingsBoard** | ★★★★★ enterprise dashboards | ★★★★★ device model, telemetry, MQTT, widgets, rules | **Pick** |
| TagoIO | ★★★★★ | ★★★ less ESP32/MQTT tutorial material | Runner-up visuals only |
| Node-RED Dashboard | ★★★ dated default UI | ★★★★★ flow/pipeline thinking | **Exploration add-on** |
| Firebase + React | ★★★★★ if you build it | ★★★ web dev > IoT platform | Custom UI path |
| Adafruit / Blynk / Ubidots | ★★★ maker/mobile | ★★ beginner-friendly | Fast but not “pro” |
| ThingSpeak | ★★ basic charts | ★★★ debug exercise | Partner / compare only |
| Home Assistant | ★★★★ (if themed) | ★★ wrong tool for counter lab | Skip |

**Why ThingsBoard wins both goals:**
- Dashboards look like **real industry IoT** (gauges, time-series charts, dark theme, layout grid) — strong Brightspace screenshots
- You learn **device provisioning**, **access tokens**, **MQTT telemetry JSON**, **dashboard widgets**, optional **rule chains** — not just “push a number to a feed”
- Free cloud: [thingsboard.cloud](https://thingsboard.cloud)
- Pure **MQTT** from ESP32 (same protocol as Labs 6–8, deeper than REST ThingSpeak)

**Optional exploration (bonus):** **Node-RED** — different learning axis (event flows, local broker). Compare *cloud platform vs flow tool* in Word doc. Not chosen for visuals.

---

## Architecture

```
ESP32 (counter) --MQTT TLS/TCP--> mqtt.thingsboard.cloud
                                        |
                                   Device telemetry
                                        |
                              ThingsBoard dashboard (browser)
```

---

## Code & testing

**Folder:** `99-ATTACHMENTS/EGE322/assignment-3/`

| File | Use |
|------|-----|
| [[99-ATTACHMENTS/EGE322/assignment-3/thingsboard_test_sender.py\|thingsboard_test_sender.py]] | **PC** — stream custom JSON to dashboard (no ESP32) |
| [[99-ATTACHMENTS/EGE322/assignment-3/main_thingsboard.py\|main_thingsboard.py]] | **ESP32** → copy to `main.py` on board |
| [[99-ATTACHMENTS/EGE322/assignment-3/README.md\|README]] | Commands + widget key reference |

### Test dashboard on PC first

```bash
cd 99-ATTACHMENTS/EGE322/assignment-3
copy config.example.py config.py   # paste ThingsBoard access token
pip install paho-mqtt
python thingsboard_test_sender.py --mode rich
```

| Mode | What it sends |
|------|----------------|
| `--mode rich` | counter + temperature + humidity (layout testing) |
| `--mode demo` | assignment counter 0→100 |
| `--once '{"counter": 75}'` | one-off custom value |
| `--interactive` | type JSON each line |

Open ThingsBoard dashboard in browser while script runs — tweak widgets until it looks pro, then flash ESP32.

---

## ThingsBoard setup

### 1. Account & device

1. Sign up at [thingsboard.cloud](https://thingsboard.cloud)
2. **Entities → Devices → +** → name `ESP32-Counter`
3. Open device → **Copy access token** (MQTT password)

### 2. Dashboard (make it look pro)

1. **Dashboards → +** → `EGE322 Assignment 3`
2. Add widgets (keys must match JSON from test sender):

| Widget | Telemetry key |
|--------|---------------|
| Analog gauge | `counter` |
| Timeseries chart | `counter`, `temperature`, `humidity` |
| LED / digital | `status` (optional, `--mode rich`) |
3. **Settings → Layout** — dark theme, full-width, align grid
4. **Make dashboard public** (or screenshot from logged-in view) for submission

### 3. ESP32 `main.py`

Use [[99-ATTACHMENTS/EGE322/assignment-3/main_thingsboard.py|main_thingsboard.py]] on the board. WiFi stays in **`boot.py`**.

Broker: `mqtt.thingsboard.cloud` · Port: **1883**  
Topic: `v1/devices/me/telemetry` · Username: access token · Password: empty
### 4. Troubleshooting for tutorial

| Issue | Fix |
|-------|-----|
| No data on dashboard | Widget must use telemetry key **`counter`** exactly |
| MQTT connect fail | Token copied wrong; check 1883 not blocked on WiFi |
| WiFi fail | Fix `boot.py`; Ctrl+D reboot |
| JSON errors | Use `json.dumps()`, not raw string |

---

## Partner guide (Word + screenshots)

Full template: [[partner-guide-screenshot-map]]

**Screenshot folder:** `99-ATTACHMENTS/EGE322/assignment-3/screenshots/`  
Name files `01-…` through `15-…` — see map for what to capture and which Word section each goes in.

**Must-have shots:** device + token (04), widget config (07–08), Thonny running (11–12), **live dashboard (14)**.

---

## Word tutorial outline (summary)

1. ThingsBoard account + device creation (screenshots)
2. Access token + MQTT settings table
3. Dashboard widget setup (before/after screenshots)
4. Full annotated `main.py`
5. Live dashboard screenshot with counter updating
6. **What you learned:** device/token model, telemetry JSON, MQTT vs Adafruit feeds, cloud IoT architecture
7. Limitations: free tier limits, latency, public dashboard security

---

## Optional exploration — Node-RED (bonus)

Same counter → local Mosquitto → Node-RED → `/ui`. One-page comparison:

| | ThingsBoard | Node-RED |
|---|-------------|----------|
| Look | Enterprise | Functional |
| Host | Cloud | Local |
| Learn | IoT platform | Event-driven flows |

See prior Node-RED flow notes in git history if needed.

---

## Work plan

- [ ] ThingsBoard cloud account + device + token
- [ ] Build polished dashboard (gauge + chart, dark theme)
- [ ] PC test: `thingsboard_test_sender.py --mode rich`
- [ ] ESP32: `main_thingsboard.py` + `boot.py`
- [ ] Screenshot set → `assignment-3/screenshots/` (see [[partner-guide-screenshot-map]])
- [ ] Word tutorial for partner (jigsaw)
- [ ] (Optional) Node-RED exploration + comparison paragraph
- [ ] Submit Brightspace + peer eval

---

## Partner

<!-- gap: confirm partner platform (likely ThingSpeak MQTT) -->

**You:** ThingsBoard MQTT tutorial  
**Partner:** TBD — exchange guides per jigsaw
