/*
 * AM33XX-CM3 firmware
 *
 * Cortex-M3 (CM3) firmware for power management on Texas Instruments' AM33XX series of SoCs
 *
 * Copyright (C) 2011 Texas Instruments Incorporated - http://www.ti.com/
 *
 *  This software is licensed under the  standard terms and conditions in the Texas Instruments  Incorporated
 *  Technology and Software Publicly Available Software License Agreement , a copy of which is included in the
 *  software download.
*/

#include <stdint.h>

#include <cm3.h>
#include <device_am335x.h>
#include <system_am335.h>

void a8_notify(int cmd_stat_value)
{
	msg_cmd_stat_update(cmd_stat_value);
	__asm("sev");
}

/* If only notification is needed, use the a8_notify() API */
void a8_m3_low_power_sync(int cmd_stat_value)
{
	a8_notify(cmd_stat_value);

	/* Enable the PRCM interrupt for MPU gated state */
	nvic_enable_irq(AM335X_IRQ_PRCM_M3_IRQ2);
}

/* Timer based sync scheme - Not required for now */
void timer_sync()
{

}
