---
id: "6d45ce3e-dec9-4827-9955-497a7420f4a2"
title: "Tion   Ensure Counters Have"
type: vault_note
vault: wiki
created: 2026-05-17
updated: 2026-05-17
checksum: "sha256:853ef2779f69f09e"
source: heimdall/auto
---

# Tion   Ensure Counters Have

- tion`
   - Ensure counters have reset conditions
   - Verify interlocks prevent unsafe states
   - Check that each output (Y###) is only used once

5. **Add Explanatory Comments**
   - Explain the purpose of each rung
   - Describe the overall system behavior
   - Note any special considerations or safety features

### Example: Creating a Start/Stop Circuit

**Requirement**: Start button starts motor, stop button stops motor.

**Step 1: Identify I/O**
- Start button: X103 (normally open, per lab standard)
- Stop button: X110 (normally closed, E-STOP per lab standard)
- Motor: Y120 (output, per lab standard)

**Step 2: Design logic**
- Need latching circuit
- Stop button should break the latch

**Step 3: Draft diagram**
```
Rung 0:
|--[X103]--------+-------------------(R1)--|
| --[R1]--[/X110]--+

Rung 1:
|--[R1]--------(Y120)--
```

**Step 4: Verify**
- Pressing X103 (start) energizes R1
- R1 latches through its own contact and the NOT X110 contact
- R1 controls Y120 (motor)
- Pressing X110 (stop/E-STOP) opens [/X110], breaking the latch

**Step 5: Add comments**
- Explain latching behavior
- Note safety feature (stop button is normally closed)

## Best Practices

1. **Use standard I/O addresses**: Reference [[EGE351 Automatino Systems & Control/Lab procedures|Lab Procedures]] for standard assignments (X103 for PB1, X110 for E-STOP, etc.)
2. **Keep rungs simple**: Each rung should have a clear, single purpose
3. <!-- id:6d45ce3e-dec9-4827-9955-497a7420f4a2 ts:2026-05-17 07:49 -->
- tion`
   - Ensure counters have reset conditions
   - Verify interlocks prevent unsafe states
   - Check that each output (Y###) is only used once

5. **Add Explanatory Comments**
   - Explain the purpose of each rung
   - Describe the overall system behavior
   - Note any special considerations or safety features

### Example: Creating a Start/Stop Circuit

**Requirement**: Start button starts motor, stop button stops motor.

**Step 1: Identify I/O**
- Start button: X103 (normally open, per lab standard)
- Stop button: X110 (normally closed, E-STOP per lab standard)
- Motor: Y120 (output, per lab standard)

**Step 2: Design logic**
- Need latching circuit
- Stop button should break the latch

**Step 3: Draft diagram**
```
Rung 0:
|--[X103]--------+-------------------(R1)--|
| --[R1]--[/X110]--+

Rung 1:
|--[R1]--------(Y120)--
```

**Step 4: Verify**
- Pressing X103 (start) energizes R1
- R1 latches through its own contact and the NOT X110 contact
- R1 controls Y120 (motor)
- Pressing X110 (stop/E-STOP) opens [/X110], breaking the latch

**Step 5: Add comments**
- Explain latching behavior
- Note safety feature (stop button is normally closed)

## Best Practices

1. **Use standard I/O addresses**: Reference [[EGE351 Automatino Systems & Control/Lab procedures|Lab Procedures]] for standard assignments (X103 for PB1, X110 for E-STOP, etc.)
2. **Keep rungs simple**: Each rung should have a clear, single purpose
3. <!-- id:6d45ce3e-dec9-4827-9955-497a7420f4a2 ts:2026-05-17 07:49 -->
