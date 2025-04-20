cmake_minimum_required(VERSION 3.10)
project(problems)

# Specify C++ standard
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# Enable testing
enable_testing()

# Include FetchContent for downloading GoogleTest
include(FetchContent)

# Fetch and make Google Test available
FetchContent_Declare(
    googletest
    GIT_REPOSITORY https://github.com/google/googletest.git
    GIT_TAG release-1.12.1
    DOWNLOAD_EXTRACT_TIMESTAMP TRUE
)
FetchContent_MakeAvailable(googletest)

# Add the ping_measure executable
add_executable(ping_measure ping_measure.cpp)

# Include directories
include_directories(include)

# Collect all test source files
file(GLOB TEST_SOURCES "src/tests/*.cpp")

# For each test source, create an executable
foreach(test_source ${TEST_SOURCES})
    get_filename_component(test_name ${test_source} NAME_WE)
    add_executable(${test_name} ${test_source})
    target_link_libraries(${test_name} PRIVATE gtest_main gmock_main)
    add_test(NAME ${test_name} COMMAND ${test_name})
endforeach()

# Add the main source file if it exists
if(EXISTS "${CMAKE_CURRENT_SOURCE_DIR}/src/main.cpp")
    add_executable(main_app src/main.cpp)
    target_link_libraries(main_app PRIVATE gtest_main gmock_main)
endif()