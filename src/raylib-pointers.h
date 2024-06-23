// raylib-pointer wrapper generated at 2024-06-23T05:29:00.208Z for 4.6.0

#include "raylib.h"

#ifndef RLP_EXPORT
  #define RLP_EXPORT
#endif

// Initialize window and OpenGL context
RLP_EXPORT void rp_InitWindow (int width, int height, const char* title) {
  InitWindow(width, height, title);
}

// Check if KEY_ESCAPE pressed or Close icon pressed
RLP_EXPORT bool rp_WindowShouldClose () {
  return WindowShouldClose();
}

// Close window and unload OpenGL context
RLP_EXPORT void rp_CloseWindow () {
  CloseWindow();
}

// Check if window has been initialized successfully
RLP_EXPORT bool rp_IsWindowReady () {
  return IsWindowReady();
}

// Check if window is currently fullscreen
RLP_EXPORT bool rp_IsWindowFullscreen () {
  return IsWindowFullscreen();
}

// Check if window is currently hidden (only PLATFORM_DESKTOP)
RLP_EXPORT bool rp_IsWindowHidden () {
  return IsWindowHidden();
}

// Check if window is currently minimized (only PLATFORM_DESKTOP)
RLP_EXPORT bool rp_IsWindowMinimized () {
  return IsWindowMinimized();
}

// Check if window is currently maximized (only PLATFORM_DESKTOP)
RLP_EXPORT bool rp_IsWindowMaximized () {
  return IsWindowMaximized();
}

// Check if window is currently focused (only PLATFORM_DESKTOP)
RLP_EXPORT bool rp_IsWindowFocused () {
  return IsWindowFocused();
}

// Check if window has been resized last frame
RLP_EXPORT bool rp_IsWindowResized () {
  return IsWindowResized();
}

// Check if one specific window flag is enabled
RLP_EXPORT bool rp_IsWindowState (unsigned int flag) {
  return IsWindowState(flag);
}

// Set window configuration state using flags (only PLATFORM_DESKTOP)
RLP_EXPORT void rp_SetWindowState (unsigned int flags) {
  SetWindowState(flags);
}

// Clear window configuration state flags
RLP_EXPORT void rp_ClearWindowState (unsigned int flags) {
  ClearWindowState(flags);
}

// Toggle window state: fullscreen/windowed (only PLATFORM_DESKTOP)
RLP_EXPORT void rp_ToggleFullscreen () {
  ToggleFullscreen();
}

// Toggle window state: borderless windowed (only PLATFORM_DESKTOP)
RLP_EXPORT void rp_ToggleBorderlessWindowed () {
  ToggleBorderlessWindowed();
}

// Set window state: maximized, if resizable (only PLATFORM_DESKTOP)
RLP_EXPORT void rp_MaximizeWindow () {
  MaximizeWindow();
}

// Set window state: minimized, if resizable (only PLATFORM_DESKTOP)
RLP_EXPORT void rp_MinimizeWindow () {
  MinimizeWindow();
}

// Set window state: not minimized/maximized (only PLATFORM_DESKTOP)
RLP_EXPORT void rp_RestoreWindow () {
  RestoreWindow();
}

// Set icon for window (single image, RGBA 32bit, only PLATFORM_DESKTOP)
RLP_EXPORT void rp_SetWindowIcon (Image* image) {
  SetWindowIcon(*image);
}

// Set icon for window (multiple images, RGBA 32bit, only PLATFORM_DESKTOP)
RLP_EXPORT void rp_SetWindowIcons (Image* images, int count) {
  SetWindowIcons(images, count);
}

// Set title for window (only PLATFORM_DESKTOP and PLATFORM_WEB)
RLP_EXPORT void rp_SetWindowTitle (const char* title) {
  SetWindowTitle(title);
}

// Set window position on screen (only PLATFORM_DESKTOP)
RLP_EXPORT void rp_SetWindowPosition (int x, int y) {
  SetWindowPosition(x, y);
}

// Set monitor for the current window
RLP_EXPORT void rp_SetWindowMonitor (int monitor) {
  SetWindowMonitor(monitor);
}

// Set window minimum dimensions (for FLAG_WINDOW_RESIZABLE)
RLP_EXPORT void rp_SetWindowMinSize (int width, int height) {
  SetWindowMinSize(width, height);
}

// Set window maximum dimensions (for FLAG_WINDOW_RESIZABLE)
RLP_EXPORT void rp_SetWindowMaxSize (int width, int height) {
  SetWindowMaxSize(width, height);
}

// Set window dimensions
RLP_EXPORT void rp_SetWindowSize (int width, int height) {
  SetWindowSize(width, height);
}

// Set window opacity [0.0f..1.0f] (only PLATFORM_DESKTOP)
RLP_EXPORT void rp_SetWindowOpacity (float opacity) {
  SetWindowOpacity(opacity);
}

// Set window focused (only PLATFORM_DESKTOP)
RLP_EXPORT void rp_SetWindowFocused () {
  SetWindowFocused();
}

// Get native window handle
RLP_EXPORT void * rp_GetWindowHandle () {
  return GetWindowHandle();
}

// Get current screen width
RLP_EXPORT int rp_GetScreenWidth () {
  return GetScreenWidth();
}

// Get current screen height
RLP_EXPORT int rp_GetScreenHeight () {
  return GetScreenHeight();
}

// Get current render width (it considers HiDPI)
RLP_EXPORT int rp_GetRenderWidth () {
  return GetRenderWidth();
}

// Get current render height (it considers HiDPI)
RLP_EXPORT int rp_GetRenderHeight () {
  return GetRenderHeight();
}

// Get number of connected monitors
RLP_EXPORT int rp_GetMonitorCount () {
  return GetMonitorCount();
}

// Get current connected monitor
RLP_EXPORT int rp_GetCurrentMonitor () {
  return GetCurrentMonitor();
}

// Get specified monitor position
RLP_EXPORT void rp_GetMonitorPosition (Vector2* rp_retVal, int monitor) {
  *rp_retVal = GetMonitorPosition(monitor);
}

// Get specified monitor width (current video mode used by monitor)
RLP_EXPORT int rp_GetMonitorWidth (int monitor) {
  return GetMonitorWidth(monitor);
}

// Get specified monitor height (current video mode used by monitor)
RLP_EXPORT int rp_GetMonitorHeight (int monitor) {
  return GetMonitorHeight(monitor);
}

// Get specified monitor physical width in millimetres
RLP_EXPORT int rp_GetMonitorPhysicalWidth (int monitor) {
  return GetMonitorPhysicalWidth(monitor);
}

// Get specified monitor physical height in millimetres
RLP_EXPORT int rp_GetMonitorPhysicalHeight (int monitor) {
  return GetMonitorPhysicalHeight(monitor);
}

// Get specified monitor refresh rate
RLP_EXPORT int rp_GetMonitorRefreshRate (int monitor) {
  return GetMonitorRefreshRate(monitor);
}

// Get window position XY on monitor
RLP_EXPORT void rp_GetWindowPosition (Vector2* rp_retVal) {
  *rp_retVal = GetWindowPosition();
}

// Get window scale DPI factor
RLP_EXPORT void rp_GetWindowScaleDPI (Vector2* rp_retVal) {
  *rp_retVal = GetWindowScaleDPI();
}

// Get the human-readable, UTF-8 encoded name of the specified monitor
RLP_EXPORT const char * rp_GetMonitorName (int monitor) {
  return GetMonitorName(monitor);
}

// Set clipboard text content
RLP_EXPORT void rp_SetClipboardText (const char* text) {
  SetClipboardText(text);
}

// Get clipboard text content
RLP_EXPORT const char * rp_GetClipboardText () {
  return GetClipboardText();
}

// Enable waiting for events on EndDrawing(), no automatic event polling
RLP_EXPORT void rp_EnableEventWaiting () {
  EnableEventWaiting();
}

// Disable waiting for events on EndDrawing(), automatic events polling
RLP_EXPORT void rp_DisableEventWaiting () {
  DisableEventWaiting();
}

// Swap back buffer with front buffer (screen drawing)
RLP_EXPORT void rp_SwapScreenBuffer () {
  SwapScreenBuffer();
}

// Register all input events
RLP_EXPORT void rp_PollInputEvents () {
  PollInputEvents();
}

// Wait for some time (halt program execution)
RLP_EXPORT void rp_WaitTime (double seconds) {
  WaitTime(seconds);
}

// Shows cursor
RLP_EXPORT void rp_ShowCursor () {
  ShowCursor();
}

// Hides cursor
RLP_EXPORT void rp_HideCursor () {
  HideCursor();
}

// Check if cursor is not visible
RLP_EXPORT bool rp_IsCursorHidden () {
  return IsCursorHidden();
}

// Enables cursor (unlock cursor)
RLP_EXPORT void rp_EnableCursor () {
  EnableCursor();
}

// Disables cursor (lock cursor)
RLP_EXPORT void rp_DisableCursor () {
  DisableCursor();
}

// Check if cursor is on the screen
RLP_EXPORT bool rp_IsCursorOnScreen () {
  return IsCursorOnScreen();
}

// Set background color (framebuffer clear color)
RLP_EXPORT void rp_ClearBackground (Color* color) {
  ClearBackground(*color);
}

// Setup canvas (framebuffer) to start drawing
RLP_EXPORT void rp_BeginDrawing () {
  BeginDrawing();
}

// End canvas drawing and swap buffers (double buffering)
RLP_EXPORT void rp_EndDrawing () {
  EndDrawing();
}

// Begin 2D mode with custom camera (2D)
RLP_EXPORT void rp_BeginMode2D (Camera2D* camera) {
  BeginMode2D(*camera);
}

// Ends 2D mode with custom camera
RLP_EXPORT void rp_EndMode2D () {
  EndMode2D();
}

// Begin 3D mode with custom camera (3D)
RLP_EXPORT void rp_BeginMode3D (Camera3D* camera) {
  BeginMode3D(*camera);
}

// Ends 3D mode and returns to default 2D orthographic mode
RLP_EXPORT void rp_EndMode3D () {
  EndMode3D();
}

// Begin drawing to render texture
RLP_EXPORT void rp_BeginTextureMode (RenderTexture2D* target) {
  BeginTextureMode(*target);
}

// Ends drawing to render texture
RLP_EXPORT void rp_EndTextureMode () {
  EndTextureMode();
}

// Begin custom shader drawing
RLP_EXPORT void rp_BeginShaderMode (Shader* shader) {
  BeginShaderMode(*shader);
}

// End custom shader drawing (use default shader)
RLP_EXPORT void rp_EndShaderMode () {
  EndShaderMode();
}

// Begin blending mode (alpha, additive, multiplied, subtract, custom)
RLP_EXPORT void rp_BeginBlendMode (int mode) {
  BeginBlendMode(mode);
}

// End blending mode (reset to default: alpha blending)
RLP_EXPORT void rp_EndBlendMode () {
  EndBlendMode();
}

// Begin scissor mode (define screen area for following drawing)
RLP_EXPORT void rp_BeginScissorMode (int x, int y, int width, int height) {
  BeginScissorMode(x, y, width, height);
}

// End scissor mode
RLP_EXPORT void rp_EndScissorMode () {
  EndScissorMode();
}

// Begin stereo rendering (requires VR simulator)
RLP_EXPORT void rp_BeginVrStereoMode (VrStereoConfig* config) {
  BeginVrStereoMode(*config);
}

// End stereo rendering (requires VR simulator)
RLP_EXPORT void rp_EndVrStereoMode () {
  EndVrStereoMode();
}

// Load VR stereo config for VR simulator device parameters
RLP_EXPORT void rp_LoadVrStereoConfig (VrStereoConfig* rp_retVal, VrDeviceInfo* device) {
  *rp_retVal = LoadVrStereoConfig(*device);
}

// Unload VR stereo config
RLP_EXPORT void rp_UnloadVrStereoConfig (VrStereoConfig* config) {
  UnloadVrStereoConfig(*config);
}

// Load shader from files and bind default locations
RLP_EXPORT void rp_LoadShader (Shader* rp_retVal, const char* vsFileName, const char* fsFileName) {
  *rp_retVal = LoadShader(vsFileName, fsFileName);
}

// Load shader from code strings and bind default locations
RLP_EXPORT void rp_LoadShaderFromMemory (Shader* rp_retVal, const char* vsCode, const char* fsCode) {
  *rp_retVal = LoadShaderFromMemory(vsCode, fsCode);
}

// Check if a shader is ready
RLP_EXPORT bool rp_IsShaderReady (Shader* shader) {
  return IsShaderReady(*shader);
}

// Get shader uniform location
RLP_EXPORT int rp_GetShaderLocation (Shader* shader, const char* uniformName) {
  return GetShaderLocation(*shader, uniformName);
}

// Get shader attribute location
RLP_EXPORT int rp_GetShaderLocationAttrib (Shader* shader, const char* attribName) {
  return GetShaderLocationAttrib(*shader, attribName);
}

// Set shader uniform value
RLP_EXPORT void rp_SetShaderValue (Shader* shader, int locIndex, const void* value, int uniformType) {
  SetShaderValue(*shader, locIndex, value, uniformType);
}

// Set shader uniform value vector
RLP_EXPORT void rp_SetShaderValueV (Shader* shader, int locIndex, const void* value, int uniformType, int count) {
  SetShaderValueV(*shader, locIndex, value, uniformType, count);
}

// Set shader uniform value (matrix 4x4)
RLP_EXPORT void rp_SetShaderValueMatrix (Shader* shader, int locIndex, Matrix* mat) {
  SetShaderValueMatrix(*shader, locIndex, *mat);
}

// Set shader uniform value for texture (sampler2d)
RLP_EXPORT void rp_SetShaderValueTexture (Shader* shader, int locIndex, Texture2D* texture) {
  SetShaderValueTexture(*shader, locIndex, *texture);
}

// Unload shader from GPU memory (VRAM)
RLP_EXPORT void rp_UnloadShader (Shader* shader) {
  UnloadShader(*shader);
}

// Get a ray trace from mouse position
RLP_EXPORT void rp_GetMouseRay (Ray* rp_retVal, Vector2* mousePosition, Camera* camera) {
  *rp_retVal = GetMouseRay(*mousePosition, *camera);
}

// Get camera transform matrix (view matrix)
RLP_EXPORT void rp_GetCameraMatrix (Matrix* rp_retVal, Camera* camera) {
  *rp_retVal = GetCameraMatrix(*camera);
}

// Get camera 2d transform matrix
RLP_EXPORT void rp_GetCameraMatrix2D (Matrix* rp_retVal, Camera2D* camera) {
  *rp_retVal = GetCameraMatrix2D(*camera);
}

// Get the screen space position for a 3d world space position
RLP_EXPORT void rp_GetWorldToScreen (Vector2* rp_retVal, Vector3* position, Camera* camera) {
  *rp_retVal = GetWorldToScreen(*position, *camera);
}

// Get the world space position for a 2d camera screen space position
RLP_EXPORT void rp_GetScreenToWorld2D (Vector2* rp_retVal, Vector2* position, Camera2D* camera) {
  *rp_retVal = GetScreenToWorld2D(*position, *camera);
}

// Get size position for a 3d world space position
RLP_EXPORT void rp_GetWorldToScreenEx (Vector2* rp_retVal, Vector3* position, Camera* camera, int width, int height) {
  *rp_retVal = GetWorldToScreenEx(*position, *camera, width, height);
}

// Get the screen space position for a 2d camera world space position
RLP_EXPORT void rp_GetWorldToScreen2D (Vector2* rp_retVal, Vector2* position, Camera2D* camera) {
  *rp_retVal = GetWorldToScreen2D(*position, *camera);
}

// Set target FPS (maximum)
RLP_EXPORT void rp_SetTargetFPS (int fps) {
  SetTargetFPS(fps);
}

// Get current FPS
RLP_EXPORT int rp_GetFPS () {
  return GetFPS();
}

// Get time in seconds for last frame drawn (delta time)
RLP_EXPORT float rp_GetFrameTime () {
  return GetFrameTime();
}

// Get elapsed time in seconds since InitWindow()
RLP_EXPORT double rp_GetTime () {
  return GetTime();
}

// Get a random value between min and max (both included)
RLP_EXPORT int rp_GetRandomValue (int min, int max) {
  return GetRandomValue(min, max);
}

// Set the seed for the random number generator
RLP_EXPORT void rp_SetRandomSeed (unsigned int seed) {
  SetRandomSeed(seed);
}

// Takes a screenshot of current screen (filename extension defines format)
RLP_EXPORT void rp_TakeScreenshot (const char* fileName) {
  TakeScreenshot(fileName);
}

// Setup init configuration flags (view FLAGS)
RLP_EXPORT void rp_SetConfigFlags (unsigned int flags) {
  SetConfigFlags(flags);
}

// Set the current threshold (minimum) log level
RLP_EXPORT void rp_SetTraceLogLevel (int logLevel) {
  SetTraceLogLevel(logLevel);
}

// Internal memory allocator
RLP_EXPORT void * rp_MemAlloc (unsigned int size) {
  return MemAlloc(size);
}

// Internal memory reallocator
RLP_EXPORT void * rp_MemRealloc (void* ptr, unsigned int size) {
  return MemRealloc(ptr, size);
}

// Internal memory free
RLP_EXPORT void rp_MemFree (void* ptr) {
  MemFree(ptr);
}

// Open URL with default system browser (if available)
RLP_EXPORT void rp_OpenURL (const char* url) {
  OpenURL(url);
}

// Set custom trace log
RLP_EXPORT void rp_SetTraceLogCallback (TraceLogCallback* callback) {
  SetTraceLogCallback(*callback);
}

// Set custom file binary data loader
RLP_EXPORT void rp_SetLoadFileDataCallback (LoadFileDataCallback* callback) {
  SetLoadFileDataCallback(*callback);
}

// Set custom file binary data saver
RLP_EXPORT void rp_SetSaveFileDataCallback (SaveFileDataCallback* callback) {
  SetSaveFileDataCallback(*callback);
}

// Set custom file text data loader
RLP_EXPORT void rp_SetLoadFileTextCallback (LoadFileTextCallback* callback) {
  SetLoadFileTextCallback(*callback);
}

// Set custom file text data saver
RLP_EXPORT void rp_SetSaveFileTextCallback (SaveFileTextCallback* callback) {
  SetSaveFileTextCallback(*callback);
}

// Load file data as byte array (read)
RLP_EXPORT unsigned char * rp_LoadFileData (const char* fileName, int* dataSize) {
  return LoadFileData(fileName, dataSize);
}

// Unload file data allocated by LoadFileData()
RLP_EXPORT void rp_UnloadFileData (unsigned char* data) {
  UnloadFileData(data);
}

// Save data to file from byte array (write), returns true on success
RLP_EXPORT bool rp_SaveFileData (const char* fileName, void* data, int dataSize) {
  return SaveFileData(fileName, data, dataSize);
}

// Export data to code (.h), returns true on success
RLP_EXPORT bool rp_ExportDataAsCode (const unsigned char* data, int dataSize, const char* fileName) {
  return ExportDataAsCode(data, dataSize, fileName);
}

// Load text data from file (read), returns a '\0' terminated string
RLP_EXPORT char * rp_LoadFileText (const char* fileName) {
  return LoadFileText(fileName);
}

// Unload file text data allocated by LoadFileText()
RLP_EXPORT void rp_UnloadFileText (char* text) {
  UnloadFileText(text);
}

// Save text data to file (write), string must be '\0' terminated, returns true on success
RLP_EXPORT bool rp_SaveFileText (const char* fileName, char* text) {
  return SaveFileText(fileName, text);
}

// Check if file exists
RLP_EXPORT bool rp_FileExists (const char* fileName) {
  return FileExists(fileName);
}

// Check if a directory path exists
RLP_EXPORT bool rp_DirectoryExists (const char* dirPath) {
  return DirectoryExists(dirPath);
}

// Check file extension (including point: .png, .wav)
RLP_EXPORT bool rp_IsFileExtension (const char* fileName, const char* ext) {
  return IsFileExtension(fileName, ext);
}

// Get file length in bytes (NOTE: GetFileSize() conflicts with windows.h)
RLP_EXPORT int rp_GetFileLength (const char* fileName) {
  return GetFileLength(fileName);
}

// Get pointer to extension for a filename string (includes dot: '.png')
RLP_EXPORT const char * rp_GetFileExtension (const char* fileName) {
  return GetFileExtension(fileName);
}

// Get pointer to filename for a path string
RLP_EXPORT const char * rp_GetFileName (const char* filePath) {
  return GetFileName(filePath);
}

// Get filename string without extension (uses static string)
RLP_EXPORT const char * rp_GetFileNameWithoutExt (const char* filePath) {
  return GetFileNameWithoutExt(filePath);
}

// Get full path for a given fileName with path (uses static string)
RLP_EXPORT const char * rp_GetDirectoryPath (const char* filePath) {
  return GetDirectoryPath(filePath);
}

// Get previous directory path for a given path (uses static string)
RLP_EXPORT const char * rp_GetPrevDirectoryPath (const char* dirPath) {
  return GetPrevDirectoryPath(dirPath);
}

// Get current working directory (uses static string)
RLP_EXPORT const char * rp_GetWorkingDirectory () {
  return GetWorkingDirectory();
}

// Get the directory of the running application (uses static string)
RLP_EXPORT const char * rp_GetApplicationDirectory () {
  return GetApplicationDirectory();
}

// Change working directory, return true on success
RLP_EXPORT bool rp_ChangeDirectory (const char* dir) {
  return ChangeDirectory(dir);
}

// Check if a given path is a file or a directory
RLP_EXPORT bool rp_IsPathFile (const char* path) {
  return IsPathFile(path);
}

// Load directory filepaths
RLP_EXPORT void rp_LoadDirectoryFiles (FilePathList* rp_retVal, const char* dirPath) {
  *rp_retVal = LoadDirectoryFiles(dirPath);
}

// Load directory filepaths with extension filtering and recursive directory scan
RLP_EXPORT void rp_LoadDirectoryFilesEx (FilePathList* rp_retVal, const char* basePath, const char* filter, bool scanSubdirs) {
  *rp_retVal = LoadDirectoryFilesEx(basePath, filter, scanSubdirs);
}

// Unload filepaths
RLP_EXPORT void rp_UnloadDirectoryFiles (FilePathList* files) {
  UnloadDirectoryFiles(*files);
}

// Check if a file has been dropped into window
RLP_EXPORT bool rp_IsFileDropped () {
  return IsFileDropped();
}

// Load dropped filepaths
RLP_EXPORT void rp_LoadDroppedFiles (FilePathList* rp_retVal) {
  *rp_retVal = LoadDroppedFiles();
}

// Unload dropped filepaths
RLP_EXPORT void rp_UnloadDroppedFiles (FilePathList* files) {
  UnloadDroppedFiles(*files);
}

// Get file modification time (last write time)
RLP_EXPORT long rp_GetFileModTime (const char* fileName) {
  return GetFileModTime(fileName);
}

// Compress data (DEFLATE algorithm), memory must be MemFree()
RLP_EXPORT unsigned char * rp_CompressData (const unsigned char* data, int dataSize, int* compDataSize) {
  return CompressData(data, dataSize, compDataSize);
}

// Decompress data (DEFLATE algorithm), memory must be MemFree()
RLP_EXPORT unsigned char * rp_DecompressData (const unsigned char* compData, int compDataSize, int* dataSize) {
  return DecompressData(compData, compDataSize, dataSize);
}

// Encode data to Base64 string, memory must be MemFree()
RLP_EXPORT char * rp_EncodeDataBase64 (const unsigned char* data, int dataSize, int* outputSize) {
  return EncodeDataBase64(data, dataSize, outputSize);
}

// Decode Base64 string data, memory must be MemFree()
RLP_EXPORT unsigned char * rp_DecodeDataBase64 (const unsigned char* data, int* outputSize) {
  return DecodeDataBase64(data, outputSize);
}

// Check if a key has been pressed once
RLP_EXPORT bool rp_IsKeyPressed (int key) {
  return IsKeyPressed(key);
}

// Check if a key has been pressed again (Only PLATFORM_DESKTOP)
RLP_EXPORT bool rp_IsKeyPressedRepeat (int key) {
  return IsKeyPressedRepeat(key);
}

// Check if a key is being pressed
RLP_EXPORT bool rp_IsKeyDown (int key) {
  return IsKeyDown(key);
}

// Check if a key has been released once
RLP_EXPORT bool rp_IsKeyReleased (int key) {
  return IsKeyReleased(key);
}

// Check if a key is NOT being pressed
RLP_EXPORT bool rp_IsKeyUp (int key) {
  return IsKeyUp(key);
}

// Set a custom key to exit program (default is ESC)
RLP_EXPORT void rp_SetExitKey (int key) {
  SetExitKey(key);
}

// Get key pressed (keycode), call it multiple times for keys queued, returns 0 when the queue is empty
RLP_EXPORT int rp_GetKeyPressed () {
  return GetKeyPressed();
}

// Get char pressed (unicode), call it multiple times for chars queued, returns 0 when the queue is empty
RLP_EXPORT int rp_GetCharPressed () {
  return GetCharPressed();
}

// Check if a gamepad is available
RLP_EXPORT bool rp_IsGamepadAvailable (int gamepad) {
  return IsGamepadAvailable(gamepad);
}

// Get gamepad internal name id
RLP_EXPORT const char * rp_GetGamepadName (int gamepad) {
  return GetGamepadName(gamepad);
}

// Check if a gamepad button has been pressed once
RLP_EXPORT bool rp_IsGamepadButtonPressed (int gamepad, int button) {
  return IsGamepadButtonPressed(gamepad, button);
}

// Check if a gamepad button is being pressed
RLP_EXPORT bool rp_IsGamepadButtonDown (int gamepad, int button) {
  return IsGamepadButtonDown(gamepad, button);
}

// Check if a gamepad button has been released once
RLP_EXPORT bool rp_IsGamepadButtonReleased (int gamepad, int button) {
  return IsGamepadButtonReleased(gamepad, button);
}

// Check if a gamepad button is NOT being pressed
RLP_EXPORT bool rp_IsGamepadButtonUp (int gamepad, int button) {
  return IsGamepadButtonUp(gamepad, button);
}

// Get the last gamepad button pressed
RLP_EXPORT int rp_GetGamepadButtonPressed () {
  return GetGamepadButtonPressed();
}

// Get gamepad axis count for a gamepad
RLP_EXPORT int rp_GetGamepadAxisCount (int gamepad) {
  return GetGamepadAxisCount(gamepad);
}

// Get axis movement value for a gamepad axis
RLP_EXPORT float rp_GetGamepadAxisMovement (int gamepad, int axis) {
  return GetGamepadAxisMovement(gamepad, axis);
}

// Set internal gamepad mappings (SDL_GameControllerDB)
RLP_EXPORT int rp_SetGamepadMappings (const char* mappings) {
  return SetGamepadMappings(mappings);
}

// Check if a mouse button has been pressed once
RLP_EXPORT bool rp_IsMouseButtonPressed (int button) {
  return IsMouseButtonPressed(button);
}

// Check if a mouse button is being pressed
RLP_EXPORT bool rp_IsMouseButtonDown (int button) {
  return IsMouseButtonDown(button);
}

// Check if a mouse button has been released once
RLP_EXPORT bool rp_IsMouseButtonReleased (int button) {
  return IsMouseButtonReleased(button);
}

// Check if a mouse button is NOT being pressed
RLP_EXPORT bool rp_IsMouseButtonUp (int button) {
  return IsMouseButtonUp(button);
}

// Get mouse position X
RLP_EXPORT int rp_GetMouseX () {
  return GetMouseX();
}

// Get mouse position Y
RLP_EXPORT int rp_GetMouseY () {
  return GetMouseY();
}

// Get mouse position XY
RLP_EXPORT void rp_GetMousePosition (Vector2* rp_retVal) {
  *rp_retVal = GetMousePosition();
}

// Get mouse delta between frames
RLP_EXPORT void rp_GetMouseDelta (Vector2* rp_retVal) {
  *rp_retVal = GetMouseDelta();
}

// Set mouse position XY
RLP_EXPORT void rp_SetMousePosition (int x, int y) {
  SetMousePosition(x, y);
}

// Set mouse offset
RLP_EXPORT void rp_SetMouseOffset (int offsetX, int offsetY) {
  SetMouseOffset(offsetX, offsetY);
}

// Set mouse scaling
RLP_EXPORT void rp_SetMouseScale (float scaleX, float scaleY) {
  SetMouseScale(scaleX, scaleY);
}

// Get mouse wheel movement for X or Y, whichever is larger
RLP_EXPORT float rp_GetMouseWheelMove () {
  return GetMouseWheelMove();
}

// Get mouse wheel movement for both X and Y
RLP_EXPORT void rp_GetMouseWheelMoveV (Vector2* rp_retVal) {
  *rp_retVal = GetMouseWheelMoveV();
}

// Set mouse cursor
RLP_EXPORT void rp_SetMouseCursor (int cursor) {
  SetMouseCursor(cursor);
}

// Get touch position X for touch point 0 (relative to screen size)
RLP_EXPORT int rp_GetTouchX () {
  return GetTouchX();
}

// Get touch position Y for touch point 0 (relative to screen size)
RLP_EXPORT int rp_GetTouchY () {
  return GetTouchY();
}

// Get touch position XY for a touch point index (relative to screen size)
RLP_EXPORT void rp_GetTouchPosition (Vector2* rp_retVal, int index) {
  *rp_retVal = GetTouchPosition(index);
}

// Get touch point identifier for given index
RLP_EXPORT int rp_GetTouchPointId (int index) {
  return GetTouchPointId(index);
}

// Get number of touch points
RLP_EXPORT int rp_GetTouchPointCount () {
  return GetTouchPointCount();
}

// Enable a set of gestures using flags
RLP_EXPORT void rp_SetGesturesEnabled (unsigned int flags) {
  SetGesturesEnabled(flags);
}

// Check if a gesture have been detected
RLP_EXPORT bool rp_IsGestureDetected (unsigned int gesture) {
  return IsGestureDetected(gesture);
}

// Get latest detected gesture
RLP_EXPORT int rp_GetGestureDetected () {
  return GetGestureDetected();
}

// Get gesture hold time in milliseconds
RLP_EXPORT float rp_GetGestureHoldDuration () {
  return GetGestureHoldDuration();
}

// Get gesture drag vector
RLP_EXPORT void rp_GetGestureDragVector (Vector2* rp_retVal) {
  *rp_retVal = GetGestureDragVector();
}

// Get gesture drag angle
RLP_EXPORT float rp_GetGestureDragAngle () {
  return GetGestureDragAngle();
}

// Get gesture pinch delta
RLP_EXPORT void rp_GetGesturePinchVector (Vector2* rp_retVal) {
  *rp_retVal = GetGesturePinchVector();
}

// Get gesture pinch angle
RLP_EXPORT float rp_GetGesturePinchAngle () {
  return GetGesturePinchAngle();
}

// Update camera position for selected mode
RLP_EXPORT void rp_UpdateCamera (Camera* camera, int mode) {
  UpdateCamera(camera, mode);
}

// Update camera movement/rotation
RLP_EXPORT void rp_UpdateCameraPro (Camera* camera, Vector3* movement, Vector3* rotation, float zoom) {
  UpdateCameraPro(camera, *movement, *rotation, zoom);
}

// Set texture and rectangle to be used on shapes drawing
RLP_EXPORT void rp_SetShapesTexture (Texture2D* texture, Rectangle* source) {
  SetShapesTexture(*texture, *source);
}

// Draw a pixel
RLP_EXPORT void rp_DrawPixel (int posX, int posY, Color* color) {
  DrawPixel(posX, posY, *color);
}

// Draw a pixel (Vector version)
RLP_EXPORT void rp_DrawPixelV (Vector2* position, Color* color) {
  DrawPixelV(*position, *color);
}

// Draw a line
RLP_EXPORT void rp_DrawLine (int startPosX, int startPosY, int endPosX, int endPosY, Color* color) {
  DrawLine(startPosX, startPosY, endPosX, endPosY, *color);
}

// Draw a line (Vector version)
RLP_EXPORT void rp_DrawLineV (Vector2* startPos, Vector2* endPos, Color* color) {
  DrawLineV(*startPos, *endPos, *color);
}

// Draw a line defining thickness
RLP_EXPORT void rp_DrawLineEx (Vector2* startPos, Vector2* endPos, float thick, Color* color) {
  DrawLineEx(*startPos, *endPos, thick, *color);
}

// Draw a line using cubic-bezier curves in-out
RLP_EXPORT void rp_DrawLineBezier (Vector2* startPos, Vector2* endPos, float thick, Color* color) {
  DrawLineBezier(*startPos, *endPos, thick, *color);
}

// Draw lines sequence
RLP_EXPORT void rp_DrawLineStrip (Vector2* points, int pointCount, Color* color) {
  DrawLineStrip(points, pointCount, *color);
}

// Draw a color-filled circle
RLP_EXPORT void rp_DrawCircle (int centerX, int centerY, float radius, Color* color) {
  DrawCircle(centerX, centerY, radius, *color);
}

// Draw a piece of a circle
RLP_EXPORT void rp_DrawCircleSector (Vector2* center, float radius, float startAngle, float endAngle, int segments, Color* color) {
  DrawCircleSector(*center, radius, startAngle, endAngle, segments, *color);
}

// Draw circle sector outline
RLP_EXPORT void rp_DrawCircleSectorLines (Vector2* center, float radius, float startAngle, float endAngle, int segments, Color* color) {
  DrawCircleSectorLines(*center, radius, startAngle, endAngle, segments, *color);
}

// Draw a gradient-filled circle
RLP_EXPORT void rp_DrawCircleGradient (int centerX, int centerY, float radius, Color* color1, Color* color2) {
  DrawCircleGradient(centerX, centerY, radius, *color1, *color2);
}

// Draw a color-filled circle (Vector version)
RLP_EXPORT void rp_DrawCircleV (Vector2* center, float radius, Color* color) {
  DrawCircleV(*center, radius, *color);
}

// Draw circle outline
RLP_EXPORT void rp_DrawCircleLines (int centerX, int centerY, float radius, Color* color) {
  DrawCircleLines(centerX, centerY, radius, *color);
}

// Draw ellipse
RLP_EXPORT void rp_DrawEllipse (int centerX, int centerY, float radiusH, float radiusV, Color* color) {
  DrawEllipse(centerX, centerY, radiusH, radiusV, *color);
}

// Draw ellipse outline
RLP_EXPORT void rp_DrawEllipseLines (int centerX, int centerY, float radiusH, float radiusV, Color* color) {
  DrawEllipseLines(centerX, centerY, radiusH, radiusV, *color);
}

// Draw ring
RLP_EXPORT void rp_DrawRing (Vector2* center, float innerRadius, float outerRadius, float startAngle, float endAngle, int segments, Color* color) {
  DrawRing(*center, innerRadius, outerRadius, startAngle, endAngle, segments, *color);
}

// Draw ring outline
RLP_EXPORT void rp_DrawRingLines (Vector2* center, float innerRadius, float outerRadius, float startAngle, float endAngle, int segments, Color* color) {
  DrawRingLines(*center, innerRadius, outerRadius, startAngle, endAngle, segments, *color);
}

// Draw a color-filled rectangle
RLP_EXPORT void rp_DrawRectangle (int posX, int posY, int width, int height, Color* color) {
  DrawRectangle(posX, posY, width, height, *color);
}

// Draw a color-filled rectangle (Vector version)
RLP_EXPORT void rp_DrawRectangleV (Vector2* position, Vector2* size, Color* color) {
  DrawRectangleV(*position, *size, *color);
}

// Draw a color-filled rectangle
RLP_EXPORT void rp_DrawRectangleRec (Rectangle* rec, Color* color) {
  DrawRectangleRec(*rec, *color);
}

// Draw a color-filled rectangle with pro parameters
RLP_EXPORT void rp_DrawRectanglePro (Rectangle* rec, Vector2* origin, float rotation, Color* color) {
  DrawRectanglePro(*rec, *origin, rotation, *color);
}

// Draw a vertical-gradient-filled rectangle
RLP_EXPORT void rp_DrawRectangleGradientV (int posX, int posY, int width, int height, Color* color1, Color* color2) {
  DrawRectangleGradientV(posX, posY, width, height, *color1, *color2);
}

// Draw a horizontal-gradient-filled rectangle
RLP_EXPORT void rp_DrawRectangleGradientH (int posX, int posY, int width, int height, Color* color1, Color* color2) {
  DrawRectangleGradientH(posX, posY, width, height, *color1, *color2);
}

// Draw a gradient-filled rectangle with custom vertex colors
RLP_EXPORT void rp_DrawRectangleGradientEx (Rectangle* rec, Color* col1, Color* col2, Color* col3, Color* col4) {
  DrawRectangleGradientEx(*rec, *col1, *col2, *col3, *col4);
}

// Draw rectangle outline
RLP_EXPORT void rp_DrawRectangleLines (int posX, int posY, int width, int height, Color* color) {
  DrawRectangleLines(posX, posY, width, height, *color);
}

// Draw rectangle outline with extended parameters
RLP_EXPORT void rp_DrawRectangleLinesEx (Rectangle* rec, float lineThick, Color* color) {
  DrawRectangleLinesEx(*rec, lineThick, *color);
}

// Draw rectangle with rounded edges
RLP_EXPORT void rp_DrawRectangleRounded (Rectangle* rec, float roundness, int segments, Color* color) {
  DrawRectangleRounded(*rec, roundness, segments, *color);
}

// Draw rectangle with rounded edges outline
RLP_EXPORT void rp_DrawRectangleRoundedLines (Rectangle* rec, float roundness, int segments, float lineThick, Color* color) {
  DrawRectangleRoundedLines(*rec, roundness, segments, lineThick, *color);
}

// Draw a color-filled triangle (vertex in counter-clockwise order!)
RLP_EXPORT void rp_DrawTriangle (Vector2* v1, Vector2* v2, Vector2* v3, Color* color) {
  DrawTriangle(*v1, *v2, *v3, *color);
}

// Draw triangle outline (vertex in counter-clockwise order!)
RLP_EXPORT void rp_DrawTriangleLines (Vector2* v1, Vector2* v2, Vector2* v3, Color* color) {
  DrawTriangleLines(*v1, *v2, *v3, *color);
}

// Draw a triangle fan defined by points (first vertex is the center)
RLP_EXPORT void rp_DrawTriangleFan (Vector2* points, int pointCount, Color* color) {
  DrawTriangleFan(points, pointCount, *color);
}

// Draw a triangle strip defined by points
RLP_EXPORT void rp_DrawTriangleStrip (Vector2* points, int pointCount, Color* color) {
  DrawTriangleStrip(points, pointCount, *color);
}

// Draw a regular polygon (Vector version)
RLP_EXPORT void rp_DrawPoly (Vector2* center, int sides, float radius, float rotation, Color* color) {
  DrawPoly(*center, sides, radius, rotation, *color);
}

// Draw a polygon outline of n sides
RLP_EXPORT void rp_DrawPolyLines (Vector2* center, int sides, float radius, float rotation, Color* color) {
  DrawPolyLines(*center, sides, radius, rotation, *color);
}

// Draw a polygon outline of n sides with extended parameters
RLP_EXPORT void rp_DrawPolyLinesEx (Vector2* center, int sides, float radius, float rotation, float lineThick, Color* color) {
  DrawPolyLinesEx(*center, sides, radius, rotation, lineThick, *color);
}

// Check collision between two rectangles
RLP_EXPORT bool rp_CheckCollisionRecs (Rectangle* rec1, Rectangle* rec2) {
  return CheckCollisionRecs(*rec1, *rec2);
}

// Check collision between two circles
RLP_EXPORT bool rp_CheckCollisionCircles (Vector2* center1, float radius1, Vector2* center2, float radius2) {
  return CheckCollisionCircles(*center1, radius1, *center2, radius2);
}

// Check collision between circle and rectangle
RLP_EXPORT bool rp_CheckCollisionCircleRec (Vector2* center, float radius, Rectangle* rec) {
  return CheckCollisionCircleRec(*center, radius, *rec);
}

// Check if point is inside rectangle
RLP_EXPORT bool rp_CheckCollisionPointRec (Vector2* point, Rectangle* rec) {
  return CheckCollisionPointRec(*point, *rec);
}

// Check if point is inside circle
RLP_EXPORT bool rp_CheckCollisionPointCircle (Vector2* point, Vector2* center, float radius) {
  return CheckCollisionPointCircle(*point, *center, radius);
}

// Check if point is inside a triangle
RLP_EXPORT bool rp_CheckCollisionPointTriangle (Vector2* point, Vector2* p1, Vector2* p2, Vector2* p3) {
  return CheckCollisionPointTriangle(*point, *p1, *p2, *p3);
}

// Check if point is within a polygon described by array of vertices
RLP_EXPORT bool rp_CheckCollisionPointPoly (Vector2* point, Vector2* points, int pointCount) {
  return CheckCollisionPointPoly(*point, points, pointCount);
}

// Check the collision between two lines defined by two points each, returns collision point by reference
RLP_EXPORT bool rp_CheckCollisionLines (Vector2* startPos1, Vector2* endPos1, Vector2* startPos2, Vector2* endPos2, Vector2* collisionPoint) {
  return CheckCollisionLines(*startPos1, *endPos1, *startPos2, *endPos2, collisionPoint);
}

// Check if point belongs to line created between two points [p1] and [p2] with defined margin in pixels [threshold]
RLP_EXPORT bool rp_CheckCollisionPointLine (Vector2* point, Vector2* p1, Vector2* p2, int threshold) {
  return CheckCollisionPointLine(*point, *p1, *p2, threshold);
}

// Get collision rectangle for two rectangles collision
RLP_EXPORT void rp_GetCollisionRec (Rectangle* rp_retVal, Rectangle* rec1, Rectangle* rec2) {
  *rp_retVal = GetCollisionRec(*rec1, *rec2);
}

// Load image from file into CPU memory (RAM)
RLP_EXPORT void rp_LoadImage (Image* rp_retVal, const char* fileName) {
  *rp_retVal = LoadImage(fileName);
}

// Load image from RAW file data
RLP_EXPORT void rp_LoadImageRaw (Image* rp_retVal, const char* fileName, int width, int height, int format, int headerSize) {
  *rp_retVal = LoadImageRaw(fileName, width, height, format, headerSize);
}

// Load image from SVG file data or string with specified size
RLP_EXPORT void rp_LoadImageSvg (Image* rp_retVal, const char* fileNameOrString, int width, int height) {
  *rp_retVal = LoadImageSvg(fileNameOrString, width, height);
}

// Load image sequence from file (frames appended to image.data)
RLP_EXPORT void rp_LoadImageAnim (Image* rp_retVal, const char* fileName, int* frames) {
  *rp_retVal = LoadImageAnim(fileName, frames);
}

// Load image from memory buffer, fileType refers to extension: i.e. '.png'
RLP_EXPORT void rp_LoadImageFromMemory (Image* rp_retVal, const char* fileType, const unsigned char* fileData, int dataSize) {
  *rp_retVal = LoadImageFromMemory(fileType, fileData, dataSize);
}

// Load image from GPU texture data
RLP_EXPORT void rp_LoadImageFromTexture (Image* rp_retVal, Texture2D* texture) {
  *rp_retVal = LoadImageFromTexture(*texture);
}

// Load image from screen buffer and (screenshot)
RLP_EXPORT void rp_LoadImageFromScreen (Image* rp_retVal) {
  *rp_retVal = LoadImageFromScreen();
}

// Check if an image is ready
RLP_EXPORT bool rp_IsImageReady (Image* image) {
  return IsImageReady(*image);
}

// Unload image from CPU memory (RAM)
RLP_EXPORT void rp_UnloadImage (Image* image) {
  UnloadImage(*image);
}

// Export image data to file, returns true on success
RLP_EXPORT bool rp_ExportImage (Image* image, const char* fileName) {
  return ExportImage(*image, fileName);
}

// Export image to memory buffer
RLP_EXPORT unsigned char * rp_ExportImageToMemory (Image* image, const char* fileType, int* fileSize) {
  return ExportImageToMemory(*image, fileType, fileSize);
}

// Export image as code file defining an array of bytes, returns true on success
RLP_EXPORT bool rp_ExportImageAsCode (Image* image, const char* fileName) {
  return ExportImageAsCode(*image, fileName);
}

// Generate image: plain color
RLP_EXPORT void rp_GenImageColor (Image* rp_retVal, int width, int height, Color* color) {
  *rp_retVal = GenImageColor(width, height, *color);
}

// Generate image: linear gradient, direction in degrees [0..360], 0=Vertical gradient
RLP_EXPORT void rp_GenImageGradientLinear (Image* rp_retVal, int width, int height, int direction, Color* start, Color* end) {
  *rp_retVal = GenImageGradientLinear(width, height, direction, *start, *end);
}

// Generate image: radial gradient
RLP_EXPORT void rp_GenImageGradientRadial (Image* rp_retVal, int width, int height, float density, Color* inner, Color* outer) {
  *rp_retVal = GenImageGradientRadial(width, height, density, *inner, *outer);
}

// Generate image: square gradient
RLP_EXPORT void rp_GenImageGradientSquare (Image* rp_retVal, int width, int height, float density, Color* inner, Color* outer) {
  *rp_retVal = GenImageGradientSquare(width, height, density, *inner, *outer);
}

// Generate image: checked
RLP_EXPORT void rp_GenImageChecked (Image* rp_retVal, int width, int height, int checksX, int checksY, Color* col1, Color* col2) {
  *rp_retVal = GenImageChecked(width, height, checksX, checksY, *col1, *col2);
}

// Generate image: white noise
RLP_EXPORT void rp_GenImageWhiteNoise (Image* rp_retVal, int width, int height, float factor) {
  *rp_retVal = GenImageWhiteNoise(width, height, factor);
}

// Generate image: perlin noise
RLP_EXPORT void rp_GenImagePerlinNoise (Image* rp_retVal, int width, int height, int offsetX, int offsetY, float scale) {
  *rp_retVal = GenImagePerlinNoise(width, height, offsetX, offsetY, scale);
}

// Generate image: cellular algorithm, bigger tileSize means bigger cells
RLP_EXPORT void rp_GenImageCellular (Image* rp_retVal, int width, int height, int tileSize) {
  *rp_retVal = GenImageCellular(width, height, tileSize);
}

// Generate image: grayscale image from text data
RLP_EXPORT void rp_GenImageText (Image* rp_retVal, int width, int height, const char* text) {
  *rp_retVal = GenImageText(width, height, text);
}

// Create an image duplicate (useful for transformations)
RLP_EXPORT void rp_ImageCopy (Image* rp_retVal, Image* image) {
  *rp_retVal = ImageCopy(*image);
}

// Create an image from another image piece
RLP_EXPORT void rp_ImageFromImage (Image* rp_retVal, Image* image, Rectangle* rec) {
  *rp_retVal = ImageFromImage(*image, *rec);
}

// Create an image from text (default font)
RLP_EXPORT void rp_ImageText (Image* rp_retVal, const char* text, int fontSize, Color* color) {
  *rp_retVal = ImageText(text, fontSize, *color);
}

// Create an image from text (custom sprite font)
RLP_EXPORT void rp_ImageTextEx (Image* rp_retVal, Font* font, const char* text, float fontSize, float spacing, Color* tint) {
  *rp_retVal = ImageTextEx(*font, text, fontSize, spacing, *tint);
}

// Convert image data to desired format
RLP_EXPORT void rp_ImageFormat (Image* image, int newFormat) {
  ImageFormat(image, newFormat);
}

// Convert image to POT (power-of-two)
RLP_EXPORT void rp_ImageToPOT (Image* image, Color* fill) {
  ImageToPOT(image, *fill);
}

// Crop an image to a defined rectangle
RLP_EXPORT void rp_ImageCrop (Image* image, Rectangle* crop) {
  ImageCrop(image, *crop);
}

// Crop image depending on alpha value
RLP_EXPORT void rp_ImageAlphaCrop (Image* image, float threshold) {
  ImageAlphaCrop(image, threshold);
}

// Clear alpha channel to desired color
RLP_EXPORT void rp_ImageAlphaClear (Image* image, Color* color, float threshold) {
  ImageAlphaClear(image, *color, threshold);
}

// Apply alpha mask to image
RLP_EXPORT void rp_ImageAlphaMask (Image* image, Image* alphaMask) {
  ImageAlphaMask(image, *alphaMask);
}

// Premultiply alpha channel
RLP_EXPORT void rp_ImageAlphaPremultiply (Image* image) {
  ImageAlphaPremultiply(image);
}

// Apply Gaussian blur using a box blur approximation
RLP_EXPORT void rp_ImageBlurGaussian (Image* image, int blurSize) {
  ImageBlurGaussian(image, blurSize);
}

// Resize image (Bicubic scaling algorithm)
RLP_EXPORT void rp_ImageResize (Image* image, int newWidth, int newHeight) {
  ImageResize(image, newWidth, newHeight);
}

// Resize image (Nearest-Neighbor scaling algorithm)
RLP_EXPORT void rp_ImageResizeNN (Image* image, int newWidth, int newHeight) {
  ImageResizeNN(image, newWidth, newHeight);
}

// Resize canvas and fill with color
RLP_EXPORT void rp_ImageResizeCanvas (Image* image, int newWidth, int newHeight, int offsetX, int offsetY, Color* fill) {
  ImageResizeCanvas(image, newWidth, newHeight, offsetX, offsetY, *fill);
}

// Compute all mipmap levels for a provided image
RLP_EXPORT void rp_ImageMipmaps (Image* image) {
  ImageMipmaps(image);
}

// Dither image data to 16bpp or lower (Floyd-Steinberg dithering)
RLP_EXPORT void rp_ImageDither (Image* image, int rBpp, int gBpp, int bBpp, int aBpp) {
  ImageDither(image, rBpp, gBpp, bBpp, aBpp);
}

// Flip image vertically
RLP_EXPORT void rp_ImageFlipVertical (Image* image) {
  ImageFlipVertical(image);
}

// Flip image horizontally
RLP_EXPORT void rp_ImageFlipHorizontal (Image* image) {
  ImageFlipHorizontal(image);
}

// Rotate image by input angle in degrees (-359 to 359)
RLP_EXPORT void rp_ImageRotate (Image* image, int degrees) {
  ImageRotate(image, degrees);
}

// Rotate image clockwise 90deg
RLP_EXPORT void rp_ImageRotateCW (Image* image) {
  ImageRotateCW(image);
}

// Rotate image counter-clockwise 90deg
RLP_EXPORT void rp_ImageRotateCCW (Image* image) {
  ImageRotateCCW(image);
}

// Modify image color: tint
RLP_EXPORT void rp_ImageColorTint (Image* image, Color* color) {
  ImageColorTint(image, *color);
}

// Modify image color: invert
RLP_EXPORT void rp_ImageColorInvert (Image* image) {
  ImageColorInvert(image);
}

// Modify image color: grayscale
RLP_EXPORT void rp_ImageColorGrayscale (Image* image) {
  ImageColorGrayscale(image);
}

// Modify image color: contrast (-100 to 100)
RLP_EXPORT void rp_ImageColorContrast (Image* image, float contrast) {
  ImageColorContrast(image, contrast);
}

// Modify image color: brightness (-255 to 255)
RLP_EXPORT void rp_ImageColorBrightness (Image* image, int brightness) {
  ImageColorBrightness(image, brightness);
}

// Modify image color: replace color
RLP_EXPORT void rp_ImageColorReplace (Image* image, Color* color, Color* replace) {
  ImageColorReplace(image, *color, *replace);
}

// Load color data from image as a Color array (RGBA - 32bit)
RLP_EXPORT Color * rp_LoadImageColors (Image* image) {
  return LoadImageColors(*image);
}

// Load colors palette from image as a Color array (RGBA - 32bit)
RLP_EXPORT Color * rp_LoadImagePalette (Image* image, int maxPaletteSize, int* colorCount) {
  return LoadImagePalette(*image, maxPaletteSize, colorCount);
}

// Unload color data loaded with LoadImageColors()
RLP_EXPORT void rp_UnloadImageColors (Color* colors) {
  UnloadImageColors(colors);
}

// Unload colors palette loaded with LoadImagePalette()
RLP_EXPORT void rp_UnloadImagePalette (Color* colors) {
  UnloadImagePalette(colors);
}

// Get image alpha border rectangle
RLP_EXPORT void rp_GetImageAlphaBorder (Rectangle* rp_retVal, Image* image, float threshold) {
  *rp_retVal = GetImageAlphaBorder(*image, threshold);
}

// Get image pixel color at (x, y) position
RLP_EXPORT void rp_GetImageColor (Color* rp_retVal, Image* image, int x, int y) {
  *rp_retVal = GetImageColor(*image, x, y);
}

// Clear image background with given color
RLP_EXPORT void rp_ImageClearBackground (Image* dst, Color* color) {
  ImageClearBackground(dst, *color);
}

// Draw pixel within an image
RLP_EXPORT void rp_ImageDrawPixel (Image* dst, int posX, int posY, Color* color) {
  ImageDrawPixel(dst, posX, posY, *color);
}

// Draw pixel within an image (Vector version)
RLP_EXPORT void rp_ImageDrawPixelV (Image* dst, Vector2* position, Color* color) {
  ImageDrawPixelV(dst, *position, *color);
}

// Draw line within an image
RLP_EXPORT void rp_ImageDrawLine (Image* dst, int startPosX, int startPosY, int endPosX, int endPosY, Color* color) {
  ImageDrawLine(dst, startPosX, startPosY, endPosX, endPosY, *color);
}

// Draw line within an image (Vector version)
RLP_EXPORT void rp_ImageDrawLineV (Image* dst, Vector2* start, Vector2* end, Color* color) {
  ImageDrawLineV(dst, *start, *end, *color);
}

// Draw a filled circle within an image
RLP_EXPORT void rp_ImageDrawCircle (Image* dst, int centerX, int centerY, int radius, Color* color) {
  ImageDrawCircle(dst, centerX, centerY, radius, *color);
}

// Draw a filled circle within an image (Vector version)
RLP_EXPORT void rp_ImageDrawCircleV (Image* dst, Vector2* center, int radius, Color* color) {
  ImageDrawCircleV(dst, *center, radius, *color);
}

// Draw circle outline within an image
RLP_EXPORT void rp_ImageDrawCircleLines (Image* dst, int centerX, int centerY, int radius, Color* color) {
  ImageDrawCircleLines(dst, centerX, centerY, radius, *color);
}

// Draw circle outline within an image (Vector version)
RLP_EXPORT void rp_ImageDrawCircleLinesV (Image* dst, Vector2* center, int radius, Color* color) {
  ImageDrawCircleLinesV(dst, *center, radius, *color);
}

// Draw rectangle within an image
RLP_EXPORT void rp_ImageDrawRectangle (Image* dst, int posX, int posY, int width, int height, Color* color) {
  ImageDrawRectangle(dst, posX, posY, width, height, *color);
}

// Draw rectangle within an image (Vector version)
RLP_EXPORT void rp_ImageDrawRectangleV (Image* dst, Vector2* position, Vector2* size, Color* color) {
  ImageDrawRectangleV(dst, *position, *size, *color);
}

// Draw rectangle within an image
RLP_EXPORT void rp_ImageDrawRectangleRec (Image* dst, Rectangle* rec, Color* color) {
  ImageDrawRectangleRec(dst, *rec, *color);
}

// Draw rectangle lines within an image
RLP_EXPORT void rp_ImageDrawRectangleLines (Image* dst, Rectangle* rec, int thick, Color* color) {
  ImageDrawRectangleLines(dst, *rec, thick, *color);
}

// Draw a source image within a destination image (tint applied to source)
RLP_EXPORT void rp_ImageDraw (Image* dst, Image* src, Rectangle* srcRec, Rectangle* dstRec, Color* tint) {
  ImageDraw(dst, *src, *srcRec, *dstRec, *tint);
}

// Draw text (using default font) within an image (destination)
RLP_EXPORT void rp_ImageDrawText (Image* dst, const char* text, int posX, int posY, int fontSize, Color* color) {
  ImageDrawText(dst, text, posX, posY, fontSize, *color);
}

// Draw text (custom sprite font) within an image (destination)
RLP_EXPORT void rp_ImageDrawTextEx (Image* dst, Font* font, const char* text, Vector2* position, float fontSize, float spacing, Color* tint) {
  ImageDrawTextEx(dst, *font, text, *position, fontSize, spacing, *tint);
}

// Load texture from file into GPU memory (VRAM)
RLP_EXPORT void rp_LoadTexture (Texture2D* rp_retVal, const char* fileName) {
  *rp_retVal = LoadTexture(fileName);
}

// Load texture from image data
RLP_EXPORT void rp_LoadTextureFromImage (Texture2D* rp_retVal, Image* image) {
  *rp_retVal = LoadTextureFromImage(*image);
}

// Load cubemap from image, multiple image cubemap layouts supported
RLP_EXPORT void rp_LoadTextureCubemap (TextureCubemap* rp_retVal, Image* image, int layout) {
  *rp_retVal = LoadTextureCubemap(*image, layout);
}

// Load texture for rendering (framebuffer)
RLP_EXPORT void rp_LoadRenderTexture (RenderTexture2D* rp_retVal, int width, int height) {
  *rp_retVal = LoadRenderTexture(width, height);
}

// Check if a texture is ready
RLP_EXPORT bool rp_IsTextureReady (Texture2D* texture) {
  return IsTextureReady(*texture);
}

// Unload texture from GPU memory (VRAM)
RLP_EXPORT void rp_UnloadTexture (Texture2D* texture) {
  UnloadTexture(*texture);
}

// Check if a render texture is ready
RLP_EXPORT bool rp_IsRenderTextureReady (RenderTexture2D* target) {
  return IsRenderTextureReady(*target);
}

// Unload render texture from GPU memory (VRAM)
RLP_EXPORT void rp_UnloadRenderTexture (RenderTexture2D* target) {
  UnloadRenderTexture(*target);
}

// Update GPU texture with new data
RLP_EXPORT void rp_UpdateTexture (Texture2D* texture, const void* pixels) {
  UpdateTexture(*texture, pixels);
}

// Update GPU texture rectangle with new data
RLP_EXPORT void rp_UpdateTextureRec (Texture2D* texture, Rectangle* rec, const void* pixels) {
  UpdateTextureRec(*texture, *rec, pixels);
}

// Generate GPU mipmaps for a texture
RLP_EXPORT void rp_GenTextureMipmaps (Texture2D* texture) {
  GenTextureMipmaps(texture);
}

// Set texture scaling filter mode
RLP_EXPORT void rp_SetTextureFilter (Texture2D* texture, int filter) {
  SetTextureFilter(*texture, filter);
}

// Set texture wrapping mode
RLP_EXPORT void rp_SetTextureWrap (Texture2D* texture, int wrap) {
  SetTextureWrap(*texture, wrap);
}

// Draw a Texture2D
RLP_EXPORT void rp_DrawTexture (Texture2D* texture, int posX, int posY, Color* tint) {
  DrawTexture(*texture, posX, posY, *tint);
}

// Draw a Texture2D with position defined as Vector2
RLP_EXPORT void rp_DrawTextureV (Texture2D* texture, Vector2* position, Color* tint) {
  DrawTextureV(*texture, *position, *tint);
}

// Draw a Texture2D with extended parameters
RLP_EXPORT void rp_DrawTextureEx (Texture2D* texture, Vector2* position, float rotation, float scale, Color* tint) {
  DrawTextureEx(*texture, *position, rotation, scale, *tint);
}

// Draw a part of a texture defined by a rectangle
RLP_EXPORT void rp_DrawTextureRec (Texture2D* texture, Rectangle* source, Vector2* position, Color* tint) {
  DrawTextureRec(*texture, *source, *position, *tint);
}

// Draw a part of a texture defined by a rectangle with 'pro' parameters
RLP_EXPORT void rp_DrawTexturePro (Texture2D* texture, Rectangle* source, Rectangle* dest, Vector2* origin, float rotation, Color* tint) {
  DrawTexturePro(*texture, *source, *dest, *origin, rotation, *tint);
}

// Draws a texture (or part of it) that stretches or shrinks nicely
RLP_EXPORT void rp_DrawTextureNPatch (Texture2D* texture, NPatchInfo* nPatchInfo, Rectangle* dest, Vector2* origin, float rotation, Color* tint) {
  DrawTextureNPatch(*texture, *nPatchInfo, *dest, *origin, rotation, *tint);
}

// Get color with alpha applied, alpha goes from 0.0f to 1.0f
RLP_EXPORT void rp_Fade (Color* rp_retVal, Color* color, float alpha) {
  *rp_retVal = Fade(*color, alpha);
}

// Get hexadecimal value for a Color
RLP_EXPORT int rp_ColorToInt (Color* color) {
  return ColorToInt(*color);
}

// Get Color normalized as float [0..1]
RLP_EXPORT void rp_ColorNormalize (Vector4* rp_retVal, Color* color) {
  *rp_retVal = ColorNormalize(*color);
}

// Get Color from normalized values [0..1]
RLP_EXPORT void rp_ColorFromNormalized (Color* rp_retVal, Vector4* normalized) {
  *rp_retVal = ColorFromNormalized(*normalized);
}

// Get HSV values for a Color, hue [0..360], saturation/value [0..1]
RLP_EXPORT void rp_ColorToHSV (Vector3* rp_retVal, Color* color) {
  *rp_retVal = ColorToHSV(*color);
}

// Get a Color from HSV values, hue [0..360], saturation/value [0..1]
RLP_EXPORT void rp_ColorFromHSV (Color* rp_retVal, float hue, float saturation, float value) {
  *rp_retVal = ColorFromHSV(hue, saturation, value);
}

// Get color multiplied with another color
RLP_EXPORT void rp_ColorTint (Color* rp_retVal, Color* color, Color* tint) {
  *rp_retVal = ColorTint(*color, *tint);
}

// Get color with brightness correction, brightness factor goes from -1.0f to 1.0f
RLP_EXPORT void rp_ColorBrightness (Color* rp_retVal, Color* color, float factor) {
  *rp_retVal = ColorBrightness(*color, factor);
}

// Get color with contrast correction, contrast values between -1.0f and 1.0f
RLP_EXPORT void rp_ColorContrast (Color* rp_retVal, Color* color, float contrast) {
  *rp_retVal = ColorContrast(*color, contrast);
}

// Get color with alpha applied, alpha goes from 0.0f to 1.0f
RLP_EXPORT void rp_ColorAlpha (Color* rp_retVal, Color* color, float alpha) {
  *rp_retVal = ColorAlpha(*color, alpha);
}

// Get src alpha-blended into dst color with tint
RLP_EXPORT void rp_ColorAlphaBlend (Color* rp_retVal, Color* dst, Color* src, Color* tint) {
  *rp_retVal = ColorAlphaBlend(*dst, *src, *tint);
}

// Get Color structure from hexadecimal value
RLP_EXPORT void rp_GetColor (Color* rp_retVal, unsigned int hexValue) {
  *rp_retVal = GetColor(hexValue);
}

// Get Color from a source pixel pointer of certain format
RLP_EXPORT void rp_GetPixelColor (Color* rp_retVal, void* srcPtr, int format) {
  *rp_retVal = GetPixelColor(srcPtr, format);
}

// Set color formatted into destination pixel pointer
RLP_EXPORT void rp_SetPixelColor (void* dstPtr, Color* color, int format) {
  SetPixelColor(dstPtr, *color, format);
}

// Get pixel data size in bytes for certain format
RLP_EXPORT int rp_GetPixelDataSize (int width, int height, int format) {
  return GetPixelDataSize(width, height, format);
}

// Get the default Font
RLP_EXPORT void rp_GetFontDefault (Font* rp_retVal) {
  *rp_retVal = GetFontDefault();
}

// Load font from file into GPU memory (VRAM)
RLP_EXPORT void rp_LoadFont (Font* rp_retVal, const char* fileName) {
  *rp_retVal = LoadFont(fileName);
}

// Load font from file with extended parameters, use NULL for codepoints and 0 for codepointCount to load the default character setFont
RLP_EXPORT void rp_LoadFontEx (Font* rp_retVal, const char* fileName, int fontSize, int* codepoints, int codepointCount) {
  *rp_retVal = LoadFontEx(fileName, fontSize, codepoints, codepointCount);
}

// Load font from Image (XNA style)
RLP_EXPORT void rp_LoadFontFromImage (Font* rp_retVal, Image* image, Color* key, int firstChar) {
  *rp_retVal = LoadFontFromImage(*image, *key, firstChar);
}

// Load font from memory buffer, fileType refers to extension: i.e. '.ttf'
RLP_EXPORT void rp_LoadFontFromMemory (Font* rp_retVal, const char* fileType, const unsigned char* fileData, int dataSize, int fontSize, int* codepoints, int codepointCount) {
  *rp_retVal = LoadFontFromMemory(fileType, fileData, dataSize, fontSize, codepoints, codepointCount);
}

// Check if a font is ready
RLP_EXPORT bool rp_IsFontReady (Font* font) {
  return IsFontReady(*font);
}

// Load font data for further use
RLP_EXPORT GlyphInfo * rp_LoadFontData (const unsigned char* fileData, int dataSize, int fontSize, int* codepoints, int codepointCount, int type) {
  return LoadFontData(fileData, dataSize, fontSize, codepoints, codepointCount, type);
}

// Generate image font atlas using chars info
RLP_EXPORT void rp_GenImageFontAtlas (Image* rp_retVal, const GlyphInfo* glyphs, Rectangle** glyphRecs, int glyphCount, int fontSize, int padding, int packMethod) {
  *rp_retVal = GenImageFontAtlas(glyphs, glyphRecs, glyphCount, fontSize, padding, packMethod);
}

// Unload font chars info data (RAM)
RLP_EXPORT void rp_UnloadFontData (GlyphInfo* glyphs, int glyphCount) {
  UnloadFontData(glyphs, glyphCount);
}

// Unload font from GPU memory (VRAM)
RLP_EXPORT void rp_UnloadFont (Font* font) {
  UnloadFont(*font);
}

// Export font as code file, returns true on success
RLP_EXPORT bool rp_ExportFontAsCode (Font* font, const char* fileName) {
  return ExportFontAsCode(*font, fileName);
}

// Draw current FPS
RLP_EXPORT void rp_DrawFPS (int posX, int posY) {
  DrawFPS(posX, posY);
}

// Draw text (using default font)
RLP_EXPORT void rp_DrawText (const char* text, int posX, int posY, int fontSize, Color* color) {
  DrawText(text, posX, posY, fontSize, *color);
}

// Draw text using font and additional parameters
RLP_EXPORT void rp_DrawTextEx (Font* font, const char* text, Vector2* position, float fontSize, float spacing, Color* tint) {
  DrawTextEx(*font, text, *position, fontSize, spacing, *tint);
}

// Draw text using Font and pro parameters (rotation)
RLP_EXPORT void rp_DrawTextPro (Font* font, const char* text, Vector2* position, Vector2* origin, float rotation, float fontSize, float spacing, Color* tint) {
  DrawTextPro(*font, text, *position, *origin, rotation, fontSize, spacing, *tint);
}

// Draw one character (codepoint)
RLP_EXPORT void rp_DrawTextCodepoint (Font* font, int codepoint, Vector2* position, float fontSize, Color* tint) {
  DrawTextCodepoint(*font, codepoint, *position, fontSize, *tint);
}

// Draw multiple character (codepoint)
RLP_EXPORT void rp_DrawTextCodepoints (Font* font, const int* codepoints, int codepointCount, Vector2* position, float fontSize, float spacing, Color* tint) {
  DrawTextCodepoints(*font, codepoints, codepointCount, *position, fontSize, spacing, *tint);
}

// Set vertical line spacing when drawing with line-breaks
RLP_EXPORT void rp_SetTextLineSpacing (int spacing) {
  SetTextLineSpacing(spacing);
}

// Measure string width for default font
RLP_EXPORT int rp_MeasureText (const char* text, int fontSize) {
  return MeasureText(text, fontSize);
}

// Measure string size for Font
RLP_EXPORT void rp_MeasureTextEx (Vector2* rp_retVal, Font* font, const char* text, float fontSize, float spacing) {
  *rp_retVal = MeasureTextEx(*font, text, fontSize, spacing);
}

// Get glyph index position in font for a codepoint (unicode character), fallback to '?' if not found
RLP_EXPORT int rp_GetGlyphIndex (Font* font, int codepoint) {
  return GetGlyphIndex(*font, codepoint);
}

// Get glyph font info data for a codepoint (unicode character), fallback to '?' if not found
RLP_EXPORT void rp_GetGlyphInfo (GlyphInfo* rp_retVal, Font* font, int codepoint) {
  *rp_retVal = GetGlyphInfo(*font, codepoint);
}

// Get glyph rectangle in font atlas for a codepoint (unicode character), fallback to '?' if not found
RLP_EXPORT void rp_GetGlyphAtlasRec (Rectangle* rp_retVal, Font* font, int codepoint) {
  *rp_retVal = GetGlyphAtlasRec(*font, codepoint);
}

// Load UTF-8 text encoded from codepoints array
RLP_EXPORT char * rp_LoadUTF8 (const int* codepoints, int length) {
  return LoadUTF8(codepoints, length);
}

// Unload UTF-8 text encoded from codepoints array
RLP_EXPORT void rp_UnloadUTF8 (char* text) {
  UnloadUTF8(text);
}

// Load all codepoints from a UTF-8 text string, codepoints count returned by parameter
RLP_EXPORT int * rp_LoadCodepoints (const char* text, int* count) {
  return LoadCodepoints(text, count);
}

// Unload codepoints data from memory
RLP_EXPORT void rp_UnloadCodepoints (int* codepoints) {
  UnloadCodepoints(codepoints);
}

// Get total number of codepoints in a UTF-8 encoded string
RLP_EXPORT int rp_GetCodepointCount (const char* text) {
  return GetCodepointCount(text);
}

// Get next codepoint in a UTF-8 encoded string, 0x3f('?') is returned on failure
RLP_EXPORT int rp_GetCodepoint (const char* text, int* codepointSize) {
  return GetCodepoint(text, codepointSize);
}

// Get next codepoint in a UTF-8 encoded string, 0x3f('?') is returned on failure
RLP_EXPORT int rp_GetCodepointNext (const char* text, int* codepointSize) {
  return GetCodepointNext(text, codepointSize);
}

// Get previous codepoint in a UTF-8 encoded string, 0x3f('?') is returned on failure
RLP_EXPORT int rp_GetCodepointPrevious (const char* text, int* codepointSize) {
  return GetCodepointPrevious(text, codepointSize);
}

// Encode one codepoint into UTF-8 byte array (array length returned as parameter)
RLP_EXPORT const char * rp_CodepointToUTF8 (int codepoint, int* utf8Size) {
  return CodepointToUTF8(codepoint, utf8Size);
}

// Copy one string to another, returns bytes copied
RLP_EXPORT int rp_TextCopy (char* dst, const char* src) {
  return TextCopy(dst, src);
}

// Check if two text string are equal
RLP_EXPORT bool rp_TextIsEqual (const char* text1, const char* text2) {
  return TextIsEqual(text1, text2);
}

// Get text length, checks for '\0' ending
RLP_EXPORT unsigned int rp_TextLength (const char* text) {
  return TextLength(text);
}

// Get a piece of a text string
RLP_EXPORT const char * rp_TextSubtext (const char* text, int position, int length) {
  return TextSubtext(text, position, length);
}

// Replace text string (WARNING: memory must be freed!)
RLP_EXPORT char * rp_TextReplace (char* text, const char* replace, const char* by) {
  return TextReplace(text, replace, by);
}

// Insert text in a position (WARNING: memory must be freed!)
RLP_EXPORT char * rp_TextInsert (const char* text, const char* insert, int position) {
  return TextInsert(text, insert, position);
}

// Join text strings with delimiter
RLP_EXPORT const char * rp_TextJoin (const char** textList, int count, const char* delimiter) {
  return TextJoin(textList, count, delimiter);
}

// Split text into multiple strings
RLP_EXPORT const char ** rp_TextSplit (const char* text, char delimiter, int* count) {
  return TextSplit(text, delimiter, count);
}

// Append text at specific position and move cursor!
RLP_EXPORT void rp_TextAppend (char* text, const char* append, int* position) {
  TextAppend(text, append, position);
}

// Find first text occurrence within a string
RLP_EXPORT int rp_TextFindIndex (const char* text, const char* find) {
  return TextFindIndex(text, find);
}

// Get upper case version of provided string
RLP_EXPORT const char * rp_TextToUpper (const char* text) {
  return TextToUpper(text);
}

// Get lower case version of provided string
RLP_EXPORT const char * rp_TextToLower (const char* text) {
  return TextToLower(text);
}

// Get Pascal case notation version of provided string
RLP_EXPORT const char * rp_TextToPascal (const char* text) {
  return TextToPascal(text);
}

// Get integer value from text (negative values not supported)
RLP_EXPORT int rp_TextToInteger (const char* text) {
  return TextToInteger(text);
}

// Draw a line in 3D world space
RLP_EXPORT void rp_DrawLine3D (Vector3* startPos, Vector3* endPos, Color* color) {
  DrawLine3D(*startPos, *endPos, *color);
}

// Draw a point in 3D space, actually a small line
RLP_EXPORT void rp_DrawPoint3D (Vector3* position, Color* color) {
  DrawPoint3D(*position, *color);
}

// Draw a circle in 3D world space
RLP_EXPORT void rp_DrawCircle3D (Vector3* center, float radius, Vector3* rotationAxis, float rotationAngle, Color* color) {
  DrawCircle3D(*center, radius, *rotationAxis, rotationAngle, *color);
}

// Draw a color-filled triangle (vertex in counter-clockwise order!)
RLP_EXPORT void rp_DrawTriangle3D (Vector3* v1, Vector3* v2, Vector3* v3, Color* color) {
  DrawTriangle3D(*v1, *v2, *v3, *color);
}

// Draw a triangle strip defined by points
RLP_EXPORT void rp_DrawTriangleStrip3D (Vector3* points, int pointCount, Color* color) {
  DrawTriangleStrip3D(points, pointCount, *color);
}

// Draw cube
RLP_EXPORT void rp_DrawCube (Vector3* position, float width, float height, float length, Color* color) {
  DrawCube(*position, width, height, length, *color);
}

// Draw cube (Vector version)
RLP_EXPORT void rp_DrawCubeV (Vector3* position, Vector3* size, Color* color) {
  DrawCubeV(*position, *size, *color);
}

// Draw cube wires
RLP_EXPORT void rp_DrawCubeWires (Vector3* position, float width, float height, float length, Color* color) {
  DrawCubeWires(*position, width, height, length, *color);
}

// Draw cube wires (Vector version)
RLP_EXPORT void rp_DrawCubeWiresV (Vector3* position, Vector3* size, Color* color) {
  DrawCubeWiresV(*position, *size, *color);
}

// Draw sphere
RLP_EXPORT void rp_DrawSphere (Vector3* centerPos, float radius, Color* color) {
  DrawSphere(*centerPos, radius, *color);
}

// Draw sphere with extended parameters
RLP_EXPORT void rp_DrawSphereEx (Vector3* centerPos, float radius, int rings, int slices, Color* color) {
  DrawSphereEx(*centerPos, radius, rings, slices, *color);
}

// Draw sphere wires
RLP_EXPORT void rp_DrawSphereWires (Vector3* centerPos, float radius, int rings, int slices, Color* color) {
  DrawSphereWires(*centerPos, radius, rings, slices, *color);
}

// Draw a cylinder/cone
RLP_EXPORT void rp_DrawCylinder (Vector3* position, float radiusTop, float radiusBottom, float height, int slices, Color* color) {
  DrawCylinder(*position, radiusTop, radiusBottom, height, slices, *color);
}

// Draw a cylinder with base at startPos and top at endPos
RLP_EXPORT void rp_DrawCylinderEx (Vector3* startPos, Vector3* endPos, float startRadius, float endRadius, int sides, Color* color) {
  DrawCylinderEx(*startPos, *endPos, startRadius, endRadius, sides, *color);
}

// Draw a cylinder/cone wires
RLP_EXPORT void rp_DrawCylinderWires (Vector3* position, float radiusTop, float radiusBottom, float height, int slices, Color* color) {
  DrawCylinderWires(*position, radiusTop, radiusBottom, height, slices, *color);
}

// Draw a cylinder wires with base at startPos and top at endPos
RLP_EXPORT void rp_DrawCylinderWiresEx (Vector3* startPos, Vector3* endPos, float startRadius, float endRadius, int sides, Color* color) {
  DrawCylinderWiresEx(*startPos, *endPos, startRadius, endRadius, sides, *color);
}

// Draw a capsule with the center of its sphere caps at startPos and endPos
RLP_EXPORT void rp_DrawCapsule (Vector3* startPos, Vector3* endPos, float radius, int slices, int rings, Color* color) {
  DrawCapsule(*startPos, *endPos, radius, slices, rings, *color);
}

// Draw capsule wireframe with the center of its sphere caps at startPos and endPos
RLP_EXPORT void rp_DrawCapsuleWires (Vector3* startPos, Vector3* endPos, float radius, int slices, int rings, Color* color) {
  DrawCapsuleWires(*startPos, *endPos, radius, slices, rings, *color);
}

// Draw a plane XZ
RLP_EXPORT void rp_DrawPlane (Vector3* centerPos, Vector2* size, Color* color) {
  DrawPlane(*centerPos, *size, *color);
}

// Draw a ray line
RLP_EXPORT void rp_DrawRay (Ray* ray, Color* color) {
  DrawRay(*ray, *color);
}

// Draw a grid (centered at (0, 0, 0))
RLP_EXPORT void rp_DrawGrid (int slices, float spacing) {
  DrawGrid(slices, spacing);
}

// Load model from files (meshes and materials)
RLP_EXPORT void rp_LoadModel (Model* rp_retVal, const char* fileName) {
  *rp_retVal = LoadModel(fileName);
}

// Load model from generated mesh (default material)
RLP_EXPORT void rp_LoadModelFromMesh (Model* rp_retVal, Mesh* mesh) {
  *rp_retVal = LoadModelFromMesh(*mesh);
}

// Check if a model is ready
RLP_EXPORT bool rp_IsModelReady (Model* model) {
  return IsModelReady(*model);
}

// Unload model (including meshes) from memory (RAM and/or VRAM)
RLP_EXPORT void rp_UnloadModel (Model* model) {
  UnloadModel(*model);
}

// Compute model bounding box limits (considers all meshes)
RLP_EXPORT void rp_GetModelBoundingBox (BoundingBox* rp_retVal, Model* model) {
  *rp_retVal = GetModelBoundingBox(*model);
}

// Draw a model (with texture if set)
RLP_EXPORT void rp_DrawModel (Model* model, Vector3* position, float scale, Color* tint) {
  DrawModel(*model, *position, scale, *tint);
}

// Draw a model with extended parameters
RLP_EXPORT void rp_DrawModelEx (Model* model, Vector3* position, Vector3* rotationAxis, float rotationAngle, Vector3* scale, Color* tint) {
  DrawModelEx(*model, *position, *rotationAxis, rotationAngle, *scale, *tint);
}

// Draw a model wires (with texture if set)
RLP_EXPORT void rp_DrawModelWires (Model* model, Vector3* position, float scale, Color* tint) {
  DrawModelWires(*model, *position, scale, *tint);
}

// Draw a model wires (with texture if set) with extended parameters
RLP_EXPORT void rp_DrawModelWiresEx (Model* model, Vector3* position, Vector3* rotationAxis, float rotationAngle, Vector3* scale, Color* tint) {
  DrawModelWiresEx(*model, *position, *rotationAxis, rotationAngle, *scale, *tint);
}

// Draw bounding box (wires)
RLP_EXPORT void rp_DrawBoundingBox (BoundingBox* box, Color* color) {
  DrawBoundingBox(*box, *color);
}

// Draw a billboard texture
RLP_EXPORT void rp_DrawBillboard (Camera* camera, Texture2D* texture, Vector3* position, float size, Color* tint) {
  DrawBillboard(*camera, *texture, *position, size, *tint);
}

// Draw a billboard texture defined by source
RLP_EXPORT void rp_DrawBillboardRec (Camera* camera, Texture2D* texture, Rectangle* source, Vector3* position, Vector2* size, Color* tint) {
  DrawBillboardRec(*camera, *texture, *source, *position, *size, *tint);
}

// Draw a billboard texture defined by source and rotation
RLP_EXPORT void rp_DrawBillboardPro (Camera* camera, Texture2D* texture, Rectangle* source, Vector3* position, Vector3* up, Vector2* size, Vector2* origin, float rotation, Color* tint) {
  DrawBillboardPro(*camera, *texture, *source, *position, *up, *size, *origin, rotation, *tint);
}

// Upload mesh vertex data in GPU and provide VAO/VBO ids
RLP_EXPORT void rp_UploadMesh (Mesh* mesh, bool dynamic) {
  UploadMesh(mesh, dynamic);
}

// Update mesh vertex data in GPU for a specific buffer index
RLP_EXPORT void rp_UpdateMeshBuffer (Mesh* mesh, int index, const void* data, int dataSize, int offset) {
  UpdateMeshBuffer(*mesh, index, data, dataSize, offset);
}

// Unload mesh data from CPU and GPU
RLP_EXPORT void rp_UnloadMesh (Mesh* mesh) {
  UnloadMesh(*mesh);
}

// Draw a 3d mesh with material and transform
RLP_EXPORT void rp_DrawMesh (Mesh* mesh, Material* material, Matrix* transform) {
  DrawMesh(*mesh, *material, *transform);
}

// Draw multiple mesh instances with material and different transforms
RLP_EXPORT void rp_DrawMeshInstanced (Mesh* mesh, Material* material, const Matrix* transforms, int instances) {
  DrawMeshInstanced(*mesh, *material, transforms, instances);
}

// Export mesh data to file, returns true on success
RLP_EXPORT bool rp_ExportMesh (Mesh* mesh, const char* fileName) {
  return ExportMesh(*mesh, fileName);
}

// Compute mesh bounding box limits
RLP_EXPORT void rp_GetMeshBoundingBox (BoundingBox* rp_retVal, Mesh* mesh) {
  *rp_retVal = GetMeshBoundingBox(*mesh);
}

// Compute mesh tangents
RLP_EXPORT void rp_GenMeshTangents (Mesh* mesh) {
  GenMeshTangents(mesh);
}

// Generate polygonal mesh
RLP_EXPORT void rp_GenMeshPoly (Mesh* rp_retVal, int sides, float radius) {
  *rp_retVal = GenMeshPoly(sides, radius);
}

// Generate plane mesh (with subdivisions)
RLP_EXPORT void rp_GenMeshPlane (Mesh* rp_retVal, float width, float length, int resX, int resZ) {
  *rp_retVal = GenMeshPlane(width, length, resX, resZ);
}

// Generate cuboid mesh
RLP_EXPORT void rp_GenMeshCube (Mesh* rp_retVal, float width, float height, float length) {
  *rp_retVal = GenMeshCube(width, height, length);
}

// Generate sphere mesh (standard sphere)
RLP_EXPORT void rp_GenMeshSphere (Mesh* rp_retVal, float radius, int rings, int slices) {
  *rp_retVal = GenMeshSphere(radius, rings, slices);
}

// Generate half-sphere mesh (no bottom cap)
RLP_EXPORT void rp_GenMeshHemiSphere (Mesh* rp_retVal, float radius, int rings, int slices) {
  *rp_retVal = GenMeshHemiSphere(radius, rings, slices);
}

// Generate cylinder mesh
RLP_EXPORT void rp_GenMeshCylinder (Mesh* rp_retVal, float radius, float height, int slices) {
  *rp_retVal = GenMeshCylinder(radius, height, slices);
}

// Generate cone/pyramid mesh
RLP_EXPORT void rp_GenMeshCone (Mesh* rp_retVal, float radius, float height, int slices) {
  *rp_retVal = GenMeshCone(radius, height, slices);
}

// Generate torus mesh
RLP_EXPORT void rp_GenMeshTorus (Mesh* rp_retVal, float radius, float size, int radSeg, int sides) {
  *rp_retVal = GenMeshTorus(radius, size, radSeg, sides);
}

// Generate trefoil knot mesh
RLP_EXPORT void rp_GenMeshKnot (Mesh* rp_retVal, float radius, float size, int radSeg, int sides) {
  *rp_retVal = GenMeshKnot(radius, size, radSeg, sides);
}

// Generate heightmap mesh from image data
RLP_EXPORT void rp_GenMeshHeightmap (Mesh* rp_retVal, Image* heightmap, Vector3* size) {
  *rp_retVal = GenMeshHeightmap(*heightmap, *size);
}

// Generate cubes-based map mesh from image data
RLP_EXPORT void rp_GenMeshCubicmap (Mesh* rp_retVal, Image* cubicmap, Vector3* cubeSize) {
  *rp_retVal = GenMeshCubicmap(*cubicmap, *cubeSize);
}

// Load materials from model file
RLP_EXPORT Material * rp_LoadMaterials (const char* fileName, int* materialCount) {
  return LoadMaterials(fileName, materialCount);
}

// Load default material (Supports: DIFFUSE, SPECULAR, NORMAL maps)
RLP_EXPORT void rp_LoadMaterialDefault (Material* rp_retVal) {
  *rp_retVal = LoadMaterialDefault();
}

// Check if a material is ready
RLP_EXPORT bool rp_IsMaterialReady (Material* material) {
  return IsMaterialReady(*material);
}

// Unload material from GPU memory (VRAM)
RLP_EXPORT void rp_UnloadMaterial (Material* material) {
  UnloadMaterial(*material);
}

// Set texture for a material map type (MATERIAL_MAP_DIFFUSE, MATERIAL_MAP_SPECULAR...)
RLP_EXPORT void rp_SetMaterialTexture (Material* material, int mapType, Texture2D* texture) {
  SetMaterialTexture(material, mapType, *texture);
}

// Set material for a mesh
RLP_EXPORT void rp_SetModelMeshMaterial (Model* model, int meshId, int materialId) {
  SetModelMeshMaterial(model, meshId, materialId);
}

// Load model animations from file
RLP_EXPORT ModelAnimation * rp_LoadModelAnimations (const char* fileName, int* animCount) {
  return LoadModelAnimations(fileName, animCount);
}

// Update model animation pose
RLP_EXPORT void rp_UpdateModelAnimation (Model* model, ModelAnimation* anim, int frame) {
  UpdateModelAnimation(*model, *anim, frame);
}

// Unload animation data
RLP_EXPORT void rp_UnloadModelAnimation (ModelAnimation* anim) {
  UnloadModelAnimation(*anim);
}

// Unload animation array data
RLP_EXPORT void rp_UnloadModelAnimations (ModelAnimation* animations, int animCount) {
  UnloadModelAnimations(animations, animCount);
}

// Check model animation skeleton match
RLP_EXPORT bool rp_IsModelAnimationValid (Model* model, ModelAnimation* anim) {
  return IsModelAnimationValid(*model, *anim);
}

// Check collision between two spheres
RLP_EXPORT bool rp_CheckCollisionSpheres (Vector3* center1, float radius1, Vector3* center2, float radius2) {
  return CheckCollisionSpheres(*center1, radius1, *center2, radius2);
}

// Check collision between two bounding boxes
RLP_EXPORT bool rp_CheckCollisionBoxes (BoundingBox* box1, BoundingBox* box2) {
  return CheckCollisionBoxes(*box1, *box2);
}

// Check collision between box and sphere
RLP_EXPORT bool rp_CheckCollisionBoxSphere (BoundingBox* box, Vector3* center, float radius) {
  return CheckCollisionBoxSphere(*box, *center, radius);
}

// Get collision info between ray and sphere
RLP_EXPORT void rp_GetRayCollisionSphere (RayCollision* rp_retVal, Ray* ray, Vector3* center, float radius) {
  *rp_retVal = GetRayCollisionSphere(*ray, *center, radius);
}

// Get collision info between ray and box
RLP_EXPORT void rp_GetRayCollisionBox (RayCollision* rp_retVal, Ray* ray, BoundingBox* box) {
  *rp_retVal = GetRayCollisionBox(*ray, *box);
}

// Get collision info between ray and mesh
RLP_EXPORT void rp_GetRayCollisionMesh (RayCollision* rp_retVal, Ray* ray, Mesh* mesh, Matrix* transform) {
  *rp_retVal = GetRayCollisionMesh(*ray, *mesh, *transform);
}

// Get collision info between ray and triangle
RLP_EXPORT void rp_GetRayCollisionTriangle (RayCollision* rp_retVal, Ray* ray, Vector3* p1, Vector3* p2, Vector3* p3) {
  *rp_retVal = GetRayCollisionTriangle(*ray, *p1, *p2, *p3);
}

// Get collision info between ray and quad
RLP_EXPORT void rp_GetRayCollisionQuad (RayCollision* rp_retVal, Ray* ray, Vector3* p1, Vector3* p2, Vector3* p3, Vector3* p4) {
  *rp_retVal = GetRayCollisionQuad(*ray, *p1, *p2, *p3, *p4);
}

// Initialize audio device and context
RLP_EXPORT void rp_InitAudioDevice () {
  InitAudioDevice();
}

// Close the audio device and context
RLP_EXPORT void rp_CloseAudioDevice () {
  CloseAudioDevice();
}

// Check if audio device has been initialized successfully
RLP_EXPORT bool rp_IsAudioDeviceReady () {
  return IsAudioDeviceReady();
}

// Set master volume (listener)
RLP_EXPORT void rp_SetMasterVolume (float volume) {
  SetMasterVolume(volume);
}

// Load wave data from file
RLP_EXPORT void rp_LoadWave (Wave* rp_retVal, const char* fileName) {
  *rp_retVal = LoadWave(fileName);
}

// Load wave from memory buffer, fileType refers to extension: i.e. '.wav'
RLP_EXPORT void rp_LoadWaveFromMemory (Wave* rp_retVal, const char* fileType, const unsigned char* fileData, int dataSize) {
  *rp_retVal = LoadWaveFromMemory(fileType, fileData, dataSize);
}

// Checks if wave data is ready
RLP_EXPORT bool rp_IsWaveReady (Wave* wave) {
  return IsWaveReady(*wave);
}

// Load sound from file
RLP_EXPORT void rp_LoadSound (Sound* rp_retVal, const char* fileName) {
  *rp_retVal = LoadSound(fileName);
}

// Load sound from wave data
RLP_EXPORT void rp_LoadSoundFromWave (Sound* rp_retVal, Wave* wave) {
  *rp_retVal = LoadSoundFromWave(*wave);
}

// Create a new sound that shares the same sample data as the source sound, does not own the sound data
RLP_EXPORT void rp_LoadSoundAlias (Sound* rp_retVal, Sound* source) {
  *rp_retVal = LoadSoundAlias(*source);
}

// Checks if a sound is ready
RLP_EXPORT bool rp_IsSoundReady (Sound* sound) {
  return IsSoundReady(*sound);
}

// Update sound buffer with new data
RLP_EXPORT void rp_UpdateSound (Sound* sound, const void* data, int sampleCount) {
  UpdateSound(*sound, data, sampleCount);
}

// Unload wave data
RLP_EXPORT void rp_UnloadWave (Wave* wave) {
  UnloadWave(*wave);
}

// Unload sound
RLP_EXPORT void rp_UnloadSound (Sound* sound) {
  UnloadSound(*sound);
}

// Unload a sound alias (does not deallocate sample data)
RLP_EXPORT void rp_UnloadSoundAlias (Sound* alias) {
  UnloadSoundAlias(*alias);
}

// Export wave data to file, returns true on success
RLP_EXPORT bool rp_ExportWave (Wave* wave, const char* fileName) {
  return ExportWave(*wave, fileName);
}

// Export wave sample data to code (.h), returns true on success
RLP_EXPORT bool rp_ExportWaveAsCode (Wave* wave, const char* fileName) {
  return ExportWaveAsCode(*wave, fileName);
}

// Play a sound
RLP_EXPORT void rp_PlaySound (Sound* sound) {
  PlaySound(*sound);
}

// Stop playing a sound
RLP_EXPORT void rp_StopSound (Sound* sound) {
  StopSound(*sound);
}

// Pause a sound
RLP_EXPORT void rp_PauseSound (Sound* sound) {
  PauseSound(*sound);
}

// Resume a paused sound
RLP_EXPORT void rp_ResumeSound (Sound* sound) {
  ResumeSound(*sound);
}

// Check if a sound is currently playing
RLP_EXPORT bool rp_IsSoundPlaying (Sound* sound) {
  return IsSoundPlaying(*sound);
}

// Set volume for a sound (1.0 is max level)
RLP_EXPORT void rp_SetSoundVolume (Sound* sound, float volume) {
  SetSoundVolume(*sound, volume);
}

// Set pitch for a sound (1.0 is base level)
RLP_EXPORT void rp_SetSoundPitch (Sound* sound, float pitch) {
  SetSoundPitch(*sound, pitch);
}

// Set pan for a sound (0.5 is center)
RLP_EXPORT void rp_SetSoundPan (Sound* sound, float pan) {
  SetSoundPan(*sound, pan);
}

// Copy a wave to a new wave
RLP_EXPORT void rp_WaveCopy (Wave* rp_retVal, Wave* wave) {
  *rp_retVal = WaveCopy(*wave);
}

// Crop a wave to defined samples range
RLP_EXPORT void rp_WaveCrop (Wave* wave, int initSample, int finalSample) {
  WaveCrop(wave, initSample, finalSample);
}

// Convert wave data to desired format
RLP_EXPORT void rp_WaveFormat (Wave* wave, int sampleRate, int sampleSize, int channels) {
  WaveFormat(wave, sampleRate, sampleSize, channels);
}

// Load samples data from wave as a 32bit float data array
RLP_EXPORT float * rp_LoadWaveSamples (Wave* wave) {
  return LoadWaveSamples(*wave);
}

// Unload samples data loaded with LoadWaveSamples()
RLP_EXPORT void rp_UnloadWaveSamples (float* samples) {
  UnloadWaveSamples(samples);
}

// Load music stream from file
RLP_EXPORT void rp_LoadMusicStream (Music* rp_retVal, const char* fileName) {
  *rp_retVal = LoadMusicStream(fileName);
}

// Load music stream from data
RLP_EXPORT void rp_LoadMusicStreamFromMemory (Music* rp_retVal, const char* fileType, const unsigned char* data, int dataSize) {
  *rp_retVal = LoadMusicStreamFromMemory(fileType, data, dataSize);
}

// Checks if a music stream is ready
RLP_EXPORT bool rp_IsMusicReady (Music* music) {
  return IsMusicReady(*music);
}

// Unload music stream
RLP_EXPORT void rp_UnloadMusicStream (Music* music) {
  UnloadMusicStream(*music);
}

// Start music playing
RLP_EXPORT void rp_PlayMusicStream (Music* music) {
  PlayMusicStream(*music);
}

// Check if music is playing
RLP_EXPORT bool rp_IsMusicStreamPlaying (Music* music) {
  return IsMusicStreamPlaying(*music);
}

// Updates buffers for music streaming
RLP_EXPORT void rp_UpdateMusicStream (Music* music) {
  UpdateMusicStream(*music);
}

// Stop music playing
RLP_EXPORT void rp_StopMusicStream (Music* music) {
  StopMusicStream(*music);
}

// Pause music playing
RLP_EXPORT void rp_PauseMusicStream (Music* music) {
  PauseMusicStream(*music);
}

// Resume playing paused music
RLP_EXPORT void rp_ResumeMusicStream (Music* music) {
  ResumeMusicStream(*music);
}

// Seek music to a position (in seconds)
RLP_EXPORT void rp_SeekMusicStream (Music* music, float position) {
  SeekMusicStream(*music, position);
}

// Set volume for music (1.0 is max level)
RLP_EXPORT void rp_SetMusicVolume (Music* music, float volume) {
  SetMusicVolume(*music, volume);
}

// Set pitch for a music (1.0 is base level)
RLP_EXPORT void rp_SetMusicPitch (Music* music, float pitch) {
  SetMusicPitch(*music, pitch);
}

// Set pan for a music (0.5 is center)
RLP_EXPORT void rp_SetMusicPan (Music* music, float pan) {
  SetMusicPan(*music, pan);
}

// Get music time length (in seconds)
RLP_EXPORT float rp_GetMusicTimeLength (Music* music) {
  return GetMusicTimeLength(*music);
}

// Get current music time played (in seconds)
RLP_EXPORT float rp_GetMusicTimePlayed (Music* music) {
  return GetMusicTimePlayed(*music);
}

// Load audio stream (to stream raw audio pcm data)
RLP_EXPORT void rp_LoadAudioStream (AudioStream* rp_retVal, unsigned int sampleRate, unsigned int sampleSize, unsigned int channels) {
  *rp_retVal = LoadAudioStream(sampleRate, sampleSize, channels);
}

// Checks if an audio stream is ready
RLP_EXPORT bool rp_IsAudioStreamReady (AudioStream* stream) {
  return IsAudioStreamReady(*stream);
}

// Unload audio stream and free memory
RLP_EXPORT void rp_UnloadAudioStream (AudioStream* stream) {
  UnloadAudioStream(*stream);
}

// Update audio stream buffers with data
RLP_EXPORT void rp_UpdateAudioStream (AudioStream* stream, const void* data, int frameCount) {
  UpdateAudioStream(*stream, data, frameCount);
}

// Check if any audio stream buffers requires refill
RLP_EXPORT bool rp_IsAudioStreamProcessed (AudioStream* stream) {
  return IsAudioStreamProcessed(*stream);
}

// Play audio stream
RLP_EXPORT void rp_PlayAudioStream (AudioStream* stream) {
  PlayAudioStream(*stream);
}

// Pause audio stream
RLP_EXPORT void rp_PauseAudioStream (AudioStream* stream) {
  PauseAudioStream(*stream);
}

// Resume audio stream
RLP_EXPORT void rp_ResumeAudioStream (AudioStream* stream) {
  ResumeAudioStream(*stream);
}

// Check if audio stream is playing
RLP_EXPORT bool rp_IsAudioStreamPlaying (AudioStream* stream) {
  return IsAudioStreamPlaying(*stream);
}

// Stop audio stream
RLP_EXPORT void rp_StopAudioStream (AudioStream* stream) {
  StopAudioStream(*stream);
}

// Set volume for audio stream (1.0 is max level)
RLP_EXPORT void rp_SetAudioStreamVolume (AudioStream* stream, float volume) {
  SetAudioStreamVolume(*stream, volume);
}

// Set pitch for audio stream (1.0 is base level)
RLP_EXPORT void rp_SetAudioStreamPitch (AudioStream* stream, float pitch) {
  SetAudioStreamPitch(*stream, pitch);
}

// Set pan for audio stream (0.5 is centered)
RLP_EXPORT void rp_SetAudioStreamPan (AudioStream* stream, float pan) {
  SetAudioStreamPan(*stream, pan);
}

// Default size for new audio streams
RLP_EXPORT void rp_SetAudioStreamBufferSizeDefault (int size) {
  SetAudioStreamBufferSizeDefault(size);
}

// Audio thread callback to request new data
RLP_EXPORT void rp_SetAudioStreamCallback (AudioStream* stream, AudioCallback* callback) {
  SetAudioStreamCallback(*stream, *callback);
}

// Attach audio stream processor to stream, receives the samples as <float>s
RLP_EXPORT void rp_AttachAudioStreamProcessor (AudioStream* stream, AudioCallback* processor) {
  AttachAudioStreamProcessor(*stream, *processor);
}

// Detach audio stream processor from stream
RLP_EXPORT void rp_DetachAudioStreamProcessor (AudioStream* stream, AudioCallback* processor) {
  DetachAudioStreamProcessor(*stream, *processor);
}

// Attach audio stream processor to the entire audio pipeline, receives the samples as <float>s
RLP_EXPORT void rp_AttachAudioMixedProcessor (AudioCallback* processor) {
  AttachAudioMixedProcessor(*processor);
}

// Detach audio stream processor from the entire audio pipeline
RLP_EXPORT void rp_DetachAudioMixedProcessor (AudioCallback* processor) {
  DetachAudioMixedProcessor(*processor);
}

