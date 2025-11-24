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
  int nextBeautifulNumber(int n) {
    if (n == 0)
      return 1;
    int size = 1;
    int div = 10;
    while (n >= div) {
      size++;
      div *= 10;
    }
    int res = get_list(n, size);

    return res;
  }

  int get_list(int n, int size) {
    vector<int> candidate;
    for (int i = 1; i < size + 1; i++) {
      candidate.push_back(i);
    }

    vector<int> pattern;
    vector<vector<int>> combs;

    for (int i = 1; i < size; i++) {
      dfs_combination(candidate, 0, i, pattern, combs, size);
    }

    vector<vector<int>> candidates;
    for (auto &&comb : combs) {
      vector<int> tmp;
      for (auto &&c : comb) {
        for (size_t i = 0; i < c; i++) {
          tmp.push_back(c);
        }
      }
      candidates.push_back(tmp);
    }

    unordered_set<int> perms;
    vector<int> curr;
    vector<int> visited;

    for (auto &&c : candidates) {
      backtrack(curr, perms, c, visited);
    }

    vector<int> res;
    for (auto &&p : perms) {
      res.push_back(p);
    }
    sort(res.begin(), res.end());
    for (auto &&r : res) {
      if (r > n)
        return r;
    }
    return get_list(n, size + 1);
  }

  void dfs_combination(vector<int> &candidates, int i, int pick,
                       vector<int> &pattern, vector<vector<int>> &result,
                       int size) {
    if (pick == 0) {
      int sum = 0;

      // ここで判定
      for (auto &&p : pattern) {
        sum += p;
      }
      if (sum == size)
        result.push_back(pattern);
      return;
    }
    if ((i + pick) > candidates.size()) {
      return;
    }

    pattern.push_back(candidates[i]);
    dfs_combination(candidates, i + 1, pick - 1, pattern, result, size);
    pattern.pop_back();
    dfs_combination(candidates, i + 1, pick, pattern, result, size);
  }

  void backtrack(vector<int> &curr, unordered_set<int> &ans, vector<int> &nums,
                 vector<int> &visited) {
    if (curr.size() == nums.size()) {
      int sum = 0;
      int tmp = 1;
      for (auto &&c : curr) {
        sum += c * tmp;
        tmp *= 10;
      }
      ans.insert(sum);

      return;
    }

    for (size_t i = 0; i < nums.size(); i++) {
      int num = nums[i];
      if (find(visited.begin(), visited.end(), i) == visited.end()) {
        curr.push_back(num);
        visited.push_back(i);
        backtrack(curr, ans, nums, visited);
        curr.pop_back();
        visited.pop_back();
      }
    }
  }
};

int main() {
  Solution s;
  int input1 = 0;
  // int input1 = 1;
  // int input1 = 1000;
  // int input1 = 3000;
  auto output = s.nextBeautifulNumber(input1);
  return 0;
}
