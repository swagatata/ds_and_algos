cmake_minimum_required(VERSION 3.10)
project(cpp_project VERSION 1.0)

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
)
FetchContent_MakeAvailable(googletest)

# Add executable
add_executable(${PROJECT_NAME} 
    src/main.cpp
    src/tests/arithmetic_test.cpp
    src/tests/calculator_test.cpp
    src/tests/leafnodes_test.cpp
)

# Add include directories
target_include_directories(${PROJECT_NAME} PRIVATE include)

# Link against Google Test and Google Mock
target_link_libraries(${PROJECT_NAME} PRIVATE gtest_main gmock_main) 