# C++ Problems

This directory contains various problem implementations with tests.

## Prerequisites

- CMake (version 3.10 or higher)
- C++ compiler (supporting C++11)
- Google Test (automatically downloaded by CMake)

## Building with CMake

```bash
# Create a build directory
mkdir -p build
cd build

# Configure and build
cmake ..
cmake --build .
```

## Running the ping_measure Tool

The ping_measure tool allows you to measure ping times to a specified IP address:

```bash
./ping_measure <IP_ADDRESS>
```

Example:
```bash
./ping_measure 8.8.8.8
```

## Running Tests

Test files are located in the `src/tests` directory. To run specific tests or test suites, use Google Test's filter functionality:

```bash
# Run all tests
./test_executable

# Run specific test
./test_executable --gtest_filter=TestCase.TestName

# Example: Run the TimeMapTest.NoOp test
./test_executable --gtest_filter=TimeMapTest.NoOp
```

## Adding New Tests

1. Create a new test file in `src/tests/`
2. Include necessary gtest headers and implement your tests
3. Use the standard Google Test macros like TEST(), EXPECT_EQ(), etc.

## Test Structure

All tests follow the Google Test framework conventions:

```cpp
#include <gtest/gtest.h>

TEST(TestSuiteName, TestName) {
    // Test implementation
    EXPECT_EQ(expected, actual);
}
```

## Project Structure

- `src/` - Source files and tests
- `CMakeLists.txt` - CMake configuration file
- `ping_measure.cpp` - Standalone ping measurement tool