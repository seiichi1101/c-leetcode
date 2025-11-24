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
  // Too slow
  // int minMeetingRooms(vector<vector<int>> &intervals) {
  //   int res = 0;
  //   vector<int> sorted_list;
  //   for (auto &&list : intervals) {
  //     sorted_list.push_back(list[0]);
  //     sorted_list.push_back(list[1]);
  //   }
  //   sort(sorted_list.begin(), sorted_list.end());

  //   vector<bool> skip_idxs(intervals.size(), false);
  //   for (auto &&v : sorted_list) {
  //     int cnt = 0;
  //     for (size_t i = 0; i < intervals.size(); i++) {
  //       if (!skip_idxs[i]) {
  //         if (intervals[i][0] < v && v <= intervals[i][1])
  //           cnt++;
  //         if (v == intervals[i][1])
  //           skip_idxs[i] = true;
  //       }
  //     }

  //     res = max(res, cnt);
  //   }

  //   return res;
  // }

  // Better
  // int minMeetingRooms(vector<vector<int>> &intervals) {
  //   int res = 0;
  //   sort(intervals.begin(), intervals.end());

  //   unordered_map<int, int> map;
  //   unordered_set<int> set;
  //   for (auto &&list : intervals) {
  //     map[list[0]]++;
  //     map[list[1]]--;
  //     set.insert(list[0]);
  //     set.insert(list[1]);
  //   }
  //   vector<int> sorted_list(set.begin(), set.end());
  //   sort(sorted_list.begin(), sorted_list.end());

  //   int cnt = 0;
  //   for (auto &&i : sorted_list) {
  //     cnt += map[i];
  //     res = max(res, cnt);
  //   }

  //   return res;
  // }

  // Optimized by two pointer
  int minMeetingRooms(vector<vector<int>> &intervals) {
    vector<int> s_list;
    vector<int> e_list;
    for (auto &&list : intervals) {
      s_list.push_back(list[0]);
      e_list.push_back(list[1]);
    }
    sort(s_list.begin(), s_list.end());
    sort(e_list.begin(), e_list.end());

    int si = 0;
    int ei = 0;
    int cnt = 0;
    while (si < s_list.size()) {
      if (s_list[si] >= e_list[ei]) {
        cnt--;
        ei++;
      }
      cnt++;
      si++;
    }

    return cnt;
  }
};

int main() {
  Solution s;
  // vector<vector<int>> input1 = {vector<int>{0, 30}, vector<int>{5, 10},
  //                               vector<int>{15, 20}};
  // vector<vector<int>> input1 = {vector<int>{13, 15}, vector<int>{1, 13}};
  vector<vector<int>> input1 = {vector<int>{9, 10}, vector<int>{4, 9},
                                vector<int>{4, 17}};
  auto output = s.minMeetingRooms(input1);
  return 0;
}
