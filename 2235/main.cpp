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
  int sum(int num1, int num2) { return num1 + num2; }
};

int main() {
  Solution s;
  int input1 = 12;
  int input2 = 5;
  auto output1 = s.sum(input1, input2);
  assert(output1 == 17);
  return 0;
}
