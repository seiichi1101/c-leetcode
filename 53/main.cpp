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
  // Two Pointer
  // int maxSubArray(vector<int> &nums) {
  //   int res = INT_MIN;

  //   int l = 0, r = 0;
  //   int size = nums.size();
  //   int tmp = 0;
  //   while (r < size) {
  //     tmp += nums[r];
  //     if (tmp > res)
  //       res = tmp;
  //     if (tmp < 0) {
  //       l++;
  //       r = l;
  //       tmp = 0;
  //     } else {
  //       r++;
  //     }
  //   }

  //   return res;
  // }

  // Simple
  int maxSubArray(vector<int> &nums) {
    int res = nums[0];
    int tmp = 0;
    for (auto &&n : nums) {
      if (tmp < 0)
        tmp = 0;
      tmp += n;
      res = max(res, tmp);
    }
    return res;
  }
};

int main() {
  Solution s;
  // vector<int> input = {-2, 1, -3, 4, -1, 2, 1, -5, 4};
  // vector<int> input = {-1, 0, -2};
  vector<int> input = {-2, 1};
  auto output = s.maxSubArray(input);
  return 0;
}
