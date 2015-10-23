/*
 * linux/arch/arm/mach-at91/generic.h
 *
 *  Copyright (C) 2005 David Brownell
 *
 * This program is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License version 2 as
 * published by the Free Software Foundation.
 */

#ifndef _AT91_GENERIC_H
#define _AT91_GENERIC_H

#include <linux/of.h>
#include <linux/reboot.h>

 /* Map io */
extern void __init at91_map_io(void);
extern void __init at91_alt_map_io(void);
extern void __init at91_sama5d2_map_io(void);

 /* Processors */
extern void __init at91rm9200_set_type(int type);
extern void __init at91rm9200_dt_initialize(void);
extern void __init at91_dt_initialize(void);

 /* Interrupts */
extern void __init at91_sysirq_mask_rtc(u32 rtc_base);
extern void __init at91_sysirq_mask_rtt(u32 rtt_base);

 /* Timer */
extern void at91rm9200_timer_init(void);

/* idle */
extern void at91sam9_idle(void);

/* Matrix */
extern void at91_ioremap_matrix(u32 base_addr);


#ifdef CONFIG_PM
extern void __init at91rm9200_pm_init(void);
extern void __init at91sam9260_pm_init(void);
extern void __init at91sam9g45_pm_init(void);
extern void __init at91sam9x5_pm_init(void);
extern void __init sam5d2_pm_init(void);
extern void __init sam5d3_pm_init(void);
extern void __init sam5d4_pm_init(void);
#else
static void __maybe_unused __init at91rm9200_pm_init(void) { }
static void __maybe_unused __init at91sam9260_pm_init(void) { }
static void __maybe_unused __init at91sam9g45_pm_init(void) { }
static void __maybe_unused __init at91sam9x5_pm_init(void) { }
static void __maybe_unused __init sam5d2_pm_init(void) {}
static void __maybe_unused __init sam5d3_pm_init(void) {}
static void __maybe_unused __init sam5d4_pm_init(void) {}
#endif

#endif /* _AT91_GENERIC_H */
