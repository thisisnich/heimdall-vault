---
id: "469b9731-b6d2-45c5-ba93-a134d240cdbf"
title: "Ocess Major Milestones In"
type: vault_note
vault: wiki
created: 2026-05-17
updated: 2026-05-17
checksum: "sha256:03b88c074eb0bba7"
source: heimdall/auto
---

# Ocess Major Milestones In

- ocess

### Major Milestones in the Avionics Development Process

The majority of aircraft systems have electronics (**hardware**) associated with the control function, usually controlled or driven by **software**. The development process typically follows **5 major milestones**:

1. **System Requirement Review (SRR)**
2. **System Design Review (SDR)**
3. **Software Specification Review (SSR)**
4. **Preliminary Design Review (PDR)**
5. **Critical Design Review (CDR)**

```
Perceived        SRR          SDR          PDR         CDR       Hardware
System Reqt  ─────────> PSD ──────> Reqt ──────> Prelim ──────> Detailed ──────> Build ─┐
                                   Analysis     HW Design       HW Design               │
                                      │                                                  ▼
                                      └──────> Reqt ──────> Prelim ──────> Detailed ──> Code ─> Integration
                                              Analysis      SW Design       SW Design    & Test   & Test ──> Final
                              SSR ─────────────────^            PDR (SW)    CDR (SW)              Product
```

### System Requirements Review (SRR)

- A **top-level multidisciplinary review** of the perceived system requirements
- Successful completion leads to a **Preliminary System Design (PSD)**
- Typical considerations include:
  - Functions
  - Software code size
  - Operating hours, MTBF
  - Dimensions, size, weight
  - Power requirements (e.g. <!-- id:469b9731-b6d2-45c5-ba93-a134d240cdbf ts:2026-05-17 07:49 -->
