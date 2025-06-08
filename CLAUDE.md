# CLAUDE.md

This file provides guidance to Claude Code (claude.ai/code) when working with code in this repository.

## Build Commands
- C++: 
  - Make: `make <target>` (e.g. `make kruskal_tests`, `make permut_tests`)
  - CMake: `cmake -B build && cmake --build build`
  - Individual targets in Makefile available for specific components

## Test Commands
- C++: 
  - `make test` for all tests
  - For Google Test: `./executable --gtest_filter=TestCase.TestName`
- Python: 
  - `python -m unittest test_sort.py`
  - Single test: `python -m unittest test_sort.TestSortingAlgorithms.test_bubble_sort`

## Code Style
- C++: 
  - Standard includes first, then project includes
  - camelCase for methods, snake_case for variables, PascalCase for classes
  - Use `optional<T>` for potentially missing values
  - Error handling: mix of exceptions and return codes

- Python:
  - 4-space indentation
  - snake_case for functions and variables
  - Simple docstrings for files

Remember to run tests after making changes to verify functionality.