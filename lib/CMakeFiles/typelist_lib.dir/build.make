# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.15

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
CMAKE_COMMAND = /usr/local/Cellar/cmake/3.15.3/bin/cmake

# The command to remove a file.
RM = /usr/local/Cellar/cmake/3.15.3/bin/cmake -E remove -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /Users/amaxacla/programs/typelist

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /Users/amaxacla/programs/typelist

# Include any dependencies generated for this target.
include lib/CMakeFiles/typelist_lib.dir/depend.make

# Include the progress variables for this target.
include lib/CMakeFiles/typelist_lib.dir/progress.make

# Include the compile flags for this target's objects.
include lib/CMakeFiles/typelist_lib.dir/flags.make

lib/CMakeFiles/typelist_lib.dir/dummy.cpp.o: lib/CMakeFiles/typelist_lib.dir/flags.make
lib/CMakeFiles/typelist_lib.dir/dummy.cpp.o: lib/dummy.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/amaxacla/programs/typelist/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object lib/CMakeFiles/typelist_lib.dir/dummy.cpp.o"
	cd /Users/amaxacla/programs/typelist/lib && /Library/Developer/CommandLineTools/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/typelist_lib.dir/dummy.cpp.o -c /Users/amaxacla/programs/typelist/lib/dummy.cpp

lib/CMakeFiles/typelist_lib.dir/dummy.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/typelist_lib.dir/dummy.cpp.i"
	cd /Users/amaxacla/programs/typelist/lib && /Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /Users/amaxacla/programs/typelist/lib/dummy.cpp > CMakeFiles/typelist_lib.dir/dummy.cpp.i

lib/CMakeFiles/typelist_lib.dir/dummy.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/typelist_lib.dir/dummy.cpp.s"
	cd /Users/amaxacla/programs/typelist/lib && /Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /Users/amaxacla/programs/typelist/lib/dummy.cpp -o CMakeFiles/typelist_lib.dir/dummy.cpp.s

# Object files for target typelist_lib
typelist_lib_OBJECTS = \
"CMakeFiles/typelist_lib.dir/dummy.cpp.o"

# External object files for target typelist_lib
typelist_lib_EXTERNAL_OBJECTS =

lib/libtypelist_lib.a: lib/CMakeFiles/typelist_lib.dir/dummy.cpp.o
lib/libtypelist_lib.a: lib/CMakeFiles/typelist_lib.dir/build.make
lib/libtypelist_lib.a: lib/CMakeFiles/typelist_lib.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/Users/amaxacla/programs/typelist/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX static library libtypelist_lib.a"
	cd /Users/amaxacla/programs/typelist/lib && $(CMAKE_COMMAND) -P CMakeFiles/typelist_lib.dir/cmake_clean_target.cmake
	cd /Users/amaxacla/programs/typelist/lib && $(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/typelist_lib.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
lib/CMakeFiles/typelist_lib.dir/build: lib/libtypelist_lib.a

.PHONY : lib/CMakeFiles/typelist_lib.dir/build

lib/CMakeFiles/typelist_lib.dir/clean:
	cd /Users/amaxacla/programs/typelist/lib && $(CMAKE_COMMAND) -P CMakeFiles/typelist_lib.dir/cmake_clean.cmake
.PHONY : lib/CMakeFiles/typelist_lib.dir/clean

lib/CMakeFiles/typelist_lib.dir/depend:
	cd /Users/amaxacla/programs/typelist && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /Users/amaxacla/programs/typelist /Users/amaxacla/programs/typelist/lib /Users/amaxacla/programs/typelist /Users/amaxacla/programs/typelist/lib /Users/amaxacla/programs/typelist/lib/CMakeFiles/typelist_lib.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : lib/CMakeFiles/typelist_lib.dir/depend

