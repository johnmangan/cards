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

# The program to use to edit the cache.
CMAKE_EDIT_COMMAND = /usr/bin/ccmake

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /home/ed/opt/cards

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/ed/opt/cards/build

# Include any dependencies generated for this target.
include CMakeFiles/unit_test.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/unit_test.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/unit_test.dir/flags.make

CMakeFiles/unit_test.dir/test/tests.cpp.o: CMakeFiles/unit_test.dir/flags.make
CMakeFiles/unit_test.dir/test/tests.cpp.o: ../test/tests.cpp
	$(CMAKE_COMMAND) -E cmake_progress_report /home/ed/opt/cards/build/CMakeFiles $(CMAKE_PROGRESS_1)
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Building CXX object CMakeFiles/unit_test.dir/test/tests.cpp.o"
	/usr/bin/c++   $(CXX_DEFINES) $(CXX_FLAGS) -o CMakeFiles/unit_test.dir/test/tests.cpp.o -c /home/ed/opt/cards/test/tests.cpp

CMakeFiles/unit_test.dir/test/tests.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/unit_test.dir/test/tests.cpp.i"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_FLAGS) -E /home/ed/opt/cards/test/tests.cpp > CMakeFiles/unit_test.dir/test/tests.cpp.i

CMakeFiles/unit_test.dir/test/tests.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/unit_test.dir/test/tests.cpp.s"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_FLAGS) -S /home/ed/opt/cards/test/tests.cpp -o CMakeFiles/unit_test.dir/test/tests.cpp.s

CMakeFiles/unit_test.dir/test/tests.cpp.o.requires:
.PHONY : CMakeFiles/unit_test.dir/test/tests.cpp.o.requires

CMakeFiles/unit_test.dir/test/tests.cpp.o.provides: CMakeFiles/unit_test.dir/test/tests.cpp.o.requires
	$(MAKE) -f CMakeFiles/unit_test.dir/build.make CMakeFiles/unit_test.dir/test/tests.cpp.o.provides.build
.PHONY : CMakeFiles/unit_test.dir/test/tests.cpp.o.provides

CMakeFiles/unit_test.dir/test/tests.cpp.o.provides.build: CMakeFiles/unit_test.dir/test/tests.cpp.o

CMakeFiles/unit_test.dir/test/src/collectoroutput.cpp.o: CMakeFiles/unit_test.dir/flags.make
CMakeFiles/unit_test.dir/test/src/collectoroutput.cpp.o: ../test/src/collectoroutput.cpp
	$(CMAKE_COMMAND) -E cmake_progress_report /home/ed/opt/cards/build/CMakeFiles $(CMAKE_PROGRESS_2)
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Building CXX object CMakeFiles/unit_test.dir/test/src/collectoroutput.cpp.o"
	/usr/bin/c++   $(CXX_DEFINES) $(CXX_FLAGS) -o CMakeFiles/unit_test.dir/test/src/collectoroutput.cpp.o -c /home/ed/opt/cards/test/src/collectoroutput.cpp

CMakeFiles/unit_test.dir/test/src/collectoroutput.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/unit_test.dir/test/src/collectoroutput.cpp.i"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_FLAGS) -E /home/ed/opt/cards/test/src/collectoroutput.cpp > CMakeFiles/unit_test.dir/test/src/collectoroutput.cpp.i

CMakeFiles/unit_test.dir/test/src/collectoroutput.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/unit_test.dir/test/src/collectoroutput.cpp.s"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_FLAGS) -S /home/ed/opt/cards/test/src/collectoroutput.cpp -o CMakeFiles/unit_test.dir/test/src/collectoroutput.cpp.s

CMakeFiles/unit_test.dir/test/src/collectoroutput.cpp.o.requires:
.PHONY : CMakeFiles/unit_test.dir/test/src/collectoroutput.cpp.o.requires

CMakeFiles/unit_test.dir/test/src/collectoroutput.cpp.o.provides: CMakeFiles/unit_test.dir/test/src/collectoroutput.cpp.o.requires
	$(MAKE) -f CMakeFiles/unit_test.dir/build.make CMakeFiles/unit_test.dir/test/src/collectoroutput.cpp.o.provides.build
.PHONY : CMakeFiles/unit_test.dir/test/src/collectoroutput.cpp.o.provides

CMakeFiles/unit_test.dir/test/src/collectoroutput.cpp.o.provides.build: CMakeFiles/unit_test.dir/test/src/collectoroutput.cpp.o

CMakeFiles/unit_test.dir/test/src/compileroutput.cpp.o: CMakeFiles/unit_test.dir/flags.make
CMakeFiles/unit_test.dir/test/src/compileroutput.cpp.o: ../test/src/compileroutput.cpp
	$(CMAKE_COMMAND) -E cmake_progress_report /home/ed/opt/cards/build/CMakeFiles $(CMAKE_PROGRESS_3)
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Building CXX object CMakeFiles/unit_test.dir/test/src/compileroutput.cpp.o"
	/usr/bin/c++   $(CXX_DEFINES) $(CXX_FLAGS) -o CMakeFiles/unit_test.dir/test/src/compileroutput.cpp.o -c /home/ed/opt/cards/test/src/compileroutput.cpp

CMakeFiles/unit_test.dir/test/src/compileroutput.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/unit_test.dir/test/src/compileroutput.cpp.i"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_FLAGS) -E /home/ed/opt/cards/test/src/compileroutput.cpp > CMakeFiles/unit_test.dir/test/src/compileroutput.cpp.i

CMakeFiles/unit_test.dir/test/src/compileroutput.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/unit_test.dir/test/src/compileroutput.cpp.s"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_FLAGS) -S /home/ed/opt/cards/test/src/compileroutput.cpp -o CMakeFiles/unit_test.dir/test/src/compileroutput.cpp.s

CMakeFiles/unit_test.dir/test/src/compileroutput.cpp.o.requires:
.PHONY : CMakeFiles/unit_test.dir/test/src/compileroutput.cpp.o.requires

CMakeFiles/unit_test.dir/test/src/compileroutput.cpp.o.provides: CMakeFiles/unit_test.dir/test/src/compileroutput.cpp.o.requires
	$(MAKE) -f CMakeFiles/unit_test.dir/build.make CMakeFiles/unit_test.dir/test/src/compileroutput.cpp.o.provides.build
.PHONY : CMakeFiles/unit_test.dir/test/src/compileroutput.cpp.o.provides

CMakeFiles/unit_test.dir/test/src/compileroutput.cpp.o.provides.build: CMakeFiles/unit_test.dir/test/src/compileroutput.cpp.o

CMakeFiles/unit_test.dir/test/src/htmloutput.cpp.o: CMakeFiles/unit_test.dir/flags.make
CMakeFiles/unit_test.dir/test/src/htmloutput.cpp.o: ../test/src/htmloutput.cpp
	$(CMAKE_COMMAND) -E cmake_progress_report /home/ed/opt/cards/build/CMakeFiles $(CMAKE_PROGRESS_4)
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Building CXX object CMakeFiles/unit_test.dir/test/src/htmloutput.cpp.o"
	/usr/bin/c++   $(CXX_DEFINES) $(CXX_FLAGS) -o CMakeFiles/unit_test.dir/test/src/htmloutput.cpp.o -c /home/ed/opt/cards/test/src/htmloutput.cpp

CMakeFiles/unit_test.dir/test/src/htmloutput.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/unit_test.dir/test/src/htmloutput.cpp.i"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_FLAGS) -E /home/ed/opt/cards/test/src/htmloutput.cpp > CMakeFiles/unit_test.dir/test/src/htmloutput.cpp.i

CMakeFiles/unit_test.dir/test/src/htmloutput.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/unit_test.dir/test/src/htmloutput.cpp.s"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_FLAGS) -S /home/ed/opt/cards/test/src/htmloutput.cpp -o CMakeFiles/unit_test.dir/test/src/htmloutput.cpp.s

CMakeFiles/unit_test.dir/test/src/htmloutput.cpp.o.requires:
.PHONY : CMakeFiles/unit_test.dir/test/src/htmloutput.cpp.o.requires

CMakeFiles/unit_test.dir/test/src/htmloutput.cpp.o.provides: CMakeFiles/unit_test.dir/test/src/htmloutput.cpp.o.requires
	$(MAKE) -f CMakeFiles/unit_test.dir/build.make CMakeFiles/unit_test.dir/test/src/htmloutput.cpp.o.provides.build
.PHONY : CMakeFiles/unit_test.dir/test/src/htmloutput.cpp.o.provides

CMakeFiles/unit_test.dir/test/src/htmloutput.cpp.o.provides.build: CMakeFiles/unit_test.dir/test/src/htmloutput.cpp.o

CMakeFiles/unit_test.dir/test/src/missing.cpp.o: CMakeFiles/unit_test.dir/flags.make
CMakeFiles/unit_test.dir/test/src/missing.cpp.o: ../test/src/missing.cpp
	$(CMAKE_COMMAND) -E cmake_progress_report /home/ed/opt/cards/build/CMakeFiles $(CMAKE_PROGRESS_5)
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Building CXX object CMakeFiles/unit_test.dir/test/src/missing.cpp.o"
	/usr/bin/c++   $(CXX_DEFINES) $(CXX_FLAGS) -o CMakeFiles/unit_test.dir/test/src/missing.cpp.o -c /home/ed/opt/cards/test/src/missing.cpp

CMakeFiles/unit_test.dir/test/src/missing.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/unit_test.dir/test/src/missing.cpp.i"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_FLAGS) -E /home/ed/opt/cards/test/src/missing.cpp > CMakeFiles/unit_test.dir/test/src/missing.cpp.i

CMakeFiles/unit_test.dir/test/src/missing.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/unit_test.dir/test/src/missing.cpp.s"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_FLAGS) -S /home/ed/opt/cards/test/src/missing.cpp -o CMakeFiles/unit_test.dir/test/src/missing.cpp.s

CMakeFiles/unit_test.dir/test/src/missing.cpp.o.requires:
.PHONY : CMakeFiles/unit_test.dir/test/src/missing.cpp.o.requires

CMakeFiles/unit_test.dir/test/src/missing.cpp.o.provides: CMakeFiles/unit_test.dir/test/src/missing.cpp.o.requires
	$(MAKE) -f CMakeFiles/unit_test.dir/build.make CMakeFiles/unit_test.dir/test/src/missing.cpp.o.provides.build
.PHONY : CMakeFiles/unit_test.dir/test/src/missing.cpp.o.provides

CMakeFiles/unit_test.dir/test/src/missing.cpp.o.provides.build: CMakeFiles/unit_test.dir/test/src/missing.cpp.o

CMakeFiles/unit_test.dir/test/src/source.cpp.o: CMakeFiles/unit_test.dir/flags.make
CMakeFiles/unit_test.dir/test/src/source.cpp.o: ../test/src/source.cpp
	$(CMAKE_COMMAND) -E cmake_progress_report /home/ed/opt/cards/build/CMakeFiles $(CMAKE_PROGRESS_6)
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Building CXX object CMakeFiles/unit_test.dir/test/src/source.cpp.o"
	/usr/bin/c++   $(CXX_DEFINES) $(CXX_FLAGS) -o CMakeFiles/unit_test.dir/test/src/source.cpp.o -c /home/ed/opt/cards/test/src/source.cpp

CMakeFiles/unit_test.dir/test/src/source.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/unit_test.dir/test/src/source.cpp.i"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_FLAGS) -E /home/ed/opt/cards/test/src/source.cpp > CMakeFiles/unit_test.dir/test/src/source.cpp.i

CMakeFiles/unit_test.dir/test/src/source.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/unit_test.dir/test/src/source.cpp.s"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_FLAGS) -S /home/ed/opt/cards/test/src/source.cpp -o CMakeFiles/unit_test.dir/test/src/source.cpp.s

CMakeFiles/unit_test.dir/test/src/source.cpp.o.requires:
.PHONY : CMakeFiles/unit_test.dir/test/src/source.cpp.o.requires

CMakeFiles/unit_test.dir/test/src/source.cpp.o.provides: CMakeFiles/unit_test.dir/test/src/source.cpp.o.requires
	$(MAKE) -f CMakeFiles/unit_test.dir/build.make CMakeFiles/unit_test.dir/test/src/source.cpp.o.provides.build
.PHONY : CMakeFiles/unit_test.dir/test/src/source.cpp.o.provides

CMakeFiles/unit_test.dir/test/src/source.cpp.o.provides.build: CMakeFiles/unit_test.dir/test/src/source.cpp.o

CMakeFiles/unit_test.dir/test/src/suite.cpp.o: CMakeFiles/unit_test.dir/flags.make
CMakeFiles/unit_test.dir/test/src/suite.cpp.o: ../test/src/suite.cpp
	$(CMAKE_COMMAND) -E cmake_progress_report /home/ed/opt/cards/build/CMakeFiles $(CMAKE_PROGRESS_7)
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Building CXX object CMakeFiles/unit_test.dir/test/src/suite.cpp.o"
	/usr/bin/c++   $(CXX_DEFINES) $(CXX_FLAGS) -o CMakeFiles/unit_test.dir/test/src/suite.cpp.o -c /home/ed/opt/cards/test/src/suite.cpp

CMakeFiles/unit_test.dir/test/src/suite.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/unit_test.dir/test/src/suite.cpp.i"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_FLAGS) -E /home/ed/opt/cards/test/src/suite.cpp > CMakeFiles/unit_test.dir/test/src/suite.cpp.i

CMakeFiles/unit_test.dir/test/src/suite.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/unit_test.dir/test/src/suite.cpp.s"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_FLAGS) -S /home/ed/opt/cards/test/src/suite.cpp -o CMakeFiles/unit_test.dir/test/src/suite.cpp.s

CMakeFiles/unit_test.dir/test/src/suite.cpp.o.requires:
.PHONY : CMakeFiles/unit_test.dir/test/src/suite.cpp.o.requires

CMakeFiles/unit_test.dir/test/src/suite.cpp.o.provides: CMakeFiles/unit_test.dir/test/src/suite.cpp.o.requires
	$(MAKE) -f CMakeFiles/unit_test.dir/build.make CMakeFiles/unit_test.dir/test/src/suite.cpp.o.provides.build
.PHONY : CMakeFiles/unit_test.dir/test/src/suite.cpp.o.provides

CMakeFiles/unit_test.dir/test/src/suite.cpp.o.provides.build: CMakeFiles/unit_test.dir/test/src/suite.cpp.o

CMakeFiles/unit_test.dir/test/src/textoutput.cpp.o: CMakeFiles/unit_test.dir/flags.make
CMakeFiles/unit_test.dir/test/src/textoutput.cpp.o: ../test/src/textoutput.cpp
	$(CMAKE_COMMAND) -E cmake_progress_report /home/ed/opt/cards/build/CMakeFiles $(CMAKE_PROGRESS_8)
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Building CXX object CMakeFiles/unit_test.dir/test/src/textoutput.cpp.o"
	/usr/bin/c++   $(CXX_DEFINES) $(CXX_FLAGS) -o CMakeFiles/unit_test.dir/test/src/textoutput.cpp.o -c /home/ed/opt/cards/test/src/textoutput.cpp

CMakeFiles/unit_test.dir/test/src/textoutput.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/unit_test.dir/test/src/textoutput.cpp.i"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_FLAGS) -E /home/ed/opt/cards/test/src/textoutput.cpp > CMakeFiles/unit_test.dir/test/src/textoutput.cpp.i

CMakeFiles/unit_test.dir/test/src/textoutput.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/unit_test.dir/test/src/textoutput.cpp.s"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_FLAGS) -S /home/ed/opt/cards/test/src/textoutput.cpp -o CMakeFiles/unit_test.dir/test/src/textoutput.cpp.s

CMakeFiles/unit_test.dir/test/src/textoutput.cpp.o.requires:
.PHONY : CMakeFiles/unit_test.dir/test/src/textoutput.cpp.o.requires

CMakeFiles/unit_test.dir/test/src/textoutput.cpp.o.provides: CMakeFiles/unit_test.dir/test/src/textoutput.cpp.o.requires
	$(MAKE) -f CMakeFiles/unit_test.dir/build.make CMakeFiles/unit_test.dir/test/src/textoutput.cpp.o.provides.build
.PHONY : CMakeFiles/unit_test.dir/test/src/textoutput.cpp.o.provides

CMakeFiles/unit_test.dir/test/src/textoutput.cpp.o.provides.build: CMakeFiles/unit_test.dir/test/src/textoutput.cpp.o

CMakeFiles/unit_test.dir/test/src/time.cpp.o: CMakeFiles/unit_test.dir/flags.make
CMakeFiles/unit_test.dir/test/src/time.cpp.o: ../test/src/time.cpp
	$(CMAKE_COMMAND) -E cmake_progress_report /home/ed/opt/cards/build/CMakeFiles $(CMAKE_PROGRESS_9)
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Building CXX object CMakeFiles/unit_test.dir/test/src/time.cpp.o"
	/usr/bin/c++   $(CXX_DEFINES) $(CXX_FLAGS) -o CMakeFiles/unit_test.dir/test/src/time.cpp.o -c /home/ed/opt/cards/test/src/time.cpp

CMakeFiles/unit_test.dir/test/src/time.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/unit_test.dir/test/src/time.cpp.i"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_FLAGS) -E /home/ed/opt/cards/test/src/time.cpp > CMakeFiles/unit_test.dir/test/src/time.cpp.i

CMakeFiles/unit_test.dir/test/src/time.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/unit_test.dir/test/src/time.cpp.s"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_FLAGS) -S /home/ed/opt/cards/test/src/time.cpp -o CMakeFiles/unit_test.dir/test/src/time.cpp.s

CMakeFiles/unit_test.dir/test/src/time.cpp.o.requires:
.PHONY : CMakeFiles/unit_test.dir/test/src/time.cpp.o.requires

CMakeFiles/unit_test.dir/test/src/time.cpp.o.provides: CMakeFiles/unit_test.dir/test/src/time.cpp.o.requires
	$(MAKE) -f CMakeFiles/unit_test.dir/build.make CMakeFiles/unit_test.dir/test/src/time.cpp.o.provides.build
.PHONY : CMakeFiles/unit_test.dir/test/src/time.cpp.o.provides

CMakeFiles/unit_test.dir/test/src/time.cpp.o.provides.build: CMakeFiles/unit_test.dir/test/src/time.cpp.o

CMakeFiles/unit_test.dir/test/src/utils.cpp.o: CMakeFiles/unit_test.dir/flags.make
CMakeFiles/unit_test.dir/test/src/utils.cpp.o: ../test/src/utils.cpp
	$(CMAKE_COMMAND) -E cmake_progress_report /home/ed/opt/cards/build/CMakeFiles $(CMAKE_PROGRESS_10)
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Building CXX object CMakeFiles/unit_test.dir/test/src/utils.cpp.o"
	/usr/bin/c++   $(CXX_DEFINES) $(CXX_FLAGS) -o CMakeFiles/unit_test.dir/test/src/utils.cpp.o -c /home/ed/opt/cards/test/src/utils.cpp

CMakeFiles/unit_test.dir/test/src/utils.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/unit_test.dir/test/src/utils.cpp.i"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_FLAGS) -E /home/ed/opt/cards/test/src/utils.cpp > CMakeFiles/unit_test.dir/test/src/utils.cpp.i

CMakeFiles/unit_test.dir/test/src/utils.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/unit_test.dir/test/src/utils.cpp.s"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_FLAGS) -S /home/ed/opt/cards/test/src/utils.cpp -o CMakeFiles/unit_test.dir/test/src/utils.cpp.s

CMakeFiles/unit_test.dir/test/src/utils.cpp.o.requires:
.PHONY : CMakeFiles/unit_test.dir/test/src/utils.cpp.o.requires

CMakeFiles/unit_test.dir/test/src/utils.cpp.o.provides: CMakeFiles/unit_test.dir/test/src/utils.cpp.o.requires
	$(MAKE) -f CMakeFiles/unit_test.dir/build.make CMakeFiles/unit_test.dir/test/src/utils.cpp.o.provides.build
.PHONY : CMakeFiles/unit_test.dir/test/src/utils.cpp.o.provides

CMakeFiles/unit_test.dir/test/src/utils.cpp.o.provides.build: CMakeFiles/unit_test.dir/test/src/utils.cpp.o

# Object files for target unit_test
unit_test_OBJECTS = \
"CMakeFiles/unit_test.dir/test/tests.cpp.o" \
"CMakeFiles/unit_test.dir/test/src/collectoroutput.cpp.o" \
"CMakeFiles/unit_test.dir/test/src/compileroutput.cpp.o" \
"CMakeFiles/unit_test.dir/test/src/htmloutput.cpp.o" \
"CMakeFiles/unit_test.dir/test/src/missing.cpp.o" \
"CMakeFiles/unit_test.dir/test/src/source.cpp.o" \
"CMakeFiles/unit_test.dir/test/src/suite.cpp.o" \
"CMakeFiles/unit_test.dir/test/src/textoutput.cpp.o" \
"CMakeFiles/unit_test.dir/test/src/time.cpp.o" \
"CMakeFiles/unit_test.dir/test/src/utils.cpp.o"

# External object files for target unit_test
unit_test_EXTERNAL_OBJECTS =

unit_test: CMakeFiles/unit_test.dir/test/tests.cpp.o
unit_test: CMakeFiles/unit_test.dir/test/src/collectoroutput.cpp.o
unit_test: CMakeFiles/unit_test.dir/test/src/compileroutput.cpp.o
unit_test: CMakeFiles/unit_test.dir/test/src/htmloutput.cpp.o
unit_test: CMakeFiles/unit_test.dir/test/src/missing.cpp.o
unit_test: CMakeFiles/unit_test.dir/test/src/source.cpp.o
unit_test: CMakeFiles/unit_test.dir/test/src/suite.cpp.o
unit_test: CMakeFiles/unit_test.dir/test/src/textoutput.cpp.o
unit_test: CMakeFiles/unit_test.dir/test/src/time.cpp.o
unit_test: CMakeFiles/unit_test.dir/test/src/utils.cpp.o
unit_test: libcards.so
unit_test: libsqlite3.so
unit_test: CMakeFiles/unit_test.dir/build.make
unit_test: CMakeFiles/unit_test.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --red --bold "Linking CXX executable unit_test"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/unit_test.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/unit_test.dir/build: unit_test
.PHONY : CMakeFiles/unit_test.dir/build

CMakeFiles/unit_test.dir/requires: CMakeFiles/unit_test.dir/test/tests.cpp.o.requires
CMakeFiles/unit_test.dir/requires: CMakeFiles/unit_test.dir/test/src/collectoroutput.cpp.o.requires
CMakeFiles/unit_test.dir/requires: CMakeFiles/unit_test.dir/test/src/compileroutput.cpp.o.requires
CMakeFiles/unit_test.dir/requires: CMakeFiles/unit_test.dir/test/src/htmloutput.cpp.o.requires
CMakeFiles/unit_test.dir/requires: CMakeFiles/unit_test.dir/test/src/missing.cpp.o.requires
CMakeFiles/unit_test.dir/requires: CMakeFiles/unit_test.dir/test/src/source.cpp.o.requires
CMakeFiles/unit_test.dir/requires: CMakeFiles/unit_test.dir/test/src/suite.cpp.o.requires
CMakeFiles/unit_test.dir/requires: CMakeFiles/unit_test.dir/test/src/textoutput.cpp.o.requires
CMakeFiles/unit_test.dir/requires: CMakeFiles/unit_test.dir/test/src/time.cpp.o.requires
CMakeFiles/unit_test.dir/requires: CMakeFiles/unit_test.dir/test/src/utils.cpp.o.requires
.PHONY : CMakeFiles/unit_test.dir/requires

CMakeFiles/unit_test.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/unit_test.dir/cmake_clean.cmake
.PHONY : CMakeFiles/unit_test.dir/clean

CMakeFiles/unit_test.dir/depend:
	cd /home/ed/opt/cards/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/ed/opt/cards /home/ed/opt/cards /home/ed/opt/cards/build /home/ed/opt/cards/build /home/ed/opt/cards/build/CMakeFiles/unit_test.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/unit_test.dir/depend
