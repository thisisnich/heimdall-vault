---
id: "588e39da-445e-4887-bfde-bbeb50e0bfb2"
title: "Ert To Light Percentage Example"
type: vault_note
vault: wiki
created: 2026-05-17
updated: 2026-05-17
checksum: "sha256:9fa25a73a7a8d815"
source: heimdall/auto
---

# Ert To Light Percentage Example

- ert to light percentage (example calculation)
    light_percentage = (raw_value - 40) * (10/86)
    print(light_percentage)
    sleep(0.1)
```

### 4. Pulse-Width Modulation (PWM)

#### LED Fading
```python
from machine import Pin, PWM
import time

led = PWM(Pin(23))  # LED on GPIO23
led.freq(1000)      # 1kHz frequency

while True:
    # Fade up
    for duty_cycle in range(0, 1024):
        led.duty(duty_cycle)
        time.sleep_ms(2)
    
    # Fade down
    for duty_cycle in range(1023, -1, -1):
        led.duty(duty_cycle)
        time.sleep_ms(2)
```

#### Servo Motor Control
```python
from machine import Pin, PWM
import time

servo = PWM(Pin(23), freq=50)  # 50Hz for servo

# Position servo at different angles
servo.duty(20)   # ~0 degrees
time.sleep(1)
servo.duty(70)   # ~90 degrees
time.sleep(1)
servo.duty(120)  # ~180 degrees
time.sleep(1)
```

#### Advanced Servo Control Function
```python
from machine import Pin, PWM
import time

def set_servo_angle(servo_pwm, angle):
    """
    Set servo angle (-90 to 90 degrees)
    """
    duty = int(((angle + 90) * 2/180 + 0.5) / 20 * 1023)
    servo_pwm.duty(duty)

servo = PWM(Pin(23), freq=50, duty=0)

# Test different angles
for angle in [-90, -45, 0, 45, 90]:
    set_servo_angle(servo, angle)
    time.sleep(1)
```

## Object-Oriented Programming

### Class-based LDR Sensor
```python
from machine import Pin, ADC
import time

class LDR:
    def __init__(self, pin):
        self.ldr_pin = ADC(Pin(pin))
        self.ldr_pin.a <!-- id:588e39da-445e-4887-bfde-bbeb50e0bfb2 ts:2026-05-17 07:49 -->
- ert to light percentage (example calculation)
    light_percentage = (raw_value - 40) * (10/86)
    print(light_percentage)
    sleep(0.1)
```

### 4. Pulse-Width Modulation (PWM)

#### LED Fading
```python
from machine import Pin, PWM
import time

led = PWM(Pin(23))  # LED on GPIO23
led.freq(1000)      # 1kHz frequency

while True:
    # Fade up
    for duty_cycle in range(0, 1024):
        led.duty(duty_cycle)
        time.sleep_ms(2)
    
    # Fade down
    for duty_cycle in range(1023, -1, -1):
        led.duty(duty_cycle)
        time.sleep_ms(2)
```

#### Servo Motor Control
```python
from machine import Pin, PWM
import time

servo = PWM(Pin(23), freq=50)  # 50Hz for servo

# Position servo at different angles
servo.duty(20)   # ~0 degrees
time.sleep(1)
servo.duty(70)   # ~90 degrees
time.sleep(1)
servo.duty(120)  # ~180 degrees
time.sleep(1)
```

#### Advanced Servo Control Function
```python
from machine import Pin, PWM
import time

def set_servo_angle(servo_pwm, angle):
    """
    Set servo angle (-90 to 90 degrees)
    """
    duty = int(((angle + 90) * 2/180 + 0.5) / 20 * 1023)
    servo_pwm.duty(duty)

servo = PWM(Pin(23), freq=50, duty=0)

# Test different angles
for angle in [-90, -45, 0, 45, 90]:
    set_servo_angle(servo, angle)
    time.sleep(1)
```

## Object-Oriented Programming

### Class-based LDR Sensor
```python
from machine import Pin, ADC
import time

class LDR:
    def __init__(self, pin):
        self.ldr_pin = ADC(Pin(pin))
        self.ldr_pin.a <!-- id:588e39da-445e-4887-bfde-bbeb50e0bfb2 ts:2026-05-17 07:49 -->
