# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.22

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

# The shell in which to execute make rules.
SHELL = /bin/sh

# The CMake executable.
CMAKE_COMMAND = /usr/bin/cmake

# The command to remove a file.
RM = /usr/bin/cmake -E rm -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /home/zahar/IKT/Class-inheritance

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/zahar/IKT/Class-inheritance/build

# Include any dependencies generated for this target.
include CMakeFiles/zoo.dir/depend.make
# Include any dependencies generated by the compiler for this target.
include CMakeFiles/zoo.dir/compiler_depend.make

# Include the progress variables for this target.
include CMakeFiles/zoo.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/zoo.dir/flags.make

CMakeFiles/zoo.dir/Drawer/Drawer.cpp.o: CMakeFiles/zoo.dir/flags.make
CMakeFiles/zoo.dir/Drawer/Drawer.cpp.o: ../Drawer/Drawer.cpp
CMakeFiles/zoo.dir/Drawer/Drawer.cpp.o: CMakeFiles/zoo.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/zahar/IKT/Class-inheritance/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/zoo.dir/Drawer/Drawer.cpp.o"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/zoo.dir/Drawer/Drawer.cpp.o -MF CMakeFiles/zoo.dir/Drawer/Drawer.cpp.o.d -o CMakeFiles/zoo.dir/Drawer/Drawer.cpp.o -c /home/zahar/IKT/Class-inheritance/Drawer/Drawer.cpp

CMakeFiles/zoo.dir/Drawer/Drawer.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/zoo.dir/Drawer/Drawer.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/zahar/IKT/Class-inheritance/Drawer/Drawer.cpp > CMakeFiles/zoo.dir/Drawer/Drawer.cpp.i

CMakeFiles/zoo.dir/Drawer/Drawer.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/zoo.dir/Drawer/Drawer.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/zahar/IKT/Class-inheritance/Drawer/Drawer.cpp -o CMakeFiles/zoo.dir/Drawer/Drawer.cpp.s

CMakeFiles/zoo.dir/Field/Field.cpp.o: CMakeFiles/zoo.dir/flags.make
CMakeFiles/zoo.dir/Field/Field.cpp.o: ../Field/Field.cpp
CMakeFiles/zoo.dir/Field/Field.cpp.o: CMakeFiles/zoo.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/zahar/IKT/Class-inheritance/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building CXX object CMakeFiles/zoo.dir/Field/Field.cpp.o"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/zoo.dir/Field/Field.cpp.o -MF CMakeFiles/zoo.dir/Field/Field.cpp.o.d -o CMakeFiles/zoo.dir/Field/Field.cpp.o -c /home/zahar/IKT/Class-inheritance/Field/Field.cpp

CMakeFiles/zoo.dir/Field/Field.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/zoo.dir/Field/Field.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/zahar/IKT/Class-inheritance/Field/Field.cpp > CMakeFiles/zoo.dir/Field/Field.cpp.i

CMakeFiles/zoo.dir/Field/Field.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/zoo.dir/Field/Field.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/zahar/IKT/Class-inheritance/Field/Field.cpp -o CMakeFiles/zoo.dir/Field/Field.cpp.s

CMakeFiles/zoo.dir/Animals/Animals.cpp.o: CMakeFiles/zoo.dir/flags.make
CMakeFiles/zoo.dir/Animals/Animals.cpp.o: ../Animals/Animals.cpp
CMakeFiles/zoo.dir/Animals/Animals.cpp.o: CMakeFiles/zoo.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/zahar/IKT/Class-inheritance/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Building CXX object CMakeFiles/zoo.dir/Animals/Animals.cpp.o"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/zoo.dir/Animals/Animals.cpp.o -MF CMakeFiles/zoo.dir/Animals/Animals.cpp.o.d -o CMakeFiles/zoo.dir/Animals/Animals.cpp.o -c /home/zahar/IKT/Class-inheritance/Animals/Animals.cpp

CMakeFiles/zoo.dir/Animals/Animals.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/zoo.dir/Animals/Animals.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/zahar/IKT/Class-inheritance/Animals/Animals.cpp > CMakeFiles/zoo.dir/Animals/Animals.cpp.i

CMakeFiles/zoo.dir/Animals/Animals.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/zoo.dir/Animals/Animals.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/zahar/IKT/Class-inheritance/Animals/Animals.cpp -o CMakeFiles/zoo.dir/Animals/Animals.cpp.s

CMakeFiles/zoo.dir/Animals/Cow.cpp.o: CMakeFiles/zoo.dir/flags.make
CMakeFiles/zoo.dir/Animals/Cow.cpp.o: ../Animals/Cow.cpp
CMakeFiles/zoo.dir/Animals/Cow.cpp.o: CMakeFiles/zoo.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/zahar/IKT/Class-inheritance/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_4) "Building CXX object CMakeFiles/zoo.dir/Animals/Cow.cpp.o"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/zoo.dir/Animals/Cow.cpp.o -MF CMakeFiles/zoo.dir/Animals/Cow.cpp.o.d -o CMakeFiles/zoo.dir/Animals/Cow.cpp.o -c /home/zahar/IKT/Class-inheritance/Animals/Cow.cpp

CMakeFiles/zoo.dir/Animals/Cow.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/zoo.dir/Animals/Cow.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/zahar/IKT/Class-inheritance/Animals/Cow.cpp > CMakeFiles/zoo.dir/Animals/Cow.cpp.i

CMakeFiles/zoo.dir/Animals/Cow.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/zoo.dir/Animals/Cow.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/zahar/IKT/Class-inheritance/Animals/Cow.cpp -o CMakeFiles/zoo.dir/Animals/Cow.cpp.s

CMakeFiles/zoo.dir/Animals/Goose.cpp.o: CMakeFiles/zoo.dir/flags.make
CMakeFiles/zoo.dir/Animals/Goose.cpp.o: ../Animals/Goose.cpp
CMakeFiles/zoo.dir/Animals/Goose.cpp.o: CMakeFiles/zoo.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/zahar/IKT/Class-inheritance/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_5) "Building CXX object CMakeFiles/zoo.dir/Animals/Goose.cpp.o"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/zoo.dir/Animals/Goose.cpp.o -MF CMakeFiles/zoo.dir/Animals/Goose.cpp.o.d -o CMakeFiles/zoo.dir/Animals/Goose.cpp.o -c /home/zahar/IKT/Class-inheritance/Animals/Goose.cpp

CMakeFiles/zoo.dir/Animals/Goose.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/zoo.dir/Animals/Goose.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/zahar/IKT/Class-inheritance/Animals/Goose.cpp > CMakeFiles/zoo.dir/Animals/Goose.cpp.i

CMakeFiles/zoo.dir/Animals/Goose.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/zoo.dir/Animals/Goose.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/zahar/IKT/Class-inheritance/Animals/Goose.cpp -o CMakeFiles/zoo.dir/Animals/Goose.cpp.s

CMakeFiles/zoo.dir/Animals/Pig.cpp.o: CMakeFiles/zoo.dir/flags.make
CMakeFiles/zoo.dir/Animals/Pig.cpp.o: ../Animals/Pig.cpp
CMakeFiles/zoo.dir/Animals/Pig.cpp.o: CMakeFiles/zoo.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/zahar/IKT/Class-inheritance/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_6) "Building CXX object CMakeFiles/zoo.dir/Animals/Pig.cpp.o"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/zoo.dir/Animals/Pig.cpp.o -MF CMakeFiles/zoo.dir/Animals/Pig.cpp.o.d -o CMakeFiles/zoo.dir/Animals/Pig.cpp.o -c /home/zahar/IKT/Class-inheritance/Animals/Pig.cpp

CMakeFiles/zoo.dir/Animals/Pig.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/zoo.dir/Animals/Pig.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/zahar/IKT/Class-inheritance/Animals/Pig.cpp > CMakeFiles/zoo.dir/Animals/Pig.cpp.i

CMakeFiles/zoo.dir/Animals/Pig.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/zoo.dir/Animals/Pig.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/zahar/IKT/Class-inheritance/Animals/Pig.cpp -o CMakeFiles/zoo.dir/Animals/Pig.cpp.s

CMakeFiles/zoo.dir/Animals/Wolf.cpp.o: CMakeFiles/zoo.dir/flags.make
CMakeFiles/zoo.dir/Animals/Wolf.cpp.o: ../Animals/Wolf.cpp
CMakeFiles/zoo.dir/Animals/Wolf.cpp.o: CMakeFiles/zoo.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/zahar/IKT/Class-inheritance/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_7) "Building CXX object CMakeFiles/zoo.dir/Animals/Wolf.cpp.o"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/zoo.dir/Animals/Wolf.cpp.o -MF CMakeFiles/zoo.dir/Animals/Wolf.cpp.o.d -o CMakeFiles/zoo.dir/Animals/Wolf.cpp.o -c /home/zahar/IKT/Class-inheritance/Animals/Wolf.cpp

CMakeFiles/zoo.dir/Animals/Wolf.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/zoo.dir/Animals/Wolf.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/zahar/IKT/Class-inheritance/Animals/Wolf.cpp > CMakeFiles/zoo.dir/Animals/Wolf.cpp.i

CMakeFiles/zoo.dir/Animals/Wolf.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/zoo.dir/Animals/Wolf.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/zahar/IKT/Class-inheritance/Animals/Wolf.cpp -o CMakeFiles/zoo.dir/Animals/Wolf.cpp.s

CMakeFiles/zoo.dir/Animals/Boar.cpp.o: CMakeFiles/zoo.dir/flags.make
CMakeFiles/zoo.dir/Animals/Boar.cpp.o: ../Animals/Boar.cpp
CMakeFiles/zoo.dir/Animals/Boar.cpp.o: CMakeFiles/zoo.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/zahar/IKT/Class-inheritance/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_8) "Building CXX object CMakeFiles/zoo.dir/Animals/Boar.cpp.o"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/zoo.dir/Animals/Boar.cpp.o -MF CMakeFiles/zoo.dir/Animals/Boar.cpp.o.d -o CMakeFiles/zoo.dir/Animals/Boar.cpp.o -c /home/zahar/IKT/Class-inheritance/Animals/Boar.cpp

CMakeFiles/zoo.dir/Animals/Boar.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/zoo.dir/Animals/Boar.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/zahar/IKT/Class-inheritance/Animals/Boar.cpp > CMakeFiles/zoo.dir/Animals/Boar.cpp.i

CMakeFiles/zoo.dir/Animals/Boar.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/zoo.dir/Animals/Boar.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/zahar/IKT/Class-inheritance/Animals/Boar.cpp -o CMakeFiles/zoo.dir/Animals/Boar.cpp.s

CMakeFiles/zoo.dir/Animals/Fox.cpp.o: CMakeFiles/zoo.dir/flags.make
CMakeFiles/zoo.dir/Animals/Fox.cpp.o: ../Animals/Fox.cpp
CMakeFiles/zoo.dir/Animals/Fox.cpp.o: CMakeFiles/zoo.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/zahar/IKT/Class-inheritance/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_9) "Building CXX object CMakeFiles/zoo.dir/Animals/Fox.cpp.o"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/zoo.dir/Animals/Fox.cpp.o -MF CMakeFiles/zoo.dir/Animals/Fox.cpp.o.d -o CMakeFiles/zoo.dir/Animals/Fox.cpp.o -c /home/zahar/IKT/Class-inheritance/Animals/Fox.cpp

CMakeFiles/zoo.dir/Animals/Fox.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/zoo.dir/Animals/Fox.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/zahar/IKT/Class-inheritance/Animals/Fox.cpp > CMakeFiles/zoo.dir/Animals/Fox.cpp.i

CMakeFiles/zoo.dir/Animals/Fox.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/zoo.dir/Animals/Fox.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/zahar/IKT/Class-inheritance/Animals/Fox.cpp -o CMakeFiles/zoo.dir/Animals/Fox.cpp.s

CMakeFiles/zoo.dir/Animals/Gorilla.cpp.o: CMakeFiles/zoo.dir/flags.make
CMakeFiles/zoo.dir/Animals/Gorilla.cpp.o: ../Animals/Gorilla.cpp
CMakeFiles/zoo.dir/Animals/Gorilla.cpp.o: CMakeFiles/zoo.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/zahar/IKT/Class-inheritance/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_10) "Building CXX object CMakeFiles/zoo.dir/Animals/Gorilla.cpp.o"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/zoo.dir/Animals/Gorilla.cpp.o -MF CMakeFiles/zoo.dir/Animals/Gorilla.cpp.o.d -o CMakeFiles/zoo.dir/Animals/Gorilla.cpp.o -c /home/zahar/IKT/Class-inheritance/Animals/Gorilla.cpp

CMakeFiles/zoo.dir/Animals/Gorilla.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/zoo.dir/Animals/Gorilla.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/zahar/IKT/Class-inheritance/Animals/Gorilla.cpp > CMakeFiles/zoo.dir/Animals/Gorilla.cpp.i

CMakeFiles/zoo.dir/Animals/Gorilla.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/zoo.dir/Animals/Gorilla.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/zahar/IKT/Class-inheritance/Animals/Gorilla.cpp -o CMakeFiles/zoo.dir/Animals/Gorilla.cpp.s

CMakeFiles/zoo.dir/Animals/Sheep.cpp.o: CMakeFiles/zoo.dir/flags.make
CMakeFiles/zoo.dir/Animals/Sheep.cpp.o: ../Animals/Sheep.cpp
CMakeFiles/zoo.dir/Animals/Sheep.cpp.o: CMakeFiles/zoo.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/zahar/IKT/Class-inheritance/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_11) "Building CXX object CMakeFiles/zoo.dir/Animals/Sheep.cpp.o"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/zoo.dir/Animals/Sheep.cpp.o -MF CMakeFiles/zoo.dir/Animals/Sheep.cpp.o.d -o CMakeFiles/zoo.dir/Animals/Sheep.cpp.o -c /home/zahar/IKT/Class-inheritance/Animals/Sheep.cpp

CMakeFiles/zoo.dir/Animals/Sheep.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/zoo.dir/Animals/Sheep.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/zahar/IKT/Class-inheritance/Animals/Sheep.cpp > CMakeFiles/zoo.dir/Animals/Sheep.cpp.i

CMakeFiles/zoo.dir/Animals/Sheep.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/zoo.dir/Animals/Sheep.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/zahar/IKT/Class-inheritance/Animals/Sheep.cpp -o CMakeFiles/zoo.dir/Animals/Sheep.cpp.s

CMakeFiles/zoo.dir/main.cpp.o: CMakeFiles/zoo.dir/flags.make
CMakeFiles/zoo.dir/main.cpp.o: ../main.cpp
CMakeFiles/zoo.dir/main.cpp.o: CMakeFiles/zoo.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/zahar/IKT/Class-inheritance/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_12) "Building CXX object CMakeFiles/zoo.dir/main.cpp.o"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/zoo.dir/main.cpp.o -MF CMakeFiles/zoo.dir/main.cpp.o.d -o CMakeFiles/zoo.dir/main.cpp.o -c /home/zahar/IKT/Class-inheritance/main.cpp

CMakeFiles/zoo.dir/main.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/zoo.dir/main.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/zahar/IKT/Class-inheritance/main.cpp > CMakeFiles/zoo.dir/main.cpp.i

CMakeFiles/zoo.dir/main.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/zoo.dir/main.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/zahar/IKT/Class-inheritance/main.cpp -o CMakeFiles/zoo.dir/main.cpp.s

# Object files for target zoo
zoo_OBJECTS = \
"CMakeFiles/zoo.dir/Drawer/Drawer.cpp.o" \
"CMakeFiles/zoo.dir/Field/Field.cpp.o" \
"CMakeFiles/zoo.dir/Animals/Animals.cpp.o" \
"CMakeFiles/zoo.dir/Animals/Cow.cpp.o" \
"CMakeFiles/zoo.dir/Animals/Goose.cpp.o" \
"CMakeFiles/zoo.dir/Animals/Pig.cpp.o" \
"CMakeFiles/zoo.dir/Animals/Wolf.cpp.o" \
"CMakeFiles/zoo.dir/Animals/Boar.cpp.o" \
"CMakeFiles/zoo.dir/Animals/Fox.cpp.o" \
"CMakeFiles/zoo.dir/Animals/Gorilla.cpp.o" \
"CMakeFiles/zoo.dir/Animals/Sheep.cpp.o" \
"CMakeFiles/zoo.dir/main.cpp.o"

# External object files for target zoo
zoo_EXTERNAL_OBJECTS =

zoo: CMakeFiles/zoo.dir/Drawer/Drawer.cpp.o
zoo: CMakeFiles/zoo.dir/Field/Field.cpp.o
zoo: CMakeFiles/zoo.dir/Animals/Animals.cpp.o
zoo: CMakeFiles/zoo.dir/Animals/Cow.cpp.o
zoo: CMakeFiles/zoo.dir/Animals/Goose.cpp.o
zoo: CMakeFiles/zoo.dir/Animals/Pig.cpp.o
zoo: CMakeFiles/zoo.dir/Animals/Wolf.cpp.o
zoo: CMakeFiles/zoo.dir/Animals/Boar.cpp.o
zoo: CMakeFiles/zoo.dir/Animals/Fox.cpp.o
zoo: CMakeFiles/zoo.dir/Animals/Gorilla.cpp.o
zoo: CMakeFiles/zoo.dir/Animals/Sheep.cpp.o
zoo: CMakeFiles/zoo.dir/main.cpp.o
zoo: CMakeFiles/zoo.dir/build.make
zoo: ../SFML-2.6.1/lib/libsfml-window-d.so.2.6.1
zoo: CMakeFiles/zoo.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/zahar/IKT/Class-inheritance/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_13) "Linking CXX executable zoo"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/zoo.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/zoo.dir/build: zoo
.PHONY : CMakeFiles/zoo.dir/build

CMakeFiles/zoo.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/zoo.dir/cmake_clean.cmake
.PHONY : CMakeFiles/zoo.dir/clean

CMakeFiles/zoo.dir/depend:
	cd /home/zahar/IKT/Class-inheritance/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/zahar/IKT/Class-inheritance /home/zahar/IKT/Class-inheritance /home/zahar/IKT/Class-inheritance/build /home/zahar/IKT/Class-inheritance/build /home/zahar/IKT/Class-inheritance/build/CMakeFiles/zoo.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/zoo.dir/depend

