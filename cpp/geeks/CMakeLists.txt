cmake_minimum_required(VERSION 3.14)
project(geeks)

# GoogleTest requires at least C++14
set(CMAKE_CXX_STANDARD 14)

include(FetchContent)
FetchContent_Declare(
  googletest
  URL https://github.com/google/googletest/archive/03597a01ee50ed33e9dfd640b249b4be3799d395.zip
)
# For Windows: Prevent overriding the parent project's compiler/linker settings
# set(gtest_force_shared_crt ON CACHE BOOL "" FORCE)
FetchContent_MakeAvailable(googletest)


set(BOOST_ROOT ~/Downloads/boost_1_81_0)
find_package(Boost 1.81.0 REQUIRED)
include_directories(${Boost_INCLUDE_DIR})

# enable_testing()
include(CTest)
# add_library(
#   print_all_binary
#   print_all_binary.cpp
# )
add_executable(
  hello_test
  hello_test.cc
)
target_link_libraries(
  hello_test
#   print_all_binary
)
target_link_libraries(
  hello_test
  GTest::gtest_main
)
# TARGET_LINK_LIBRARIES( hello_test LINK_PUBLIC ${Boost_LIBRARIES} )
include(GoogleTest)
gtest_discover_tests(hello_test)