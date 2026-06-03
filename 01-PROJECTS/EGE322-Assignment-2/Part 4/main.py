def web_page():
    bme = BME280.BME280(i2c=i2c)
    temp = bme.temperature
    pres = bme.pressure
    hum = bme.humidity
    led1_state = "ON" if led1.value() == 1 else "OFF"
    led2_state = "ON" if led2.value() == 1 else "OFF"
    led1_dot = "#22c55e" if led1.value() == 1 else "#d1d5db"
    led2_dot = "#ef4444" if led2.value() == 1 else "#d1d5db"
    html = """<!DOCTYPE html>
<html>
<head>
  <meta http-equiv="refresh" content="5">
  <meta name="viewport" content="width=device-width, initial-scale=1">
  <title>ESP32 Dashboard</title>
  <style>
    *, *::before, *::after {{ box-sizing: border-box; margin: 0; padding: 0; }}
    body {{
      font-family: -apple-system, BlinkMacSystemFont, 'Segoe UI', sans-serif;
      background: #f4f4f5;
      display: flex;
      justify-content: center;
      align-items: flex-start;
      min-height: 100vh;
      padding: 32px 16px;
    }}
    .card {{
      background: #ffffff;
      border-radius: 12px;
      border: 1px solid #e4e4e7;
      padding: 24px;
      width: 100%;
      max-width: 380px;
    }}
    .card-title {{
      font-size: 16px;
      font-weight: 600;
      color: #18181b;
      margin-bottom: 2px;
    }}
    .card-sub {{
      font-size: 12px;
      color: #a1a1aa;
      margin-bottom: 20px;
    }}
    .sensor-grid {{
      display: grid;
      grid-template-columns: 1fr 1fr 1fr;
      gap: 8px;
      margin-bottom: 20px;
    }}
    .s-cell {{
      background: #f4f4f5;
      border-radius: 8px;
      padding: 10px 12px;
    }}
    .s-label {{
      font-size: 10px;
      color: #a1a1aa;
      text-transform: uppercase;
      letter-spacing: 0.06em;
      margin-bottom: 4px;
    }}
    .s-val {{
      font-size: 15px;
      font-weight: 600;
      color: #18181b;
    }}
    .s-unit {{
      font-size: 10px;
      font-weight: 400;
      color: #a1a1aa;
    }}
    .divider {{
      height: 1px;
      background: #f4f4f5;
      margin-bottom: 16px;
    }}
    .section-label {{
      font-size: 10px;
      font-weight: 500;
      color: #a1a1aa;
      text-transform: uppercase;
      letter-spacing: 0.08em;
      margin-bottom: 12px;
    }}
    .led-row {{
      display: flex;
      align-items: center;
      justify-content: space-between;
      padding: 8px 0;
    }}
    .led-row + .led-row {{
      border-top: 1px solid #f4f4f5;
    }}
    .led-left {{
      display: flex;
      align-items: center;
      gap: 8px;
    }}
    .dot {{
      width: 8px;
      height: 8px;
      border-radius: 50%;
    }}
    .led-name {{
      font-size: 13px;
      font-weight: 500;
      color: #18181b;
    }}
    .led-state {{
      font-size: 11px;
      color: #a1a1aa;
      margin-right: 10px;
    }}
    .btn-row {{ display: flex; gap: 6px; }}
    .btn {{
      font-size: 12px;
      font-weight: 500;
      padding: 5px 14px;
      border-radius: 6px;
      border: 1px solid;
      cursor: pointer;
      text-decoration: none;
      display: inline-block;
    }}
    .btn-on {{
      background: #f0fdf4;
      color: #166534;
      border-color: #bbf7d0;
    }}
    .btn-off {{
      background: #f4f4f5;
      color: #71717a;
      border-color: #e4e4e7;
    }}
  </style>
</head>
<body>
  <div class="card">
    <div class="card-title">ESP32 Dashboard</div>
    <div class="card-sub">BME280 &middot; live readings</div>

    <div class="sensor-grid">
      <div class="s-cell">
        <div class="s-label">Temp</div>
        <div class="s-val">{}<span class="s-unit"> C</span></div>
      </div>
      <div class="s-cell">
        <div class="s-label">Pressure</div>
        <div class="s-val">{}<span class="s-unit"> hPa</span></div>
      </div>
      <div class="s-cell">
        <div class="s-label">Humidity</div>
        <div class="s-val">{}<span class="s-unit"> %</span></div>
      </div>
    </div>

    <div class="divider"></div>
    <div class="section-label">GPIO Control</div>

    <div class="led-row">
      <div class="led-left">
        <div class="dot" style="background:{};"></div>
        <span class="led-name">LED 1</span>
      </div>
      <div style="display:flex;align-items:center;">
        <span class="led-state">{}</span>
        <div class="btn-row">
          <a href="/?led1=on" class="btn btn-on">ON</a>
          <a href="/?led1=off" class="btn btn-off">OFF</a>
        </div>
      </div>
    </div>

    <div class="led-row">
      <div class="led-left">
        <div class="dot" style="background:{};"></div>
        <span class="led-name">LED 2</span>
      </div>
      <div style="display:flex;align-items:center;">
        <span class="led-state">{}</span>
        <div class="btn-row">
          <a href="/?led2=on" class="btn btn-on">ON</a>
          <a href="/?led2=off" class="btn btn-off">OFF</a>
        </div>
      </div>
    </div>

  </div>
</body>
</html>""".format(temp, pres, hum, led1_dot, led1_state, led2_dot, led2_state)
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