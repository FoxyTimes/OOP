# CMAKE generated file: DO NOT EDIT!
# Generated by "MinGW Makefiles" Generator, CMake Version 3.31

# Delete rule output on recipe failure.
.DELETE_ON_ERROR:

#=============================================================================
# Special targets provided by cmake.

# Disable implicit rules so canonical targets will work.
.SUFFIXES:

# Disable VCS-based implicit rules.
% : %,v

# Disable VCS-based implicit rules.
% : RCS/%

# Disable VCS-based implicit rules.
% : RCS/%,v

# Disable VCS-based implicit rules.
% : SCCS/s.%

# Disable VCS-based implicit rules.
% : s.%

.SUFFIXES: .hpux_make_needs_suffix_list

# Command-line flag to silence nested $(MAKE).
$(VERBOSE)MAKESILENT = -s

#Suppress display of executed commands.
$(VERBOSE).SILENT:

# A target that is always out of date.
cmake_force:
.PHONY : cmake_force

#=============================================================================
# Set environment variables for the build.

SHELL = cmd.exe

# The CMake executable.
CMAKE_COMMAND = C:\CMake\bin\cmake.exe

# The command to remove a file.
RM = C:\CMake\bin\cmake.exe -E rm -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = C:\Users\qawwa\CLionProjects\lab3

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = C:\Users\qawwa\CLionProjects\lab3\debug

# Include any dependencies generated for this target.
include test/CMakeFiles/lab3_tst.dir/depend.make
# Include any dependencies generated by the compiler for this target.
include test/CMakeFiles/lab3_tst.dir/compiler_depend.make

# Include the progress variables for this target.
include test/CMakeFiles/lab3_tst.dir/progress.make

# Include the compile flags for this target's objects.
include test/CMakeFiles/lab3_tst.dir/flags.make

test/CMakeFiles/lab3_tst.dir/codegen:
.PHONY : test/CMakeFiles/lab3_tst.dir/codegen

test/CMakeFiles/lab3_tst.dir/ParsersTest.cpp.obj: test/CMakeFiles/lab3_tst.dir/flags.make
test/CMakeFiles/lab3_tst.dir/ParsersTest.cpp.obj: test/CMakeFiles/lab3_tst.dir/includes_CXX.rsp
test/CMakeFiles/lab3_tst.dir/ParsersTest.cpp.obj: C:/Users/qawwa/CLionProjects/lab3/test/ParsersTest.cpp
test/CMakeFiles/lab3_tst.dir/ParsersTest.cpp.obj: test/CMakeFiles/lab3_tst.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --progress-dir=C:\Users\qawwa\CLionProjects\lab3\debug\CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object test/CMakeFiles/lab3_tst.dir/ParsersTest.cpp.obj"
	cd /d C:\Users\qawwa\CLionProjects\lab3\debug\test && C:\MinGW\bin\c++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT test/CMakeFiles/lab3_tst.dir/ParsersTest.cpp.obj -MF CMakeFiles\lab3_tst.dir\ParsersTest.cpp.obj.d -o CMakeFiles\lab3_tst.dir\ParsersTest.cpp.obj -c C:\Users\qawwa\CLionProjects\lab3\test\ParsersTest.cpp

test/CMakeFiles/lab3_tst.dir/ParsersTest.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Preprocessing CXX source to CMakeFiles/lab3_tst.dir/ParsersTest.cpp.i"
	cd /d C:\Users\qawwa\CLionProjects\lab3\debug\test && C:\MinGW\bin\c++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E C:\Users\qawwa\CLionProjects\lab3\test\ParsersTest.cpp > CMakeFiles\lab3_tst.dir\ParsersTest.cpp.i

test/CMakeFiles/lab3_tst.dir/ParsersTest.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Compiling CXX source to assembly CMakeFiles/lab3_tst.dir/ParsersTest.cpp.s"
	cd /d C:\Users\qawwa\CLionProjects\lab3\debug\test && C:\MinGW\bin\c++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S C:\Users\qawwa\CLionProjects\lab3\test\ParsersTest.cpp -o CMakeFiles\lab3_tst.dir\ParsersTest.cpp.s

test/CMakeFiles/lab3_tst.dir/SoundProcTest.cpp.obj: test/CMakeFiles/lab3_tst.dir/flags.make
test/CMakeFiles/lab3_tst.dir/SoundProcTest.cpp.obj: test/CMakeFiles/lab3_tst.dir/includes_CXX.rsp
test/CMakeFiles/lab3_tst.dir/SoundProcTest.cpp.obj: C:/Users/qawwa/CLionProjects/lab3/test/SoundProcTest.cpp
test/CMakeFiles/lab3_tst.dir/SoundProcTest.cpp.obj: test/CMakeFiles/lab3_tst.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --progress-dir=C:\Users\qawwa\CLionProjects\lab3\debug\CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building CXX object test/CMakeFiles/lab3_tst.dir/SoundProcTest.cpp.obj"
	cd /d C:\Users\qawwa\CLionProjects\lab3\debug\test && C:\MinGW\bin\c++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT test/CMakeFiles/lab3_tst.dir/SoundProcTest.cpp.obj -MF CMakeFiles\lab3_tst.dir\SoundProcTest.cpp.obj.d -o CMakeFiles\lab3_tst.dir\SoundProcTest.cpp.obj -c C:\Users\qawwa\CLionProjects\lab3\test\SoundProcTest.cpp

test/CMakeFiles/lab3_tst.dir/SoundProcTest.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Preprocessing CXX source to CMakeFiles/lab3_tst.dir/SoundProcTest.cpp.i"
	cd /d C:\Users\qawwa\CLionProjects\lab3\debug\test && C:\MinGW\bin\c++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E C:\Users\qawwa\CLionProjects\lab3\test\SoundProcTest.cpp > CMakeFiles\lab3_tst.dir\SoundProcTest.cpp.i

test/CMakeFiles/lab3_tst.dir/SoundProcTest.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Compiling CXX source to assembly CMakeFiles/lab3_tst.dir/SoundProcTest.cpp.s"
	cd /d C:\Users\qawwa\CLionProjects\lab3\debug\test && C:\MinGW\bin\c++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S C:\Users\qawwa\CLionProjects\lab3\test\SoundProcTest.cpp -o CMakeFiles\lab3_tst.dir\SoundProcTest.cpp.s

# Object files for target lab3_tst
lab3_tst_OBJECTS = \
"CMakeFiles/lab3_tst.dir/ParsersTest.cpp.obj" \
"CMakeFiles/lab3_tst.dir/SoundProcTest.cpp.obj"

# External object files for target lab3_tst
lab3_tst_EXTERNAL_OBJECTS =

test/lab3_tst.exe: test/CMakeFiles/lab3_tst.dir/ParsersTest.cpp.obj
test/lab3_tst.exe: test/CMakeFiles/lab3_tst.dir/SoundProcTest.cpp.obj
test/lab3_tst.exe: test/CMakeFiles/lab3_tst.dir/build.make
test/lab3_tst.exe: src/liblab3_lib.a
test/lab3_tst.exe: lib/libgtest.a
test/lab3_tst.exe: lib/libgtest_main.a
test/lab3_tst.exe: lib/libgtest.a
test/lab3_tst.exe: test/CMakeFiles/lab3_tst.dir/linkLibs.rsp
test/lab3_tst.exe: test/CMakeFiles/lab3_tst.dir/objects1.rsp
test/lab3_tst.exe: test/CMakeFiles/lab3_tst.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --bold --progress-dir=C:\Users\qawwa\CLionProjects\lab3\debug\CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Linking CXX executable lab3_tst.exe"
	cd /d C:\Users\qawwa\CLionProjects\lab3\debug\test && $(CMAKE_COMMAND) -E cmake_link_script CMakeFiles\lab3_tst.dir\link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
test/CMakeFiles/lab3_tst.dir/build: test/lab3_tst.exe
.PHONY : test/CMakeFiles/lab3_tst.dir/build

test/CMakeFiles/lab3_tst.dir/clean:
	cd /d C:\Users\qawwa\CLionProjects\lab3\debug\test && $(CMAKE_COMMAND) -P CMakeFiles\lab3_tst.dir\cmake_clean.cmake
.PHONY : test/CMakeFiles/lab3_tst.dir/clean

test/CMakeFiles/lab3_tst.dir/depend:
	$(CMAKE_COMMAND) -E cmake_depends "MinGW Makefiles" C:\Users\qawwa\CLionProjects\lab3 C:\Users\qawwa\CLionProjects\lab3\test C:\Users\qawwa\CLionProjects\lab3\debug C:\Users\qawwa\CLionProjects\lab3\debug\test C:\Users\qawwa\CLionProjects\lab3\debug\test\CMakeFiles\lab3_tst.dir\DependInfo.cmake "--color=$(COLOR)"
.PHONY : test/CMakeFiles/lab3_tst.dir/depend

