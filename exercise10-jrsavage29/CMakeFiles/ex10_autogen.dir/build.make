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

# Utility rule file for ex10_autogen.

# Include the progress variables for this target.
include CMakeFiles/ex10_autogen.dir/progress.make

CMakeFiles/ex10_autogen:
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --blue --bold --progress-dir=/vagrant/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Automatic MOC for target ex10"
	/usr/bin/cmake -E cmake_autogen /vagrant/CMakeFiles/ex10_autogen.dir ""

ex10_autogen: CMakeFiles/ex10_autogen
ex10_autogen: CMakeFiles/ex10_autogen.dir/build.make

.PHONY : ex10_autogen

# Rule to build all files generated by this target.
CMakeFiles/ex10_autogen.dir/build: ex10_autogen

.PHONY : CMakeFiles/ex10_autogen.dir/build

CMakeFiles/ex10_autogen.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/ex10_autogen.dir/cmake_clean.cmake
.PHONY : CMakeFiles/ex10_autogen.dir/clean

CMakeFiles/ex10_autogen.dir/depend:
	cd /vagrant && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /vagrant /vagrant /vagrant /vagrant /vagrant/CMakeFiles/ex10_autogen.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/ex10_autogen.dir/depend

