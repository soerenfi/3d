# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.21

# Delete rule output on recipe failure.
.DELETE_ON_ERROR:

#=============================================================================
# Special targets provided by cmake.

# Disable implicit rules so canonical targets will work.
.SUFFIXES:

# Disable VCS-based implicit rules.
% : %,v

# Disable VCS-based implicit rules.
% : RCS/%

# Disable VCS-based implicit rules.
% : RCS/%,v

# Disable VCS-based implicit rules.
% : SCCS/s.%

# Disable VCS-based implicit rules.
% : s.%

.SUFFIXES: .hpux_make_needs_suffix_list

# Command-line flag to silence nested $(MAKE).
$(VERBOSE)MAKESILENT = -s

#Suppress display of executed commands.
$(VERBOSE).SILENT:

# A target that is always out of date.
cmake_force:
.PHONY : cmake_force

#=============================================================================
# Set environment variables for the build.

# The shell in which to execute make rules.
SHELL = /bin/sh

# The CMake executable.
CMAKE_COMMAND = /usr/local/Cellar/cmake/3.21.3_1/bin/cmake

# The command to remove a file.
RM = /usr/local/Cellar/cmake/3.21.3_1/bin/cmake -E rm -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /Users/Jana/workspace/opengl_start

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /Users/Jana/workspace/opengl_start/build

# Include any dependencies generated for this target.
include CMakeFiles/opengl-start.dir/depend.make
# Include any dependencies generated by the compiler for this target.
include CMakeFiles/opengl-start.dir/compiler_depend.make

# Include the progress variables for this target.
include CMakeFiles/opengl-start.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/opengl-start.dir/flags.make

CMakeFiles/opengl-start.dir/src/main.cc.o: CMakeFiles/opengl-start.dir/flags.make
CMakeFiles/opengl-start.dir/src/main.cc.o: ../src/main.cc
CMakeFiles/opengl-start.dir/src/main.cc.o: CMakeFiles/opengl-start.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/Jana/workspace/opengl_start/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/opengl-start.dir/src/main.cc.o"
	/Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/opengl-start.dir/src/main.cc.o -MF CMakeFiles/opengl-start.dir/src/main.cc.o.d -o CMakeFiles/opengl-start.dir/src/main.cc.o -c /Users/Jana/workspace/opengl_start/src/main.cc

CMakeFiles/opengl-start.dir/src/main.cc.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/opengl-start.dir/src/main.cc.i"
	/Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /Users/Jana/workspace/opengl_start/src/main.cc > CMakeFiles/opengl-start.dir/src/main.cc.i

CMakeFiles/opengl-start.dir/src/main.cc.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/opengl-start.dir/src/main.cc.s"
	/Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /Users/Jana/workspace/opengl_start/src/main.cc -o CMakeFiles/opengl-start.dir/src/main.cc.s

# Object files for target opengl-start
opengl__start_OBJECTS = \
"CMakeFiles/opengl-start.dir/src/main.cc.o"

# External object files for target opengl-start
opengl__start_EXTERNAL_OBJECTS =

opengl-start: CMakeFiles/opengl-start.dir/src/main.cc.o
opengl-start: CMakeFiles/opengl-start.dir/build.make
opengl-start: ../thirdparty/GLFW/lib-x86_64/libglfw3.a
opengl-start: CMakeFiles/opengl-start.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/Users/Jana/workspace/opengl_start/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable opengl-start"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/opengl-start.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/opengl-start.dir/build: opengl-start
.PHONY : CMakeFiles/opengl-start.dir/build

CMakeFiles/opengl-start.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/opengl-start.dir/cmake_clean.cmake
.PHONY : CMakeFiles/opengl-start.dir/clean

CMakeFiles/opengl-start.dir/depend:
	cd /Users/Jana/workspace/opengl_start/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /Users/Jana/workspace/opengl_start /Users/Jana/workspace/opengl_start /Users/Jana/workspace/opengl_start/build /Users/Jana/workspace/opengl_start/build /Users/Jana/workspace/opengl_start/build/CMakeFiles/opengl-start.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/opengl-start.dir/depend

