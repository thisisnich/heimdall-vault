---
tags:
  - EGE322
  - ESP32
  - programming
  - MicroPython
  - guide
  - IoT
  - reference
course: EGE322 IoT System Project
topic: ESP32 Programming Guide
source: NYPY3 Import
created: 2026-05-17
type: Guide
status: Completed
---

> 📚 **Related:** [[NYPY3 - Main Index|NYPY3 Index]] | [[03-RESOURCES/EGE322-IOT-System-Project/EGE322 Lab 1- MicroPython Programming v2026b.md|Lab 1]] | [[📅 Schedule & Assessments Dashboard|Assessment Dashboard]]

# ESP32 Programming Guide - EGE322 IoT System Project

## Overview

This document describes the programming approach, libraries, and tools used to develop ESP32 applications in the EGE322 IoT System Project course at Nanyang Polytechnic.

## Hardware Platform

### ESP32-WROOM-32 Module
- **Manufacturer**: Espressif Systems
- **Architecture**: Dual-core 32-bit Tensilica Xtensa LX6 microprocessor
- **Clock Speed**: Up to 240MHz
- **Integrated Features**: Wi-Fi, Bluetooth, BLE
- **Power Modes**: Multiple power-saving modes

### Key Specifications
- **ADC**: Up to 18 × 12-bit analog-to-digital converters
- **DAC**: 2 × 8-bit digital-to-analog converters
- **Touch**: 10 capacitive touch-sensor inputs
- **Communication**: 
  - 4 SPI bus channels
  - 2 I2C bus connections
  - 2 I2S bus connections
  - 2 UARTs
  - SD card host controller
- **PWM**: Up to 16 PWM channels
- **Sensors**: Integrated Hall-effect sensor, ultra low-power analog preamp
- **RTC**: Multiple Real Time Clocks
- **IR**: IR remote controller (up to 8 channels)

### Development Board
- **ESP32 DEVKIT** board with ESP-WROOM-32 chip
- **Power**: USB port or 5V supply pin with on-board 3.3V regulator
- **Controls**: BOOT button for soft-reboot, Enable button for reset
- **LEDs**: Power LED (Red), User LED (Blue - GPIO2)
- **USB Interface**: CP2102 USB-UART Bridge IC

## Programming Environment

### Primary Language: MicroPython
The course uses **MicroPython** as the primary programming language for ESP32 development.

### Development Tools

#### 1. Thonny IDE
- **Download**: https://thonny.org/
- **Purpose**: Primary IDE for MicroPython development
- **Features**:
  - Code creation and management
  - Debugging capabilities
  - MicroPython firmware flashing
  - REPL (Read-Eval-Print Loop) interface

#### 2. Essential Setup Steps
1. Install Thonny IDE
2. Connect ESP32 via USB
3. Install CP210X VCP USB Driver if needed
4. Flash MicroPython firmware via Thonny
5. Configure interpreter to correct COM port

## Core Libraries and Modules

### 1. `machine` Module
The fundamental module for hardware control in MicroPython.

#### Key Classes:
- **`Pin`**: Digital I/O pin control
- **`ADC`**: Analog-to-digital conversion
- **`PWM`**: Pulse-width modulation
- **`UART`**: Serial communication
- **`I2C`**: I2C bus communication
- **`SPI`**: SPI bus communication

### 2. `time` Module
Timing and delay functions.
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

### 1. Pin Management
- Always configure pins with appropriate modes
- Use pull-up/pull-down resistors for inputs
- Check pin conflicts before assigning multiple functions

### 2. Timing and Delays
- Use appropriate sleep functions to avoid blocking
- Consider using non-blocking approaches for complex applications

### 3. Error Handling
- Implement try-except blocks for robust code
- Handle hardware-specific errors gracefully

### 4. Code Organization
- Use classes for reusable components
- Separate hardware configuration from application logic
- Comment pin assignments and hardware connections

## Common Issues and Solutions

### 1. Firmware Flashing Problems
- Hold BOOT button during flashing
- Try different COM ports
- Restart computer if issues persist

### 2. Pin Conflicts
- Not all pins can be used simultaneously
- Some pins have special boot behaviors
- Check board-specific pinouts

### 3. ADC Reading Issues
- Ensure proper voltage range (0-3.3V)
- Set appropriate attenuation
- Calibrate sensors for accurate readings

### 4. PWM Timing
- Different frequencies for different applications
- Servo motors typically need 50Hz
- LEDs can use higher frequencies for smoother fading

## Advanced Topics (Future Learning)

### 1. Wireless Communication
- Wi-Fi connectivity
- Bluetooth/BLE communication
- MQTT protocol for IoT applications

### 2. Sensor Integration
- I2C sensors (temperature, humidity, pressure)
- SPI displays and sensors
- Complex sensor arrays

### 3. Real-time Applications
- Multi-tasking with dual-core architecture
- Interrupt handling
- Low-power optimization

## Summary

The EGE322 IoT System Project teaches ESP32 programming using:
- **Language**: MicroPython
- **IDE**: Thonny
- **Core Libraries**: `machine`, `time`
- **Programming Focus**: GPIO control, ADC reading, PWM control, sensor integration
- **Hardware**: ESP32-WROOM-32 development board
- **Methodology**: Hands-on laboratory exercises with real-world applications

This approach provides students with practical embedded systems programming skills essential for IoT development while maintaining accessibility through Python's beginner-friendly syntax.
