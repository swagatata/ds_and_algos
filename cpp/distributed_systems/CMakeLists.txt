cmake_minimum_required(VERSION 3.14)
project(distributed_systems)

set(CMAKE_CXX_STANDARD 14)

find_library(GTEST_LIBRARIES
             NAMES gtest gtest_main
             HINTS /usr/local/lib)

find_path(GTEST_INCLUDE_DIRS
          NAMES gtest/gtest.h
          HINTS /usr/local/include/)

message(STATUS "GTest include directories: ${GTEST_INCLUDE_DIRS}")
message(STATUS "GTest library directories: ${GTEST_LIBRARY_DIRS}")
message(STATUS "GTest libraries: ${GTEST_LIBRARIES}")

# Add the include directory
include_directories(include)
include_directories(${GTEST_INCLUDE_DIRS})

# Add the source files
add_library(distributed_system src/distributed_system.cpp)
add_executable(distributed_system.tsk tests/distributed_system.t.cpp)
target_link_libraries(distributed_system.tsk distributed_system ${GTEST_LIBRARIES} pthread)

# Add the test target
add_test(NAME distributed_system_test COMMAND distributed_system.tsk)