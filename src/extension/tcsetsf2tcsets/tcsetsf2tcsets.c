#include <asm/types.h>
#include <stdint.h>
#include <string.h>
#include <termios.h>

#include "extension/extension.h"
#include "tracee/tracee.h"
#include "tracee/mem.h"

int tcsetsf2tcsets(Extension *const extension, const ExtensionEvent event, const intptr_t data1 UNUSED, const intptr_t data2 UNUSED) {
    switch (event) {
    case INITIALIZATION: {
        static const FilteredSysnum filtered_sysnums[] = {
            { PR_ioctl, FILTER_SYSEXIT },
            FILTERED_SYSNUM_END
        };
        extension->filtered_sysnums = filtered_sysnums;
        return 0;
    }
    case SYSCALL_ENTER_END: {
        Tracee *const tracee = TRACEE(extension);
        const word_t sysnum = get_sysnum(tracee, CURRENT);
        switch (sysnum) {
        case PR_ioctl: {
            const word_t cmd = peek_reg(tracee, CURRENT, SYSARG_2);
            if (cmd == TCSETSF) poke_reg(tracee, SYSARG_2, TCSETS); /* As Termux does it... */
            return 0;
        }
        default:
            return 0;
        }
    }
    default:
        return 0;
    }
}
