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
  bool containsDuplicate(vector<int> &nums) {
    unordered_set<int> map{};
    for (auto &&n : nums) {
      if (map.find(n) != map.end())
        return true;
      else
        map.insert(n);
    }

    return false;
  }
};

int main() {
  Solution s;
  vector<int> input1{1, 2, 3};
  assert(s.containsDuplicate(input1) == false);
  vector<int> input2{1, 2, 3, 1};
  assert(s.containsDuplicate(input2) == true);
  return 0;
}
