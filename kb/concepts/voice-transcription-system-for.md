---
id: "4660d4f4-a880-405d-9694-317796593c30"
title: "Voice Transcription System For"
type: vault_note
vault: wiki
created: 2026-05-17
updated: 2026-05-17
checksum: "sha256:e1db5e0603b19082"
source: heimdall/auto
---

# Voice Transcription System For

- # Voice Transcription System for NYPY3 Vault

Two options available: **Quick** (simple, fast setup) and **Full** (speaker ID, diarization).

---

## Option 1: Quick Version (Recommended Start)

`voice_quick.py` — Just transcription + auto-tagging. No speaker identification.

### Setup
```bash
cd "c:\Users\Nicholas Dubs\Documents\Obsidian\NYPY3\_tools"
pip install openai-whisper torch numpy sounddevice
```

### Usage
```bash
# Transcribe phone voice memo
python voice_quick.py "..\..\Downloads\recording.m4a"

# Record from microphone (5 min)
python voice_quick.py --record --duration 300

# Use faster (less accurate) model
python voice_quick.py recording.m4a --model tiny
```

**Output:** Markdown file in `_inbox/` with YAML frontmatter, course auto-detected from keywords.

---

## Option 2: Full Version (Speaker Identification)

`voice_to_note.py` — Speaker diarization, voice fingerprinting, interactive speaker registry.

### Setup
```bash
pip install -r requirements_voice.txt

# IMPORTANT: For speaker diarization, accept license at:
# https://huggingface.co/pyannote/speaker-diarization
# Then: huggingface-cli login
```

### Usage
```bash
# Transcribe with speaker detection
python voice_to_note.py recording.m4a

# If unknown speaker detected, you'll be prompted:
#   "Who is this?" → type name
#   "Mannerisms?"  → "Singaporean accent, speaks fast, laughs often"
#   "Notes?"       → "Prof Hum from EGE351"

# List known speakers
python voice_to_note.py --speakers

# Record from mic <!-- id:4660d4f4-a880-405d-9694-317796593c30 ts:2026-05-17 07:49 -->
- # Voice Transcription System for NYPY3 Vault

Two options available: **Quick** (simple, fast setup) and **Full** (speaker ID, diarization).

---

## Option 1: Quick Version (Recommended Start)

`voice_quick.py` — Just transcription + auto-tagging. No speaker identification.

### Setup
```bash
cd "c:\Users\Nicholas Dubs\Documents\Obsidian\NYPY3\_tools"
pip install openai-whisper torch numpy sounddevice
```

### Usage
```bash
# Transcribe phone voice memo
python voice_quick.py "..\..\Downloads\recording.m4a"

# Record from microphone (5 min)
python voice_quick.py --record --duration 300

# Use faster (less accurate) model
python voice_quick.py recording.m4a --model tiny
```

**Output:** Markdown file in `_inbox/` with YAML frontmatter, course auto-detected from keywords.

---

## Option 2: Full Version (Speaker Identification)

`voice_to_note.py` — Speaker diarization, voice fingerprinting, interactive speaker registry.

### Setup
```bash
pip install -r requirements_voice.txt

# IMPORTANT: For speaker diarization, accept license at:
# https://huggingface.co/pyannote/speaker-diarization
# Then: huggingface-cli login
```

### Usage
```bash
# Transcribe with speaker detection
python voice_to_note.py recording.m4a

# If unknown speaker detected, you'll be prompted:
#   "Who is this?" → type name
#   "Mannerisms?"  → "Singaporean accent, speaks fast, laughs often"
#   "Notes?"       → "Prof Hum from EGE351"

# List known speakers
python voice_to_note.py --speakers

# Record from mic <!-- id:4660d4f4-a880-405d-9694-317796593c30 ts:2026-05-17 07:49 -->
