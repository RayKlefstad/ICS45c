cmake_minimum_required(VERSION 3.20)

project(HW6 CXX)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_EXTENSIONS OFF)
set(CMAKE_CXX_STANDARD_REQUIRED ON)


add_library(alloc_objects OBJECT
    src/alloc.cpp
    src/alloc.hpp
)

add_library(shape_objects OBJECT
    src/shape.hpp
    src/shape.cpp
    src/circle.cpp
    src/circle.hpp
    src/square.cpp
    src/square.hpp
    src/rectangle.cpp
    src/rectangle.hpp
    src/triangle.cpp
    src/triangle.hpp
)

add_library(picture_objects OBJECT
    src/picture.hpp
    src/picture.cpp
)

add_executable(picture_main
    src/standard_main.cpp
    $<TARGET_OBJECTS:alloc_objects>
    $<TARGET_OBJECTS:shape_objects>
    $<TARGET_OBJECTS:picture_objects>
)

find_package(GTest)
if (GTest_FOUND)
    add_library(gtestmain OBJECT
        gtest/gtestmain.cpp
    )
    target_include_directories(gtestmain PUBLIC src ${GTEST_INCLUDE_DIRS})
    target_link_libraries(gtestmain PUBLIC ${GTEST_LIBRARIES})

    add_executable(shape_gtests
        gtest/shape_gtests.cpp
        $<TARGET_OBJECTS:shape_objects>
    )
    target_link_libraries(shape_gtests PRIVATE gtestmain)

    add_executable(picture_gtests
        gtest/picture_gtests.cpp
        $<TARGET_OBJECTS:alloc_objects>
        $<TARGET_OBJECTS:shape_objects>
        $<TARGET_OBJECTS:picture_objects>
    )
    target_link_libraries(picture_gtests PRIVATE gtestmain)
endif()
