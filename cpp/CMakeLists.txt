cmake_minimum_required(VERSION 3.10)
project(ds_and_algos)

# Specify C++ standard
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# Enable testing
enable_testing()

# Include FetchContent for downloading GoogleTest
include(FetchContent)
FetchContent_Declare(
    googletest
    GIT_REPOSITORY https://github.com/google/googletest.git
    GIT_TAG release-1.12.1
    DOWNLOAD_EXTRACT_TIMESTAMP TRUE
)
FetchContent_MakeAvailable(googletest)

# Create build directory for binaries
file(MAKE_DIRECTORY ${CMAKE_BINARY_DIR}/bin)
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin)

# Process each .cpp file to create individual executables
file(GLOB CPP_SOURCES "*.cpp")
foreach(source_file ${CPP_SOURCES})
    get_filename_component(filename ${source_file} NAME_WE)
    # Skip files that will be handled specially
    if(NOT filename STREQUAL "kruskal_tests" AND 
       NOT filename STREQUAL "permutations_without_duplicates" AND
       NOT filename STREQUAL "permutations_without_duplicates_v2")
        add_executable(${filename} ${source_file})
        
        # Special handling for cpp20.cpp
        if(filename STREQUAL "cpp20")
            set_target_properties(${filename} PROPERTIES
                CXX_STANDARD 20
                CXX_STANDARD_REQUIRED ON
            )
        endif()
    endif()
endforeach()

# Special targets with dependencies
add_executable(kruskal_tests_exec kruskal_tests.cpp)
target_link_libraries(kruskal_tests_exec PRIVATE gtest_main)

add_executable(permutations_without_duplicates_exec permutations_without_duplicates.cpp)
add_executable(permutations_without_duplicates_v2_exec permutations_without_duplicates_v2.cpp)

# Add problems subdirectory
add_subdirectory(problems)

# Add test for permutations
add_test(NAME permutations_test COMMAND ${CMAKE_BINARY_DIR}/bin/permutations_without_duplicates_exec abc)
add_test(NAME permutations_test_v2 COMMAND ${CMAKE_BINARY_DIR}/bin/permutations_without_duplicates_v2_exec abc)

# Add distributed_systems directory if it exists
if(EXISTS ${CMAKE_CURRENT_SOURCE_DIR}/distributed_systems/CMakeLists.txt)
    add_subdirectory(distributed_systems)
endif()

# Add geeks directory if it exists - conditionally require Boost
if(EXISTS ${CMAKE_CURRENT_SOURCE_DIR}/geeks/CMakeLists.txt)
    # Check if Boost is available, but make it optional
    find_package(Boost 1.81.0 QUIET)
    set(BOOST_AVAILABLE ${Boost_FOUND})
    add_subdirectory(geeks)
endif()