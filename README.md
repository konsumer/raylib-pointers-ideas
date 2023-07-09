The idea here is that this is raylib, but all structs are pointers, and all struct-returns are moved to the first paramater of the function.

Currently, this is a minimal POC.

This is similar to what emscripten does, and should help with lower-to-the-ground wasm, but also make it easier to bind in bun (and more) which works better with pointers.

```
npm i

npm run build
```

You can see what I am trying to do in `src/test.c`, and similar will be implemented for other targets, like `src/test-bun.js`


The eventual goal is a pointer-based interface that will work on these targets:

- Wasm game - your game (written in something compiled to wasm) will import pointer-based functions from (native or web) host.
- Wasm wrapper - a host (written in JS) will direclty call pointer-based raylib functions from wasm
- Bun FFI - Bun will import the DLL and call the functions in JS code.