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
  string simplifyPath(string path) {
    vector<string> stack;
    string tmp = "";
    for (size_t i = 0; i < path.size() + 1; i++) {
      if (!tmp.empty() && (path[i] == '/' || i == path.size())) {
        if (tmp == ".") {
          ;
        } else if (tmp == "..") {
          if (!stack.empty()) {
            stack.pop_back();
          }
        } else {
          stack.push_back(tmp);
        }
        tmp = "";
      }

      if (path[i] != '/' && i < path.size()) {
        tmp.push_back(path[i]);
      }
    }

    if (stack.empty()) {
      return "/";
    }

    string res;
    for (auto &&e : stack) {
      res += ("/" + e);
    }
    return res;
  }
};

int main() {
  Solution s;
  // auto input = "/home/user/Documents/../Pictures";
  // auto input = "/home//foo/";
  auto input = "/../";
  // auto input = "/.../a/../b/c/../d/./";
  // auto input = "/a//b////c/d//././/..";
  auto output = s.simplifyPath(input);
  return 0;
}
