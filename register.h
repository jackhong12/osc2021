#ifndef REGISTER_H
#define REGISTER_H

#define AUX_IRQ_REG 0x3F215000
#define AUX_ENABLES_REG 0x3F215004
#define AUX_MU_IO_REG   0x3F215040
#define AUX_MU_IER_REG  0x3F215044
#define AUX_MU_IIR_REG  0x3F215048
#define AUX_MU_LCR_REG  0x3F21504C
#define AUX_MU_MCR_REG  0x3F215050
#define AUX_MU_LSR_REG  0x3F215054
#define AUX_MU_MSR_REG  0x3F215058
#define AUX_MU_SCRATCH  0x3F21505C
#define AUX_MU_CNTL_REG 0x3F215060
#define AUX_MU_STAT_REG 0x3F215064
#define AUX_MU_BAUD_REG 0x3F215068
#define AUX_SPI0_CNTL0_REG  0x3F215080
#define AUX_SPI0_CNTL1_REG  0x3F215084
#define AUX_SPI0_STAT_REG   0x3F215088
#define AUX_SPI0_IO_REG 0x3F215090
#define AUX_SPI0_PEEK_REG   0x3F215094
#define AUX_SPI1_CNTL0_REG  0x3F2150C0
#define AUX_SPI1_CNTL1_REG  0x3F2150C4
#define AUX_SPI1_STAT_REG   0x3F2150C8
#define AUX_SPI1_IO_REG 0x3F2150D0
#define AUX_SPI1_PEEK_REG   0x3F2150D4
#define aux(NAME) ((volatile unsigned int *)(AUX_ ## NAME ## _REG))

#define PM_PASSWORD 0x5a000000

#define GPFSEL0_REG 0x3F200000
#define GPFSEL1_REG 0x3F200004
#define GPFSEL2_REG 0x3F200008
#define GPFSEL3_REG 0x3F20000C
#define GPFSEL4_REG 0x3F200010
#define GPFSEL5_REG 0x3F200014
#define GPPUD_REG 0x3F200094
#define GPPUDCLK0_REG 0x3F200098
#define PM_RSTC_REG 0x3F10001c
#define PM_WDOG_REG 0x3F100024
#define regp(NAME) ((volatile unsigned int *)(NAME ## _REG))

#endif
