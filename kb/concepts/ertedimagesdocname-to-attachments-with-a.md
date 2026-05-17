---
id: "8b41e3b3-42b2-44a0-aeb2-8468567f269d"
title: "Ertedimagesdocname To Attachments With A"
type: vault_note
vault: wiki
created: 2026-05-17
updated: 2026-05-17
checksum: "sha256:6b216d7e26b3ef09"
source: heimdall/auto
---

# Ertedimagesdocname To Attachments With A

- erted/images/<docname>/`
      to `_attachments/` with a descriptive name:
      `<docname>-fig-<number>.png`  (e.g. `EGE320-Lab1-fig-2.1a.png`)
   3. Embed the image directly below the figure reference using Obsidian syntax:
      `![[<docname>-fig-<number>.png|Figure caption]]`
   
   Example — before:
   ```
   Figure 2.1a: Code Composer Studio (CCS) Software Icon
   ```
   After:
   ```
   **Figure 2.1a:** Code Composer Studio (CCS) Software Icon
   ![[EGE320-Lab1-fig-2.1a.png|Code Composer Studio Software Icon]]
   ```
   
   RULES for images:
   - Only embed images where figures are explicitly referenced in text
   - If multiple figures appear on one page, embed the same page image for each
   - If a figure spans multiple pages, pick the page with the main content
   - Delete any leftover unused page images from `_to_upload/converted/images/`

c) ADD CROSS-LINKS
   Add a "Related" line near the top with wikilinks:
   > 📚 **Related:** [[ExistingNote|Label]] | [[AnotherNote|Label]]
   
   Link to:
   - Course MOC/index file
   - Previous related notes in same course
   - Core concepts referenced

d) CONFIRM PLACEMENT
   Determine the correct destination folder based on:
   - Filename indicators (e.g., "EGE320" → Embedded Systems folder)
   - Content analysis (scan first 500 chars for course codes)
   - Existing vault structure conventions
   
   RECOMMEND: "This file should go to [folder]/[filename].md"
   RECOMMEND: "[X] images will be saved to _attachments/"
   ASK: "Co <!-- id:8b41e3b3-42b2-44a0-aeb2-8468567f269d ts:2026-05-17 07:49 -->
- erted/images/<docname>/`
      to `_attachments/` with a descriptive name:
      `<docname>-fig-<number>.png`  (e.g. `EGE320-Lab1-fig-2.1a.png`)
   3. Embed the image directly below the figure reference using Obsidian syntax:
      `![[<docname>-fig-<number>.png|Figure caption]]`
   
   Example — before:
   ```
   Figure 2.1a: Code Composer Studio (CCS) Software Icon
   ```
   After:
   ```
   **Figure 2.1a:** Code Composer Studio (CCS) Software Icon
   ![[EGE320-Lab1-fig-2.1a.png|Code Composer Studio Software Icon]]
   ```
   
   RULES for images:
   - Only embed images where figures are explicitly referenced in text
   - If multiple figures appear on one page, embed the same page image for each
   - If a figure spans multiple pages, pick the page with the main content
   - Delete any leftover unused page images from `_to_upload/converted/images/`

c) ADD CROSS-LINKS
   Add a "Related" line near the top with wikilinks:
   > 📚 **Related:** [[ExistingNote|Label]] | [[AnotherNote|Label]]
   
   Link to:
   - Course MOC/index file
   - Previous related notes in same course
   - Core concepts referenced

d) CONFIRM PLACEMENT
   Determine the correct destination folder based on:
   - Filename indicators (e.g., "EGE320" → Embedded Systems folder)
   - Content analysis (scan first 500 chars for course codes)
   - Existing vault structure conventions
   
   RECOMMEND: "This file should go to [folder]/[filename].md"
   RECOMMEND: "[X] images will be saved to _attachments/"
   ASK: "Co <!-- id:8b41e3b3-42b2-44a0-aeb2-8468567f269d ts:2026-05-17 07:49 -->
