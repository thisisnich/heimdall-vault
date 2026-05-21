---
type: lab
course: EGE322
module: EGE322-IOT-System-Project
status: draft
source: manual
created: 2026-05-20
tags: [EGE322, lab, micropython, ESP32, lab-code]
---

> **Related:** [[07-DASHBOARDS/NYPY3 - Main Index|NYPY3 Index]] | [[EGE322 Lab 2- Controlling the ESP32 GPIOs v2026-1|Lab 2]] | [[EGE322 Lab 3- Interacting with the ESP32 GPIOs v2026-1|Lab 3]] | [[EGE322 Assignment 2 - BME280 Web Server|Assignment 2]]

# EGE322 Lab Code Reference

MicroPython scripts from lab sessions. Source files in `99-ATTACHMENTS/EGE322/lab-code/`.

> [!ingest] source: 00-INBOX/Lab2, Lab4 | date: 2026-05-20 | tool: manual
> Copied from inbox lab folders. Edit summary below.

## Summary

Reference implementations for ESP32 GPIO, buttons, PWM, ADC/LDR, servo, DHT22, and OLED display labs.

---

## Assignment 2 Reference Scripts

| Script | Part | Description |
|--------|------|-------------|
| [[99-ATTACHMENTS/EGE322/assignment-2/bme280_WebServer_1.py\|bme280_WebServer_1.py]] | 2 | BME280 readings via web server (text/HTML) |
| [[99-ATTACHMENTS/EGE322/assignment-2/web_server_led_on-off.py\|web_server_led_on-off.py]] | 3 | Single LED ON/OFF via web buttons |

See [[01-PROJECTS/EGE322-Assignment-2/EGE322 Assignment 2 - BME280 Web Server|Assignment 2 project note]].

---

## Lab 2 — GPIO & Buttons

| Script | Description | GPIO |
|--------|-------------|------|
| [[99-ATTACHMENTS/EGE322/lab-code/Lab2/Lab2/Blinking_LED.py\|Blinking_LED.py]] | Toggle onboard LED | GPIO 2 |
| [[99-ATTACHMENTS/EGE322/lab-code/Lab2/Lab2/Blinking_2LED.py\|Blinking_2LED.py]] | Alternate two LEDs | GPIO 2, 5 |
| [[99-ATTACHMENTS/EGE322/lab-code/Lab2/Lab2/LED_LightUp_Button_pressed.py\|LED_LightUp_Button_pressed.py]] | LED on while button held | Btn 15, LED 5 |
| [[99-ATTACHMENTS/EGE322/lab-code/Lab2/Lab2/LED_toggle_With_Button.py\|LED_toggle_With_Button.py]] | Toggle LED on press (debounce) | Btn 15, LED 5 |
| [[99-ATTACHMENTS/EGE322/lab-code/Lab2/Lab2/Exercise_Lab2.py\|Exercise_Lab2.py]] | Two buttons toggle two LEDs | Btn 15/19, LED 5/2 |

**Debounce pattern** (used in button scripts):
```python
first = button.value()
sleep(0.01)
second = button.value()
if first and not second:  # falling edge = press
    ...
```

---

## Lab 3 — PWM, ADC, LDR, Servo

| Script | Description | GPIO |
|--------|-------------|------|
| [[99-ATTACHMENTS/EGE322/lab-code/Lab2/Lab3/fadeLED.py\|fadeLED.py]] | PWM fade up (function wrapper) | GPIO 23 |
| [[99-ATTACHMENTS/EGE322/lab-code/Lab2/Lab3/Fade2.py\|Fade2.py]] | PWM fade up and down | GPIO 23 |
| [[99-ATTACHMENTS/EGE322/lab-code/Lab2/Lab3/readADC.py\|readADC.py]] | Read potentiometer ADC raw | GPIO 36 |
| [[99-ATTACHMENTS/EGE322/lab-code/Lab2/Lab3/readLDR.py\|readLDR.py]] | LDR scaled value | GPIO 36 |
| [[99-ATTACHMENTS/EGE322/lab-code/Lab2/Lab3/readLDR_percenrage.py\|readLDR_percenrage.py]] | LDR class — percentage | GPIO 36 |
| [[99-ATTACHMENTS/EGE322/lab-code/Lab2/Lab3/Servo1.py\|Servo1.py]] | Servo 0° → 90° → 180° | GPIO 23 |

---

## Lab 4 — DHT22 & OLED

| Script | Description | GPIO |
|--------|-------------|------|
| [[99-ATTACHMENTS/EGE322/lab-code/Lab4/dht22.py\|dht22.py]] | DHT22 temp/humidity serial | GPIO 5 |
| [[99-ATTACHMENTS/EGE322/lab-code/Lab4/ssd1306.py\|ssd1306.py]] | OLED driver library (I2C) | — |
| [[99-ATTACHMENTS/EGE322/lab-code/Lab4/DHTT22_LED.py\|DHTT22_LED.py]] | DHT22 + OLED display | DHT 5, I2C 21/26 |

**DHTT22_LED wiring:**
- DHT22 data → GPIO 5
- OLED SDA → GPIO 21, SCL → GPIO 26

---

## Suggested next

- [ ] Add summary notes to [[EGE322 Lab 2- Controlling the ESP32 GPIOs v2026-1|Lab 2 tutorial]]
- [ ] Link Lab 4 scripts when Lab 4 note exists in vault
