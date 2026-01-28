#include "../util.hpp"
#include <algorithm>
#include <bitset>
#include <cassert>
#include <climits>
#include <cmath>
#include <iostream>
#include <list>
#include <numeric>
#include <optional>
#include <queue>
#include <set>
#include <stack>
#include <string>
#include <unordered_map>
#include <unordered_set>
#include <vector>

using namespace std;

class Solution {
public:
  int findMaxConsecutiveOnes(vector<int>& nums) {
    int res = 0;
    int cnt = 0;
    for (auto n : nums) {
      if (n == 0) {
        res = max(res, cnt);
        cnt = 0;
      } else {
        cnt++;
      }
    }
    return max(res, cnt);
  };

  int main() {
    Solution s;
    vector<int> input1 = {1, 1, 0, 1, 1, 1};
    auto output1 = s.findMaxConsecutiveOnes(input1);
    assert(output1 == 3);
    return 0;
  };
};
