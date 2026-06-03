---
type: assignment
course: EGE322
module: EGE322-IOT-System-Project
status: draft
source: manual
created: 2026-06-02
due: 2026-06-08
tags: [EGE322, assignment-3, tutorial, screenshots, jigsaw]
---

> **Related:** [[EGE322 Assignment 3 — MQTT Dashboard|Project hub]] | [[ege322-assignment-3-iot-dashboard-2026b-slides|Assignment brief]]

# Partner tutorial — screenshot map & Word template

**Deliverable:** Microsoft Word guide your partner can follow without asking you questions.  
**Platform:** ThingsBoard MQTT + ESP32 (or PC test sender for verification).

---

## Where to put screenshots

Save all captures here before inserting into Word:

```
99-ATTACHMENTS/EGE322/assignment-3/screenshots/
├── 01-thingsboard-signup.png
├── 02-devices-new.png
├── ...
└── 15-dashboard-live.png
```

**Naming:** `NN-short-description.png` — numbers match sections below.  
**Tips:** Win+Shift+S → crop tight → paste into Word. Blur or redact your **access token** in any shot where it appears.

Optional: embed copies in this vault note with `![[99-ATTACHMENTS/EGE322/assignment-3/screenshots/01-....png]]` as you collect them.

---

## Screenshot checklist (15 images)

Tick when captured. **Bold** = required by rubric.

| # | Filename | Take this screenshot when… | Goes in Word section |
|---|----------|----------------------------|----------------------|
| **01** | `01-thingsboard-home.png` | Logged into [thingsboard.cloud](https://thingsboard.cloud) — sidebar visible | §1 Introduction |
| **02** | `02-devices-list.png` | **Entities → Devices** page | §2 Step 1 |
| **03** | `03-device-create.png` | **+** dialog with name `ESP32-Counter` filled | §2 Step 1 |
| **04** | `04-access-token.png` | Device page → **Copy access token** (redact token in doc) | §2 Step 2 |
| **05** | `05-mqtt-settings-table.png` | Optional: device **Check connectivity** or your own table screenshot | §2 Step 3 |
| **06** | `06-dashboard-new.png` | **Dashboards → +** creating `EGE322 Assignment 3` | §3 Step 1 |
| **07** | `07-widget-gauge-config.png` | Adding **Analog gauge** — data key `counter` highlighted | §3 Step 2 |
| **08** | `08-widget-chart-config.png` | **Timeseries chart** — keys `counter`, `temperature`, `humidity` | §3 Step 3 |
| **09** | `09-dashboard-layout.png` | Finished dashboard (dark theme, all widgets placed) — static OK | §3 Step 4 |
| **10** | `10-pc-test-terminal.png` | PC running `thingsboard_test_sender.py --mode rich` showing `→ {"counter":...}` | §4 Step 1 (verify before ESP32) |
| **11** | `11-thonny-main-py.png` | Thonny: `main.py` on ESP32 with token **redacted**, key lines visible | §4 Step 2 |
| **12** | `12-thonny-shell-connected.png` | Shell: `ThingsBoard MQTT connected` + `Published:` lines | §4 Step 3 |
| **13** | `13-latest-telemetry.png` | Device → **Latest telemetry** tab showing incoming JSON | §4 Step 4 |
| **14** | `14-dashboard-live.png` | **Hero shot** — dashboard with gauges/charts **actively updating** | §5 Results |
| **15** | `15-troubleshooting.png` | Optional: wrong widget key (empty) vs fixed — teaches one pitfall | §6 Troubleshooting |

Minimum for full marks: **01–04, 06–09, 11–12, 14** (11 shots). Add 10 if partner may test on PC first.

---

## Word document outline (copy into .docx)

Use heading styles in Word. After each *[Figure N]* line, insert the matching PNG.

---

### Title page

- Module: EGE322 IoT System Project  
- Title: **ThingsBoard MQTT Tutorial — ESP32 Telemetry Dashboard**  
- Author / Date  
- Partner name  

---

### §1 Introduction (½ page)

Explain what the guide covers: ESP32 sends JSON telemetry over MQTT to ThingsBoard; partner needs Thonny, ESP32, WiFi via `boot.py`, no extra sensors.

*[Figure 01]* — ThingsBoard home  

**Architecture diagram** (draw or paste):

```
ESP32 → MQTT → mqtt.thingsboard.cloud → Dashboard widgets
```

---

### §2 ThingsBoard account & device

**Step 1 — Create device**  
1. Sign up at thingsboard.cloud  
2. Entities → Devices → +  
3. Name: `ESP32-Counter` → Add  

*[Figure 02]* · *[Figure 03]*  

**Step 2 — Access token**  
1. Open device → Copy access token  
2. This token = MQTT **username** (password is empty)  

*[Figure 04]* — redact token in image  

**Step 3 — MQTT connection settings**

| Setting | Value |
|---------|--------|
| Broker | `mqtt.thingsboard.cloud` |
| Port | `1883` |
| Client ID | any (e.g. `esp32_thingsboard`) |
| Username | *device access token* |
| Password | *(leave empty)* |
| Publish topic | `v1/devices/me/telemetry` |
| Payload format | JSON, e.g. `{"counter": 10}` |

*[Figure 05]* optional  

---

### §3 Build the dashboard

**Step 1 — New dashboard**  
Dashboards → + → name `EGE322 Assignment 3`  

*[Figure 06]*  

**Step 2 — Analog gauge**  
Add widget → Analog gauge → data key **`counter`** → save  

*[Figure 07]*  

**Step 3 — Timeseries chart**  
Add widget → Chart → keys **`counter`**, **`temperature`**, **`humidity`** → real-time window 5 min  

*[Figure 08]*  

**Step 4 — Layout**  
Dark theme, align widgets, save  

*[Figure 09]*  

> **Important:** Widget data keys must **exactly match** JSON field names from the code.

---

### §4 ESP32 setup & code

**Step 1 — Test on PC first (optional but recommended)**  
Run `thingsboard_test_sender.py --mode rich` — dashboard should update before flashing ESP32.

*[Figure 10]*  

**Step 2 — Copy code to ESP32**  
1. WiFi stays in **`boot.py`** (do not duplicate)  
2. Copy `main_thingsboard.py` → ESP32 `main.py`  
3. Paste access token in `ACCESS_TOKEN`  

*[Figure 11]*  

**Step 3 — Run**  
Soft reboot **Ctrl+D**. Shell should show connected + published JSON.

*[Figure 12]*  

**Step 4 — Verify telemetry**  
Device → Latest telemetry  

*[Figure 13]*  

**Full code listing** — paste annotated `main.py` below (use Word *Code* style or monospace):

<!-- paste main_thingsboard.py with line comments -->

---

### §5 Results

*[Figure 14]* — live dashboard (best screenshot for submission)  

Describe what partner should see: counter 0→100 step 10 every 2 s; temperature/humidity if using full payload.

---

### §6 Troubleshooting

| Problem | Cause | Fix |
|---------|-------|-----|
| Dashboard empty | Wrong data key | Match `counter` in widget and JSON |
| MQTT fail | Bad token | Re-copy from device page |
| No WiFi | `boot.py` | Fix SSID/password, Ctrl+D |
| Old values only | Widget not realtime | Set chart to real-time mode |

*[Figure 15]* optional before/after  

---

### §7 Limitations

- ThingsBoard free tier rate/device limits  
- WiFi must be 2.4 GHz  
- Access token is secret — do not share publicly  
- ~2 s latency cloud round-trip  

---

### §8 What I learned (short paragraph)

Device/token model, MQTT telemetry JSON, difference vs ThingSpeak REST / Adafruit feeds.

---

## Rubric cross-check

Assignment requires:

- [ ] Step-by-step procedures with screenshots → §2–§5  
- [ ] Corrected MicroPython with comments → §4 code block + Fig 11–12  
- [ ] Dashboard result screenshots → **Fig 14** (required), Fig 09  
- [ ] Limitations → §7  

---

## Quick capture order (do in one session)

1. ThingsBoard setup → **01–09**  
2. Run PC test sender → **10**, refresh dashboard → **14**  
3. Flash ESP32 → **11–13**, refresh **14** again if better  
4. Write Word doc inserting figures in order  

---

## Partner handoff

Send partner:

1. Word `.docx`  
2. Optional: zip of `main_thingsboard.py` (token removed — they use their own device)  
3. Link to `99-ATTACHMENTS/EGE322/assignment-3/README.md` for MQTT reference  

They use **their own** ThingsBoard account + token unless you share a test device (not recommended for submission).
