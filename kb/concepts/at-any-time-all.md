---
id: "e1ea00f2-741f-4053-85e3-ba333985e977"
title: "At Any Time All"
type: vault_note
vault: wiki
created: 2026-05-17
updated: 2026-05-17
checksum: "sha256:949ff230e6bac756"
source: heimdall/auto
---

# At Any Time All

- at any time → All LEDs OFF
### Question 3
When PB1 is pressed five times, a green LED flashes. When PB1 is pressed eight times, an amber LED flashes. When PB1 is pressed twelve times, a red LED flashes. After this, a left gantry is raised. Two seconds later, the gantry is lowered and all LEDs are turned off.

**Solution:**
```
Rung 1:
|--[X103]-------------------------------------------[CT1]--|
|                                                   [   ]
|--[T1]---------------------------------------------[U5]--|

Rung 2:
|--[C1]--[SR1C]--------------------------------------(Y122)--|

Rung 3:
|--[C1]--[X103]-------------------------------------[CT2]--|
|                                                   [   ]
|--[T1]---------------------------------------------[U8]--|

Rung 4:
|--[C2]--[SR1C]--------------------------------------(Y121)--|

Rung 5:
|--[C2]--[X103]-------------------------------------[CT3]--|
|                                                   [   ]
|--[T1]---------------------------------------------[U12]--|

Rung 6:
|--[C3]--[SR1C]--------------------------------------(Y120)--|

Rung 7:
|--[C3]-----------------------------[TMY1 | U2]--|

Rung 8:
|--[C3]----------------------------------------------(Y124)--|

Rung 9:
|--[/C3]--------------------------------------------- (Y125)--|
```

**How the ladder diagram works:**

This is a multi-stage counter system that triggers different LEDs based on button press counts, then controls a gantry with automatic reset.

**S <!-- id:e1ea00f2-741f-4053-85e3-ba333985e977 ts:2026-05-17 07:49 -->
- at any time → All LEDs OFF
### Question 3
When PB1 is pressed five times, a green LED flashes. When PB1 is pressed eight times, an amber LED flashes. When PB1 is pressed twelve times, a red LED flashes. After this, a left gantry is raised. Two seconds later, the gantry is lowered and all LEDs are turned off.

**Solution:**
```
Rung 1:
|--[X103]-------------------------------------------[CT1]--|
|                                                   [   ]
|--[T1]---------------------------------------------[U5]--|

Rung 2:
|--[C1]--[SR1C]--------------------------------------(Y122)--|

Rung 3:
|--[C1]--[X103]-------------------------------------[CT2]--|
|                                                   [   ]
|--[T1]---------------------------------------------[U8]--|

Rung 4:
|--[C2]--[SR1C]--------------------------------------(Y121)--|

Rung 5:
|--[C2]--[X103]-------------------------------------[CT3]--|
|                                                   [   ]
|--[T1]---------------------------------------------[U12]--|

Rung 6:
|--[C3]--[SR1C]--------------------------------------(Y120)--|

Rung 7:
|--[C3]-----------------------------[TMY1 | U2]--|

Rung 8:
|--[C3]----------------------------------------------(Y124)--|

Rung 9:
|--[/C3]--------------------------------------------- (Y125)--|
```

**How the ladder diagram works:**

This is a multi-stage counter system that triggers different LEDs based on button press counts, then controls a gantry with automatic reset.

**S <!-- id:e1ea00f2-741f-4053-85e3-ba333985e977 ts:2026-05-17 07:49 -->
