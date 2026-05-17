---
id: "e13cf389-9579-4b76-8fd8-6f1337aa1699"
title: "For New Files Remind Me"
type: vault_note
vault: wiki
created: 2026-05-17
updated: 2026-05-17
checksum: "sha256:273eca11b7acebd9"
source: heimdall/auto
---

# For New Files Remind Me

- for new files, remind me of upcoming deadlines and what to study, ask about any gaps in my knowledge base, then update the vault index and dashboard. Keep it brief.
```

---

## NOTES FOR THE AGENT

- The vault root is the NYPY3 folder
- `.vault-index.md` is the single source of truth for vault structure
- `📅 Schedule & Assessments Dashboard.md` is the human-facing schedule
- MOC (Map of Content) files exist for each course at the vault root
- All notes use YAML frontmatter with tags
- Cross-links use Obsidian `[[wikilink]]` format
- The owner is a student — be encouraging but direct
- **Document conversion:** There are two separate prompts — this one (daily maintenance) and `_tools/conversion-prompt.md` (full conversion + cleanup). Daily maintenance only flags waiting files; the conversion prompt handles the actual convert → clean → integrate → index workflow.
- `_to_upload/` is the inbox for new documents (PDF, PPTX, DOCX, etc.)
- `_to_upload/converted/` holds raw converted .md files awaiting cleanup
- `_to_upload/done/` holds originals already processed — ignore these <!-- id:e13cf389-9579-4b76-8fd8-6f1337aa1699 ts:2026-05-17 07:49 -->
