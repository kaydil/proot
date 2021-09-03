#include <assert.h>      /* assert(3), */
#include <stdint.h>      /* intptr_t, */
#include <errno.h>       /* E*, */

#include "extension/extension.h"
#include "syscall/syscall.h"
#include "syscall/sysnum.h"
#include "syscall/seccomp.h"
#include "syscall/chain.h"
#include "execve/execve.h"
#include "tracee/tracee.h"
#include "tracee/abi.h"
#include "tracee/mem.h"
#include "execve/auxv.h"
#include "path/binding.h"
#include "path/f2fs-bug.h"
#include "arch.h"

int mute_setxid_callback(Extension *extension, ExtensionEvent event, intptr_t data1, intptr_t data2) {
	switch (event) {
		case INITIALIZATION: {
			static const FilteredSysnum filtered_sysnums[] = {
				{ PR_setuid,		FILTER_SYSEXIT },
				{ PR_setuid32,		FILTER_SYSEXIT },
				{ PR_setgid,		FILTER_SYSEXIT },
				{ PR_setgid32,		FILTER_SYSEXIT },
				{ PR_setreuid,		FILTER_SYSEXIT },
				{ PR_setreuid32,	FILTER_SYSEXIT },
				{ PR_setregid,		FILTER_SYSEXIT },
				{ PR_setregid32,	FILTER_SYSEXIT },
				{ PR_setresuid,		FILTER_SYSEXIT },
				{ PR_setresuid32,	FILTER_SYSEXIT },
				{ PR_setresgid,		FILTER_SYSEXIT },
				{ PR_setresgid32,	FILTER_SYSEXIT },
				FILTERED_SYSNUM_END
			};
			extension->filtered_sysnums = filtered_sysnums;
			return 0;
		}
		case SIGSYS_OCC: {
			Tracee *const tracee = TRACEE(extension);
			const word_t sysnum = get_sysnum(tracee, CURRENT);
			switch (sysnum) {
				case PR_setuid:
				case PR_setuid32:
				case PR_setgid:
				case PR_setgid32:
				case PR_setreuid:
				case PR_setreuid32:
				case PR_setregid:
				case PR_setregid32:
				case PR_setresuid:
				case PR_setresuid32:
				case PR_setresgid:
				case PR_setresgid32:
					poke_reg(tracee, SYSARG_RESULT, 0);
					return 1;
			}
			return 0;
		}
	}
	return 0;
}
