# Set required version of CMake. Set this to the version
# of cmake on your computer/server. To find the version,
# run the command: `cmake --version`
cmake_minimum_required(VERSION 3.20)

# Specify the C++ standard that you will use in the project:
set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_EXTENSIONS OFF)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# This will export the commands required to compile your
# program. This important for a lot of external tools such
# as language servers and debuggers for allowing them to
# understand the overall structure of your program and give
# better feedback and support. Not necessary but generally
# good to have.
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

# This will contain the list of all *.cpp and *.h files you make
# for the project. Make sure that you add the files to
# CMakeLists.txt when you add it to your src folder or it
# will not compile!
# NOTE: *.h files are not strictly necessary to be added for most
# build systems but it is considered best practice for
# portability (e.g. for IDEs like Visual Studio).
# WARNING: DO NOT INCLUDE MAIN! We will add the main.cpp
# file in the executable command.
set(SRC_FILES_EXCEPT_MAIN
)

# Set up a project with a name and C++ as the language:
project(hw CXX)

# Adds an executable target that will be built by gcc/g++,
# the name being the same as the project name (hw in this
# example).
add_executable(${PROJECT_NAME} ${SRC_FILES_EXCEPT_MAIN} src/main.cpp)

# This is for optionally building GTest suites. If GTest
# is installed on your system and it can be found on your
# $PATH, then this will build a 'gtest' binary that will
# run your tests. GTest is guaranteed to be installed on
# OpenLab, but you will need to install it on your own computer
# for this to build.
find_package(GTest)
if (GTest_FOUND)
    project(hw_gtests CXX)

    # If you add other test files, be sure to add them to
    # this list!
    set(GTEST_FILES
        gtest/gtestmain.cpp
        gtest/hw_gtests.cpp
    )

    include_directories(${GTEST_INCLUDE_DIRS})
    add_executable(${PROJECT_NAME} ${SRC_FILES_EXCEPT_MAIN} ${GTEST_FILES})
    # This ensures that the cpp files in gtest/ can include headers from
    # src/ simply by doing
    #     #include "foo.h"
    # instead of having to write the cumbersome
    #     #include "../src/foo.h"
    target_include_directories(${PROJECT_NAME} PRIVATE ${CMAKE_SOURCE_DIR}/src)
    target_link_libraries(${PROJECT_NAME} ${GTEST_LIBRARIES})
endif()
