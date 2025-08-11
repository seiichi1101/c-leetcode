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
#include <stack>
#include <string>
#include <unordered_map>
#include <unordered_set>
#include <vector>

using namespace std;

class Solution {
public:
  vector<int> findSubstring(string s, vector<string> &words) {
    vector<int> res = {};
    int wordNum = words.size();
    int wordLen = words[0].size();
    int totalLen = wordNum * wordLen;
    if ((int)s.size() < totalLen)
      return res;

    unordered_map<string, int> need;
    for (auto &w : words)
      need[w]++;

    for (int i = 0; i < wordLen; i++) {
      int left = i;
      int right = i;
      int used = 0;
      unordered_map<string, int> have;

      while (right + wordLen <= s.size()) {
        string sub = s.substr(right, wordLen);
        right += wordLen;

        if (!need.count(sub)) {
          have.clear();
          used = 0;
          left = right;
          continue;
        }

        have[sub]++;
        if (have[sub] <= need[sub]) {
          used++;
        } else {
          while (have[sub] > need[sub]) {
            // 余剰になった分が解消されるまで進める
            string lw = s.substr(left, wordLen);
            left += wordLen;
            have[lw]--;
            if (have[lw] < need[lw])
              used--;
          }
        }

        if (right - left == totalLen && used == wordNum) {
          res.push_back(left);
          string lw = s.substr(left, wordLen);
          left += wordLen;
          if (--have[lw] < need[lw])
            used--;
        }
      }
    }
    return res;
  }
};

int main() {
  Solution s;
  // string str = "barfoothefoobarman";
  // vector<string> words{"foo", "bar"};
  // string str = "barfoofoobarthefoobarman";
  // vector<string> words{"foo", "bar", "the"};
  // string str = "wordgoodgoodgoodbestword";
  // vector<string> words{"word", "good", "best", "word"};
  string str = "wordgoodgoodgoodbestword";
  vector<string> words{"word", "good", "best", "good"};
  // string str = "barfoofoobarthefoobarman";
  // vector<string> words{"bar", "foo", "the"};
  // string str = "lingmindraboofooowingdingbarrwingmonkeypoundcake";
  // vector<string> words{"fooo", "barr", "wing", "ding", "wing"};
  auto output = s.findSubstring(str, words);
  return 0;
}
