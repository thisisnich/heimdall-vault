---
id: "e28db655-2bd4-41c5-a5cd-900de1cb25ab"
title: "W Then Click On Launch"
type: vault_note
vault: wiki
created: 2026-05-17
updated: 2026-05-17
checksum: "sha256:4fe11a615edd20dc"
source: heimdall/auto
---

# W Then Click On Launch

- w. Then, click on **Launch**.

3. The CCS IDE software takes a while to set up the workspace. The starting page is shown after setup is completed.

4. To create a project, click on **Project** and select **New CCS Project…** from the top menu in the CCS IDE software starting page.

5. In the **New CCS Project** window, set the following configuration and click **Finish**:

| Field | Value |
|-------|-------|
| Target | Tiva C Series → `Tiva TM4C129ENCPDT` |
| Connection | `Texas Instruments XDS100v2 USB Debug Probe` |
| Project name | `lab1` |


6. The CCS IDE software takes a while to set up the project configuration. The project appears in the Project Explorer after setup is completed.

7. To reset the software window perspective to default, click on **Window** → **Perspective** → **Reset Perspective…** from the top menu. Click **Reset Perspective** when prompted to confirm.


8. The default window perspective view is shown. The `lab1` project has been created and listed in the Project Explorer panel. Click the `>` arrow next to the `lab1` project to view the project file structure.

9. To include the required peripheral driver and library files, download `Utility.zip` from **POLITEMall**, unzip it, and copy the `Drivers` and `Libraries` folders into the `lab1` project.

10. To set the `Drivers` and `Libraries` folder paths in the compiler, right-click on `lab1` → **Properties**. In the Properties window, add the six paths in **Include Options** under **ARM Compiler**. <!-- id:e28db655-2bd4-41c5-a5cd-900de1cb25ab ts:2026-05-17 07:49 -->
