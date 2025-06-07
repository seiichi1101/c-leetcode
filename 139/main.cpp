#include "../util.hpp"
#include <algorithm>
#include <bitset>
#include <cassert>
#include <climits>
#include <iostream>
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
  vector<bool> visited;

public:
  // Memorize with visited
  bool _wordBreak(string sub, set<string> &wordSet, int idx) {
    for (auto &&word : wordSet) {
      if (sub == word)
        return true;
      if (sub.starts_with(word) && !visited[idx + word.size() - 1]) {
        visited[idx + word.size() - 1] = true;
        if (_wordBreak(sub.substr(word.size(), sub.size()), wordSet,
                       idx + word.size()))
          return true;
      }
    }
    return false;
  }

  bool wordBreak(string s, vector<string> &wordDict) {
    visited = vector<bool>(s.size());
    set<string> wordSet(wordDict.begin(), wordDict.end());
    return _wordBreak(s, wordSet, 0);
  }

  // Memorize with dp
  // bool wordBreak(string s, vector<string> &wordDict) {
  //   int size = s.size();
  //   vector<bool> dp(size + 1, false);
  //   dp[0] = true;

  //   for (int i = 1; i < size + 1; i++) {
  //     for (string word : wordDict) {
  //       int start = i - word.size();
  //       if (start >= 0 && s.substr(start, word.size()) == word &&
  //           dp[start] == true) {
  //         dp[i] = true;
  //       }
  //     }
  //   }

  //   return dp[size];
  // }
};

int main() {
  Solution s;
  // string word = "leetcode";
  // vector<string> wordDict{"leet", "code", "code"};
  // string word = "applepenapple";
  // vector<string> wordDict{"apple", "pen"};
  // string word = "catsandog";
  // vector<string> wordDict{"cats", "dog", "sand", "and", "cat"};
  // string word =
  // "aaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa"
  //               "aaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa"
  //               "aaaaaaaaaaaaaaaaaaaaaaaaaab";
  // vector<string> wordDict{"a",         "aa",        "aaa",     "aaaa",
  //                         "aaaaa",     "aaaaaa",    "aaaaaaa", "aaaaaaaa",
  //                         "aaaaaaaaa", "aaaaaaaaaa"};
  // string word = "abcd";
  // vector<string> wordDict{"a", "abc", "b", "cd"};
  // string word = "goalspecial";
  // vector<string> wordDict{"go", "goal", "goals", "special"};
  string word = "catskicatcats";
  vector<string> wordDict{"cats", "cat", "dog", "ski"};
  auto output = s.wordBreak(word, wordDict);
  return 0;
}
