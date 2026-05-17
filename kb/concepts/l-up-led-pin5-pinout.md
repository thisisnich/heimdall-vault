---
id: "e317e42b-c2f7-4595-b7a4-d9e436b7ae56"
title: "L Up Led Pin5 Pinout"
type: vault_note
vault: wiki
created: 2026-05-17
updated: 2026-05-17
checksum: "sha256:d52de1892f9580d2"
source: heimdall/auto
---

# L Up Led Pin5 Pinout

- L_UP)
led = Pin(5, Pin.OUT)

while True:
    first = button.value()
    sleep(0.01)
    second = button.value()
    
    if first and not second:
        led.value(not led.value())  # Toggle LED
```

### 3. Analog Input (ADC)

#### Potentiometer Reading
```python
from machine import Pin, ADC
from time import sleep

pot = ADC(Pin(34))  # ADC on GPIO34
pot.atten(ADC.ATTN_11DB)  # Full range: 0-3.3V

while True:
    pot_value = pot.read()
    print(pot_value)  # 0-4095 (12-bit)
    sleep(0.1)
```

#### LDR (Light Sensor) Reading
```python
from machine import Pin, ADC
from time import sleep

ldr = ADC(Pin(36))
ldr.atten(ADC.ATTN_11DB)

while True:
    raw_value = ldr.read()
    # Convert to light percentage (example calculation)
    light_percentage = (raw_value - 40) * (10/86)
    print(light_percentage)
    sleep(0.1)
```

### 4. <!-- id:e317e42b-c2f7-4595-b7a4-d9e436b7ae56 ts:2026-05-17 07:49 -->
- L_UP)
led = Pin(5, Pin.OUT)

while True:
    first = button.value()
    sleep(0.01)
    second = button.value()
    
    if first and not second:
        led.value(not led.value())  # Toggle LED
```

### 3. Analog Input (ADC)

#### Potentiometer Reading
```python
from machine import Pin, ADC
from time import sleep

pot = ADC(Pin(34))  # ADC on GPIO34
pot.atten(ADC.ATTN_11DB)  # Full range: 0-3.3V

while True:
    pot_value = pot.read()
    print(pot_value)  # 0-4095 (12-bit)
    sleep(0.1)
```

#### LDR (Light Sensor) Reading
```python
from machine import Pin, ADC
from time import sleep

ldr = ADC(Pin(36))
ldr.atten(ADC.ATTN_11DB)

while True:
    raw_value = ldr.read()
    # Convert to light percentage (example calculation)
    light_percentage = (raw_value - 40) * (10/86)
    print(light_percentage)
    sleep(0.1)
```

### 4. <!-- id:e317e42b-c2f7-4595-b7a4-d9e436b7ae56 ts:2026-05-17 07:49 -->
