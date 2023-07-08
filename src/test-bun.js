// this is a minimal POC of using raylib-pointers in bun

// this will be in the library header, and be mostly generated:

import { dirname } from 'path'
import { fileURLToPath } from 'url'

import { dlopen, suffix, ptr } from 'bun:ffi'

const ffi = {
   "rp_InitWindow": {
    "args": [
      "i32",
      "i32",
      "cstring"
    ],
    "returns": "void"
  },
  
  "rp_WindowShouldClose": {
    "args": [
    ],
    "returns": "bool"
  },
  
  "rp_CloseWindow": {
    "args": [
    ],
    "returns": "void"
  },
  
  "rp_SetTargetFPS": {
    "args": [
      "i32"
    ],
    "returns": "void"
  },
  
  "rp_BeginDrawing": {
    "args": [
    ],
    "returns": "void"
  },
  
  "rp_EndDrawing": {
    "args": [
    ],
    "returns": "void"
  },
  
  "rp_DrawFPS": {
    "args": [
      "i32",
      "i32"
    ],
    "returns": "void"
  },
  
  "rp_ClearBackground": {
    "args": [
      "ptr"
    ],
    "returns": "void"
  },
  
  "rp_DrawText": {
    "args": [
      "cstring",
      "i32",
      "i32",
      "i32",
      "ptr"
    ],
    "returns": "void"
  },
  
  "rp_DrawTexture": {
    "args": [
      "ptr",
      "i32",
      "i32",
      "ptr"
    ],
    "returns": "void"
  },
  
  "rp_LoadTexture": {
    "args": [
      "ptr",
      "cstring"
    ],
    "returns": "void"
  },

  "rp_malloc": {
    "args": [
      "i32"
    ],
    "returns": "ptr"
  },
  
  "rp_free": {
    "args": [
      "ptr"
    ],
    "returns": "void"
  },

  "rp_get_u8": {
    "args": [
      "ptr"
    ],
    "returns": "u8"
  },

  "rp_set_u8": {
    "args": [
      "ptr",
      "u8"
    ],
    "returns": "void"
  },
  
  "rp_get_u32": {
    "args": [
      "ptr"
    ],
    "returns": "u32"
  },

  "rp_set_u32": {
    "args": [
      "ptr",
      "u32"
    ],
    "returns": "void"
  },

  "rp_get_i32": {
    "args": [
      "ptr"
    ],
    "returns": "i32"
  },

  "rp_set_i32": {
    "args": [
      "ptr",
      "i32"
    ],
    "returns": "void"
  }
}


const { symbols } = dlopen(`${__dirname}/../build/libraylib_pointers.${suffix}`, ffi)

const cstr = s => ptr(Buffer.from((s || '\0')))

// these are wrappers to make it all look more like normal raylib in js, this will also be generated

class Color {
  constructor(init = {}, _address) {
    this._size = 4
    this._address = _address || symbols.rp_malloc(this._size)

    this.r = init.r || 0
    this.g = init.g || 0
    this.b = init.b || 0
    this.a = init.a || 0
  }
  
  get r () {
    return symbols.rp_get_u8(this._address + 0)
  }
  set r (r) {
    symbols.rp_set_u8(this._address + 0, r)
  }

  get g () {
    return symbols.rp_get_u8(this._address + 1)
  }
  set g (g) {
    symbols.rp_set_u8(this._address + 1, g)
  }

  get b () {
    return symbols.rp_get_u8(this._address + 2)
  }
  set b (b) {
    symbols.rp_set_u8(this._address + 2, b)
  }

  get a () {
    return symbols.rp_get_u8(this._address + 3)
  }
  set a (a) {
    symbols.rp_set_u8(this._address + 3, a)
  }
}

class Texture {
  constructor(init = {}, _address) {
    this._size = 20
    this._address = _address || symbols.rp_malloc(this._size)

    this.id = init.id || 0
    this.width = init.width || 0
    this.height = init.height || 0
    this.mipmaps = init.mipmaps || 0
    this.format = init.format || 0
  }
  
  get id () {
    return symbols.rp_get_u32(this._address + 0)
  }
  set id (id) {
    symbols.rp_set_u32(this._address + 0, id)
  }

  get width () {
    return symbols.rp_get_i32(this._address + 4)
  }
  set width (width) {
    symbols.rp_set_i32(this._address + 4, width)
  }

  get height () {
    return symbols.rp_get_i32(this._address + 8)
  }
  set height (height) {
    symbols.rp_set_i32(this._address + 8, height)
  }

  get mipmaps () {
    return symbols.rp_get_i32(this._address + 12)
  }
  set mipmaps (mipmaps) {
    symbols.rp_set_i32(this._address + 12, mipmaps)
  }

  get format () {
    return symbols.rp_get_i32(this._address + 16)
  }
  set format (format) {
    symbols.rp_set_i32(this._address + 16, format)
  }
}

const LIGHTGRAY = new Color({r: 200, g: 200, b: 200, a: 255}) // Light Gray
const WHITE = new Color({r: 255, g: 255, b: 255, a: 255}) // White
const RAYWHITE = new Color({r: 245, g: 245, b: 245, a: 255}) // My own White (raylib logo)

const InitWindow = (width, height, title) => symbols.rp_InitWindow(width, height, cstr(title))
const WindowShouldClose = symbols.rp_WindowShouldClose
const CloseWindow = symbols.rp_CloseWindow
const BeginDrawing = symbols.rp_BeginDrawing
const EndDrawing = symbols.rp_EndDrawing
const SetTargetFPS = symbols.rp_SetTargetFPS
const DrawFPS = symbols.rp_DrawFPS
const ClearBackground = (color) => symbols.rp_ClearBackground(color._address)
const DrawText = (text, x, y, size, color) => symbols.rp_DrawText(cstr(text), x, y, size, color._address)
const DrawTexture = (texture, tint) =>  symbols.rp_DrawTexture(texture._address, tint._address)
const LoadTexture = (filename) => {
  const ret = new Texture()
  symbols.rp_LoadTexture(ret._address, cstr(filename))
  return ret
}

// here the actual demo starts

InitWindow(800, 450, "raylib-pointers test program")
SetTargetFPS(60)

const texBunny = LoadTexture("wabbit_alpha.png")

while (!WindowShouldClose()) {
  BeginDrawing()
  ClearBackground(RAYWHITE)
  DrawText("Congrats! You created your first window!", 190, 200, 20, LIGHTGRAY)
  DrawTexture(texBunny, 100, 100, WHITE)
  DrawFPS(10, 10)
  EndDrawing()
}

CloseWindow()
