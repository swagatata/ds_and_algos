#include <gtest/gtest.h>
#include <gmock/gmock.h>
#include <iostream>

// Calculator interface
class Calculator {
public:
    virtual ~Calculator() = default;
    virtual int multiply(int a, int b) = 0;
    virtual int divide(int a, int b) = 0;
};

// Mock calculator
class MockCalculator : public Calculator {
public:
    MOCK_METHOD(int, multiply, (int a, int b), (override));
    MOCK_METHOD(int, divide, (int a, int b), (override));
};

// Test using mock
TEST(CalculatorTest, MockExample) {
    MockCalculator mockCalc;
    
    // Set expectations
    EXPECT_CALL(mockCalc, multiply(2, 3))
        .Times(1)
        .WillOnce(testing::Return(6));
    
    EXPECT_CALL(mockCalc, divide(10, 2))
        .Times(1)
        .WillOnce(testing::Return(5));
    
    // Verify the mock behavior
    EXPECT_EQ(mockCalc.multiply(2, 3), 6);
    EXPECT_EQ(mockCalc.divide(10, 2), 5);
} 