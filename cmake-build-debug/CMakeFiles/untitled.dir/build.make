# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.17

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
CMAKE_COMMAND = /opt/jetbrains/clion/bin/cmake/linux/bin/cmake

# The command to remove a file.
RM = /opt/jetbrains/clion/bin/cmake/linux/bin/cmake -E rm -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /home/brett/CLionProjects/untitled

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/brett/CLionProjects/untitled/cmake-build-debug

# Include any dependencies generated for this target.
include CMakeFiles/untitled.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/untitled.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/untitled.dir/flags.make

CMakeFiles/untitled.dir/src/main.cpp.o: CMakeFiles/untitled.dir/flags.make
CMakeFiles/untitled.dir/src/main.cpp.o: ../src/main.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/brett/CLionProjects/untitled/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/untitled.dir/src/main.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/untitled.dir/src/main.cpp.o -c /home/brett/CLionProjects/untitled/src/main.cpp

CMakeFiles/untitled.dir/src/main.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/untitled.dir/src/main.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/brett/CLionProjects/untitled/src/main.cpp > CMakeFiles/untitled.dir/src/main.cpp.i

CMakeFiles/untitled.dir/src/main.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/untitled.dir/src/main.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/brett/CLionProjects/untitled/src/main.cpp -o CMakeFiles/untitled.dir/src/main.cpp.s

CMakeFiles/untitled.dir/src/shaders/shader.cpp.o: CMakeFiles/untitled.dir/flags.make
CMakeFiles/untitled.dir/src/shaders/shader.cpp.o: ../src/shaders/shader.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/brett/CLionProjects/untitled/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building CXX object CMakeFiles/untitled.dir/src/shaders/shader.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/untitled.dir/src/shaders/shader.cpp.o -c /home/brett/CLionProjects/untitled/src/shaders/shader.cpp

CMakeFiles/untitled.dir/src/shaders/shader.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/untitled.dir/src/shaders/shader.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/brett/CLionProjects/untitled/src/shaders/shader.cpp > CMakeFiles/untitled.dir/src/shaders/shader.cpp.i

CMakeFiles/untitled.dir/src/shaders/shader.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/untitled.dir/src/shaders/shader.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/brett/CLionProjects/untitled/src/shaders/shader.cpp -o CMakeFiles/untitled.dir/src/shaders/shader.cpp.s

CMakeFiles/untitled.dir/src/utils/time.cpp.o: CMakeFiles/untitled.dir/flags.make
CMakeFiles/untitled.dir/src/utils/time.cpp.o: ../src/utils/time.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/brett/CLionProjects/untitled/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Building CXX object CMakeFiles/untitled.dir/src/utils/time.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/untitled.dir/src/utils/time.cpp.o -c /home/brett/CLionProjects/untitled/src/utils/time.cpp

CMakeFiles/untitled.dir/src/utils/time.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/untitled.dir/src/utils/time.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/brett/CLionProjects/untitled/src/utils/time.cpp > CMakeFiles/untitled.dir/src/utils/time.cpp.i

CMakeFiles/untitled.dir/src/utils/time.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/untitled.dir/src/utils/time.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/brett/CLionProjects/untitled/src/utils/time.cpp -o CMakeFiles/untitled.dir/src/utils/time.cpp.s

# Object files for target untitled
untitled_OBJECTS = \
"CMakeFiles/untitled.dir/src/main.cpp.o" \
"CMakeFiles/untitled.dir/src/shaders/shader.cpp.o" \
"CMakeFiles/untitled.dir/src/utils/time.cpp.o"

# External object files for target untitled
untitled_EXTERNAL_OBJECTS =

untitled: CMakeFiles/untitled.dir/src/main.cpp.o
untitled: CMakeFiles/untitled.dir/src/shaders/shader.cpp.o
untitled: CMakeFiles/untitled.dir/src/utils/time.cpp.o
untitled: CMakeFiles/untitled.dir/build.make
untitled: /usr/local/lib/libglfw3.a
untitled: glad/libglad.a
untitled: /usr/lib/x86_64-linux-gnu/librt.so
untitled: /usr/lib/x86_64-linux-gnu/libm.so
untitled: /usr/lib/x86_64-linux-gnu/libX11.so
untitled: /usr/lib/x86_64-linux-gnu/libGLX.so
untitled: /usr/lib/x86_64-linux-gnu/libOpenGL.so
untitled: CMakeFiles/untitled.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/brett/CLionProjects/untitled/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_4) "Linking CXX executable untitled"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/untitled.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/untitled.dir/build: untitled

.PHONY : CMakeFiles/untitled.dir/build

CMakeFiles/untitled.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/untitled.dir/cmake_clean.cmake
.PHONY : CMakeFiles/untitled.dir/clean

CMakeFiles/untitled.dir/depend:
	cd /home/brett/CLionProjects/untitled/cmake-build-debug && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/brett/CLionProjects/untitled /home/brett/CLionProjects/untitled /home/brett/CLionProjects/untitled/cmake-build-debug /home/brett/CLionProjects/untitled/cmake-build-debug /home/brett/CLionProjects/untitled/cmake-build-debug/CMakeFiles/untitled.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/untitled.dir/depend

