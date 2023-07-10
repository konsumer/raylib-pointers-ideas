// This will load the wasm built with `npm run build:wasm1` in node

import { readFile } from 'fs/promises'

const env = {
  raylib: {
    rp_InitWindow() {
      console.log('InitWindow', arguments)
    },
    rp_LoadTexture(){
      console.log('LoadTexture', arguments)
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
      console.log('malloc', size)
    }
  }
}

const { instance: { exports } } = await WebAssembly.instantiate(await readFile("game.wasm"), env)

exports.InitGame()
exports.UpdateGame()