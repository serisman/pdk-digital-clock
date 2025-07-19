# firmware-serial ([pdk-digital-clock](https://github.com/serisman/pdk-digital-clock/))

This alternate firmware allows the time to be set by a serial command instead of requiring button presses.
This makes it easier to keep time updated and synced after it naturally drifts due to crystal accuracy and temperature fluctuations.

To set/update time, connect a Serial UART's TX pin (TTL level) to pin PA5 (PIN_RX):
- Send the following 5 bytes @9600 baud (1 start bit, 8 data bits, 1 stop bit, no parity):
  - `start byte`: 0x00
  - `hours byte`: using bcd notation, bit[7] is am_pm indicator, bits[5:4] is hours_10, bits[3:0] is hours_01
  - `minutes byte`: using bcd notation, bits[6:4] is minutes_10, bits[3:0] is minutes_01
  - `seconds byte`: using bcd notation, bits[6:4] is seconds_10, bits[3:0] is seconds_01
  - `parity byte`: the sum of all preceding data bytes.

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
  > Note: Only valid choice is: 524288 to use the IHRC.  This values make it easier for timekeeping (although true accuracy only comes from using an external crystal).
          Changing this would also require changes to the UART receive code which has very precise timing requirements.
- **TARGET_VDD_MV**: Use a different voltage while calibrating the internal oscillator (IHRC or ILRC) (defaults to 3300mV)
- **TARGET_VDD**: Use a different voltage while the IC is operating (defaults to 3.3V)
- **DEBUG**: If set to 1, the 16-bit timer will use the less accurate internal oscillator instead of requiring an external crystal (defaults to 0)

> Note: All of these variables can be changed on the commandline as well.  i.e. `make DEVICE=PFS173 clean program run` 

### Compatibility
This project is currently intended to be run (without modifications) on the PFS154, PFS173, PMS152, and PMS154C Padauk microcontrollers,
but it should be able to be modified to run on other 16-pin Padauk microcontrollers that are supported by SDCC and the Easy PDK Programmer.
Less common devices may require additional device specific include files (pdk/device/*.h) to be supplied.

### Build Stats
- Code Size: ~365 words
- RAM usage: 28 bytes + stack
