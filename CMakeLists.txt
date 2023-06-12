cmake_minimum_required(VERSION 3.20)

project(HW5 CXX)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_EXTENSIONS OFF)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

set(ALLOC_FILES
    src/alloc.cpp
    src/alloc.hpp
)

set(LIST_FILES
    src/list.cpp
    src/list.hpp
    ${ALLOC_FILES}
)

set(STRING_FILES
    src/string.cpp
    src/string.hpp
    ${LIST_FILES}
)
add_executable(standard_main
    src/standard_main.cpp
    ${STRING_FILES}
)

find_package(GTest)
if (GTest_FOUND)
    add_executable(string_gtests
        gtest/gtestmain.cpp
        gtest/string_gtests.cpp
        ${STRING_FILES}
    )
    target_include_directories(string_gtests PRIVATE src ${GTEST_INCLUDE_DIRS})
    target_link_libraries(string_gtests PRIVATE ${GTEST_LIBRARIES})

    add_executable(student_gtests
        gtest/gtestmain.cpp
        gtest/student_gtests.cpp
        ${LIST_FILES}
    )
    target_include_directories(student_gtests PRIVATE src ${GTEST_INCLUDE_DIRS})
    target_link_libraries(student_gtests PRIVATE ${GTEST_LIBRARIES})
endif()
