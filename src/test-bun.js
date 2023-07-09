// this is a minimal POC of using raylib-pointers in bun

// this will be in the library header, and be mostly generated:

import { dlopen, suffix, ptr, toArrayBuffer } from 'bun:ffi'

const ffi = {
  rp_InitWindow: {
    args: [
      'i32',
      'i32',
      'cstring'
    ],
    returns: 'void'
  },

  rp_WindowShouldClose: {
    args: [
    ],
    returns: 'bool'
  },

  rp_CloseWindow: {
    args: [
    ],
    returns: 'void'
  },

  rp_SetTargetFPS: {
    args: [
      'i32'
    ],
    returns: 'void'
  },

  rp_BeginDrawing: {
    args: [
    ],
    returns: 'void'
  },

  rp_EndDrawing: {
    args: [
    ],
    returns: 'void'
  },

  rp_DrawFPS: {
    args: [
      'i32',
      'i32'
    ],
    returns: 'void'
  },

  rp_ClearBackground: {
    args: [
      'ptr'
    ],
    returns: 'void'
  },

  rp_DrawText: {
    args: [
      'cstring',
      'i32',
      'i32',
      'i32',
      'ptr'
    ],
    returns: 'void'
  },

  rp_DrawTexture: {
    args: [
      'ptr',
      'i32',
      'i32',
      'ptr'
    ],
    returns: 'void'
  },

  rp_LoadTexture: {
    args: [
      'ptr',
      'cstring'
    ],
    returns: 'void'
  }
}

const { symbols } = dlopen(`${__dirname}/../build/libraylib_pointers.${suffix}`, ffi)

const cstr = s => ptr(Buffer.from((s || '') + '\0'))

// these are wrappers to make it all look more like normal raylib in js, this will also be generated

class Color {
  constructor (init = {}, _address) {
    this._size = 4
    this._buffer = new ArrayBuffer(this._size)
    this._address = ptr(this._buffer)
    this._dv = new DataView(this._buffer)

    this.r = init.r || 0
    this.g = init.g || 0
    this.b = init.b || 0
    this.a = init.a || 0
  }

  get r () {
    return this._dv.getUint8(0)
  }

  set r (r) {
    this._dv.setUint8(0, r)
  }

  get g () {
    return this._dv.getUint8(1)
  }

  set g (g) {
    this._dv.setUint8(1, g)
  }

  get b () {
    return this._dv.getUint8(2)
  }

  set b (b) {
    this._dv.setUint8(2, b)
  }

  get a () {
    return this._dv.getUint8(3)
  }

  set a (a) {
    this._dv.setUint8(3, a)
  }
}

class Texture {
  constructor (init = {}, _address) {
    this._size = 20
    this._buffer = new ArrayBuffer(this._size)
    this._address = ptr(this._buffer)
    this._dv = new DataView(this._buffer)

    this.id = init.id || 0
    this.width = init.width || 0
    this.height = init.height || 0
    this.mipmaps = init.mipmaps || 0
    this.format = init.format || 0
  }

  get id () {
    return this._dv.getUint32(0, true)
  }

  set id (id) {
    this._dv.setUint32(0, id, true)
  }

  get width () {
    return this._dv.getInt32(4, true)
  }

  set width (width) {
    this._dv.setInt32(4, width, true)
  }

  get height () {
    return this._dv.getInt32(8, true)
  }

  set height (height) {
    this._dv.setInt32(8, height, true)
  }

  get mipmaps () {
    return this._dv.getInt32(12, true)
  }

  set mipmaps (mipmaps) {
    this._dv.setInt32(12, mipmaps, true)
  }

  get format () {
    return this._dv.getInt32(16, true)
  }

  set format (format) {
    this._dv.setInt32(16, format, true)
  }
}

const LIGHTGRAY = new Color({ r: 200, g: 200, b: 200, a: 255 }) // Light Gray
const GRAY = new Color({ r: 130, g: 130, b: 130, a: 255 }) // Gray
const DARKGRAY = new Color({ r: 80, g: 80, b: 80, a: 255 }) // Dark Gray
const YELLOW = new Color({ r: 253, g: 249, b: 0, a: 255 }) // Yellow
const GOLD = new Color({ r: 255, g: 203, b: 0, a: 255 }) // Gold
const ORANGE = new Color({ r: 255, g: 161, b: 0, a: 255 }) // Orange
const PINK = new Color({ r: 255, g: 109, b: 194, a: 255 }) // Pink
const RED = new Color({ r: 230, g: 41, b: 55, a: 255 }) // Red
const MAROON = new Color({ r: 190, g: 33, b: 55, a: 255 }) // Maroon
const GREEN = new Color({ r: 0, g: 228, b: 48, a: 255 }) // Green
const LIME = new Color({ r: 0, g: 158, b: 47, a: 255 }) // Lime
const DARKGREEN = new Color({ r: 0, g: 117, b: 44, a: 255 }) // Dark Green
const SKYBLUE = new Color({ r: 102, g: 191, b: 255, a: 255 }) // Sky Blue
const BLUE = new Color({ r: 0, g: 121, b: 241, a: 255 }) // Blue
const DARKBLUE = new Color({ r: 0, g: 82, b: 172, a: 255 }) // Dark Blue
const PURPLE = new Color({ r: 200, g: 122, b: 255, a: 255 }) // Purple
const VIOLET = new Color({ r: 135, g: 60, b: 190, a: 255 }) // Violet
const DARKPURPLE = new Color({ r: 112, g: 31, b: 126, a: 255 }) // Dark Purple
const BEIGE = new Color({ r: 211, g: 176, b: 131, a: 255 }) // Beige
const BROWN = new Color({ r: 127, g: 106, b: 79, a: 255 }) // Brown
const DARKBROWN = new Color({ r: 76, g: 63, b: 47, a: 255 }) // Dark Brown
const WHITE = new Color({ r: 255, g: 255, b: 255, a: 255 }) // White
const BLACK = new Color({ r: 0, g: 0, b: 0, a: 255 }) // Black
const BLANK = new Color({ r: 0, g: 0, b: 0, a: 0 }) // Blank (Transparent)
const MAGENTA = new Color({ r: 255, g: 0, b: 255, a: 255 }) // Magenta
const RAYWHITE = new Color({ r: 245, g: 245, b: 245, a: 255 }) // My own White (const logo)

const InitWindow = (width, height, title) => symbols.rp_InitWindow(width, height, cstr(title))
const WindowShouldClose = symbols.rp_WindowShouldClose
const CloseWindow = symbols.rp_CloseWindow
const BeginDrawing = symbols.rp_BeginDrawing
const EndDrawing = symbols.rp_EndDrawing
const SetTargetFPS = symbols.rp_SetTargetFPS
const DrawFPS = symbols.rp_DrawFPS
const ClearBackground = (color) => symbols.rp_ClearBackground(color._address)
const DrawText = (text, x, y, size, color) => symbols.rp_DrawText(cstr(text), x, y, size, color._address)
const DrawTexture = (texture, x, y, tint) => symbols.rp_DrawTexture(texture._address, x, y, tint._address)
const LoadTexture = (filename) => {
  const ret = new Texture()
  symbols.rp_LoadTexture(ret._address, cstr(filename))
  return ret
}

// here the actual demo starts

InitWindow(800, 450, 'raylib-pointers test program')
SetTargetFPS(60)

const texBunny = LoadTexture('wabbit_alpha.png')

const s = cstr('Congrats! You created your first window!')

while (!WindowShouldClose()) {
  BeginDrawing()
  ClearBackground(RAYWHITE)

  // EXC_BAD_ACCESS after many frames
  // DrawText("Congrats! You created your first window!", 190, 200, 20, LIGHTGRAY)

  // this is a hack that uses a pre-allocated string, since it makes bun grumpy to allocate strings in a loop
  // but it eventually corrupts, too
  symbols.rp_DrawText(s, 190, 200, 20, LIGHTGRAY._address)

  DrawTexture(texBunny, 100, 100, WHITE)
  DrawFPS(10, 10)
  EndDrawing()
}

CloseWindow()
