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
include CMakeFiles/sqlite3-shared.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/sqlite3-shared.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/sqlite3-shared.dir/flags.make

CMakeFiles/sqlite3-shared.dir/sqlite/src/sqlite3.c.o: CMakeFiles/sqlite3-shared.dir/flags.make
CMakeFiles/sqlite3-shared.dir/sqlite/src/sqlite3.c.o: ../sqlite/src/sqlite3.c
	$(CMAKE_COMMAND) -E cmake_progress_report /home/ed/opt/cards/build/CMakeFiles $(CMAKE_PROGRESS_1)
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Building C object CMakeFiles/sqlite3-shared.dir/sqlite/src/sqlite3.c.o"
	/usr/bin/gcc  $(C_DEFINES) $(C_FLAGS) -o CMakeFiles/sqlite3-shared.dir/sqlite/src/sqlite3.c.o   -c /home/ed/opt/cards/sqlite/src/sqlite3.c

CMakeFiles/sqlite3-shared.dir/sqlite/src/sqlite3.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/sqlite3-shared.dir/sqlite/src/sqlite3.c.i"
	/usr/bin/gcc  $(C_DEFINES) $(C_FLAGS) -E /home/ed/opt/cards/sqlite/src/sqlite3.c > CMakeFiles/sqlite3-shared.dir/sqlite/src/sqlite3.c.i

CMakeFiles/sqlite3-shared.dir/sqlite/src/sqlite3.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/sqlite3-shared.dir/sqlite/src/sqlite3.c.s"
	/usr/bin/gcc  $(C_DEFINES) $(C_FLAGS) -S /home/ed/opt/cards/sqlite/src/sqlite3.c -o CMakeFiles/sqlite3-shared.dir/sqlite/src/sqlite3.c.s

CMakeFiles/sqlite3-shared.dir/sqlite/src/sqlite3.c.o.requires:
.PHONY : CMakeFiles/sqlite3-shared.dir/sqlite/src/sqlite3.c.o.requires

CMakeFiles/sqlite3-shared.dir/sqlite/src/sqlite3.c.o.provides: CMakeFiles/sqlite3-shared.dir/sqlite/src/sqlite3.c.o.requires
	$(MAKE) -f CMakeFiles/sqlite3-shared.dir/build.make CMakeFiles/sqlite3-shared.dir/sqlite/src/sqlite3.c.o.provides.build
.PHONY : CMakeFiles/sqlite3-shared.dir/sqlite/src/sqlite3.c.o.provides

CMakeFiles/sqlite3-shared.dir/sqlite/src/sqlite3.c.o.provides.build: CMakeFiles/sqlite3-shared.dir/sqlite/src/sqlite3.c.o

# Object files for target sqlite3-shared
sqlite3__shared_OBJECTS = \
"CMakeFiles/sqlite3-shared.dir/sqlite/src/sqlite3.c.o"

# External object files for target sqlite3-shared
sqlite3__shared_EXTERNAL_OBJECTS =

libsqlite3.so: CMakeFiles/sqlite3-shared.dir/sqlite/src/sqlite3.c.o
libsqlite3.so: CMakeFiles/sqlite3-shared.dir/build.make
libsqlite3.so: CMakeFiles/sqlite3-shared.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --red --bold "Linking C shared library libsqlite3.so"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/sqlite3-shared.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/sqlite3-shared.dir/build: libsqlite3.so
.PHONY : CMakeFiles/sqlite3-shared.dir/build

CMakeFiles/sqlite3-shared.dir/requires: CMakeFiles/sqlite3-shared.dir/sqlite/src/sqlite3.c.o.requires
.PHONY : CMakeFiles/sqlite3-shared.dir/requires

CMakeFiles/sqlite3-shared.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/sqlite3-shared.dir/cmake_clean.cmake
.PHONY : CMakeFiles/sqlite3-shared.dir/clean

CMakeFiles/sqlite3-shared.dir/depend:
	cd /home/ed/opt/cards/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/ed/opt/cards /home/ed/opt/cards /home/ed/opt/cards/build /home/ed/opt/cards/build /home/ed/opt/cards/build/CMakeFiles/sqlite3-shared.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/sqlite3-shared.dir/depend

