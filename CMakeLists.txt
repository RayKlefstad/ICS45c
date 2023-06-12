cmake_minimum_required(VERSION 3.20)

project(HW4 CXX)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_EXTENSIONS OFF)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

set(STRING_FILES
  src/string.cpp
  src/string.hpp
  src/alloc.cpp
  src/alloc.hpp
)
add_executable(standard_main ${STRING_FILES} src/standard_main.cpp)

find_package(GTest)
if (GTest_FOUND)
  set(STRING_TEST_FILES
    gtest/string_gtests.cpp
    gtest/student_gtests.cpp
  )

  add_executable(string_gtests gtest/gtestmain.cpp ${STRING_FILES} ${STRING_TEST_FILES})
  target_include_directories(string_gtests PRIVATE ${GTEST_INCLUDE_DIRS})
  target_include_directories(string_gtests AFTER PRIVATE src)
  target_link_libraries(string_gtests PRIVATE ${GTEST_LIBRARIES})

  set(STUDENT_TEST_FILES
    gtest/student_gtests.cpp
  )
  add_executable(student_gtests gtest/gtestmain.cpp ${STRING_FILES} ${STUDENT_TEST_FILES})
  target_include_directories(student_gtests PRIVATE ${GTEST_INCLUDE_DIRS})
  target_include_directories(student_gtests AFTER PRIVATE src)
  target_link_libraries(student_gtests PRIVATE ${GTEST_LIBRARIES})


  set(STANDARD_MAIN_FILES
    gtest/standard_main_gtests.cpp)
  add_executable(standard_main_gtests gtest/gtestmain.cpp ${STRING_FILES} ${STANDARD_MAIN_FILES})
  target_include_directories(standard_main_gtests PRIVATE ${GTEST_INCLUDE_DIRS})
  target_include_directories(standard_main_gtests AFTER PRIVATE src)
  target_link_libraries(standard_main_gtests PRIVATE ${GTEST_LIBRARIES})
endif()
