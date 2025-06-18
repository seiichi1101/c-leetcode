#include "../util.hpp"
#include <algorithm>
#include <bitset>
#include <cassert>
#include <climits>
#include <iostream>
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
  int search(vector<int> &nums, int target) {
    int size = nums.size();
    if (size == 1)
      return nums[0] == target ? 0 : -1;

    int s = 0, e = size - 1, m = size / 2;
    if (nums[s] == target)
      return s;
    if (nums[e] == target)
      return e;
    if (nums[m] == target)
      return m;

    if (nums[s] < nums[m] && nums[m] < nums[e]) {
      if (target < nums[m]) {
        vector<int> newNums(nums.begin(), nums.begin() + m);
        int res = search(newNums, target);
        return res;
      } else {
        vector<int> newNums(nums.begin() + m, nums.end());
        int res = search(newNums, target);
        return res < 0 ? res : m + res;
      }
    } else if (nums[s] < nums[m] && nums[m] > nums[e]) {
      if (nums[s] < target && target < nums[m]) {
        vector<int> newNums(nums.begin(), nums.begin() + m);
        int res = search(newNums, target);
        return res;
      } else {
        vector<int> newNums(nums.begin() + m, nums.end());
        int res = search(newNums, target);
        return res < 0 ? res : m + res;
      }
    } else {
      if (nums[m] < target && target < nums[e]) {
        vector<int> newNums(nums.begin() + m, nums.end());
        int res = search(newNums, target);
        return res < 0 ? res : m + res;
      } else {
        vector<int> newNums(nums.begin(), nums.begin() + m);
        int res = search(newNums, target);
        return res;
      }
    }
    return -1;
  }
};

int main() {
  Solution s;
  vector<int> input = {4, 5, 6, 7, 0, 1, 2};
  int target = 0;
  auto output = s.search(input, target);
  return 0;
}
