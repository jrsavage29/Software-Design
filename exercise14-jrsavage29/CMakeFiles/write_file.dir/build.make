# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.10

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
CMAKE_SOURCE_DIR = /vagrant

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /vagrant

# Include any dependencies generated for this target.
include CMakeFiles/write_file.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/write_file.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/write_file.dir/flags.make

CMakeFiles/write_file.dir/write_file.cpp.o: CMakeFiles/write_file.dir/flags.make
CMakeFiles/write_file.dir/write_file.cpp.o: write_file.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/vagrant/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/write_file.dir/write_file.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/write_file.dir/write_file.cpp.o -c /vagrant/write_file.cpp

CMakeFiles/write_file.dir/write_file.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/write_file.dir/write_file.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /vagrant/write_file.cpp > CMakeFiles/write_file.dir/write_file.cpp.i

CMakeFiles/write_file.dir/write_file.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/write_file.dir/write_file.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /vagrant/write_file.cpp -o CMakeFiles/write_file.dir/write_file.cpp.s

CMakeFiles/write_file.dir/write_file.cpp.o.requires:

.PHONY : CMakeFiles/write_file.dir/write_file.cpp.o.requires

CMakeFiles/write_file.dir/write_file.cpp.o.provides: CMakeFiles/write_file.dir/write_file.cpp.o.requires
	$(MAKE) -f CMakeFiles/write_file.dir/build.make CMakeFiles/write_file.dir/write_file.cpp.o.provides.build
.PHONY : CMakeFiles/write_file.dir/write_file.cpp.o.provides

CMakeFiles/write_file.dir/write_file.cpp.o.provides.build: CMakeFiles/write_file.dir/write_file.cpp.o


CMakeFiles/write_file.dir/write_file_autogen/mocs_compilation.cpp.o: CMakeFiles/write_file.dir/flags.make
CMakeFiles/write_file.dir/write_file_autogen/mocs_compilation.cpp.o: write_file_autogen/mocs_compilation.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/vagrant/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building CXX object CMakeFiles/write_file.dir/write_file_autogen/mocs_compilation.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/write_file.dir/write_file_autogen/mocs_compilation.cpp.o -c /vagrant/write_file_autogen/mocs_compilation.cpp

CMakeFiles/write_file.dir/write_file_autogen/mocs_compilation.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/write_file.dir/write_file_autogen/mocs_compilation.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /vagrant/write_file_autogen/mocs_compilation.cpp > CMakeFiles/write_file.dir/write_file_autogen/mocs_compilation.cpp.i

CMakeFiles/write_file.dir/write_file_autogen/mocs_compilation.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/write_file.dir/write_file_autogen/mocs_compilation.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /vagrant/write_file_autogen/mocs_compilation.cpp -o CMakeFiles/write_file.dir/write_file_autogen/mocs_compilation.cpp.s

CMakeFiles/write_file.dir/write_file_autogen/mocs_compilation.cpp.o.requires:

.PHONY : CMakeFiles/write_file.dir/write_file_autogen/mocs_compilation.cpp.o.requires

CMakeFiles/write_file.dir/write_file_autogen/mocs_compilation.cpp.o.provides: CMakeFiles/write_file.dir/write_file_autogen/mocs_compilation.cpp.o.requires
	$(MAKE) -f CMakeFiles/write_file.dir/build.make CMakeFiles/write_file.dir/write_file_autogen/mocs_compilation.cpp.o.provides.build
.PHONY : CMakeFiles/write_file.dir/write_file_autogen/mocs_compilation.cpp.o.provides

CMakeFiles/write_file.dir/write_file_autogen/mocs_compilation.cpp.o.provides.build: CMakeFiles/write_file.dir/write_file_autogen/mocs_compilation.cpp.o


# Object files for target write_file
write_file_OBJECTS = \
"CMakeFiles/write_file.dir/write_file.cpp.o" \
"CMakeFiles/write_file.dir/write_file_autogen/mocs_compilation.cpp.o"

# External object files for target write_file
write_file_EXTERNAL_OBJECTS =

write_file: CMakeFiles/write_file.dir/write_file.cpp.o
write_file: CMakeFiles/write_file.dir/write_file_autogen/mocs_compilation.cpp.o
write_file: CMakeFiles/write_file.dir/build.make
write_file: /usr/lib/x86_64-linux-gnu/libQt5Core.so.5.9.5
write_file: CMakeFiles/write_file.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/vagrant/CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Linking CXX executable write_file"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/write_file.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/write_file.dir/build: write_file

.PHONY : CMakeFiles/write_file.dir/build

CMakeFiles/write_file.dir/requires: CMakeFiles/write_file.dir/write_file.cpp.o.requires
CMakeFiles/write_file.dir/requires: CMakeFiles/write_file.dir/write_file_autogen/mocs_compilation.cpp.o.requires

.PHONY : CMakeFiles/write_file.dir/requires

CMakeFiles/write_file.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/write_file.dir/cmake_clean.cmake
.PHONY : CMakeFiles/write_file.dir/clean

CMakeFiles/write_file.dir/depend:
	cd /vagrant && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /vagrant /vagrant /vagrant /vagrant /vagrant/CMakeFiles/write_file.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/write_file.dir/depend

