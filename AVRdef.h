#ifndef _AVRDEF_H_
#define _AVRDEF_H_	1

#if !defined(_AVR)
#error "This file should only be used with ICCV7 for AVR"
#endif

#ifndef BIT
#define BIT(x)	(1 << (x))
#endif

#if !defined(flash)
#define flash	__flash		/* IAR compatibility */
#endif

#ifndef C_task
#define C_task
#endif

#define _asm	asm			/* old style */

#define WDR() 	asm("wdr")
#define SEI()	asm("sei")
#define CLI()	asm("cli")
#define NOP()	asm("nop")
#define SPM()	asm("spm")
#define SLEEP() asm("sleep");
#define _WDR() 	asm("wdr")
#define _SEI()	asm("sei")
#define _CLI()	asm("cli")
#define _NOP()	asm("nop")
#define _SPM()	asm("spm")
#define _SLEEP() asm("sleep");

#endif
