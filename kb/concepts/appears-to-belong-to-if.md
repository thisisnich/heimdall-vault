---
id: "ee85ca89-a7f9-4e63-aa6c-532161c61662"
title: "Appears To Belong To If"
type: vault_note
vault: wiki
created: 2026-05-17
updated: 2026-05-17
checksum: "sha256:df08c403da06ace6"
source: heimdall/auto
---

# Appears To Belong To If

- appears to belong to (if obvious from filename)
- Whether it's a new file or an update to existing content

ASK: "I found [X] files ready to convert. Shall I proceed?"

━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━

STEP 3 — CONVERT FILES
━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━

Run the conversion script:
    python _tools/convert_to_md.py

The script will:
- Convert each file to Markdown using markitdown
- Extract PDF pages as images to `_to_upload/converted/images/<filename>/`
- Save output to `_to_upload/converted/`
- Move originals to `_to_upload/done/`

CONFIRM: List each file that converted successfully and how many page images were extracted. Report any failures immediately.

━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━

STEP 4 — CLEAN UP EACH CONVERTED FILE
━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━

For each file in `_to_upload/converted/`:

a) FILL YAML FRONTMATTER
   Replace FILL_IN stubs with actual values:
   ```yaml
   ---
   tags:
     - [course-code]
     - [content-type: lecture/lab/tutorial/reading]
     - [topic-keyword-1]
     - [topic-keyword-2]
   course: [Full Course Name]
   topic: [Brief description of content]
   source: [original filename]
   converted: [YYYY-MM-DD]
   ---
   ```

b) STRUCTURE THE CONTENT
   - Add clear H1 heading if missing
   - Convert "wall of text" into logical sections with H2/H3 <!-- id:ee85ca89-a7f9-4e63-aa6c-532161c61662 ts:2026-05-17 07:49 -->
- appears to belong to (if obvious from filename)
- Whether it's a new file or an update to existing content

ASK: "I found [X] files ready to convert. Shall I proceed?"

━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━

STEP 3 — CONVERT FILES
━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━

Run the conversion script:
    python _tools/convert_to_md.py

The script will:
- Convert each file to Markdown using markitdown
- Extract PDF pages as images to `_to_upload/converted/images/<filename>/`
- Save output to `_to_upload/converted/`
- Move originals to `_to_upload/done/`

CONFIRM: List each file that converted successfully and how many page images were extracted. Report any failures immediately.

━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━

STEP 4 — CLEAN UP EACH CONVERTED FILE
━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━

For each file in `_to_upload/converted/`:

a) FILL YAML FRONTMATTER
   Replace FILL_IN stubs with actual values:
   ```yaml
   ---
   tags:
     - [course-code]
     - [content-type: lecture/lab/tutorial/reading]
     - [topic-keyword-1]
     - [topic-keyword-2]
   course: [Full Course Name]
   topic: [Brief description of content]
   source: [original filename]
   converted: [YYYY-MM-DD]
   ---
   ```

b) STRUCTURE THE CONTENT
   - Add clear H1 heading if missing
   - Convert "wall of text" into logical sections with H2/H3 <!-- id:ee85ca89-a7f9-4e63-aa6c-532161c61662 ts:2026-05-17 07:49 -->
