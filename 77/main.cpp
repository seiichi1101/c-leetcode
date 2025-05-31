#include "../util.hpp"
#include <algorithm>
#include <bitset>
#include <cassert>
#include <climits>
#include <iostream>
#include <optional>
#include <queue>
#include <stack>
#include <string>
#include <unordered_map>
#include <unordered_set>
#include <vector>

using namespace std;

class Solution {
private:
  void _combine(int i, int n, int k, vector<int> &curr,
                vector<vector<int>> &res) {
    if (k == 0) {
      res.push_back(curr);
      return;
    }
    for (; i <= n; i++) {
      curr.push_back(i);
      _combine(i + 1, n, k - 1, curr, res);
      curr.pop_back();
    }
  }

public:
  vector<vector<int>> combine(int n, int k) {
    vector<int> curr;
    vector<vector<int>> res;

    _combine(1, n, k, curr, res);
    return res;
  }
};

int main() {
  Solution s;
  auto output = s.combine(4, 2);
  return 0;
}
