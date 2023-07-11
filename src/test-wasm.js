// This will load the wasm built with `npm run build:wasm1` in node

import { readFile } from 'fs/promises'

let i = 0

const decoder = new TextDecoder()

// pull a c-string (UTF8, null-terminated) from WASM-memory
const str = ptr => {
  let p = ptr
  while(memory.getUint8(p) !== 0) { p++ }
  return decoder.decode(memory.buffer.slice(ptr, p))
}

class Color {
  constructor(init = {}, _address) {
    this._size = 4
    this._address = _address || exports.malloc(this._size)

    for (const f of Object.keys(init)) {
      this[f] = init[f]
    }

    // console.log('Color', this._address, memory.buffer.slice(this._address, this._address + this._size))
  }
  
  get r () {
    return memory.getUint8(this._address + 0)
  }
  set r (r) {
    console.log('r', r)
    memory.setUint8(this._address + 0, r)
  }

  get g () {
    return memory.getUint8(this._address + 1)
  }
  set g (g) {
    console.log('g', g)
    memory.setUint8(this._address + 1, g)
  }

  get b () {
    return memory.getUint8(this._address + 2)
  }
  set b (b) {
    console.log('b', b)
    memory.setUint8(this._address + 2, b)
  }

  get a () {
    return memory.getUint8(this._address + 3)
  }
  set a (a) {
    console.log('a', a)
    memory.setUint8(this._address + 3, a)
  }
}

class Texture {
  constructor(init = {}, _address) {
    this._size = 20
    this._address = _address || exports.malloc(this._size)

    for (const f of Object.keys(init)) {
      this[f] = init[f]
    }

    // console.log('Texture', this._address, memory.buffer.slice(this._address, this._address + this._size))
  }
  
  get id () {
    return memory.getUint32(this._address + 0)
  }
  set id (id) {
    memory.setUint32(this._address + 0, id)
  }

  get width () {
    return memory.getInt32(this._address + 4)
  }
  set width (width) {
    memory.setInt32(this._address + 4, width)
  }

  get height () {
    return memory.getInt32(this._address + 8)
  }
  set height (height) {
    memory.setInt32(this._address + 8, height)
  }

  get mipmaps () {
    return memory.getInt32(this._address + 12)
  }
  set mipmaps (mipmaps) {
    memory.setInt32(this._address + 12, mipmaps)
  }

  get format () {
    return memory.getInt32(this._address + 16)
  }
  set format (format) {
    memory.setInt32(this._address + 16, format)
  }
}

const imports = {
  raylib: {
    rp_InitWindow(width, height, titlePtr) {
      console.log('InitWindow', {
        width,
        height,
        title: str(titlePtr)
      })
    },
    
    rp_LoadTexture(retPtr, filenamePtr){
      // example of filling in the return
      const t = new Texture({id: i++, width: 32, height: 32, mipmaps: 2}, retPtr)
      console.log('LoadTexture', {
        filename: str(filenamePtr),
        returns: `Texture(id:${t.id}, width:${t.width}, height:${t.height}, mipmaps:${t.mipmaps}, format:${t.format})`
      })
    },

    rp_BeginDrawing(){ console.log('BeginDrawing') },

    rp_ClearBackground(colorPtr){
      const c = new Color({}, colorPtr)
      console.log('ClearBackground', {
        color: `Color(${c.r}, ${c.g}, ${c.b}, ${c.a})`
      })
    },
    
    rp_DrawText(textPtr, x, y, fontSize, colorPtr){
      const c = new Color({}, colorPtr)
      console.log('DrawText', {
        text: str(textPtr),
        x,
        y,
        fontSize,
        color: `Color(${c.r}, ${c.g}, ${c.b}, ${c.a})`
      })
    },
    
    rp_DrawTexture(texturePtr, x, y, colorPtr){
      const c = new Color({}, colorPtr)
      const t = new Texture({}, texturePtr)
      console.log('DrawTexture', {
        texture: `Texture(id:${t.id}, width:${t.width}, height:${t.height}, mipmaps:${t.mipmaps}, format:${t.format})`,
        x,
        y,
        color: `Color(${c.r}, ${c.g}, ${c.b}, ${c.a})`
      })
    },
    
    rp_DrawFPS(x, y){ console.log('DrawFPS', {x, y}) },
    
    rp_EndDrawing(){ console.log('EndDrawing') }
  },

  // these could be implemented to handle stdlib stuff, but aren't needed for demo.
  wasi_snapshot_preview1: {
    args_get() { console.log("args_get", arguments) },
    args_sizes_get() { console.log("args_sizes_get", arguments) },
    environ_get() { console.log("environ_get", arguments) },
    environ_sizes_get() { console.log("environ_sizes_get", arguments) },
    clock_res_get() { console.log("clock_res_get", arguments) },
    clock_time_get() { console.log("clock_time_get", arguments) },
    fd_advise() { console.log("fd_advise", arguments) },
    fd_allocate() { console.log("fd_allocate", arguments) },
    fd_close() { console.log("fd_close", arguments) },
    fd_datasync() { console.log("fd_datasync", arguments) },
    fd_fdstat_get() { console.log("fd_fdstat_get", arguments) },
    fd_fdstat_set_flags() { console.log("fd_fdstat_set_flags", arguments) },
    fd_fdstat_set_rights() { console.log("fd_fdstat_set_rights", arguments) },
    fd_filestat_get() { console.log("fd_filestat_get", arguments) },
    fd_filestat_set_size() { console.log("fd_filestat_set_size", arguments) },
    fd_filestat_set_times() { console.log("fd_filestat_set_times", arguments) },
    fd_pread() { console.log("fd_pread", arguments) },
    fd_prestat_get() { console.log("fd_prestat_get", arguments) },
    fd_prestat_dir_name() { console.log("fd_prestat_dir_name", arguments) },
    fd_pwrite() { console.log("fd_pwrite", arguments) },
    fd_read() { console.log("fd_read", arguments) },
    fd_readdir() { console.log("fd_readdir", arguments) },
    fd_renumber() { console.log("fd_renumber", arguments) },
    fd_seek() { console.log("fd_seek", arguments) },
    fd_sync() { console.log("fd_sync", arguments) },
    fd_tell() { console.log("fd_tell", arguments) },
    fd_write() { console.log("fd_write", arguments) },
    path_create_directory() { console.log("path_create_directory", arguments) },
    path_filestat_get() { console.log("path_filestat_get", arguments) },
    path_filestat_set_times() { console.log("path_filestat_set_times", arguments) },
    path_link() { console.log("path_link", arguments) },
    path_open() { console.log("path_open", arguments) },
    path_readlink() { console.log("path_readlink", arguments) },
    path_remove_directory() { console.log("path_remove_directory", arguments) },
    path_rename() { console.log("path_rename", arguments) },
    path_symlink() { console.log("path_symlink", arguments) },
    path_unlink_file() { console.log("path_unlink_file", arguments) },
    poll_oneoff() { console.log("poll_oneoff", arguments) },
    proc_exit() { console.log("proc_exit", arguments) },
    sched_yield() { console.log("sched_yield", arguments) },
    random_get() { console.log("random_get", arguments) },
    sock_accept() { console.log("sock_accept", arguments) },
    sock_recv() { console.log("sock_recv", arguments) },
    sock_send() { console.log("sock_send", arguments) },
    sock_shutdown() { console.log("sock_shutdown", arguments) }
  }
}

const { instance: { exports } } = await WebAssembly.instantiate(await readFile("game.wasm"), imports)
const memory = new DataView(exports.memory.buffer)

exports.InitGame()
exports.UpdateGame()
