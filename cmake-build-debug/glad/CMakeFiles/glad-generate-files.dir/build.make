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

# Utility rule file for glad-generate-files.

# Include the progress variables for this target.
include glad/CMakeFiles/glad-generate-files.dir/progress.make

glad/CMakeFiles/glad-generate-files: glad/src/glad.c
glad/CMakeFiles/glad-generate-files: glad/include/glad/glad.h


glad/src/glad.c:
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --blue --bold --progress-dir=/home/brett/CLionProjects/untitled/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Generating GLAD"
	cd /home/brett/CLionProjects/untitled/glad && /usr/bin/python3.9 -m glad --profile=compatibility --out-path=/home/brett/CLionProjects/untitled/cmake-build-debug/glad --api= --generator=c --extensions= --spec=gl

glad/include/glad/glad.h: glad/src/glad.c
	@$(CMAKE_COMMAND) -E touch_nocreate glad/include/glad/glad.h

glad-generate-files: glad/CMakeFiles/glad-generate-files
glad-generate-files: glad/src/glad.c
glad-generate-files: glad/include/glad/glad.h
glad-generate-files: glad/CMakeFiles/glad-generate-files.dir/build.make

.PHONY : glad-generate-files

# Rule to build all files generated by this target.
glad/CMakeFiles/glad-generate-files.dir/build: glad-generate-files

.PHONY : glad/CMakeFiles/glad-generate-files.dir/build

glad/CMakeFiles/glad-generate-files.dir/clean:
	cd /home/brett/CLionProjects/untitled/cmake-build-debug/glad && $(CMAKE_COMMAND) -P CMakeFiles/glad-generate-files.dir/cmake_clean.cmake
.PHONY : glad/CMakeFiles/glad-generate-files.dir/clean

glad/CMakeFiles/glad-generate-files.dir/depend:
	cd /home/brett/CLionProjects/untitled/cmake-build-debug && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/brett/CLionProjects/untitled /home/brett/CLionProjects/untitled/glad /home/brett/CLionProjects/untitled/cmake-build-debug /home/brett/CLionProjects/untitled/cmake-build-debug/glad /home/brett/CLionProjects/untitled/cmake-build-debug/glad/CMakeFiles/glad-generate-files.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : glad/CMakeFiles/glad-generate-files.dir/depend

