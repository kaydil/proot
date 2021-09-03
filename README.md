# PRoot

It is a clone of the Termux version of PRoot with some additional adaptations for Android deployment.

## Features

* In case of unbundled loader, relocation does not require to set `PROOT_LOADER` / `PROOT_LOADER_32` variables
and these variables can be relative to the `proot` binary location and resolved as `<proot_location>/$PROOT_LOADER`.
Defaults are `../libexec/proot/loader` / `../libexec/proot/loader32` respectively.

* `--tcsetsf2tcsets` option as long as `TCSETSF` is forbidden in Android and substitution with `TCSETS` can be an acceptable workaround.
`tcsetattr(TCSAFLUSH, ...)` => `tcsetattr(TCSANOW, ...)` in other words.

* `--tcsetsf2tcsetsw` as `TCSETSW` looks even better. `tcsetattr(TCSAFLUSH, ...)` => `tcsetattr(TCSADRAIN, ...)` in other words.

* `--mute-setxid` return `0` for calls
  - `setuid()`
  - `setuid32()`
  - `setgid()`
  - `setgid32()`
  - `setreuid()`
  - `setreuid32()`
  - `setregid()`
  - `setregid32()`
  - `setresuid()`
  - `setresuid32()`
  - `setresgid()`
  - `setresgid32()`
if they trigger `SIGSYS` (Android related).

* `--bind-memfd=<pattern>` option as long as Android does not provide access to *tmpfs* for regular apps. It uses `memfd_create()`.
Pattern acts like the `fnmatch()` one with the `FNM_PATHNAME` and `FNM_EXTMATCH` flags.
*Experimental. No `open_by_handle_at` syscall support yet.*

* `ANDROID_PRE5` make variable can be set in order to produce Android version < 5 (API < 21) compatible variant.

* Hardlinks:
  * with broken meta info are not weird zombie files anymore. Now they are just dangling symlinks;
  * prefix `.l2s.` => `.proot.l2s.` for non-UserLAnd builds.

* Hidden files (`-H` option):
  * prefix changed: `.proot` => `.proot.`.

* USERLAND variant meta file prefix changed: `.proot-meta-file.` => `.proot.meta-file.`.

## Known Issues

"chfn: PAM: system error" (it seems, Debian and Ubuntu bootstraps for 32-bit architectures only are affected):
https://github.com/proot-me/proot/issues/174#issuecomment-495406815 and https://github.com/proot-me/PRoot/issues/156
