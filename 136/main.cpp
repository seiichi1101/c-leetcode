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
  int singleNumber(vector<int> &nums) {
    int res = 0;
    for (auto &&n : nums) {
      res ^= n;
    }
    return res;
  }
};

int main() {
  Solution s;
  vector<int> input = {2, 2, 1};
  auto output = s.singleNumber(input);
  return 0;
}
