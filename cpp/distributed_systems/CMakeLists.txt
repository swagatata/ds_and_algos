cmake_minimum_required(VERSION 3.14)
project(distributed_systems)

set(CMAKE_CXX_STANDARD 14)

# Check if GoogleTest has already been added by parent project
if(NOT TARGET gtest AND NOT TARGET gtest_main)
  include(FetchContent)
  FetchContent_Declare(
    googletest
    GIT_REPOSITORY https://github.com/google/googletest.git
    GIT_TAG release-1.12.1
    DOWNLOAD_EXTRACT_TIMESTAMP TRUE
  )
  FetchContent_MakeAvailable(googletest)
  message(STATUS "Fetched GoogleTest for distributed_systems module")
else()
  message(STATUS "Using parent project's GoogleTest")
endif()

# Add the include directory
include_directories(include)

# Add the source files
add_library(distributed_system src/distributed_system.cpp)
add_executable(distributed_system_test tests/distributed_system.t.cpp)
target_link_libraries(distributed_system_test distributed_system gtest gtest_main pthread)

# Add the test target
add_test(NAME distributed_system_test COMMAND distributed_system_test)