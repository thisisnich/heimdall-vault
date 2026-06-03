---
type: assignment
course: EGE322
module: EGE322-IOT-System-Project
status: draft
source: pdf
created: 2026-06-02
due: 2026-06-08
tags: [EGE322, assignment, MQTT, jigsaw, ThingSpeak, Adafruit-IO, dashboard]
---

> **Related:** [[07-DASHBOARDS/Schedule & Assessments Dashboard|Assessments]] | [[ege322-labs-6-8-walkthrough-guide|Labs 6–8 Guide]] | [[select-an-iot-dashboard-photo|Dashboard options chart]] | [[01-PROJECTS/EGE322-Assignment-3/EGE322 Assignment 3 — MQTT Dashboard|Project note]]

# EGE322 Assignment 3 — MQTT Cloud Dashboard (Jigsaw)

> [!ingest] source: IOT Assignment 3 2026b.pdf | date: 2026-06-02 | tool: markitdown
> Auto-converted. Edit summary below; re-run ingest to replace block above.

**PDF:** `99-ATTACHMENTS/EGE322/IOT Assignment 3 2026b.pdf`  
**Due:** Week 8 — **8 Jun 2026** (20% combined with Practical Lab Assignment 3)

## Summary

Pair **jigsaw** assignment: explore **MQTT** from ESP32 to a cloud dashboard, debug buggy sample code, and write a **tutorial your partner can follow**. No extra sensors — ESP32 generates sample data internally. **Basic tasks are fixed by role** (A = ThingSpeak MQTT, B = Adafruit IO MQTT). Optional **exploration task** on another platform for bonus marks.

---

## Jigsaw roles

| Role | Basic task | Deliverable |
|------|------------|-------------|
| **Student A** | ThingSpeak MQTT | Debug provided code → step-by-step guide for B |
| **Student B** | Adafruit IO MQTT | Similar upload task → guide for A |

Both guides must include: procedures + screenshots, **corrected MicroPython** with comments/troubleshooting, dashboard result screenshots, limitations.

Afterward: exchange knowledge + **peer evaluation form**.

---

## Provided ThingSpeak sample (intentionally buggy)

Known issues to fix in your guide (not exhaustive):

| Bug | Fix |
|-----|-----|
| `CHANNE_ID` typo vs `CHANNEL_ID` | Consistent variable name |
| `WiFi_PASS` vs `WiFi_Password` | Match variable names |
| `USER` / `PASSWORD` undefined in `MQTTClient(...)` | Use credentials from ThingSpeak MQTT device `.txt` |
| `wifi_connect()` in `main.py` | Use existing **`boot.py`** for WiFi if kept on board |
| Topic format | ThingSpeak MQTT v2: `channels/{channel_id}/publish` with payload `field1=value` |

**Broker:** `mqtt-v2.thingspeak.com` port **1883**

---

## Exploration task (bonus)

Choose **one** from lecturer list:

- ThingsBoard · Tago IO · Home Assistant · Node-RED Dashboard · **Google Firebase** · Ubidots · Blynk · AllThingsTalk Maker

See [[select-an-iot-dashboard-photo|dashboard comparison chart]] for wider context.

---

## Submission

1. **Word doc** — tutorial (steps, screenshots, fixed code, dashboard shots, limitations)
2. Upload to **Brightspace**
3. Complete **peer evaluation** form

---

## Figures

![[99-ATTACHMENTS/EGE322/ege322-assignment-3-iot-dashboard-2026b/ege322-assignment-3-iot-dashboard-2026b-p01.png|Assignment cover]]
![[99-ATTACHMENTS/EGE322/ege322-assignment-3-iot-dashboard-2026b/ege322-assignment-3-iot-dashboard-2026b-p02.png|Jigsaw method]]
![[99-ATTACHMENTS/EGE322/ege322-assignment-3-iot-dashboard-2026b/ege322-assignment-3-iot-dashboard-2026b-p04.png|Assignment tasks]]
