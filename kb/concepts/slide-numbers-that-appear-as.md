---
id: "40e6b82b-a844-48c2-a50a-22c692d93420"
title: "Slide Numbers That Appear As"
type: vault_note
vault: wiki
created: 2026-05-17
updated: 2026-05-17
checksum: "sha256:b3f620591b507e13"
source: heimdall/auto
---

# Slide Numbers That Appear As

- slide numbers that appear as standalone lines (e.g. just "12" or "Slide 12")
   - Remove watermarks or boilerplate text that repeats throughout (e.g. "CONFIDENTIAL", "DRAFT")

d) TABLE DETECTION & FORMATTING
   - Actively look for data that should be a table — even if it didn't come through as one:
     * Side-by-side comparisons (e.g. "Feature A ... Feature B ...")
     * Repeated label: value patterns (e.g. "Name: X  Weight: Y  Date: Z")
     * Assessment/schedule lists with consistent columns
     * Spec sheets or component lists
   - If you recognise tabular data, reformat it as a proper Markdown table with headers
   - For tables that came through partially broken (columns on separate lines), reconstruct them
   - Rejoin bullet points that were split across lines
   - Fix numbered lists where the number got separated from the text
   - Convert plain dashes used as visual separators (--- or ___) to Markdown `---` horizontal rules

e) VISUAL FORMATTING PASS
   After fixing artifacts, do a light pass to make the document easier to read:
   - Wrap key terms, values, or technical names in **bold** if they clearly stand out in the original
   - Use `inline code` for any code snippets, commands, pin numbers, register names, or syntax
   - Use > blockquote callouts for tips, warnings, or notes that were visually highlighted in the original (e.g. <!-- id:40e6b82b-a844-48c2-a50a-22c692d93420 ts:2026-05-17 07:49 -->
- slide numbers that appear as standalone lines (e.g. just "12" or "Slide 12")
   - Remove watermarks or boilerplate text that repeats throughout (e.g. "CONFIDENTIAL", "DRAFT")

d) TABLE DETECTION & FORMATTING
   - Actively look for data that should be a table — even if it didn't come through as one:
     * Side-by-side comparisons (e.g. "Feature A ... Feature B ...")
     * Repeated label: value patterns (e.g. "Name: X  Weight: Y  Date: Z")
     * Assessment/schedule lists with consistent columns
     * Spec sheets or component lists
   - If you recognise tabular data, reformat it as a proper Markdown table with headers
   - For tables that came through partially broken (columns on separate lines), reconstruct them
   - Rejoin bullet points that were split across lines
   - Fix numbered lists where the number got separated from the text
   - Convert plain dashes used as visual separators (--- or ___) to Markdown `---` horizontal rules

e) VISUAL FORMATTING PASS
   After fixing artifacts, do a light pass to make the document easier to read:
   - Wrap key terms, values, or technical names in **bold** if they clearly stand out in the original
   - Use `inline code` for any code snippets, commands, pin numbers, register names, or syntax
   - Use > blockquote callouts for tips, warnings, or notes that were visually highlighted in the original (e.g. <!-- id:40e6b82b-a844-48c2-a50a-22c692d93420 ts:2026-05-17 07:49 -->
