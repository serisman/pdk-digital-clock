# pdk-digital-clock
A 4-digit 7-segment digital clock, based on the inexpensive 8-bit Padauk microcontrollers

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
> ![Schematic](https://github.com/serisman/pdk-digital-clock/blob/master/pcb-s16/output/Schematic.png?raw=true)

### Compatibility
This project is currently intended to be run (without modifications) on the PFS154, PFS173, PMS152, and PMS154C Padauk microcontrollers,
but it should be able to be modified to run on other 16-pin Padauk microcontrollers that are supported by SDCC and the Easy PDK Programmer.

### Bill of Materials
| Ref | Part # | Description | Footprint | Purchase Link | Price | Minimum Purchase |
| --- | --- | --- | --- | --- | --- | --- |
| PCB | - | - | - | [OSHPARK](https://oshpark.com/shared_projects/jvGgF1gC) | $1.033 each | $3.10 for 3 |
| U3 | SLR0394DRA5BD | 4-digit time-mode 7-segment display | - | [LCSC C225902](https://lcsc.com/product-detail/Led-Segment-Display_SUNLIGHT-SLR0394DRA5BD_C225902.html) | $0.501 each | $0.501 for 1|  
| U1 | PMS152-S16 | 8-bit Padauk microcontroller | SOP-16 | [LCSC C317590](https://lcsc.com/product-detail/Others_PADAUK-Tech-PMS152-S16_C317590.html) | $0.077 each | $0.39 for 5 |
| U2 | 74HC595D | Serial shift register | SOP-16 | [LCSC C93838](https://lcsc.com/product-detail/LED-Drivers_Shenzhen-Sunmoon-Micro-SM74HC595D_C93838.html) | $0.046 each | $0.46 for 10 |
| Y1 | - | 32.767KHz radial cylinder crystal | 2x6mm | [LCSC C2236](https://lcsc.com/product-detail/Radial-Cylinder-Crystals_Yangxing-Tech-X206032768KGB2SC_C2236.html) | $0.045 each | $0.45 for 10 |
| J1 | - | Micro USB connector | - | [LCSC C393940](https://lcsc.com/product-detail/USB-Connectors_SHOU-HAN-MICRO5-9mmusb_C393940.html) | $0.026 each | $0.52 for 20 |   
| SW1 | TS24CA | SPST side-actuated button tactile switch | - | [LCSC C393942](https://lcsc.com/product-detail/Tactile-Switches_SHOU-HAN-TS24CA_C393942.html) | $0.025 each | $0.50 for 20 |
| C2 | - | 10uF capacitor | 0805 | [LCSC C92786](https://lcsc.com/product-detail/Multilayer-Ceramic-Capacitors-MLCC-SMD-SMT_Taiyo-Yuden_JMK212BJ106KD-T_Taiyo-Yuden-JMK212BJ106KD-T_C92786.html) | $0.015 each | $0.73 for 50 |
| C3,C4 | - | 20pF capacitor | 0805 | [LCSC C309037](https://lcsc.com/product-detail/Multilayer-Ceramic-Capacitors-MLCC-SMD-SMT_CCTC-TCC0805C0G200J500BT_C309037.html) | $0.007 each | $0.36 for 50 |
| RN1,RN2 | - | 4x 680 ohm resistor network | 0603_x4 | [LCSC C102679](https://lcsc.com/product-detail/Resistor-Networks-Arrays_RALEC-RTA03-4D681JTP_C102679.html) | $0.007 each | $0.35 for 50 |
| C1 | - | 100nF capacitor | 0805 | [LCSC C235732](https://lcsc.com/product-detail/Multilayer-Ceramic-Capacitors-MLCC-SMD-SMT_PSA-Prosperity-Dielectrics-FN21X104K500PXG_C235732.html) | $0.006 each | $0.30 for 50 |

Total: ~$1.80 each (+/- depending on quantity)

### Images
![Front (without 7-segment display)](https://github.com/serisman/pdk-digital-clock/blob/master/img/Front%20(without%207-segment%20display).jpg?raw=true)
![Back](https://github.com/serisman/pdk-digital-clock/blob/master/img/Back.jpg?raw=true)
![Installed and working!](https://github.com/serisman/pdk-digital-clock/blob/master/img/Installed%20and%20working.jpg?raw=true)

### Copyright and License:
- Copyright (C) 2020 - serisman (github@serisman.com)
- License: [GPL v3 (or later)](LICENSE)
