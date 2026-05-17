---
id: "fb7e0bda-b711-4221-bea7-6ea1f99a946a"
title: "Universal Document Conversion Prompt"
type: vault_note
vault: wiki
created: 2026-05-17
updated: 2026-05-17
checksum: "sha256:9a81fb6593380381"
source: heimdall/auto
---

# Universal Document Conversion Prompt

- # Universal Document Conversion Prompt Template

> **Purpose:** Drop this into `_tools/` folder of any Obsidian vault to enable AI-assisted document conversion.
> 
> **End Goal:** Upload PDFs → Agent reads prompt → Runs script → Reviews output → Formats & integrates

---

## 📋 QUICK START (For Vault Owner)

1. **Create folder structure:**
   ```
   YourVault/
   ├── _tools/
   │   ├── convert_to_md.py          ← Create this (script below)
   │   └── conversion-prompt.md      ← This file
   ├── _to_upload/                  ← Drop PDFs/PPTXs/DOCXs here
   │   ├── converted/               ← Output goes here (auto-created)
   │   │   └── images/              ← Extracted page images go here
   │   └── done/                    ← Originals moved here after conversion
   ├── _attachments/                ← Final image storage (Obsidian attachments)
   └── .vault-index.md              ← Optional: vault structure index
   ```

2. **Install dependencies:** `pip install markitdown pymupdf`

3. **Drop files** into `_to_upload/`

4. **Paste this prompt to any AI agent** with vault access

---

## 🤖 THE PROMPT (Copy-Paste Ready)

```
You are integrating new documents into this Obsidian vault. Follow these steps precisely.

━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━

STEP 1 — READ THE VAULT INDEX
━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━

Read `.vault-index.md` if it exists. <!-- id:fb7e0bda-b711-4221-bea7-6ea1f99a946a ts:2026-05-17 07:49 -->
- # Universal Document Conversion Prompt Template

> **Purpose:** Drop this into `_tools/` folder of any Obsidian vault to enable AI-assisted document conversion.
> 
> **End Goal:** Upload PDFs → Agent reads prompt → Runs script → Reviews output → Formats & integrates

---

## 📋 QUICK START (For Vault Owner)

1. **Create folder structure:**
   ```
   YourVault/
   ├── _tools/
   │   ├── convert_to_md.py          ← Create this (script below)
   │   └── conversion-prompt.md      ← This file
   ├── _to_upload/                  ← Drop PDFs/PPTXs/DOCXs here
   │   ├── converted/               ← Output goes here (auto-created)
   │   │   └── images/              ← Extracted page images go here
   │   └── done/                    ← Originals moved here after conversion
   ├── _attachments/                ← Final image storage (Obsidian attachments)
   └── .vault-index.md              ← Optional: vault structure index
   ```

2. **Install dependencies:** `pip install markitdown pymupdf`

3. **Drop files** into `_to_upload/`

4. **Paste this prompt to any AI agent** with vault access

---

## 🤖 THE PROMPT (Copy-Paste Ready)

```
You are integrating new documents into this Obsidian vault. Follow these steps precisely.

━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━

STEP 1 — READ THE VAULT INDEX
━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━

Read `.vault-index.md` if it exists. <!-- id:fb7e0bda-b711-4221-bea7-6ea1f99a946a ts:2026-05-17 07:49 -->
