# this will build the example
# cmake -B build && cmake --build build

cmake_minimum_required(VERSION 3.11)

project(raylib-pointers
  DESCRIPTION "raylib with pointers"
  HOMEPAGE_URL "https://github.com/konsumer/raylib-pointers"
  VERSION 0.0.1
  LANGUAGES C
)

set(raylib_USE_STATIC_LIBS TRUE)

# raylib
find_package(raylib QUIET)
if (NOT raylib_FOUND)
    include(FetchContent)
    FetchContent_Declare(
        raylib
        GIT_REPOSITORY https://github.com/raysan5/raylib.git
        GIT_TAG 5.0
        GIT_SHALLOW 1
    )
    FetchContent_GetProperties(raylib)
    if (NOT raylib_POPULATED) # Have we downloaded raylib yet?
        set(FETCHCONTENT_QUIET NO)
        FetchContent_Populate(raylib)
        set(BUILD_EXAMPLES OFF CACHE BOOL "" FORCE)
        set(BUILD_GAMES    OFF CACHE BOOL "" FORCE)
        add_subdirectory(${raylib_SOURCE_DIR} ${raylib_BINARY_DIR})
    endif()
endif()


add_library(raylib-pointers SHARED src/lib.c)
set_property(TARGET raylib-pointers PROPERTY POSITION_INDEPENDENT_CODE ON)
target_link_libraries(raylib-pointers PUBLIC raylib)

add_library(raylib-pointers-static STATIC src/lib.c)
target_link_libraries(raylib-pointers-static PUBLIC raylib)
set_target_properties(raylib-pointers-static PROPERTIES OUTPUT_NAME raylib-pointers)

add_executable(test example/test.c)
target_link_libraries(test raylib-pointers-static)
target_include_directories(test PRIVATE src)