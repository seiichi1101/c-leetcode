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
public:
  vector<int> findOrder(int numCourses, vector<vector<int>> &prerequisites) {
    vector<int> res;
    vector<vector<int>> graph(numCourses);
    vector<int> inDegree(numCourses);
    for (auto &&p : prerequisites) {
      graph[p[1]].push_back(p[0]);
      inDegree[p[0]]++;
    }
    queue<int> queue;
    for (size_t i = 0; i < numCourses; i++) {
      if (inDegree[i] == 0)
        queue.push(i);
    }

    while (!queue.empty()) {
      int num = queue.front();
      queue.pop();
      res.push_back(num);
      for (auto &&n : graph[num]) {
        inDegree[n]--;
        if (inDegree[n] == 0)
          queue.push(n);
      }
    }

    return res.size() == numCourses ? res : vector<int>{};
  }
};

int main() {
  Solution s;
  int input1 = 2;
  vector<vector<int>> input2 = {vector<int>{1, 0}, vector<int>{0, 1}};
  // int input1 = 4;
  // vector<vector<int>> input2 = {vector<int>{1, 0}, vector<int>{2, 0},
  //                               vector<int>{3, 1}, vector<int>{3, 2}};
  auto output = s.findOrder(input1, input2);
  return 0;
}
