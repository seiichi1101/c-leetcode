#include "../util.hpp"
#include <algorithm>
#include <bitset>
#include <cassert>
#include <climits>
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
  // NLog(N)
  // int candy(vector<int> &ratings) {
  //   priority_queue<pair<int, int>, vector<pair<int, int>>,
  //                  greater<pair<int, int>>>
  //       minHeap;
  //   vector<int> scores(ratings.size(), 0);
  //   for (int i = 0; i < ratings.size(); i++) {
  //     minHeap.push({ratings[i], i});
  //   }

  //   while (!minHeap.empty()) {
  //     pair<int, int> node = minHeap.top();
  //     int score = 1;
  //     if (node.second - 1 >= 0 &&
  //         ratings[node.second - 1] < ratings[node.second])
  //       score = max(score, scores[node.second - 1] + 1);
  //     if (node.second + 1 < ratings.size() &&
  //         ratings[node.second + 1] < ratings[node.second])
  //       score = max(score, scores[node.second + 1] + 1);
  //     scores[node.second] = score;
  //     minHeap.pop();
  //   }

  //   return accumulate(scores.begin(), scores.end(), 0);
  // }
  int candy(vector<int> &ratings) {
    vector<int> scores(ratings.size(), 1);

    // left to right
    for (int i = 1; i < ratings.size(); i++) {
      scores[i] = ratings[i - 1] < ratings[i] ? scores[i - 1] + 1 : scores[i];
    }

    // right to left
    for (int i = ratings.size() - 2; i > -1; i--) {
      scores[i] = ratings[i] > ratings[i + 1]
                      ? max(scores[i], scores[i + 1] + 1)
                      : scores[i];
    }
    return accumulate(scores.begin(), scores.end(), 0);
  }
};

int main() {
  Solution s;
  // vector<int> input = {1, 0, 2};
  vector<int> input = {1, 3, 4, 5, 2};
  auto output = s.candy(input);
  return 0;
}
