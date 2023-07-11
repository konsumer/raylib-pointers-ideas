// This will load the wasm built with `npm run build:wasm1` in node

import { readFile } from 'fs/promises'

let lastPtr = 0

const env = {
  raylib: {
    rp_InitWindow() { console.log('InitWindow', arguments)},
    rp_LoadTexture(){ console.log('LoadTexture', arguments) },
    rp_BeginDrawing(){ console.log('BeginDrawing') },
    rp_ClearBackground(){ console.log('ClearBackground', arguments) },
    rp_DrawText(){ console.log('DrawText', arguments) },
    rp_DrawTexture(){ console.log('DrawTexture', arguments) },
    rp_DrawFPS(){ console.log('DrawFPS', arguments) },
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

const { instance: { exports } } = await WebAssembly.instantiate(await readFile("game.wasm"), env)

exports.InitGame()
exports.UpdateGame()
