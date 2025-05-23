#include "../util.hpp"
#include <algorithm>
#include <bitset>
#include <cassert>
#include <climits>
#include <iostream>
#include <optional>
#include <queue>
#include <stack>
#include <string>
#include <unordered_map>
#include <unordered_set>
#include <vector>

using namespace std;

class Solution {
public:
  int findMinArrowShots(vector<vector<int>> &points) {
    if (points.size() == 0)
      return 0;

    sort(begin(points), end(points),
         [](const vector<int> &o1, const vector<int> &o2) {
           return (o1[1] < o2[1]);
         });
    int res = 1;
    int end = points[0][1];
    for (auto &&p : points) {
      if (end < p[0]) {
        res++;
        end = p[1];
      }
    }
    return res;
  }
};

int main() {
  Solution s;
  // vector<vector<int>> input = {vector<int>{10, 16}, vector<int>{2, 8},
  //                              vector<int>{1, 6}, vector<int>{7, 12}};
  vector<vector<int>> input = {vector<int>{3, 9},  vector<int>{7, 12},
                               vector<int>{3, 8},  vector<int>{6, 8},
                               vector<int>{9, 10}, vector<int>{2, 9},
                               vector<int>{0, 9},  vector<int>{3, 9},
                               vector<int>{0, 6},  vector<int>{2, 8}};
  auto output = s.findMinArrowShots(input);
  return 0;
}
