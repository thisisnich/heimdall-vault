---
id: "54222518-f591-4177-90c7-0d77eacfa12b"
title: "E Output Directories Exist Converted Dirmkdirexist Oktrue"
type: vault_note
vault: wiki
created: 2026-05-17
updated: 2026-05-17
checksum: "sha256:f9a14637a1a61610"
source: heimdall/auto
---

# E Output Directories Exist Converted Dirmkdirexist Oktrue

- e output directories exist."""
    CONVERTED_DIR.mkdir(exist_ok=True)
    IMAGES_DIR.mkdir(exist_ok=True)
    DONE_DIR.mkdir(exist_ok=True)


def get_files_to_convert():
    """Get list of convertible files from upload directory."""
    files = []
    for item in UPLOAD_DIR.iterdir():
        if item.is_file() and item.suffix.lower() in SUPPORTED:
            files.append(item)
    return files


def extract_pdf_pages_as_images(file_path: Path) -> int:
    """Extract each page of a PDF as a PNG image. Returns number of pages extracted."""
    if not HAS_PYMUPDF:
        print("\n    ⚠️  pymupdf not installed — skipping image extraction (pip install pymupdf)")
        return 0

    doc_images_dir = IMAGES_DIR / file_path.stem
    doc_images_dir.mkdir(exist_ok=True)

    try:
        doc = fitz.open(str(file_path))
        page_count = len(doc)
        for page_num in range(page_count):
            page = doc[page_num]
            # Render at 2x resolution (144 DPI) for clarity
            pix = page.get_pixmap(dpi=144)
            output_file = doc_images_dir / f"page-{page_num + 1}.png"
            pix.save(str(output_file))
        doc.close()
        return page_count
    except Exception as e:
        print(f"\n    ⚠️  Image extraction failed: {e}")
        return 0


def convert_file(file_path: Path) -> bool:
    """Convert a single file to markdown using markitdown."""
    output_name = file_path.stem + ".md"
    output_path = CONVERTED_DIR / output_name

    # Create ma <!-- id:54222518-f591-4177-90c7-0d77eacfa12b ts:2026-05-17 07:49 -->
- e output directories exist."""
    CONVERTED_DIR.mkdir(exist_ok=True)
    IMAGES_DIR.mkdir(exist_ok=True)
    DONE_DIR.mkdir(exist_ok=True)


def get_files_to_convert():
    """Get list of convertible files from upload directory."""
    files = []
    for item in UPLOAD_DIR.iterdir():
        if item.is_file() and item.suffix.lower() in SUPPORTED:
            files.append(item)
    return files


def extract_pdf_pages_as_images(file_path: Path) -> int:
    """Extract each page of a PDF as a PNG image. Returns number of pages extracted."""
    if not HAS_PYMUPDF:
        print("\n    ⚠️  pymupdf not installed — skipping image extraction (pip install pymupdf)")
        return 0

    doc_images_dir = IMAGES_DIR / file_path.stem
    doc_images_dir.mkdir(exist_ok=True)

    try:
        doc = fitz.open(str(file_path))
        page_count = len(doc)
        for page_num in range(page_count):
            page = doc[page_num]
            # Render at 2x resolution (144 DPI) for clarity
            pix = page.get_pixmap(dpi=144)
            output_file = doc_images_dir / f"page-{page_num + 1}.png"
            pix.save(str(output_file))
        doc.close()
        return page_count
    except Exception as e:
        print(f"\n    ⚠️  Image extraction failed: {e}")
        return 0


def convert_file(file_path: Path) -> bool:
    """Convert a single file to markdown using markitdown."""
    output_name = file_path.stem + ".md"
    output_path = CONVERTED_DIR / output_name

    # Create ma <!-- id:54222518-f591-4177-90c7-0d77eacfa12b ts:2026-05-17 07:49 -->
