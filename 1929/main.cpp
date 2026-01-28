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
  vector<int> getConcatenation(vector<int>& nums) {
    int n = nums.size();
    for (int i = 0; i < n; i++) {
      nums.push_back(nums[i]);
    }
    return nums;
  }
};

int main() {
  Solution s;
  vector<int> nums{1, 2, 3};
  auto out = s.getConcatenation(nums);
  for (auto n : nums) {
    cout << n << "\n";
  }
  return 0;
}
