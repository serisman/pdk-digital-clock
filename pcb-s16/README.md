# pcb-s16 ([pdk-digital-clock](https://github.com/serisman/pdk-digital-clock/))

### Schematic
(for 16-pin PFS154, PFS173, PMS152, or PMS154C)
> ![Schematic](https://github.com/serisman/pdk-digital-clock/blob/master/img/Schematic.png?raw=true)

### PCB

This PCB design was created with KiCad, and has been [shared on OSHPARK](https://oshpark.com/shared_projects/jvGgF1gC).
There are also gerber files available in the [output/gerber/](output/gerber/) directory.

This uses the [SLR0394DRC5BD](https://lcsc.com/product-detail/Led-Segment-Display_SUNLIGHT-SLR0394DRA5BD_C225902.html) 4-digit 7-segment common cathode 'time' display,
which sits over the top of the 74HC595 and the (2) 4x resistor packs.
The 74HC595 is used to drive the (4) 7-segment digits, (2) outputs per digit for extra current sink capabilities.
The segments themselves are driven directly by the Port B outputs of the Padauk microcontroller.

A single push button is used to set the time, with the following 'user interface':
- A short press will temporarily show the current 'seconds'.
- A medium-press will switch to time config mode.  While in config mode:
  - A short press will increment the currently selected time value, with rollover.
  - A medium-press will switch to the next time value, or exit config mode if on the last time value.
  - A long-press will exit config mode. 

This digital clock is powered via micro USB cable, although it should work at much lower voltages as well.
It isn't really suitable for long-term battery operation, as the LED based 7-segment display consumes enough energy that it wouldn't last very long.

![3D Render - display](https://github.com/serisman/pdk-digital-clock/blob/master/img/3D%20Render%20-%20display.png?raw=true)
![3D Render - Top](https://github.com/serisman/pdk-digital-clock/blob/master/img/3D%20Render%20-%20Top.png?raw=true)
![3D Render - Bottom](https://github.com/serisman/pdk-digital-clock/blob/master/img/3D%20Render%20-%20Bottom.png?raw=true)
![PCB Top](https://github.com/serisman/pdk-digital-clock/blob/master/img/PCB%20-%20Top.png?raw=true)
![PCB Bottom](https://github.com/serisman/pdk-digital-clock/blob/master/img/PCB%20-%20Bottom.png?raw=true)
