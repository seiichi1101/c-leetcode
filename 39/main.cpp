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
private:
  void comb(vector<int> &candidates, int start, int target, vector<int> &curr,
            vector<vector<int>> &ans) {
    for (int i = start; i < candidates.size(); i++) {
      int c = candidates[i];
      curr.push_back(c);
      if (target - c == 0) {
        ans.push_back(curr);
      } else if (target - c > 0) {
        comb(candidates, i, target - c, curr, ans);
      }
      curr.pop_back();
    }
  };

public:
  vector<vector<int>> combinationSum(vector<int> &candidates, int target) {
    vector<vector<int>> ans;
    vector<int> curr;
    comb(candidates, 0, target, curr, ans);
    return ans;
  }
};

int main() {
  Solution s;
  vector<int> input1 = {2, 3, 6, 7};
  int input2 = 7;
  auto output = s.combinationSum(input1, input2);
  return 0;
}
