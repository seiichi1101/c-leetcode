#include "../util.hpp"
#include <algorithm>
#include <bitset>
#include <cassert>
#include <climits>
#include <iostream>
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
  // // max heap
  // int findKthLargest(vector<int> &nums, int k) {
  //   priority_queue<int> heap(nums.begin(),
  //                            nums.end()); // created by heapify:O(N)
  //   for (size_t i = 0; i < k - 1; i++)
  //     heap.pop();
  //   return heap.top();
  // }

  // optimized max heap
  int findKthLargest(vector<int> &nums, int k) {
    priority_queue<int> heap;
    for (auto &&n : nums) {
      // Hold at most k elements in the heap to avoid extra exploration
      heap.push(-n);
      if (heap.size() > k)
        heap.pop();
    }
    return -heap.top();
  }
};

int main() {
  Solution s;
  vector<int> input = {3, 2, 1, 5, 6, 4};
  int k = 2;
  auto output = s.findKthLargest(input, k);
  return 0;
}
