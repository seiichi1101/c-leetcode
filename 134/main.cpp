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
  int canCompleteCircuit(vector<int> &gas, vector<int> &cost) {
    int size = gas.size();
    int startIdx = 0;
    int diff = 0;
    int sum = 0;
    for (size_t i = 0; i < size; i++) {
      sum += gas[i] - cost[i];
      diff += gas[i] - cost[i];
      if (diff < 0) {
        startIdx = i + 1;
        diff = 0;
      }
    }

    return sum < 0 ? -1 : startIdx;
  }
};

int main() {
  Solution s;
  vector<int> gas = {1, 2, 3, 4, 5};
  vector<int> cost = {3, 4, 5, 1, 2};
  // vector<int> gas = {5, 1, 2, 3, 4};
  // vector<int> cost = {4, 4, 1, 5, 1};
  auto output = s.canCompleteCircuit(gas, cost);
  return 0;
}
