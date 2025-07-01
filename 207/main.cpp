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
  // optimized
  bool canFinish(int numCourses, vector<vector<int>> &prerequisites) {
    vector<vector<int>> graph(numCourses);
    vector<int> inDegree(numCourses, 0);
    for (auto &p : prerequisites) {
      graph[p[1]].push_back(p[0]);
      inDegree[p[0]]++;
    }
    queue<int> queue;
    for (int i = 0; i < numCourses; i++) {
      if (inDegree[i] == 0)
        queue.push(i);
    }
    int cnt = 0;
    while (!queue.empty()) {
      int node = queue.front();
      queue.pop();
      cnt++;
      for (int next : graph[node]) {
        if (--inDegree[next] == 0)
          queue.push(next);
      }
    }
    return cnt == numCourses;
  }

  // bool canFinish(int numCourses, vector<vector<int>> &prerequisites) {
  //   if (prerequisites.size() == 0)
  //     return true;
  //   unordered_map<int, vector<int>> map;
  //   vector<optional<bool>> result(numCourses, true);
  //   for (auto &&elem : prerequisites) {
  //     map[elem[0]].push_back(elem[1]);
  //     result[elem[0]] = false;
  //     result[elem[1]] = result[elem[1]] == nullopt ? true : result[elem[1]];
  //   }

  //   int cnt = 0;
  //   for (int i = 0; i < numCourses; i++) {
  //     if (result[i] == true)
  //       cnt++;
  //   }

  //   int i = 0;
  //   while (i < prerequisites.size()) {
  //     if (cnt >= numCourses)
  //       return true;

  //     vector<int> elem = prerequisites[i];
  //     if (result[elem[0]] == false) {
  //       bool flag = true;
  //       for (size_t j = 0; j < map[elem[0]].size(); j++) {
  //         if (result[map[elem[0]][j]] == false) {
  //           flag = false;
  //           break;
  //         }
  //       }
  //       if (flag) {
  //         cnt++;
  //         result[elem[0]] = true;
  //         i = 0;
  //         continue;
  //       }
  //     }

  //     i++;
  //   }

  //   return cnt == numCourses;
  // }
};

int main() {
  Solution s;
  // int input1 = 2;
  // vector<vector<int>> input2 = {vector<int>{1, 0}, vector<int>{0, 1}};
  int input1 = 5;
  vector<vector<int>> input2 = {vector<int>{1, 4}, vector<int>{2, 4},
                                vector<int>{3, 1}, vector<int>{3, 2}};
  auto output = s.canFinish(input1, input2);
  return 0;
}
