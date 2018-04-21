cmake_minimum_required(VERSION 3.0.0 FATAL_ERROR)
project(BugWorld)

set(CMAKE_CXX_FLAGS "-g -O0 -std=c++11 -Wall -fprofile-arcs -ftest-coverage")
set(CMAKE_C_FLAGS "-g -O0 -std=c++11 -Wall -W -fprofile-arcs -ftest-coverage")
set(CMAKE_EXE_LINKER_FLAGS "-fprofile-arcs -ftest-coverage")

find_package(Threads)
find_package(PkgConfig)

if(CMAKE_COMPILER_IS_GNUCC)
    add_definitions(-Wall -Werror)
endif(CMAKE_COMPILER_IS_GNUCC)

add_subdirectory(src)
add_subdirectory(test)

enable_testing()
add_test(NAME Instructions COMMAND testInstructions)
add_test(NAME Program COMMAND testProgram)
add_test(NAME Cell COMMAND testCell)
add_test(NAME Marker COMMAND testMarker)
add_test(NAME Bug COMMAND testBug)