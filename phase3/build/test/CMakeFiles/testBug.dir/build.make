# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.9

# Delete rule output on recipe failure.
.DELETE_ON_ERROR:


#=============================================================================
# Special targets provided by cmake.

# Disable implicit rules so canonical targets will work.
.SUFFIXES:


# Remove some rules from gmake that .SUFFIXES does not remove.
SUFFIXES =

.SUFFIXES: .hpux_make_needs_suffix_list


# Suppress display of executed commands.
$(VERBOSE).SILENT:


# A target that is always out of date.
cmake_force:

.PHONY : cmake_force

#=============================================================================
# Set environment variables for the build.

# The shell in which to execute make rules.
SHELL = /bin/sh

# The CMake executable.
CMAKE_COMMAND = /usr/bin/cmake

# The command to remove a file.
RM = /usr/bin/cmake -E remove -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /home/mvitanov/Desktop/phase4/phase3

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/mvitanov/Desktop/phase4/phase3/build

# Include any dependencies generated for this target.
include test/CMakeFiles/testBug.dir/depend.make

# Include the progress variables for this target.
include test/CMakeFiles/testBug.dir/progress.make

# Include the compile flags for this target's objects.
include test/CMakeFiles/testBug.dir/flags.make

test/CMakeFiles/testBug.dir/simulator/BugTestRunner.cpp.o: test/CMakeFiles/testBug.dir/flags.make
test/CMakeFiles/testBug.dir/simulator/BugTestRunner.cpp.o: ../test/simulator/BugTestRunner.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/mvitanov/Desktop/phase4/phase3/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object test/CMakeFiles/testBug.dir/simulator/BugTestRunner.cpp.o"
	cd /home/mvitanov/Desktop/phase4/phase3/build/test && /usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/testBug.dir/simulator/BugTestRunner.cpp.o -c /home/mvitanov/Desktop/phase4/phase3/test/simulator/BugTestRunner.cpp

test/CMakeFiles/testBug.dir/simulator/BugTestRunner.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/testBug.dir/simulator/BugTestRunner.cpp.i"
	cd /home/mvitanov/Desktop/phase4/phase3/build/test && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/mvitanov/Desktop/phase4/phase3/test/simulator/BugTestRunner.cpp > CMakeFiles/testBug.dir/simulator/BugTestRunner.cpp.i

test/CMakeFiles/testBug.dir/simulator/BugTestRunner.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/testBug.dir/simulator/BugTestRunner.cpp.s"
	cd /home/mvitanov/Desktop/phase4/phase3/build/test && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/mvitanov/Desktop/phase4/phase3/test/simulator/BugTestRunner.cpp -o CMakeFiles/testBug.dir/simulator/BugTestRunner.cpp.s

test/CMakeFiles/testBug.dir/simulator/BugTestRunner.cpp.o.requires:

.PHONY : test/CMakeFiles/testBug.dir/simulator/BugTestRunner.cpp.o.requires

test/CMakeFiles/testBug.dir/simulator/BugTestRunner.cpp.o.provides: test/CMakeFiles/testBug.dir/simulator/BugTestRunner.cpp.o.requires
	$(MAKE) -f test/CMakeFiles/testBug.dir/build.make test/CMakeFiles/testBug.dir/simulator/BugTestRunner.cpp.o.provides.build
.PHONY : test/CMakeFiles/testBug.dir/simulator/BugTestRunner.cpp.o.provides

test/CMakeFiles/testBug.dir/simulator/BugTestRunner.cpp.o.provides.build: test/CMakeFiles/testBug.dir/simulator/BugTestRunner.cpp.o


test/CMakeFiles/testBug.dir/simulator/BugTest.cpp.o: test/CMakeFiles/testBug.dir/flags.make
test/CMakeFiles/testBug.dir/simulator/BugTest.cpp.o: ../test/simulator/BugTest.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/mvitanov/Desktop/phase4/phase3/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building CXX object test/CMakeFiles/testBug.dir/simulator/BugTest.cpp.o"
	cd /home/mvitanov/Desktop/phase4/phase3/build/test && /usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/testBug.dir/simulator/BugTest.cpp.o -c /home/mvitanov/Desktop/phase4/phase3/test/simulator/BugTest.cpp

test/CMakeFiles/testBug.dir/simulator/BugTest.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/testBug.dir/simulator/BugTest.cpp.i"
	cd /home/mvitanov/Desktop/phase4/phase3/build/test && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/mvitanov/Desktop/phase4/phase3/test/simulator/BugTest.cpp > CMakeFiles/testBug.dir/simulator/BugTest.cpp.i

test/CMakeFiles/testBug.dir/simulator/BugTest.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/testBug.dir/simulator/BugTest.cpp.s"
	cd /home/mvitanov/Desktop/phase4/phase3/build/test && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/mvitanov/Desktop/phase4/phase3/test/simulator/BugTest.cpp -o CMakeFiles/testBug.dir/simulator/BugTest.cpp.s

test/CMakeFiles/testBug.dir/simulator/BugTest.cpp.o.requires:

.PHONY : test/CMakeFiles/testBug.dir/simulator/BugTest.cpp.o.requires

test/CMakeFiles/testBug.dir/simulator/BugTest.cpp.o.provides: test/CMakeFiles/testBug.dir/simulator/BugTest.cpp.o.requires
	$(MAKE) -f test/CMakeFiles/testBug.dir/build.make test/CMakeFiles/testBug.dir/simulator/BugTest.cpp.o.provides.build
.PHONY : test/CMakeFiles/testBug.dir/simulator/BugTest.cpp.o.provides

test/CMakeFiles/testBug.dir/simulator/BugTest.cpp.o.provides.build: test/CMakeFiles/testBug.dir/simulator/BugTest.cpp.o


# Object files for target testBug
testBug_OBJECTS = \
"CMakeFiles/testBug.dir/simulator/BugTestRunner.cpp.o" \
"CMakeFiles/testBug.dir/simulator/BugTest.cpp.o"

# External object files for target testBug
testBug_EXTERNAL_OBJECTS =

test/testBug: test/CMakeFiles/testBug.dir/simulator/BugTestRunner.cpp.o
test/testBug: test/CMakeFiles/testBug.dir/simulator/BugTest.cpp.o
test/testBug: test/CMakeFiles/testBug.dir/build.make
test/testBug: src/simulator/liblbug.a
test/testBug: test/CMakeFiles/testBug.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/mvitanov/Desktop/phase4/phase3/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Linking CXX executable testBug"
	cd /home/mvitanov/Desktop/phase4/phase3/build/test && $(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/testBug.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
test/CMakeFiles/testBug.dir/build: test/testBug

.PHONY : test/CMakeFiles/testBug.dir/build

test/CMakeFiles/testBug.dir/requires: test/CMakeFiles/testBug.dir/simulator/BugTestRunner.cpp.o.requires
test/CMakeFiles/testBug.dir/requires: test/CMakeFiles/testBug.dir/simulator/BugTest.cpp.o.requires

.PHONY : test/CMakeFiles/testBug.dir/requires

test/CMakeFiles/testBug.dir/clean:
	cd /home/mvitanov/Desktop/phase4/phase3/build/test && $(CMAKE_COMMAND) -P CMakeFiles/testBug.dir/cmake_clean.cmake
.PHONY : test/CMakeFiles/testBug.dir/clean

test/CMakeFiles/testBug.dir/depend:
	cd /home/mvitanov/Desktop/phase4/phase3/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/mvitanov/Desktop/phase4/phase3 /home/mvitanov/Desktop/phase4/phase3/test /home/mvitanov/Desktop/phase4/phase3/build /home/mvitanov/Desktop/phase4/phase3/build/test /home/mvitanov/Desktop/phase4/phase3/build/test/CMakeFiles/testBug.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : test/CMakeFiles/testBug.dir/depend
