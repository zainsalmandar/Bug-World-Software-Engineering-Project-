cmake_minimum_required(VERSION 3.0 FATAL_ERROR)

include_directories(${PROJECT_BINARY_DIR}/src)

add_library(lbug Bug.cpp)
add_library(lmarker Marker.cpp)
add_library(lcell Cell.cpp)
add_library(lworld World.cpp)
add_library(lprogram Program.cpp)

add_subdirectory(commands)
