cmake_minimum_required(VERSION 3.20)

project(HW8 CXX)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_EXTENSIONS OFF)
set(CMAKE_CXX_STANDARD_REQUIRED ON)


add_library(mapset_obj OBJECT
    src/mapset.cpp
    src/mapset.hpp
)

add_library(process_numbers_obj OBJECT
    src/process_numbers.cpp
    src/process_numbers.hpp
)

add_library(compute_grades_obj OBJECT
    src/compute_grades.cpp
    src/compute_grades.hpp
)

add_executable(mapset
    src/mapset_main.cpp
    $<TARGET_OBJECTS:mapset_obj>
)

add_executable(process_numbers
    src/process_numbers_main.cpp
    $<TARGET_OBJECTS:process_numbers_obj>
)

add_executable(compute_grades
    src/compute_grades_main.cpp
    $<TARGET_OBJECTS:compute_grades_obj>
)

find_package(GTest)
if (GTest_FOUND)
    add_library(gtestmain OBJECT
        gtest/gtestmain.cpp
    )
    target_include_directories(gtestmain PUBLIC src ${GTEST_INCLUDE_DIRS})
    target_link_libraries(gtestmain PUBLIC ${GTEST_LIBRARIES})

    add_executable(mapset_gtests
        gtest/mapset_gtests.cpp
        $<TARGET_OBJECTS:mapset_obj>
    )
    target_link_libraries(mapset_gtests PRIVATE gtestmain)

    add_executable(process_numbers_gtests
        gtest/process_numbers_gtests.cpp
        $<TARGET_OBJECTS:process_numbers_obj>
    )
    target_link_libraries(process_numbers_gtests PRIVATE gtestmain)

    add_executable(compute_grades_gtests
        gtest/compute_grades_gtests.cpp
        $<TARGET_OBJECTS:compute_grades_obj>
    )
    target_link_libraries(compute_grades_gtests PRIVATE gtestmain)
endif()
