# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.25

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
CMAKE_COMMAND = /snap/clion/235/bin/cmake/linux/x64/bin/cmake

# The command to remove a file.
RM = /snap/clion/235/bin/cmake/linux/x64/bin/cmake -E rm -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /home/jurguen/Documentos/GitHub/quiz-SO

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/jurguen/Documentos/GitHub/quiz-SO/cmake-build-debug

# Include any dependencies generated for this target.
include CMakeFiles/quiz_SO.dir/depend.make
# Include any dependencies generated by the compiler for this target.
include CMakeFiles/quiz_SO.dir/compiler_depend.make

# Include the progress variables for this target.
include CMakeFiles/quiz_SO.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/quiz_SO.dir/flags.make

CMakeFiles/quiz_SO.dir/main.c.o: CMakeFiles/quiz_SO.dir/flags.make
CMakeFiles/quiz_SO.dir/main.c.o: /home/jurguen/Documentos/GitHub/quiz-SO/main.c
CMakeFiles/quiz_SO.dir/main.c.o: CMakeFiles/quiz_SO.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/jurguen/Documentos/GitHub/quiz-SO/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building C object CMakeFiles/quiz_SO.dir/main.c.o"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -MD -MT CMakeFiles/quiz_SO.dir/main.c.o -MF CMakeFiles/quiz_SO.dir/main.c.o.d -o CMakeFiles/quiz_SO.dir/main.c.o -c /home/jurguen/Documentos/GitHub/quiz-SO/main.c

CMakeFiles/quiz_SO.dir/main.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/quiz_SO.dir/main.c.i"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /home/jurguen/Documentos/GitHub/quiz-SO/main.c > CMakeFiles/quiz_SO.dir/main.c.i

CMakeFiles/quiz_SO.dir/main.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/quiz_SO.dir/main.c.s"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /home/jurguen/Documentos/GitHub/quiz-SO/main.c -o CMakeFiles/quiz_SO.dir/main.c.s

# Object files for target quiz_SO
quiz_SO_OBJECTS = \
"CMakeFiles/quiz_SO.dir/main.c.o"

# External object files for target quiz_SO
quiz_SO_EXTERNAL_OBJECTS =

quiz_SO: CMakeFiles/quiz_SO.dir/main.c.o
quiz_SO: CMakeFiles/quiz_SO.dir/build.make
quiz_SO: CMakeFiles/quiz_SO.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/jurguen/Documentos/GitHub/quiz-SO/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking C executable quiz_SO"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/quiz_SO.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/quiz_SO.dir/build: quiz_SO
.PHONY : CMakeFiles/quiz_SO.dir/build

CMakeFiles/quiz_SO.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/quiz_SO.dir/cmake_clean.cmake
.PHONY : CMakeFiles/quiz_SO.dir/clean

CMakeFiles/quiz_SO.dir/depend:
	cd /home/jurguen/Documentos/GitHub/quiz-SO/cmake-build-debug && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/jurguen/Documentos/GitHub/quiz-SO /home/jurguen/Documentos/GitHub/quiz-SO /home/jurguen/Documentos/GitHub/quiz-SO/cmake-build-debug /home/jurguen/Documentos/GitHub/quiz-SO/cmake-build-debug /home/jurguen/Documentos/GitHub/quiz-SO/cmake-build-debug/CMakeFiles/quiz_SO.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/quiz_SO.dir/depend
