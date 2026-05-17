---
tags:
  - EGE320
  - tutorial
  - embedded-systems
  - microcontroller
  - peripherals
  - tutorial-1
  - development-tools
course: EGE320 Embedded System Design and Technology
topic: Tutorial 1 - Embedded system definition, peripherals and development tools
source: EGE320 - Tutorial1.pdf
converted: 2026-04-23
type: Tutorial
status: Completed
source: NYPY3 Import
---

> 📚 **Related:** [[NYPY3 - Main Index|NYPY3 Index]] | [[03-RESOURCES/EGE320-Embedded-System-Design/EGE320-Chapter1.md|Chapter 1]] | [[📅 Schedule & Assessments Dashboard|Assessment Dashboard]]

> 📚 **Related:** [[NYPY3 - Main Index|NYPY3 Index]] | [[03-RESOURCES/EGE320-Embedded-System-Design/EGE320-Chapter1.md|Chapter 1]] | [[📅 Schedule & Assessments Dashboard|Assessment Dashboard]]

> 📚 **Related:** [[NYPY3 - Main Index|NYPY3 Index]] | [[03-RESOURCES/EGE320-Embedded-System-Design/ch0.md|Chapter 0]] | [[📅 Schedule & Assessments Dashboard|Assessment Dashboard]]

# Tutorial 1: Embedded System Definition, Peripherals and Development Tools

## Objectives
- Define embedded system
- Identify different types of microcontroller and peripherals in embedded system
- Identify the tools for embedded system development

---

## Questions

**1. What is an embedded system?**
- A. Processor-based system with HW+SW designed to perform *generic* tasks with limited resources.
- B. Processor-based system with HW only, designed to perform *specific* tasks with limited resources.
- C. Processor-based system with HW+SW designed to perform specific tasks with *unlimited* resources.
- D. Processor-based system with HW+SW designed to perform specific tasks with limited resources.

> ✅ **Answer: D**

---

**2. Which of the following is NOT a peripheral in the processor?**
- A. `GPIO`
- B. `ADC`
- C. Connector
- D. `SPI`

> ✅ **Answer: C** — A Connector is a physical interface component, not an on-chip peripheral.

---

**3. What is the MAIN role of a processor in an embedded system?**
- A. Stores data and program.
- B. Communicates with another processor.
- C. Processes data and instructions.
- D. Captures and converts sensor data.

> ✅ **Answer: C**

---

**4. Which of the following is a type of processor?**
- A. `PWM` and Comparator
- B. **MPU** and **MCU**
- C. `ADC` and `DAC`
- D. `SPI` and `I2C`

> ✅ **Answer: B** — MPU (Microprocessor Unit) and MCU (Microcontroller Unit) are processor types. The others are peripherals.

---

**5. Which of the following is NOT supposed to be connected to a digital input of a microcontroller?**
- A. Switch
- B. Push button
- C. Digital output of a sensor
- D. LED

> ✅ **Answer: D** — An LED is an output device; it should be connected to a digital *output*, not an input.

---

**6. Which peripheral is commonly used to generate audible tones through a buzzer?**
- A. `ADC`
- B. Comparator
- C. `PWM`
- D. `GPIO`

> ✅ **Answer: C** — PWM (Pulse Width Modulation) generates variable-frequency signals used to drive buzzers.

---

**7. Which of the following is NOT a serial interface?**  (this on i didnt know)
- A. `UART`
- B. `ADC`
- C. `SPI`
- D. `I2C`

> ✅ **Answer: B** — ADC is a signal conversion peripheral, not a serial communication interface.

---

**8. Which peripheral CAN be used to provide accurate clock timing to the processor?**
- A. `GPIO`
- B. `ADC`
- C. Real Time Clock (`RTC`)
- D. `UART`

> ✅ **Answer: C**
> -> RTC is usually external, but can be internal/embedded.  e.g. RTC on mobo -> battery supplies it seperately



---

**9. What is the purpose of a debug probe in embedded system development?**
- A. To probe, trace and control the target processor.
- B. To convert assembly language into a pattern of bits.
- C. To link one or more object files into a single executable file.
- D. To translate a high-level programming language to a lower level language.

> ✅ **Answer: A**

---

**10. An IDE (Integrated Development Environment) comprises the following EXCEPT:**
- A. Editor
- B. Assembler
- C. Compiler
- D. Calculator

> ✅ **Answer: D** — An IDE contains an editor, assembler, compiler, and debugger — not a calculator.

---

## Quick Reference — Key Terms

| Term | Description |
|------|-------------|
| **MCU** | Microcontroller Unit — processor + peripherals on one chip |
| **MPU** | Microprocessor Unit — processor only, needs external peripherals |
| `GPIO` | General Purpose I/O — digital pins for switches, LEDs |
| `ADC` | Analogue-to-Digital Converter — reads analogue sensor values |
| `DAC` | Digital-to-Analogue Converter — outputs analogue signals |
| `PWM` | Pulse Width Modulation — variable duty cycle, drives buzzers/motors |
| `UART` | Universal Async Receiver/Transmitter — serial comms |
| `SPI` | Serial Peripheral Interface — synchronous serial comms |
| `I2C` | Inter-Integrated Circuit — 2-wire serial bus |
| `RTC` | Real Time Clock — accurate timekeeping peripheral |
| **IDE** | Integrated Development Environment — editor + compiler + debugger |
| **Debug Probe** | Hardware tool to probe, trace and control target processor |

