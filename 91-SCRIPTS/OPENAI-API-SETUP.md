# OpenAI API key setup (optional — Whisper audio ingest)

**Default workflow:** Apple Voice Memos auto-transcript → `.txt` → [[VOICE-MEMOS-WORKFLOW.md]]. **You do not need this file** for that path.

Use OpenAI only if you want `ingest.py` to transcribe **raw audio files** on PC without copying Voice Memos text.

## 1. Create an OpenAI account

1. Go to [https://platform.openai.com/signup](https://platform.openai.com/signup)
2. Sign in or create an account
3. Add a **payment method** under [Billing](https://platform.openai.com/settings/organization/billing) — Whisper is pay-per-minute (typically low cost for lecture clips)

## 2. Create an API key

1. Open [API keys](https://platform.openai.com/api-keys)
2. Click **Create new secret key**
3. Name it e.g. `heimdall-ingest-local`
4. **Copy the key immediately** — it starts with `sk-` and is shown only once

## 3. Put the key in this vault (never commit it)

From PowerShell:

```powershell
cd "c:\Users\Nicholas Dubs\Documents\Obsidian\heimdall-vault\91-SCRIPTS"
copy .env.example .env
notepad .env
```

In `.env`, set:

```env
OPENAI_API_KEY=sk-your-actual-key-here
```

Save and close. Confirm `.env` is gitignored:

```powershell
git check-ignore -v .env
# Should show: .gitignore ... 91-SCRIPTS/.env
```

## 4. Test audio ingest

```powershell
.\.venv\Scripts\Activate.ps1   # if venv not created yet: python -m venv .venv; pip install -r requirements.txt
python ingest.py audio "path\to\lecture.m4a" --course EGE320
```

If the key works, you get a `*-transcript.md` under the course folder with a Whisper-filled **Raw** section.

## Security

| Do | Don't |
|----|--------|
| Keep key only in `91-SCRIPTS/.env` | Commit `.env` to Git |
| Rotate key if leaked | Paste key in Telegram, Discord, or notes |
| Set [usage limits](https://platform.openai.com/settings/organization/limits) | Share vault `.env` with the PA bot repo |

Your **Telegram PA** should run ingest on your machine (or a private server) with `.env` local — not embed the key in the vault.

## Optional: no OpenAI key

- Use **YouTube** ingest (`youtube` command) — uses yt-dlp only
- Use **PDF/images** — uses MarkItDown only
- Transcribe audio elsewhere, drop `.txt` in `00-INBOX/_drop/`

## Troubleshooting

| Error | Fix |
|-------|-----|
| `_No OPENAI_API_KEY_` | Create `.env` from `.env.example` |
| `401 Unauthorized` | Key wrong or revoked — create new key |
| `Insufficient quota` | Add billing / check limits on OpenAI dashboard |
| `ModuleNotFoundError: openai` | `pip install -r requirements.txt` in venv |
