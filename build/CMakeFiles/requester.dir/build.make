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

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /nishome/gcerna/ros/rosbuild_ws/taskallocator

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /nishome/gcerna/ros/rosbuild_ws/taskallocator/build

# Include any dependencies generated for this target.
include CMakeFiles/requester.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/requester.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/requester.dir/flags.make

CMakeFiles/requester.dir/src/requester.cpp.o: CMakeFiles/requester.dir/flags.make
CMakeFiles/requester.dir/src/requester.cpp.o: ../src/requester.cpp
CMakeFiles/requester.dir/src/requester.cpp.o: ../manifest.xml
CMakeFiles/requester.dir/src/requester.cpp.o: /opt/ros/groovy/share/catkin/package.xml
CMakeFiles/requester.dir/src/requester.cpp.o: /opt/ros/groovy/share/rospack/package.xml
CMakeFiles/requester.dir/src/requester.cpp.o: /opt/ros/groovy/share/roslib/package.xml
CMakeFiles/requester.dir/src/requester.cpp.o: /opt/ros/groovy/share/cpp_common/package.xml
CMakeFiles/requester.dir/src/requester.cpp.o: /opt/ros/groovy/share/rostime/package.xml
CMakeFiles/requester.dir/src/requester.cpp.o: /opt/ros/groovy/share/roscpp_traits/package.xml
CMakeFiles/requester.dir/src/requester.cpp.o: /opt/ros/groovy/share/roscpp_serialization/package.xml
CMakeFiles/requester.dir/src/requester.cpp.o: /opt/ros/groovy/share/genmsg/package.xml
CMakeFiles/requester.dir/src/requester.cpp.o: /opt/ros/groovy/share/genpy/package.xml
CMakeFiles/requester.dir/src/requester.cpp.o: /opt/ros/groovy/share/message_runtime/package.xml
CMakeFiles/requester.dir/src/requester.cpp.o: /opt/ros/groovy/share/rosconsole/package.xml
CMakeFiles/requester.dir/src/requester.cpp.o: /opt/ros/groovy/share/std_msgs/package.xml
CMakeFiles/requester.dir/src/requester.cpp.o: /opt/ros/groovy/share/rosgraph_msgs/package.xml
CMakeFiles/requester.dir/src/requester.cpp.o: /opt/ros/groovy/share/xmlrpcpp/package.xml
CMakeFiles/requester.dir/src/requester.cpp.o: /opt/ros/groovy/share/roscpp/package.xml
	$(CMAKE_COMMAND) -E cmake_progress_report /nishome/gcerna/ros/rosbuild_ws/taskallocator/build/CMakeFiles $(CMAKE_PROGRESS_1)
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Building CXX object CMakeFiles/requester.dir/src/requester.cpp.o"
	/usr/bin/c++   $(CXX_DEFINES) $(CXX_FLAGS) -W -Wall -Wno-unused-parameter -fno-strict-aliasing -pthread -o CMakeFiles/requester.dir/src/requester.cpp.o -c /nishome/gcerna/ros/rosbuild_ws/taskallocator/src/requester.cpp

CMakeFiles/requester.dir/src/requester.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/requester.dir/src/requester.cpp.i"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_FLAGS) -W -Wall -Wno-unused-parameter -fno-strict-aliasing -pthread -E /nishome/gcerna/ros/rosbuild_ws/taskallocator/src/requester.cpp > CMakeFiles/requester.dir/src/requester.cpp.i

CMakeFiles/requester.dir/src/requester.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/requester.dir/src/requester.cpp.s"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_FLAGS) -W -Wall -Wno-unused-parameter -fno-strict-aliasing -pthread -S /nishome/gcerna/ros/rosbuild_ws/taskallocator/src/requester.cpp -o CMakeFiles/requester.dir/src/requester.cpp.s

CMakeFiles/requester.dir/src/requester.cpp.o.requires:
.PHONY : CMakeFiles/requester.dir/src/requester.cpp.o.requires

CMakeFiles/requester.dir/src/requester.cpp.o.provides: CMakeFiles/requester.dir/src/requester.cpp.o.requires
	$(MAKE) -f CMakeFiles/requester.dir/build.make CMakeFiles/requester.dir/src/requester.cpp.o.provides.build
.PHONY : CMakeFiles/requester.dir/src/requester.cpp.o.provides

CMakeFiles/requester.dir/src/requester.cpp.o.provides.build: CMakeFiles/requester.dir/src/requester.cpp.o

# Object files for target requester
requester_OBJECTS = \
"CMakeFiles/requester.dir/src/requester.cpp.o"

# External object files for target requester
requester_EXTERNAL_OBJECTS =

../bin/requester: CMakeFiles/requester.dir/src/requester.cpp.o
../bin/requester: CMakeFiles/requester.dir/build.make
../bin/requester: CMakeFiles/requester.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --red --bold "Linking CXX executable ../bin/requester"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/requester.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/requester.dir/build: ../bin/requester
.PHONY : CMakeFiles/requester.dir/build

CMakeFiles/requester.dir/requires: CMakeFiles/requester.dir/src/requester.cpp.o.requires
.PHONY : CMakeFiles/requester.dir/requires

CMakeFiles/requester.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/requester.dir/cmake_clean.cmake
.PHONY : CMakeFiles/requester.dir/clean

CMakeFiles/requester.dir/depend:
	cd /nishome/gcerna/ros/rosbuild_ws/taskallocator/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /nishome/gcerna/ros/rosbuild_ws/taskallocator /nishome/gcerna/ros/rosbuild_ws/taskallocator /nishome/gcerna/ros/rosbuild_ws/taskallocator/build /nishome/gcerna/ros/rosbuild_ws/taskallocator/build /nishome/gcerna/ros/rosbuild_ws/taskallocator/build/CMakeFiles/requester.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/requester.dir/depend

