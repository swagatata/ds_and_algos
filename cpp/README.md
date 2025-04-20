# Data Structures and Algorithms in C++

This repository contains implementations of various data structures and algorithms in C++.

## Building with CMake

To build all projects in the cpp directory:

```bash
# Create a build directory
mkdir -p build
cd build

# Configure and build
cmake ..
cmake --build .

# Run tests (optional)
ctest
```

## Directory Structure

- `problems/`: Contains various problem implementations with tests
- `distributed_systems/`: Distributed systems implementations
- `geeks/`: Implementations of various algorithms from GeeksForGeeks
- Root directory: Various standalone algorithm implementations

## Running Individual Programs

After building, executables can be found in the `build/bin` directory:

```bash
# Run a specific program
./build/bin/program_name [arguments]

# For example, to run the permutations program
./build/bin/permutations_without_duplicates abc
```

## Running Tests

```bash
# Run all tests
cd build
ctest

# Run specific tests
ctest -R test_name
```