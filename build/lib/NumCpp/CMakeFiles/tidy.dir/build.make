# CMAKE generated file: DO NOT EDIT!
# Generated by "MinGW Makefiles" Generator, CMake Version 3.27

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
CMAKE_COMMAND = C:\msys64\mingw64\CMake\bin\cmake.exe

# The command to remove a file.
RM = C:\msys64\mingw64\CMake\bin\cmake.exe -E rm -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = C:\Users\defga\OneDrive\Documents\GitHub\AIs-with-Grenade-Launchers-Fight

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = C:\Users\defga\OneDrive\Documents\GitHub\AIs-with-Grenade-Launchers-Fight\build

# Utility rule file for tidy.

# Include any custom commands dependencies for this target.
include lib/NumCpp/CMakeFiles/tidy.dir/compiler_depend.make

# Include the progress variables for this target.
include lib/NumCpp/CMakeFiles/tidy.dir/progress.make

lib/NumCpp/CMakeFiles/tidy:
	cd /d C:\Users\defga\OneDrive\Documents\GitHub\AIs-with-Grenade-Launchers-Fight\build\lib\NumCpp && run-clang-tidy -p C:/Users/defga/OneDrive/Documents/GitHub/AIs-with-Grenade-Launchers-Fight/build -extra-arg=-std=c++17

tidy: lib/NumCpp/CMakeFiles/tidy
tidy: lib/NumCpp/CMakeFiles/tidy.dir/build.make
.PHONY : tidy

# Rule to build all files generated by this target.
lib/NumCpp/CMakeFiles/tidy.dir/build: tidy
.PHONY : lib/NumCpp/CMakeFiles/tidy.dir/build

lib/NumCpp/CMakeFiles/tidy.dir/clean:
	cd /d C:\Users\defga\OneDrive\Documents\GitHub\AIs-with-Grenade-Launchers-Fight\build\lib\NumCpp && $(CMAKE_COMMAND) -P CMakeFiles\tidy.dir\cmake_clean.cmake
.PHONY : lib/NumCpp/CMakeFiles/tidy.dir/clean

lib/NumCpp/CMakeFiles/tidy.dir/depend:
	$(CMAKE_COMMAND) -E cmake_depends "MinGW Makefiles" C:\Users\defga\OneDrive\Documents\GitHub\AIs-with-Grenade-Launchers-Fight C:\Users\defga\OneDrive\Documents\GitHub\AIs-with-Grenade-Launchers-Fight\lib\NumCpp C:\Users\defga\OneDrive\Documents\GitHub\AIs-with-Grenade-Launchers-Fight\build C:\Users\defga\OneDrive\Documents\GitHub\AIs-with-Grenade-Launchers-Fight\build\lib\NumCpp C:\Users\defga\OneDrive\Documents\GitHub\AIs-with-Grenade-Launchers-Fight\build\lib\NumCpp\CMakeFiles\tidy.dir\DependInfo.cmake "--color=$(COLOR)"
.PHONY : lib/NumCpp/CMakeFiles/tidy.dir/depend

