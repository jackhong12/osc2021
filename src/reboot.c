#include "reboot.h"
#include "register.h"
void reset (int tick) { // reboot after watchdog timer expire
    *regp(PM_RSTC) = PM_PASSWORD | 0x20; // full reset
    *regp(PM_WDOG) = PM_PASSWORD | tick; // number of watchdog tick
}

void cancel_reset () {
    *regp(PM_RSTC) = PM_PASSWORD; // full reset
    *regp(PM_WDOG) = PM_PASSWORD; // number of watchdog tick
}