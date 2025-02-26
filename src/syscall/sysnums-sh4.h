#include "syscall/sysnum.h"

static const Sysnum sysnums_sh4[] = {
	[ 0 ] = PR_restart_syscall,
	[ 1 ] = PR_exit,
	[ 2 ] = PR_fork,
	[ 3 ] = PR_read,
	[ 4 ] = PR_write,
	[ 5 ] = PR_open,
	[ 6 ] = PR_close,
	[ 7 ] = PR_waitpid,
	[ 8 ] = PR_creat,
	[ 9 ] = PR_link,
	[ 10 ] = PR_unlink,
	[ 11 ] = PR_execve,
	[ 12 ] = PR_chdir,
	[ 13 ] = PR_time,
	[ 14 ] = PR_mknod,
	[ 15 ] = PR_chmod,
	[ 16 ] = PR_lchown,
	[ 18 ] = PR_oldstat,
	[ 19 ] = PR_lseek,
	[ 20 ] = PR_getpid,
	[ 21 ] = PR_mount,
	[ 22 ] = PR_umount,
	[ 23 ] = PR_setuid,
	[ 24 ] = PR_getuid,
	[ 25 ] = PR_stime,
	[ 26 ] = PR_ptrace,
	[ 27 ] = PR_alarm,
	[ 28 ] = PR_oldfstat,
	[ 29 ] = PR_pause,
	[ 30 ] = PR_utime,
	[ 33 ] = PR_access,
	[ 34 ] = PR_nice,
	[ 36 ] = PR_sync,
	[ 37 ] = PR_kill,
	[ 38 ] = PR_rename,
	[ 39 ] = PR_mkdir,
	[ 40 ] = PR_rmdir,
	[ 41 ] = PR_dup,
	[ 42 ] = PR_pipe,
	[ 43 ] = PR_times,
	[ 45 ] = PR_brk,
	[ 46 ] = PR_setgid,
	[ 47 ] = PR_getgid,
	[ 48 ] = PR_signal,
	[ 49 ] = PR_geteuid,
	[ 50 ] = PR_getegid,
	[ 51 ] = PR_acct,
	[ 52 ] = PR_umount2,
	[ 54 ] = PR_ioctl,
	[ 55 ] = PR_fcntl,
	[ 57 ] = PR_setpgid,
	[ 60 ] = PR_umask,
	[ 61 ] = PR_chroot,
	[ 62 ] = PR_ustat,
	[ 63 ] = PR_dup2,
	[ 64 ] = PR_getppid,
	[ 65 ] = PR_getpgrp,
	[ 66 ] = PR_setsid,
	[ 67 ] = PR_sigaction,
	[ 68 ] = PR_sgetmask,
	[ 69 ] = PR_ssetmask,
	[ 70 ] = PR_setreuid,
	[ 71 ] = PR_setregid,
	[ 72 ] = PR_sigsuspend,
	[ 73 ] = PR_sigpending,
	[ 74 ] = PR_sethostname,
	[ 75 ] = PR_setrlimit,
	[ 76 ] = PR_getrlimit,
	[ 77 ] = PR_getrusage,
	[ 78 ] = PR_gettimeofday,
	[ 79 ] = PR_settimeofday,
	[ 80 ] = PR_getgroups,
	[ 81 ] = PR_setgroups,
	[ 83 ] = PR_symlink,
	[ 84 ] = PR_oldlstat,
	[ 85 ] = PR_readlink,
	[ 86 ] = PR_uselib,
	[ 87 ] = PR_swapon,
	[ 88 ] = PR_reboot,
	[ 89 ] = PR_readdir,
	[ 90 ] = PR_mmap,
	[ 91 ] = PR_munmap,
	[ 92 ] = PR_truncate,
	[ 93 ] = PR_ftruncate,
	[ 94 ] = PR_fchmod,
	[ 95 ] = PR_fchown,
	[ 96 ] = PR_getpriority,
	[ 97 ] = PR_setpriority,
	[ 99 ] = PR_statfs,
	[ 100 ] = PR_fstatfs,
	[ 102 ] = PR_socketcall,
	[ 103 ] = PR_syslog,
	[ 104 ] = PR_setitimer,
	[ 105 ] = PR_getitimer,
	[ 106 ] = PR_stat,
	[ 107 ] = PR_lstat,
	[ 108 ] = PR_fstat,
	[ 109 ] = PR_olduname,
	[ 111 ] = PR_vhangup,
	[ 114 ] = PR_wait4,
	[ 115 ] = PR_swapoff,
	[ 116 ] = PR_sysinfo,
	[ 117 ] = PR_ipc,
	[ 118 ] = PR_fsync,
	[ 119 ] = PR_sigreturn,
	[ 120 ] = PR_clone,
	[ 121 ] = PR_setdomainname,
	[ 122 ] = PR_uname,
	[ 123 ] = PR_cacheflush,
	[ 124 ] = PR_adjtimex,
	[ 125 ] = PR_mprotect,
	[ 126 ] = PR_sigprocmask,
	[ 128 ] = PR_init_module,
	[ 129 ] = PR_delete_module,
	[ 131 ] = PR_quotactl,
	[ 132 ] = PR_getpgid,
	[ 133 ] = PR_fchdir,
	[ 134 ] = PR_bdflush,
	[ 135 ] = PR_sysfs,
	[ 136 ] = PR_personality,
	[ 138 ] = PR_setfsuid,
	[ 139 ] = PR_setfsgid,
	[ 140 ] = PR__llseek,
	[ 141 ] = PR_getdents,
	[ 142 ] = PR__newselect,
	[ 143 ] = PR_flock,
	[ 144 ] = PR_msync,
	[ 145 ] = PR_readv,
	[ 146 ] = PR_writev,
	[ 147 ] = PR_getsid,
	[ 148 ] = PR_fdatasync,
	[ 149 ] = PR__sysctl,
	[ 150 ] = PR_mlock,
	[ 151 ] = PR_munlock,
	[ 152 ] = PR_mlockall,
	[ 153 ] = PR_munlockall,
	[ 154 ] = PR_sched_setparam,
	[ 155 ] = PR_sched_getparam,
	[ 156 ] = PR_sched_setscheduler,
	[ 157 ] = PR_sched_getscheduler,
	[ 158 ] = PR_sched_yield,
	[ 159 ] = PR_sched_get_priority_max,
	[ 160 ] = PR_sched_get_priority_min,
	[ 161 ] = PR_sched_rr_get_interval,
	[ 162 ] = PR_nanosleep,
	[ 163 ] = PR_mremap,
	[ 164 ] = PR_setresuid,
	[ 165 ] = PR_getresuid,
	[ 168 ] = PR_poll,
	[ 169 ] = PR_nfsservctl,
	[ 170 ] = PR_setresgid,
	[ 171 ] = PR_getresgid,
	[ 172 ] = PR_prctl,
	[ 173 ] = PR_rt_sigreturn,
	[ 174 ] = PR_rt_sigaction,
	[ 175 ] = PR_rt_sigprocmask,
	[ 176 ] = PR_rt_sigpending,
	[ 177 ] = PR_rt_sigtimedwait,
	[ 178 ] = PR_rt_sigqueueinfo,
	[ 179 ] = PR_rt_sigsuspend,
	[ 180 ] = PR_pread64,
	[ 181 ] = PR_pwrite64,
	[ 182 ] = PR_chown,
	[ 183 ] = PR_getcwd,
	[ 184 ] = PR_capget,
	[ 185 ] = PR_capset,
	[ 186 ] = PR_sigaltstack,
	[ 187 ] = PR_sendfile,
	[ 190 ] = PR_vfork,
	[ 191 ] = PR_ugetrlimit,
	[ 192 ] = PR_mmap2,
	[ 193 ] = PR_truncate64,
	[ 194 ] = PR_ftruncate64,
	[ 195 ] = PR_stat64,
	[ 196 ] = PR_lstat64,
	[ 197 ] = PR_fstat64,
	[ 198 ] = PR_lchown32,
	[ 199 ] = PR_getuid32,
	[ 200 ] = PR_getgid32,
	[ 201 ] = PR_geteuid32,
	[ 202 ] = PR_getegid32,
	[ 203 ] = PR_setreuid32,
	[ 204 ] = PR_setregid32,
	[ 205 ] = PR_getgroups32,
	[ 206 ] = PR_setgroups32,
	[ 207 ] = PR_fchown32,
	[ 208 ] = PR_setresuid32,
	[ 209 ] = PR_getresuid32,
	[ 210 ] = PR_setresgid32,
	[ 211 ] = PR_getresgid32,
	[ 212 ] = PR_chown32,
	[ 213 ] = PR_setuid32,
	[ 214 ] = PR_setgid32,
	[ 215 ] = PR_setfsuid32,
	[ 216 ] = PR_setfsgid32,
	[ 217 ] = PR_pivot_root,
	[ 218 ] = PR_mincore,
	[ 219 ] = PR_madvise,
	[ 220 ] = PR_getdents64,
	[ 221 ] = PR_fcntl64,
	[ 224 ] = PR_gettid,
	[ 225 ] = PR_readahead,
	[ 226 ] = PR_setxattr,
	[ 227 ] = PR_lsetxattr,
	[ 228 ] = PR_fsetxattr,
	[ 229 ] = PR_getxattr,
	[ 230 ] = PR_lgetxattr,
	[ 231 ] = PR_fgetxattr,
	[ 232 ] = PR_listxattr,
	[ 233 ] = PR_llistxattr,
	[ 234 ] = PR_flistxattr,
	[ 235 ] = PR_removexattr,
	[ 236 ] = PR_lremovexattr,
	[ 237 ] = PR_fremovexattr,
	[ 238 ] = PR_tkill,
	[ 239 ] = PR_sendfile64,
	[ 240 ] = PR_futex,
	[ 241 ] = PR_sched_setaffinity,
	[ 242 ] = PR_sched_getaffinity,
	[ 245 ] = PR_io_setup,
	[ 246 ] = PR_io_destroy,
	[ 247 ] = PR_io_getevents,
	[ 248 ] = PR_io_submit,
	[ 249 ] = PR_io_cancel,
	[ 250 ] = PR_fadvise64,
	[ 252 ] = PR_exit_group,
	[ 253 ] = PR_lookup_dcookie,
	[ 254 ] = PR_epoll_create,
	[ 255 ] = PR_epoll_ctl,
	[ 256 ] = PR_epoll_wait,
	[ 257 ] = PR_remap_file_pages,
	[ 258 ] = PR_set_tid_address,
	[ 259 ] = PR_timer_create,
	[ 260 ] = PR_timer_settime,
	[ 261 ] = PR_timer_gettime,
	[ 262 ] = PR_timer_getoverrun,
	[ 263 ] = PR_timer_delete,
	[ 264 ] = PR_clock_settime,
	[ 265 ] = PR_clock_gettime,
	[ 266 ] = PR_clock_getres,
	[ 267 ] = PR_clock_nanosleep,
	[ 268 ] = PR_statfs64,
	[ 269 ] = PR_fstatfs64,
	[ 270 ] = PR_tgkill,
	[ 271 ] = PR_utimes,
	[ 272 ] = PR_fadvise64_64,
	[ 274 ] = PR_mbind,
	[ 275 ] = PR_get_mempolicy,
	[ 276 ] = PR_set_mempolicy,
	[ 277 ] = PR_mq_open,
	[ 278 ] = PR_mq_unlink,
	[ 279 ] = PR_mq_timedsend,
	[ 280 ] = PR_mq_timedreceive,
	[ 281 ] = PR_mq_notify,
	[ 282 ] = PR_mq_getsetattr,
	[ 283 ] = PR_kexec_load,
	[ 284 ] = PR_waitid,
	[ 285 ] = PR_add_key,
	[ 286 ] = PR_request_key,
	[ 287 ] = PR_keyctl,
	[ 288 ] = PR_ioprio_set,
	[ 289 ] = PR_ioprio_get,
	[ 290 ] = PR_inotify_init,
	[ 291 ] = PR_inotify_add_watch,
	[ 292 ] = PR_inotify_rm_watch,
	[ 294 ] = PR_migrate_pages,
	[ 295 ] = PR_openat,
	[ 296 ] = PR_mkdirat,
	[ 297 ] = PR_mknodat,
	[ 298 ] = PR_fchownat,
	[ 299 ] = PR_futimesat,
	[ 300 ] = PR_fstatat64,
	[ 301 ] = PR_unlinkat,
	[ 302 ] = PR_renameat,
	[ 303 ] = PR_linkat,
	[ 304 ] = PR_symlinkat,
	[ 305 ] = PR_readlinkat,
	[ 306 ] = PR_fchmodat,
	[ 307 ] = PR_faccessat,
	[ 308 ] = PR_pselect6,
	[ 309 ] = PR_ppoll,
	[ 310 ] = PR_unshare,
	[ 311 ] = PR_set_robust_list,
	[ 312 ] = PR_get_robust_list,
	[ 313 ] = PR_splice,
	[ 314 ] = PR_sync_file_range,
	[ 315 ] = PR_tee,
	[ 316 ] = PR_vmsplice,
	[ 317 ] = PR_move_pages,
	[ 318 ] = PR_getcpu,
	[ 319 ] = PR_epoll_pwait,
	[ 320 ] = PR_utimensat,
	[ 321 ] = PR_signalfd,
	[ 322 ] = PR_timerfd_create,
	[ 323 ] = PR_eventfd,
	[ 324 ] = PR_fallocate,
	[ 325 ] = PR_timerfd_settime,
	[ 326 ] = PR_timerfd_gettime,
	[ 327 ] = PR_signalfd4,
	[ 328 ] = PR_eventfd2,
	[ 329 ] = PR_epoll_create1,
	[ 330 ] = PR_dup3,
	[ 331 ] = PR_pipe2,
	[ 332 ] = PR_inotify_init1,
	[ 333 ] = PR_preadv,
	[ 334 ] = PR_pwritev,
	[ 335 ] = PR_rt_tgsigqueueinfo,
	[ 336 ] = PR_perf_event_open,
	[ 337 ] = PR_fanotify_init,
	[ 338 ] = PR_fanotify_mark,
	[ 339 ] = PR_prlimit64,
	[ 340 ] = PR_socket,
	[ 341 ] = PR_bind,
	[ 342 ] = PR_connect,
	[ 343 ] = PR_listen,
	[ 344 ] = PR_accept,
	[ 345 ] = PR_getsockname,
	[ 346 ] = PR_getpeername,
	[ 347 ] = PR_socketpair,
	[ 348 ] = PR_send,
	[ 349 ] = PR_sendto,
	[ 350 ] = PR_recv,
	[ 351 ] = PR_recvfrom,
	[ 352 ] = PR_shutdown,
	[ 353 ] = PR_setsockopt,
	[ 354 ] = PR_getsockopt,
	[ 355 ] = PR_sendmsg,
	[ 356 ] = PR_recvmsg,
	[ 357 ] = PR_recvmmsg,
	[ 358 ] = PR_accept4,
	[ 359 ] = PR_name_to_handle_at,
	[ 360 ] = PR_open_by_handle_at,
	[ 361 ] = PR_clock_adjtime,
	[ 362 ] = PR_syncfs,
	[ 363 ] = PR_sendmmsg,
	[ 364 ] = PR_setns,
	[ 365 ] = PR_process_vm_readv,
	[ 366 ] = PR_process_vm_writev,
	[ 374 ] = PR_memfd_create,
	[ 439 ] = PR_faccessat2,
};
