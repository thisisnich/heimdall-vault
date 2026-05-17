---
id: "7d732652-13fe-4e3c-85fa-d394186c47b3"
title: "Formatting Artifacts Strict Rule"
type: vault_note
vault: wiki
created: 2026-05-17
updated: 2026-05-17
checksum: "sha256:42ee70e084c31c18"
source: heimdall/auto
---

# Formatting Artifacts Strict Rule

- FORMATTING ARTIFACTS
⚠️ STRICT RULE: Do NOT change, reword, summarise, or remove any of the original words. Only fix how they are presented visually. If you are unsure whether something is an artifact or intentional content, leave it.

For each file in `_to_upload/converted/`, do a first pass purely to fix raw conversion artifacts:

a) LINE BREAK ISSUES
   - Join lines that were split mid-sentence or mid-word (common in PDFs with narrow columns)
   - Fix hyphenated line breaks: "com-\nmunication" → "communication"
   - Remove stray single newlines in the middle of paragraphs (should be one continuous paragraph)
   - Preserve intentional paragraph breaks (blank lines between sections)

b) SPACING ISSUES
   - Remove double spaces within sentences
   - Remove trailing spaces at end of lines
   - Fix words that got merged without a space: "thesystem" → "the system"
   - Normalise multiple blank lines to at most two

c) HEADER / STRUCTURE ARTIFACTS
   - Fix headers that got broken across lines (e.g. "## Chapter\n1" → "## Chapter 1")
   - Remove repeated page headers/footers that PDF extraction duplicates (e.g. "NYP School of Engineering" appearing every page)
   - Remove slide numbers that appear as standalone lines (e.g. just "12" or "Slide 12")
   - Remove watermarks or boilerplate text that repeats throughout (e.g. <!-- id:7d732652-13fe-4e3c-85fa-d394186c47b3 ts:2026-05-17 07:49 -->
- FORMATTING ARTIFACTS
⚠️ STRICT RULE: Do NOT change, reword, summarise, or remove any of the original words. Only fix how they are presented visually. If you are unsure whether something is an artifact or intentional content, leave it.

For each file in `_to_upload/converted/`, do a first pass purely to fix raw conversion artifacts:

a) LINE BREAK ISSUES
   - Join lines that were split mid-sentence or mid-word (common in PDFs with narrow columns)
   - Fix hyphenated line breaks: "com-\nmunication" → "communication"
   - Remove stray single newlines in the middle of paragraphs (should be one continuous paragraph)
   - Preserve intentional paragraph breaks (blank lines between sections)

b) SPACING ISSUES
   - Remove double spaces within sentences
   - Remove trailing spaces at end of lines
   - Fix words that got merged without a space: "thesystem" → "the system"
   - Normalise multiple blank lines to at most two

c) HEADER / STRUCTURE ARTIFACTS
   - Fix headers that got broken across lines (e.g. "## Chapter\n1" → "## Chapter 1")
   - Remove repeated page headers/footers that PDF extraction duplicates (e.g. "NYP School of Engineering" appearing every page)
   - Remove slide numbers that appear as standalone lines (e.g. just "12" or "Slide 12")
   - Remove watermarks or boilerplate text that repeats throughout (e.g. <!-- id:7d732652-13fe-4e3c-85fa-d394186c47b3 ts:2026-05-17 07:49 -->
