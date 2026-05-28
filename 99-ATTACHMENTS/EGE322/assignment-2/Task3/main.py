import socket
from machine import Pin

led1 = Pin(2, Pin.OUT)
led2 = Pin(4, Pin.OUT)

def web_page():
    led1_state = "ON" if led1.value() == 1 else "OFF"
    led2_state = "ON" if led2.value() == 1 else "OFF"

    html = """<html>
    <head>
        <title>ESP Web Server</title>
        <meta name="viewport" content="width=device-width, initial-scale=1">
        <style>
            body {{ font-family: Arial, sans-serif; text-align: center; background: white; }}
            h1 {{ color: #0F3376; padding: 2vh; }}
            p {{ font-size: 1.2rem; }}
            .button {{ display: inline-block; background-color: #e7bd3b; border: none;
                border-radius: 4px; color: white; padding: 16px 40px;
                text-decoration: none; font-size: 30px; margin: 2px; cursor: pointer; }}
            .button2 {{ background-color: #4286f4; }}
        </style>
    </head>
    <body>
        <h1>ESP Web Server</h1>

        <p>LED1 state: <strong>{}</strong></p>
        <p><a href="/?led1=on"><button class="button">ON</button></a></p>
        <p><a href="/?led1=off"><button class="button button2">OFF</button></a></p>

        <hr>

        <p>LED2 state: <strong>{}</strong></p>
        <p><a href="/?led2=on"><button class="button">ON</button></a></p>
        <p><a href="/?led2=off"><button class="button button2">OFF</button></a></p>
    </body>
    </html>""".format(led1_state, led2_state)
    return html

s = socket.socket(socket.AF_INET, socket.SOCK_STREAM)
s.setsockopt(socket.SOL_SOCKET, socket.SO_REUSEADDR, 1)
s.bind(('', 80))
s.listen(5)
print('Web server running on port 80')

while True:
    try:
        conn, addr = s.accept()
        print('Got a connection from %s' % str(addr))
        request = conn.recv(1024)
        request = str(request)
        print('Content = %s' % request)

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
        conn.sendall(response)
        conn.close()
    except OSError as e:
        conn.close()
        print('Connection closed')
