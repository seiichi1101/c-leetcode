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
  int findMin(vector<int> &nums) {
    int size = nums.size();
    if (size == 1)
      return nums[0];
    if (size == 2)
      return min(nums[0], nums[1]);

    int mid = size / 2;
    if (nums[0] < nums[size - 1])
      return nums[0];

    if (nums[mid] < nums[size - 1]) {
      vector<int> newNums(nums.begin(), nums.begin() + mid + 1);
      return findMin(newNums);
    } else {
      vector<int> newNums(nums.begin() + mid + 1, nums.end());
      return findMin(newNums);
    }
  }
};

int main() {
  Solution s;
  vector<int> input = {3, 4, 5, 1, 2};
  // vector<int> input = {4, 5, 6, 7, 0, 1, 2};
  auto output = s.findMin(input);
  return 0;
}
