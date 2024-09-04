> [!NOTE]  
> Work on this has been moved to [raylib-pointers](https://github.com/konsumer/raylib-pointers).


The idea here is that this is raylib, but all structs are pointers, and all struct-returns are moved to the first paramater of the function. This is similar to what emscripten/clang does, and is meant to help with bunjs ffi (and others) which can only use pointers, not values of non-numbers.

Every raylib function gets a `rp_` prefix.

An example:

```c
// original
Matrix GetCameraMatrix(Camera camera);

// wrapped
void rp_GetCameraMatrix(Matrix* retval, Camera* camera);
```

Functions that don't return struct-vals, or take struct-val params will just stay the same:

```c
bool rp_WindowShouldClose(void);
```

## development

```
# run the code-generation
bun run generate

# full build of everything
bun run build
```
