// this is a test program that will use raylib-pointers in C
// other targets will attempt to do similar

// this stuff would be in the interface header or whatever
// setup all the struct defs in the consumer and use pointers instead of values

#include <stdbool.h>
#include <stdlib.h>

typedef struct Texture {
    unsigned int id;        // OpenGL texture id
    int width;              // Texture base width
    int height;             // Texture base height
    int mipmaps;            // Mipmap levels, 1 by default
    int format;             // Data format (PixelFormat type)
} Texture;
typedef Texture Texture2D;

typedef struct Color {
    unsigned char r;        // Color red value
    unsigned char g;        // Color green value
    unsigned char b;        // Color blue value
    unsigned char a;        // Color alpha value
} Color;

void rp_InitWindow(int width, int height, const char *title);
bool rp_WindowShouldClose(void);
void rp_CloseWindow(void);
void rp_SetTargetFPS(int fps);
void rp_BeginDrawing(void);
void rp_EndDrawing(void);
void rp_DrawFPS(int posX, int posY); 
void rp_ClearBackground(Color* color);
void rp_DrawText(const char *text, int posX, int posY, int fontSize, Color* color);
void rp_DrawTexture(Texture2D* texture, int posX, int posY, Color* tint);
void rp_LoadTexture(Texture2D* ret, const char *fileName);

Color* rp_LIGHTGRAY = &((Color){ 200, 200, 200, 255 });
Color* rp_WHITE = &((Color){ 255, 255, 255, 255 });
Color* rp_RAYWHITE = &((Color){ 245, 245, 245, 255 });

// game starts here

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