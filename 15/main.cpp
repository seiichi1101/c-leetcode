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
  // vector<vector<int>> threeSum(vector<int> &nums) {
  //   int size = nums.size();
  //   unordered_set<string> visited;
  //   vector<vector<int>> res{};
  //   sort(nums.begin(), nums.end());
  //   for (size_t i = 0; i < size; i++) {
  //     int left = i + 1;
  //     int right = size - 1;
  //     while (left < right) {
  //       int sum = nums[i] + nums[left] + nums[right];
  //       if (sum == 0) {
  //         string s = to_string(nums[i]) + to_string(nums[left]) +
  //                    to_string(nums[right]);
  //         if (visited.find(s) == visited.end()) {
  //           res.push_back(vector<int>{nums[i], nums[left], nums[right]});
  //           visited.insert(s);
  //         }
  //         left++;
  //         right--;
  //       } else if (sum < 0) {
  //         left++;
  //       } else {
  //         right--;
  //       }
  //     }
  //   }

  //   return res;
  // }

  // Optimized (skip duplications)
  vector<vector<int>> threeSum(vector<int> &nums) {
    int size = nums.size();
    vector<vector<int>> res{};
    sort(nums.begin(), nums.end());
    for (size_t i = 0; i < size; i++) {
      // skip duplicate first elements
      if (i > 0 && nums[i] == nums[i - 1])
        continue;

      int left = i + 1;
      int right = size - 1;
      while (left < right) {
        int sum = nums[i] + nums[left] + nums[right];
        if (sum == 0) {
          res.push_back(vector<int>{nums[i], nums[left], nums[right]});

          // Skip duplicates
          while (left < right && nums[left] == nums[left + 1])
            left++;
          while (left < right && nums[right] == nums[right - 1])
            right--;

          left++;
          right--;
        } else if (sum < 0) {
          left++;
        } else {
          right--;
        }
      }
    }

    return res;
  }
};

int main() {
  Solution s;
  vector<int> input = {-1, 0, 1, 2, -1, -4};
  auto output = s.threeSum(input);
  return 0;
}
