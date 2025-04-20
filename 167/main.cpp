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
  vector<int> twoSum(vector<int> &numbers, int target) {
    int i = 0, j = numbers.size() - 1;
    while (i < j) {
      if (numbers[i] + numbers[j] < target) {
        i++;
      } else if (numbers[i] + numbers[j] > target) {
        j--;
      } else {
        break;
      }
    }
    vector<int> res = {i + 1, j + 1};
    return res;
  }
};

int main() {
  Solution s;
  vector<int> input = {2, 7, 11, 15};
  auto output = s.twoSum(input, 9);
  return 0;
}
