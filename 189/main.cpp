#include "../util.hpp"
#include <algorithm>
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
  void rotate(vector<int> &nums, int k) {
    int size = nums.size();
    if (k > size) {
      k %= size;
    }
    reverse(nums.begin(), nums.end());
    reverse(nums.begin(), nums.begin() + k);
    reverse(nums.begin() + k, nums.end());

    // int size = nums.size();
    // vector<bool> visit(size);
    // int i = 0;
    // int prev = nums[i];
    // for (size_t j = 0; j < size; j++) {
    //   i = (i + k) % size;
    //   if (visit[i]) {
    //     i++, j--;
    //     prev = nums[i];
    //     continue;
    //   }
    //   int tmp = nums[i];
    //   nums[i] = prev;
    //   prev = tmp;
    //   visit[i] = true;
    // }
  }
};

int main() {
  Solution s;
  // vector<int> input = {1, 2, 3, 4, 5, 6, 7};
  // s.rotate(input, 3);
  vector<int> input = {-1, -100, 3, 99};
  s.rotate(input, 2);
  return 0;
}
