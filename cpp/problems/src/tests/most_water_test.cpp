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
    vector<unsigned int> leftMax(d_towers.size(), 0);
    vector<unsigned int> rightMax(d_towers.size(), 0);

    leftMax[0] = 0;
    for (int i = 1; i < d_towers.size(); ++i) {
      leftMax[i] = (d_towers[i] > d_towers[leftMax[i - 1]] ? i : leftMax[i - 1]);
    }
    DEBUG_LOG("Printing leftMax")
    PV(leftMax)

    // rightMax[d_towers.size() - 1] = d_towers.back();
    // for (int i = d_towers.size() - 2; i >= 0; --i) {
    //   rightMax[i] = (d_towers[i] > rightMax[i + 1] ? d_towers[i] : rightMax[i + 1]);
    // }
    unsigned long long maxArea = 0;
    for (int i = 1; i < d_towers.size(); ++i) {
      unsigned long long area = (i - leftMax[i - 1]) * min(d_towers[i], d_towers[leftMax[i - 1]]); 
      DEBUG_LOG("Area when i is " << i << " is " << area) 
      if (area > maxArea)
        maxArea = area;
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
    make_tuple(vector<unsigned int>{1, 1}, 1)
    ,make_tuple(vector<unsigned int>{1, 0}, 0)
    ,make_tuple(vector<unsigned int>{1, 2}, 1)
    ,make_tuple(vector<unsigned int>{2, 2}, 2)
    ,make_tuple(vector<unsigned int>{2, 1, 2}, 4)
  ) 
);