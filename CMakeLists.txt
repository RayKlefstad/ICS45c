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

# Add knots main executable
set(KNOT_SRC_FILES
  src/convert_knots.h
  src/convert_knots.cpp
)
project(knot CXX)
add_executable(${PROJECT_NAME} ${KNOT_SRC_FILES})

# Add stack main executable
set(STACK_SRC_FILES
  src/stack.h
  src/stack.cpp
)
project(stack CXX)
add_executable(${PROJECT_NAME} ${STACK_SRC_FILES})

# Add letter_count main executable
set(COUNT_SRC_FILES
  src/letter_count.h
  src/letter_count.cpp
)
project(count CXX)
add_executable(${PROJECT_NAME} ${COUNT_SRC_FILES})

# This is for optionally building GTest suites. If GTest
# is installed on your system and it can be found on your
# $PATH, then this will build a 'gtest' binary that will
# run your tests. GTest is guaranteed to be installed on
# OpenLab, but you will need to install it on your own computer
# for this to build.
find_package(GTest)
if (GTest_FOUND)
    # Knot Tests:
    project(knot_gtests CXX)

    # If you add other test files, be sure to add them to
    # this list!
    # NOTE : We are adding src/convert_knots.h manually
    # here to disconnect errors in `stack` from affecting
    # this test.
    set(KNOT_GTEST_FILES
        gtest/gtestmain.cpp
        gtest/knot_gtests.cpp
        src/convert_knots.h
    )

    include_directories(${GTEST_INCLUDE_DIRS})
    add_executable(${PROJECT_NAME} ${KNOT_GTEST_FILES})
    # This ensures that the cpp files in gtest/ can include headers from
    # src/ simply by doing
    #     #include "foo.h"
    # instead of having to write the cumbersome
    #     #include "../src/foo.h"
    target_include_directories(${PROJECT_NAME} PRIVATE ${CMAKE_SOURCE_DIR}/src)
    target_link_libraries(${PROJECT_NAME} ${GTEST_LIBRARIES})

    # Stack Tests:
    project(stack_gtests CXX)

    # If you add other test files, be sure to add them to
    # this list!
    set(STACK_GTEST_FILES
        gtest/gtestmain.cpp
        gtest/stack_gtests.cpp
        src/stack.h
    )

    include_directories(${GTEST_INCLUDE_DIRS})
    add_executable(${PROJECT_NAME} ${STACK_GTEST_FILES})
    # This ensures that the cpp files in gtest/ can include headers from
    # src/ simply by doing
    #     #include "foo.h"
    # instead of having to write the cumbersome
    #     #include "../src/foo.h"
    target_include_directories(${PROJECT_NAME} PRIVATE ${CMAKE_SOURCE_DIR}/src)
    target_link_libraries(${PROJECT_NAME} ${GTEST_LIBRARIES})

    # Letter Count Tests:
    project(count_gtests CXX)

    # If you add other test files, be sure to add them to
    # this list!
    set(COUNT_GTEST_FILES
        gtest/gtestmain.cpp
        gtest/count_gtests.cpp
        src/letter_count.h
    )

    include_directories(${GTEST_INCLUDE_DIRS})
    add_executable(${PROJECT_NAME} ${COUNT_GTEST_FILES})
    # This ensures that the cpp files in gtest/ can include headers from
    # src/ simply by doing
    #     #include "foo.h"
    # instead of having to write the cumbersome
    #     #include "../src/foo.h"
    target_include_directories(${PROJECT_NAME} PRIVATE ${CMAKE_SOURCE_DIR}/src)
    target_link_libraries(${PROJECT_NAME} ${GTEST_LIBRARIES})
endif()

