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
  int lengthOfLIS(vector<int> &nums) {
    vector<int> list;
    list.push_back(nums[0]);
    for (size_t i = 1; i < nums.size(); i++) {
      if (nums[i] > list[list.size() - 1]) {
        list.push_back(nums[i]);
      } else {
        size_t index = 0;
        while (nums[i] > list[index]) {
          index++;
        }
        list[index] = nums[i];
      }
    }

    return list.size();
  }
};

int main() {
  Solution s;
  vector<int> input = {10, 9, 2, 5, 3, 7, 101, 18};
  auto output = s.lengthOfLIS(input);
  return 0;
}
