---
id: "89321a9a-74bb-40a4-829c-bfb3ad65faa4"
title: "Agent Prompt Voice"
type: vault_note
vault: wiki
created: 2026-05-17
updated: 2026-05-17
checksum: "sha256:1445a1fed54d7965"
source: heimdall/auto
---

# Agent Prompt Voice

- # Agent Prompt — Voice Transcription System

> **READ THIS FIRST** before modifying voice transcription code or speaker index.

## Overview

This vault has a voice-to-note transcription system in `_tools/` that converts audio recordings into Obsidian-ready markdown with speaker identification and auto-tagging.

---

## System Components

| File | Purpose |
|------|---------|
| `voice_quick.py` | Lightweight transcription only. Fast setup, no speaker ID. |
| `voice_to_note.py` | Full system: speaker diarization + voice fingerprinting + interactive registry |
| `requirements_voice.txt` | Python dependencies for full version |
| `VOICE_SETUP.md` | User-facing documentation |
| `_data/speaker_index.json` | **SPEAKER DATABASE** — voice embeddings, names, mannerisms |

---

## Speaker Index Structure

**Location:** `_data/speaker_index.json` (created on first run of full version)

**Schema per speaker:**
```json
{
  "spk_abc123": {
    "id": "spk_abc123",
    "name": "Bob Hum",
    "embedding": [0.023, -0.156, ...],  // 256-dim voice fingerprint
    "mannerisms": "Singaporean accent, fast speaker, uses 'uh' frequently",
    "notes": "EGE351 instructor, S.234, likes ladder diagram examples",
    "first_seen": "2026-04-28T10:30:00",
    "last_seen": "2026-04-28T14:15:00",
    "sample_count": 3
  }
}
```

**Critical Rules:**
- ⚠️ **NEVER delete entries** without confirming with user — destroys voice training
- ⚠️ **Preserve embedding arrays exactly** — they're trained voice fingerprin <!-- id:89321a9a-74bb-40a4-829c-bfb3ad65faa4 ts:2026-05-17 07:49 -->
- # Agent Prompt — Voice Transcription System

> **READ THIS FIRST** before modifying voice transcription code or speaker index.

## Overview

This vault has a voice-to-note transcription system in `_tools/` that converts audio recordings into Obsidian-ready markdown with speaker identification and auto-tagging.

---

## System Components

| File | Purpose |
|------|---------|
| `voice_quick.py` | Lightweight transcription only. Fast setup, no speaker ID. |
| `voice_to_note.py` | Full system: speaker diarization + voice fingerprinting + interactive registry |
| `requirements_voice.txt` | Python dependencies for full version |
| `VOICE_SETUP.md` | User-facing documentation |
| `_data/speaker_index.json` | **SPEAKER DATABASE** — voice embeddings, names, mannerisms |

---

## Speaker Index Structure

**Location:** `_data/speaker_index.json` (created on first run of full version)

**Schema per speaker:**
```json
{
  "spk_abc123": {
    "id": "spk_abc123",
    "name": "Bob Hum",
    "embedding": [0.023, -0.156, ...],  // 256-dim voice fingerprint
    "mannerisms": "Singaporean accent, fast speaker, uses 'uh' frequently",
    "notes": "EGE351 instructor, S.234, likes ladder diagram examples",
    "first_seen": "2026-04-28T10:30:00",
    "last_seen": "2026-04-28T14:15:00",
    "sample_count": 3
  }
}
```

**Critical Rules:**
- ⚠️ **NEVER delete entries** without confirming with user — destroys voice training
- ⚠️ **Preserve embedding arrays exactly** — they're trained voice fingerprin <!-- id:89321a9a-74bb-40a4-829c-bfb3ad65faa4 ts:2026-05-17 07:49 -->
