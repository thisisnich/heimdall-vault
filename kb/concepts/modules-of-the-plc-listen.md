---
id: "049d43fc-e269-4f3b-9c48-7441ec189025"
title: "Modules Of The Plc Listen"
type: vault_note
vault: wiki
created: 2026-05-17
updated: 2026-05-17
checksum: "sha256:df727296518b4a63"
source: heimdall/auto
---

# Modules Of The Plc Listen

- Modules of the PLC

Listen to the lecturer's presentation on the key features of the programmable logic controller (PLC) and the input/output devices. Take note how to start the PLC software.

### PLC

The PLC is made of the following modules:

- Power supply (AC to DC)
- CPU
- Input module
- Output module
- Analog module (not used now)

---

## b) Understand How to Get the Address of Input/Output Devices

### Addressing Scheme of Input Module

Whenever an input device is activated, a small indicator lights up on the input module which allows you to know the address of that input device. **"X" represents input.**

**AFP7X32D2 / X32D2**

> Address range on module: X100 (top-left) → X107 (top-right) → X110 (bottom-left) → X11F (bottom-right)

**Task:** Find the address of all the input devices and record in the table below.

---

### Addressing Scheme of Output Module

Write the program below in the PLC and note what happens.

```
     X103                                                        Y120
|-----||----------------------------------------------------------( )
     Input                                                      Output
```

Whenever the input device **X103** (a normally-open pushbutton) is activated, the ladder program (or PLC program) activates the output **Y120** which is an LED. At the same time a small indicator lights up on the output module which allows you to know the address of that output device. <!-- id:049d43fc-e269-4f3b-9c48-7441ec189025 ts:2026-05-17 07:49 -->
- Modules of the PLC

Listen to the lecturer's presentation on the key features of the programmable logic controller (PLC) and the input/output devices. Take note how to start the PLC software.

### PLC

The PLC is made of the following modules:

- Power supply (AC to DC)
- CPU
- Input module
- Output module
- Analog module (not used now)

---

## b) Understand How to Get the Address of Input/Output Devices

### Addressing Scheme of Input Module

Whenever an input device is activated, a small indicator lights up on the input module which allows you to know the address of that input device. **"X" represents input.**

**AFP7X32D2 / X32D2**

> Address range on module: X100 (top-left) → X107 (top-right) → X110 (bottom-left) → X11F (bottom-right)

**Task:** Find the address of all the input devices and record in the table below.

---

### Addressing Scheme of Output Module

Write the program below in the PLC and note what happens.

```
     X103                                                        Y120
|-----||----------------------------------------------------------( )
     Input                                                      Output
```

Whenever the input device **X103** (a normally-open pushbutton) is activated, the ladder program (or PLC program) activates the output **Y120** which is an LED. At the same time a small indicator lights up on the output module which allows you to know the address of that output device. <!-- id:049d43fc-e269-4f3b-9c48-7441ec189025 ts:2026-05-17 07:49 -->
