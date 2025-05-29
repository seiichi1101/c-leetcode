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
  int minMutation(string startGene, string endGene, vector<string> &bank) {
    if (bank.size() == 0)
      return -1;

    unordered_set<string> bankSet(bank.begin(), bank.end());
    queue<string> queue;
    unordered_set<string> visited;

    queue.push(startGene);
    visited.insert(startGene);
    int cnt = 0;
    while (!queue.empty()) {
      int size = queue.size();

      for (int i = 0; i < size; i++) {
        string node = queue.front();
        queue.pop();
        if (node == endGene)
          return cnt;

        for (char c : "ACGT") {
          for (int j = 0; j < node.size(); j++) {
            string tmp = node;
            tmp[j] = c;
            if (!visited.count(tmp) && bankSet.find(tmp) != bankSet.end()) {
              queue.push(tmp);
              visited.insert(tmp);
            }
          }
        }
      }
      cnt++;
    }

    return -1;
  }
};

int main() {
  Solution s;
  string startGen = "AACCGGTT";
  string endGen = "AAACGGTA";
  vector<string> bank{"AACCGGTA", "AACCGCTA", "AAACGGTA"};
  auto output = s.minMutation(startGen, endGen, bank);
  return 0;
}
