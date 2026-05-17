---
id: "b0549be1-55ff-4890-adde-4d8f34facc73"
title: "Nique And Cpm Critical Path"
type: vault_note
vault: wiki
created: 2026-05-17
updated: 2026-05-17
checksum: "sha256:e84d49ac7295341d"
source: heimdall/auto
---

# Nique And Cpm Critical Path

- nique)** and **CPM (Critical Path Method)** are two project management techniques used for **scheduling, planning, and controlling** complex projects. Both methods help project managers identify the **critical path** — the sequence of tasks that determines the minimum project duration.

### PERT (Program Evaluation and Review Technique)

**Purpose:** Used when task durations are **uncertain** or variable. PERT uses **probabilistic time estimates** to calculate expected project duration.

**Key Features:**
- Uses **three time estimates** for each activity:
  - **Optimistic (O)** — Best-case scenario (everything goes perfectly)
  - **Most Likely (M)** — Normal scenario (most probable duration)
  - **Pessimistic (P)** — Worst-case scenario (everything goes wrong)
- Calculates **expected time (TE)** using the formula:
  - **TE = (O + 4M + P) / 6**
- Provides a **probability distribution** for project completion
- Best for **R&D, new product development, IoT prototyping** where uncertainties are high

**PERT Formula for Variance:**
- **Variance (σ²) = [(P - O) / 6]²**
- **Standard Deviation (σ) = (P - O) / 6**

**Example — IoT Sensor Development:**
- Optimistic: 3 days
- Most Likely: 5 days
- Pessimistic: 13 days
- **TE = (3 + 4×5 + 13) / 6 = (3 + 20 + 13) / 6 = 36 / 6 = 6 days**
- **σ = (13 - 3) / 6 = 10 / 6 ≈ 1.67 days**
- **σ² ≈ 2.78**

### CPM (Critical Path Method)

**Purpose:** Used when task durations are **deterministic** and well-known. <!-- id:b0549be1-55ff-4890-adde-4d8f34facc73 ts:2026-05-17 07:49 -->
