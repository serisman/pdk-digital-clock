#ifndef __UTIL_H__
#define __UTIL_H__

#include <stdbool.h>
#include <stdint.h>

#define HIGH                          1
#define LOW                           0

// ----------------------------------------------------------------------

#define BV(bit)											  (uint8_t)(1<<(bit))

#define BV1(b1)											  (BV(b1))
#define BV2(b1,b2)										(BV(b1)|BV(b2))
#define BV3(b1,b2,b3)							  	(BV(b1)|BV(b2)|BV(b3))
#define BV4(b1,b2,b3,b4)							(BV(b1)|BV(b2)|BV(b3)|BV(b4))
#define BV5(b1,b2,b3,b4,b5)					  (BV(b1)|BV(b2)|BV(b3)|BV(b4)|BV(b5))
#define BV6(b1,b2,b3,b4,b5,b6)				(BV(b1)|BV(b2)|BV(b3)|BV(b4)|BV(b5)|BV(b6))
#define BV7(b1,b2,b3,b4,b5,b6,b7)		  (BV(b1)|BV(b2)|BV(b3)|BV(b4)|BV(b5)|BV(b6)|BV(b7))
#define BV8(b1,b2,b3,b4,b5,b6,b7,b8)	(BV(b1)|BV(b2)|BV(b3)|BV(b4)|BV(b5)|BV(b6)|BV(b7)|BV(b8))

#define setBit(byte,bit)							byte |= BV(bit)
#define clearBit(byte,bit)						byte &= ~(BV(bit))
#define setBits(byte,mask)						byte |= mask
#define clearBits(byte,mask)					byte &= ~(mask)

#define isBitSet(byte,bit)						byte & BV(bit)
#define isBitClear(byte,bit)					!(byte & BV(bit))
#define areBitsSet(byte,mask)			  	byte & mask
#define areBitsClear(byte,mask)		  	!(byte & mask)

// ----------------------------------------------------------------------

#define ARG1_EX(a,...)								a
#define ARG2_EX(a,b,...)							b

#define _REG_EX(reg,...)              _ ## reg
#define _REG_CTRL_EX(reg,...)         _ ## reg ## c
#define _BIT_EX(reg,bit)              bit

#define PORT_EX(port,pin)             port
#define PORT_CTRL_EX(port,pin)        port ## c
#define PORT_DIER_EX(port,pin)        port ## dier
#define PORT_PULLUP_EX(port,pin)      port ## ph
#define PIN_EX(port,pin)              port ## pin

// ----------------------------------------------------------------------

#define ARG1(args)										ARG1_EX(args)
#define ARG2(args)										ARG2_EX(args)

#define _REG(spec)                    _REG_EX(spec)
#define _REG_CTRL(spec)               _REG_CTRL_EX(spec)
#define _BIT(spec)                    _BIT_EX(spec)

#define PORT(pinspec)                	PORT_EX(pinspec)
#define PORT_CTRL(pinspec)            PORT_DIR_EX(pinspec)
#define PIN(pinspec)                 	PIN_EX(pinspec)

#define setPinOutput(pinspec)         setBit(PORT_CTRL_EX(pinspec),ARG2_EX(pinspec))
#define setPinInput(pinspec)          clearBit(PORT_CTRL_EX(pinspec),ARG2_EX(pinspec))

#define enableDigitalInput(pinspec)   setBit(PORT_DIER_EX(pinspec),ARG2_EX(pinspec))
#define disableDigitalInput(pinspec)  clearBit(PORT_DIER_EX(pinspec),ARG2_EX(pinspec))

#define setPinPullup(pinspec)         setBit(PORT_PULLUP_EX(pinspec),ARG2_EX(pinspec))
#define clearPinPullup(pinspec)       clearBit(PORT_PULLUP_EX(pinspec),ARG2_EX(pinspec))

#define setPin(pinspec)	  		  	    setBit(PORT_EX(pinspec),ARG2_EX(pinspec))
#define clearPin(pinspec)		     	    clearBit(PORT_EX(pinspec),ARG2_EX(pinspec))

#define isPinHigh(pinspec)            isBitSet(PORT_EX(pinspec),ARG2_EX(pinspec))
#define isPinLow(pinspec)             isBitClear(PORT_EX(pinspec),ARG2_EX(pinspec))

// ----------------------------------------------------------------------

#endif /* __UTIL_H__ */
