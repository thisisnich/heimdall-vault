---
id: "fead77b8-03b0-42c8-a47f-53bb05e7b9b5"
title: "G And Delay Functions"
type: vault_note
vault: wiki
created: 2026-05-17
updated: 2026-05-17
checksum: "sha256:f8f597ab4b01c8dc"
source: heimdall/auto
---

# G And Delay Functions

- g and delay functions.
- **`sleep(seconds)`**: Delay in seconds
- **`sleep_ms(milliseconds)`**: Delay in milliseconds

## Programming Patterns

### 1. Digital I/O Control

#### Basic LED Blink
```python
from machine import Pin
from time import sleep

led = Pin(2, Pin.OUT)  # Onboard LED on GPIO2

while True:
    led.value(1)        # Turn ON
    sleep(0.5)
    led.value(0)        # Turn OFF
    sleep(0.5)
```

#### Multiple LEDs
```python
from machine import Pin
from time import sleep

led1 = Pin(2, Pin.OUT)
led2 = Pin(5, Pin.OUT)

while True:
    led1.value(1)
    led2.value(0)
    sleep(1)
    led1.value(0)
    led2.value(1)
    sleep(1)
```

### 2. Digital Input with Buttons

#### Basic Button Reading
```python
from machine import Pin

button = Pin(15, Pin.IN, Pin.PULL_UP)

while True:
    if not button.value():
        print("Button pressed!")
```

#### Debounced Button Detection
```python
from machine import Pin
from time import sleep

button = Pin(15, Pin.IN, Pin.PULL_UP)

while True:
    first = button.value()
    sleep(0.01)  # Debounce delay
    second = button.value()
    
    if first and not second:
        print("Button pressed!")
    elif not first and second:
        print("Button released!")
```

#### LED Toggle with Button
```python
from machine import Pin
from time import sleep

button = Pin(15, Pin.IN, Pin.PULL_UP)
led = Pin(5, Pin.OUT)

while True:
    first = button.value()
    sleep(0.01)
    second = button.value()
    
    if first and not second: <!-- id:fead77b8-03b0-42c8-a47f-53bb05e7b9b5 ts:2026-05-17 07:49 -->
- g and delay functions.
- **`sleep(seconds)`**: Delay in seconds
- **`sleep_ms(milliseconds)`**: Delay in milliseconds

## Programming Patterns

### 1. Digital I/O Control

#### Basic LED Blink
```python
from machine import Pin
from time import sleep

led = Pin(2, Pin.OUT)  # Onboard LED on GPIO2

while True:
    led.value(1)        # Turn ON
    sleep(0.5)
    led.value(0)        # Turn OFF
    sleep(0.5)
```

#### Multiple LEDs
```python
from machine import Pin
from time import sleep

led1 = Pin(2, Pin.OUT)
led2 = Pin(5, Pin.OUT)

while True:
    led1.value(1)
    led2.value(0)
    sleep(1)
    led1.value(0)
    led2.value(1)
    sleep(1)
```

### 2. Digital Input with Buttons

#### Basic Button Reading
```python
from machine import Pin

button = Pin(15, Pin.IN, Pin.PULL_UP)

while True:
    if not button.value():
        print("Button pressed!")
```

#### Debounced Button Detection
```python
from machine import Pin
from time import sleep

button = Pin(15, Pin.IN, Pin.PULL_UP)

while True:
    first = button.value()
    sleep(0.01)  # Debounce delay
    second = button.value()
    
    if first and not second:
        print("Button pressed!")
    elif not first and second:
        print("Button released!")
```

#### LED Toggle with Button
```python
from machine import Pin
from time import sleep

button = Pin(15, Pin.IN, Pin.PULL_UP)
led = Pin(5, Pin.OUT)

while True:
    first = button.value()
    sleep(0.01)
    second = button.value()
    
    if first and not second: <!-- id:fead77b8-03b0-42c8-a47f-53bb05e7b9b5 ts:2026-05-17 07:49 -->
