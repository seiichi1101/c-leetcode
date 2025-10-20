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
  // int countPrimes(int n) {
  //   vector<int> primes{};
  //   for (int i = 2; i < n; i++) {
  //     bool flag = true;
  //     for (auto &&p : primes) {
  //       if (i % p == 0) {
  //         flag = false;
  //         break;
  //       }
  //     }
  //     if (flag)
  //       primes.push_back(i);
  //   }

  //   return primes.size();
  // }

  // Eratosthenes
  int countPrimes(int n) {
    if (n <= 2) {
      return 0;
    }

    vector<bool> primes(n, true);
    primes[0] = false;
    primes[1] = false;

    for (int i = 2; i < sqrt(n); i++) {
      if (primes[i])
        for (int j = i * i; j < n; j += i) {
          primes[j] = false;
        }
    }

    int cnt = 0;
    for (size_t i = 0; i < primes.size(); i++) {
      if (primes[i])
        cnt++;
    }

    return cnt;
  }
};

int main() {
  Solution s;
  int input = 499979;
  // int input = 10;
  auto output = s.countPrimes(input);
  return 0;
}
