# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.5

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
CMAKE_SOURCE_DIR = /home/ziusudra/Desktop/aves

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/ziusudra/Desktop/aves

# Include any dependencies generated for this target.
include CMakeFiles/Aves.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/Aves.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/Aves.dir/flags.make

CMakeFiles/Aves.dir/src/World.cpp.o: CMakeFiles/Aves.dir/flags.make
CMakeFiles/Aves.dir/src/World.cpp.o: src/World.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/ziusudra/Desktop/aves/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/Aves.dir/src/World.cpp.o"
	/usr/bin/c++   $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/Aves.dir/src/World.cpp.o -c /home/ziusudra/Desktop/aves/src/World.cpp

CMakeFiles/Aves.dir/src/World.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/Aves.dir/src/World.cpp.i"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/ziusudra/Desktop/aves/src/World.cpp > CMakeFiles/Aves.dir/src/World.cpp.i

CMakeFiles/Aves.dir/src/World.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/Aves.dir/src/World.cpp.s"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/ziusudra/Desktop/aves/src/World.cpp -o CMakeFiles/Aves.dir/src/World.cpp.s

CMakeFiles/Aves.dir/src/World.cpp.o.requires:

.PHONY : CMakeFiles/Aves.dir/src/World.cpp.o.requires

CMakeFiles/Aves.dir/src/World.cpp.o.provides: CMakeFiles/Aves.dir/src/World.cpp.o.requires
	$(MAKE) -f CMakeFiles/Aves.dir/build.make CMakeFiles/Aves.dir/src/World.cpp.o.provides.build
.PHONY : CMakeFiles/Aves.dir/src/World.cpp.o.provides

CMakeFiles/Aves.dir/src/World.cpp.o.provides.build: CMakeFiles/Aves.dir/src/World.cpp.o


CMakeFiles/Aves.dir/src/Ave.cpp.o: CMakeFiles/Aves.dir/flags.make
CMakeFiles/Aves.dir/src/Ave.cpp.o: src/Ave.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/ziusudra/Desktop/aves/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building CXX object CMakeFiles/Aves.dir/src/Ave.cpp.o"
	/usr/bin/c++   $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/Aves.dir/src/Ave.cpp.o -c /home/ziusudra/Desktop/aves/src/Ave.cpp

CMakeFiles/Aves.dir/src/Ave.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/Aves.dir/src/Ave.cpp.i"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/ziusudra/Desktop/aves/src/Ave.cpp > CMakeFiles/Aves.dir/src/Ave.cpp.i

CMakeFiles/Aves.dir/src/Ave.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/Aves.dir/src/Ave.cpp.s"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/ziusudra/Desktop/aves/src/Ave.cpp -o CMakeFiles/Aves.dir/src/Ave.cpp.s

CMakeFiles/Aves.dir/src/Ave.cpp.o.requires:

.PHONY : CMakeFiles/Aves.dir/src/Ave.cpp.o.requires

CMakeFiles/Aves.dir/src/Ave.cpp.o.provides: CMakeFiles/Aves.dir/src/Ave.cpp.o.requires
	$(MAKE) -f CMakeFiles/Aves.dir/build.make CMakeFiles/Aves.dir/src/Ave.cpp.o.provides.build
.PHONY : CMakeFiles/Aves.dir/src/Ave.cpp.o.provides

CMakeFiles/Aves.dir/src/Ave.cpp.o.provides.build: CMakeFiles/Aves.dir/src/Ave.cpp.o


CMakeFiles/Aves.dir/src/mainApp.cpp.o: CMakeFiles/Aves.dir/flags.make
CMakeFiles/Aves.dir/src/mainApp.cpp.o: src/mainApp.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/ziusudra/Desktop/aves/CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Building CXX object CMakeFiles/Aves.dir/src/mainApp.cpp.o"
	/usr/bin/c++   $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/Aves.dir/src/mainApp.cpp.o -c /home/ziusudra/Desktop/aves/src/mainApp.cpp

CMakeFiles/Aves.dir/src/mainApp.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/Aves.dir/src/mainApp.cpp.i"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/ziusudra/Desktop/aves/src/mainApp.cpp > CMakeFiles/Aves.dir/src/mainApp.cpp.i

CMakeFiles/Aves.dir/src/mainApp.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/Aves.dir/src/mainApp.cpp.s"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/ziusudra/Desktop/aves/src/mainApp.cpp -o CMakeFiles/Aves.dir/src/mainApp.cpp.s

CMakeFiles/Aves.dir/src/mainApp.cpp.o.requires:

.PHONY : CMakeFiles/Aves.dir/src/mainApp.cpp.o.requires

CMakeFiles/Aves.dir/src/mainApp.cpp.o.provides: CMakeFiles/Aves.dir/src/mainApp.cpp.o.requires
	$(MAKE) -f CMakeFiles/Aves.dir/build.make CMakeFiles/Aves.dir/src/mainApp.cpp.o.provides.build
.PHONY : CMakeFiles/Aves.dir/src/mainApp.cpp.o.provides

CMakeFiles/Aves.dir/src/mainApp.cpp.o.provides.build: CMakeFiles/Aves.dir/src/mainApp.cpp.o


# Object files for target Aves
Aves_OBJECTS = \
"CMakeFiles/Aves.dir/src/World.cpp.o" \
"CMakeFiles/Aves.dir/src/Ave.cpp.o" \
"CMakeFiles/Aves.dir/src/mainApp.cpp.o"

# External object files for target Aves
Aves_EXTERNAL_OBJECTS =

Aves: CMakeFiles/Aves.dir/src/World.cpp.o
Aves: CMakeFiles/Aves.dir/src/Ave.cpp.o
Aves: CMakeFiles/Aves.dir/src/mainApp.cpp.o
Aves: CMakeFiles/Aves.dir/build.make
Aves: /usr/local/lib/libopencv_highgui.so.4.5.1
Aves: /usr/local/lib/libopencv_objdetect.so.4.5.1
Aves: /usr/local/lib/libopencv_stitching.so.4.5.1
Aves: /usr/local/lib/libopencv_ml.so.4.5.1
Aves: /usr/local/lib/libopencv_gapi.so.4.5.1
Aves: /usr/local/lib/libopencv_photo.so.4.5.1
Aves: /usr/local/lib/libopencv_videoio.so.4.5.1
Aves: /usr/local/lib/libopencv_imgcodecs.so.4.5.1
Aves: /usr/local/lib/libopencv_video.so.4.5.1
Aves: /usr/local/lib/libopencv_dnn.so.4.5.1
Aves: /usr/local/lib/libopencv_calib3d.so.4.5.1
Aves: /usr/local/lib/libopencv_features2d.so.4.5.1
Aves: /usr/local/lib/libopencv_flann.so.4.5.1
Aves: /usr/local/lib/libopencv_imgproc.so.4.5.1
Aves: /usr/local/lib/libopencv_core.so.4.5.1
Aves: CMakeFiles/Aves.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/ziusudra/Desktop/aves/CMakeFiles --progress-num=$(CMAKE_PROGRESS_4) "Linking CXX executable Aves"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/Aves.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/Aves.dir/build: Aves

.PHONY : CMakeFiles/Aves.dir/build

CMakeFiles/Aves.dir/requires: CMakeFiles/Aves.dir/src/World.cpp.o.requires
CMakeFiles/Aves.dir/requires: CMakeFiles/Aves.dir/src/Ave.cpp.o.requires
CMakeFiles/Aves.dir/requires: CMakeFiles/Aves.dir/src/mainApp.cpp.o.requires

.PHONY : CMakeFiles/Aves.dir/requires

CMakeFiles/Aves.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/Aves.dir/cmake_clean.cmake
.PHONY : CMakeFiles/Aves.dir/clean

CMakeFiles/Aves.dir/depend:
	cd /home/ziusudra/Desktop/aves && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/ziusudra/Desktop/aves /home/ziusudra/Desktop/aves /home/ziusudra/Desktop/aves /home/ziusudra/Desktop/aves /home/ziusudra/Desktop/aves/CMakeFiles/Aves.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/Aves.dir/depend
