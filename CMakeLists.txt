cmake_minimum_required(VERSION 3.10)

project(sdl2_test VERSION 0.1)

# Windows SDL2 pre-setup
if (MSVC)
    set(SDL2_DIR "${CMAKE_SOURCE_DIR}/SDL2-$ENV{SDL2_VERSION}/")
endif(MSVC)

# SDL2
set(CMAKE_MODULE_PATH ${CMAKE_MODULE_PATH} "${CMAKE_SOURCE_DIR}/cmake/")
find_package(SDL2 REQUIRED)

# Executable target
add_executable(sdl2_test main.c)
target_include_directories(sdl2_test PUBLIC
                           "${PROJECT_BINARY_DIR}"
			   "${SDL2_INCLUDE_DIR}")
target_link_libraries(sdl2_test "${SDL2_LIBRARY}")
