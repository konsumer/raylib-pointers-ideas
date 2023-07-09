// this is a test program that will use raylib-pointers in C
// other targets will attempt to do similar

// this stuff would be in the interface header or whatever
// setup all the struct defs in the consumer and use pointers instead of values

// #include <stdbool.h>
// #include <stdlib.h>

#include "api.h"

Texture2D* texBunny;

void InitGame() {
  rp_InitWindow(800, 450, "raylib-pointers test program");
  texBunny = (Texture2D*) malloc(sizeof(Texture2D));
  rp_LoadTexture(texBunny, "wabbit_alpha.png");
}

void UpdateGame() {
  rp_BeginDrawing();
  rp_ClearBackground(rp_RAYWHITE);
  rp_DrawText("Congrats! You created your first window!", 190, 200, 20, rp_LIGHTGRAY);
  rp_DrawTexture(texBunny, 100, 100, rp_WHITE);
  rp_DrawFPS(10, 10);
  rp_EndDrawing();
}

int main(void) {
  InitGame();
  rp_SetTargetFPS(60);
  while (!rp_WindowShouldClose()) {
    UpdateGame();
  }
  rp_CloseWindow();
  return 0;
}