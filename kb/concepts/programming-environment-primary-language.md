---
id: "d433bf18-53bd-4994-9ffe-1ae90f8e6fdb"
title: "Programming Environment Primary Language"
type: vault_note
vault: wiki
created: 2026-05-17
updated: 2026-05-17
checksum: "sha256:453893a9b6b5ff32"
source: heimdall/auto
---

# Programming Environment Primary Language

- Programming Environment

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

### 1. <!-- id:d433bf18-53bd-4994-9ffe-1ae90f8e6fdb ts:2026-05-17 07:49 -->
- Programming Environment

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

### 1. <!-- id:d433bf18-53bd-4994-9ffe-1ae90f8e6fdb ts:2026-05-17 07:49 -->
