// this is the lib interface
// all struct inputs are pointers, all struct-returns are pointers as first param

#include "raylib.h"
#include <memory.h>
#include <stdlib.h>

// TODO: put more in here for wasm, etc
#if defined(_WIN32)
    #if defined(BUILD_LIBTYPE_SHARED)
        #if defined(__TINYC__)
            #define __declspec(x) __attribute__((x))
        #endif
        #define RLP_EXPORT __declspec(dllexport)
    #elif defined(USE_LIBTYPE_SHARED)
        #define RLP_EXPORT __declspec(dllimport)
    #endif
#endif

#ifndef RLP_EXPORT
    #define RLP_EXPORT
#endif

// these are just passed through, so name is the same
RLP_EXPORT void rp_InitWindow(int width, int height, const char *title);
RLP_EXPORT bool rp_WindowShouldClose(void);
RLP_EXPORT void rp_CloseWindow(void);
RLP_EXPORT void rp_SetTargetFPS(int fps);
RLP_EXPORT void rp_BeginDrawing(void);
RLP_EXPORT void rp_EndDrawing(void);
RLP_EXPORT void rp_DrawFPS(int posX, int posY); 

// these use struct-pointers
RLP_EXPORT void rp_ClearBackground(Color* color);
RLP_EXPORT void rp_DrawText(const char *text, int posX, int posY, int fontSize, Color* color);
RLP_EXPORT void rp_DrawTexture(Texture2D* texture, int posX, int posY, Color* tint);
RLP_EXPORT void rp_LoadTexture(Texture2D* ret, const char *fileName);

void rp_InitWindow(int width, int height, const char *title) {
  InitWindow(width, height, title);
}

bool rp_WindowShouldClose(void) {
  return WindowShouldClose();
}

void rp_CloseWindow(void) {
  CloseWindow();
}

void rp_SetTargetFPS(int fps){
  SetTargetFPS(fps);
}

void rp_BeginDrawing(void){
  BeginDrawing();
}

void rp_EndDrawing(void){
  EndDrawing();
}

void rp_DrawFPS(int posX, int posY){
  DrawFPS(posX, posY);
}

void rp_ClearBackground(Color* color) {
  ClearBackground(*color);
}

void rp_DrawText(const char *text, int posX, int posY, int fontSize, Color* color) {
  DrawText(text, posX, posY, fontSize, *color);
}

void rp_DrawTexture(Texture2D* texture, int posX, int posY, Color* tint) {
  DrawTexture(*texture, posX, posY, *tint);
}

void rp_LoadTexture(Texture2D* ret, const char *fileName) {
  Texture2D val = LoadTexture(fileName);
  memcpy(ret, &val, sizeof(Texture2D));
}
