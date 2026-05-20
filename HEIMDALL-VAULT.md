# Heimdall Vault — Human Guide

> **For AI agents:** read [[AGENTS.md]] first. That file is the authoritative operating manual.  
> **For Telegram PA:** paste [[PA-SYSTEM-PROMPT.md]] into the bot system prompt (full rules still in AGENTS.md).

## What this vault is

A **second brain** for Nicholas Dubs: NYP Year 3 coursework, AP self-study, coaching sessions, personal learning, and dev projects. Synced via **Git** (laptop + desktop). A separate repo **`heimdall-memory`** holds archived semesters (read-mostly).

## Folder map (active vault)

| Path | Purpose |
|------|---------|
| `00-INBOX/` | All new captures land here first |
| `01-PROJECTS/` | Time-bound work: ICAs, labs due, group assignments |
| `02-DAILY/` | Daily notes (journal + quick capture) |
| `03-RESOURCES/` | Courses, AP, ingested media |
| `04-AREAS/` | Ongoing: coaching, learning queue, career |
| `05-KB/concepts/` | Cross-module concept notes only |
| `06-PROJECTS-DEV/` | Git repos, summaries, dev todos |
| `07-DASHBOARDS/` | Indexes, schedules, study command center |
| `04-ARCHIVE/` | Completed local material (pre–memory-repo) |
| `90-TEMPLATES/` | Note templates |
| `91-SCRIPTS/` | Ingestion & archive CLI |
| `99-ATTACHMENTS/` | Binary files (PDF, audio, images) |

### Course modules (current layout)

Active modules live directly under `03-RESOURCES/` (migration to `03-RESOURCES/Courses/` is optional):

- `EGE301-Communication-Workplace-Success`
- `EGE320-Embedded-System-Design`
- `EGE321-Wireless-Communication`
- `EGE322-IOT-System-Project`
- `EGE351-Automation-Systems-Control`
- `EGE353-Autonomous-Mobile-Robotics`
- `FGX312-Japanese-Culture-Society`
- `HSX302-Healthy-Resilient-Families`

AP study plans: `03-RESOURCES/AP/`

## Weekly routine (~30–45 min)

1. Process `00-INBOX/` → file to correct folder.
2. Review `02-DAILY/` from the week → tasks & links.
3. Update assessment dashboard if dates changed.
4. Run `python 91-SCRIPTS/ingest.py --process-inbox` if drops are pending.
5. Ask PA: “study gaps for assessments in the next 14 days”.

## Ingestion (quick)

```bash
cd 91-SCRIPTS
pip install -r requirements.txt
python ingest.py pdf path/to/slides.pdf --course EGE322
python ingest.py transcript path/to/voice-memos.txt --course EGE322 --title "Week 3 lecture"
python ingest.py youtube "https://youtube.com/..." --title "ROS intro"
python ingest.py --process-inbox
```

**Lectures:** Apple Voice Memos auto-transcript → save `.txt` to `00-INBOX/_drop/` → ingest. See `91-SCRIPTS/VOICE-MEMOS-WORKFLOW.md` (no OpenAI key).

## End of semester

```bash
python 91-SCRIPTS/archive-course.py EGE322-IOT-System-Project --semester 2026-S1
```

Moves module to `heimdall-memory` repo and leaves a stub MOC in the active vault.

## Telegram PA

The PA must `git pull` before edits and only `git commit` after user approval for structural changes. Calendar: CalDAV (read). Full behaviour: [[AGENTS.md]].
