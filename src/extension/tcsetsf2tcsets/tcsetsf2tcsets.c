#include <asm/types.h>
#include <stdint.h>
#include <string.h>
#include <termios.h>

#include "extension/extension.h"
#include "tracee/tracee.h"
#include "tracee/mem.h"

int tcsetsf2tcsets_callback(Extension *const extension, const ExtensionEvent event, const intptr_t data1, const intptr_t data2 UNUSED) {
	static int subst_cmd = TCSETS;
	switch (event) {
	case INITIALIZATION: {
		static const FilteredSysnum filtered_sysnums[] = {
			{ PR_ioctl, FILTER_SYSEXIT },
			FILTERED_SYSNUM_END
		};
		subst_cmd = data1 ? TCSETSW : TCSETS;
		extension->filtered_sysnums = filtered_sysnums;
		return 0;
	}
	case SYSCALL_ENTER_END: {
		Tracee *const tracee = TRACEE(extension);
		const word_t sysnum = get_sysnum(tracee, CURRENT);
		switch (sysnum) {
		case PR_ioctl: {
			const word_t cmd = peek_reg(tracee, CURRENT, SYSARG_2);
			if (cmd == TCSETSF) poke_reg(tracee, SYSARG_2, subst_cmd);
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
