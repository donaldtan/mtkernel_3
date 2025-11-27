/*
 *----------------------------------------------------------------------
 *    micro T-Kernel 3.00.08.B1
 *
 *    Copyright (C) 2025 by Ken Sakamura.
 *    This software is distributed under the T-License 2.2.
 *----------------------------------------------------------------------
 *
 *    Released by TRON Forum(http://www.tron.org) at 2025/11.
 *
 *----------------------------------------------------------------------
 */

/*
 *	syslib.h
 *
 *	micro T-Kernel System Library  (RA6M5 depended)
 */

#ifndef __TK_SYSLIB_CPU_DEPEND_H__
#define __TK_SYSLIB_CPU_DEPEND_H__

#include "../core/armv8m/syslib.h"

/* ------------------------------------------------------------------------ */
/*
 * Interrupt Control
 */

/*
 * Interrupt mode ( Use SetIntMode )
 */
#define IM_EDGE		0x0000		/* Edge trigger */
#define IM_HI		0x0002		/* Interrupt at rising edge */
#define IM_LOW		0x0001		/* Interrupt at falling edge */
#define IM_BOTH		0x0003		/* Interrupt at both edge */

#endif /* __TK_SYSLIB_CPU_DEPEND_H__ */
