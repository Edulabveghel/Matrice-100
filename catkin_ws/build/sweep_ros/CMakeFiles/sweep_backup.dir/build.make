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

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /home/ubuntu/catkin_ws/src

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/ubuntu/catkin_ws/build

# Include any dependencies generated for this target.
include sweep_ros/CMakeFiles/sweep_backup.dir/depend.make

# Include the progress variables for this target.
include sweep_ros/CMakeFiles/sweep_backup.dir/progress.make

# Include the compile flags for this target's objects.
include sweep_ros/CMakeFiles/sweep_backup.dir/flags.make

sweep_ros/CMakeFiles/sweep_backup.dir/src/node_backup.cpp.o: sweep_ros/CMakeFiles/sweep_backup.dir/flags.make
sweep_ros/CMakeFiles/sweep_backup.dir/src/node_backup.cpp.o: /home/ubuntu/catkin_ws/src/sweep_ros/src/node_backup.cpp
	$(CMAKE_COMMAND) -E cmake_progress_report /home/ubuntu/catkin_ws/build/CMakeFiles $(CMAKE_PROGRESS_1)
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Building CXX object sweep_ros/CMakeFiles/sweep_backup.dir/src/node_backup.cpp.o"
	cd /home/ubuntu/catkin_ws/build/sweep_ros && /usr/bin/c++   $(CXX_DEFINES) $(CXX_FLAGS) -o CMakeFiles/sweep_backup.dir/src/node_backup.cpp.o -c /home/ubuntu/catkin_ws/src/sweep_ros/src/node_backup.cpp

sweep_ros/CMakeFiles/sweep_backup.dir/src/node_backup.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/sweep_backup.dir/src/node_backup.cpp.i"
	cd /home/ubuntu/catkin_ws/build/sweep_ros && /usr/bin/c++  $(CXX_DEFINES) $(CXX_FLAGS) -E /home/ubuntu/catkin_ws/src/sweep_ros/src/node_backup.cpp > CMakeFiles/sweep_backup.dir/src/node_backup.cpp.i

sweep_ros/CMakeFiles/sweep_backup.dir/src/node_backup.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/sweep_backup.dir/src/node_backup.cpp.s"
	cd /home/ubuntu/catkin_ws/build/sweep_ros && /usr/bin/c++  $(CXX_DEFINES) $(CXX_FLAGS) -S /home/ubuntu/catkin_ws/src/sweep_ros/src/node_backup.cpp -o CMakeFiles/sweep_backup.dir/src/node_backup.cpp.s

sweep_ros/CMakeFiles/sweep_backup.dir/src/node_backup.cpp.o.requires:
.PHONY : sweep_ros/CMakeFiles/sweep_backup.dir/src/node_backup.cpp.o.requires

sweep_ros/CMakeFiles/sweep_backup.dir/src/node_backup.cpp.o.provides: sweep_ros/CMakeFiles/sweep_backup.dir/src/node_backup.cpp.o.requires
	$(MAKE) -f sweep_ros/CMakeFiles/sweep_backup.dir/build.make sweep_ros/CMakeFiles/sweep_backup.dir/src/node_backup.cpp.o.provides.build
.PHONY : sweep_ros/CMakeFiles/sweep_backup.dir/src/node_backup.cpp.o.provides

sweep_ros/CMakeFiles/sweep_backup.dir/src/node_backup.cpp.o.provides.build: sweep_ros/CMakeFiles/sweep_backup.dir/src/node_backup.cpp.o

sweep_ros/CMakeFiles/sweep_backup.dir/src/protocol.cc.o: sweep_ros/CMakeFiles/sweep_backup.dir/flags.make
sweep_ros/CMakeFiles/sweep_backup.dir/src/protocol.cc.o: /home/ubuntu/catkin_ws/src/sweep_ros/src/protocol.cc
	$(CMAKE_COMMAND) -E cmake_progress_report /home/ubuntu/catkin_ws/build/CMakeFiles $(CMAKE_PROGRESS_2)
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Building CXX object sweep_ros/CMakeFiles/sweep_backup.dir/src/protocol.cc.o"
	cd /home/ubuntu/catkin_ws/build/sweep_ros && /usr/bin/c++   $(CXX_DEFINES) $(CXX_FLAGS) -o CMakeFiles/sweep_backup.dir/src/protocol.cc.o -c /home/ubuntu/catkin_ws/src/sweep_ros/src/protocol.cc

sweep_ros/CMakeFiles/sweep_backup.dir/src/protocol.cc.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/sweep_backup.dir/src/protocol.cc.i"
	cd /home/ubuntu/catkin_ws/build/sweep_ros && /usr/bin/c++  $(CXX_DEFINES) $(CXX_FLAGS) -E /home/ubuntu/catkin_ws/src/sweep_ros/src/protocol.cc > CMakeFiles/sweep_backup.dir/src/protocol.cc.i

sweep_ros/CMakeFiles/sweep_backup.dir/src/protocol.cc.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/sweep_backup.dir/src/protocol.cc.s"
	cd /home/ubuntu/catkin_ws/build/sweep_ros && /usr/bin/c++  $(CXX_DEFINES) $(CXX_FLAGS) -S /home/ubuntu/catkin_ws/src/sweep_ros/src/protocol.cc -o CMakeFiles/sweep_backup.dir/src/protocol.cc.s

sweep_ros/CMakeFiles/sweep_backup.dir/src/protocol.cc.o.requires:
.PHONY : sweep_ros/CMakeFiles/sweep_backup.dir/src/protocol.cc.o.requires

sweep_ros/CMakeFiles/sweep_backup.dir/src/protocol.cc.o.provides: sweep_ros/CMakeFiles/sweep_backup.dir/src/protocol.cc.o.requires
	$(MAKE) -f sweep_ros/CMakeFiles/sweep_backup.dir/build.make sweep_ros/CMakeFiles/sweep_backup.dir/src/protocol.cc.o.provides.build
.PHONY : sweep_ros/CMakeFiles/sweep_backup.dir/src/protocol.cc.o.provides

sweep_ros/CMakeFiles/sweep_backup.dir/src/protocol.cc.o.provides.build: sweep_ros/CMakeFiles/sweep_backup.dir/src/protocol.cc.o

sweep_ros/CMakeFiles/sweep_backup.dir/src/serial.cc.o: sweep_ros/CMakeFiles/sweep_backup.dir/flags.make
sweep_ros/CMakeFiles/sweep_backup.dir/src/serial.cc.o: /home/ubuntu/catkin_ws/src/sweep_ros/src/serial.cc
	$(CMAKE_COMMAND) -E cmake_progress_report /home/ubuntu/catkin_ws/build/CMakeFiles $(CMAKE_PROGRESS_3)
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Building CXX object sweep_ros/CMakeFiles/sweep_backup.dir/src/serial.cc.o"
	cd /home/ubuntu/catkin_ws/build/sweep_ros && /usr/bin/c++   $(CXX_DEFINES) $(CXX_FLAGS) -o CMakeFiles/sweep_backup.dir/src/serial.cc.o -c /home/ubuntu/catkin_ws/src/sweep_ros/src/serial.cc

sweep_ros/CMakeFiles/sweep_backup.dir/src/serial.cc.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/sweep_backup.dir/src/serial.cc.i"
	cd /home/ubuntu/catkin_ws/build/sweep_ros && /usr/bin/c++  $(CXX_DEFINES) $(CXX_FLAGS) -E /home/ubuntu/catkin_ws/src/sweep_ros/src/serial.cc > CMakeFiles/sweep_backup.dir/src/serial.cc.i

sweep_ros/CMakeFiles/sweep_backup.dir/src/serial.cc.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/sweep_backup.dir/src/serial.cc.s"
	cd /home/ubuntu/catkin_ws/build/sweep_ros && /usr/bin/c++  $(CXX_DEFINES) $(CXX_FLAGS) -S /home/ubuntu/catkin_ws/src/sweep_ros/src/serial.cc -o CMakeFiles/sweep_backup.dir/src/serial.cc.s

sweep_ros/CMakeFiles/sweep_backup.dir/src/serial.cc.o.requires:
.PHONY : sweep_ros/CMakeFiles/sweep_backup.dir/src/serial.cc.o.requires

sweep_ros/CMakeFiles/sweep_backup.dir/src/serial.cc.o.provides: sweep_ros/CMakeFiles/sweep_backup.dir/src/serial.cc.o.requires
	$(MAKE) -f sweep_ros/CMakeFiles/sweep_backup.dir/build.make sweep_ros/CMakeFiles/sweep_backup.dir/src/serial.cc.o.provides.build
.PHONY : sweep_ros/CMakeFiles/sweep_backup.dir/src/serial.cc.o.provides

sweep_ros/CMakeFiles/sweep_backup.dir/src/serial.cc.o.provides.build: sweep_ros/CMakeFiles/sweep_backup.dir/src/serial.cc.o

sweep_ros/CMakeFiles/sweep_backup.dir/src/sweep.cc.o: sweep_ros/CMakeFiles/sweep_backup.dir/flags.make
sweep_ros/CMakeFiles/sweep_backup.dir/src/sweep.cc.o: /home/ubuntu/catkin_ws/src/sweep_ros/src/sweep.cc
	$(CMAKE_COMMAND) -E cmake_progress_report /home/ubuntu/catkin_ws/build/CMakeFiles $(CMAKE_PROGRESS_4)
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Building CXX object sweep_ros/CMakeFiles/sweep_backup.dir/src/sweep.cc.o"
	cd /home/ubuntu/catkin_ws/build/sweep_ros && /usr/bin/c++   $(CXX_DEFINES) $(CXX_FLAGS) -o CMakeFiles/sweep_backup.dir/src/sweep.cc.o -c /home/ubuntu/catkin_ws/src/sweep_ros/src/sweep.cc

sweep_ros/CMakeFiles/sweep_backup.dir/src/sweep.cc.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/sweep_backup.dir/src/sweep.cc.i"
	cd /home/ubuntu/catkin_ws/build/sweep_ros && /usr/bin/c++  $(CXX_DEFINES) $(CXX_FLAGS) -E /home/ubuntu/catkin_ws/src/sweep_ros/src/sweep.cc > CMakeFiles/sweep_backup.dir/src/sweep.cc.i

sweep_ros/CMakeFiles/sweep_backup.dir/src/sweep.cc.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/sweep_backup.dir/src/sweep.cc.s"
	cd /home/ubuntu/catkin_ws/build/sweep_ros && /usr/bin/c++  $(CXX_DEFINES) $(CXX_FLAGS) -S /home/ubuntu/catkin_ws/src/sweep_ros/src/sweep.cc -o CMakeFiles/sweep_backup.dir/src/sweep.cc.s

sweep_ros/CMakeFiles/sweep_backup.dir/src/sweep.cc.o.requires:
.PHONY : sweep_ros/CMakeFiles/sweep_backup.dir/src/sweep.cc.o.requires

sweep_ros/CMakeFiles/sweep_backup.dir/src/sweep.cc.o.provides: sweep_ros/CMakeFiles/sweep_backup.dir/src/sweep.cc.o.requires
	$(MAKE) -f sweep_ros/CMakeFiles/sweep_backup.dir/build.make sweep_ros/CMakeFiles/sweep_backup.dir/src/sweep.cc.o.provides.build
.PHONY : sweep_ros/CMakeFiles/sweep_backup.dir/src/sweep.cc.o.provides

sweep_ros/CMakeFiles/sweep_backup.dir/src/sweep.cc.o.provides.build: sweep_ros/CMakeFiles/sweep_backup.dir/src/sweep.cc.o

# Object files for target sweep_backup
sweep_backup_OBJECTS = \
"CMakeFiles/sweep_backup.dir/src/node_backup.cpp.o" \
"CMakeFiles/sweep_backup.dir/src/protocol.cc.o" \
"CMakeFiles/sweep_backup.dir/src/serial.cc.o" \
"CMakeFiles/sweep_backup.dir/src/sweep.cc.o"

# External object files for target sweep_backup
sweep_backup_EXTERNAL_OBJECTS =

/home/ubuntu/catkin_ws/devel/lib/sweep_ros/sweep_backup: sweep_ros/CMakeFiles/sweep_backup.dir/src/node_backup.cpp.o
/home/ubuntu/catkin_ws/devel/lib/sweep_ros/sweep_backup: sweep_ros/CMakeFiles/sweep_backup.dir/src/protocol.cc.o
/home/ubuntu/catkin_ws/devel/lib/sweep_ros/sweep_backup: sweep_ros/CMakeFiles/sweep_backup.dir/src/serial.cc.o
/home/ubuntu/catkin_ws/devel/lib/sweep_ros/sweep_backup: sweep_ros/CMakeFiles/sweep_backup.dir/src/sweep.cc.o
/home/ubuntu/catkin_ws/devel/lib/sweep_ros/sweep_backup: sweep_ros/CMakeFiles/sweep_backup.dir/build.make
/home/ubuntu/catkin_ws/devel/lib/sweep_ros/sweep_backup: /opt/ros/indigo/lib/libroscpp.so
/home/ubuntu/catkin_ws/devel/lib/sweep_ros/sweep_backup: /usr/lib/arm-linux-gnueabihf/libboost_signals.so
/home/ubuntu/catkin_ws/devel/lib/sweep_ros/sweep_backup: /usr/lib/arm-linux-gnueabihf/libboost_filesystem.so
/home/ubuntu/catkin_ws/devel/lib/sweep_ros/sweep_backup: /opt/ros/indigo/lib/librosconsole.so
/home/ubuntu/catkin_ws/devel/lib/sweep_ros/sweep_backup: /opt/ros/indigo/lib/librosconsole_log4cxx.so
/home/ubuntu/catkin_ws/devel/lib/sweep_ros/sweep_backup: /opt/ros/indigo/lib/librosconsole_backend_interface.so
/home/ubuntu/catkin_ws/devel/lib/sweep_ros/sweep_backup: /usr/lib/liblog4cxx.so
/home/ubuntu/catkin_ws/devel/lib/sweep_ros/sweep_backup: /usr/lib/arm-linux-gnueabihf/libboost_regex.so
/home/ubuntu/catkin_ws/devel/lib/sweep_ros/sweep_backup: /opt/ros/indigo/lib/libxmlrpcpp.so
/home/ubuntu/catkin_ws/devel/lib/sweep_ros/sweep_backup: /opt/ros/indigo/lib/libroscpp_serialization.so
/home/ubuntu/catkin_ws/devel/lib/sweep_ros/sweep_backup: /opt/ros/indigo/lib/librostime.so
/home/ubuntu/catkin_ws/devel/lib/sweep_ros/sweep_backup: /usr/lib/arm-linux-gnueabihf/libboost_date_time.so
/home/ubuntu/catkin_ws/devel/lib/sweep_ros/sweep_backup: /opt/ros/indigo/lib/libcpp_common.so
/home/ubuntu/catkin_ws/devel/lib/sweep_ros/sweep_backup: /usr/lib/arm-linux-gnueabihf/libboost_system.so
/home/ubuntu/catkin_ws/devel/lib/sweep_ros/sweep_backup: /usr/lib/arm-linux-gnueabihf/libboost_thread.so
/home/ubuntu/catkin_ws/devel/lib/sweep_ros/sweep_backup: /usr/lib/arm-linux-gnueabihf/libpthread.so
/home/ubuntu/catkin_ws/devel/lib/sweep_ros/sweep_backup: /usr/lib/arm-linux-gnueabihf/libconsole_bridge.so
/home/ubuntu/catkin_ws/devel/lib/sweep_ros/sweep_backup: sweep_ros/CMakeFiles/sweep_backup.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --red --bold "Linking CXX executable /home/ubuntu/catkin_ws/devel/lib/sweep_ros/sweep_backup"
	cd /home/ubuntu/catkin_ws/build/sweep_ros && $(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/sweep_backup.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
sweep_ros/CMakeFiles/sweep_backup.dir/build: /home/ubuntu/catkin_ws/devel/lib/sweep_ros/sweep_backup
.PHONY : sweep_ros/CMakeFiles/sweep_backup.dir/build

sweep_ros/CMakeFiles/sweep_backup.dir/requires: sweep_ros/CMakeFiles/sweep_backup.dir/src/node_backup.cpp.o.requires
sweep_ros/CMakeFiles/sweep_backup.dir/requires: sweep_ros/CMakeFiles/sweep_backup.dir/src/protocol.cc.o.requires
sweep_ros/CMakeFiles/sweep_backup.dir/requires: sweep_ros/CMakeFiles/sweep_backup.dir/src/serial.cc.o.requires
sweep_ros/CMakeFiles/sweep_backup.dir/requires: sweep_ros/CMakeFiles/sweep_backup.dir/src/sweep.cc.o.requires
.PHONY : sweep_ros/CMakeFiles/sweep_backup.dir/requires

sweep_ros/CMakeFiles/sweep_backup.dir/clean:
	cd /home/ubuntu/catkin_ws/build/sweep_ros && $(CMAKE_COMMAND) -P CMakeFiles/sweep_backup.dir/cmake_clean.cmake
.PHONY : sweep_ros/CMakeFiles/sweep_backup.dir/clean

sweep_ros/CMakeFiles/sweep_backup.dir/depend:
	cd /home/ubuntu/catkin_ws/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/ubuntu/catkin_ws/src /home/ubuntu/catkin_ws/src/sweep_ros /home/ubuntu/catkin_ws/build /home/ubuntu/catkin_ws/build/sweep_ros /home/ubuntu/catkin_ws/build/sweep_ros/CMakeFiles/sweep_backup.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : sweep_ros/CMakeFiles/sweep_backup.dir/depend

