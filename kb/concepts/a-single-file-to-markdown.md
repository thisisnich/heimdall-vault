---
id: "e098ca9d-f63a-47e7-8b8d-1614b8ab42fd"
title: "A Single File To Markdown"
type: vault_note
vault: wiki
created: 2026-05-17
updated: 2026-05-17
checksum: "sha256:5bf6ce578b872038"
source: heimdall/auto
---

# A Single File To Markdown

- a single file to markdown using markitdown."""
    output_name = file_path.stem + ".md"
    output_path = CONVERTED_DIR / output_name

    # Create markdown with YAML frontmatter template
    today = datetime.now().strftime("%Y-%m-%d")
    yaml_frontmatter = f"""---
tags:
  - FILL_IN
course: FILL_IN
topic: FILL_IN
source: {file_path.name}
converted: {today}
---

> 📌 **TODO:** Fill in tags, course, and topic above, then move this file to the correct course folder.

---

"""

    try:
        # Run markitdown
        result = subprocess.run(
            ["markitdown", str(file_path)],
            capture_output=True,
            text=True,
            encoding='utf-8'
        )

        if result.returncode != 0:
            print(f"  ❌ Error converting {file_path.name}: {result.stderr}")
            return False

        # Write output with YAML frontmatter
        output_path.write_text(yaml_frontmatter + result.stdout, encoding='utf-8')

        # Extract page images for PDFs
        img_count = 0
        if file_path.suffix.lower() in PDF_EXTENSIONS:
            img_count = extract_pdf_pages_as_images(file_path)

        # Move original to done/
        shutil.move(str(file_path), str(DONE_DIR / file_path.name))

        status = f"  ✅ {file_path.name} → {output_path.name}"
        if img_count > 0:
            status += f" ({img_count} page images extracted)"
        print(status)
        return True

    except Exception as e:
        print(f"  ❌ Exception converting {fil <!-- id:e098ca9d-f63a-47e7-8b8d-1614b8ab42fd ts:2026-05-17 07:49 -->
- a single file to markdown using markitdown."""
    output_name = file_path.stem + ".md"
    output_path = CONVERTED_DIR / output_name

    # Create markdown with YAML frontmatter template
    today = datetime.now().strftime("%Y-%m-%d")
    yaml_frontmatter = f"""---
tags:
  - FILL_IN
course: FILL_IN
topic: FILL_IN
source: {file_path.name}
converted: {today}
---

> 📌 **TODO:** Fill in tags, course, and topic above, then move this file to the correct course folder.

---

"""

    try:
        # Run markitdown
        result = subprocess.run(
            ["markitdown", str(file_path)],
            capture_output=True,
            text=True,
            encoding='utf-8'
        )

        if result.returncode != 0:
            print(f"  ❌ Error converting {file_path.name}: {result.stderr}")
            return False

        # Write output with YAML frontmatter
        output_path.write_text(yaml_frontmatter + result.stdout, encoding='utf-8')

        # Extract page images for PDFs
        img_count = 0
        if file_path.suffix.lower() in PDF_EXTENSIONS:
            img_count = extract_pdf_pages_as_images(file_path)

        # Move original to done/
        shutil.move(str(file_path), str(DONE_DIR / file_path.name))

        status = f"  ✅ {file_path.name} → {output_path.name}"
        if img_count > 0:
            status += f" ({img_count} page images extracted)"
        print(status)
        return True

    except Exception as e:
        print(f"  ❌ Exception converting {fil <!-- id:e098ca9d-f63a-47e7-8b8d-1614b8ab42fd ts:2026-05-17 07:49 -->
