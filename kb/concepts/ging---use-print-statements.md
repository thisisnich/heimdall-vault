---
id: "98faa58c-6cee-4ef6-9b68-6eb3b0248e64"
title: "Ging   Use Print Statements"
type: vault_note
vault: wiki
created: 2026-05-17
updated: 2026-05-17
checksum: "sha256:590a1f18b798ecae"
source: heimdall/auto
---

# Ging   Use Print Statements

- ging
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

### 1. <!-- id:98faa58c-6cee-4ef6-9b68-6eb3b0248e64 ts:2026-05-17 07:49 -->
- ging
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

### 1. <!-- id:98faa58c-6cee-4ef6-9b68-6eb3b0248e64 ts:2026-05-17 07:49 -->
