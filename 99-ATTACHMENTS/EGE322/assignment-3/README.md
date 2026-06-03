# EGE322 Assignment 3 — ThingsBoard MQTT

**Default transport: MQTT** (matches ThingsBoard / `mosquitto_pub` template).

## MQTT template (ThingsBoard)

| Setting | Value |
|---------|--------|
| Host | `mqtt.thingsboard.cloud` |
| Port | `1883` |
| Topic | `v1/devices/me/telemetry` |
| Username (`-u`) | **device access token** |
| Password | *(empty — omit `-P`)* |
| QoS | `1` (recommended) |
| Message (`-m`) | **Valid JSON** — keys in double quotes |

### mosquitto_pub (one message)

```powershell
# Install Mosquitto first, or use the Python script below
mosquitto_pub -d -q 1 -h mqtt.thingsboard.cloud -p 1883 `
  -t v1/devices/me/telemetry `
  -u "PASTE_ACCESS_TOKEN_IN_CONFIG_PY" `
  -m '{"temperature":25,"humidity":58,"counter":40}'
```

Wrong: `-m "{temperature:25}"` — invalid JSON.  
Right: `-m '{"temperature":25}'`

### Python test sender (same MQTT settings)

```powershell
cd 99-ATTACHMENTS/EGE322/assignment-3
copy config.example.py config.py    # paste token into THINGSBOARD_TOKEN
pip install paho-mqtt

python thingsboard_test_sender.py --seed-ai
python thingsboard_test_sender.py --mode rich
python thingsboard_test_sender.py --once '{"temperature":25,"humidity":58,"counter":40}'
```

Uses: broker `mqtt.thingsboard.cloud`, topic `v1/devices/me/telemetry`, token as username, **qos=1**.

---

## Generate dashboard with AI

Send **multiple keys** in one message, then use device → **Generate dashboard with AI**:

```powershell
python thingsboard_test_sender.py --seed-ai
```

Keys sent: `temperature`, `humidity`, `counter`, `pressure`, `co2`, `battery`, `rssi`, `light`, `motion`, `status`.

---

## ESP32 — DHT22 + counter (Lab 7 wiring)

Copy `main_thingsboard.py` → ESP32 `main.py`. WiFi in **`boot.py`** only → **Ctrl+D** reboot.

| DHT22 | ESP32 | OLED (optional) | ESP32 |
|-------|-------|-----------------|-------|
| VDD → 3.3V | | SDA → **GPIO 21** |
| DATA → **GPIO 15** | | SCL → **GPIO 22** |
| GND → GND | | | |

Real DHT22 `temperature` / `humidity` + internal `counter` (0→100, step 10) every 2 s via MQTT qos=1.

---

## Optional: HTTP (not default)

```powershell
python thingsboard_test_sender.py --seed-ai --http
Invoke-RestMethod -Uri "https://thingsboard.cloud/api/v1/$token/telemetry" -Method Post -ContentType "application/json" -Body '{"temperature":25}'
```

Use MQTT for the assignment tutorial to match ESP32 + partner guide.

---

## Widget keys

Must match JSON field names: `counter`, `temperature`, `humidity`, `status`, etc.
