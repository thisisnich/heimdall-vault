---
id: "0b505d92-010a-4282-a1fb-b258a13c968d"
title: "Document Conversion Integration"
type: vault_note
vault: wiki
created: 2026-05-17
updated: 2026-05-17
checksum: "sha256:7ca229c0843199fa"
source: heimdall/auto
---

# Document Conversion Integration

- # Document Conversion & Integration Prompt

> **How to use:** Drop your files into `_to_upload/`, then paste this prompt to any AI agent with vault access.

---

## THE PROMPT

```
You are integrating new documents into my Obsidian knowledge base (vault) at the NYPY3 folder.

STEP 1 — READ THE INDEX
Read `.vault-index.md` to understand the vault structure, existing courses, and note conventions before doing anything.

STEP 2 — CHECK THE INBOX
List all files in `_to_upload/` (ignore README.md, converted/, done/).
Tell me what you found and what format each file is.

STEP 3 — CONVERT
Run the conversion script:
    python _tools/convert_to_md.py

This will:
- Convert each file to Markdown using markitdown
- Place the output in `_to_upload/converted/`
- Move the original to `_to_upload/done/`

Confirm each file converted successfully. Report any failures.

STEP 4 — FIX FORMATTING ARTIFACTS
⚠️ STRICT RULE: Do NOT change, reword, summarise, or remove any of the original words. Only fix how they are presented visually. <!-- id:0b505d92-010a-4282-a1fb-b258a13c968d ts:2026-05-17 07:49 -->
- # Document Conversion & Integration Prompt

> **How to use:** Drop your files into `_to_upload/`, then paste this prompt to any AI agent with vault access.

---

## THE PROMPT

```
You are integrating new documents into my Obsidian knowledge base (vault) at the NYPY3 folder.

STEP 1 — READ THE INDEX
Read `.vault-index.md` to understand the vault structure, existing courses, and note conventions before doing anything.

STEP 2 — CHECK THE INBOX
List all files in `_to_upload/` (ignore README.md, converted/, done/).
Tell me what you found and what format each file is.

STEP 3 — CONVERT
Run the conversion script:
    python _tools/convert_to_md.py

This will:
- Convert each file to Markdown using markitdown
- Place the output in `_to_upload/converted/`
- Move the original to `_to_upload/done/`

Confirm each file converted successfully. Report any failures.

STEP 4 — FIX FORMATTING ARTIFACTS
⚠️ STRICT RULE: Do NOT change, reword, summarise, or remove any of the original words. Only fix how they are presented visually. <!-- id:0b505d92-010a-4282-a1fb-b258a13c968d ts:2026-05-17 07:49 -->
