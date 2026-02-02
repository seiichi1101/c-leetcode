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
  int minPairSum(vector<int>& nums) {
    sort(nums.begin(), nums.end());
    int res = nums[0] + nums[1];
    int size = nums.size();
    for (int i = 0; i < size; i++) {
      res = max(res, nums[i] + nums[size - i - 1]);
    }
    return res;
  }
};

int main() {
  Solution s;
  vector<int> input1 = {1, 2, 3};
  auto output = s.minPairSum(input1);
  assert(output == 7);
  return 0;
}
