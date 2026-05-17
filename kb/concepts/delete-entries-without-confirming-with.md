---
id: "44308e73-95e3-4282-a923-da82b35f2360"
title: "Delete Entries Without Confirming With"
type: vault_note
vault: wiki
created: 2026-05-17
updated: 2026-05-17
checksum: "sha256:c048de4fec743f0d"
source: heimdall/auto
---

# Delete Entries Without Confirming With

- delete entries** without confirming with user — destroys voice training
- ⚠️ **Preserve embedding arrays exactly** — they're trained voice fingerprints
- ✅ Mannerisms/notes fields are safe to edit/extend
- ✅ Sample count and last_seen update automatically on recognition

---

## Auto-Tagging Logic

**Course detection** uses keyword matching on transcript text:
- EGE353: ros, robot, slam, turtlesim, docker, lidar, sensor, actuator
- EGE320: embedded, microcontroller, ccs, msp430, gpio, timer, interrupt
- EGE321: wireless, rf, spectrum, fdma, tdma, cdma, ofdma, antenna, signal
- EGE351: plc, ladder, automation, panasonic, fpwin, input, output, relay, timer
- EGE322: iot, project, management, mqtt, node-red, dashboard
- EGE301: communication, workplace, culture, ethics, presentation, ica

**Tag detection** adds: lecture, lab, assignment, exam-prep, question

---

## Common Agent Tasks

### Adding/Modifying Course Keywords
Edit `COURSE_KEYWORDS` dict in `voice_to_note.py` or `voice_quick.py`:
```python
COURSE_KEYWORDS = {
    "EGE3XX": ["keyword1", "keyword2", ...],
    ...
}
```

### Updating Speaker Mannerisms
Safe to edit directly in `_data/speaker_index.json`:
```bash
# Or read with Python, modify, save
import json
with open("_data/speaker_index.json") as f:
    index = json.load(f)
index["spk_abc123"]["mannerisms"] = "Updated description"
with open("_data/speaker_index.json", "w") as f:
    json.dump(index, f, indent=2)
```

### Adding New Tag Categories
Edit `TAG_KEYWORDS` <!-- id:44308e73-95e3-4282-a923-da82b35f2360 ts:2026-05-17 07:49 -->
- delete entries** without confirming with user — destroys voice training
- ⚠️ **Preserve embedding arrays exactly** — they're trained voice fingerprints
- ✅ Mannerisms/notes fields are safe to edit/extend
- ✅ Sample count and last_seen update automatically on recognition

---

## Auto-Tagging Logic

**Course detection** uses keyword matching on transcript text:
- EGE353: ros, robot, slam, turtlesim, docker, lidar, sensor, actuator
- EGE320: embedded, microcontroller, ccs, msp430, gpio, timer, interrupt
- EGE321: wireless, rf, spectrum, fdma, tdma, cdma, ofdma, antenna, signal
- EGE351: plc, ladder, automation, panasonic, fpwin, input, output, relay, timer
- EGE322: iot, project, management, mqtt, node-red, dashboard
- EGE301: communication, workplace, culture, ethics, presentation, ica

**Tag detection** adds: lecture, lab, assignment, exam-prep, question

---

## Common Agent Tasks

### Adding/Modifying Course Keywords
Edit `COURSE_KEYWORDS` dict in `voice_to_note.py` or `voice_quick.py`:
```python
COURSE_KEYWORDS = {
    "EGE3XX": ["keyword1", "keyword2", ...],
    ...
}
```

### Updating Speaker Mannerisms
Safe to edit directly in `_data/speaker_index.json`:
```bash
# Or read with Python, modify, save
import json
with open("_data/speaker_index.json") as f:
    index = json.load(f)
index["spk_abc123"]["mannerisms"] = "Updated description"
with open("_data/speaker_index.json", "w") as f:
    json.dump(index, f, indent=2)
```

### Adding New Tag Categories
Edit `TAG_KEYWORDS` <!-- id:44308e73-95e3-4282-a923-da82b35f2360 ts:2026-05-17 07:49 -->
