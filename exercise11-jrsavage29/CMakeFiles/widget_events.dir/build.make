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
include CMakeFiles/widget_events.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/widget_events.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/widget_events.dir/flags.make

CMakeFiles/widget_events.dir/main.cpp.o: CMakeFiles/widget_events.dir/flags.make
CMakeFiles/widget_events.dir/main.cpp.o: main.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/vagrant/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/widget_events.dir/main.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/widget_events.dir/main.cpp.o -c /vagrant/main.cpp

CMakeFiles/widget_events.dir/main.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/widget_events.dir/main.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /vagrant/main.cpp > CMakeFiles/widget_events.dir/main.cpp.i

CMakeFiles/widget_events.dir/main.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/widget_events.dir/main.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /vagrant/main.cpp -o CMakeFiles/widget_events.dir/main.cpp.s

CMakeFiles/widget_events.dir/main.cpp.o.requires:

.PHONY : CMakeFiles/widget_events.dir/main.cpp.o.requires

CMakeFiles/widget_events.dir/main.cpp.o.provides: CMakeFiles/widget_events.dir/main.cpp.o.requires
	$(MAKE) -f CMakeFiles/widget_events.dir/build.make CMakeFiles/widget_events.dir/main.cpp.o.provides.build
.PHONY : CMakeFiles/widget_events.dir/main.cpp.o.provides

CMakeFiles/widget_events.dir/main.cpp.o.provides.build: CMakeFiles/widget_events.dir/main.cpp.o


CMakeFiles/widget_events.dir/widget_events.cpp.o: CMakeFiles/widget_events.dir/flags.make
CMakeFiles/widget_events.dir/widget_events.cpp.o: widget_events.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/vagrant/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building CXX object CMakeFiles/widget_events.dir/widget_events.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/widget_events.dir/widget_events.cpp.o -c /vagrant/widget_events.cpp

CMakeFiles/widget_events.dir/widget_events.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/widget_events.dir/widget_events.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /vagrant/widget_events.cpp > CMakeFiles/widget_events.dir/widget_events.cpp.i

CMakeFiles/widget_events.dir/widget_events.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/widget_events.dir/widget_events.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /vagrant/widget_events.cpp -o CMakeFiles/widget_events.dir/widget_events.cpp.s

CMakeFiles/widget_events.dir/widget_events.cpp.o.requires:

.PHONY : CMakeFiles/widget_events.dir/widget_events.cpp.o.requires

CMakeFiles/widget_events.dir/widget_events.cpp.o.provides: CMakeFiles/widget_events.dir/widget_events.cpp.o.requires
	$(MAKE) -f CMakeFiles/widget_events.dir/build.make CMakeFiles/widget_events.dir/widget_events.cpp.o.provides.build
.PHONY : CMakeFiles/widget_events.dir/widget_events.cpp.o.provides

CMakeFiles/widget_events.dir/widget_events.cpp.o.provides.build: CMakeFiles/widget_events.dir/widget_events.cpp.o


CMakeFiles/widget_events.dir/widget_events_autogen/mocs_compilation.cpp.o: CMakeFiles/widget_events.dir/flags.make
CMakeFiles/widget_events.dir/widget_events_autogen/mocs_compilation.cpp.o: widget_events_autogen/mocs_compilation.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/vagrant/CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Building CXX object CMakeFiles/widget_events.dir/widget_events_autogen/mocs_compilation.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/widget_events.dir/widget_events_autogen/mocs_compilation.cpp.o -c /vagrant/widget_events_autogen/mocs_compilation.cpp

CMakeFiles/widget_events.dir/widget_events_autogen/mocs_compilation.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/widget_events.dir/widget_events_autogen/mocs_compilation.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /vagrant/widget_events_autogen/mocs_compilation.cpp > CMakeFiles/widget_events.dir/widget_events_autogen/mocs_compilation.cpp.i

CMakeFiles/widget_events.dir/widget_events_autogen/mocs_compilation.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/widget_events.dir/widget_events_autogen/mocs_compilation.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /vagrant/widget_events_autogen/mocs_compilation.cpp -o CMakeFiles/widget_events.dir/widget_events_autogen/mocs_compilation.cpp.s

CMakeFiles/widget_events.dir/widget_events_autogen/mocs_compilation.cpp.o.requires:

.PHONY : CMakeFiles/widget_events.dir/widget_events_autogen/mocs_compilation.cpp.o.requires

CMakeFiles/widget_events.dir/widget_events_autogen/mocs_compilation.cpp.o.provides: CMakeFiles/widget_events.dir/widget_events_autogen/mocs_compilation.cpp.o.requires
	$(MAKE) -f CMakeFiles/widget_events.dir/build.make CMakeFiles/widget_events.dir/widget_events_autogen/mocs_compilation.cpp.o.provides.build
.PHONY : CMakeFiles/widget_events.dir/widget_events_autogen/mocs_compilation.cpp.o.provides

CMakeFiles/widget_events.dir/widget_events_autogen/mocs_compilation.cpp.o.provides.build: CMakeFiles/widget_events.dir/widget_events_autogen/mocs_compilation.cpp.o


# Object files for target widget_events
widget_events_OBJECTS = \
"CMakeFiles/widget_events.dir/main.cpp.o" \
"CMakeFiles/widget_events.dir/widget_events.cpp.o" \
"CMakeFiles/widget_events.dir/widget_events_autogen/mocs_compilation.cpp.o"

# External object files for target widget_events
widget_events_EXTERNAL_OBJECTS =

widget_events: CMakeFiles/widget_events.dir/main.cpp.o
widget_events: CMakeFiles/widget_events.dir/widget_events.cpp.o
widget_events: CMakeFiles/widget_events.dir/widget_events_autogen/mocs_compilation.cpp.o
widget_events: CMakeFiles/widget_events.dir/build.make
widget_events: /usr/lib/x86_64-linux-gnu/libQt5Widgets.so.5.9.5
widget_events: /usr/lib/x86_64-linux-gnu/libQt5Gui.so.5.9.5
widget_events: /usr/lib/x86_64-linux-gnu/libQt5Core.so.5.9.5
widget_events: CMakeFiles/widget_events.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/vagrant/CMakeFiles --progress-num=$(CMAKE_PROGRESS_4) "Linking CXX executable widget_events"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/widget_events.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/widget_events.dir/build: widget_events

.PHONY : CMakeFiles/widget_events.dir/build

CMakeFiles/widget_events.dir/requires: CMakeFiles/widget_events.dir/main.cpp.o.requires
CMakeFiles/widget_events.dir/requires: CMakeFiles/widget_events.dir/widget_events.cpp.o.requires
CMakeFiles/widget_events.dir/requires: CMakeFiles/widget_events.dir/widget_events_autogen/mocs_compilation.cpp.o.requires

.PHONY : CMakeFiles/widget_events.dir/requires

CMakeFiles/widget_events.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/widget_events.dir/cmake_clean.cmake
.PHONY : CMakeFiles/widget_events.dir/clean

CMakeFiles/widget_events.dir/depend:
	cd /vagrant && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /vagrant /vagrant /vagrant /vagrant /vagrant/CMakeFiles/widget_events.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/widget_events.dir/depend

