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
  vector<int> plusOne(vector<int> &digits) {
    for (int i = digits.size() - 1; i >= 0; i--) {
      if (digits[i] == 9) {
        digits[i] = 0;
      } else {
        digits[i]++;
        return digits;
      }
    }
    digits.insert(digits.begin(), 1);
    return digits;
  }
};

int main() {
  Solution s;
  // vector<int> input = {1, 2, 3};
  vector<int> input = {9};
  auto output = s.plusOne(input);
  return 0;
}
