---
id: "9ac80c75-cb76-44ae-b9d0-59c57dd2b58f"
title: "44Mb 2Gb Default"
type: vault_note
vault: wiki
created: 2026-05-17
updated: 2026-05-17
checksum: "sha256:e9df4db3521fc1c8"
source: heimdall/auto
---

# 44Mb 2Gb Default

- 44MB | ~2GB | **Default choice** |
| medium | 769MB | ~5GB | Important recordings |
| large | 1550MB | ~10GB | Maximum accuracy |

Default is `small`. User can override with `--model` flag.

---

## Safety Checklist

Before modifying voice system code:
- [ ] Read `_data/speaker_index.json` if it exists
- [ ] Back up speaker index before structural changes
- [ ] Test with `--no-interactive` flag if modifying speaker logic
- [ ] Verify YAML frontmatter output matches vault conventions
- [ ] Check auto-tagging still detects courses correctly

---

## User Workflow & File Locations

**Audio Input Files** (from phone, recordings, etc.):
- **User's location:** `Downloads/recordings/` — copy phone recordings here
- Also supports: any path, Desktop, temp folders
- Supported formats: `.m4a`, `.mp3`, `.wav`, `.ogg`, `.webm`
- Deleted after transcription? No, original stays in place

**Generated Markdown Notes:**
- Default location: `_inbox/` (staging area)
- Auto-routed: Course folder if course detected (e.g., `EGE351/`)
- Naming: `{COURSE}_voice_{tag}_{date}.md` or `voice_{date}_{time}.md`

**Direct Recording:**
```bash
python voice_quick.py --record --duration 300
```
- Audio saved to: `_inbox/recording_YYYYMMDD_HHMMSS.wav`
- Transcript saved to: `_inbox/{course}_voice_*.md`

**Typical User Flow:**
1. Phone records lecture → saves to `Downloads/`
2. Run: `python voice_quick.py "..\..\Downloads\lecture.m4a"`
3. Review generated `.md` in `_inbox/`
4. <!-- id:9ac80c75-cb76-44ae-b9d0-59c57dd2b58f ts:2026-05-17 07:49 -->
- 44MB | ~2GB | **Default choice** |
| medium | 769MB | ~5GB | Important recordings |
| large | 1550MB | ~10GB | Maximum accuracy |

Default is `small`. User can override with `--model` flag.

---

## Safety Checklist

Before modifying voice system code:
- [ ] Read `_data/speaker_index.json` if it exists
- [ ] Back up speaker index before structural changes
- [ ] Test with `--no-interactive` flag if modifying speaker logic
- [ ] Verify YAML frontmatter output matches vault conventions
- [ ] Check auto-tagging still detects courses correctly

---

## User Workflow & File Locations

**Audio Input Files** (from phone, recordings, etc.):
- **User's location:** `Downloads/recordings/` — copy phone recordings here
- Also supports: any path, Desktop, temp folders
- Supported formats: `.m4a`, `.mp3`, `.wav`, `.ogg`, `.webm`
- Deleted after transcription? No, original stays in place

**Generated Markdown Notes:**
- Default location: `_inbox/` (staging area)
- Auto-routed: Course folder if course detected (e.g., `EGE351/`)
- Naming: `{COURSE}_voice_{tag}_{date}.md` or `voice_{date}_{time}.md`

**Direct Recording:**
```bash
python voice_quick.py --record --duration 300
```
- Audio saved to: `_inbox/recording_YYYYMMDD_HHMMSS.wav`
- Transcript saved to: `_inbox/{course}_voice_*.md`

**Typical User Flow:**
1. Phone records lecture → saves to `Downloads/`
2. Run: `python voice_quick.py "..\..\Downloads\lecture.m4a"`
3. Review generated `.md` in `_inbox/`
4. <!-- id:9ac80c75-cb76-44ae-b9d0-59c57dd2b58f ts:2026-05-17 07:49 -->
