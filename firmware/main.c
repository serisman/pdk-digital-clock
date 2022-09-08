/*
  main.c: Main program code for the PDK digital clock project.

  Copyright (C) 2020  serisman  <github@serisman.com>

  This program is free software: you can redistribute it and/or modify
  it under the terms of the GNU General Public License as published by
  the Free Software Foundation, either version 3 of the License, or
  (at your option) any later version.

  This program is distributed in the hope that it will be useful,
  but WITHOUT ANY WARRANTY; without even the implied warranty of
  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
  GNU General Public License for more details.

  You should have received a copy of the GNU General Public License
  along with this program.  If not, see <http://www.gnu.org/licenses/>.
*/

#include <pdk/device.h>
#include <easy-pdk/calibrate.h>
#include "util.h"

#define PORT_SEGMENTS   PB
#define PIN_SR_DATA     PA,3
#define PIN_SR_CLOCK    PA,0
#define PIN_SR_LATCH    PA,4

#define PIN_BTN         PA,5

volatile uint8_t quarter_seconds;

// Initialize clock to 12:00:00 AM
uint8_t hours_10=1, hours_01=2, minutes_10, minutes_01, seconds_10, seconds_01, am_pm;

// Initialize display to --:--
uint8_t digit1=0b01000000, digit2=0b01000000, digit3=0b01000000, digit4=0b01000000;
uint8_t current_digit_mask = 0b10001000;

uint8_t _tmp, prev_quarter_seconds, btn_ctr, display_mode, config_mode, config_ctr;

// void display_next_digit()
//
//  Rotates to and outputs a single digit 'register' for a 4-digit 7-segment display.
//  NOTE: This should be called multiple 100's of times a second to light up all the digits for 'persistence of vision'.
//    This method has been written in assembly to make it as small and fast as possible.
//  This uses a 74HC595 as a digit 'driver' which provides two benefits:
//   1. Enables 4 (or more) outputs (digits) from 3 IO pins.
//   2. Enables a higher current sink for each digit than IO pins would otherwise allow.
//  We double up the 74HC595 output pins (i.e. 2 per digit) for extra current sink capability.
//
//  Assumes (#define'd above):
//   Segments[a-g,dp] are mapped to PB[0-7]
//   74HC595 (14) DS - DATA is on PA3
//   74HC595 (11) SH_CP - CLOCK is on PA0
//   74HC595 (12) ST_CP - LATCH is on PA4
void display_next_digit() {
__asm
	;// Rotate to next digit
  set0  f, c
  t0sn  _current_digit_mask, #7
    set1  f, c
  slc   _current_digit_mask

	;// Shift out /EN for all digits to 74HC595
	mov   a, _current_digit_mask
	mov   __tmp, a
	mov   a, #8
00001$:
	set1  _REG(PIN_SR_DATA), #_BIT(PIN_SR_DATA)
	t0sn  __tmp, #7
		set0  _REG(PIN_SR_DATA), #_BIT(PIN_SR_DATA)
	set1  _REG(PIN_SR_CLOCK), #_BIT(PIN_SR_CLOCK)
	set0  _REG(PIN_SR_CLOCK), #_BIT(PIN_SR_CLOCK)
	sl    __tmp
	dzsn  a
		goto  00001$
	set1  _REG(PIN_SR_DATA), #_BIT(PIN_SR_DATA)

	;// Get the current digit's segments
	t0sn  _current_digit_mask, #0
		mov   a, _digit1
	t0sn  _current_digit_mask, #1
		mov   a, _digit2
	t0sn  _current_digit_mask, #2
		mov   a, _digit3
	t0sn  _current_digit_mask, #3
		mov   a, _digit4
	mov   __tmp, a

	;// Disable the previous digit's segments
	disgint
	mov   a, #0b00000000
	mov   _REG(PORT_SEGMENTS), a

	;// Latch 74HC595 - Enables the digit that was set low
	set1  _REG(PIN_SR_LATCH), #_BIT(PIN_SR_LATCH)

	;// Enable the current digit's segments
	mov   a, __tmp
	mov   _REG(PORT_SEGMENTS), a
	engint

	set0  _REG(PIN_SR_LATCH), #_BIT(PIN_SR_LATCH)

__endasm;
}

// uint8_t bcd_to_7segment(uint8_t bcd)
//
//  Given a number 0 through 9, will return a 7 segment digit mask representation of said number
//  Assumes bits 0-6 maps to the top segment, then the other segments in a clockwise circle, and finally the middle segment,
//    with bit 7 being the 'dot'
uint8_t bcd_to_7segment(uint8_t bcd) __naked {
//	if (bcd > 9) return 0b00000000;
//	switch (bcd) {
//		case 0: return 0b00111111;
//		case 1: return 0b00000110;
//		case 2: return 0b01011011;
//		case 3: return 0b01001111;
//		case 4: return 0b01100110;
//		case 5: return 0b01101101;
//		case 6: return 0b01111101;
//		case 7: return 0b00000111;
//		case 8: return 0b01111111;
//		case 9: return 0b01100111;
//	}
	bcd; // Ignore unreferenced function argument warning
__asm
	;// Make sure bcd is <= 9 (otherwise unexpected results would occur!)
	mov	a, #9
	sub	a, _bcd_to_7segment_PARM_1
	t0sn	f, c
		ret	#0b00000000
	;// Lookup and return 7-segment representation
	mov   a, _bcd_to_7segment_PARM_1
	add   a, #1
	pcadd a
	ret   #0b00111111     ;// 0
	ret   #0b00000110     ;// 1
	ret   #0b01011011     ;// 2
	ret   #0b01001111     ;// 3
	ret   #0b01100110     ;// 4
	ret   #0b01101101     ;// 5
	ret   #0b01111101     ;// 6
	ret   #0b00000111     ;// 7
	ret   #0b01111111     ;// 8
	ret   #0b01101111     ;// 9
__endasm;
}

// Increment the clock's time values with cascading roll-overs
// NOTE: This needs to be called EXACTLY once a second!
void update_clock() {
  if (++seconds_01 == 10) {
    seconds_01=0;
    if (++seconds_10 == 6) {
      seconds_10=0;
      if (++minutes_01 == 10) {
        minutes_01=0;
        if (++minutes_10 == 6) {
          minutes_10=0;
          hours_01++;
          if (hours_10 == 0 && hours_01 == 10) {
            hours_01=0;
            hours_10++;
          } else if (hours_10 == 1 && hours_01 == 3) {
            hours_01=1;
            hours_10=0;
          } else if (hours_10 == 1 && hours_01 == 2) {
            am_pm = 1-am_pm;
          }
        }
      }
    }
  }
}

// Write the current time (seconds or hours:minutes) to the 4x 7-segment digit 'registers'
void update_time_display() {
	if (display_mode) {
    // Seconds
		digit1 = 0b01101101;    // 'S'
		digit2 = 0;
		digit3 = bcd_to_7segment(seconds_10);
		digit4 = bcd_to_7segment(seconds_01);

		if (display_mode++ == 4) display_mode = 0;  // Revert to HH:MM display after a second or so
	} else {
		// Hours
		digit1 = 0b00000000; // Don't display leading 0 for hours
		if (hours_10)
			digit1 = bcd_to_7segment(hours_10);
		digit2 = bcd_to_7segment(hours_01);

		// Minutes
		digit3 = bcd_to_7segment(minutes_10);
		digit4 = bcd_to_7segment(minutes_01);

		// AM/PM indicator
		if (am_pm)
			setBit(digit1,7);
	}

	// Blink the half-second indicator
	if (quarter_seconds & 0b00000010) {
		setBit(digit2,7);
		setBit(digit4,7);
	}
}

// Write the current config variable to the 4x 7-segment digit 'registers'
void update_config_display() {
	digit1=digit2=digit3=digit4=0;

	if (/*config_mode == 1 || config_mode == 2*/ config_mode < 3) {
		// Seconds
		digit1 = 0b01101101;    // 'S'
		digit3 = bcd_to_7segment(seconds_10);
		digit4 = bcd_to_7segment(seconds_01);
  } else if (/*config_mode > 2 &&*/ config_mode < 7) {
    // Hours:Minutes
		digit1 = bcd_to_7segment(hours_10);
    digit2 = bcd_to_7segment(hours_01);
    digit3 = bcd_to_7segment(minutes_10);
    digit4 = bcd_to_7segment(minutes_01);
   } else /*if (config_mode == 7)*/ {
		if (am_pm) {
			digit1 = 0b01110011;  // 'P'
		} else {
			digit1 = 0b01110111;  // 'A'
		}
	}

  // Blink the current config variable digit
	if (quarter_seconds & 0b00000001) {
		switch (config_mode) {
			case 1:
			case 3: digit4 = 0; break;
			case 2:
			case 4: digit3 = 0; break;
			case 5: digit2 = 0; break;
			case 6:
			case 7: digit1 = 0; break;
		}
	} else {
	  // Blink the seconds indictor as a config indicator
  	setBit(digit2,7);
	  setBit(digit4,7);
	}
}

// Write the appropriate 'screen' to the 4x 7-segment digit 'registers'
void update_display() {
  if (!config_mode) {
    update_time_display();
  } else {
    update_config_display();
  }
}

// Increment the current config variable with reset on rollover
void increment_config_value() {
	switch (config_mode) {
		case 1: if (++seconds_01 == 10) seconds_01 = 0;	break;
		case 2:	if (++seconds_10 == 6) seconds_10 = 0;	break;
		case 3:	if (++minutes_01 == 10) minutes_01 = 0;	break;
		case 4:	if (++minutes_10 == 6) minutes_10 = 0;	break;
		case 5:	if (++hours_01 == 10) hours_01 = 0;	break;
		case 6:	hours_10 = 1-hours_10;	break;
		case 7:	am_pm = 1-am_pm;	break;
	}
}

// Check the button's state and process button up/down events
void process_btn() {
	if (isPinLow(PIN_BTN)) {
		if (!btn_ctr) {               // On button down
			btn_ctr = 1;
			display_mode = 1;           // Briefly show Seconds
      update_display();
		} else if (btn_ctr == 5) {    // Long press (don't wait for button up)
			btn_ctr++;
			display_mode = 0;
      config_mode++;              // Enter config / Move to next config setting
      config_ctr = 1;
      if (config_mode == 8) {
        config_mode = 0;          // Exit config
      }
      update_display();
    } else if (btn_ctr == 14) {   // Really long press (don't wait for button up)
      btn_ctr++;
      config_mode = 0;            // Exit config
      update_display();
    }
	} else if (btn_ctr) {           // On button up
		if (btn_ctr < 5) {            // Short press (wait for button up)
			if (config_mode) {
			  config_ctr = 1;
				increment_config_value(); // Increment config setting
			}
			update_display();
		}
		btn_ctr = 0;
	}
}

// Process things that we want done every 1/4 seconds
void every_quarter_second() {
	if ((quarter_seconds & 0b00000011) == 0b00000011) {
    update_clock();
  }
  if (btn_ctr && btn_ctr != 255) {
 		btn_ctr++;
	}
	if (config_mode && config_ctr++ == 40) {
    config_mode = 0;            // Exit config (timeout)
	}
  update_display();
}

// Main program
void main() {
  // Make sure PA7/PA6 is Disabled for External Crystal (recommended for all ICs)
  // Make sure PA5 is Enabled as input for Button (needed by PMS152/PFS173)
  PADIER = 0b00100000;

	// Set appropriate pins as outputs (all pins are input by default)
	PAC = 0b00011001;           // Set PA[0,3,4] to output (74HC595 for digits)
	PBC = 0xFF;                 // Set Port B[0-7] to output (segments)
	setPinPullup(PIN_BTN);

	// Enable T16 timer to generate an interrupt every 1/4 seconds
#if (DEBUG == 1)
	#if (F_CPU == 65536)
		T16M = 0b11010001;        // Use ILRC clock source (65.536 kHz), /16, Interrupt on (rising) Bit 9
	#elif (F_CPU == 524288)
		T16M = 0b00111010;        // Use System (IHRC) clock source (524.288 kHz), /64, Interrupt on (rising) Bit 10
	#endif
#else
	EOSCR = 0b10100000;         // Enable External Oscillator (32kHz crystal)
	T16M = 0b10110000;          // Use EOSC clock source (32.768 kHz), /16, Interrupt on (rising) Bit 8
#endif
	T16C = 0;
	INTEN = INTEN_T16;

	// Enable interrupts
	INTRQ = 0;
	__engint();

  // Main processing loop
	while(1) {
    if (quarter_seconds != prev_quarter_seconds) {
      every_quarter_second();
      prev_quarter_seconds = quarter_seconds;
    }
    process_btn();
    display_next_digit();
	}
}

// Interrupt handler (kept as simple/minimalistic as possible)
//  - When T16 'ticks' - Increment our quarter_seconds 'register'
void interrupt(void) __interrupt(0) __naked {
//	if (INTRQ & INTRQ_T16) {
//		quarter_seconds++;
//		INTRQ &= ~INTRQ_T16;
//	}
__asm
	t1sn	_REG(INTRQ), #INTRQ_T16_BIT
		goto  00001$
	push  af
	inc   _quarter_seconds
	set0	_REG(INTRQ), #INTRQ_T16_BIT
	pop   af
00001$:
	reti
__endasm;
}

unsigned char _sdcc_external_startup(void) {

#if defined(PFS154)
  PDK_SET_FUSE(FUSE_SECURITY_OFF|FUSE_IO_DRV_NORMAL|FUSE_BOOTUP_FAST);
#elif defined(PFS173)
  PDK_SET_FUSE(FUSE_SECURITY_OFF|FUSE_PB4_PB5_NORMAL|FUSE_BOOTUP_FAST);
#elif defined(PMS152)
  PDK_SET_FUSE(FUSE_SECURITY_OFF|FUSE_BOOTUP_FAST);
#elif defined(PMS154C)
  PDK_SET_FUSE(FUSE_SECURITY_OFF|FUSE_LVR_2V|FUSE_IO_DRV_NORMAL|FUSE_BOOTUP_FAST);
#else
  #error "Device not currently supported!"
#endif

  // Make sure we have a reasonable LVR value.
  // Red LEDs work at around 2V, so let's use that as our minimum.
#if defined(MISCLVR_2V)
  MISCLVR = (uint8_t) MISCLVR_2V;
#endif

  // Calibrate IHRC or ILRC for values that work better for timekeeping.
  // Nowhere near accurate enough for actual timekeeping, but good enough for debugging (i.e. testing without a crystal).
  // For real timekeeping, we use an external 32.768 kHz crystal as input to T16.
#if (F_CPU == 524288)
  PDK_SET_SYSCLOCK(SYSCLOCK_IHRC_500KHZ);
  EASY_PDK_CALIBRATE_IHRC(524288, TARGET_VDD_MV);
#elif (F_CPU == 65536)
  PDK_SET_SYSCLOCK(SYSCLOCK_ILRC);
  EASY_PDK_CALIBRATE_ILRC(65536, TARGET_VDD_MV);
#else
  #error "Unknown F_CPU"
#endif

  return 0;
}
