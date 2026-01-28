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
  int binarySearch(int s, int e, vector<int>& nums) {
    if (s == e)
      return nums[s];

    int mid = s + (e - s) / 2;
    if (mid % 2 == 1)
      mid--;

    if (nums[mid] == nums[mid + 1])
      return binarySearch(mid + 2, e, nums);
    else
      return binarySearch(s, mid, nums);
  }

  int singleNonDuplicate(vector<int>& nums) { return binarySearch(0, nums.size() - 1, nums); };

  int main() {
    Solution s;
    vector<int> input1 = {1, 1, 2, 3, 3, 4, 4, 8, 8};
    auto output = s.singleNonDuplicate(input1);
    assert(output == 2);
    return 0;
  }
};
