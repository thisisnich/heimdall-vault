#!/usr/bin/env python3
"""Scan vault for flashcard notes and build 07-DASHBOARDS/flashcard-hub/decks.js.

Notes qualify if frontmatter has tag `flashcards` or type `flashcards`.

Supported card formats inside a note:
  - ## Flashcards section with Q::: / A::: pairs (Obsidian Spaced Repetition)
  - **Q:** / **A:** blocks (EGE322-style, often under ### Card N headings)

Usage:
  python build-flashcard-hub.py
  python build-flashcard-hub.py --vault ..\\..
"""

from __future__ import annotations

import argparse
import json
import re
import sys
from datetime import date
from pathlib import Path

VAULT_ROOT = Path(__file__).resolve().parent.parent
HUB_DIR = VAULT_ROOT / "07-DASHBOARDS" / "flashcard-hub"
SKIP_DIRS = {
    ".git",
    ".obsidian",
    "90-TEMPLATES",
    "91-SCRIPTS",
    "99-ATTACHMENTS",
    "00-INBOX",
    "04-ARCHIVE",
    "node_modules",
    "flashcard-hub",
}

SR_CARD = re.compile(
    r"^Q:::\s*(?P<q>.+?)\s*\nA:::\s*(?P<a>.+?)(?=\nQ:::|\Z)",
    re.MULTILINE | re.DOTALL,
)
BOLD_QA = re.compile(
    r"\*\*Q:\*\*\s*(?P<q>.*?)\s*\n+\*\*A:\*\*\s*(?P<a>.*?)(?=\n---|\n###\s+Card|\n##\s|\Z)",
    re.DOTALL,
)
QNA_NUMBERED = re.compile(
    r"\*\*Q(?P<num>\d+):\s*(?P<q>.*?)\*\*\s*"
    r"(?P<body>.*?)(?=\n\n\*\*Q\d+:|\n\n---|\n\n## |\Z)",
    re.MULTILINE | re.DOTALL,
)
CODE_FENCE = re.compile(r"```[\s\S]*?```", re.MULTILINE)
FRONTMATTER = re.compile(r"^---\s*\n(.*?)\n---\s*\n", re.DOTALL)


def slugify(text: str) -> str:
    text = text.lower().strip()
    text = re.sub(r"[^\w\s-]", "", text)
    text = re.sub(r"[\s_]+", "-", text)
    return text[:80] or "deck"


def parse_frontmatter(text: str) -> tuple[dict[str, str], str, str]:
    text = text.lstrip("\ufeff")
    match = FRONTMATTER.match(text)
    if not match:
        return {}, text, ""
    fm_raw = match.group(1)
    body = text[match.end() :]
    fm: dict[str, str] = {}
    for line in fm_raw.splitlines():
        if ":" not in line:
            continue
        key, _, value = line.partition(":")
        fm[key.strip()] = value.strip()
    return fm, body, fm_raw


def fm_has_flashcards(fm: dict[str, str], body: str, fm_raw: str) -> bool:
    if re.search(r"\bflashcards\b", fm_raw, re.I):
        return True
    note_type = fm.get("type", "")
    if re.fullmatch(r"flashcards?", note_type, re.I):
        return True
    if "## Flashcards" in body and re.search(r"^Q:::", body, re.MULTILINE):
        return True
    return False


def note_title(body: str, path: Path) -> str:
    for line in body.splitlines():
        if line.startswith("# "):
            return line[2:].strip()
    return path.stem


def note_course(fm: dict[str, str], path: Path, fm_raw: str) -> str:
    if fm.get("course"):
        course = fm["course"]
        code = re.search(r"EGE\d{3}|FGX\d{3}|HSX\d{3}|AP[\w-]+", course, re.I)
        if code:
            return code.group(0).upper()
    for blob in (fm_raw, fm.get("tags", "")):
        code = re.search(r"EGE\d{3}|FGX\d{3}|HSX\d{3}|AP[\w-]+", blob, re.I)
        if code:
            return code.group(0).upper()
    for part in path.parts:
        m = re.match(r"(EGE\d{3}|FGX\d{3}|HSX\d{3})", part, re.I)
        if m:
            return m.group(0).upper()
    return "General"


def normalize_question(text: str) -> str:
    """Single-line for questions."""
    text = text.strip()
    text = re.sub(r"\s*\n\s*", " ", text)
    text = re.sub(r" +", " ", text)
    return text


def preserve_markdown(text: str) -> str:
    """Keep line breaks for tables, lists, and code in answers."""
    text = text.strip()
    lines = [re.sub(r"[ \t]+", " ", line.rstrip()) for line in text.splitlines()]
    text = "\n".join(lines)
    text = re.sub(r"\n{3,}", "\n\n", text)
    return restore_collapsed_tables(text)


def restore_collapsed_tables(text: str) -> str:
    """Re-break markdown table rows stored on one line."""
    if "\n|" in text or "|" not in text:
        return text
    if text.count("|") < 4:
        return text
    return re.sub(r"\|\s+\|", "|\n|", text)


def extract_qna_answer(body: str) -> str:
    body = body.strip()
    if not body:
        return ""
    parts = re.split(r"(?:^|\n)A:\s*", body, maxsplit=1)
    if len(parts) > 1:
        return preserve_markdown(parts[1])
    code = CODE_FENCE.search(body)
    if code:
        snippet = code.group(0)
        snippet = re.sub(r"^```\w*\n?", "", snippet)
        snippet = re.sub(r"\n?```$", "", snippet)
        return preserve_markdown(snippet)
    return preserve_markdown(body)


def parse_qn_numbered_cards(body: str) -> list[dict]:
    cards = []
    for match in QNA_NUMBERED.finditer(body):
        q = normalize_question(match.group("q"))
        a = extract_qna_answer(match.group("body"))
        if q and a:
            cards.append({"question": q, "answer": a, "critical": "quiz" in q.lower()})
    return cards


def dedupe_cards(cards: list[dict]) -> list[dict]:
    seen: set[str] = set()
    unique: list[dict] = []
    for card in cards:
        key = normalize_question(card["question"]).lower()
        if key in seen:
            continue
        seen.add(key)
        unique.append(card)
    return unique


def parse_sr_cards(section: str) -> list[dict]:
    cards = []
    for match in SR_CARD.finditer(section):
        q = normalize_question(match.group("q"))
        a = preserve_markdown(match.group("a"))
        if q and a:
            cards.append({"question": q, "answer": a, "critical": "quiz" in q.lower()})
    return cards


def parse_bold_qa_cards(body: str) -> list[dict]:
    cards = []
    for match in BOLD_QA.finditer(body):
        q = normalize_question(match.group("q"))
        a = preserve_markdown(match.group("a"))
        if q and a:
            critical = "quiz" in q.lower() or "⚠" in q
            cards.append({"question": q, "answer": a, "critical": critical})
    return cards


def parse_cards(body: str) -> list[dict]:
    main, _, flash_section = body.partition("## Flashcards")
    cards: list[dict] = []
    cards.extend(parse_qn_numbered_cards(main))
    cards.extend(parse_bold_qa_cards(main))
    if flash_section:
        cards.extend(parse_sr_cards(flash_section))
    if not cards:
        cards.extend(parse_bold_qa_cards(body))
        cards.extend(parse_sr_cards(body))
    return dedupe_cards(cards)


def scan_vault(vault: Path) -> list[dict]:
    decks: list[dict] = []
    seen_ids: set[str] = set()

    for path in sorted(vault.rglob("*.md")):
        if any(part in SKIP_DIRS for part in path.parts):
            continue
        try:
            text = path.read_text(encoding="utf-8-sig")
        except OSError:
            continue

        fm, body, fm_raw = parse_frontmatter(text)
        if not fm_has_flashcards(fm, body, fm_raw):
            continue

        cards = parse_cards(body)
        if not cards:
            continue

        rel = path.relative_to(vault).as_posix()
        deck_id = slugify(path.stem)
        if deck_id in seen_ids:
            deck_id = slugify(f"{path.parent.name}-{path.stem}")
        seen_ids.add(deck_id)

        decks.append(
            {
                "id": deck_id,
                "title": note_title(body, path),
                "course": note_course(fm, path, fm_raw),
                "path": rel,
                "cardCount": len(cards),
                "cards": cards,
            }
        )

    decks.sort(key=lambda d: (d["course"], d["title"]))
    return decks


def write_hub(decks: list[dict], hub: Path) -> None:
    hub.mkdir(parents=True, exist_ok=True)
    payload = {"generated": date.today().isoformat(), "deckCount": len(decks), "decks": decks}
    json_text = json.dumps(payload, ensure_ascii=False, indent=2)
    (hub / "decks.json").write_text(json_text, encoding="utf-8")
    (hub / "decks.js").write_text(
        f"// Auto-generated by 91-SCRIPTS/build-flashcard-hub.py — do not edit\n"
        f"window.HEIMDALL_DECKS = {json.dumps(payload, ensure_ascii=False)};\n",
        encoding="utf-8",
    )


def main() -> int:
    parser = argparse.ArgumentParser(description="Build Heimdall flashcard hub from vault notes")
    parser.add_argument("--vault", type=Path, default=VAULT_ROOT, help="Vault root path")
    parser.add_argument("--hub", type=Path, default=HUB_DIR, help="Output hub directory")
    args = parser.parse_args()

    decks = scan_vault(args.vault)
    if not decks:
        print("No flashcard decks found. Tag notes with `flashcards` and add Q::: / A::: cards.", file=sys.stderr)
        return 1

    write_hub(decks, args.hub)
    total = sum(d["cardCount"] for d in decks)
    print(f"Built {len(decks)} deck(s), {total} cards → {args.hub}")
    for deck in decks:
        print(f"  · [{deck['course']}] {deck['title']} ({deck['cardCount']} cards)")
    return 0


if __name__ == "__main__":
    raise SystemExit(main())
