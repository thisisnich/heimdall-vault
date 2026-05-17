---
id: "1e073a04-068a-46f2-8371-3bce61e38cb7"
title: "Chpanelinthandler Register Touch Panel Interrupt"
type: vault_note
vault: wiki
created: 2026-05-17
updated: 2026-05-17
checksum: "sha256:02658942ff5408b5"
source: heimdall/auto
---

# Chpanelinthandler Register Touch Panel Interrupt

- chPanelIntHandler);                //Register Touch Panel Interrupt

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

12. <!-- id:1e073a04-068a-46f2-8371-3bce61e38cb7 ts:2026-05-17 07:49 -->
- chPanelIntHandler);                //Register Touch Panel Interrupt

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

12. <!-- id:1e073a04-068a-46f2-8371-3bce61e38cb7 ts:2026-05-17 07:49 -->
