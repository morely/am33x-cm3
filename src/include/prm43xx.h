/*
 * AM43xx PRM instance offset macros
 *
 */

#ifndef __PRM43XX_H
#define __PRM43XX_H

#define AM43XX_PRM_BASE		0x44df0000

#define AM43XX_PRM_REGADDR(inst, reg)				\
	(AM43XX_PRM_BASE + (inst) + (reg))


/* PRM instances */
#define AM43XX_PRM_OCP_SOCKET_INST	0x0000
#define AM43XX_PRM_MPU_INST		0x0300
#define AM43XX_PRM_GFX_INST		0x0400
#define AM43XX_PRM_RTC_INST		0x0500
#define AM43XX_PRM_TAMPER_INST		0x0600
#define AM43XX_PRM_CEFUSE_INST		0x0700
#define AM43XX_PRM_PER_INST		0x0800
#define AM43XX_PRM_WKUP_INST		0x2000
#define AM43XX_PRM_DEVICE_INST		0x4000

/* PRCM clockdomain register offsets (from instance start) */

/* PRM */

/* PRM.OCP_SOCKET_PRM register offsets */
#define AM43XX_REVISION_PRM_OFFSET			0x0000
#define AM43XX_PRM_IRQSTATUS_MPU_OFFSET			0x0004
#define AM43XX_PRM_IRQENABLE_MPU_OFFSET			0x0008
#define AM43XX_PRM_IRQSTATUS_M3_OFFSET			0x000c
#define AM43XX_PRM_IRQENABLE_M3_OFFSET			0x0010

/* PRM.PRM_MPU register offsets */
#define AM43XX_PM_MPU_PWRSTCTRL_OFFSET			0x0000
#define AM43XX_PM_MPU_PWRSTCTRL				AM43XX_PRM_REGADDR(AM43XX_PRM_MPU_INST, 0x0000)
#define AM43XX_PM_MPU_PWRSTST_OFFSET			0x0004
#define AM43XX_PM_MPU_PWRSTST				AM43XX_PRM_REGADDR(AM43XX_PRM_MPU_INST, 0x0004)
#define AM43XX_RM_MPU_RSTST_OFFSET			0x0014
#define AM43XX_RM_MPU_MPU_CONTEXT_OFFSET		0x0024

/* PRM.PRM_GFX register offsets */
#define AM43XX_PM_GFX_PWRSTCTRL_OFFSET			0x0000
#define AM43XX_PM_GFX_PWRSTST_OFFSET			0x0004
#define AM43XX_RM_GFX_RSTCTRL_OFFSET			0x0010
#define AM43XX_RM_GFX_RSTST_OFFSET			0x0014
#define AM43XX_RM_GFX_GFX_CONTEXT_OFFSET		0x0024

/* PRM.PRM_RTC register offsets */

/* PRM.PRM_TAMPER register offsets */
#define AM43XX_RM_TAMPER_TPMSS_CONTEXT_OFFSET		0x0000

/* PRM.PRM_CEFUSE register offsets */
#define AM43XX_PM_CEFUSE_PWRSTCTRL_OFFSET		0x0000
#define AM43XX_PM_CEFUSE_PWRSTST_OFFSET			0x0004
#define AM43XX_RM_CEFUSE_CEFUSE_CONTEXT_OFFSET		0x0024

/* PRM.PRM_PER register offsets */
#define AM43XX_PM_PER_PWRSTCTRL_OFFSET			0x0000
#define AM43XX_PM_PER_PWRSTCTRL				AM43XX_PRM_REGADDR(AM43XX_PRM_PER_INST, 0x0000)
#define AM43XX_PM_PER_PWRSTST_OFFSET			0x0004
#define AM43XX_PM_PER_PWRSTST				AM43XX_PRM_REGADDR(AM43XX_PRM_PER_INST, 0x0004)
#define AM43XX_RM_PER_RSTCTRL_OFFSET			0x0010
#define AM43XX_RM_PER_RSTST_OFFSET			0x0014
#define AM43XX_RM_PER_L3_CONTEXT_OFFSET			0x0024
#define AM43XX_RM_PER_AES0_CONTEXT_OFFSET		0x002c
#define AM43XX_RM_PER_DES_CONTEXT_OFFSET		0x0034
#define AM43XX_RM_PER_CRYPTODMA_CONTEXT_OFFSET		0x003c
#define AM43XX_RM_PER_L3_INSTR_CONTEXT_OFFSET		0x0044
#define AM43XX_RM_PER_MSTR_EXPS_CONTEXT_OFFSET		0x004c
#define AM43XX_RM_PER_OCMCRAM_CONTEXT_OFFSET		0x0054
#define AM43XX_RM_PER_SHA0_CONTEXT_OFFSET		0x005c
#define AM43XX_RM_PER_SLV_EXPS_CONTEXT_OFFSET		0x0064
#define AM43XX_RM_PER_VPFE0_CONTEXT_OFFSET		0x006c
#define AM43XX_RM_PER_VPFE1_CONTEXT_OFFSET		0x0074
#define AM43XX_RM_PER_TPCC_CONTEXT_OFFSET		0x007c
#define AM43XX_RM_PER_TPTC0_CONTEXT_OFFSET		0x0084
#define AM43XX_RM_PER_TPTC1_CONTEXT_OFFSET		0x008c
#define AM43XX_RM_PER_TPTC2_CONTEXT_OFFSET		0x0094
#define AM43XX_RM_PER_DLL_AGING_CONTEXT_OFFSET		0x009c
#define AM43XX_RM_PER_L4HS_CONTEXT_OFFSET		0x00a4
#define AM43XX_RM_PER_L4FW_CONTEXT_OFFSET		0x00ac
#define AM43XX_RM_PER_GPMC_CONTEXT_OFFSET		0x0224
#define AM43XX_RM_PER_IEEE5000_CONTEXT_OFFSET		0x022c
#define AM43XX_RM_PER_MAG_CARD_CONTEXT_OFFSET		0x0234
#define AM43XX_RM_PER_MCASP0_CONTEXT_OFFSET		0x023c
#define AM43XX_RM_PER_MCASP1_CONTEXT_OFFSET		0x0244
#define AM43XX_RM_PER_MMC2_CONTEXT_OFFSET		0x024c
#define AM43XX_RM_PER_QSPI_CONTEXT_OFFSET		0x025c
#define AM43XX_RM_PER_USB_OTG_SS0_CONTEXT_OFFSET	0x0264
#define AM43XX_RM_PER_USB_OTG_SS1_CONTEXT_OFFSET	0x026c
#define AM43XX_RM_PER_ICSS_CONTEXT_OFFSET		0x0324
#define AM43XX_RM_PER_L4LS_CONTEXT_OFFSET		0x0424
#define AM43XX_RM_PER_DCAN0_CONTEXT_OFFSET		0x042c
#define AM43XX_RM_PER_DCAN1_CONTEXT_OFFSET		0x0434
#define AM43XX_RM_PER_EPWMSS0_CONTEXT_OFFSET		0x043c
#define AM43XX_RM_PER_EPWMSS1_CONTEXT_OFFSET		0x0444
#define AM43XX_RM_PER_EPWMSS2_CONTEXT_OFFSET		0x044c
#define AM43XX_RM_PER_EPWMSS3_CONTEXT_OFFSET		0x0454
#define AM43XX_RM_PER_EPWMSS4_CONTEXT_OFFSET		0x045c
#define AM43XX_RM_PER_EPWMSS5_CONTEXT_OFFSET		0x0464
#define AM43XX_RM_PER_ELM_CONTEXT_OFFSET		0x046c
#define AM43XX_RM_PER_ERMC_CONTEXT_OFFSET		0x0474
#define AM43XX_RM_PER_GPIO1_CONTEXT_OFFSET		0x047c
#define AM43XX_RM_PER_GPIO2_CONTEXT_OFFSET		0x0484
#define AM43XX_RM_PER_GPIO3_CONTEXT_OFFSET		0x048c
#define AM43XX_RM_PER_GPIO4_CONTEXT_OFFSET		0x0494
#define AM43XX_RM_PER_GPIO5_CONTEXT_OFFSET		0x049c
#define AM43XX_RM_PER_HDQ1W_CONTEXT_OFFSET		0x04a4
#define AM43XX_RM_PER_I2C1_CONTEXT_OFFSET		0x04ac
#define AM43XX_RM_PER_I2C2_CONTEXT_OFFSET		0x04b4
#define AM43XX_RM_PER_MAILBOX0_CONTEXT_OFFSET		0x04bc
#define AM43XX_RM_PER_MMC0_CONTEXT_OFFSET		0x04c4
#define AM43XX_RM_PER_MMC1_CONTEXT_OFFSET		0x04cc
#define AM43XX_RM_PER_PKA_CONTEXT_OFFSET		0x04d4
#define AM43XX_RM_PER_RNG_CONTEXT_OFFSET		0x04e4
#define AM43XX_RM_PER_SPARE0_CONTEXT_OFFSET		0x04ec
#define AM43XX_RM_PER_SPARE1_CONTEXT_OFFSET		0x04f4
#define AM43XX_RM_PER_SPI0_CONTEXT_OFFSET		0x0504
#define AM43XX_RM_PER_SPI1_CONTEXT_OFFSET		0x050c
#define AM43XX_RM_PER_SPI2_CONTEXT_OFFSET		0x0514
#define AM43XX_RM_PER_SPI3_CONTEXT_OFFSET		0x051c
#define AM43XX_RM_PER_SPI4_CONTEXT_OFFSET		0x0524
#define AM43XX_RM_PER_SPINLOCK_CONTEXT_OFFSET		0x052c
#define AM43XX_RM_PER_TIMER2_CONTEXT_OFFSET		0x0534
#define AM43XX_RM_PER_TIMER3_CONTEXT_OFFSET		0x053c
#define AM43XX_RM_PER_TIMER4_CONTEXT_OFFSET		0x0544
#define AM43XX_RM_PER_TIMER5_CONTEXT_OFFSET		0x054c
#define AM43XX_RM_PER_TIMER6_CONTEXT_OFFSET		0x0554
#define AM43XX_RM_PER_TIMER7_CONTEXT_OFFSET		0x055c
#define AM43XX_RM_PER_TIMER8_CONTEXT_OFFSET		0x0564
#define AM43XX_RM_PER_TIMER9_CONTEXT_OFFSET		0x056c
#define AM43XX_RM_PER_TIMER10_CONTEXT_OFFSET		0x0574
#define AM43XX_RM_PER_TIMER11_CONTEXT_OFFSET		0x057c
#define AM43XX_RM_PER_UART1_CONTEXT_OFFSET		0x0584
#define AM43XX_RM_PER_UART2_CONTEXT_OFFSET		0x058c
#define AM43XX_RM_PER_UART3_CONTEXT_OFFSET		0x0594
#define AM43XX_RM_PER_UART4_CONTEXT_OFFSET		0x059c
#define AM43XX_RM_PER_UART5_CONTEXT_OFFSET		0x05a4
#define AM43XX_RM_PER_USIM0_CONTEXT_OFFSET		0x05ac
#define AM43XX_RM_PER_USIM1_CONTEXT_OFFSET		0x05b4
#define AM43XX_RM_PER_USBPHYOCP2SCP0_CONTEXT_OFFSET	0x05bc
#define AM43XX_RM_PER_USBPHYOCP2SCP1_CONTEXT_OFFSET	0x05c4
#define AM43XX_RM_PER_EMIF_CONTEXT_OFFSET		0x0724
#define AM43XX_RM_PER_DLL_CONTEXT_OFFSET		0x072c
#define AM43XX_RM_PER_EMIF_FW_CONTEXT_OFFSET		0x0734
#define AM43XX_RM_PER_OTFA_EMIF_CONTEXT_OFFSET		0x073c
#define AM43XX_RM_PER_LCDC_CONTEXT_OFFSET		0x0824
#define AM43XX_RM_PER_DSS_CONTEXT_OFFSET		0x0a24
#define AM43XX_RM_PER_CPGMAC0_CONTEXT_OFFSET		0x0b24
#define AM43XX_RM_PER_OCPWP_CONTEXT_OFFSET		0x0c24

/* PRM.PRM_WKUP register offsets */
#define AM43XX_RM_WKUP_RSTCTRL_OFFSET			0x0000
#define AM43XX_RM_WKUP_RSTST_OFFSET			0x0004
#define AM43XX_RM_WKUP_DEBUGSS_CONTEXT_OFFSET		0x0014
#define AM43XX_RM_WKUP_L4WKUP_CONTEXT_OFFSET		0x0214
#define AM43XX_RM_WKUP_WKUP_M3_CONTEXT_OFFSET		0x021c
#define AM43XX_RM_WKUP_SYNCTIMER_CONTEXT_OFFSET		0x0224
#define AM43XX_RM_WKUP_TIMER0_CONTEXT_OFFSET		0x0314
#define AM43XX_RM_WKUP_TIMER1_CONTEXT_OFFSET		0x031c
#define AM43XX_RM_WKUP_WDT0_CONTEXT_OFFSET		0x0324
#define AM43XX_RM_WKUP_WDT1_CONTEXT_OFFSET		0x032c
#define AM43XX_RM_WKUP_I2C0_CONTEXT_OFFSET		0x0334
#define AM43XX_RM_WKUP_UART0_CONTEXT_OFFSET		0x033c
#define AM43XX_RM_WKUP_SMARTREFLEX0_CONTEXT_OFFSET	0x0344
#define AM43XX_RM_WKUP_SMARTREFLEX1_CONTEXT_OFFSET	0x034c
#define AM43XX_RM_WKUP_GPIO0_CONTEXT_OFFSET		0x035c

/* PRM.PRM_DEVICE register offsets */
#define AM43XX_PRM_RSTCTRL_OFFSET			0x0000
#define AM43XX_PRM_RSTST_OFFSET				0x0004
#define AM43XX_PRM_RSTTIME_OFFSET			0x0008
#define AM43XX_PRM_SRAM_COUNT_OFFSET			0x000c
#define AM43XX_PRM_LDO_SRAM_CORE_SETUP_OFFSET		0x0010
#define AM43XX_PRM_LDO_SRAM_CORE_CTRL_OFFSET		0x0014
#define AM43XX_PRM_LDO_SRAM_CORE_CTRL			AM43XX_PRM_REGADDR(AM43XX_PRM_DEVICE_INST, 0x0014)
#define AM43XX_PRM_LDO_SRAM_MPU_SETUP_OFFSET		0x0018
#define AM43XX_PRM_LDO_SRAM_MPU_CTRL_OFFSET		0x001c
#define AM43XX_PRM_LDO_SRAM_MPU_CTRL			AM43XX_PRM_REGADDR(AM43XX_PRM_DEVICE_INST, 0x001c)
#define AM43XX_PRM_IO_COUNT_OFFSET			0x0020
#define AM43XX_PRM_IO_PMCTRL_OFFSET			0x0024
#define AM43XX_PRM_VC_VAL_BYPASS_OFFSET			0x0028
#define AM43XX_PRM_EMIF_CTRL_OFFSET			0x0030

#endif
