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
CMAKE_COMMAND = /Applications/CLion.app/Contents/bin/cmake/mac/bin/cmake

# The command to remove a file.
RM = /Applications/CLion.app/Contents/bin/cmake/mac/bin/cmake -E remove -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /Users/frederickwang/Desktop/CS/GitHub/s20-pa03-sorting-FreddyWang-12

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /Users/frederickwang/Desktop/CS/GitHub/s20-pa03-sorting-FreddyWang-12/cmake-build-debug

# Include any dependencies generated for this target.
include CMakeFiles/Sorting.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/Sorting.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/Sorting.dir/flags.make

CMakeFiles/Sorting.dir/main.cpp.o: CMakeFiles/Sorting.dir/flags.make
CMakeFiles/Sorting.dir/main.cpp.o: ../main.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/frederickwang/Desktop/CS/GitHub/s20-pa03-sorting-FreddyWang-12/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/Sorting.dir/main.cpp.o"
	/Library/Developer/CommandLineTools/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/Sorting.dir/main.cpp.o -c /Users/frederickwang/Desktop/CS/GitHub/s20-pa03-sorting-FreddyWang-12/main.cpp

CMakeFiles/Sorting.dir/main.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/Sorting.dir/main.cpp.i"
	/Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /Users/frederickwang/Desktop/CS/GitHub/s20-pa03-sorting-FreddyWang-12/main.cpp > CMakeFiles/Sorting.dir/main.cpp.i

CMakeFiles/Sorting.dir/main.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/Sorting.dir/main.cpp.s"
	/Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /Users/frederickwang/Desktop/CS/GitHub/s20-pa03-sorting-FreddyWang-12/main.cpp -o CMakeFiles/Sorting.dir/main.cpp.s

# Object files for target Sorting
Sorting_OBJECTS = \
"CMakeFiles/Sorting.dir/main.cpp.o"

# External object files for target Sorting
Sorting_EXTERNAL_OBJECTS =

Sorting: CMakeFiles/Sorting.dir/main.cpp.o
Sorting: CMakeFiles/Sorting.dir/build.make
Sorting: CMakeFiles/Sorting.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/Users/frederickwang/Desktop/CS/GitHub/s20-pa03-sorting-FreddyWang-12/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable Sorting"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/Sorting.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/Sorting.dir/build: Sorting

.PHONY : CMakeFiles/Sorting.dir/build

CMakeFiles/Sorting.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/Sorting.dir/cmake_clean.cmake
.PHONY : CMakeFiles/Sorting.dir/clean

CMakeFiles/Sorting.dir/depend:
	cd /Users/frederickwang/Desktop/CS/GitHub/s20-pa03-sorting-FreddyWang-12/cmake-build-debug && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /Users/frederickwang/Desktop/CS/GitHub/s20-pa03-sorting-FreddyWang-12 /Users/frederickwang/Desktop/CS/GitHub/s20-pa03-sorting-FreddyWang-12 /Users/frederickwang/Desktop/CS/GitHub/s20-pa03-sorting-FreddyWang-12/cmake-build-debug /Users/frederickwang/Desktop/CS/GitHub/s20-pa03-sorting-FreddyWang-12/cmake-build-debug /Users/frederickwang/Desktop/CS/GitHub/s20-pa03-sorting-FreddyWang-12/cmake-build-debug/CMakeFiles/Sorting.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/Sorting.dir/depend

