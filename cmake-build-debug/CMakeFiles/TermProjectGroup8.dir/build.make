# CMAKE generated file: DO NOT EDIT!
# Generated by "MinGW Makefiles" Generator, CMake Version 3.26

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

SHELL = cmd.exe

# The CMake executable.
CMAKE_COMMAND = "C:\Program Files\JetBrains\CLion 2023.2.1\bin\cmake\win\x64\bin\cmake.exe"

# The command to remove a file.
RM = "C:\Program Files\JetBrains\CLion 2023.2.1\bin\cmake\win\x64\bin\cmake.exe" -E rm -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = C:\Users\Kate\CLionProjects\COMP2510TermProject3

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = C:\Users\Kate\CLionProjects\COMP2510TermProject3\cmake-build-debug

# Include any dependencies generated for this target.
include CMakeFiles/TermProjectGroup8.dir/depend.make
# Include any dependencies generated by the compiler for this target.
include CMakeFiles/TermProjectGroup8.dir/compiler_depend.make

# Include the progress variables for this target.
include CMakeFiles/TermProjectGroup8.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/TermProjectGroup8.dir/flags.make

CMakeFiles/TermProjectGroup8.dir/main.c.obj: CMakeFiles/TermProjectGroup8.dir/flags.make
CMakeFiles/TermProjectGroup8.dir/main.c.obj: C:/Users/Kate/CLionProjects/COMP2510TermProject3/main.c
CMakeFiles/TermProjectGroup8.dir/main.c.obj: CMakeFiles/TermProjectGroup8.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=C:\Users\Kate\CLionProjects\COMP2510TermProject3\cmake-build-debug\CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building C object CMakeFiles/TermProjectGroup8.dir/main.c.obj"
	C:\PROGRA~1\JETBRA~1\CLION2~1.1\bin\mingw\bin\gcc.exe $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -MD -MT CMakeFiles/TermProjectGroup8.dir/main.c.obj -MF CMakeFiles\TermProjectGroup8.dir\main.c.obj.d -o CMakeFiles\TermProjectGroup8.dir\main.c.obj -c C:\Users\Kate\CLionProjects\COMP2510TermProject3\main.c

CMakeFiles/TermProjectGroup8.dir/main.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/TermProjectGroup8.dir/main.c.i"
	C:\PROGRA~1\JETBRA~1\CLION2~1.1\bin\mingw\bin\gcc.exe $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E C:\Users\Kate\CLionProjects\COMP2510TermProject3\main.c > CMakeFiles\TermProjectGroup8.dir\main.c.i

CMakeFiles/TermProjectGroup8.dir/main.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/TermProjectGroup8.dir/main.c.s"
	C:\PROGRA~1\JETBRA~1\CLION2~1.1\bin\mingw\bin\gcc.exe $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S C:\Users\Kate\CLionProjects\COMP2510TermProject3\main.c -o CMakeFiles\TermProjectGroup8.dir\main.c.s

CMakeFiles/TermProjectGroup8.dir/implementation.c.obj: CMakeFiles/TermProjectGroup8.dir/flags.make
CMakeFiles/TermProjectGroup8.dir/implementation.c.obj: C:/Users/Kate/CLionProjects/COMP2510TermProject3/implementation.c
CMakeFiles/TermProjectGroup8.dir/implementation.c.obj: CMakeFiles/TermProjectGroup8.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=C:\Users\Kate\CLionProjects\COMP2510TermProject3\cmake-build-debug\CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building C object CMakeFiles/TermProjectGroup8.dir/implementation.c.obj"
	C:\PROGRA~1\JETBRA~1\CLION2~1.1\bin\mingw\bin\gcc.exe $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -MD -MT CMakeFiles/TermProjectGroup8.dir/implementation.c.obj -MF CMakeFiles\TermProjectGroup8.dir\implementation.c.obj.d -o CMakeFiles\TermProjectGroup8.dir\implementation.c.obj -c C:\Users\Kate\CLionProjects\COMP2510TermProject3\implementation.c

CMakeFiles/TermProjectGroup8.dir/implementation.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/TermProjectGroup8.dir/implementation.c.i"
	C:\PROGRA~1\JETBRA~1\CLION2~1.1\bin\mingw\bin\gcc.exe $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E C:\Users\Kate\CLionProjects\COMP2510TermProject3\implementation.c > CMakeFiles\TermProjectGroup8.dir\implementation.c.i

CMakeFiles/TermProjectGroup8.dir/implementation.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/TermProjectGroup8.dir/implementation.c.s"
	C:\PROGRA~1\JETBRA~1\CLION2~1.1\bin\mingw\bin\gcc.exe $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S C:\Users\Kate\CLionProjects\COMP2510TermProject3\implementation.c -o CMakeFiles\TermProjectGroup8.dir\implementation.c.s

# Object files for target TermProjectGroup8
TermProjectGroup8_OBJECTS = \
"CMakeFiles/TermProjectGroup8.dir/main.c.obj" \
"CMakeFiles/TermProjectGroup8.dir/implementation.c.obj"

# External object files for target TermProjectGroup8
TermProjectGroup8_EXTERNAL_OBJECTS =

TermProjectGroup8.exe: CMakeFiles/TermProjectGroup8.dir/main.c.obj
TermProjectGroup8.exe: CMakeFiles/TermProjectGroup8.dir/implementation.c.obj
TermProjectGroup8.exe: CMakeFiles/TermProjectGroup8.dir/build.make
TermProjectGroup8.exe: CMakeFiles/TermProjectGroup8.dir/linkLibs.rsp
TermProjectGroup8.exe: CMakeFiles/TermProjectGroup8.dir/objects1.rsp
TermProjectGroup8.exe: CMakeFiles/TermProjectGroup8.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=C:\Users\Kate\CLionProjects\COMP2510TermProject3\cmake-build-debug\CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Linking C executable TermProjectGroup8.exe"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles\TermProjectGroup8.dir\link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/TermProjectGroup8.dir/build: TermProjectGroup8.exe
.PHONY : CMakeFiles/TermProjectGroup8.dir/build

CMakeFiles/TermProjectGroup8.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles\TermProjectGroup8.dir\cmake_clean.cmake
.PHONY : CMakeFiles/TermProjectGroup8.dir/clean

CMakeFiles/TermProjectGroup8.dir/depend:
	$(CMAKE_COMMAND) -E cmake_depends "MinGW Makefiles" C:\Users\Kate\CLionProjects\COMP2510TermProject3 C:\Users\Kate\CLionProjects\COMP2510TermProject3 C:\Users\Kate\CLionProjects\COMP2510TermProject3\cmake-build-debug C:\Users\Kate\CLionProjects\COMP2510TermProject3\cmake-build-debug C:\Users\Kate\CLionProjects\COMP2510TermProject3\cmake-build-debug\CMakeFiles\TermProjectGroup8.dir\DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/TermProjectGroup8.dir/depend

