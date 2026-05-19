---
tags:
  - EGE320
  - embedded-systems
  - user-interface
  - touch-screen
  - video-lesson
  - input-devices
course: EGE320 Embedded System Design and Technology
topic: Touch Screen Technology
source: YouTube - How The Touch Screen Works
source_url: https://www.youtube.com/watch?v=l-v1uJbzMEo
created: 2026-05-19
type: Video Lesson
status: Completed
---

> 📚 **Related:** [[NYPY3 - Main Index|NYPY3 Index]] | [[03-RESOURCES/EGE320-Embedded-System-Design/EGE320-Chapter1.md|Chapter 1]] | [[📅 Schedule & Assessments Dashboard|Assessment Dashboard]]

> **Video:** [How The Touch Screen Works: The Science Behind This Popular Technology](https://www.youtube.com/watch?v=l-v1uJbzMEo)

---

# How The Touch Screen Works: The Science Behind This Popular Technology

## Video Metadata

- **Runtime:** 8 minutes 46 seconds
- **Channel:** chrvoje_engineering
- **Keywords:** Touch screen, Resistive, Capacitive, Surface Acoustic Wave, Infrared

---

## Overview

Have you ever stopped to think about how the touch screen works? How it's able to respond to your fingertips and translate your gestures into actions on the screen? This video explores the science behind touch screens, from the basic principles of capacitance and resistance to how touch screens detect and interpret your gestures.

---

## Topics Covered

### 1. When Was Touch Screen Invented
- Historical context and development timeline

### 2. What is Touch Screen
- Basic principles and functionality
- How touch screens detect and interpret gestures

### 3. Types of Touch Screens

#### Resistive Touch Screen Technology

**Working Principle:**
- Two electrically conductive layers separated by tiny spacers
- When pressed together, the electrical current changes at the point of contact
- Software identifies the current change and executes the corresponding function
- One layer is consistent, the other is conductive, with a scratch-resistant layer on top

**Applications:**
- ATM machines
- Supermarkets (electronic signature pads)
- Industrial environments

**Pros:**
- Robust and efficient
- Works with any object (finger, stylus, pen)
- Can handle harsh environments

**Cons:**
- Challenging to read due to multiple layers reflecting light
- Only supports single-touch (no multi-touch)
- Requires pressure to activate
- Lower image quality

---

#### Capacitive Touch Screen Technology

**Working Principle:**
- Does not use pressure; detects anything with electrical charge
- Uses human skin (which contains atoms with + and - charges)
- Made from copper or indium tin oxide materials
- Charges stored in electrostatic grid of tiny wires (thinner than human hair)
- When finger touches screen, electrical charge transfers to finger, creating voltage drop
- Software processes voltage drop location to execute action

**Types:**

##### Surface Capacitive Touch Screen

**Working Principle:**
- Sensors around the edges
- Thin, finely divided film around the surface
- When finger touches, charge passes to finger completing circuit
- Creates voltage drop at touch point

##### Projective Capacitive Touch Screen (PCT)

**Working Principle:**
- Grid of columns and rows with distinct sensing chips
- Glass sheet with embedded transparent electrode films
- IC chip develops 3D electrostatic field
- Detects difference in electrical currents when touched
- Supports multi-touch functionality

**Pros:**
- High sensitivity
- Excellent image quality
- Multi-touch support (PCT)
- Works with surgical gloves or thin cotton gloves (PCT)
- Most common in modern smartphones

**Cons:**
- Won't work with regular gloves (unless conductive)
- Won't work with non-conductive objects
- More expensive than resistive

---

#### Surface Acoustic Wave (SAW) Touch Screen Technology

**Working Principle:**
- Transducers mounted on corners of glass panel
- Creates hidden grid of ultrasonic waves on surface
- Sensors receive the waves
- When touched, some waves are absorbed
- Receivers identify touchpoint and send to computer

**Pros:**
- Can be used with finger, gloved hand, or stylus
- Excellent visibility
- High optical clarity
- Prolonged touch life
- Easy to use

**Cons:**
- Cannot be activated with hard objects (pens, credit cards, fingernails)
- Susceptible to false touches from water droplets
- Solid contaminants create non-touch areas until cleaned
- More expensive than other types

---

#### Infrared Touch Screen Technology

**Working Principle:**
- No overlay layer on screen
- Uses light beam interruption technology
- Infrared emitters and receivers create transparent grid of light beams
- When object interrupts beams, sensor detects touch
- Supports multi-touch

**Pros:**
- Best image quality and clarity (no extra layer)
- Multi-touch support
- No pressure required
- Works even if screen is scratched
- Can use objects other than fingers
- Durable

**Cons:**
- Sunlight can affect functionality
- More expensive
- Requires precise alignment of emitters and receivers

---

## Timestamps

| Time | Topic |
|------|-------|
| 00:06 | Introduction |
| 00:24 | When Was Touch Screen Invented |
| 01:35 | What is Touch Screen |
| 02:18 | Types of Touch Screens |
| 02:50 | Resistive Touch Screen Technology |
| 03:56 | Capacitive Touch Screen Technology |
| 04:36 | Surface Capacitive Touch Screen Technology |
| 05:26 | Projective Capacitive Touch Screen Technology |
| 06:23 | Surface Acoustic Wave Touch Screen Technology |
| 07:34 | Infrared Touch Screen Technology |
| 08:27 | Conclusion |

---

## Reference Sources

- [1] Internet of Things
- [2] Touchscreens - https://www.explainthatstuff.com/touchscreens/
- [3] How the iPhone Works - https://electronics.howstuffworks.com/
- [4] How Does A Smartphone Touchscreen Work? - https://smartphonedomain.com/
- [5] What Is a Touchscreen and How Do They Work? - https://www.lifewire.com/

---

## Key Takeaways

- Touch screens use different technologies: resistive, capacitive, surface acoustic wave, and infrared
- Each technology has its own working principle, advantages, and disadvantages
- Capacitive touch screens are most common in modern smartphones due to multi-touch capability
- Understanding touch screen technology is important for embedded system design involving user interfaces
