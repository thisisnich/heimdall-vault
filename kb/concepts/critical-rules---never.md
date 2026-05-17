---
id: "72c97e07-8fba-477c-970a-f5a8e117d360"
title: "Critical Rules   Never"
type: vault_note
vault: wiki
created: 2026-05-17
updated: 2026-05-17
checksum: "sha256:d884d89a4b116a5d"
source: heimdall/auto
---

# Critical Rules   Never

- ━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━

CRITICAL RULES:
- NEVER delete or summarize original content — only enhance formatting
- ALWAYS preserve source PDF filename in YAML frontmatter
- ALWAYS add proper YAML frontmatter with relevant tags
- ALWAYS embed images where figures are referenced — don't leave "Figure X" as dead text
- ALWAYS ask before placing files if course/subject is ambiguous
- Store all images in `_attachments/` with descriptive filenames
- When in doubt, ASK rather than assume
```

---

## 🐍 CONVERSION SCRIPT

Save this as `_tools/convert_to_md.py`:

```python
#!/usr/bin/env python3
"""
Document to Markdown Converter for Obsidian Vault
Supports: PDF, PPTX, DOCX, XLSX, CSV, HTML, images
Requires: pip install markitdown pymupdf
"""

import os
import shutil
import subprocess
from pathlib import Path
from datetime import datetime

try:
    import fitz  # pymupdf
    HAS_PYMUPDF = True
except ImportError:
    HAS_PYMUPDF = False

# Configuration
UPLOAD_DIR = Path("_to_upload")
CONVERTED_DIR = UPLOAD_DIR / "converted"
IMAGES_DIR = CONVERTED_DIR / "images"
DONE_DIR = UPLOAD_DIR / "done"

# Supported extensions
SUPPORTED = {'.pdf', '.pptx', '.ppt', '.docx', '.doc', '.xlsx', '.xls', '.csv', '.html', '.htm', '.jpg', '.jpeg', '.png', '.gif', '.bmp', '.webp'}
PDF_EXTENSIONS = {'.pdf'}


def setup_dirs():
    """Ensure output directories exist."""
    CONVERTED_DIR.mkdir(exist_ok=True)
    IMAGES_DIR.mkdir(exist_ok=True)
    DONE_DIR.mkdir(exist_ok=True)


def get_ <!-- id:72c97e07-8fba-477c-970a-f5a8e117d360 ts:2026-05-17 07:49 -->
- ━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━

CRITICAL RULES:
- NEVER delete or summarize original content — only enhance formatting
- ALWAYS preserve source PDF filename in YAML frontmatter
- ALWAYS add proper YAML frontmatter with relevant tags
- ALWAYS embed images where figures are referenced — don't leave "Figure X" as dead text
- ALWAYS ask before placing files if course/subject is ambiguous
- Store all images in `_attachments/` with descriptive filenames
- When in doubt, ASK rather than assume
```

---

## 🐍 CONVERSION SCRIPT

Save this as `_tools/convert_to_md.py`:

```python
#!/usr/bin/env python3
"""
Document to Markdown Converter for Obsidian Vault
Supports: PDF, PPTX, DOCX, XLSX, CSV, HTML, images
Requires: pip install markitdown pymupdf
"""

import os
import shutil
import subprocess
from pathlib import Path
from datetime import datetime

try:
    import fitz  # pymupdf
    HAS_PYMUPDF = True
except ImportError:
    HAS_PYMUPDF = False

# Configuration
UPLOAD_DIR = Path("_to_upload")
CONVERTED_DIR = UPLOAD_DIR / "converted"
IMAGES_DIR = CONVERTED_DIR / "images"
DONE_DIR = UPLOAD_DIR / "done"

# Supported extensions
SUPPORTED = {'.pdf', '.pptx', '.ppt', '.docx', '.doc', '.xlsx', '.xls', '.csv', '.html', '.htm', '.jpg', '.jpeg', '.png', '.gif', '.bmp', '.webp'}
PDF_EXTENSIONS = {'.pdf'}


def setup_dirs():
    """Ensure output directories exist."""
    CONVERTED_DIR.mkdir(exist_ok=True)
    IMAGES_DIR.mkdir(exist_ok=True)
    DONE_DIR.mkdir(exist_ok=True)


def get_ <!-- id:72c97e07-8fba-477c-970a-f5a8e117d360 ts:2026-05-17 07:49 -->
