// this is a test program that will use raylib-pointers in C
// other targets will attempt to do similar

#include "raylib-pointers.h"

int main(void) {
  rp_InitWindow(800, 450, "raylib-pointers test program");
  Texture2D* texBunny = (Texture2D*) rp_MemAlloc(sizeof(Texture2D));
  rp_LoadTexture(texBunny, "example/wabbit_alpha.png");
  rp_SetTargetFPS(60);
  
  while (!rp_WindowShouldClose()) {
    rp_BeginDrawing();
    rp_ClearBackground(&RAYWHITE);
    rp_DrawText("Congrats! You created your first window!", 190, 200, 20, &LIGHTGRAY);
    rp_DrawTexture(texBunny, 100, 100, &WHITE);
    rp_DrawFPS(10, 10);
    rp_EndDrawing();
  }
  
  rp_CloseWindow();
  rp_MemFree(texBunny);
  return 0;
}