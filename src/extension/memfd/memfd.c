#include <asm/types.h>
#include <stdint.h>
#include <string.h>
#include <linux/memfd.h>
#include <fcntl.h>

#include "extension/extension.h"
#include "tracee/tracee.h"
#include "tracee/mem.h"
#include "syscall/syscall.h"
#include "path/path.h"

#include "compat/fnmatch.h"

#include "extension/memfd/config.h"

// TODO: open_by_handle_at() support

static int match_location(const char *const pattern, const char *const path) {
	return fnmatch(pattern, path, FNM_PATHNAME | FNM_EXTMATCH);
}

static int substitute(Extension *const extension,
		const int path_arg, const int flags_arg, const int fd_arg) {
	Tracee *const tracee = TRACEE(extension);
	const int flags = (flags_arg >= 0) ?
		peek_reg(tracee, CURRENT, flags_arg) : O_CREAT;
	if ((flags & O_CREAT) == 0)
		return 0;
	Config *const config = talloc_get_type_abort(extension->config, Config);
	char path[PATH_MAX];
	const int path_len = get_sysarg_path(tracee, path, path_arg);
	if (path_len < 0)
		return path_len;
	const int fd = (fd_arg >=0 ) ?
		peek_reg(tracee, CURRENT, fd_arg) : AT_FDCWD;
	char *full_path;
	int r;
	if (path[0] != '/') {
		char base_path[PATH_MAX];
		if (fd == AT_FDCWD) {
			r = getcwd2(tracee, base_path);
			if (r < 0) return r;
		} else {
			r = readlink_proc_pid_fd(tracee->pid, fd, base_path);
			if (r < 0) return r;
			r = detranslate_path(tracee, base_path, NULL);
			if (r < 0) return r;
		}
		r = join_paths(2, base_path, base_path, path);
		if (r < 0) return r;
		full_path = base_path;
	} else {
		r = detranslate_path(tracee, path, NULL);
		if (r < 0) return r;
		full_path = path;
	}
	if (match_location(config->location_pattern, full_path) == 0) {
		const int flags_n = (flags & O_CLOEXEC) ? MFD_CLOEXEC : 0;
		set_sysnum(tracee, PR_memfd_create);
		poke_reg(tracee, SYSARG_2, flags_n);
		if (path_arg != SYSARG_1)
			set_sysarg_path(tracee, path, SYSARG_1);
		return 1;
	}
	return 0;
}

int memfd_callback(Extension *const extension, const ExtensionEvent event,
		const intptr_t data1, const intptr_t data2 UNUSED) {
	switch (event) {
	case INITIALIZATION: {
		static const FilteredSysnum filtered_sysnums[] = {
			{ PR_creat, 0 },
			{ PR_open, 0 },
			{ PR_openat, 0 },
			FILTERED_SYSNUM_END
		};
		extension->config = talloc(extension, Config);
		Config *const config = talloc_get_type_abort(extension->config, Config);
		config->location_pattern = talloc_strdup(extension, (const char *const) data1);
		extension->filtered_sysnums = filtered_sysnums;
		return 0;
	}
	case SYSCALL_ENTER_END: {
		Tracee *const tracee = TRACEE(extension);
		const word_t sysnum = get_sysnum(tracee, CURRENT);
		switch (sysnum) {
		case PR_creat:
			return substitute(extension, SYSARG_1, -1, -1);
		case PR_open:
			return substitute(extension, SYSARG_1, SYSARG_2, -1);
		case PR_openat:
			return substitute(extension, SYSARG_2, SYSARG_3, SYSARG_1);
		default:
			return 0;
		}
	}
	default:
		return 0;
	}
}
