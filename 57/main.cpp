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
  vector<vector<int>> insert(vector<vector<int>> &intervals,
                             vector<int> &newInterval) {
    if (intervals.size() == 0)
      return vector<vector<int>>{newInterval};
    vector<vector<int>> res{};
    bool flag = true;
    for (auto &&interval : intervals) {
      if (flag) {
        if (newInterval[1] < interval[0]) {
          res.push_back(newInterval);
          res.push_back(interval);
          flag = false;
        } else if (interval[1] < newInterval[0]) {
          res.push_back(interval);
        } else {
          res.push_back(vector<int>{min(interval[0], newInterval[0]),
                                    max(interval[1], newInterval[1])});
          flag = false;
        }
      } else if (res.size() > 0) {
        vector<int> last = res.back();
        res.pop_back();
        if (last[1] >= interval[0]) {
          res.push_back(vector<int>{min(interval[0], last[0]),
                                    max(interval[1], last[1])});
        } else {
          res.push_back(last);
          res.push_back(interval);
        }
      } else {
        res.push_back(interval);
      }
    }
    if (flag)
      res.push_back(newInterval);
    return res;
  }
};

int main() {
  Solution s;
  vector<vector<int>> intervals = {vector<int>{1, 3}, vector<int>{6, 9}};
  vector<int> newInterval = {2, 5};
  auto output = s.insert(intervals, newInterval);
  return 0;
}
