---
type: lab
course: EGE322
module: EGE322-IOT-System-Project
status: draft
source: pdf
created: 2026-05-28
tags: [EGE322, lab, ThingSpeak, REST-API, cloud]
---

> **Related:** [[ege322-labs-6-8-walkthrough-guide|Labs 6–8 Walkthrough Guide]] | [[07-DASHBOARDS/NYPY3 - Main Index|NYPY3 Index]] | [[iot-data-collection-mqtt-rest-api-cloud-services-slides|MQTT & REST Lecture]] | [[ege322-lab-7-esp32-thingspeak-slides|Lab 7 ESP32 ThingSpeak]] | [[05-KB/concepts/MQTT|MQTT concept]]

# EGE322 Lab 6 — Introduction to ThingSpeak

> [!ingest] source: EGE322 Lab 6 - Introduction to ThingSpeak v2026.pdf | date: 2026-05-28 | tool: markitdown
> Auto-converted. Edit summary below; re-run ingest to replace block above.

## Summary

Introduces **ThingSpeak** — an IoT platform for storing and retrieving sensor data over HTTP. Students register a MathWorks account, create a channel with four fields (Temperature, Humidity, Luminosity, PIR), and update field values via **REST API URL** requests from a browser.

**PDF:** `99-ATTACHMENTS/EGE322/EGE322 Lab 6 - Introduction to ThingSpeak v2026.pdf`

---

## Objectives

- Create a ThingSpeak channel to view sensor data
- Use REST API to update status/field data

---

## Material

- Computer with Internet connection

---

## Theory

ThingSpeak is an open-source IoT application/API for storing and retrieving data from devices via HTTP. Each **channel** has up to **8 data fields**, 3 location fields, and 1 status field. Data can be updated with a URL request in the browser.

---

## Procedures

### 4.1 Register MathWorks account

1. Open [thingspeak.com](https://thingspeak.com/)
2. Click **Sign Up** → create MathWorks account
3. Verify via email link

### 4.2 Create channel and dashboard

1. Sign in → **Channels > My Channels** → **New Channel**
2. Enable **Fields 1–4** and name them: Temperature, Humidity, Luminosity, PIR
3. **Save Channel**

| Tab | Purpose |
|-----|---------|
| Private View | Channel data (owner only) |
| Public View | Public visualizations |
| Channel Settings | Edit/delete channel |
| Sharing | Private / public / shared users |
| API Keys | Read/write keys |
| Data Import/Export | Import/export data |

![[99-ATTACHMENTS/EGE322/ege322-lab-6-introduction-to-thingspeak/ege322-lab-6-introduction-to-thingspeak-p04.png|Four field charts created]]

### 4.3 Update fields via REST API

```
http://api.thingspeak.com/update?api_key=<api_key>&field1=25
```

- Replace `<api_key>` with **Write API Key** from API Keys tab
- Use `field1`–`field4` for Temperature, Humidity, Luminosity, PIR
- Refresh channel tab to see updated charts

![[99-ATTACHMENTS/EGE322/ege322-lab-6-introduction-to-thingspeak/ege322-lab-6-introduction-to-thingspeak-p05.png|Browser update response]]

---

## Figures

![[99-ATTACHMENTS/EGE322/ege322-lab-6-introduction-to-thingspeak/ege322-lab-6-introduction-to-thingspeak-p01.png|Lab 6 cover]]
![[99-ATTACHMENTS/EGE322/ege322-lab-6-introduction-to-thingspeak/ege322-lab-6-introduction-to-thingspeak-p02.png|Sign up]]
![[99-ATTACHMENTS/EGE322/ege322-lab-6-introduction-to-thingspeak/ege322-lab-6-introduction-to-thingspeak-p03.png|New channel settings]]
![[99-ATTACHMENTS/EGE322/ege322-lab-6-introduction-to-thingspeak/ege322-lab-6-introduction-to-thingspeak-p06.png|All four fields updated]]
