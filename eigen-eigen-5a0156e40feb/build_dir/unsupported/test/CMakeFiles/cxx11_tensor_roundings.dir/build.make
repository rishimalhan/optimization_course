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
include unsupported/test/CMakeFiles/cxx11_tensor_roundings.dir/depend.make

# Include the progress variables for this target.
include unsupported/test/CMakeFiles/cxx11_tensor_roundings.dir/progress.make

# Include the compile flags for this target's objects.
include unsupported/test/CMakeFiles/cxx11_tensor_roundings.dir/flags.make

unsupported/test/CMakeFiles/cxx11_tensor_roundings.dir/cxx11_tensor_roundings.cpp.o: unsupported/test/CMakeFiles/cxx11_tensor_roundings.dir/flags.make
unsupported/test/CMakeFiles/cxx11_tensor_roundings.dir/cxx11_tensor_roundings.cpp.o: ../unsupported/test/cxx11_tensor_roundings.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/badass/optimization/eigen-eigen-5a0156e40feb/build_dir/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object unsupported/test/CMakeFiles/cxx11_tensor_roundings.dir/cxx11_tensor_roundings.cpp.o"
	cd /home/badass/optimization/eigen-eigen-5a0156e40feb/build_dir/unsupported/test && /usr/bin/c++   $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/cxx11_tensor_roundings.dir/cxx11_tensor_roundings.cpp.o -c /home/badass/optimization/eigen-eigen-5a0156e40feb/unsupported/test/cxx11_tensor_roundings.cpp

unsupported/test/CMakeFiles/cxx11_tensor_roundings.dir/cxx11_tensor_roundings.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/cxx11_tensor_roundings.dir/cxx11_tensor_roundings.cpp.i"
	cd /home/badass/optimization/eigen-eigen-5a0156e40feb/build_dir/unsupported/test && /usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/badass/optimization/eigen-eigen-5a0156e40feb/unsupported/test/cxx11_tensor_roundings.cpp > CMakeFiles/cxx11_tensor_roundings.dir/cxx11_tensor_roundings.cpp.i

unsupported/test/CMakeFiles/cxx11_tensor_roundings.dir/cxx11_tensor_roundings.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/cxx11_tensor_roundings.dir/cxx11_tensor_roundings.cpp.s"
	cd /home/badass/optimization/eigen-eigen-5a0156e40feb/build_dir/unsupported/test && /usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/badass/optimization/eigen-eigen-5a0156e40feb/unsupported/test/cxx11_tensor_roundings.cpp -o CMakeFiles/cxx11_tensor_roundings.dir/cxx11_tensor_roundings.cpp.s

unsupported/test/CMakeFiles/cxx11_tensor_roundings.dir/cxx11_tensor_roundings.cpp.o.requires:

.PHONY : unsupported/test/CMakeFiles/cxx11_tensor_roundings.dir/cxx11_tensor_roundings.cpp.o.requires

unsupported/test/CMakeFiles/cxx11_tensor_roundings.dir/cxx11_tensor_roundings.cpp.o.provides: unsupported/test/CMakeFiles/cxx11_tensor_roundings.dir/cxx11_tensor_roundings.cpp.o.requires
	$(MAKE) -f unsupported/test/CMakeFiles/cxx11_tensor_roundings.dir/build.make unsupported/test/CMakeFiles/cxx11_tensor_roundings.dir/cxx11_tensor_roundings.cpp.o.provides.build
.PHONY : unsupported/test/CMakeFiles/cxx11_tensor_roundings.dir/cxx11_tensor_roundings.cpp.o.provides

unsupported/test/CMakeFiles/cxx11_tensor_roundings.dir/cxx11_tensor_roundings.cpp.o.provides.build: unsupported/test/CMakeFiles/cxx11_tensor_roundings.dir/cxx11_tensor_roundings.cpp.o


# Object files for target cxx11_tensor_roundings
cxx11_tensor_roundings_OBJECTS = \
"CMakeFiles/cxx11_tensor_roundings.dir/cxx11_tensor_roundings.cpp.o"

# External object files for target cxx11_tensor_roundings
cxx11_tensor_roundings_EXTERNAL_OBJECTS =

unsupported/test/cxx11_tensor_roundings: unsupported/test/CMakeFiles/cxx11_tensor_roundings.dir/cxx11_tensor_roundings.cpp.o
unsupported/test/cxx11_tensor_roundings: unsupported/test/CMakeFiles/cxx11_tensor_roundings.dir/build.make
unsupported/test/cxx11_tensor_roundings: unsupported/test/CMakeFiles/cxx11_tensor_roundings.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/badass/optimization/eigen-eigen-5a0156e40feb/build_dir/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable cxx11_tensor_roundings"
	cd /home/badass/optimization/eigen-eigen-5a0156e40feb/build_dir/unsupported/test && $(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/cxx11_tensor_roundings.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
unsupported/test/CMakeFiles/cxx11_tensor_roundings.dir/build: unsupported/test/cxx11_tensor_roundings

.PHONY : unsupported/test/CMakeFiles/cxx11_tensor_roundings.dir/build

unsupported/test/CMakeFiles/cxx11_tensor_roundings.dir/requires: unsupported/test/CMakeFiles/cxx11_tensor_roundings.dir/cxx11_tensor_roundings.cpp.o.requires

.PHONY : unsupported/test/CMakeFiles/cxx11_tensor_roundings.dir/requires

unsupported/test/CMakeFiles/cxx11_tensor_roundings.dir/clean:
	cd /home/badass/optimization/eigen-eigen-5a0156e40feb/build_dir/unsupported/test && $(CMAKE_COMMAND) -P CMakeFiles/cxx11_tensor_roundings.dir/cmake_clean.cmake
.PHONY : unsupported/test/CMakeFiles/cxx11_tensor_roundings.dir/clean

unsupported/test/CMakeFiles/cxx11_tensor_roundings.dir/depend:
	cd /home/badass/optimization/eigen-eigen-5a0156e40feb/build_dir && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/badass/optimization/eigen-eigen-5a0156e40feb /home/badass/optimization/eigen-eigen-5a0156e40feb/unsupported/test /home/badass/optimization/eigen-eigen-5a0156e40feb/build_dir /home/badass/optimization/eigen-eigen-5a0156e40feb/build_dir/unsupported/test /home/badass/optimization/eigen-eigen-5a0156e40feb/build_dir/unsupported/test/CMakeFiles/cxx11_tensor_roundings.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : unsupported/test/CMakeFiles/cxx11_tensor_roundings.dir/depend

