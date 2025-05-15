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
  vector<int> productExceptSelf(vector<int> &nums) {
    vector<int> res(nums.size(), 0);
    int product = 1;
    int zeroCnt = 0;
    size_t zeroIdx = 0;
    for (size_t i = 0; i < nums.size(); i++) {
      if (nums[i] == 0) {
        zeroCnt++;
        zeroIdx = i;
        if (zeroCnt > 1)
          return res;
      } else {
        product *= nums[i];
      }
    }

    if (zeroCnt == 1) {
      res[zeroIdx] = product;
      return res;
    }

    for (size_t i = 0; i < res.size(); i++) {
      res[i] = product / nums[i];
    }

    return res;
  }
};

int main() {
  Solution s;
  vector<int> input = {1, 2, 3, 4};
  // vector<int> input = {-1, 1, 0, -3, 3};
  // vector<int> input = {-1, 1, 0, -3, 3, 0};
  auto output = s.productExceptSelf(input);
  return 0;
}
