---
id: "462fb4d3-2ebd-443a-bea1-9e8281a04b1b"
title: "T Speaks Fast Laughs Often"
type: vault_note
vault: wiki
created: 2026-05-17
updated: 2026-05-17
checksum: "sha256:017f6193256aa6e5"
source: heimdall/auto
---

# T Speaks Fast Laughs Often

- t, speaks fast, laughs often"
#   "Notes?"       → "Prof Hum from EGE351"

# List known speakers
python voice_to_note.py --speakers

# Record from mic
python voice_to_note.py --record --duration 300

# Skip interactive prompts (good for batch processing)
python voice_to_note.py recording.m4a --no-interactive
```

---

## Features

### Auto-Tagging
Content analyzed for course keywords:
| Course | Keywords Detected |
|--------|-------------------|
| EGE353 | ros, robot, slam, turtlesim, docker |
| EGE320 | embedded, msp430, ccs, gpio, interrupt |
| EGE321 | wireless, rf, spectrum, fdma, cdma, antenna |
| EGE351 | plc, ladder, panasonic, fpwin, relay |
| EGE322 | iot, mqtt, node-red, sensor |
| EGE301 | communication, workplace, culture, presentation |

### Output Format
All transcripts include:
- YAML frontmatter (tags, course, speakers, duration)
- Timestamped segments
- Speaker labels (full version only)
- Placeholder sections for summary and action items

---

## Phone Workflow

1. **Record** on phone during lecture/lab
2. **Transfer** to PC → place in `Downloads/recordings/`
3. **Run** either script:
   ```bash
   python voice_quick.py "..\..\Downloads\recordings\lecture.m4a"
   
   # Or process all recordings in folder:
   for %f in ("..\..\Downloads\recordings\*") do python voice_quick.py "%f"
   ```
4. **Review** generated markdown in `_inbox/`
5. <!-- id:462fb4d3-2ebd-443a-bea1-9e8281a04b1b ts:2026-05-17 07:49 -->
- t, speaks fast, laughs often"
#   "Notes?"       → "Prof Hum from EGE351"

# List known speakers
python voice_to_note.py --speakers

# Record from mic
python voice_to_note.py --record --duration 300

# Skip interactive prompts (good for batch processing)
python voice_to_note.py recording.m4a --no-interactive
```

---

## Features

### Auto-Tagging
Content analyzed for course keywords:
| Course | Keywords Detected |
|--------|-------------------|
| EGE353 | ros, robot, slam, turtlesim, docker |
| EGE320 | embedded, msp430, ccs, gpio, interrupt |
| EGE321 | wireless, rf, spectrum, fdma, cdma, antenna |
| EGE351 | plc, ladder, panasonic, fpwin, relay |
| EGE322 | iot, mqtt, node-red, sensor |
| EGE301 | communication, workplace, culture, presentation |

### Output Format
All transcripts include:
- YAML frontmatter (tags, course, speakers, duration)
- Timestamped segments
- Speaker labels (full version only)
- Placeholder sections for summary and action items

---

## Phone Workflow

1. **Record** on phone during lecture/lab
2. **Transfer** to PC → place in `Downloads/recordings/`
3. **Run** either script:
   ```bash
   python voice_quick.py "..\..\Downloads\recordings\lecture.m4a"
   
   # Or process all recordings in folder:
   for %f in ("..\..\Downloads\recordings\*") do python voice_quick.py "%f"
   ```
4. **Review** generated markdown in `_inbox/`
5. <!-- id:462fb4d3-2ebd-443a-bea1-9e8281a04b1b ts:2026-05-17 07:49 -->
