import socket
import gc
import BME280
from machine import Pin, I2C

i2c = I2C(scl=Pin(22), sda=Pin(21), freq=10000)
led1 = Pin(2, Pin.OUT)
led2 = Pin(4, Pin.OUT)

def web_page():
    bme = BME280.BME280(i2c=i2c)
    # Library properties return strings, e.g. "28.45C", "1013.25hPa", "45.67%"
    temp = bme.temperature.replace('C', '')
    pres = bme.pressure.replace('hPa', '')
    hum = bme.humidity.replace('%', '')
    led1_on = led1.value() == 1
    led2_on = led2.value() == 1
    led1_badge = 'badge-on' if led1_on else 'badge-off'
    led2_badge = 'badge-on' if led2_on else 'badge-off'
    led1_on_btn = ' active' if led1_on else ''
    led1_off_btn = ' active' if not led1_on else ''
    led2_on_btn = ' active' if led2_on else ''
    led2_off_btn = ' active' if not led2_on else ''
    html = """<!DOCTYPE html>
<html lang="en">
<head>
  <meta charset="utf-8">
  <meta http-equiv="refresh" content="5">
  <meta name="viewport" content="width=device-width, initial-scale=1">
  <title>ESP32 BME280 Dashboard</title>
  <style>
    * {{ box-sizing: border-box; margin: 0; padding: 0; }}
    body {{
      font-family: system-ui, -apple-system, sans-serif;
      background: #eef2f7;
      color: #1e293b;
      padding: 20px 12px 28px;
    }}
    .wrap {{ max-width: 420px; margin: 0 auto; }}
    header {{
      text-align: center;
      margin-bottom: 18px;
    }}
    header h1 {{
      font-size: 1.35rem;
      font-weight: 700;
      margin-bottom: 4px;
    }}
    header p {{
      font-size: 0.85rem;
      color: #64748b;
    }}
    .panel {{
      background: #fff;
      border: 1px solid #dbe3ee;
      border-radius: 14px;
      padding: 16px;
      margin-bottom: 14px;
      box-shadow: 0 1px 3px rgba(15, 23, 42, 0.06);
    }}
    .panel h2 {{
      font-size: 0.72rem;
      font-weight: 700;
      letter-spacing: 0.08em;
      text-transform: uppercase;
      color: #64748b;
      margin-bottom: 12px;
    }}
    .sensors {{
      display: grid;
      grid-template-columns: repeat(3, 1fr);
      gap: 8px;
    }}
    .sensor {{
      background: #f8fafc;
      border: 1px solid #e2e8f0;
      border-radius: 10px;
      padding: 12px 8px;
      text-align: center;
    }}
    .sensor .label {{
      font-size: 0.68rem;
      color: #64748b;
      margin-bottom: 6px;
    }}
    .sensor .value {{
      font-size: 1.15rem;
      font-weight: 700;
      line-height: 1.1;
    }}
    .sensor .unit {{
      display: block;
      font-size: 0.68rem;
      font-weight: 500;
      color: #94a3b8;
      margin-top: 4px;
    }}
    .hint {{
      margin-top: 10px;
      font-size: 0.75rem;
      color: #94a3b8;
      text-align: center;
    }}
    .led {{
      display: flex;
      align-items: center;
      justify-content: space-between;
      gap: 10px;
      padding: 12px 0;
    }}
    .led + .led {{
      border-top: 1px solid #eef2f7;
    }}
    .led-info {{ min-width: 0; }}
    .led-title {{
      font-size: 0.95rem;
      font-weight: 600;
      margin-bottom: 2px;
    }}
    .led-pin {{
      font-size: 0.72rem;
      color: #94a3b8;
    }}
    .badge {{
      display: inline-block;
      margin-top: 6px;
      padding: 3px 10px;
      border-radius: 999px;
      font-size: 0.72rem;
      font-weight: 700;
      letter-spacing: 0.04em;
    }}
    .badge-on {{
      background: #dcfce7;
      color: #166534;
    }}
    .badge-off {{
      background: #f1f5f9;
      color: #64748b;
    }}
    .actions {{
      display: flex;
      gap: 8px;
      flex-shrink: 0;
    }}
    .btn {{
      min-width: 58px;
      padding: 10px 14px;
      border-radius: 10px;
      border: 1px solid transparent;
      font-size: 0.85rem;
      font-weight: 700;
      text-align: center;
      text-decoration: none;
      line-height: 1;
    }}
    .btn-on {{
      background: #ecfdf5;
      color: #047857;
      border-color: #a7f3d0;
    }}
    .btn-off {{
      background: #f8fafc;
      color: #475569;
      border-color: #cbd5e1;
    }}
    .btn-on.active {{
      background: #059669;
      color: #fff;
      border-color: #059669;
    }}
    .btn-off.active {{
      background: #334155;
      color: #fff;
      border-color: #334155;
    }}
    footer {{
      text-align: center;
      font-size: 0.72rem;
      color: #94a3b8;
    }}
  </style>
</head>
<body>
  <div class="wrap">
    <header>
      <h1>ESP32 Dashboard</h1>
      <p>BME280 sensor readings and LED control</p>
    </header>

    <section class="panel">
      <h2>Environment</h2>
      <div class="sensors">
        <div class="sensor">
          <div class="label">Temperature</div>
          <div class="value">{}</div>
          <span class="unit">&deg;C</span>
        </div>
        <div class="sensor">
          <div class="label">Pressure</div>
          <div class="value">{}</div>
          <span class="unit">hPa</span>
        </div>
        <div class="sensor">
          <div class="label">Humidity</div>
          <div class="value">{}</div>
          <span class="unit">%</span>
        </div>
      </div>
      <p class="hint">Readings refresh automatically every 5 seconds.</p>
    </section>

    <section class="panel">
      <h2>LED Controls</h2>
      <p class="hint" style="margin-top:0;margin-bottom:12px;">Tap ON or OFF to control each LED.</p>

      <div class="led">
        <div class="led-info">
          <div class="led-title">LED 1</div>
          <div class="led-pin">GPIO 2</div>
          <span class="badge {}">{}</span>
        </div>
        <div class="actions">
          <a href="/?led1=on" class="btn btn-on{}">ON</a>
          <a href="/?led1=off" class="btn btn-off{}">OFF</a>
        </div>
      </div>

      <div class="led">
        <div class="led-info">
          <div class="led-title">LED 2</div>
          <div class="led-pin">GPIO 4</div>
          <span class="badge {}">{}</span>
        </div>
        <div class="actions">
          <a href="/?led2=on" class="btn btn-on{}">ON</a>
          <a href="/?led2=off" class="btn btn-off{}">OFF</a>
        </div>
      </div>
    </section>

    <footer>Auto-refresh enabled &middot; ESP32 web server</footer>
  </div>
</body>
</html>""".format(
        temp, pres, hum,
        led1_badge, 'ON' if led1_on else 'OFF', led1_on_btn, led1_off_btn,
        led2_badge, 'ON' if led2_on else 'OFF', led2_on_btn, led2_off_btn)
    return html

s = socket.socket(socket.AF_INET, socket.SOCK_STREAM)
s.setsockopt(socket.SOL_SOCKET, socket.SO_REUSEADDR, 1)
s.bind(('', 80))
s.listen(5)
print('Web server running on port 80')
while True:
    try:
        if gc.mem_free() < 102000:
            gc.collect()
        conn, addr = s.accept()
        conn.settimeout(3.0)
        print('Got a connection from %s' % str(addr))
        request = conn.recv(1024)
        conn.settimeout(None)
        request = str(request)

        if '/?led1=on' in request:
            print('LED1 ON')
            led1.value(1)
        if '/?led1=off' in request:
            print('LED1 OFF')
            led1.value(0)
        if '/?led2=on' in request:
            print('LED2 ON')
            led2.value(1)
        if '/?led2=off' in request:
            print('LED2 OFF')
            led2.value(0)

        response = web_page()
        conn.send('HTTP/1.1 200 OK\n')
        conn.send('Content-Type: text/html\n')
        conn.send('Connection: close\n\n')

        # Send in chunks instead of all at once
        chunk_size = 512
        for i in range(0, len(response), chunk_size):
            conn.send(response[i:i + chunk_size])

        conn.close()
        print('Response sent OK')
    except OSError as e:
        conn.close()
        print('Connection closed:', e)
