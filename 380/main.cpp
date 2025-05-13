#include "../util.hpp"
#include <algorithm>
#include <bitset>
#include <cassert>
#include <climits>
#include <cmath>
#include <iostream>
#include <optional>
#include <queue>
#include <random>
#include <stack>
#include <string>
#include <unordered_map>
#include <unordered_set>
#include <vector>

using namespace std;

class RandomizedSet {
private:
  std::mt19937 mt32;
  vector<int> list;
  unordered_map<int, uint> map;

public:
  RandomizedSet() {
    std::random_device rd;
    mt32.seed(rd());
  }

  bool insert(int val) {
    auto [it, inserted] = map.emplace(val, list.size());
    if (!inserted)
      return false;

    list.push_back(val);
    return true;
  }

  bool remove(int val) {
    if (map.find(val) != map.end()) {
      int targetIdx = map[val];
      int lastIdx = list.size() - 1;
      map[list[lastIdx]] = targetIdx;
      swap(list[targetIdx], list[lastIdx]);
      list.pop_back();
      map.erase(val);
      return true;
    } else {
      return false;
    }
  }

  int getRandom() {
    uniform_int_distribution<int> get_rand_uni_int(0, list.size() - 1);
    int randomIdx = get_rand_uni_int(mt32);
    return list[randomIdx];
  }
};

int main() {
  RandomizedSet *obj = new RandomizedSet();
  bool param_1 = obj->insert(1);
  bool param_2 = obj->insert(10);
  bool param_3 = obj->insert(20);
  bool param_4 = obj->insert(30);
  int param_5 = obj->getRandom();
  int param_6 = obj->getRandom();
  int param_7 = obj->getRandom();
  int param_8 = obj->getRandom();
  return 0;
}
