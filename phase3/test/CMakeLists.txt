cmake_minimum_required(VERSION 3.0 FATAL_ERROR)

include_directories(${CMAKE_SOURCE_DIR}/src)
include_directories(${CMAKE_SOURCE_DIR}/src/assembler)
include_directories(${CMAKE_SOURCE_DIR}/src/assembler/commands)
include_directories(${CMAKE_SOURCE_DIR}/src/simulator)

configure_file(${CMAKE_SOURCE_DIR}/test/assembler/test.buggy test.buggy COPYONLY)

add_executable(testInstructions assembler/TestInstructions.cpp)
add_executable(testProgram assembler/TestProgram.cpp)
add_executable(testBug simulator/BugTestRunner.cpp simulator/BugTest.cpp)
add_executable(testMarker simulator/MarkerTestRunner.cpp simulator/MarkerTest.cpp)
add_executable(testCell simulator/CellTestRunner.cpp simulator/CellTest.cpp)

target_link_libraries(testInstructions cppunit ${CMAKE_DL_LIBS} dl asm-test)
target_link_libraries(testProgram cppunit ${CMAKE_DL_LIBS} dl asm-test)
target_link_libraries(testBug cppunit lbug)
target_link_libraries(testMarker cppunit lmarker)
target_link_libraries(testCell cppunit lcell lbug)