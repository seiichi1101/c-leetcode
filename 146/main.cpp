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

class LRUCache {
private:
  int capacity;
  using Node = std::pair<int, int>;
  // listの内部構造はノード間をつないだ双方向linkedList
  // (バラけたメモリ配置なのでループは遅いが、ノードのつけ外しはポインタの切り替えだけなので高速)
  // ここでは、双方向LinkedListのiteratorをvalueに保存する
  unordered_map<int, list<Node>::iterator> map;
  list<Node> lru;

public:
  LRUCache(int capacity) { this->capacity = capacity; }

  int get(int key) {
    auto itr = map.find(key);
    if (itr == map.end())
      return -1;

    int value = itr->second->second;
    lru.erase(itr->second);
    lru.push_front({key, value});

    map.erase(itr);
    map[key] = lru.begin();
    return value;
  }

  void put(int key, int value) {
    auto itr = map.find(key);
    if (itr != map.end()) {
      lru.erase(itr->second);
      map.erase(itr);
    }
    lru.push_front({key, value});
    map[key] = lru.begin();

    if (lru.size() > capacity) {
      auto last = lru.back();
      map.erase(last.first);
      lru.pop_back();
    }
  }
};

int main() {
  LRUCache lru(2);
  lru.put(1, 1);
  lru.put(2, 2);
  lru.get(1);
  lru.put(3, 3);
  lru.get(2);
  lru.put(4, 4);
  lru.get(1);
  lru.get(3);
  lru.get(4);

  return 0;
}
