# Set required version of CMake. Set this to the version
# of cmake on your computer/server. To find the version,
# run the command: `cmake --version`
cmake_minimum_required(VERSION 3.20)

# Explicitly states which C and CXX compilers to use (not
# strictly necessary but important when you have more than
# one on a system):
set(CMAKE_C_COMPILER gcc)
set(CMAKE_CXX_COMPILER g++)

# Specify the C++ standard that you will use in the project:
set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# This will export the commands required to compile your
# program. This important for a lot of external tools such
# as language servers and debuggers for allowing them to
# understand the overall structure of your program and give
# better feedback and support. Not necessary but generally
# good to have.
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

# Compiler flags set here:
set(COMPILE_FLAGS "-std=c++20 -ggdb -Wall -Wextra -pedantic -Wfatal-errors")

# This will contain the list of all *.cpp files you make
# for the project. Make sure that you add the files to
# CMakeLists.txt when you add it to your src folder or it
# will not compile!
# WARNING: DO NOT INCLUDE MAIN! We will add the main.cpp
# file in the executable command.
set(SRC_FILES_EXCEPT_MAIN
)

# Set up a project with a name:
project(hw)

# Adds an executable target that will be built by gcc/g++,
# the name being the same as the project name (hw in this
# example).
add_executable(${PROJECT_NAME} ${SRC_FILES_EXCEPT_MAIN} src/main.cpp)

# Set build flags: (this adds the flags from COMPILE_FLAGS above).
set_target_properties(${PROJECT_NAME} PROPERTIES COMPILE_FLAGS ${COMPILE_FLAGS})

# This ensures that all of the *.cpp files you have included above
# can find their *.h files that they include (eg: '#include "example.h"').
# For this class DO NOT put *.h files anywhere outside of the src/ directory.
target_include_directories(${PROJECT_NAME} PRIVATE ${CMAKE_SOURCE_DIR}/src)

# This is for linking pre-build library files such as pthread.
target_link_libraries(${PROJECT_NAME} pthread)

# This is for optionally building GTest suites. If GTest
# is installed on your system and it can be found on your
# $PATH, then this will build a 'gtest' binary that will
# run your tests. GTest is guaranteed to be installed on
# OpenLab, but you will need to install it on your own computer
# for this to build.
find_package(GTest)
if (GTest_FOUND)
  project(gtest)

  # If you add other test files, be sure to add them to
  # this list!
  set(GTEST_FILES
    gtest/gtestmain.cpp
    gtest/tests.cpp
    )

  include_directories(${GTEST_INCLUDE_DIRS})
  add_executable(${PROJECT_NAME} ${SRC_FILES_EXCEPT_MAIN} ${GTEST_FILES})
  target_include_directories(${PROJECT_NAME} PRIVATE ${CMAKE_SOURCE_DIR}/src ${CMAKE_SOURCE_DIR}/gtest)
  target_link_libraries(${PROJECT_NAME} ${GTEST_LIBRARIES} pthread)
endif()
