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
  vector<int> searchRange(vector<int> &nums, int target) {
    int size = nums.size();
    int mid = size / 2;
    if (size == 0)
      return {-1, -1};
    if (size == 1)
      return nums[0] != target ? vector<int>{-1, -1} : vector<int>{0, 0};

    if (target < nums[mid]) {
      vector<int> left(nums.begin(), nums.begin() + mid);
      vector<int> res = searchRange(left, target);
      return res;
    } else if (nums[mid] < target) {
      vector<int> right(nums.begin() + mid, nums.end());
      vector<int> res = searchRange(right, target);
      res[0] = res[0] != -1 ? res[0] + mid : res[0];
      res[1] = res[1] != -1 ? res[1] + mid : res[1];
      return res;
    } else {
      vector<int> left(nums.begin(), nums.begin() + mid);
      vector<int> resL = searchRange(left, target);
      vector<int> right(nums.begin() + mid + 1, nums.end());
      vector<int> resR = searchRange(right, target);
      int l = resL[0] != -1 ? resL[0] : mid;
      int r = resR[1] != -1 ? resR[1] + mid + 1 : mid;
      return vector<int>{l, r};
    }
  }
};

int main() {
  Solution s;
  vector<int> input1 = {5, 7, 7, 8, 8, 10};
  int input2 = 8;
  auto output = s.searchRange(input1, input2);
  return 0;
}
