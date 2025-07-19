# firmware ([pdk-digital-clock](https://github.com/serisman/pdk-digital-clock/))

A single push button is used to set the time, with the following 'user interface':
- A short press will temporarily show the current 'seconds'.
- A medium-press will switch to time config mode.  While in config mode:
    - A short press will increment the currently selected time value, with rollover.
    - A medium-press will switch to the next time value, or exit config mode if on the last time value.
    - A long-press will exit config mode.

### Toolchain:
- The open-source [Small Device C Compiler (SDCC)](http://sdcc.sourceforge.net/)
  - Requires version 4.4.0+
- The open-source [Easy PDK Programmer](https://github.com/free-pdk/easy-pdk-programmer-software)
  - Requires version 1.3 or newer
- The open-source [pdk-includes](https://github.com/free-pdk/pdk-includes) repository
  - Integrated via local copy into the pdk/ directory
- The open-source [easy-pdk-includes](https://github.com/free-pdk/easy-pdk-includes) repository
  - Integrated via local copy into the easy-pdk/ directory
- Also requires 'make' and other common build tools

### Build Commands:
```
make clean
make build
make size (also calls build)
make program (also calls size which calls build)
make run
```
> Note: These commands can be chained as well.  i.e. `make clean program run`

### Customization:
Edit the variables at the top of the Makefile to:
- **DEVICE**: Use a different Padauk MCU (defaults to PFS154)
- **F_CPU**: Use a different frequency for the system clock (defaults to 524.288 kHz, i.e. IHRC/32)
  > Note: Valid choices are: 524288 to use the IHRC, or 65536 to use the ILRC.  These values make it easier for timekeeping (although true accuracy only comes from using an external crystal).
- **TARGET_VDD_MV**: Use a different voltage while calibrating the internal oscillator (IHRC or ILRC) (defaults to 4000mV)
- **TARGET_VDD**: Use a different voltage while the IC is operating (defaults to 4.0V)
- **DEBUG**: If set to 1, the 16-bit timer will use the less accurate internal oscillator instead of requiring an external crystal (defaults to 0)

> Note: All of these variables can be changed on the commandline as well.  i.e. `make DEVICE=PFS173 clean program run` 

### Compatibility
This project is currently intended to be run (without modifications) on the PFS154, PFS173, PMS152, and PMS154C Padauk microcontrollers,
but it should be able to be modified to run on other 16-pin Padauk microcontrollers that are supported by SDCC and the Easy PDK Programmer.
Less common devices may require additional device specific include files (pdk/device/*.h) to be supplied.

### Build Stats
- Code Size: ~463 words
- RAM usage: 22 bytes + stack
