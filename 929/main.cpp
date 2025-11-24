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
  int numUniqueEmails(vector<string> &emails) {
    unordered_set<string> set;
    for (auto &&email : emails) {

      string forward = email.substr(0, email.find('@'));
      string backward = email.substr(email.find('@'), email.size());
      for (size_t i = 0; i < forward.size(); i++) {
        if (forward[i] == '.') {
          forward.erase(i, 1);
          i--;
        }
        if (forward[i] == '+') {
          forward.erase(i);
          break;
        }
      }
      set.insert(forward + backward);
    }

    return set.size();
  }
};

int main() {
  Solution s;
  vector<string> input1 = {"test.email+alex@leetcode.com",
                           "test.e.mail+bob.cathy@leetcode.com",
                           "testemail+david@lee.tcode.com"};
  vector<string> input1 = {"a.............@b.com", "a++++++@b.com"};

  return 0;
}
