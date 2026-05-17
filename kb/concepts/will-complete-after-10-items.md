---
id: "4504a06b-03e6-4366-91b9-76d6ba265898"
title: "Will Complete After 10 Items"
type: vault_note
vault: wiki
created: 2026-05-17
updated: 2026-05-17
checksum: "sha256:c0baeb5a6b6208ab"
source: heimdall/auto
---

# Will Complete After 10 Items

- will complete after 10 items.

- **Rung 2 (Conveyor motor control):** When counter C1 is NOT complete ([/C1] is closed), the conveyor motor Y122 runs. Once 10 items pass and C1 completes, [/C1] opens and stops the conveyor.

- **Rung 3 (Cylinder extend):** When counter C1 completes (after 10 items), the cylinder Y125 extends.

- **Rung 4 (Cylinder retract timer):** When C1 completes, timer TMY1 starts with 2-second preset (U2 = 2 seconds). This times how long the cylinder stays extended.

- **Rung 5 (Cylinder retract + counter reset):** When timer T1 completes (after 2 seconds), it energizes Y124 (cylinder retract) AND resets the counter through the empty contact (the reset input to CT1). This restarts the conveyor and begins counting again.

--- <!-- id:4504a06b-03e6-4366-91b9-76d6ba265898 ts:2026-05-17 07:49 -->
- will complete after 10 items.

- **Rung 2 (Conveyor motor control):** When counter C1 is NOT complete ([/C1] is closed), the conveyor motor Y122 runs. Once 10 items pass and C1 completes, [/C1] opens and stops the conveyor.

- **Rung 3 (Cylinder extend):** When counter C1 completes (after 10 items), the cylinder Y125 extends.

- **Rung 4 (Cylinder retract timer):** When C1 completes, timer TMY1 starts with 2-second preset (U2 = 2 seconds). This times how long the cylinder stays extended.

- **Rung 5 (Cylinder retract + counter reset):** When timer T1 completes (after 2 seconds), it energizes Y124 (cylinder retract) AND resets the counter through the empty contact (the reset input to CT1). This restarts the conveyor and begins counting again.

--- <!-- id:4504a06b-03e6-4366-91b9-76d6ba265898 ts:2026-05-17 07:49 -->
