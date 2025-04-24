#include "../util.hpp"
#include <algorithm>
#include <bitset>
#include <cassert>
#include <climits>
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
  vector<vector<int>> merge(vector<vector<int>> &intervals) {
    sort(intervals.begin(), intervals.end());

    vector<vector<int>> res;
    for (auto &&interval : intervals) {
      if (res.empty() || res.back()[1] < interval[0]) {
        res.push_back(interval);
      } else {
        res.back()[1] = max(res.back()[1], interval[1]);
      }
    }

    return res;
  }
};

int main() {
  Solution s;
  // vector<vector<int>> input = {{1, 3}, {2, 6}, {8, 10}, {15, 18}};
  vector<vector<int>> input = {{1, 4}, {4, 5}};
  auto output = s.merge(input);
  return 0;
}
