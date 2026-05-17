---
tags:
  - EGE320
  - lab
  - embedded-systems
  - CCS
  - development-environment
  - Tiva-C
  - programming
course: EGE320 Embedded System Design and Technology
topic: Lab 1 - Embedded System Development Environment
source: EGE320 - Lab1 Embedded System Development Environment.pdf
converted: 2026-04-23
type: Lab
status: Completed
---

> 📚 **Related:** [[NYPY3 - Main Index|NYPY3 Index]] | [[03-RESOURCES/EGE320-Embedded-System-Design/tutorial1.md|Tutorial 1]] | [[📅 Schedule & Assessments Dashboard|Assessment Dashboard]]

> 📚 **Related:** [[NYPY3 - Main Index|NYPY3 Index]] | [[📅 Schedule & Assessments Dashboard|Assessment Dashboard]] | [[03-RESOURCES/EGE320-Embedded-System-Design/ch0.md|Chapter 0]]

# Lab 1: Embedded System Development Environment

## Objectives
- To identify the tools for embedded system development
- To demonstrate the setup for embedded system development  
- To illustrate the use of C programming in embedded system development

## Contents
1. [Embedded System Development Hardware Setup](#1-embedded-system-development-hardware-setup)
2. [Embedded System Development Software Setup](#2-embedded-system-development-software-setup)
   - 2.1 [Project Creation](#21-project-creation)
   - 2.2 [Project Export](#22-project-export)
   - 2.3 [Project Import](#23-project-import)
   - 2.4 [Project Flashing](#24-project-flashing)

## 1. Embedded System Development Hardware Setup

Hardware setup includes connecting the development board, power supply, and debugging probe to the computer.

## 2. Embedded System Development Software Setup

### 2.1 Project Creation

1. Double click on the Code Composer Studio (CCS) icon to launch the Integrated Development Environment (IDE) Software.

2. To create a lab1 folder in the D drive, type `D:\lab1` in the workspace field in the Code Composer Studio Launcher window. Then, click on **Launch**.

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

10. To set the `Drivers` and `Libraries` folder paths in the compiler, right-click on `lab1` → **Properties**. In the Properties window, add the six paths in **Include Options** under **ARM Compiler**. Click **Apply and Close**.


11. Double click on `main.c` in project `lab1`, delete all existing code, enter the program below, and save.

```c
#include <stdbool.h>
#include <stdint.h>
#include <stdio.h>
#include "clock.h"
#include "rgbled.h"
#include "grlib.h"
#include "st7789_spi.h"
#include "it7258_i2c.h"

bool bTouchStatus = 0;

void TouchPanelIntHandler(void)                             //Touch Panel ISR
{
    IT7258IntClear();                                       //Clear Interrupt
    bTouchStatus = 1;                                       //Set bTouchStatus
}

int main(void)
{
    tContext sContext = {};
    uint16_t ui16XPosition[3] = {};
    uint16_t ui16YPosition[3] = {};
    uint8_t ui8Pressure[3] = {};

    ClockFrequencySet(120000000);                           //Set processor clock to 120MHz
    RGBLEDPinInit();                                        //Initialize RGBLED pin
    IT7258PinInit(120000000);                               //Initialize Touch Controller pin
    ST7789PinInit(120000000);                               //Initialize LCD Controller pin
    GrContextInit(&sContext, &g_sST7789);                   //Initialize glib Context
    IT7258IntRegister(TouchPanelIntHandler);                //Register Touch Panel Interrupt

    GrContextForegroundSet(&sContext, ClrRed);
    GrCircleFill(&sContext, 120, 60, 40);                   //Draw a red filled circle
    GrContextForegroundSet(&sContext, ClrLimeGreen);
    GrCircleFill(&sContext, 75, 140, 40);                   //Draw a green filled circle
    GrContextForegroundSet(&sContext, ClrBlue);
    GrCircleFill(&sContext, 165, 140, 40);                  //Draw a blue filled circle

    while(1)
    {
        if(bTouchStatus == 1)
        {
            IT7258GetTouchPointData(ui16XPosition, ui16YPosition, ui8Pressure);//Read Touch Point
            if(((100 < ui16XPosition[0]) && (ui16XPosition[0] < 140)) &&
               ((140 < ui16YPosition[0]) && (ui16YPosition[0] < 180)))
            {
                RGBLEDOnOff(1, 0, 0);                                          //Turn ON RedLED
            }
            if(((145 < ui16XPosition[0]) && (ui16XPosition[0] < 185)) &&
               ((80 < ui16YPosition[0]) && (ui16YPosition[0] < 120)))
            {
                RGBLEDOnOff(0, 1, 0);                                          //Turn ON GreenLED
            }
            if(((55 < ui16XPosition[0]) && (ui16XPosition[0] < 95)) &&
              ((80 < ui16YPosition[0]) && (ui16YPosition[0] < 120)))
            {
                RGBLEDOnOff(0, 0, 1);                                          //Turn ON BlueLED
            }
            bTouchStatus = 0;
        }
    }
}
```

12. To build the program, click the **Hammer** icon in CCS. Alternatively: **Project** → **Build Project**.


13. CCS takes a while to compile and check for errors. If no error is detected, the `Build Finished` message appears in the console panel.


14. To debug the program, click the **Bug** icon. Alternatively: **Run** → **Debug**, or press `F11`.


15. To run the program, click the **Play** icon. Alternatively: **Run** → **Resume**, or press `F8`.


16. Three filled circles with different colours appear on the LCD screen. Touch each circle to see the RGB LED change colour.

17. To suspend the program, click the **Pause** icon. Alternatively: **Run** → **Suspend**, or press `Alt+F8`.


18. To terminate the program: **Run** → **Terminate**, or click the **Stop** icon, or press `Ctrl+F2`.


19. To insert a breakpoint at a line (e.g. line 32), double-click on the line number. A blue dot appears to indicate the breakpoint.


20. Repeat steps 14 and 15 to debug and run. The program will stop at the breakpoint.


21. While paused at the breakpoint, variable values can be observed in the **Variables** window.


22. To single-step from the breakpoint: **Run** → **Step Over**, or press `F6`. To resume normal speed, repeat step 15.


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


6. Click **Load Image** to flash `Project.out` into the microcontroller. Flashing takes a while — once complete, the program runs on the microcontroller.



---

> 💡 **Key Shortcuts Summary**
>
> | Action | Shortcut / Method |
> |--------|-------------------|
> | Build | Hammer icon / **Project → Build Project** |
> | Debug | Bug icon / **Run → Debug** / `F11` |
> | Run/Resume | Play icon / **Run → Resume** / `F8` |
> | Suspend | Pause icon / **Run → Suspend** / `Alt+F8` |
> | Terminate | Stop icon / **Run → Terminate** / `Ctrl+F2` |
> | Step Over | **Run → Step Over** / `F6` |
> | Breakpoint | Double-click line number |
