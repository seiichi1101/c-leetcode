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
  int longestConsecutive(vector<int> &nums) {
    int res = 0;
    unordered_set<int> set(nums.begin(), nums.end());
    for (auto &&num : set) {
      if (!set.contains(num - 1)) {
        int cnt = 1;
        int currNum = num + 1;
        while (set.contains(currNum)) {
          cnt++;
          currNum++;
        }
        res = max(res, cnt);
      }
    }

    return res;
  }
};

int main() {
  Solution s;
  vector<int> input = {1, 2, 3};
  auto output = s.longestConsecutive(input);
  return 0;
}
