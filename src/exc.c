#include "exc.h"
#include "io.h"
#include "utility.h"

int sys_call_handler (int sys_num) {
    switch (sys_num) {
        /* show specific register */
        case 400:
            kprintf("spsr_el1: %x\n", get_spsr_el1());
            kprintf("elr_el1: %x\n", get_elr_el1());
            kprintf("esr_el1: %x\n\n", get_esr_el1());
            break;
        /* exit */
        case 60:
            return 60;
        /* read */
        case 0:
        /* write */
        case 1:
        /* open */
        case 2:
        default:
            kprintf("Unsupported syscall: %d\n", sys_num);
    }
    return 1;
}

int aarch64_sync_handler (u32 sys_num, u32 *instruction) {
    u32 svc_num = (instruction[-1] & 0xfffff) >> 5;
    if (svc_num != 0x80)
        return 0;
    return sys_call_handler(sys_num);
}


void print_exc_error (int error) {
    switch (error) {
        case 0:
            kprintf("Unsupport exception: SP_EL0 sync\n");
            break;
        case 1:
            kprintf("Unsupport exception: SP_EL0 IRQ\n");
            break;
        case 2:
            kprintf("Unsupport exception: SP_EL0 FIQ\n");
            break;
        case 3:
            kprintf("Unsupport exception: SP_EL0 SError");
            break;
        case 4:
            kprintf("Unsupport exception: SP_ELx sync\n");
            break;
        case 5:
            kprintf("Unsupport exception: SP_ELx IRQ\n");
            break;
        case 6:
            kprintf("Unsupport exception: SP_ELx FIQ\n");
            break;
        case 7:
            kprintf("Unsupport exception: SP_ELx SError\n");
            break;
        case 8:
            kprintf("Unsupport exception: AArch64 sync\n");
            break;
        case 9:
            kprintf("Unsupport exception: AARch64 IRQ\n");
            break;
        case 10:
            kprintf("Unsupport exception: AARch64 FIQ\n");
            break;
        case 11:
            kprintf("Unsupport exception: AArch64 SError\n");
            break;
        case 12:
            kprintf("Unsupport exception: AArch32 sync\n");
            break;
        case 13:
            kprintf("Unsupport exception: AArch32 IRQ\n");
            break;
        case 14:
            kprintf("Unsupport exception: AArch32 FIQ\n");
            break;
        case 15:
            kprintf("Unsupport exception: AArch32 SError\n");
            break;
        default:
            kprintf("Unkown exception: %d\n", error);
    }
}