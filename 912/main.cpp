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
  vector<int> sortArray(vector<int>& nums) {
    if (nums.size() <= 1)
      return nums;

    int mid = nums.size() / 2;
    vector<int> left(nums.begin(), nums.begin() + mid);
    vector<int> right(nums.begin() + mid, nums.end());
    left = sortArray(left);
    right = sortArray(right);

    int i = 0, l = 0, r = 0;

    while (l < left.size() || r < right.size()) {
      if (l >= left.size()) {
        nums[i] = right[r];
        r++;
      } else if (r >= right.size()) {
        nums[i] = left[l];
        l++;
      } else {
        if (left[l] > right[r]) {
          nums[i] = left[l];
          l++;
        } else {
          nums[i] = right[r];
          r++;
        }
      }
      i++;
    }

    return nums;
  }
};

int main() {
  Solution s;
  vector<int> input1 = {5, 2, 3, 1};
  auto output = s.sortArray(input1);
  vector<int> res{1, 2, 3, 5};
  assert(output == res);
  return 0;
}
