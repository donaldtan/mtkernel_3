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
 *	profile.h
 *
 *	Service Profile (EK-RA6M5)
 */

#ifndef __SYS_DEPEND_PROFILE_H__
#define __SYS_DEPEND_PROFILE_H__

/*
 **** CPU Core depended profile (ARMv8M)
 */
#include "../cpu/core/armv8m/profile.h"

/*
 **** Target-depeneded profile (EK-RA6M5)
 */

/*
 * Power management
 */
#define TK_SUPPORT_LOWPOWER	FALSE		/* Support of power management */

#endif /* __SYS_DEPEND_PROFILE_H__ */
