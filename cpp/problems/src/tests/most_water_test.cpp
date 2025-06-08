#include <gtest/gtest.h>
#include "basetest.t.h"

#include <tuple>
#include <vector>

using namespace std;

class Problem {
  const vector<unsigned int>& d_towers;
public:
  Problem(const vector<unsigned int>& towers) : d_towers(towers) {}

  unsigned long long solution() {
    DEBUG_LOG("Solving problem for") PV(d_towers)
    
    if (d_towers.size() < 2) return 0;
    
    unsigned long long maxArea = 0;
    int left = 0;
    int right = d_towers.size() - 1;
    
    while (left < right) {
      // Calculate current area
      unsigned long long currentArea = (right - left) * min(d_towers[left], d_towers[right]);
      DEBUG_LOG("Current area between " << left << " and " << right << " is " << currentArea)
      
      // Update max area if current area is larger
      maxArea = max(maxArea, currentArea);
      
      // Move the pointer pointing to the smaller height
      if (d_towers[left] < d_towers[right]) {
        left++;
      } else {
        right--;
      }
    }
    
    return maxArea;
  }
};

class MostWaterTest : public BaseTest, public ::testing::WithParamInterface<tuple<vector<unsigned int>, unsigned long long>> {
};

TEST_P(MostWaterTest, EdgeCases) {
  auto [towers, mostWater] = GetParam();
  Problem problem(towers);
  EXPECT_EQ(problem.solution(), mostWater);
}

INSTANTIATE_TEST_SUITE_P(
  MostWaterTest,
  MostWaterTest,
  ::testing::Values(
    make_tuple(vector<unsigned int>{1, 1}, 1),
    make_tuple(vector<unsigned int>{1, 0}, 0),
    make_tuple(vector<unsigned int>{1, 2}, 1),
    make_tuple(vector<unsigned int>{2, 2}, 2),
    make_tuple(vector<unsigned int>{2, 1, 2}, 4),
    make_tuple(vector<unsigned int>{1, 1, 2, 1, 1}, 4),
    make_tuple(vector<unsigned int>{1, 8, 6, 2, 5, 4, 8, 3, 7}, 49),
    make_tuple(vector<unsigned int>{4, 3, 2, 1, 4}, 16),
    make_tuple(vector<unsigned int>{1, 2, 1}, 2)
  ) 
);