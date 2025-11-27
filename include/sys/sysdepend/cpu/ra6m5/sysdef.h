/*
 *----------------------------------------------------------------------
 *    micro T-Kernel 3.00.08.B1
 *
 *    Copyright (C) 2006-2025 by Ken Sakamura.
 *    This software is distributed under the T-License 2.2.
 *----------------------------------------------------------------------
 *
 *    Released by TRON Forum(http://www.tron.org) at 2025/11.
 *
 *----------------------------------------------------------------------
 */

/*
 *	sysdef.h
 *
 *	System dependencies definition (RA6M5 depended)
 *	Included also from assembler program.
 */

#ifndef __TK_SYSDEF_DEPEND_CPU_H__
#define __TK_SYSDEF_DEPEND_CPU_H__

#include "../../../machine.h"

/* CPU Core-dependent definition */
#include "../core/armv8m/sysdef.h"

/* ------------------------------------------------------------------------ */
/*
 * Internal Memorie (Main RAM)
 */
/* RA6M5 Internal SRAM0   0x20000000 - 0x2007FFFF  (Size 512KB) */
#define INTERNAL_RAM_START      0x20000000
#define INTERNAL_RAM_SIZE       0x0007FFFF

#define INTERNAL_RAM_END        (INTERNAL_RAM_START+INTERNAL_RAM_SIZE)

/* ------------------------------------------------------------------------ */
/*
 * Initial Stack pointer (Used in initialization process)
 */
#define	INITIAL_SP		INTERNAL_RAM_END

/* ------------------------------------------------------------------------ */
/*
 * System Timer clock
 */

/* Settable interval range (millisecond) */
#define MIN_TIMER_PERIOD	1
#define MAX_TIMER_PERIOD	50

/* ------------------------------------------------------------------------ */
/*
 * Number of Interrupt vectors
 */
#define	N_SYSVEC		16	/* Number of System Exceptions */
#define N_INTVEC		96	/* Number of Interrupt vectors */

/*
 * Exception vector table alignment
*/
#define	EXCTBL_ALIGN		1024

/*
 * The number of the implemented bit width for priority value fields.
 */
#define INTPRI_BITWIDTH		4

/* ------------------------------------------------------------------------ */
/*
 * Interrupt Priority Levels
 */
#define INTPRI_MAX_EXTINT_PRI	1	/* Highest Ext. interrupt level */
#define INTPRI_SVC		0	/* SVCall */
#define INTPRI_SYSTICK		1	/* SysTick */
#define INTPRI_PENDSV		15	/* PendSV */

/*
 * Time-event handler interrupt level
 */
#define TIMER_INTLEVEL		0

/* ------------------------------------------------------------------------ */
/*
 * Coprocessor
 */
#define CPU_HAS_FPU		1
#define CPU_HAS_DSP		0

/*
 *  Number of coprocessors to use. Depends on user configuration
 */
#if USE_FPU
#define NUM_COPROCESSOR		1
#else
#define NUM_COPROCESSOR		0
#endif


/* ------------------------------------------------------------------------ */
/*
 * Physical timer (for RA6M5)
 */
#define	CPU_HAS_PTMR	0

#endif /* __TK_SYSDEF_DEPEND_CPU_H__ */
