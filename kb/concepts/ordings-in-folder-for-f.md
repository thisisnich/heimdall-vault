---
id: "1db778bf-2613-44b1-98f7-5dd80333d82c"
title: "Ordings In Folder For F"
type: vault_note
vault: wiki
created: 2026-05-17
updated: 2026-05-17
checksum: "sha256:2c86c678d79aa64d"
source: heimdall/auto
---

# Ordings In Folder For F

- ordings in folder:
   for %f in ("..\..\Downloads\recordings\*") do python voice_quick.py "%f"
   ```
4. **Review** generated markdown in `_inbox/`
5. **Move** to appropriate course folder in Obsidian, add summary/action items

---

## Speaker Index Location

Full version stores voice fingerprints at:
```
_data/speaker_index.json
```

Each entry contains:
- Voice embedding (256-dim fingerprint)
- Name, mannerisms, notes
- First/last seen dates
- Sample count

---

## Model Sizes

| Model | Size | Speed | Use Case |
|-------|------|-------|----------|
| tiny | 39MB | ⚡ Fastest | Testing, quick drafts |
| base | 74MB | 🚀 Fast | Good for clean audio |
| small | 244MB | ✅ Balanced | **Recommended** |
| medium | 769MB | 🐢 Slower | Better accuracy |
| large | 1550MB | 🐌 Slowest | Best accuracy |

---

## Troubleshooting

### "CUDA out of memory"
Add: `--device cpu` or use smaller model (`--model tiny`)

### "No speakers in index yet"
First run will prompt you for all speakers. After that, they auto-match.

### Poor transcription quality
- Move closer to speaker
- Reduce background noise
- Use `medium` or `large` model
- Speak clearly, avoid overlapping speech

### PyAnnote license error
Visit https://huggingface.co/pyannote/speaker-diarization and click "Access repository" to accept terms. <!-- id:1db778bf-2613-44b1-98f7-5dd80333d82c ts:2026-05-17 07:49 -->
- ordings in folder:
   for %f in ("..\..\Downloads\recordings\*") do python voice_quick.py "%f"
   ```
4. **Review** generated markdown in `_inbox/`
5. **Move** to appropriate course folder in Obsidian, add summary/action items

---

## Speaker Index Location

Full version stores voice fingerprints at:
```
_data/speaker_index.json
```

Each entry contains:
- Voice embedding (256-dim fingerprint)
- Name, mannerisms, notes
- First/last seen dates
- Sample count

---

## Model Sizes

| Model | Size | Speed | Use Case |
|-------|------|-------|----------|
| tiny | 39MB | ⚡ Fastest | Testing, quick drafts |
| base | 74MB | 🚀 Fast | Good for clean audio |
| small | 244MB | ✅ Balanced | **Recommended** |
| medium | 769MB | 🐢 Slower | Better accuracy |
| large | 1550MB | 🐌 Slowest | Best accuracy |

---

## Troubleshooting

### "CUDA out of memory"
Add: `--device cpu` or use smaller model (`--model tiny`)

### "No speakers in index yet"
First run will prompt you for all speakers. After that, they auto-match.

### Poor transcription quality
- Move closer to speaker
- Reduce background noise
- Use `medium` or `large` model
- Speak clearly, avoid overlapping speech

### PyAnnote license error
Visit https://huggingface.co/pyannote/speaker-diarization and click "Access repository" to accept terms. <!-- id:1db778bf-2613-44b1-98f7-5dd80333d82c ts:2026-05-17 07:49 -->
