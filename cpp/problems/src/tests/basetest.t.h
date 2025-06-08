#pragma once

#include <gtest/gtest.h>
#include <iostream>
#include <cstdlib>
#include <string>

using namespace std;

// Debug flag - can be set via environment variable DEBUG_MODE
static bool DEBUG = false;

// Debug logging macro that only prints when DEBUG is true
#define DEBUG_LOG(x) if (DEBUG) { cout << x << endl; }
#define DEBUG_LOG_SPACES(x) if (DEBUG) { cout << x << " "; }

// Base test fixture that handles debug mode
class BaseTest : public ::testing::Test {
protected:
    void SetUp() override {
        const char* debug_env = std::getenv("DEBUG_MODE");
        DEBUG = (debug_env != nullptr && string(debug_env) == "1");
        if (DEBUG) {
            cout << "Running in DEBUG mode" << endl;
        }
    }
}; 

#define PV(x) for(auto v : x) DEBUG_LOG(v)