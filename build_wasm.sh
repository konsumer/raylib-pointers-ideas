#!/bin/bash

# this is meant to be run inside "docker run -it --rm -v $(pwd):/cart null0"

clang --target=wasm32-unknown-wasi -Wl,--allow-undefined --sysroot $WASI_SYSROOT -nostartfiles -Wl,--import-memory -Wl,--no-entry -Wl,--export-all $*