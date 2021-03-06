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
include producers/V1730/CMakeFiles/V1730Producer.exe.dir/depend.make

# Include the progress variables for this target.
include producers/V1730/CMakeFiles/V1730Producer.exe.dir/progress.make

# Include the compile flags for this target's objects.
include producers/V1730/CMakeFiles/V1730Producer.exe.dir/flags.make

producers/V1730/CMakeFiles/V1730Producer.exe.dir/src/V1730Producer.cxx.o: producers/V1730/CMakeFiles/V1730Producer.exe.dir/flags.make
producers/V1730/CMakeFiles/V1730Producer.exe.dir/src/V1730Producer.cxx.o: ../producers/V1730/src/V1730Producer.cxx
	$(CMAKE_COMMAND) -E cmake_progress_report /home/testbeam/sdvlp/eudaq-drs4/build/CMakeFiles $(CMAKE_PROGRESS_1)
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Building CXX object producers/V1730/CMakeFiles/V1730Producer.exe.dir/src/V1730Producer.cxx.o"
	cd /home/testbeam/sdvlp/eudaq-drs4/build/producers/V1730 && /opt/rh/devtoolset-3/root/usr/bin/c++   $(CXX_DEFINES) $(CXX_FLAGS) -o CMakeFiles/V1730Producer.exe.dir/src/V1730Producer.cxx.o -c /home/testbeam/sdvlp/eudaq-drs4/producers/V1730/src/V1730Producer.cxx

producers/V1730/CMakeFiles/V1730Producer.exe.dir/src/V1730Producer.cxx.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/V1730Producer.exe.dir/src/V1730Producer.cxx.i"
	cd /home/testbeam/sdvlp/eudaq-drs4/build/producers/V1730 && /opt/rh/devtoolset-3/root/usr/bin/c++  $(CXX_DEFINES) $(CXX_FLAGS) -E /home/testbeam/sdvlp/eudaq-drs4/producers/V1730/src/V1730Producer.cxx > CMakeFiles/V1730Producer.exe.dir/src/V1730Producer.cxx.i

producers/V1730/CMakeFiles/V1730Producer.exe.dir/src/V1730Producer.cxx.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/V1730Producer.exe.dir/src/V1730Producer.cxx.s"
	cd /home/testbeam/sdvlp/eudaq-drs4/build/producers/V1730 && /opt/rh/devtoolset-3/root/usr/bin/c++  $(CXX_DEFINES) $(CXX_FLAGS) -S /home/testbeam/sdvlp/eudaq-drs4/producers/V1730/src/V1730Producer.cxx -o CMakeFiles/V1730Producer.exe.dir/src/V1730Producer.cxx.s

producers/V1730/CMakeFiles/V1730Producer.exe.dir/src/V1730Producer.cxx.o.requires:
.PHONY : producers/V1730/CMakeFiles/V1730Producer.exe.dir/src/V1730Producer.cxx.o.requires

producers/V1730/CMakeFiles/V1730Producer.exe.dir/src/V1730Producer.cxx.o.provides: producers/V1730/CMakeFiles/V1730Producer.exe.dir/src/V1730Producer.cxx.o.requires
	$(MAKE) -f producers/V1730/CMakeFiles/V1730Producer.exe.dir/build.make producers/V1730/CMakeFiles/V1730Producer.exe.dir/src/V1730Producer.cxx.o.provides.build
.PHONY : producers/V1730/CMakeFiles/V1730Producer.exe.dir/src/V1730Producer.cxx.o.provides

producers/V1730/CMakeFiles/V1730Producer.exe.dir/src/V1730Producer.cxx.o.provides.build: producers/V1730/CMakeFiles/V1730Producer.exe.dir/src/V1730Producer.cxx.o

# Object files for target V1730Producer.exe
V1730Producer_exe_OBJECTS = \
"CMakeFiles/V1730Producer.exe.dir/src/V1730Producer.cxx.o"

# External object files for target V1730Producer.exe
V1730Producer_exe_EXTERNAL_OBJECTS =

producers/V1730/V1730Producer.exe: producers/V1730/CMakeFiles/V1730Producer.exe.dir/src/V1730Producer.cxx.o
producers/V1730/V1730Producer.exe: producers/V1730/CMakeFiles/V1730Producer.exe.dir/build.make
producers/V1730/V1730Producer.exe: main/lib/libEUDAQ.so
producers/V1730/V1730Producer.exe: /home/testbeam/lib/liblab.so
producers/V1730/V1730Producer.exe: /usr/lib64/libusb.so
producers/V1730/V1730Producer.exe: /ATLAS/lib/libio_rcc.so
producers/V1730/V1730Producer.exe: /ATLAS/lib/libvme_rcc.so
producers/V1730/V1730Producer.exe: /ATLAS/lib/libcmem_rcc.so
producers/V1730/V1730Producer.exe: /ATLAS/lib/librcc_error.so
producers/V1730/V1730Producer.exe: producers/V1730/CMakeFiles/V1730Producer.exe.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --red --bold "Linking CXX executable V1730Producer.exe"
	cd /home/testbeam/sdvlp/eudaq-drs4/build/producers/V1730 && $(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/V1730Producer.exe.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
producers/V1730/CMakeFiles/V1730Producer.exe.dir/build: producers/V1730/V1730Producer.exe
.PHONY : producers/V1730/CMakeFiles/V1730Producer.exe.dir/build

producers/V1730/CMakeFiles/V1730Producer.exe.dir/requires: producers/V1730/CMakeFiles/V1730Producer.exe.dir/src/V1730Producer.cxx.o.requires
.PHONY : producers/V1730/CMakeFiles/V1730Producer.exe.dir/requires

producers/V1730/CMakeFiles/V1730Producer.exe.dir/clean:
	cd /home/testbeam/sdvlp/eudaq-drs4/build/producers/V1730 && $(CMAKE_COMMAND) -P CMakeFiles/V1730Producer.exe.dir/cmake_clean.cmake
.PHONY : producers/V1730/CMakeFiles/V1730Producer.exe.dir/clean

producers/V1730/CMakeFiles/V1730Producer.exe.dir/depend:
	cd /home/testbeam/sdvlp/eudaq-drs4/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/testbeam/sdvlp/eudaq-drs4 /home/testbeam/sdvlp/eudaq-drs4/producers/V1730 /home/testbeam/sdvlp/eudaq-drs4/build /home/testbeam/sdvlp/eudaq-drs4/build/producers/V1730 /home/testbeam/sdvlp/eudaq-drs4/build/producers/V1730/CMakeFiles/V1730Producer.exe.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : producers/V1730/CMakeFiles/V1730Producer.exe.dir/depend

