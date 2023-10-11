# this will build the DLL and the test-program
# cmake --build build

cmake_minimum_required(VERSION 3.0)
project(raylib_pointers C)
set(CMAKE_C_STANDARD 99)

include(FetchContent)
set(BUILD_EXAMPLES OFF CACHE BOOL "" FORCE)
set(BUILD_GAMES    OFF CACHE BOOL "" FORCE)
set(CMAKE_BUILD_TYPE "Release")
FetchContent_Declare(raylib GIT_REPOSITORY https://github.com/raysan5/raylib.git GIT_TAG 4.5.0)
FetchContent_MakeAvailable(raylib)

add_library(${PROJECT_NAME} STATIC src/lib.c)
target_link_libraries(${PROJECT_NAME} PRIVATE raylib)

add_executable(${PROJECT_NAME}_test src/lib.c src/test.c)
target_link_libraries(${PROJECT_NAME}_test PRIVATE raylib)