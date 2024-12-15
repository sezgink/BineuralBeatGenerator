# Minimum version of CMake
cmake_minimum_required(VERSION 3.10)

# Project name and language
project(BinauralBeatGenerator LANGUAGES C)

# Set the C Standard
set(CMAKE_C_STANDARD 11)
set(CMAKE_C_STANDARD_REQUIRED True)

# Define source files
set(SOURCES 
    src/main.c
    src/noiseGenerator.c
    src/saveOperations.c
    src/scalarOperations.c
    src/waveGenerator.c
)

# Add executable
add_executable(${PROJECT_NAME} ${SOURCES})

# Platform-Specific Compiler Definitions
if (MSVC) # For Visual Studio (Windows)
    target_compile_definitions(${PROJECT_NAME} PRIVATE PLATFORM_WINDOWS)
elseif (CMAKE_C_COMPILER_ID STREQUAL "GNU")
    target_compile_definitions(${PROJECT_NAME} PRIVATE PLATFORM_UNIX)
endif()
