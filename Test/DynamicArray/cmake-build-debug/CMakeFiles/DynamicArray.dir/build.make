# CMAKE generated file: DO NOT EDIT!
# Generated by "MinGW Makefiles" Generator, CMake Version 3.24

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
CMAKE_COMMAND = C:\Users\boboo\AppData\Local\JetBrains\Toolbox\apps\CLion\ch-0\223.8836.42\bin\cmake\win\x64\bin\cmake.exe

# The command to remove a file.
RM = C:\Users\boboo\AppData\Local\JetBrains\Toolbox\apps\CLion\ch-0\223.8836.42\bin\cmake\win\x64\bin\cmake.exe -E rm -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = D:\Programming\Data-Structures-and-Algorithms\Test\DynamicArray

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = D:\Programming\Data-Structures-and-Algorithms\Test\DynamicArray\cmake-build-debug

# Include any dependencies generated for this target.
include CMakeFiles/DynamicArray.dir/depend.make
# Include any dependencies generated by the compiler for this target.
include CMakeFiles/DynamicArray.dir/compiler_depend.make

# Include the progress variables for this target.
include CMakeFiles/DynamicArray.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/DynamicArray.dir/flags.make

CMakeFiles/DynamicArray.dir/main.cpp.obj: CMakeFiles/DynamicArray.dir/flags.make
CMakeFiles/DynamicArray.dir/main.cpp.obj: D:/Programming/Data-Structures-and-Algorithms/Test/DynamicArray/main.cpp
CMakeFiles/DynamicArray.dir/main.cpp.obj: CMakeFiles/DynamicArray.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=D:\Programming\Data-Structures-and-Algorithms\Test\DynamicArray\cmake-build-debug\CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/DynamicArray.dir/main.cpp.obj"
	C:\Users\boboo\AppData\Local\JetBrains\Toolbox\apps\CLion\ch-0\223.8836.42\bin\mingw\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/DynamicArray.dir/main.cpp.obj -MF CMakeFiles\DynamicArray.dir\main.cpp.obj.d -o CMakeFiles\DynamicArray.dir\main.cpp.obj -c D:\Programming\Data-Structures-and-Algorithms\Test\DynamicArray\main.cpp

CMakeFiles/DynamicArray.dir/main.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/DynamicArray.dir/main.cpp.i"
	C:\Users\boboo\AppData\Local\JetBrains\Toolbox\apps\CLion\ch-0\223.8836.42\bin\mingw\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E D:\Programming\Data-Structures-and-Algorithms\Test\DynamicArray\main.cpp > CMakeFiles\DynamicArray.dir\main.cpp.i

CMakeFiles/DynamicArray.dir/main.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/DynamicArray.dir/main.cpp.s"
	C:\Users\boboo\AppData\Local\JetBrains\Toolbox\apps\CLion\ch-0\223.8836.42\bin\mingw\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S D:\Programming\Data-Structures-and-Algorithms\Test\DynamicArray\main.cpp -o CMakeFiles\DynamicArray.dir\main.cpp.s

CMakeFiles/DynamicArray.dir/Example.cpp.obj: CMakeFiles/DynamicArray.dir/flags.make
CMakeFiles/DynamicArray.dir/Example.cpp.obj: D:/Programming/Data-Structures-and-Algorithms/Test/DynamicArray/Example.cpp
CMakeFiles/DynamicArray.dir/Example.cpp.obj: CMakeFiles/DynamicArray.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=D:\Programming\Data-Structures-and-Algorithms\Test\DynamicArray\cmake-build-debug\CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building CXX object CMakeFiles/DynamicArray.dir/Example.cpp.obj"
	C:\Users\boboo\AppData\Local\JetBrains\Toolbox\apps\CLion\ch-0\223.8836.42\bin\mingw\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/DynamicArray.dir/Example.cpp.obj -MF CMakeFiles\DynamicArray.dir\Example.cpp.obj.d -o CMakeFiles\DynamicArray.dir\Example.cpp.obj -c D:\Programming\Data-Structures-and-Algorithms\Test\DynamicArray\Example.cpp

CMakeFiles/DynamicArray.dir/Example.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/DynamicArray.dir/Example.cpp.i"
	C:\Users\boboo\AppData\Local\JetBrains\Toolbox\apps\CLion\ch-0\223.8836.42\bin\mingw\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E D:\Programming\Data-Structures-and-Algorithms\Test\DynamicArray\Example.cpp > CMakeFiles\DynamicArray.dir\Example.cpp.i

CMakeFiles/DynamicArray.dir/Example.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/DynamicArray.dir/Example.cpp.s"
	C:\Users\boboo\AppData\Local\JetBrains\Toolbox\apps\CLion\ch-0\223.8836.42\bin\mingw\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S D:\Programming\Data-Structures-and-Algorithms\Test\DynamicArray\Example.cpp -o CMakeFiles\DynamicArray.dir\Example.cpp.s

CMakeFiles/DynamicArray.dir/DynamicArray.cpp.obj: CMakeFiles/DynamicArray.dir/flags.make
CMakeFiles/DynamicArray.dir/DynamicArray.cpp.obj: D:/Programming/Data-Structures-and-Algorithms/Test/DynamicArray/DynamicArray.cpp
CMakeFiles/DynamicArray.dir/DynamicArray.cpp.obj: CMakeFiles/DynamicArray.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=D:\Programming\Data-Structures-and-Algorithms\Test\DynamicArray\cmake-build-debug\CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Building CXX object CMakeFiles/DynamicArray.dir/DynamicArray.cpp.obj"
	C:\Users\boboo\AppData\Local\JetBrains\Toolbox\apps\CLion\ch-0\223.8836.42\bin\mingw\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/DynamicArray.dir/DynamicArray.cpp.obj -MF CMakeFiles\DynamicArray.dir\DynamicArray.cpp.obj.d -o CMakeFiles\DynamicArray.dir\DynamicArray.cpp.obj -c D:\Programming\Data-Structures-and-Algorithms\Test\DynamicArray\DynamicArray.cpp

CMakeFiles/DynamicArray.dir/DynamicArray.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/DynamicArray.dir/DynamicArray.cpp.i"
	C:\Users\boboo\AppData\Local\JetBrains\Toolbox\apps\CLion\ch-0\223.8836.42\bin\mingw\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E D:\Programming\Data-Structures-and-Algorithms\Test\DynamicArray\DynamicArray.cpp > CMakeFiles\DynamicArray.dir\DynamicArray.cpp.i

CMakeFiles/DynamicArray.dir/DynamicArray.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/DynamicArray.dir/DynamicArray.cpp.s"
	C:\Users\boboo\AppData\Local\JetBrains\Toolbox\apps\CLion\ch-0\223.8836.42\bin\mingw\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S D:\Programming\Data-Structures-and-Algorithms\Test\DynamicArray\DynamicArray.cpp -o CMakeFiles\DynamicArray.dir\DynamicArray.cpp.s

# Object files for target DynamicArray
DynamicArray_OBJECTS = \
"CMakeFiles/DynamicArray.dir/main.cpp.obj" \
"CMakeFiles/DynamicArray.dir/Example.cpp.obj" \
"CMakeFiles/DynamicArray.dir/DynamicArray.cpp.obj"

# External object files for target DynamicArray
DynamicArray_EXTERNAL_OBJECTS =

DynamicArray.exe: CMakeFiles/DynamicArray.dir/main.cpp.obj
DynamicArray.exe: CMakeFiles/DynamicArray.dir/Example.cpp.obj
DynamicArray.exe: CMakeFiles/DynamicArray.dir/DynamicArray.cpp.obj
DynamicArray.exe: CMakeFiles/DynamicArray.dir/build.make
DynamicArray.exe: CMakeFiles/DynamicArray.dir/linklibs.rsp
DynamicArray.exe: CMakeFiles/DynamicArray.dir/objects1.rsp
DynamicArray.exe: CMakeFiles/DynamicArray.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=D:\Programming\Data-Structures-and-Algorithms\Test\DynamicArray\cmake-build-debug\CMakeFiles --progress-num=$(CMAKE_PROGRESS_4) "Linking CXX executable DynamicArray.exe"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles\DynamicArray.dir\link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/DynamicArray.dir/build: DynamicArray.exe
.PHONY : CMakeFiles/DynamicArray.dir/build

CMakeFiles/DynamicArray.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles\DynamicArray.dir\cmake_clean.cmake
.PHONY : CMakeFiles/DynamicArray.dir/clean

CMakeFiles/DynamicArray.dir/depend:
	$(CMAKE_COMMAND) -E cmake_depends "MinGW Makefiles" D:\Programming\Data-Structures-and-Algorithms\Test\DynamicArray D:\Programming\Data-Structures-and-Algorithms\Test\DynamicArray D:\Programming\Data-Structures-and-Algorithms\Test\DynamicArray\cmake-build-debug D:\Programming\Data-Structures-and-Algorithms\Test\DynamicArray\cmake-build-debug D:\Programming\Data-Structures-and-Algorithms\Test\DynamicArray\cmake-build-debug\CMakeFiles\DynamicArray.dir\DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/DynamicArray.dir/depend

