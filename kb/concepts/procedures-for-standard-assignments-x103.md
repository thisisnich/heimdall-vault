---
id: "3f18e525-ab38-412c-8952-c31393095a20"
title: "Procedures For Standard Assignments X103"
type: vault_note
vault: wiki
created: 2026-05-17
updated: 2026-05-17
checksum: "sha256:87ff6d400af04c3e"
source: heimdall/auto
---

# Procedures For Standard Assignments X103

- Procedures]] for standard assignments (X103 for PB1, X110 for E-STOP, etc.)
2. **Keep rungs simple**: Each rung should have a clear, single purpose
3. **Document thoroughly**: Add comments explaining complex logic
4. **Use consistent formatting**: Maintain alignment and spacing throughout
5. **Include safety interlocks**: Always consider what happens if components fail
6. **Test incrementally**: Verify each section of logic before adding more
7. **Choose correct timer type**: Use TMR for precision (10ms), TMY for standard (1s), TMX for long delays (100ms)
8. **Calculate SV correctly**: Remember SV is counts, not time. `SV = Desired Time ÷ Timer Resolution`
9. **Reset counters**: Always provide a reset condition for counters
10. **Single output use**: Each Y address can only appear once in the entire program

## Common Mistakes to Avoid

1. **Forgetting to reset timers**: Timers reset automatically when input goes OFF, but latching circuits need explicit reset
2. **Missing interlocks**: Bidirectional motors need mutual exclusion (NOT contacts)
3. **Infinite loops**: Latching circuits must have a reset condition
4. **Incorrect contact types**: Normally open vs normally closed matters
5. **Timing conflicts**: Multiple timers in the same circuit can interfere with each other
6. **Wrong timer type**: Using TMY (1s) when you need TMR (10ms) for precision
7. **SV calculation errors**: Forgetting that SV is counts, not time
8. <!-- id:3f18e525-ab38-412c-8952-c31393095a20 ts:2026-05-17 07:49 -->
- Procedures]] for standard assignments (X103 for PB1, X110 for E-STOP, etc.)
2. **Keep rungs simple**: Each rung should have a clear, single purpose
3. **Document thoroughly**: Add comments explaining complex logic
4. **Use consistent formatting**: Maintain alignment and spacing throughout
5. **Include safety interlocks**: Always consider what happens if components fail
6. **Test incrementally**: Verify each section of logic before adding more
7. **Choose correct timer type**: Use TMR for precision (10ms), TMY for standard (1s), TMX for long delays (100ms)
8. **Calculate SV correctly**: Remember SV is counts, not time. `SV = Desired Time ÷ Timer Resolution`
9. **Reset counters**: Always provide a reset condition for counters
10. **Single output use**: Each Y address can only appear once in the entire program

## Common Mistakes to Avoid

1. **Forgetting to reset timers**: Timers reset automatically when input goes OFF, but latching circuits need explicit reset
2. **Missing interlocks**: Bidirectional motors need mutual exclusion (NOT contacts)
3. **Infinite loops**: Latching circuits must have a reset condition
4. **Incorrect contact types**: Normally open vs normally closed matters
5. **Timing conflicts**: Multiple timers in the same circuit can interfere with each other
6. **Wrong timer type**: Using TMY (1s) when you need TMR (10ms) for precision
7. **SV calculation errors**: Forgetting that SV is counts, not time
8. <!-- id:3f18e525-ab38-412c-8952-c31393095a20 ts:2026-05-17 07:49 -->
