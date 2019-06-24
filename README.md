PRoot
=====
It is a clone of the Termux version of PRoot with some additional adaptations for Android deployment.

* In case of unbundled loader, relocation does not require to set `PROOT_LOADER` / `PROOT_LOADER_32` variables and these variables can be relative to the `proot` binary location and resolved as `<proot_location>/../$PROOT_LOADER`. Defaults are `libexec/proot/loader` / `libexec/proot/loader32` respectively.

* --tcsetsf2tcsets option as long as TCSETSF is forbidden in Android and substitution with TCSETS can be an acceptable workaround. `tcsetattr(TCSAFLUSH, ...)` => `tcsetattr(TCSANOW, ...)` in other words.

* ANDROID_PRE5 make variable can be set in order to produce Android version < 5 (API < 21) compatible variant.
