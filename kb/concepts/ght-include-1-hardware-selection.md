---
id: "98108cad-7a0e-46b4-a880-d057fdfe293c"
title: "Ght Include 1 Hardware Selection"
type: vault_note
vault: wiki
created: 2026-05-17
updated: 2026-05-17
checksum: "sha256:d4865d828d6b024c"
source: heimdall/auto
---

# Ght Include 1 Hardware Selection

- ght include:
1. **Hardware selection** → 2. **Sensor procurement** → 3. **Circuit design** → 4. **PCB fabrication** → 5. **Firmware development** → 6. **Integration testing**

If any activity on this path is delayed, the **entire project is delayed**.

**Example IoT Project Critical Path:**
```
Task A: Hardware Selection (2 days)
Task B: Sensor Procurement (5 days) — depends on A
Task C: Circuit Design (4 days) — depends on B
Task D: PCB Fabrication (7 days) — depends on C
Task E: Firmware Development (8 days) — depends on D
Task F: Integration Testing (3 days) — depends on E
Total Critical Path: 2 + 5 + 4 + 7 + 8 + 3 = 29 days
```

### Slack/Float in IoT Projects

Activities **not** on the critical path have **slack** — they can be delayed without affecting project completion.

**Example:**
- **Documentation** can be done in parallel with development
- **User interface design** may have slack if backend development is critical
- **Packaging design** often has slack as it's done near the end

### Using PERT/CPM for IoT Projects

**When to use PERT for IoT:**
- Developing **new sensor technology** with unknown performance
- **Wireless protocol selection** with uncertain range/reliability
- **Cloud integration** with third-party services
- **Regulatory certification** with unpredictable timelines

**When to use CPM for IoT:**
- **Hardware assembly** with known component lead times
- **Software testing** with established test suites
- **Documentation** with clear requirements
- <!-- id:98108cad-7a0e-46b4-a880-d057fdfe293c ts:2026-05-17 07:49 -->
