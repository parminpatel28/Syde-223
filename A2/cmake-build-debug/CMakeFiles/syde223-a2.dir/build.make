# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.19

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
CMAKE_COMMAND = /Applications/CLion.app/Contents/bin/cmake/mac/bin/cmake

# The command to remove a file.
RM = /Applications/CLion.app/Contents/bin/cmake/mac/bin/cmake -E rm -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /Users/parmin/CLionProjects/ps26pate/A2

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /Users/parmin/CLionProjects/ps26pate/A2/cmake-build-debug

# Include any dependencies generated for this target.
include CMakeFiles/syde223-a2.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/syde223-a2.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/syde223-a2.dir/flags.make

CMakeFiles/syde223-a2.dir/dynamic-stack.cpp.o: CMakeFiles/syde223-a2.dir/flags.make
CMakeFiles/syde223-a2.dir/dynamic-stack.cpp.o: ../dynamic-stack.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/parmin/CLionProjects/ps26pate/A2/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/syde223-a2.dir/dynamic-stack.cpp.o"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/syde223-a2.dir/dynamic-stack.cpp.o -c /Users/parmin/CLionProjects/ps26pate/A2/dynamic-stack.cpp

CMakeFiles/syde223-a2.dir/dynamic-stack.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/syde223-a2.dir/dynamic-stack.cpp.i"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /Users/parmin/CLionProjects/ps26pate/A2/dynamic-stack.cpp > CMakeFiles/syde223-a2.dir/dynamic-stack.cpp.i

CMakeFiles/syde223-a2.dir/dynamic-stack.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/syde223-a2.dir/dynamic-stack.cpp.s"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /Users/parmin/CLionProjects/ps26pate/A2/dynamic-stack.cpp -o CMakeFiles/syde223-a2.dir/dynamic-stack.cpp.s

CMakeFiles/syde223-a2.dir/circular-queue.cpp.o: CMakeFiles/syde223-a2.dir/flags.make
CMakeFiles/syde223-a2.dir/circular-queue.cpp.o: ../circular-queue.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/parmin/CLionProjects/ps26pate/A2/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building CXX object CMakeFiles/syde223-a2.dir/circular-queue.cpp.o"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/syde223-a2.dir/circular-queue.cpp.o -c /Users/parmin/CLionProjects/ps26pate/A2/circular-queue.cpp

CMakeFiles/syde223-a2.dir/circular-queue.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/syde223-a2.dir/circular-queue.cpp.i"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /Users/parmin/CLionProjects/ps26pate/A2/circular-queue.cpp > CMakeFiles/syde223-a2.dir/circular-queue.cpp.i

CMakeFiles/syde223-a2.dir/circular-queue.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/syde223-a2.dir/circular-queue.cpp.s"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /Users/parmin/CLionProjects/ps26pate/A2/circular-queue.cpp -o CMakeFiles/syde223-a2.dir/circular-queue.cpp.s

CMakeFiles/syde223-a2.dir/test.cpp.o: CMakeFiles/syde223-a2.dir/flags.make
CMakeFiles/syde223-a2.dir/test.cpp.o: ../test.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/parmin/CLionProjects/ps26pate/A2/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Building CXX object CMakeFiles/syde223-a2.dir/test.cpp.o"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/syde223-a2.dir/test.cpp.o -c /Users/parmin/CLionProjects/ps26pate/A2/test.cpp

CMakeFiles/syde223-a2.dir/test.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/syde223-a2.dir/test.cpp.i"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /Users/parmin/CLionProjects/ps26pate/A2/test.cpp > CMakeFiles/syde223-a2.dir/test.cpp.i

CMakeFiles/syde223-a2.dir/test.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/syde223-a2.dir/test.cpp.s"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /Users/parmin/CLionProjects/ps26pate/A2/test.cpp -o CMakeFiles/syde223-a2.dir/test.cpp.s

# Object files for target syde223-a2
syde223__a2_OBJECTS = \
"CMakeFiles/syde223-a2.dir/dynamic-stack.cpp.o" \
"CMakeFiles/syde223-a2.dir/circular-queue.cpp.o" \
"CMakeFiles/syde223-a2.dir/test.cpp.o"

# External object files for target syde223-a2
syde223__a2_EXTERNAL_OBJECTS =

syde223-a2: CMakeFiles/syde223-a2.dir/dynamic-stack.cpp.o
syde223-a2: CMakeFiles/syde223-a2.dir/circular-queue.cpp.o
syde223-a2: CMakeFiles/syde223-a2.dir/test.cpp.o
syde223-a2: CMakeFiles/syde223-a2.dir/build.make
syde223-a2: CMakeFiles/syde223-a2.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/Users/parmin/CLionProjects/ps26pate/A2/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_4) "Linking CXX executable syde223-a2"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/syde223-a2.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/syde223-a2.dir/build: syde223-a2

.PHONY : CMakeFiles/syde223-a2.dir/build

CMakeFiles/syde223-a2.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/syde223-a2.dir/cmake_clean.cmake
.PHONY : CMakeFiles/syde223-a2.dir/clean

CMakeFiles/syde223-a2.dir/depend:
	cd /Users/parmin/CLionProjects/ps26pate/A2/cmake-build-debug && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /Users/parmin/CLionProjects/ps26pate/A2 /Users/parmin/CLionProjects/ps26pate/A2 /Users/parmin/CLionProjects/ps26pate/A2/cmake-build-debug /Users/parmin/CLionProjects/ps26pate/A2/cmake-build-debug /Users/parmin/CLionProjects/ps26pate/A2/cmake-build-debug/CMakeFiles/syde223-a2.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/syde223-a2.dir/depend
