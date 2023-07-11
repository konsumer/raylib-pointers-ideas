// these will maybe eventually be part of the generated header
#define WASM_EXPORT __attribute__((visibility("default")))
#define RLP_EXPORT __attribute__((import_module("raylib"))) extern
#include "api.h"

Texture2D* texBunny;
Texture2D* texBunny2;

WASM_EXPORT void InitGame() {
  rp_InitWindow(800, 450, "raylib-pointers test program");

  texBunny = (Texture2D*) malloc(sizeof(Texture2D));
  rp_LoadTexture(texBunny, "wabbit_alpha.png");
  texBunny2 = (Texture2D*) malloc(sizeof(Texture2D));
  rp_LoadTexture(texBunny2, "wabbit_alpha.png");
}

WASM_EXPORT void UpdateGame() {
  rp_BeginDrawing();
  rp_ClearBackground(rp_RAYWHITE);
  rp_DrawText("Congrats! You created your first window!", 190, 200, 20, rp_LIGHTGRAY);
  rp_DrawTexture(texBunny, 100, 100, rp_WHITE);
  rp_DrawFPS(10, 10);
  rp_EndDrawing();
}

