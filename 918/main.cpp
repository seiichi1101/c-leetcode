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
  // TLE
  // int maxSubarraySumCircular(vector<int> &nums) {
  //   int res = nums[0];
  //   int size = nums.size();
  //   for (size_t i = 0; i < size; i++) {
  //     int tmp = 0;
  //     int end = i + size;
  //     for (size_t j = i; j < end; j++) {
  //       if (tmp < 0)
  //         tmp = 0;
  //       tmp += nums[j % size];
  //       res = max(res, tmp);
  //     }
  //   }
  //   return res;
  // }

  // find min zone instead of max
  int maxSubarraySumCircular(vector<int> &nums) {
    int sumTotal = 0;
    int sumMax = nums[0];
    int sumMin = nums[0];
    int currMax = 0;
    int currMin = 0;
    int size = nums.size();
    for (auto &&num : nums) {
      currMax = max(currMax, 0);
      currMax += num;
      sumMax = max(sumMax, currMax);

      currMin = min(currMin, 0);
      currMin += num;
      sumMin = min(sumMin, currMin);

      sumTotal += num;
    }

    if (sumTotal == sumMin)
      return sumMax;

    return max(sumMax, sumTotal - sumMin);
  }
};

int main() {
  Solution s;
  // vector<int> input = {1, -2, 3, -2};
  vector<int> input = {-3, -2, -3};
  // vector<int> input = {-2, 4, -5, 4, -5, 9, 4};
  auto output = s.maxSubarraySumCircular(input);
  return 0;
}
