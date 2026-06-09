        # EGE322 Assignment 3 — ESP32 → ThingsBoard MQTT
        # Copy to ESP32 as main.py. WiFi is handled by boot.py (do not duplicate here).
        #
        # IMPORTANT: Save to ESP32 main.py and soft reboot (Ctrl+D).
        # Do NOT use Thonny "Run" (F5) — that skips boot.py and causes OSError -202.
        #
        # Wiring (same as Lab 7):
        #   DHT22 VDD → 3.3V, DATA → GPIO 15, GND → GND
        #   OLED (optional): SDA → GPIO 21, SCL → GPIO 22

        import json
        import time
        import network
        import dht
        from machine import Pin, I2C
        from umqtt.robust import MQTTClient

        try:
            from ssd1306 import SSD1306_I2C
            oled = SSD1306_I2C(128, 64, I2C(scl=Pin(22), sda=Pin(21)), 0x3C)
            HAS_OLED = True
        except Exception:
            HAS_OLED = False

        # Paste from ThingsBoard → Device → Copy access token
        ACCESS_TOKEN = b"PASTE_DEVICE_ACCESS_TOKEN_HERE"

        BROKER = "mqtt.thingsboard.cloud"
        PORT = 1883
        TOPIC = b"v1/devices/me/telemetry"
        PUBLISH_EVERY_S = 2


        def wait_for_wifi(timeout_s=20):
            """boot.py should connect WiFi; this guards editor runs and slow DHCP."""
            wlan = network.WLAN(network.STA_IF)
            if not wlan.active():
                wlan.active(True)
            if wlan.isconnected():
                print("WiFi OK:", wlan.ifconfig()[0])
                time.sleep(1)  # let DNS settle
                return
            print("WiFi not ready — waiting (use Ctrl+D reboot if this hangs)...")
            while timeout_s > 0 and not wlan.isconnected():
                time.sleep(1)
                timeout_s -= 1
            if not wlan.isconnected():
                raise OSError("WiFi not connected — fix boot.py, then Ctrl+D reboot")
            print("WiFi OK:", wlan.ifconfig()[0])
            time.sleep(1)


        def connect_mqtt():
            client = MQTTClient(
                client_id=b"esp32_thingsboard",
                server=BROKER,
                port=PORT,
                user=ACCESS_TOKEN,
                password=b"",
                keepalive=60,
                ssl=False,
            )
            for attempt in range(5):
                try:
                    client.connect()
                    print("ThingsBoard MQTT connected")
                    return client
                except OSError as e:
                    print("MQTT connect failed (attempt %d): %s" % (attempt + 1, e))
                    time.sleep(3)
            raise OSError("MQTT connect failed after retries — check token and network")


        wait_for_wifi()
        sensor = dht.DHT22(Pin(15))
        client = connect_mqtt()

        counter = 0


        def read_dht22():
            sensor.measure()
            return sensor.temperature(), sensor.humidity()


        def show_oled(c, t, h):
            if not HAS_OLED:
                return
            oled.fill(0)
            oled.text("ThingsBoard", 0, 0)
            oled.text("Cnt: %d" % c, 0, 16)
            oled.text("T: %.1f C" % t, 0, 32)
            oled.text("H: %.1f %%" % h, 0, 48)
            oled.show()


        while True:
            if counter > 100:
                counter = 0

            try:
                temp, hum = read_dht22()
                payload = json.dumps({
                    "counter": counter,
                    "temperature": round(temp, 1),
                    "humidity": round(hum, 1),
                })
                client.publish(TOPIC, payload, qos=1)
                print("Published:", payload)
                show_oled(counter, temp, hum)
            except OSError as e:
                print("Publish/DHT error:", e)
                try:
                    client.disconnect()
                except Exception:
                    pass
                client = connect_mqtt()
                payload = json.dumps({"counter": counter})
                client.publish(TOPIC, payload, qos=1)
                print("Published counter only:", payload)

            counter += 10
            time.sleep(PUBLISH_EVERY_S)
