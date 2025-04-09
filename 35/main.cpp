#include "../util.hpp"
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
  int searchInsert(vector<int> &nums, int target) {
    int size = nums.size();
    int mid = size / 2;
    while (mid > 0 && mid < size && nums[mid] != target) {
      if (nums[mid] < target) {
        mid += mid / 2;
      } else {
        mid -= mid / 2;
      }
    }
    return mid;
  }
};

int main() {
  Solution s;
  vector<int> input = {1, 3, 5, 6};
  auto output = s.searchInsert(input, 2);
  return 0;
}
