#!/usr/bin/env python3
"""Convert **Qx: ...** / A: blocks in a markdown note to Q::: / A::: flashcards.

Usage:
  python qna-to-flashcards.py NOTE.md              # print flashcards
  python qna-to-flashcards.py NOTE.md --write      # replace ## Flashcards section in place
  python qna-to-flashcards.py NOTE.md --write --prefix "Lab 1"  # tag each card (optional)
"""

from __future__ import annotations

import argparse
import re
import sys
from pathlib import Path

CODE_FENCE = re.compile(r"```[\s\S]*?```", re.MULTILINE)

QNA_BLOCK = re.compile(
    r"\*\*Q(?P<num>\d+):\s*(?P<q>.*?)\*\*\s*"
    r"(?P<body>.*?)(?=\n\n\*\*Q\d+:|\n\n---|\n\n## |\Z)",
    re.MULTILINE | re.DOTALL,
)

FLASHCARDS_HEADING = re.compile(r"^## Flashcards\s*$", re.MULTILINE)


def normalize(text: str) -> str:
    text = text.strip()
    text = re.sub(r"\s*\n\s*", " ", text)
    text = re.sub(r" +", " ", text)
    return text


def extract_answer(body: str) -> str:
    body = body.strip()
    if not body:
        return ""

    parts = re.split(r"(?:^|\n)A:\s*", body, maxsplit=1)
    if len(parts) > 1:
        return normalize(parts[1])

    code = CODE_FENCE.search(body)
    if code:
        snippet = code.group(0)
        snippet = re.sub(r"^```\w*\n?", "", snippet)
        snippet = re.sub(r"\n?```$", "", snippet)
        return normalize(snippet)

    return normalize(body)


def parse_qna(markdown: str) -> list[tuple[str, str]]:
    # Only parse Q&A sections, not the generated flashcards block
    if "## Flashcards" in markdown:
        markdown = markdown.split("## Flashcards", maxsplit=1)[0]

    cards: list[tuple[str, str]] = []
    for match in QNA_BLOCK.finditer(markdown):
        question = normalize(match.group("q"))
        answer = extract_answer(match.group("body"))
        if question and answer:
            cards.append((question, answer))
    return cards


def to_flashcards_section(cards: list[tuple[str, str]], prefix: str | None = None) -> str:
    lines = ["## Flashcards", ""]
    for q, a in cards:
        if prefix:
            q = f"[{prefix}] {q}"
        lines.append(f"Q::: {q}")
        lines.append(f"A::: {a}")
        lines.append("")
    return "\n".join(lines).rstrip() + "\n"


def replace_flashcards_section(markdown: str, section: str) -> str:
    if FLASHCARDS_HEADING.search(markdown):
        before = FLASHCARDS_HEADING.split(markdown, maxsplit=1)[0].rstrip()
        return before + "\n\n" + section
    return markdown.rstrip() + "\n\n" + section


def main() -> int:
    parser = argparse.ArgumentParser(description="Convert Q&A markdown to Obsidian SR flashcards")
    parser.add_argument("note", type=Path, help="Markdown note with **Qn:** / A: blocks")
    parser.add_argument("--write", action="store_true", help="Replace ## Flashcards in the note")
    parser.add_argument("--prefix", help="Optional prefix for every question, e.g. 'Lab 1'")
    args = parser.parse_args()

    text = args.note.read_text(encoding="utf-8")
    cards = parse_qna(text)
    if not cards:
        print("No Q&A pairs found.", file=sys.stderr)
        return 1

    section = to_flashcards_section(cards, args.prefix)
    if args.write:
        args.note.write_text(replace_flashcards_section(text, section), encoding="utf-8")
        print(f"Wrote {len(cards)} flashcards to {args.note}", file=sys.stderr)
    else:
        sys.stdout.reconfigure(encoding="utf-8")  # type: ignore[attr-defined]
        print(section)
        print(f"# {len(cards)} cards", file=sys.stderr)
    return 0


if __name__ == "__main__":
    raise SystemExit(main())
