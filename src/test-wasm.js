// This will load the wasm built with `npm run build:wasm1` in node

import { readFile } from 'fs/promises'

let lastPtr = 0

const env = {
  raylib: {
    rp_InitWindow() {
      console.log('InitWindow', arguments)
    },
    rp_LoadTexture(){
      console.log('LoadTexture', arguments)
      // could do something here like use the pointer to point to an image loaded in browser
    },
    rp_BeginDrawing(){
      console.log('BeginDrawing')
    },
    rp_ClearBackground(){
      console.log('ClearBackground', arguments)
    },
    rp_DrawText(){
      console.log('DrawText', arguments)
    },
    rp_DrawTexture(){
      console.log('DrawTexture', arguments)
    },
    rp_DrawFPS(){
      console.log('DrawFPS', arguments)
    },
    rp_EndDrawing(){
      console.log('EndDrawing')
    }
  },
  
  env: {
    malloc(size) {
      const ptr = lastPtr
      lastPtr += size
      return ptr
    }
  }
}

const { instance: { exports } } = await WebAssembly.instantiate(await readFile("game.wasm"), env)

exports.InitGame()
exports.UpdateGame()
