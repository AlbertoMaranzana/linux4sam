/*
 *  Setup code for SAMA5 Evaluation Kits with Device Tree support
 *
 *  Copyright (C) 2013 Atmel,
 *                2013 Ludovic Desroches <ludovic.desroches@atmel.com>
 *
 * Licensed under GPLv2 or later.
 */

#include <linux/types.h>
#include <linux/init.h>
#include <linux/module.h>
#include <linux/gpio.h>
#include <linux/micrel_phy.h>
#include <linux/of.h>
#include <linux/of_irq.h>
#include <linux/of_platform.h>
#include <linux/phy.h>
#include <linux/clk-provider.h>
#include <linux/phy.h>

#include <asm/setup.h>
#include <asm/irq.h>
#include <asm/mach/arch.h>
#include <asm/mach/map.h>
#include <asm/mach/irq.h>

#include "generic.h"

static int ksz8081_phy_fixup(struct phy_device *phy)
{
	int value;

	value = phy_read(phy, 0x16);
	value &= ~0x20;
	phy_write(phy, 0x16, value);

	return 0;
}

static void __init sama5d2_dt_device_init(void)
{
	of_platform_populate(NULL, of_default_bus_match_table, NULL, NULL);
	sam5d2_pm_init();
}

static const char *sama5_alt2_dt_board_compat[] __initconst = {
	"atmel,sama5d2",
	NULL
};

DT_MACHINE_START(sama5_sama5d2_dt, "Atmel SAMA5")
	/* Maintainer: Atmel */
	.map_io		= at91_sama5d2_map_io,
	.init_early	= at91_dt_initialize,
	.init_machine	= sama5d2_dt_device_init,
	.dt_compat	= sama5_alt2_dt_board_compat,
	.l2c_aux_mask	= ~0UL,
MACHINE_END

static void __init sama5_dt_device_init(void)
{
	if (of_machine_is_compatible("atmel,sama5d4ek") &&
	   IS_ENABLED(CONFIG_PHYLIB)) {
		phy_register_fixup_for_id("fc028000.etherne:00",
						ksz8081_phy_fixup);
	}

	if (of_machine_is_compatible("atmel,sama5d3xmb") &&
	   IS_ENABLED(CONFIG_PHYLIB)) {
		phy_register_fixup_for_uid(PHY_ID_KSZ8051, MICREL_PHY_ID_MASK,
						ksz8081_phy_fixup);
	}

	of_platform_populate(NULL, of_default_bus_match_table, NULL, NULL);
	sam5d3_pm_init();
}

static const char *sama5_dt_board_compat[] __initconst = {
	"atmel,sama5",
	NULL
};

DT_MACHINE_START(sama5_dt, "Atmel SAMA5")
	/* Maintainer: Atmel */
	.map_io		= at91_map_io,
	.init_early	= at91_dt_initialize,
	.init_machine	= sama5_dt_device_init,
	.dt_compat	= sama5_dt_board_compat,
MACHINE_END

static void __init sama5d4_dt_device_init(void)
{
	of_platform_populate(NULL, of_default_bus_match_table, NULL, NULL);
	sam5d4_pm_init();
}

static const char *sama5_alt_dt_board_compat[] __initconst = {
	"atmel,sama5d4",
	NULL
};

DT_MACHINE_START(sama5_alt_dt, "Atmel SAMA5")
	/* Maintainer: Atmel */
	.map_io		= at91_alt_map_io,
	.init_early	= at91_dt_initialize,
	.init_machine	= sama5d4_dt_device_init,
	.dt_compat	= sama5_alt_dt_board_compat,
	.l2c_aux_mask	= ~0UL,
MACHINE_END
