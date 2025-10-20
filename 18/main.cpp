#include "../util.hpp"
#include <algorithm>
#include <bitset>
#include <cassert>
#include <climits>
#include <iostream>
#include <list>
#include <numeric>
#include <optional>
#include <queue>
#include <set>
#include <sstream>
#include <stack>
#include <string>
#include <unordered_map>
#include <unordered_set>
#include <vector>

using namespace std;

class Solution {
public:
  vector<vector<int>> fourSum(vector<int> &nums, int target) {
    vector<vector<int>> res;
    unordered_set<string> tmpRes;
    sort(nums.begin(), nums.end());
    for (int a = 0; a < nums.size(); a++) {
      for (int b = a + 1; b < nums.size(); b++) {
        for (int c = b + 1; c < nums.size(); c++) {
          for (int d = c + 1; d < nums.size(); d++) {
            if (static_cast<long long>(nums[a]) +
                    static_cast<long long>(nums[b]) +
                    static_cast<long long>(nums[c]) +
                    static_cast<long long>(nums[d]) ==
                static_cast<long long>(target))
              tmpRes.insert(to_string(nums[a]) + "," + to_string(nums[b]) +
                            "," + to_string(nums[c]) + "," +
                            to_string(nums[d]));
          }
        }
      }
    }

    for (auto &&elem : tmpRes) {
      stringstream ss(elem);
      string token;

      vector<int> tmp;
      while (getline(ss, token, ',')) {
        tmp.push_back(std::stoi(token));
      }
      res.push_back(tmp);
    }

    return res;
  }
};

int main() {
  Solution s;
  // vector<int> input1 = {1, 0, -1, 0, -2, 2};
  // int input2 = 0;
  vector<int> input1 = {1000000000, 1000000000, 1000000000, 1000000000};
  int input2 = 0;
  auto output = s.fourSum(input1, input2);
  return 0;
}
