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
  int totalFruit(vector<int> &fruits) {
    if (fruits.size() <= 1)
      return fruits.size();
    int total = 1;
    size_t last = 0;
    unordered_set<int> set{fruits[0]};
    int cnt = 1;
    for (size_t i = 1; i < fruits.size(); i++) {
      if (set.find(fruits[i]) != set.end()) {
        cnt++;
        total = max(total, cnt);
      } else {
        if (set.size() < 2) {
          cnt++;
          set.insert(fruits[i]);
          total = max(total, cnt);
        } else {
          set.erase(fruits[last]);
          set.insert(fruits[i]);
          cnt = i - last;
        }
      }

      if (fruits[i - 1] != fruits[i])
        last = i - 1;
    }

    return total;
  }
};

int main() {
  Solution s;
  vector<int> input1 = {0, 1, 2, 2};
  // vector<int> input1 = {1, 2, 3, 2, 2};
  // vector<int> input1 = {3, 3, 3, 1, 2, 1, 1, 2, 3, 3, 4};
  // vector<int> input1 = {0, 1, 1, 4, 3};
  // vector<int> input1 = {1, 0, 3, 4, 3};
  auto output = s.totalFruit(input1);
  return 0;
}
