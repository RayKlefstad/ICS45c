cmake_minimum_required(VERSION 3.20)

project(HW9 CXX)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_EXTENSIONS OFF)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

add_executable(mapset
    src/mapset_main.cpp
)

find_package(GTest)
if (GTest_FOUND)
    add_library(gtestmain OBJECT
        gtest/gtestmain.cpp
    )
    target_include_directories(gtestmain PUBLIC src ${GTEST_INCLUDE_DIRS})
    target_link_libraries(gtestmain PUBLIC ${GTEST_LIBRARIES})

    add_executable(map_array_gtests
        gtest/map_array_gtests.cpp
    )
    target_link_libraries(map_array_gtests PRIVATE gtestmain)

    add_executable(set_list_gtests
        gtest/set_list_gtests.cpp
    )
    target_link_libraries(set_list_gtests PRIVATE gtestmain)
endif()
