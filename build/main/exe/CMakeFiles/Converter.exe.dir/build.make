# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 2.8

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

# The program to use to edit the cache.
CMAKE_EDIT_COMMAND = /usr/bin/cmake-gui

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /home/testbeam/sdvlp/eudaq-drs4

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/testbeam/sdvlp/eudaq-drs4/build

# Include any dependencies generated for this target.
include main/exe/CMakeFiles/Converter.exe.dir/depend.make

# Include the progress variables for this target.
include main/exe/CMakeFiles/Converter.exe.dir/progress.make

# Include the compile flags for this target's objects.
include main/exe/CMakeFiles/Converter.exe.dir/flags.make

main/exe/CMakeFiles/Converter.exe.dir/src/Converter.cxx.o: main/exe/CMakeFiles/Converter.exe.dir/flags.make
main/exe/CMakeFiles/Converter.exe.dir/src/Converter.cxx.o: ../main/exe/src/Converter.cxx
	$(CMAKE_COMMAND) -E cmake_progress_report /home/testbeam/sdvlp/eudaq-drs4/build/CMakeFiles $(CMAKE_PROGRESS_1)
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Building CXX object main/exe/CMakeFiles/Converter.exe.dir/src/Converter.cxx.o"
	cd /home/testbeam/sdvlp/eudaq-drs4/build/main/exe && /opt/rh/devtoolset-3/root/usr/bin/c++   $(CXX_DEFINES) $(CXX_FLAGS) -o CMakeFiles/Converter.exe.dir/src/Converter.cxx.o -c /home/testbeam/sdvlp/eudaq-drs4/main/exe/src/Converter.cxx

main/exe/CMakeFiles/Converter.exe.dir/src/Converter.cxx.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/Converter.exe.dir/src/Converter.cxx.i"
	cd /home/testbeam/sdvlp/eudaq-drs4/build/main/exe && /opt/rh/devtoolset-3/root/usr/bin/c++  $(CXX_DEFINES) $(CXX_FLAGS) -E /home/testbeam/sdvlp/eudaq-drs4/main/exe/src/Converter.cxx > CMakeFiles/Converter.exe.dir/src/Converter.cxx.i

main/exe/CMakeFiles/Converter.exe.dir/src/Converter.cxx.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/Converter.exe.dir/src/Converter.cxx.s"
	cd /home/testbeam/sdvlp/eudaq-drs4/build/main/exe && /opt/rh/devtoolset-3/root/usr/bin/c++  $(CXX_DEFINES) $(CXX_FLAGS) -S /home/testbeam/sdvlp/eudaq-drs4/main/exe/src/Converter.cxx -o CMakeFiles/Converter.exe.dir/src/Converter.cxx.s

main/exe/CMakeFiles/Converter.exe.dir/src/Converter.cxx.o.requires:
.PHONY : main/exe/CMakeFiles/Converter.exe.dir/src/Converter.cxx.o.requires

main/exe/CMakeFiles/Converter.exe.dir/src/Converter.cxx.o.provides: main/exe/CMakeFiles/Converter.exe.dir/src/Converter.cxx.o.requires
	$(MAKE) -f main/exe/CMakeFiles/Converter.exe.dir/build.make main/exe/CMakeFiles/Converter.exe.dir/src/Converter.cxx.o.provides.build
.PHONY : main/exe/CMakeFiles/Converter.exe.dir/src/Converter.cxx.o.provides

main/exe/CMakeFiles/Converter.exe.dir/src/Converter.cxx.o.provides.build: main/exe/CMakeFiles/Converter.exe.dir/src/Converter.cxx.o

# Object files for target Converter.exe
Converter_exe_OBJECTS = \
"CMakeFiles/Converter.exe.dir/src/Converter.cxx.o"

# External object files for target Converter.exe
Converter_exe_EXTERNAL_OBJECTS =

main/exe/Converter.exe: main/exe/CMakeFiles/Converter.exe.dir/src/Converter.cxx.o
main/exe/Converter.exe: main/exe/CMakeFiles/Converter.exe.dir/build.make
main/exe/Converter.exe: main/lib/libEUDAQ.so
main/exe/Converter.exe: main/exe/CMakeFiles/Converter.exe.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --red --bold "Linking CXX executable Converter.exe"
	cd /home/testbeam/sdvlp/eudaq-drs4/build/main/exe && $(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/Converter.exe.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
main/exe/CMakeFiles/Converter.exe.dir/build: main/exe/Converter.exe
.PHONY : main/exe/CMakeFiles/Converter.exe.dir/build

main/exe/CMakeFiles/Converter.exe.dir/requires: main/exe/CMakeFiles/Converter.exe.dir/src/Converter.cxx.o.requires
.PHONY : main/exe/CMakeFiles/Converter.exe.dir/requires

main/exe/CMakeFiles/Converter.exe.dir/clean:
	cd /home/testbeam/sdvlp/eudaq-drs4/build/main/exe && $(CMAKE_COMMAND) -P CMakeFiles/Converter.exe.dir/cmake_clean.cmake
.PHONY : main/exe/CMakeFiles/Converter.exe.dir/clean

main/exe/CMakeFiles/Converter.exe.dir/depend:
	cd /home/testbeam/sdvlp/eudaq-drs4/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/testbeam/sdvlp/eudaq-drs4 /home/testbeam/sdvlp/eudaq-drs4/main/exe /home/testbeam/sdvlp/eudaq-drs4/build /home/testbeam/sdvlp/eudaq-drs4/build/main/exe /home/testbeam/sdvlp/eudaq-drs4/build/main/exe/CMakeFiles/Converter.exe.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : main/exe/CMakeFiles/Converter.exe.dir/depend

