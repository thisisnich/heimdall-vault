# Heimdall Vault — Agent Operating Manual

> **Audience:** Cursor agents, Claude Code, Telegram PA, Codex, Gemini CLI, or any tool with vault access.  
> **Owner:** Nicholas Dubs  
> **Vault:** `heimdall-vault` (active, Git-synced) + `heimdall-memory` (archived semesters, separate repo)  
> **Human guide:** [[HEIMDALL-VAULT.md]]

---

## 0. Mission

Help Nicholas **study effectively**, **never miss submissions**, **capture coaching and learning**, and **maintain a searchable second brain** — without creating duplicate notes, invented lecture content, or unstructured AI clutter.

**Three equal goals (long-term):** exam success · portfolio/career · durable reference.  
**Current priority:** school (NYP + AP). After a semester, course folders move to `heimdall-memory`; active vault keeps a stub link only.

---

## 1. Mandatory workflow (every request)

```
PAUSE → SEARCH → READ → PLAN → ACT → REPORT
```

1. **PAUSE** — Do not answer from general knowledge if the vault may hold the answer.
2. **SEARCH** — In order:
   - `07-DASHBOARDS/` (indexes, due dates)
   - `03-RESOURCES/` course folders + `03-RESOURCES/AP/`
   - `01-PROJECTS/` (active ICAs/labs)
   - `05-KB/concepts/` (cross-module ideas)
   - `06-PROJECTS-DEV/`
   - `04-AREAS/Coaching/`, `04-AREAS/Learning/`
   - `heimdall-memory/` **only** when user asks for old semesters or a stub says `archived: true`
3. **READ** — Open relevant notes; respect frontmatter `type`, `course`, `status`.
4. **PLAN** — State what you will create/move/link before doing it (except read-only Q&A).
5. **ACT** — Execute with minimal diff; prefer editing existing notes over new files.
6. **REPORT** — Cite paths; list new todos; flag `#gap` items and upcoming due dates.

### Git discipline (laptop + desktop + PA)

- **`git pull`** before any write session.
- **Never force-push** `main`.
- **Commit message format:** `vault: <action> — <target>` (e.g. `vault: ingest — EGE322 week3 slides`).
- **Structural moves** (archive course, rename module folder): require explicit user approval in chat/Telegram.
- **Auto-commit** after approved batches is OK if Obsidian Git or PA policy allows.

---

## 2. Vault topology

### Active: `heimdall-vault`

| Path | `type` values | Rules |
|------|---------------|-------|
| `00-INBOX/` | — | Default landing zone. Nothing stays >7 days without user override. |
| `00-INBOX/_drop/` | — | User/PA drops raw files for scripts. |
| `00-INBOX/_processing/` | — | Script output before filing. |
| `01-PROJECTS/<name>/` | `assignment`, `project` | Deadlines, ICA drafts, group work. Link to course MOC. |
| `02-DAILY/YYYY-MM-DD.md` | `daily` | Journal + capture. Process weekly. |
| `03-RESOURCES/<MODULE>/` | `lecture`, `lab`, `tutorial`, `course-moc` | **Primary course notes.** See §4. |
| `03-RESOURCES/AP/` | `study-plan`, `lecture` | Same rules as courses. |
| `03-RESOURCES/Media/` | `media` | Ingested YouTube, reels, articles. |
| `04-AREAS/Coaching/` | `coaching-session` | Session logs — see template. |
| `04-AREAS/Learning/` | `learning-topic` | Topics to learn; queue, not dumps. |
| `05-KB/concepts/` | `concept` | **Only** cross-module atomic ideas. |
| `06-PROJECTS-DEV/` | `dev-project` | Git URL, AI summary, todos. |
| `07-DASHBOARDS/` | `dashboard`, `index` | Schedules, MOCs, command center. |
| `04-ARCHIVE/` | — | Local legacy archive (pre–memory-repo). |
| `90-TEMPLATES/` | — | Do not edit unless asked. |
| `91-SCRIPTS/` | — | Ingestion/archive automation. |
| `99-ATTACHMENTS/` | — | PDFs, audio, images; link from notes. |

### Legacy paths (still valid — do not delete)

- `wiki/`, `work/projects/` → migrate new items to `06-PROJECTS-DEV/`; read old paths when searching.
- `kb/`, `personal/` → use `05-KB/` and `04-AREAS/` for new content.
- `04-MEMORIES/` → prefer `04-AREAS/Learning/` for new memory-style notes.

### Archived: `heimdall-memory` (separate repo)

- Path pattern: `NYP/<YYYY-Sn>/<MODULE>/`
- **Read-only by default.** Copy snippets into active vault only when user requests.
- After archive: active vault keeps `03-RESOURCES/<MODULE>.md` stub with `archived: true` and link to memory path.

---

## 3. Frontmatter contract

Every **new** note you create must include:

```yaml
---
type: <see table>
course: <CODE or AP-Calculus-BC or null>
module: <folder name or null>
status: draft | reviewed | exam-ready | archived
source: manual | pdf | youtube | audio | photo | web | git
created: YYYY-MM-DD
tags: []
---
```

Additional fields when applicable:

| Field | Used for |
|-------|----------|
| `due: YYYY-MM-DD` | Assignments, tasks |
| `client:` | Coaching (use anonymized `client-A` unless user names) |
| `repo: URL` | Dev projects |
| `duration_min:` | Coaching sessions |
| `week:` | Lectures |
| `archived: true` | Stub after semester move |

**Tasks in body:** `- [ ] Description 📅 YYYY-MM-DD` or Tasks-plugin format.

**Gap marker:** `<!-- gap: describe what's missing -->` or tag `#gap` in frontmatter.

---

## 4. Course module rules

### Folder layout (per module under `03-RESOURCES/<MODULE>/`)

```
<METHOD>/
  _MOC.md              # Hub: assessments, staff, quick links (create if missing)
  Lectures/            # Optional; flat files OK if already established
  Labs/
  Tutorials/
  _sources/            # Original PDFs, audio (optional)
```

**Do not reorganize existing flat module folders** unless user explicitly requests migration — links depend on current paths.

### Active NYP modules (S1 2026)

| Code | Folder |
|------|--------|
| EGE301 | `EGE301-Communication-Workplace-Success` |
| EGE320 | `EGE320-Embedded-System-Design` |
| EGE321 | `EGE321-Wireless-Communication` |
| EGE322 | `EGE322-IOT-System-Project` |
| EGE351 | `EGE351-Automation-Systems-Control` |
| EGE353 | `EGE353-Autonomous-Mobile-Robotics` |
| FGX312 | `FGX312-Japanese-Culture-Society` |
| HSX302 | `HSX302-Healthy-Resilient-Families` |

### Note-taking hierarchy

1. **Tutorial / lecture note** (user-edited) = source of truth for studying.
2. **Ingested file** (`*-slides.md`, `*-transcript.md`) = reference block at top; link from tutorial.
3. **Concept note** (`05-KB/concepts/`) = only if used in ≥2 modules or user confirms.

### Linking policy

- **Default:** links stay inside the same module folder.
- **Cross-link** only to `05-KB/concepts/<topic>.md` for shared ideas (MQTT, ROS, PID, SLAM, PLC, QoS, ESP32, etc.).
- **Never** create a web of links between modules for one-off topics.

### Ingested content block (required)

```markdown
> [!ingest] source: <filename or URL> | date: YYYY-MM-DD | tool: markitdown|yt-dlp|apple-voice-memos|whisper
> Auto-converted. Edit summary below; re-run ingest to replace block above.

## Summary
<!-- AI or human -->

## Raw
<!-- converted text -->
```

---

## 5. Ingestion pipeline

### Entry points

| User action | Agent/script |
|-------------|----------------|
| Drops file in `00-INBOX/_drop/` | Run `python 91-SCRIPTS/ingest.py --process-inbox` |
| `ingest.py pdf FILE --course EGE322` | Writes to `_processing/`, then file to module |
| YouTube URL | `ingest.py youtube URL --course EGE353 --title "..."` |
| **Voice Memos transcript** (`.txt`) | User copies Apple transcript → `_drop/` → `ingest.py transcript FILE --course CODE` (preferred over audio) |
| Audio file (optional) | `ingest.py audio FILE` only if Whisper configured — **default: ask user for Voice Memos transcript instead** |
| Photo (board/slides) | `ingest.py image FILE --course CODE` |
| Web article | `ingest.py url URL` |

### Filing rules after ingest

1. Attachments → `99-ATTACHMENTS/<course or Media>/`
2. Markdown → module folder or `03-RESOURCES/Media/`
3. Add wikilink from user's tutorial note if one exists (search by week/title).
4. Set `source:` and `status: draft` in frontmatter.
5. Offer to generate **Summary** + **Flashcards** sections in the **tutorial** note, not duplicate files.

### Post-ingest cleanup pass (mandatory for agents)

`ingest.py` + MarkItDown only produces a **raw dump**. The agent **must run one cleanup round** on the output `.md` before reporting done:

1. **Keep** the `[!ingest]` callout block unchanged (re-run ingest replaces it).
2. **Write `## Summary`** — 2–5 sentences: topic, key tasks, links to related vault notes.
3. **Restructure body** — replace PDF line-break junk with:
   - Proper `#` / `##` headings
   - Tables (wiring, specs, MCQ options)
   - Fenced code blocks for scripts
   - Remove form-feed (`\f`), page headers/footers, duplicate titles
4. **Set frontmatter** — correct `type` (`lecture` | `lab` | `assignment` | `tutorial`), `course`, `module`, `tags`, `status: draft`.
5. **Link** — PDF in `99-ATTACHMENTS/`, project note in `01-PROJECTS/` if assignment, existing tutorial/lab note if duplicate topic.
6. **Raw section** — either delete after structuring, or collapse to `## Raw (archive)` with only content not captured above. Do not leave an unedited MarkItDown dump as the only body.
7. **Inbox** — move originals to `99-ATTACHMENTS/<course>/`; clear `00-INBOX/` (see `00-INBOX/README.md`).

Do **not** consider ingest complete until the cleanup pass is done.

### Tools

- **MarkItDown** — PDF, PPTX, DOCX, images, URLs
- **yt-dlp** — YouTube transcripts
- **Apple Voice Memos** — user copies auto-transcript to `.txt` → `ingest.py transcript` (see `91-SCRIPTS/VOICE-MEMOS-WORKFLOW.md`)
- **Whisper** (optional) — only if user explicitly wants PC audio transcription; `91-SCRIPTS/.env`

**Do not** store API keys in the vault. Use `91-SCRIPTS/.env` (gitignored). **Do not** push user to OpenAI if they use Voice Memos transcripts.

---

## 6. What you SHOULD do

### Study support

- Generate **summaries**, **flashcards** (`## Flashcards` with Q/A), and **practice questions** from vault content only.
- Query `07-DASHBOARDS/Schedule & Assessments Dashboard.md` for due dates; create reminders as tasks with `📅`.
- Proactively report: *"EGE322 Test 1 in X days — these notes are `#gap`"*.
- Suggest **what to study next** from assessment scope + note `status` fields.

### Organization

- Process `00-INBOX/` → correct folders using `type` + `course`.
- Normalize filenames: `YYYY-MM-DD-topic.md` for coaching; `weekN-topic.md` for lectures when helpful.
- Merge duplicate notes when user approves; prefer one tutorial + one ingest file.
- Update `_MOC.md` when new assessments or key notes appear.

### Coaching (`04-AREAS/Coaching/`)

- Log: duration, location, what you did, takeaways, follow-ups.
- Default filename: `YYYY-MM-DD-client-A.md` unless user supplies a name.
- **Privacy:** no real client PII in Git without user confirmation.

### Dev projects (`06-PROJECTS-DEV/`)

When user gives a **Git URL**:

1. Fetch README, manifest, recent commits (if tools allow).
2. Update/create note with `repo:`, **Summary**, **Todos** (`- [ ]`).
3. Do not clone secrets; skip `.env` in repos.

### Calendar (CalDAV)

- Read-only unless user grants write.
- Morning briefing (Telegram PA): today's events + assessments due in 7 days + open `#gap` in those courses.

---

## 7. What you MUST NOT do

- Invent lecture facts, lab answers, or ICA content not in vault/ingest.
- Create a second note for the same lecture without checking search.
- Mass-rename/move module folders without approval.
- Archive to `heimdall-memory` without approval.
- Add more than **5–10** concept notes per month without user review (avoid KB sprawl).
- Dump long AI prose into inbox or daily notes without structure.
- Commit API keys, client full names, or credentials.

---

## 8. Dashboards & search order

| File | Role |
|------|------|
| `07-DASHBOARDS/NYPY3 - Main Index.md` | Course hub, cross-links |
| `07-DASHBOARDS/Schedule & Assessments Dashboard.md` | Due dates, study priorities |
| `07-DASHBOARDS/NYP Timetable S1 2026.md` | Weekly schedule |

**Dataview** (if available): query `due`, `status`, `type`, `#gap`.

---

## 9. Approved concept seeds (`05-KB/concepts/`)

Create or update only when content exists in vault:

`MQTT.md` · `ROS.md` · `ESP32-MicroPython.md` · `PID-control.md` · `SLAM.md` · `PLC-ladder.md` · `wireless-QoS.md` · `embedded-C.md` · `project-management.md`

Each concept note structure:

```markdown
## Definition
## In my courses
- [[module/note|context]]

## Flashcards

## Sources
```

---

## 10. Semester archive procedure

Run only with user approval:

```bash
python 91-SCRIPTS/archive-course.py <MODULE-FOLDER> --semester 2026-S1 --memory-root <path-to-heimdall-memory>
```

1. Move `03-RESOURCES/<MODULE>/` → `heimdall-memory/NYP/2026-S1/<MODULE>/`
2. Write stub `03-RESOURCES/<MODULE>.md` with `archived: true`, link to memory path
3. Remove module from active dashboards or mark archived
4. Commit both repos

---

## 11. Telegram PA integration

The PA service should expose tools: `vault_search`, `vault_read`, `vault_write`, `ingest_run`, `calendar_today`, `git_pull`, `git_commit`.

**Session start:** `git pull` → read `07-DASHBOARDS/Schedule & Assessments Dashboard.md` → load today's `02-DAILY` if exists.

**User messages like** "study tonight" → §1 workflow + assessments in 48h + gap report.

**User messages like** "ingest this" → save to `_drop/` → run ingest → reply with filed paths.

**Approval gates:** folder moves, archive, delete, merge notes.

---

## 12. Response templates

### Study plan

```
## Due soon
## Notes to review (exam-ready / draft)
## Gaps (#gap)
## Suggested 90-min block
```

### After ingest

```
## Filed
- path (markdown + attachment)

## Cleaned up
- summary, headings, code blocks, links added

## Linked to
- [[tutorial note]] or "none — create?"

## Suggested next
- [ ] Add flashcards to tutorial note (not duplicate file)
```

### After inbox process

```
## Moved (n items)
## Needs your input (n items)
## Reminders created
```

---

## 13. Conflict resolution

| Situation | Rule |
|-----------|------|
| Ingest vs handwritten note conflict | **Handwritten wins**; ingest is reference |
| Two summaries for same lecture | Merge into tutorial; delete duplicate with approval |
| Git merge conflict | Never auto-resolve note content; alert user |
| PA vs Cursor both edit | Last writer wins on Git; prefer single agent per task |

---

## 14. Versioning

| Date | Change |
|------|--------|
| 2026-05-21 | Post-ingest cleanup pass required after MarkItDown |

When you change vault conventions, update this file and add a row above.

---

*End of AGENTS.md — treat this file as law for all agents maintaining Heimdall.*
