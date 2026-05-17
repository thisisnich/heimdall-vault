---
id: "81890804-644b-4bd3-b0dc-2a74bf664836"
title: "Sion Workflow 1 Drop Files"
type: vault_note
vault: wiki
created: 2026-05-17
updated: 2026-05-17
checksum: "sha256:7d7abae417461aac"
source: heimdall/auto
---

# Sion Workflow 1 Drop Files

- sion Workflow:
1. Drop files in `_to_upload/`
2. Paste the PROMPT section to your AI agent
3. Let agent run the workflow
4. Confirm file placements
5. Done!

---

## 💡 OPTIMIZATIONS & TIPS

### File Naming Conventions
Good: `EGE320-Lab1-Development-Environment.pdf`  
Good: `Lecture-2-Wireless-Fundamentals.pptx`  
Avoid: `Document.pdf`, `Slide1.pptx`

### Vault Structure Best Practices
- Use `.vault-index.md` at root — agents read it first for context
- Keep consistent folder naming (use course codes if applicable)
- Create MOC (Map of Content) files for each subject area

### For Large Batches
- Convert in batches of 5-10 files for easier review
- Use subfolders in `_to_upload/` to organize by course before converting

### Troubleshooting
- **"markitdown not found"** → Run `pip install markitdown`
- **"pymupdf not found"** → Run `pip install pymupdf` (needed for image extraction)
- **"Permission denied"** → Check file isn't open in another program
- **Scanned PDFs** → Text extraction limited; page images will still be extracted
- **Large files (>50MB)** → May take longer; consider splitting
- **No images extracted** → Ensure pymupdf is installed; only PDFs get page images

---

## 📄 OPTIONAL: .vault-index.md Template

Create this at vault root for better agent context:

```yaml
---
type: vault-index
version: 1
owner: [Your Name]
program: [Your Program/Course]
institution: [School/Org]
last_updated: [YYYY-MM-DD]
---

# [Vault Name] Index

## Subjects/Courses

### [CODE] — [Cou <!-- id:81890804-644b-4bd3-b0dc-2a74bf664836 ts:2026-05-17 07:49 -->
- sion Workflow:
1. Drop files in `_to_upload/`
2. Paste the PROMPT section to your AI agent
3. Let agent run the workflow
4. Confirm file placements
5. Done!

---

## 💡 OPTIMIZATIONS & TIPS

### File Naming Conventions
Good: `EGE320-Lab1-Development-Environment.pdf`  
Good: `Lecture-2-Wireless-Fundamentals.pptx`  
Avoid: `Document.pdf`, `Slide1.pptx`

### Vault Structure Best Practices
- Use `.vault-index.md` at root — agents read it first for context
- Keep consistent folder naming (use course codes if applicable)
- Create MOC (Map of Content) files for each subject area

### For Large Batches
- Convert in batches of 5-10 files for easier review
- Use subfolders in `_to_upload/` to organize by course before converting

### Troubleshooting
- **"markitdown not found"** → Run `pip install markitdown`
- **"pymupdf not found"** → Run `pip install pymupdf` (needed for image extraction)
- **"Permission denied"** → Check file isn't open in another program
- **Scanned PDFs** → Text extraction limited; page images will still be extracted
- **Large files (>50MB)** → May take longer; consider splitting
- **No images extracted** → Ensure pymupdf is installed; only PDFs get page images

---

## 📄 OPTIONAL: .vault-index.md Template

Create this at vault root for better agent context:

```yaml
---
type: vault-index
version: 1
owner: [Your Name]
program: [Your Program/Course]
institution: [School/Org]
last_updated: [YYYY-MM-DD]
---

# [Vault Name] Index

## Subjects/Courses

### [CODE] — [Cou <!-- id:81890804-644b-4bd3-b0dc-2a74bf664836 ts:2026-05-17 07:49 -->
