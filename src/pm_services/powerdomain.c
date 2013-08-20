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

#include <device_am335x.h>
#include <low_power.h>
#include <prcm.h>
#include <prmam335x.h>
#include <prm43xx.h>
#include <system_am335.h>
#include <powerdomain.h>

/* PRM_MPU bits */
static const struct pd_mpu_bits am335x_mpu_bits = {
	.ram_retst_mask		= AM335X_MPU_RAM_RETSTATE_MASK,
	.ram_retst_shift	= AM335X_MPU_RAM_RETSTATE_SHIFT,
	.l2_retst_mask		= AM335X_MPU_L2_RETSTATE_MASK,
	.l2_retst_shift		= AM335X_MPU_L2_RETSTATE_SHIFT,
	.l1_retst_mask		= AM335X_MPU_L1_RETSTATE_MASK,
	.l1_retst_shift		= AM335X_MPU_L1_RETSTATE_SHIFT,
	.lpstchg_mask		= AM335X_MPU_LOWPOWERSTATECHANGE_MASK,
	.lpstchg_shift		= AM335X_MPU_LOWPOWERSTATECHANGE_SHIFT,
	.logicretst_mask	= AM335X_MPU_LOGICRETSTATE_MASK,
	.logicretst_shift	= AM335X_MPU_LOGICRETSTATE_SHIFT,
	.pwrst_mask		= AM335X_MPU_POWERSTATE_MASK,
	.pwrst_shift		= AM335X_MPU_POWERSTATE_SHIFT,
};

/* PRM_MPU bits */
static const struct pd_mpu_bits am43xx_mpu_bits = {
	.ram_retst_mask		= AM43XX_MPU_RAM_RETSTATE_MASK,
	.ram_retst_shift	= AM43XX_MPU_RAM_RETSTATE_SHIFT,
	.l2_retst_mask		= AM43XX_MPU_L2_RETSTATE_MASK,
	.l2_retst_shift		= AM43XX_MPU_L2_RETSTATE_SHIFT,
	.l1_retst_mask		= AM43XX_MPU_L1_RETSTATE_MASK,
	.l1_retst_shift		= AM43XX_MPU_L1_RETSTATE_SHIFT,
	.lpstchg_mask		= AM43XX_MPU_LOWPOWERSTATECHANGE_MASK,
	.lpstchg_shift		= AM43XX_MPU_LOWPOWERSTATECHANGE_SHIFT,
	.logicretst_mask	= AM43XX_MPU_LOGICRETSTATE_MASK,
	.logicretst_shift	= AM43XX_MPU_LOGICRETSTATE_SHIFT,
	.pwrst_mask		= AM43XX_MPU_POWERSTATE_MASK,
	.pwrst_shift		= AM43XX_MPU_POWERSTATE_SHIFT,
};

/* PRM_PER bits */
static const struct pd_per_bits am335x_per_bits = {
	.per_retst_mask		= AM335X_PER_MEM_RETSTATE_MASK,
	.per_retst_shift	= AM335X_PER_MEM_RETSTATE_SHIFT,
	.ram1_retst_mask	= AM335X_PER_RAM_MEM_RETSTATE_MASK,
	.ram1_retst_shift	= AM335X_PER_RAM_MEM_RETSTATE_SHIFT,
	.icss_retst_mask	= AM335X_PER_ICSS_MEM_RETSTATE_MASK,
	.icss_retst_shift	= AM335X_PER_ICSS_MEM_RETSTATE_SHIFT,
	.lpstchg_mask		= AM335X_PER_LOWPOWERSTATECHANGE_MASK,
	.lpstchg_shift		= AM335X_PER_LOWPOWERSTATECHANGE_SHIFT,
	.logicretst_mask	= AM335X_PER_LOGICRETSTATE_MASK,
	.logicretst_shift	= AM335X_PER_LOGICRETSTATE_SHIFT,
	.pwrst_mask		= AM335X_PER_POWERSTATE_MASK,
	.pwrst_shift		= AM335X_PER_POWERSTATE_SHIFT,
};

/* PRM_PER bits */
static const struct pd_per_bits am43xx_per_bits = {
	.per_retst_mask		= AM43XX_PER_MEM_RETSTATE_MASK,
	.per_retst_shift	= AM43XX_PER_MEM_RETSTATE_SHIFT,
	.ram1_retst_mask	= AM43XX_PER_RAM1_MEM_RETSTATE_MASK,
	.ram1_retst_shift	= AM43XX_PER_RAM1_MEM_RETSTATE_SHIFT,
	.ram2_retst_mask	= AM43XX_PER_RAM2_MEM_RETSTATE_MASK,
	.ram2_retst_shift	= AM43XX_PER_RAM2_MEM_RETSTATE_SHIFT,
	.icss_retst_mask	= AM43XX_PER_ICSS_MEM_RETSTATE_MASK,
	.icss_retst_shift	= AM43XX_PER_ICSS_MEM_RETSTATE_SHIFT,
	.lpstchg_mask		= AM43XX_PER_LOWPOWERSTATECHANGE_MASK,
	.lpstchg_shift		= AM43XX_PER_LOWPOWERSTATECHANGE_SHIFT,
	.logicretst_mask	= AM43XX_PER_LOGICRETSTATE_MASK,
	.logicretst_shift	= AM43XX_PER_LOGICRETSTATE_SHIFT,
	.pwrst_mask		= AM43XX_PER_POWERSTATE_MASK,
	.pwrst_shift		= AM43XX_PER_POWERSTATE_SHIFT,
};

struct powerdomain_regs {
	unsigned int stctrl;
	unsigned int pwrstst;
};

struct powerdomain_state {
	unsigned int stctrl_next_val;
	unsigned int stctrl_prev_val;
	unsigned int pwrstst_prev_val;
};

static const struct powerdomain_regs am335x_pd_regs[] = {
	[PD_MPU] = {
		.stctrl		= AM335X_PM_MPU_PWRSTCTRL,
		.pwrstst	= AM335X_PM_MPU_PWRSTST,
	},
	[PD_PER] = {
		.stctrl		= AM335X_PM_PER_PWRSTCTRL,
		.pwrstst	= AM335X_PM_PER_PWRSTST,
	},
};

static const struct powerdomain_regs am43xx_pd_regs[] = {
	[PD_MPU] = {
		.stctrl		= AM43XX_PM_MPU_PWRSTCTRL,
		.pwrstst	= AM43XX_PM_MPU_PWRSTST,
	},
	[PD_PER] = {
		.stctrl		= AM43XX_PM_PER_PWRSTCTRL,
		.pwrstst	= AM43XX_PM_PER_PWRSTST,
	},
};

static const struct pd_mpu_bits *mpu_bits;
static const struct pd_per_bits *per_bits;
static const struct powerdomain_regs *pd_regs;

static struct powerdomain_state pd_states[] = {
	[PD_MPU] = {},
	[PD_PER] = {},
};


/* Clear out the global variables here */
void powerdomain_reset(void)
{
	pd_states[PD_MPU].stctrl_next_val = 0;
	pd_states[PD_MPU].stctrl_prev_val = 0;
	pd_states[PD_MPU].pwrstst_prev_val = 0;
	pd_states[PD_PER].stctrl_next_val = 0;
	pd_states[PD_PER].stctrl_prev_val = 0;
	pd_states[PD_PER].pwrstst_prev_val = 0;
}

void powerdomain_init(void)
{
	if (soc_id == AM335X_SOC_ID) {
		mpu_bits = &am335x_mpu_bits;
		per_bits = &am335x_per_bits;
		pd_regs = am335x_pd_regs;
	} else if (soc_id == AM43XX_SOC_ID) {
		mpu_bits = &am43xx_mpu_bits;
		per_bits = &am43xx_per_bits;
		pd_regs = am43xx_pd_regs;
	}
}

unsigned int pd_state_change(unsigned int val, int pd)
{
	pd_states[pd].stctrl_next_val = val;
	pd_states[pd].stctrl_prev_val = __raw_readl(pd_regs[pd].stctrl);
	pd_states[pd].pwrstst_prev_val = __raw_readl(pd_regs[pd].pwrstst);
	__raw_writel(val, pd_regs[pd].stctrl);

	return 0;
}

static unsigned int mpu_ram_ret_state_change(unsigned int val, unsigned int v)
{
	return var_mod(v, mpu_bits->ram_retst_mask,
					val << mpu_bits->ram_retst_shift);
}

static unsigned int mpu_l1_ret_state_change(unsigned int val, unsigned int v)
{
	return var_mod(v, mpu_bits->l1_retst_mask,
					val << mpu_bits->l1_retst_shift);
}

static unsigned int mpu_l2_ret_state_change(unsigned int val, unsigned int v)
{
	return var_mod(v, mpu_bits->l2_retst_mask,
					val << mpu_bits->l2_retst_shift);
}

static unsigned int icss_mem_ret_state_change(unsigned int val, unsigned int v)
{
	return var_mod(v, per_bits->icss_retst_mask,
					val << per_bits->icss_retst_shift);
}

static unsigned int per_mem_ret_state_change(unsigned int val, unsigned int v)
{
	return var_mod(v, per_bits->per_retst_mask,
					val << per_bits->per_retst_shift);
}

static unsigned int ocmc_mem_ret_state_change(unsigned int val, unsigned int v)
{
	v = var_mod(v, per_bits->ram1_retst_mask,
					val << per_bits->ram1_retst_shift);

	if (per_bits->ram2_retst_mask)
		v = var_mod(v, per_bits->ram2_retst_mask,
					val << per_bits->ram2_retst_shift);

	return v;
}

static unsigned int per_powerst_change(unsigned int val, unsigned int v)
{
	return var_mod(v, per_bits->pwrst_mask,
					val << per_bits->pwrst_shift);
}

static unsigned int mpu_powerst_change(unsigned int val, unsigned int v)
{
	return var_mod(v, mpu_bits->pwrst_mask,
					val << mpu_bits->pwrst_shift);
}

unsigned int get_pd_per_stctrl_val(struct deep_sleep_data *data)
{
	unsigned int v = 0;

	v = per_powerst_change(data->pd_per_state, v);
	v = icss_mem_ret_state_change(data->pd_per_icss_mem_ret_state, v);
	v = per_mem_ret_state_change(data->pd_per_mem_ret_state, v);
	v = ocmc_mem_ret_state_change(data->pd_per_ocmc_ret_state, v);

	return v;
}

unsigned int get_pd_mpu_stctrl_val(struct deep_sleep_data *data)
{
	unsigned int v = 0;

	v = mpu_powerst_change(data->pd_mpu_state, v);
	v = mpu_ram_ret_state_change(data->pd_mpu_ram_ret_state, v);
	v = mpu_l1_ret_state_change(data->pd_mpu_l1_ret_state, v);
	v = mpu_l2_ret_state_change(data->pd_mpu_l2_ret_state, v);

	return v;
}

void pd_state_restore(int pd)
{
	__raw_writel(pd_states[pd].stctrl_prev_val, pd_regs[pd].stctrl);
}

/* Checking only the stst bits for now */
static int verify_pd_transition(int pd)
{
	unsigned int ctrl;
	unsigned int stst;

	ctrl = __raw_readl(pd_regs[pd].stctrl);
	stst = __raw_readl(pd_regs[pd].pwrstst);

	if ((ctrl & 0x3) == (stst & 0x3))
		return CMD_STAT_PASS;
	else
		return CMD_STAT_FAIL;
}

int verify_pd_transitions(void)
{
	int result;

	result = verify_pd_transition(PD_MPU);
	if (result == CMD_STAT_FAIL);
		return result;

	return verify_pd_transition(PD_PER);
}

