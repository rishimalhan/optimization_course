# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.5

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
CMAKE_SOURCE_DIR = /home/badass/optimization/eigen-eigen-5a0156e40feb

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/badass/optimization/eigen-eigen-5a0156e40feb/build_dir

# Include any dependencies generated for this target.
include test/CMakeFiles/geo_alignedbox_11.dir/depend.make

# Include the progress variables for this target.
include test/CMakeFiles/geo_alignedbox_11.dir/progress.make

# Include the compile flags for this target's objects.
include test/CMakeFiles/geo_alignedbox_11.dir/flags.make

test/CMakeFiles/geo_alignedbox_11.dir/geo_alignedbox.cpp.o: test/CMakeFiles/geo_alignedbox_11.dir/flags.make
test/CMakeFiles/geo_alignedbox_11.dir/geo_alignedbox.cpp.o: ../test/geo_alignedbox.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/badass/optimization/eigen-eigen-5a0156e40feb/build_dir/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object test/CMakeFiles/geo_alignedbox_11.dir/geo_alignedbox.cpp.o"
	cd /home/badass/optimization/eigen-eigen-5a0156e40feb/build_dir/test && /usr/bin/c++   $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/geo_alignedbox_11.dir/geo_alignedbox.cpp.o -c /home/badass/optimization/eigen-eigen-5a0156e40feb/test/geo_alignedbox.cpp

test/CMakeFiles/geo_alignedbox_11.dir/geo_alignedbox.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/geo_alignedbox_11.dir/geo_alignedbox.cpp.i"
	cd /home/badass/optimization/eigen-eigen-5a0156e40feb/build_dir/test && /usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/badass/optimization/eigen-eigen-5a0156e40feb/test/geo_alignedbox.cpp > CMakeFiles/geo_alignedbox_11.dir/geo_alignedbox.cpp.i

test/CMakeFiles/geo_alignedbox_11.dir/geo_alignedbox.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/geo_alignedbox_11.dir/geo_alignedbox.cpp.s"
	cd /home/badass/optimization/eigen-eigen-5a0156e40feb/build_dir/test && /usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/badass/optimization/eigen-eigen-5a0156e40feb/test/geo_alignedbox.cpp -o CMakeFiles/geo_alignedbox_11.dir/geo_alignedbox.cpp.s

test/CMakeFiles/geo_alignedbox_11.dir/geo_alignedbox.cpp.o.requires:

.PHONY : test/CMakeFiles/geo_alignedbox_11.dir/geo_alignedbox.cpp.o.requires

test/CMakeFiles/geo_alignedbox_11.dir/geo_alignedbox.cpp.o.provides: test/CMakeFiles/geo_alignedbox_11.dir/geo_alignedbox.cpp.o.requires
	$(MAKE) -f test/CMakeFiles/geo_alignedbox_11.dir/build.make test/CMakeFiles/geo_alignedbox_11.dir/geo_alignedbox.cpp.o.provides.build
.PHONY : test/CMakeFiles/geo_alignedbox_11.dir/geo_alignedbox.cpp.o.provides

test/CMakeFiles/geo_alignedbox_11.dir/geo_alignedbox.cpp.o.provides.build: test/CMakeFiles/geo_alignedbox_11.dir/geo_alignedbox.cpp.o


# Object files for target geo_alignedbox_11
geo_alignedbox_11_OBJECTS = \
"CMakeFiles/geo_alignedbox_11.dir/geo_alignedbox.cpp.o"

# External object files for target geo_alignedbox_11
geo_alignedbox_11_EXTERNAL_OBJECTS =

test/geo_alignedbox_11: test/CMakeFiles/geo_alignedbox_11.dir/geo_alignedbox.cpp.o
test/geo_alignedbox_11: test/CMakeFiles/geo_alignedbox_11.dir/build.make
test/geo_alignedbox_11: test/CMakeFiles/geo_alignedbox_11.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/badass/optimization/eigen-eigen-5a0156e40feb/build_dir/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable geo_alignedbox_11"
	cd /home/badass/optimization/eigen-eigen-5a0156e40feb/build_dir/test && $(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/geo_alignedbox_11.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
test/CMakeFiles/geo_alignedbox_11.dir/build: test/geo_alignedbox_11

.PHONY : test/CMakeFiles/geo_alignedbox_11.dir/build

test/CMakeFiles/geo_alignedbox_11.dir/requires: test/CMakeFiles/geo_alignedbox_11.dir/geo_alignedbox.cpp.o.requires

.PHONY : test/CMakeFiles/geo_alignedbox_11.dir/requires

test/CMakeFiles/geo_alignedbox_11.dir/clean:
	cd /home/badass/optimization/eigen-eigen-5a0156e40feb/build_dir/test && $(CMAKE_COMMAND) -P CMakeFiles/geo_alignedbox_11.dir/cmake_clean.cmake
.PHONY : test/CMakeFiles/geo_alignedbox_11.dir/clean

test/CMakeFiles/geo_alignedbox_11.dir/depend:
	cd /home/badass/optimization/eigen-eigen-5a0156e40feb/build_dir && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/badass/optimization/eigen-eigen-5a0156e40feb /home/badass/optimization/eigen-eigen-5a0156e40feb/test /home/badass/optimization/eigen-eigen-5a0156e40feb/build_dir /home/badass/optimization/eigen-eigen-5a0156e40feb/build_dir/test /home/badass/optimization/eigen-eigen-5a0156e40feb/build_dir/test/CMakeFiles/geo_alignedbox_11.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : test/CMakeFiles/geo_alignedbox_11.dir/depend

