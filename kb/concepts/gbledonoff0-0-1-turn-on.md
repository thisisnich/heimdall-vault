---
id: "a16b6c90-5d8e-4416-b061-602c248b9952"
title: "Gbledonoff0 0 1 Turn On"
type: vault_note
vault: wiki
created: 2026-05-17
updated: 2026-05-17
checksum: "sha256:b2a170285a82e2b8"
source: heimdall/auto
---

# Gbledonoff0 0 1 Turn On

- GBLEDOnOff(0, 0, 1);                                          //Turn ON BlueLED
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


23. Repeat step 18 to terminate. <!-- id:a16b6c90-5d8e-4416-b061-602c248b9952 ts:2026-05-17 07:49 -->
