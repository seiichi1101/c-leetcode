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

private:
  inline static unordered_map<string, vector<string>> phone{
      {"2", {"a", "b", "c"}}, {"3", {"d", "e", "f"}},
      {"4", {"g", "h", "i"}}, {"5", {"j", "k", "l"}},
      {"6", {"m", "n", "o"}}, {"7", {"p", "q", "r", "s"}},
      {"8", {"t", "u", "v"}}, {"9", {"w", "x", "y", "z"}},
  };

public:
  vector<string> letterCombinations(string digits) {
    if (digits.empty()) {
      return vector<string>{};
    }
    if (digits.size() == 1) {
      return phone[digits];
    } else {
      vector<string> res;
      vector<string> currAlphabets = phone[digits.substr(0, 1)];
      string remDigits = digits.substr(1);
      vector<string> remAlphabets = letterCombinations(remDigits);
      for (auto &&ca : currAlphabets) {
        for (auto &&ra : remAlphabets) {
          res.push_back(ca + ra);
        }
      }
      return res;
    }
  }
};

int main() {
  Solution s;
  // string input = "23";
  // string input = "";
  string input = "7";
  auto output = s.letterCombinations(input);
  return 0;
}
