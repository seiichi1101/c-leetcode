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
  int maxProfit(vector<int> &prices) {
    int res = 0;
    for (size_t i = 1; i < prices.size(); i++) {
      res += max(0, prices[i] - prices[i - 1]);
    }
    return res;
  }
};

int main() {
  Solution s;
  // vector<int> input = {7, 1, 5, 3, 6, 4};
  vector<int> input = {1, 2, 3, 4, 5};
  auto output = s.maxProfit(input);
  return 0;
}
