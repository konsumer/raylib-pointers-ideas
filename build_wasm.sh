#!/bin/bash

# this is meant to be run inside "docker run -it --rm -v $(pwd):/cart null0"

clang --target=wasm32-unknown-wasi -Ofast --sysroot $WASI_SYSROOT -Wl,--allow-undefined -Wl,--export-all -Wl,--no-entry -nostartfiles $*
