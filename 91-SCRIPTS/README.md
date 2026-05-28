# Heimdall ingestion scripts

## Setup

```powershell
cd "c:\Users\Nicholas Dubs\Documents\Obsidian\heimdall-vault\91-SCRIPTS"
python -m venv .venv
.\.venv\Scripts\Activate.ps1
pip install -r requirements.txt
copy .env.example .env
```

**Voice Memos transcripts (default):** see [[VOICE-MEMOS-WORKFLOW.md]].  
**OpenAI key (optional, raw audio only):** see [[OPENAI-API-SETUP.md]].

Requires **ffmpeg** on PATH for audio/video (Whisper / yt-dlp).

## Usage

```powershell
# PDF / PPTX / DOCX / image
python ingest.py pdf "..\99-ATTACHMENTS\EGE322\slides.pdf" --course EGE322

# YouTube
python ingest.py youtube "https://www.youtube.com/watch?v=..." --title "ROS intro" --course EGE353

# Audio (uses OpenAI Whisper if OPENAI_API_KEY set; else prints instructions)
python ingest.py audio "lecture.m4a" --course EGE320

# Image (whiteboard / slide photo)
python ingest.py image "photo.jpg" --course EGE322

# Web URL
python ingest.py url "https://example.com/article"

# Process everything in 00-INBOX/_drop/
python ingest.py --process-inbox
```

Output lands in `00-INBOX/_processing/` then copies to `03-RESOURCES/<module>/` or `Media/`.

**PDF diagrams:** `ingest.py pdf` renders pages that mention figures/circuits/plots (or contain substantial visuals) to `99-ATTACHMENTS/<COURSE>/<slug>/` and adds a `## Figures` section to the note. Agents embed these inline during cleanup where questions reference them; skip logos/decorative shots.

**After `ingest.py` finishes:** agent must run the **post-ingest cleanup pass** — structure the `.md` (headings, tables, code blocks, summary, figure embeds, links). MarkItDown output alone is not done. See [[AGENTS.md]] §5.

**Agents:** see [[AGENTS.md]] §5.
