# CMAKE generated file: DO NOT EDIT!
# Generated by "MinGW Makefiles" Generator, CMake Version 3.13

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

SHELL = cmd.exe

# The CMake executable.
CMAKE_COMMAND = F:\IDEA\Clion\bin\cmake\win\bin\cmake.exe

# The command to remove a file.
RM = F:\IDEA\Clion\bin\cmake\win\bin\cmake.exe -E remove -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = F:\IDEA\CCode\x86ToMips

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = F:\IDEA\CCode\x86ToMips\cmake-build-debug

# Include any dependencies generated for this target.
include CMakeFiles/x86ToMips.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/x86ToMips.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/x86ToMips.dir/flags.make

CMakeFiles/x86ToMips.dir/code/main.cpp.obj: CMakeFiles/x86ToMips.dir/flags.make
CMakeFiles/x86ToMips.dir/code/main.cpp.obj: ../code/main.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=F:\IDEA\CCode\x86ToMips\cmake-build-debug\CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/x86ToMips.dir/code/main.cpp.obj"
	F:\Dev-Cpp_gr\Dev-Cpp\MinGW64\bin\g++.exe  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles\x86ToMips.dir\code\main.cpp.obj -c F:\IDEA\CCode\x86ToMips\code\main.cpp

CMakeFiles/x86ToMips.dir/code/main.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/x86ToMips.dir/code/main.cpp.i"
	F:\Dev-Cpp_gr\Dev-Cpp\MinGW64\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E F:\IDEA\CCode\x86ToMips\code\main.cpp > CMakeFiles\x86ToMips.dir\code\main.cpp.i

CMakeFiles/x86ToMips.dir/code/main.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/x86ToMips.dir/code/main.cpp.s"
	F:\Dev-Cpp_gr\Dev-Cpp\MinGW64\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S F:\IDEA\CCode\x86ToMips\code\main.cpp -o CMakeFiles\x86ToMips.dir\code\main.cpp.s

# Object files for target x86ToMips
x86ToMips_OBJECTS = \
"CMakeFiles/x86ToMips.dir/code/main.cpp.obj"

# External object files for target x86ToMips
x86ToMips_EXTERNAL_OBJECTS =

x86ToMips.exe: CMakeFiles/x86ToMips.dir/code/main.cpp.obj
x86ToMips.exe: CMakeFiles/x86ToMips.dir/build.make
x86ToMips.exe: CMakeFiles/x86ToMips.dir/linklibs.rsp
x86ToMips.exe: CMakeFiles/x86ToMips.dir/objects1.rsp
x86ToMips.exe: CMakeFiles/x86ToMips.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=F:\IDEA\CCode\x86ToMips\cmake-build-debug\CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable x86ToMips.exe"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles\x86ToMips.dir\link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/x86ToMips.dir/build: x86ToMips.exe

.PHONY : CMakeFiles/x86ToMips.dir/build

CMakeFiles/x86ToMips.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles\x86ToMips.dir\cmake_clean.cmake
.PHONY : CMakeFiles/x86ToMips.dir/clean

CMakeFiles/x86ToMips.dir/depend:
	$(CMAKE_COMMAND) -E cmake_depends "MinGW Makefiles" F:\IDEA\CCode\x86ToMips F:\IDEA\CCode\x86ToMips F:\IDEA\CCode\x86ToMips\cmake-build-debug F:\IDEA\CCode\x86ToMips\cmake-build-debug F:\IDEA\CCode\x86ToMips\cmake-build-debug\CMakeFiles\x86ToMips.dir\DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/x86ToMips.dir/depend
