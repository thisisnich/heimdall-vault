#!/usr/bin/env python3
"""
Move a completed course module to heimdall-memory and leave a stub in the active vault.
Usage: python archive-course.py EGE322-IOT-System-Project --semester 2026-S1
Requires --memory-root pointing at the heimdall-memory repo clone.
"""

from __future__ import annotations

import argparse
import shutil
from datetime import date
from pathlib import Path

VAULT_ROOT = Path(__file__).resolve().parent.parent
RESOURCES = VAULT_ROOT / "03-RESOURCES"


def main() -> None:
    parser = argparse.ArgumentParser()
    parser.add_argument("module", help="Folder name under 03-RESOURCES/")
    parser.add_argument("--semester", required=True, help="e.g. 2026-S1")
    parser.add_argument(
        "--memory-root",
        required=True,
        help="Path to heimdall-memory repo (e.g. ../heimdall-memory)",
    )
    parser.add_argument("--dry-run", action="store_true")
    args = parser.parse_args()

    src = RESOURCES / args.module
    if not src.is_dir():
        raise SystemExit(f"Module not found: {src}")

    memory_root = Path(args.memory_root).resolve()
    dest = memory_root / "NYP" / args.semester / args.module

    print(f"Source:      {src}")
    print(f"Destination: {dest}")

    if args.dry_run:
        print("(dry run — no changes)")
        return

    dest.parent.mkdir(parents=True, exist_ok=True)
    if dest.exists():
        raise SystemExit(f"Destination already exists: {dest}")

    shutil.move(str(src), str(dest))

    stub = RESOURCES / f"{args.module}.md"
    stub.write_text(
        f"""---
type: course-moc
module: {args.module}
status: archived
archived: true
archived_date: {date.today().isoformat()}
memory_path: NYP/{args.semester}/{args.module}
tags: [school, archived]
---

# {args.module} (archived)

This module was moved to **heimdall-memory** for semester **{args.semester}**.

Local path: `{dest}`

Ask your PA to search the memory repo when you need old notes.
""",
        encoding="utf-8",
    )
    print(f"Stub written: {stub}")
    print("Remember to commit both repos.")


if __name__ == "__main__":
    main()
