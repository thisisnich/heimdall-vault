---
type: lecture
course: EGE322
module: EGE322-IOT-System-Project
status: draft
source: pdf
created: 2026-05-28
tags: [EGE322, lecture, MQTT, REST-API, ThingSpeak, Adafruit-IO, cloud]
---

> **Related:** [[07-DASHBOARDS/NYPY3 - Main Index|NYPY3 Index]] | [[05-KB/concepts/MQTT|MQTT concept]] | [[ege322-lab-6-introduction-to-thingspeak-slides|Lab 6]] | [[ege322-lab-7-esp32-thingspeak-slides|Lab 7]] | [[ege322-lab-8-mqtt-adafruit-io-slides|Lab 8]]

# IoT Data Collection — MQTT, REST API & Cloud Services

> [!ingest] source: My IoT Data Collection and Control Using MQTT, REST API & Cloud Services (BS).pdf | date: 2026-05-28 | tool: markitdown
> Auto-converted. Edit summary below; re-run ingest to replace block above.

## Summary

Lecture slides covering **REST API** (HTTP request-response) and **MQTT** (publish-subscribe) for IoT cloud connectivity. Compares QoS levels, REST vs MQTT trade-offs, and demo setups for **ThingSpeak** (REST URL updates) and **Adafruit IO** (MQTT feeds + dashboard widgets).

**PDF:** `99-ATTACHMENTS/EGE322/My IoT Data Collection and Control Using MQTT, REST API & Cloud Services (BS).pdf`

---

## REST API (HTTP)

A REST API lets devices/programs communicate using **HTTP** — the same protocol as web browsers.

| Function | HTTP Method | Analogy | Common Use |
|----------|-------------|---------|------------|
| Read data | GET | "Show me the menu" | Fetch sensor readings |
| Create resource | POST | "Order a new dish" | Send new data to server |
| Update data | PUT | "Change my pizza to extra cheese" | Update existing record |
| Delete data | DELETE | "Cancel my order" | Remove data |

![[99-ATTACHMENTS/EGE322/iot-data-collection-mqtt-rest-api-cloud-services/iot-data-collection-mqtt-rest-api-cloud-services-p03.png|HTTP REST overview]]

---

## MQTT

**MQTT** = Message Queuing Telemetry Transport. Lightweight pub/sub protocol over TCP/IP. Brokers include Mosquitto, HiveMQ.

![[99-ATTACHMENTS/EGE322/iot-data-collection-mqtt-rest-api-cloud-services/iot-data-collection-mqtt-rest-api-cloud-services-p06.png|MQTT uplink and downlink]]

### QoS levels

| Level | Name | Guarantee | Typical Use |
|-------|------|-----------|-------------|
| 0 | At most once | Fire-and-forget; may be lost | Non-critical sensor streams |
| 1 | At least once | Retries until ACK; duplicates possible | Control commands |
| 2 | Exactly once | Two-phase handshake; no loss/dup | Critical billing/actuator data |

![[99-ATTACHMENTS/EGE322/iot-data-collection-mqtt-rest-api-cloud-services/iot-data-collection-mqtt-rest-api-cloud-services-p07.png|MQTT QoS levels]]

---

## REST API vs MQTT

| Feature | REST API | MQTT |
|---------|----------|------|
| Model | Request-Response | Publish-Subscribe |
| Protocol | HTTP | MQTT over TCP/IP |
| Connection | Short-lived per request | Long-lived persistent |
| Data format | JSON, XML, HTML | JSON, binary, plain text |

**REST best for:** one-time requests, device config/registration, web app integration.

**MQTT best for:** real-time streaming, low bandwidth/power networks, automatic push updates.

![[99-ATTACHMENTS/EGE322/iot-data-collection-mqtt-rest-api-cloud-services/iot-data-collection-mqtt-rest-api-cloud-services-p08.png|REST vs MQTT comparison]]

---

## ThingSpeak (REST)

MathWorks IoT analytics platform. Update channel fields via URL:

```
api.thingspeak.com/update?api_key=<API_KEY>&field1=35
```

- Wait ~15 s for chart refresh
- Free tier rate limits apply

![[99-ATTACHMENTS/EGE322/iot-data-collection-mqtt-rest-api-cloud-services/iot-data-collection-mqtt-rest-api-cloud-services-p09.png|ThingSpeak dashboard]]
![[99-ATTACHMENTS/EGE322/iot-data-collection-mqtt-rest-api-cloud-services/iot-data-collection-mqtt-rest-api-cloud-services-p11.png|REST API URL example]]

---

## Adafruit IO (MQTT)

Cloud dashboard with **feeds** (data streams) and **blocks** (widgets). MQTT setup for publish/subscribe; downlink control example toggles devices from dashboard.

![[99-ATTACHMENTS/EGE322/iot-data-collection-mqtt-rest-api-cloud-services/iot-data-collection-mqtt-rest-api-cloud-services-p12.png|Adafruit IO dashboard]]
![[99-ATTACHMENTS/EGE322/iot-data-collection-mqtt-rest-api-cloud-services/iot-data-collection-mqtt-rest-api-cloud-services-p13.png|MQTT setup]]
![[99-ATTACHMENTS/EGE322/iot-data-collection-mqtt-rest-api-cloud-services/iot-data-collection-mqtt-rest-api-cloud-services-p16.png|Completed dashboard]]

---

## Figures (all slides)

![[99-ATTACHMENTS/EGE322/iot-data-collection-mqtt-rest-api-cloud-services/iot-data-collection-mqtt-rest-api-cloud-services-p01.png|Title slide]]
![[99-ATTACHMENTS/EGE322/iot-data-collection-mqtt-rest-api-cloud-services/iot-data-collection-mqtt-rest-api-cloud-services-p02.png|Rest API and MQTT]]
![[99-ATTACHMENTS/EGE322/iot-data-collection-mqtt-rest-api-cloud-services/iot-data-collection-mqtt-rest-api-cloud-services-p04.png|REST API functions]]
![[99-ATTACHMENTS/EGE322/iot-data-collection-mqtt-rest-api-cloud-services/iot-data-collection-mqtt-rest-api-cloud-services-p05.png|What is MQTT]]
![[99-ATTACHMENTS/EGE322/iot-data-collection-mqtt-rest-api-cloud-services/iot-data-collection-mqtt-rest-api-cloud-services-p10.png|ThingSpeak from MATLAB]]
![[99-ATTACHMENTS/EGE322/iot-data-collection-mqtt-rest-api-cloud-services/iot-data-collection-mqtt-rest-api-cloud-services-p14.png|Create new block]]
![[99-ATTACHMENTS/EGE322/iot-data-collection-mqtt-rest-api-cloud-services/iot-data-collection-mqtt-rest-api-cloud-services-p15.png|Feed setup]]
