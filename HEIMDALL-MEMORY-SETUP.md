# heimdall-memory (archived semesters)

Create a **second Git repository** sibling to this vault:

```text
Documents/Obsidian/
  heimdall-vault/      ← active (this repo)
  heimdall-memory/     ← archived courses
```

## Initialize

**Done locally (2026-05-20):** `c:\Users\Nicholas Dubs\Documents\Obsidian\heimdall-memory` — `git init`, initial commit on `main`.

### Add a remote (GitHub — optional)

```powershell
cd "c:\Users\Nicholas Dubs\Documents\Obsidian\heimdall-memory"
gh repo create heimdall-memory --private --source=. --remote=origin --push
```

Or manually:

```powershell
git remote add origin https://github.com/YOUR_USER/heimdall-memory.git
git push -u origin main
```

Use the **same sync habit** as `heimdall-vault` (pull on PA/desktop before edits).

## Archive a module (end of semester)

```powershell
cd heimdall-vault\91-SCRIPTS
python archive-course.py EGE322-IOT-System-Project --semester 2026-S1 --memory-root "..\..\heimdall-memory"
```

This moves `03-RESOURCES/EGE322-IOT-System-Project/` into `heimdall-memory/NYP/2026-S1/` and leaves a stub `.md` in the active vault.

## PA behaviour

- Default search: **heimdall-vault** only.
- Search **heimdall-memory** when user mentions old modules or a stub has `archived: true`.

See [[AGENTS.md]] §10.
