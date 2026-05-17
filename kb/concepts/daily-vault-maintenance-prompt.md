---
id: "4aed60da-8d0a-4e97-ae87-04259a001d16"
title: "Daily Vault Maintenance Prompt"
type: vault_note
vault: wiki
created: 2026-05-17
updated: 2026-05-17
checksum: "sha256:336df1d10dd8f743"
source: heimdall/auto
---

# Daily Vault Maintenance Prompt

- # Daily Vault Maintenance Prompt

> **How to use:** Copy everything inside the PROMPT block below and paste it to your AI agent (Cascade, ChatGPT, Claude, etc.) that has access to your Obsidian vault.

---

## THE PROMPT

```
You are maintaining my Obsidian knowledge base (vault). Your job is to keep it organized, up to date, and useful for my studies.

STEP 1 — READ THE INDEX
Read the file `.vault-index.md` in the vault root. This is your map. It tells you the vault structure, all courses, assessments, known gaps, and maintenance history. Read it fully before doing anything.

STEP 2 — DETERMINE CURRENT WEEK
Today's date determines the current semester week.
- Week 1 started: 20 Apr 2026
- Term break: Weeks 9-10 (15-26 Jun 2026)
- Calculate the current week number from today's date.

STEP 3 — CHECK THE CONVERSION INBOX
Check `_to_upload/` for any files (ignore README.md, converted/, done/).
- If files are present: stop and tell me — "You have X file(s) waiting in _to_upload/. Run the conversion prompt (`_tools/conversion-prompt.md`) to convert and integrate them before continuing maintenance."
- If `_to_upload/converted/` has unconverted .md files that haven't been moved yet: flag those too.
- If both are empty: move on silently.

STEP 4 — CHECK FOR NEW OR CHANGED FILES
Scan all .md files in the vault. <!-- id:4aed60da-8d0a-4e97-ae87-04259a001d16 ts:2026-05-17 07:49 -->
- # Daily Vault Maintenance Prompt

> **How to use:** Copy everything inside the PROMPT block below and paste it to your AI agent (Cascade, ChatGPT, Claude, etc.) that has access to your Obsidian vault.

---

## THE PROMPT

```
You are maintaining my Obsidian knowledge base (vault). Your job is to keep it organized, up to date, and useful for my studies.

STEP 1 — READ THE INDEX
Read the file `.vault-index.md` in the vault root. This is your map. It tells you the vault structure, all courses, assessments, known gaps, and maintenance history. Read it fully before doing anything.

STEP 2 — DETERMINE CURRENT WEEK
Today's date determines the current semester week.
- Week 1 started: 20 Apr 2026
- Term break: Weeks 9-10 (15-26 Jun 2026)
- Calculate the current week number from today's date.

STEP 3 — CHECK THE CONVERSION INBOX
Check `_to_upload/` for any files (ignore README.md, converted/, done/).
- If files are present: stop and tell me — "You have X file(s) waiting in _to_upload/. Run the conversion prompt (`_tools/conversion-prompt.md`) to convert and integrate them before continuing maintenance."
- If `_to_upload/converted/` has unconverted .md files that haven't been moved yet: flag those too.
- If both are empty: move on silently.

STEP 4 — CHECK FOR NEW OR CHANGED FILES
Scan all .md files in the vault. <!-- id:4aed60da-8d0a-4e97-ae87-04259a001d16 ts:2026-05-17 07:49 -->
