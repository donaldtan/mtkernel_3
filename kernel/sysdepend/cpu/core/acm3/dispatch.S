/*
 *----------------------------------------------------------------------
 *    micro T-Kernel 3.00.01
 *
 *    Copyright (C) 2006-2019 by Ken Sakamura.
 *    This software is distributed under the T-License 2.1.
 *----------------------------------------------------------------------
 *
 *    Released by TRON Forum(http://www.tron.org) at 2020/05/29.
 *
 *----------------------------------------------------------------------
 */
#include <sys/machine.h>
#ifdef CPU_CORE_ACM3
/*
 *	dispatch.S (ARM Cortex-M3)
 *	Dispatcher
 */

#define	_in_asm_source_

#include <sys/machine.h>
#include <tk/errno.h>
#include <sys/sysdef.h>
#include <sys/knldef.h>

#include "offset.h"

	.code 16
	.syntax unified
	.thumb

/* ------------------------------------------------------------------------ */
/*
 * Dispatcher
 *	knl_dispatch_entry:
 *		Normal dispatch processing.
 *
 *	Contexts to save
 *	Save registers except for ssp to a stack. Save 'ssp' to TCB.
 *
 *	   High Address +---------------+
 *			| xpsr		|
 *			| Return Address| Return address (pc)
 *			| lr		|
 *			| R12 (ip)	|
 *			| R0-R3		|
 *			+---------------+ Save by Exception entry process.
 *			+---------------+
 *			| lr		|
 *		ssp ->	| R4 - R11	|
 *	    Low Address +---------------+
 */

	.text
	.align 2
	.thumb
	.thumb_func
	.globl Csym(knl_dispatch_entry)
Csym(knl_dispatch_entry):
	ldr	r0, =Csym(knl_dispatch_disabled)
	ldr	r1, =1
	str	r1, [r0]			// Dispatch disable

	ldr	r0, =Csym(knl_ctxtsk)
	cmp	r0, #0
	bne	l_dispatch00

	ldr	sp, =(Csym(knl_tmp_stack) + TMP_STACK_SIZE)	// Set temporal stack
	b	l_dispatch0

l_dispatch00:
	// Context save
	push	{lr}				// Context save (lr)

	stmfd	sp!, {r4-r11}

	ldr	r4, =Csym(knl_ctxtsk)		// R4 = &ctxtsk
	ldr	r0, =0
	ldr	r8, [r4]
	str	sp, [r8, #TCB_tskctxb + CTXB_ssp]	// Save 'ssp' to TCB
	str	r0, [r4]			// ctxtsk = NULL

l_dispatch0:

	ldr	r5, =Csym(knl_schedtsk)		// R5 = &schedtsk
	ldr	r6, =Csym(knl_lowpow_discnt)	// R6 = &lowpow_discnt

l_dispatch1:
	ldr	r0, =INTPRI_VAL(INTPRI_MAX_EXTINT_PRI)
	msr	basepri, r0

	ldr	r8, [r5]			// R8 = schedtsk
	cmp	r8, #0				// Is there 'schedtsk'?
	bne	l_dispatch2

	/* Because there is no task that should be executed, move to the power-saving mode */
	ldr	ip, [r6]			// Is 'low_pow' disabled?
	cmp	ip, #0
	it	eq
	bleq	Csym(low_pow)		// call low_pow()

	ldr	r0, =0
	msr	basepri, r0

	b	l_dispatch1

l_dispatch2:				// Switch to 'schedtsk'
	str	r8, [r4]			// ctxtsk = schedtsk
	ldr	sp, [r8, #TCB_tskctxb + CTXB_ssp]	// Restore 'ssp' from TCB

	ldr	r0, =Csym(knl_dispatch_disabled)
	ldr	r1, =0
	str	r1, [r0]			// Dispatch enable

	ldmfd	sp!, {r4-r11}

	pop	{lr}				// R14_svc restore

	ldr	r0, =0
	msr	basepri, r0

	bx	lr

#endif /* CPU_CORE_ACM3 */
