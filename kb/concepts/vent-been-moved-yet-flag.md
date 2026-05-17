---
id: "d803f31d-1067-4289-81fa-e6bda1433c42"
title: "Vent Been Moved Yet Flag"
type: vault_note
vault: wiki
created: 2026-05-17
updated: 2026-05-17
checksum: "sha256:49d9a8362ed7f82a"
source: heimdall/auto
---

# Vent Been Moved Yet Flag

- ven't been moved yet: flag those too.
- If both are empty: move on silently.

STEP 4 — CHECK FOR NEW OR CHANGED FILES
Scan all .md files in the vault. Compare against the file list in `.vault-index.md`.
- If there are NEW files not listed in the index, read them and add them to the index.
- If files have been modified since last maintenance, review the changes.
- For any new content: add YAML frontmatter (tags, course, topic), add cross-links to related notes in other courses, and update the relevant MOC page.

STEP 5 — ASK ME ABOUT GAPS
Review the "KNOWN GAPS & MISSING INFO" section of `.vault-index.md`. Ask me about EACH unchecked gap, one category at a time. Specifically ask me:

a) MISSING COURSE INFO — Do I now know any of these?
   - Instructor names, emails, class times for courses marked UNKNOWN
   - Assessment schedules for courses marked as unknown

b) MISSING NOTES — Did I take notes today that I haven't added yet?
   - Remind me which lessons/labs I should have notes for by now (based on the weekly schedule)
   - Ask if I have handwritten notes, photos, or BrightSpace materials to transcribe

c) MISSING PROJECT INFO — Any project updates?
   - Ask about project decisions, team assignments, topic choices
   - Ask about any new assignment briefs or rubrics received

d) GENERAL KNOWLEDGE HOLES — Based on what I've studied vs. <!-- id:d803f31d-1067-4289-81fa-e6bda1433c42 ts:2026-05-17 07:49 -->
