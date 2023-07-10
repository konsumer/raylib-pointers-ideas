// pointer-raylib
// File generated on 2023-07-10T02:29:20.811Z

#ifdef RP_NATIVE
  #include "raylib.h"
#endif // RP_NATIVE

#include <memory.h>
#include <stdlib.h>
#include <stdbool.h>

#ifndef RLP_EXPORT
  #define RLP_EXPORT
#endif

// TODO: not sure how to map these
#ifndef RP_NATIVE
  typedef void rAudioProcessor;
  typedef void rAudioBuffer;
  typedef void* TraceLogCallback;
  typedef void* LoadFileDataCallback;
  typedef void* SaveFileDataCallback;
  typedef void* LoadFileTextCallback;
  typedef void* SaveFileTextCallback;
  typedef void* AudioCallback;



/*
 * Vector2, 2 components
 */
typedef struct Vector2 {
  float x; // Vector x component
  float y; // Vector y component
} Vector2;

/*
 * Vector3, 3 components
 */
typedef struct Vector3 {
  float x; // Vector x component
  float y; // Vector y component
  float z; // Vector z component
} Vector3;

/*
 * Vector4, 4 components
 */
typedef struct Vector4 {
  float x; // Vector x component
  float y; // Vector y component
  float z; // Vector z component
  float w; // Vector w component
} Vector4;

// Quaternion, 4 components (Vector4 alias)
typedef Vector4 Quaternion;

/*
 * Matrix, 4x4 components, column major, OpenGL style, right-handed
 */
typedef struct Matrix {
  float m0; // Matrix first row (4 components)
  float m4; // Matrix first row (4 components)
  float m8; // Matrix first row (4 components)
  float m12; // Matrix first row (4 components)
  float m1; // Matrix second row (4 components)
  float m5; // Matrix second row (4 components)
  float m9; // Matrix second row (4 components)
  float m13; // Matrix second row (4 components)
  float m2; // Matrix third row (4 components)
  float m6; // Matrix third row (4 components)
  float m10; // Matrix third row (4 components)
  float m14; // Matrix third row (4 components)
  float m3; // Matrix fourth row (4 components)
  float m7; // Matrix fourth row (4 components)
  float m11; // Matrix fourth row (4 components)
  float m15; // Matrix fourth row (4 components)
} Matrix;

/*
 * Color, 4 components, R8G8B8A8 (32bit)
 */
typedef struct Color {
  unsigned char r; // Color red value
  unsigned char g; // Color green value
  unsigned char b; // Color blue value
  unsigned char a; // Color alpha value
} Color;

/*
 * Rectangle, 4 components
 */
typedef struct Rectangle {
  float x; // Rectangle top-left corner position x
  float y; // Rectangle top-left corner position y
  float width; // Rectangle width
  float height; // Rectangle height
} Rectangle;

/*
 * Image, pixel data stored in CPU memory (RAM)
 */
typedef struct Image {
  void * data; // Image raw data
  int width; // Image base width
  int height; // Image base height
  int mipmaps; // Mipmap levels, 1 by default
  int format; // Data format (PixelFormat type)
} Image;

/*
 * Texture, tex data stored in GPU memory (VRAM)
 */
typedef struct Texture {
  unsigned int id; // OpenGL texture id
  int width; // Texture base width
  int height; // Texture base height
  int mipmaps; // Mipmap levels, 1 by default
  int format; // Data format (PixelFormat type)
} Texture;

// Texture2D, same as Texture
typedef Texture Texture2D;

// TextureCubemap, same as Texture
typedef Texture TextureCubemap;

/*
 * RenderTexture, fbo for texture rendering
 */
typedef struct RenderTexture {
  unsigned int id; // OpenGL framebuffer object id
  Texture texture; // Color buffer attachment texture
  Texture depth; // Depth buffer attachment texture
} RenderTexture;

// RenderTexture2D, same as RenderTexture
typedef RenderTexture RenderTexture2D;

/*
 * NPatchInfo, n-patch layout info
 */
typedef struct NPatchInfo {
  Rectangle source; // Texture source rectangle
  int left; // Left border offset
  int top; // Top border offset
  int right; // Right border offset
  int bottom; // Bottom border offset
  int layout; // Layout of the n-patch: 3x3, 1x3 or 3x1
} NPatchInfo;

/*
 * GlyphInfo, font characters glyphs info
 */
typedef struct GlyphInfo {
  int value; // Character value (Unicode)
  int offsetX; // Character offset X when drawing
  int offsetY; // Character offset Y when drawing
  int advanceX; // Character advance position X
  Image image; // Character image data
} GlyphInfo;

/*
 * Font, font texture and GlyphInfo array data
 */
typedef struct Font {
  int baseSize; // Base size (default chars height)
  int glyphCount; // Number of glyph characters
  int glyphPadding; // Padding around the glyph characters
  Texture2D texture; // Texture atlas containing the glyphs
  Rectangle * recs; // Rectangles in texture for the glyphs
  GlyphInfo * glyphs; // Glyphs info data
} Font;

/*
 * Camera, defines position/orientation in 3d space
 */
typedef struct Camera3D {
  Vector3 position; // Camera position
  Vector3 target; // Camera target it looks-at
  Vector3 up; // Camera up vector (rotation over its axis)
  float fovy; // Camera field-of-view aperture in Y (degrees) in perspective, used as near plane width in orthographic
  int projection; // Camera projection: CAMERA_PERSPECTIVE or CAMERA_ORTHOGRAPHIC
} Camera3D;

// Camera type fallback, defaults to Camera3D
typedef Camera3D Camera;

/*
 * Camera2D, defines position/orientation in 2d space
 */
typedef struct Camera2D {
  Vector2 offset; // Camera offset (displacement from target)
  Vector2 target; // Camera target (rotation and zoom origin)
  float rotation; // Camera rotation in degrees
  float zoom; // Camera zoom (scaling), should be 1.0f by default
} Camera2D;

/*
 * Mesh, vertex data and vao/vbo
 */
typedef struct Mesh {
  int vertexCount; // Number of vertices stored in arrays
  int triangleCount; // Number of triangles stored (indexed or not)
  float * vertices; // Vertex position (XYZ - 3 components per vertex) (shader-location = 0)
  float * texcoords; // Vertex texture coordinates (UV - 2 components per vertex) (shader-location = 1)
  float * texcoords2; // Vertex texture second coordinates (UV - 2 components per vertex) (shader-location = 5)
  float * normals; // Vertex normals (XYZ - 3 components per vertex) (shader-location = 2)
  float * tangents; // Vertex tangents (XYZW - 4 components per vertex) (shader-location = 4)
  unsigned char * colors; // Vertex colors (RGBA - 4 components per vertex) (shader-location = 3)
  unsigned short * indices; // Vertex indices (in case vertex data comes indexed)
  float * animVertices; // Animated vertex positions (after bones transformations)
  float * animNormals; // Animated normals (after bones transformations)
  unsigned char * boneIds; // Vertex bone ids, max 255 bone ids, up to 4 bones influence by vertex (skinning)
  float * boneWeights; // Vertex bone weight, up to 4 bones influence by vertex (skinning)
  unsigned int vaoId; // OpenGL Vertex Array Object id
  unsigned int * vboId; // OpenGL Vertex Buffer Objects id (default vertex data)
} Mesh;

/*
 * Shader
 */
typedef struct Shader {
  unsigned int id; // Shader program id
  int * locs; // Shader locations array (RL_MAX_SHADER_LOCATIONS)
} Shader;

/*
 * MaterialMap
 */
typedef struct MaterialMap {
  Texture2D texture; // Material map texture
  Color color; // Material map color
  float value; // Material map value
} MaterialMap;

/*
 * Material, includes shader and maps
 */
typedef struct Material {
  Shader shader; // Material shader
  MaterialMap * maps; // Material maps array (MAX_MATERIAL_MAPS)
  float params[4]; // Material generic parameters (if required)
} Material;

/*
 * Transform, vertex transformation data
 */
typedef struct Transform {
  Vector3 translation; // Translation
  Quaternion rotation; // Rotation
  Vector3 scale; // Scale
} Transform;

/*
 * Bone, skeletal animation bone
 */
typedef struct BoneInfo {
  char name[32]; // Bone name
  int parent; // Bone parent
} BoneInfo;

/*
 * Model, meshes, materials and animation data
 */
typedef struct Model {
  Matrix transform; // Local transform matrix
  int meshCount; // Number of meshes
  int materialCount; // Number of materials
  Mesh * meshes; // Meshes array
  Material * materials; // Materials array
  int * meshMaterial; // Mesh material number
  int boneCount; // Number of bones
  BoneInfo * bones; // Bones information (skeleton)
  Transform * bindPose; // Bones base transformation (pose)
} Model;

/*
 * ModelAnimation
 */
typedef struct ModelAnimation {
  int boneCount; // Number of bones
  int frameCount; // Number of animation frames
  BoneInfo * bones; // Bones information (skeleton)
  Transform ** framePoses; // Poses array by frame
} ModelAnimation;

/*
 * Ray, ray for raycasting
 */
typedef struct Ray {
  Vector3 position; // Ray position (origin)
  Vector3 direction; // Ray direction
} Ray;

/*
 * RayCollision, ray hit information
 */
typedef struct RayCollision {
  bool hit; // Did the ray hit something?
  float distance; // Distance to the nearest hit
  Vector3 point; // Point of the nearest hit
  Vector3 normal; // Surface normal of hit
} RayCollision;

/*
 * BoundingBox
 */
typedef struct BoundingBox {
  Vector3 min; // Minimum vertex box-corner
  Vector3 max; // Maximum vertex box-corner
} BoundingBox;

/*
 * Wave, audio wave data
 */
typedef struct Wave {
  unsigned int frameCount; // Total number of frames (considering channels)
  unsigned int sampleRate; // Frequency (samples per second)
  unsigned int sampleSize; // Bit depth (bits per sample): 8, 16, 32 (24 not supported)
  unsigned int channels; // Number of channels (1-mono, 2-stereo, ...)
  void * data; // Buffer data pointer
} Wave;

/*
 * AudioStream, custom audio stream
 */
typedef struct AudioStream {
  rAudioBuffer * buffer; // Pointer to internal data used by the audio system
  rAudioProcessor * processor; // Pointer to internal data processor, useful for audio effects
  unsigned int sampleRate; // Frequency (samples per second)
  unsigned int sampleSize; // Bit depth (bits per sample): 8, 16, 32 (24 not supported)
  unsigned int channels; // Number of channels (1-mono, 2-stereo, ...)
} AudioStream;

/*
 * Sound
 */
typedef struct Sound {
  AudioStream stream; // Audio stream
  unsigned int frameCount; // Total number of frames (considering channels)
} Sound;

/*
 * Music, audio stream, anything longer than ~10 seconds should be streamed
 */
typedef struct Music {
  AudioStream stream; // Audio stream
  unsigned int frameCount; // Total number of frames (considering channels)
  bool looping; // Music looping enable
  int ctxType; // Type of music context (audio filetype)
  void * ctxData; // Audio context data, depends on type
} Music;

/*
 * VrDeviceInfo, Head-Mounted-Display device parameters
 */
typedef struct VrDeviceInfo {
  int hResolution; // Horizontal resolution in pixels
  int vResolution; // Vertical resolution in pixels
  float hScreenSize; // Horizontal size in meters
  float vScreenSize; // Vertical size in meters
  float vScreenCenter; // Screen center in meters
  float eyeToScreenDistance; // Distance between eye and display in meters
  float lensSeparationDistance; // Lens separation distance in meters
  float interpupillaryDistance; // IPD (distance between pupils) in meters
  float lensDistortionValues[4]; // Lens distortion constant parameters
  float chromaAbCorrection[4]; // Chromatic aberration correction parameters
} VrDeviceInfo;

/*
 * VrStereoConfig, VR stereo rendering configuration for simulator
 */
typedef struct VrStereoConfig {
  Matrix projection[2]; // VR projection matrices (per eye)
  Matrix viewOffset[2]; // VR view offset matrices (per eye)
  float leftLensCenter[2]; // VR left lens center
  float rightLensCenter[2]; // VR right lens center
  float leftScreenCenter[2]; // VR left screen center
  float rightScreenCenter[2]; // VR right screen center
  float scale[2]; // VR distortion scale
  float scaleIn[2]; // VR distortion scale in
} VrStereoConfig;

/*
 * File path list
 */
typedef struct FilePathList {
  unsigned int capacity; // Filepaths max entries
  unsigned int count; // Filepaths entries count
  char ** paths; // Filepaths entries
} FilePathList;

Color * rp_LIGHTGRAY = &((Color) { 200, 200, 200, 255 }); // Light Gray
Color * rp_GRAY = &((Color) { 130, 130, 130, 255 }); // Gray
Color * rp_DARKGRAY = &((Color) { 80, 80, 80, 255 }); // Dark Gray
Color * rp_YELLOW = &((Color) { 253, 249, 0, 255 }); // Yellow
Color * rp_GOLD = &((Color) { 255, 203, 0, 255 }); // Gold
Color * rp_ORANGE = &((Color) { 255, 161, 0, 255 }); // Orange
Color * rp_PINK = &((Color) { 255, 109, 194, 255 }); // Pink
Color * rp_RED = &((Color) { 230, 41, 55, 255 }); // Red
Color * rp_MAROON = &((Color) { 190, 33, 55, 255 }); // Maroon
Color * rp_GREEN = &((Color) { 0, 228, 48, 255 }); // Green
Color * rp_LIME = &((Color) { 0, 158, 47, 255 }); // Lime
Color * rp_DARKGREEN = &((Color) { 0, 117, 44, 255 }); // Dark Green
Color * rp_SKYBLUE = &((Color) { 102, 191, 255, 255 }); // Sky Blue
Color * rp_BLUE = &((Color) { 0, 121, 241, 255 }); // Blue
Color * rp_DARKBLUE = &((Color) { 0, 82, 172, 255 }); // Dark Blue
Color * rp_PURPLE = &((Color) { 200, 122, 255, 255 }); // Purple
Color * rp_VIOLET = &((Color) { 135, 60, 190, 255 }); // Violet
Color * rp_DARKPURPLE = &((Color) { 112, 31, 126, 255 }); // Dark Purple
Color * rp_BEIGE = &((Color) { 211, 176, 131, 255 }); // Beige
Color * rp_BROWN = &((Color) { 127, 106, 79, 255 }); // Brown
Color * rp_DARKBROWN = &((Color) { 76, 63, 47, 255 }); // Dark Brown
Color * rp_WHITE = &((Color) { 255, 255, 255, 255 }); // White
Color * rp_BLACK = &((Color) { 0, 0, 0, 255 }); // Black
Color * rp_BLANK = &((Color) { 0, 0, 0, 0 }); // Blank (Transparent)
Color * rp_MAGENTA = &((Color) { 255, 0, 255, 255 }); // Magenta
Color * rp_RAYWHITE = &((Color) { 245, 245, 245, 255 }); // My own White (raylib logo)
#endif // RP_NATIVE

/**
 * Initialize window and OpenGL context
 */
RLP_EXPORT void rp_InitWindow(int width, int height, const char * title);

/**
 * Check if KEY_ESCAPE pressed or Close icon pressed
 */
RLP_EXPORT bool rp_WindowShouldClose();

/**
 * Close window and unload OpenGL context
 */
RLP_EXPORT void rp_CloseWindow();

/**
 * Check if window has been initialized successfully
 */
RLP_EXPORT bool rp_IsWindowReady();

/**
 * Check if window is currently fullscreen
 */
RLP_EXPORT bool rp_IsWindowFullscreen();

/**
 * Check if window is currently hidden (only PLATFORM_DESKTOP)
 */
RLP_EXPORT bool rp_IsWindowHidden();

/**
 * Check if window is currently minimized (only PLATFORM_DESKTOP)
 */
RLP_EXPORT bool rp_IsWindowMinimized();

/**
 * Check if window is currently maximized (only PLATFORM_DESKTOP)
 */
RLP_EXPORT bool rp_IsWindowMaximized();

/**
 * Check if window is currently focused (only PLATFORM_DESKTOP)
 */
RLP_EXPORT bool rp_IsWindowFocused();

/**
 * Check if window has been resized last frame
 */
RLP_EXPORT bool rp_IsWindowResized();

/**
 * Check if one specific window flag is enabled
 */
RLP_EXPORT bool rp_IsWindowState(unsigned int flag);

/**
 * Set window configuration state using flags (only PLATFORM_DESKTOP)
 */
RLP_EXPORT void rp_SetWindowState(unsigned int flags);

/**
 * Clear window configuration state flags
 */
RLP_EXPORT void rp_ClearWindowState(unsigned int flags);

/**
 * Toggle window state: fullscreen/windowed (only PLATFORM_DESKTOP)
 */
RLP_EXPORT void rp_ToggleFullscreen();

/**
 * Set window state: maximized, if resizable (only PLATFORM_DESKTOP)
 */
RLP_EXPORT void rp_MaximizeWindow();

/**
 * Set window state: minimized, if resizable (only PLATFORM_DESKTOP)
 */
RLP_EXPORT void rp_MinimizeWindow();

/**
 * Set window state: not minimized/maximized (only PLATFORM_DESKTOP)
 */
RLP_EXPORT void rp_RestoreWindow();

/**
 * Set icon for window (single image, RGBA 32bit, only PLATFORM_DESKTOP)
 */
RLP_EXPORT void rp_SetWindowIcon(Image* image);

/**
 * Set icon for window (multiple images, RGBA 32bit, only PLATFORM_DESKTOP)
 */
RLP_EXPORT void rp_SetWindowIcons(Image * images, int count);

/**
 * Set title for window (only PLATFORM_DESKTOP)
 */
RLP_EXPORT void rp_SetWindowTitle(const char * title);

/**
 * Set window position on screen (only PLATFORM_DESKTOP)
 */
RLP_EXPORT void rp_SetWindowPosition(int x, int y);

/**
 * Set monitor for the current window (fullscreen mode)
 */
RLP_EXPORT void rp_SetWindowMonitor(int monitor);

/**
 * Set window minimum dimensions (for FLAG_WINDOW_RESIZABLE)
 */
RLP_EXPORT void rp_SetWindowMinSize(int width, int height);

/**
 * Set window dimensions
 */
RLP_EXPORT void rp_SetWindowSize(int width, int height);

/**
 * Set window opacity [0.0f..1.0f] (only PLATFORM_DESKTOP)
 */
RLP_EXPORT void rp_SetWindowOpacity(float opacity);

/**
 * Get native window handle
 */
RLP_EXPORT void * rp_GetWindowHandle();

/**
 * Get current screen width
 */
RLP_EXPORT int rp_GetScreenWidth();

/**
 * Get current screen height
 */
RLP_EXPORT int rp_GetScreenHeight();

/**
 * Get current render width (it considers HiDPI)
 */
RLP_EXPORT int rp_GetRenderWidth();

/**
 * Get current render height (it considers HiDPI)
 */
RLP_EXPORT int rp_GetRenderHeight();

/**
 * Get number of connected monitors
 */
RLP_EXPORT int rp_GetMonitorCount();

/**
 * Get current connected monitor
 */
RLP_EXPORT int rp_GetCurrentMonitor();

/**
 * Get specified monitor position
 */
RLP_EXPORT void rp_GetMonitorPosition(Vector2* output, int monitor);

/**
 * Get specified monitor width (current video mode used by monitor)
 */
RLP_EXPORT int rp_GetMonitorWidth(int monitor);

/**
 * Get specified monitor height (current video mode used by monitor)
 */
RLP_EXPORT int rp_GetMonitorHeight(int monitor);

/**
 * Get specified monitor physical width in millimetres
 */
RLP_EXPORT int rp_GetMonitorPhysicalWidth(int monitor);

/**
 * Get specified monitor physical height in millimetres
 */
RLP_EXPORT int rp_GetMonitorPhysicalHeight(int monitor);

/**
 * Get specified monitor refresh rate
 */
RLP_EXPORT int rp_GetMonitorRefreshRate(int monitor);

/**
 * Get window position XY on monitor
 */
RLP_EXPORT void rp_GetWindowPosition(Vector2* output);

/**
 * Get window scale DPI factor
 */
RLP_EXPORT void rp_GetWindowScaleDPI(Vector2* output);

/**
 * Get the human-readable, UTF-8 encoded name of the primary monitor
 */
RLP_EXPORT const char * rp_GetMonitorName(int monitor);

/**
 * Set clipboard text content
 */
RLP_EXPORT void rp_SetClipboardText(const char * text);

/**
 * Get clipboard text content
 */
RLP_EXPORT const char * rp_GetClipboardText();

/**
 * Enable waiting for events on EndDrawing(), no automatic event polling
 */
RLP_EXPORT void rp_EnableEventWaiting();

/**
 * Disable waiting for events on EndDrawing(), automatic events polling
 */
RLP_EXPORT void rp_DisableEventWaiting();

/**
 * Swap back buffer with front buffer (screen drawing)
 */
RLP_EXPORT void rp_SwapScreenBuffer();

/**
 * Register all input events
 */
RLP_EXPORT void rp_PollInputEvents();

/**
 * Wait for some time (halt program execution)
 */
RLP_EXPORT void rp_WaitTime(double seconds);

/**
 * Shows cursor
 */
RLP_EXPORT void rp_ShowCursor();

/**
 * Hides cursor
 */
RLP_EXPORT void rp_HideCursor();

/**
 * Check if cursor is not visible
 */
RLP_EXPORT bool rp_IsCursorHidden();

/**
 * Enables cursor (unlock cursor)
 */
RLP_EXPORT void rp_EnableCursor();

/**
 * Disables cursor (lock cursor)
 */
RLP_EXPORT void rp_DisableCursor();

/**
 * Check if cursor is on the screen
 */
RLP_EXPORT bool rp_IsCursorOnScreen();

/**
 * Set background color (framebuffer clear color)
 */
RLP_EXPORT void rp_ClearBackground(Color* color);

/**
 * Setup canvas (framebuffer) to start drawing
 */
RLP_EXPORT void rp_BeginDrawing();

/**
 * End canvas drawing and swap buffers (double buffering)
 */
RLP_EXPORT void rp_EndDrawing();

/**
 * Begin 2D mode with custom camera (2D)
 */
RLP_EXPORT void rp_BeginMode2D(Camera2D* camera);

/**
 * Ends 2D mode with custom camera
 */
RLP_EXPORT void rp_EndMode2D();

/**
 * Begin 3D mode with custom camera (3D)
 */
RLP_EXPORT void rp_BeginMode3D(Camera3D* camera);

/**
 * Ends 3D mode and returns to default 2D orthographic mode
 */
RLP_EXPORT void rp_EndMode3D();

/**
 * Begin drawing to render texture
 */
RLP_EXPORT void rp_BeginTextureMode(RenderTexture2D* target);

/**
 * Ends drawing to render texture
 */
RLP_EXPORT void rp_EndTextureMode();

/**
 * Begin custom shader drawing
 */
RLP_EXPORT void rp_BeginShaderMode(Shader* shader);

/**
 * End custom shader drawing (use default shader)
 */
RLP_EXPORT void rp_EndShaderMode();

/**
 * Begin blending mode (alpha, additive, multiplied, subtract, custom)
 */
RLP_EXPORT void rp_BeginBlendMode(int mode);

/**
 * End blending mode (reset to default: alpha blending)
 */
RLP_EXPORT void rp_EndBlendMode();

/**
 * Begin scissor mode (define screen area for following drawing)
 */
RLP_EXPORT void rp_BeginScissorMode(int x, int y, int width, int height);

/**
 * End scissor mode
 */
RLP_EXPORT void rp_EndScissorMode();

/**
 * Begin stereo rendering (requires VR simulator)
 */
RLP_EXPORT void rp_BeginVrStereoMode(VrStereoConfig* config);

/**
 * End stereo rendering (requires VR simulator)
 */
RLP_EXPORT void rp_EndVrStereoMode();

/**
 * Load VR stereo config for VR simulator device parameters
 */
RLP_EXPORT void rp_LoadVrStereoConfig(VrStereoConfig* output, VrDeviceInfo* device);

/**
 * Unload VR stereo config
 */
RLP_EXPORT void rp_UnloadVrStereoConfig(VrStereoConfig* config);

/**
 * Load shader from files and bind default locations
 */
RLP_EXPORT void rp_LoadShader(Shader* output, const char * vsFileName, const char * fsFileName);

/**
 * Load shader from code strings and bind default locations
 */
RLP_EXPORT void rp_LoadShaderFromMemory(Shader* output, const char * vsCode, const char * fsCode);

/**
 * Check if a shader is ready
 */
RLP_EXPORT bool rp_IsShaderReady(Shader* shader);

/**
 * Get shader uniform location
 */
RLP_EXPORT int rp_GetShaderLocation(Shader* shader, const char * uniformName);

/**
 * Get shader attribute location
 */
RLP_EXPORT int rp_GetShaderLocationAttrib(Shader* shader, const char * attribName);

/**
 * Set shader uniform value
 */
RLP_EXPORT void rp_SetShaderValue(Shader* shader, int locIndex, const void * value, int uniformType);

/**
 * Set shader uniform value vector
 */
RLP_EXPORT void rp_SetShaderValueV(Shader* shader, int locIndex, const void * value, int uniformType, int count);

/**
 * Set shader uniform value (matrix 4x4)
 */
RLP_EXPORT void rp_SetShaderValueMatrix(Shader* shader, int locIndex, Matrix* mat);

/**
 * Set shader uniform value for texture (sampler2d)
 */
RLP_EXPORT void rp_SetShaderValueTexture(Shader* shader, int locIndex, Texture2D* texture);

/**
 * Unload shader from GPU memory (VRAM)
 */
RLP_EXPORT void rp_UnloadShader(Shader* shader);

/**
 * Get a ray trace from mouse position
 */
RLP_EXPORT void rp_GetMouseRay(Ray* output, Vector2* mousePosition, Camera* camera);

/**
 * Get camera transform matrix (view matrix)
 */
RLP_EXPORT void rp_GetCameraMatrix(Matrix* output, Camera* camera);

/**
 * Get camera 2d transform matrix
 */
RLP_EXPORT void rp_GetCameraMatrix2D(Matrix* output, Camera2D* camera);

/**
 * Get the screen space position for a 3d world space position
 */
RLP_EXPORT void rp_GetWorldToScreen(Vector2* output, Vector3* position, Camera* camera);

/**
 * Get the world space position for a 2d camera screen space position
 */
RLP_EXPORT void rp_GetScreenToWorld2D(Vector2* output, Vector2* position, Camera2D* camera);

/**
 * Get size position for a 3d world space position
 */
RLP_EXPORT void rp_GetWorldToScreenEx(Vector2* output, Vector3* position, Camera* camera, int width, int height);

/**
 * Get the screen space position for a 2d camera world space position
 */
RLP_EXPORT void rp_GetWorldToScreen2D(Vector2* output, Vector2* position, Camera2D* camera);

/**
 * Set target FPS (maximum)
 */
RLP_EXPORT void rp_SetTargetFPS(int fps);

/**
 * Get current FPS
 */
RLP_EXPORT int rp_GetFPS();

/**
 * Get time in seconds for last frame drawn (delta time)
 */
RLP_EXPORT float rp_GetFrameTime();

/**
 * Get elapsed time in seconds since InitWindow()
 */
RLP_EXPORT double rp_GetTime();

/**
 * Get a random value between min and max (both included)
 */
RLP_EXPORT int rp_GetRandomValue(int min, int max);

/**
 * Set the seed for the random number generator
 */
RLP_EXPORT void rp_SetRandomSeed(unsigned int seed);

/**
 * Takes a screenshot of current screen (filename extension defines format)
 */
RLP_EXPORT void rp_TakeScreenshot(const char * fileName);

/**
 * Setup init configuration flags (view FLAGS)
 */
RLP_EXPORT void rp_SetConfigFlags(unsigned int flags);

/**
 * Show trace log messages (LOG_DEBUG, LOG_INFO, LOG_WARNING, LOG_ERROR...)
 */
RLP_EXPORT void rp_TraceLog(int logLevel, const char * text, char* args);

/**
 * Set the current threshold (minimum) log level
 */
RLP_EXPORT void rp_SetTraceLogLevel(int logLevel);

/**
 * Internal memory allocator
 */
RLP_EXPORT void * rp_MemAlloc(unsigned int size);

/**
 * Internal memory reallocator
 */
RLP_EXPORT void * rp_MemRealloc(void * ptr, unsigned int size);

/**
 * Internal memory free
 */
RLP_EXPORT void rp_MemFree(void * ptr);

/**
 * Open URL with default system browser (if available)
 */
RLP_EXPORT void rp_OpenURL(const char * url);

/**
 * Set custom trace log
 */
RLP_EXPORT void rp_SetTraceLogCallback(TraceLogCallback callback);

/**
 * Set custom file binary data loader
 */
RLP_EXPORT void rp_SetLoadFileDataCallback(LoadFileDataCallback callback);

/**
 * Set custom file binary data saver
 */
RLP_EXPORT void rp_SetSaveFileDataCallback(SaveFileDataCallback callback);

/**
 * Set custom file text data loader
 */
RLP_EXPORT void rp_SetLoadFileTextCallback(LoadFileTextCallback callback);

/**
 * Set custom file text data saver
 */
RLP_EXPORT void rp_SetSaveFileTextCallback(SaveFileTextCallback callback);

/**
 * Load file data as byte array (read)
 */
RLP_EXPORT unsigned char * rp_LoadFileData(const char * fileName, unsigned int * bytesRead);

/**
 * Unload file data allocated by LoadFileData()
 */
RLP_EXPORT void rp_UnloadFileData(unsigned char * data);

/**
 * Save data to file from byte array (write), returns true on success
 */
RLP_EXPORT bool rp_SaveFileData(const char * fileName, void * data, unsigned int bytesToWrite);

/**
 * Export data to code (.h), returns true on success
 */
RLP_EXPORT bool rp_ExportDataAsCode(const unsigned char * data, unsigned int size, const char * fileName);

/**
 * Load text data from file (read), returns a '\0' terminated string
 */
RLP_EXPORT char * rp_LoadFileText(const char * fileName);

/**
 * Unload file text data allocated by LoadFileText()
 */
RLP_EXPORT void rp_UnloadFileText(char * text);

/**
 * Save text data to file (write), string must be '\0' terminated, returns true on success
 */
RLP_EXPORT bool rp_SaveFileText(const char * fileName, char * text);

/**
 * Check if file exists
 */
RLP_EXPORT bool rp_FileExists(const char * fileName);

/**
 * Check if a directory path exists
 */
RLP_EXPORT bool rp_DirectoryExists(const char * dirPath);

/**
 * Check file extension (including point: .png, .wav)
 */
RLP_EXPORT bool rp_IsFileExtension(const char * fileName, const char * ext);

/**
 * Get file length in bytes (NOTE: GetFileSize() conflicts with windows.h)
 */
RLP_EXPORT int rp_GetFileLength(const char * fileName);

/**
 * Get pointer to extension for a filename string (includes dot: '.png')
 */
RLP_EXPORT const char * rp_GetFileExtension(const char * fileName);

/**
 * Get pointer to filename for a path string
 */
RLP_EXPORT const char * rp_GetFileName(const char * filePath);

/**
 * Get filename string without extension (uses static string)
 */
RLP_EXPORT const char * rp_GetFileNameWithoutExt(const char * filePath);

/**
 * Get full path for a given fileName with path (uses static string)
 */
RLP_EXPORT const char * rp_GetDirectoryPath(const char * filePath);

/**
 * Get previous directory path for a given path (uses static string)
 */
RLP_EXPORT const char * rp_GetPrevDirectoryPath(const char * dirPath);

/**
 * Get current working directory (uses static string)
 */
RLP_EXPORT const char * rp_GetWorkingDirectory();

/**
 * Get the directory if the running application (uses static string)
 */
RLP_EXPORT const char * rp_GetApplicationDirectory();

/**
 * Change working directory, return true on success
 */
RLP_EXPORT bool rp_ChangeDirectory(const char * dir);

/**
 * Check if a given path is a file or a directory
 */
RLP_EXPORT bool rp_IsPathFile(const char * path);

/**
 * Load directory filepaths
 */
RLP_EXPORT void rp_LoadDirectoryFiles(FilePathList* output, const char * dirPath);

/**
 * Load directory filepaths with extension filtering and recursive directory scan
 */
RLP_EXPORT void rp_LoadDirectoryFilesEx(FilePathList* output, const char * basePath, const char * filter, bool scanSubdirs);

/**
 * Unload filepaths
 */
RLP_EXPORT void rp_UnloadDirectoryFiles(FilePathList* files);

/**
 * Check if a file has been dropped into window
 */
RLP_EXPORT bool rp_IsFileDropped();

/**
 * Load dropped filepaths
 */
RLP_EXPORT void rp_LoadDroppedFiles(FilePathList* output);

/**
 * Unload dropped filepaths
 */
RLP_EXPORT void rp_UnloadDroppedFiles(FilePathList* files);

/**
 * Get file modification time (last write time)
 */
RLP_EXPORT long rp_GetFileModTime(const char * fileName);

/**
 * Compress data (DEFLATE algorithm), memory must be MemFree()
 */
RLP_EXPORT unsigned char * rp_CompressData(const unsigned char * data, int dataSize, int * compDataSize);

/**
 * Decompress data (DEFLATE algorithm), memory must be MemFree()
 */
RLP_EXPORT unsigned char * rp_DecompressData(const unsigned char * compData, int compDataSize, int * dataSize);

/**
 * Encode data to Base64 string, memory must be MemFree()
 */
RLP_EXPORT char * rp_EncodeDataBase64(const unsigned char * data, int dataSize, int * outputSize);

/**
 * Decode Base64 string data, memory must be MemFree()
 */
RLP_EXPORT unsigned char * rp_DecodeDataBase64(const unsigned char * data, int * outputSize);

/**
 * Check if a key has been pressed once
 */
RLP_EXPORT bool rp_IsKeyPressed(int key);

/**
 * Check if a key is being pressed
 */
RLP_EXPORT bool rp_IsKeyDown(int key);

/**
 * Check if a key has been released once
 */
RLP_EXPORT bool rp_IsKeyReleased(int key);

/**
 * Check if a key is NOT being pressed
 */
RLP_EXPORT bool rp_IsKeyUp(int key);

/**
 * Set a custom key to exit program (default is ESC)
 */
RLP_EXPORT void rp_SetExitKey(int key);

/**
 * Get key pressed (keycode), call it multiple times for keys queued, returns 0 when the queue is empty
 */
RLP_EXPORT int rp_GetKeyPressed();

/**
 * Get char pressed (unicode), call it multiple times for chars queued, returns 0 when the queue is empty
 */
RLP_EXPORT int rp_GetCharPressed();

/**
 * Check if a gamepad is available
 */
RLP_EXPORT bool rp_IsGamepadAvailable(int gamepad);

/**
 * Get gamepad internal name id
 */
RLP_EXPORT const char * rp_GetGamepadName(int gamepad);

/**
 * Check if a gamepad button has been pressed once
 */
RLP_EXPORT bool rp_IsGamepadButtonPressed(int gamepad, int button);

/**
 * Check if a gamepad button is being pressed
 */
RLP_EXPORT bool rp_IsGamepadButtonDown(int gamepad, int button);

/**
 * Check if a gamepad button has been released once
 */
RLP_EXPORT bool rp_IsGamepadButtonReleased(int gamepad, int button);

/**
 * Check if a gamepad button is NOT being pressed
 */
RLP_EXPORT bool rp_IsGamepadButtonUp(int gamepad, int button);

/**
 * Get the last gamepad button pressed
 */
RLP_EXPORT int rp_GetGamepadButtonPressed();

/**
 * Get gamepad axis count for a gamepad
 */
RLP_EXPORT int rp_GetGamepadAxisCount(int gamepad);

/**
 * Get axis movement value for a gamepad axis
 */
RLP_EXPORT float rp_GetGamepadAxisMovement(int gamepad, int axis);

/**
 * Set internal gamepad mappings (SDL_GameControllerDB)
 */
RLP_EXPORT int rp_SetGamepadMappings(const char * mappings);

/**
 * Check if a mouse button has been pressed once
 */
RLP_EXPORT bool rp_IsMouseButtonPressed(int button);

/**
 * Check if a mouse button is being pressed
 */
RLP_EXPORT bool rp_IsMouseButtonDown(int button);

/**
 * Check if a mouse button has been released once
 */
RLP_EXPORT bool rp_IsMouseButtonReleased(int button);

/**
 * Check if a mouse button is NOT being pressed
 */
RLP_EXPORT bool rp_IsMouseButtonUp(int button);

/**
 * Get mouse position X
 */
RLP_EXPORT int rp_GetMouseX();

/**
 * Get mouse position Y
 */
RLP_EXPORT int rp_GetMouseY();

/**
 * Get mouse position XY
 */
RLP_EXPORT void rp_GetMousePosition(Vector2* output);

/**
 * Get mouse delta between frames
 */
RLP_EXPORT void rp_GetMouseDelta(Vector2* output);

/**
 * Set mouse position XY
 */
RLP_EXPORT void rp_SetMousePosition(int x, int y);

/**
 * Set mouse offset
 */
RLP_EXPORT void rp_SetMouseOffset(int offsetX, int offsetY);

/**
 * Set mouse scaling
 */
RLP_EXPORT void rp_SetMouseScale(float scaleX, float scaleY);

/**
 * Get mouse wheel movement for X or Y, whichever is larger
 */
RLP_EXPORT float rp_GetMouseWheelMove();

/**
 * Get mouse wheel movement for both X and Y
 */
RLP_EXPORT void rp_GetMouseWheelMoveV(Vector2* output);

/**
 * Set mouse cursor
 */
RLP_EXPORT void rp_SetMouseCursor(int cursor);

/**
 * Get touch position X for touch point 0 (relative to screen size)
 */
RLP_EXPORT int rp_GetTouchX();

/**
 * Get touch position Y for touch point 0 (relative to screen size)
 */
RLP_EXPORT int rp_GetTouchY();

/**
 * Get touch position XY for a touch point index (relative to screen size)
 */
RLP_EXPORT void rp_GetTouchPosition(Vector2* output, int index);

/**
 * Get touch point identifier for given index
 */
RLP_EXPORT int rp_GetTouchPointId(int index);

/**
 * Get number of touch points
 */
RLP_EXPORT int rp_GetTouchPointCount();

/**
 * Enable a set of gestures using flags
 */
RLP_EXPORT void rp_SetGesturesEnabled(unsigned int flags);

/**
 * Check if a gesture have been detected
 */
RLP_EXPORT bool rp_IsGestureDetected(int gesture);

/**
 * Get latest detected gesture
 */
RLP_EXPORT int rp_GetGestureDetected();

/**
 * Get gesture hold time in milliseconds
 */
RLP_EXPORT float rp_GetGestureHoldDuration();

/**
 * Get gesture drag vector
 */
RLP_EXPORT void rp_GetGestureDragVector(Vector2* output);

/**
 * Get gesture drag angle
 */
RLP_EXPORT float rp_GetGestureDragAngle();

/**
 * Get gesture pinch delta
 */
RLP_EXPORT void rp_GetGesturePinchVector(Vector2* output);

/**
 * Get gesture pinch angle
 */
RLP_EXPORT float rp_GetGesturePinchAngle();

/**
 * Update camera position for selected mode
 */
RLP_EXPORT void rp_UpdateCamera(Camera * camera, int mode);

/**
 * Update camera movement/rotation
 */
RLP_EXPORT void rp_UpdateCameraPro(Camera * camera, Vector3* movement, Vector3* rotation, float zoom);

/**
 * Set texture and rectangle to be used on shapes drawing
 */
RLP_EXPORT void rp_SetShapesTexture(Texture2D* texture, Rectangle* source);

/**
 * Draw a pixel
 */
RLP_EXPORT void rp_DrawPixel(int posX, int posY, Color* color);

/**
 * Draw a pixel (Vector version)
 */
RLP_EXPORT void rp_DrawPixelV(Vector2* position, Color* color);

/**
 * Draw a line
 */
RLP_EXPORT void rp_DrawLine(int startPosX, int startPosY, int endPosX, int endPosY, Color* color);

/**
 * Draw a line (Vector version)
 */
RLP_EXPORT void rp_DrawLineV(Vector2* startPos, Vector2* endPos, Color* color);

/**
 * Draw a line defining thickness
 */
RLP_EXPORT void rp_DrawLineEx(Vector2* startPos, Vector2* endPos, float thick, Color* color);

/**
 * Draw a line using cubic-bezier curves in-out
 */
RLP_EXPORT void rp_DrawLineBezier(Vector2* startPos, Vector2* endPos, float thick, Color* color);

/**
 * Draw line using quadratic bezier curves with a control point
 */
RLP_EXPORT void rp_DrawLineBezierQuad(Vector2* startPos, Vector2* endPos, Vector2* controlPos, float thick, Color* color);

/**
 * Draw line using cubic bezier curves with 2 control points
 */
RLP_EXPORT void rp_DrawLineBezierCubic(Vector2* startPos, Vector2* endPos, Vector2* startControlPos, Vector2* endControlPos, float thick, Color* color);

/**
 * Draw lines sequence
 */
RLP_EXPORT void rp_DrawLineStrip(Vector2 * points, int pointCount, Color* color);

/**
 * Draw a color-filled circle
 */
RLP_EXPORT void rp_DrawCircle(int centerX, int centerY, float radius, Color* color);

/**
 * Draw a piece of a circle
 */
RLP_EXPORT void rp_DrawCircleSector(Vector2* center, float radius, float startAngle, float endAngle, int segments, Color* color);

/**
 * Draw circle sector outline
 */
RLP_EXPORT void rp_DrawCircleSectorLines(Vector2* center, float radius, float startAngle, float endAngle, int segments, Color* color);

/**
 * Draw a gradient-filled circle
 */
RLP_EXPORT void rp_DrawCircleGradient(int centerX, int centerY, float radius, Color* color1, Color* color2);

/**
 * Draw a color-filled circle (Vector version)
 */
RLP_EXPORT void rp_DrawCircleV(Vector2* center, float radius, Color* color);

/**
 * Draw circle outline
 */
RLP_EXPORT void rp_DrawCircleLines(int centerX, int centerY, float radius, Color* color);

/**
 * Draw ellipse
 */
RLP_EXPORT void rp_DrawEllipse(int centerX, int centerY, float radiusH, float radiusV, Color* color);

/**
 * Draw ellipse outline
 */
RLP_EXPORT void rp_DrawEllipseLines(int centerX, int centerY, float radiusH, float radiusV, Color* color);

/**
 * Draw ring
 */
RLP_EXPORT void rp_DrawRing(Vector2* center, float innerRadius, float outerRadius, float startAngle, float endAngle, int segments, Color* color);

/**
 * Draw ring outline
 */
RLP_EXPORT void rp_DrawRingLines(Vector2* center, float innerRadius, float outerRadius, float startAngle, float endAngle, int segments, Color* color);

/**
 * Draw a color-filled rectangle
 */
RLP_EXPORT void rp_DrawRectangle(int posX, int posY, int width, int height, Color* color);

/**
 * Draw a color-filled rectangle (Vector version)
 */
RLP_EXPORT void rp_DrawRectangleV(Vector2* position, Vector2* size, Color* color);

/**
 * Draw a color-filled rectangle
 */
RLP_EXPORT void rp_DrawRectangleRec(Rectangle* rec, Color* color);

/**
 * Draw a color-filled rectangle with pro parameters
 */
RLP_EXPORT void rp_DrawRectanglePro(Rectangle* rec, Vector2* origin, float rotation, Color* color);

/**
 * Draw a vertical-gradient-filled rectangle
 */
RLP_EXPORT void rp_DrawRectangleGradientV(int posX, int posY, int width, int height, Color* color1, Color* color2);

/**
 * Draw a horizontal-gradient-filled rectangle
 */
RLP_EXPORT void rp_DrawRectangleGradientH(int posX, int posY, int width, int height, Color* color1, Color* color2);

/**
 * Draw a gradient-filled rectangle with custom vertex colors
 */
RLP_EXPORT void rp_DrawRectangleGradientEx(Rectangle* rec, Color* col1, Color* col2, Color* col3, Color* col4);

/**
 * Draw rectangle outline
 */
RLP_EXPORT void rp_DrawRectangleLines(int posX, int posY, int width, int height, Color* color);

/**
 * Draw rectangle outline with extended parameters
 */
RLP_EXPORT void rp_DrawRectangleLinesEx(Rectangle* rec, float lineThick, Color* color);

/**
 * Draw rectangle with rounded edges
 */
RLP_EXPORT void rp_DrawRectangleRounded(Rectangle* rec, float roundness, int segments, Color* color);

/**
 * Draw rectangle with rounded edges outline
 */
RLP_EXPORT void rp_DrawRectangleRoundedLines(Rectangle* rec, float roundness, int segments, float lineThick, Color* color);

/**
 * Draw a color-filled triangle (vertex in counter-clockwise order!)
 */
RLP_EXPORT void rp_DrawTriangle(Vector2* v1, Vector2* v2, Vector2* v3, Color* color);

/**
 * Draw triangle outline (vertex in counter-clockwise order!)
 */
RLP_EXPORT void rp_DrawTriangleLines(Vector2* v1, Vector2* v2, Vector2* v3, Color* color);

/**
 * Draw a triangle fan defined by points (first vertex is the center)
 */
RLP_EXPORT void rp_DrawTriangleFan(Vector2 * points, int pointCount, Color* color);

/**
 * Draw a triangle strip defined by points
 */
RLP_EXPORT void rp_DrawTriangleStrip(Vector2 * points, int pointCount, Color* color);

/**
 * Draw a regular polygon (Vector version)
 */
RLP_EXPORT void rp_DrawPoly(Vector2* center, int sides, float radius, float rotation, Color* color);

/**
 * Draw a polygon outline of n sides
 */
RLP_EXPORT void rp_DrawPolyLines(Vector2* center, int sides, float radius, float rotation, Color* color);

/**
 * Draw a polygon outline of n sides with extended parameters
 */
RLP_EXPORT void rp_DrawPolyLinesEx(Vector2* center, int sides, float radius, float rotation, float lineThick, Color* color);

/**
 * Check collision between two rectangles
 */
RLP_EXPORT bool rp_CheckCollisionRecs(Rectangle* rec1, Rectangle* rec2);

/**
 * Check collision between two circles
 */
RLP_EXPORT bool rp_CheckCollisionCircles(Vector2* center1, float radius1, Vector2* center2, float radius2);

/**
 * Check collision between circle and rectangle
 */
RLP_EXPORT bool rp_CheckCollisionCircleRec(Vector2* center, float radius, Rectangle* rec);

/**
 * Check if point is inside rectangle
 */
RLP_EXPORT bool rp_CheckCollisionPointRec(Vector2* point, Rectangle* rec);

/**
 * Check if point is inside circle
 */
RLP_EXPORT bool rp_CheckCollisionPointCircle(Vector2* point, Vector2* center, float radius);

/**
 * Check if point is inside a triangle
 */
RLP_EXPORT bool rp_CheckCollisionPointTriangle(Vector2* point, Vector2* p1, Vector2* p2, Vector2* p3);

/**
 * Check if point is within a polygon described by array of vertices
 */
RLP_EXPORT bool rp_CheckCollisionPointPoly(Vector2* point, Vector2 * points, int pointCount);

/**
 * Check the collision between two lines defined by two points each, returns collision point by reference
 */
RLP_EXPORT bool rp_CheckCollisionLines(Vector2* startPos1, Vector2* endPos1, Vector2* startPos2, Vector2* endPos2, Vector2 * collisionPoint);

/**
 * Check if point belongs to line created between two points [p1] and [p2] with defined margin in pixels [threshold]
 */
RLP_EXPORT bool rp_CheckCollisionPointLine(Vector2* point, Vector2* p1, Vector2* p2, int threshold);

/**
 * Get collision rectangle for two rectangles collision
 */
RLP_EXPORT void rp_GetCollisionRec(Rectangle* output, Rectangle* rec1, Rectangle* rec2);

/**
 * Load image from file into CPU memory (RAM)
 */
RLP_EXPORT void rp_LoadImage(Image* output, const char * fileName);

/**
 * Load image from RAW file data
 */
RLP_EXPORT void rp_LoadImageRaw(Image* output, const char * fileName, int width, int height, int format, int headerSize);

/**
 * Load image sequence from file (frames appended to image.data)
 */
RLP_EXPORT void rp_LoadImageAnim(Image* output, const char * fileName, int * frames);

/**
 * Load image from memory buffer, fileType refers to extension: i.e. '.png'
 */
RLP_EXPORT void rp_LoadImageFromMemory(Image* output, const char * fileType, const unsigned char * fileData, int dataSize);

/**
 * Load image from GPU texture data
 */
RLP_EXPORT void rp_LoadImageFromTexture(Image* output, Texture2D* texture);

/**
 * Load image from screen buffer and (screenshot)
 */
RLP_EXPORT void rp_LoadImageFromScreen(Image* output);

/**
 * Check if an image is ready
 */
RLP_EXPORT bool rp_IsImageReady(Image* image);

/**
 * Unload image from CPU memory (RAM)
 */
RLP_EXPORT void rp_UnloadImage(Image* image);

/**
 * Export image data to file, returns true on success
 */
RLP_EXPORT bool rp_ExportImage(Image* image, const char * fileName);

/**
 * Export image as code file defining an array of bytes, returns true on success
 */
RLP_EXPORT bool rp_ExportImageAsCode(Image* image, const char * fileName);

/**
 * Generate image: plain color
 */
RLP_EXPORT void rp_GenImageColor(Image* output, int width, int height, Color* color);

/**
 * Generate image: vertical gradient
 */
RLP_EXPORT void rp_GenImageGradientV(Image* output, int width, int height, Color* top, Color* bottom);

/**
 * Generate image: horizontal gradient
 */
RLP_EXPORT void rp_GenImageGradientH(Image* output, int width, int height, Color* left, Color* right);

/**
 * Generate image: radial gradient
 */
RLP_EXPORT void rp_GenImageGradientRadial(Image* output, int width, int height, float density, Color* inner, Color* outer);

/**
 * Generate image: checked
 */
RLP_EXPORT void rp_GenImageChecked(Image* output, int width, int height, int checksX, int checksY, Color* col1, Color* col2);

/**
 * Generate image: white noise
 */
RLP_EXPORT void rp_GenImageWhiteNoise(Image* output, int width, int height, float factor);

/**
 * Generate image: perlin noise
 */
RLP_EXPORT void rp_GenImagePerlinNoise(Image* output, int width, int height, int offsetX, int offsetY, float scale);

/**
 * Generate image: cellular algorithm, bigger tileSize means bigger cells
 */
RLP_EXPORT void rp_GenImageCellular(Image* output, int width, int height, int tileSize);

/**
 * Generate image: grayscale image from text data
 */
RLP_EXPORT void rp_GenImageText(Image* output, int width, int height, const char * text);

/**
 * Create an image duplicate (useful for transformations)
 */
RLP_EXPORT void rp_ImageCopy(Image* output, Image* image);

/**
 * Create an image from another image piece
 */
RLP_EXPORT void rp_ImageFromImage(Image* output, Image* image, Rectangle* rec);

/**
 * Create an image from text (default font)
 */
RLP_EXPORT void rp_ImageText(Image* output, const char * text, int fontSize, Color* color);

/**
 * Create an image from text (custom sprite font)
 */
RLP_EXPORT void rp_ImageTextEx(Image* output, Font* font, const char * text, float fontSize, float spacing, Color* tint);

/**
 * Convert image data to desired format
 */
RLP_EXPORT void rp_ImageFormat(Image * image, int newFormat);

/**
 * Convert image to POT (power-of-two)
 */
RLP_EXPORT void rp_ImageToPOT(Image * image, Color* fill);

/**
 * Crop an image to a defined rectangle
 */
RLP_EXPORT void rp_ImageCrop(Image * image, Rectangle* crop);

/**
 * Crop image depending on alpha value
 */
RLP_EXPORT void rp_ImageAlphaCrop(Image * image, float threshold);

/**
 * Clear alpha channel to desired color
 */
RLP_EXPORT void rp_ImageAlphaClear(Image * image, Color* color, float threshold);

/**
 * Apply alpha mask to image
 */
RLP_EXPORT void rp_ImageAlphaMask(Image * image, Image* alphaMask);

/**
 * Premultiply alpha channel
 */
RLP_EXPORT void rp_ImageAlphaPremultiply(Image * image);

/**
 * Apply Gaussian blur using a box blur approximation
 */
RLP_EXPORT void rp_ImageBlurGaussian(Image * image, int blurSize);

/**
 * Resize image (Bicubic scaling algorithm)
 */
RLP_EXPORT void rp_ImageResize(Image * image, int newWidth, int newHeight);

/**
 * Resize image (Nearest-Neighbor scaling algorithm)
 */
RLP_EXPORT void rp_ImageResizeNN(Image * image, int newWidth, int newHeight);

/**
 * Resize canvas and fill with color
 */
RLP_EXPORT void rp_ImageResizeCanvas(Image * image, int newWidth, int newHeight, int offsetX, int offsetY, Color* fill);

/**
 * Compute all mipmap levels for a provided image
 */
RLP_EXPORT void rp_ImageMipmaps(Image * image);

/**
 * Dither image data to 16bpp or lower (Floyd-Steinberg dithering)
 */
RLP_EXPORT void rp_ImageDither(Image * image, int rBpp, int gBpp, int bBpp, int aBpp);

/**
 * Flip image vertically
 */
RLP_EXPORT void rp_ImageFlipVertical(Image * image);

/**
 * Flip image horizontally
 */
RLP_EXPORT void rp_ImageFlipHorizontal(Image * image);

/**
 * Rotate image clockwise 90deg
 */
RLP_EXPORT void rp_ImageRotateCW(Image * image);

/**
 * Rotate image counter-clockwise 90deg
 */
RLP_EXPORT void rp_ImageRotateCCW(Image * image);

/**
 * Modify image color: tint
 */
RLP_EXPORT void rp_ImageColorTint(Image * image, Color* color);

/**
 * Modify image color: invert
 */
RLP_EXPORT void rp_ImageColorInvert(Image * image);

/**
 * Modify image color: grayscale
 */
RLP_EXPORT void rp_ImageColorGrayscale(Image * image);

/**
 * Modify image color: contrast (-100 to 100)
 */
RLP_EXPORT void rp_ImageColorContrast(Image * image, float contrast);

/**
 * Modify image color: brightness (-255 to 255)
 */
RLP_EXPORT void rp_ImageColorBrightness(Image * image, int brightness);

/**
 * Modify image color: replace color
 */
RLP_EXPORT void rp_ImageColorReplace(Image * image, Color* color, Color* replace);

/**
 * Load color data from image as a Color array (RGBA - 32bit)
 */
RLP_EXPORT Color * rp_LoadImageColors(Image* image);

/**
 * Load colors palette from image as a Color array (RGBA - 32bit)
 */
RLP_EXPORT Color * rp_LoadImagePalette(Image* image, int maxPaletteSize, int * colorCount);

/**
 * Unload color data loaded with LoadImageColors()
 */
RLP_EXPORT void rp_UnloadImageColors(Color * colors);

/**
 * Unload colors palette loaded with LoadImagePalette()
 */
RLP_EXPORT void rp_UnloadImagePalette(Color * colors);

/**
 * Get image alpha border rectangle
 */
RLP_EXPORT void rp_GetImageAlphaBorder(Rectangle* output, Image* image, float threshold);

/**
 * Get image pixel color at (x, y) position
 */
RLP_EXPORT void rp_GetImageColor(Color* output, Image* image, int x, int y);

/**
 * Clear image background with given color
 */
RLP_EXPORT void rp_ImageClearBackground(Image * dst, Color* color);

/**
 * Draw pixel within an image
 */
RLP_EXPORT void rp_ImageDrawPixel(Image * dst, int posX, int posY, Color* color);

/**
 * Draw pixel within an image (Vector version)
 */
RLP_EXPORT void rp_ImageDrawPixelV(Image * dst, Vector2* position, Color* color);

/**
 * Draw line within an image
 */
RLP_EXPORT void rp_ImageDrawLine(Image * dst, int startPosX, int startPosY, int endPosX, int endPosY, Color* color);

/**
 * Draw line within an image (Vector version)
 */
RLP_EXPORT void rp_ImageDrawLineV(Image * dst, Vector2* start, Vector2* end, Color* color);

/**
 * Draw a filled circle within an image
 */
RLP_EXPORT void rp_ImageDrawCircle(Image * dst, int centerX, int centerY, int radius, Color* color);

/**
 * Draw a filled circle within an image (Vector version)
 */
RLP_EXPORT void rp_ImageDrawCircleV(Image * dst, Vector2* center, int radius, Color* color);

/**
 * Draw circle outline within an image
 */
RLP_EXPORT void rp_ImageDrawCircleLines(Image * dst, int centerX, int centerY, int radius, Color* color);

/**
 * Draw circle outline within an image (Vector version)
 */
RLP_EXPORT void rp_ImageDrawCircleLinesV(Image * dst, Vector2* center, int radius, Color* color);

/**
 * Draw rectangle within an image
 */
RLP_EXPORT void rp_ImageDrawRectangle(Image * dst, int posX, int posY, int width, int height, Color* color);

/**
 * Draw rectangle within an image (Vector version)
 */
RLP_EXPORT void rp_ImageDrawRectangleV(Image * dst, Vector2* position, Vector2* size, Color* color);

/**
 * Draw rectangle within an image
 */
RLP_EXPORT void rp_ImageDrawRectangleRec(Image * dst, Rectangle* rec, Color* color);

/**
 * Draw rectangle lines within an image
 */
RLP_EXPORT void rp_ImageDrawRectangleLines(Image * dst, Rectangle* rec, int thick, Color* color);

/**
 * Draw a source image within a destination image (tint applied to source)
 */
RLP_EXPORT void rp_ImageDraw(Image * dst, Image* src, Rectangle* srcRec, Rectangle* dstRec, Color* tint);

/**
 * Draw text (using default font) within an image (destination)
 */
RLP_EXPORT void rp_ImageDrawText(Image * dst, const char * text, int posX, int posY, int fontSize, Color* color);

/**
 * Draw text (custom sprite font) within an image (destination)
 */
RLP_EXPORT void rp_ImageDrawTextEx(Image * dst, Font* font, const char * text, Vector2* position, float fontSize, float spacing, Color* tint);

/**
 * Load texture from file into GPU memory (VRAM)
 */
RLP_EXPORT void rp_LoadTexture(Texture2D* output, const char * fileName);

/**
 * Load texture from image data
 */
RLP_EXPORT void rp_LoadTextureFromImage(Texture2D* output, Image* image);

/**
 * Load cubemap from image, multiple image cubemap layouts supported
 */
RLP_EXPORT void rp_LoadTextureCubemap(TextureCubemap* output, Image* image, int layout);

/**
 * Load texture for rendering (framebuffer)
 */
RLP_EXPORT void rp_LoadRenderTexture(RenderTexture2D* output, int width, int height);

/**
 * Check if a texture is ready
 */
RLP_EXPORT bool rp_IsTextureReady(Texture2D* texture);

/**
 * Unload texture from GPU memory (VRAM)
 */
RLP_EXPORT void rp_UnloadTexture(Texture2D* texture);

/**
 * Check if a render texture is ready
 */
RLP_EXPORT bool rp_IsRenderTextureReady(RenderTexture2D* target);

/**
 * Unload render texture from GPU memory (VRAM)
 */
RLP_EXPORT void rp_UnloadRenderTexture(RenderTexture2D* target);

/**
 * Update GPU texture with new data
 */
RLP_EXPORT void rp_UpdateTexture(Texture2D* texture, const void * pixels);

/**
 * Update GPU texture rectangle with new data
 */
RLP_EXPORT void rp_UpdateTextureRec(Texture2D* texture, Rectangle* rec, const void * pixels);

/**
 * Generate GPU mipmaps for a texture
 */
RLP_EXPORT void rp_GenTextureMipmaps(Texture2D * texture);

/**
 * Set texture scaling filter mode
 */
RLP_EXPORT void rp_SetTextureFilter(Texture2D* texture, int filter);

/**
 * Set texture wrapping mode
 */
RLP_EXPORT void rp_SetTextureWrap(Texture2D* texture, int wrap);

/**
 * Draw a Texture2D
 */
RLP_EXPORT void rp_DrawTexture(Texture2D* texture, int posX, int posY, Color* tint);

/**
 * Draw a Texture2D with position defined as Vector2
 */
RLP_EXPORT void rp_DrawTextureV(Texture2D* texture, Vector2* position, Color* tint);

/**
 * Draw a Texture2D with extended parameters
 */
RLP_EXPORT void rp_DrawTextureEx(Texture2D* texture, Vector2* position, float rotation, float scale, Color* tint);

/**
 * Draw a part of a texture defined by a rectangle
 */
RLP_EXPORT void rp_DrawTextureRec(Texture2D* texture, Rectangle* source, Vector2* position, Color* tint);

/**
 * Draw a part of a texture defined by a rectangle with 'pro' parameters
 */
RLP_EXPORT void rp_DrawTexturePro(Texture2D* texture, Rectangle* source, Rectangle* dest, Vector2* origin, float rotation, Color* tint);

/**
 * Draws a texture (or part of it) that stretches or shrinks nicely
 */
RLP_EXPORT void rp_DrawTextureNPatch(Texture2D* texture, NPatchInfo* nPatchInfo, Rectangle* dest, Vector2* origin, float rotation, Color* tint);

/**
 * Get color with alpha applied, alpha goes from 0.0f to 1.0f
 */
RLP_EXPORT void rp_Fade(Color* output, Color* color, float alpha);

/**
 * Get hexadecimal value for a Color
 */
RLP_EXPORT int rp_ColorToInt(Color* color);

/**
 * Get Color normalized as float [0..1]
 */
RLP_EXPORT void rp_ColorNormalize(Vector4* output, Color* color);

/**
 * Get Color from normalized values [0..1]
 */
RLP_EXPORT void rp_ColorFromNormalized(Color* output, Vector4* normalized);

/**
 * Get HSV values for a Color, hue [0..360], saturation/value [0..1]
 */
RLP_EXPORT void rp_ColorToHSV(Vector3* output, Color* color);

/**
 * Get a Color from HSV values, hue [0..360], saturation/value [0..1]
 */
RLP_EXPORT void rp_ColorFromHSV(Color* output, float hue, float saturation, float value);

/**
 * Get color multiplied with another color
 */
RLP_EXPORT void rp_ColorTint(Color* output, Color* color, Color* tint);

/**
 * Get color with brightness correction, brightness factor goes from -1.0f to 1.0f
 */
RLP_EXPORT void rp_ColorBrightness(Color* output, Color* color, float factor);

/**
 * Get color with contrast correction, contrast values between -1.0f and 1.0f
 */
RLP_EXPORT void rp_ColorContrast(Color* output, Color* color, float contrast);

/**
 * Get color with alpha applied, alpha goes from 0.0f to 1.0f
 */
RLP_EXPORT void rp_ColorAlpha(Color* output, Color* color, float alpha);

/**
 * Get src alpha-blended into dst color with tint
 */
RLP_EXPORT void rp_ColorAlphaBlend(Color* output, Color* dst, Color* src, Color* tint);

/**
 * Get Color structure from hexadecimal value
 */
RLP_EXPORT void rp_GetColor(Color* output, unsigned int hexValue);

/**
 * Get Color from a source pixel pointer of certain format
 */
RLP_EXPORT void rp_GetPixelColor(Color* output, void * srcPtr, int format);

/**
 * Set color formatted into destination pixel pointer
 */
RLP_EXPORT void rp_SetPixelColor(void * dstPtr, Color* color, int format);

/**
 * Get pixel data size in bytes for certain format
 */
RLP_EXPORT int rp_GetPixelDataSize(int width, int height, int format);

/**
 * Get the default Font
 */
RLP_EXPORT void rp_GetFontDefault(Font* output);

/**
 * Load font from file into GPU memory (VRAM)
 */
RLP_EXPORT void rp_LoadFont(Font* output, const char * fileName);

/**
 * Load font from file with extended parameters, use NULL for fontChars and 0 for glyphCount to load the default character set
 */
RLP_EXPORT void rp_LoadFontEx(Font* output, const char * fileName, int fontSize, int * fontChars, int glyphCount);

/**
 * Load font from Image (XNA style)
 */
RLP_EXPORT void rp_LoadFontFromImage(Font* output, Image* image, Color* key, int firstChar);

/**
 * Load font from memory buffer, fileType refers to extension: i.e. '.ttf'
 */
RLP_EXPORT void rp_LoadFontFromMemory(Font* output, const char * fileType, const unsigned char * fileData, int dataSize, int fontSize, int * fontChars, int glyphCount);

/**
 * Check if a font is ready
 */
RLP_EXPORT bool rp_IsFontReady(Font* font);

/**
 * Load font data for further use
 */
RLP_EXPORT GlyphInfo * rp_LoadFontData(const unsigned char * fileData, int dataSize, int fontSize, int * fontChars, int glyphCount, int type);

/**
 * Generate image font atlas using chars info
 */
RLP_EXPORT void rp_GenImageFontAtlas(Image* output, const GlyphInfo * chars, Rectangle ** recs, int glyphCount, int fontSize, int padding, int packMethod);

/**
 * Unload font chars info data (RAM)
 */
RLP_EXPORT void rp_UnloadFontData(GlyphInfo * chars, int glyphCount);

/**
 * Unload font from GPU memory (VRAM)
 */
RLP_EXPORT void rp_UnloadFont(Font* font);

/**
 * Export font as code file, returns true on success
 */
RLP_EXPORT bool rp_ExportFontAsCode(Font* font, const char * fileName);

/**
 * Draw current FPS
 */
RLP_EXPORT void rp_DrawFPS(int posX, int posY);

/**
 * Draw text (using default font)
 */
RLP_EXPORT void rp_DrawText(const char * text, int posX, int posY, int fontSize, Color* color);

/**
 * Draw text using font and additional parameters
 */
RLP_EXPORT void rp_DrawTextEx(Font* font, const char * text, Vector2* position, float fontSize, float spacing, Color* tint);

/**
 * Draw text using Font and pro parameters (rotation)
 */
RLP_EXPORT void rp_DrawTextPro(Font* font, const char * text, Vector2* position, Vector2* origin, float rotation, float fontSize, float spacing, Color* tint);

/**
 * Draw one character (codepoint)
 */
RLP_EXPORT void rp_DrawTextCodepoint(Font* font, int codepoint, Vector2* position, float fontSize, Color* tint);

/**
 * Draw multiple character (codepoint)
 */
RLP_EXPORT void rp_DrawTextCodepoints(Font* font, const int * codepoints, int count, Vector2* position, float fontSize, float spacing, Color* tint);

/**
 * Measure string width for default font
 */
RLP_EXPORT int rp_MeasureText(const char * text, int fontSize);

/**
 * Measure string size for Font
 */
RLP_EXPORT void rp_MeasureTextEx(Vector2* output, Font* font, const char * text, float fontSize, float spacing);

/**
 * Get glyph index position in font for a codepoint (unicode character), fallback to '?' if not found
 */
RLP_EXPORT int rp_GetGlyphIndex(Font* font, int codepoint);

/**
 * Get glyph font info data for a codepoint (unicode character), fallback to '?' if not found
 */
RLP_EXPORT void rp_GetGlyphInfo(GlyphInfo* output, Font* font, int codepoint);

/**
 * Get glyph rectangle in font atlas for a codepoint (unicode character), fallback to '?' if not found
 */
RLP_EXPORT void rp_GetGlyphAtlasRec(Rectangle* output, Font* font, int codepoint);

/**
 * Load UTF-8 text encoded from codepoints array
 */
RLP_EXPORT char * rp_LoadUTF8(const int * codepoints, int length);

/**
 * Unload UTF-8 text encoded from codepoints array
 */
RLP_EXPORT void rp_UnloadUTF8(char * text);

/**
 * Load all codepoints from a UTF-8 text string, codepoints count returned by parameter
 */
RLP_EXPORT int * rp_LoadCodepoints(const char * text, int * count);

/**
 * Unload codepoints data from memory
 */
RLP_EXPORT void rp_UnloadCodepoints(int * codepoints);

/**
 * Get total number of codepoints in a UTF-8 encoded string
 */
RLP_EXPORT int rp_GetCodepointCount(const char * text);

/**
 * Get next codepoint in a UTF-8 encoded string, 0x3f('?') is returned on failure
 */
RLP_EXPORT int rp_GetCodepoint(const char * text, int * codepointSize);

/**
 * Get next codepoint in a UTF-8 encoded string, 0x3f('?') is returned on failure
 */
RLP_EXPORT int rp_GetCodepointNext(const char * text, int * codepointSize);

/**
 * Get previous codepoint in a UTF-8 encoded string, 0x3f('?') is returned on failure
 */
RLP_EXPORT int rp_GetCodepointPrevious(const char * text, int * codepointSize);

/**
 * Encode one codepoint into UTF-8 byte array (array length returned as parameter)
 */
RLP_EXPORT const char * rp_CodepointToUTF8(int codepoint, int * utf8Size);

/**
 * Copy one string to another, returns bytes copied
 */
RLP_EXPORT int rp_TextCopy(char * dst, const char * src);

/**
 * Check if two text string are equal
 */
RLP_EXPORT bool rp_TextIsEqual(const char * text1, const char * text2);

/**
 * Get text length, checks for '\0' ending
 */
RLP_EXPORT unsigned int rp_TextLength(const char * text);

/**
 * Text formatting with variables (sprintf() style)
 */
RLP_EXPORT const char * rp_TextFormat(const char * text, char* args);

/**
 * Get a piece of a text string
 */
RLP_EXPORT const char * rp_TextSubtext(const char * text, int position, int length);

/**
 * Replace text string (WARNING: memory must be freed!)
 */
RLP_EXPORT char * rp_TextReplace(char * text, const char * replace, const char * by);

/**
 * Insert text in a position (WARNING: memory must be freed!)
 */
RLP_EXPORT char * rp_TextInsert(const char * text, const char * insert, int position);

/**
 * Join text strings with delimiter
 */
RLP_EXPORT const char * rp_TextJoin(const char ** textList, int count, const char * delimiter);

/**
 * Split text into multiple strings
 */
RLP_EXPORT const char ** rp_TextSplit(const char * text, char delimiter, int * count);

/**
 * Append text at specific position and move cursor!
 */
RLP_EXPORT void rp_TextAppend(char * text, const char * append, int * position);

/**
 * Find first text occurrence within a string
 */
RLP_EXPORT int rp_TextFindIndex(const char * text, const char * find);

/**
 * Get upper case version of provided string
 */
RLP_EXPORT const char * rp_TextToUpper(const char * text);

/**
 * Get lower case version of provided string
 */
RLP_EXPORT const char * rp_TextToLower(const char * text);

/**
 * Get Pascal case notation version of provided string
 */
RLP_EXPORT const char * rp_TextToPascal(const char * text);

/**
 * Get integer value from text (negative values not supported)
 */
RLP_EXPORT int rp_TextToInteger(const char * text);

/**
 * Draw a line in 3D world space
 */
RLP_EXPORT void rp_DrawLine3D(Vector3* startPos, Vector3* endPos, Color* color);

/**
 * Draw a point in 3D space, actually a small line
 */
RLP_EXPORT void rp_DrawPoint3D(Vector3* position, Color* color);

/**
 * Draw a circle in 3D world space
 */
RLP_EXPORT void rp_DrawCircle3D(Vector3* center, float radius, Vector3* rotationAxis, float rotationAngle, Color* color);

/**
 * Draw a color-filled triangle (vertex in counter-clockwise order!)
 */
RLP_EXPORT void rp_DrawTriangle3D(Vector3* v1, Vector3* v2, Vector3* v3, Color* color);

/**
 * Draw a triangle strip defined by points
 */
RLP_EXPORT void rp_DrawTriangleStrip3D(Vector3 * points, int pointCount, Color* color);

/**
 * Draw cube
 */
RLP_EXPORT void rp_DrawCube(Vector3* position, float width, float height, float length, Color* color);

/**
 * Draw cube (Vector version)
 */
RLP_EXPORT void rp_DrawCubeV(Vector3* position, Vector3* size, Color* color);

/**
 * Draw cube wires
 */
RLP_EXPORT void rp_DrawCubeWires(Vector3* position, float width, float height, float length, Color* color);

/**
 * Draw cube wires (Vector version)
 */
RLP_EXPORT void rp_DrawCubeWiresV(Vector3* position, Vector3* size, Color* color);

/**
 * Draw sphere
 */
RLP_EXPORT void rp_DrawSphere(Vector3* centerPos, float radius, Color* color);

/**
 * Draw sphere with extended parameters
 */
RLP_EXPORT void rp_DrawSphereEx(Vector3* centerPos, float radius, int rings, int slices, Color* color);

/**
 * Draw sphere wires
 */
RLP_EXPORT void rp_DrawSphereWires(Vector3* centerPos, float radius, int rings, int slices, Color* color);

/**
 * Draw a cylinder/cone
 */
RLP_EXPORT void rp_DrawCylinder(Vector3* position, float radiusTop, float radiusBottom, float height, int slices, Color* color);

/**
 * Draw a cylinder with base at startPos and top at endPos
 */
RLP_EXPORT void rp_DrawCylinderEx(Vector3* startPos, Vector3* endPos, float startRadius, float endRadius, int sides, Color* color);

/**
 * Draw a cylinder/cone wires
 */
RLP_EXPORT void rp_DrawCylinderWires(Vector3* position, float radiusTop, float radiusBottom, float height, int slices, Color* color);

/**
 * Draw a cylinder wires with base at startPos and top at endPos
 */
RLP_EXPORT void rp_DrawCylinderWiresEx(Vector3* startPos, Vector3* endPos, float startRadius, float endRadius, int sides, Color* color);

/**
 * Draw a capsule with the center of its sphere caps at startPos and endPos
 */
RLP_EXPORT void rp_DrawCapsule(Vector3* startPos, Vector3* endPos, float radius, int slices, int rings, Color* color);

/**
 * Draw capsule wireframe with the center of its sphere caps at startPos and endPos
 */
RLP_EXPORT void rp_DrawCapsuleWires(Vector3* startPos, Vector3* endPos, float radius, int slices, int rings, Color* color);

/**
 * Draw a plane XZ
 */
RLP_EXPORT void rp_DrawPlane(Vector3* centerPos, Vector2* size, Color* color);

/**
 * Draw a ray line
 */
RLP_EXPORT void rp_DrawRay(Ray* ray, Color* color);

/**
 * Draw a grid (centered at (0, 0, 0))
 */
RLP_EXPORT void rp_DrawGrid(int slices, float spacing);

/**
 * Load model from files (meshes and materials)
 */
RLP_EXPORT void rp_LoadModel(Model* output, const char * fileName);

/**
 * Load model from generated mesh (default material)
 */
RLP_EXPORT void rp_LoadModelFromMesh(Model* output, Mesh* mesh);

/**
 * Check if a model is ready
 */
RLP_EXPORT bool rp_IsModelReady(Model* model);

/**
 * Unload model (including meshes) from memory (RAM and/or VRAM)
 */
RLP_EXPORT void rp_UnloadModel(Model* model);

/**
 * Compute model bounding box limits (considers all meshes)
 */
RLP_EXPORT void rp_GetModelBoundingBox(BoundingBox* output, Model* model);

/**
 * Draw a model (with texture if set)
 */
RLP_EXPORT void rp_DrawModel(Model* model, Vector3* position, float scale, Color* tint);

/**
 * Draw a model with extended parameters
 */
RLP_EXPORT void rp_DrawModelEx(Model* model, Vector3* position, Vector3* rotationAxis, float rotationAngle, Vector3* scale, Color* tint);

/**
 * Draw a model wires (with texture if set)
 */
RLP_EXPORT void rp_DrawModelWires(Model* model, Vector3* position, float scale, Color* tint);

/**
 * Draw a model wires (with texture if set) with extended parameters
 */
RLP_EXPORT void rp_DrawModelWiresEx(Model* model, Vector3* position, Vector3* rotationAxis, float rotationAngle, Vector3* scale, Color* tint);

/**
 * Draw bounding box (wires)
 */
RLP_EXPORT void rp_DrawBoundingBox(BoundingBox* box, Color* color);

/**
 * Draw a billboard texture
 */
RLP_EXPORT void rp_DrawBillboard(Camera* camera, Texture2D* texture, Vector3* position, float size, Color* tint);

/**
 * Draw a billboard texture defined by source
 */
RLP_EXPORT void rp_DrawBillboardRec(Camera* camera, Texture2D* texture, Rectangle* source, Vector3* position, Vector2* size, Color* tint);

/**
 * Draw a billboard texture defined by source and rotation
 */
RLP_EXPORT void rp_DrawBillboardPro(Camera* camera, Texture2D* texture, Rectangle* source, Vector3* position, Vector3* up, Vector2* size, Vector2* origin, float rotation, Color* tint);

/**
 * Upload mesh vertex data in GPU and provide VAO/VBO ids
 */
RLP_EXPORT void rp_UploadMesh(Mesh * mesh, bool dynamic);

/**
 * Update mesh vertex data in GPU for a specific buffer index
 */
RLP_EXPORT void rp_UpdateMeshBuffer(Mesh* mesh, int index, const void * data, int dataSize, int offset);

/**
 * Unload mesh data from CPU and GPU
 */
RLP_EXPORT void rp_UnloadMesh(Mesh* mesh);

/**
 * Draw a 3d mesh with material and transform
 */
RLP_EXPORT void rp_DrawMesh(Mesh* mesh, Material* material, Matrix* transform);

/**
 * Draw multiple mesh instances with material and different transforms
 */
RLP_EXPORT void rp_DrawMeshInstanced(Mesh* mesh, Material* material, const Matrix * transforms, int instances);

/**
 * Export mesh data to file, returns true on success
 */
RLP_EXPORT bool rp_ExportMesh(Mesh* mesh, const char * fileName);

/**
 * Compute mesh bounding box limits
 */
RLP_EXPORT void rp_GetMeshBoundingBox(BoundingBox* output, Mesh* mesh);

/**
 * Compute mesh tangents
 */
RLP_EXPORT void rp_GenMeshTangents(Mesh * mesh);

/**
 * Generate polygonal mesh
 */
RLP_EXPORT void rp_GenMeshPoly(Mesh* output, int sides, float radius);

/**
 * Generate plane mesh (with subdivisions)
 */
RLP_EXPORT void rp_GenMeshPlane(Mesh* output, float width, float length, int resX, int resZ);

/**
 * Generate cuboid mesh
 */
RLP_EXPORT void rp_GenMeshCube(Mesh* output, float width, float height, float length);

/**
 * Generate sphere mesh (standard sphere)
 */
RLP_EXPORT void rp_GenMeshSphere(Mesh* output, float radius, int rings, int slices);

/**
 * Generate half-sphere mesh (no bottom cap)
 */
RLP_EXPORT void rp_GenMeshHemiSphere(Mesh* output, float radius, int rings, int slices);

/**
 * Generate cylinder mesh
 */
RLP_EXPORT void rp_GenMeshCylinder(Mesh* output, float radius, float height, int slices);

/**
 * Generate cone/pyramid mesh
 */
RLP_EXPORT void rp_GenMeshCone(Mesh* output, float radius, float height, int slices);

/**
 * Generate torus mesh
 */
RLP_EXPORT void rp_GenMeshTorus(Mesh* output, float radius, float size, int radSeg, int sides);

/**
 * Generate trefoil knot mesh
 */
RLP_EXPORT void rp_GenMeshKnot(Mesh* output, float radius, float size, int radSeg, int sides);

/**
 * Generate heightmap mesh from image data
 */
RLP_EXPORT void rp_GenMeshHeightmap(Mesh* output, Image* heightmap, Vector3* size);

/**
 * Generate cubes-based map mesh from image data
 */
RLP_EXPORT void rp_GenMeshCubicmap(Mesh* output, Image* cubicmap, Vector3* cubeSize);

/**
 * Load materials from model file
 */
RLP_EXPORT Material * rp_LoadMaterials(const char * fileName, int * materialCount);

/**
 * Load default material (Supports: DIFFUSE, SPECULAR, NORMAL maps)
 */
RLP_EXPORT void rp_LoadMaterialDefault(Material* output);

/**
 * Check if a material is ready
 */
RLP_EXPORT bool rp_IsMaterialReady(Material* material);

/**
 * Unload material from GPU memory (VRAM)
 */
RLP_EXPORT void rp_UnloadMaterial(Material* material);

/**
 * Set texture for a material map type (MATERIAL_MAP_DIFFUSE, MATERIAL_MAP_SPECULAR...)
 */
RLP_EXPORT void rp_SetMaterialTexture(Material * material, int mapType, Texture2D* texture);

/**
 * Set material for a mesh
 */
RLP_EXPORT void rp_SetModelMeshMaterial(Model * model, int meshId, int materialId);

/**
 * Load model animations from file
 */
RLP_EXPORT ModelAnimation * rp_LoadModelAnimations(const char * fileName, unsigned int * animCount);

/**
 * Update model animation pose
 */
RLP_EXPORT void rp_UpdateModelAnimation(Model* model, ModelAnimation* anim, int frame);

/**
 * Unload animation data
 */
RLP_EXPORT void rp_UnloadModelAnimation(ModelAnimation* anim);

/**
 * Unload animation array data
 */
RLP_EXPORT void rp_UnloadModelAnimations(ModelAnimation * animations, unsigned int count);

/**
 * Check model animation skeleton match
 */
RLP_EXPORT bool rp_IsModelAnimationValid(Model* model, ModelAnimation* anim);

/**
 * Check collision between two spheres
 */
RLP_EXPORT bool rp_CheckCollisionSpheres(Vector3* center1, float radius1, Vector3* center2, float radius2);

/**
 * Check collision between two bounding boxes
 */
RLP_EXPORT bool rp_CheckCollisionBoxes(BoundingBox* box1, BoundingBox* box2);

/**
 * Check collision between box and sphere
 */
RLP_EXPORT bool rp_CheckCollisionBoxSphere(BoundingBox* box, Vector3* center, float radius);

/**
 * Get collision info between ray and sphere
 */
RLP_EXPORT void rp_GetRayCollisionSphere(RayCollision* output, Ray* ray, Vector3* center, float radius);

/**
 * Get collision info between ray and box
 */
RLP_EXPORT void rp_GetRayCollisionBox(RayCollision* output, Ray* ray, BoundingBox* box);

/**
 * Get collision info between ray and mesh
 */
RLP_EXPORT void rp_GetRayCollisionMesh(RayCollision* output, Ray* ray, Mesh* mesh, Matrix* transform);

/**
 * Get collision info between ray and triangle
 */
RLP_EXPORT void rp_GetRayCollisionTriangle(RayCollision* output, Ray* ray, Vector3* p1, Vector3* p2, Vector3* p3);

/**
 * Get collision info between ray and quad
 */
RLP_EXPORT void rp_GetRayCollisionQuad(RayCollision* output, Ray* ray, Vector3* p1, Vector3* p2, Vector3* p3, Vector3* p4);

/**
 * Initialize audio device and context
 */
RLP_EXPORT void rp_InitAudioDevice();

/**
 * Close the audio device and context
 */
RLP_EXPORT void rp_CloseAudioDevice();

/**
 * Check if audio device has been initialized successfully
 */
RLP_EXPORT bool rp_IsAudioDeviceReady();

/**
 * Set master volume (listener)
 */
RLP_EXPORT void rp_SetMasterVolume(float volume);

/**
 * Load wave data from file
 */
RLP_EXPORT void rp_LoadWave(Wave* output, const char * fileName);

/**
 * Load wave from memory buffer, fileType refers to extension: i.e. '.wav'
 */
RLP_EXPORT void rp_LoadWaveFromMemory(Wave* output, const char * fileType, const unsigned char * fileData, int dataSize);

/**
 * Checks if wave data is ready
 */
RLP_EXPORT bool rp_IsWaveReady(Wave* wave);

/**
 * Load sound from file
 */
RLP_EXPORT void rp_LoadSound(Sound* output, const char * fileName);

/**
 * Load sound from wave data
 */
RLP_EXPORT void rp_LoadSoundFromWave(Sound* output, Wave* wave);

/**
 * Checks if a sound is ready
 */
RLP_EXPORT bool rp_IsSoundReady(Sound* sound);

/**
 * Update sound buffer with new data
 */
RLP_EXPORT void rp_UpdateSound(Sound* sound, const void * data, int sampleCount);

/**
 * Unload wave data
 */
RLP_EXPORT void rp_UnloadWave(Wave* wave);

/**
 * Unload sound
 */
RLP_EXPORT void rp_UnloadSound(Sound* sound);

/**
 * Export wave data to file, returns true on success
 */
RLP_EXPORT bool rp_ExportWave(Wave* wave, const char * fileName);

/**
 * Export wave sample data to code (.h), returns true on success
 */
RLP_EXPORT bool rp_ExportWaveAsCode(Wave* wave, const char * fileName);

/**
 * Play a sound
 */
RLP_EXPORT void rp_PlaySound(Sound* sound);

/**
 * Stop playing a sound
 */
RLP_EXPORT void rp_StopSound(Sound* sound);

/**
 * Pause a sound
 */
RLP_EXPORT void rp_PauseSound(Sound* sound);

/**
 * Resume a paused sound
 */
RLP_EXPORT void rp_ResumeSound(Sound* sound);

/**
 * Check if a sound is currently playing
 */
RLP_EXPORT bool rp_IsSoundPlaying(Sound* sound);

/**
 * Set volume for a sound (1.0 is max level)
 */
RLP_EXPORT void rp_SetSoundVolume(Sound* sound, float volume);

/**
 * Set pitch for a sound (1.0 is base level)
 */
RLP_EXPORT void rp_SetSoundPitch(Sound* sound, float pitch);

/**
 * Set pan for a sound (0.5 is center)
 */
RLP_EXPORT void rp_SetSoundPan(Sound* sound, float pan);

/**
 * Copy a wave to a new wave
 */
RLP_EXPORT void rp_WaveCopy(Wave* output, Wave* wave);

/**
 * Crop a wave to defined samples range
 */
RLP_EXPORT void rp_WaveCrop(Wave * wave, int initSample, int finalSample);

/**
 * Convert wave data to desired format
 */
RLP_EXPORT void rp_WaveFormat(Wave * wave, int sampleRate, int sampleSize, int channels);

/**
 * Load samples data from wave as a 32bit float data array
 */
RLP_EXPORT float * rp_LoadWaveSamples(Wave* wave);

/**
 * Unload samples data loaded with LoadWaveSamples()
 */
RLP_EXPORT void rp_UnloadWaveSamples(float * samples);

/**
 * Load music stream from file
 */
RLP_EXPORT void rp_LoadMusicStream(Music* output, const char * fileName);

/**
 * Load music stream from data
 */
RLP_EXPORT void rp_LoadMusicStreamFromMemory(Music* output, const char * fileType, const unsigned char * data, int dataSize);

/**
 * Checks if a music stream is ready
 */
RLP_EXPORT bool rp_IsMusicReady(Music* music);

/**
 * Unload music stream
 */
RLP_EXPORT void rp_UnloadMusicStream(Music* music);

/**
 * Start music playing
 */
RLP_EXPORT void rp_PlayMusicStream(Music* music);

/**
 * Check if music is playing
 */
RLP_EXPORT bool rp_IsMusicStreamPlaying(Music* music);

/**
 * Updates buffers for music streaming
 */
RLP_EXPORT void rp_UpdateMusicStream(Music* music);

/**
 * Stop music playing
 */
RLP_EXPORT void rp_StopMusicStream(Music* music);

/**
 * Pause music playing
 */
RLP_EXPORT void rp_PauseMusicStream(Music* music);

/**
 * Resume playing paused music
 */
RLP_EXPORT void rp_ResumeMusicStream(Music* music);

/**
 * Seek music to a position (in seconds)
 */
RLP_EXPORT void rp_SeekMusicStream(Music* music, float position);

/**
 * Set volume for music (1.0 is max level)
 */
RLP_EXPORT void rp_SetMusicVolume(Music* music, float volume);

/**
 * Set pitch for a music (1.0 is base level)
 */
RLP_EXPORT void rp_SetMusicPitch(Music* music, float pitch);

/**
 * Set pan for a music (0.5 is center)
 */
RLP_EXPORT void rp_SetMusicPan(Music* music, float pan);

/**
 * Get music time length (in seconds)
 */
RLP_EXPORT float rp_GetMusicTimeLength(Music* music);

/**
 * Get current music time played (in seconds)
 */
RLP_EXPORT float rp_GetMusicTimePlayed(Music* music);

/**
 * Load audio stream (to stream raw audio pcm data)
 */
RLP_EXPORT void rp_LoadAudioStream(AudioStream* output, unsigned int sampleRate, unsigned int sampleSize, unsigned int channels);

/**
 * Checks if an audio stream is ready
 */
RLP_EXPORT bool rp_IsAudioStreamReady(AudioStream* stream);

/**
 * Unload audio stream and free memory
 */
RLP_EXPORT void rp_UnloadAudioStream(AudioStream* stream);

/**
 * Update audio stream buffers with data
 */
RLP_EXPORT void rp_UpdateAudioStream(AudioStream* stream, const void * data, int frameCount);

/**
 * Check if any audio stream buffers requires refill
 */
RLP_EXPORT bool rp_IsAudioStreamProcessed(AudioStream* stream);

/**
 * Play audio stream
 */
RLP_EXPORT void rp_PlayAudioStream(AudioStream* stream);

/**
 * Pause audio stream
 */
RLP_EXPORT void rp_PauseAudioStream(AudioStream* stream);

/**
 * Resume audio stream
 */
RLP_EXPORT void rp_ResumeAudioStream(AudioStream* stream);

/**
 * Check if audio stream is playing
 */
RLP_EXPORT bool rp_IsAudioStreamPlaying(AudioStream* stream);

/**
 * Stop audio stream
 */
RLP_EXPORT void rp_StopAudioStream(AudioStream* stream);

/**
 * Set volume for audio stream (1.0 is max level)
 */
RLP_EXPORT void rp_SetAudioStreamVolume(AudioStream* stream, float volume);

/**
 * Set pitch for audio stream (1.0 is base level)
 */
RLP_EXPORT void rp_SetAudioStreamPitch(AudioStream* stream, float pitch);

/**
 * Set pan for audio stream (0.5 is centered)
 */
RLP_EXPORT void rp_SetAudioStreamPan(AudioStream* stream, float pan);

/**
 * Default size for new audio streams
 */
RLP_EXPORT void rp_SetAudioStreamBufferSizeDefault(int size);

/**
 * Audio thread callback to request new data
 */
RLP_EXPORT void rp_SetAudioStreamCallback(AudioStream* stream, AudioCallback callback);

/**
 * Attach audio stream processor to stream
 */
RLP_EXPORT void rp_AttachAudioStreamProcessor(AudioStream* stream, AudioCallback processor);

/**
 * Detach audio stream processor from stream
 */
RLP_EXPORT void rp_DetachAudioStreamProcessor(AudioStream* stream, AudioCallback processor);

/**
 * Attach audio stream processor to the entire audio pipeline
 */
RLP_EXPORT void rp_AttachAudioMixedProcessor(AudioCallback processor);

/**
 * Detach audio stream processor from the entire audio pipeline
 */
RLP_EXPORT void rp_DetachAudioMixedProcessor(AudioCallback processor);


#ifdef RP_NATIVE
void rp_InitWindow(int width, int height, const char * title) {
    InitWindow(width, height, title);
}
    
bool rp_WindowShouldClose() {
    return WindowShouldClose();
}
    
void rp_CloseWindow() {
    CloseWindow();
}
    
bool rp_IsWindowReady() {
    return IsWindowReady();
}
    
bool rp_IsWindowFullscreen() {
    return IsWindowFullscreen();
}
    
bool rp_IsWindowHidden() {
    return IsWindowHidden();
}
    
bool rp_IsWindowMinimized() {
    return IsWindowMinimized();
}
    
bool rp_IsWindowMaximized() {
    return IsWindowMaximized();
}
    
bool rp_IsWindowFocused() {
    return IsWindowFocused();
}
    
bool rp_IsWindowResized() {
    return IsWindowResized();
}
    
bool rp_IsWindowState(unsigned int flag) {
    return IsWindowState(flag);
}
    
void rp_SetWindowState(unsigned int flags) {
    SetWindowState(flags);
}
    
void rp_ClearWindowState(unsigned int flags) {
    ClearWindowState(flags);
}
    
void rp_ToggleFullscreen() {
    ToggleFullscreen();
}
    
void rp_MaximizeWindow() {
    MaximizeWindow();
}
    
void rp_MinimizeWindow() {
    MinimizeWindow();
}
    
void rp_RestoreWindow() {
    RestoreWindow();
}
    
void rp_SetWindowIcon(Image* image) {
    SetWindowIcon(*image);
}
    
void rp_SetWindowIcons(Image * images, int count) {
    SetWindowIcons(images, count);
}
    
void rp_SetWindowTitle(const char * title) {
    SetWindowTitle(title);
}
    
void rp_SetWindowPosition(int x, int y) {
    SetWindowPosition(x, y);
}
    
void rp_SetWindowMonitor(int monitor) {
    SetWindowMonitor(monitor);
}
    
void rp_SetWindowMinSize(int width, int height) {
    SetWindowMinSize(width, height);
}
    
void rp_SetWindowSize(int width, int height) {
    SetWindowSize(width, height);
}
    
void rp_SetWindowOpacity(float opacity) {
    SetWindowOpacity(opacity);
}
    
void * rp_GetWindowHandle() {
    return GetWindowHandle();
}
    
int rp_GetScreenWidth() {
    return GetScreenWidth();
}
    
int rp_GetScreenHeight() {
    return GetScreenHeight();
}
    
int rp_GetRenderWidth() {
    return GetRenderWidth();
}
    
int rp_GetRenderHeight() {
    return GetRenderHeight();
}
    
int rp_GetMonitorCount() {
    return GetMonitorCount();
}
    
int rp_GetCurrentMonitor() {
    return GetCurrentMonitor();
}
    
void rp_GetMonitorPosition(Vector2* output, int monitor) {
    Vector2 val = GetMonitorPosition(monitor);
    memcpy(output, &val, sizeof(Vector2));
}
    
int rp_GetMonitorWidth(int monitor) {
    return GetMonitorWidth(monitor);
}
    
int rp_GetMonitorHeight(int monitor) {
    return GetMonitorHeight(monitor);
}
    
int rp_GetMonitorPhysicalWidth(int monitor) {
    return GetMonitorPhysicalWidth(monitor);
}
    
int rp_GetMonitorPhysicalHeight(int monitor) {
    return GetMonitorPhysicalHeight(monitor);
}
    
int rp_GetMonitorRefreshRate(int monitor) {
    return GetMonitorRefreshRate(monitor);
}
    
void rp_GetWindowPosition(Vector2* output) {
    Vector2 val = GetWindowPosition();
    memcpy(output, &val, sizeof(Vector2));
}
    
void rp_GetWindowScaleDPI(Vector2* output) {
    Vector2 val = GetWindowScaleDPI();
    memcpy(output, &val, sizeof(Vector2));
}
    
const char * rp_GetMonitorName(int monitor) {
    return GetMonitorName(monitor);
}
    
void rp_SetClipboardText(const char * text) {
    SetClipboardText(text);
}
    
const char * rp_GetClipboardText() {
    return GetClipboardText();
}
    
void rp_EnableEventWaiting() {
    EnableEventWaiting();
}
    
void rp_DisableEventWaiting() {
    DisableEventWaiting();
}
    
void rp_SwapScreenBuffer() {
    SwapScreenBuffer();
}
    
void rp_PollInputEvents() {
    PollInputEvents();
}
    
void rp_WaitTime(double seconds) {
    WaitTime(seconds);
}
    
void rp_ShowCursor() {
    ShowCursor();
}
    
void rp_HideCursor() {
    HideCursor();
}
    
bool rp_IsCursorHidden() {
    return IsCursorHidden();
}
    
void rp_EnableCursor() {
    EnableCursor();
}
    
void rp_DisableCursor() {
    DisableCursor();
}
    
bool rp_IsCursorOnScreen() {
    return IsCursorOnScreen();
}
    
void rp_ClearBackground(Color* color) {
    ClearBackground(*color);
}
    
void rp_BeginDrawing() {
    BeginDrawing();
}
    
void rp_EndDrawing() {
    EndDrawing();
}
    
void rp_BeginMode2D(Camera2D* camera) {
    BeginMode2D(*camera);
}
    
void rp_EndMode2D() {
    EndMode2D();
}
    
void rp_BeginMode3D(Camera3D* camera) {
    BeginMode3D(*camera);
}
    
void rp_EndMode3D() {
    EndMode3D();
}
    
void rp_BeginTextureMode(RenderTexture2D* target) {
    BeginTextureMode(*target);
}
    
void rp_EndTextureMode() {
    EndTextureMode();
}
    
void rp_BeginShaderMode(Shader* shader) {
    BeginShaderMode(*shader);
}
    
void rp_EndShaderMode() {
    EndShaderMode();
}
    
void rp_BeginBlendMode(int mode) {
    BeginBlendMode(mode);
}
    
void rp_EndBlendMode() {
    EndBlendMode();
}
    
void rp_BeginScissorMode(int x, int y, int width, int height) {
    BeginScissorMode(x, y, width, height);
}
    
void rp_EndScissorMode() {
    EndScissorMode();
}
    
void rp_BeginVrStereoMode(VrStereoConfig* config) {
    BeginVrStereoMode(*config);
}
    
void rp_EndVrStereoMode() {
    EndVrStereoMode();
}
    
void rp_LoadVrStereoConfig(VrStereoConfig* output, VrDeviceInfo* device) {
    VrStereoConfig val = LoadVrStereoConfig(*device);
    memcpy(output, &val, sizeof(VrStereoConfig));
}
    
void rp_UnloadVrStereoConfig(VrStereoConfig* config) {
    UnloadVrStereoConfig(*config);
}
    
void rp_LoadShader(Shader* output, const char * vsFileName, const char * fsFileName) {
    Shader val = LoadShader(vsFileName, fsFileName);
    memcpy(output, &val, sizeof(Shader));
}
    
void rp_LoadShaderFromMemory(Shader* output, const char * vsCode, const char * fsCode) {
    Shader val = LoadShaderFromMemory(vsCode, fsCode);
    memcpy(output, &val, sizeof(Shader));
}
    
bool rp_IsShaderReady(Shader* shader) {
    return IsShaderReady(*shader);
}
    
int rp_GetShaderLocation(Shader* shader, const char * uniformName) {
    return GetShaderLocation(*shader, uniformName);
}
    
int rp_GetShaderLocationAttrib(Shader* shader, const char * attribName) {
    return GetShaderLocationAttrib(*shader, attribName);
}
    
void rp_SetShaderValue(Shader* shader, int locIndex, const void * value, int uniformType) {
    SetShaderValue(*shader, locIndex, value, uniformType);
}
    
void rp_SetShaderValueV(Shader* shader, int locIndex, const void * value, int uniformType, int count) {
    SetShaderValueV(*shader, locIndex, value, uniformType, count);
}
    
void rp_SetShaderValueMatrix(Shader* shader, int locIndex, Matrix* mat) {
    SetShaderValueMatrix(*shader, locIndex, *mat);
}
    
void rp_SetShaderValueTexture(Shader* shader, int locIndex, Texture2D* texture) {
    SetShaderValueTexture(*shader, locIndex, *texture);
}
    
void rp_UnloadShader(Shader* shader) {
    UnloadShader(*shader);
}
    
void rp_GetMouseRay(Ray* output, Vector2* mousePosition, Camera* camera) {
    Ray val = GetMouseRay(*mousePosition, *camera);
    memcpy(output, &val, sizeof(Ray));
}
    
void rp_GetCameraMatrix(Matrix* output, Camera* camera) {
    Matrix val = GetCameraMatrix(*camera);
    memcpy(output, &val, sizeof(Matrix));
}
    
void rp_GetCameraMatrix2D(Matrix* output, Camera2D* camera) {
    Matrix val = GetCameraMatrix2D(*camera);
    memcpy(output, &val, sizeof(Matrix));
}
    
void rp_GetWorldToScreen(Vector2* output, Vector3* position, Camera* camera) {
    Vector2 val = GetWorldToScreen(*position, *camera);
    memcpy(output, &val, sizeof(Vector2));
}
    
void rp_GetScreenToWorld2D(Vector2* output, Vector2* position, Camera2D* camera) {
    Vector2 val = GetScreenToWorld2D(*position, *camera);
    memcpy(output, &val, sizeof(Vector2));
}
    
void rp_GetWorldToScreenEx(Vector2* output, Vector3* position, Camera* camera, int width, int height) {
    Vector2 val = GetWorldToScreenEx(*position, *camera, width, height);
    memcpy(output, &val, sizeof(Vector2));
}
    
void rp_GetWorldToScreen2D(Vector2* output, Vector2* position, Camera2D* camera) {
    Vector2 val = GetWorldToScreen2D(*position, *camera);
    memcpy(output, &val, sizeof(Vector2));
}
    
void rp_SetTargetFPS(int fps) {
    SetTargetFPS(fps);
}
    
int rp_GetFPS() {
    return GetFPS();
}
    
float rp_GetFrameTime() {
    return GetFrameTime();
}
    
double rp_GetTime() {
    return GetTime();
}
    
int rp_GetRandomValue(int min, int max) {
    return GetRandomValue(min, max);
}
    
void rp_SetRandomSeed(unsigned int seed) {
    SetRandomSeed(seed);
}
    
void rp_TakeScreenshot(const char * fileName) {
    TakeScreenshot(fileName);
}
    
void rp_SetConfigFlags(unsigned int flags) {
    SetConfigFlags(flags);
}
    
void rp_TraceLog(int logLevel, const char * text, char* args) {
    TraceLog(logLevel, text, args);
}
    
void rp_SetTraceLogLevel(int logLevel) {
    SetTraceLogLevel(logLevel);
}
    
void * rp_MemAlloc(unsigned int size) {
    return MemAlloc(size);
}
    
void * rp_MemRealloc(void * ptr, unsigned int size) {
    return MemRealloc(ptr, size);
}
    
void rp_MemFree(void * ptr) {
    MemFree(ptr);
}
    
void rp_OpenURL(const char * url) {
    OpenURL(url);
}
    
void rp_SetTraceLogCallback(TraceLogCallback callback) {
    SetTraceLogCallback(callback);
}
    
void rp_SetLoadFileDataCallback(LoadFileDataCallback callback) {
    SetLoadFileDataCallback(callback);
}
    
void rp_SetSaveFileDataCallback(SaveFileDataCallback callback) {
    SetSaveFileDataCallback(callback);
}
    
void rp_SetLoadFileTextCallback(LoadFileTextCallback callback) {
    SetLoadFileTextCallback(callback);
}
    
void rp_SetSaveFileTextCallback(SaveFileTextCallback callback) {
    SetSaveFileTextCallback(callback);
}
    
unsigned char * rp_LoadFileData(const char * fileName, unsigned int * bytesRead) {
    return LoadFileData(fileName, bytesRead);
}
    
void rp_UnloadFileData(unsigned char * data) {
    UnloadFileData(data);
}
    
bool rp_SaveFileData(const char * fileName, void * data, unsigned int bytesToWrite) {
    return SaveFileData(fileName, data, bytesToWrite);
}
    
bool rp_ExportDataAsCode(const unsigned char * data, unsigned int size, const char * fileName) {
    return ExportDataAsCode(data, size, fileName);
}
    
char * rp_LoadFileText(const char * fileName) {
    return LoadFileText(fileName);
}
    
void rp_UnloadFileText(char * text) {
    UnloadFileText(text);
}
    
bool rp_SaveFileText(const char * fileName, char * text) {
    return SaveFileText(fileName, text);
}
    
bool rp_FileExists(const char * fileName) {
    return FileExists(fileName);
}
    
bool rp_DirectoryExists(const char * dirPath) {
    return DirectoryExists(dirPath);
}
    
bool rp_IsFileExtension(const char * fileName, const char * ext) {
    return IsFileExtension(fileName, ext);
}
    
int rp_GetFileLength(const char * fileName) {
    return GetFileLength(fileName);
}
    
const char * rp_GetFileExtension(const char * fileName) {
    return GetFileExtension(fileName);
}
    
const char * rp_GetFileName(const char * filePath) {
    return GetFileName(filePath);
}
    
const char * rp_GetFileNameWithoutExt(const char * filePath) {
    return GetFileNameWithoutExt(filePath);
}
    
const char * rp_GetDirectoryPath(const char * filePath) {
    return GetDirectoryPath(filePath);
}
    
const char * rp_GetPrevDirectoryPath(const char * dirPath) {
    return GetPrevDirectoryPath(dirPath);
}
    
const char * rp_GetWorkingDirectory() {
    return GetWorkingDirectory();
}
    
const char * rp_GetApplicationDirectory() {
    return GetApplicationDirectory();
}
    
bool rp_ChangeDirectory(const char * dir) {
    return ChangeDirectory(dir);
}
    
bool rp_IsPathFile(const char * path) {
    return IsPathFile(path);
}
    
void rp_LoadDirectoryFiles(FilePathList* output, const char * dirPath) {
    FilePathList val = LoadDirectoryFiles(dirPath);
    memcpy(output, &val, sizeof(FilePathList));
}
    
void rp_LoadDirectoryFilesEx(FilePathList* output, const char * basePath, const char * filter, bool scanSubdirs) {
    FilePathList val = LoadDirectoryFilesEx(basePath, filter, scanSubdirs);
    memcpy(output, &val, sizeof(FilePathList));
}
    
void rp_UnloadDirectoryFiles(FilePathList* files) {
    UnloadDirectoryFiles(*files);
}
    
bool rp_IsFileDropped() {
    return IsFileDropped();
}
    
void rp_LoadDroppedFiles(FilePathList* output) {
    FilePathList val = LoadDroppedFiles();
    memcpy(output, &val, sizeof(FilePathList));
}
    
void rp_UnloadDroppedFiles(FilePathList* files) {
    UnloadDroppedFiles(*files);
}
    
long rp_GetFileModTime(const char * fileName) {
    return GetFileModTime(fileName);
}
    
unsigned char * rp_CompressData(const unsigned char * data, int dataSize, int * compDataSize) {
    return CompressData(data, dataSize, compDataSize);
}
    
unsigned char * rp_DecompressData(const unsigned char * compData, int compDataSize, int * dataSize) {
    return DecompressData(compData, compDataSize, dataSize);
}
    
char * rp_EncodeDataBase64(const unsigned char * data, int dataSize, int * outputSize) {
    return EncodeDataBase64(data, dataSize, outputSize);
}
    
unsigned char * rp_DecodeDataBase64(const unsigned char * data, int * outputSize) {
    return DecodeDataBase64(data, outputSize);
}
    
bool rp_IsKeyPressed(int key) {
    return IsKeyPressed(key);
}
    
bool rp_IsKeyDown(int key) {
    return IsKeyDown(key);
}
    
bool rp_IsKeyReleased(int key) {
    return IsKeyReleased(key);
}
    
bool rp_IsKeyUp(int key) {
    return IsKeyUp(key);
}
    
void rp_SetExitKey(int key) {
    SetExitKey(key);
}
    
int rp_GetKeyPressed() {
    return GetKeyPressed();
}
    
int rp_GetCharPressed() {
    return GetCharPressed();
}
    
bool rp_IsGamepadAvailable(int gamepad) {
    return IsGamepadAvailable(gamepad);
}
    
const char * rp_GetGamepadName(int gamepad) {
    return GetGamepadName(gamepad);
}
    
bool rp_IsGamepadButtonPressed(int gamepad, int button) {
    return IsGamepadButtonPressed(gamepad, button);
}
    
bool rp_IsGamepadButtonDown(int gamepad, int button) {
    return IsGamepadButtonDown(gamepad, button);
}
    
bool rp_IsGamepadButtonReleased(int gamepad, int button) {
    return IsGamepadButtonReleased(gamepad, button);
}
    
bool rp_IsGamepadButtonUp(int gamepad, int button) {
    return IsGamepadButtonUp(gamepad, button);
}
    
int rp_GetGamepadButtonPressed() {
    return GetGamepadButtonPressed();
}
    
int rp_GetGamepadAxisCount(int gamepad) {
    return GetGamepadAxisCount(gamepad);
}
    
float rp_GetGamepadAxisMovement(int gamepad, int axis) {
    return GetGamepadAxisMovement(gamepad, axis);
}
    
int rp_SetGamepadMappings(const char * mappings) {
    return SetGamepadMappings(mappings);
}
    
bool rp_IsMouseButtonPressed(int button) {
    return IsMouseButtonPressed(button);
}
    
bool rp_IsMouseButtonDown(int button) {
    return IsMouseButtonDown(button);
}
    
bool rp_IsMouseButtonReleased(int button) {
    return IsMouseButtonReleased(button);
}
    
bool rp_IsMouseButtonUp(int button) {
    return IsMouseButtonUp(button);
}
    
int rp_GetMouseX() {
    return GetMouseX();
}
    
int rp_GetMouseY() {
    return GetMouseY();
}
    
void rp_GetMousePosition(Vector2* output) {
    Vector2 val = GetMousePosition();
    memcpy(output, &val, sizeof(Vector2));
}
    
void rp_GetMouseDelta(Vector2* output) {
    Vector2 val = GetMouseDelta();
    memcpy(output, &val, sizeof(Vector2));
}
    
void rp_SetMousePosition(int x, int y) {
    SetMousePosition(x, y);
}
    
void rp_SetMouseOffset(int offsetX, int offsetY) {
    SetMouseOffset(offsetX, offsetY);
}
    
void rp_SetMouseScale(float scaleX, float scaleY) {
    SetMouseScale(scaleX, scaleY);
}
    
float rp_GetMouseWheelMove() {
    return GetMouseWheelMove();
}
    
void rp_GetMouseWheelMoveV(Vector2* output) {
    Vector2 val = GetMouseWheelMoveV();
    memcpy(output, &val, sizeof(Vector2));
}
    
void rp_SetMouseCursor(int cursor) {
    SetMouseCursor(cursor);
}
    
int rp_GetTouchX() {
    return GetTouchX();
}
    
int rp_GetTouchY() {
    return GetTouchY();
}
    
void rp_GetTouchPosition(Vector2* output, int index) {
    Vector2 val = GetTouchPosition(index);
    memcpy(output, &val, sizeof(Vector2));
}
    
int rp_GetTouchPointId(int index) {
    return GetTouchPointId(index);
}
    
int rp_GetTouchPointCount() {
    return GetTouchPointCount();
}
    
void rp_SetGesturesEnabled(unsigned int flags) {
    SetGesturesEnabled(flags);
}
    
bool rp_IsGestureDetected(int gesture) {
    return IsGestureDetected(gesture);
}
    
int rp_GetGestureDetected() {
    return GetGestureDetected();
}
    
float rp_GetGestureHoldDuration() {
    return GetGestureHoldDuration();
}
    
void rp_GetGestureDragVector(Vector2* output) {
    Vector2 val = GetGestureDragVector();
    memcpy(output, &val, sizeof(Vector2));
}
    
float rp_GetGestureDragAngle() {
    return GetGestureDragAngle();
}
    
void rp_GetGesturePinchVector(Vector2* output) {
    Vector2 val = GetGesturePinchVector();
    memcpy(output, &val, sizeof(Vector2));
}
    
float rp_GetGesturePinchAngle() {
    return GetGesturePinchAngle();
}
    
void rp_UpdateCamera(Camera * camera, int mode) {
    UpdateCamera(camera, mode);
}
    
void rp_UpdateCameraPro(Camera * camera, Vector3* movement, Vector3* rotation, float zoom) {
    UpdateCameraPro(camera, *movement, *rotation, zoom);
}
    
void rp_SetShapesTexture(Texture2D* texture, Rectangle* source) {
    SetShapesTexture(*texture, *source);
}
    
void rp_DrawPixel(int posX, int posY, Color* color) {
    DrawPixel(posX, posY, *color);
}
    
void rp_DrawPixelV(Vector2* position, Color* color) {
    DrawPixelV(*position, *color);
}
    
void rp_DrawLine(int startPosX, int startPosY, int endPosX, int endPosY, Color* color) {
    DrawLine(startPosX, startPosY, endPosX, endPosY, *color);
}
    
void rp_DrawLineV(Vector2* startPos, Vector2* endPos, Color* color) {
    DrawLineV(*startPos, *endPos, *color);
}
    
void rp_DrawLineEx(Vector2* startPos, Vector2* endPos, float thick, Color* color) {
    DrawLineEx(*startPos, *endPos, thick, *color);
}
    
void rp_DrawLineBezier(Vector2* startPos, Vector2* endPos, float thick, Color* color) {
    DrawLineBezier(*startPos, *endPos, thick, *color);
}
    
void rp_DrawLineBezierQuad(Vector2* startPos, Vector2* endPos, Vector2* controlPos, float thick, Color* color) {
    DrawLineBezierQuad(*startPos, *endPos, *controlPos, thick, *color);
}
    
void rp_DrawLineBezierCubic(Vector2* startPos, Vector2* endPos, Vector2* startControlPos, Vector2* endControlPos, float thick, Color* color) {
    DrawLineBezierCubic(*startPos, *endPos, *startControlPos, *endControlPos, thick, *color);
}
    
void rp_DrawLineStrip(Vector2 * points, int pointCount, Color* color) {
    DrawLineStrip(points, pointCount, *color);
}
    
void rp_DrawCircle(int centerX, int centerY, float radius, Color* color) {
    DrawCircle(centerX, centerY, radius, *color);
}
    
void rp_DrawCircleSector(Vector2* center, float radius, float startAngle, float endAngle, int segments, Color* color) {
    DrawCircleSector(*center, radius, startAngle, endAngle, segments, *color);
}
    
void rp_DrawCircleSectorLines(Vector2* center, float radius, float startAngle, float endAngle, int segments, Color* color) {
    DrawCircleSectorLines(*center, radius, startAngle, endAngle, segments, *color);
}
    
void rp_DrawCircleGradient(int centerX, int centerY, float radius, Color* color1, Color* color2) {
    DrawCircleGradient(centerX, centerY, radius, *color1, *color2);
}
    
void rp_DrawCircleV(Vector2* center, float radius, Color* color) {
    DrawCircleV(*center, radius, *color);
}
    
void rp_DrawCircleLines(int centerX, int centerY, float radius, Color* color) {
    DrawCircleLines(centerX, centerY, radius, *color);
}
    
void rp_DrawEllipse(int centerX, int centerY, float radiusH, float radiusV, Color* color) {
    DrawEllipse(centerX, centerY, radiusH, radiusV, *color);
}
    
void rp_DrawEllipseLines(int centerX, int centerY, float radiusH, float radiusV, Color* color) {
    DrawEllipseLines(centerX, centerY, radiusH, radiusV, *color);
}
    
void rp_DrawRing(Vector2* center, float innerRadius, float outerRadius, float startAngle, float endAngle, int segments, Color* color) {
    DrawRing(*center, innerRadius, outerRadius, startAngle, endAngle, segments, *color);
}
    
void rp_DrawRingLines(Vector2* center, float innerRadius, float outerRadius, float startAngle, float endAngle, int segments, Color* color) {
    DrawRingLines(*center, innerRadius, outerRadius, startAngle, endAngle, segments, *color);
}
    
void rp_DrawRectangle(int posX, int posY, int width, int height, Color* color) {
    DrawRectangle(posX, posY, width, height, *color);
}
    
void rp_DrawRectangleV(Vector2* position, Vector2* size, Color* color) {
    DrawRectangleV(*position, *size, *color);
}
    
void rp_DrawRectangleRec(Rectangle* rec, Color* color) {
    DrawRectangleRec(*rec, *color);
}
    
void rp_DrawRectanglePro(Rectangle* rec, Vector2* origin, float rotation, Color* color) {
    DrawRectanglePro(*rec, *origin, rotation, *color);
}
    
void rp_DrawRectangleGradientV(int posX, int posY, int width, int height, Color* color1, Color* color2) {
    DrawRectangleGradientV(posX, posY, width, height, *color1, *color2);
}
    
void rp_DrawRectangleGradientH(int posX, int posY, int width, int height, Color* color1, Color* color2) {
    DrawRectangleGradientH(posX, posY, width, height, *color1, *color2);
}
    
void rp_DrawRectangleGradientEx(Rectangle* rec, Color* col1, Color* col2, Color* col3, Color* col4) {
    DrawRectangleGradientEx(*rec, *col1, *col2, *col3, *col4);
}
    
void rp_DrawRectangleLines(int posX, int posY, int width, int height, Color* color) {
    DrawRectangleLines(posX, posY, width, height, *color);
}
    
void rp_DrawRectangleLinesEx(Rectangle* rec, float lineThick, Color* color) {
    DrawRectangleLinesEx(*rec, lineThick, *color);
}
    
void rp_DrawRectangleRounded(Rectangle* rec, float roundness, int segments, Color* color) {
    DrawRectangleRounded(*rec, roundness, segments, *color);
}
    
void rp_DrawRectangleRoundedLines(Rectangle* rec, float roundness, int segments, float lineThick, Color* color) {
    DrawRectangleRoundedLines(*rec, roundness, segments, lineThick, *color);
}
    
void rp_DrawTriangle(Vector2* v1, Vector2* v2, Vector2* v3, Color* color) {
    DrawTriangle(*v1, *v2, *v3, *color);
}
    
void rp_DrawTriangleLines(Vector2* v1, Vector2* v2, Vector2* v3, Color* color) {
    DrawTriangleLines(*v1, *v2, *v3, *color);
}
    
void rp_DrawTriangleFan(Vector2 * points, int pointCount, Color* color) {
    DrawTriangleFan(points, pointCount, *color);
}
    
void rp_DrawTriangleStrip(Vector2 * points, int pointCount, Color* color) {
    DrawTriangleStrip(points, pointCount, *color);
}
    
void rp_DrawPoly(Vector2* center, int sides, float radius, float rotation, Color* color) {
    DrawPoly(*center, sides, radius, rotation, *color);
}
    
void rp_DrawPolyLines(Vector2* center, int sides, float radius, float rotation, Color* color) {
    DrawPolyLines(*center, sides, radius, rotation, *color);
}
    
void rp_DrawPolyLinesEx(Vector2* center, int sides, float radius, float rotation, float lineThick, Color* color) {
    DrawPolyLinesEx(*center, sides, radius, rotation, lineThick, *color);
}
    
bool rp_CheckCollisionRecs(Rectangle* rec1, Rectangle* rec2) {
    return CheckCollisionRecs(*rec1, *rec2);
}
    
bool rp_CheckCollisionCircles(Vector2* center1, float radius1, Vector2* center2, float radius2) {
    return CheckCollisionCircles(*center1, radius1, *center2, radius2);
}
    
bool rp_CheckCollisionCircleRec(Vector2* center, float radius, Rectangle* rec) {
    return CheckCollisionCircleRec(*center, radius, *rec);
}
    
bool rp_CheckCollisionPointRec(Vector2* point, Rectangle* rec) {
    return CheckCollisionPointRec(*point, *rec);
}
    
bool rp_CheckCollisionPointCircle(Vector2* point, Vector2* center, float radius) {
    return CheckCollisionPointCircle(*point, *center, radius);
}
    
bool rp_CheckCollisionPointTriangle(Vector2* point, Vector2* p1, Vector2* p2, Vector2* p3) {
    return CheckCollisionPointTriangle(*point, *p1, *p2, *p3);
}
    
bool rp_CheckCollisionPointPoly(Vector2* point, Vector2 * points, int pointCount) {
    return CheckCollisionPointPoly(*point, points, pointCount);
}
    
bool rp_CheckCollisionLines(Vector2* startPos1, Vector2* endPos1, Vector2* startPos2, Vector2* endPos2, Vector2 * collisionPoint) {
    return CheckCollisionLines(*startPos1, *endPos1, *startPos2, *endPos2, collisionPoint);
}
    
bool rp_CheckCollisionPointLine(Vector2* point, Vector2* p1, Vector2* p2, int threshold) {
    return CheckCollisionPointLine(*point, *p1, *p2, threshold);
}
    
void rp_GetCollisionRec(Rectangle* output, Rectangle* rec1, Rectangle* rec2) {
    Rectangle val = GetCollisionRec(*rec1, *rec2);
    memcpy(output, &val, sizeof(Rectangle));
}
    
void rp_LoadImage(Image* output, const char * fileName) {
    Image val = LoadImage(fileName);
    memcpy(output, &val, sizeof(Image));
}
    
void rp_LoadImageRaw(Image* output, const char * fileName, int width, int height, int format, int headerSize) {
    Image val = LoadImageRaw(fileName, width, height, format, headerSize);
    memcpy(output, &val, sizeof(Image));
}
    
void rp_LoadImageAnim(Image* output, const char * fileName, int * frames) {
    Image val = LoadImageAnim(fileName, frames);
    memcpy(output, &val, sizeof(Image));
}
    
void rp_LoadImageFromMemory(Image* output, const char * fileType, const unsigned char * fileData, int dataSize) {
    Image val = LoadImageFromMemory(fileType, fileData, dataSize);
    memcpy(output, &val, sizeof(Image));
}
    
void rp_LoadImageFromTexture(Image* output, Texture2D* texture) {
    Image val = LoadImageFromTexture(*texture);
    memcpy(output, &val, sizeof(Image));
}
    
void rp_LoadImageFromScreen(Image* output) {
    Image val = LoadImageFromScreen();
    memcpy(output, &val, sizeof(Image));
}
    
bool rp_IsImageReady(Image* image) {
    return IsImageReady(*image);
}
    
void rp_UnloadImage(Image* image) {
    UnloadImage(*image);
}
    
bool rp_ExportImage(Image* image, const char * fileName) {
    return ExportImage(*image, fileName);
}
    
bool rp_ExportImageAsCode(Image* image, const char * fileName) {
    return ExportImageAsCode(*image, fileName);
}
    
void rp_GenImageColor(Image* output, int width, int height, Color* color) {
    Image val = GenImageColor(width, height, *color);
    memcpy(output, &val, sizeof(Image));
}
    
void rp_GenImageGradientV(Image* output, int width, int height, Color* top, Color* bottom) {
    Image val = GenImageGradientV(width, height, *top, *bottom);
    memcpy(output, &val, sizeof(Image));
}
    
void rp_GenImageGradientH(Image* output, int width, int height, Color* left, Color* right) {
    Image val = GenImageGradientH(width, height, *left, *right);
    memcpy(output, &val, sizeof(Image));
}
    
void rp_GenImageGradientRadial(Image* output, int width, int height, float density, Color* inner, Color* outer) {
    Image val = GenImageGradientRadial(width, height, density, *inner, *outer);
    memcpy(output, &val, sizeof(Image));
}
    
void rp_GenImageChecked(Image* output, int width, int height, int checksX, int checksY, Color* col1, Color* col2) {
    Image val = GenImageChecked(width, height, checksX, checksY, *col1, *col2);
    memcpy(output, &val, sizeof(Image));
}
    
void rp_GenImageWhiteNoise(Image* output, int width, int height, float factor) {
    Image val = GenImageWhiteNoise(width, height, factor);
    memcpy(output, &val, sizeof(Image));
}
    
void rp_GenImagePerlinNoise(Image* output, int width, int height, int offsetX, int offsetY, float scale) {
    Image val = GenImagePerlinNoise(width, height, offsetX, offsetY, scale);
    memcpy(output, &val, sizeof(Image));
}
    
void rp_GenImageCellular(Image* output, int width, int height, int tileSize) {
    Image val = GenImageCellular(width, height, tileSize);
    memcpy(output, &val, sizeof(Image));
}
    
void rp_GenImageText(Image* output, int width, int height, const char * text) {
    Image val = GenImageText(width, height, text);
    memcpy(output, &val, sizeof(Image));
}
    
void rp_ImageCopy(Image* output, Image* image) {
    Image val = ImageCopy(*image);
    memcpy(output, &val, sizeof(Image));
}
    
void rp_ImageFromImage(Image* output, Image* image, Rectangle* rec) {
    Image val = ImageFromImage(*image, *rec);
    memcpy(output, &val, sizeof(Image));
}
    
void rp_ImageText(Image* output, const char * text, int fontSize, Color* color) {
    Image val = ImageText(text, fontSize, *color);
    memcpy(output, &val, sizeof(Image));
}
    
void rp_ImageTextEx(Image* output, Font* font, const char * text, float fontSize, float spacing, Color* tint) {
    Image val = ImageTextEx(*font, text, fontSize, spacing, *tint);
    memcpy(output, &val, sizeof(Image));
}
    
void rp_ImageFormat(Image * image, int newFormat) {
    ImageFormat(image, newFormat);
}
    
void rp_ImageToPOT(Image * image, Color* fill) {
    ImageToPOT(image, *fill);
}
    
void rp_ImageCrop(Image * image, Rectangle* crop) {
    ImageCrop(image, *crop);
}
    
void rp_ImageAlphaCrop(Image * image, float threshold) {
    ImageAlphaCrop(image, threshold);
}
    
void rp_ImageAlphaClear(Image * image, Color* color, float threshold) {
    ImageAlphaClear(image, *color, threshold);
}
    
void rp_ImageAlphaMask(Image * image, Image* alphaMask) {
    ImageAlphaMask(image, *alphaMask);
}
    
void rp_ImageAlphaPremultiply(Image * image) {
    ImageAlphaPremultiply(image);
}
    
void rp_ImageBlurGaussian(Image * image, int blurSize) {
    ImageBlurGaussian(image, blurSize);
}
    
void rp_ImageResize(Image * image, int newWidth, int newHeight) {
    ImageResize(image, newWidth, newHeight);
}
    
void rp_ImageResizeNN(Image * image, int newWidth, int newHeight) {
    ImageResizeNN(image, newWidth, newHeight);
}
    
void rp_ImageResizeCanvas(Image * image, int newWidth, int newHeight, int offsetX, int offsetY, Color* fill) {
    ImageResizeCanvas(image, newWidth, newHeight, offsetX, offsetY, *fill);
}
    
void rp_ImageMipmaps(Image * image) {
    ImageMipmaps(image);
}
    
void rp_ImageDither(Image * image, int rBpp, int gBpp, int bBpp, int aBpp) {
    ImageDither(image, rBpp, gBpp, bBpp, aBpp);
}
    
void rp_ImageFlipVertical(Image * image) {
    ImageFlipVertical(image);
}
    
void rp_ImageFlipHorizontal(Image * image) {
    ImageFlipHorizontal(image);
}
    
void rp_ImageRotateCW(Image * image) {
    ImageRotateCW(image);
}
    
void rp_ImageRotateCCW(Image * image) {
    ImageRotateCCW(image);
}
    
void rp_ImageColorTint(Image * image, Color* color) {
    ImageColorTint(image, *color);
}
    
void rp_ImageColorInvert(Image * image) {
    ImageColorInvert(image);
}
    
void rp_ImageColorGrayscale(Image * image) {
    ImageColorGrayscale(image);
}
    
void rp_ImageColorContrast(Image * image, float contrast) {
    ImageColorContrast(image, contrast);
}
    
void rp_ImageColorBrightness(Image * image, int brightness) {
    ImageColorBrightness(image, brightness);
}
    
void rp_ImageColorReplace(Image * image, Color* color, Color* replace) {
    ImageColorReplace(image, *color, *replace);
}
    
Color * rp_LoadImageColors(Image* image) {
    return LoadImageColors(*image);
}
    
Color * rp_LoadImagePalette(Image* image, int maxPaletteSize, int * colorCount) {
    return LoadImagePalette(*image, maxPaletteSize, colorCount);
}
    
void rp_UnloadImageColors(Color * colors) {
    UnloadImageColors(colors);
}
    
void rp_UnloadImagePalette(Color * colors) {
    UnloadImagePalette(colors);
}
    
void rp_GetImageAlphaBorder(Rectangle* output, Image* image, float threshold) {
    Rectangle val = GetImageAlphaBorder(*image, threshold);
    memcpy(output, &val, sizeof(Rectangle));
}
    
void rp_GetImageColor(Color* output, Image* image, int x, int y) {
    Color val = GetImageColor(*image, x, y);
    memcpy(output, &val, sizeof(Color));
}
    
void rp_ImageClearBackground(Image * dst, Color* color) {
    ImageClearBackground(dst, *color);
}
    
void rp_ImageDrawPixel(Image * dst, int posX, int posY, Color* color) {
    ImageDrawPixel(dst, posX, posY, *color);
}
    
void rp_ImageDrawPixelV(Image * dst, Vector2* position, Color* color) {
    ImageDrawPixelV(dst, *position, *color);
}
    
void rp_ImageDrawLine(Image * dst, int startPosX, int startPosY, int endPosX, int endPosY, Color* color) {
    ImageDrawLine(dst, startPosX, startPosY, endPosX, endPosY, *color);
}
    
void rp_ImageDrawLineV(Image * dst, Vector2* start, Vector2* end, Color* color) {
    ImageDrawLineV(dst, *start, *end, *color);
}
    
void rp_ImageDrawCircle(Image * dst, int centerX, int centerY, int radius, Color* color) {
    ImageDrawCircle(dst, centerX, centerY, radius, *color);
}
    
void rp_ImageDrawCircleV(Image * dst, Vector2* center, int radius, Color* color) {
    ImageDrawCircleV(dst, *center, radius, *color);
}
    
void rp_ImageDrawCircleLines(Image * dst, int centerX, int centerY, int radius, Color* color) {
    ImageDrawCircleLines(dst, centerX, centerY, radius, *color);
}
    
void rp_ImageDrawCircleLinesV(Image * dst, Vector2* center, int radius, Color* color) {
    ImageDrawCircleLinesV(dst, *center, radius, *color);
}
    
void rp_ImageDrawRectangle(Image * dst, int posX, int posY, int width, int height, Color* color) {
    ImageDrawRectangle(dst, posX, posY, width, height, *color);
}
    
void rp_ImageDrawRectangleV(Image * dst, Vector2* position, Vector2* size, Color* color) {
    ImageDrawRectangleV(dst, *position, *size, *color);
}
    
void rp_ImageDrawRectangleRec(Image * dst, Rectangle* rec, Color* color) {
    ImageDrawRectangleRec(dst, *rec, *color);
}
    
void rp_ImageDrawRectangleLines(Image * dst, Rectangle* rec, int thick, Color* color) {
    ImageDrawRectangleLines(dst, *rec, thick, *color);
}
    
void rp_ImageDraw(Image * dst, Image* src, Rectangle* srcRec, Rectangle* dstRec, Color* tint) {
    ImageDraw(dst, *src, *srcRec, *dstRec, *tint);
}
    
void rp_ImageDrawText(Image * dst, const char * text, int posX, int posY, int fontSize, Color* color) {
    ImageDrawText(dst, text, posX, posY, fontSize, *color);
}
    
void rp_ImageDrawTextEx(Image * dst, Font* font, const char * text, Vector2* position, float fontSize, float spacing, Color* tint) {
    ImageDrawTextEx(dst, *font, text, *position, fontSize, spacing, *tint);
}
    
void rp_LoadTexture(Texture2D* output, const char * fileName) {
    Texture2D val = LoadTexture(fileName);
    memcpy(output, &val, sizeof(Texture2D));
}
    
void rp_LoadTextureFromImage(Texture2D* output, Image* image) {
    Texture2D val = LoadTextureFromImage(*image);
    memcpy(output, &val, sizeof(Texture2D));
}
    
void rp_LoadTextureCubemap(TextureCubemap* output, Image* image, int layout) {
    TextureCubemap val = LoadTextureCubemap(*image, layout);
    memcpy(output, &val, sizeof(TextureCubemap));
}
    
void rp_LoadRenderTexture(RenderTexture2D* output, int width, int height) {
    RenderTexture2D val = LoadRenderTexture(width, height);
    memcpy(output, &val, sizeof(RenderTexture2D));
}
    
bool rp_IsTextureReady(Texture2D* texture) {
    return IsTextureReady(*texture);
}
    
void rp_UnloadTexture(Texture2D* texture) {
    UnloadTexture(*texture);
}
    
bool rp_IsRenderTextureReady(RenderTexture2D* target) {
    return IsRenderTextureReady(*target);
}
    
void rp_UnloadRenderTexture(RenderTexture2D* target) {
    UnloadRenderTexture(*target);
}
    
void rp_UpdateTexture(Texture2D* texture, const void * pixels) {
    UpdateTexture(*texture, pixels);
}
    
void rp_UpdateTextureRec(Texture2D* texture, Rectangle* rec, const void * pixels) {
    UpdateTextureRec(*texture, *rec, pixels);
}
    
void rp_GenTextureMipmaps(Texture2D * texture) {
    GenTextureMipmaps(texture);
}
    
void rp_SetTextureFilter(Texture2D* texture, int filter) {
    SetTextureFilter(*texture, filter);
}
    
void rp_SetTextureWrap(Texture2D* texture, int wrap) {
    SetTextureWrap(*texture, wrap);
}
    
void rp_DrawTexture(Texture2D* texture, int posX, int posY, Color* tint) {
    DrawTexture(*texture, posX, posY, *tint);
}
    
void rp_DrawTextureV(Texture2D* texture, Vector2* position, Color* tint) {
    DrawTextureV(*texture, *position, *tint);
}
    
void rp_DrawTextureEx(Texture2D* texture, Vector2* position, float rotation, float scale, Color* tint) {
    DrawTextureEx(*texture, *position, rotation, scale, *tint);
}
    
void rp_DrawTextureRec(Texture2D* texture, Rectangle* source, Vector2* position, Color* tint) {
    DrawTextureRec(*texture, *source, *position, *tint);
}
    
void rp_DrawTexturePro(Texture2D* texture, Rectangle* source, Rectangle* dest, Vector2* origin, float rotation, Color* tint) {
    DrawTexturePro(*texture, *source, *dest, *origin, rotation, *tint);
}
    
void rp_DrawTextureNPatch(Texture2D* texture, NPatchInfo* nPatchInfo, Rectangle* dest, Vector2* origin, float rotation, Color* tint) {
    DrawTextureNPatch(*texture, *nPatchInfo, *dest, *origin, rotation, *tint);
}
    
void rp_Fade(Color* output, Color* color, float alpha) {
    Color val = Fade(*color, alpha);
    memcpy(output, &val, sizeof(Color));
}
    
int rp_ColorToInt(Color* color) {
    return ColorToInt(*color);
}
    
void rp_ColorNormalize(Vector4* output, Color* color) {
    Vector4 val = ColorNormalize(*color);
    memcpy(output, &val, sizeof(Vector4));
}
    
void rp_ColorFromNormalized(Color* output, Vector4* normalized) {
    Color val = ColorFromNormalized(*normalized);
    memcpy(output, &val, sizeof(Color));
}
    
void rp_ColorToHSV(Vector3* output, Color* color) {
    Vector3 val = ColorToHSV(*color);
    memcpy(output, &val, sizeof(Vector3));
}
    
void rp_ColorFromHSV(Color* output, float hue, float saturation, float value) {
    Color val = ColorFromHSV(hue, saturation, value);
    memcpy(output, &val, sizeof(Color));
}
    
void rp_ColorTint(Color* output, Color* color, Color* tint) {
    Color val = ColorTint(*color, *tint);
    memcpy(output, &val, sizeof(Color));
}
    
void rp_ColorBrightness(Color* output, Color* color, float factor) {
    Color val = ColorBrightness(*color, factor);
    memcpy(output, &val, sizeof(Color));
}
    
void rp_ColorContrast(Color* output, Color* color, float contrast) {
    Color val = ColorContrast(*color, contrast);
    memcpy(output, &val, sizeof(Color));
}
    
void rp_ColorAlpha(Color* output, Color* color, float alpha) {
    Color val = ColorAlpha(*color, alpha);
    memcpy(output, &val, sizeof(Color));
}
    
void rp_ColorAlphaBlend(Color* output, Color* dst, Color* src, Color* tint) {
    Color val = ColorAlphaBlend(*dst, *src, *tint);
    memcpy(output, &val, sizeof(Color));
}
    
void rp_GetColor(Color* output, unsigned int hexValue) {
    Color val = GetColor(hexValue);
    memcpy(output, &val, sizeof(Color));
}
    
void rp_GetPixelColor(Color* output, void * srcPtr, int format) {
    Color val = GetPixelColor(srcPtr, format);
    memcpy(output, &val, sizeof(Color));
}
    
void rp_SetPixelColor(void * dstPtr, Color* color, int format) {
    SetPixelColor(dstPtr, *color, format);
}
    
int rp_GetPixelDataSize(int width, int height, int format) {
    return GetPixelDataSize(width, height, format);
}
    
void rp_GetFontDefault(Font* output) {
    Font val = GetFontDefault();
    memcpy(output, &val, sizeof(Font));
}
    
void rp_LoadFont(Font* output, const char * fileName) {
    Font val = LoadFont(fileName);
    memcpy(output, &val, sizeof(Font));
}
    
void rp_LoadFontEx(Font* output, const char * fileName, int fontSize, int * fontChars, int glyphCount) {
    Font val = LoadFontEx(fileName, fontSize, fontChars, glyphCount);
    memcpy(output, &val, sizeof(Font));
}
    
void rp_LoadFontFromImage(Font* output, Image* image, Color* key, int firstChar) {
    Font val = LoadFontFromImage(*image, *key, firstChar);
    memcpy(output, &val, sizeof(Font));
}
    
void rp_LoadFontFromMemory(Font* output, const char * fileType, const unsigned char * fileData, int dataSize, int fontSize, int * fontChars, int glyphCount) {
    Font val = LoadFontFromMemory(fileType, fileData, dataSize, fontSize, fontChars, glyphCount);
    memcpy(output, &val, sizeof(Font));
}
    
bool rp_IsFontReady(Font* font) {
    return IsFontReady(*font);
}
    
GlyphInfo * rp_LoadFontData(const unsigned char * fileData, int dataSize, int fontSize, int * fontChars, int glyphCount, int type) {
    return LoadFontData(fileData, dataSize, fontSize, fontChars, glyphCount, type);
}
    
void rp_GenImageFontAtlas(Image* output, const GlyphInfo * chars, Rectangle ** recs, int glyphCount, int fontSize, int padding, int packMethod) {
    Image val = GenImageFontAtlas(chars, recs, glyphCount, fontSize, padding, packMethod);
    memcpy(output, &val, sizeof(Image));
}
    
void rp_UnloadFontData(GlyphInfo * chars, int glyphCount) {
    UnloadFontData(chars, glyphCount);
}
    
void rp_UnloadFont(Font* font) {
    UnloadFont(*font);
}
    
bool rp_ExportFontAsCode(Font* font, const char * fileName) {
    return ExportFontAsCode(*font, fileName);
}
    
void rp_DrawFPS(int posX, int posY) {
    DrawFPS(posX, posY);
}
    
void rp_DrawText(const char * text, int posX, int posY, int fontSize, Color* color) {
    DrawText(text, posX, posY, fontSize, *color);
}
    
void rp_DrawTextEx(Font* font, const char * text, Vector2* position, float fontSize, float spacing, Color* tint) {
    DrawTextEx(*font, text, *position, fontSize, spacing, *tint);
}
    
void rp_DrawTextPro(Font* font, const char * text, Vector2* position, Vector2* origin, float rotation, float fontSize, float spacing, Color* tint) {
    DrawTextPro(*font, text, *position, *origin, rotation, fontSize, spacing, *tint);
}
    
void rp_DrawTextCodepoint(Font* font, int codepoint, Vector2* position, float fontSize, Color* tint) {
    DrawTextCodepoint(*font, codepoint, *position, fontSize, *tint);
}
    
void rp_DrawTextCodepoints(Font* font, const int * codepoints, int count, Vector2* position, float fontSize, float spacing, Color* tint) {
    DrawTextCodepoints(*font, codepoints, count, *position, fontSize, spacing, *tint);
}
    
int rp_MeasureText(const char * text, int fontSize) {
    return MeasureText(text, fontSize);
}
    
void rp_MeasureTextEx(Vector2* output, Font* font, const char * text, float fontSize, float spacing) {
    Vector2 val = MeasureTextEx(*font, text, fontSize, spacing);
    memcpy(output, &val, sizeof(Vector2));
}
    
int rp_GetGlyphIndex(Font* font, int codepoint) {
    return GetGlyphIndex(*font, codepoint);
}
    
void rp_GetGlyphInfo(GlyphInfo* output, Font* font, int codepoint) {
    GlyphInfo val = GetGlyphInfo(*font, codepoint);
    memcpy(output, &val, sizeof(GlyphInfo));
}
    
void rp_GetGlyphAtlasRec(Rectangle* output, Font* font, int codepoint) {
    Rectangle val = GetGlyphAtlasRec(*font, codepoint);
    memcpy(output, &val, sizeof(Rectangle));
}
    
char * rp_LoadUTF8(const int * codepoints, int length) {
    return LoadUTF8(codepoints, length);
}
    
void rp_UnloadUTF8(char * text) {
    UnloadUTF8(text);
}
    
int * rp_LoadCodepoints(const char * text, int * count) {
    return LoadCodepoints(text, count);
}
    
void rp_UnloadCodepoints(int * codepoints) {
    UnloadCodepoints(codepoints);
}
    
int rp_GetCodepointCount(const char * text) {
    return GetCodepointCount(text);
}
    
int rp_GetCodepoint(const char * text, int * codepointSize) {
    return GetCodepoint(text, codepointSize);
}
    
int rp_GetCodepointNext(const char * text, int * codepointSize) {
    return GetCodepointNext(text, codepointSize);
}
    
int rp_GetCodepointPrevious(const char * text, int * codepointSize) {
    return GetCodepointPrevious(text, codepointSize);
}
    
const char * rp_CodepointToUTF8(int codepoint, int * utf8Size) {
    return CodepointToUTF8(codepoint, utf8Size);
}
    
int rp_TextCopy(char * dst, const char * src) {
    return TextCopy(dst, src);
}
    
bool rp_TextIsEqual(const char * text1, const char * text2) {
    return TextIsEqual(text1, text2);
}
    
unsigned int rp_TextLength(const char * text) {
    return TextLength(text);
}
    
const char * rp_TextFormat(const char * text, char* args) {
    return TextFormat(text, args);
}
    
const char * rp_TextSubtext(const char * text, int position, int length) {
    return TextSubtext(text, position, length);
}
    
char * rp_TextReplace(char * text, const char * replace, const char * by) {
    return TextReplace(text, replace, by);
}
    
char * rp_TextInsert(const char * text, const char * insert, int position) {
    return TextInsert(text, insert, position);
}
    
const char * rp_TextJoin(const char ** textList, int count, const char * delimiter) {
    return TextJoin(textList, count, delimiter);
}
    
const char ** rp_TextSplit(const char * text, char delimiter, int * count) {
    return TextSplit(text, delimiter, count);
}
    
void rp_TextAppend(char * text, const char * append, int * position) {
    TextAppend(text, append, position);
}
    
int rp_TextFindIndex(const char * text, const char * find) {
    return TextFindIndex(text, find);
}
    
const char * rp_TextToUpper(const char * text) {
    return TextToUpper(text);
}
    
const char * rp_TextToLower(const char * text) {
    return TextToLower(text);
}
    
const char * rp_TextToPascal(const char * text) {
    return TextToPascal(text);
}
    
int rp_TextToInteger(const char * text) {
    return TextToInteger(text);
}
    
void rp_DrawLine3D(Vector3* startPos, Vector3* endPos, Color* color) {
    DrawLine3D(*startPos, *endPos, *color);
}
    
void rp_DrawPoint3D(Vector3* position, Color* color) {
    DrawPoint3D(*position, *color);
}
    
void rp_DrawCircle3D(Vector3* center, float radius, Vector3* rotationAxis, float rotationAngle, Color* color) {
    DrawCircle3D(*center, radius, *rotationAxis, rotationAngle, *color);
}
    
void rp_DrawTriangle3D(Vector3* v1, Vector3* v2, Vector3* v3, Color* color) {
    DrawTriangle3D(*v1, *v2, *v3, *color);
}
    
void rp_DrawTriangleStrip3D(Vector3 * points, int pointCount, Color* color) {
    DrawTriangleStrip3D(points, pointCount, *color);
}
    
void rp_DrawCube(Vector3* position, float width, float height, float length, Color* color) {
    DrawCube(*position, width, height, length, *color);
}
    
void rp_DrawCubeV(Vector3* position, Vector3* size, Color* color) {
    DrawCubeV(*position, *size, *color);
}
    
void rp_DrawCubeWires(Vector3* position, float width, float height, float length, Color* color) {
    DrawCubeWires(*position, width, height, length, *color);
}
    
void rp_DrawCubeWiresV(Vector3* position, Vector3* size, Color* color) {
    DrawCubeWiresV(*position, *size, *color);
}
    
void rp_DrawSphere(Vector3* centerPos, float radius, Color* color) {
    DrawSphere(*centerPos, radius, *color);
}
    
void rp_DrawSphereEx(Vector3* centerPos, float radius, int rings, int slices, Color* color) {
    DrawSphereEx(*centerPos, radius, rings, slices, *color);
}
    
void rp_DrawSphereWires(Vector3* centerPos, float radius, int rings, int slices, Color* color) {
    DrawSphereWires(*centerPos, radius, rings, slices, *color);
}
    
void rp_DrawCylinder(Vector3* position, float radiusTop, float radiusBottom, float height, int slices, Color* color) {
    DrawCylinder(*position, radiusTop, radiusBottom, height, slices, *color);
}
    
void rp_DrawCylinderEx(Vector3* startPos, Vector3* endPos, float startRadius, float endRadius, int sides, Color* color) {
    DrawCylinderEx(*startPos, *endPos, startRadius, endRadius, sides, *color);
}
    
void rp_DrawCylinderWires(Vector3* position, float radiusTop, float radiusBottom, float height, int slices, Color* color) {
    DrawCylinderWires(*position, radiusTop, radiusBottom, height, slices, *color);
}
    
void rp_DrawCylinderWiresEx(Vector3* startPos, Vector3* endPos, float startRadius, float endRadius, int sides, Color* color) {
    DrawCylinderWiresEx(*startPos, *endPos, startRadius, endRadius, sides, *color);
}
    
void rp_DrawCapsule(Vector3* startPos, Vector3* endPos, float radius, int slices, int rings, Color* color) {
    DrawCapsule(*startPos, *endPos, radius, slices, rings, *color);
}
    
void rp_DrawCapsuleWires(Vector3* startPos, Vector3* endPos, float radius, int slices, int rings, Color* color) {
    DrawCapsuleWires(*startPos, *endPos, radius, slices, rings, *color);
}
    
void rp_DrawPlane(Vector3* centerPos, Vector2* size, Color* color) {
    DrawPlane(*centerPos, *size, *color);
}
    
void rp_DrawRay(Ray* ray, Color* color) {
    DrawRay(*ray, *color);
}
    
void rp_DrawGrid(int slices, float spacing) {
    DrawGrid(slices, spacing);
}
    
void rp_LoadModel(Model* output, const char * fileName) {
    Model val = LoadModel(fileName);
    memcpy(output, &val, sizeof(Model));
}
    
void rp_LoadModelFromMesh(Model* output, Mesh* mesh) {
    Model val = LoadModelFromMesh(*mesh);
    memcpy(output, &val, sizeof(Model));
}
    
bool rp_IsModelReady(Model* model) {
    return IsModelReady(*model);
}
    
void rp_UnloadModel(Model* model) {
    UnloadModel(*model);
}
    
void rp_GetModelBoundingBox(BoundingBox* output, Model* model) {
    BoundingBox val = GetModelBoundingBox(*model);
    memcpy(output, &val, sizeof(BoundingBox));
}
    
void rp_DrawModel(Model* model, Vector3* position, float scale, Color* tint) {
    DrawModel(*model, *position, scale, *tint);
}
    
void rp_DrawModelEx(Model* model, Vector3* position, Vector3* rotationAxis, float rotationAngle, Vector3* scale, Color* tint) {
    DrawModelEx(*model, *position, *rotationAxis, rotationAngle, *scale, *tint);
}
    
void rp_DrawModelWires(Model* model, Vector3* position, float scale, Color* tint) {
    DrawModelWires(*model, *position, scale, *tint);
}
    
void rp_DrawModelWiresEx(Model* model, Vector3* position, Vector3* rotationAxis, float rotationAngle, Vector3* scale, Color* tint) {
    DrawModelWiresEx(*model, *position, *rotationAxis, rotationAngle, *scale, *tint);
}
    
void rp_DrawBoundingBox(BoundingBox* box, Color* color) {
    DrawBoundingBox(*box, *color);
}
    
void rp_DrawBillboard(Camera* camera, Texture2D* texture, Vector3* position, float size, Color* tint) {
    DrawBillboard(*camera, *texture, *position, size, *tint);
}
    
void rp_DrawBillboardRec(Camera* camera, Texture2D* texture, Rectangle* source, Vector3* position, Vector2* size, Color* tint) {
    DrawBillboardRec(*camera, *texture, *source, *position, *size, *tint);
}
    
void rp_DrawBillboardPro(Camera* camera, Texture2D* texture, Rectangle* source, Vector3* position, Vector3* up, Vector2* size, Vector2* origin, float rotation, Color* tint) {
    DrawBillboardPro(*camera, *texture, *source, *position, *up, *size, *origin, rotation, *tint);
}
    
void rp_UploadMesh(Mesh * mesh, bool dynamic) {
    UploadMesh(mesh, dynamic);
}
    
void rp_UpdateMeshBuffer(Mesh* mesh, int index, const void * data, int dataSize, int offset) {
    UpdateMeshBuffer(*mesh, index, data, dataSize, offset);
}
    
void rp_UnloadMesh(Mesh* mesh) {
    UnloadMesh(*mesh);
}
    
void rp_DrawMesh(Mesh* mesh, Material* material, Matrix* transform) {
    DrawMesh(*mesh, *material, *transform);
}
    
void rp_DrawMeshInstanced(Mesh* mesh, Material* material, const Matrix * transforms, int instances) {
    DrawMeshInstanced(*mesh, *material, transforms, instances);
}
    
bool rp_ExportMesh(Mesh* mesh, const char * fileName) {
    return ExportMesh(*mesh, fileName);
}
    
void rp_GetMeshBoundingBox(BoundingBox* output, Mesh* mesh) {
    BoundingBox val = GetMeshBoundingBox(*mesh);
    memcpy(output, &val, sizeof(BoundingBox));
}
    
void rp_GenMeshTangents(Mesh * mesh) {
    GenMeshTangents(mesh);
}
    
void rp_GenMeshPoly(Mesh* output, int sides, float radius) {
    Mesh val = GenMeshPoly(sides, radius);
    memcpy(output, &val, sizeof(Mesh));
}
    
void rp_GenMeshPlane(Mesh* output, float width, float length, int resX, int resZ) {
    Mesh val = GenMeshPlane(width, length, resX, resZ);
    memcpy(output, &val, sizeof(Mesh));
}
    
void rp_GenMeshCube(Mesh* output, float width, float height, float length) {
    Mesh val = GenMeshCube(width, height, length);
    memcpy(output, &val, sizeof(Mesh));
}
    
void rp_GenMeshSphere(Mesh* output, float radius, int rings, int slices) {
    Mesh val = GenMeshSphere(radius, rings, slices);
    memcpy(output, &val, sizeof(Mesh));
}
    
void rp_GenMeshHemiSphere(Mesh* output, float radius, int rings, int slices) {
    Mesh val = GenMeshHemiSphere(radius, rings, slices);
    memcpy(output, &val, sizeof(Mesh));
}
    
void rp_GenMeshCylinder(Mesh* output, float radius, float height, int slices) {
    Mesh val = GenMeshCylinder(radius, height, slices);
    memcpy(output, &val, sizeof(Mesh));
}
    
void rp_GenMeshCone(Mesh* output, float radius, float height, int slices) {
    Mesh val = GenMeshCone(radius, height, slices);
    memcpy(output, &val, sizeof(Mesh));
}
    
void rp_GenMeshTorus(Mesh* output, float radius, float size, int radSeg, int sides) {
    Mesh val = GenMeshTorus(radius, size, radSeg, sides);
    memcpy(output, &val, sizeof(Mesh));
}
    
void rp_GenMeshKnot(Mesh* output, float radius, float size, int radSeg, int sides) {
    Mesh val = GenMeshKnot(radius, size, radSeg, sides);
    memcpy(output, &val, sizeof(Mesh));
}
    
void rp_GenMeshHeightmap(Mesh* output, Image* heightmap, Vector3* size) {
    Mesh val = GenMeshHeightmap(*heightmap, *size);
    memcpy(output, &val, sizeof(Mesh));
}
    
void rp_GenMeshCubicmap(Mesh* output, Image* cubicmap, Vector3* cubeSize) {
    Mesh val = GenMeshCubicmap(*cubicmap, *cubeSize);
    memcpy(output, &val, sizeof(Mesh));
}
    
Material * rp_LoadMaterials(const char * fileName, int * materialCount) {
    return LoadMaterials(fileName, materialCount);
}
    
void rp_LoadMaterialDefault(Material* output) {
    Material val = LoadMaterialDefault();
    memcpy(output, &val, sizeof(Material));
}
    
bool rp_IsMaterialReady(Material* material) {
    return IsMaterialReady(*material);
}
    
void rp_UnloadMaterial(Material* material) {
    UnloadMaterial(*material);
}
    
void rp_SetMaterialTexture(Material * material, int mapType, Texture2D* texture) {
    SetMaterialTexture(material, mapType, *texture);
}
    
void rp_SetModelMeshMaterial(Model * model, int meshId, int materialId) {
    SetModelMeshMaterial(model, meshId, materialId);
}
    
ModelAnimation * rp_LoadModelAnimations(const char * fileName, unsigned int * animCount) {
    return LoadModelAnimations(fileName, animCount);
}
    
void rp_UpdateModelAnimation(Model* model, ModelAnimation* anim, int frame) {
    UpdateModelAnimation(*model, *anim, frame);
}
    
void rp_UnloadModelAnimation(ModelAnimation* anim) {
    UnloadModelAnimation(*anim);
}
    
void rp_UnloadModelAnimations(ModelAnimation * animations, unsigned int count) {
    UnloadModelAnimations(animations, count);
}
    
bool rp_IsModelAnimationValid(Model* model, ModelAnimation* anim) {
    return IsModelAnimationValid(*model, *anim);
}
    
bool rp_CheckCollisionSpheres(Vector3* center1, float radius1, Vector3* center2, float radius2) {
    return CheckCollisionSpheres(*center1, radius1, *center2, radius2);
}
    
bool rp_CheckCollisionBoxes(BoundingBox* box1, BoundingBox* box2) {
    return CheckCollisionBoxes(*box1, *box2);
}
    
bool rp_CheckCollisionBoxSphere(BoundingBox* box, Vector3* center, float radius) {
    return CheckCollisionBoxSphere(*box, *center, radius);
}
    
void rp_GetRayCollisionSphere(RayCollision* output, Ray* ray, Vector3* center, float radius) {
    RayCollision val = GetRayCollisionSphere(*ray, *center, radius);
    memcpy(output, &val, sizeof(RayCollision));
}
    
void rp_GetRayCollisionBox(RayCollision* output, Ray* ray, BoundingBox* box) {
    RayCollision val = GetRayCollisionBox(*ray, *box);
    memcpy(output, &val, sizeof(RayCollision));
}
    
void rp_GetRayCollisionMesh(RayCollision* output, Ray* ray, Mesh* mesh, Matrix* transform) {
    RayCollision val = GetRayCollisionMesh(*ray, *mesh, *transform);
    memcpy(output, &val, sizeof(RayCollision));
}
    
void rp_GetRayCollisionTriangle(RayCollision* output, Ray* ray, Vector3* p1, Vector3* p2, Vector3* p3) {
    RayCollision val = GetRayCollisionTriangle(*ray, *p1, *p2, *p3);
    memcpy(output, &val, sizeof(RayCollision));
}
    
void rp_GetRayCollisionQuad(RayCollision* output, Ray* ray, Vector3* p1, Vector3* p2, Vector3* p3, Vector3* p4) {
    RayCollision val = GetRayCollisionQuad(*ray, *p1, *p2, *p3, *p4);
    memcpy(output, &val, sizeof(RayCollision));
}
    
void rp_InitAudioDevice() {
    InitAudioDevice();
}
    
void rp_CloseAudioDevice() {
    CloseAudioDevice();
}
    
bool rp_IsAudioDeviceReady() {
    return IsAudioDeviceReady();
}
    
void rp_SetMasterVolume(float volume) {
    SetMasterVolume(volume);
}
    
void rp_LoadWave(Wave* output, const char * fileName) {
    Wave val = LoadWave(fileName);
    memcpy(output, &val, sizeof(Wave));
}
    
void rp_LoadWaveFromMemory(Wave* output, const char * fileType, const unsigned char * fileData, int dataSize) {
    Wave val = LoadWaveFromMemory(fileType, fileData, dataSize);
    memcpy(output, &val, sizeof(Wave));
}
    
bool rp_IsWaveReady(Wave* wave) {
    return IsWaveReady(*wave);
}
    
void rp_LoadSound(Sound* output, const char * fileName) {
    Sound val = LoadSound(fileName);
    memcpy(output, &val, sizeof(Sound));
}
    
void rp_LoadSoundFromWave(Sound* output, Wave* wave) {
    Sound val = LoadSoundFromWave(*wave);
    memcpy(output, &val, sizeof(Sound));
}
    
bool rp_IsSoundReady(Sound* sound) {
    return IsSoundReady(*sound);
}
    
void rp_UpdateSound(Sound* sound, const void * data, int sampleCount) {
    UpdateSound(*sound, data, sampleCount);
}
    
void rp_UnloadWave(Wave* wave) {
    UnloadWave(*wave);
}
    
void rp_UnloadSound(Sound* sound) {
    UnloadSound(*sound);
}
    
bool rp_ExportWave(Wave* wave, const char * fileName) {
    return ExportWave(*wave, fileName);
}
    
bool rp_ExportWaveAsCode(Wave* wave, const char * fileName) {
    return ExportWaveAsCode(*wave, fileName);
}
    
void rp_PlaySound(Sound* sound) {
    PlaySound(*sound);
}
    
void rp_StopSound(Sound* sound) {
    StopSound(*sound);
}
    
void rp_PauseSound(Sound* sound) {
    PauseSound(*sound);
}
    
void rp_ResumeSound(Sound* sound) {
    ResumeSound(*sound);
}
    
bool rp_IsSoundPlaying(Sound* sound) {
    return IsSoundPlaying(*sound);
}
    
void rp_SetSoundVolume(Sound* sound, float volume) {
    SetSoundVolume(*sound, volume);
}
    
void rp_SetSoundPitch(Sound* sound, float pitch) {
    SetSoundPitch(*sound, pitch);
}
    
void rp_SetSoundPan(Sound* sound, float pan) {
    SetSoundPan(*sound, pan);
}
    
void rp_WaveCopy(Wave* output, Wave* wave) {
    Wave val = WaveCopy(*wave);
    memcpy(output, &val, sizeof(Wave));
}
    
void rp_WaveCrop(Wave * wave, int initSample, int finalSample) {
    WaveCrop(wave, initSample, finalSample);
}
    
void rp_WaveFormat(Wave * wave, int sampleRate, int sampleSize, int channels) {
    WaveFormat(wave, sampleRate, sampleSize, channels);
}
    
float * rp_LoadWaveSamples(Wave* wave) {
    return LoadWaveSamples(*wave);
}
    
void rp_UnloadWaveSamples(float * samples) {
    UnloadWaveSamples(samples);
}
    
void rp_LoadMusicStream(Music* output, const char * fileName) {
    Music val = LoadMusicStream(fileName);
    memcpy(output, &val, sizeof(Music));
}
    
void rp_LoadMusicStreamFromMemory(Music* output, const char * fileType, const unsigned char * data, int dataSize) {
    Music val = LoadMusicStreamFromMemory(fileType, data, dataSize);
    memcpy(output, &val, sizeof(Music));
}
    
bool rp_IsMusicReady(Music* music) {
    return IsMusicReady(*music);
}
    
void rp_UnloadMusicStream(Music* music) {
    UnloadMusicStream(*music);
}
    
void rp_PlayMusicStream(Music* music) {
    PlayMusicStream(*music);
}
    
bool rp_IsMusicStreamPlaying(Music* music) {
    return IsMusicStreamPlaying(*music);
}
    
void rp_UpdateMusicStream(Music* music) {
    UpdateMusicStream(*music);
}
    
void rp_StopMusicStream(Music* music) {
    StopMusicStream(*music);
}
    
void rp_PauseMusicStream(Music* music) {
    PauseMusicStream(*music);
}
    
void rp_ResumeMusicStream(Music* music) {
    ResumeMusicStream(*music);
}
    
void rp_SeekMusicStream(Music* music, float position) {
    SeekMusicStream(*music, position);
}
    
void rp_SetMusicVolume(Music* music, float volume) {
    SetMusicVolume(*music, volume);
}
    
void rp_SetMusicPitch(Music* music, float pitch) {
    SetMusicPitch(*music, pitch);
}
    
void rp_SetMusicPan(Music* music, float pan) {
    SetMusicPan(*music, pan);
}
    
float rp_GetMusicTimeLength(Music* music) {
    return GetMusicTimeLength(*music);
}
    
float rp_GetMusicTimePlayed(Music* music) {
    return GetMusicTimePlayed(*music);
}
    
void rp_LoadAudioStream(AudioStream* output, unsigned int sampleRate, unsigned int sampleSize, unsigned int channels) {
    AudioStream val = LoadAudioStream(sampleRate, sampleSize, channels);
    memcpy(output, &val, sizeof(AudioStream));
}
    
bool rp_IsAudioStreamReady(AudioStream* stream) {
    return IsAudioStreamReady(*stream);
}
    
void rp_UnloadAudioStream(AudioStream* stream) {
    UnloadAudioStream(*stream);
}
    
void rp_UpdateAudioStream(AudioStream* stream, const void * data, int frameCount) {
    UpdateAudioStream(*stream, data, frameCount);
}
    
bool rp_IsAudioStreamProcessed(AudioStream* stream) {
    return IsAudioStreamProcessed(*stream);
}
    
void rp_PlayAudioStream(AudioStream* stream) {
    PlayAudioStream(*stream);
}
    
void rp_PauseAudioStream(AudioStream* stream) {
    PauseAudioStream(*stream);
}
    
void rp_ResumeAudioStream(AudioStream* stream) {
    ResumeAudioStream(*stream);
}
    
bool rp_IsAudioStreamPlaying(AudioStream* stream) {
    return IsAudioStreamPlaying(*stream);
}
    
void rp_StopAudioStream(AudioStream* stream) {
    StopAudioStream(*stream);
}
    
void rp_SetAudioStreamVolume(AudioStream* stream, float volume) {
    SetAudioStreamVolume(*stream, volume);
}
    
void rp_SetAudioStreamPitch(AudioStream* stream, float pitch) {
    SetAudioStreamPitch(*stream, pitch);
}
    
void rp_SetAudioStreamPan(AudioStream* stream, float pan) {
    SetAudioStreamPan(*stream, pan);
}
    
void rp_SetAudioStreamBufferSizeDefault(int size) {
    SetAudioStreamBufferSizeDefault(size);
}
    
void rp_SetAudioStreamCallback(AudioStream* stream, AudioCallback callback) {
    SetAudioStreamCallback(*stream, callback);
}
    
void rp_AttachAudioStreamProcessor(AudioStream* stream, AudioCallback processor) {
    AttachAudioStreamProcessor(*stream, processor);
}
    
void rp_DetachAudioStreamProcessor(AudioStream* stream, AudioCallback processor) {
    DetachAudioStreamProcessor(*stream, processor);
}
    
void rp_AttachAudioMixedProcessor(AudioCallback processor) {
    AttachAudioMixedProcessor(processor);
}
    
void rp_DetachAudioMixedProcessor(AudioCallback processor) {
    DetachAudioMixedProcessor(processor);
}
    
#endif // RP_NATIVE
