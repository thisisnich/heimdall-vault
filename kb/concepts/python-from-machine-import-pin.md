---
id: "290ded3a-4aa8-4f2a-b46b-f03be509ed7b"
title: "Python From Machine Import Pin"
type: vault_note
vault: wiki
created: 2026-05-17
updated: 2026-05-17
checksum: "sha256:9ca2e9487c1e86bc"
source: heimdall/auto
---

# Python From Machine Import Pin

- ``python
from machine import Pin, ADC
import time

class LDR:
    def __init__(self, pin):
        self.ldr_pin = ADC(Pin(pin))
        self.ldr_pin.atten(ADC.ATTN_11DB)
    
    def get_raw_value(self):
        return self.ldr_pin.read()
    
    def get_light_percentage(self):
        return round(self.get_raw_value() / 4095 * 100, 2)

# Usage
ldr = LDR(36)
while True:
    print(f"Light: {ldr.get_light_percentage()}%")
    time.sleep(1)
```

## Available GPIO Pins

### ADC Pins
GPIO pins that support analog input: 0, 2, 4, 12, 13, 14, 15, 25, 26, 27, 32, 33, 34, 35, 36, 39

### PWM Capable Pins
Most GPIO pins support PWM output, but some have limitations:
- GPIO 34-39: Input only (no PWM output)
- Strapping pins may have special behaviors during boot

### Common Pin Assignments
- **GPIO2**: Onboard blue LED
- **GPIO15**: Commonly used for buttons
- **GPIO23**: Often used for PWM/servo control
- **GPIO34-36**: Common for analog sensors

## Development Workflow

### 1. Code Development
- Write code in Thonny IDE
- Test using REPL for quick prototyping
- Save as `.py` files for persistent programs

### 2. Program Execution
- **REPL Mode**: Interactive line-by-line execution
- **Script Mode**: Run complete `.py` files
- **Auto-run**: Save as `main.py` for automatic execution on boot

### 3. Debugging
- Use `print()` statements for debugging
- Thonny's built-in debugger
- Hardware debugging with LEDs and serial output

## Best Practices

### 1. <!-- id:290ded3a-4aa8-4f2a-b46b-f03be509ed7b ts:2026-05-17 07:49 -->
- ``python
from machine import Pin, ADC
import time

class LDR:
    def __init__(self, pin):
        self.ldr_pin = ADC(Pin(pin))
        self.ldr_pin.atten(ADC.ATTN_11DB)
    
    def get_raw_value(self):
        return self.ldr_pin.read()
    
    def get_light_percentage(self):
        return round(self.get_raw_value() / 4095 * 100, 2)

# Usage
ldr = LDR(36)
while True:
    print(f"Light: {ldr.get_light_percentage()}%")
    time.sleep(1)
```

## Available GPIO Pins

### ADC Pins
GPIO pins that support analog input: 0, 2, 4, 12, 13, 14, 15, 25, 26, 27, 32, 33, 34, 35, 36, 39

### PWM Capable Pins
Most GPIO pins support PWM output, but some have limitations:
- GPIO 34-39: Input only (no PWM output)
- Strapping pins may have special behaviors during boot

### Common Pin Assignments
- **GPIO2**: Onboard blue LED
- **GPIO15**: Commonly used for buttons
- **GPIO23**: Often used for PWM/servo control
- **GPIO34-36**: Common for analog sensors

## Development Workflow

### 1. Code Development
- Write code in Thonny IDE
- Test using REPL for quick prototyping
- Save as `.py` files for persistent programs

### 2. Program Execution
- **REPL Mode**: Interactive line-by-line execution
- **Script Mode**: Run complete `.py` files
- **Auto-run**: Save as `main.py` for automatic execution on boot

### 3. Debugging
- Use `print()` statements for debugging
- Thonny's built-in debugger
- Hardware debugging with LEDs and serial output

## Best Practices

### 1. <!-- id:290ded3a-4aa8-4f2a-b46b-f03be509ed7b ts:2026-05-17 07:49 -->
