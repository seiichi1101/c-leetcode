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
  int hIndex(vector<int> &citations) {
    // order: nlog(n)
    // int size = citations.size();
    // sort(citations.rbegin(), citations.rend());
    // for (size_t i = 0; i < size; i++) {
    //   if (citations[i] < i + 1) {
    //     return i;
    //   }
    // }
    // return size;

    // order: n
    int size = citations.size();
    // citationされた数ごとのカウントをリストアップ (max: size)
    vector<int> cnt(size + 1);
    for (auto &&c : citations) {
      cnt[min(size, c)]++;
    }
    // リストアップしたcntからcitationされた数を満たすかチェック
    int res = 0;
    for (int i = cnt.size() - 1; i >= 0; i--) {
      res += cnt[i];
      if (res >= i) {
        return i;
      }
    }
    return res;
  }
};

int main() {
  Solution s;
  // vector<int> input = {3, 0, 6, 1, 5};
  vector<int> input = {1, 3, 1};
  // vector<int> input = {1};

  auto output = s.hIndex(input);
  return 0;
}
