---
id: "7e16697c-39c0-4d1c-b038-26be32fa98b3"
title: "To Single Step From The Breakpoint"
type: vault_note
vault: wiki
created: 2026-05-17
updated: 2026-05-17
checksum: "sha256:2c3bfc96d14d61dd"
source: heimdall/auto
---

# To Single Step From The Breakpoint

- To single-step from the breakpoint: **Run** → **Step Over**, or press `F6`. To resume normal speed, repeat step 15.


23. Repeat step 18 to terminate. To remove a breakpoint, double-click the blue dot — it will disappear.

### 2.2 Project Export

1. To export the project, click **File** → **Export…** from the top menu.


2. In the Export window, select **Archive File** under the General folder and click **Next >**.


3. Click **Select All** to select all project files. Click **Browse…** to set the archive file name and directory. Click **Finish** to start. Locate the `.zip` file in the set directory once complete.


### 2.3 Project Import

1. To import an archived project, click **Project** → **Import CCS Projects…** from the top menu.


2. In the Import CCS Eclipse Projects window, click **Browse…** to locate the archived `.zip` file from the earlier export. Click **Finish**.


3. Once importing is complete, a ready project workspace for code development is shown.


### 2.4 Project Flashing

1. Double-click the icon below to launch **CCS UniFlash** Software.


2. CCS UniFlash takes a while to launch. The starting page is shown after launch is complete.

3. In the UniFlash Starting Page, select device: `TIVA TM4C129ENCPDT`.


4. Choose connection: `Texas Instruments XDS100v2 USB Debug Probe`. Click **Start**.


5. Click **Browse** to select the `Project.out` file downloaded from POLITEMall. Click **Open**.


6. <!-- id:7e16697c-39c0-4d1c-b038-26be32fa98b3 ts:2026-05-17 07:49 -->
