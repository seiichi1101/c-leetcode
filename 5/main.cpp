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
  // TLE
  // private:
  //   unordered_map<string, bool> map;
  //   bool isValid(string s) {
  //     int size = s.size();
  //     if (map.find(s) != map.end()) {
  //       return map[s];
  //     } else if (size <= 1) {
  //       return true;
  //     } else {
  //       bool res = s[0] == s[size - 1] && isValid(s.substr(1, size - 2));
  //       map[s] = res;
  //       return res;
  //     }
  //   }

  // public:
  //   string longestPalindrome(string s) {
  //     string sub = "";
  //     int size = s.size();
  //     for (int i = size; i > 0; i--) {
  //       for (int j = 0; j + i < size + 1; j++) {
  //         sub = s.substr(j, i);
  //         if (isValid(sub))
  //           return sub;
  //       }
  //     }

  //     return sub;
  //   }

public:
  string longestPalindrome(string s) {
    string res = "";
    int size = s.size();
    vector<vector<bool>> dp(size, vector<bool>(size));
    for (int i = 0; i < size; i++) {
      res = s[i];
      dp[i][i] = true;
    }

    for (int i = 0; i < size; i++) {
      if (s[i] == s[i + 1]) {
        res = s.substr(i, 2);
        dp[i][i + 1] = true;
      }
    }

    for (int i = 2; i < size; i++) {
      for (size_t j = 0; j + i < size; j++) {
        if (s[j] == s[j + i] && dp[j + 1][j + i - 1]) {
          res = s.substr(j, i + 1);
          dp[j][j + i] = true;
        }
      }
    }

    return res;
  }
};

int main() {
  Solution s;
  // string input = "babad";
  string input = "cbbd";
  // string input =
  //     "zudfweormatjycujjirzjpyrmaxurectxrtqedmmgergwdvjmjtstdhcihacqnothgttgqfy"
  //     "wcpgnuvwglvfiuxteopoyizgehkwuvvkqxbnufkcbodlhdmbqyghkojrgokpwdhtdrwmvdeg"
  //     "wycecrgjvuexlguayzcammupgeskrvpthrmwqaqsdcgycdupykppiyhwzwcplivjnnvwhqkk"
  //     "xildtyjltklcokcrgqnnwzzeuqioyahqpuskkpbxhvzvqyhlegmoviogzwuiqahiouhnecjw"
  //     "ysmtarjjdjqdrkljawzasriouuiqkcwwqsxifbndjmyprdozhwaoibpqrthpcjphgsfbeqrq"
  //     "qoqiqqdicvybzxhklehzzapbvcyleljawowluqgxxwlrymzojshlwkmzwpixgfjljkmwdtje"
  //     "abgyrpbqyyykmoaqdambpkyyvukalbrzoyoufjqeftniddsfqnilxlplselqatdgjziphvrb"
  //     "okofvuerpsvqmzakbyzxtxvyanvjpfyvyiivqusfrsufjanmfibgrkwtiuoykiavpbqeyfsu"
  //     "teuxxjiyxvlvgmehycdvxdorpepmsinvmyzeqeiikajopqedyopirmhymozernxzaueljjrh"
  //     "csofwyddkpnvcvzixdjknikyhzmstvbducjcoyoeoaqruuewclzqqqxzpgykrkygxnmlsrju"
  //     "doaejxkipkgmcoqtxhelvsizgdwdyjwuumazxfstoaxeqqxoqezakdqjwpkrbldpcbbxexqu"
  //     "qrznavcrprnydufsidakvrpuzgfisdxreldbqfizngtrilnbqboxwmwienlkmmiuifrvytuk"
  //     "cqcpeqdwwucymgvyrektsnfijdcdoawbcwkkjkqwzffnuqituihjaklvthulmcjrhqcyzvek"
  //     "zqlxgddjoir";
  auto output = s.longestPalindrome(input);
  return 0;
}
