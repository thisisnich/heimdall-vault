---
id: "cdb772f0-4f41-4ab0-bde7-7b02869a381f"
title: "R Are Needed For Intermediate"
type: vault_note
vault: wiki
created: 2026-05-17
updated: 2026-05-17
checksum: "sha256:e1d4d80a5ac34c21"
source: heimdall/auto
---

# R Are Needed For Intermediate

- R) are needed for intermediate logic
   - Check [[EGE351 Automatino Systems & Control/Lab procedures|Lab Procedures]] for standard I/O assignments

2. **Design the Logic Flow**
   - Determine the sequence of operations
   - Identify conditions that must be met
   - Plan for safety interlocks
   - Consider timing requirements (use appropriate timer type)
   - Determine if counting is needed

3. **Draft Each Rung**
   - Start with the left power rail `|--`
   - Add input conditions in series (AND logic) or parallel (OR logic)
   - Add branches using `+` and `|` markers
   - For timers: Use `[TMxz, Uy]` format
   - For counters: Use two-line format with `[CTx]` on top, `[Uy]` on bottom
   - End with the output coil `(ADDRESS)` or right rail `--|`

4. **Verify the Diagram**
   - Trace logic from left to right
   - Check that all conditions are satisfied for outputs
   - Ensure timers use correct resolution (TMR/TMX/TMY/TML)
   - Calculate SV values: `SV = Desired Time ÷ Timer Resolution`
   - Ensure counters have reset conditions
   - Verify interlocks prevent unsafe states
   - Check that each output (Y###) is only used once

5. <!-- id:cdb772f0-4f41-4ab0-bde7-7b02869a381f ts:2026-05-17 07:49 -->
- R) are needed for intermediate logic
   - Check [[EGE351 Automatino Systems & Control/Lab procedures|Lab Procedures]] for standard I/O assignments

2. **Design the Logic Flow**
   - Determine the sequence of operations
   - Identify conditions that must be met
   - Plan for safety interlocks
   - Consider timing requirements (use appropriate timer type)
   - Determine if counting is needed

3. **Draft Each Rung**
   - Start with the left power rail `|--`
   - Add input conditions in series (AND logic) or parallel (OR logic)
   - Add branches using `+` and `|` markers
   - For timers: Use `[TMxz, Uy]` format
   - For counters: Use two-line format with `[CTx]` on top, `[Uy]` on bottom
   - End with the output coil `(ADDRESS)` or right rail `--|`

4. **Verify the Diagram**
   - Trace logic from left to right
   - Check that all conditions are satisfied for outputs
   - Ensure timers use correct resolution (TMR/TMX/TMY/TML)
   - Calculate SV values: `SV = Desired Time ÷ Timer Resolution`
   - Ensure counters have reset conditions
   - Verify interlocks prevent unsafe states
   - Check that each output (Y###) is only used once

5. <!-- id:cdb772f0-4f41-4ab0-bde7-7b02869a381f ts:2026-05-17 07:49 -->
