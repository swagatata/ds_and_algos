cmake_minimum_required(VERSION 3.14)
project(geeks)

# GoogleTest requires at least C++14
set(CMAKE_CXX_STANDARD 14)

# Check if GoogleTest has already been added by parent project
if(NOT TARGET gtest AND NOT TARGET gtest_main)
  include(FetchContent)
  FetchContent_Declare(
    googletest
    URL https://github.com/google/googletest/archive/03597a01ee50ed33e9dfd640b249b4be3799d395.zip
    DOWNLOAD_EXTRACT_TIMESTAMP TRUE
  )
  # For Windows: Prevent overriding the parent project's compiler/linker settings
  # set(gtest_force_shared_crt ON CACHE BOOL "" FORCE)
  FetchContent_MakeAvailable(googletest)
endif()

# Try to find Boost, but make it optional
if(NOT DEFINED BOOST_AVAILABLE)
  # If parent hasn't checked, check here
  find_package(Boost 1.81.0 QUIET)
  set(BOOST_AVAILABLE ${Boost_FOUND})
endif()

# Setup based on Boost availability
if(BOOST_AVAILABLE)
  message(STATUS "Building with Boost support")
  include_directories(${Boost_INCLUDE_DIR})
else()
  message(STATUS "Building without Boost support - some features may be disabled")
endif()

# Enable testing
include(CTest)

# Basic test executable that doesn't require Boost
add_executable(hello_test hello_test.cc)
target_link_libraries(hello_test GTest::gtest_main)

include(GoogleTest)
gtest_discover_tests(hello_test)

# Add other executables as needed (conditional on Boost if required)
# Example:
# if(BOOST_AVAILABLE)
#   add_executable(boost_dependent_test boost_test.cc)
#   target_link_libraries(boost_dependent_test GTest::gtest_main ${Boost_LIBRARIES})
# endif()