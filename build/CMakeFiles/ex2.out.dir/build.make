# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.16

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
CMAKE_SOURCE_DIR = /home/tseela/AP1/ex3

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/tseela/AP1/ex3/build

# Include any dependencies generated for this target.
include CMakeFiles/ex2.out.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/ex2.out.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/ex2.out.dir/flags.make

CMakeFiles/ex2.out.dir/tester2.cpp.o: CMakeFiles/ex2.out.dir/flags.make
CMakeFiles/ex2.out.dir/tester2.cpp.o: ../tester2.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/tseela/AP1/ex3/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/ex2.out.dir/tester2.cpp.o"
	/bin/g++-9  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/ex2.out.dir/tester2.cpp.o -c /home/tseela/AP1/ex3/tester2.cpp

CMakeFiles/ex2.out.dir/tester2.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/ex2.out.dir/tester2.cpp.i"
	/bin/g++-9 $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/tseela/AP1/ex3/tester2.cpp > CMakeFiles/ex2.out.dir/tester2.cpp.i

CMakeFiles/ex2.out.dir/tester2.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/ex2.out.dir/tester2.cpp.s"
	/bin/g++-9 $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/tseela/AP1/ex3/tester2.cpp -o CMakeFiles/ex2.out.dir/tester2.cpp.s

CMakeFiles/ex2.out.dir/src/BMArrayParserToMatrixes.cpp.o: CMakeFiles/ex2.out.dir/flags.make
CMakeFiles/ex2.out.dir/src/BMArrayParserToMatrixes.cpp.o: ../src/BMArrayParserToMatrixes.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/tseela/AP1/ex3/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building CXX object CMakeFiles/ex2.out.dir/src/BMArrayParserToMatrixes.cpp.o"
	/bin/g++-9  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/ex2.out.dir/src/BMArrayParserToMatrixes.cpp.o -c /home/tseela/AP1/ex3/src/BMArrayParserToMatrixes.cpp

CMakeFiles/ex2.out.dir/src/BMArrayParserToMatrixes.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/ex2.out.dir/src/BMArrayParserToMatrixes.cpp.i"
	/bin/g++-9 $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/tseela/AP1/ex3/src/BMArrayParserToMatrixes.cpp > CMakeFiles/ex2.out.dir/src/BMArrayParserToMatrixes.cpp.i

CMakeFiles/ex2.out.dir/src/BMArrayParserToMatrixes.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/ex2.out.dir/src/BMArrayParserToMatrixes.cpp.s"
	/bin/g++-9 $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/tseela/AP1/ex3/src/BMArrayParserToMatrixes.cpp -o CMakeFiles/ex2.out.dir/src/BMArrayParserToMatrixes.cpp.s

CMakeFiles/ex2.out.dir/src/BMArrayWithColorPattle.cpp.o: CMakeFiles/ex2.out.dir/flags.make
CMakeFiles/ex2.out.dir/src/BMArrayWithColorPattle.cpp.o: ../src/BMArrayWithColorPattle.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/tseela/AP1/ex3/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Building CXX object CMakeFiles/ex2.out.dir/src/BMArrayWithColorPattle.cpp.o"
	/bin/g++-9  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/ex2.out.dir/src/BMArrayWithColorPattle.cpp.o -c /home/tseela/AP1/ex3/src/BMArrayWithColorPattle.cpp

CMakeFiles/ex2.out.dir/src/BMArrayWithColorPattle.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/ex2.out.dir/src/BMArrayWithColorPattle.cpp.i"
	/bin/g++-9 $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/tseela/AP1/ex3/src/BMArrayWithColorPattle.cpp > CMakeFiles/ex2.out.dir/src/BMArrayWithColorPattle.cpp.i

CMakeFiles/ex2.out.dir/src/BMArrayWithColorPattle.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/ex2.out.dir/src/BMArrayWithColorPattle.cpp.s"
	/bin/g++-9 $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/tseela/AP1/ex3/src/BMArrayWithColorPattle.cpp -o CMakeFiles/ex2.out.dir/src/BMArrayWithColorPattle.cpp.s

CMakeFiles/ex2.out.dir/src/BMPHeaderParser.cpp.o: CMakeFiles/ex2.out.dir/flags.make
CMakeFiles/ex2.out.dir/src/BMPHeaderParser.cpp.o: ../src/BMPHeaderParser.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/tseela/AP1/ex3/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_4) "Building CXX object CMakeFiles/ex2.out.dir/src/BMPHeaderParser.cpp.o"
	/bin/g++-9  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/ex2.out.dir/src/BMPHeaderParser.cpp.o -c /home/tseela/AP1/ex3/src/BMPHeaderParser.cpp

CMakeFiles/ex2.out.dir/src/BMPHeaderParser.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/ex2.out.dir/src/BMPHeaderParser.cpp.i"
	/bin/g++-9 $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/tseela/AP1/ex3/src/BMPHeaderParser.cpp > CMakeFiles/ex2.out.dir/src/BMPHeaderParser.cpp.i

CMakeFiles/ex2.out.dir/src/BMPHeaderParser.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/ex2.out.dir/src/BMPHeaderParser.cpp.s"
	/bin/g++-9 $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/tseela/AP1/ex3/src/BMPHeaderParser.cpp -o CMakeFiles/ex2.out.dir/src/BMPHeaderParser.cpp.s

CMakeFiles/ex2.out.dir/src/BMPParser.cpp.o: CMakeFiles/ex2.out.dir/flags.make
CMakeFiles/ex2.out.dir/src/BMPParser.cpp.o: ../src/BMPParser.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/tseela/AP1/ex3/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_5) "Building CXX object CMakeFiles/ex2.out.dir/src/BMPParser.cpp.o"
	/bin/g++-9  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/ex2.out.dir/src/BMPParser.cpp.o -c /home/tseela/AP1/ex3/src/BMPParser.cpp

CMakeFiles/ex2.out.dir/src/BMPParser.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/ex2.out.dir/src/BMPParser.cpp.i"
	/bin/g++-9 $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/tseela/AP1/ex3/src/BMPParser.cpp > CMakeFiles/ex2.out.dir/src/BMPParser.cpp.i

CMakeFiles/ex2.out.dir/src/BMPParser.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/ex2.out.dir/src/BMPParser.cpp.s"
	/bin/g++-9 $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/tseela/AP1/ex3/src/BMPParser.cpp -o CMakeFiles/ex2.out.dir/src/BMPParser.cpp.s

CMakeFiles/ex2.out.dir/src/CacheManager.cpp.o: CMakeFiles/ex2.out.dir/flags.make
CMakeFiles/ex2.out.dir/src/CacheManager.cpp.o: ../src/CacheManager.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/tseela/AP1/ex3/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_6) "Building CXX object CMakeFiles/ex2.out.dir/src/CacheManager.cpp.o"
	/bin/g++-9  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/ex2.out.dir/src/CacheManager.cpp.o -c /home/tseela/AP1/ex3/src/CacheManager.cpp

CMakeFiles/ex2.out.dir/src/CacheManager.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/ex2.out.dir/src/CacheManager.cpp.i"
	/bin/g++-9 $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/tseela/AP1/ex3/src/CacheManager.cpp > CMakeFiles/ex2.out.dir/src/CacheManager.cpp.i

CMakeFiles/ex2.out.dir/src/CacheManager.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/ex2.out.dir/src/CacheManager.cpp.s"
	/bin/g++-9 $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/tseela/AP1/ex3/src/CacheManager.cpp -o CMakeFiles/ex2.out.dir/src/CacheManager.cpp.s

CMakeFiles/ex2.out.dir/src/CacheOperation.cpp.o: CMakeFiles/ex2.out.dir/flags.make
CMakeFiles/ex2.out.dir/src/CacheOperation.cpp.o: ../src/CacheOperation.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/tseela/AP1/ex3/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_7) "Building CXX object CMakeFiles/ex2.out.dir/src/CacheOperation.cpp.o"
	/bin/g++-9  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/ex2.out.dir/src/CacheOperation.cpp.o -c /home/tseela/AP1/ex3/src/CacheOperation.cpp

CMakeFiles/ex2.out.dir/src/CacheOperation.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/ex2.out.dir/src/CacheOperation.cpp.i"
	/bin/g++-9 $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/tseela/AP1/ex3/src/CacheOperation.cpp > CMakeFiles/ex2.out.dir/src/CacheOperation.cpp.i

CMakeFiles/ex2.out.dir/src/CacheOperation.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/ex2.out.dir/src/CacheOperation.cpp.s"
	/bin/g++-9 $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/tseela/AP1/ex3/src/CacheOperation.cpp -o CMakeFiles/ex2.out.dir/src/CacheOperation.cpp.s

CMakeFiles/ex2.out.dir/src/Color.cpp.o: CMakeFiles/ex2.out.dir/flags.make
CMakeFiles/ex2.out.dir/src/Color.cpp.o: ../src/Color.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/tseela/AP1/ex3/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_8) "Building CXX object CMakeFiles/ex2.out.dir/src/Color.cpp.o"
	/bin/g++-9  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/ex2.out.dir/src/Color.cpp.o -c /home/tseela/AP1/ex3/src/Color.cpp

CMakeFiles/ex2.out.dir/src/Color.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/ex2.out.dir/src/Color.cpp.i"
	/bin/g++-9 $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/tseela/AP1/ex3/src/Color.cpp > CMakeFiles/ex2.out.dir/src/Color.cpp.i

CMakeFiles/ex2.out.dir/src/Color.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/ex2.out.dir/src/Color.cpp.s"
	/bin/g++-9 $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/tseela/AP1/ex3/src/Color.cpp -o CMakeFiles/ex2.out.dir/src/Color.cpp.s

CMakeFiles/ex2.out.dir/src/ColorTableParser.cpp.o: CMakeFiles/ex2.out.dir/flags.make
CMakeFiles/ex2.out.dir/src/ColorTableParser.cpp.o: ../src/ColorTableParser.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/tseela/AP1/ex3/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_9) "Building CXX object CMakeFiles/ex2.out.dir/src/ColorTableParser.cpp.o"
	/bin/g++-9  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/ex2.out.dir/src/ColorTableParser.cpp.o -c /home/tseela/AP1/ex3/src/ColorTableParser.cpp

CMakeFiles/ex2.out.dir/src/ColorTableParser.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/ex2.out.dir/src/ColorTableParser.cpp.i"
	/bin/g++-9 $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/tseela/AP1/ex3/src/ColorTableParser.cpp > CMakeFiles/ex2.out.dir/src/ColorTableParser.cpp.i

CMakeFiles/ex2.out.dir/src/ColorTableParser.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/ex2.out.dir/src/ColorTableParser.cpp.s"
	/bin/g++-9 $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/tseela/AP1/ex3/src/ColorTableParser.cpp -o CMakeFiles/ex2.out.dir/src/ColorTableParser.cpp.s

CMakeFiles/ex2.out.dir/src/CurrentTime.cpp.o: CMakeFiles/ex2.out.dir/flags.make
CMakeFiles/ex2.out.dir/src/CurrentTime.cpp.o: ../src/CurrentTime.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/tseela/AP1/ex3/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_10) "Building CXX object CMakeFiles/ex2.out.dir/src/CurrentTime.cpp.o"
	/bin/g++-9  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/ex2.out.dir/src/CurrentTime.cpp.o -c /home/tseela/AP1/ex3/src/CurrentTime.cpp

CMakeFiles/ex2.out.dir/src/CurrentTime.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/ex2.out.dir/src/CurrentTime.cpp.i"
	/bin/g++-9 $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/tseela/AP1/ex3/src/CurrentTime.cpp > CMakeFiles/ex2.out.dir/src/CurrentTime.cpp.i

CMakeFiles/ex2.out.dir/src/CurrentTime.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/ex2.out.dir/src/CurrentTime.cpp.s"
	/bin/g++-9 $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/tseela/AP1/ex3/src/CurrentTime.cpp -o CMakeFiles/ex2.out.dir/src/CurrentTime.cpp.s

CMakeFiles/ex2.out.dir/src/DIBHeaderParser.cpp.o: CMakeFiles/ex2.out.dir/flags.make
CMakeFiles/ex2.out.dir/src/DIBHeaderParser.cpp.o: ../src/DIBHeaderParser.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/tseela/AP1/ex3/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_11) "Building CXX object CMakeFiles/ex2.out.dir/src/DIBHeaderParser.cpp.o"
	/bin/g++-9  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/ex2.out.dir/src/DIBHeaderParser.cpp.o -c /home/tseela/AP1/ex3/src/DIBHeaderParser.cpp

CMakeFiles/ex2.out.dir/src/DIBHeaderParser.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/ex2.out.dir/src/DIBHeaderParser.cpp.i"
	/bin/g++-9 $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/tseela/AP1/ex3/src/DIBHeaderParser.cpp > CMakeFiles/ex2.out.dir/src/DIBHeaderParser.cpp.i

CMakeFiles/ex2.out.dir/src/DIBHeaderParser.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/ex2.out.dir/src/DIBHeaderParser.cpp.s"
	/bin/g++-9 $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/tseela/AP1/ex3/src/DIBHeaderParser.cpp -o CMakeFiles/ex2.out.dir/src/DIBHeaderParser.cpp.s

CMakeFiles/ex2.out.dir/src/ErrorCodeException.cpp.o: CMakeFiles/ex2.out.dir/flags.make
CMakeFiles/ex2.out.dir/src/ErrorCodeException.cpp.o: ../src/ErrorCodeException.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/tseela/AP1/ex3/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_12) "Building CXX object CMakeFiles/ex2.out.dir/src/ErrorCodeException.cpp.o"
	/bin/g++-9  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/ex2.out.dir/src/ErrorCodeException.cpp.o -c /home/tseela/AP1/ex3/src/ErrorCodeException.cpp

CMakeFiles/ex2.out.dir/src/ErrorCodeException.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/ex2.out.dir/src/ErrorCodeException.cpp.i"
	/bin/g++-9 $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/tseela/AP1/ex3/src/ErrorCodeException.cpp > CMakeFiles/ex2.out.dir/src/ErrorCodeException.cpp.i

CMakeFiles/ex2.out.dir/src/ErrorCodeException.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/ex2.out.dir/src/ErrorCodeException.cpp.s"
	/bin/g++-9 $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/tseela/AP1/ex3/src/ErrorCodeException.cpp -o CMakeFiles/ex2.out.dir/src/ErrorCodeException.cpp.s

CMakeFiles/ex2.out.dir/src/MatrixClass.cpp.o: CMakeFiles/ex2.out.dir/flags.make
CMakeFiles/ex2.out.dir/src/MatrixClass.cpp.o: ../src/MatrixClass.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/tseela/AP1/ex3/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_13) "Building CXX object CMakeFiles/ex2.out.dir/src/MatrixClass.cpp.o"
	/bin/g++-9  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/ex2.out.dir/src/MatrixClass.cpp.o -c /home/tseela/AP1/ex3/src/MatrixClass.cpp

CMakeFiles/ex2.out.dir/src/MatrixClass.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/ex2.out.dir/src/MatrixClass.cpp.i"
	/bin/g++-9 $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/tseela/AP1/ex3/src/MatrixClass.cpp > CMakeFiles/ex2.out.dir/src/MatrixClass.cpp.i

CMakeFiles/ex2.out.dir/src/MatrixClass.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/ex2.out.dir/src/MatrixClass.cpp.s"
	/bin/g++-9 $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/tseela/AP1/ex3/src/MatrixClass.cpp -o CMakeFiles/ex2.out.dir/src/MatrixClass.cpp.s

CMakeFiles/ex2.out.dir/src/bmp_tester.cpp.o: CMakeFiles/ex2.out.dir/flags.make
CMakeFiles/ex2.out.dir/src/bmp_tester.cpp.o: ../src/bmp_tester.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/tseela/AP1/ex3/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_14) "Building CXX object CMakeFiles/ex2.out.dir/src/bmp_tester.cpp.o"
	/bin/g++-9  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/ex2.out.dir/src/bmp_tester.cpp.o -c /home/tseela/AP1/ex3/src/bmp_tester.cpp

CMakeFiles/ex2.out.dir/src/bmp_tester.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/ex2.out.dir/src/bmp_tester.cpp.i"
	/bin/g++-9 $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/tseela/AP1/ex3/src/bmp_tester.cpp > CMakeFiles/ex2.out.dir/src/bmp_tester.cpp.i

CMakeFiles/ex2.out.dir/src/bmp_tester.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/ex2.out.dir/src/bmp_tester.cpp.s"
	/bin/g++-9 $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/tseela/AP1/ex3/src/bmp_tester.cpp -o CMakeFiles/ex2.out.dir/src/bmp_tester.cpp.s

CMakeFiles/ex2.out.dir/src/crc32.cpp.o: CMakeFiles/ex2.out.dir/flags.make
CMakeFiles/ex2.out.dir/src/crc32.cpp.o: ../src/crc32.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/tseela/AP1/ex3/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_15) "Building CXX object CMakeFiles/ex2.out.dir/src/crc32.cpp.o"
	/bin/g++-9  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/ex2.out.dir/src/crc32.cpp.o -c /home/tseela/AP1/ex3/src/crc32.cpp

CMakeFiles/ex2.out.dir/src/crc32.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/ex2.out.dir/src/crc32.cpp.i"
	/bin/g++-9 $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/tseela/AP1/ex3/src/crc32.cpp > CMakeFiles/ex2.out.dir/src/crc32.cpp.i

CMakeFiles/ex2.out.dir/src/crc32.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/ex2.out.dir/src/crc32.cpp.s"
	/bin/g++-9 $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/tseela/AP1/ex3/src/crc32.cpp -o CMakeFiles/ex2.out.dir/src/crc32.cpp.s

CMakeFiles/ex2.out.dir/src/crc32FileReader.cpp.o: CMakeFiles/ex2.out.dir/flags.make
CMakeFiles/ex2.out.dir/src/crc32FileReader.cpp.o: ../src/crc32FileReader.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/tseela/AP1/ex3/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_16) "Building CXX object CMakeFiles/ex2.out.dir/src/crc32FileReader.cpp.o"
	/bin/g++-9  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/ex2.out.dir/src/crc32FileReader.cpp.o -c /home/tseela/AP1/ex3/src/crc32FileReader.cpp

CMakeFiles/ex2.out.dir/src/crc32FileReader.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/ex2.out.dir/src/crc32FileReader.cpp.i"
	/bin/g++-9 $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/tseela/AP1/ex3/src/crc32FileReader.cpp > CMakeFiles/ex2.out.dir/src/crc32FileReader.cpp.i

CMakeFiles/ex2.out.dir/src/crc32FileReader.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/ex2.out.dir/src/crc32FileReader.cpp.s"
	/bin/g++-9 $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/tseela/AP1/ex3/src/crc32FileReader.cpp -o CMakeFiles/ex2.out.dir/src/crc32FileReader.cpp.s

CMakeFiles/ex2.out.dir/src/file_reading.cpp.o: CMakeFiles/ex2.out.dir/flags.make
CMakeFiles/ex2.out.dir/src/file_reading.cpp.o: ../src/file_reading.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/tseela/AP1/ex3/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_17) "Building CXX object CMakeFiles/ex2.out.dir/src/file_reading.cpp.o"
	/bin/g++-9  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/ex2.out.dir/src/file_reading.cpp.o -c /home/tseela/AP1/ex3/src/file_reading.cpp

CMakeFiles/ex2.out.dir/src/file_reading.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/ex2.out.dir/src/file_reading.cpp.i"
	/bin/g++-9 $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/tseela/AP1/ex3/src/file_reading.cpp > CMakeFiles/ex2.out.dir/src/file_reading.cpp.i

CMakeFiles/ex2.out.dir/src/file_reading.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/ex2.out.dir/src/file_reading.cpp.s"
	/bin/g++-9 $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/tseela/AP1/ex3/src/file_reading.cpp -o CMakeFiles/ex2.out.dir/src/file_reading.cpp.s

# Object files for target ex2.out
ex2_out_OBJECTS = \
"CMakeFiles/ex2.out.dir/tester2.cpp.o" \
"CMakeFiles/ex2.out.dir/src/BMArrayParserToMatrixes.cpp.o" \
"CMakeFiles/ex2.out.dir/src/BMArrayWithColorPattle.cpp.o" \
"CMakeFiles/ex2.out.dir/src/BMPHeaderParser.cpp.o" \
"CMakeFiles/ex2.out.dir/src/BMPParser.cpp.o" \
"CMakeFiles/ex2.out.dir/src/CacheManager.cpp.o" \
"CMakeFiles/ex2.out.dir/src/CacheOperation.cpp.o" \
"CMakeFiles/ex2.out.dir/src/Color.cpp.o" \
"CMakeFiles/ex2.out.dir/src/ColorTableParser.cpp.o" \
"CMakeFiles/ex2.out.dir/src/CurrentTime.cpp.o" \
"CMakeFiles/ex2.out.dir/src/DIBHeaderParser.cpp.o" \
"CMakeFiles/ex2.out.dir/src/ErrorCodeException.cpp.o" \
"CMakeFiles/ex2.out.dir/src/MatrixClass.cpp.o" \
"CMakeFiles/ex2.out.dir/src/bmp_tester.cpp.o" \
"CMakeFiles/ex2.out.dir/src/crc32.cpp.o" \
"CMakeFiles/ex2.out.dir/src/crc32FileReader.cpp.o" \
"CMakeFiles/ex2.out.dir/src/file_reading.cpp.o"

# External object files for target ex2.out
ex2_out_EXTERNAL_OBJECTS =

../src/bin/ex2.out: CMakeFiles/ex2.out.dir/tester2.cpp.o
../src/bin/ex2.out: CMakeFiles/ex2.out.dir/src/BMArrayParserToMatrixes.cpp.o
../src/bin/ex2.out: CMakeFiles/ex2.out.dir/src/BMArrayWithColorPattle.cpp.o
../src/bin/ex2.out: CMakeFiles/ex2.out.dir/src/BMPHeaderParser.cpp.o
../src/bin/ex2.out: CMakeFiles/ex2.out.dir/src/BMPParser.cpp.o
../src/bin/ex2.out: CMakeFiles/ex2.out.dir/src/CacheManager.cpp.o
../src/bin/ex2.out: CMakeFiles/ex2.out.dir/src/CacheOperation.cpp.o
../src/bin/ex2.out: CMakeFiles/ex2.out.dir/src/Color.cpp.o
../src/bin/ex2.out: CMakeFiles/ex2.out.dir/src/ColorTableParser.cpp.o
../src/bin/ex2.out: CMakeFiles/ex2.out.dir/src/CurrentTime.cpp.o
../src/bin/ex2.out: CMakeFiles/ex2.out.dir/src/DIBHeaderParser.cpp.o
../src/bin/ex2.out: CMakeFiles/ex2.out.dir/src/ErrorCodeException.cpp.o
../src/bin/ex2.out: CMakeFiles/ex2.out.dir/src/MatrixClass.cpp.o
../src/bin/ex2.out: CMakeFiles/ex2.out.dir/src/bmp_tester.cpp.o
../src/bin/ex2.out: CMakeFiles/ex2.out.dir/src/crc32.cpp.o
../src/bin/ex2.out: CMakeFiles/ex2.out.dir/src/crc32FileReader.cpp.o
../src/bin/ex2.out: CMakeFiles/ex2.out.dir/src/file_reading.cpp.o
../src/bin/ex2.out: CMakeFiles/ex2.out.dir/build.make
../src/bin/ex2.out: CMakeFiles/ex2.out.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/tseela/AP1/ex3/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_18) "Linking CXX executable ../src/bin/ex2.out"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/ex2.out.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/ex2.out.dir/build: ../src/bin/ex2.out

.PHONY : CMakeFiles/ex2.out.dir/build

CMakeFiles/ex2.out.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/ex2.out.dir/cmake_clean.cmake
.PHONY : CMakeFiles/ex2.out.dir/clean

CMakeFiles/ex2.out.dir/depend:
	cd /home/tseela/AP1/ex3/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/tseela/AP1/ex3 /home/tseela/AP1/ex3 /home/tseela/AP1/ex3/build /home/tseela/AP1/ex3/build /home/tseela/AP1/ex3/build/CMakeFiles/ex2.out.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/ex2.out.dir/depend

