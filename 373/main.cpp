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

struct Compare {
  bool operator()(const vector<int> &a, const vector<int> &b) const {
    return a[0] + a[1] > b[0] + b[1];
  }
};

class Solution {
public:
  // vector<vector<int>> kSmallestPairs(vector<int> &nums1, vector<int> &nums2,
  //                                    int k) {
  //   vector<vector<int>> res;
  //   int size = nums1.size();
  //   int s1 = 0, s2 = 0;
  //   while (s1 < size - 1 || s2 < size - 1) {
  //     int num1 = nums1[s1];
  //     int num2 = nums2[s2];
  //     res.push_back(vector<int>{num1, num2});
  //     int i = s1 + 1, j = s2 + 1;
  //     while (i < size || j < size) {
  //       if (res.size() == k) {
  //         return res;
  //       }
  //       if (i == size) {
  //         res.push_back(vector<int>{num1, nums2[j]});
  //         j++;
  //       } else if (j == size) {
  //         res.push_back(vector<int>{nums1[i], num2});
  //         i++;
  //       } else {
  //         if (num1 + nums2[j] < nums1[i], num2) {
  //           res.push_back(vector<int>{num1, nums2[j]});
  //           j++;
  //         } else {
  //           res.push_back(vector<int>{nums1[i], num2});
  //           i++;
  //         }
  //       }
  //     }
  //     s1++, s2++;
  //   }

  //   return res;
  // }

  // TLE
  // vector<vector<int>> kSmallestPairs(vector<int> &nums1, vector<int> &nums2,
  //                                    int k) {
  //   vector<vector<int>> res;
  //   priority_queue<vector<int>, vector<vector<int>>, Compare> queue;
  //   for (size_t i = 0; i < nums1.size(); i++) {
  //     for (size_t j = 0; j < nums2.size(); j++) {
  //       queue.push(vector<int>{nums1[i], nums2[j]});
  //     }
  //   }

  //   while (res.size() < k) {
  //     res.push_back(queue.top());
  //     queue.pop();
  //   }

  //   return res;
  // }

  // Optimized heap
  vector<vector<int>> kSmallestPairs(vector<int> &nums1, vector<int> &nums2,
                                     int k) {
    int m = nums1.size();
    int n = nums2.size();

    vector<vector<int>> ans;
    set<pair<int, int>> visited;

    priority_queue<pair<int, pair<int, int>>, vector<pair<int, pair<int, int>>>,
                   greater<pair<int, pair<int, int>>>>
        minHeap;
    minHeap.push({nums1[0] + nums2[0], {0, 0}});
    visited.insert({0, 0});

    while (k-- && !minHeap.empty()) {
      auto top = minHeap.top();
      minHeap.pop();
      int i = top.second.first;
      int j = top.second.second;

      ans.push_back({nums1[i], nums2[j]});

      if (i + 1 < m && visited.find({i + 1, j}) == visited.end()) {
        minHeap.push({nums1[i + 1] + nums2[j], {i + 1, j}});
        visited.insert({i + 1, j});
      }

      if (j + 1 < n && visited.find({i, j + 1}) == visited.end()) {
        minHeap.push({nums1[i] + nums2[j + 1], {i, j + 1}});
        visited.insert({i, j + 1});
      }
    }

    return ans;
  }
};

int main() {
  Solution s;
  vector<int> input1 = {1, 7, 14};
  vector<int> input2 = {2, 4, 6};
  int k = 8;
  auto output = s.kSmallestPairs(input1, input2, k);
  return 0;
}
