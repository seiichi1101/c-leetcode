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
public:
  vector<vector<string>> groupAnagrams(vector<string> &strs) {
    int size = strs.size();
    unordered_map<string, vector<string>> map;
    for (auto &&str : strs) {
      int sum[26](0);
      for (auto &&c : str) {
        sum[c - 'a']++;
      }
      string key = "";
      for (auto &&e : sum) {
        key += (to_string(e) + "#");
      }
      map[key].push_back(str);
    }

    vector<vector<string>> res;
    for (auto &&e : map) {
      res.push_back(e.second);
    }

    return res;
  }
};

int main() {
  Solution s;
  vector<string> input = {"eat", "tea", "tan", "ate", "nat", "bat"};
  auto output = s.groupAnagrams(input);
  return 0;
}
