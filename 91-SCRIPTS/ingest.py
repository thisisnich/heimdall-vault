#!/usr/bin/env python3
"""
Heimdall vault ingestion — PDF, Office, images, URLs, YouTube, audio.
See AGENTS.md §5 and README.md in this folder.
"""

from __future__ import annotations

import argparse
import re
import shutil
import subprocess
import sys
from datetime import date
from pathlib import Path

SCRIPT_DIR = Path(__file__).resolve().parent
VAULT_ROOT = SCRIPT_DIR.parent
INBOX_DROP = VAULT_ROOT / "00-INBOX" / "_drop"
INBOX_PROCESSING = VAULT_ROOT / "00-INBOX" / "_processing"
ATTACHMENTS = VAULT_ROOT / "99-ATTACHMENTS"
RESOURCES = VAULT_ROOT / "03-RESOURCES"
MEDIA = RESOURCES / "Media"

# Map course codes → module folder names
COURSE_MAP: dict[str, str] = {
    "EGE301": "EGE301-Communication-Workplace-Success",
    "EGE320": "EGE320-Embedded-System-Design",
    "EGE321": "EGE321-Wireless-Communication",
    "EGE322": "EGE322-IOT-System-Project",
    "EGE351": "EGE351-Automation-Systems-Control",
    "EGE353": "EGE353-Autonomous-Mobile-Robotics",
    "FGX312": "FGX312-Japanese-Culture-Society",
    "HSX302": "HSX302-Healthy-Resilient-Families",
}

SUPPORTED_DROP = {
    ".pdf", ".pptx", ".ppt", ".docx", ".doc",
    ".png", ".jpg", ".jpeg", ".webp", ".gif",
    ".mp3", ".m4a", ".wav", ".mp4", ".webm",
    ".txt", ".md",
}

# Pages whose text mentions a figure/diagram, or pages with substantial visuals.
DIAGRAM_CUES = re.compile(
    r"\b("
    r"figure|fig\.|diagram|circuit|sketch|constellation|vector diagram|"
    r"spectral|waveform|modulated signal|time domain|frequency domain|"
    r"refer to|shown below|shown above|see below|see the circuit|"
    r"draw the|plot below|graph below|illustration"
    r")\b",
    re.IGNORECASE,
)

MIN_FIGURE_PX = 120  # skip logos / icons smaller than this
PAGE_RENDER_DPI = 150


def today() -> str:
    return date.today().isoformat()


def slugify(name: str, max_len: int = 80) -> str:
    s = re.sub(r"[^\w\s-]", "", name, flags=re.UNICODE)
    s = re.sub(r"[-\s]+", "-", s.strip()).strip("-").lower()
    return (s[:max_len] or "untitled").rstrip("-")


def resolve_module(course: str | None) -> Path | None:
    if not course:
        return None
    key = course.upper().replace(" ", "")
    folder = COURSE_MAP.get(key)
    if folder:
        p = RESOURCES / folder
        if p.is_dir():
            return p
    # Direct folder name
    direct = RESOURCES / course
    if direct.is_dir():
        return direct
    return None


def ingest_block(source: str, tool: str) -> str:
    return (
        f"> [!ingest] source: {source} | date: {today()} | tool: {tool}\n"
        f"> Auto-converted. Edit summary below; re-run ingest to replace block above.\n\n"
    )


def frontmatter(
    note_type: str,
    source: str,
    course: str | None = None,
    title: str | None = None,
) -> str:
    module = COURSE_MAP.get((course or "").upper(), course or "")
    lines = [
        "---",
        f"type: {note_type}",
        f"course: {course or ''}",
        f"module: {module or ''}",
        "status: draft",
        f"source: {source}",
        f"created: {today()}",
        "tags: []",
        "---",
        "",
    ]
    if title:
        lines.extend([f"# {title}", ""])
    return "\n".join(lines)


def convert_with_markitdown(path: Path) -> str:
    from markitdown import MarkItDown

    md = MarkItDown()
    result = md.convert(str(path))
    return result.text_content or ""


def convert_url(url: str) -> str:
    from markitdown import MarkItDown

    md = MarkItDown()
    result = md.convert(url)
    return result.text_content or ""


def youtube_transcript(url: str) -> tuple[str, str]:
    """Return (title_guess, transcript_text)."""
    title = slugify(url.split("v=")[-1][:11] if "v=" in url else "youtube")
    try:
        out = subprocess.run(
            [
                sys.executable, "-m", "yt_dlp",
                "--skip-download",
                "--write-auto-sub",
                "--sub-lang", "en",
                "--sub-format", "vtt",
                "-o", str(INBOX_PROCESSING / "yt-%(id)s"),
                url,
            ],
            capture_output=True,
            text=True,
            timeout=120,
        )
        if out.returncode != 0:
            return title, f"_yt-dlp error: {out.stderr[:500]}_\n"
        vtt_files = list(INBOX_PROCESSING.glob("yt-*.vtt"))
        if not vtt_files:
            return title, "_No transcript found._\n"
        text = vtt_files[0].read_text(encoding="utf-8", errors="replace")
        # crude VTT strip
        lines = []
        for line in text.splitlines():
            if line.strip() and not line.startswith("WEBVTT") and "-->" not in line and not re.match(r"^\d+$", line.strip()):
                lines.append(line.strip())
        body = " ".join(lines)
        vtt_files[0].unlink(missing_ok=True)
        return title, body
    except FileNotFoundError:
        return title, "_Install yt-dlp: pip install yt-dlp_\n"
    except subprocess.TimeoutExpired:
        return title, "_yt-dlp timed out._\n"


def transcribe_audio(path: Path) -> str:
    import os

    from dotenv import load_dotenv

    load_dotenv(SCRIPT_DIR / ".env")
    api_key = os.getenv("OPENAI_API_KEY")
    if not api_key:
        return (
            "_No OPENAI_API_KEY in 91-SCRIPTS/.env — add key for Whisper, "
            "or transcribe manually and save as .txt in _drop._\n"
        )
    try:
        from openai import OpenAI

        client = OpenAI(api_key=api_key)
        with path.open("rb") as f:
            tr = client.audio.transcriptions.create(model="whisper-1", file=f)
        return tr.text or ""
    except Exception as e:
        return f"_Whisper error: {e}_\n"


def figures_section(figures: list[dict]) -> str:
    if not figures:
        return ""
    lines = ["## Figures", ""]
    for fig in figures:
        rel = fig["vault_path"].replace("\\", "/")
        caption = fig.get("caption") or fig["filename"]
        lines.append(f"![[{rel}|{caption}]]")
        lines.append("")
    return "\n".join(lines) + "\n"


def write_note(
    out_path: Path,
    body: str,
    note_type: str,
    source_kind: str,
    ingest_source: str,
    tool: str,
    course: str | None,
    title: str,
    figures: list[dict] | None = None,
) -> Path:
    out_path.parent.mkdir(parents=True, exist_ok=True)
    figs = figures_section(figures or [])
    content = (
        frontmatter(note_type, source_kind, course, title)
        + ingest_block(ingest_source, tool)
        + "## Summary\n\n\n"
        + figs
        + "## Raw\n\n"
        + body.strip()
        + "\n"
    )
    out_path.write_text(content, encoding="utf-8")
    return out_path


def _page_has_large_images(page) -> bool:
    for info in page.get_images(full=True):
        try:
            xref = info[0]
            w, h = page.parent.extract_image(xref)["width"], page.parent.extract_image(xref)["height"]
            if w >= MIN_FIGURE_PX and h >= MIN_FIGURE_PX:
                return True
        except (IndexError, KeyError, TypeError):
            continue
    return False


def _page_needs_figure(page) -> bool:
    text = page.get_text("text") or ""
    if DIAGRAM_CUES.search(text):
        return True
    if _page_has_large_images(page):
        return True
    # Vector drawings (circuits drawn in PDF, not embedded bitmaps)
    try:
        if len(page.get_drawings()) >= 8:
            return True
    except AttributeError:
        pass
    return False


def extract_pdf_figures(pdf_path: Path, course: str | None, slug: str) -> list[dict]:
    """Render or extract diagram pages from a PDF into 99-ATTACHMENTS."""
    try:
        import fitz  # pymupdf
    except ImportError:
        print("  (pymupdf not installed — skip figure extraction)")
        return []

    dest_dir = ATTACHMENTS / (course.upper() if course else "Media") / slug
    dest_dir.mkdir(parents=True, exist_ok=True)
    figures: list[dict] = []

    doc = fitz.open(pdf_path)
    try:
        for page_index, page in enumerate(doc):
            if not _page_needs_figure(page):
                continue

            page_num = page_index + 1
            filename = f"{slug}-p{page_num:02d}.png"
            out_path = dest_dir / filename

            # Page screenshot — captures circuits, plots, and composite layouts
            pix = page.get_pixmap(dpi=PAGE_RENDER_DPI, alpha=False)
            pix.save(str(out_path))

            vault_rel = out_path.relative_to(VAULT_ROOT).as_posix()
            caption = f"Page {page_num}"
            preview = (page.get_text("text") or "").strip().splitlines()
            for line in preview[:6]:
                line = line.strip()
                if line and len(line) > 8 and not line.lower().startswith("official"):
                    caption = f"Page {page_num} — {line[:80]}"
                    break

            figures.append(
                {
                    "page": page_num,
                    "filename": filename,
                    "path": out_path,
                    "vault_path": vault_rel,
                    "caption": caption,
                }
            )
            print(f"  figure: {vault_rel}")
    finally:
        doc.close()

    return figures


def copy_attachment(src: Path, course: str | None) -> Path:
    dest_dir = ATTACHMENTS / (course.upper() if course else "Media")
    dest_dir.mkdir(parents=True, exist_ok=True)
    dest = dest_dir / src.name
    if src.resolve() != dest.resolve():
        shutil.copy2(src, dest)
    return dest


def file_pdf(path: Path, course: str | None, title: str | None) -> Path:
    title = title or path.stem
    slug = slugify(title)
    body = convert_with_markitdown(path)
    mod = resolve_module(course)
    out_dir = mod if mod else INBOX_PROCESSING
    out = out_dir / f"{slug}-slides.md"
    copy_attachment(path, course)
    figures = extract_pdf_figures(path, course, slug)
    return write_note(
        out, body, "lecture", "pdf", path.name, "markitdown", course, title, figures
    )


def file_image(path: Path, course: str | None, title: str | None) -> Path:
    title = title or path.stem
    body = convert_with_markitdown(path)
    mod = resolve_module(course)
    out_dir = mod if mod else INBOX_PROCESSING
    out = out_dir / f"{slugify(title)}-photo.md"
    copy_attachment(path, course)
    return write_note(out, body, "lecture", "photo", path.name, "markitdown", course, title)


def file_audio(path: Path, course: str | None, title: str | None) -> Path:
    title = title or path.stem
    body = transcribe_audio(path)
    mod = resolve_module(course)
    out_dir = mod if mod else INBOX_PROCESSING
    out = out_dir / f"{slugify(title)}-transcript.md"
    copy_attachment(path, course)
    return write_note(out, body, "lecture", "audio", path.name, "whisper", course, title)


def file_transcript(path: Path, course: str | None, title: str | None) -> Path:
    """Apple Voice Memos (or any pasted) plain-text transcript."""
    title = title or path.stem
    body = path.read_text(encoding="utf-8", errors="replace")
    mod = resolve_module(course)
    out_dir = mod if mod else INBOX_PROCESSING
    out = out_dir / f"{slugify(title)}-transcript.md"
    copy_attachment(path, course)
    return write_note(
        out, body, "lecture", "audio", path.name, "apple-voice-memos", course, title
    )


def cmd_youtube(url: str, course: str | None, title: str | None) -> Path:
    title_guess, body = youtube_transcript(url)
    title = title or title_guess.replace("-", " ").title()
    mod = resolve_module(course)
    out_dir = MEDIA if not mod else mod
    out = out_dir / f"{slugify(title)}-youtube.md"
    return write_note(out, body, "media", "youtube", url, "yt-dlp", course, title)


def cmd_url(url: str, course: str | None, title: str | None) -> Path:
    title = title or slugify(url)[:40]
    body = convert_url(url)
    out = MEDIA / f"{slugify(title)}-web.md"
    return write_note(out, body, "media", "web", url, "markitdown", course, title)


def process_drop_file(path: Path) -> Path | None:
    ext = path.suffix.lower()
    if ext in {".pdf", ".pptx", ".ppt", ".docx", ".doc"}:
        return file_pdf(path, None, path.stem)
    if ext in {".png", ".jpg", ".jpeg", ".webp", ".gif"}:
        return file_image(path, None, path.stem)
    if ext in {".mp3", ".m4a", ".wav", ".mp4", ".webm"}:
        return file_audio(path, None, path.stem)
    if ext in {".txt", ".md"}:
        return file_transcript(path, None, path.stem)
    print(f"Skip unsupported: {path}")
    return None


def process_inbox() -> list[Path]:
    INBOX_DROP.mkdir(parents=True, exist_ok=True)
    INBOX_PROCESSING.mkdir(parents=True, exist_ok=True)
    results: list[Path] = []
    for path in sorted(INBOX_DROP.iterdir()):
        if path.name.startswith(".") or path.is_dir():
            continue
        print(f"Processing {path.name}...")
        out = process_drop_file(path)
        if out:
            results.append(out)
            # move original to attachments/Media/processed
            done = INBOX_DROP / "processed"
            done.mkdir(exist_ok=True)
            shutil.move(str(path), str(done / path.name))
    return results


def main() -> None:
    parser = argparse.ArgumentParser(description="Heimdall vault ingest")
    parser.add_argument(
        "command",
        nargs="?",
        choices=["pdf", "image", "audio", "transcript", "youtube", "url"],
    )
    parser.add_argument("target", nargs="?", help="File path or URL")
    parser.add_argument("--course", "-c", help="Course code e.g. EGE322")
    parser.add_argument("--title", "-t", help="Note title")
    parser.add_argument("--process-inbox", action="store_true", help="Process 00-INBOX/_drop/")
    args = parser.parse_args()

    if args.process_inbox:
        paths = process_inbox()
        print(f"Done. {len(paths)} file(s) ingested.")
        for p in paths:
            print(f"  → {p.relative_to(VAULT_ROOT)}")
        return

    if not args.command or not args.target:
        parser.print_help()
        sys.exit(1)

    target = Path(args.target)
    out: Path
    if args.command == "pdf":
        out = file_pdf(target, args.course, args.title)
    elif args.command == "image":
        out = file_image(target, args.course, args.title)
    elif args.command == "audio":
        out = file_audio(target, args.course, args.title)
    elif args.command == "transcript":
        out = file_transcript(target, args.course, args.title)
    elif args.command == "youtube":
        out = cmd_youtube(args.target, args.course, args.title)
    elif args.command == "url":
        out = cmd_url(args.target, args.course, args.title)
    else:
        parser.print_help()
        sys.exit(1)

    print(f"Wrote: {out.relative_to(VAULT_ROOT)}")


if __name__ == "__main__":
    main()
