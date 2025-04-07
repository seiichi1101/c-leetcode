#include "util.hpp"
#include <cassert>
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
  int test(vector<int> v) { return v[0]; }
};

int main() {
  Solution s;
  vector<int> input = {1, 2, 3};
  auto output = s.test(input);
  return 0;
}
