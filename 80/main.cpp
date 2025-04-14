#include "../util.hpp"
#include <bitset>
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
  int removeDuplicates(vector<int> &nums) {
    int size = nums.size();
    if (size < 3) {
      return size;
    }

    // int max = nums[0];
    int cnt = 1;
    int i = 1, j = 1;
    while (j < size) {
      if (nums[j - 1] == nums[j]) {
        cnt++;
        if (cnt > 2) {
          j++;
          continue;
        }
      } else {
        cnt = 1;
      }

      nums[i] = nums[j];
      i++;
      j++;
    }
    return i - 1;
  }
};

int main() {
  Solution s;
  // vector<int> input = {1, 1, 1, 2, 2, 3};
  vector<int> input = {0, 0, 1, 1, 1, 1, 2, 3, 3};
  auto output = s.removeDuplicates(input);
  return 0;
}
