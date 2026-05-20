# Apple Voice Memos → vault (no OpenAI key)

You transcribe on the phone; the vault stores and links the text. **No Whisper / API cost.**

## On iPhone / iPad

1. Record in **Voice Memos**.
2. When done, open the recording → tap **⋯** or the transcript area.
3. Use **View Transcript** / copy transcript (iOS 17+ auto-transcribes many recordings).
4. Get text to the PC one of these ways:
   - **Share** → AirDrop to Windows (save as `.txt`) → drop in `00-INBOX/_drop/`
   - **Copy** transcript → paste into a new file `lecture-week3.txt` → save into `_drop/`
   - **Telegram PA** → paste transcript; PA saves to `_drop/` and runs ingest

## On Mac (if you sync Voice Memos via iCloud)

1. Open **Voice Memos** → select recording → show transcript.
2. **Edit → Select All → Copy** (or Export if available).
3. Save as `.txt` in:

   `heimdall-vault\00-INBOX\_drop\`

## Ingest on PC

```powershell
cd heimdall-vault\91-SCRIPTS
.\.venv\Scripts\Activate.ps1

# Single file with course tag
python ingest.py transcript "..\00-INBOX\_drop\lecture-week3.txt" --course EGE322 --title "Week 3 lecture"

# Or process everything in _drop/
python ingest.py --process-inbox
```

Creates `week-3-lecture-transcript.md` in the course folder with an ingest block (`tool: apple-voice-memos`).

## After ingest (you or AI)

1. Open your **tutorial / lecture note** (the one you actually study from).
2. Add a link: `[[week-3-lecture-transcript]]`
3. Optional: ask agent to fill **Summary** and **Flashcards** on the tutorial note — not on the raw transcript.

## Coaching sessions

Same flow: save transcript as `2026-05-20-coaching.txt`, ingest with:

```powershell
python ingest.py transcript "..\00-INBOX\_drop\2026-05-20-coaching.txt" --title "Coaching session"
```

Then copy takeaways into `04-AREAS/Coaching/YYYY-MM-DD-client-A.md` (human-edited summary beats raw transcript).

## Skip OpenAI entirely

- **Audio files** in `_drop/` still call Whisper if you run default inbox processing on `.m4a` — prefer exporting **transcript .txt** instead of raw audio.
- See [[OPENAI-API-SETUP.md]] only if you later want automatic audio transcription on PC.
