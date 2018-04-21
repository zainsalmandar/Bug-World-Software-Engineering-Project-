cmake_minimum_required(VERSION 3.0 FATAL_ERROR)

include_directories(${PROJECT_BINARY_DIR}/src)

file(GLOB assembler
    "*.h"
    "*.cpp"
    "commands/*.cpp"
)
add_library(asm-test ${assembler})
add_executable(asm ${assembler})
target_link_libraries (asm asm-test)