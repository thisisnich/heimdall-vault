---
id: "10ad7b8e-0281-49de-9f39-48b7c39fac42"
title: "Esp32 Programming Guide"
type: vault_note
vault: wiki
created: 2026-05-17
updated: 2026-05-17
checksum: "sha256:4510d4d2704f8a3a"
source: heimdall/auto
---

# Esp32 Programming Guide

- # ESP32 Programming Guide - EGE322 IoT System Project

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
The course uses **MicroPython** as the primary programming language for ESP32 development. <!-- id:10ad7b8e-0281-49de-9f39-48b7c39fac42 ts:2026-05-17 07:49 -->
- # ESP32 Programming Guide - EGE322 IoT System Project

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
The course uses **MicroPython** as the primary programming language for ESP32 development. <!-- id:10ad7b8e-0281-49de-9f39-48b7c39fac42 ts:2026-05-17 07:49 -->
