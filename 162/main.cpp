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
  // Linear Log(N)
  // int findPeakElement(vector<int> &nums) {
  //   int size = nums.size();
  //   if (size == 1)
  //     return 0;
  //   for (size_t i = 0; i < size - 1; i++) {
  //     if (nums[i] > nums[i + 1])
  //       return i;
  //   }
  //   return size - 1;
  // }

  // BinarySearch Log(N)
  int findPeakElement(vector<int> &nums) {
    int size = nums.size();
    if (size == 1) {
      return 0;
    } else if (size == 2) {
      if (nums[0] > nums[1])
        return 0;
      else
        return 1;
    } else {
      int mid = size / 2;
      if (nums[mid - 1] < nums[mid] && nums[mid] > nums[mid + 1])
        return mid;
      else if (nums[mid - 1] > nums[mid]) {
        vector<int> left(nums.begin(), nums.begin() + mid);
        return findPeakElement(left);
      } else {
        vector<int> right(nums.begin() + mid, nums.end());
        return findPeakElement(right) + mid;
      }
    }
  }
};

int main() {
  Solution s;
  // vector<int> input = {1, 2, 3, 1};
  // vector<int> input = {1, 2, 1, 3, 5, 6, 4};
  vector<int> input = {2, 1};
  auto output = s.findPeakElement(input);
  return 0;
}
