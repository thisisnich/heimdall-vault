

/**
 * main.c
 */
#include <stdbool.h>
#include <stdint.h>
#include "clock.h"
#include "rgbled.h"                                     //Include the rgbled driver file

uint32_t ui32Count = 0;

void MultiColorLEDDisplay(void)
{
    //Turn ON Red LED
    RGBLEDOnOff(1, 0, 0);

    //LED ON for ~0.5s
    for(ui32Count=0; ui32Count<3000000; ui32Count++);

    //Turn OFF Red LED
    RGBLEDOnOff(0, 0, 0);

    //LED OFF for ~0.5s
    for(ui32Count=0; ui32Count<3000000; ui32Count++);

    //Turn ON and OFF Green LED
    RGBLEDOnOff(0, 1, 0);
    for(ui32Count=0; ui32Count<3000000; ui32Count++);
    RGBLEDOnOff(0, 0, 0);
    for(ui32Count=0; ui32Count<3000000; ui32Count++);

    //Turn ON and OFF Blue LED
    RGBLEDOnOff(0, 0, 1);
    for(ui32Count=0; ui32Count<3000000; ui32Count++);
    RGBLEDOnOff(0, 0, 0);
    for(ui32Count=0; ui32Count<3000000; ui32Count++);
}

int main(void)
{
    ClockFrequencySet(120000000);                       //Set processor clock to 120MHz
    RGBLEDPinInit();                                    //Initialize RGB LED pin

    while(1)
    {
        //MultiColorLEDDisplay function call
        MultiColorLEDDisplay();
    }
}
