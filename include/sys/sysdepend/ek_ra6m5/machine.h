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
 *	machine.h
 *
 *	Machine type definition (EK-RA6M5 depended)
 */

#ifndef __SYS_SYSDEPEND_MACHINE_H__
#define __SYS_SYSDEPEND_MACHINE_H__

/*
 * [TYPE]_[CPU]		TARGET SYSTEM
 * CPU_xxxx		CPU type
 * CPU_CORE_xxx		CPU core type
 */

/* ----- EK-RA6M5 (CPU: STM32N657X0) definition ----- */
#define EK_RA6M5		1	/* Target Board    : EK-RA6M5 */

#define CPU_RA6			1	/* Target CPU type : RA6 series */
#define CPU_RA6M5		1	/* Target CPU      : RA6M5 */

#define CPU_CORE_ARMV8M		1	/* Target CPU-Core type : ARMv8-M */
#define CPU_CORE_ACM33		1	/* Target CPU-Core      : ARM Cortex-M33 */

#define TARGET_DIR		ek_ra6m5	/* Sysdepend-Directory name */
#define	TARGET_CPU_DIR		ra6m5		/* Sysdepend-CPU-Directory name */

#define KNL_SYSDEP_PATH		sysdepend/kernel/ek_ra6m5	/* Kernel sysdepend path */

/* ----- Extension definition ----*/
#define EXT_SEC		1	/* Secure Extension for Arm (TrustZone) */

/*
 **** CPU Core depended profile (ARMv8M)
 */
#include "../cpu/core/armv8m/machine.h"

#endif /* __SYS_SYSDEPEND_MACHINE_H__ */
