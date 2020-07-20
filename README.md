# pdk-digital-clock
A 4-digit 7-segment digital clock, based on the inexpensive Padauk microcontrollers

### Links
- [Firmware](firmware/)
- [PCB](pcb-s16/)

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

### Schematic
(for 16-pin PFS154, PFS173, PMS152, or PMS154C)
> ![Schematic](https://github.com/serisman/pdk-digital-clock/blob/master/img/Schematic.png?raw=true)

### Compatibility
This project is currently intended to be run (without modifications) on the PFS154, PFS173, PMS152, and PMS154C Padauk microcontrollers,
but it should be able to be modified to run on other 16-pin Padauk microcontrollers that are supported by SDCC and the Easy PDK Programmer.

### Copyright and License:
- Copyright (C) 2020 - serisman (github@serisman.com)
- License: [GPL v3 (or later)](LICENSE)
