# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.5

# Default target executed when no arguments are given to make.
default_target: all

.PHONY : default_target

# Allow only one "make -f Makefile2" at a time, but pass parallelism.
.NOTPARALLEL:


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
CMAKE_SOURCE_DIR = /home/zjl/code/liso

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/zjl/code/liso

#=============================================================================
# Targets provided globally by CMake.

# Special rule for the target edit_cache
edit_cache:
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --cyan "No interactive CMake dialog available..."
	/usr/bin/cmake -E echo No\ interactive\ CMake\ dialog\ available.
.PHONY : edit_cache

# Special rule for the target edit_cache
edit_cache/fast: edit_cache

.PHONY : edit_cache/fast

# Special rule for the target rebuild_cache
rebuild_cache:
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --cyan "Running CMake to regenerate build system..."
	/usr/bin/cmake -H$(CMAKE_SOURCE_DIR) -B$(CMAKE_BINARY_DIR)
.PHONY : rebuild_cache

# Special rule for the target rebuild_cache
rebuild_cache/fast: rebuild_cache

.PHONY : rebuild_cache/fast

# The main all target
all: cmake_check_build_system
	$(CMAKE_COMMAND) -E cmake_progress_start /home/zjl/code/liso/CMakeFiles /home/zjl/code/liso/CMakeFiles/progress.marks
	$(MAKE) -f CMakeFiles/Makefile2 all
	$(CMAKE_COMMAND) -E cmake_progress_start /home/zjl/code/liso/CMakeFiles 0
.PHONY : all

# The main clean target
clean:
	$(MAKE) -f CMakeFiles/Makefile2 clean
.PHONY : clean

# The main clean target
clean/fast: clean

.PHONY : clean/fast

# Prepare targets for installation.
preinstall: all
	$(MAKE) -f CMakeFiles/Makefile2 preinstall
.PHONY : preinstall

# Prepare targets for installation.
preinstall/fast:
	$(MAKE) -f CMakeFiles/Makefile2 preinstall
.PHONY : preinstall/fast

# clear depends
depend:
	$(CMAKE_COMMAND) -H$(CMAKE_SOURCE_DIR) -B$(CMAKE_BINARY_DIR) --check-build-system CMakeFiles/Makefile.cmake 1
.PHONY : depend

#=============================================================================
# Target rules for targets named liso

# Build rule for target.
liso: cmake_check_build_system
	$(MAKE) -f CMakeFiles/Makefile2 liso
.PHONY : liso

# fast build rule for target.
liso/fast:
	$(MAKE) -f CMakeFiles/liso.dir/build.make CMakeFiles/liso.dir/build
.PHONY : liso/fast

arg_parser.o: arg_parser.c.o

.PHONY : arg_parser.o

# target to build an object file
arg_parser.c.o:
	$(MAKE) -f CMakeFiles/liso.dir/build.make CMakeFiles/liso.dir/arg_parser.c.o
.PHONY : arg_parser.c.o

arg_parser.i: arg_parser.c.i

.PHONY : arg_parser.i

# target to preprocess a source file
arg_parser.c.i:
	$(MAKE) -f CMakeFiles/liso.dir/build.make CMakeFiles/liso.dir/arg_parser.c.i
.PHONY : arg_parser.c.i

arg_parser.s: arg_parser.c.s

.PHONY : arg_parser.s

# target to generate assembly for a file
arg_parser.c.s:
	$(MAKE) -f CMakeFiles/liso.dir/build.make CMakeFiles/liso.dir/arg_parser.c.s
.PHONY : arg_parser.c.s

http_mod.o: http_mod.c.o

.PHONY : http_mod.o

# target to build an object file
http_mod.c.o:
	$(MAKE) -f CMakeFiles/liso.dir/build.make CMakeFiles/liso.dir/http_mod.c.o
.PHONY : http_mod.c.o

http_mod.i: http_mod.c.i

.PHONY : http_mod.i

# target to preprocess a source file
http_mod.c.i:
	$(MAKE) -f CMakeFiles/liso.dir/build.make CMakeFiles/liso.dir/http_mod.c.i
.PHONY : http_mod.c.i

http_mod.s: http_mod.c.s

.PHONY : http_mod.s

# target to generate assembly for a file
http_mod.c.s:
	$(MAKE) -f CMakeFiles/liso.dir/build.make CMakeFiles/liso.dir/http_mod.c.s
.PHONY : http_mod.c.s

liso_core.o: liso_core.c.o

.PHONY : liso_core.o

# target to build an object file
liso_core.c.o:
	$(MAKE) -f CMakeFiles/liso.dir/build.make CMakeFiles/liso.dir/liso_core.c.o
.PHONY : liso_core.c.o

liso_core.i: liso_core.c.i

.PHONY : liso_core.i

# target to preprocess a source file
liso_core.c.i:
	$(MAKE) -f CMakeFiles/liso.dir/build.make CMakeFiles/liso.dir/liso_core.c.i
.PHONY : liso_core.c.i

liso_core.s: liso_core.c.s

.PHONY : liso_core.s

# target to generate assembly for a file
liso_core.c.s:
	$(MAKE) -f CMakeFiles/liso.dir/build.make CMakeFiles/liso.dir/liso_core.c.s
.PHONY : liso_core.c.s

liso_server.o: liso_server.c.o

.PHONY : liso_server.o

# target to build an object file
liso_server.c.o:
	$(MAKE) -f CMakeFiles/liso.dir/build.make CMakeFiles/liso.dir/liso_server.c.o
.PHONY : liso_server.c.o

liso_server.i: liso_server.c.i

.PHONY : liso_server.i

# target to preprocess a source file
liso_server.c.i:
	$(MAKE) -f CMakeFiles/liso.dir/build.make CMakeFiles/liso.dir/liso_server.c.i
.PHONY : liso_server.c.i

liso_server.s: liso_server.c.s

.PHONY : liso_server.s

# target to generate assembly for a file
liso_server.c.s:
	$(MAKE) -f CMakeFiles/liso.dir/build.make CMakeFiles/liso.dir/liso_server.c.s
.PHONY : liso_server.c.s

main.o: main.c.o

.PHONY : main.o

# target to build an object file
main.c.o:
	$(MAKE) -f CMakeFiles/liso.dir/build.make CMakeFiles/liso.dir/main.c.o
.PHONY : main.c.o

main.i: main.c.i

.PHONY : main.i

# target to preprocess a source file
main.c.i:
	$(MAKE) -f CMakeFiles/liso.dir/build.make CMakeFiles/liso.dir/main.c.i
.PHONY : main.c.i

main.s: main.c.s

.PHONY : main.s

# target to generate assembly for a file
main.c.s:
	$(MAKE) -f CMakeFiles/liso.dir/build.make CMakeFiles/liso.dir/main.c.s
.PHONY : main.c.s

# Help Target
help:
	@echo "The following are some of the valid targets for this Makefile:"
	@echo "... all (the default if no target is provided)"
	@echo "... clean"
	@echo "... depend"
	@echo "... edit_cache"
	@echo "... rebuild_cache"
	@echo "... liso"
	@echo "... arg_parser.o"
	@echo "... arg_parser.i"
	@echo "... arg_parser.s"
	@echo "... http_mod.o"
	@echo "... http_mod.i"
	@echo "... http_mod.s"
	@echo "... liso_core.o"
	@echo "... liso_core.i"
	@echo "... liso_core.s"
	@echo "... liso_server.o"
	@echo "... liso_server.i"
	@echo "... liso_server.s"
	@echo "... main.o"
	@echo "... main.i"
	@echo "... main.s"
.PHONY : help



#=============================================================================
# Special targets to cleanup operation of make.

# Special rule to run CMake to check the build system integrity.
# No rule that depends on this can have commands that come from listfiles
# because they might be regenerated.
cmake_check_build_system:
	$(CMAKE_COMMAND) -H$(CMAKE_SOURCE_DIR) -B$(CMAKE_BINARY_DIR) --check-build-system CMakeFiles/Makefile.cmake 0
.PHONY : cmake_check_build_system

