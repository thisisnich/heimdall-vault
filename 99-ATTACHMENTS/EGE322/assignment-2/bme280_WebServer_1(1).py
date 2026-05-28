  
def web_page():
    bme = bme280.BME280(i2c=i2c)
    html = """
    <html>
    <head>
        <meta http-equiv="refresh" content="5">
        <title>BME280 Sensor Readings</title>
    </head>
    <body>
        <h1>BME280 Sensor Readings</h1>
        <p><strong>Temperature (C):</strong> {}</p>
        <p><strong>Pressure (hPa):</strong> {}</p>
        <p><strong>Humidity (%):</strong> {}</p>
    </body>
    </html>
    """.format(bme.temperature, bme.pressure, bme.humidity)
    return html


s = socket.socket(socket.AF_INET, socket.SOCK_STREAM)
s.bind(('', 80))
s.listen(5)

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
    print('Content = %s' % request)
    response = web_page()
    conn.send('HTTP/1.1 200 OK\n')
    conn.send('Content-Type: text/html\n')
    conn.send('Connection: close\n\n')
    conn.sendall(response)
    conn.close()
  except OSError as e:
    conn.close()
    print('Connection closed')




