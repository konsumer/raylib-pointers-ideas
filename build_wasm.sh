#!/bin/bash

# this is meant to be run inside "docker run -it --rm -v $(pwd):/cart null0"

clang --target=wasm32-unknown-wasi -Wl,--strip-all -fpic -Wl,--allow-undefined -Wl,--export-all --sysroot $WASI_SYSROOT -Wl,--no-entry -mexec-model=reactor -nostartfiles $*