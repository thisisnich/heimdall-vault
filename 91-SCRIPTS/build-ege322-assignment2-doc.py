#!/usr/bin/env python3
"""Generate EGE322 Assignment 2 Word submission document (screenshot placeholders + code diffs)."""

from pathlib import Path

from docx import Document
from docx.enum.text import WD_COLOR_INDEX
from docx.shared import Inches, Pt

VAULT = Path(__file__).resolve().parent.parent
OUT = VAULT / "01-PROJECTS" / "EGE322-Assignment-2" / "Assignment_2.docx"


def add_heading(doc, text, level=1):
    doc.add_heading(text, level=level)


def add_para(doc, text, bold=False, italic=False):
    p = doc.add_paragraph()
    run = p.add_run(text)
    run.bold = bold
    run.italic = italic
    return p


def add_placeholder(doc, label):
    p = doc.add_paragraph()
    run = p.add_run(f"[INSERT SCREENSHOT: {label}]")
    run.italic = True
    run.font.highlight_color = WD_COLOR_INDEX.YELLOW
    doc.add_paragraph()


def add_code_block(doc, lines, highlight_lines=None):
    highlight_lines = highlight_lines or set()
    for i, line in enumerate(lines, start=1):
        p = doc.add_paragraph()
        p.paragraph_format.space_after = Pt(0)
        p.paragraph_format.space_before = Pt(0)
        run = p.add_run(line if line else " ")
        run.font.name = "Consolas"
        run.font.size = Pt(9)
        if i in highlight_lines:
            run.font.highlight_color = WD_COLOR_INDEX.YELLOW


def main():
    doc = Document()

    add_heading(doc, "EGE322 — Assignment 2: BME280 Web Server")
    add_para(doc, "Module: EGE322 IoT System Project")
    add_para(doc, "Name: Nicholas Dubs")
    add_para(doc, "Student ID: [fill in if required]")
    doc.add_paragraph()

    add_heading(doc, "Submission checklist (zip: Assignment_2/)", level=2)
    for item in [
        "Part 1/ — main.py, BME280.py",
        "Part 2/ — main.py, boot.py",
        "Part 3/ — main.py, boot.py",
        "Part 4/ — main.py, boot.py",
        "This Word document",
    ]:
        doc.add_paragraph(item, style="List Bullet")
    doc.add_paragraph()

    # --- Part 2 ---
    add_heading(doc, "Part 2 — BME280 sensor web server (HTML table)", level=2)
    add_para(doc, "Screenshot of the web page showing temperature, humidity, and pressure in a table:")
    add_placeholder(doc, "Part 2 — browser at ESP32 IP, sensor table visible, auto-refresh working")

    add_para(doc, "Modified sections in main.py (compared to portal reference bme280_WebServer_1.py):", bold=True)
    add_para(doc, "Yellow highlight = changed or added vs the original provided code.")

    part2_code = [
        "def web_page():",
        "    bme = BME280.BME280(i2c=i2c)",
        "    temp = bme.temperature",
        "    pres = bme.pressure",
        "    hum = bme.humidity",
        "",
        "    html = \"\"\"<html>",
        "    <head>",
        "        <meta http-equiv=\"refresh\" content=\"5\">",
        "        <title>ESP with BME280</title>",
        "        <style>",
        "            table { margin: auto; border-collapse: collapse; ... }",
        "            thead th { background-color: #1a56b0; color: white; ... }",
        "        </style>",
        "    </head>",
        "    <body>",
        "        <h1>ESP with BME280</h1>",
        "        <table>",
        "            <thead>",
        "                <tr><th>MEASUREMENT</th><th>VALUE</th></tr>",
        "            </thead>",
        "            <tbody>",
        "                <tr><td>Temp. Celsius</td><td>{}</td></tr>",
        "                <tr><td>Pressure</td><td>{}</td></tr>",
        "                <tr><td>Humidity</td><td>{}</td></tr>",
        "            </tbody>",
        "        </table>",
        "    </body>",
        "    </html>\"\"\".format(temp, pres, hum)",
        "    return html",
    ]
    add_code_block(doc, part2_code, highlight_lines={2, 3, 4, 5, 8, 9, 10, 11, 12, 13, 14, 15, 16, 17, 18, 19, 20, 21, 22, 23, 24, 25, 26, 27})

    add_para(doc, "Summary of changes:", bold=True)
    for bullet in [
        "Replaced three <p> tags with an HTML <table> (thead + tbody) as required.",
        "Added CSS for table header, alternating row colours, and centred layout.",
        "Read sensor values into variables before .format() (same data, clearer structure).",
        "Uses BME280 library module uploaded to the ESP32.",
    ]:
        doc.add_paragraph(bullet, style="List Bullet")
    doc.add_page_break()

    # --- Part 3 ---
    add_heading(doc, "Part 3 — Two LEDs with ON/OFF web buttons", level=2)
    add_placeholder(doc, "Part 3 — web page showing LED1 and LED2 states with ON/OFF buttons")

    add_para(doc, "Modified sections in main.py (compared to portal reference web_server_led_on-off.py):", bold=True)

    part3_code = [
        "led1 = Pin(2, Pin.OUT)",
        "led2 = Pin(4, Pin.OUT)",
        "",
        "def web_page():",
        "    led1_state = \"ON\" if led1.value() == 1 else \"OFF\"",
        "    led2_state = \"ON\" if led2.value() == 1 else \"OFF\"",
        "    ...",
        "    <p>LED1 state: <strong>{}</strong></p>",
        "    <p><a href=\"/?led1=on\"><button ...>ON</button></a></p>",
        "    <p><a href=\"/?led1=off\"><button ...>OFF</button></a></p>",
        "    <hr>",
        "    <p>LED2 state: <strong>{}</strong></p>",
        "    <p><a href=\"/?led2=on\">...</p>",
        "    <p><a href=\"/?led2=off\">...</p>",
        "",
        "    if '/?led1=on' in request:",
        "        led1.value(1)",
        "    if '/?led1=off' in request:",
        "        led1.value(0)",
        "    if '/?led2=on' in request:",
        "        led2.value(1)",
        "    if '/?led2=off' in request:",
        "        led2.value(0)",
    ]
    add_code_block(doc, part3_code, highlight_lines=set(range(1, len(part3_code) + 1)))

    add_para(doc, "Summary of changes:", bold=True)
    for bullet in [
        "Added second LED on GPIO 4 (LED1 on GPIO 2, LED2 on GPIO 4).",
        "Duplicated ON/OFF button pairs — one set per LED.",
        "Changed URL query from /?led=on|off to /?led1=on|off and /?led2=on|off.",
        "Request handler updated to control led1 and led2 independently.",
    ]:
        doc.add_paragraph(bullet, style="List Bullet")
    doc.add_page_break()

    # --- Part 4 ---
    add_heading(doc, "Part 4 — Combined sensor + LED control page", level=2)
    add_placeholder(doc, "Part 4 — final combined dashboard (sensor readings + both LED controls on one page)")

    add_para(doc, "Part 4 merges Part 2 sensor table/grid and Part 3 dual-LED controls into a single web_page(), with improved card-style CSS and 5-second auto-refresh for live sensor data.", italic=True)

    doc.save(OUT)
    print(f"Wrote {OUT}")


if __name__ == "__main__":
    main()
