cmake_minimum_required(VERSION 3.20)

project(HW2 CXX)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_EXTENSIONS OFF)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

set(WORD_COUNT_SRC_FILES
  src/word_count.cpp
  src/word_count.h
)
add_executable(word_count ${WORD_COUNT_SRC_FILES} src/word_count_main.cpp)

set(COINS_SRC_FILES
  src/coins.cpp
  src/coins.h
)
add_executable(coins_simple ${COINS_SRC_FILES} src/coins_simple.cpp)
add_executable(coins_menu ${COINS_SRC_FILES} src/coins_menu.cpp)
add_executable(coins_transfer ${COINS_SRC_FILES} src/coins_transfer.cpp)

find_package(GTest)
if (GTest_FOUND)
  set(WORD_COUNT_TEST_FILES
    gtest/word_count_gtests.cpp
  )

  add_executable(word_count_gtests gtest/gtestmain.cpp ${WORD_COUNT_SRC_FILES} ${WORD_COUNT_TEST_FILES})
  target_include_directories(word_count_gtests PRIVATE src ${GTEST_INCLUDE_DIRS})
  target_link_libraries(word_count_gtests PRIVATE ${GTEST_LIBRARIES})

  set(COINS_TEST_FILES
    gtest/coins_gtests.cpp
  )

  add_executable(coins_gtests gtest/gtestmain.cpp ${COINS_SRC_FILES} ${COINS_TEST_FILES})
  target_include_directories(coins_gtests PRIVATE src ${GTEST_INCLUDE_DIRS})
  target_link_libraries(coins_gtests PRIVATE ${GTEST_LIBRARIES})
endif()
