from machine import Pin, I2C
from time import sleep
import dht
import ssd1306

# DHT22 data pin is connected to GPIO5
sensor = dht.DHT22(Pin(5))

# OLED: SDA = GPIO21, SCL = GPIO26
i2c = I2C(0, scl=Pin(26), sda=Pin(21))
oled = ssd1306.SSD1306_I2C(128, 64, i2c)

while True:
    try:
        sensor.measure()

        temp = sensor.temperature()
        hum = sensor.humidity()

        print("Temp: %.2f C" % temp)
        print("Humidity: %.2f %%" % hum)

        oled.fill(0)
        oled.text("DHT22 Sensor", 0, 0)
        oled.text("Temp: %.2f C" % temp, 0, 20)
        oled.text("Hum: %.2f %%" % hum, 0, 40)
        oled.show()

        sleep(3)

    except OSError:
        print("Failed to read sensor")
        oled.fill(0)
        oled.text("Sensor Error", 0, 20)
        oled.show()
        sleep(3)