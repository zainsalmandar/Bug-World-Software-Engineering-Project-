# CMake generated Testfile for 
# Source directory: /home/mvitanov/Desktop/phase4/phase3
# Build directory: /home/mvitanov/Desktop/phase4/phase3/build
# 
# This file includes the relevant testing commands required for 
# testing this directory and lists subdirectories to be tested as well.
add_test(Instructions "/home/mvitanov/Desktop/phase4/phase3/build/test/testInstructions")
add_test(Program "/home/mvitanov/Desktop/phase4/phase3/build/test/testProgram")
add_test(Cell "/home/mvitanov/Desktop/phase4/phase3/build/test/testCell")
add_test(Marker "/home/mvitanov/Desktop/phase4/phase3/build/test/testMarker")
add_test(Bug "/home/mvitanov/Desktop/phase4/phase3/build/test/testBug")
add_test(World "/home/mvitanov/Desktop/phase4/phase3/build/test/testWorld")
add_test(I_direction "/home/mvitanov/Desktop/phase4/phase3/build/test/testI_direction")
subdirs("src")
subdirs("test")
