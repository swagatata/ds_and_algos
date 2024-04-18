cmake_minimum_required(VERSION 3.14)
project(interviews)

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
add_library(interviews src/interviews.cpp)
add_library(atlassian src/atlassian.cpp)
add_executable(interviews.t.tsk tests/interviews.t.cpp)
add_executable(atlassian.t.tsk tests/atlassian.t.cpp)
target_link_libraries(interviews.t.tsk interviews ${GTEST_LIBRARIES} pthread)
target_link_libraries(atlassian.t.tsk interviews ${GTEST_LIBRARIES} pthread)

# Add the test target
add_test(NAME interviews_test COMMAND interviews.t.tsk)
add_test(NAME atlassian COMMAND atlassian.t.tsk)