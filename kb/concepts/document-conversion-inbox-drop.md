---
id: "7d1fd00c-fc35-4a8c-8377-73c721b69239"
title: "Document Conversion Inbox Drop"
type: vault_note
vault: wiki
created: 2026-05-17
updated: 2026-05-17
checksum: "sha256:eeb9c1d53718c4ea"
source: heimdall/auto
---

# Document Conversion Inbox Drop

- # Document Conversion Inbox

Drop files here to convert them into Obsidian-ready Markdown.

## Workflow

1. **Drop files** (PDF, PPTX, DOCX, XLSX, CSV, images) into this folder (`_to_upload/`)
2. **Run the script:**
   ```
   python _tools/convert_to_md.py
   ```
3. **Converted `.md` files** appear in `_to_upload/converted/`
4. **Original files** are automatically moved to `_to_upload/done/`
5. **Edit** each converted file — fill in the YAML frontmatter stubs (`tags`, `course`, `topic`)
6. **Move** the file into the correct course folder in the vault

## Supported Formats

| Format | Extension(s) |
|--------|-------------|
| PDF | `.pdf` |
| PowerPoint | `.pptx`, `.ppt` |
| Word | `.docx`, `.doc` |
| Excel | `.xlsx`, `.xls` |
| CSV | `.csv` |
| HTML | `.html`, `.htm` |
| Images | `.jpg`, `.jpeg`, `.png`, `.gif`, `.bmp`, `.webp` |

## Agent Instructions

> If you are an AI agent performing vault maintenance and you see files in `_to_upload/` (excluding `README.md`, `converted/`, and `done/`):
> 1. Tell the user files are waiting to be converted
> 2. Run: `python _tools/convert_to_md.py`
> 3. Review the output in `_to_upload/converted/` — fill in frontmatter, cross-links, and move to the correct course folder
> 4. Update `.vault-index.md` with the new notes <!-- id:7d1fd00c-fc35-4a8c-8377-73c721b69239 ts:2026-05-17 07:49 -->
- # Document Conversion Inbox

Drop files here to convert them into Obsidian-ready Markdown.

## Workflow

1. **Drop files** (PDF, PPTX, DOCX, XLSX, CSV, images) into this folder (`_to_upload/`)
2. **Run the script:**
   ```
   python _tools/convert_to_md.py
   ```
3. **Converted `.md` files** appear in `_to_upload/converted/`
4. **Original files** are automatically moved to `_to_upload/done/`
5. **Edit** each converted file — fill in the YAML frontmatter stubs (`tags`, `course`, `topic`)
6. **Move** the file into the correct course folder in the vault

## Supported Formats

| Format | Extension(s) |
|--------|-------------|
| PDF | `.pdf` |
| PowerPoint | `.pptx`, `.ppt` |
| Word | `.docx`, `.doc` |
| Excel | `.xlsx`, `.xls` |
| CSV | `.csv` |
| HTML | `.html`, `.htm` |
| Images | `.jpg`, `.jpeg`, `.png`, `.gif`, `.bmp`, `.webp` |

## Agent Instructions

> If you are an AI agent performing vault maintenance and you see files in `_to_upload/` (excluding `README.md`, `converted/`, and `done/`):
> 1. Tell the user files are waiting to be converted
> 2. Run: `python _tools/convert_to_md.py`
> 3. Review the output in `_to_upload/converted/` — fill in frontmatter, cross-links, and move to the correct course folder
> 4. Update `.vault-index.md` with the new notes <!-- id:7d1fd00c-fc35-4a8c-8377-73c721b69239 ts:2026-05-17 07:49 -->
