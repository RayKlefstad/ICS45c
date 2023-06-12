cmake_minimum_required(VERSION 3.20)

project(HW7 CXX)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_EXTENSIONS OFF)
set(CMAKE_CXX_STANDARD_REQUIRED ON)


add_library(alloc_objects OBJECT
    src/alloc.cpp
    src/alloc.hpp
)

add_executable(standard_main
    src/standard_main.cpp
    src/array.hpp
    src/matrix.hpp
    $<TARGET_OBJECTS:alloc_objects>
)

find_package(GTest)
if (GTest_FOUND)
    add_library(gtestmain OBJECT
        gtest/gtestmain.cpp
    )
    target_include_directories(gtestmain PUBLIC src ${GTEST_INCLUDE_DIRS})
    target_link_libraries(gtestmain PUBLIC ${GTEST_LIBRARIES})

    add_executable(int_array_gtests
        gtest/int_array_gtests.cpp
        src/int_array.hpp
        $<TARGET_OBJECTS:alloc_objects>
    )
    target_link_libraries(int_array_gtests PRIVATE gtestmain)

    add_executable(array_gtests
        gtest/array_gtests.cpp
        src/array.hpp
        $<TARGET_OBJECTS:alloc_objects>
    )
    target_link_libraries(array_gtests PRIVATE gtestmain)

    add_executable(matrix_gtests
        gtest/matrix_gtests.cpp
        src/array.hpp
        src/matrix.hpp
        $<TARGET_OBJECTS:alloc_objects>
    )
    target_link_libraries(matrix_gtests PRIVATE gtestmain)
endif()
