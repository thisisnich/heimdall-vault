---
type: dev-project
course: EGE320
module: EGE320-Embedded-System-Design
status: draft
source: manual
created: 2026-05-21
tags: [EGE320, CCS, vscode]
---

# EGE320_E2 — CCS + VS Code workflow

**Notes:** [[03-RESOURCES/EGE320-Embedded-System-Design/ege320-lab-5-touchscreen-interaction-slides|EGE320 Lab 5]] · [[03-RESOURCES/EGE320-Embedded-System-Design/ege320-tutorial-5-slides|Tutorial 5]]

## Quick start (Lab 5)

| Exercise | Project folder | Edit in VS Code |
|----------|----------------|-----------------|
| 1.1 Touch coordinates | `lab5_1.1/` | `lab5_1.1/main.c` |
| 1.2 App icon touch | `lab5_1.2/` | `lab5_1.2/main.c` |
| 1.3 Unlock flow | `lab5_1.3/` | `lab5_1.3/main.c` |

Open **`EGE320-E2.code-workspace`** in VS Code — code + course notes side by side.

## CCS setup (once)

1. Launch **Code Composer Studio**.
2. **File → Switch Workspace → Other…**
3. Select this folder:
   `...\heimdall-vault\99-ATTACHMENTS\EGE320\EGE320_E2`
4. **Project → Import CCS Projects…**
   - Select root directory: same `EGE320_E2` folder
   - Check `lab5_1.1` (or `lab5_1.2` / `lab5_1.3`)
   - Click **Finish**
5. Confirm target:
   - Device: **Tiva TM4C129ENCPDT**
   - Connection: **Texas Instruments XDS100v2 USB Debug Probe**
6. **Lab 5 only:** stack size **1024** (Project → Properties → Build → ARM Linker → Set C system stack size). Already set on `lab5_1.1` Debug/Release.

## Daily loop

1. Edit `main.c` in **VS Code** (save).
2. Switch to **CCS** → hammer **Build** (or F11 debug).
3. Connect board + XDS100v2 → **Run → Debug** → **Resume (F8)**.

Build/debug stay in CCS. VS Code is for editing + IntelliSense only.

## VS Code IntelliSense

If `#include` squiggles appear after CCS install, update the TI compiler path in `.vscode/c_cpp_properties.json`:

```text
C:/ti/ccs1281/ccs/tools/compiler/ti-cgt-arm_20.2.7.LTS/include
```

Replace `ccs1281` with your installed version (check under `C:/ti/`).

Use the status bar **C/C++ configuration** dropdown to pick `lab5_1.1`, `lab5_1.2`, or `lab5_1.3`.

## Hardware

- Development board (smartwatch kit)
- USB to host PC (debug + power)
- XDS100v2 debug probe connected

## Troubleshooting

### GEL: Could not open file `lab5_1.1.out`

The `.out` file **does not exist yet** — debug was started before a successful build.

**Root cause on your PC:** CCS 20.5.1 only installed the **LLVM** compiler (`ti-cgt-armllvm`). These lab projects need the **classic** compiler (`ti-cgt-arm` 18.12.x), which is not installed by default.

### "20.2.7.LTS [Arm] is not installed"

The compiler **is** on disk at `C:\ti\ccs2051\ccs\tools\compiler\ti-cgt-arm_20.2.7.LTS\` but CCS has not registered it. Old workspace builds pointed at `C:\ti\ccs1281\` (not on this PC).

**Fix in CCS (once):**

1. **Window → Preferences → Code Composer Studio → Build → Compilers**
2. Under **Tool discovery path**, click **Add**
3. Browse to: `C:\ti\ccs2051\ccs\tools\compiler`
4. OK — confirm **20.2.7.LTS [Arm]** appears under **Discovered tools**
5. Close CCS completely, reopen workspace
6. For each project: delete its `Debug/` folder → **Project → Clean** → **Build**

**Project file fixes (lab5):** `.ccsproject` was still on `16.9.6.LTS` — now updated to `20.2.7.LTS` to match Lab2/Lab3.

**Fix:** Install **TI ARM CGT 20.2.7.LTS** (classic). Lab5 projects are now retargeted to **20.2.7.LTS** (same as Lab2/Lab3). In CCS: right-click project → **Properties → General → Compiler version → 20.2.7.LTS**, then **Clean + Build**.

### Build console shows empty compiler path (`"" -mv7M4`)

Stale `Debug/` folder from another machine. Delete `lab5_1.1/Debug`, then Clean + Build in CCS after installing the classic compiler.


| Location | x | y |
|----------|---|---|
| Bottom | 120 | 220 |
| Top | 120 | 50 |
| Right | 220 | 120 |
| Left | 20 | 120 |
