import socket
import gc
import BME280
from machine import Pin, I2C

i2c = I2C(scl=Pin(22), sda=Pin(21), freq=10000)

def web_page():
    bme = BME280.BME280(i2c=i2c)
    temp = bme.temperature
    pres = bme.pressure
    hum = bme.humidity

    html = """<html>
    <head>
        <meta http-equiv="refresh" content="5">
        <title>ESP with BME280</title>

<style>
            body {{ font-family: Arial, sans-serif; text-align: center; background: white; }}
            h1 {{ color: black; font-size: 24px; margin-bottom: 20px; }}
            table {{ margin: auto; border-collapse: collapse; width: 420px; }}
            thead th {{ background-color: #1a56b0; color: white; padding: 12px 20px;
                text-align: center; font-size: 13px; letter-spacing: 1px; }}
            tbody td {{ padding: 12px 20px; font-size: 14px; }}
            tbody tr:nth-child(odd) td {{ background-color: #ffffff; color: #333; }}
            tbody tr:nth-child(even) td {{ background-color: #c8c8c8; color: #333; }}
            .highlight {{ background-color: #c8c8c8; color: white; padding: 2px 8px; }}
        </style>
</head>
    <body>
        <h1>ESP with BME280</h1>
        <table>
            <thead>
                <tr><th>MEASUREMENT</th><th>VALUE</th></tr>
            </thead>
<tbody>
                <tr><td>Temp. Celsius</td><td><span class="highlight">{}</span></td></tr>
                <tr><td>Pressure</td><td><span class="highlight">{}</span></td></tr>
                <tr><td>Humidity</td><td><span class="highlight">{}</span></td></tr>
            </tbody>        </table>    </body>
    </html>""".format(temp, pres, hum)
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