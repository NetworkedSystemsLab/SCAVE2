# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.9

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
CMAKE_SOURCE_DIR = /home/christian/workspace/SCAVE2/dev/src/cpp

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/christian/workspace/SCAVE2/dev/src/cpp/.build

# Include any dependencies generated for this target.
include packages/tachometer/CMakeFiles/tachometer.out.dir/depend.make

# Include the progress variables for this target.
include packages/tachometer/CMakeFiles/tachometer.out.dir/progress.make

# Include the compile flags for this target's objects.
include packages/tachometer/CMakeFiles/tachometer.out.dir/flags.make

packages/tachometer/CMakeFiles/tachometer.out.dir/__/jetsonTX2/jetsonTX2.cpp.o: packages/tachometer/CMakeFiles/tachometer.out.dir/flags.make
packages/tachometer/CMakeFiles/tachometer.out.dir/__/jetsonTX2/jetsonTX2.cpp.o: ../packages/jetsonTX2/jetsonTX2.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/christian/workspace/SCAVE2/dev/src/cpp/.build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object packages/tachometer/CMakeFiles/tachometer.out.dir/__/jetsonTX2/jetsonTX2.cpp.o"
	cd /home/christian/workspace/SCAVE2/dev/src/cpp/.build/packages/tachometer && /usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/tachometer.out.dir/__/jetsonTX2/jetsonTX2.cpp.o -c /home/christian/workspace/SCAVE2/dev/src/cpp/packages/jetsonTX2/jetsonTX2.cpp

packages/tachometer/CMakeFiles/tachometer.out.dir/__/jetsonTX2/jetsonTX2.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/tachometer.out.dir/__/jetsonTX2/jetsonTX2.cpp.i"
	cd /home/christian/workspace/SCAVE2/dev/src/cpp/.build/packages/tachometer && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/christian/workspace/SCAVE2/dev/src/cpp/packages/jetsonTX2/jetsonTX2.cpp > CMakeFiles/tachometer.out.dir/__/jetsonTX2/jetsonTX2.cpp.i

packages/tachometer/CMakeFiles/tachometer.out.dir/__/jetsonTX2/jetsonTX2.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/tachometer.out.dir/__/jetsonTX2/jetsonTX2.cpp.s"
	cd /home/christian/workspace/SCAVE2/dev/src/cpp/.build/packages/tachometer && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/christian/workspace/SCAVE2/dev/src/cpp/packages/jetsonTX2/jetsonTX2.cpp -o CMakeFiles/tachometer.out.dir/__/jetsonTX2/jetsonTX2.cpp.s

packages/tachometer/CMakeFiles/tachometer.out.dir/__/jetsonTX2/jetsonTX2.cpp.o.requires:

.PHONY : packages/tachometer/CMakeFiles/tachometer.out.dir/__/jetsonTX2/jetsonTX2.cpp.o.requires

packages/tachometer/CMakeFiles/tachometer.out.dir/__/jetsonTX2/jetsonTX2.cpp.o.provides: packages/tachometer/CMakeFiles/tachometer.out.dir/__/jetsonTX2/jetsonTX2.cpp.o.requires
	$(MAKE) -f packages/tachometer/CMakeFiles/tachometer.out.dir/build.make packages/tachometer/CMakeFiles/tachometer.out.dir/__/jetsonTX2/jetsonTX2.cpp.o.provides.build
.PHONY : packages/tachometer/CMakeFiles/tachometer.out.dir/__/jetsonTX2/jetsonTX2.cpp.o.provides

packages/tachometer/CMakeFiles/tachometer.out.dir/__/jetsonTX2/jetsonTX2.cpp.o.provides.build: packages/tachometer/CMakeFiles/tachometer.out.dir/__/jetsonTX2/jetsonTX2.cpp.o


packages/tachometer/CMakeFiles/tachometer.out.dir/__/timer/timer.cpp.o: packages/tachometer/CMakeFiles/tachometer.out.dir/flags.make
packages/tachometer/CMakeFiles/tachometer.out.dir/__/timer/timer.cpp.o: ../packages/timer/timer.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/christian/workspace/SCAVE2/dev/src/cpp/.build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building CXX object packages/tachometer/CMakeFiles/tachometer.out.dir/__/timer/timer.cpp.o"
	cd /home/christian/workspace/SCAVE2/dev/src/cpp/.build/packages/tachometer && /usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/tachometer.out.dir/__/timer/timer.cpp.o -c /home/christian/workspace/SCAVE2/dev/src/cpp/packages/timer/timer.cpp

packages/tachometer/CMakeFiles/tachometer.out.dir/__/timer/timer.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/tachometer.out.dir/__/timer/timer.cpp.i"
	cd /home/christian/workspace/SCAVE2/dev/src/cpp/.build/packages/tachometer && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/christian/workspace/SCAVE2/dev/src/cpp/packages/timer/timer.cpp > CMakeFiles/tachometer.out.dir/__/timer/timer.cpp.i

packages/tachometer/CMakeFiles/tachometer.out.dir/__/timer/timer.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/tachometer.out.dir/__/timer/timer.cpp.s"
	cd /home/christian/workspace/SCAVE2/dev/src/cpp/.build/packages/tachometer && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/christian/workspace/SCAVE2/dev/src/cpp/packages/timer/timer.cpp -o CMakeFiles/tachometer.out.dir/__/timer/timer.cpp.s

packages/tachometer/CMakeFiles/tachometer.out.dir/__/timer/timer.cpp.o.requires:

.PHONY : packages/tachometer/CMakeFiles/tachometer.out.dir/__/timer/timer.cpp.o.requires

packages/tachometer/CMakeFiles/tachometer.out.dir/__/timer/timer.cpp.o.provides: packages/tachometer/CMakeFiles/tachometer.out.dir/__/timer/timer.cpp.o.requires
	$(MAKE) -f packages/tachometer/CMakeFiles/tachometer.out.dir/build.make packages/tachometer/CMakeFiles/tachometer.out.dir/__/timer/timer.cpp.o.provides.build
.PHONY : packages/tachometer/CMakeFiles/tachometer.out.dir/__/timer/timer.cpp.o.provides

packages/tachometer/CMakeFiles/tachometer.out.dir/__/timer/timer.cpp.o.provides.build: packages/tachometer/CMakeFiles/tachometer.out.dir/__/timer/timer.cpp.o


packages/tachometer/CMakeFiles/tachometer.out.dir/tachometer.cpp.o: packages/tachometer/CMakeFiles/tachometer.out.dir/flags.make
packages/tachometer/CMakeFiles/tachometer.out.dir/tachometer.cpp.o: ../packages/tachometer/tachometer.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/christian/workspace/SCAVE2/dev/src/cpp/.build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Building CXX object packages/tachometer/CMakeFiles/tachometer.out.dir/tachometer.cpp.o"
	cd /home/christian/workspace/SCAVE2/dev/src/cpp/.build/packages/tachometer && /usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/tachometer.out.dir/tachometer.cpp.o -c /home/christian/workspace/SCAVE2/dev/src/cpp/packages/tachometer/tachometer.cpp

packages/tachometer/CMakeFiles/tachometer.out.dir/tachometer.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/tachometer.out.dir/tachometer.cpp.i"
	cd /home/christian/workspace/SCAVE2/dev/src/cpp/.build/packages/tachometer && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/christian/workspace/SCAVE2/dev/src/cpp/packages/tachometer/tachometer.cpp > CMakeFiles/tachometer.out.dir/tachometer.cpp.i

packages/tachometer/CMakeFiles/tachometer.out.dir/tachometer.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/tachometer.out.dir/tachometer.cpp.s"
	cd /home/christian/workspace/SCAVE2/dev/src/cpp/.build/packages/tachometer && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/christian/workspace/SCAVE2/dev/src/cpp/packages/tachometer/tachometer.cpp -o CMakeFiles/tachometer.out.dir/tachometer.cpp.s

packages/tachometer/CMakeFiles/tachometer.out.dir/tachometer.cpp.o.requires:

.PHONY : packages/tachometer/CMakeFiles/tachometer.out.dir/tachometer.cpp.o.requires

packages/tachometer/CMakeFiles/tachometer.out.dir/tachometer.cpp.o.provides: packages/tachometer/CMakeFiles/tachometer.out.dir/tachometer.cpp.o.requires
	$(MAKE) -f packages/tachometer/CMakeFiles/tachometer.out.dir/build.make packages/tachometer/CMakeFiles/tachometer.out.dir/tachometer.cpp.o.provides.build
.PHONY : packages/tachometer/CMakeFiles/tachometer.out.dir/tachometer.cpp.o.provides

packages/tachometer/CMakeFiles/tachometer.out.dir/tachometer.cpp.o.provides.build: packages/tachometer/CMakeFiles/tachometer.out.dir/tachometer.cpp.o


packages/tachometer/CMakeFiles/tachometer.out.dir/main.cpp.o: packages/tachometer/CMakeFiles/tachometer.out.dir/flags.make
packages/tachometer/CMakeFiles/tachometer.out.dir/main.cpp.o: ../packages/tachometer/main.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/christian/workspace/SCAVE2/dev/src/cpp/.build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_4) "Building CXX object packages/tachometer/CMakeFiles/tachometer.out.dir/main.cpp.o"
	cd /home/christian/workspace/SCAVE2/dev/src/cpp/.build/packages/tachometer && /usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/tachometer.out.dir/main.cpp.o -c /home/christian/workspace/SCAVE2/dev/src/cpp/packages/tachometer/main.cpp

packages/tachometer/CMakeFiles/tachometer.out.dir/main.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/tachometer.out.dir/main.cpp.i"
	cd /home/christian/workspace/SCAVE2/dev/src/cpp/.build/packages/tachometer && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/christian/workspace/SCAVE2/dev/src/cpp/packages/tachometer/main.cpp > CMakeFiles/tachometer.out.dir/main.cpp.i

packages/tachometer/CMakeFiles/tachometer.out.dir/main.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/tachometer.out.dir/main.cpp.s"
	cd /home/christian/workspace/SCAVE2/dev/src/cpp/.build/packages/tachometer && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/christian/workspace/SCAVE2/dev/src/cpp/packages/tachometer/main.cpp -o CMakeFiles/tachometer.out.dir/main.cpp.s

packages/tachometer/CMakeFiles/tachometer.out.dir/main.cpp.o.requires:

.PHONY : packages/tachometer/CMakeFiles/tachometer.out.dir/main.cpp.o.requires

packages/tachometer/CMakeFiles/tachometer.out.dir/main.cpp.o.provides: packages/tachometer/CMakeFiles/tachometer.out.dir/main.cpp.o.requires
	$(MAKE) -f packages/tachometer/CMakeFiles/tachometer.out.dir/build.make packages/tachometer/CMakeFiles/tachometer.out.dir/main.cpp.o.provides.build
.PHONY : packages/tachometer/CMakeFiles/tachometer.out.dir/main.cpp.o.provides

packages/tachometer/CMakeFiles/tachometer.out.dir/main.cpp.o.provides.build: packages/tachometer/CMakeFiles/tachometer.out.dir/main.cpp.o


# Object files for target tachometer.out
tachometer_out_OBJECTS = \
"CMakeFiles/tachometer.out.dir/__/jetsonTX2/jetsonTX2.cpp.o" \
"CMakeFiles/tachometer.out.dir/__/timer/timer.cpp.o" \
"CMakeFiles/tachometer.out.dir/tachometer.cpp.o" \
"CMakeFiles/tachometer.out.dir/main.cpp.o"

# External object files for target tachometer.out
tachometer_out_EXTERNAL_OBJECTS =

packages/tachometer/tachometer.out: packages/tachometer/CMakeFiles/tachometer.out.dir/__/jetsonTX2/jetsonTX2.cpp.o
packages/tachometer/tachometer.out: packages/tachometer/CMakeFiles/tachometer.out.dir/__/timer/timer.cpp.o
packages/tachometer/tachometer.out: packages/tachometer/CMakeFiles/tachometer.out.dir/tachometer.cpp.o
packages/tachometer/tachometer.out: packages/tachometer/CMakeFiles/tachometer.out.dir/main.cpp.o
packages/tachometer/tachometer.out: packages/tachometer/CMakeFiles/tachometer.out.dir/build.make
packages/tachometer/tachometer.out: packages/tachometer/CMakeFiles/tachometer.out.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/christian/workspace/SCAVE2/dev/src/cpp/.build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_5) "Linking CXX executable tachometer.out"
	cd /home/christian/workspace/SCAVE2/dev/src/cpp/.build/packages/tachometer && $(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/tachometer.out.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
packages/tachometer/CMakeFiles/tachometer.out.dir/build: packages/tachometer/tachometer.out

.PHONY : packages/tachometer/CMakeFiles/tachometer.out.dir/build

packages/tachometer/CMakeFiles/tachometer.out.dir/requires: packages/tachometer/CMakeFiles/tachometer.out.dir/__/jetsonTX2/jetsonTX2.cpp.o.requires
packages/tachometer/CMakeFiles/tachometer.out.dir/requires: packages/tachometer/CMakeFiles/tachometer.out.dir/__/timer/timer.cpp.o.requires
packages/tachometer/CMakeFiles/tachometer.out.dir/requires: packages/tachometer/CMakeFiles/tachometer.out.dir/tachometer.cpp.o.requires
packages/tachometer/CMakeFiles/tachometer.out.dir/requires: packages/tachometer/CMakeFiles/tachometer.out.dir/main.cpp.o.requires

.PHONY : packages/tachometer/CMakeFiles/tachometer.out.dir/requires

packages/tachometer/CMakeFiles/tachometer.out.dir/clean:
	cd /home/christian/workspace/SCAVE2/dev/src/cpp/.build/packages/tachometer && $(CMAKE_COMMAND) -P CMakeFiles/tachometer.out.dir/cmake_clean.cmake
.PHONY : packages/tachometer/CMakeFiles/tachometer.out.dir/clean

packages/tachometer/CMakeFiles/tachometer.out.dir/depend:
	cd /home/christian/workspace/SCAVE2/dev/src/cpp/.build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/christian/workspace/SCAVE2/dev/src/cpp /home/christian/workspace/SCAVE2/dev/src/cpp/packages/tachometer /home/christian/workspace/SCAVE2/dev/src/cpp/.build /home/christian/workspace/SCAVE2/dev/src/cpp/.build/packages/tachometer /home/christian/workspace/SCAVE2/dev/src/cpp/.build/packages/tachometer/CMakeFiles/tachometer.out.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : packages/tachometer/CMakeFiles/tachometer.out.dir/depend

