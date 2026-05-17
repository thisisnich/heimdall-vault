---
id: "83582740-8c4f-49f0-a0af-74006c309a2e"
title: "Yyyy Mm Dd     B Structure"
type: vault_note
vault: wiki
created: 2026-05-17
updated: 2026-05-17
checksum: "sha256:ce0122ee20ecc6ab"
source: heimdall/auto
---

# Yyyy Mm Dd     B Structure

- [YYYY-MM-DD]
   ---
   ```

b) STRUCTURE THE CONTENT
   - Add clear H1 heading if missing
   - Convert "wall of text" into logical sections with H2/H3 headers
   - Format tables that came through as plain text
   - Preserve ALL original content — do not summarize or remove
   - Remove page headers/footers ("Page X of Y", "Effective Date", etc.)
   - Fix obvious OCR artifacts (broken lines, repeated headers)

b2) EMBED IMAGES
   The script extracts each PDF page as a PNG in `_to_upload/converted/images/<docname>/`.
   
   Scan the converted text for figure/image references such as:
   - "Figure 1a:", "Figure 2.1b:", "Fig. 3:"
   - "as shown in Figure below"
   - "see diagram", "see image"
   
   For each reference found:
   1. Determine which page the figure is on (use page markers like "Page X of Y" 
      from the raw conversion, or infer from content order)
   2. Move the corresponding page image from `_to_upload/converted/images/<docname>/`
      to `_attachments/` with a descriptive name:
      `<docname>-fig-<number>.png`  (e.g. `EGE320-Lab1-fig-2.1a.png`)
   3. <!-- id:83582740-8c4f-49f0-a0af-74006c309a2e ts:2026-05-17 07:49 -->
- [YYYY-MM-DD]
   ---
   ```

b) STRUCTURE THE CONTENT
   - Add clear H1 heading if missing
   - Convert "wall of text" into logical sections with H2/H3 headers
   - Format tables that came through as plain text
   - Preserve ALL original content — do not summarize or remove
   - Remove page headers/footers ("Page X of Y", "Effective Date", etc.)
   - Fix obvious OCR artifacts (broken lines, repeated headers)

b2) EMBED IMAGES
   The script extracts each PDF page as a PNG in `_to_upload/converted/images/<docname>/`.
   
   Scan the converted text for figure/image references such as:
   - "Figure 1a:", "Figure 2.1b:", "Fig. 3:"
   - "as shown in Figure below"
   - "see diagram", "see image"
   
   For each reference found:
   1. Determine which page the figure is on (use page markers like "Page X of Y" 
      from the raw conversion, or infer from content order)
   2. Move the corresponding page image from `_to_upload/converted/images/<docname>/`
      to `_attachments/` with a descriptive name:
      `<docname>-fig-<number>.png`  (e.g. `EGE320-Lab1-fig-2.1a.png`)
   3. <!-- id:83582740-8c4f-49f0-a0af-74006c309a2e ts:2026-05-17 07:49 -->
