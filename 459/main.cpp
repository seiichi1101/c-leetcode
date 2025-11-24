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
  // Faster
  bool repeatedSubstringPattern(string s) {
    int size = s.size();
    if (size == 1)
      return false;
    for (size_t i = 1; i <= size / 2; i++) {
      if (size % i == 0) {
        int sub_size = i == 1 ? i : size / i;
        bool flag = true;
        for (size_t j = 0; j < sub_size; j++) {
          char c = s[j];
          for (size_t k = sub_size; k < size; k += sub_size) {
            if (c != s[j + k]) {
              flag = false;
              break;
            }
          }
          if (!flag)
            break;
        }
        if (flag)
          return true;
      }
    }
    return false;
  }

  // Simple
  //   bool repeatedSubstringPattern(string s) {
  //     int size = s.size();
  //     if (size == 1)
  //       return false;
  //     for (size_t i = 1; i <= size / 2; i++) {
  //       if (size % i == 0) {
  //         string sub = "";
  //         for (size_t j = 0; j < size / i; j++) {
  //           sub += s.substr(0, i);
  //         }
  //         if (s == sub)
  //           return true;
  //       }
  //     }
  //     return false;
  //   }
};

int main() {
  Solution s;
  // vector<int> input1 = {1, 2, 3, 1};
  // auto output = s.findPeakElement(input1);
  assert(s.repeatedSubstringPattern("abcabcabc") == true);
  assert(s.repeatedSubstringPattern("abcdeabcde") == true);
  assert(s.repeatedSubstringPattern("aba") == false);
  assert(s.repeatedSubstringPattern("abac") == false);
  assert(s.repeatedSubstringPattern("abab") == true);
  assert(s.repeatedSubstringPattern("bb") == true);
  assert(s.repeatedSubstringPattern("ababba") == false);
  assert(s.repeatedSubstringPattern("ababab") == true);
  return 0;
}
