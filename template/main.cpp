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
  int test(vector<int> v) {
    cout << "test\n";
    return v[0];
  }
};

int main() {
  Solution s;
  vector<int> input1 = {1, 2, 3};
  auto output = s.test(input1);
  assert(s.test(vector<int>{1, 2, 3}) == 1);
  return 0;
}
