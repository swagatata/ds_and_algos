/**
 * represent building with (top_left) & length
 *
 * input can be in any order
 *
 *
 */

#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>

using namespace std;

struct Building
{
  int left;
  int right;
  int height;

  Building(int left, int right, int height) : left(left), right(right), height(height) {}
};

bool operator>(const Building &left, const Building &right)
{
  if (left.right == right.right)
  {
    return left.height > right.height;
  }
  return left.right > right.right;
}

queue<pair<int, int>> get_skyline(vector<Building> buildings)
{
  // get all x coordinates
  // sort x coordinates
  sort(buildings.begin(), buildings.end());
  queue<pair<int, int>> result;
  // for each x coordinate
  int cur_height = 0;
  for (size_t i = buildings.size() - 1; i >= 0;)
  {
    result.push({buildings[i].right, max(0, cur_height)}); // TODO
    result.push({buildings[i].right, buildings[i].height});
    cur_height = buildings[i].height;

    int left = buildings[i].left;
    // get all buildings with right > this left
    int j = i - 1;
    while (j >= 0 && buildings[j].right > left)
    {
      if (buildings[j].height > buildings[i].height)
      {
        i = j;
        break;
        // result.push({buildings[j].right, buildings[i].height});
        // result.push({buildings[j].right, buildings[j].height});
      }
      j--;
    }
    if (!(j >= 0 && buildings[j].right > left))
    {
      result.push({buildings[i].left, buildings[i].height});
      result.push({buildings[i].left, 0});
      cur_height = 0;
      i = j;
    }
  }
  //   get all buildings that have x coordinate
  //   get max height
  //   if max height is greater than previous max height
  //     add to skyline
  // return skyline
  return result;
}

int main()
{
  vector<Building> buildings = {
      Building(1, 3, 3),
      // Building(2, 4, 4),
      // Building(5, 6, 1),
      // Building(7, 8, 2),
      // Building(9, 10, 3),
  };
  auto skyline = get_skyline(buildings);
  for (auto p : skyline)
  {
    cout << p.first << " " << p.second << endl;
  }

  return 0;
}

get_skyline()