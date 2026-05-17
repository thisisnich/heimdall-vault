---
id: "8d354987-0d8e-4ce9-b1ab-6e51fc39d21f"
title: "Description With Open Dataspeaker Indexjson W As"
type: vault_note
vault: wiki
created: 2026-05-17
updated: 2026-05-17
checksum: "sha256:7161eec77b955d4a"
source: heimdall/auto
---

# Description With Open Dataspeaker Indexjson W As

- description"
with open("_data/speaker_index.json", "w") as f:
    json.dump(index, f, indent=2)
```

### Adding New Tag Categories
Edit `TAG_KEYWORDS` dict in transcription scripts:
```python
TAG_KEYWORDS = {
    "existing": [...],
    "newtag": ["trigger", "words", "here"],
}
```

### Fixing Recognition Threshold
In `voice_to_note.py`, adjust similarity threshold:
```python
# Line ~147 in find_best_match()
if best_score > 0.25:  # Lower = more permissive, Higher = stricter
```

---

## Output Format

Transcriptions generate markdown with this YAML frontmatter:
```yaml
---
type: voice-memo
date: 2026-04-28
duration: 45m 30s
course: EGE351
tags:
  - lecture
  - voice-memo
  - transcription
  - ege351
speakers:
  - Bob Hum
  - Nicholas
source_file: recording_20260428_103000.m4a
language: en
---
```

Followed by:
- Header with metadata
- Transcript with speaker labels + timestamps
- "Key Points Summary" section (placeholder)
- "Action Items" checklist (placeholder)

---

## Model Configuration

**Whisper models** (speed vs accuracy tradeoff):
| Model | Size | VRAM | Use When |
|-------|------|------|----------|
| tiny | 39MB | ~1GB | Quick tests, noisy audio |
| base | 74MB | ~1GB | Fast turnaround needed |
| small | 244MB | ~2GB | **Default choice** |
| medium | 769MB | ~5GB | Important recordings |
| large | 1550MB | ~10GB | Maximum accuracy |

Default is `small`. <!-- id:8d354987-0d8e-4ce9-b1ab-6e51fc39d21f ts:2026-05-17 07:49 -->
- description"
with open("_data/speaker_index.json", "w") as f:
    json.dump(index, f, indent=2)
```

### Adding New Tag Categories
Edit `TAG_KEYWORDS` dict in transcription scripts:
```python
TAG_KEYWORDS = {
    "existing": [...],
    "newtag": ["trigger", "words", "here"],
}
```

### Fixing Recognition Threshold
In `voice_to_note.py`, adjust similarity threshold:
```python
# Line ~147 in find_best_match()
if best_score > 0.25:  # Lower = more permissive, Higher = stricter
```

---

## Output Format

Transcriptions generate markdown with this YAML frontmatter:
```yaml
---
type: voice-memo
date: 2026-04-28
duration: 45m 30s
course: EGE351
tags:
  - lecture
  - voice-memo
  - transcription
  - ege351
speakers:
  - Bob Hum
  - Nicholas
source_file: recording_20260428_103000.m4a
language: en
---
```

Followed by:
- Header with metadata
- Transcript with speaker labels + timestamps
- "Key Points Summary" section (placeholder)
- "Action Items" checklist (placeholder)

---

## Model Configuration

**Whisper models** (speed vs accuracy tradeoff):
| Model | Size | VRAM | Use When |
|-------|------|------|----------|
| tiny | 39MB | ~1GB | Quick tests, noisy audio |
| base | 74MB | ~1GB | Fast turnaround needed |
| small | 244MB | ~2GB | **Default choice** |
| medium | 769MB | ~5GB | Important recordings |
| large | 1550MB | ~10GB | Maximum accuracy |

Default is `small`. <!-- id:8d354987-0d8e-4ce9-b1ab-6e51fc39d21f ts:2026-05-17 07:49 -->
